/*
 * File: PMSM_ROM_NSS_CodeGeneration.h
 *
 * Code generated for Simulink model 'PMSM_ROM_NSS_CodeGeneration'.
 *
 * Model version                  : 10.0
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Thu Aug 28 14:18:48 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-32 (Windows32)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef PMSM_ROM_NSS_CodeGeneration_h_
#define PMSM_ROM_NSS_CodeGeneration_h_
#ifndef PMSM_ROM_NSS_CodeGeneration_COMMON_INCLUDES_
#define PMSM_ROM_NSS_CodeGeneration_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                        /* PMSM_ROM_NSS_CodeGeneration_COMMON_INCLUDES_ */

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[4];              /* '<S5>/Delay' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: Layer.Bias
   * Referenced by: '<S14>/Bias'
   */
  real_T Bias_Value[4];

  /* Expression: Layer.Weights
   * Referenced by: '<S14>/Weights'
   */
  real_T Weights_Value[256];

  /* Expression: Layer.Bias
   * Referenced by: '<S15>/Bias'
   */
  real_T Bias_Value_o[64];

  /* Expression: Layer.Weights
   * Referenced by: '<S15>/Weights'
   */
  real_T Weights_Value_p[704];

  /* Expression: Layer.Bias
   * Referenced by: '<S16>/Bias'
   */
  real_T Bias_Value_b[64];

  /* Expression: Layer.Weights
   * Referenced by: '<S16>/Weights'
   */
  real_T Weights_Value_e[4096];

  /* Expression: Layer.Bias
   * Referenced by: '<S17>/Bias'
   */
  real_T Bias_Value_k[64];

  /* Expression: Layer.Weights
   * Referenced by: '<S17>/Weights'
   */
  real_T Weights_Value_m[4096];

  /* Expression: Layer.Bias
   * Referenced by: '<S18>/Bias'
   */
  real_T Bias_Value_a[64];

  /* Expression: Layer.Weights
   * Referenced by: '<S18>/Weights'
   */
  real_T Weights_Value_d[4096];

  /* Expression: Layer.Bias
   * Referenced by: '<S19>/Bias'
   */
  real_T Bias_Value_n[64];

  /* Expression: Layer.Weights
   * Referenced by: '<S19>/Weights'
   */
  real_T Weights_Value_f[4096];

  /* Expression: meanY_nss
   * Referenced by: '<S2>/Constant'
   */
  real_T Constant_Value[4];

  /* Expression: 1./stdX_nss
   * Referenced by: '<S4>/Gain1'
   */
  real_T Gain1_Gain[7];

  /* Expression: stdY_nss
   * Referenced by: '<S2>/Gain'
   */
  real_T Gain_Gain[4];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T ambientT;                     /* '<Root>/Inport' */
  real_T coolantT;                     /* '<Root>/Inport1' */
  real_T u_d;                          /* '<Root>/Inport2' */
  real_T u_q;                          /* '<Root>/Inport3' */
  real_T motor_speed;                  /* '<Root>/Inport4' */
  real_T i_d;                          /* '<Root>/Inport5' */
  real_T i_q;                          /* '<Root>/Inport6' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
  real_T Out2;                         /* '<Root>/Out2' */
  real_T Out3;                         /* '<Root>/Out3' */
  real_T Out4;                         /* '<Root>/Out4' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void PMSM_ROM_NSS_CodeGeneration_initialize(void);
extern void PMSM_ROM_NSS_CodeGeneration_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Reshape' : Reshape block reduction
 * Block '<S6>/Reshape2' : Reshape block reduction
 * Block '<S45>/Reshape' : Reshape block reduction
 * Block '<S51>/Reshape' : Reshape block reduction
 * Block '<S57>/Reshape' : Reshape block reduction
 * Block '<S63>/Reshape' : Reshape block reduction
 * Block '<S69>/Reshape' : Reshape block reduction
 * Block '<S75>/Reshape' : Reshape block reduction
 * Block '<S4>/Reshape' : Reshape block reduction
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PMSM_ROM_NSS_CodeGeneration'
 * '<S1>'   : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model'
 * '<S2>'   : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Denormalize2'
 * '<S3>'   : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model'
 * '<S4>'   : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Normalize2'
 * '<S5>'   : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS'
 * '<S6>'   : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network'
 * '<S7>'   : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network'
 * '<S8>'   : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem'
 * '<S9>'   : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act1'
 * '<S10>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act2'
 * '<S11>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act3'
 * '<S12>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act4'
 * '<S13>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act5'
 * '<S14>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/dx'
 * '<S15>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc1'
 * '<S16>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc2'
 * '<S17>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc3'
 * '<S18>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc4'
 * '<S19>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc5'
 * '<S20>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act1/OutputDataType'
 * '<S21>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act1/Tanh_VSS'
 * '<S22>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act1/OutputDataType/PassThrough'
 * '<S23>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act1/Tanh_VSS/None'
 * '<S24>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act2/OutputDataType'
 * '<S25>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act2/Tanh_VSS'
 * '<S26>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act2/OutputDataType/PassThrough'
 * '<S27>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act2/Tanh_VSS/None'
 * '<S28>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act3/OutputDataType'
 * '<S29>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act3/Tanh_VSS'
 * '<S30>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act3/OutputDataType/PassThrough'
 * '<S31>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act3/Tanh_VSS/None'
 * '<S32>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act4/OutputDataType'
 * '<S33>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act4/Tanh_VSS'
 * '<S34>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act4/OutputDataType/PassThrough'
 * '<S35>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act4/Tanh_VSS/None'
 * '<S36>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act5/OutputDataType'
 * '<S37>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act5/Tanh_VSS'
 * '<S38>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act5/OutputDataType/PassThrough'
 * '<S39>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act5/Tanh_VSS/None'
 * '<S40>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/dx/BiasAddition'
 * '<S41>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/dx/OutputDataType'
 * '<S42>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/dx/Reshape'
 * '<S43>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/dx/BiasAddition/Add'
 * '<S44>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/dx/OutputDataType/PassThrough'
 * '<S45>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/dx/Reshape/Reshape'
 * '<S46>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc1/BiasAddition'
 * '<S47>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc1/OutputDataType'
 * '<S48>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc1/Reshape'
 * '<S49>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc1/BiasAddition/Add'
 * '<S50>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc1/OutputDataType/PassThrough'
 * '<S51>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc1/Reshape/Reshape'
 * '<S52>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc2/BiasAddition'
 * '<S53>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc2/OutputDataType'
 * '<S54>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc2/Reshape'
 * '<S55>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc2/BiasAddition/Add'
 * '<S56>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc2/OutputDataType/PassThrough'
 * '<S57>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc2/Reshape/Reshape'
 * '<S58>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc3/BiasAddition'
 * '<S59>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc3/OutputDataType'
 * '<S60>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc3/Reshape'
 * '<S61>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc3/BiasAddition/Add'
 * '<S62>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc3/OutputDataType/PassThrough'
 * '<S63>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc3/Reshape/Reshape'
 * '<S64>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc4/BiasAddition'
 * '<S65>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc4/OutputDataType'
 * '<S66>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc4/Reshape'
 * '<S67>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc4/BiasAddition/Add'
 * '<S68>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc4/OutputDataType/PassThrough'
 * '<S69>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc4/Reshape/Reshape'
 * '<S70>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc5/BiasAddition'
 * '<S71>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc5/OutputDataType'
 * '<S72>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc5/Reshape'
 * '<S73>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc5/BiasAddition/Add'
 * '<S74>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc5/OutputDataType/PassThrough'
 * '<S75>'  : 'PMSM_ROM_NSS_CodeGeneration/Neural State Space PMSM Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc5/Reshape/Reshape'
 */
#endif                                 /* PMSM_ROM_NSS_CodeGeneration_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
