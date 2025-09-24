#ifndef EXECUTOR_DEFAULT_TIMER_H_
#define EXECUTOR_DEFAULT_TIMER_H_

#include <condition_variable>
#include <chrono>
#include <thread>
#include <mutex>
#include <cassert>
#include <cmath>
#include <cstdint>

namespace utility {

// An interval timer which spawns a thread to count the number of elapsed intervals
//
// Usage:
//     // Create a timer with the interval length set to 1.2 second
//     Timer timer(std::chrono::duration<double>(1.2)); 
//     timer.start();    // Initiate the timer
//     timer.wait();     // Wait for one period to pass
//
// This timer class is the default timer for the Executor's run method. To use a
// custom timer, the custom timer should have these three functions: 
// (1) constructor (std::chrono::duration<double>), (2) start() and (3) wait().
//
class Timer final {
    public:

      // Constructor
      //
      // @param period The time length measured in seconds.
      explicit Timer(const std::chrono::duration<double> period) noexcept: 
          seconds_portion(std::chrono::duration_cast<std::chrono::seconds>(period)), 
          nanoseconds_portion(std::chrono::duration_cast<std::chrono::nanoseconds>(period - seconds_portion)), 
          is_timer_halt(false), elapsed_period_counter(0) {
          // The given period should be greater than 0
          assert(period.count() > 0.0F);
      }
  
      // Constructor
      Timer() = delete;
      // Copy constructor
      Timer(const Timer &other) = delete;
      // Move constructor
      Timer(Timer&& other) = delete;
      // Copy assignment operator
      Timer& operator = (const Timer& other) = delete;
      // Move assignment operator
      Timer& operator = (Timer&& other) = delete;
  
      // Destructor
      ~Timer() {
          stop();
          if(counting_thread.joinable()) {
              counting_thread.join();
          }
      }
  
      // Launch a thread to count how many intervals have elapsed
      void start() {
          counting_thread = std::thread([this] () noexcept {
              std::unique_lock<std::mutex> lock {this->timer_state_mutex};
              while(!is_timer_halt) {
                  lock.unlock();
                  std::this_thread::sleep_for(this->seconds_portion);
                  std::this_thread::sleep_for(this->nanoseconds_portion);
                  lock.lock();
                  this->elapsed_period_counter ++;
                  this->state_signal.notify_one();
              }
          });
      }
  
      // Wait for one period to pass. The caller will be blocked if there is no elapsed
      // elapsed interval (i.e. elapsed_period_counter = 0).
      void wait() {
          std::unique_lock<std::mutex> lock {timer_state_mutex};
          state_signal.wait(lock, [this] () noexcept -> bool { return this->elapsed_period_counter > 0; });
          --elapsed_period_counter;
      }

    private:
      // The period consists of two portions: seconds + nanoseconds
      std::chrono::seconds const seconds_portion;
      // The nanoseconds portion of the period
      std::chrono::nanoseconds const nanoseconds_portion;

      // A flag to stop the timer
      bool is_timer_halt;
      // The elapsed_period_counter records how many periods have elapsed since the wait function
      // has been called
      uint32_t elapsed_period_counter;
      // The thread that counts how many periods have elapsed
      std::thread counting_thread;
      // A signal to wait for/notify a period pass or timer termination 
      std::condition_variable state_signal;
      // Protect the elapsed_period_counter and is_timer_halt from concurrent access
      std::mutex timer_state_mutex;

      // Notify the timer thread to quit when the timer terminates
      void stop() {
        {
            const std::lock_guard<std::mutex> lock {timer_state_mutex};
            is_timer_halt = true;
        }
        state_signal.notify_one();
      }
};

} // End of utility namespace

#endif

