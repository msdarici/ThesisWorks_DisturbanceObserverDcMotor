/*
 * DOB_Gravity_DcMotor.h
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

#ifndef DOB_Gravity_DcMotor_h_
#define DOB_Gravity_DcMotor_h_
#ifndef DOB_Gravity_DcMotor_COMMON_INCLUDES_
#define DOB_Gravity_DcMotor_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                /* DOB_Gravity_DcMotor_COMMON_INCLUDES_ */

#include "DOB_Gravity_DcMotor_types.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include <float.h>
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Output;                       /* '<S7>/Output' */
  real_T Integrator1;                  /* '<Root>/Integrator1' */
  real_T ProportionalGain;             /* '<S101>/Proportional Gain' */
  real_T Integrator2;                  /* '<Root>/Integrator2' */
  real_T Gain12;                       /* '<S1>/Gain12' */
  real_T ProportionalGain_f;           /* '<S42>/Proportional Gain' */
  real_T Integrator;                   /* '<S5>/Integrator' */
  real_T Gain3;                        /* '<S5>/Gain3' */
  real_T Gain7;                        /* '<Root>/Gain7' */
  real_T Atan2;                        /* '<Root>/Atan2' */
  real_T ViskozSurtunme;               /* '<S6>/Gain4' */
  real_T CoulombSurtunmesiKinetik;     /* '<S6>/Gain' */
  real_T Product1;                     /* '<S6>/Product1' */
  real_T Sum;                          /* '<S6>/Sum' */
  real_T Gain8;                        /* '<S2>/Gain8' */
  real_T ViskozSurtunme_b;             /* '<S3>/Gain4' */
  real_T CoulombSurtunmesiKinetik_a;   /* '<S3>/Gain' */
  real_T Product1_k;                   /* '<S3>/Product1' */
  real_T Sum_p;                        /* '<S3>/Sum' */
  real_T Gain5;                        /* '<Root>/Gain5' */
  real_T IntegralGain;                 /* '<S41>/Integral Gain' */
  real_T Gain2;                        /* '<S5>/Gain2' */
  real_T Gain1;                        /* '<S5>/Gain1' */
  real_T Saturation;                   /* '<S5>/Saturation' */
  real_T Gain6;                        /* '<S5>/Gain6' */
  real_T SumI4;                        /* '<S141>/SumI4' */
} B_DOB_Gravity_DcMotor_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T IC1_FirstOutputTime;          /* '<S4>/IC1' */
  real_T IC_FirstOutputTime;           /* '<S4>/IC' */
  real_T IC_FirstOutputTime_g;         /* '<S5>/IC' */
  real_T IC1_FirstOutputTime_a;        /* '<S5>/IC1' */
  uint8_T Output_DSTATE;               /* '<S167>/Output' */
} DW_DOB_Gravity_DcMotor_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<S44>/Integrator' */
  real_T Integrator_CSTATE_e;          /* '<S5>/Integrator' */
  real_T Integrator_CSTATE_f;          /* '<S149>/Integrator' */
} X_DOB_Gravity_DcMotor_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<S44>/Integrator' */
  real_T Integrator_CSTATE_e;          /* '<S5>/Integrator' */
  real_T Integrator_CSTATE_f;          /* '<S149>/Integrator' */
} XDot_DOB_Gravity_DcMotor_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<Root>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<Root>/Integrator2' */
  boolean_T Integrator_CSTATE;         /* '<S44>/Integrator' */
  boolean_T Integrator_CSTATE_e;       /* '<S5>/Integrator' */
  boolean_T Integrator_CSTATE_f;       /* '<S149>/Integrator' */
} XDis_DOB_Gravity_DcMotor_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_DOB_Gravity_DcMotor_T_ {
  struct_fbNKwZuyDdXrBw3dOuMkZB M1;    /* Variable: M1
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
  struct_s1qcXHnLiVOcS8IFh0hdcH kontrolculer;/* Variable: kontrolculer
                                              * Referenced by:
                                              *   '<S41>/Integral Gain'
                                              *   '<S42>/Proportional Gain'
                                              *   '<S101>/Proportional Gain'
                                              *   '<S141>/Kb'
                                              *   '<S146>/Integral Gain'
                                              *   '<S147>/Proportional Gain'
                                              */
  struct_LouLjD93OM6ZIgZUcV1N0E G1;    /* Variable: G1
                                        * Referenced by:
                                        *   '<S1>/Gain12'
                                        *   '<S2>/Gain8'
                                        *   '<S3>/Gain'
                                        *   '<S3>/Gain2'
                                        *   '<S3>/Gain3'
                                        *   '<S3>/Gain4'
                                        */
  struct_cQzxaHQdOTqgNSFbGrzjcB Joint1;/* Variable: Joint1
                                        * Referenced by:
                                        *   '<Root>/Gain5'
                                        *   '<Root>/Gain7'
                                        */
  real_T HizPI_InitialConditionForIntegr;
                              /* Mask Parameter: HizPI_InitialConditionForIntegr
                               * Referenced by: '<S44>/Integrator'
                               */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S149>/Integrator'
                               */
  real_T PIDController_LowerSaturationLi;
                              /* Mask Parameter: PIDController_LowerSaturationLi
                               * Referenced by: '<S156>/Saturation'
                               */
  real_T RepeatingSequenceStair_OutValue[5];
                              /* Mask Parameter: RepeatingSequenceStair_OutValue
                               * Referenced by: '<S7>/Vector'
                               */
  real_T PIDController_UpperSaturationLi;
                              /* Mask Parameter: PIDController_UpperSaturationLi
                               * Referenced by: '<S156>/Saturation'
                               */
  uint8_T LimitedCounter_uplimit;      /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S169>/FixPt Switch'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T IC1_Value;                    /* Expression: 0.001
                                        * Referenced by: '<S4>/IC1'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  real_T IC_Value;                     /* Expression: 0.001
                                        * Referenced by: '<S4>/IC'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S5>/Integrator'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1/P.ws^2
                                        * Referenced by: '<S6>/Gain5'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T Gain5_Gain_a;                 /* Expression: 1/P.ws^2
                                        * Referenced by: '<S3>/Gain5'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: -1
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T IC_Value_c;                   /* Expression: 0
                                        * Referenced by: '<S5>/IC'
                                        */
  real_T IC1_Value_i;                  /* Expression: 0
                                        * Referenced by: '<S5>/IC1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 24
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -24
                                        * Referenced by: '<S5>/Saturation'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S169>/Constant'
                                        */
  uint8_T Output_InitialCondition;/* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S167>/Output'
                                   */
  uint8_T FixPtConstant_Value;        /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S168>/FixPt Constant'
                                       */
};

