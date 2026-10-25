/*
 * DOB_Gravity_DcMotor.c
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
#include "rtwtypes.h"
#include <math.h>
#include "DOB_Gravity_DcMotor_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Block signals (default storage) */
B_DOB_Gravity_DcMotor_T DOB_Gravity_DcMotor_B;

/* Continuous states */
X_DOB_Gravity_DcMotor_T DOB_Gravity_DcMotor_X;

/* Disabled State Vector */
XDis_DOB_Gravity_DcMotor_T DOB_Gravity_DcMotor_XDis;

/* Block states (default storage) */
DW_DOB_Gravity_DcMotor_T DOB_Gravity_DcMotor_DW;

/* Real-time model */
static RT_MODEL_DOB_Gravity_DcMotor_T DOB_Gravity_DcMotor_M_;
RT_MODEL_DOB_Gravity_DcMotor_T *const DOB_Gravity_DcMotor_M =
  &DOB_Gravity_DcMotor_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  DOB_Gravity_DcMotor_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  DOB_Gravity_DcMotor_step();
  DOB_Gravity_DcMotor_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  DOB_Gravity_DcMotor_step();
  DOB_Gravity_DcMotor_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp, tmp_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void DOB_Gravity_DcMotor_step(void)
{
  /* local block i/o variables */
  uint8_T rtb_FixPtSwitch;
  real_T rtb_ProportionalGain;
  real_T rtb_Saturation;
  real_T rtb_Sum1_k;
  real_T u0;
  uint8_T rtb_Output;
  boolean_T tmp;
  if (rtmIsMajorTimeStep(DOB_Gravity_DcMotor_M)) {
    /* set solver stop time */
    if (!(DOB_Gravity_DcMotor_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&DOB_Gravity_DcMotor_M->solverInfo,
                            ((DOB_Gravity_DcMotor_M->Timing.clockTickH0 + 1) *
        DOB_Gravity_DcMotor_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&DOB_Gravity_DcMotor_M->solverInfo,
                            ((DOB_Gravity_DcMotor_M->Timing.clockTick0 + 1) *
        DOB_Gravity_DcMotor_M->Timing.stepSize0 +
        DOB_Gravity_DcMotor_M->Timing.clockTickH0 *
        DOB_Gravity_DcMotor_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(DOB_Gravity_DcMotor_M)) {
    DOB_Gravity_DcMotor_M->Timing.t[0] = rtsiGetT
      (&DOB_Gravity_DcMotor_M->solverInfo);
  }

  tmp = rtmIsMajorTimeStep(DOB_Gravity_DcMotor_M);
  if (tmp) {
    /* UnitDelay: '<S167>/Output' */
    rtb_Output = DOB_Gravity_DcMotor_DW.Output_DSTATE;

    /* MultiPortSwitch: '<S7>/Output' incorporates:
     *  Constant: '<S7>/Vector'
     *  UnitDelay: '<S167>/Output'
     */
    DOB_Gravity_DcMotor_B.Output =
      DOB_Gravity_DcMotor_P.RepeatingSequenceStair_OutValue[DOB_Gravity_DcMotor_DW.Output_DSTATE];
  }

  /* Integrator: '<Root>/Integrator1' */
  DOB_Gravity_DcMotor_B.Integrator1 = DOB_Gravity_DcMotor_X.Integrator1_CSTATE;

  /* InitialCondition: '<S4>/IC1' incorporates:
   *  InitialCondition: '<S4>/IC'
   *  InitialCondition: '<S5>/IC'
   *  InitialCondition: '<S5>/IC1'
   */
  rtb_Saturation = DOB_Gravity_DcMotor_M->Timing.t[0];
  if ((DOB_Gravity_DcMotor_DW.IC1_FirstOutputTime == (rtMinusInf)) ||
      (DOB_Gravity_DcMotor_DW.IC1_FirstOutputTime == rtb_Saturation)) {
    DOB_Gravity_DcMotor_DW.IC1_FirstOutputTime = rtb_Saturation;
    rtb_ProportionalGain = DOB_Gravity_DcMotor_P.IC1_Value;
  } else {
    rtb_ProportionalGain = DOB_Gravity_DcMotor_B.Integrator1;
  }

  /* Gain: '<S101>/Proportional Gain' incorporates:
   *  Sum: '<S4>/Sum2'
   */
  DOB_Gravity_DcMotor_B.ProportionalGain = (DOB_Gravity_DcMotor_B.Output -
    rtb_ProportionalGain) * DOB_Gravity_DcMotor_P.kontrolculer.poz.Kp;

  /* Integrator: '<Root>/Integrator2' */
  DOB_Gravity_DcMotor_B.Integrator2 = DOB_Gravity_DcMotor_X.Integrator2_CSTATE;

  /* Gain: '<S1>/Gain12' */
  DOB_Gravity_DcMotor_B.Gain12 = DOB_Gravity_DcMotor_P.G1.N *
    DOB_Gravity_DcMotor_B.Integrator2;

  /* InitialCondition: '<S4>/IC' incorporates:
   *  InitialCondition: '<S4>/IC1'
   */
  if ((DOB_Gravity_DcMotor_DW.IC_FirstOutputTime == (rtMinusInf)) ||
      (DOB_Gravity_DcMotor_DW.IC_FirstOutputTime == rtb_Saturation)) {
    DOB_Gravity_DcMotor_DW.IC_FirstOutputTime = rtb_Saturation;
    rtb_ProportionalGain = DOB_Gravity_DcMotor_P.IC_Value;
  } else {
    rtb_ProportionalGain = DOB_Gravity_DcMotor_B.Gain12;
  }

  /* Sum: '<S4>/Sum3' */
  rtb_ProportionalGain = DOB_Gravity_DcMotor_B.ProportionalGain -
    rtb_ProportionalGain;

  /* Gain: '<S42>/Proportional Gain' incorporates:
   *  Integrator: '<S44>/Integrator'
   *  Sum: '<S53>/Sum'
   */
  DOB_Gravity_DcMotor_B.ProportionalGain_f = (rtb_ProportionalGain +
    DOB_Gravity_DcMotor_X.Integrator_CSTATE) *
    DOB_Gravity_DcMotor_P.kontrolculer.hiz.Kp;

  /* Integrator: '<S5>/Integrator' */
  DOB_Gravity_DcMotor_B.Integrator = DOB_Gravity_DcMotor_X.Integrator_CSTATE_e;

  /* Gain: '<S5>/Gain3' */
  DOB_Gravity_DcMotor_B.Gain3 = DOB_Gravity_DcMotor_P.M1.Kt *
    DOB_Gravity_DcMotor_B.Integrator;

  /* Trigonometry: '<Root>/Sin' incorporates:
   *  Trigonometry: '<Root>/Sin1'
   */
  rtb_Sum1_k = sin(DOB_Gravity_DcMotor_B.Integrator1);

  /* Gain: '<Root>/Gain7' incorporates:
   *  Trigonometry: '<Root>/Sin'
   */
  DOB_Gravity_DcMotor_B.Gain7 = DOB_Gravity_DcMotor_P.Joint1.tau_yuk_katsayisi *
    rtb_Sum1_k;
  if (tmp) {
  }

  /* Trigonometry: '<Root>/Atan2' incorporates:
   *  Trigonometry: '<Root>/Cos'
   */
  DOB_Gravity_DcMotor_B.Atan2 = rt_atan2d_snf(rtb_Sum1_k, cos
    (DOB_Gravity_DcMotor_B.Integrator1));
  if (tmp) {
  }

  /* Gain: '<S6>/Gain4' */
  DOB_Gravity_DcMotor_B.ViskozSurtunme = DOB_Gravity_DcMotor_P.M1.Bv *
    DOB_Gravity_DcMotor_B.Gain12;

  /* Trigonometry: '<S6>/Tanh' incorporates:
   *  Gain: '<S6>/Gain3'
   */
  rtb_Sum1_k = tanh(1.0 / DOB_Gravity_DcMotor_P.M1.we *
                    DOB_Gravity_DcMotor_B.Gain12);

  /* Gain: '<S6>/Gain' */
  DOB_Gravity_DcMotor_B.CoulombSurtunmesiKinetik = DOB_Gravity_DcMotor_P.M1.Fc *
    rtb_Sum1_k;

  /* Product: '<S6>/Product1' incorporates:
   *  Gain: '<S6>/Gain1'
   *  Gain: '<S6>/Gain2'
   *  Gain: '<S6>/Gain5'
   *  Math: '<S6>/Exp'
   *  Math: '<S6>/Square'
   *
   * About '<S6>/Exp':
   *  Operator: exp
   */
  DOB_Gravity_DcMotor_B.Product1 = exp(DOB_Gravity_DcMotor_B.Gain12 *
    DOB_Gravity_DcMotor_B.Gain12 * DOB_Gravity_DcMotor_P.Gain5_Gain *
    DOB_Gravity_DcMotor_P.Gain1_Gain) * DOB_Gravity_DcMotor_P.M1.Fstr *
    rtb_Sum1_k;

  /* Sum: '<S6>/Sum' */
  DOB_Gravity_DcMotor_B.Sum = (DOB_Gravity_DcMotor_B.ViskozSurtunme +
    DOB_Gravity_DcMotor_B.CoulombSurtunmesiKinetik) +
    DOB_Gravity_DcMotor_B.Product1;

  /* Gain: '<S2>/Gain8' incorporates:
   *  Sum: '<Root>/Sum1'
   */
  DOB_Gravity_DcMotor_B.Gain8 = (DOB_Gravity_DcMotor_B.Gain3 -
    DOB_Gravity_DcMotor_B.Sum) * DOB_Gravity_DcMotor_P.G1.N;
  if (tmp) {
  }

  /* Gain: '<S3>/Gain4' */
  DOB_Gravity_DcMotor_B.ViskozSurtunme_b = DOB_Gravity_DcMotor_P.G1.Bv *
    DOB_Gravity_DcMotor_B.Integrator2;

  /* Trigonometry: '<S3>/Tanh' incorporates:
   *  Gain: '<S3>/Gain3'
   */
  rtb_Sum1_k = tanh(1.0 / DOB_Gravity_DcMotor_P.G1.we *
                    DOB_Gravity_DcMotor_B.Integrator2);

  /* Gain: '<S3>/Gain' */
  DOB_Gravity_DcMotor_B.CoulombSurtunmesiKinetik_a = DOB_Gravity_DcMotor_P.G1.Fc
    * rtb_Sum1_k;

  /* Product: '<S3>/Product1' incorporates:
   *  Gain: '<S3>/Gain1'
   *  Gain: '<S3>/Gain2'
   *  Gain: '<S3>/Gain5'
   *  Math: '<S3>/Exp'
   *  Math: '<S3>/Square'
   *
   * About '<S3>/Exp':
   *  Operator: exp
   */
  DOB_Gravity_DcMotor_B.Product1_k = exp(DOB_Gravity_DcMotor_B.Integrator2 *
    DOB_Gravity_DcMotor_B.Integrator2 * DOB_Gravity_DcMotor_P.Gain5_Gain_a *
    DOB_Gravity_DcMotor_P.Gain1_Gain_l) * DOB_Gravity_DcMotor_P.G1.Fstr *
    rtb_Sum1_k;

  /* Sum: '<S3>/Sum' */
  DOB_Gravity_DcMotor_B.Sum_p = (DOB_Gravity_DcMotor_B.ViskozSurtunme_b +
    DOB_Gravity_DcMotor_B.CoulombSurtunmesiKinetik_a) +
    DOB_Gravity_DcMotor_B.Product1_k;
  if (tmp) {
  }

  /* Gain: '<Root>/Gain5' incorporates:
   *  Sum: '<Root>/Sum'
   */
  DOB_Gravity_DcMotor_B.Gain5 = ((DOB_Gravity_DcMotor_B.Gain8 +
    DOB_Gravity_DcMotor_B.Gain7) - DOB_Gravity_DcMotor_B.Sum_p) * (1.0 /
    DOB_Gravity_DcMotor_P.Joint1.J);

  /* Gain: '<S41>/Integral Gain' */
  DOB_Gravity_DcMotor_B.IntegralGain = DOB_Gravity_DcMotor_P.kontrolculer.hiz.Ki
    * rtb_ProportionalGain;

  /* InitialCondition: '<S5>/IC' incorporates:
   *  InitialCondition: '<S4>/IC1'
   */
  if ((DOB_Gravity_DcMotor_DW.IC_FirstOutputTime_g == (rtMinusInf)) ||
      (DOB_Gravity_DcMotor_DW.IC_FirstOutputTime_g == rtb_Saturation)) {
    DOB_Gravity_DcMotor_DW.IC_FirstOutputTime_g = rtb_Saturation;
    rtb_Sum1_k = DOB_Gravity_DcMotor_P.IC_Value_c;
  } else {
    rtb_Sum1_k = DOB_Gravity_DcMotor_B.Integrator;
  }

  /* Gain: '<S5>/Gain2' */
  DOB_Gravity_DcMotor_B.Gain2 = DOB_Gravity_DcMotor_P.M1.Rs * rtb_Sum1_k;

  /* InitialCondition: '<S5>/IC1' incorporates:
   *  InitialCondition: '<S4>/IC1'
   */
  if ((DOB_Gravity_DcMotor_DW.IC1_FirstOutputTime_a == (rtMinusInf)) ||
      (DOB_Gravity_DcMotor_DW.IC1_FirstOutputTime_a == rtb_Saturation)) {
    DOB_Gravity_DcMotor_DW.IC1_FirstOutputTime_a = rtb_Saturation;
    rtb_Sum1_k = DOB_Gravity_DcMotor_P.IC1_Value_i;
  } else {
    rtb_Sum1_k = DOB_Gravity_DcMotor_B.Gain12;
  }

  /* Gain: '<S5>/Gain1' */
  DOB_Gravity_DcMotor_B.Gain1 = DOB_Gravity_DcMotor_P.M1.Ke * rtb_Sum1_k;

  /* Sum: '<S5>/Sum1' incorporates:
   *  Gain: '<S5>/Gain'
   *  Sum: '<Root>/Sum2'
   */
  rtb_Sum1_k = 1.0 / DOB_Gravity_DcMotor_P.M1.Kt * (DOB_Gravity_DcMotor_B.Gain7
    + DOB_Gravity_DcMotor_B.ProportionalGain_f) -
    DOB_Gravity_DcMotor_B.Integrator;

  /* Gain: '<S147>/Proportional Gain' incorporates:
   *  Integrator: '<S149>/Integrator'
   *  Sum: '<S158>/Sum'
   */
  rtb_ProportionalGain = (rtb_Sum1_k + DOB_Gravity_DcMotor_X.Integrator_CSTATE_f)
    * DOB_Gravity_DcMotor_P.kontrolculer.akim.Kp;

  /* Saturate: '<S156>/Saturation' */
  if (rtb_ProportionalGain >
      DOB_Gravity_DcMotor_P.PIDController_UpperSaturationLi) {
    rtb_Saturation = DOB_Gravity_DcMotor_P.PIDController_UpperSaturationLi;
  } else if (rtb_ProportionalGain <
             DOB_Gravity_DcMotor_P.PIDController_LowerSaturationLi) {
    rtb_Saturation = DOB_Gravity_DcMotor_P.PIDController_LowerSaturationLi;
  } else {
    rtb_Saturation = rtb_ProportionalGain;
  }

  /* End of Saturate: '<S156>/Saturation' */

  /* Sum: '<S5>/Sum' */
  u0 = DOB_Gravity_DcMotor_B.Gain1 + rtb_Saturation;

  /* Saturate: '<S5>/Saturation' */
  if (u0 > DOB_Gravity_DcMotor_P.Saturation_UpperSat) {
    /* Saturate: '<S5>/Saturation' */
    DOB_Gravity_DcMotor_B.Saturation = DOB_Gravity_DcMotor_P.Saturation_UpperSat;
  } else if (u0 < DOB_Gravity_DcMotor_P.Saturation_LowerSat) {
    /* Saturate: '<S5>/Saturation' */
    DOB_Gravity_DcMotor_B.Saturation = DOB_Gravity_DcMotor_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S5>/Saturation' */
    DOB_Gravity_DcMotor_B.Saturation = u0;
  }

  /* End of Saturate: '<S5>/Saturation' */
  if (tmp) {
  }

  /* Gain: '<S5>/Gain6' incorporates:
   *  Sum: '<S5>/Add'
   */
  DOB_Gravity_DcMotor_B.Gain6 = ((DOB_Gravity_DcMotor_B.Saturation -
    DOB_Gravity_DcMotor_B.Gain2) - DOB_Gravity_DcMotor_B.Gain1) * (1.0 /
    DOB_Gravity_DcMotor_P.M1.Ls);

  /* Sum: '<S141>/SumI4' incorporates:
   *  Gain: '<S141>/Kb'
   *  Gain: '<S146>/Integral Gain'
   *  Sum: '<S141>/SumI2'
   */
  DOB_Gravity_DcMotor_B.SumI4 = (rtb_Saturation - rtb_ProportionalGain) *
    DOB_Gravity_DcMotor_P.kontrolculer.akim.Ki +
    DOB_Gravity_DcMotor_P.kontrolculer.akim.Ki * rtb_Sum1_k;
  if (tmp) {
    /* Sum: '<S168>/FixPt Sum1' incorporates:
     *  Constant: '<S168>/FixPt Constant'
     */
    rtb_Output += DOB_Gravity_DcMotor_P.FixPtConstant_Value;

    /* Switch: '<S169>/FixPt Switch' */
    if (rtb_Output > DOB_Gravity_DcMotor_P.LimitedCounter_uplimit) {
      /* Switch: '<S169>/FixPt Switch' incorporates:
       *  Constant: '<S169>/Constant'
       */
      rtb_FixPtSwitch = DOB_Gravity_DcMotor_P.Constant_Value;
    } else {
      /* Switch: '<S169>/FixPt Switch' */
      rtb_FixPtSwitch = rtb_Output;
    }

    /* End of Switch: '<S169>/FixPt Switch' */
  }

  if (rtmIsMajorTimeStep(DOB_Gravity_DcMotor_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(DOB_Gravity_DcMotor_M->rtwLogInfo,
                        (DOB_Gravity_DcMotor_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(DOB_Gravity_DcMotor_M)) {
    if (rtmIsMajorTimeStep(DOB_Gravity_DcMotor_M)) {
      /* Update for UnitDelay: '<S167>/Output' */
      DOB_Gravity_DcMotor_DW.Output_DSTATE = rtb_FixPtSwitch;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(DOB_Gravity_DcMotor_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(DOB_Gravity_DcMotor_M)!=-1) &&
          !((rtmGetTFinal(DOB_Gravity_DcMotor_M)-
             (((DOB_Gravity_DcMotor_M->Timing.clockTick1+
                DOB_Gravity_DcMotor_M->Timing.clockTickH1* 4294967296.0)) * 0.2))
            > (((DOB_Gravity_DcMotor_M->Timing.clockTick1+
                 DOB_Gravity_DcMotor_M->Timing.clockTickH1* 4294967296.0)) * 0.2)
            * (DBL_EPSILON))) {
        rtmSetErrorStatus(DOB_Gravity_DcMotor_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&DOB_Gravity_DcMotor_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++DOB_Gravity_DcMotor_M->Timing.clockTick0)) {
      ++DOB_Gravity_DcMotor_M->Timing.clockTickH0;
    }

    DOB_Gravity_DcMotor_M->Timing.t[0] = rtsiGetSolverStopTime
      (&DOB_Gravity_DcMotor_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.2s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.2, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      DOB_Gravity_DcMotor_M->Timing.clockTick1++;
      if (!DOB_Gravity_DcMotor_M->Timing.clockTick1) {
        DOB_Gravity_DcMotor_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void DOB_Gravity_DcMotor_derivatives(void)
{
  XDot_DOB_Gravity_DcMotor_T *_rtXdot;
  _rtXdot = ((XDot_DOB_Gravity_DcMotor_T *) DOB_Gravity_DcMotor_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = DOB_Gravity_DcMotor_B.Integrator2;

  /* Derivatives for Integrator: '<Root>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = DOB_Gravity_DcMotor_B.Gain5;

  /* Derivatives for Integrator: '<S44>/Integrator' */
  _rtXdot->Integrator_CSTATE = DOB_Gravity_DcMotor_B.IntegralGain;

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE_e = DOB_Gravity_DcMotor_B.Gain6;

  /* Derivatives for Integrator: '<S149>/Integrator' */
  _rtXdot->Integrator_CSTATE_f = DOB_Gravity_DcMotor_B.SumI4;
}

/* Model initialize function */
void DOB_Gravity_DcMotor_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)DOB_Gravity_DcMotor_M, 0,
                sizeof(RT_MODEL_DOB_Gravity_DcMotor_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&DOB_Gravity_DcMotor_M->solverInfo,
                          &DOB_Gravity_DcMotor_M->Timing.simTimeStep);
    rtsiSetTPtr(&DOB_Gravity_DcMotor_M->solverInfo, &rtmGetTPtr
                (DOB_Gravity_DcMotor_M));
    rtsiSetStepSizePtr(&DOB_Gravity_DcMotor_M->solverInfo,
                       &DOB_Gravity_DcMotor_M->Timing.stepSize0);
    rtsiSetdXPtr(&DOB_Gravity_DcMotor_M->solverInfo,
                 &DOB_Gravity_DcMotor_M->derivs);
    rtsiSetContStatesPtr(&DOB_Gravity_DcMotor_M->solverInfo, (real_T **)
                         &DOB_Gravity_DcMotor_M->contStates);
    rtsiSetNumContStatesPtr(&DOB_Gravity_DcMotor_M->solverInfo,
      &DOB_Gravity_DcMotor_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&DOB_Gravity_DcMotor_M->solverInfo,
      &DOB_Gravity_DcMotor_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&DOB_Gravity_DcMotor_M->solverInfo,
      &DOB_Gravity_DcMotor_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&DOB_Gravity_DcMotor_M->solverInfo,
      &DOB_Gravity_DcMotor_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&DOB_Gravity_DcMotor_M->solverInfo, (boolean_T**)
      &DOB_Gravity_DcMotor_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&DOB_Gravity_DcMotor_M->solverInfo,
                          (&rtmGetErrorStatus(DOB_Gravity_DcMotor_M)));
    rtsiSetRTModelPtr(&DOB_Gravity_DcMotor_M->solverInfo, DOB_Gravity_DcMotor_M);
  }

  rtsiSetSimTimeStep(&DOB_Gravity_DcMotor_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&DOB_Gravity_DcMotor_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&DOB_Gravity_DcMotor_M->solverInfo, false);
  DOB_Gravity_DcMotor_M->intgData.y = DOB_Gravity_DcMotor_M->odeY;
  DOB_Gravity_DcMotor_M->intgData.f[0] = DOB_Gravity_DcMotor_M->odeF[0];
  DOB_Gravity_DcMotor_M->intgData.f[1] = DOB_Gravity_DcMotor_M->odeF[1];
  DOB_Gravity_DcMotor_M->intgData.f[2] = DOB_Gravity_DcMotor_M->odeF[2];
  DOB_Gravity_DcMotor_M->contStates = ((X_DOB_Gravity_DcMotor_T *)
    &DOB_Gravity_DcMotor_X);
  DOB_Gravity_DcMotor_M->contStateDisabled = ((XDis_DOB_Gravity_DcMotor_T *)
    &DOB_Gravity_DcMotor_XDis);
  DOB_Gravity_DcMotor_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&DOB_Gravity_DcMotor_M->solverInfo, (void *)
                    &DOB_Gravity_DcMotor_M->intgData);
  rtsiSetSolverName(&DOB_Gravity_DcMotor_M->solverInfo,"ode3");
  rtmSetTPtr(DOB_Gravity_DcMotor_M, &DOB_Gravity_DcMotor_M->Timing.tArray[0]);
  rtmSetTFinal(DOB_Gravity_DcMotor_M, 1.0);
  DOB_Gravity_DcMotor_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    DOB_Gravity_DcMotor_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(DOB_Gravity_DcMotor_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(DOB_Gravity_DcMotor_M->rtwLogInfo, (NULL));
    rtliSetLogT(DOB_Gravity_DcMotor_M->rtwLogInfo, "tout");
    rtliSetLogX(DOB_Gravity_DcMotor_M->rtwLogInfo, "");
    rtliSetLogXFinal(DOB_Gravity_DcMotor_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(DOB_Gravity_DcMotor_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(DOB_Gravity_DcMotor_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(DOB_Gravity_DcMotor_M->rtwLogInfo, 0);
    rtliSetLogDecimation(DOB_Gravity_DcMotor_M->rtwLogInfo, 1);
    rtliSetLogY(DOB_Gravity_DcMotor_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(DOB_Gravity_DcMotor_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(DOB_Gravity_DcMotor_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &DOB_Gravity_DcMotor_B), 0,
                sizeof(B_DOB_Gravity_DcMotor_T));

  /* states (continuous) */
  {
    (void) memset((void *)&DOB_Gravity_DcMotor_X, 0,
                  sizeof(X_DOB_Gravity_DcMotor_T));
  }

  /* disabled states */
  {
    (void) memset((void *)&DOB_Gravity_DcMotor_XDis, 0,
                  sizeof(XDis_DOB_Gravity_DcMotor_T));
  }

  /* states (dwork) */
  (void) memset((void *)&DOB_Gravity_DcMotor_DW, 0,
                sizeof(DW_DOB_Gravity_DcMotor_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(DOB_Gravity_DcMotor_M->rtwLogInfo, 0.0,
    rtmGetTFinal(DOB_Gravity_DcMotor_M), DOB_Gravity_DcMotor_M->Timing.stepSize0,
    (&rtmGetErrorStatus(DOB_Gravity_DcMotor_M)));

  /* Start for InitialCondition: '<S4>/IC1' */
  DOB_Gravity_DcMotor_DW.IC1_FirstOutputTime = (rtMinusInf);

  /* Start for InitialCondition: '<S4>/IC' */
  DOB_Gravity_DcMotor_DW.IC_FirstOutputTime = (rtMinusInf);

  /* Start for InitialCondition: '<S5>/IC' */
  DOB_Gravity_DcMotor_DW.IC_FirstOutputTime_g = (rtMinusInf);

  /* Start for InitialCondition: '<S5>/IC1' */
  DOB_Gravity_DcMotor_DW.IC1_FirstOutputTime_a = (rtMinusInf);

  /* InitializeConditions for UnitDelay: '<S167>/Output' */
  DOB_Gravity_DcMotor_DW.Output_DSTATE =
    DOB_Gravity_DcMotor_P.Output_InitialCondition;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  DOB_Gravity_DcMotor_X.Integrator1_CSTATE =
    DOB_Gravity_DcMotor_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  DOB_Gravity_DcMotor_X.Integrator2_CSTATE =
    DOB_Gravity_DcMotor_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S44>/Integrator' */
  DOB_Gravity_DcMotor_X.Integrator_CSTATE =
    DOB_Gravity_DcMotor_P.HizPI_InitialConditionForIntegr;

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  DOB_Gravity_DcMotor_X.Integrator_CSTATE_e =
    DOB_Gravity_DcMotor_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S149>/Integrator' */
  DOB_Gravity_DcMotor_X.Integrator_CSTATE_f =
    DOB_Gravity_DcMotor_P.PIDController_InitialConditionF;
}

/* Model terminate function */
void DOB_Gravity_DcMotor_terminate(void)
{
  /* (no terminate code required) */
}
