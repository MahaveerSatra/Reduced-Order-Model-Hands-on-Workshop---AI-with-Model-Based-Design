//
// File: BatteryModel_NSS_CodeGeneration.h
//
// Code generated for Simulink model 'BatteryModel_NSS_CodeGeneration'.
//
// Model version                  : 3.7
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Tue Apr 29 12:04:26 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-32 (Windows32)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef BatteryModel_NSS_CodeGeneration_h_
#define BatteryModel_NSS_CodeGeneration_h_
#include <cmath>
#include "rtwtypes.h"

// Class declaration for model BatteryModel_NSS_CodeGeneration
class BatteryModel_NSS_CodeGeneration final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    real_T Delay_DSTATE[2];            // '<S5>/Delay'
    boolean_T IC_FirstOutputTime;      // '<S1>/IC'
    boolean_T IC1_FirstOutputTime;     // '<S1>/IC1'
  };

  // Constant parameters (default storage)
  struct ConstP {
    // Expression: Layer.Bias
    //  Referenced by: '<S13>/Bias'

    real_T Bias_Value[2];

    // Expression: Layer.Weights
    //  Referenced by: '<S13>/Weights'

    real_T Weights_Value[32];

    // Expression: Layer.Bias
    //  Referenced by: '<S14>/Bias'

    real_T Bias_Value_n[16];

    // Expression: Layer.Weights
    //  Referenced by: '<S14>/Weights'

    real_T Weights_Value_l[80];

    // Expression: Layer.Bias
    //  Referenced by: '<S15>/Bias'

    real_T Bias_Value_g[16];

    // Expression: Layer.Weights
    //  Referenced by: '<S15>/Weights'

    real_T Weights_Value_f[256];

    // Expression: Layer.Bias
    //  Referenced by: '<S16>/Bias'

    real_T Bias_Value_m[16];

    // Expression: Layer.Weights
    //  Referenced by: '<S16>/Weights'

    real_T Weights_Value_i[256];

    // Expression: Layer.Bias
    //  Referenced by: '<S17>/Bias'

    real_T Bias_Value_b[16];

    // Expression: Layer.Weights
    //  Referenced by: '<S17>/Weights'

    real_T Weights_Value_p[256];

    // Expression: NSSTrainingOutput.Normalization.Mu{1,4:5}
    //  Referenced by: '<S2>/Constant'

    real_T Constant_Value[2];

    // Expression: NSSTrainingOutput.Normalization.Sigma{1,4:5}
    //  Referenced by: '<S2>/Gain'

    real_T Gain_Gain[2];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU {
    real_T InputCurrent;               // '<Root>/InputCurrent'
    real_T SOC;                        // '<Root>/SOC'
    real_T Temperature;                // '<Root>/Temperature'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY {
    real_T Out1;                       // '<Root>/Out1'
    real_T Out2;                       // '<Root>/Out2'
    real_T Out3;                       // '<Root>/Out3'
  };

  // Copy Constructor
  BatteryModel_NSS_CodeGeneration(BatteryModel_NSS_CodeGeneration const&) =
    delete;

  // Assignment Operator
  BatteryModel_NSS_CodeGeneration& operator= (BatteryModel_NSS_CodeGeneration
    const&) & = delete;

  // Move Constructor
  BatteryModel_NSS_CodeGeneration(BatteryModel_NSS_CodeGeneration &&) = delete;

  // Move Assignment Operator
  BatteryModel_NSS_CodeGeneration& operator= (BatteryModel_NSS_CodeGeneration &&)
    = delete;

  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  BatteryModel_NSS_CodeGeneration();

  // Destructor
  ~BatteryModel_NSS_CodeGeneration();

  // private data and function members
 private:
  // Block states
  DW rtDW;

  // private member function(s) for subsystem '<S8>/act1'
  static void act1(const real_T rtu_In1[16], real_T rty_Out1[16]);
};

// Constant parameters (default storage)
extern const BatteryModel_NSS_CodeGeneration::ConstP rtConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/Reshape' : Reshape block reduction
//  Block '<S6>/Reshape2' : Reshape block reduction
//  Block '<S29>/Reshape' : Reshape block reduction
//  Block '<S33>/Reshape' : Reshape block reduction
//  Block '<S37>/Reshape' : Reshape block reduction
//  Block '<S41>/Reshape' : Reshape block reduction
//  Block '<S45>/Reshape' : Reshape block reduction
//  Block '<S4>/Reshape' : Reshape block reduction


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'BatteryModel_NSS_CodeGeneration'
//  '<S1>'   : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model'
//  '<S2>'   : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Denormalize'
//  '<S3>'   : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model'
//  '<S4>'   : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Normalize'
//  '<S5>'   : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS'
//  '<S6>'   : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network'
//  '<S7>'   : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network'
//  '<S8>'   : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem'
//  '<S9>'   : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act1'
//  '<S10>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act2'
//  '<S11>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act3'
//  '<S12>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act4'
//  '<S13>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/dx'
//  '<S14>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc1'
//  '<S15>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc2'
//  '<S16>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc3'
//  '<S17>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc4'
//  '<S18>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act1/Tanh_VSS'
//  '<S19>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act1/Tanh_VSS/None'
//  '<S20>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act2/Tanh_VSS'
//  '<S21>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act2/Tanh_VSS/None'
//  '<S22>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act3/Tanh_VSS'
//  '<S23>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act3/Tanh_VSS/None'
//  '<S24>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act4/Tanh_VSS'
//  '<S25>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/act4/Tanh_VSS/None'
//  '<S26>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/dx/BiasAddition'
//  '<S27>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/dx/Reshape'
//  '<S28>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/dx/BiasAddition/Add'
//  '<S29>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/dx/Reshape/Reshape'
//  '<S30>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc1/BiasAddition'
//  '<S31>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc1/Reshape'
//  '<S32>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc1/BiasAddition/Add'
//  '<S33>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc1/Reshape/Reshape'
//  '<S34>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc2/BiasAddition'
//  '<S35>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc2/Reshape'
//  '<S36>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc2/BiasAddition/Add'
//  '<S37>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc2/Reshape/Reshape'
//  '<S38>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc3/BiasAddition'
//  '<S39>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc3/Reshape'
//  '<S40>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc3/BiasAddition/Add'
//  '<S41>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc3/Reshape/Reshape'
//  '<S42>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc4/BiasAddition'
//  '<S43>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc4/Reshape'
//  '<S44>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc4/BiasAddition/Add'
//  '<S45>'  : 'BatteryModel_NSS_CodeGeneration/Neural State Space Battery Model/Neural State Space Model/NSS/State Network/State Network/NetworkSubsystem/fc4/Reshape/Reshape'

#endif                                 // BatteryModel_NSS_CodeGeneration_h_

//
// File trailer for generated code.
//
// [EOF]
//
