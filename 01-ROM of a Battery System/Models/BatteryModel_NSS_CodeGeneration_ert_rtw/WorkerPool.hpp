#ifndef EXECUTOR_WORKERPOOL_H_
#define EXECUTOR_WORKERPOOL_H_


#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <algorithm>
#include <atomic>
#include <cstdint>


namespace utility {

/** @brief A WorkerPool manages a set of threads (called workers) and runs
 *         given tasks concurrently on the threads
 *
 *         A presumption of WorkerPool is the tasks are independent to each other,
 *         and there is no guarantee on the order of task execution.
*/
class WorkerPool final {

    public:

        /** @brief Constructor
         *
         *  @param numWorkers The number of threads managed by the WorkerPool
        */
        explicit WorkerPool(const uint32_t numThreads=0): numWorkers(numThreads) {
            if(numWorkers == 0U) {
                numWorkers = std::max<uint32_t>(std::thread::hardware_concurrency(), 1U);
            }
        }

        /** @brief Copy Constructor */
        WorkerPool(const WorkerPool &other) = delete;

        /** @brief Move Constructor */
        WorkerPool(WorkerPool&& other) = delete;

        /** @brief Copy assignment operator */
        WorkerPool& operator = (const WorkerPool& other) = delete;

        /** @brief Move assignment operator */
        WorkerPool& operator = (WorkerPool&& other) = delete;

        /** @brief Destructor */
        ~WorkerPool() { 
            if(workers.empty()) {
                return ;
            }

            {
                const std::lock_guard<std::mutex> lock{taskAndStateMutex};
                stop = true;
            }
            taskAndStateSignal.notify_all();
            std::for_each(workers.begin(), workers.end(), [](std::thread& thd){ thd.join(); });
        }

        /** @brief Launch worker threads */
        void start() {
            for(uint32_t i {0}; i<numWorkers; i++) {
                workers.emplace_back([this](){ this->workerLoop(); });
            }
        }

        /** @brief Caller blocks until all tasks are executed (finished)
        */
        void wait() {
            std::unique_lock<std::mutex> lock{taskAndStateMutex};
            taskAndStateSignal.wait(lock, [this](){ 
                return ((this->numIdleWorkers == this->workers.size()) && (this->taskQueue.empty())); 
            });
        }

        /** @brief Dispatch a task to the WorkerPool without needing to know the result (i.e. fire & forget)
         *
         *  @param task A callable object
         */
        void post(std::function<void()>&& task) {
            {
                const std::lock_guard<std::mutex> lock{taskAndStateMutex};
                taskQueue.emplace(std::move(task));
            }
            taskAndStateSignal.notify_one();
        }

        /** @brief Dispatch a set of tasks to the WorkerPool without needing to know the result
         *
         *  @param tasks A set of callable objects
         */
        void post(std::vector<std::function<void()>>& tasks) {
            if(tasks.empty()) {
                return;
            }
            {
                const std::lock_guard<std::mutex> lock{taskAndStateMutex};
                for(auto &t: tasks) {
                    taskQueue.emplace(std::move(t));
                }
            }
            taskAndStateSignal.notify_all();
        }

    private:

        /** @brief Threads in the pool */
        std::vector<std::thread> workers;

        /** @brief A queue to store tasks ready for execution */
        std::queue<std::function<void()>> taskQueue;

        /** @brief A signal to notify workers if tasks are available or the pool terminates */
        std::condition_variable taskAndStateSignal;

        /** @brief A lock to protect access to the queue and the stop flag */
        std::mutex taskAndStateMutex;

        /** @brief Number of workers in the pool */
        uint32_t numWorkers;

        /** @brief Number of workers that are not executing tasks */
        uint32_t numIdleWorkers = 0;

        /** @brief A flag to indicate the pool terminates or not */
        bool stop = false;

        /**
         * @brief The context to be executed by worker threads
        */
        void workerLoop() {
            std::unique_lock<std::mutex> lock{taskAndStateMutex};
            while(!stop) {
                if(taskQueue.empty()) {
                    ++ numIdleWorkers;
                    if(numIdleWorkers == numWorkers) {
                        taskAndStateSignal.notify_all();
                    }
                    taskAndStateSignal.wait(lock, [this](){ return ((this->stop) || (!this->taskQueue.empty())); });
                    -- numIdleWorkers;
                }
        
                if(stop) {
                    return;
                }
                auto task = std::move(taskQueue.front());
                taskQueue.pop();
        
                lock.unlock();
                task();
                lock.lock();
            }
        }
};

}
#endif