/* Real-time Model Data Structure */
struct tag_RTM_DOB_Gravity_DcMotor_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_DOB_Gravity_DcMotor_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_DOB_Gravity_DcMotor_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[5];
  real_T odeF[3][5];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_DOB_Gravity_DcMotor_T DOB_Gravity_DcMotor_P;

/* Block signals (default storage) */
extern B_DOB_Gravity_DcMotor_T DOB_Gravity_DcMotor_B;

/* Continuous states (default storage) */
extern X_DOB_Gravity_DcMotor_T DOB_Gravity_DcMotor_X;

/* Disabled states (default storage) */
extern XDis_DOB_Gravity_DcMotor_T DOB_Gravity_DcMotor_XDis;

/* Block states (default storage) */
extern DW_DOB_Gravity_DcMotor_T DOB_Gravity_DcMotor_DW;

/* Model entry point functions */
extern void DOB_Gravity_DcMotor_initialize(void);
extern void DOB_Gravity_DcMotor_step(void);
extern void DOB_Gravity_DcMotor_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DOB_Gravity_DcMotor_T *const DOB_Gravity_DcMotor_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'DOB_Gravity_DcMotor'
 * '<S1>'   : 'DOB_Gravity_DcMotor/Disli Geri'
 * '<S2>'   : 'DOB_Gravity_DcMotor/Disli Ileri'
 * '<S3>'   : 'DOB_Gravity_DcMotor/Disli Surtunme Modeli'
 * '<S4>'   : 'DOB_Gravity_DcMotor/HizPozKontrolcu'
 * '<S5>'   : 'DOB_Gravity_DcMotor/Motor'
 * '<S6>'   : 'DOB_Gravity_DcMotor/Motor Surtunme Modeli'
 * '<S7>'   : 'DOB_Gravity_DcMotor/Repeating Sequence Stair'
 * '<S8>'   : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI'
 * '<S9>'   : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1'
 * '<S10>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Anti-windup'
 * '<S11>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/D Gain'
 * '<S12>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/External Derivative'
 * '<S13>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Filter'
 * '<S14>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Filter ICs'
 * '<S15>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/I Gain'
 * '<S16>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Ideal P Gain'
 * '<S17>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Ideal P Gain Fdbk'
 * '<S18>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Integrator'
 * '<S19>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Integrator ICs'
 * '<S20>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/N Copy'
 * '<S21>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/N Gain'
 * '<S22>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/P Copy'
 * '<S23>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Parallel P Gain'
 * '<S24>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Reset Signal'
 * '<S25>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Saturation'
 * '<S26>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Saturation Fdbk'
 * '<S27>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Sum'
 * '<S28>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Sum Fdbk'
 * '<S29>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Tracking Mode'
 * '<S30>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Tracking Mode Sum'
 * '<S31>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Tsamp - Integral'
 * '<S32>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Tsamp - Ngain'
 * '<S33>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/postSat Signal'
 * '<S34>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/preInt Signal'
 * '<S35>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/preSat Signal'
 * '<S36>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Anti-windup/Passthrough'
 * '<S37>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/D Gain/Disabled'
 * '<S38>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/External Derivative/Disabled'
 * '<S39>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Filter/Disabled'
 * '<S40>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Filter ICs/Disabled'
 * '<S41>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/I Gain/Internal Parameters'
 * '<S42>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Ideal P Gain/Internal Parameters'
 * '<S43>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Ideal P Gain Fdbk/Disabled'
 * '<S44>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Integrator/Continuous'
 * '<S45>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Integrator ICs/Internal IC'
 * '<S46>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/N Copy/Disabled wSignal Specification'
 * '<S47>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/N Gain/Disabled'
 * '<S48>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/P Copy/Disabled'
 * '<S49>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Parallel P Gain/Passthrough'
 * '<S50>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Reset Signal/Disabled'
 * '<S51>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Saturation/Passthrough'
 * '<S52>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Saturation Fdbk/Disabled'
 * '<S53>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Sum/Sum_PI'
 * '<S54>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Sum Fdbk/Disabled'
 * '<S55>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Tracking Mode/Disabled'
 * '<S56>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Tracking Mode Sum/Passthrough'
 * '<S57>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Tsamp - Integral/TsSignalSpecification'
 * '<S58>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/Tsamp - Ngain/Passthrough'
 * '<S59>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/postSat Signal/Forward_Path'
 * '<S60>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/preInt Signal/Internal PreInt'
 * '<S61>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/HizPI/preSat Signal/Forward_Path'
 * '<S62>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Anti-windup'
 * '<S63>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/D Gain'
 * '<S64>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/External Derivative'
 * '<S65>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Filter'
 * '<S66>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Filter ICs'
 * '<S67>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/I Gain'
 * '<S68>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Ideal P Gain'
 * '<S69>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Ideal P Gain Fdbk'
 * '<S70>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Integrator'
 * '<S71>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Integrator ICs'
 * '<S72>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/N Copy'
 * '<S73>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/N Gain'
 * '<S74>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/P Copy'
 * '<S75>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Parallel P Gain'
 * '<S76>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Reset Signal'
 * '<S77>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Saturation'
 * '<S78>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Saturation Fdbk'
 * '<S79>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Sum'
 * '<S80>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Sum Fdbk'
 * '<S81>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Tracking Mode'
 * '<S82>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Tracking Mode Sum'
 * '<S83>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Tsamp - Integral'
 * '<S84>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Tsamp - Ngain'
 * '<S85>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/postSat Signal'
 * '<S86>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/preInt Signal'
 * '<S87>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/preSat Signal'
 * '<S88>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Anti-windup/Disabled'
 * '<S89>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/D Gain/Disabled'
 * '<S90>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/External Derivative/Disabled'
 * '<S91>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Filter/Disabled'
 * '<S92>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Filter ICs/Disabled'
 * '<S93>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/I Gain/Disabled'
 * '<S94>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Ideal P Gain/Passthrough'
 * '<S95>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S96>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Integrator/Disabled'
 * '<S97>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Integrator ICs/Disabled'
 * '<S98>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S99>'  : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/N Gain/Disabled'
 * '<S100>' : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/P Copy/Disabled'
 * '<S101>' : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S102>' : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Reset Signal/Disabled'
 * '<S103>' : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Saturation/Passthrough'
 * '<S104>' : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Saturation Fdbk/Disabled'
 * '<S105>' : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Sum/Passthrough_P'
 * '<S106>' : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Sum Fdbk/Disabled'
 * '<S107>' : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Tracking Mode/Disabled'
 * '<S108>' : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S109>' : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S110>' : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S111>' : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/postSat Signal/Forward_Path'
 * '<S112>' : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/preInt Signal/Internal PreInt'
 * '<S113>' : 'DOB_Gravity_DcMotor/HizPozKontrolcu/PID Controller1/preSat Signal/Forward_Path'
 * '<S114>' : 'DOB_Gravity_DcMotor/Motor/PID Controller'
 * '<S115>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Anti-windup'
 * '<S116>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/D Gain'
 * '<S117>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/External Derivative'
 * '<S118>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Filter'
 * '<S119>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Filter ICs'
 * '<S120>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/I Gain'
 * '<S121>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Ideal P Gain'
 * '<S122>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Ideal P Gain Fdbk'
 * '<S123>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Integrator'
 * '<S124>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Integrator ICs'
 * '<S125>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/N Copy'
 * '<S126>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/N Gain'
 * '<S127>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/P Copy'
 * '<S128>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Parallel P Gain'
 * '<S129>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Reset Signal'
 * '<S130>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Saturation'
 * '<S131>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Saturation Fdbk'
 * '<S132>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Sum'
 * '<S133>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Sum Fdbk'
 * '<S134>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Tracking Mode'
 * '<S135>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Tracking Mode Sum'
 * '<S136>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Tsamp - Integral'
 * '<S137>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Tsamp - Ngain'
 * '<S138>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/postSat Signal'
 * '<S139>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/preInt Signal'
 * '<S140>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/preSat Signal'
 * '<S141>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Anti-windup/Back Calculation'
 * '<S142>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/D Gain/Disabled'
 * '<S143>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/External Derivative/Disabled'
 * '<S144>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Filter/Disabled'
 * '<S145>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Filter ICs/Disabled'
 * '<S146>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/I Gain/Internal Parameters'
 * '<S147>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Ideal P Gain/Internal Parameters'
 * '<S148>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S149>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Integrator/Continuous'
 * '<S150>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Integrator ICs/Internal IC'
 * '<S151>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S152>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/N Gain/Disabled'
 * '<S153>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/P Copy/Disabled'
 * '<S154>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Parallel P Gain/Passthrough'
 * '<S155>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Reset Signal/Disabled'
 * '<S156>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Saturation/Enabled'
 * '<S157>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Saturation Fdbk/Disabled'
 * '<S158>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Sum/Sum_PI'
 * '<S159>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Sum Fdbk/Disabled'
 * '<S160>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Tracking Mode/Disabled'
 * '<S161>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S162>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S163>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S164>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/postSat Signal/Forward_Path'
 * '<S165>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/preInt Signal/Internal PreInt'
 * '<S166>' : 'DOB_Gravity_DcMotor/Motor/PID Controller/preSat Signal/Forward_Path'
 * '<S167>' : 'DOB_Gravity_DcMotor/Repeating Sequence Stair/LimitedCounter'
 * '<S168>' : 'DOB_Gravity_DcMotor/Repeating Sequence Stair/LimitedCounter/Increment Real World'
 * '<S169>' : 'DOB_Gravity_DcMotor/Repeating Sequence Stair/LimitedCounter/Wrap To Zero'
 */
#endif                                 /* DOB_Gravity_DcMotor_h_ */
