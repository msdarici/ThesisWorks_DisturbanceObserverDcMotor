/*
 * DOB_Gravity_DcMotor_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DOB_Gravity_DcMotor".
 *
 * Model version              : 1.8
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Sun Oct 25 20:07:34 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef DOB_Gravity_DcMotor_types_h_
#define DOB_Gravity_DcMotor_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_LouLjD93OM6ZIgZUcV1N0E_
#define DEFINED_TYPEDEF_FOR_struct_LouLjD93OM6ZIgZUcV1N0E_

typedef struct {
  real_T N;
  real_T eta;
  real_T Jg;
  real_T Bg;
  real_T Bv;
  real_T Fc;
  real_T Fs;
  real_T ws;
  real_T we;
  real_T Fstr;
} struct_LouLjD93OM6ZIgZUcV1N0E;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_ZldpYwsFWSyhiUAlTz4FKE_
#define DEFINED_TYPEDEF_FOR_struct_ZldpYwsFWSyhiUAlTz4FKE_

typedef struct {
  real_T Kp;
  real_T Ki;
  real_T Kd;
  real_T Kaw;
} struct_ZldpYwsFWSyhiUAlTz4FKE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_s1qcXHnLiVOcS8IFh0hdcH_
#define DEFINED_TYPEDEF_FOR_struct_s1qcXHnLiVOcS8IFh0hdcH_

typedef struct {
  struct_ZldpYwsFWSyhiUAlTz4FKE akim;
  struct_ZldpYwsFWSyhiUAlTz4FKE hiz;
  struct_ZldpYwsFWSyhiUAlTz4FKE poz;
} struct_s1qcXHnLiVOcS8IFh0hdcH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_fbNKwZuyDdXrBw3dOuMkZB_
#define DEFINED_TYPEDEF_FOR_struct_fbNKwZuyDdXrBw3dOuMkZB_

typedef struct {
  real_T Kt;
  real_T Ke;
  real_T Rs;
  real_T Ls;
  real_T Jr;
  real_T Br;
  real_T Bv;
  real_T Fc;
  real_T Fs;
  real_T ws;
  real_T we;
  real_T Fstr;
} struct_fbNKwZuyDdXrBw3dOuMkZB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_cQzxaHQdOTqgNSFbGrzjcB_
#define DEFINED_TYPEDEF_FOR_struct_cQzxaHQdOTqgNSFbGrzjcB_

typedef struct {
  real_T J;
  real_T tau_yuk_katsayisi;
} struct_cQzxaHQdOTqgNSFbGrzjcB;

#endif

/* Parameters (default storage) */
typedef struct P_DOB_Gravity_DcMotor_T_ P_DOB_Gravity_DcMotor_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_DOB_Gravity_DcMotor_T RT_MODEL_DOB_Gravity_DcMotor_T;

#endif                                 /* DOB_Gravity_DcMotor_types_h_ */
