/*
 * File: PMSM_ROM_NSS_CodeGeneration_ca.c
 *
 * Abstract: Tests assumptions in the generated code.
 */

#include "PMSM_ROM_NSS_CodeGeneration_ca.h"

CA_HWImpl_TestResults CA_PMSM_ROM_NSS_CodeGeneration_HWRes;
CA_PWS_TestResults CA_PMSM_ROM_NSS_CodeGeneration_PWSRes;
const CA_HWImpl CA_PMSM_ROM_NSS_CodeGeneration_ExpHW = {
  8,                                   /* BitPerChar */
  16,                                  /* BitPerShort */
  32,                                  /* BitPerInt */
  32,                                  /* BitPerLong */
  64,                                  /* BitPerLongLong */
  32,                                  /* BitPerFloat */
  64,                                  /* BitPerDouble */
  32,                                  /* BitPerPointer */
  32,                                  /* BitPerSizeT */
  32,                                  /* BitPerPtrDiffT */
  CA_LITTLE_ENDIAN,                    /* Endianess */
  CA_ZERO,                             /* IntDivRoundTo */
  1,                                   /* ShiftRightIntArith */
  1,                                   /* LongLongMode */
  0,                                   /* PortableWordSizes */
  "Intel->x86-32 (Windows32)",         /* HWDeviceType */
  0,                                   /* MemoryAtStartup */
  0,                                   /* DynamicMemoryAtStartup */
  0,                                   /* DenormalFlushToZero */
  0                                    /* DenormalAsZero */
};

CA_HWImpl CA_PMSM_ROM_NSS_CodeGeneration_ActHW = {
  0,                                   /* BitPerChar */
  0,                                   /* BitPerShort */
  0,                                   /* BitPerInt */
  0,                                   /* BitPerLong */
  0,                                   /* BitPerLongLong */
  0,                                   /* BitPerFloat */
  0,                                   /* BitPerDouble */
  0,                                   /* BitPerPointer */
  0,                                   /* BitPerSizeT */
  0,                                   /* BitPerPtrDiffT */
  CA_UNSPECIFIED,                      /* Endianess */
  CA_UNDEFINED,                        /* IntDivRoundTo */
  0,                                   /* ShiftRightIntArith */
  0,                                   /* LongLongMode */
  0,                                   /* PortableWordSizes */
  "",                                  /* HWDeviceType */
  0,                                   /* MemoryAtStartup */
  0,                                   /* DynamicMemoryAtStartup */
  0,                                   /* DenormalFlushToZero */
  0                                    /* DenormalAsZero */
};

void PMSM_ROM_NSS_CodeGeneration_caRunTests(void)
{
  /* verify hardware implementation */
  caVerifyPortableWordSizes(&CA_PMSM_ROM_NSS_CodeGeneration_ActHW,
    &CA_PMSM_ROM_NSS_CodeGeneration_ExpHW,
    &CA_PMSM_ROM_NSS_CodeGeneration_PWSRes);
  caVerifyHWImpl(&CA_PMSM_ROM_NSS_CodeGeneration_ActHW,
                 &CA_PMSM_ROM_NSS_CodeGeneration_ExpHW,
                 &CA_PMSM_ROM_NSS_CodeGeneration_HWRes);
}
