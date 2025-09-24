/*
 * Neural0.c
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

#include "Neural0.h"
#include "rtwtypes.h"
#include "Neural0_private.h"
#include <math.h>
#include <emmintrin.h>
#include <string.h>

/* Block signals (default storage) */
B_Neural0_T Neural0_B;

/* Block states (default storage) */
DW_Neural0_T Neural0_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Neural0_T Neural0_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Neural0_T Neural0_Y;

/* Real-time model */
static RT_MODEL_Neural0_T Neural0_M_;
RT_MODEL_Neural0_T *const Neural0_M = &Neural0_M_;

/*
 * Output and update for atomic system:
 *    '<S8>/act1'
 *    '<S8>/act2'
 *    '<S8>/act3'
 *    '<S8>/act4'
 */
void Neural0_act1(const real_T rtu_In1[16], B_act1_Neural0_T *localB)
{
  int32_T i;
  for (i = 0; i < 16; i++) {
    /* Trigonometry: '<S19>/Tanh' */
    localB->Tanh[i] = tanh(rtu_In1[i]);
  }
}

/*
 * Output and update for atomic system:
 *    '<S8>/fc2'
 *    '<S8>/fc3'
 *    '<S8>/fc4'
 */
void Neural0_fc2(const real_T rtu_In1[16], B_fc2_Neural0_T *localB,
                 P_fc2_Neural0_T *localP)
{
  int32_T i;
  int32_T i_0;
  for (i = 0; i < 16; i++) {
    real_T tmp;

    /* Sum: '<S36>/Add' incorporates:
     *  Constant: '<S15>/Bias'
     *  Constant: '<S15>/Weights'
     *  Product: '<S15>/Matrix Multiply'
     */
    tmp = 0.0;
    for (i_0 = 0; i_0 < 16; i_0++) {
      tmp += localP->Weights_Value[(i_0 << 4) + i] * rtu_In1[i_0];
    }

    localB->Add[i] = tmp + localP->Bias_Value[i];

    /* End of Sum: '<S36>/Add' */
  }
}

