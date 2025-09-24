/* Code generated for Simulink model BatteryModel_NSS_CodeGeneration */
/* Code generated on 29-Apr-2025 12:04:31.112 */
#include "Executor.hpp"
#include "BatteryModel_NSS_CodeGeneration.h"

static BatteryModel_NSS_CodeGeneration rtObj{};

/* main handles the following: */
/*  - Instantiate the model object and owns its memory. */
/*  - Call the model initialize and terminate functions. */
/*  - Register tasks and add them to the scheduler */
int main() {

  /* These rate variables represent how many base rate  */
  /* periods to wait before running a step function. */
  double const baserate = 1;
  /* Initialize Function */
  rtObj.initialize();

  /* Create scheduler and add tasks */
  platform::runtime::Executor executor;
  executor.setBaseRateInSeconds(std::chrono::duration<double>(baserate));
  /* Add periodic tasks */
  executor.addPeriodicEvent([]() { rtObj.step(); }, 1);

/* Run model */
#if defined(rtmSetStopRequested) && defined(rtmGetStopRequested)
  executor.run([]() { return rtmGetStopRequested(rtObj.getRTM()); });
#else
  executor.run();
#endif

  /* Terminate Function */

  return EXIT_SUCCESS;
}
