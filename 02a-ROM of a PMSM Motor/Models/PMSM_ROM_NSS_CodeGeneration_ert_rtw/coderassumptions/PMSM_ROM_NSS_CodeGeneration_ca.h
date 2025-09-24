/*
 * File: PMSM_ROM_NSS_CodeGeneration_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef PMSM_ROM_NSS_CODEGENERATION_CA_H
#define PMSM_ROM_NSS_CODEGENERATION_CA_H

/* preprocessor validation checks */
#include "PMSM_ROM_NSS_CodeGeneration_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_PMSM_ROM_NSS_CodeGeneration_HWRes;
extern CA_PWS_TestResults CA_PMSM_ROM_NSS_CodeGeneration_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_PMSM_ROM_NSS_CodeGeneration_ExpHW;
extern CA_HWImpl CA_PMSM_ROM_NSS_CodeGeneration_ActHW;

/* entry point function to run tests */
void PMSM_ROM_NSS_CodeGeneration_caRunTests(void);

#endif                                 /* PMSM_ROM_NSS_CODEGENERATION_CA_H */
