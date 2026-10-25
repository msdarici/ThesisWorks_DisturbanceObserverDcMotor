/*
 * DOB_Gravity_DcMotor_data.c
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

#include "DOB_Gravity_DcMotor.h"

/* Block parameters (default storage) */
P_DOB_Gravity_DcMotor_T DOB_Gravity_DcMotor_P = {
  /* Variable: M1
   * Referenced by:
   *   '<S5>/Gain'
   *   '<S5>/Gain1'
   *   '<S5>/Gain2'
   *   '<S5>/Gain3'
   *   '<S5>/Gain6'
   *   '<S6>/Gain'
   *   '<S6>/Gain2'
   *   '<S6>/Gain3'
   *   '<S6>/Gain4'
   */
  {
    0.00932,
    0.0093620554759938426,
    5.3,
    0.00014,
    8.5e-8,
    5.0e-6,
    5.0e-6,
    0.0,
    0.0,
    0.1,
    0.05,
    0.0
  },

  /* Variable: kontrolculer
   * Referenced by:
   *   '<S41>/Integral Gain'
   *   '<S42>/Proportional Gain'
   *   '<S101>/Proportional Gain'
   *   '<S141>/Kb'
   *   '<S146>/Integral Gain'
   *   '<S147>/Proportional Gain'
   */
  {
    {
      4.39822971502571,
      166504.41064025904,
      0.0,
      0.0
    },

    {
      0.48380526865282814,
      0.14279966607226333,
      0.0,
      0.0
    },

    {
      1256.6370614359173,
      0.0,
      0.0,
      0.0
    }
  },

  /* Variable: G1
   * Referenced by:
   *   '<S1>/Gain12'
   *   '<S2>/Gain8'
   *   '<S3>/Gain'
   *   '<S3>/Gain2'
   *   '<S3>/Gain3'
   *   '<S3>/Gain4'
   */
  {
    20.0,
    1.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.1,
    0.05,
    0.0
  },

  /* Variable: Joint1
   * Referenced by:
   *   '<Root>/Gain5'
   *   '<Root>/Gain7'
   */
  {
    0.000154,
    0.012654899999999998
  },

  /* Mask Parameter: HizPI_InitialConditionForIntegr
   * Referenced by: '<S44>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S149>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_LowerSaturationLi
   * Referenced by: '<S156>/Saturation'
   */
  -24.0,

  /* Mask Parameter: RepeatingSequenceStair_OutValue
   * Referenced by: '<S7>/Vector'
   */
  { 3.0, 1.0, 4.0, 2.0, 1.0 },

  /* Mask Parameter: PIDController_UpperSaturationLi
   * Referenced by: '<S156>/Saturation'
   */
  24.0,

  /* Mask Parameter: LimitedCounter_uplimit
   * Referenced by: '<S169>/FixPt Switch'
   */
  4U,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator1'
   */
  0.0,

  /* Expression: 0.001
   * Referenced by: '<S4>/IC1'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator2'
   */
  0.0,

  /* Expression: 0.001
   * Referenced by: '<S4>/IC'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator'
   */
  0.0,

  /* Expression: 1/P.ws^2
   * Referenced by: '<S6>/Gain5'
   */
  99.999999999999986,

  /* Expression: -1
   * Referenced by: '<S6>/Gain1'
   */
  -1.0,

  /* Expression: 1/P.ws^2
   * Referenced by: '<S3>/Gain5'
   */
  99.999999999999986,

  /* Expression: -1
   * Referenced by: '<S3>/Gain1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S5>/IC'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/IC1'
   */
  0.0,

  /* Expression: 24
   * Referenced by: '<S5>/Saturation'
   */
  24.0,

  /* Expression: -24
   * Referenced by: '<S5>/Saturation'
   */
  -24.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S169>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S167>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S168>/FixPt Constant'
   */
  1U
};