/* Model step function */
void Neural0_step(void)
{
  real_T rtb_Add_m[16];
  real_T tmp[5];
  real_T rtb_Delay[2];
  real_T rtb_IC;
  real_T rtb_IC1;
  int32_T i;
  int32_T i_0;

  /* InitialCondition: '<S1>/IC' incorporates:
   *  Inport: '<Root>/Inport1'
   */
  if (Neural0_DW.IC_FirstOutputTime) {
    Neural0_DW.IC_FirstOutputTime = false;
    rtb_IC = Neural0_P.SOCs;
  } else {
    rtb_IC = Neural0_U.Inport1;
  }

  /* End of InitialCondition: '<S1>/IC' */

  /* Outport: '<Root>/NSS SOC' */
  Neural0_Y.NSSSOC = rtb_IC;

  /* InitialCondition: '<S1>/IC1' incorporates:
   *  Inport: '<Root>/Inport2'
   */
  if (Neural0_DW.IC1_FirstOutputTime) {
    Neural0_DW.IC1_FirstOutputTime = false;
    rtb_IC1 = Neural0_P.Ts;
  } else {
    rtb_IC1 = Neural0_U.temperature;
  }

  /* End of InitialCondition: '<S1>/IC1' */

  /* Outputs for Atomic SubSystem: '<S1>/Neural State Space Model' */
  /* Delay: '<S5>/Delay' */
  rtb_Delay[0] = Neural0_DW.Delay_DSTATE[0];

  /* Outputs for Atomic SubSystem: '<S8>/fc1' */
  /* Product: '<S14>/Matrix Multiply' incorporates:
   *  Delay: '<S5>/Delay'
   */
  tmp[0] = Neural0_DW.Delay_DSTATE[0];

  /* End of Outputs for SubSystem: '<S8>/fc1' */

  /* Delay: '<S5>/Delay' */
  rtb_Delay[1] = Neural0_DW.Delay_DSTATE[1];

  /* Outputs for Atomic SubSystem: '<S8>/fc1' */
  /* Product: '<S14>/Matrix Multiply' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Delay: '<S5>/Delay'
   *  Gain: '<S4>/Gain1'
   *  Inport: '<Root>/Current'
   *  Sum: '<S4>/Add1'
   */
  tmp[1] = Neural0_DW.Delay_DSTATE[1];
  _mm_storeu_pd(&tmp[2], _mm_mul_pd(_mm_sub_pd(_mm_set_pd(rtb_IC,
    Neural0_U.InputCurrent), _mm_loadu_pd(&Neural0_P.Constant1_Value[0])),
    _mm_loadu_pd(&Neural0_P.Gain1_Gain[0])));
  tmp[4] = (rtb_IC1 - Neural0_P.Constant1_Value[2]) * Neural0_P.Gain1_Gain[2];

  /* Sum: '<S32>/Add' incorporates:
   *  Constant: '<S14>/Bias'
   *  Constant: '<S14>/Weights'
   *  Product: '<S14>/Matrix Multiply'
   */
  for (i = 0; i < 16; i++) {
    rtb_IC = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_IC += Neural0_P.Weights_Value_m[(i_0 << 4) + i] * tmp[i_0];
    }

    rtb_Add_m[i] = rtb_IC + Neural0_P.Bias_Value_k[i];
  }

  /* End of Sum: '<S32>/Add' */
  /* End of Outputs for SubSystem: '<S8>/fc1' */

  /* Outputs for Atomic SubSystem: '<S8>/act1' */
  Neural0_act1(rtb_Add_m, &Neural0_B.act1);

  /* End of Outputs for SubSystem: '<S8>/act1' */

  /* Outputs for Atomic SubSystem: '<S8>/fc2' */
  Neural0_fc2(Neural0_B.act1.Tanh, &Neural0_B.fc2, &Neural0_P.fc2);

  /* End of Outputs for SubSystem: '<S8>/fc2' */

  /* Outputs for Atomic SubSystem: '<S8>/act2' */
  Neural0_act1(Neural0_B.fc2.Add, &Neural0_B.act2);

  /* End of Outputs for SubSystem: '<S8>/act2' */

  /* Outputs for Atomic SubSystem: '<S8>/fc3' */
  Neural0_fc2(Neural0_B.act2.Tanh, &Neural0_B.fc3, &Neural0_P.fc3);

  /* End of Outputs for SubSystem: '<S8>/fc3' */

  /* Outputs for Atomic SubSystem: '<S8>/act3' */
  Neural0_act1(Neural0_B.fc3.Add, &Neural0_B.act3);

  /* End of Outputs for SubSystem: '<S8>/act3' */

  /* Outputs for Atomic SubSystem: '<S8>/fc4' */
  Neural0_fc2(Neural0_B.act3.Tanh, &Neural0_B.fc4, &Neural0_P.fc4);

  /* End of Outputs for SubSystem: '<S8>/fc4' */

  /* Outputs for Atomic SubSystem: '<S8>/act4' */
  Neural0_act1(Neural0_B.fc4.Add, &Neural0_B.act4);

  /* End of Outputs for SubSystem: '<S8>/act4' */
  for (i = 0; i < 2; i++) {
    /* Update for Delay: '<S5>/Delay' incorporates:
     *  Constant: '<S13>/Bias'
     *  Constant: '<S13>/Weights'
     *  Product: '<S13>/Matrix Multiply'
     *  Sum: '<S28>/Add'
     *  Sum: '<S5>/Add'
     *  Trigonometry: '<S25>/Tanh'
     */
    rtb_IC = 0.0;
    for (i_0 = 0; i_0 < 16; i_0++) {
      /* Outputs for Atomic SubSystem: '<S8>/dx' */
      rtb_IC += Neural0_P.Weights_Value[(i_0 << 1) + i] *
        Neural0_B.act4.Tanh[i_0];

      /* End of Outputs for SubSystem: '<S8>/dx' */
    }

    /* Outputs for Atomic SubSystem: '<S8>/dx' */
    Neural0_DW.Delay_DSTATE[i] += rtb_IC + Neural0_P.Bias_Value[i];

    /* End of Update for Delay: '<S5>/Delay' */
    /* End of Outputs for SubSystem: '<S8>/dx' */

    /* Sum: '<S2>/Add' incorporates:
     *  Constant: '<S2>/Constant'
     *  Gain: '<S2>/Gain'
     */
    rtb_Delay[i] = (real32_T)(Neural0_P.Gain_Gain[i] * rtb_Delay[i]) +
      Neural0_P.Constant_Value[i];
  }

  /* End of Outputs for SubSystem: '<S1>/Neural State Space Model' */

  /* Outport: '<Root>/NSS Temperature' */
  Neural0_Y.NSSTemperature = rtb_Delay[0];

  /* Outport: '<Root>/NSS Voltage' */
  Neural0_Y.NSSVoltage = rtb_Delay[1];

  /* Matfile logging */
  rt_UpdateTXYLogVars(Neural0_M->rtwLogInfo, (&Neural0_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [1.0s, 0.0s] */
    if ((rtmGetTFinal(Neural0_M)!=-1) &&
        !((rtmGetTFinal(Neural0_M)-Neural0_M->Timing.taskTime0) >
          Neural0_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Neural0_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Neural0_M->Timing.clockTick0)) {
    ++Neural0_M->Timing.clockTickH0;
  }

  Neural0_M->Timing.taskTime0 = Neural0_M->Timing.clockTick0 *
    Neural0_M->Timing.stepSize0 + Neural0_M->Timing.clockTickH0 *
    Neural0_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Neural0_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Neural0_M, 0,
                sizeof(RT_MODEL_Neural0_T));
  rtmSetTFinal(Neural0_M, 1068.0);
  Neural0_M->Timing.stepSize0 = 1.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Neural0_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Neural0_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Neural0_M->rtwLogInfo, (NULL));
    rtliSetLogT(Neural0_M->rtwLogInfo, "tout");
    rtliSetLogX(Neural0_M->rtwLogInfo, "");
    rtliSetLogXFinal(Neural0_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Neural0_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Neural0_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Neural0_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Neural0_M->rtwLogInfo, 1);
    rtliSetLogY(Neural0_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Neural0_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Neural0_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &Neural0_B), 0,
                sizeof(B_Neural0_T));

  /* states (dwork) */
  (void) memset((void *)&Neural0_DW, 0,
                sizeof(DW_Neural0_T));

  /* external inputs */
  (void)memset(&Neural0_U, 0, sizeof(ExtU_Neural0_T));

  /* external outputs */
  (void)memset(&Neural0_Y, 0, sizeof(ExtY_Neural0_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Neural0_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Neural0_M), Neural0_M->Timing.stepSize0, (&rtmGetErrorStatus(Neural0_M)));

  /* Start for InitialCondition: '<S1>/IC' */
  Neural0_DW.IC_FirstOutputTime = true;

  /* Start for InitialCondition: '<S1>/IC1' */
  Neural0_DW.IC1_FirstOutputTime = true;

  /* SystemInitialize for Atomic SubSystem: '<S1>/Neural State Space Model' */
  /* InitializeConditions for Delay: '<S5>/Delay' */
  Neural0_DW.Delay_DSTATE[0] = Neural0_P.Delay_InitialCondition[0];
  Neural0_DW.Delay_DSTATE[1] = Neural0_P.Delay_InitialCondition[1];

  /* End of SystemInitialize for SubSystem: '<S1>/Neural State Space Model' */
}

/* Model terminate function */
void Neural0_terminate(void)
{
  /* (no terminate code required) */
}
