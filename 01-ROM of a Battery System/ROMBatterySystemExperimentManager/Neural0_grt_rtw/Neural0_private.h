/*
 * Neural0_private.h
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

#ifndef Neural0_private_h_
#define Neural0_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "Neural0.h"
#include "Neural0_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern void Neural0_act1(const real_T rtu_In1[16], B_act1_Neural0_T *localB);
extern void Neural0_fc2(const real_T rtu_In1[16], B_fc2_Neural0_T *localB,
  P_fc2_Neural0_T *localP);

#endif                                 /* Neural0_private_h_ */
