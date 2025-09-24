/*
 * File: PMSM_ROM_NSS_CodeGeneration.c
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

#include "PMSM_ROM_NSS_CodeGeneration.h"
#include "rtwtypes.h"
#include <math.h>

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static void act1(const real_T rtu_In1[64], real_T rty_Out1[64]);
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 3) {/* Sample time: [2.0s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S8>/act1'
 *    '<S8>/act2'
 *    '<S8>/act3'
 *    '<S8>/act4'
 *    '<S8>/act5'
 */
static void act1(const real_T rtu_In1[64], real_T rty_Out1[64])
{
  int32_T i;

  /* Trigonometry: '<S23>/Tanh' */
  for (i = 0; i < 64; i++) {
    rty_Out1[i] = tanh(rtu_In1[i]);
  }

  /* End of Trigonometry: '<S23>/Tanh' */
}

/* Model step function */
void PMSM_ROM_NSS_CodeGeneration_step(void)
{
  real_T rtb_Add_o[64];
  real_T rtb_MatrixMultiply[64];
  real_T tmp[11];
  real_T rtb_Delay[4];
  real_T tmp_0;
  int32_T i;
  int32_T i_0;
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S4>/Add1' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Inport: '<Root>/Inport'
     *  Inport: '<Root>/Inport1'
     *  Inport: '<Root>/Inport2'
     *  Inport: '<Root>/Inport3'
     *  Inport: '<Root>/Inport4'
     *  Inport: '<Root>/Inport5'
     *  Inport: '<Root>/Inport6'
     */
    rtb_MatrixMultiply[0] = rtU.ambientT - 24.567529928829476;
    rtb_MatrixMultiply[1] = rtU.coolantT - 36.927770343469525;
    rtb_MatrixMultiply[2] = rtU.u_d - -22.942627627794394;
    rtb_MatrixMultiply[3] = rtU.u_q - 54.304549505064806;
    rtb_MatrixMultiply[4] = rtU.motor_speed - 2173.5779562216553;
    rtb_MatrixMultiply[5] = rtU.i_d - -66.932673992189038;
    rtb_MatrixMultiply[6] = rtU.i_q - 35.316949634986543;

    /* Outputs for Atomic SubSystem: '<S1>/Neural State Space Model' */
    /* Delay: '<S5>/Delay' */
    rtb_Delay[0] = rtDW.Delay_DSTATE[0];

    /* Outputs for Atomic SubSystem: '<S8>/fc1' */
    /* Product: '<S15>/Matrix Multiply' incorporates:
     *  Delay: '<S5>/Delay'
     */
    tmp[0] = rtDW.Delay_DSTATE[0];

    /* End of Outputs for SubSystem: '<S8>/fc1' */

    /* Delay: '<S5>/Delay' */
    rtb_Delay[1] = rtDW.Delay_DSTATE[1];

    /* Outputs for Atomic SubSystem: '<S8>/fc1' */
    /* Product: '<S15>/Matrix Multiply' incorporates:
     *  Delay: '<S5>/Delay'
     */
    tmp[1] = rtDW.Delay_DSTATE[1];

    /* End of Outputs for SubSystem: '<S8>/fc1' */

    /* Delay: '<S5>/Delay' */
    rtb_Delay[2] = rtDW.Delay_DSTATE[2];

    /* Outputs for Atomic SubSystem: '<S8>/fc1' */
    /* Product: '<S15>/Matrix Multiply' incorporates:
     *  Delay: '<S5>/Delay'
     */
    tmp[2] = rtDW.Delay_DSTATE[2];

    /* End of Outputs for SubSystem: '<S8>/fc1' */

    /* Delay: '<S5>/Delay' */
    rtb_Delay[3] = rtDW.Delay_DSTATE[3];

    /* Outputs for Atomic SubSystem: '<S8>/fc1' */
    /* Product: '<S15>/Matrix Multiply' incorporates:
     *  Delay: '<S5>/Delay'
     *  Gain: '<S4>/Gain1'
     */
    tmp[3] = rtDW.Delay_DSTATE[3];
    for (i = 0; i < 7; i++) {
      tmp[i + 4] = rtConstP.Gain1_Gain[i] * rtb_MatrixMultiply[i];
    }

    /* Sum: '<S49>/Add' incorporates:
     *  Constant: '<S15>/Bias'
     *  Constant: '<S15>/Weights'
     *  Product: '<S15>/Matrix Multiply'
     */
    for (i = 0; i < 64; i++) {
      tmp_0 = 0.0;
      for (i_0 = 0; i_0 < 11; i_0++) {
        tmp_0 += rtConstP.Weights_Value_p[(i_0 << 6) + i] * tmp[i_0];
      }

      rtb_Add_o[i] = tmp_0 + rtConstP.Bias_Value_o[i];
    }

    /* End of Sum: '<S49>/Add' */
    /* End of Outputs for SubSystem: '<S8>/fc1' */

    /* Outputs for Atomic SubSystem: '<S8>/act1' */
    act1(rtb_Add_o, rtb_MatrixMultiply);

    /* End of Outputs for SubSystem: '<S8>/act1' */

    /* Outputs for Atomic SubSystem: '<S8>/fc2' */
    /* Sum: '<S55>/Add' incorporates:
     *  Constant: '<S16>/Bias'
     *  Constant: '<S16>/Weights'
     *  Product: '<S16>/Matrix Multiply'
     *  Trigonometry: '<S39>/Tanh'
     */
    for (i = 0; i < 64; i++) {
      tmp_0 = 0.0;
      for (i_0 = 0; i_0 < 64; i_0++) {
        tmp_0 += rtConstP.Weights_Value_e[(i_0 << 6) + i] *
          rtb_MatrixMultiply[i_0];
      }

      rtb_Add_o[i] = tmp_0 + rtConstP.Bias_Value_b[i];
    }

    /* End of Sum: '<S55>/Add' */
    /* End of Outputs for SubSystem: '<S8>/fc2' */

    /* Outputs for Atomic SubSystem: '<S8>/act2' */
    act1(rtb_Add_o, rtb_MatrixMultiply);

    /* End of Outputs for SubSystem: '<S8>/act2' */

    /* Outputs for Atomic SubSystem: '<S8>/fc3' */
    /* Sum: '<S61>/Add' incorporates:
     *  Constant: '<S17>/Bias'
     *  Constant: '<S17>/Weights'
     *  Product: '<S17>/Matrix Multiply'
     *  Trigonometry: '<S39>/Tanh'
     */
    for (i = 0; i < 64; i++) {
      tmp_0 = 0.0;
      for (i_0 = 0; i_0 < 64; i_0++) {
        tmp_0 += rtConstP.Weights_Value_m[(i_0 << 6) + i] *
          rtb_MatrixMultiply[i_0];
      }

      rtb_Add_o[i] = tmp_0 + rtConstP.Bias_Value_k[i];
    }

    /* End of Sum: '<S61>/Add' */
    /* End of Outputs for SubSystem: '<S8>/fc3' */

    /* Outputs for Atomic SubSystem: '<S8>/act3' */
    act1(rtb_Add_o, rtb_MatrixMultiply);

    /* End of Outputs for SubSystem: '<S8>/act3' */

    /* Outputs for Atomic SubSystem: '<S8>/fc4' */
    /* Sum: '<S67>/Add' incorporates:
     *  Constant: '<S18>/Bias'
     *  Constant: '<S18>/Weights'
     *  Product: '<S18>/Matrix Multiply'
     *  Trigonometry: '<S39>/Tanh'
     */
    for (i = 0; i < 64; i++) {
      tmp_0 = 0.0;
      for (i_0 = 0; i_0 < 64; i_0++) {
        tmp_0 += rtConstP.Weights_Value_d[(i_0 << 6) + i] *
          rtb_MatrixMultiply[i_0];
      }

      rtb_Add_o[i] = tmp_0 + rtConstP.Bias_Value_a[i];
    }

    /* End of Sum: '<S67>/Add' */
    /* End of Outputs for SubSystem: '<S8>/fc4' */

    /* Outputs for Atomic SubSystem: '<S8>/act4' */
    act1(rtb_Add_o, rtb_MatrixMultiply);

    /* End of Outputs for SubSystem: '<S8>/act4' */

    /* Outputs for Atomic SubSystem: '<S8>/fc5' */
    /* Sum: '<S73>/Add' incorporates:
     *  Constant: '<S19>/Bias'
     *  Constant: '<S19>/Weights'
     *  Product: '<S19>/Matrix Multiply'
     *  Trigonometry: '<S39>/Tanh'
     */
    for (i = 0; i < 64; i++) {
      tmp_0 = 0.0;
      for (i_0 = 0; i_0 < 64; i_0++) {
        tmp_0 += rtConstP.Weights_Value_f[(i_0 << 6) + i] *
          rtb_MatrixMultiply[i_0];
      }

      rtb_Add_o[i] = tmp_0 + rtConstP.Bias_Value_n[i];
    }

    /* End of Sum: '<S73>/Add' */
    /* End of Outputs for SubSystem: '<S8>/fc5' */

    /* Outputs for Atomic SubSystem: '<S8>/act5' */
    act1(rtb_Add_o, rtb_MatrixMultiply);

    /* End of Outputs for SubSystem: '<S8>/act5' */
    for (i = 0; i < 4; i++) {
      /* Update for Delay: '<S5>/Delay' incorporates:
       *  Constant: '<S14>/Bias'
       *  Constant: '<S14>/Weights'
       *  Product: '<S14>/Matrix Multiply'
       *  Sum: '<S43>/Add'
       *  Sum: '<S5>/Add'
       *  Trigonometry: '<S39>/Tanh'
       */
      tmp_0 = 0.0;
      for (i_0 = 0; i_0 < 64; i_0++) {
        /* Outputs for Atomic SubSystem: '<S8>/dx' */
        tmp_0 += rtConstP.Weights_Value[(i_0 << 2) + i] * rtb_MatrixMultiply[i_0];

        /* End of Outputs for SubSystem: '<S8>/dx' */
      }

      /* Outputs for Atomic SubSystem: '<S8>/dx' */
      rtDW.Delay_DSTATE[i] += tmp_0 + rtConstP.Bias_Value[i];

      /* End of Update for Delay: '<S5>/Delay' */
      /* End of Outputs for SubSystem: '<S8>/dx' */

      /* Sum: '<S2>/Add' incorporates:
       *  Constant: '<S2>/Constant'
       *  Gain: '<S2>/Gain'
       */
      rtb_Delay[i] = (real32_T)(rtConstP.Gain_Gain[i] * rtb_Delay[i]) +
        rtConstP.Constant_Value[i];
    }

    /* End of Outputs for SubSystem: '<S1>/Neural State Space Model' */

    /* Outport: '<Root>/Out1' */
    rtY.Out1 = rtb_Delay[0];

    /* Outport: '<Root>/Out2' */
    rtY.Out2 = rtb_Delay[1];

    /* Outport: '<Root>/Out3' */
    rtY.Out3 = rtb_Delay[2];

    /* Outport: '<Root>/Out4' */
    rtY.Out4 = rtb_Delay[3];
  }

  rate_scheduler();
}

/* Model initialize function */
void PMSM_ROM_NSS_CodeGeneration_initialize(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S1>/Neural State Space Model' */
  /* InitializeConditions for Delay: '<S5>/Delay' */
  rtDW.Delay_DSTATE[0] = -1.4912;
  rtDW.Delay_DSTATE[1] = -1.0704;
  rtDW.Delay_DSTATE[2] = -1.2954;
  rtDW.Delay_DSTATE[3] = -1.3511;

  /* End of SystemInitialize for SubSystem: '<S1>/Neural State Space Model' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
