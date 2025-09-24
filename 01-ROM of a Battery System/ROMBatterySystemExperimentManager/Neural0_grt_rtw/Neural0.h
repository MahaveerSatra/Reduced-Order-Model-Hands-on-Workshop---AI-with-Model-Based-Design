/*
 * Neural0.h
 *
 * Code generation for model "Neural0".
 *
 * Model version              : 1.18
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Mon Apr 28 14:44:28 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Neural0_h_
#define Neural0_h_
#ifndef Neural0_COMMON_INCLUDES_
#define Neural0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* Neural0_COMMON_INCLUDES_ */

#include "Neural0_types.h"
#include <float.h>
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals for system '<S8>/act1' */
typedef struct {
  real_T Tanh[16];                     /* '<S19>/Tanh' */
} B_act1_Neural0_T;

/* Block signals for system '<S8>/fc2' */
typedef struct {
  real_T Add[16];                      /* '<S36>/Add' */
} B_fc2_Neural0_T;

/* Block signals (default storage) */
typedef struct {
  B_fc2_Neural0_T fc4;                 /* '<S8>/fc4' */
  B_fc2_Neural0_T fc3;                 /* '<S8>/fc3' */
  B_fc2_Neural0_T fc2;                 /* '<S8>/fc2' */
  B_act1_Neural0_T act4;               /* '<S8>/act4' */
  B_act1_Neural0_T act3;               /* '<S8>/act3' */
  B_act1_Neural0_T act2;               /* '<S8>/act2' */
  B_act1_Neural0_T act1;               /* '<S8>/act1' */
} B_Neural0_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[2];              /* '<S5>/Delay' */
  boolean_T IC_FirstOutputTime;        /* '<S1>/IC' */
  boolean_T IC1_FirstOutputTime;       /* '<S1>/IC1' */
} DW_Neural0_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T InputCurrent;                 /* '<Root>/Current' */
  real_T Inport1;                      /* '<Root>/Inport1' */
  real_T temperature;                  /* '<Root>/Inport2' */
} ExtU_Neural0_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T NSSSOC;                       /* '<Root>/NSS SOC' */
  real_T NSSTemperature;               /* '<Root>/NSS Temperature' */
  real_T NSSVoltage;                   /* '<Root>/NSS Voltage' */
} ExtY_Neural0_T;

/* Parameters for system: '<S8>/fc2' */
struct P_fc2_Neural0_T_ {
  real_T Bias_Value[16];               /* Expression: Layer.Bias
                                        * Referenced by: '<S15>/Bias'
                                        */
  real_T Weights_Value[256];           /* Expression: Layer.Weights
                                        * Referenced by: '<S15>/Weights'
                                        */
};

/* Parameters (default storage) */
struct P_Neural0_T_ {
  real_T SOCs;                         /* Variable: SOCs
                                        * Referenced by: '<S1>/IC'
                                        */
  real_T Ts;                           /* Variable: Ts
                                        * Referenced by: '<S1>/IC1'
                                        */
  real_T Bias_Value[2];                /* Expression: Layer.Bias
                                        * Referenced by: '<S13>/Bias'
                                        */
  real_T Weights_Value[32];            /* Expression: Layer.Weights
                                        * Referenced by: '<S13>/Weights'
                                        */
  real_T Bias_Value_k[16];             /* Expression: Layer.Bias
                                        * Referenced by: '<S14>/Bias'
                                        */
  real_T Weights_Value_m[80];          /* Expression: Layer.Weights
                                        * Referenced by: '<S14>/Weights'
                                        */
  real_T Delay_InitialCondition[2];    /* Expression: p.IC
                                        * Referenced by: '<S5>/Delay'
                                        */
  real_T Constant1_Value[3];
                        /* Expression: NSSTrainingOutput.Normalization.Mu{1,1:3}
                         * Referenced by: '<S4>/Constant1'
                         */
  real_T Gain1_Gain[3];
                  /* Expression: 1./NSSTrainingOutput.Normalization.Sigma{1,1:3}
                   * Referenced by: '<S4>/Gain1'
                   */
  real_T Gain_Gain[2];
                     /* Expression: NSSTrainingOutput.Normalization.Sigma{1,4:5}
                      * Referenced by: '<S2>/Gain'
                      */
  real_T Constant_Value[2];
                        /* Expression: NSSTrainingOutput.Normalization.Mu{1,4:5}
                         * Referenced by: '<S2>/Constant'
                         */
  P_fc2_Neural0_T fc4;                 /* '<S8>/fc4' */
  P_fc2_Neural0_T fc3;                 /* '<S8>/fc3' */
  P_fc2_Neural0_T fc2;                 /* '<S8>/fc2' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Neural0_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Neural0_T Neural0_P;

/* Block signals (default storage) */
extern B_Neural0_T Neural0_B;

/* Block states (default storage) */
extern DW_Neural0_T Neural0_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Neural0_T Neural0_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Neural0_T Neural0_Y;

/* Model entry point functions */
extern void Neural0_initialize(void);
extern void Neural0_step(void);
extern void Neural0_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Neural0_T *const Neural0_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('ValidateROMBatteryModel/Neural State Space Battery Model')    - opens subsystem ValidateROMBatteryModel/Neural State Space Battery Model
 * hilite_system('ValidateROMBatteryModel/Neural State Space Battery Model/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ValidateROMBatteryModel'
 * '<S1>'   : 'ValidateROMBatteryModel/Neural State Space Battery Model'
 * '<S2>'   : 'ValidateROMBatteryModel/Neural State Space Battery Model/Denormalize'
 * '<S3>'   : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model'
 * '<S4>'   : 'ValidateROMBatteryModel/Neural State Space Battery Model/Normalize'
 * '<S5>'   : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS'
 * '<S6>'   : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network'
 * '<S7>'   : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network'
 * '<S8>'   : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem'
 * '<S9>'   : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act1'
 * '<S10>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act2'
 * '<S11>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act3'
 * '<S12>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act4'
 * '<S13>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/dx'
 * '<S14>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc1'
 * '<S15>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc2'
 * '<S16>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc3'
 * '<S17>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc4'
 * '<S18>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act1/Tanh_VSS'
 * '<S19>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act1/Tanh_VSS/None'
 * '<S20>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act2/Tanh_VSS'
 * '<S21>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act2/Tanh_VSS/None'
 * '<S22>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act3/Tanh_VSS'
 * '<S23>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act3/Tanh_VSS/None'
 * '<S24>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act4/Tanh_VSS'
 * '<S25>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act4/Tanh_VSS/None'
 * '<S26>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/dx/BiasAddition'
 * '<S27>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/dx/Reshape'
 * '<S28>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/dx/BiasAddition/Add'
 * '<S29>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/dx/Reshape/Reshape'
 * '<S30>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc1/BiasAddition'
 * '<S31>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc1/Reshape'
 * '<S32>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc1/BiasAddition/Add'
 * '<S33>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc1/Reshape/Reshape'
 * '<S34>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc2/BiasAddition'
 * '<S35>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc2/Reshape'
 * '<S36>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc2/BiasAddition/Add'
 * '<S37>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc2/Reshape/Reshape'
 * '<S38>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc3/BiasAddition'
 * '<S39>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc3/Reshape'
 * '<S40>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc3/BiasAddition/Add'
 * '<S41>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc3/Reshape/Reshape'
 * '<S42>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc4/BiasAddition'
 * '<S43>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc4/Reshape'
 * '<S44>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc4/BiasAddition/Add'
 * '<S45>'  : 'ValidateROMBatteryModel/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc4/Reshape/Reshape'
 */
#endif                                 /* Neural0_h_ */
