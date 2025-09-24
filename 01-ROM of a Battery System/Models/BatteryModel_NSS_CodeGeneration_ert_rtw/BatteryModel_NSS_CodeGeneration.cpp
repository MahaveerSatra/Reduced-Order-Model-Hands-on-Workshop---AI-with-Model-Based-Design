//
// File: BatteryModel_NSS_CodeGeneration.cpp
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
#include "BatteryModel_NSS_CodeGeneration.h"
#include "rtwtypes.h"
#include <cmath>

//
// Output and update for atomic system:
//    '<S8>/act1'
//    '<S8>/act2'
//    '<S8>/act3'
//    '<S8>/act4'
//
void BatteryModel_NSS_CodeGeneration::act1(const real_T rtu_In1[16], real_T
  rty_Out1[16])
{
  // Trigonometry: '<S19>/Tanh'
  for (int32_T i{0}; i < 16; i++) {
    rty_Out1[i] = std::tanh(rtu_In1[i]);
  }

  // End of Trigonometry: '<S19>/Tanh'
}

// Model step function
void BatteryModel_NSS_CodeGeneration::step()
{
  real_T rtb_Add_c[16];
  real_T rtb_Tanh[16];
  real_T tmp[5];
  real_T rtb_Delay[2];
  real_T rtb_IC;
  real_T rtb_IC1;
  int32_T i;
  int32_T i_0;

  // Outputs for Atomic SubSystem: '<Root>/Neural State Space Battery Model'
  // InitialCondition: '<S1>/IC' incorporates:
  //   Inport: '<Root>/SOC'

  if (rtDW.IC_FirstOutputTime) {
    rtDW.IC_FirstOutputTime = false;
    rtb_IC = 0.3;
  } else {
    rtb_IC = rtU.SOC;
  }

  // End of InitialCondition: '<S1>/IC'

  // InitialCondition: '<S1>/IC1' incorporates:
  //   Inport: '<Root>/Temperature'

  if (rtDW.IC1_FirstOutputTime) {
    rtDW.IC1_FirstOutputTime = false;
    rtb_IC1 = 280.0;
  } else {
    rtb_IC1 = rtU.Temperature;
  }

  // End of InitialCondition: '<S1>/IC1'

  // Outputs for Atomic SubSystem: '<S1>/Neural State Space Model'
  // Delay: '<S5>/Delay'
  rtb_Delay[0] = rtDW.Delay_DSTATE[0];

  // Outputs for Atomic SubSystem: '<S8>/fc1'
  // Product: '<S14>/Matrix Multiply' incorporates:
  //   Delay: '<S5>/Delay'

  tmp[0] = rtDW.Delay_DSTATE[0];

  // End of Outputs for SubSystem: '<S8>/fc1'

  // Delay: '<S5>/Delay'
  rtb_Delay[1] = rtDW.Delay_DSTATE[1];

  // Outputs for Atomic SubSystem: '<S8>/fc1'
  // Product: '<S14>/Matrix Multiply' incorporates:
  //   Constant: '<S4>/Constant1'
  //   Delay: '<S5>/Delay'
  //   Gain: '<S4>/Gain1'
  //   Inport: '<Root>/InputCurrent'
  //   Sum: '<S4>/Add1'

  tmp[1] = rtDW.Delay_DSTATE[1];
  tmp[2] = (rtU.InputCurrent - -0.0429870499610664) * 1.8044950228454222;
  tmp[3] = (rtb_IC - 0.50184304399524893) * 3.3117626614401305;
  tmp[4] = (rtb_IC1 - 294.13793103448273) * 0.090533937074353241;

  // Sum: '<S32>/Add' incorporates:
  //   Constant: '<S14>/Bias'
  //   Constant: '<S14>/Weights'
  //   Product: '<S14>/Matrix Multiply'

  for (i = 0; i < 16; i++) {
    rtb_IC1 = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_IC1 += rtConstP.Weights_Value_l[(i_0 << 4) + i] * tmp[i_0];
    }

    rtb_Add_c[i] = rtb_IC1 + rtConstP.Bias_Value_n[i];
  }

  // End of Sum: '<S32>/Add'
  // End of Outputs for SubSystem: '<S8>/fc1'

  // Outputs for Atomic SubSystem: '<S8>/act1'
  act1(rtb_Add_c, rtb_Tanh);

  // End of Outputs for SubSystem: '<S8>/act1'

  // Outputs for Atomic SubSystem: '<S8>/fc2'
  // Sum: '<S36>/Add' incorporates:
  //   Constant: '<S15>/Bias'
  //   Constant: '<S15>/Weights'
  //   Product: '<S15>/Matrix Multiply'
  //   Trigonometry: '<S25>/Tanh'

  for (i = 0; i < 16; i++) {
    rtb_IC1 = 0.0;
    for (i_0 = 0; i_0 < 16; i_0++) {
      rtb_IC1 += rtConstP.Weights_Value_f[(i_0 << 4) + i] * rtb_Tanh[i_0];
    }

    rtb_Add_c[i] = rtb_IC1 + rtConstP.Bias_Value_g[i];
  }

  // End of Sum: '<S36>/Add'
  // End of Outputs for SubSystem: '<S8>/fc2'

  // Outputs for Atomic SubSystem: '<S8>/act2'
  act1(rtb_Add_c, rtb_Tanh);

  // End of Outputs for SubSystem: '<S8>/act2'

  // Outputs for Atomic SubSystem: '<S8>/fc3'
  // Sum: '<S40>/Add' incorporates:
  //   Constant: '<S16>/Bias'
  //   Constant: '<S16>/Weights'
  //   Product: '<S16>/Matrix Multiply'
  //   Trigonometry: '<S25>/Tanh'

  for (i = 0; i < 16; i++) {
    rtb_IC1 = 0.0;
    for (i_0 = 0; i_0 < 16; i_0++) {
      rtb_IC1 += rtConstP.Weights_Value_i[(i_0 << 4) + i] * rtb_Tanh[i_0];
    }

    rtb_Add_c[i] = rtb_IC1 + rtConstP.Bias_Value_m[i];
  }

  // End of Sum: '<S40>/Add'
  // End of Outputs for SubSystem: '<S8>/fc3'

  // Outputs for Atomic SubSystem: '<S8>/act3'
  act1(rtb_Add_c, rtb_Tanh);

  // End of Outputs for SubSystem: '<S8>/act3'

  // Outputs for Atomic SubSystem: '<S8>/fc4'
  // Sum: '<S44>/Add' incorporates:
  //   Constant: '<S17>/Bias'
  //   Constant: '<S17>/Weights'
  //   Product: '<S17>/Matrix Multiply'
  //   Trigonometry: '<S25>/Tanh'

  for (i = 0; i < 16; i++) {
    rtb_IC1 = 0.0;
    for (i_0 = 0; i_0 < 16; i_0++) {
      rtb_IC1 += rtConstP.Weights_Value_p[(i_0 << 4) + i] * rtb_Tanh[i_0];
    }

    rtb_Add_c[i] = rtb_IC1 + rtConstP.Bias_Value_b[i];
  }

  // End of Sum: '<S44>/Add'
  // End of Outputs for SubSystem: '<S8>/fc4'

  // Outputs for Atomic SubSystem: '<S8>/act4'
  act1(rtb_Add_c, rtb_Tanh);

  // End of Outputs for SubSystem: '<S8>/act4'
  for (i = 0; i < 2; i++) {
    // Update for Delay: '<S5>/Delay' incorporates:
    //   Constant: '<S13>/Bias'
    //   Constant: '<S13>/Weights'
    //   Product: '<S13>/Matrix Multiply'
    //   Sum: '<S28>/Add'
    //   Sum: '<S5>/Add'
    //   Trigonometry: '<S25>/Tanh'

    rtb_IC1 = 0.0;
    for (i_0 = 0; i_0 < 16; i_0++) {
      // Outputs for Atomic SubSystem: '<S8>/dx'
      rtb_IC1 += rtConstP.Weights_Value[(i_0 << 1) + i] * rtb_Tanh[i_0];

      // End of Outputs for SubSystem: '<S8>/dx'
    }

    // Outputs for Atomic SubSystem: '<S8>/dx'
    rtDW.Delay_DSTATE[i] += rtb_IC1 + rtConstP.Bias_Value[i];

    // End of Update for Delay: '<S5>/Delay'
    // End of Outputs for SubSystem: '<S8>/dx'

    // Sum: '<S2>/Add' incorporates:
    //   Constant: '<S2>/Constant'
    //   Gain: '<S2>/Gain'

    rtb_Delay[i] = static_cast<real32_T>(rtConstP.Gain_Gain[i] * rtb_Delay[i]) +
      rtConstP.Constant_Value[i];
  }

  // End of Outputs for SubSystem: '<S1>/Neural State Space Model'
  // End of Outputs for SubSystem: '<Root>/Neural State Space Battery Model'

  // Outport: '<Root>/Out1'
  rtY.Out1 = rtb_IC;

  // Outport: '<Root>/Out2'
  rtY.Out2 = rtb_Delay[0];

  // Outport: '<Root>/Out3'
  rtY.Out3 = rtb_Delay[1];
}

// Model initialize function
void BatteryModel_NSS_CodeGeneration::initialize()
{
  // SystemInitialize for Atomic SubSystem: '<Root>/Neural State Space Battery Model' 
  // Start for InitialCondition: '<S1>/IC'
  rtDW.IC_FirstOutputTime = true;

  // Start for InitialCondition: '<S1>/IC1'
  rtDW.IC1_FirstOutputTime = true;

  // SystemInitialize for Atomic SubSystem: '<S1>/Neural State Space Model'
  // InitializeConditions for Delay: '<S5>/Delay'
  rtDW.Delay_DSTATE[0] = -1.0;
  rtDW.Delay_DSTATE[1] = -0.5;

  // End of SystemInitialize for SubSystem: '<S1>/Neural State Space Model'
  // End of SystemInitialize for SubSystem: '<Root>/Neural State Space Battery Model' 
}

// Constructor
BatteryModel_NSS_CodeGeneration::BatteryModel_NSS_CodeGeneration():
  rtU(),
  rtY(),
  rtDW()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
BatteryModel_NSS_CodeGeneration::~BatteryModel_NSS_CodeGeneration() = default;

//
// File trailer for generated code.
//
// [EOF]
//
