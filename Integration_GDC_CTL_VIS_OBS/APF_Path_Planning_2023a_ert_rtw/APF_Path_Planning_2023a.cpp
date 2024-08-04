//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: APF_Path_Planning_2023a.cpp
//
// Code generated for Simulink model 'APF_Path_Planning_2023a'.
//
// Model version                  : 1.1080
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Fri Apr  5 15:13:21 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "APF_Path_Planning_2023a.h"
#include "rtwtypes.h"
#include "APF_Path_Planning_2023a_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"
#include <string.h>

// Block signals (default storage)
B_APF_Path_Planning_2023a_T APF_Path_Planning_2023a_B;

// Continuous states
X_APF_Path_Planning_2023a_T APF_Path_Planning_2023a_X;

// Block states (default storage)
DW_APF_Path_Planning_2023a_T APF_Path_Planning_2023a_DW;

// Real-time model
RT_MODEL_APF_Path_Planning_20_T APF_Path_Planning_2023a_M_ =
  RT_MODEL_APF_Path_Planning_20_T();
RT_MODEL_APF_Path_Planning_20_T *const APF_Path_Planning_2023a_M =
  &APF_Path_Planning_2023a_M_;

// Forward declaration for local functions
static real_T APF_Path_Planning_2023a_maximum(const real_T x[8]);

// Forward declaration for local functions
static real_T APF_Path_Planning_202_maximum_p(const real_T x[8]);

// Forward declaration for local functions
static real_T APF_Path_Planning_rt_atan2d_snf(real_T u0, real_T u1);
static real_T APF_Path_Planning_rt_hypotd_snf(real_T u0, real_T u1);
static real_T APF_Path_Planning_2_rt_powd_snf(real_T u0, real_T u1);
static real_T APF__rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
static real_T APF__rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);
static real_T APF_Path_Planning_2023a_xnrm2(int32_T n, const real_T x[36],
  int32_T ix0);
static real_T APF_Path_Planning_2023a_xdotc(int32_T n, const real_T x[36],
  int32_T ix0, const real_T y[36], int32_T iy0);
static void APF_Path_Planning_2023a_xaxpy(int32_T n, real_T a, int32_T ix0,
  real_T y[36], int32_T iy0);
static real_T APF_Path_Planning_2023a_xnrm2_c(int32_T n, const real_T x[6],
  int32_T ix0);
static void APF_Path_Planning_2023a_xaxpy_j(int32_T n, real_T a, const real_T x
  [36], int32_T ix0, real_T y[6], int32_T iy0);
static void APF_Path_Planning_2023_xaxpy_jv(int32_T n, real_T a, const real_T x
  [6], int32_T ix0, real_T y[36], int32_T iy0);
static void APF_Path_Planning_2023a_xswap(real_T x[36], int32_T ix0, int32_T iy0);
static void APF_Path_Planning_2023a_xrotg(real_T *a, real_T *b, real_T *c,
  real_T *s);
static void APF_Path_Planning_2023a_xrot(real_T x[36], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static void APF_Path_Planning_2023a_svd(const real_T A[36], real_T U[36], real_T
  s[6], real_T V[36]);
static void APF_Path_Plannin_rt_invd3x3_snf(const real_T u[9], real_T y[9]);

//
// This function updates continuous states using the ODE4 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = static_cast<ODE4_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  APF_Path_Planning_2023a_derivatives();

  // f1 = f(t + (h/2), y + (h/2)*f0)
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  APF_Path_Planning_2023a_step();
  APF_Path_Planning_2023a_derivatives();

  // f2 = f(t + (h/2), y + (h/2)*f1)
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  APF_Path_Planning_2023a_step();
  APF_Path_Planning_2023a_derivatives();

  // f3 = f(t + h, y + h*f2)
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  APF_Path_Planning_2023a_step();
  APF_Path_Planning_2023a_derivatives();

  // tnew = t + h
  // ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3)
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

//
// System initialize for action system:
//    '<S1>/Change BLACK Behavior'
//    '<S1>/Change BLUE Behavior'
//
void APF_Pa_ChangeBLACKBehavior_Init(RT_MODEL_APF_Path_Planning_20_T * const
  APF_Path_Planning_2023a_M, DW_ChangeBLACKBehavior_APF_Pa_T *localDW,
  P_ChangeBLACKBehavior_APF_Pat_T *localP)
{
  char_T *sErr;

  // Start for S-Function (sdspToNetwork): '<S20>/UDP Send'
  sErr = GetErrorBuffer(&localDW->UDPSend_NetworkLib[0U]);
  CreateUDPInterface(&localDW->UDPSend_NetworkLib[0U]);
  if (*sErr == 0) {
    LibCreate_Network(&localDW->UDPSend_NetworkLib[0U], 1, "0.0.0.0", -1,
                      "255.255.255.255", localP->UDPSend_Port, 8192, 4, 0);
  }

  if (*sErr == 0) {
    LibStart(&localDW->UDPSend_NetworkLib[0U]);
  }

  if (*sErr != 0) {
    DestroyUDPInterface(&localDW->UDPSend_NetworkLib[0U]);
    if (*sErr != 0) {
      rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
      rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
    }
  }

  // End of Start for S-Function (sdspToNetwork): '<S20>/UDP Send'
}

//
// Output and update for action system:
//    '<S1>/Change BLACK Behavior'
//    '<S1>/Change BLUE Behavior'
//
void APF_Path_Pl_ChangeBLACKBehavior(RT_MODEL_APF_Path_Planning_20_T * const
  APF_Path_Planning_2023a_M, DW_ChangeBLACKBehavior_APF_Pa_T *localDW,
  P_ChangeBLACKBehavior_APF_Pat_T *localP)
{
  char_T *sErr;

  // Update for S-Function (sdspToNetwork): '<S20>/UDP Send' incorporates:
  //   Constant: '<S20>/Constant1'

  sErr = GetErrorBuffer(&localDW->UDPSend_NetworkLib[0U]);
  LibUpdate_Network(&localDW->UDPSend_NetworkLib[0U], &localP->Constant1_Value,
                    1);
  if (*sErr != 0) {
    rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
    rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
  }

  // End of Update for S-Function (sdspToNetwork): '<S20>/UDP Send'
}

//
// Termination for action system:
//    '<S1>/Change BLACK Behavior'
//    '<S1>/Change BLUE Behavior'
//
void APF_Pa_ChangeBLACKBehavior_Term(RT_MODEL_APF_Path_Planning_20_T * const
  APF_Path_Planning_2023a_M, DW_ChangeBLACKBehavior_APF_Pa_T *localDW)
{
  char_T *sErr;

  // Terminate for S-Function (sdspToNetwork): '<S20>/UDP Send'
  sErr = GetErrorBuffer(&localDW->UDPSend_NetworkLib[0U]);
  LibTerminate(&localDW->UDPSend_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
    rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
  }

  LibDestroy(&localDW->UDPSend_NetworkLib[0U], 1);
  DestroyUDPInterface(&localDW->UDPSend_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S20>/UDP Send'
}

//
// Output and update for action system:
//    '<S6>/Change BLUE Behavior'
//    '<S7>/Change BLUE Behavior'
//    '<S12>/Change BLUE Behavior'
//
void APF_Path_Pla_ChangeBLUEBehavior(RT_MODEL_APF_Path_Planning_20_T * const
  APF_Path_Planning_2023a_M, real_T *rtd_BLUE_Fx, real_T *rtd_BLUE_Fy, real_T
  *rtd_BLUE_Tz, real_T *rtd_Float_State, P_ChangeBLUEBehavior_APF_Path_T *localP)
{
  if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
    // DataStoreWrite: '<S28>/BLUE_Fx' incorporates:
    //   Constant: '<S28>/Constant3'

    *rtd_BLUE_Fx = localP->Constant3_Value;

    // DataStoreWrite: '<S28>/BLUE_Fy' incorporates:
    //   Constant: '<S28>/Constant4'

    *rtd_BLUE_Fy = localP->Constant4_Value;

    // DataStoreWrite: '<S28>/BLUE_Tz' incorporates:
    //   Constant: '<S28>/Constant5'

    *rtd_BLUE_Tz = localP->Constant5_Value;

    // DataStoreWrite: '<S28>/Data Store Write4' incorporates:
    //   Constant: '<S28>/Puck State'

    *rtd_Float_State = localP->PuckState_Value;
  }
}

//
// System initialize for action system:
//    '<Root>/Phase #0: Synchronization'
//    '<Root>/Phase #1: Start Floating '
//
void APF__Phase0Synchronization_Init(DW_Phase0Synchronization_APF__T *localDW)
{
  // Start for If: '<S6>/This IF block determines whether or not to run the BLACK sim//exp' 
  localDW->ThisIFblockdetermineswhetherorn = -1;

  // Start for If: '<S6>/This IF block determines whether or not to run the BLUE sim//exp' 
  localDW->ThisIFblockdetermineswhethero_d = -1;

  // Start for If: '<S6>/This IF block determines whether or not to run the RED sim//exp ' 
  localDW->ThisIFblockdetermineswhethero_e = -1;
}

//
// Output and update for action system:
//    '<Root>/Phase #0: Synchronization'
//    '<Root>/Phase #1: Start Floating '
//
void APF_Path__Phase0Synchronization(RT_MODEL_APF_Path_Planning_20_T * const
  APF_Path_Planning_2023a_M, real_T *rtd_BLACK_Fx, real_T *rtd_BLACK_Fy, real_T *
  rtd_BLACK_Tz, real_T *rtd_BLUE_Fx, real_T *rtd_BLUE_Fy, real_T *rtd_BLUE_Tz,
  real_T *rtd_Float_State, real_T *rtd_RED_ARM_Control_Mode, real_T *rtd_RED_Fx,
  real_T *rtd_RED_Fy, real_T *rtd_RED_Tz, real_T *rtd_RED_Tz_RW, const real_T
  *rtd_WhoAmI, const real_T *rtd_isSim, DW_Phase0Synchronization_APF__T *localDW,
  P_Phase0Synchronization_APF_P_T *localP)
{
  int8_T rtAction;

  // If: '<S6>/This IF block determines whether or not to run the BLACK sim//exp' 
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
    if ((*rtd_WhoAmI == 2.0) || (*rtd_isSim == 1.0)) {
      rtAction = 0;
    }

    localDW->ThisIFblockdetermineswhetherorn = rtAction;
  } else {
    rtAction = localDW->ThisIFblockdetermineswhetherorn;
  }

  if (rtAction == 0) {
    // Outputs for IfAction SubSystem: '<S6>/Change BLACK Behavior' incorporates:
    //   ActionPort: '<S27>/Action Port'

    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // DataStoreWrite: '<S27>/BLACK_Fx' incorporates:
      //   Constant: '<S27>/Constant3'

      *rtd_BLACK_Fx = localP->Constant3_Value;

      // DataStoreWrite: '<S27>/BLACK_Fy' incorporates:
      //   Constant: '<S27>/Constant4'

      *rtd_BLACK_Fy = localP->Constant4_Value;

      // DataStoreWrite: '<S27>/BLACK_Tz' incorporates:
      //   Constant: '<S27>/Constant5'

      *rtd_BLACK_Tz = localP->Constant5_Value;

      // DataStoreWrite: '<S27>/Data Store Write4' incorporates:
      //   Constant: '<S27>/Puck State'

      *rtd_Float_State = localP->PuckState_Value;
    }

    // End of Outputs for SubSystem: '<S6>/Change BLACK Behavior'
  }

  // End of If: '<S6>/This IF block determines whether or not to run the BLACK sim//exp' 

  // If: '<S6>/This IF block determines whether or not to run the BLUE sim//exp' 
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
    if ((*rtd_WhoAmI == 3.0) || (*rtd_isSim == 1.0)) {
      rtAction = 0;
    }

    localDW->ThisIFblockdetermineswhethero_d = rtAction;
  } else {
    rtAction = localDW->ThisIFblockdetermineswhethero_d;
  }

  if (rtAction == 0) {
    // Outputs for IfAction SubSystem: '<S6>/Change BLUE Behavior' incorporates:
    //   ActionPort: '<S28>/Action Port'

    APF_Path_Pla_ChangeBLUEBehavior(APF_Path_Planning_2023a_M, rtd_BLUE_Fx,
      rtd_BLUE_Fy, rtd_BLUE_Tz, rtd_Float_State, &localP->ChangeBLUEBehavior);

    // End of Outputs for SubSystem: '<S6>/Change BLUE Behavior'
  }

  // End of If: '<S6>/This IF block determines whether or not to run the BLUE sim//exp' 

  // If: '<S6>/This IF block determines whether or not to run the RED sim//exp ' 
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
    if ((*rtd_WhoAmI == 1.0) || (*rtd_isSim == 1.0)) {
      rtAction = 0;
    }

    localDW->ThisIFblockdetermineswhethero_e = rtAction;
  } else {
    rtAction = localDW->ThisIFblockdetermineswhethero_e;
  }

  if (rtAction == 0) {
    // Outputs for IfAction SubSystem: '<S6>/Change RED Behavior' incorporates:
    //   ActionPort: '<S29>/Action Port'

    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // DataStoreWrite: '<S29>/RED_Fx' incorporates:
      //   Constant: '<S29>/Constant'

      *rtd_RED_Fx = localP->Constant_Value;

      // DataStoreWrite: '<S29>/RED_Fy' incorporates:
      //   Constant: '<S29>/Constant1'

      *rtd_RED_Fy = localP->Constant1_Value;

      // DataStoreWrite: '<S29>/RED_Tz' incorporates:
      //   Constant: '<S29>/Constant2'

      *rtd_RED_Tz = localP->Constant2_Value;

      // DataStoreWrite: '<S29>/RED_Tz_RW' incorporates:
      //   Constant: '<S29>/Constant3'

      *rtd_RED_Tz_RW = localP->Constant3_Value_e;

      // DataStoreWrite: '<S29>/Data Store Write1' incorporates:
      //   Constant: '<S29>/Constant4'

      *rtd_RED_ARM_Control_Mode = localP->Constant4_Value_b;

      // DataStoreWrite: '<S29>/Data Store Write4' incorporates:
      //   Constant: '<S29>/Puck State'

      *rtd_Float_State = localP->PuckState_Value_h;
    }

    // End of Outputs for SubSystem: '<S6>/Change RED Behavior'
  }

  // End of If: '<S6>/This IF block determines whether or not to run the RED sim//exp ' 
}

//
// Output and update for atomic system:
//    '<S39>/MATLAB Function2'
//    '<S52>/MATLAB Function2'
//    '<S65>/MATLAB Function2'
//    '<S418>/MATLAB Function2'
//    '<S431>/MATLAB Function2'
//    '<S444>/MATLAB Function2'
//    '<S472>/MATLAB Function2'
//    '<S485>/MATLAB Function2'
//    '<S498>/MATLAB Function2'
//
void APF_Path_Planni_MATLABFunction2(real_T rtu_z, real_T rty_Oy[2], real_T
  rty_Ox[2])
{
  real_T tmp;
  real_T tmp_0;
  tmp_0 = sin(rtu_z);
  tmp = cos(rtu_z);
  rty_Ox[0] = tmp_0 * 0.0 + tmp;
  rty_Ox[1] = tmp * 0.0 - tmp_0;
  rty_Oy[0] = tmp * 0.0 + tmp_0;
  rty_Oy[1] = -tmp_0 * 0.0 + tmp;
}

//
// Output and update for atomic system:
//    '<S39>/MATLAB Function3'
//    '<S52>/MATLAB Function3'
//    '<S65>/MATLAB Function3'
//    '<S98>/MATLAB Function3'
//    '<S115>/MATLAB Function3'
//    '<S132>/MATLAB Function3'
//    '<S148>/MATLAB Function3'
//    '<S169>/MATLAB Function3'
//    '<S190>/MATLAB Function3'
//    '<S211>/MATLAB Function3'
//    ...
//
void APF_Path_Planni_MATLABFunction3(real_T rtu_z, real_T rty_Ox[2])
{
  real_T tmp;
  real_T tmp_0;
  tmp = sin(rtu_z);
  tmp_0 = cos(rtu_z);
  rty_Ox[0] = tmp * 0.0 + tmp_0;
  rty_Ox[1] = tmp_0 * 0.0 - tmp;
}

//
// Output and update for atomic system:
//    '<S39>/MATLAB Function4'
//    '<S52>/MATLAB Function4'
//    '<S65>/MATLAB Function4'
//    '<S98>/MATLAB Function4'
//    '<S115>/MATLAB Function4'
//    '<S132>/MATLAB Function4'
//    '<S148>/MATLAB Function4'
//    '<S169>/MATLAB Function4'
//    '<S190>/MATLAB Function4'
//    '<S211>/MATLAB Function4'
//    ...
//
void APF_Path_Planni_MATLABFunction4(const real_T rtu_Oy[2], const real_T
  rtu_e_in[2], real_T *rty_e_out)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = fabs(rtu_e_in[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(rtu_e_in[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = rtu_Oy[0] * rtu_e_in[0] + rtu_Oy[1] * rtu_e_in[1];
  if (rtIsNaN(absxk)) {
    absxk = (rtNaN);
  } else if (absxk < 0.0) {
    absxk = -1.0;
  } else {
    absxk = (absxk > 0.0);
  }

  *rty_e_out = scale * sqrt(y) * -absxk;
}

//
// System initialize for action system:
//    '<S66>/Simulated Position Controller'
//    '<S254>/Simulated Position Controller'
//    '<S287>/Simulated Position Controller'
//    '<S320>/Simulated Position Controller'
//    '<S352>/Simulated Position Controller'
//
void SimulatedPositionControlle_Init(B_SimulatedPositionController_T *localB,
  DW_SimulatedPositionControlle_T *localDW, P_SimulatedPositionController_T
  *localP)
{
  // InitializeConditions for Delay: '<S83>/Delay1'
  localDW->icLoad = true;

  // InitializeConditions for Delay: '<S81>/Delay1'
  localDW->icLoad_j = true;

  // InitializeConditions for Delay: '<S85>/Delay1'
  localDW->icLoad_m = true;

  // SystemInitialize for IfAction SubSystem: '<S83>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S84>/In1' incorporates:
  //   Outport: '<S84>/Out1'

  localB->In1_g = localP->Out1_Y0_h;

  // End of SystemInitialize for SubSystem: '<S83>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S81>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S82>/In1' incorporates:
  //   Outport: '<S82>/Out1'

  localB->In1_g2 = localP->Out1_Y0;

  // End of SystemInitialize for SubSystem: '<S81>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S85>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S86>/In1' incorporates:
  //   Outport: '<S86>/Out1'

  localB->In1 = localP->Out1_Y0_k;

  // End of SystemInitialize for SubSystem: '<S85>/Hold this value'
}

//
// Output and update for action system:
//    '<S66>/Simulated Position Controller'
//    '<S254>/Simulated Position Controller'
//    '<S287>/Simulated Position Controller'
//    '<S320>/Simulated Position Controller'
//    '<S352>/Simulated Position Controller'
//
void APF_SimulatedPositionController(real_T rtu_q1_desired, real_T
  rtu_q2_desired, real_T rtu_q3_desired, real_T *rty_q1_command, real_T
  *rty_q2_command, real_T *rty_q3_command, const real_T *rtd_RED_Rz_Elbow, const
  real_T *rtd_RED_Rz_Shoulder, const real_T *rtd_RED_Rz_Wrist,
  B_SimulatedPositionController_T *localB, DW_SimulatedPositionControlle_T
  *localDW)
{
  real_T rtb_Subtract2_kc;
  real_T rtb_Sum6_ba;
  real_T rtb_Sum6_jb;
  real_T rtb_Sum6_pt;

  // Sum: '<S77>/Subtract2' incorporates:
  //   DataStoreRead: '<S77>/Data Store Read'

  rtb_Subtract2_kc = rtu_q1_desired - *rtd_RED_Rz_Shoulder;

  // Delay: '<S83>/Delay1'
  if (localDW->icLoad) {
    localDW->Delay1_DSTATE = rtb_Subtract2_kc;
  }

  // Sum: '<S83>/Sum6' incorporates:
  //   Delay: '<S83>/Delay1'

  rtb_Sum6_jb = rtb_Subtract2_kc - localDW->Delay1_DSTATE;

  // If: '<S83>/if we went through a "step"'
  if (rtb_Sum6_jb != 0.0) {
    // Outputs for IfAction SubSystem: '<S83>/Hold this value' incorporates:
    //   ActionPort: '<S84>/Action Port'

    // SignalConversion generated from: '<S84>/In1'
    localB->In1_g = rtb_Sum6_jb;

    // End of Outputs for SubSystem: '<S83>/Hold this value'
  }

  // End of If: '<S83>/if we went through a "step"'

  // Sum: '<S79>/Sum3' incorporates:
  //   Gain: '<S79>/kd_sharm'
  //   Gain: '<S79>/kp_sharm'
  //   Gain: '<S83>/divide by delta T'

  rtb_Sum6_pt = 1.0 / APF_Path_Planning_2023a_P.baseRate * localB->In1_g *
    APF_Path_Planning_2023a_P.Kd_sharm + APF_Path_Planning_2023a_P.Kp_sharm *
    rtb_Subtract2_kc;

  // Saturate: '<S77>/Saturation'
  if (rtb_Sum6_pt > APF_Path_Planning_2023a_P.Tz_lim_sharm) {
    *rty_q1_command = APF_Path_Planning_2023a_P.Tz_lim_sharm;
  } else if (rtb_Sum6_pt < -APF_Path_Planning_2023a_P.Tz_lim_sharm) {
    *rty_q1_command = -APF_Path_Planning_2023a_P.Tz_lim_sharm;
  } else {
    *rty_q1_command = rtb_Sum6_pt;
  }

  // End of Saturate: '<S77>/Saturation'

  // Sum: '<S77>/Subtract3' incorporates:
  //   DataStoreRead: '<S77>/Data Store Read5'

  rtb_Sum6_jb = rtu_q2_desired - *rtd_RED_Rz_Elbow;

  // Delay: '<S81>/Delay1'
  if (localDW->icLoad_j) {
    localDW->Delay1_DSTATE_e = rtb_Sum6_jb;
  }

  // Sum: '<S81>/Sum6' incorporates:
  //   Delay: '<S81>/Delay1'

  rtb_Sum6_ba = rtb_Sum6_jb - localDW->Delay1_DSTATE_e;

  // If: '<S81>/if we went through a "step"'
  if (rtb_Sum6_ba != 0.0) {
    // Outputs for IfAction SubSystem: '<S81>/Hold this value' incorporates:
    //   ActionPort: '<S82>/Action Port'

    // SignalConversion generated from: '<S82>/In1'
    localB->In1_g2 = rtb_Sum6_ba;

    // End of Outputs for SubSystem: '<S81>/Hold this value'
  }

  // End of If: '<S81>/if we went through a "step"'

  // Sum: '<S78>/Sum3' incorporates:
  //   Gain: '<S78>/kd_elarm'
  //   Gain: '<S78>/kp_elarm'
  //   Gain: '<S81>/divide by delta T'

  rtb_Sum6_pt = 1.0 / APF_Path_Planning_2023a_P.baseRate * localB->In1_g2 *
    APF_Path_Planning_2023a_P.Kd_elarm + APF_Path_Planning_2023a_P.Kp_elarm *
    rtb_Sum6_jb;

  // Saturate: '<S77>/Saturation1'
  if (rtb_Sum6_pt > APF_Path_Planning_2023a_P.Tz_lim_elarm) {
    *rty_q2_command = APF_Path_Planning_2023a_P.Tz_lim_elarm;
  } else if (rtb_Sum6_pt < -APF_Path_Planning_2023a_P.Tz_lim_elarm) {
    *rty_q2_command = -APF_Path_Planning_2023a_P.Tz_lim_elarm;
  } else {
    *rty_q2_command = rtb_Sum6_pt;
  }

  // End of Saturate: '<S77>/Saturation1'

  // Sum: '<S77>/Subtract4' incorporates:
  //   DataStoreRead: '<S77>/Data Store Read6'

  rtb_Sum6_ba = rtu_q3_desired - *rtd_RED_Rz_Wrist;

  // Delay: '<S85>/Delay1'
  if (localDW->icLoad_m) {
    localDW->Delay1_DSTATE_l = rtb_Sum6_ba;
  }

  // Sum: '<S85>/Sum6' incorporates:
  //   Delay: '<S85>/Delay1'

  rtb_Sum6_pt = rtb_Sum6_ba - localDW->Delay1_DSTATE_l;

  // If: '<S85>/if we went through a "step"'
  if (rtb_Sum6_pt != 0.0) {
    // Outputs for IfAction SubSystem: '<S85>/Hold this value' incorporates:
    //   ActionPort: '<S86>/Action Port'

    // SignalConversion generated from: '<S86>/In1'
    localB->In1 = rtb_Sum6_pt;

    // End of Outputs for SubSystem: '<S85>/Hold this value'
  }

  // End of If: '<S85>/if we went through a "step"'

  // Sum: '<S80>/Sum3' incorporates:
  //   Gain: '<S80>/kd_wrarm'
  //   Gain: '<S80>/kp_wrarm'
  //   Gain: '<S85>/divide by delta T'

  rtb_Sum6_pt = 1.0 / APF_Path_Planning_2023a_P.baseRate * localB->In1 *
    APF_Path_Planning_2023a_P.Kd_wrarm + APF_Path_Planning_2023a_P.Kp_wrarm *
    rtb_Sum6_ba;

  // Saturate: '<S77>/Saturation3'
  if (rtb_Sum6_pt > APF_Path_Planning_2023a_P.Tz_lim_wrarm) {
    *rty_q3_command = APF_Path_Planning_2023a_P.Tz_lim_wrarm;
  } else if (rtb_Sum6_pt < -APF_Path_Planning_2023a_P.Tz_lim_wrarm) {
    *rty_q3_command = -APF_Path_Planning_2023a_P.Tz_lim_wrarm;
  } else {
    *rty_q3_command = rtb_Sum6_pt;
  }

  // End of Saturate: '<S77>/Saturation3'

  // Update for Delay: '<S83>/Delay1'
  localDW->icLoad = false;
  localDW->Delay1_DSTATE = rtb_Subtract2_kc;

  // Update for Delay: '<S81>/Delay1'
  localDW->icLoad_j = false;
  localDW->Delay1_DSTATE_e = rtb_Sum6_jb;

  // Update for Delay: '<S85>/Delay1'
  localDW->icLoad_m = false;
  localDW->Delay1_DSTATE_l = rtb_Sum6_ba;
}

//
// Output and update for action system:
//    '<S66>/Passthrough for Experiment'
//    '<S254>/Passthrough for Experiment'
//    '<S287>/Passthrough for Experiment'
//    '<S320>/Passthrough for Experiment'
//    '<S352>/Passthrough for Experiment'
//
void APF_Pa_PassthroughforExperiment(real_T rtu_q1_desired, real_T
  rtu_q2_desired, real_T rtu_q3_desired, real_T *rty_q1_command, real_T
  *rty_q2_command, real_T *rty_q3_command)
{
  // SignalConversion generated from: '<S76>/q1_desired'
  *rty_q1_command = rtu_q1_desired;

  // SignalConversion generated from: '<S76>/q2_desired'
  *rty_q2_command = rtu_q2_desired;

  // SignalConversion generated from: '<S76>/q3_desired'
  *rty_q3_command = rtu_q3_desired;
}

//
// System initialize for action system:
//    '<S35>/RED+ARM'
//    '<S244>/RED+ARM'
//    '<S245>/RED+ARM'
//    '<S246>/RED+ARM'
//
void APF_Path_Planning_2_REDARM_Init(B_REDARM_APF_Path_Planning_20_T *localB,
  DW_REDARM_APF_Path_Planning_2_T *localDW, P_REDARM_APF_Path_Planning_20_T
  *localP)
{
  // SystemInitialize for IfAction SubSystem: '<S66>/Simulated Position Controller' 
  SimulatedPositionControlle_Init(&localB->SimulatedPositionController,
    &localDW->SimulatedPositionController, &localP->SimulatedPositionController);

  // End of SystemInitialize for SubSystem: '<S66>/Simulated Position Controller' 
}

//
// Output and update for action system:
//    '<S35>/RED+ARM'
//    '<S244>/RED+ARM'
//    '<S245>/RED+ARM'
//    '<S246>/RED+ARM'
//
void APF_Path_Planning_2023a_REDARM(real_T *rtd_RED_ARM_Control_Mode, real_T
  *rtd_RED_Elbow_Command, const real_T *rtd_RED_Rz_Elbow, const real_T
  *rtd_RED_Rz_Shoulder, const real_T *rtd_RED_Rz_Wrist, real_T
  *rtd_RED_Shoulder_Command, real_T *rtd_RED_Wrist_Command, const real_T
  *rtd_isSim, B_REDARM_APF_Path_Planning_20_T *localB,
  DW_REDARM_APF_Path_Planning_2_T *localDW, P_REDARM_APF_Path_Planning_20_T
  *localP)
{
  // If: '<S66>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' incorporates:
  //   DataStoreRead: '<S66>/Data Store Read1'

  if (*rtd_isSim == 1.0) {
    // Outputs for IfAction SubSystem: '<S66>/Simulated Position Controller' incorporates:
    //   ActionPort: '<S77>/Action Port'

    // DataStoreWrite: '<S66>/Data Store Write2' incorporates:
    //   Constant: '<S66>/Constant4'
    //   Constant: '<S66>/Constant5'
    //   Constant: '<S66>/Constant6'
    //   DataStoreWrite: '<S66>/Data Store Write'
    //   DataStoreWrite: '<S66>/Data Store Write1'

    APF_SimulatedPositionController(localP->Constant4_Value,
      localP->Constant5_Value, localP->Constant6_Value, rtd_RED_Shoulder_Command,
      rtd_RED_Elbow_Command, rtd_RED_Wrist_Command, (real_T *)rtd_RED_Rz_Elbow,
      (real_T *)rtd_RED_Rz_Shoulder, (real_T *)rtd_RED_Rz_Wrist,
      &localB->SimulatedPositionController,
      &localDW->SimulatedPositionController);

    // End of Outputs for SubSystem: '<S66>/Simulated Position Controller'
  } else {
    // Outputs for IfAction SubSystem: '<S66>/Passthrough for Experiment' incorporates:
    //   ActionPort: '<S76>/Action Port'

    // DataStoreWrite: '<S66>/Data Store Write2' incorporates:
    //   Constant: '<S66>/Constant4'
    //   Constant: '<S66>/Constant5'
    //   Constant: '<S66>/Constant6'
    //   DataStoreWrite: '<S66>/Data Store Write'
    //   DataStoreWrite: '<S66>/Data Store Write1'

    APF_Pa_PassthroughforExperiment(localP->Constant4_Value,
      localP->Constant5_Value, localP->Constant6_Value, rtd_RED_Shoulder_Command,
      rtd_RED_Elbow_Command, rtd_RED_Wrist_Command);

    // End of Outputs for SubSystem: '<S66>/Passthrough for Experiment'
  }

  // End of If: '<S66>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 

  // DataStoreWrite: '<S66>/Data Store Write3' incorporates:
  //   Constant: '<S66>/Constant7'

  *rtd_RED_ARM_Control_Mode = localP->Constant7_Value;
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

    y = atan2(static_cast<real_T>(tmp), static_cast<real_T>(tmp_0));
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

//
// Output and update for atomic system:
//    '<S100>/MATLAB Function'
//    '<S117>/MATLAB Function'
//    '<S134>/MATLAB Function'
//    '<S174>/MATLAB Function'
//    '<S195>/MATLAB Function'
//    '<S216>/MATLAB Function'
//    '<S278>/MATLAB Function'
//    '<S311>/MATLAB Function'
//    '<S344>/MATLAB Function'
//    '<S396>/MATLAB Function'
//
void APF_Path_Plannin_MATLABFunction(real_T rtu_u, real_T *rty_wrappedAngle)
{
  *rty_wrappedAngle = rt_atan2d_snf(sin(rtu_u), cos(rtu_u));
}

//
// System initialize for action system:
//    '<S87>/Sub-Phase #1'
//    '<S87>/Sub-Phase #2 '
//    '<S87>/Sub-Phase #3 '
//
void APF_Path_Plannin_SubPhase1_Init(B_SubPhase1_APF_Path_Planning_T *localB,
  DW_SubPhase1_APF_Path_Plannin_T *localDW, P_SubPhase1_APF_Path_Planning_T
  *localP)
{
  // Start for If: '<S104>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSubs = -1;

  // Start for If: '<S106>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_g = -1;

  // Start for If: '<S102>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_o = -1;

  // InitializeConditions for Delay: '<S104>/Delay1'
  localDW->icLoad = true;

  // InitializeConditions for Delay: '<S106>/Delay1'
  localDW->icLoad_p = true;

  // InitializeConditions for Delay: '<S102>/Delay1'
  localDW->icLoad_c = true;

  // SystemInitialize for IfAction SubSystem: '<S104>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S105>/In1' incorporates:
  //   Outport: '<S105>/Out1'

  localB->In1_g = localP->Out1_Y0_a;

  // End of SystemInitialize for SubSystem: '<S104>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S106>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S107>/In1' incorporates:
  //   Outport: '<S107>/Out1'

  localB->In1 = localP->Out1_Y0_o;

  // End of SystemInitialize for SubSystem: '<S106>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S102>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S103>/In1' incorporates:
  //   Outport: '<S103>/Out1'

  localB->In1_g2 = localP->Out1_Y0;

  // End of SystemInitialize for SubSystem: '<S102>/Hold this value'
}

//
// Outputs for action system:
//    '<S87>/Sub-Phase #1'
//    '<S87>/Sub-Phase #2 '
//    '<S87>/Sub-Phase #3 '
//
void APF_Path_Planning_202_SubPhase1(RT_MODEL_APF_Path_Planning_20_T * const
  APF_Path_Planning_2023a_M, real_T *rtd_BLACK_Fx, real_T *rtd_BLACK_Fy, const
  real_T *rtd_BLACK_Px, const real_T *rtd_BLACK_Py, const real_T *rtd_BLACK_Rz,
  real_T *rtd_BLACK_Tz, real_T *rtd_Float_State, const real_T *rtd_Univ_Time,
  B_SubPhase1_APF_Path_Planning_T *localB, DW_SubPhase1_APF_Path_Plannin_T
  *localDW, P_SubPhase1_APF_Path_Planning_T *localP)
{
  real_T rtb_Oy_ik[2];
  real_T rtb_Sum6_ii;
  int8_T rtAction;

  // Sum: '<S90>/Subtract' incorporates:
  //   Constant: '<S90>/Desired X-Position (BLACK)'

  localB->Subtract = APF_Path_Planning_2023a_P.xLength / 2.0 - *rtd_BLACK_Px;
  if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
    // Delay: '<S104>/Delay1'
    if (localDW->icLoad) {
      localDW->Delay1_DSTATE = localB->Subtract;
    }

    // Delay: '<S104>/Delay1'
    localB->Delay1 = localDW->Delay1_DSTATE;
  }

  // Sum: '<S104>/Sum6'
  rtb_Sum6_ii = localB->Subtract - localB->Delay1;

  // If: '<S104>/if we went through a "step"'
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
    if (rtb_Sum6_ii != 0.0) {
      rtAction = 0;
    }

    localDW->ifwewentthroughastep_ActiveSubs = rtAction;
  } else {
    rtAction = localDW->ifwewentthroughastep_ActiveSubs;
  }

  if (rtAction == 0) {
    // Outputs for IfAction SubSystem: '<S104>/Hold this value' incorporates:
    //   ActionPort: '<S105>/Action Port'

    // SignalConversion generated from: '<S105>/In1'
    localB->In1_g = rtb_Sum6_ii;

    // End of Outputs for SubSystem: '<S104>/Hold this value'
  }

  // End of If: '<S104>/if we went through a "step"'

  // Sum: '<S96>/Sum3' incorporates:
  //   DataStoreWrite: '<S90>/BLACK_Fx'
  //   Gain: '<S104>/divide by delta T'
  //   Gain: '<S96>/kd_xb'
  //   Gain: '<S96>/kp_xb'

  *rtd_BLACK_Fx = 1.0 / APF_Path_Planning_2023a_P.baseRate * localB->In1_g *
    APF_Path_Planning_2023a_P.Kd_xb + APF_Path_Planning_2023a_P.Kp_xb *
    localB->Subtract;

  // Sum: '<S90>/Subtract1' incorporates:
  //   Constant: '<S90>/Desired Y-Position (BLACK)'

  localB->Subtract1 = APF_Path_Planning_2023a_P.yLength / 2.0 - *rtd_BLACK_Py;
  if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
    // Delay: '<S106>/Delay1'
    if (localDW->icLoad_p) {
      localDW->Delay1_DSTATE_n = localB->Subtract1;
    }

    // Delay: '<S106>/Delay1'
    localB->Delay1_l = localDW->Delay1_DSTATE_n;
  }

  // Sum: '<S106>/Sum6'
  rtb_Sum6_ii = localB->Subtract1 - localB->Delay1_l;

  // If: '<S106>/if we went through a "step"'
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
    if (rtb_Sum6_ii != 0.0) {
      rtAction = 0;
    }

    localDW->ifwewentthroughastep_ActiveSu_g = rtAction;
  } else {
    rtAction = localDW->ifwewentthroughastep_ActiveSu_g;
  }

  if (rtAction == 0) {
    // Outputs for IfAction SubSystem: '<S106>/Hold this value' incorporates:
    //   ActionPort: '<S107>/Action Port'

    // SignalConversion generated from: '<S107>/In1'
    localB->In1 = rtb_Sum6_ii;

    // End of Outputs for SubSystem: '<S106>/Hold this value'
  }

  // End of If: '<S106>/if we went through a "step"'

  // Sum: '<S97>/Sum3' incorporates:
  //   DataStoreWrite: '<S90>/BLACK_Fy'
  //   Gain: '<S106>/divide by delta T'
  //   Gain: '<S97>/kd_yb'
  //   Gain: '<S97>/kp_yb'

  *rtd_BLACK_Fy = 1.0 / APF_Path_Planning_2023a_P.baseRate * localB->In1 *
    APF_Path_Planning_2023a_P.Kd_yb + APF_Path_Planning_2023a_P.Kp_yb *
    localB->Subtract1;

  // MATLAB Function: '<S100>/MATLAB Function' incorporates:
  //   Constant: '<S94>/Desired Rate (BLACK)'
  //   Constant: '<S99>/Constant1'
  //   Product: '<S94>/Product'
  //   Sum: '<S99>/Subtract'

  APF_Path_Plannin_MATLABFunction(localP->DesiredRateBLACK_Value *
    (*rtd_Univ_Time - APF_Path_Planning_2023a_P.Phase2_End), &rtb_Sum6_ii);

  // MATLAB Function: '<S98>/MATLAB Function2'
  APF_Path_Planni_MATLABFunction2(rtb_Sum6_ii, rtb_Oy_ik, localB->rtb_Ox_fz_m);

  // MATLAB Function: '<S98>/MATLAB Function3'
  APF_Path_Planni_MATLABFunction3(*rtd_BLACK_Rz, localB->rtb_Ox_a5_c);

  // Sum: '<S98>/Subtract2'
  localB->rtb_Ox_fz_m[0] -= localB->rtb_Ox_a5_c[0];
  localB->rtb_Ox_fz_m[1] -= localB->rtb_Ox_a5_c[1];

  // MATLAB Function: '<S98>/MATLAB Function4'
  APF_Path_Planni_MATLABFunction4(rtb_Oy_ik, localB->rtb_Ox_fz_m, &localB->e_out);
  if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
    // Delay: '<S102>/Delay1'
    if (localDW->icLoad_c) {
      localDW->Delay1_DSTATE_j = localB->e_out;
    }

    // Delay: '<S102>/Delay1'
    localB->Delay1_lb = localDW->Delay1_DSTATE_j;
  }

  // Sum: '<S102>/Sum6'
  rtb_Sum6_ii = localB->e_out - localB->Delay1_lb;

  // If: '<S102>/if we went through a "step"'
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
    if (rtb_Sum6_ii != 0.0) {
      rtAction = 0;
    }

    localDW->ifwewentthroughastep_ActiveSu_o = rtAction;
  } else {
    rtAction = localDW->ifwewentthroughastep_ActiveSu_o;
  }

  if (rtAction == 0) {
    // Outputs for IfAction SubSystem: '<S102>/Hold this value' incorporates:
    //   ActionPort: '<S103>/Action Port'

    // SignalConversion generated from: '<S103>/In1'
    localB->In1_g2 = rtb_Sum6_ii;

    // End of Outputs for SubSystem: '<S102>/Hold this value'
  }

  // End of If: '<S102>/if we went through a "step"'

  // Sum: '<S95>/Sum3' incorporates:
  //   DataStoreWrite: '<S90>/BLACK_Tz'
  //   Gain: '<S102>/divide by delta T'
  //   Gain: '<S95>/kd_tb'
  //   Gain: '<S95>/kp_tb'

  *rtd_BLACK_Tz = 1.0 / APF_Path_Planning_2023a_P.baseRate * localB->In1_g2 *
    APF_Path_Planning_2023a_P.Kd_tb + APF_Path_Planning_2023a_P.Kp_tb *
    localB->e_out;
  if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
    // DataStoreWrite: '<S90>/Data Store Write3' incorporates:
    //   Constant: '<S90>/Puck State'

    *rtd_Float_State = localP->PuckState_Value;
  }
}

//
// Update for action system:
//    '<S87>/Sub-Phase #1'
//    '<S87>/Sub-Phase #2 '
//    '<S87>/Sub-Phase #3 '
//
void APF_Path_Plann_SubPhase1_Update(RT_MODEL_APF_Path_Planning_20_T * const
  APF_Path_Planning_2023a_M, B_SubPhase1_APF_Path_Planning_T *localB,
  DW_SubPhase1_APF_Path_Plannin_T *localDW)
{
  if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
    // Update for Delay: '<S104>/Delay1'
    localDW->icLoad = false;
    localDW->Delay1_DSTATE = localB->Subtract;

    // Update for Delay: '<S106>/Delay1'
    localDW->icLoad_p = false;
    localDW->Delay1_DSTATE_n = localB->Subtract1;

    // Update for Delay: '<S102>/Delay1'
    localDW->icLoad_c = false;
    localDW->Delay1_DSTATE_j = localB->e_out;
  }
}

//
// System initialize for action system:
//    '<S88>/Sub-Phase #1'
//    '<S88>/Sub-Phase #2 '
//    '<S88>/Sub-Phase #3 '
//
void APF_Path_Plann_SubPhase1_p_Init(B_SubPhase1_APF_Path_Planni_n_T *localB,
  DW_SubPhase1_APF_Path_Plann_o_T *localDW, P_SubPhase1_APF_Path_Planni_a_T
  *localP)
{
  // Start for If: '<S178>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSubs = -1;

  // Start for If: '<S180>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_l = -1;

  // Start for If: '<S176>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_i = -1;

  // InitializeConditions for Delay: '<S178>/Delay1'
  localDW->icLoad = true;

  // InitializeConditions for Delay: '<S180>/Delay1'
  localDW->icLoad_j = true;

  // InitializeConditions for Delay: '<S176>/Delay1'
  localDW->icLoad_h = true;

  // SystemInitialize for IfAction SubSystem: '<S178>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S179>/In1' incorporates:
  //   Outport: '<S179>/Out1'

  localB->In1_g = localP->Out1_Y0_p;

  // End of SystemInitialize for SubSystem: '<S178>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S180>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S181>/In1' incorporates:
  //   Outport: '<S181>/Out1'

  localB->In1 = localP->Out1_Y0_j;

  // End of SystemInitialize for SubSystem: '<S180>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S176>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S177>/In1' incorporates:
  //   Outport: '<S177>/Out1'

  localB->In1_g2 = localP->Out1_Y0;

  // End of SystemInitialize for SubSystem: '<S176>/Hold this value'
}

//
// Outputs for action system:
//    '<S88>/Sub-Phase #1'
//    '<S88>/Sub-Phase #2 '
//    '<S88>/Sub-Phase #3 '
//
void APF_Path_Planning_2_SubPhase1_g(RT_MODEL_APF_Path_Planning_20_T * const
  APF_Path_Planning_2023a_M, real_T *rtd_BLUE_Fx, real_T *rtd_BLUE_Fy, const
  real_T *rtd_BLUE_Px, const real_T *rtd_BLUE_Py, const real_T *rtd_BLUE_Rz,
  real_T *rtd_BLUE_Tz, real_T *rtd_Float_State, const real_T *rtd_Univ_Time,
  B_SubPhase1_APF_Path_Planni_n_T *localB, DW_SubPhase1_APF_Path_Plann_o_T
  *localDW, P_SubPhase1_APF_Path_Planni_a_T *localP)
{
  real_T rtb_Subtract3_o;
  real_T rtb_Sum6_bu;
  int8_T rtAction;

  // Sum: '<S172>/Subtract3' incorporates:
  //   Constant: '<S172>/Constant2'

  rtb_Subtract3_o = *rtd_Univ_Time - APF_Path_Planning_2023a_P.Phase2_End;

  // Sum: '<S161>/Subtract' incorporates:
  //   MATLAB Function: '<S161>/MATLAB Function2'

  localB->Subtract = (cos(0.03490659 * rtb_Subtract3_o) * -0.85 +
                      APF_Path_Planning_2023a_P.xLength / 2.0) - *rtd_BLUE_Px;
  if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
    // Delay: '<S178>/Delay1'
    if (localDW->icLoad) {
      localDW->Delay1_DSTATE = localB->Subtract;
    }

    // Delay: '<S178>/Delay1'
    localB->Delay1 = localDW->Delay1_DSTATE;
  }

  // Sum: '<S178>/Sum6'
  rtb_Sum6_bu = localB->Subtract - localB->Delay1;

  // If: '<S178>/if we went through a "step"'
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
    if (rtb_Sum6_bu != 0.0) {
      rtAction = 0;
    }

    localDW->ifwewentthroughastep_ActiveSubs = rtAction;
  } else {
    rtAction = localDW->ifwewentthroughastep_ActiveSubs;
  }

  if (rtAction == 0) {
    // Outputs for IfAction SubSystem: '<S178>/Hold this value' incorporates:
    //   ActionPort: '<S179>/Action Port'

    // SignalConversion generated from: '<S179>/In1'
    localB->In1_g = rtb_Sum6_bu;

    // End of Outputs for SubSystem: '<S178>/Hold this value'
  }

  // End of If: '<S178>/if we went through a "step"'

  // Sum: '<S167>/Sum3' incorporates:
  //   DataStoreWrite: '<S161>/BLUE_Fx'
  //   Gain: '<S167>/kd_xb'
  //   Gain: '<S167>/kp_xb'
  //   Gain: '<S178>/divide by delta T'

  *rtd_BLUE_Fx = 1.0 / APF_Path_Planning_2023a_P.baseRate * localB->In1_g *
    APF_Path_Planning_2023a_P.Kd_xblue + APF_Path_Planning_2023a_P.Kp_xblue *
    localB->Subtract;

  // Sum: '<S161>/Subtract1' incorporates:
  //   MATLAB Function: '<S161>/MATLAB Function3'

  localB->Subtract1 = (sin(0.03490659 * rtb_Subtract3_o) * -0.85 +
                       APF_Path_Planning_2023a_P.yLength / 2.0) - *rtd_BLUE_Py;
  if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
    // Delay: '<S180>/Delay1'
    if (localDW->icLoad_j) {
      localDW->Delay1_DSTATE_o = localB->Subtract1;
    }

    // Delay: '<S180>/Delay1'
    localB->Delay1_l = localDW->Delay1_DSTATE_o;
  }

  // Sum: '<S180>/Sum6'
  rtb_Subtract3_o = localB->Subtract1 - localB->Delay1_l;

  // If: '<S180>/if we went through a "step"'
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
    if (rtb_Subtract3_o != 0.0) {
      rtAction = 0;
    }

    localDW->ifwewentthroughastep_ActiveSu_l = rtAction;
  } else {
    rtAction = localDW->ifwewentthroughastep_ActiveSu_l;
  }

  if (rtAction == 0) {
    // Outputs for IfAction SubSystem: '<S180>/Hold this value' incorporates:
    //   ActionPort: '<S181>/Action Port'

    // SignalConversion generated from: '<S181>/In1'
    localB->In1 = rtb_Subtract3_o;

    // End of Outputs for SubSystem: '<S180>/Hold this value'
  }

  // End of If: '<S180>/if we went through a "step"'

  // Sum: '<S168>/Sum3' incorporates:
  //   DataStoreWrite: '<S161>/BLUE_Fy'
  //   Gain: '<S168>/kd_yb'
  //   Gain: '<S168>/kp_yb'
  //   Gain: '<S180>/divide by delta T'

  *rtd_BLUE_Fy = 1.0 / APF_Path_Planning_2023a_P.baseRate * localB->In1 *
    APF_Path_Planning_2023a_P.Kd_yblue + APF_Path_Planning_2023a_P.Kp_yblue *
    localB->Subtract1;

  // MATLAB Function: '<S174>/MATLAB Function' incorporates:
  //   Constant: '<S165>/Desired Rate '
  //   Constant: '<S173>/Constant1'
  //   Product: '<S165>/Product'
  //   Sum: '<S173>/Subtract'

  APF_Path_Plannin_MATLABFunction(localP->DesiredRate_Value * (*rtd_Univ_Time -
    APF_Path_Planning_2023a_P.Phase2_End), &rtb_Subtract3_o);

  // MATLAB Function: '<S169>/MATLAB Function2'
  APF_Path_Planni_MATLABFunction2(rtb_Subtract3_o, localB->rtb_Oy_p_k,
    localB->rtb_Ox_eh_m);

  // MATLAB Function: '<S169>/MATLAB Function3'
  APF_Path_Planni_MATLABFunction3(*rtd_BLUE_Rz, localB->rtb_Ox_kz_c);

  // Sum: '<S169>/Subtract2'
  localB->rtb_Ox_eh_m[0] -= localB->rtb_Ox_kz_c[0];
  localB->rtb_Ox_eh_m[1] -= localB->rtb_Ox_kz_c[1];

  // MATLAB Function: '<S169>/MATLAB Function4'
  APF_Path_Planni_MATLABFunction4(localB->rtb_Oy_p_k, localB->rtb_Ox_eh_m,
    &localB->e_out);
  if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
    // Delay: '<S176>/Delay1'
    if (localDW->icLoad_h) {
      localDW->Delay1_DSTATE_i = localB->e_out;
    }

    // Delay: '<S176>/Delay1'
    localB->Delay1_k = localDW->Delay1_DSTATE_i;
  }

  // Sum: '<S176>/Sum6'
  rtb_Subtract3_o = localB->e_out - localB->Delay1_k;

  // If: '<S176>/if we went through a "step"'
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
    if (rtb_Subtract3_o != 0.0) {
      rtAction = 0;
    }

    localDW->ifwewentthroughastep_ActiveSu_i = rtAction;
  } else {
    rtAction = localDW->ifwewentthroughastep_ActiveSu_i;
  }

  if (rtAction == 0) {
    // Outputs for IfAction SubSystem: '<S176>/Hold this value' incorporates:
    //   ActionPort: '<S177>/Action Port'

    // SignalConversion generated from: '<S177>/In1'
    localB->In1_g2 = rtb_Subtract3_o;

    // End of Outputs for SubSystem: '<S176>/Hold this value'
  }

  // End of If: '<S176>/if we went through a "step"'

  // Sum: '<S166>/Sum3' incorporates:
  //   DataStoreWrite: '<S161>/BLUE_Tz'
  //   Gain: '<S166>/kd_tb'
  //   Gain: '<S166>/kp_tb'
  //   Gain: '<S176>/divide by delta T'

  *rtd_BLUE_Tz = 1.0 / APF_Path_Planning_2023a_P.baseRate * localB->In1_g2 *
    APF_Path_Planning_2023a_P.Kd_tblue + APF_Path_Planning_2023a_P.Kp_tblue *
    localB->e_out;
  if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
    // DataStoreWrite: '<S161>/Data Store Write1' incorporates:
    //   Constant: '<S161>/Puck State'

    *rtd_Float_State = localP->PuckState_Value;
  }
}

//
// Update for action system:
//    '<S88>/Sub-Phase #1'
//    '<S88>/Sub-Phase #2 '
//    '<S88>/Sub-Phase #3 '
//
void APF_Path_Pla_SubPhase1_f_Update(RT_MODEL_APF_Path_Planning_20_T * const
  APF_Path_Planning_2023a_M, B_SubPhase1_APF_Path_Planni_n_T *localB,
  DW_SubPhase1_APF_Path_Plann_o_T *localDW)
{
  if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
    // Update for Delay: '<S178>/Delay1'
    localDW->icLoad = false;
    localDW->Delay1_DSTATE = localB->Subtract;

    // Update for Delay: '<S180>/Delay1'
    localDW->icLoad_j = false;
    localDW->Delay1_DSTATE_o = localB->Subtract1;

    // Update for Delay: '<S176>/Delay1'
    localDW->icLoad_h = false;
    localDW->Delay1_DSTATE_i = localB->e_out;
  }
}

//
// Output and update for atomic system:
//    '<S244>/MATLAB Function'
//    '<S245>/MATLAB Function'
//    '<S246>/MATLAB Function'
//
void APF_Path_Plann_MATLABFunction_o(real_T rtu_t, real_T *rty_x)
{
  *rty_x = cos(0.03490659 * rtu_t) * 0.9 + APF_Path_Planning_2023a_P.xLength /
    2.0;
}

//
// Output and update for atomic system:
//    '<S244>/MATLAB Function1'
//    '<S245>/MATLAB Function1'
//    '<S246>/MATLAB Function1'
//
void APF_Path_Planni_MATLABFunction1(real_T rtu_t, real_T *rty_y)
{
  *rty_y = sin(0.03490659 * rtu_t) * 0.85 + APF_Path_Planning_2023a_P.yLength /
    2.0;
}

//
// System initialize for action system:
//    '<S89>/Sub-Phase #1'
//    '<S89>/Sub-Phase #2 '
//
void APF_Path_Plann_SubPhase1_k_Init(B_SubPhase1_APF_Path_Planni_i_T *localB,
  DW_SubPhase1_APF_Path_Plann_m_T *localDW, P_SubPhase1_APF_Path_Planni_h_T
  *localP)
{
  // Start for If: '<S257>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSubs = -1;

  // Start for If: '<S259>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_a = -1;

  // Start for If: '<S261>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_i = -1;

  // InitializeConditions for Delay: '<S257>/Delay1'
  localDW->icLoad = true;

  // InitializeConditions for Delay: '<S259>/Delay1'
  localDW->icLoad_g = true;

  // InitializeConditions for Delay: '<S261>/Delay1'
  localDW->icLoad_h = true;

  // SystemInitialize for IfAction SubSystem: '<S257>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S258>/In1' incorporates:
  //   Outport: '<S258>/Out1'

  localB->In1_g2 = localP->Out1_Y0;

  // End of SystemInitialize for SubSystem: '<S257>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S259>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S260>/In1' incorporates:
  //   Outport: '<S260>/Out1'

  localB->In1_g = localP->Out1_Y0_c;

  // End of SystemInitialize for SubSystem: '<S259>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S261>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S262>/In1' incorporates:
  //   Outport: '<S262>/Out1'

  localB->In1 = localP->Out1_Y0_j;

  // End of SystemInitialize for SubSystem: '<S261>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S244>/RED+ARM'
  APF_Path_Planning_2_REDARM_Init(&localB->REDARM, &localDW->REDARM,
    &localP->REDARM);

  // End of SystemInitialize for SubSystem: '<S244>/RED+ARM'
}

//
// Outputs for action system:
//    '<S89>/Sub-Phase #1'
//    '<S89>/Sub-Phase #2 '
//
void APF_Path_Planning_2_SubPhase1_p(RT_MODEL_APF_Path_Planning_20_T * const
  APF_Path_Planning_2023a_M, real_T *rtd_Float_State, real_T
  *rtd_RED_ARM_Control_Mode, real_T *rtd_RED_Elbow_Command, real_T *rtd_RED_Fx,
  real_T *rtd_RED_Fy, const real_T *rtd_RED_Px, const real_T *rtd_RED_Py, const
  real_T *rtd_RED_Rz, const real_T *rtd_RED_Rz_Elbow, const real_T
  *rtd_RED_Rz_Shoulder, const real_T *rtd_RED_Rz_Wrist, real_T
  *rtd_RED_Shoulder_Command, real_T *rtd_RED_Tz, real_T *rtd_RED_Tz_RW, real_T
  *rtd_RED_Wrist_Command, const real_T *rtd_Univ_Time, const real_T *rtd_isSim,
  B_SubPhase1_APF_Path_Planni_i_T *localB, DW_SubPhase1_APF_Path_Plann_m_T
  *localDW, P_SubPhase1_APF_Path_Planni_h_T *localP)
{
  real_T rtb_Sum6_f2;
  real_T rtb_y_g;
  int8_T rtAction;
  if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
    // DataStoreWrite: '<S244>/RED_Tz_RW' incorporates:
    //   Constant: '<S244>/Constant1'

    *rtd_RED_Tz_RW = localP->Constant1_Value;
  }

  // MATLAB Function: '<S278>/MATLAB Function' incorporates:
  //   Constant: '<S255>/Constant'
  //   Constant: '<S255>/Desired Rate '
  //   Constant: '<S277>/Constant1'
  //   Product: '<S255>/Product'
  //   Sum: '<S255>/Sum'
  //   Sum: '<S277>/Subtract'

  APF_Path_Plannin_MATLABFunction(localP->DesiredRate_Value * (*rtd_Univ_Time -
    APF_Path_Planning_2023a_P.Phase2_End) + localP->Constant_Value, &rtb_y_g);

  // MATLAB Function: '<S251>/MATLAB Function2'
  APF_Path_Planni_MATLABFunction2(rtb_y_g, localB->rtb_Oy_j5_k,
    localB->rtb_Ox_o_m);

  // MATLAB Function: '<S251>/MATLAB Function3'
  APF_Path_Planni_MATLABFunction3(*rtd_RED_Rz, localB->rtb_Ox_gy_c);

  // Sum: '<S251>/Subtract2'
  localB->rtb_Ox_o_m[0] -= localB->rtb_Ox_gy_c[0];
  localB->rtb_Ox_o_m[1] -= localB->rtb_Ox_gy_c[1];

  // MATLAB Function: '<S251>/MATLAB Function4'
  APF_Path_Planni_MATLABFunction4(localB->rtb_Oy_j5_k, localB->rtb_Ox_o_m,
    &localB->e_out);
  if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
    // Delay: '<S257>/Delay1'
    if (localDW->icLoad) {
      localDW->Delay1_DSTATE = localB->e_out;
    }

    // Delay: '<S257>/Delay1'
    localB->Delay1 = localDW->Delay1_DSTATE;
  }

  // Sum: '<S257>/Sum6'
  rtb_Sum6_f2 = localB->e_out - localB->Delay1;

  // If: '<S257>/if we went through a "step"'
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
    if (rtb_Sum6_f2 != 0.0) {
      rtAction = 0;
    }

    localDW->ifwewentthroughastep_ActiveSubs = rtAction;
  } else {
    rtAction = localDW->ifwewentthroughastep_ActiveSubs;
  }

  if (rtAction == 0) {
    // Outputs for IfAction SubSystem: '<S257>/Hold this value' incorporates:
    //   ActionPort: '<S258>/Action Port'

    // SignalConversion generated from: '<S258>/In1'
    localB->In1_g2 = rtb_Sum6_f2;

    // End of Outputs for SubSystem: '<S257>/Hold this value'
  }

  // End of If: '<S257>/if we went through a "step"'

  // Sum: '<S248>/Sum3' incorporates:
  //   DataStoreWrite: '<S244>/RED_Tz'
  //   Gain: '<S248>/kd_tr'
  //   Gain: '<S248>/kp_tr'
  //   Gain: '<S257>/divide by delta T'

  *rtd_RED_Tz = 1.0 / APF_Path_Planning_2023a_P.baseRate * localB->In1_g2 *
    APF_Path_Planning_2023a_P.Kd_tr + APF_Path_Planning_2023a_P.Kp_tr *
    localB->e_out;

  // Sum: '<S256>/Subtract3' incorporates:
  //   Constant: '<S256>/Constant2'

  rtb_Sum6_f2 = *rtd_Univ_Time - APF_Path_Planning_2023a_P.Phase2_End;

  // MATLAB Function: '<S244>/MATLAB Function'
  APF_Path_Plann_MATLABFunction_o(rtb_Sum6_f2, &rtb_y_g);

  // Sum: '<S244>/Subtract'
  localB->Subtract = rtb_y_g - *rtd_RED_Px;
  if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
    // Delay: '<S259>/Delay1'
    if (localDW->icLoad_g) {
      localDW->Delay1_DSTATE_e = localB->Subtract;
    }

    // Delay: '<S259>/Delay1'
    localB->Delay1_c = localDW->Delay1_DSTATE_e;
  }

  // Sum: '<S259>/Sum6'
  rtb_y_g = localB->Subtract - localB->Delay1_c;

  // If: '<S259>/if we went through a "step"'
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
    if (rtb_y_g != 0.0) {
      rtAction = 0;
    }

    localDW->ifwewentthroughastep_ActiveSu_a = rtAction;
  } else {
    rtAction = localDW->ifwewentthroughastep_ActiveSu_a;
  }

  if (rtAction == 0) {
    // Outputs for IfAction SubSystem: '<S259>/Hold this value' incorporates:
    //   ActionPort: '<S260>/Action Port'

    // SignalConversion generated from: '<S260>/In1'
    localB->In1_g = rtb_y_g;

    // End of Outputs for SubSystem: '<S259>/Hold this value'
  }

  // End of If: '<S259>/if we went through a "step"'

  // Sum: '<S249>/Sum3' incorporates:
  //   DataStoreWrite: '<S244>/RED_Fx'
  //   Gain: '<S249>/kd_xr'
  //   Gain: '<S249>/kp_xr'
  //   Gain: '<S259>/divide by delta T'

  *rtd_RED_Fx = 1.0 / APF_Path_Planning_2023a_P.baseRate * localB->In1_g *
    APF_Path_Planning_2023a_P.Kd_xr + APF_Path_Planning_2023a_P.Kp_xr *
    localB->Subtract;

  // MATLAB Function: '<S244>/MATLAB Function1'
  APF_Path_Planni_MATLABFunction1(rtb_Sum6_f2, &rtb_y_g);

  // Sum: '<S244>/Subtract2'
  localB->Subtract2 = rtb_y_g - *rtd_RED_Py;
  if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
    // Delay: '<S261>/Delay1'
    if (localDW->icLoad_h) {
      localDW->Delay1_DSTATE_o = localB->Subtract2;
    }

    // Delay: '<S261>/Delay1'
    localB->Delay1_m = localDW->Delay1_DSTATE_o;
  }

  // Sum: '<S261>/Sum6'
  rtb_Sum6_f2 = localB->Subtract2 - localB->Delay1_m;

  // If: '<S261>/if we went through a "step"'
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
    if (rtb_Sum6_f2 != 0.0) {
      rtAction = 0;
    }

    localDW->ifwewentthroughastep_ActiveSu_i = rtAction;
  } else {
    rtAction = localDW->ifwewentthroughastep_ActiveSu_i;
  }

  if (rtAction == 0) {
    // Outputs for IfAction SubSystem: '<S261>/Hold this value' incorporates:
    //   ActionPort: '<S262>/Action Port'

    // SignalConversion generated from: '<S262>/In1'
    localB->In1 = rtb_Sum6_f2;

    // End of Outputs for SubSystem: '<S261>/Hold this value'
  }

  // End of If: '<S261>/if we went through a "step"'

  // Sum: '<S250>/Sum3' incorporates:
  //   DataStoreWrite: '<S244>/RED_Fy'
  //   Gain: '<S250>/kd_yr'
  //   Gain: '<S250>/kp_yr'
  //   Gain: '<S261>/divide by delta T'

  *rtd_RED_Fy = 1.0 / APF_Path_Planning_2023a_P.baseRate * localB->In1 *
    APF_Path_Planning_2023a_P.Kd_yr + APF_Path_Planning_2023a_P.Kp_yr *
    localB->Subtract2;
  if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
    // DataStoreWrite: '<S244>/Data Store Write3' incorporates:
    //   Constant: '<S244>/Puck State'

    *rtd_Float_State = localP->PuckState_Value;

    // If: '<S244>/If' incorporates:
    //   Constant: '<S244>/Constant4'

    if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo) &&
        ((APF_Path_Planning_2023a_P.platformSelection == 4.0) ||
         (APF_Path_Planning_2023a_P.platformSelection == 5.0) ||
         (APF_Path_Planning_2023a_P.platformSelection == 10.0) ||
         (APF_Path_Planning_2023a_P.platformSelection == 11.0))) {
      // Outputs for IfAction SubSystem: '<S244>/RED+ARM' incorporates:
      //   ActionPort: '<S254>/Action Port'

      APF_Path_Planning_2023a_REDARM(rtd_RED_ARM_Control_Mode,
        rtd_RED_Elbow_Command, (real_T *)rtd_RED_Rz_Elbow, (real_T *)
        rtd_RED_Rz_Shoulder, (real_T *)rtd_RED_Rz_Wrist,
        rtd_RED_Shoulder_Command, rtd_RED_Wrist_Command, (real_T *)rtd_isSim,
        &localB->REDARM, &localDW->REDARM, &localP->REDARM);

      // End of Outputs for SubSystem: '<S244>/RED+ARM'
    }

    // End of If: '<S244>/If'
  }
}

//
// Update for action system:
//    '<S89>/Sub-Phase #1'
//    '<S89>/Sub-Phase #2 '
//
void APF_Path_Pla_SubPhase1_e_Update(RT_MODEL_APF_Path_Planning_20_T * const
  APF_Path_Planning_2023a_M, B_SubPhase1_APF_Path_Planni_i_T *localB,
  DW_SubPhase1_APF_Path_Plann_m_T *localDW)
{
  if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
    // Update for Delay: '<S257>/Delay1'
    localDW->icLoad = false;
    localDW->Delay1_DSTATE = localB->e_out;

    // Update for Delay: '<S259>/Delay1'
    localDW->icLoad_g = false;
    localDW->Delay1_DSTATE_e = localB->Subtract;

    // Update for Delay: '<S261>/Delay1'
    localDW->icLoad_h = false;
    localDW->Delay1_DSTATE_o = localB->Subtract2;
  }
}

//
// System initialize for action system:
//    '<S349>/Target Tracker'
//    '<S349>/Target Finder'
//
void APF_Path_Pla_TargetTracker_Init(real_T rty_Out1[3],
  P_TargetTracker_APF_Path_Plan_T *localP, X_TargetTracker_APF_Path_Plan_T
  *localX)
{
  // InitializeConditions for TransferFcn: '<S366>/Pseudo Derivative'
  localX->PseudoDerivative_CSTATE = 0.0;

  // InitializeConditions for TransferFcn: '<S366>/Pseudo Derivative1'
  localX->PseudoDerivative1_CSTATE = 0.0;

  // InitializeConditions for TransferFcn: '<S366>/Pseudo Derivative2'
  localX->PseudoDerivative2_CSTATE = 0.0;

  // SystemInitialize for Outport: '<S356>/Out1'
  rty_Out1[0] = localP->Out1_Y0;
  rty_Out1[1] = localP->Out1_Y0;
  rty_Out1[2] = localP->Out1_Y0;
}

//
// Outputs for action system:
//    '<S349>/Target Tracker'
//    '<S349>/Target Finder'
//
void APF_Path_Planning_TargetTracker(real_T rtu_e_x, real_T rtu_e_y, real_T
  rtu_e_t, real_T rty_Out1[3], P_TargetTracker_APF_Path_Plan_T *localP,
  X_TargetTracker_APF_Path_Plan_T *localX)
{
  real_T rtu_e_x_0[6];

  // MATLAB Function: '<S366>/MATLAB Function' incorporates:
  //   Constant: '<S366>/Constant'
  //   TransferFcn: '<S366>/Pseudo Derivative'
  //   TransferFcn: '<S366>/Pseudo Derivative1'
  //   TransferFcn: '<S366>/Pseudo Derivative2'

  rtu_e_x_0[0] = rtu_e_x;
  rtu_e_x_0[1] = rtu_e_y;
  rtu_e_x_0[2] = rtu_e_t;
  rtu_e_x_0[3] = localP->PseudoDerivative_C * localX->PseudoDerivative_CSTATE +
    localP->PseudoDerivative_D * rtu_e_x;
  rtu_e_x_0[4] = localP->PseudoDerivative1_C * localX->PseudoDerivative1_CSTATE
    + localP->PseudoDerivative1_D * rtu_e_y;
  rtu_e_x_0[5] = localP->PseudoDerivative2_C * localX->PseudoDerivative2_CSTATE
    + localP->PseudoDerivative2_D * rtu_e_t;
  for (int32_T i = 0; i < 3; i++) {
    real_T tmp;
    tmp = 0.0;
    for (int32_T i_0 = 0; i_0 < 6; i_0++) {
      tmp += APF_Path_Planning_2023a_P.k[3 * i_0 + i] * rtu_e_x_0[i_0];
    }

    rty_Out1[i] = tmp;
  }

  // End of MATLAB Function: '<S366>/MATLAB Function'
}

//
// Derivatives for action system:
//    '<S349>/Target Tracker'
//    '<S349>/Target Finder'
//
void APF_Path_Pl_TargetTracker_Deriv(real_T rtu_e_x, real_T rtu_e_y, real_T
  rtu_e_t, P_TargetTracker_APF_Path_Plan_T *localP,
  X_TargetTracker_APF_Path_Plan_T *localX, XDot_TargetTracker_APF_Path_P_T
  *localXdot)
{
  // Derivatives for TransferFcn: '<S366>/Pseudo Derivative'
  localXdot->PseudoDerivative_CSTATE = localP->PseudoDerivative_A *
    localX->PseudoDerivative_CSTATE;
  localXdot->PseudoDerivative_CSTATE += rtu_e_x;

  // Derivatives for TransferFcn: '<S366>/Pseudo Derivative1'
  localXdot->PseudoDerivative1_CSTATE = localP->PseudoDerivative1_A *
    localX->PseudoDerivative1_CSTATE;
  localXdot->PseudoDerivative1_CSTATE += rtu_e_y;

  // Derivatives for TransferFcn: '<S366>/Pseudo Derivative2'
  localXdot->PseudoDerivative2_CSTATE = localP->PseudoDerivative2_A *
    localX->PseudoDerivative2_CSTATE;
  localXdot->PseudoDerivative2_CSTATE += rtu_e_t;
}

//
// System initialize for action system:
//    '<Root>/Phase #4: Return Home'
//    '<Root>/Phase #5: Hold Home'
//
void APF_Path__Phase4ReturnHome_Init(B_Phase4ReturnHome_APF_Path_P_T *localB,
  DW_Phase4ReturnHome_APF_Path__T *localDW, P_Phase4ReturnHome_APF_Path_P_T
  *localP)
{
  // Start for If: '<S10>/This IF block determines whether or not to run the BLACK sim//exp' 
  localDW->ThisIFblockdetermineswhetherorn = -1;

  // Start for If: '<S10>/This IF block determines whether or not to run the BLUE sim//exp' 
  localDW->ThisIFblockdetermineswhethero_j = -1;

  // Start for If: '<S10>/This IF block determines whether or not to run the RED sim//exp ' 
  localDW->ThisIFblockdetermineswhethero_a = -1;

  // SystemInitialize for IfAction SubSystem: '<S10>/Change BLACK Behavior'
  // Start for If: '<S421>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_a = -1;

  // Start for If: '<S423>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_l = -1;

  // Start for If: '<S419>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_d = -1;

  // InitializeConditions for Delay: '<S421>/Delay1'
  localDW->icLoad_f = true;

  // InitializeConditions for Delay: '<S423>/Delay1'
  localDW->icLoad_jl = true;

  // InitializeConditions for Delay: '<S419>/Delay1'
  localDW->icLoad_ca = true;

  // SystemInitialize for IfAction SubSystem: '<S421>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S422>/In1' incorporates:
  //   Outport: '<S422>/Out1'

  localB->In1_g20asdtgi0 = localP->Out1_Y0_k;

  // End of SystemInitialize for SubSystem: '<S421>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S423>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S424>/In1' incorporates:
  //   Outport: '<S424>/Out1'

  localB->In1_g20asdtgi = localP->Out1_Y0_d;

  // End of SystemInitialize for SubSystem: '<S423>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S419>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S420>/In1' incorporates:
  //   Outport: '<S420>/Out1'

  localB->In1_g20asdtgi0c = localP->Out1_Y0;

  // End of SystemInitialize for SubSystem: '<S419>/Hold this value'
  // End of SystemInitialize for SubSystem: '<S10>/Change BLACK Behavior'

  // SystemInitialize for IfAction SubSystem: '<S10>/Change BLUE Behavior'
  // Start for If: '<S434>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_i = -1;

  // Start for If: '<S436>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_p = -1;

  // Start for If: '<S432>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_k = -1;

  // InitializeConditions for Delay: '<S434>/Delay1'
  localDW->icLoad_c = true;

  // InitializeConditions for Delay: '<S436>/Delay1'
  localDW->icLoad_p = true;

  // InitializeConditions for Delay: '<S432>/Delay1'
  localDW->icLoad_j = true;

  // SystemInitialize for IfAction SubSystem: '<S434>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S435>/In1' incorporates:
  //   Outport: '<S435>/Out1'

  localB->In1_g20asdt = localP->Out1_Y0_dv;

  // End of SystemInitialize for SubSystem: '<S434>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S436>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S437>/In1' incorporates:
  //   Outport: '<S437>/Out1'

  localB->In1_g20asd = localP->Out1_Y0_p;

  // End of SystemInitialize for SubSystem: '<S436>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S432>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S433>/In1' incorporates:
  //   Outport: '<S433>/Out1'

  localB->In1_g20asdtg = localP->Out1_Y0_b;

  // End of SystemInitialize for SubSystem: '<S432>/Hold this value'
  // End of SystemInitialize for SubSystem: '<S10>/Change BLUE Behavior'

  // SystemInitialize for IfAction SubSystem: '<S10>/Change RED Behavior'
  // Start for If: '<S446>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSubs = -1;

  // Start for If: '<S448>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_c = -1;

  // Start for If: '<S450>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_m = -1;

  // InitializeConditions for Delay: '<S446>/Delay1'
  localDW->icLoad = true;

  // InitializeConditions for Delay: '<S448>/Delay1'
  localDW->icLoad_g = true;

  // InitializeConditions for Delay: '<S450>/Delay1'
  localDW->icLoad_d = true;

  // SystemInitialize for IfAction SubSystem: '<S446>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S447>/In1' incorporates:
  //   Outport: '<S447>/Out1'

  localB->In1_g20as = localP->Out1_Y0_b3;

  // End of SystemInitialize for SubSystem: '<S446>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S448>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S449>/In1' incorporates:
  //   Outport: '<S449>/Out1'

  localB->In1_g20a = localP->Out1_Y0_b1;

  // End of SystemInitialize for SubSystem: '<S448>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S450>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S451>/In1' incorporates:
  //   Outport: '<S451>/Out1'

  localB->In1_g20 = localP->Out1_Y0_ba;

  // End of SystemInitialize for SubSystem: '<S450>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S414>/RED+ARM'
  // SystemInitialize for IfAction SubSystem: '<S445>/Simulated Position Controller' 
  // InitializeConditions for Delay: '<S462>/Delay1'
  localDW->icLoad_e = true;

  // InitializeConditions for Delay: '<S460>/Delay1'
  localDW->icLoad_gp = true;

  // InitializeConditions for Delay: '<S464>/Delay1'
  localDW->icLoad_k = true;

  // SystemInitialize for IfAction SubSystem: '<S462>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S463>/In1' incorporates:
  //   Outport: '<S463>/Out1'

  localB->In1_g = localP->Out1_Y0_o;

  // End of SystemInitialize for SubSystem: '<S462>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S460>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S461>/In1' incorporates:
  //   Outport: '<S461>/Out1'

  localB->In1_g2 = localP->Out1_Y0_c;

  // End of SystemInitialize for SubSystem: '<S460>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S464>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S465>/In1' incorporates:
  //   Outport: '<S465>/Out1'

  localB->In1 = localP->Out1_Y0_a;

  // End of SystemInitialize for SubSystem: '<S464>/Hold this value'
  // End of SystemInitialize for SubSystem: '<S445>/Simulated Position Controller' 
  // End of SystemInitialize for SubSystem: '<S414>/RED+ARM'
  // End of SystemInitialize for SubSystem: '<S10>/Change RED Behavior'
}

//
// Outputs for action system:
//    '<Root>/Phase #4: Return Home'
//    '<Root>/Phase #5: Hold Home'
//
void APF_Path_Plann_Phase4ReturnHome(RT_MODEL_APF_Path_Planning_20_T * const
  APF_Path_Planning_2023a_M, real_T *rtd_BLACK_Fx, real_T *rtd_BLACK_Fy, const
  real_T *rtd_BLACK_Px, const real_T *rtd_BLACK_Py, const real_T *rtd_BLACK_Rz,
  real_T *rtd_BLACK_Tz, real_T *rtd_BLUE_Fx, real_T *rtd_BLUE_Fy, const real_T
  *rtd_BLUE_Px, const real_T *rtd_BLUE_Py, const real_T *rtd_BLUE_Rz, real_T
  *rtd_BLUE_Tz, real_T *rtd_Float_State, real_T *rtd_RED_ARM_Control_Mode,
  real_T *rtd_RED_Elbow_Command, real_T *rtd_RED_Fx, real_T *rtd_RED_Fy, const
  real_T *rtd_RED_Px, const real_T *rtd_RED_Py, const real_T *rtd_RED_Rz, const
  real_T *rtd_RED_Rz_Elbow, const real_T *rtd_RED_Rz_Shoulder, const real_T
  *rtd_RED_Rz_Wrist, real_T *rtd_RED_Shoulder_Command, real_T *rtd_RED_Tz,
  real_T *rtd_RED_Tz_RW, real_T *rtd_RED_Wrist_Command, const real_T *rtd_WhoAmI,
  const real_T *rtd_isSim, B_Phase4ReturnHome_APF_Path_P_T *localB,
  DW_Phase4ReturnHome_APF_Path__T *localDW, P_Phase4ReturnHome_APF_Path_P_T
  *localP)
{
  real_T rtb_Sum6_bf;
  real_T rtb_Sum6_gp;
  real_T rtb_Sum6_py;
  int8_T rtAction;

  // If: '<S10>/This IF block determines whether or not to run the BLACK sim//exp' 
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
    if ((*rtd_WhoAmI == 2.0) || (*rtd_isSim == 1.0)) {
      rtAction = 0;
    }

    localDW->ThisIFblockdetermineswhetherorn = rtAction;
  } else {
    rtAction = localDW->ThisIFblockdetermineswhetherorn;
  }

  if (rtAction == 0) {
    // Outputs for IfAction SubSystem: '<S10>/Change BLACK Behavior' incorporates:
    //   ActionPort: '<S412>/Action Port'

    // Sum: '<S412>/Subtract' incorporates:
    //   Constant: '<S412>/Desired Px (BLACK)'

    localB->Subtract_c = APF_Path_Planning_2023a_P.home_states_BLACK[0] -
      *rtd_BLACK_Px;
    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // Delay: '<S421>/Delay1'
      if (localDW->icLoad_f) {
        localDW->Delay1_DSTATE_a = localB->Subtract_c;
      }

      // Delay: '<S421>/Delay1'
      localB->Delay1_j = localDW->Delay1_DSTATE_a;
    }

    // Sum: '<S421>/Sum6'
    localB->Sum6_hx = localB->Subtract_c - localB->Delay1_j;

    // If: '<S421>/if we went through a "step"'
    rtAction = -1;
    if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
      if (localB->Sum6_hx != 0.0) {
        rtAction = 0;
      }

      localDW->ifwewentthroughastep_ActiveSu_a = rtAction;
    } else {
      rtAction = localDW->ifwewentthroughastep_ActiveSu_a;
    }

    if (rtAction == 0) {
      // Outputs for IfAction SubSystem: '<S421>/Hold this value' incorporates:
      //   ActionPort: '<S422>/Action Port'

      // SignalConversion generated from: '<S422>/In1'
      localB->In1_g20asdtgi0 = localB->Sum6_hx;

      // End of Outputs for SubSystem: '<S421>/Hold this value'
    }

    // End of If: '<S421>/if we went through a "step"'

    // DataStoreWrite: '<S412>/BLACK_Fx' incorporates:
    //   Gain: '<S416>/kd_xb'
    //   Gain: '<S416>/kp_xb'
    //   Gain: '<S421>/divide by delta T'
    //   Sum: '<S416>/Sum3'

    *rtd_BLACK_Fx = 1.0 / APF_Path_Planning_2023a_P.baseRate *
      localB->In1_g20asdtgi0 * APF_Path_Planning_2023a_P.Kd_xb +
      APF_Path_Planning_2023a_P.Kp_xb * localB->Subtract_c;

    // Sum: '<S412>/Subtract1' incorporates:
    //   Constant: '<S412>/Desired Py (BLACK)'

    localB->Subtract1_k = APF_Path_Planning_2023a_P.home_states_BLACK[1] -
      *rtd_BLACK_Py;
    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // Delay: '<S423>/Delay1'
      if (localDW->icLoad_jl) {
        localDW->Delay1_DSTATE_jh = localB->Subtract1_k;
      }

      // Delay: '<S423>/Delay1'
      localB->Delay1_i = localDW->Delay1_DSTATE_jh;
    }

    // Sum: '<S423>/Sum6'
    localB->Sum6_hx = localB->Subtract1_k - localB->Delay1_i;

    // If: '<S423>/if we went through a "step"'
    rtAction = -1;
    if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
      if (localB->Sum6_hx != 0.0) {
        rtAction = 0;
      }

      localDW->ifwewentthroughastep_ActiveSu_l = rtAction;
    } else {
      rtAction = localDW->ifwewentthroughastep_ActiveSu_l;
    }

    if (rtAction == 0) {
      // Outputs for IfAction SubSystem: '<S423>/Hold this value' incorporates:
      //   ActionPort: '<S424>/Action Port'

      // SignalConversion generated from: '<S424>/In1'
      localB->In1_g20asdtgi = localB->Sum6_hx;

      // End of Outputs for SubSystem: '<S423>/Hold this value'
    }

    // End of If: '<S423>/if we went through a "step"'

    // DataStoreWrite: '<S412>/BLACK_Fy' incorporates:
    //   Gain: '<S417>/kd_yb'
    //   Gain: '<S417>/kp_yb'
    //   Gain: '<S423>/divide by delta T'
    //   Sum: '<S417>/Sum3'

    *rtd_BLACK_Fy = 1.0 / APF_Path_Planning_2023a_P.baseRate *
      localB->In1_g20asdtgi * APF_Path_Planning_2023a_P.Kd_yb +
      APF_Path_Planning_2023a_P.Kp_yb * localB->Subtract1_k;

    // MATLAB Function: '<S418>/MATLAB Function2' incorporates:
    //   Constant: '<S412>/Desired Attitude (BLACK)'

    APF_Path_Planni_MATLABFunction2(APF_Path_Planning_2023a_P.home_states_BLACK
      [2], localB->rtb_Oy_a_k, localB->rtb_Ox_d_m);

    // MATLAB Function: '<S418>/MATLAB Function3'
    APF_Path_Planni_MATLABFunction3(*rtd_BLACK_Rz, localB->rtb_Ox_kr_c);

    // Sum: '<S418>/Subtract2'
    localB->rtb_Ox_d_m[0] -= localB->rtb_Ox_kr_c[0];
    localB->rtb_Ox_d_m[1] -= localB->rtb_Ox_kr_c[1];

    // MATLAB Function: '<S418>/MATLAB Function4'
    APF_Path_Planni_MATLABFunction4(localB->rtb_Oy_a_k, localB->rtb_Ox_d_m,
      &localB->e_out_hp);
    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // Delay: '<S419>/Delay1'
      if (localDW->icLoad_ca) {
        localDW->Delay1_DSTATE_h5 = localB->e_out_hp;
      }

      // Delay: '<S419>/Delay1'
      localB->Delay1_c = localDW->Delay1_DSTATE_h5;
    }

    // Sum: '<S419>/Sum6'
    localB->Sum6_hx = localB->e_out_hp - localB->Delay1_c;

    // If: '<S419>/if we went through a "step"'
    rtAction = -1;
    if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
      if (localB->Sum6_hx != 0.0) {
        rtAction = 0;
      }

      localDW->ifwewentthroughastep_ActiveSu_d = rtAction;
    } else {
      rtAction = localDW->ifwewentthroughastep_ActiveSu_d;
    }

    if (rtAction == 0) {
      // Outputs for IfAction SubSystem: '<S419>/Hold this value' incorporates:
      //   ActionPort: '<S420>/Action Port'

      // SignalConversion generated from: '<S420>/In1'
      localB->In1_g20asdtgi0c = localB->Sum6_hx;

      // End of Outputs for SubSystem: '<S419>/Hold this value'
    }

    // End of If: '<S419>/if we went through a "step"'

    // DataStoreWrite: '<S412>/BLACK_Tz' incorporates:
    //   Gain: '<S415>/kd_tb'
    //   Gain: '<S415>/kp_tb'
    //   Gain: '<S419>/divide by delta T'
    //   Sum: '<S415>/Sum3'

    *rtd_BLACK_Tz = 1.0 / APF_Path_Planning_2023a_P.baseRate *
      localB->In1_g20asdtgi0c * APF_Path_Planning_2023a_P.Kd_tb +
      APF_Path_Planning_2023a_P.Kp_tb * localB->e_out_hp;
    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // DataStoreWrite: '<S412>/Data Store Write3' incorporates:
      //   Constant: '<S412>/Puck State'

      *rtd_Float_State = localP->PuckState_Value;
    }

    // End of Outputs for SubSystem: '<S10>/Change BLACK Behavior'
  }

  // End of If: '<S10>/This IF block determines whether or not to run the BLACK sim//exp' 

  // If: '<S10>/This IF block determines whether or not to run the BLUE sim//exp' 
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
    if ((*rtd_WhoAmI == 3.0) || (*rtd_isSim == 1.0)) {
      rtAction = 0;
    }

    localDW->ThisIFblockdetermineswhethero_j = rtAction;
  } else {
    rtAction = localDW->ThisIFblockdetermineswhethero_j;
  }

  if (rtAction == 0) {
    // Outputs for IfAction SubSystem: '<S10>/Change BLUE Behavior' incorporates:
    //   ActionPort: '<S413>/Action Port'

    // Sum: '<S413>/Subtract' incorporates:
    //   Constant: '<S413>/Desired Px (BLUE)'

    localB->Subtract_k = APF_Path_Planning_2023a_P.home_states_BLUE[0] -
      *rtd_BLUE_Px;
    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // Delay: '<S434>/Delay1'
      if (localDW->icLoad_c) {
        localDW->Delay1_DSTATE_f = localB->Subtract_k;
      }

      // Delay: '<S434>/Delay1'
      localB->Delay1_k = localDW->Delay1_DSTATE_f;
    }

    // Sum: '<S434>/Sum6'
    localB->Sum6_hx = localB->Subtract_k - localB->Delay1_k;

    // If: '<S434>/if we went through a "step"'
    rtAction = -1;
    if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
      if (localB->Sum6_hx != 0.0) {
        rtAction = 0;
      }

      localDW->ifwewentthroughastep_ActiveSu_i = rtAction;
    } else {
      rtAction = localDW->ifwewentthroughastep_ActiveSu_i;
    }

    if (rtAction == 0) {
      // Outputs for IfAction SubSystem: '<S434>/Hold this value' incorporates:
      //   ActionPort: '<S435>/Action Port'

      // SignalConversion generated from: '<S435>/In1'
      localB->In1_g20asdt = localB->Sum6_hx;

      // End of Outputs for SubSystem: '<S434>/Hold this value'
    }

    // End of If: '<S434>/if we went through a "step"'

    // DataStoreWrite: '<S413>/BLUE_Fx' incorporates:
    //   Gain: '<S429>/kd_xb'
    //   Gain: '<S429>/kp_xb'
    //   Gain: '<S434>/divide by delta T'
    //   Sum: '<S429>/Sum3'

    *rtd_BLUE_Fx = 1.0 / APF_Path_Planning_2023a_P.baseRate *
      localB->In1_g20asdt * APF_Path_Planning_2023a_P.Kd_xblue +
      APF_Path_Planning_2023a_P.Kp_xblue * localB->Subtract_k;

    // Sum: '<S413>/Subtract1' incorporates:
    //   Constant: '<S413>/Desired Py (BLUE)'

    localB->Subtract1_j = APF_Path_Planning_2023a_P.home_states_BLUE[1] -
      *rtd_BLUE_Py;
    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // Delay: '<S436>/Delay1'
      if (localDW->icLoad_p) {
        localDW->Delay1_DSTATE_i = localB->Subtract1_j;
      }

      // Delay: '<S436>/Delay1'
      localB->Delay1_g = localDW->Delay1_DSTATE_i;
    }

    // Sum: '<S436>/Sum6'
    localB->Sum6_hx = localB->Subtract1_j - localB->Delay1_g;

    // If: '<S436>/if we went through a "step"'
    rtAction = -1;
    if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
      if (localB->Sum6_hx != 0.0) {
        rtAction = 0;
      }

      localDW->ifwewentthroughastep_ActiveSu_p = rtAction;
    } else {
      rtAction = localDW->ifwewentthroughastep_ActiveSu_p;
    }

    if (rtAction == 0) {
      // Outputs for IfAction SubSystem: '<S436>/Hold this value' incorporates:
      //   ActionPort: '<S437>/Action Port'

      // SignalConversion generated from: '<S437>/In1'
      localB->In1_g20asd = localB->Sum6_hx;

      // End of Outputs for SubSystem: '<S436>/Hold this value'
    }

    // End of If: '<S436>/if we went through a "step"'

    // DataStoreWrite: '<S413>/BLUE_Fy' incorporates:
    //   Gain: '<S430>/kd_yb'
    //   Gain: '<S430>/kp_yb'
    //   Gain: '<S436>/divide by delta T'
    //   Sum: '<S430>/Sum3'

    *rtd_BLUE_Fy = 1.0 / APF_Path_Planning_2023a_P.baseRate * localB->In1_g20asd
      * APF_Path_Planning_2023a_P.Kd_yblue + APF_Path_Planning_2023a_P.Kp_yblue *
      localB->Subtract1_j;

    // MATLAB Function: '<S431>/MATLAB Function2' incorporates:
    //   Constant: '<S413>/Desired Attitude (BLUE)'

    APF_Path_Planni_MATLABFunction2(APF_Path_Planning_2023a_P.home_states_BLUE[2],
      localB->rtb_Oy_a_k, localB->rtb_Ox_d_m);

    // MATLAB Function: '<S431>/MATLAB Function3'
    APF_Path_Planni_MATLABFunction3(*rtd_BLUE_Rz, localB->rtb_Ox_kr_c);

    // Sum: '<S431>/Subtract2'
    localB->rtb_Ox_d_m[0] -= localB->rtb_Ox_kr_c[0];
    localB->rtb_Ox_d_m[1] -= localB->rtb_Ox_kr_c[1];

    // MATLAB Function: '<S431>/MATLAB Function4'
    APF_Path_Planni_MATLABFunction4(localB->rtb_Oy_a_k, localB->rtb_Ox_d_m,
      &localB->e_out_h);
    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // Delay: '<S432>/Delay1'
      if (localDW->icLoad_j) {
        localDW->Delay1_DSTATE_ol = localB->e_out_h;
      }

      // Delay: '<S432>/Delay1'
      localB->Delay1_p = localDW->Delay1_DSTATE_ol;
    }

    // Sum: '<S432>/Sum6'
    localB->Sum6_hx = localB->e_out_h - localB->Delay1_p;

    // If: '<S432>/if we went through a "step"'
    rtAction = -1;
    if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
      if (localB->Sum6_hx != 0.0) {
        rtAction = 0;
      }

      localDW->ifwewentthroughastep_ActiveSu_k = rtAction;
    } else {
      rtAction = localDW->ifwewentthroughastep_ActiveSu_k;
    }

    if (rtAction == 0) {
      // Outputs for IfAction SubSystem: '<S432>/Hold this value' incorporates:
      //   ActionPort: '<S433>/Action Port'

      // SignalConversion generated from: '<S433>/In1'
      localB->In1_g20asdtg = localB->Sum6_hx;

      // End of Outputs for SubSystem: '<S432>/Hold this value'
    }

    // End of If: '<S432>/if we went through a "step"'

    // DataStoreWrite: '<S413>/BLUE_Tz' incorporates:
    //   Gain: '<S428>/kd_tb'
    //   Gain: '<S428>/kp_tb'
    //   Gain: '<S432>/divide by delta T'
    //   Sum: '<S428>/Sum3'

    *rtd_BLUE_Tz = 1.0 / APF_Path_Planning_2023a_P.baseRate *
      localB->In1_g20asdtg * APF_Path_Planning_2023a_P.Kd_tblue +
      APF_Path_Planning_2023a_P.Kp_tblue * localB->e_out_h;
    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // DataStoreWrite: '<S413>/Data Store Write3' incorporates:
      //   Constant: '<S413>/Puck State'

      *rtd_Float_State = localP->PuckState_Value_d;
    }

    // End of Outputs for SubSystem: '<S10>/Change BLUE Behavior'
  }

  // End of If: '<S10>/This IF block determines whether or not to run the BLUE sim//exp' 

  // If: '<S10>/This IF block determines whether or not to run the RED sim//exp ' 
  rtAction = -1;
  if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
    if ((*rtd_WhoAmI == 1.0) || (*rtd_isSim == 1.0)) {
      rtAction = 0;
    }

    localDW->ThisIFblockdetermineswhethero_a = rtAction;
  } else {
    rtAction = localDW->ThisIFblockdetermineswhethero_a;
  }

  if (rtAction == 0) {
    // Outputs for IfAction SubSystem: '<S10>/Change RED Behavior' incorporates:
    //   ActionPort: '<S414>/Action Port'

    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // DataStoreWrite: '<S414>/RED_Tz_RW1' incorporates:
      //   Constant: '<S414>/Constant2'

      *rtd_RED_Tz_RW = localP->Constant2_Value;
    }

    // MATLAB Function: '<S444>/MATLAB Function2' incorporates:
    //   Constant: '<S414>/Desired Rz (RED)'

    APF_Path_Planni_MATLABFunction2(APF_Path_Planning_2023a_P.home_states_RED[2],
      localB->rtb_Oy_a_k, localB->rtb_Ox_d_m);

    // MATLAB Function: '<S444>/MATLAB Function3'
    APF_Path_Planni_MATLABFunction3(*rtd_RED_Rz, localB->rtb_Ox_kr_c);

    // Sum: '<S444>/Subtract2'
    localB->rtb_Ox_d_m[0] -= localB->rtb_Ox_kr_c[0];
    localB->rtb_Ox_d_m[1] -= localB->rtb_Ox_kr_c[1];

    // MATLAB Function: '<S444>/MATLAB Function4'
    APF_Path_Planni_MATLABFunction4(localB->rtb_Oy_a_k, localB->rtb_Ox_d_m,
      &localB->e_out);
    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // Delay: '<S446>/Delay1'
      if (localDW->icLoad) {
        localDW->Delay1_DSTATE = localB->e_out;
      }

      // Delay: '<S446>/Delay1'
      localB->Delay1 = localDW->Delay1_DSTATE;
    }

    // Sum: '<S446>/Sum6'
    localB->Sum6_hx = localB->e_out - localB->Delay1;

    // If: '<S446>/if we went through a "step"'
    rtAction = -1;
    if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
      if (localB->Sum6_hx != 0.0) {
        rtAction = 0;
      }

      localDW->ifwewentthroughastep_ActiveSubs = rtAction;
    } else {
      rtAction = localDW->ifwewentthroughastep_ActiveSubs;
    }

    if (rtAction == 0) {
      // Outputs for IfAction SubSystem: '<S446>/Hold this value' incorporates:
      //   ActionPort: '<S447>/Action Port'

      // SignalConversion generated from: '<S447>/In1'
      localB->In1_g20as = localB->Sum6_hx;

      // End of Outputs for SubSystem: '<S446>/Hold this value'
    }

    // End of If: '<S446>/if we went through a "step"'

    // DataStoreWrite: '<S414>/RED_Tz' incorporates:
    //   Gain: '<S441>/kd_tr'
    //   Gain: '<S441>/kp_tr'
    //   Gain: '<S446>/divide by delta T'
    //   Sum: '<S441>/Sum3'

    *rtd_RED_Tz = 1.0 / APF_Path_Planning_2023a_P.baseRate * localB->In1_g20as *
      APF_Path_Planning_2023a_P.Kd_tr + APF_Path_Planning_2023a_P.Kp_tr *
      localB->e_out;

    // Sum: '<S414>/Subtract' incorporates:
    //   Constant: '<S414>/Desired Px (RED)'

    localB->Subtract = APF_Path_Planning_2023a_P.home_states_RED[0] -
      *rtd_RED_Px;
    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // Delay: '<S448>/Delay1'
      if (localDW->icLoad_g) {
        localDW->Delay1_DSTATE_d = localB->Subtract;
      }

      // Delay: '<S448>/Delay1'
      localB->Delay1_b = localDW->Delay1_DSTATE_d;
    }

    // Sum: '<S448>/Sum6'
    localB->Sum6_hx = localB->Subtract - localB->Delay1_b;

    // If: '<S448>/if we went through a "step"'
    rtAction = -1;
    if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
      if (localB->Sum6_hx != 0.0) {
        rtAction = 0;
      }

      localDW->ifwewentthroughastep_ActiveSu_c = rtAction;
    } else {
      rtAction = localDW->ifwewentthroughastep_ActiveSu_c;
    }

    if (rtAction == 0) {
      // Outputs for IfAction SubSystem: '<S448>/Hold this value' incorporates:
      //   ActionPort: '<S449>/Action Port'

      // SignalConversion generated from: '<S449>/In1'
      localB->In1_g20a = localB->Sum6_hx;

      // End of Outputs for SubSystem: '<S448>/Hold this value'
    }

    // End of If: '<S448>/if we went through a "step"'

    // DataStoreWrite: '<S414>/RED_Fx' incorporates:
    //   Gain: '<S442>/kd_xr'
    //   Gain: '<S442>/kp_xr'
    //   Gain: '<S448>/divide by delta T'
    //   Sum: '<S442>/Sum3'

    *rtd_RED_Fx = 1.0 / APF_Path_Planning_2023a_P.baseRate * localB->In1_g20a *
      APF_Path_Planning_2023a_P.Kd_xr + APF_Path_Planning_2023a_P.Kp_xr *
      localB->Subtract;

    // Sum: '<S414>/Subtract1' incorporates:
    //   Constant: '<S414>/Desired Py (RED)'

    localB->Subtract1 = APF_Path_Planning_2023a_P.home_states_RED[1] -
      *rtd_RED_Py;
    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // Delay: '<S450>/Delay1'
      if (localDW->icLoad_d) {
        localDW->Delay1_DSTATE_o = localB->Subtract1;
      }

      // Delay: '<S450>/Delay1'
      localB->Delay1_d = localDW->Delay1_DSTATE_o;
    }

    // Sum: '<S450>/Sum6'
    localB->Sum6_hx = localB->Subtract1 - localB->Delay1_d;

    // If: '<S450>/if we went through a "step"'
    rtAction = -1;
    if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
      if (localB->Sum6_hx != 0.0) {
        rtAction = 0;
      }

      localDW->ifwewentthroughastep_ActiveSu_m = rtAction;
    } else {
      rtAction = localDW->ifwewentthroughastep_ActiveSu_m;
    }

    if (rtAction == 0) {
      // Outputs for IfAction SubSystem: '<S450>/Hold this value' incorporates:
      //   ActionPort: '<S451>/Action Port'

      // SignalConversion generated from: '<S451>/In1'
      localB->In1_g20 = localB->Sum6_hx;

      // End of Outputs for SubSystem: '<S450>/Hold this value'
    }

    // End of If: '<S450>/if we went through a "step"'

    // DataStoreWrite: '<S414>/RED_Fy' incorporates:
    //   Gain: '<S443>/kd_yr'
    //   Gain: '<S443>/kp_yr'
    //   Gain: '<S450>/divide by delta T'
    //   Sum: '<S443>/Sum3'

    *rtd_RED_Fy = 1.0 / APF_Path_Planning_2023a_P.baseRate * localB->In1_g20 *
      APF_Path_Planning_2023a_P.Kd_yr + APF_Path_Planning_2023a_P.Kp_yr *
      localB->Subtract1;
    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // DataStoreWrite: '<S414>/Data Store Write3' incorporates:
      //   Constant: '<S414>/Puck State'

      *rtd_Float_State = localP->PuckState_Value_c;

      // If: '<S414>/If' incorporates:
      //   Constant: '<S414>/Constant4'

      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo) &&
          ((APF_Path_Planning_2023a_P.platformSelection == 4.0) ||
           (APF_Path_Planning_2023a_P.platformSelection == 5.0) ||
           (APF_Path_Planning_2023a_P.platformSelection == 10.0) ||
           (APF_Path_Planning_2023a_P.platformSelection == 11.0))) {
        // Outputs for IfAction SubSystem: '<S414>/RED+ARM' incorporates:
        //   ActionPort: '<S445>/Action Port'

        // If: '<S445>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 
        if (*rtd_isSim == 1.0) {
          // Outputs for IfAction SubSystem: '<S445>/Simulated Position Controller' incorporates:
          //   ActionPort: '<S456>/Action Port'

          // Sum: '<S456>/Subtract2' incorporates:
          //   Constant: '<S445>/Constant1'

          localB->Sum6_hx = localP->Constant1_Value - *rtd_RED_Rz_Shoulder;

          // Delay: '<S462>/Delay1'
          if (localDW->icLoad_e) {
            localDW->Delay1_DSTATE_j = localB->Sum6_hx;
          }

          // Sum: '<S462>/Sum6' incorporates:
          //   Delay: '<S462>/Delay1'

          rtb_Sum6_gp = localB->Sum6_hx - localDW->Delay1_DSTATE_j;

          // If: '<S462>/if we went through a "step"'
          if (rtb_Sum6_gp != 0.0) {
            // Outputs for IfAction SubSystem: '<S462>/Hold this value' incorporates:
            //   ActionPort: '<S463>/Action Port'

            // SignalConversion generated from: '<S463>/In1'
            localB->In1_g = rtb_Sum6_gp;

            // End of Outputs for SubSystem: '<S462>/Hold this value'
          }

          // End of If: '<S462>/if we went through a "step"'

          // Sum: '<S458>/Sum3' incorporates:
          //   Gain: '<S458>/kd_sharm'
          //   Gain: '<S458>/kp_sharm'
          //   Gain: '<S462>/divide by delta T'

          rtb_Sum6_bf = 1.0 / APF_Path_Planning_2023a_P.baseRate * localB->In1_g
            * APF_Path_Planning_2023a_P.Kd_sharm +
            APF_Path_Planning_2023a_P.Kp_sharm * localB->Sum6_hx;

          // Saturate: '<S456>/Saturation'
          if (rtb_Sum6_bf > APF_Path_Planning_2023a_P.Tz_lim_sharm) {
            // DataStoreWrite: '<S445>/Data Store Write'
            *rtd_RED_Shoulder_Command = APF_Path_Planning_2023a_P.Tz_lim_sharm;
          } else if (rtb_Sum6_bf < -APF_Path_Planning_2023a_P.Tz_lim_sharm) {
            // DataStoreWrite: '<S445>/Data Store Write'
            *rtd_RED_Shoulder_Command = -APF_Path_Planning_2023a_P.Tz_lim_sharm;
          } else {
            // DataStoreWrite: '<S445>/Data Store Write'
            *rtd_RED_Shoulder_Command = rtb_Sum6_bf;
          }

          // End of Saturate: '<S456>/Saturation'

          // Sum: '<S456>/Subtract3' incorporates:
          //   Constant: '<S445>/Constant1'

          rtb_Sum6_gp = localP->Constant1_Value - *rtd_RED_Rz_Elbow;

          // Delay: '<S460>/Delay1'
          if (localDW->icLoad_gp) {
            localDW->Delay1_DSTATE_l = rtb_Sum6_gp;
          }

          // Sum: '<S460>/Sum6' incorporates:
          //   Delay: '<S460>/Delay1'

          rtb_Sum6_py = rtb_Sum6_gp - localDW->Delay1_DSTATE_l;

          // If: '<S460>/if we went through a "step"'
          if (rtb_Sum6_py != 0.0) {
            // Outputs for IfAction SubSystem: '<S460>/Hold this value' incorporates:
            //   ActionPort: '<S461>/Action Port'

            // SignalConversion generated from: '<S461>/In1'
            localB->In1_g2 = rtb_Sum6_py;

            // End of Outputs for SubSystem: '<S460>/Hold this value'
          }

          // End of If: '<S460>/if we went through a "step"'

          // Sum: '<S457>/Sum3' incorporates:
          //   Gain: '<S457>/kd_elarm'
          //   Gain: '<S457>/kp_elarm'
          //   Gain: '<S460>/divide by delta T'

          rtb_Sum6_bf = 1.0 / APF_Path_Planning_2023a_P.baseRate *
            localB->In1_g2 * APF_Path_Planning_2023a_P.Kd_elarm +
            APF_Path_Planning_2023a_P.Kp_elarm * rtb_Sum6_gp;

          // Saturate: '<S456>/Saturation1'
          if (rtb_Sum6_bf > APF_Path_Planning_2023a_P.Tz_lim_elarm) {
            // DataStoreWrite: '<S445>/Data Store Write1'
            *rtd_RED_Elbow_Command = APF_Path_Planning_2023a_P.Tz_lim_elarm;
          } else if (rtb_Sum6_bf < -APF_Path_Planning_2023a_P.Tz_lim_elarm) {
            // DataStoreWrite: '<S445>/Data Store Write1'
            *rtd_RED_Elbow_Command = -APF_Path_Planning_2023a_P.Tz_lim_elarm;
          } else {
            // DataStoreWrite: '<S445>/Data Store Write1'
            *rtd_RED_Elbow_Command = rtb_Sum6_bf;
          }

          // End of Saturate: '<S456>/Saturation1'

          // Sum: '<S456>/Subtract4' incorporates:
          //   Constant: '<S445>/Constant6'

          rtb_Sum6_py = localP->Constant6_Value - *rtd_RED_Rz_Wrist;

          // Delay: '<S464>/Delay1'
          if (localDW->icLoad_k) {
            localDW->Delay1_DSTATE_h = rtb_Sum6_py;
          }

          // Sum: '<S464>/Sum6' incorporates:
          //   Delay: '<S464>/Delay1'

          rtb_Sum6_bf = rtb_Sum6_py - localDW->Delay1_DSTATE_h;

          // If: '<S464>/if we went through a "step"'
          if (rtb_Sum6_bf != 0.0) {
            // Outputs for IfAction SubSystem: '<S464>/Hold this value' incorporates:
            //   ActionPort: '<S465>/Action Port'

            // SignalConversion generated from: '<S465>/In1'
            localB->In1 = rtb_Sum6_bf;

            // End of Outputs for SubSystem: '<S464>/Hold this value'
          }

          // End of If: '<S464>/if we went through a "step"'

          // Sum: '<S459>/Sum3' incorporates:
          //   Gain: '<S459>/kd_wrarm'
          //   Gain: '<S459>/kp_wrarm'
          //   Gain: '<S464>/divide by delta T'

          rtb_Sum6_bf = 1.0 / APF_Path_Planning_2023a_P.baseRate * localB->In1 *
            APF_Path_Planning_2023a_P.Kd_wrarm +
            APF_Path_Planning_2023a_P.Kp_wrarm * rtb_Sum6_py;

          // Saturate: '<S456>/Saturation3'
          if (rtb_Sum6_bf > APF_Path_Planning_2023a_P.Tz_lim_wrarm) {
            // DataStoreWrite: '<S445>/Data Store Write2'
            *rtd_RED_Wrist_Command = APF_Path_Planning_2023a_P.Tz_lim_wrarm;
          } else if (rtb_Sum6_bf < -APF_Path_Planning_2023a_P.Tz_lim_wrarm) {
            // DataStoreWrite: '<S445>/Data Store Write2'
            *rtd_RED_Wrist_Command = -APF_Path_Planning_2023a_P.Tz_lim_wrarm;
          } else {
            // DataStoreWrite: '<S445>/Data Store Write2'
            *rtd_RED_Wrist_Command = rtb_Sum6_bf;
          }

          // End of Saturate: '<S456>/Saturation3'

          // Update for Delay: '<S462>/Delay1'
          localDW->icLoad_e = false;
          localDW->Delay1_DSTATE_j = localB->Sum6_hx;

          // Update for Delay: '<S460>/Delay1'
          localDW->icLoad_gp = false;
          localDW->Delay1_DSTATE_l = rtb_Sum6_gp;

          // Update for Delay: '<S464>/Delay1'
          localDW->icLoad_k = false;
          localDW->Delay1_DSTATE_h = rtb_Sum6_py;

          // End of Outputs for SubSystem: '<S445>/Simulated Position Controller' 
        } else {
          // Outputs for IfAction SubSystem: '<S445>/Passthrough for Experiment' incorporates:
          //   ActionPort: '<S455>/Action Port'

          // DataStoreWrite: '<S445>/Data Store Write' incorporates:
          //   Constant: '<S445>/Constant1'
          //   SignalConversion generated from: '<S455>/q1_desired'

          *rtd_RED_Shoulder_Command = localP->Constant1_Value;

          // DataStoreWrite: '<S445>/Data Store Write1' incorporates:
          //   Constant: '<S445>/Constant1'
          //   SignalConversion generated from: '<S455>/q2_desired'

          *rtd_RED_Elbow_Command = localP->Constant1_Value;

          // DataStoreWrite: '<S445>/Data Store Write2' incorporates:
          //   Constant: '<S445>/Constant6'
          //   SignalConversion generated from: '<S455>/q3_desired'

          *rtd_RED_Wrist_Command = localP->Constant6_Value;

          // End of Outputs for SubSystem: '<S445>/Passthrough for Experiment'
        }

        // End of If: '<S445>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 

        // DataStoreWrite: '<S445>/Data Store Write3' incorporates:
        //   Constant: '<S445>/Constant7'

        *rtd_RED_ARM_Control_Mode = localP->Constant7_Value;

        // End of Outputs for SubSystem: '<S414>/RED+ARM'
      }

      // End of If: '<S414>/If'
    }

    // End of Outputs for SubSystem: '<S10>/Change RED Behavior'
  }

  // End of If: '<S10>/This IF block determines whether or not to run the RED sim//exp ' 
}

//
// Update for action system:
//    '<Root>/Phase #4: Return Home'
//    '<Root>/Phase #5: Hold Home'
//
void APF_Pat_Phase4ReturnHome_Update(RT_MODEL_APF_Path_Planning_20_T * const
  APF_Path_Planning_2023a_M, B_Phase4ReturnHome_APF_Path_P_T *localB,
  DW_Phase4ReturnHome_APF_Path__T *localDW)
{
  // Update for If: '<S10>/This IF block determines whether or not to run the BLACK sim//exp' 
  if (localDW->ThisIFblockdetermineswhetherorn == 0) {
    // Update for IfAction SubSystem: '<S10>/Change BLACK Behavior' incorporates:
    //   ActionPort: '<S412>/Action Port'

    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // Update for Delay: '<S421>/Delay1'
      localDW->icLoad_f = false;
      localDW->Delay1_DSTATE_a = localB->Subtract_c;

      // Update for Delay: '<S423>/Delay1'
      localDW->icLoad_jl = false;
      localDW->Delay1_DSTATE_jh = localB->Subtract1_k;

      // Update for Delay: '<S419>/Delay1'
      localDW->icLoad_ca = false;
      localDW->Delay1_DSTATE_h5 = localB->e_out_hp;
    }

    // End of Update for SubSystem: '<S10>/Change BLACK Behavior'
  }

  // End of Update for If: '<S10>/This IF block determines whether or not to run the BLACK sim//exp' 

  // Update for If: '<S10>/This IF block determines whether or not to run the BLUE sim//exp' 
  if (localDW->ThisIFblockdetermineswhethero_j == 0) {
    // Update for IfAction SubSystem: '<S10>/Change BLUE Behavior' incorporates:
    //   ActionPort: '<S413>/Action Port'

    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // Update for Delay: '<S434>/Delay1'
      localDW->icLoad_c = false;
      localDW->Delay1_DSTATE_f = localB->Subtract_k;

      // Update for Delay: '<S436>/Delay1'
      localDW->icLoad_p = false;
      localDW->Delay1_DSTATE_i = localB->Subtract1_j;

      // Update for Delay: '<S432>/Delay1'
      localDW->icLoad_j = false;
      localDW->Delay1_DSTATE_ol = localB->e_out_h;
    }

    // End of Update for SubSystem: '<S10>/Change BLUE Behavior'
  }

  // End of Update for If: '<S10>/This IF block determines whether or not to run the BLUE sim//exp' 

  // Update for If: '<S10>/This IF block determines whether or not to run the RED sim//exp ' 
  if (localDW->ThisIFblockdetermineswhethero_a == 0) {
    // Update for IfAction SubSystem: '<S10>/Change RED Behavior' incorporates:
    //   ActionPort: '<S414>/Action Port'

    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // Update for Delay: '<S446>/Delay1'
      localDW->icLoad = false;
      localDW->Delay1_DSTATE = localB->e_out;

      // Update for Delay: '<S448>/Delay1'
      localDW->icLoad_g = false;
      localDW->Delay1_DSTATE_d = localB->Subtract;

      // Update for Delay: '<S450>/Delay1'
      localDW->icLoad_d = false;
      localDW->Delay1_DSTATE_o = localB->Subtract1;
    }

    // End of Update for SubSystem: '<S10>/Change RED Behavior'
  }

  // End of Update for If: '<S10>/This IF block determines whether or not to run the RED sim//exp ' 
}

// Function for MATLAB Function: '<S629>/MATLAB Function1'
static real_T APF_Path_Planning_2023a_maximum(const real_T x[8])
{
  real_T ex;
  int32_T idx;
  int32_T k;
  if (!rtIsNaN(x[0])) {
    idx = 1;
  } else {
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!rtIsNaN(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    for (k = idx + 1; k < 9; k++) {
      real_T x_0;
      x_0 = x[k - 1];
      if (ex < x_0) {
        ex = x_0;
      }
    }
  }

  return ex;
}

//
// Output and update for atomic system:
//    '<S629>/MATLAB Function1'
//    '<S641>/MATLAB Function2'
//    '<S653>/MATLAB Function2'
//
void APF_Path_Plan_MATLABFunction1_l(const real_T rtu_ThrustPer[8], real_T
  rty_ThrustPer_Final[8])
{
  real_T TControl;
  real_T ThrustPer_Sat;
  real_T maxval;
  int32_T i;
  TControl = 1.0 / APF_Path_Planning_2023a_P.PWMFreq;
  maxval = APF_Path_Planning_2023a_maximum(rtu_ThrustPer);
  for (i = 0; i < 8; i++) {
    if (maxval > 1.0) {
      ThrustPer_Sat = rtu_ThrustPer[i] / maxval;
    } else {
      ThrustPer_Sat = rtu_ThrustPer[i];
    }

    if (ThrustPer_Sat > 0.007 / TControl) {
      rty_ThrustPer_Final[i] = ThrustPer_Sat;
    } else {
      rty_ThrustPer_Final[i] = 0.0;
    }
  }
}

// Function for MATLAB Function: '<S629>/MATLAB Function10'
static real_T APF_Path_Planning_202_maximum_p(const real_T x[8])
{
  real_T ex;
  int32_T idx;
  int32_T k;
  if (!rtIsNaN(x[0])) {
    idx = 1;
  } else {
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!rtIsNaN(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    for (k = idx + 1; k < 9; k++) {
      real_T x_0;
      x_0 = x[k - 1];
      if (ex < x_0) {
        ex = x_0;
      }
    }
  }

  return ex;
}

//
// Output and update for atomic system:
//    '<S629>/MATLAB Function10'
//    '<S641>/MATLAB Function6'
//    '<S653>/MATLAB Function5'
//
void APF_Path_Plann_MATLABFunction10(const real_T rtu_PWMs[8], real_T
  *rty_thrust_decay_factor, real_T *rty_count, B_MATLABFunction10_APF_Path_P_T
  *localB)
{
  real_T rtu_PWMs_0;
  real_T sum_of_duty_cycles;
  int32_T i;
  int32_T nz;
  boolean_T x[8];
  sum_of_duty_cycles = APF_Path_Planning_202_maximum_p(rtu_PWMs);
  for (i = 0; i < 8; i++) {
    rtu_PWMs_0 = rtu_PWMs[i];
    localB->PWMs[i] = rtu_PWMs_0;
    if (sum_of_duty_cycles > 1.0) {
      rtu_PWMs_0 /= sum_of_duty_cycles;
      localB->PWMs[i] = rtu_PWMs_0;
    }

    x[i] = (rtu_PWMs_0 > APF_Path_Planning_2023a_P.thruster_count_threshold);
  }

  nz = x[0];
  for (i = 0; i < 7; i++) {
    nz += x[i + 1];
  }

  for (i = 0; i < 8; i++) {
    sum_of_duty_cycles = localB->PWMs[i];
    if (sum_of_duty_cycles >= 0.0) {
      localB->positives_only[i] = sum_of_duty_cycles;
    } else {
      localB->positives_only[i] = 0.0;
    }
  }

  sum_of_duty_cycles = localB->positives_only[0];
  for (i = 0; i < 7; i++) {
    sum_of_duty_cycles += localB->positives_only[i + 1];
  }

  sum_of_duty_cycles /= static_cast<real_T>(nz);
  if ((sum_of_duty_cycles < 0.3) || (nz == 0)) {
    *rty_thrust_decay_factor = 1.0;
  } else {
    sum_of_duty_cycles = (0.6 - 2.0 * sum_of_duty_cycles) + 1.0;
    if (sum_of_duty_cycles >= 0.5) {
      *rty_thrust_decay_factor = sum_of_duty_cycles;
    } else {
      *rty_thrust_decay_factor = 0.5;
    }
  }

  *rty_count = nz;
}

//
// Output and update for atomic system:
//    '<S636>/Create Rotation Matrix'
//    '<S648>/Create Rotation Matrix'
//    '<S669>/Create Rotation Matrix'
//
void APF_Path_P_CreateRotationMatrix(real_T rtu_Rz, real_T rty_C_Ib[4])
{
  real_T x_tmp;
  real_T x_tmp_0;
  x_tmp = sin(rtu_Rz);
  x_tmp_0 = cos(rtu_Rz);
  if (fabs(-x_tmp) > fabs(x_tmp_0)) {
    real_T r_tmp;
    real_T t;
    r_tmp = x_tmp_0 / -x_tmp;
    t = 1.0 / (r_tmp * x_tmp_0 - x_tmp);
    x_tmp_0 = r_tmp * t;
    rty_C_Ib[0] = x_tmp_0;
    rty_C_Ib[1] = -t;
    rty_C_Ib[2] = -x_tmp / -x_tmp * t;
    rty_C_Ib[3] = x_tmp_0;
  } else {
    real_T r_tmp;
    real_T t;
    r_tmp = -x_tmp / x_tmp_0;
    t = 1.0 / (x_tmp_0 - r_tmp * x_tmp);
    rty_C_Ib[0] = x_tmp_0 / x_tmp_0 * t;
    rty_C_Ib[1] = -r_tmp * t;
    rty_C_Ib[2] = r_tmp * t;
    rty_C_Ib[3] = t;
  }
}

//
// Output and update for atomic system:
//    '<S630>/Create Rotation Matrix'
//    '<S642>/Create Rotation Matrix'
//    '<S654>/Create Rotation Matrix'
//
void APF_Path_CreateRotationMatrix_g(real_T rtu_Rz, real_T rty_C_bI[4])
{
  real_T tmp;
  real_T tmp_0;
  tmp = sin(rtu_Rz);
  tmp_0 = cos(rtu_Rz);
  rty_C_bI[0] = tmp_0;
  rty_C_bI[2] = tmp;
  rty_C_bI[1] = -tmp;
  rty_C_bI[3] = tmp_0;
}

static real_T APF_Path_Planning_rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      APF_Path_Planning_2023a_B.i4 = 1;
    } else {
      APF_Path_Planning_2023a_B.i4 = -1;
    }

    if (u1 > 0.0) {
      APF_Path_Planning_2023a_B.i5 = 1;
    } else {
      APF_Path_Planning_2023a_B.i5 = -1;
    }

    y = atan2(static_cast<real_T>(APF_Path_Planning_2023a_B.i4),
              static_cast<real_T>(APF_Path_Planning_2023a_B.i5));
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

static real_T APF_Path_Planning_rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  APF_Path_Planning_2023a_B.a_d = fabs(u0);
  APF_Path_Planning_2023a_B.b_e = fabs(u1);
  if (APF_Path_Planning_2023a_B.a_d < APF_Path_Planning_2023a_B.b_e) {
    APF_Path_Planning_2023a_B.a_d /= APF_Path_Planning_2023a_B.b_e;
    y = sqrt(APF_Path_Planning_2023a_B.a_d * APF_Path_Planning_2023a_B.a_d + 1.0)
      * APF_Path_Planning_2023a_B.b_e;
  } else if (APF_Path_Planning_2023a_B.a_d > APF_Path_Planning_2023a_B.b_e) {
    APF_Path_Planning_2023a_B.b_e /= APF_Path_Planning_2023a_B.a_d;
    y = sqrt(APF_Path_Planning_2023a_B.b_e * APF_Path_Planning_2023a_B.b_e + 1.0)
      * APF_Path_Planning_2023a_B.a_d;
  } else if (rtIsNaN(APF_Path_Planning_2023a_B.b_e)) {
    y = (rtNaN);
  } else {
    y = APF_Path_Planning_2023a_B.a_d * 1.4142135623730951;
  }

  return y;
}

static real_T APF_Path_Planning_2_rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    APF_Path_Planning_2023a_B.d = fabs(u0);
    APF_Path_Planning_2023a_B.d1 = fabs(u1);
    if (rtIsInf(u1)) {
      if (APF_Path_Planning_2023a_B.d == 1.0) {
        y = 1.0;
      } else if (APF_Path_Planning_2023a_B.d > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (APF_Path_Planning_2023a_B.d1 == 0.0) {
      y = 1.0;
    } else if (APF_Path_Planning_2023a_B.d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

static real_T APF__rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  // Uniform random number generator (random number between 0 and 1)

  // #define IA      16807                      magic multiplier = 7^5
  // #define IM      2147483647                 modulus = 2^31-1
  // #define IQ      127773                     IM div IA
  // #define IR      2836                       IM modulo IA
  // #define S       4.656612875245797e-10      reciprocal of 2^31-1
  // test = IA * (seed % IQ) - IR * (seed/IQ)
  // seed = test < 0 ? (test + IM) : test
  // return (seed*S)

  APF_Path_Planning_2023a_B.lo = *u % 127773U * 16807U;
  APF_Path_Planning_2023a_B.hi = *u / 127773U * 2836U;
  if (APF_Path_Planning_2023a_B.lo < APF_Path_Planning_2023a_B.hi) {
    *u = 2147483647U - (APF_Path_Planning_2023a_B.hi -
                        APF_Path_Planning_2023a_B.lo);
  } else {
    *u = APF_Path_Planning_2023a_B.lo - APF_Path_Planning_2023a_B.hi;
  }

  return static_cast<real_T>(*u) * 4.6566128752457969E-10;
}

static real_T APF__rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;

  // Normal (Gaussian) random number generator
  do {
    APF_Path_Planning_2023a_B.sr = 2.0 * APF__rt_urand_Upu32_Yd_f_pw_snf(u) -
      1.0;
    APF_Path_Planning_2023a_B.si = 2.0 * APF__rt_urand_Upu32_Yd_f_pw_snf(u) -
      1.0;
    APF_Path_Planning_2023a_B.si = APF_Path_Planning_2023a_B.sr *
      APF_Path_Planning_2023a_B.sr + APF_Path_Planning_2023a_B.si *
      APF_Path_Planning_2023a_B.si;
  } while (APF_Path_Planning_2023a_B.si > 1.0);

  y = sqrt(-2.0 * log(APF_Path_Planning_2023a_B.si) /
           APF_Path_Planning_2023a_B.si) * APF_Path_Planning_2023a_B.sr;
  return y;
}

// Function for MATLAB Function: '<S601>/Dynamics Model'
static real_T APF_Path_Planning_2023a_xnrm2(int32_T n, const real_T x[36],
  int32_T ix0)
{
  real_T y;
  y = 0.0;
  APF_Path_Planning_2023a_B.scale_bs = 3.3121686421112381E-170;
  APF_Path_Planning_2023a_B.kend_a = (ix0 + n) - 1;
  for (APF_Path_Planning_2023a_B.k_j = ix0; APF_Path_Planning_2023a_B.k_j <=
       APF_Path_Planning_2023a_B.kend_a; APF_Path_Planning_2023a_B.k_j++) {
    APF_Path_Planning_2023a_B.absxk_l = fabs(x[APF_Path_Planning_2023a_B.k_j - 1]);
    if (APF_Path_Planning_2023a_B.absxk_l > APF_Path_Planning_2023a_B.scale_bs)
    {
      APF_Path_Planning_2023a_B.t_h = APF_Path_Planning_2023a_B.scale_bs /
        APF_Path_Planning_2023a_B.absxk_l;
      y = y * APF_Path_Planning_2023a_B.t_h * APF_Path_Planning_2023a_B.t_h +
        1.0;
      APF_Path_Planning_2023a_B.scale_bs = APF_Path_Planning_2023a_B.absxk_l;
    } else {
      APF_Path_Planning_2023a_B.t_h = APF_Path_Planning_2023a_B.absxk_l /
        APF_Path_Planning_2023a_B.scale_bs;
      y += APF_Path_Planning_2023a_B.t_h * APF_Path_Planning_2023a_B.t_h;
    }
  }

  return APF_Path_Planning_2023a_B.scale_bs * sqrt(y);
}

// Function for MATLAB Function: '<S601>/Dynamics Model'
static real_T APF_Path_Planning_2023a_xdotc(int32_T n, const real_T x[36],
  int32_T ix0, const real_T y[36], int32_T iy0)
{
  real_T d;
  d = 0.0;
  APF_Path_Planning_2023a_B.b_m = static_cast<uint8_T>(n);
  for (APF_Path_Planning_2023a_B.k_c = 0; APF_Path_Planning_2023a_B.k_c <
       APF_Path_Planning_2023a_B.b_m; APF_Path_Planning_2023a_B.k_c++) {
    d += x[(ix0 + APF_Path_Planning_2023a_B.k_c) - 1] * y[(iy0 +
      APF_Path_Planning_2023a_B.k_c) - 1];
  }

  return d;
}

// Function for MATLAB Function: '<S601>/Dynamics Model'
static void APF_Path_Planning_2023a_xaxpy(int32_T n, real_T a, int32_T ix0,
  real_T y[36], int32_T iy0)
{
  if (!(a == 0.0)) {
    for (APF_Path_Planning_2023a_B.k_nv = 0; APF_Path_Planning_2023a_B.k_nv < n;
         APF_Path_Planning_2023a_B.k_nv++) {
      APF_Path_Planning_2023a_B.i1 = (iy0 + APF_Path_Planning_2023a_B.k_nv) - 1;
      y[APF_Path_Planning_2023a_B.i1] += y[(ix0 + APF_Path_Planning_2023a_B.k_nv)
        - 1] * a;
    }
  }
}

// Function for MATLAB Function: '<S601>/Dynamics Model'
static real_T APF_Path_Planning_2023a_xnrm2_c(int32_T n, const real_T x[6],
  int32_T ix0)
{
  real_T y;
  y = 0.0;
  APF_Path_Planning_2023a_B.scale_b = 3.3121686421112381E-170;
  APF_Path_Planning_2023a_B.kend = (ix0 + n) - 1;
  for (APF_Path_Planning_2023a_B.k_f = ix0; APF_Path_Planning_2023a_B.k_f <=
       APF_Path_Planning_2023a_B.kend; APF_Path_Planning_2023a_B.k_f++) {
    APF_Path_Planning_2023a_B.absxk = fabs(x[APF_Path_Planning_2023a_B.k_f - 1]);
    if (APF_Path_Planning_2023a_B.absxk > APF_Path_Planning_2023a_B.scale_b) {
      APF_Path_Planning_2023a_B.t_n = APF_Path_Planning_2023a_B.scale_b /
        APF_Path_Planning_2023a_B.absxk;
      y = y * APF_Path_Planning_2023a_B.t_n * APF_Path_Planning_2023a_B.t_n +
        1.0;
      APF_Path_Planning_2023a_B.scale_b = APF_Path_Planning_2023a_B.absxk;
    } else {
      APF_Path_Planning_2023a_B.t_n = APF_Path_Planning_2023a_B.absxk /
        APF_Path_Planning_2023a_B.scale_b;
      y += APF_Path_Planning_2023a_B.t_n * APF_Path_Planning_2023a_B.t_n;
    }
  }

  return APF_Path_Planning_2023a_B.scale_b * sqrt(y);
}

// Function for MATLAB Function: '<S601>/Dynamics Model'
static void APF_Path_Planning_2023a_xaxpy_j(int32_T n, real_T a, const real_T x
  [36], int32_T ix0, real_T y[6], int32_T iy0)
{
  if (!(a == 0.0)) {
    for (APF_Path_Planning_2023a_B.k_m3 = 0; APF_Path_Planning_2023a_B.k_m3 < n;
         APF_Path_Planning_2023a_B.k_m3++) {
      APF_Path_Planning_2023a_B.i3 = (iy0 + APF_Path_Planning_2023a_B.k_m3) - 1;
      y[APF_Path_Planning_2023a_B.i3] += x[(ix0 + APF_Path_Planning_2023a_B.k_m3)
        - 1] * a;
    }
  }
}

// Function for MATLAB Function: '<S601>/Dynamics Model'
static void APF_Path_Planning_2023_xaxpy_jv(int32_T n, real_T a, const real_T x
  [6], int32_T ix0, real_T y[36], int32_T iy0)
{
  if (!(a == 0.0)) {
    for (APF_Path_Planning_2023a_B.k_m = 0; APF_Path_Planning_2023a_B.k_m < n;
         APF_Path_Planning_2023a_B.k_m++) {
      APF_Path_Planning_2023a_B.i2 = (iy0 + APF_Path_Planning_2023a_B.k_m) - 1;
      y[APF_Path_Planning_2023a_B.i2] += x[(ix0 + APF_Path_Planning_2023a_B.k_m)
        - 1] * a;
    }
  }
}

// Function for MATLAB Function: '<S601>/Dynamics Model'
static void APF_Path_Planning_2023a_xswap(real_T x[36], int32_T ix0, int32_T iy0)
{
  for (APF_Path_Planning_2023a_B.k_n = 0; APF_Path_Planning_2023a_B.k_n < 6;
       APF_Path_Planning_2023a_B.k_n++) {
    APF_Path_Planning_2023a_B.temp_tmp_i = (ix0 + APF_Path_Planning_2023a_B.k_n)
      - 1;
    APF_Path_Planning_2023a_B.temp = x[APF_Path_Planning_2023a_B.temp_tmp_i];
    APF_Path_Planning_2023a_B.i_o = (iy0 + APF_Path_Planning_2023a_B.k_n) - 1;
    x[APF_Path_Planning_2023a_B.temp_tmp_i] = x[APF_Path_Planning_2023a_B.i_o];
    x[APF_Path_Planning_2023a_B.i_o] = APF_Path_Planning_2023a_B.temp;
  }
}

// Function for MATLAB Function: '<S601>/Dynamics Model'
static void APF_Path_Planning_2023a_xrotg(real_T *a, real_T *b, real_T *c,
  real_T *s)
{
  APF_Path_Planning_2023a_B.roe = *b;
  APF_Path_Planning_2023a_B.absa = fabs(*a);
  APF_Path_Planning_2023a_B.absb = fabs(*b);
  if (APF_Path_Planning_2023a_B.absa > APF_Path_Planning_2023a_B.absb) {
    APF_Path_Planning_2023a_B.roe = *a;
  }

  APF_Path_Planning_2023a_B.scale = APF_Path_Planning_2023a_B.absa +
    APF_Path_Planning_2023a_B.absb;
  if (APF_Path_Planning_2023a_B.scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    APF_Path_Planning_2023a_B.ads = APF_Path_Planning_2023a_B.absa /
      APF_Path_Planning_2023a_B.scale;
    APF_Path_Planning_2023a_B.bds = APF_Path_Planning_2023a_B.absb /
      APF_Path_Planning_2023a_B.scale;
    APF_Path_Planning_2023a_B.scale *= sqrt(APF_Path_Planning_2023a_B.ads *
      APF_Path_Planning_2023a_B.ads + APF_Path_Planning_2023a_B.bds *
      APF_Path_Planning_2023a_B.bds);
    if (APF_Path_Planning_2023a_B.roe < 0.0) {
      APF_Path_Planning_2023a_B.scale = -APF_Path_Planning_2023a_B.scale;
    }

    *c = *a / APF_Path_Planning_2023a_B.scale;
    *s = *b / APF_Path_Planning_2023a_B.scale;
    if (APF_Path_Planning_2023a_B.absa > APF_Path_Planning_2023a_B.absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = APF_Path_Planning_2023a_B.scale;
  }
}

// Function for MATLAB Function: '<S601>/Dynamics Model'
static void APF_Path_Planning_2023a_xrot(real_T x[36], int32_T ix0, int32_T iy0,
  real_T c, real_T s)
{
  for (APF_Path_Planning_2023a_B.k_jz = 0; APF_Path_Planning_2023a_B.k_jz < 6;
       APF_Path_Planning_2023a_B.k_jz++) {
    APF_Path_Planning_2023a_B.temp_tmp_tmp = (iy0 +
      APF_Path_Planning_2023a_B.k_jz) - 1;
    APF_Path_Planning_2023a_B.temp_tmp =
      x[APF_Path_Planning_2023a_B.temp_tmp_tmp];
    APF_Path_Planning_2023a_B.temp_tmp_tmp_o = (ix0 +
      APF_Path_Planning_2023a_B.k_jz) - 1;
    APF_Path_Planning_2023a_B.temp_tmp_b =
      x[APF_Path_Planning_2023a_B.temp_tmp_tmp_o];
    x[APF_Path_Planning_2023a_B.temp_tmp_tmp] =
      APF_Path_Planning_2023a_B.temp_tmp * c -
      APF_Path_Planning_2023a_B.temp_tmp_b * s;
    x[APF_Path_Planning_2023a_B.temp_tmp_tmp_o] =
      APF_Path_Planning_2023a_B.temp_tmp_b * c +
      APF_Path_Planning_2023a_B.temp_tmp * s;
  }
}

// Function for MATLAB Function: '<S601>/Dynamics Model'
static void APF_Path_Planning_2023a_svd(const real_T A[36], real_T U[36], real_T
  s[6], real_T V[36])
{
  boolean_T exitg1;
  memcpy(&APF_Path_Planning_2023a_B.b_A[0], &A[0], 36U * sizeof(real_T));
  for (APF_Path_Planning_2023a_B.i = 0; APF_Path_Planning_2023a_B.i < 6;
       APF_Path_Planning_2023a_B.i++) {
    APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.i] = 0.0;
    APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.i] = 0.0;
    APF_Path_Planning_2023a_B.work[APF_Path_Planning_2023a_B.i] = 0.0;
  }

  memset(&U[0], 0, 36U * sizeof(real_T));
  memset(&APF_Path_Planning_2023a_B.Vf[0], 0, 36U * sizeof(real_T));
  for (APF_Path_Planning_2023a_B.i = 0; APF_Path_Planning_2023a_B.i < 5;
       APF_Path_Planning_2023a_B.i++) {
    APF_Path_Planning_2023a_B.qp1 = APF_Path_Planning_2023a_B.i + 2;
    APF_Path_Planning_2023a_B.qs = 6 * APF_Path_Planning_2023a_B.i +
      APF_Path_Planning_2023a_B.i;
    APF_Path_Planning_2023a_B.qq = APF_Path_Planning_2023a_B.qs + 1;
    APF_Path_Planning_2023a_B.apply_transform = false;
    APF_Path_Planning_2023a_B.nrm = APF_Path_Planning_2023a_xnrm2(6 -
      APF_Path_Planning_2023a_B.i, APF_Path_Planning_2023a_B.b_A,
      APF_Path_Planning_2023a_B.qs + 1);
    if (APF_Path_Planning_2023a_B.nrm > 0.0) {
      APF_Path_Planning_2023a_B.apply_transform = true;
      if (APF_Path_Planning_2023a_B.b_A[APF_Path_Planning_2023a_B.qs] < 0.0) {
        APF_Path_Planning_2023a_B.nrm = -APF_Path_Planning_2023a_B.nrm;
      }

      APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.i] =
        APF_Path_Planning_2023a_B.nrm;
      if (fabs(APF_Path_Planning_2023a_B.nrm) >= 1.0020841800044864E-292) {
        APF_Path_Planning_2023a_B.nrm = 1.0 / APF_Path_Planning_2023a_B.nrm;
        APF_Path_Planning_2023a_B.qjj = (APF_Path_Planning_2023a_B.qs -
          APF_Path_Planning_2023a_B.i) + 6;
        for (APF_Path_Planning_2023a_B.e_k = APF_Path_Planning_2023a_B.qq;
             APF_Path_Planning_2023a_B.e_k <= APF_Path_Planning_2023a_B.qjj;
             APF_Path_Planning_2023a_B.e_k++) {
          APF_Path_Planning_2023a_B.b_A[APF_Path_Planning_2023a_B.e_k - 1] *=
            APF_Path_Planning_2023a_B.nrm;
        }
      } else {
        APF_Path_Planning_2023a_B.qjj = (APF_Path_Planning_2023a_B.qs -
          APF_Path_Planning_2023a_B.i) + 6;
        for (APF_Path_Planning_2023a_B.e_k = APF_Path_Planning_2023a_B.qq;
             APF_Path_Planning_2023a_B.e_k <= APF_Path_Planning_2023a_B.qjj;
             APF_Path_Planning_2023a_B.e_k++) {
          APF_Path_Planning_2023a_B.b_A[APF_Path_Planning_2023a_B.e_k - 1] /=
            APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.i];
        }
      }

      APF_Path_Planning_2023a_B.b_A[APF_Path_Planning_2023a_B.qs]++;
      APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.i] =
        -APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.i];
    } else {
      APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.i] = 0.0;
    }

    for (APF_Path_Planning_2023a_B.qq = APF_Path_Planning_2023a_B.qp1;
         APF_Path_Planning_2023a_B.qq < 7; APF_Path_Planning_2023a_B.qq++) {
      APF_Path_Planning_2023a_B.qjj = (APF_Path_Planning_2023a_B.qq - 1) * 6 +
        APF_Path_Planning_2023a_B.i;
      if (APF_Path_Planning_2023a_B.apply_transform) {
        APF_Path_Planning_2023a_xaxpy(6 - APF_Path_Planning_2023a_B.i,
          -(APF_Path_Planning_2023a_xdotc(6 - APF_Path_Planning_2023a_B.i,
          APF_Path_Planning_2023a_B.b_A, APF_Path_Planning_2023a_B.qs + 1,
          APF_Path_Planning_2023a_B.b_A, APF_Path_Planning_2023a_B.qjj + 1) /
            APF_Path_Planning_2023a_B.b_A[APF_Path_Planning_2023a_B.qs]),
          APF_Path_Planning_2023a_B.qs + 1, APF_Path_Planning_2023a_B.b_A,
          APF_Path_Planning_2023a_B.qjj + 1);
      }

      APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qq - 1] =
        APF_Path_Planning_2023a_B.b_A[APF_Path_Planning_2023a_B.qjj];
    }

    for (APF_Path_Planning_2023a_B.qq = APF_Path_Planning_2023a_B.i + 1;
         APF_Path_Planning_2023a_B.qq < 7; APF_Path_Planning_2023a_B.qq++) {
      APF_Path_Planning_2023a_B.qs = (6 * APF_Path_Planning_2023a_B.i +
        APF_Path_Planning_2023a_B.qq) - 1;
      U[APF_Path_Planning_2023a_B.qs] =
        APF_Path_Planning_2023a_B.b_A[APF_Path_Planning_2023a_B.qs];
    }

    if (APF_Path_Planning_2023a_B.i + 1 <= 4) {
      APF_Path_Planning_2023a_B.nrm = APF_Path_Planning_2023a_xnrm2_c(5 -
        APF_Path_Planning_2023a_B.i, APF_Path_Planning_2023a_B.e,
        APF_Path_Planning_2023a_B.i + 2);
      if (APF_Path_Planning_2023a_B.nrm == 0.0) {
        APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.i] = 0.0;
      } else {
        if (APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.i + 1] < 0.0)
        {
          APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.i] =
            -APF_Path_Planning_2023a_B.nrm;
        } else {
          APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.i] =
            APF_Path_Planning_2023a_B.nrm;
        }

        APF_Path_Planning_2023a_B.nrm =
          APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.i];
        if (fabs(APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.i]) >=
            1.0020841800044864E-292) {
          APF_Path_Planning_2023a_B.nrm = 1.0 /
            APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.i];
          for (APF_Path_Planning_2023a_B.qq = APF_Path_Planning_2023a_B.qp1;
               APF_Path_Planning_2023a_B.qq < 7; APF_Path_Planning_2023a_B.qq++)
          {
            APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qq - 1] *=
              APF_Path_Planning_2023a_B.nrm;
          }
        } else {
          for (APF_Path_Planning_2023a_B.qq = APF_Path_Planning_2023a_B.qp1;
               APF_Path_Planning_2023a_B.qq < 7; APF_Path_Planning_2023a_B.qq++)
          {
            APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qq - 1] /=
              APF_Path_Planning_2023a_B.nrm;
          }
        }

        APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.i + 1]++;
        APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.i] =
          -APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.i];
        for (APF_Path_Planning_2023a_B.qq = APF_Path_Planning_2023a_B.qp1;
             APF_Path_Planning_2023a_B.qq < 7; APF_Path_Planning_2023a_B.qq++) {
          APF_Path_Planning_2023a_B.work[APF_Path_Planning_2023a_B.qq - 1] = 0.0;
        }

        for (APF_Path_Planning_2023a_B.qq = APF_Path_Planning_2023a_B.qp1;
             APF_Path_Planning_2023a_B.qq < 7; APF_Path_Planning_2023a_B.qq++) {
          APF_Path_Planning_2023a_xaxpy_j(5 - APF_Path_Planning_2023a_B.i,
            APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qq - 1],
            APF_Path_Planning_2023a_B.b_A, (APF_Path_Planning_2023a_B.i + 6 *
            (APF_Path_Planning_2023a_B.qq - 1)) + 2,
            APF_Path_Planning_2023a_B.work, APF_Path_Planning_2023a_B.i + 2);
        }

        for (APF_Path_Planning_2023a_B.qq = APF_Path_Planning_2023a_B.qp1;
             APF_Path_Planning_2023a_B.qq < 7; APF_Path_Planning_2023a_B.qq++) {
          APF_Path_Planning_2023_xaxpy_jv(5 - APF_Path_Planning_2023a_B.i,
            -APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qq - 1] /
            APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.i + 1],
            APF_Path_Planning_2023a_B.work, APF_Path_Planning_2023a_B.i + 2,
            APF_Path_Planning_2023a_B.b_A, (APF_Path_Planning_2023a_B.i + 6 *
            (APF_Path_Planning_2023a_B.qq - 1)) + 2);
        }
      }

      for (APF_Path_Planning_2023a_B.qq = APF_Path_Planning_2023a_B.qp1;
           APF_Path_Planning_2023a_B.qq < 7; APF_Path_Planning_2023a_B.qq++) {
        APF_Path_Planning_2023a_B.Vf[(APF_Path_Planning_2023a_B.qq + 6 *
          APF_Path_Planning_2023a_B.i) - 1] =
          APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qq - 1];
      }
    }
  }

  APF_Path_Planning_2023a_B.i = 4;
  APF_Path_Planning_2023a_B.b_s[5] = APF_Path_Planning_2023a_B.b_A[35];
  APF_Path_Planning_2023a_B.e[4] = APF_Path_Planning_2023a_B.b_A[34];
  APF_Path_Planning_2023a_B.e[5] = 0.0;
  for (APF_Path_Planning_2023a_B.qp1 = 0; APF_Path_Planning_2023a_B.qp1 < 6;
       APF_Path_Planning_2023a_B.qp1++) {
    U[APF_Path_Planning_2023a_B.qp1 + 30] = 0.0;
  }

  U[35] = 1.0;
  for (APF_Path_Planning_2023a_B.qp1 = 4; APF_Path_Planning_2023a_B.qp1 >= 0;
       APF_Path_Planning_2023a_B.qp1--) {
    APF_Path_Planning_2023a_B.qq = 6 * APF_Path_Planning_2023a_B.qp1 +
      APF_Path_Planning_2023a_B.qp1;
    if (APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qp1] != 0.0) {
      for (APF_Path_Planning_2023a_B.qs = APF_Path_Planning_2023a_B.qp1 + 2;
           APF_Path_Planning_2023a_B.qs < 7; APF_Path_Planning_2023a_B.qs++) {
        APF_Path_Planning_2023a_B.qjj = ((APF_Path_Planning_2023a_B.qs - 1) * 6
          + APF_Path_Planning_2023a_B.qp1) + 1;
        APF_Path_Planning_2023a_xaxpy(6 - APF_Path_Planning_2023a_B.qp1,
          -(APF_Path_Planning_2023a_xdotc(6 - APF_Path_Planning_2023a_B.qp1, U,
          APF_Path_Planning_2023a_B.qq + 1, U, APF_Path_Planning_2023a_B.qjj) /
            U[APF_Path_Planning_2023a_B.qq]), APF_Path_Planning_2023a_B.qq + 1,
          U, APF_Path_Planning_2023a_B.qjj);
      }

      for (APF_Path_Planning_2023a_B.qjj = APF_Path_Planning_2023a_B.qp1 + 1;
           APF_Path_Planning_2023a_B.qjj < 7; APF_Path_Planning_2023a_B.qjj++) {
        APF_Path_Planning_2023a_B.qs = (6 * APF_Path_Planning_2023a_B.qp1 +
          APF_Path_Planning_2023a_B.qjj) - 1;
        U[APF_Path_Planning_2023a_B.qs] = -U[APF_Path_Planning_2023a_B.qs];
      }

      U[APF_Path_Planning_2023a_B.qq]++;
      for (APF_Path_Planning_2023a_B.qq = 0; APF_Path_Planning_2023a_B.qq <
           APF_Path_Planning_2023a_B.qp1; APF_Path_Planning_2023a_B.qq++) {
        U[APF_Path_Planning_2023a_B.qq + 6 * APF_Path_Planning_2023a_B.qp1] =
          0.0;
      }
    } else {
      for (APF_Path_Planning_2023a_B.qs = 0; APF_Path_Planning_2023a_B.qs < 6;
           APF_Path_Planning_2023a_B.qs++) {
        U[APF_Path_Planning_2023a_B.qs + 6 * APF_Path_Planning_2023a_B.qp1] =
          0.0;
      }

      U[APF_Path_Planning_2023a_B.qq] = 1.0;
    }
  }

  for (APF_Path_Planning_2023a_B.qp1 = 5; APF_Path_Planning_2023a_B.qp1 >= 0;
       APF_Path_Planning_2023a_B.qp1--) {
    if ((APF_Path_Planning_2023a_B.qp1 + 1 <= 4) &&
        (APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qp1] != 0.0)) {
      APF_Path_Planning_2023a_B.qq = (6 * APF_Path_Planning_2023a_B.qp1 +
        APF_Path_Planning_2023a_B.qp1) + 2;
      for (APF_Path_Planning_2023a_B.qs = APF_Path_Planning_2023a_B.qp1 + 2;
           APF_Path_Planning_2023a_B.qs < 7; APF_Path_Planning_2023a_B.qs++) {
        APF_Path_Planning_2023a_B.qjj = ((APF_Path_Planning_2023a_B.qs - 1) * 6
          + APF_Path_Planning_2023a_B.qp1) + 2;
        APF_Path_Planning_2023a_xaxpy(5 - APF_Path_Planning_2023a_B.qp1,
          -(APF_Path_Planning_2023a_xdotc(5 - APF_Path_Planning_2023a_B.qp1,
          APF_Path_Planning_2023a_B.Vf, APF_Path_Planning_2023a_B.qq,
          APF_Path_Planning_2023a_B.Vf, APF_Path_Planning_2023a_B.qjj) /
            APF_Path_Planning_2023a_B.Vf[APF_Path_Planning_2023a_B.qq - 1]),
          APF_Path_Planning_2023a_B.qq, APF_Path_Planning_2023a_B.Vf,
          APF_Path_Planning_2023a_B.qjj);
      }
    }

    for (APF_Path_Planning_2023a_B.qq = 0; APF_Path_Planning_2023a_B.qq < 6;
         APF_Path_Planning_2023a_B.qq++) {
      APF_Path_Planning_2023a_B.Vf[APF_Path_Planning_2023a_B.qq + 6 *
        APF_Path_Planning_2023a_B.qp1] = 0.0;
    }

    APF_Path_Planning_2023a_B.Vf[APF_Path_Planning_2023a_B.qp1 + 6 *
      APF_Path_Planning_2023a_B.qp1] = 1.0;
  }

  APF_Path_Planning_2023a_B.qp1 = 0;
  APF_Path_Planning_2023a_B.nrm = 0.0;
  for (APF_Path_Planning_2023a_B.qq = 0; APF_Path_Planning_2023a_B.qq < 6;
       APF_Path_Planning_2023a_B.qq++) {
    APF_Path_Planning_2023a_B.r =
      APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qq];
    if (APF_Path_Planning_2023a_B.r != 0.0) {
      APF_Path_Planning_2023a_B.rt = fabs(APF_Path_Planning_2023a_B.r);
      APF_Path_Planning_2023a_B.r /= APF_Path_Planning_2023a_B.rt;
      APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qq] =
        APF_Path_Planning_2023a_B.rt;
      if (APF_Path_Planning_2023a_B.qq + 1 < 6) {
        APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qq] /=
          APF_Path_Planning_2023a_B.r;
      }

      APF_Path_Planning_2023a_B.qs = 6 * APF_Path_Planning_2023a_B.qq + 1;
      for (APF_Path_Planning_2023a_B.qjj = APF_Path_Planning_2023a_B.qs;
           APF_Path_Planning_2023a_B.qjj <= APF_Path_Planning_2023a_B.qs + 5;
           APF_Path_Planning_2023a_B.qjj++) {
        U[APF_Path_Planning_2023a_B.qjj - 1] *= APF_Path_Planning_2023a_B.r;
      }
    }

    if (APF_Path_Planning_2023a_B.qq + 1 < 6) {
      APF_Path_Planning_2023a_B.r =
        APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qq];
      if (APF_Path_Planning_2023a_B.r != 0.0) {
        APF_Path_Planning_2023a_B.rt = fabs(APF_Path_Planning_2023a_B.r);
        APF_Path_Planning_2023a_B.r = APF_Path_Planning_2023a_B.rt /
          APF_Path_Planning_2023a_B.r;
        APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qq] =
          APF_Path_Planning_2023a_B.rt;
        APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qq + 1] *=
          APF_Path_Planning_2023a_B.r;
        APF_Path_Planning_2023a_B.qs = (APF_Path_Planning_2023a_B.qq + 1) * 6 +
          1;
        for (APF_Path_Planning_2023a_B.qjj = APF_Path_Planning_2023a_B.qs;
             APF_Path_Planning_2023a_B.qjj <= APF_Path_Planning_2023a_B.qs + 5;
             APF_Path_Planning_2023a_B.qjj++) {
          APF_Path_Planning_2023a_B.Vf[APF_Path_Planning_2023a_B.qjj - 1] *=
            APF_Path_Planning_2023a_B.r;
        }
      }
    }

    APF_Path_Planning_2023a_B.r = fabs
      (APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qq]);
    APF_Path_Planning_2023a_B.rt = fabs
      (APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qq]);
    if ((APF_Path_Planning_2023a_B.r >= APF_Path_Planning_2023a_B.rt) || rtIsNaN
        (APF_Path_Planning_2023a_B.rt)) {
      APF_Path_Planning_2023a_B.rt = APF_Path_Planning_2023a_B.r;
    }

    if ((!(APF_Path_Planning_2023a_B.nrm >= APF_Path_Planning_2023a_B.rt)) &&
        (!rtIsNaN(APF_Path_Planning_2023a_B.rt))) {
      APF_Path_Planning_2023a_B.nrm = APF_Path_Planning_2023a_B.rt;
    }
  }

  while ((APF_Path_Planning_2023a_B.i + 2 > 0) && (APF_Path_Planning_2023a_B.qp1
          < 75)) {
    APF_Path_Planning_2023a_B.qq = APF_Path_Planning_2023a_B.i + 1;
    exitg1 = false;
    while (!(exitg1 || (APF_Path_Planning_2023a_B.qq == 0))) {
      APF_Path_Planning_2023a_B.rt = fabs
        (APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qq - 1]);
      if (APF_Path_Planning_2023a_B.rt <= (fabs
           (APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qq - 1]) +
           fabs(APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qq])) *
          2.2204460492503131E-16) {
        APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qq - 1] = 0.0;
        exitg1 = true;
      } else if ((APF_Path_Planning_2023a_B.rt <= 1.0020841800044864E-292) ||
                 ((APF_Path_Planning_2023a_B.qp1 > 20) &&
                  (APF_Path_Planning_2023a_B.rt <= 2.2204460492503131E-16 *
                   APF_Path_Planning_2023a_B.nrm))) {
        APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qq - 1] = 0.0;
        exitg1 = true;
      } else {
        APF_Path_Planning_2023a_B.qq--;
      }
    }

    if (APF_Path_Planning_2023a_B.i + 1 == APF_Path_Planning_2023a_B.qq) {
      APF_Path_Planning_2023a_B.qjj = 4;
    } else {
      APF_Path_Planning_2023a_B.qs = APF_Path_Planning_2023a_B.i + 2;
      APF_Path_Planning_2023a_B.qjj = APF_Path_Planning_2023a_B.i + 2;
      exitg1 = false;
      while ((!exitg1) && (APF_Path_Planning_2023a_B.qjj >=
                           APF_Path_Planning_2023a_B.qq)) {
        APF_Path_Planning_2023a_B.qs = APF_Path_Planning_2023a_B.qjj;
        if (APF_Path_Planning_2023a_B.qjj == APF_Path_Planning_2023a_B.qq) {
          exitg1 = true;
        } else {
          APF_Path_Planning_2023a_B.rt = 0.0;
          if (APF_Path_Planning_2023a_B.qjj < APF_Path_Planning_2023a_B.i + 2) {
            APF_Path_Planning_2023a_B.rt = fabs
              (APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qjj - 1]);
          }

          if (APF_Path_Planning_2023a_B.qjj > APF_Path_Planning_2023a_B.qq + 1)
          {
            APF_Path_Planning_2023a_B.rt += fabs
              (APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qjj - 2]);
          }

          APF_Path_Planning_2023a_B.r = fabs
            (APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qjj - 1]);
          if ((APF_Path_Planning_2023a_B.r <= 2.2204460492503131E-16 *
               APF_Path_Planning_2023a_B.rt) || (APF_Path_Planning_2023a_B.r <=
               1.0020841800044864E-292)) {
            APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qjj - 1] =
              0.0;
            exitg1 = true;
          } else {
            APF_Path_Planning_2023a_B.qjj--;
          }
        }
      }

      if (APF_Path_Planning_2023a_B.qs == APF_Path_Planning_2023a_B.qq) {
        APF_Path_Planning_2023a_B.qjj = 3;
      } else if (APF_Path_Planning_2023a_B.i + 2 == APF_Path_Planning_2023a_B.qs)
      {
        APF_Path_Planning_2023a_B.qjj = 1;
      } else {
        APF_Path_Planning_2023a_B.qjj = 2;
        APF_Path_Planning_2023a_B.qq = APF_Path_Planning_2023a_B.qs;
      }
    }

    switch (APF_Path_Planning_2023a_B.qjj) {
     case 1:
      APF_Path_Planning_2023a_B.rt =
        APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.i];
      APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.i] = 0.0;
      for (APF_Path_Planning_2023a_B.qs = APF_Path_Planning_2023a_B.i + 1;
           APF_Path_Planning_2023a_B.qs >= APF_Path_Planning_2023a_B.qq + 1;
           APF_Path_Planning_2023a_B.qs--) {
        APF_Path_Planning_2023a_xrotg
          (&APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qs - 1],
           &APF_Path_Planning_2023a_B.rt, &APF_Path_Planning_2023a_B.sqds,
           &APF_Path_Planning_2023a_B.smm1);
        if (APF_Path_Planning_2023a_B.qs > APF_Path_Planning_2023a_B.qq + 1) {
          APF_Path_Planning_2023a_B.r =
            APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qs - 2];
          APF_Path_Planning_2023a_B.rt = -APF_Path_Planning_2023a_B.smm1 *
            APF_Path_Planning_2023a_B.r;
          APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qs - 2] =
            APF_Path_Planning_2023a_B.r * APF_Path_Planning_2023a_B.sqds;
        }

        APF_Path_Planning_2023a_xrot(APF_Path_Planning_2023a_B.Vf, 6 *
          (APF_Path_Planning_2023a_B.qs - 1) + 1, 6 *
          (APF_Path_Planning_2023a_B.i + 1) + 1, APF_Path_Planning_2023a_B.sqds,
          APF_Path_Planning_2023a_B.smm1);
      }
      break;

     case 2:
      APF_Path_Planning_2023a_B.rt =
        APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qq - 1];
      APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qq - 1] = 0.0;
      for (APF_Path_Planning_2023a_B.qs = APF_Path_Planning_2023a_B.qq + 1;
           APF_Path_Planning_2023a_B.qs <= APF_Path_Planning_2023a_B.i + 2;
           APF_Path_Planning_2023a_B.qs++) {
        APF_Path_Planning_2023a_xrotg
          (&APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qs - 1],
           &APF_Path_Planning_2023a_B.rt, &APF_Path_Planning_2023a_B.sqds,
           &APF_Path_Planning_2023a_B.smm1);
        APF_Path_Planning_2023a_B.r =
          APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qs - 1];
        APF_Path_Planning_2023a_B.rt = -APF_Path_Planning_2023a_B.smm1 *
          APF_Path_Planning_2023a_B.r;
        APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qs - 1] =
          APF_Path_Planning_2023a_B.r * APF_Path_Planning_2023a_B.sqds;
        APF_Path_Planning_2023a_xrot(U, 6 * (APF_Path_Planning_2023a_B.qs - 1) +
          1, 6 * (APF_Path_Planning_2023a_B.qq - 1) + 1,
          APF_Path_Planning_2023a_B.sqds, APF_Path_Planning_2023a_B.smm1);
      }
      break;

     case 3:
      APF_Path_Planning_2023a_B.sqds =
        APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.i + 1];
      APF_Path_Planning_2023a_B.r = fabs(APF_Path_Planning_2023a_B.sqds);
      APF_Path_Planning_2023a_B.rt = fabs
        (APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.i]);
      if ((APF_Path_Planning_2023a_B.r >= APF_Path_Planning_2023a_B.rt) ||
          rtIsNaN(APF_Path_Planning_2023a_B.rt)) {
        APF_Path_Planning_2023a_B.rt = APF_Path_Planning_2023a_B.r;
      }

      APF_Path_Planning_2023a_B.r = fabs
        (APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.i]);
      if ((APF_Path_Planning_2023a_B.rt >= APF_Path_Planning_2023a_B.r) ||
          rtIsNaN(APF_Path_Planning_2023a_B.r)) {
        APF_Path_Planning_2023a_B.r = APF_Path_Planning_2023a_B.rt;
      }

      APF_Path_Planning_2023a_B.rt = fabs
        (APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qq]);
      if ((APF_Path_Planning_2023a_B.r >= APF_Path_Planning_2023a_B.rt) ||
          rtIsNaN(APF_Path_Planning_2023a_B.rt)) {
        APF_Path_Planning_2023a_B.rt = APF_Path_Planning_2023a_B.r;
      }

      APF_Path_Planning_2023a_B.r = fabs
        (APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qq]);
      if ((APF_Path_Planning_2023a_B.rt >= APF_Path_Planning_2023a_B.r) ||
          rtIsNaN(APF_Path_Planning_2023a_B.r)) {
        APF_Path_Planning_2023a_B.r = APF_Path_Planning_2023a_B.rt;
      }

      APF_Path_Planning_2023a_B.rt = APF_Path_Planning_2023a_B.sqds /
        APF_Path_Planning_2023a_B.r;
      APF_Path_Planning_2023a_B.smm1 =
        APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.i] /
        APF_Path_Planning_2023a_B.r;
      APF_Path_Planning_2023a_B.emm1 =
        APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.i] /
        APF_Path_Planning_2023a_B.r;
      APF_Path_Planning_2023a_B.sqds =
        APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qq] /
        APF_Path_Planning_2023a_B.r;
      APF_Path_Planning_2023a_B.smm1 = ((APF_Path_Planning_2023a_B.smm1 +
        APF_Path_Planning_2023a_B.rt) * (APF_Path_Planning_2023a_B.smm1 -
        APF_Path_Planning_2023a_B.rt) + APF_Path_Planning_2023a_B.emm1 *
        APF_Path_Planning_2023a_B.emm1) / 2.0;
      APF_Path_Planning_2023a_B.emm1 *= APF_Path_Planning_2023a_B.rt;
      APF_Path_Planning_2023a_B.emm1 *= APF_Path_Planning_2023a_B.emm1;
      if ((APF_Path_Planning_2023a_B.smm1 != 0.0) ||
          (APF_Path_Planning_2023a_B.emm1 != 0.0)) {
        APF_Path_Planning_2023a_B.shift = sqrt(APF_Path_Planning_2023a_B.smm1 *
          APF_Path_Planning_2023a_B.smm1 + APF_Path_Planning_2023a_B.emm1);
        if (APF_Path_Planning_2023a_B.smm1 < 0.0) {
          APF_Path_Planning_2023a_B.shift = -APF_Path_Planning_2023a_B.shift;
        }

        APF_Path_Planning_2023a_B.shift = APF_Path_Planning_2023a_B.emm1 /
          (APF_Path_Planning_2023a_B.smm1 + APF_Path_Planning_2023a_B.shift);
      } else {
        APF_Path_Planning_2023a_B.shift = 0.0;
      }

      APF_Path_Planning_2023a_B.rt = (APF_Path_Planning_2023a_B.sqds +
        APF_Path_Planning_2023a_B.rt) * (APF_Path_Planning_2023a_B.sqds -
        APF_Path_Planning_2023a_B.rt) + APF_Path_Planning_2023a_B.shift;
      APF_Path_Planning_2023a_B.r =
        APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.qq] /
        APF_Path_Planning_2023a_B.r * APF_Path_Planning_2023a_B.sqds;
      for (APF_Path_Planning_2023a_B.e_k = APF_Path_Planning_2023a_B.qq + 1;
           APF_Path_Planning_2023a_B.e_k <= APF_Path_Planning_2023a_B.i + 1;
           APF_Path_Planning_2023a_B.e_k++) {
        APF_Path_Planning_2023a_xrotg(&APF_Path_Planning_2023a_B.rt,
          &APF_Path_Planning_2023a_B.r, &APF_Path_Planning_2023a_B.sqds,
          &APF_Path_Planning_2023a_B.smm1);
        if (APF_Path_Planning_2023a_B.e_k > APF_Path_Planning_2023a_B.qq + 1) {
          APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.e_k - 2] =
            APF_Path_Planning_2023a_B.rt;
        }

        APF_Path_Planning_2023a_B.emm1 =
          APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.e_k - 1];
        APF_Path_Planning_2023a_B.r =
          APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.e_k - 1];
        APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.e_k - 1] =
          APF_Path_Planning_2023a_B.emm1 * APF_Path_Planning_2023a_B.sqds -
          APF_Path_Planning_2023a_B.r * APF_Path_Planning_2023a_B.smm1;
        APF_Path_Planning_2023a_B.rt = APF_Path_Planning_2023a_B.smm1 *
          APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.e_k];
        APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.e_k] *=
          APF_Path_Planning_2023a_B.sqds;
        APF_Path_Planning_2023a_B.qs = (APF_Path_Planning_2023a_B.e_k - 1) * 6 +
          1;
        APF_Path_Planning_2023a_B.qjj = 6 * APF_Path_Planning_2023a_B.e_k + 1;
        APF_Path_Planning_2023a_xrot(APF_Path_Planning_2023a_B.Vf,
          APF_Path_Planning_2023a_B.qs, APF_Path_Planning_2023a_B.qjj,
          APF_Path_Planning_2023a_B.sqds, APF_Path_Planning_2023a_B.smm1);
        APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.e_k - 1] =
          APF_Path_Planning_2023a_B.r * APF_Path_Planning_2023a_B.sqds +
          APF_Path_Planning_2023a_B.emm1 * APF_Path_Planning_2023a_B.smm1;
        APF_Path_Planning_2023a_xrotg
          (&APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.e_k - 1],
           &APF_Path_Planning_2023a_B.rt, &APF_Path_Planning_2023a_B.sqds,
           &APF_Path_Planning_2023a_B.smm1);
        APF_Path_Planning_2023a_B.r =
          APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.e_k - 1];
        APF_Path_Planning_2023a_B.rt = APF_Path_Planning_2023a_B.r *
          APF_Path_Planning_2023a_B.sqds + APF_Path_Planning_2023a_B.smm1 *
          APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.e_k];
        APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.e_k] =
          APF_Path_Planning_2023a_B.r * -APF_Path_Planning_2023a_B.smm1 +
          APF_Path_Planning_2023a_B.sqds *
          APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.e_k];
        APF_Path_Planning_2023a_B.r = APF_Path_Planning_2023a_B.smm1 *
          APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.e_k];
        APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.e_k] *=
          APF_Path_Planning_2023a_B.sqds;
        APF_Path_Planning_2023a_xrot(U, APF_Path_Planning_2023a_B.qs,
          APF_Path_Planning_2023a_B.qjj, APF_Path_Planning_2023a_B.sqds,
          APF_Path_Planning_2023a_B.smm1);
      }

      APF_Path_Planning_2023a_B.e[APF_Path_Planning_2023a_B.i] =
        APF_Path_Planning_2023a_B.rt;
      APF_Path_Planning_2023a_B.qp1++;
      break;

     default:
      if (APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qq] < 0.0) {
        APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qq] =
          -APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qq];
        APF_Path_Planning_2023a_B.qp1 = 6 * APF_Path_Planning_2023a_B.qq + 1;
        for (APF_Path_Planning_2023a_B.qs = APF_Path_Planning_2023a_B.qp1;
             APF_Path_Planning_2023a_B.qs <= APF_Path_Planning_2023a_B.qp1 + 5;
             APF_Path_Planning_2023a_B.qs++) {
          APF_Path_Planning_2023a_B.Vf[APF_Path_Planning_2023a_B.qs - 1] =
            -APF_Path_Planning_2023a_B.Vf[APF_Path_Planning_2023a_B.qs - 1];
        }
      }

      APF_Path_Planning_2023a_B.qp1 = APF_Path_Planning_2023a_B.qq + 1;
      while ((APF_Path_Planning_2023a_B.qq + 1 < 6) &&
             (APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qq] <
              APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qp1])) {
        APF_Path_Planning_2023a_B.rt =
          APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qq];
        APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qq] =
          APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qp1];
        APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qp1] =
          APF_Path_Planning_2023a_B.rt;
        APF_Path_Planning_2023a_B.qs = 6 * APF_Path_Planning_2023a_B.qq + 1;
        APF_Path_Planning_2023a_B.qjj = (APF_Path_Planning_2023a_B.qq + 1) * 6 +
          1;
        APF_Path_Planning_2023a_xswap(APF_Path_Planning_2023a_B.Vf,
          APF_Path_Planning_2023a_B.qs, APF_Path_Planning_2023a_B.qjj);
        APF_Path_Planning_2023a_xswap(U, APF_Path_Planning_2023a_B.qs,
          APF_Path_Planning_2023a_B.qjj);
        APF_Path_Planning_2023a_B.qq = APF_Path_Planning_2023a_B.qp1;
        APF_Path_Planning_2023a_B.qp1++;
      }

      APF_Path_Planning_2023a_B.qp1 = 0;
      APF_Path_Planning_2023a_B.i--;
      break;
    }
  }

  for (APF_Path_Planning_2023a_B.qp1 = 0; APF_Path_Planning_2023a_B.qp1 < 6;
       APF_Path_Planning_2023a_B.qp1++) {
    s[APF_Path_Planning_2023a_B.qp1] =
      APF_Path_Planning_2023a_B.b_s[APF_Path_Planning_2023a_B.qp1];
    for (APF_Path_Planning_2023a_B.i = 0; APF_Path_Planning_2023a_B.i < 6;
         APF_Path_Planning_2023a_B.i++) {
      V[APF_Path_Planning_2023a_B.i + 6 * APF_Path_Planning_2023a_B.qp1] =
        APF_Path_Planning_2023a_B.Vf[6 * APF_Path_Planning_2023a_B.qp1 +
        APF_Path_Planning_2023a_B.i];
    }
  }
}

static void APF_Path_Plannin_rt_invd3x3_snf(const real_T u[9], real_T y[9])
{
  memcpy(&APF_Path_Planning_2023a_B.x[0], &u[0], 9U * sizeof(real_T));
  APF_Path_Planning_2023a_B.p1 = 1;
  APF_Path_Planning_2023a_B.p2 = 3;
  APF_Path_Planning_2023a_B.p3 = 6;
  APF_Path_Planning_2023a_B.absx11 = fabs(u[0]);
  APF_Path_Planning_2023a_B.absx21 = fabs(u[1]);
  APF_Path_Planning_2023a_B.absx31 = fabs(u[2]);
  if ((APF_Path_Planning_2023a_B.absx21 > APF_Path_Planning_2023a_B.absx11) &&
      (APF_Path_Planning_2023a_B.absx21 > APF_Path_Planning_2023a_B.absx31)) {
    APF_Path_Planning_2023a_B.p1 = 4;
    APF_Path_Planning_2023a_B.p2 = 0;
    APF_Path_Planning_2023a_B.x[0] = u[1];
    APF_Path_Planning_2023a_B.x[1] = u[0];
    APF_Path_Planning_2023a_B.x[3] = u[4];
    APF_Path_Planning_2023a_B.x[4] = u[3];
    APF_Path_Planning_2023a_B.x[6] = u[7];
    APF_Path_Planning_2023a_B.x[7] = u[6];
  } else if (APF_Path_Planning_2023a_B.absx31 > APF_Path_Planning_2023a_B.absx11)
  {
    APF_Path_Planning_2023a_B.p1 = 7;
    APF_Path_Planning_2023a_B.p3 = 0;
    APF_Path_Planning_2023a_B.x[2] = APF_Path_Planning_2023a_B.x[0];
    APF_Path_Planning_2023a_B.x[0] = u[2];
    APF_Path_Planning_2023a_B.x[5] = APF_Path_Planning_2023a_B.x[3];
    APF_Path_Planning_2023a_B.x[3] = u[5];
    APF_Path_Planning_2023a_B.x[8] = APF_Path_Planning_2023a_B.x[6];
    APF_Path_Planning_2023a_B.x[6] = u[8];
  }

  APF_Path_Planning_2023a_B.absx11 = APF_Path_Planning_2023a_B.x[1] /
    APF_Path_Planning_2023a_B.x[0];
  APF_Path_Planning_2023a_B.x[1] = APF_Path_Planning_2023a_B.absx11;
  APF_Path_Planning_2023a_B.absx21 = APF_Path_Planning_2023a_B.x[2] /
    APF_Path_Planning_2023a_B.x[0];
  APF_Path_Planning_2023a_B.x[2] = APF_Path_Planning_2023a_B.absx21;
  APF_Path_Planning_2023a_B.x[4] -= APF_Path_Planning_2023a_B.absx11 *
    APF_Path_Planning_2023a_B.x[3];
  APF_Path_Planning_2023a_B.x[5] -= APF_Path_Planning_2023a_B.absx21 *
    APF_Path_Planning_2023a_B.x[3];
  APF_Path_Planning_2023a_B.x[7] -= APF_Path_Planning_2023a_B.absx11 *
    APF_Path_Planning_2023a_B.x[6];
  APF_Path_Planning_2023a_B.x[8] -= APF_Path_Planning_2023a_B.absx21 *
    APF_Path_Planning_2023a_B.x[6];
  if (fabs(APF_Path_Planning_2023a_B.x[5]) > fabs(APF_Path_Planning_2023a_B.x[4]))
  {
    APF_Path_Planning_2023a_B.itmp = APF_Path_Planning_2023a_B.p2;
    APF_Path_Planning_2023a_B.p2 = APF_Path_Planning_2023a_B.p3;
    APF_Path_Planning_2023a_B.p3 = APF_Path_Planning_2023a_B.itmp;
    APF_Path_Planning_2023a_B.x[1] = APF_Path_Planning_2023a_B.absx21;
    APF_Path_Planning_2023a_B.x[2] = APF_Path_Planning_2023a_B.absx11;
    APF_Path_Planning_2023a_B.absx11 = APF_Path_Planning_2023a_B.x[4];
    APF_Path_Planning_2023a_B.x[4] = APF_Path_Planning_2023a_B.x[5];
    APF_Path_Planning_2023a_B.x[5] = APF_Path_Planning_2023a_B.absx11;
    APF_Path_Planning_2023a_B.absx11 = APF_Path_Planning_2023a_B.x[7];
    APF_Path_Planning_2023a_B.x[7] = APF_Path_Planning_2023a_B.x[8];
    APF_Path_Planning_2023a_B.x[8] = APF_Path_Planning_2023a_B.absx11;
  }

  APF_Path_Planning_2023a_B.absx11 = APF_Path_Planning_2023a_B.x[5] /
    APF_Path_Planning_2023a_B.x[4];
  APF_Path_Planning_2023a_B.x[8] -= APF_Path_Planning_2023a_B.absx11 *
    APF_Path_Planning_2023a_B.x[7];
  APF_Path_Planning_2023a_B.absx21 = (APF_Path_Planning_2023a_B.x[1] *
    APF_Path_Planning_2023a_B.absx11 - APF_Path_Planning_2023a_B.x[2]) /
    APF_Path_Planning_2023a_B.x[8];
  APF_Path_Planning_2023a_B.absx31 = -(APF_Path_Planning_2023a_B.x[7] *
    APF_Path_Planning_2023a_B.absx21 + APF_Path_Planning_2023a_B.x[1]) /
    APF_Path_Planning_2023a_B.x[4];
  y[APF_Path_Planning_2023a_B.p1 - 1] = ((1.0 - APF_Path_Planning_2023a_B.x[3] *
    APF_Path_Planning_2023a_B.absx31) - APF_Path_Planning_2023a_B.x[6] *
    APF_Path_Planning_2023a_B.absx21) / APF_Path_Planning_2023a_B.x[0];
  y[APF_Path_Planning_2023a_B.p1] = APF_Path_Planning_2023a_B.absx31;
  y[APF_Path_Planning_2023a_B.p1 + 1] = APF_Path_Planning_2023a_B.absx21;
  APF_Path_Planning_2023a_B.absx21 = -APF_Path_Planning_2023a_B.absx11 /
    APF_Path_Planning_2023a_B.x[8];
  APF_Path_Planning_2023a_B.absx31 = (1.0 - APF_Path_Planning_2023a_B.x[7] *
    APF_Path_Planning_2023a_B.absx21) / APF_Path_Planning_2023a_B.x[4];
  y[APF_Path_Planning_2023a_B.p2] = -(APF_Path_Planning_2023a_B.x[3] *
    APF_Path_Planning_2023a_B.absx31 + APF_Path_Planning_2023a_B.x[6] *
    APF_Path_Planning_2023a_B.absx21) / APF_Path_Planning_2023a_B.x[0];
  y[APF_Path_Planning_2023a_B.p2 + 1] = APF_Path_Planning_2023a_B.absx31;
  y[APF_Path_Planning_2023a_B.p2 + 2] = APF_Path_Planning_2023a_B.absx21;
  APF_Path_Planning_2023a_B.absx21 = 1.0 / APF_Path_Planning_2023a_B.x[8];
  APF_Path_Planning_2023a_B.absx31 = -APF_Path_Planning_2023a_B.x[7] *
    APF_Path_Planning_2023a_B.absx21 / APF_Path_Planning_2023a_B.x[4];
  y[APF_Path_Planning_2023a_B.p3] = -(APF_Path_Planning_2023a_B.x[3] *
    APF_Path_Planning_2023a_B.absx31 + APF_Path_Planning_2023a_B.x[6] *
    APF_Path_Planning_2023a_B.absx21) / APF_Path_Planning_2023a_B.x[0];
  y[APF_Path_Planning_2023a_B.p3 + 1] = APF_Path_Planning_2023a_B.absx31;
  y[APF_Path_Planning_2023a_B.p3 + 2] = APF_Path_Planning_2023a_B.absx21;
}

// Model step function
void APF_Path_Planning_2023a_step(void)
{
  if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&APF_Path_Planning_2023a_M->solverInfo,
                          ((APF_Path_Planning_2023a_M->Timing.clockTick0+1)*
      APF_Path_Planning_2023a_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(APF_Path_Planning_2023a_M)) {
    APF_Path_Planning_2023a_M->Timing.t[0] = rtsiGetT
      (&APF_Path_Planning_2023a_M->solverInfo);
  }

  {
    real_T *lastU;
    char_T *sErr;
    static const int8_T b[8] = { -1, -1, 0, 0, 1, 1, 0, 0 };

    static const int8_T c[8] = { 0, 0, 1, 1, 0, 0, -1, -1 };

    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // S-Function (sdspFromNetwork): '<S2>/UDP Receive1'
      sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib
                            [0U]);
      APF_Path_Planning_2023a_B.ntIdx1 = 12;
      LibOutputs_Network(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib[0U],
                         &APF_Path_Planning_2023a_B.UDPReceive1_o1_k[0U],
                         &APF_Path_Planning_2023a_B.ntIdx1);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
      }

      // End of S-Function (sdspFromNetwork): '<S2>/UDP Receive1'

      // S-Function (byte2any): '<S2>/Byte Unpack'

      // Unpack: <S2>/Byte Unpack
      (void) memcpy(&APF_Path_Planning_2023a_B.ByteUnpack_o1,
                    &APF_Path_Planning_2023a_B.UDPReceive1_o1_k[0],
                    4);
      (void) memcpy(&APF_Path_Planning_2023a_B.ByteUnpack_o2,
                    &APF_Path_Planning_2023a_B.UDPReceive1_o1_k[4],
                    4);
      (void) memcpy(&APF_Path_Planning_2023a_B.ByteUnpack_o3,
                    &APF_Path_Planning_2023a_B.UDPReceive1_o1_k[8],
                    4);

      // DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
      //   DataStoreWrite: '<S2>/Data Store Write'

      APF_Path_Planning_2023a_DW.TX2_data1 =
        APF_Path_Planning_2023a_B.ByteUnpack_o1;

      // DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
      //   DataStoreWrite: '<S2>/Data Store Write1'

      APF_Path_Planning_2023a_DW.TX2_data2 =
        APF_Path_Planning_2023a_B.ByteUnpack_o2;

      // DataTypeConversion: '<S2>/Data Type Conversion2' incorporates:
      //   DataStoreWrite: '<S2>/Data Store Write2'

      APF_Path_Planning_2023a_DW.TX2_data3 =
        APF_Path_Planning_2023a_B.ByteUnpack_o3;

      // DataStoreWrite: '<S18>/Data Store Write' incorporates:
      //   Constant: '<S18>/Constant'

      APF_Path_Planning_2023a_DW.isSim = APF_Path_Planning_2023a_P.simMode;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
      }

      // End of DataStoreWrite: '<S18>/Data Store Write'
    }

    // If: '<Root>/Separate Phases' incorporates:
    //   Constant: '<Root>/Constant'
    //   Constant: '<Root>/Constant1'
    //   Constant: '<Root>/Constant2'
    //   Constant: '<Root>/Constant3'
    //   Constant: '<Root>/Constant4'
    //   Constant: '<Root>/Constant6'
    //   DataStoreRead: '<Root>/Universal_Time25'

    APF_Path_Planning_2023a_B.rtAction = -1;
    if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
      if (APF_Path_Planning_2023a_DW.Univ_Time <
          APF_Path_Planning_2023a_P.Phase0_End) {
        APF_Path_Planning_2023a_B.rtAction = 0;
      } else if ((APF_Path_Planning_2023a_DW.Univ_Time <
                  APF_Path_Planning_2023a_P.Phase1_End) &&
                 (APF_Path_Planning_2023a_DW.Univ_Time >=
                  APF_Path_Planning_2023a_P.Phase0_End)) {
        APF_Path_Planning_2023a_B.rtAction = 1;
      } else if ((APF_Path_Planning_2023a_DW.Univ_Time <
                  APF_Path_Planning_2023a_P.Phase2_End) &&
                 (APF_Path_Planning_2023a_DW.Univ_Time >=
                  APF_Path_Planning_2023a_P.Phase1_End)) {
        APF_Path_Planning_2023a_B.rtAction = 2;
      } else if ((APF_Path_Planning_2023a_DW.Univ_Time <
                  APF_Path_Planning_2023a_P.Phase3_End) &&
                 (APF_Path_Planning_2023a_DW.Univ_Time >=
                  APF_Path_Planning_2023a_P.Phase2_End)) {
        APF_Path_Planning_2023a_B.rtAction = 3;
      } else if ((APF_Path_Planning_2023a_DW.Univ_Time <
                  APF_Path_Planning_2023a_P.Phase4_End) &&
                 (APF_Path_Planning_2023a_DW.Univ_Time >=
                  APF_Path_Planning_2023a_P.Phase3_End)) {
        APF_Path_Planning_2023a_B.rtAction = 4;
      } else if ((APF_Path_Planning_2023a_DW.Univ_Time <
                  APF_Path_Planning_2023a_P.Phase5_End) &&
                 (APF_Path_Planning_2023a_DW.Univ_Time >=
                  APF_Path_Planning_2023a_P.Phase4_End)) {
        APF_Path_Planning_2023a_B.rtAction = 5;
      } else if (APF_Path_Planning_2023a_DW.Univ_Time >=
                 APF_Path_Planning_2023a_P.Phase5_End) {
        APF_Path_Planning_2023a_B.rtAction = 6;
      }

      APF_Path_Planning_2023a_DW.SeparatePhases_ActiveSubsystem =
        APF_Path_Planning_2023a_B.rtAction;
    } else {
      APF_Path_Planning_2023a_B.rtAction =
        APF_Path_Planning_2023a_DW.SeparatePhases_ActiveSubsystem;
    }

    switch (APF_Path_Planning_2023a_B.rtAction) {
     case 0:
      // Outputs for IfAction SubSystem: '<Root>/Phase #0: Synchronization' incorporates:
      //   ActionPort: '<S6>/Action Port'

      APF_Path__Phase0Synchronization(APF_Path_Planning_2023a_M,
        &APF_Path_Planning_2023a_DW.BLACK_Fx,
        &APF_Path_Planning_2023a_DW.BLACK_Fy,
        &APF_Path_Planning_2023a_DW.BLACK_Tz,
        &APF_Path_Planning_2023a_DW.BLUE_Fx, &APF_Path_Planning_2023a_DW.BLUE_Fy,
        &APF_Path_Planning_2023a_DW.BLUE_Tz,
        &APF_Path_Planning_2023a_DW.Float_State,
        &APF_Path_Planning_2023a_DW.RED_ARM_Control_Mode,
        &APF_Path_Planning_2023a_DW.RED_Fx, &APF_Path_Planning_2023a_DW.RED_Fy,
        &APF_Path_Planning_2023a_DW.RED_Tz, &APF_Path_Planning_2023a_B.RED_Tz_RW,
        &APF_Path_Planning_2023a_DW.WhoAmI, &APF_Path_Planning_2023a_DW.isSim,
        &APF_Path_Planning_2023a_DW.Phase0Synchronization,
        &APF_Path_Planning_2023a_P.Phase0Synchronization);

      // End of Outputs for SubSystem: '<Root>/Phase #0: Synchronization'
      break;

     case 1:
      // Outputs for IfAction SubSystem: '<Root>/Phase #1: Start Floating ' incorporates:
      //   ActionPort: '<S7>/Action Port'

      APF_Path__Phase0Synchronization(APF_Path_Planning_2023a_M,
        &APF_Path_Planning_2023a_DW.BLACK_Fx,
        &APF_Path_Planning_2023a_DW.BLACK_Fy,
        &APF_Path_Planning_2023a_DW.BLACK_Tz,
        &APF_Path_Planning_2023a_DW.BLUE_Fx, &APF_Path_Planning_2023a_DW.BLUE_Fy,
        &APF_Path_Planning_2023a_DW.BLUE_Tz,
        &APF_Path_Planning_2023a_DW.Float_State,
        &APF_Path_Planning_2023a_DW.RED_ARM_Control_Mode,
        &APF_Path_Planning_2023a_DW.RED_Fx, &APF_Path_Planning_2023a_DW.RED_Fy,
        &APF_Path_Planning_2023a_DW.RED_Tz, &APF_Path_Planning_2023a_B.RED_Tz_RW,
        &APF_Path_Planning_2023a_DW.WhoAmI, &APF_Path_Planning_2023a_DW.isSim,
        &APF_Path_Planning_2023a_DW.Phase1StartFloating,
        &APF_Path_Planning_2023a_P.Phase1StartFloating);

      // End of Outputs for SubSystem: '<Root>/Phase #1: Start Floating '
      break;

     case 2:
      // Outputs for IfAction SubSystem: '<Root>/Phase #2: Initial Position' incorporates:
      //   ActionPort: '<S8>/Action Port'

      // If: '<S8>/This IF block determines whether or not to run the BLACK sim//exp' incorporates:
      //   DataStoreRead: '<S8>/Data Store Read'
      //   DataStoreRead: '<S8>/Data Store Read1'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if ((APF_Path_Planning_2023a_DW.WhoAmI == 2.0) ||
            (APF_Path_Planning_2023a_DW.isSim == 1.0)) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_h2 =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_h2;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S8>/Change BLACK Behavior' incorporates:
        //   ActionPort: '<S33>/Action Port'

        // Sum: '<S33>/Subtract' incorporates:
        //   Constant: '<S33>/Desired Px (BLACK)'
        //   DataStoreRead: '<S33>/BLACK_Px'

        APF_Path_Planning_2023a_B.Subtract_d =
          APF_Path_Planning_2023a_P.init_states_BLACK[0] -
          APF_Path_Planning_2023a_DW.BLACK_Px;
        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          // Delay: '<S42>/Delay1'
          if (APF_Path_Planning_2023a_DW.icLoad_fp) {
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_i =
              APF_Path_Planning_2023a_B.Subtract_d;
          }

          // Delay: '<S42>/Delay1'
          APF_Path_Planning_2023a_B.Delay1_mm =
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_i;
        }

        // Sum: '<S42>/Sum6'
        APF_Path_Planning_2023a_B.RED_Tz_RW =
          APF_Path_Planning_2023a_B.Subtract_d -
          APF_Path_Planning_2023a_B.Delay1_mm;

        // If: '<S42>/if we went through a "step"'
        APF_Path_Planning_2023a_B.rtAction = -1;
        if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
          if (APF_Path_Planning_2023a_B.RED_Tz_RW != 0.0) {
            APF_Path_Planning_2023a_B.rtAction = 0;
          }

          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ba =
            APF_Path_Planning_2023a_B.rtAction;
        } else {
          APF_Path_Planning_2023a_B.rtAction =
            APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ba;
        }

        if (APF_Path_Planning_2023a_B.rtAction == 0) {
          // Outputs for IfAction SubSystem: '<S42>/Hold this value' incorporates:
          //   ActionPort: '<S43>/Action Port'

          // SignalConversion generated from: '<S43>/In1'
          APF_Path_Planning_2023a_B.In1_g20asdtgi0cdy =
            APF_Path_Planning_2023a_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S42>/Hold this value'
        }

        // End of If: '<S42>/if we went through a "step"'

        // Sum: '<S37>/Sum3' incorporates:
        //   DataStoreWrite: '<S33>/BLACK_Fx'
        //   Gain: '<S37>/kd_xb'
        //   Gain: '<S37>/kp_xb'
        //   Gain: '<S42>/divide by delta T'

        APF_Path_Planning_2023a_DW.BLACK_Fx = 1.0 /
          APF_Path_Planning_2023a_P.baseRate *
          APF_Path_Planning_2023a_B.In1_g20asdtgi0cdy *
          APF_Path_Planning_2023a_P.Kd_xb + APF_Path_Planning_2023a_P.Kp_xb *
          APF_Path_Planning_2023a_B.Subtract_d;

        // Sum: '<S33>/Subtract1' incorporates:
        //   Constant: '<S33>/Desired Py (BLACK)'
        //   DataStoreRead: '<S33>/BLACK_Py '

        APF_Path_Planning_2023a_B.Subtract1_g =
          APF_Path_Planning_2023a_P.init_states_BLACK[1] -
          APF_Path_Planning_2023a_DW.BLACK_Py;
        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          // Delay: '<S44>/Delay1'
          if (APF_Path_Planning_2023a_DW.icLoad_ig) {
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_c =
              APF_Path_Planning_2023a_B.Subtract1_g;
          }

          // Delay: '<S44>/Delay1'
          APF_Path_Planning_2023a_B.Delay1_hm =
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_c;
        }

        // Sum: '<S44>/Sum6'
        APF_Path_Planning_2023a_B.RED_Tz_RW =
          APF_Path_Planning_2023a_B.Subtract1_g -
          APF_Path_Planning_2023a_B.Delay1_hm;

        // If: '<S44>/if we went through a "step"'
        APF_Path_Planning_2023a_B.rtAction = -1;
        if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
          if (APF_Path_Planning_2023a_B.RED_Tz_RW != 0.0) {
            APF_Path_Planning_2023a_B.rtAction = 0;
          }

          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_il =
            APF_Path_Planning_2023a_B.rtAction;
        } else {
          APF_Path_Planning_2023a_B.rtAction =
            APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_il;
        }

        if (APF_Path_Planning_2023a_B.rtAction == 0) {
          // Outputs for IfAction SubSystem: '<S44>/Hold this value' incorporates:
          //   ActionPort: '<S45>/Action Port'

          // SignalConversion generated from: '<S45>/In1'
          APF_Path_Planning_2023a_B.In1_g20asdtgi0cd =
            APF_Path_Planning_2023a_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S44>/Hold this value'
        }

        // End of If: '<S44>/if we went through a "step"'

        // Sum: '<S38>/Sum3' incorporates:
        //   DataStoreWrite: '<S33>/BLACK_Fy'
        //   Gain: '<S38>/kd_yb'
        //   Gain: '<S38>/kp_yb'
        //   Gain: '<S44>/divide by delta T'

        APF_Path_Planning_2023a_DW.BLACK_Fy = 1.0 /
          APF_Path_Planning_2023a_P.baseRate *
          APF_Path_Planning_2023a_B.In1_g20asdtgi0cd *
          APF_Path_Planning_2023a_P.Kd_yb + APF_Path_Planning_2023a_P.Kp_yb *
          APF_Path_Planning_2023a_B.Subtract1_g;

        // MATLAB Function: '<S39>/MATLAB Function2' incorporates:
        //   Constant: '<S33>/Desired Attitude (BLACK)'

        APF_Path_Planni_MATLABFunction2
          (APF_Path_Planning_2023a_P.init_states_BLACK[2],
           APF_Path_Planning_2023a_B.rtb_Oy_kp_n,
           APF_Path_Planning_2023a_B.rtb_Ox_pc_l);

        // MATLAB Function: '<S39>/MATLAB Function3' incorporates:
        //   DataStoreRead: '<S33>/BLACK_Rz'

        APF_Path_Planni_MATLABFunction3(APF_Path_Planning_2023a_DW.BLACK_Rz,
          APF_Path_Planning_2023a_B.rtb_Ox_pr_p);

        // Sum: '<S39>/Subtract2'
        APF_Path_Planning_2023a_B.rtb_Ox_pc_l[0] -=
          APF_Path_Planning_2023a_B.rtb_Ox_pr_p[0];
        APF_Path_Planning_2023a_B.rtb_Ox_pc_l[1] -=
          APF_Path_Planning_2023a_B.rtb_Ox_pr_p[1];

        // MATLAB Function: '<S39>/MATLAB Function4'
        APF_Path_Planni_MATLABFunction4(APF_Path_Planning_2023a_B.rtb_Oy_kp_n,
          APF_Path_Planning_2023a_B.rtb_Ox_pc_l,
          &APF_Path_Planning_2023a_B.e_out_m2);
        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          // Delay: '<S40>/Delay1'
          if (APF_Path_Planning_2023a_DW.icLoad_p) {
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_c1 =
              APF_Path_Planning_2023a_B.e_out_m2;
          }

          // Delay: '<S40>/Delay1'
          APF_Path_Planning_2023a_B.Delay1_aj =
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_c1;
        }

        // Sum: '<S40>/Sum6'
        APF_Path_Planning_2023a_B.RED_Tz_RW = APF_Path_Planning_2023a_B.e_out_m2
          - APF_Path_Planning_2023a_B.Delay1_aj;

        // If: '<S40>/if we went through a "step"'
        APF_Path_Planning_2023a_B.rtAction = -1;
        if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
          if (APF_Path_Planning_2023a_B.RED_Tz_RW != 0.0) {
            APF_Path_Planning_2023a_B.rtAction = 0;
          }

          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_m =
            APF_Path_Planning_2023a_B.rtAction;
        } else {
          APF_Path_Planning_2023a_B.rtAction =
            APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_m;
        }

        if (APF_Path_Planning_2023a_B.rtAction == 0) {
          // Outputs for IfAction SubSystem: '<S40>/Hold this value' incorporates:
          //   ActionPort: '<S41>/Action Port'

          // SignalConversion generated from: '<S41>/In1'
          APF_Path_Planning_2023a_B.In1_g20asdtgi0cdyi =
            APF_Path_Planning_2023a_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S40>/Hold this value'
        }

        // End of If: '<S40>/if we went through a "step"'

        // Sum: '<S36>/Sum3' incorporates:
        //   DataStoreWrite: '<S33>/BLACK_Tz'
        //   Gain: '<S36>/kd_tb'
        //   Gain: '<S36>/kp_tb'
        //   Gain: '<S40>/divide by delta T'

        APF_Path_Planning_2023a_DW.BLACK_Tz = 1.0 /
          APF_Path_Planning_2023a_P.baseRate *
          APF_Path_Planning_2023a_B.In1_g20asdtgi0cdyi *
          APF_Path_Planning_2023a_P.Kd_tb + APF_Path_Planning_2023a_P.Kp_tb *
          APF_Path_Planning_2023a_B.e_out_m2;
        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          // DataStoreWrite: '<S33>/Data Store Write3' incorporates:
          //   Constant: '<S33>/Puck State'

          APF_Path_Planning_2023a_DW.Float_State =
            APF_Path_Planning_2023a_P.PuckState_Value;
        }

        // End of Outputs for SubSystem: '<S8>/Change BLACK Behavior'
      }

      // End of If: '<S8>/This IF block determines whether or not to run the BLACK sim//exp' 

      // If: '<S8>/This IF block determines whether or not to run the BLUE sim//exp' incorporates:
      //   DataStoreRead: '<S8>/Data Store Read'
      //   DataStoreRead: '<S8>/Data Store Read1'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if ((APF_Path_Planning_2023a_DW.WhoAmI == 3.0) ||
            (APF_Path_Planning_2023a_DW.isSim == 1.0)) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_l2 =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_l2;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S8>/Change BLUE Behavior' incorporates:
        //   ActionPort: '<S34>/Action Port'

        // Sum: '<S34>/Subtract' incorporates:
        //   Constant: '<S34>/Desired Px (BLUE)'
        //   DataStoreRead: '<S34>/BLUE_Px'

        APF_Path_Planning_2023a_B.Subtract_n =
          APF_Path_Planning_2023a_P.init_states_BLUE[0] -
          APF_Path_Planning_2023a_DW.BLUE_Px;
        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          // Delay: '<S55>/Delay1'
          if (APF_Path_Planning_2023a_DW.icLoad_o) {
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_mw =
              APF_Path_Planning_2023a_B.Subtract_n;
          }

          // Delay: '<S55>/Delay1'
          APF_Path_Planning_2023a_B.Delay1_p4 =
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_mw;
        }

        // Sum: '<S55>/Sum6'
        APF_Path_Planning_2023a_B.RED_Tz_RW =
          APF_Path_Planning_2023a_B.Subtract_n -
          APF_Path_Planning_2023a_B.Delay1_p4;

        // If: '<S55>/if we went through a "step"'
        APF_Path_Planning_2023a_B.rtAction = -1;
        if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
          if (APF_Path_Planning_2023a_B.RED_Tz_RW != 0.0) {
            APF_Path_Planning_2023a_B.rtAction = 0;
          }

          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_e =
            APF_Path_Planning_2023a_B.rtAction;
        } else {
          APF_Path_Planning_2023a_B.rtAction =
            APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_e;
        }

        if (APF_Path_Planning_2023a_B.rtAction == 0) {
          // Outputs for IfAction SubSystem: '<S55>/Hold this value' incorporates:
          //   ActionPort: '<S56>/Action Port'

          // SignalConversion generated from: '<S56>/In1'
          APF_Path_Planning_2023a_B.In1_g20asdtgi0 =
            APF_Path_Planning_2023a_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S55>/Hold this value'
        }

        // End of If: '<S55>/if we went through a "step"'

        // Sum: '<S50>/Sum3' incorporates:
        //   DataStoreWrite: '<S34>/BLUE_Fx'
        //   Gain: '<S50>/kd_xb'
        //   Gain: '<S50>/kp_xb'
        //   Gain: '<S55>/divide by delta T'

        APF_Path_Planning_2023a_DW.BLUE_Fx = 1.0 /
          APF_Path_Planning_2023a_P.baseRate *
          APF_Path_Planning_2023a_B.In1_g20asdtgi0 *
          APF_Path_Planning_2023a_P.Kd_xblue +
          APF_Path_Planning_2023a_P.Kp_xblue *
          APF_Path_Planning_2023a_B.Subtract_n;

        // Sum: '<S34>/Subtract1' incorporates:
        //   Constant: '<S34>/Desired Py (BLUE)'
        //   DataStoreRead: '<S34>/BLUE_Py '

        APF_Path_Planning_2023a_B.Subtract1_ld =
          APF_Path_Planning_2023a_P.init_states_BLUE[1] -
          APF_Path_Planning_2023a_DW.BLUE_Py;
        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          // Delay: '<S57>/Delay1'
          if (APF_Path_Planning_2023a_DW.icLoad_n) {
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_et =
              APF_Path_Planning_2023a_B.Subtract1_ld;
          }

          // Delay: '<S57>/Delay1'
          APF_Path_Planning_2023a_B.Delay1_j =
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_et;
        }

        // Sum: '<S57>/Sum6'
        APF_Path_Planning_2023a_B.RED_Tz_RW =
          APF_Path_Planning_2023a_B.Subtract1_ld -
          APF_Path_Planning_2023a_B.Delay1_j;

        // If: '<S57>/if we went through a "step"'
        APF_Path_Planning_2023a_B.rtAction = -1;
        if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
          if (APF_Path_Planning_2023a_B.RED_Tz_RW != 0.0) {
            APF_Path_Planning_2023a_B.rtAction = 0;
          }

          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_f =
            APF_Path_Planning_2023a_B.rtAction;
        } else {
          APF_Path_Planning_2023a_B.rtAction =
            APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_f;
        }

        if (APF_Path_Planning_2023a_B.rtAction == 0) {
          // Outputs for IfAction SubSystem: '<S57>/Hold this value' incorporates:
          //   ActionPort: '<S58>/Action Port'

          // SignalConversion generated from: '<S58>/In1'
          APF_Path_Planning_2023a_B.In1_g20asdtgi =
            APF_Path_Planning_2023a_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S57>/Hold this value'
        }

        // End of If: '<S57>/if we went through a "step"'

        // Sum: '<S51>/Sum3' incorporates:
        //   DataStoreWrite: '<S34>/BLUE_Fy'
        //   Gain: '<S51>/kd_yb'
        //   Gain: '<S51>/kp_yb'
        //   Gain: '<S57>/divide by delta T'

        APF_Path_Planning_2023a_DW.BLUE_Fy = 1.0 /
          APF_Path_Planning_2023a_P.baseRate *
          APF_Path_Planning_2023a_B.In1_g20asdtgi *
          APF_Path_Planning_2023a_P.Kd_yblue +
          APF_Path_Planning_2023a_P.Kp_yblue *
          APF_Path_Planning_2023a_B.Subtract1_ld;

        // MATLAB Function: '<S52>/MATLAB Function2' incorporates:
        //   Constant: '<S34>/Desired Attitude (BLUE)'

        APF_Path_Planni_MATLABFunction2
          (APF_Path_Planning_2023a_P.init_states_BLUE[2],
           APF_Path_Planning_2023a_B.rtb_Oy_kp_n,
           APF_Path_Planning_2023a_B.rtb_Ox_pc_l);

        // MATLAB Function: '<S52>/MATLAB Function3' incorporates:
        //   DataStoreRead: '<S34>/BLUE_Rz'

        APF_Path_Planni_MATLABFunction3(APF_Path_Planning_2023a_DW.BLUE_Rz,
          APF_Path_Planning_2023a_B.rtb_Ox_pr_p);

        // Sum: '<S52>/Subtract2'
        APF_Path_Planning_2023a_B.rtb_Ox_pc_l[0] -=
          APF_Path_Planning_2023a_B.rtb_Ox_pr_p[0];
        APF_Path_Planning_2023a_B.rtb_Ox_pc_l[1] -=
          APF_Path_Planning_2023a_B.rtb_Ox_pr_p[1];

        // MATLAB Function: '<S52>/MATLAB Function4'
        APF_Path_Planni_MATLABFunction4(APF_Path_Planning_2023a_B.rtb_Oy_kp_n,
          APF_Path_Planning_2023a_B.rtb_Ox_pc_l,
          &APF_Path_Planning_2023a_B.e_out_m);
        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          // Delay: '<S53>/Delay1'
          if (APF_Path_Planning_2023a_DW.icLoad_bb) {
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_a =
              APF_Path_Planning_2023a_B.e_out_m;
          }

          // Delay: '<S53>/Delay1'
          APF_Path_Planning_2023a_B.Delay1_ej =
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_a;
        }

        // Sum: '<S53>/Sum6'
        APF_Path_Planning_2023a_B.RED_Tz_RW = APF_Path_Planning_2023a_B.e_out_m
          - APF_Path_Planning_2023a_B.Delay1_ej;

        // If: '<S53>/if we went through a "step"'
        APF_Path_Planning_2023a_B.rtAction = -1;
        if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
          if (APF_Path_Planning_2023a_B.RED_Tz_RW != 0.0) {
            APF_Path_Planning_2023a_B.rtAction = 0;
          }

          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_jh =
            APF_Path_Planning_2023a_B.rtAction;
        } else {
          APF_Path_Planning_2023a_B.rtAction =
            APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_jh;
        }

        if (APF_Path_Planning_2023a_B.rtAction == 0) {
          // Outputs for IfAction SubSystem: '<S53>/Hold this value' incorporates:
          //   ActionPort: '<S54>/Action Port'

          // SignalConversion generated from: '<S54>/In1'
          APF_Path_Planning_2023a_B.In1_g20asdtgi0c =
            APF_Path_Planning_2023a_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S53>/Hold this value'
        }

        // End of If: '<S53>/if we went through a "step"'

        // Sum: '<S49>/Sum3' incorporates:
        //   DataStoreWrite: '<S34>/BLUE_Tz'
        //   Gain: '<S49>/kd_tb'
        //   Gain: '<S49>/kp_tb'
        //   Gain: '<S53>/divide by delta T'

        APF_Path_Planning_2023a_DW.BLUE_Tz = 1.0 /
          APF_Path_Planning_2023a_P.baseRate *
          APF_Path_Planning_2023a_B.In1_g20asdtgi0c *
          APF_Path_Planning_2023a_P.Kd_tblue +
          APF_Path_Planning_2023a_P.Kp_tblue * APF_Path_Planning_2023a_B.e_out_m;
        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          // DataStoreWrite: '<S34>/Data Store Write3' incorporates:
          //   Constant: '<S34>/Puck State'

          APF_Path_Planning_2023a_DW.Float_State =
            APF_Path_Planning_2023a_P.PuckState_Value_g;
        }

        // End of Outputs for SubSystem: '<S8>/Change BLUE Behavior'
      }

      // End of If: '<S8>/This IF block determines whether or not to run the BLUE sim//exp' 

      // If: '<S8>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
      //   DataStoreRead: '<S8>/Data Store Read'
      //   DataStoreRead: '<S8>/Data Store Read1'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if ((APF_Path_Planning_2023a_DW.WhoAmI == 1.0) ||
            (APF_Path_Planning_2023a_DW.isSim == 1.0)) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_gv =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_gv;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S8>/Change RED Behavior' incorporates:
        //   ActionPort: '<S35>/Action Port'

        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          // MATLAB Function: '<S65>/MATLAB Function2' incorporates:
          //   Constant: '<S35>/Constant'

          APF_Path_Planni_MATLABFunction2
            (APF_Path_Planning_2023a_P.init_states_RED[2],
             APF_Path_Planning_2023a_B.Oy, APF_Path_Planning_2023a_B.Ox);
        }

        // MATLAB Function: '<S65>/MATLAB Function3' incorporates:
        //   DataStoreRead: '<S35>/RED_Rz'

        APF_Path_Planni_MATLABFunction3(APF_Path_Planning_2023a_DW.RED_Rz,
          APF_Path_Planning_2023a_B.rtb_Oy_kp_n);

        // Sum: '<S65>/Subtract2'
        APF_Path_Planning_2023a_B.rtb_Oy_kp_n[0] = APF_Path_Planning_2023a_B.Ox
          [0] - APF_Path_Planning_2023a_B.rtb_Oy_kp_n[0];
        APF_Path_Planning_2023a_B.rtb_Oy_kp_n[1] = APF_Path_Planning_2023a_B.Ox
          [1] - APF_Path_Planning_2023a_B.rtb_Oy_kp_n[1];

        // MATLAB Function: '<S65>/MATLAB Function4'
        APF_Path_Planni_MATLABFunction4(APF_Path_Planning_2023a_B.Oy,
          APF_Path_Planning_2023a_B.rtb_Oy_kp_n,
          &APF_Path_Planning_2023a_B.e_out_k);
        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          // Delay: '<S67>/Delay1'
          if (APF_Path_Planning_2023a_DW.icLoad_g) {
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_gi =
              APF_Path_Planning_2023a_B.e_out_k;
          }

          // Delay: '<S67>/Delay1'
          APF_Path_Planning_2023a_B.Delay1_lo =
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_gi;
        }

        // Sum: '<S67>/Sum6'
        APF_Path_Planning_2023a_B.RED_Tz_RW = APF_Path_Planning_2023a_B.e_out_k
          - APF_Path_Planning_2023a_B.Delay1_lo;

        // If: '<S67>/if we went through a "step"'
        APF_Path_Planning_2023a_B.rtAction = -1;
        if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
          if (APF_Path_Planning_2023a_B.RED_Tz_RW != 0.0) {
            APF_Path_Planning_2023a_B.rtAction = 0;
          }

          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_n =
            APF_Path_Planning_2023a_B.rtAction;
        } else {
          APF_Path_Planning_2023a_B.rtAction =
            APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_n;
        }

        if (APF_Path_Planning_2023a_B.rtAction == 0) {
          // Outputs for IfAction SubSystem: '<S67>/Hold this value' incorporates:
          //   ActionPort: '<S68>/Action Port'

          // SignalConversion generated from: '<S68>/In1'
          APF_Path_Planning_2023a_B.In1_g20asdtg =
            APF_Path_Planning_2023a_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S67>/Hold this value'
        }

        // End of If: '<S67>/if we went through a "step"'

        // Sum: '<S62>/Sum3' incorporates:
        //   DataStoreWrite: '<S35>/RED_Tz'
        //   Gain: '<S62>/kd_tr'
        //   Gain: '<S62>/kp_tr'
        //   Gain: '<S67>/divide by delta T'

        APF_Path_Planning_2023a_DW.RED_Tz = 1.0 /
          APF_Path_Planning_2023a_P.baseRate *
          APF_Path_Planning_2023a_B.In1_g20asdtg *
          APF_Path_Planning_2023a_P.Kd_tr + APF_Path_Planning_2023a_P.Kp_tr *
          APF_Path_Planning_2023a_B.e_out_k;

        // Sum: '<S35>/Subtract' incorporates:
        //   Constant: '<S35>/Constant1'
        //   DataStoreRead: '<S35>/RED_Px'

        APF_Path_Planning_2023a_B.Subtract_j =
          APF_Path_Planning_2023a_P.init_states_RED[0] -
          APF_Path_Planning_2023a_DW.RED_Px;
        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          // Delay: '<S69>/Delay1'
          if (APF_Path_Planning_2023a_DW.icLoad_a) {
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_m =
              APF_Path_Planning_2023a_B.Subtract_j;
          }

          // Delay: '<S69>/Delay1'
          APF_Path_Planning_2023a_B.Delay1_nm =
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_m;
        }

        // Sum: '<S69>/Sum6'
        APF_Path_Planning_2023a_B.RED_Tz_RW =
          APF_Path_Planning_2023a_B.Subtract_j -
          APF_Path_Planning_2023a_B.Delay1_nm;

        // If: '<S69>/if we went through a "step"'
        APF_Path_Planning_2023a_B.rtAction = -1;
        if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
          if (APF_Path_Planning_2023a_B.RED_Tz_RW != 0.0) {
            APF_Path_Planning_2023a_B.rtAction = 0;
          }

          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_c =
            APF_Path_Planning_2023a_B.rtAction;
        } else {
          APF_Path_Planning_2023a_B.rtAction =
            APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_c;
        }

        if (APF_Path_Planning_2023a_B.rtAction == 0) {
          // Outputs for IfAction SubSystem: '<S69>/Hold this value' incorporates:
          //   ActionPort: '<S70>/Action Port'

          // SignalConversion generated from: '<S70>/In1'
          APF_Path_Planning_2023a_B.In1_g20asdt =
            APF_Path_Planning_2023a_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S69>/Hold this value'
        }

        // End of If: '<S69>/if we went through a "step"'

        // Sum: '<S63>/Sum3' incorporates:
        //   DataStoreWrite: '<S35>/RED_Fx'
        //   Gain: '<S63>/kd_xr'
        //   Gain: '<S63>/kp_xr'
        //   Gain: '<S69>/divide by delta T'

        APF_Path_Planning_2023a_DW.RED_Fx = 1.0 /
          APF_Path_Planning_2023a_P.baseRate *
          APF_Path_Planning_2023a_B.In1_g20asdt *
          APF_Path_Planning_2023a_P.Kd_xr + APF_Path_Planning_2023a_P.Kp_xr *
          APF_Path_Planning_2023a_B.Subtract_j;

        // Sum: '<S35>/Subtract1' incorporates:
        //   Constant: '<S35>/Constant3'
        //   DataStoreRead: '<S35>/RED_Py '

        APF_Path_Planning_2023a_B.Subtract1_n =
          APF_Path_Planning_2023a_P.init_states_RED[1] -
          APF_Path_Planning_2023a_DW.RED_Py;
        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          // Delay: '<S71>/Delay1'
          if (APF_Path_Planning_2023a_DW.icLoad_b) {
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_ej =
              APF_Path_Planning_2023a_B.Subtract1_n;
          }

          // Delay: '<S71>/Delay1'
          APF_Path_Planning_2023a_B.Delay1_ag =
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_ej;
        }

        // Sum: '<S71>/Sum6'
        APF_Path_Planning_2023a_B.RED_Tz_RW =
          APF_Path_Planning_2023a_B.Subtract1_n -
          APF_Path_Planning_2023a_B.Delay1_ag;

        // If: '<S71>/if we went through a "step"'
        APF_Path_Planning_2023a_B.rtAction = -1;
        if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
          if (APF_Path_Planning_2023a_B.RED_Tz_RW != 0.0) {
            APF_Path_Planning_2023a_B.rtAction = 0;
          }

          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_j =
            APF_Path_Planning_2023a_B.rtAction;
        } else {
          APF_Path_Planning_2023a_B.rtAction =
            APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_j;
        }

        if (APF_Path_Planning_2023a_B.rtAction == 0) {
          // Outputs for IfAction SubSystem: '<S71>/Hold this value' incorporates:
          //   ActionPort: '<S72>/Action Port'

          // SignalConversion generated from: '<S72>/In1'
          APF_Path_Planning_2023a_B.In1_g20asd =
            APF_Path_Planning_2023a_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S71>/Hold this value'
        }

        // End of If: '<S71>/if we went through a "step"'

        // Sum: '<S64>/Sum3' incorporates:
        //   DataStoreWrite: '<S35>/RED_Fy'
        //   Gain: '<S64>/kd_yr'
        //   Gain: '<S64>/kp_yr'
        //   Gain: '<S71>/divide by delta T'

        APF_Path_Planning_2023a_DW.RED_Fy = 1.0 /
          APF_Path_Planning_2023a_P.baseRate *
          APF_Path_Planning_2023a_B.In1_g20asd * APF_Path_Planning_2023a_P.Kd_yr
          + APF_Path_Planning_2023a_P.Kp_yr *
          APF_Path_Planning_2023a_B.Subtract1_n;
        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          // DataStoreWrite: '<S35>/Data Store Write3' incorporates:
          //   Constant: '<S35>/Puck State'

          APF_Path_Planning_2023a_DW.Float_State =
            APF_Path_Planning_2023a_P.PuckState_Value_h;

          // If: '<S35>/If' incorporates:
          //   Constant: '<S35>/Constant4'

          if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo) &&
              ((APF_Path_Planning_2023a_P.platformSelection == 4.0) ||
               (APF_Path_Planning_2023a_P.platformSelection == 5.0) ||
               (APF_Path_Planning_2023a_P.platformSelection == 10.0) ||
               (APF_Path_Planning_2023a_P.platformSelection == 11.0))) {
            // Outputs for IfAction SubSystem: '<S35>/RED+ARM' incorporates:
            //   ActionPort: '<S66>/Action Port'

            APF_Path_Planning_2023a_REDARM
              (&APF_Path_Planning_2023a_DW.RED_ARM_Control_Mode,
               &APF_Path_Planning_2023a_DW.RED_Elbow_Command,
               &APF_Path_Planning_2023a_DW.RED_Rz_Elbow,
               &APF_Path_Planning_2023a_DW.RED_Rz_Shoulder,
               &APF_Path_Planning_2023a_DW.RED_Rz_Wrist,
               &APF_Path_Planning_2023a_DW.RED_Shoulder_Command,
               &APF_Path_Planning_2023a_DW.RED_Wrist_Command,
               &APF_Path_Planning_2023a_DW.isSim,
               &APF_Path_Planning_2023a_B.REDARM_e,
               &APF_Path_Planning_2023a_DW.REDARM_e,
               &APF_Path_Planning_2023a_P.REDARM_e);

            // End of Outputs for SubSystem: '<S35>/RED+ARM'
          }

          // End of If: '<S35>/If'
        }

        // End of Outputs for SubSystem: '<S8>/Change RED Behavior'
      }

      // End of If: '<S8>/This IF block determines whether or not to run the RED sim//exp ' 
      // End of Outputs for SubSystem: '<Root>/Phase #2: Initial Position'
      break;

     case 3:
      // Outputs for IfAction SubSystem: '<Root>/Phase #3: Experiment' incorporates:
      //   ActionPort: '<S9>/Action Port'

      // If: '<S9>/This IF block determines whether or not to run the BLACK sim//exp' incorporates:
      //   DataStoreRead: '<S9>/Data Store Read'
      //   DataStoreRead: '<S9>/Data Store Read1'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if ((APF_Path_Planning_2023a_DW.WhoAmI == 2.0) ||
            (APF_Path_Planning_2023a_DW.isSim == 1.0)) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_n =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_n;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S9>/Change BLACK Behavior' incorporates:
        //   ActionPort: '<S87>/Action Port'

        // If: '<S87>/Experiment Sub-Phases' incorporates:
        //   Constant: '<S87>/Constant1'
        //   Constant: '<S87>/Constant2'
        //   Constant: '<S87>/Constant3'
        //   Constant: '<S87>/Constant4'
        //   DataStoreRead: '<S87>/Universal_Time'

        APF_Path_Planning_2023a_B.rtAction = -1;
        if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
          if (APF_Path_Planning_2023a_DW.Univ_Time <
              APF_Path_Planning_2023a_P.Phase3_SubPhase1_End) {
            APF_Path_Planning_2023a_B.rtAction = 0;
          } else if ((APF_Path_Planning_2023a_DW.Univ_Time <
                      APF_Path_Planning_2023a_P.Phase3_SubPhase2_End) &&
                     (APF_Path_Planning_2023a_DW.Univ_Time >=
                      APF_Path_Planning_2023a_P.Phase3_SubPhase1_End)) {
            APF_Path_Planning_2023a_B.rtAction = 1;
          } else if ((APF_Path_Planning_2023a_DW.Univ_Time <
                      APF_Path_Planning_2023a_P.Phase3_SubPhase3_End) &&
                     (APF_Path_Planning_2023a_DW.Univ_Time >=
                      APF_Path_Planning_2023a_P.Phase3_SubPhase2_End)) {
            APF_Path_Planning_2023a_B.rtAction = 2;
          } else if ((APF_Path_Planning_2023a_DW.Univ_Time <
                      APF_Path_Planning_2023a_P.Phase3_SubPhase4_End) &&
                     (APF_Path_Planning_2023a_DW.Univ_Time >=
                      APF_Path_Planning_2023a_P.Phase3_SubPhase3_End)) {
            APF_Path_Planning_2023a_B.rtAction = 3;
          }

          APF_Path_Planning_2023a_DW.ExperimentSubPhases_ActiveSub_l =
            APF_Path_Planning_2023a_B.rtAction;
        } else {
          APF_Path_Planning_2023a_B.rtAction =
            APF_Path_Planning_2023a_DW.ExperimentSubPhases_ActiveSub_l;
        }

        switch (APF_Path_Planning_2023a_B.rtAction) {
         case 0:
          // Outputs for IfAction SubSystem: '<S87>/Sub-Phase #1' incorporates:
          //   ActionPort: '<S90>/Action Port'

          APF_Path_Planning_202_SubPhase1(APF_Path_Planning_2023a_M,
            &APF_Path_Planning_2023a_DW.BLACK_Fx,
            &APF_Path_Planning_2023a_DW.BLACK_Fy,
            &APF_Path_Planning_2023a_DW.BLACK_Px,
            &APF_Path_Planning_2023a_DW.BLACK_Py,
            &APF_Path_Planning_2023a_DW.BLACK_Rz,
            &APF_Path_Planning_2023a_DW.BLACK_Tz,
            &APF_Path_Planning_2023a_DW.Float_State,
            &APF_Path_Planning_2023a_DW.Univ_Time,
            &APF_Path_Planning_2023a_B.SubPhase1,
            &APF_Path_Planning_2023a_DW.SubPhase1,
            &APF_Path_Planning_2023a_P.SubPhase1);

          // End of Outputs for SubSystem: '<S87>/Sub-Phase #1'
          break;

         case 1:
          // Outputs for IfAction SubSystem: '<S87>/Sub-Phase #2 ' incorporates:
          //   ActionPort: '<S91>/Action Port'

          APF_Path_Planning_202_SubPhase1(APF_Path_Planning_2023a_M,
            &APF_Path_Planning_2023a_DW.BLACK_Fx,
            &APF_Path_Planning_2023a_DW.BLACK_Fy,
            &APF_Path_Planning_2023a_DW.BLACK_Px,
            &APF_Path_Planning_2023a_DW.BLACK_Py,
            &APF_Path_Planning_2023a_DW.BLACK_Rz,
            &APF_Path_Planning_2023a_DW.BLACK_Tz,
            &APF_Path_Planning_2023a_DW.Float_State,
            &APF_Path_Planning_2023a_DW.Univ_Time,
            &APF_Path_Planning_2023a_B.SubPhase2,
            &APF_Path_Planning_2023a_DW.SubPhase2,
            &APF_Path_Planning_2023a_P.SubPhase2);

          // End of Outputs for SubSystem: '<S87>/Sub-Phase #2 '
          break;

         case 2:
          // Outputs for IfAction SubSystem: '<S87>/Sub-Phase #3 ' incorporates:
          //   ActionPort: '<S92>/Action Port'

          APF_Path_Planning_202_SubPhase1(APF_Path_Planning_2023a_M,
            &APF_Path_Planning_2023a_DW.BLACK_Fx,
            &APF_Path_Planning_2023a_DW.BLACK_Fy,
            &APF_Path_Planning_2023a_DW.BLACK_Px,
            &APF_Path_Planning_2023a_DW.BLACK_Py,
            &APF_Path_Planning_2023a_DW.BLACK_Rz,
            &APF_Path_Planning_2023a_DW.BLACK_Tz,
            &APF_Path_Planning_2023a_DW.Float_State,
            &APF_Path_Planning_2023a_DW.Univ_Time,
            &APF_Path_Planning_2023a_B.SubPhase3,
            &APF_Path_Planning_2023a_DW.SubPhase3,
            &APF_Path_Planning_2023a_P.SubPhase3);

          // End of Outputs for SubSystem: '<S87>/Sub-Phase #3 '
          break;

         case 3:
          // Outputs for IfAction SubSystem: '<S87>/Sub-Phase #4' incorporates:
          //   ActionPort: '<S93>/Action Port'

          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // DataStoreWrite: '<S93>/BLACK_Fx' incorporates:
            //   Constant: '<S93>/Constant'

            APF_Path_Planning_2023a_DW.BLACK_Fx =
              APF_Path_Planning_2023a_P.Constant_Value_m;

            // DataStoreWrite: '<S93>/BLACK_Fy' incorporates:
            //   Constant: '<S93>/Constant'

            APF_Path_Planning_2023a_DW.BLACK_Fy =
              APF_Path_Planning_2023a_P.Constant_Value_m;

            // DataStoreWrite: '<S93>/BLACK_Tz' incorporates:
            //   Constant: '<S93>/Constant'

            APF_Path_Planning_2023a_DW.BLACK_Tz =
              APF_Path_Planning_2023a_P.Constant_Value_m;

            // DataStoreWrite: '<S93>/Data Store Write3' incorporates:
            //   Constant: '<S93>/Puck State'

            APF_Path_Planning_2023a_DW.Float_State =
              APF_Path_Planning_2023a_P.PuckState_Value_c;

            // DiscreteIntegrator: '<S149>/Start Pos'
            APF_Path_Planning_2023a_B.StartPos_h =
              APF_Path_Planning_2023a_DW.StartPos_DSTATE_p;
          }

          // Step: '<S149>/End Time' incorporates:
          //   Step: '<S150>/End Time'
          //   Step: '<S151>/End Time'

          APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_M->Timing.t[0];
          if (APF_Path_Planning_2023a_B.t <
              APF_Path_Planning_2023a_P.end_time_black) {
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
              APF_Path_Planning_2023a_P.EndTime_Y0;
          } else {
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
              APF_Path_Planning_2023a_P.EndTime_YFinal;
          }

          // Switch: '<S149>/Switch' incorporates:
          //   Constant: '<S149>/End Pos'
          //   Step: '<S149>/End Time'

          if (APF_Path_Planning_2023a_B.rtb_path_b_idx_0 >
              APF_Path_Planning_2023a_P.Switch_Threshold) {
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
              APF_Path_Planning_2023a_B.StartPos_h;
          } else {
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
              APF_Path_Planning_2023a_P.BLACK_end[0];
          }

          // Sum: '<S93>/Subtract' incorporates:
          //   DataStoreRead: '<S93>/BLACK_Px'
          //   Switch: '<S149>/Switch'

          APF_Path_Planning_2023a_B.Subtract_k =
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 -
            APF_Path_Planning_2023a_DW.BLACK_Px;
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // Delay: '<S154>/Delay1'
            if (APF_Path_Planning_2023a_DW.icLoad_c) {
              APF_Path_Planning_2023a_DW.Delay1_DSTATE_p =
                APF_Path_Planning_2023a_B.Subtract_k;
            }

            // End of Delay: '<S154>/Delay1'

            // DiscreteIntegrator: '<S150>/Start Pos'
            APF_Path_Planning_2023a_B.StartPos_d =
              APF_Path_Planning_2023a_DW.StartPos_DSTATE_b;
          }

          // Step: '<S150>/End Time'
          if (APF_Path_Planning_2023a_B.t <
              APF_Path_Planning_2023a_P.end_time_black) {
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
              APF_Path_Planning_2023a_P.EndTime_Y0_f;
          } else {
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
              APF_Path_Planning_2023a_P.EndTime_YFinal_h;
          }

          // Switch: '<S150>/Switch' incorporates:
          //   Constant: '<S150>/End Pos'
          //   Step: '<S150>/End Time'

          if (APF_Path_Planning_2023a_B.rtb_path_b_idx_0 >
              APF_Path_Planning_2023a_P.Switch_Threshold_g) {
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
              APF_Path_Planning_2023a_B.StartPos_d;
          } else {
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
              APF_Path_Planning_2023a_P.BLACK_end[1];
          }

          // Sum: '<S93>/Subtract1' incorporates:
          //   DataStoreRead: '<S93>/BLACK_Py '
          //   Switch: '<S150>/Switch'

          APF_Path_Planning_2023a_B.Subtract1_l =
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 -
            APF_Path_Planning_2023a_DW.BLACK_Py;
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // Delay: '<S156>/Delay1'
            if (APF_Path_Planning_2023a_DW.icLoad_j) {
              APF_Path_Planning_2023a_DW.Delay1_DSTATE_n =
                APF_Path_Planning_2023a_B.Subtract1_l;
            }

            // End of Delay: '<S156>/Delay1'

            // DiscreteIntegrator: '<S151>/Start Pos'
            APF_Path_Planning_2023a_B.StartPos_e =
              APF_Path_Planning_2023a_DW.StartPos_DSTATE_l4;
          }

          // Step: '<S151>/End Time'
          if (APF_Path_Planning_2023a_B.t <
              APF_Path_Planning_2023a_P.end_time_black) {
            APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_P.EndTime_Y0_c;
          } else {
            APF_Path_Planning_2023a_B.t =
              APF_Path_Planning_2023a_P.EndTime_YFinal_c;
          }

          // Switch: '<S151>/Switch' incorporates:
          //   Constant: '<S151>/End Pos'
          //   Step: '<S151>/End Time'

          if (APF_Path_Planning_2023a_B.t >
              APF_Path_Planning_2023a_P.Switch_Threshold_o) {
            APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_B.StartPos_e;
          } else {
            APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_P.BLACK_end[2];
          }

          // MATLAB Function: '<S148>/MATLAB Function2' incorporates:
          //   Switch: '<S151>/Switch'

          APF_Path_Planni_MATLABFunction2(APF_Path_Planning_2023a_B.t,
            APF_Path_Planning_2023a_B.rtb_Oy_kp_n,
            APF_Path_Planning_2023a_B.rtb_Ox_pc_l);

          // MATLAB Function: '<S148>/MATLAB Function3' incorporates:
          //   DataStoreRead: '<S93>/BLACK_Rz'

          APF_Path_Planni_MATLABFunction3(APF_Path_Planning_2023a_DW.BLACK_Rz,
            APF_Path_Planning_2023a_B.rtb_Ox_pr_p);

          // Sum: '<S148>/Subtract2'
          APF_Path_Planning_2023a_B.rtb_Ox_pc_l[0] -=
            APF_Path_Planning_2023a_B.rtb_Ox_pr_p[0];
          APF_Path_Planning_2023a_B.rtb_Ox_pc_l[1] -=
            APF_Path_Planning_2023a_B.rtb_Ox_pr_p[1];

          // MATLAB Function: '<S148>/MATLAB Function4'
          APF_Path_Planni_MATLABFunction4(APF_Path_Planning_2023a_B.rtb_Oy_kp_n,
            APF_Path_Planning_2023a_B.rtb_Ox_pc_l,
            &APF_Path_Planning_2023a_B.e_out_b);
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // Delay: '<S152>/Delay1'
            if (APF_Path_Planning_2023a_DW.icLoad_fo) {
              APF_Path_Planning_2023a_DW.Delay1_DSTATE_p2 =
                APF_Path_Planning_2023a_B.e_out_b;
            }

            // End of Delay: '<S152>/Delay1'
          }

          // End of Outputs for SubSystem: '<S87>/Sub-Phase #4'
          break;
        }

        // End of If: '<S87>/Experiment Sub-Phases'
        // End of Outputs for SubSystem: '<S9>/Change BLACK Behavior'
      }

      // End of If: '<S9>/This IF block determines whether or not to run the BLACK sim//exp' 

      // If: '<S9>/This IF block determines whether or not to run the BLUE sim//exp' incorporates:
      //   DataStoreRead: '<S9>/Data Store Read'
      //   DataStoreRead: '<S9>/Data Store Read1'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if ((APF_Path_Planning_2023a_DW.WhoAmI == 3.0) ||
            (APF_Path_Planning_2023a_DW.isSim == 1.0)) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_al =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_al;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S9>/Change BLUE Behavior' incorporates:
        //   ActionPort: '<S88>/Action Port'

        // If: '<S88>/Experiment Sub-Phases' incorporates:
        //   Constant: '<S88>/Constant1'
        //   Constant: '<S88>/Constant2'
        //   Constant: '<S88>/Constant3'
        //   Constant: '<S88>/Constant4'
        //   DataStoreRead: '<S88>/Universal_Time'

        APF_Path_Planning_2023a_B.rtAction = -1;
        if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
          if (APF_Path_Planning_2023a_DW.Univ_Time <
              APF_Path_Planning_2023a_P.Phase3_SubPhase1_End) {
            APF_Path_Planning_2023a_B.rtAction = 0;
          } else if ((APF_Path_Planning_2023a_DW.Univ_Time <
                      APF_Path_Planning_2023a_P.Phase3_SubPhase2_End) &&
                     (APF_Path_Planning_2023a_DW.Univ_Time >=
                      APF_Path_Planning_2023a_P.Phase3_SubPhase1_End)) {
            APF_Path_Planning_2023a_B.rtAction = 1;
          } else if ((APF_Path_Planning_2023a_DW.Univ_Time <
                      APF_Path_Planning_2023a_P.Phase3_SubPhase3_End) &&
                     (APF_Path_Planning_2023a_DW.Univ_Time >=
                      APF_Path_Planning_2023a_P.Phase3_SubPhase2_End)) {
            APF_Path_Planning_2023a_B.rtAction = 2;
          } else if ((APF_Path_Planning_2023a_DW.Univ_Time <
                      APF_Path_Planning_2023a_P.Phase3_SubPhase4_End) &&
                     (APF_Path_Planning_2023a_DW.Univ_Time >=
                      APF_Path_Planning_2023a_P.Phase3_SubPhase3_End)) {
            APF_Path_Planning_2023a_B.rtAction = 3;
          }

          APF_Path_Planning_2023a_DW.ExperimentSubPhases_ActiveSub_c =
            APF_Path_Planning_2023a_B.rtAction;
        } else {
          APF_Path_Planning_2023a_B.rtAction =
            APF_Path_Planning_2023a_DW.ExperimentSubPhases_ActiveSub_c;
        }

        switch (APF_Path_Planning_2023a_B.rtAction) {
         case 0:
          // Outputs for IfAction SubSystem: '<S88>/Sub-Phase #1' incorporates:
          //   ActionPort: '<S161>/Action Port'

          APF_Path_Planning_2_SubPhase1_g(APF_Path_Planning_2023a_M,
            &APF_Path_Planning_2023a_DW.BLUE_Fx,
            &APF_Path_Planning_2023a_DW.BLUE_Fy,
            &APF_Path_Planning_2023a_DW.BLUE_Px,
            &APF_Path_Planning_2023a_DW.BLUE_Py,
            &APF_Path_Planning_2023a_DW.BLUE_Rz,
            &APF_Path_Planning_2023a_DW.BLUE_Tz,
            &APF_Path_Planning_2023a_DW.Float_State,
            &APF_Path_Planning_2023a_DW.Univ_Time,
            &APF_Path_Planning_2023a_B.SubPhase1_g,
            &APF_Path_Planning_2023a_DW.SubPhase1_g,
            &APF_Path_Planning_2023a_P.SubPhase1_g);

          // End of Outputs for SubSystem: '<S88>/Sub-Phase #1'
          break;

         case 1:
          // Outputs for IfAction SubSystem: '<S88>/Sub-Phase #2 ' incorporates:
          //   ActionPort: '<S162>/Action Port'

          APF_Path_Planning_2_SubPhase1_g(APF_Path_Planning_2023a_M,
            &APF_Path_Planning_2023a_DW.BLUE_Fx,
            &APF_Path_Planning_2023a_DW.BLUE_Fy,
            &APF_Path_Planning_2023a_DW.BLUE_Px,
            &APF_Path_Planning_2023a_DW.BLUE_Py,
            &APF_Path_Planning_2023a_DW.BLUE_Rz,
            &APF_Path_Planning_2023a_DW.BLUE_Tz,
            &APF_Path_Planning_2023a_DW.Float_State,
            &APF_Path_Planning_2023a_DW.Univ_Time,
            &APF_Path_Planning_2023a_B.SubPhase2_c,
            &APF_Path_Planning_2023a_DW.SubPhase2_c,
            &APF_Path_Planning_2023a_P.SubPhase2_c);

          // End of Outputs for SubSystem: '<S88>/Sub-Phase #2 '
          break;

         case 2:
          // Outputs for IfAction SubSystem: '<S88>/Sub-Phase #3 ' incorporates:
          //   ActionPort: '<S163>/Action Port'

          APF_Path_Planning_2_SubPhase1_g(APF_Path_Planning_2023a_M,
            &APF_Path_Planning_2023a_DW.BLUE_Fx,
            &APF_Path_Planning_2023a_DW.BLUE_Fy,
            &APF_Path_Planning_2023a_DW.BLUE_Px,
            &APF_Path_Planning_2023a_DW.BLUE_Py,
            &APF_Path_Planning_2023a_DW.BLUE_Rz,
            &APF_Path_Planning_2023a_DW.BLUE_Tz,
            &APF_Path_Planning_2023a_DW.Float_State,
            &APF_Path_Planning_2023a_DW.Univ_Time,
            &APF_Path_Planning_2023a_B.SubPhase3_e,
            &APF_Path_Planning_2023a_DW.SubPhase3_e,
            &APF_Path_Planning_2023a_P.SubPhase3_e);

          // End of Outputs for SubSystem: '<S88>/Sub-Phase #3 '
          break;

         case 3:
          // Outputs for IfAction SubSystem: '<S88>/Sub-Phase #4' incorporates:
          //   ActionPort: '<S164>/Action Port'

          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // DiscreteIntegrator: '<S232>/Start Pos'
            APF_Path_Planning_2023a_B.StartPos =
              APF_Path_Planning_2023a_DW.StartPos_DSTATE;
          }

          // Step: '<S232>/End Pos' incorporates:
          //   Step: '<S233>/End Pos'
          //   Step: '<S234>/End Pos'

          APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_M->Timing.t[0];
          if (APF_Path_Planning_2023a_B.t <
              APF_Path_Planning_2023a_P.end_time_blue) {
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
              APF_Path_Planning_2023a_P.EndPos_Y0;
          } else {
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
              APF_Path_Planning_2023a_P.EndPos_YFinal;
          }

          // Switch: '<S232>/Switch' incorporates:
          //   Constant: '<S232>/End Time'
          //   Step: '<S232>/End Pos'

          if (APF_Path_Planning_2023a_B.rtb_path_b_idx_0 >
              APF_Path_Planning_2023a_P.Switch_Threshold_k) {
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
              APF_Path_Planning_2023a_B.StartPos;
          } else {
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
              APF_Path_Planning_2023a_P.BLUE_end[0];
          }

          // Sum: '<S164>/Subtract' incorporates:
          //   DataStoreRead: '<S164>/BLUE_Px'
          //   Switch: '<S232>/Switch'

          APF_Path_Planning_2023a_B.Subtract_p =
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 -
            APF_Path_Planning_2023a_DW.BLUE_Px;
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // Delay: '<S237>/Delay1'
            if (APF_Path_Planning_2023a_DW.icLoad_d) {
              APF_Path_Planning_2023a_DW.Delay1_DSTATE_b =
                APF_Path_Planning_2023a_B.Subtract_p;
            }

            // Delay: '<S237>/Delay1'
            APF_Path_Planning_2023a_B.Delay1_n =
              APF_Path_Planning_2023a_DW.Delay1_DSTATE_b;
          }

          // Sum: '<S237>/Sum6'
          APF_Path_Planning_2023a_B.RED_Tz_RW =
            APF_Path_Planning_2023a_B.Subtract_p -
            APF_Path_Planning_2023a_B.Delay1_n;

          // If: '<S237>/if we went through a "step"'
          APF_Path_Planning_2023a_B.rtAction = -1;
          if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo))
          {
            if (APF_Path_Planning_2023a_B.RED_Tz_RW != 0.0) {
              APF_Path_Planning_2023a_B.rtAction = 0;
            }

            APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_p =
              APF_Path_Planning_2023a_B.rtAction;
          } else {
            APF_Path_Planning_2023a_B.rtAction =
              APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_p;
          }

          if (APF_Path_Planning_2023a_B.rtAction == 0) {
            // Outputs for IfAction SubSystem: '<S237>/Hold this value' incorporates:
            //   ActionPort: '<S238>/Action Port'

            // SignalConversion generated from: '<S238>/In1'
            APF_Path_Planning_2023a_B.In1_g20a =
              APF_Path_Planning_2023a_B.RED_Tz_RW;

            // End of Outputs for SubSystem: '<S237>/Hold this value'
          }

          // End of If: '<S237>/if we went through a "step"'

          // Sum: '<S229>/Sum3' incorporates:
          //   DataStoreWrite: '<S164>/BLUE_Fx'
          //   Gain: '<S229>/kd_xb'
          //   Gain: '<S229>/kp_xb'
          //   Gain: '<S237>/divide by delta T'

          APF_Path_Planning_2023a_DW.BLUE_Fx = 1.0 /
            APF_Path_Planning_2023a_P.baseRate *
            APF_Path_Planning_2023a_B.In1_g20a *
            APF_Path_Planning_2023a_P.Kd_xblue +
            APF_Path_Planning_2023a_P.Kp_xblue *
            APF_Path_Planning_2023a_B.Subtract_p;
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // DiscreteIntegrator: '<S233>/Start Pos'
            APF_Path_Planning_2023a_B.StartPos_o =
              APF_Path_Planning_2023a_DW.StartPos_DSTATE_j;
          }

          // Step: '<S233>/End Pos'
          if (APF_Path_Planning_2023a_B.t <
              APF_Path_Planning_2023a_P.end_time_blue) {
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
              APF_Path_Planning_2023a_P.EndPos_Y0_g;
          } else {
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
              APF_Path_Planning_2023a_P.EndPos_YFinal_d;
          }

          // Switch: '<S233>/Switch' incorporates:
          //   Constant: '<S233>/End Time'
          //   Step: '<S233>/End Pos'

          if (APF_Path_Planning_2023a_B.rtb_path_b_idx_0 >
              APF_Path_Planning_2023a_P.Switch_Threshold_n) {
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
              APF_Path_Planning_2023a_B.StartPos_o;
          } else {
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
              APF_Path_Planning_2023a_P.BLUE_end[1];
          }

          // Sum: '<S164>/Subtract1' incorporates:
          //   DataStoreRead: '<S164>/BLUE_Py '
          //   Switch: '<S233>/Switch'

          APF_Path_Planning_2023a_B.Subtract1 =
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 -
            APF_Path_Planning_2023a_DW.BLUE_Py;
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // Delay: '<S239>/Delay1'
            if (APF_Path_Planning_2023a_DW.icLoad_d4) {
              APF_Path_Planning_2023a_DW.Delay1_DSTATE_e =
                APF_Path_Planning_2023a_B.Subtract1;
            }

            // Delay: '<S239>/Delay1'
            APF_Path_Planning_2023a_B.Delay1_d =
              APF_Path_Planning_2023a_DW.Delay1_DSTATE_e;
          }

          // Sum: '<S239>/Sum6'
          APF_Path_Planning_2023a_B.RED_Tz_RW =
            APF_Path_Planning_2023a_B.Subtract1 -
            APF_Path_Planning_2023a_B.Delay1_d;

          // If: '<S239>/if we went through a "step"'
          APF_Path_Planning_2023a_B.rtAction = -1;
          if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo))
          {
            if (APF_Path_Planning_2023a_B.RED_Tz_RW != 0.0) {
              APF_Path_Planning_2023a_B.rtAction = 0;
            }

            APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_i =
              APF_Path_Planning_2023a_B.rtAction;
          } else {
            APF_Path_Planning_2023a_B.rtAction =
              APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_i;
          }

          if (APF_Path_Planning_2023a_B.rtAction == 0) {
            // Outputs for IfAction SubSystem: '<S239>/Hold this value' incorporates:
            //   ActionPort: '<S240>/Action Port'

            // SignalConversion generated from: '<S240>/In1'
            APF_Path_Planning_2023a_B.In1_g20 =
              APF_Path_Planning_2023a_B.RED_Tz_RW;

            // End of Outputs for SubSystem: '<S239>/Hold this value'
          }

          // End of If: '<S239>/if we went through a "step"'

          // Sum: '<S230>/Sum3' incorporates:
          //   DataStoreWrite: '<S164>/BLUE_Fy'
          //   Gain: '<S230>/kd_yb'
          //   Gain: '<S230>/kp_yb'
          //   Gain: '<S239>/divide by delta T'

          APF_Path_Planning_2023a_DW.BLUE_Fy = 1.0 /
            APF_Path_Planning_2023a_P.baseRate *
            APF_Path_Planning_2023a_B.In1_g20 *
            APF_Path_Planning_2023a_P.Kd_yblue +
            APF_Path_Planning_2023a_P.Kp_yblue *
            APF_Path_Planning_2023a_B.Subtract1;
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // DiscreteIntegrator: '<S234>/Start Pos'
            APF_Path_Planning_2023a_B.StartPos_l =
              APF_Path_Planning_2023a_DW.StartPos_DSTATE_l;
          }

          // Step: '<S234>/End Pos'
          if (APF_Path_Planning_2023a_B.t <
              APF_Path_Planning_2023a_P.end_time_blue) {
            APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_P.EndPos_Y0_k;
          } else {
            APF_Path_Planning_2023a_B.t =
              APF_Path_Planning_2023a_P.EndPos_YFinal_k;
          }

          // Switch: '<S234>/Switch' incorporates:
          //   Constant: '<S234>/End Time'
          //   Step: '<S234>/End Pos'

          if (APF_Path_Planning_2023a_B.t >
              APF_Path_Planning_2023a_P.Switch_Threshold_m) {
            APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_B.StartPos_l;
          } else {
            APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_P.BLUE_end[2];
          }

          // MATLAB Function: '<S231>/MATLAB Function2' incorporates:
          //   Switch: '<S234>/Switch'

          APF_Path_Planni_MATLABFunction2(APF_Path_Planning_2023a_B.t,
            APF_Path_Planning_2023a_B.rtb_Oy_kp_n,
            APF_Path_Planning_2023a_B.rtb_Ox_pc_l);

          // MATLAB Function: '<S231>/MATLAB Function3' incorporates:
          //   DataStoreRead: '<S164>/Data Store Read'

          APF_Path_Planni_MATLABFunction3(APF_Path_Planning_2023a_DW.BLUE_Rz,
            APF_Path_Planning_2023a_B.rtb_Ox_pr_p);

          // Sum: '<S231>/Subtract2'
          APF_Path_Planning_2023a_B.rtb_Ox_pc_l[0] -=
            APF_Path_Planning_2023a_B.rtb_Ox_pr_p[0];
          APF_Path_Planning_2023a_B.rtb_Ox_pc_l[1] -=
            APF_Path_Planning_2023a_B.rtb_Ox_pr_p[1];

          // MATLAB Function: '<S231>/MATLAB Function4'
          APF_Path_Planni_MATLABFunction4(APF_Path_Planning_2023a_B.rtb_Oy_kp_n,
            APF_Path_Planning_2023a_B.rtb_Ox_pc_l,
            &APF_Path_Planning_2023a_B.e_out_pv);
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // Delay: '<S235>/Delay1'
            if (APF_Path_Planning_2023a_DW.icLoad_l) {
              APF_Path_Planning_2023a_DW.Delay1_DSTATE_do =
                APF_Path_Planning_2023a_B.e_out_pv;
            }

            // Delay: '<S235>/Delay1'
            APF_Path_Planning_2023a_B.Delay1_f =
              APF_Path_Planning_2023a_DW.Delay1_DSTATE_do;
          }

          // Sum: '<S235>/Sum6'
          APF_Path_Planning_2023a_B.RED_Tz_RW =
            APF_Path_Planning_2023a_B.e_out_pv -
            APF_Path_Planning_2023a_B.Delay1_f;

          // If: '<S235>/if we went through a "step"'
          APF_Path_Planning_2023a_B.rtAction = -1;
          if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo))
          {
            if (APF_Path_Planning_2023a_B.RED_Tz_RW != 0.0) {
              APF_Path_Planning_2023a_B.rtAction = 0;
            }

            APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_k =
              APF_Path_Planning_2023a_B.rtAction;
          } else {
            APF_Path_Planning_2023a_B.rtAction =
              APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_k;
          }

          if (APF_Path_Planning_2023a_B.rtAction == 0) {
            // Outputs for IfAction SubSystem: '<S235>/Hold this value' incorporates:
            //   ActionPort: '<S236>/Action Port'

            // SignalConversion generated from: '<S236>/In1'
            APF_Path_Planning_2023a_B.In1_g20as =
              APF_Path_Planning_2023a_B.RED_Tz_RW;

            // End of Outputs for SubSystem: '<S235>/Hold this value'
          }

          // End of If: '<S235>/if we went through a "step"'

          // Sum: '<S228>/Sum3' incorporates:
          //   DataStoreWrite: '<S164>/BLUE_Tz'
          //   Gain: '<S228>/kd_tb'
          //   Gain: '<S228>/kp_tb'
          //   Gain: '<S235>/divide by delta T'

          APF_Path_Planning_2023a_DW.BLUE_Tz = 1.0 /
            APF_Path_Planning_2023a_P.baseRate *
            APF_Path_Planning_2023a_B.In1_g20as *
            APF_Path_Planning_2023a_P.Kd_tblue +
            APF_Path_Planning_2023a_P.Kp_tblue *
            APF_Path_Planning_2023a_B.e_out_pv;
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // DataStoreWrite: '<S164>/Data Store Write1' incorporates:
            //   Constant: '<S164>/Puck State'

            APF_Path_Planning_2023a_DW.Float_State =
              APF_Path_Planning_2023a_P.PuckState_Value_gh;
          }

          // End of Outputs for SubSystem: '<S88>/Sub-Phase #4'
          break;
        }

        // End of If: '<S88>/Experiment Sub-Phases'
        // End of Outputs for SubSystem: '<S9>/Change BLUE Behavior'
      }

      // End of If: '<S9>/This IF block determines whether or not to run the BLUE sim//exp' 

      // If: '<S9>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
      //   DataStoreRead: '<S9>/Data Store Read'
      //   DataStoreRead: '<S9>/Data Store Read1'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if ((APF_Path_Planning_2023a_DW.WhoAmI == 1.0) ||
            (APF_Path_Planning_2023a_DW.isSim == 1.0)) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_fg =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_fg;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S9>/Change RED Behavior' incorporates:
        //   ActionPort: '<S89>/Action Port'

        // If: '<S89>/Experiment Sub-Phases' incorporates:
        //   Constant: '<S89>/Constant1'
        //   Constant: '<S89>/Constant2'
        //   Constant: '<S89>/Constant3'
        //   Constant: '<S89>/Constant4'
        //   DataStoreRead: '<S89>/Universal_Time'

        APF_Path_Planning_2023a_B.rtAction = -1;
        if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
          if (APF_Path_Planning_2023a_DW.Univ_Time <
              APF_Path_Planning_2023a_P.Phase3_SubPhase1_End) {
            APF_Path_Planning_2023a_B.rtAction = 0;
          } else if ((APF_Path_Planning_2023a_DW.Univ_Time <
                      APF_Path_Planning_2023a_P.Phase3_SubPhase2_End) &&
                     (APF_Path_Planning_2023a_DW.Univ_Time >=
                      APF_Path_Planning_2023a_P.Phase3_SubPhase1_End)) {
            APF_Path_Planning_2023a_B.rtAction = 1;
          } else if ((APF_Path_Planning_2023a_DW.Univ_Time <
                      APF_Path_Planning_2023a_P.Phase3_SubPhase3_End) &&
                     (APF_Path_Planning_2023a_DW.Univ_Time >=
                      APF_Path_Planning_2023a_P.Phase3_SubPhase2_End)) {
            APF_Path_Planning_2023a_B.rtAction = 2;
          } else if ((APF_Path_Planning_2023a_DW.Univ_Time <
                      APF_Path_Planning_2023a_P.Phase3_SubPhase4_End) &&
                     (APF_Path_Planning_2023a_DW.Univ_Time >=
                      APF_Path_Planning_2023a_P.Phase3_SubPhase3_End)) {
            APF_Path_Planning_2023a_B.rtAction = 3;
          }

          APF_Path_Planning_2023a_DW.ExperimentSubPhases_ActiveSubsy =
            APF_Path_Planning_2023a_B.rtAction;
        } else {
          APF_Path_Planning_2023a_B.rtAction =
            APF_Path_Planning_2023a_DW.ExperimentSubPhases_ActiveSubsy;
        }

        switch (APF_Path_Planning_2023a_B.rtAction) {
         case 0:
          // Outputs for IfAction SubSystem: '<S89>/Sub-Phase #1' incorporates:
          //   ActionPort: '<S244>/Action Port'

          APF_Path_Planning_2_SubPhase1_p(APF_Path_Planning_2023a_M,
            &APF_Path_Planning_2023a_DW.Float_State,
            &APF_Path_Planning_2023a_DW.RED_ARM_Control_Mode,
            &APF_Path_Planning_2023a_DW.RED_Elbow_Command,
            &APF_Path_Planning_2023a_DW.RED_Fx,
            &APF_Path_Planning_2023a_DW.RED_Fy,
            &APF_Path_Planning_2023a_DW.RED_Px,
            &APF_Path_Planning_2023a_DW.RED_Py,
            &APF_Path_Planning_2023a_DW.RED_Rz,
            &APF_Path_Planning_2023a_DW.RED_Rz_Elbow,
            &APF_Path_Planning_2023a_DW.RED_Rz_Shoulder,
            &APF_Path_Planning_2023a_DW.RED_Rz_Wrist,
            &APF_Path_Planning_2023a_DW.RED_Shoulder_Command,
            &APF_Path_Planning_2023a_DW.RED_Tz,
            &APF_Path_Planning_2023a_B.RED_Tz_RW,
            &APF_Path_Planning_2023a_DW.RED_Wrist_Command,
            &APF_Path_Planning_2023a_DW.Univ_Time,
            &APF_Path_Planning_2023a_DW.isSim,
            &APF_Path_Planning_2023a_B.SubPhase1_p,
            &APF_Path_Planning_2023a_DW.SubPhase1_p,
            &APF_Path_Planning_2023a_P.SubPhase1_p);

          // End of Outputs for SubSystem: '<S89>/Sub-Phase #1'
          break;

         case 1:
          // Outputs for IfAction SubSystem: '<S89>/Sub-Phase #2 ' incorporates:
          //   ActionPort: '<S245>/Action Port'

          APF_Path_Planning_2_SubPhase1_p(APF_Path_Planning_2023a_M,
            &APF_Path_Planning_2023a_DW.Float_State,
            &APF_Path_Planning_2023a_DW.RED_ARM_Control_Mode,
            &APF_Path_Planning_2023a_DW.RED_Elbow_Command,
            &APF_Path_Planning_2023a_DW.RED_Fx,
            &APF_Path_Planning_2023a_DW.RED_Fy,
            &APF_Path_Planning_2023a_DW.RED_Px,
            &APF_Path_Planning_2023a_DW.RED_Py,
            &APF_Path_Planning_2023a_DW.RED_Rz,
            &APF_Path_Planning_2023a_DW.RED_Rz_Elbow,
            &APF_Path_Planning_2023a_DW.RED_Rz_Shoulder,
            &APF_Path_Planning_2023a_DW.RED_Rz_Wrist,
            &APF_Path_Planning_2023a_DW.RED_Shoulder_Command,
            &APF_Path_Planning_2023a_DW.RED_Tz,
            &APF_Path_Planning_2023a_B.RED_Tz_RW,
            &APF_Path_Planning_2023a_DW.RED_Wrist_Command,
            &APF_Path_Planning_2023a_DW.Univ_Time,
            &APF_Path_Planning_2023a_DW.isSim,
            &APF_Path_Planning_2023a_B.SubPhase2_p,
            &APF_Path_Planning_2023a_DW.SubPhase2_p,
            &APF_Path_Planning_2023a_P.SubPhase2_p);

          // End of Outputs for SubSystem: '<S89>/Sub-Phase #2 '
          break;

         case 2:
          // Outputs for IfAction SubSystem: '<S89>/Sub-Phase #3 ' incorporates:
          //   ActionPort: '<S246>/Action Port'

          // MATLAB Function: '<S344>/MATLAB Function' incorporates:
          //   Constant: '<S321>/Constant'
          //   Constant: '<S321>/Desired Rate '
          //   Constant: '<S343>/Constant1'
          //   DataStoreRead: '<S343>/Universal_Time'
          //   Product: '<S321>/Product'
          //   Sum: '<S321>/Sum'
          //   Sum: '<S343>/Subtract'

          APF_Path_Plannin_MATLABFunction
            (APF_Path_Planning_2023a_P.DesiredRate_Value *
             (APF_Path_Planning_2023a_DW.Univ_Time -
              APF_Path_Planning_2023a_P.Phase2_End) +
             APF_Path_Planning_2023a_P.Constant_Value_n,
             &APF_Path_Planning_2023a_B.rtb_y_g);

          // MATLAB Function: '<S317>/MATLAB Function2'
          APF_Path_Planni_MATLABFunction2(APF_Path_Planning_2023a_B.rtb_y_g,
            APF_Path_Planning_2023a_B.rtb_Oy_kp_n,
            APF_Path_Planning_2023a_B.rtb_Ox_pc_l);

          // MATLAB Function: '<S317>/MATLAB Function3' incorporates:
          //   DataStoreRead: '<S246>/RED_Rz'

          APF_Path_Planni_MATLABFunction3(APF_Path_Planning_2023a_DW.RED_Rz,
            APF_Path_Planning_2023a_B.rtb_Ox_pr_p);

          // Sum: '<S317>/Subtract2'
          APF_Path_Planning_2023a_B.rtb_Ox_pc_l[0] -=
            APF_Path_Planning_2023a_B.rtb_Ox_pr_p[0];
          APF_Path_Planning_2023a_B.rtb_Ox_pc_l[1] -=
            APF_Path_Planning_2023a_B.rtb_Ox_pr_p[1];

          // MATLAB Function: '<S317>/MATLAB Function4'
          APF_Path_Planni_MATLABFunction4(APF_Path_Planning_2023a_B.rtb_Oy_kp_n,
            APF_Path_Planning_2023a_B.rtb_Ox_pc_l,
            &APF_Path_Planning_2023a_B.e_out_p);
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // Delay: '<S323>/Delay1'
            if (APF_Path_Planning_2023a_DW.icLoad) {
              APF_Path_Planning_2023a_DW.Delay1_DSTATE_da =
                APF_Path_Planning_2023a_B.e_out_p;
            }

            // Delay: '<S323>/Delay1'
            APF_Path_Planning_2023a_B.Delay1_e =
              APF_Path_Planning_2023a_DW.Delay1_DSTATE_da;
          }

          // Sum: '<S323>/Sum6'
          APF_Path_Planning_2023a_B.RED_Tz_RW =
            APF_Path_Planning_2023a_B.e_out_p -
            APF_Path_Planning_2023a_B.Delay1_e;

          // If: '<S323>/if we went through a "step"'
          APF_Path_Planning_2023a_B.rtAction = -1;
          if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo))
          {
            if (APF_Path_Planning_2023a_B.RED_Tz_RW != 0.0) {
              APF_Path_Planning_2023a_B.rtAction = 0;
            }

            APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSubs =
              APF_Path_Planning_2023a_B.rtAction;
          } else {
            APF_Path_Planning_2023a_B.rtAction =
              APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSubs;
          }

          if (APF_Path_Planning_2023a_B.rtAction == 0) {
            // Outputs for IfAction SubSystem: '<S323>/Hold this value' incorporates:
            //   ActionPort: '<S324>/Action Port'

            // SignalConversion generated from: '<S324>/In1'
            APF_Path_Planning_2023a_B.In1_g2 =
              APF_Path_Planning_2023a_B.RED_Tz_RW;

            // End of Outputs for SubSystem: '<S323>/Hold this value'
          }

          // End of If: '<S323>/if we went through a "step"'

          // Sum: '<S314>/Sum3' incorporates:
          //   DataStoreWrite: '<S246>/RED_Tz'
          //   Gain: '<S314>/kd_tr'
          //   Gain: '<S314>/kp_tr'
          //   Gain: '<S323>/divide by delta T'

          APF_Path_Planning_2023a_DW.RED_Tz = 1.0 /
            APF_Path_Planning_2023a_P.baseRate *
            APF_Path_Planning_2023a_B.In1_g2 * APF_Path_Planning_2023a_P.Kd_tr +
            APF_Path_Planning_2023a_P.Kp_tr * APF_Path_Planning_2023a_B.e_out_p;

          // Sum: '<S322>/Subtract3' incorporates:
          //   Constant: '<S322>/Constant2'
          //   DataStoreRead: '<S346>/Universal_Time'

          APF_Path_Planning_2023a_B.RED_Tz_RW =
            APF_Path_Planning_2023a_DW.Univ_Time -
            APF_Path_Planning_2023a_P.Phase2_End;

          // MATLAB Function: '<S246>/MATLAB Function'
          APF_Path_Plann_MATLABFunction_o(APF_Path_Planning_2023a_B.RED_Tz_RW,
            &APF_Path_Planning_2023a_B.rtb_y_g);

          // Sum: '<S246>/Subtract' incorporates:
          //   DataStoreRead: '<S246>/RED_Px1'

          APF_Path_Planning_2023a_B.Subtract = APF_Path_Planning_2023a_B.rtb_y_g
            - APF_Path_Planning_2023a_DW.RED_Px;
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // Delay: '<S325>/Delay1'
            if (APF_Path_Planning_2023a_DW.icLoad_f) {
              APF_Path_Planning_2023a_DW.Delay1_DSTATE_d3 =
                APF_Path_Planning_2023a_B.Subtract;
            }

            // Delay: '<S325>/Delay1'
            APF_Path_Planning_2023a_B.Delay1_l =
              APF_Path_Planning_2023a_DW.Delay1_DSTATE_d3;
          }

          // Sum: '<S325>/Sum6'
          APF_Path_Planning_2023a_B.rtb_y_g = APF_Path_Planning_2023a_B.Subtract
            - APF_Path_Planning_2023a_B.Delay1_l;

          // If: '<S325>/if we went through a "step"'
          APF_Path_Planning_2023a_B.rtAction = -1;
          if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo))
          {
            if (APF_Path_Planning_2023a_B.rtb_y_g != 0.0) {
              APF_Path_Planning_2023a_B.rtAction = 0;
            }

            APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_h =
              APF_Path_Planning_2023a_B.rtAction;
          } else {
            APF_Path_Planning_2023a_B.rtAction =
              APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_h;
          }

          if (APF_Path_Planning_2023a_B.rtAction == 0) {
            // Outputs for IfAction SubSystem: '<S325>/Hold this value' incorporates:
            //   ActionPort: '<S326>/Action Port'

            // SignalConversion generated from: '<S326>/In1'
            APF_Path_Planning_2023a_B.In1_g = APF_Path_Planning_2023a_B.rtb_y_g;

            // End of Outputs for SubSystem: '<S325>/Hold this value'
          }

          // End of If: '<S325>/if we went through a "step"'

          // Sum: '<S315>/Sum3' incorporates:
          //   DataStoreWrite: '<S246>/RED_Fx'
          //   Gain: '<S315>/kd_xr'
          //   Gain: '<S315>/kp_xr'
          //   Gain: '<S325>/divide by delta T'

          APF_Path_Planning_2023a_DW.RED_Fx = 1.0 /
            APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_g
            * APF_Path_Planning_2023a_P.Kd_xr + APF_Path_Planning_2023a_P.Kp_xr *
            APF_Path_Planning_2023a_B.Subtract;

          // MATLAB Function: '<S246>/MATLAB Function1'
          APF_Path_Planni_MATLABFunction1(APF_Path_Planning_2023a_B.RED_Tz_RW,
            &APF_Path_Planning_2023a_B.rtb_y_g);

          // Sum: '<S246>/Subtract2' incorporates:
          //   DataStoreRead: '<S246>/RED_Py '

          APF_Path_Planning_2023a_B.Subtract2 =
            APF_Path_Planning_2023a_B.rtb_y_g -
            APF_Path_Planning_2023a_DW.RED_Py;
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // Delay: '<S327>/Delay1'
            if (APF_Path_Planning_2023a_DW.icLoad_i) {
              APF_Path_Planning_2023a_DW.Delay1_DSTATE_g =
                APF_Path_Planning_2023a_B.Subtract2;
            }

            // Delay: '<S327>/Delay1'
            APF_Path_Planning_2023a_B.Delay1_a =
              APF_Path_Planning_2023a_DW.Delay1_DSTATE_g;
          }

          // Sum: '<S327>/Sum6'
          APF_Path_Planning_2023a_B.RED_Tz_RW =
            APF_Path_Planning_2023a_B.Subtract2 -
            APF_Path_Planning_2023a_B.Delay1_a;

          // If: '<S327>/if we went through a "step"'
          APF_Path_Planning_2023a_B.rtAction = -1;
          if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo))
          {
            if (APF_Path_Planning_2023a_B.RED_Tz_RW != 0.0) {
              APF_Path_Planning_2023a_B.rtAction = 0;
            }

            APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_l =
              APF_Path_Planning_2023a_B.rtAction;
          } else {
            APF_Path_Planning_2023a_B.rtAction =
              APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_l;
          }

          if (APF_Path_Planning_2023a_B.rtAction == 0) {
            // Outputs for IfAction SubSystem: '<S327>/Hold this value' incorporates:
            //   ActionPort: '<S328>/Action Port'

            // SignalConversion generated from: '<S328>/In1'
            APF_Path_Planning_2023a_B.In1 = APF_Path_Planning_2023a_B.RED_Tz_RW;

            // End of Outputs for SubSystem: '<S327>/Hold this value'
          }

          // End of If: '<S327>/if we went through a "step"'

          // Sum: '<S316>/Sum3' incorporates:
          //   DataStoreWrite: '<S246>/RED_Fy'
          //   Gain: '<S316>/kd_yr'
          //   Gain: '<S316>/kp_yr'
          //   Gain: '<S327>/divide by delta T'

          APF_Path_Planning_2023a_DW.RED_Fy = 1.0 /
            APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1 *
            APF_Path_Planning_2023a_P.Kd_yr + APF_Path_Planning_2023a_P.Kp_yr *
            APF_Path_Planning_2023a_B.Subtract2;
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // DataStoreWrite: '<S246>/Data Store Write3' incorporates:
            //   Constant: '<S246>/Puck State'

            APF_Path_Planning_2023a_DW.Float_State =
              APF_Path_Planning_2023a_P.PuckState_Value_gv;

            // If: '<S246>/If' incorporates:
            //   Constant: '<S246>/Constant1'

            if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)
                && ((APF_Path_Planning_2023a_P.platformSelection == 4.0) ||
                    (APF_Path_Planning_2023a_P.platformSelection == 5.0) ||
                    (APF_Path_Planning_2023a_P.platformSelection == 10.0) ||
                    (APF_Path_Planning_2023a_P.platformSelection == 11.0))) {
              // Outputs for IfAction SubSystem: '<S246>/RED+ARM' incorporates:
              //   ActionPort: '<S320>/Action Port'

              APF_Path_Planning_2023a_REDARM
                (&APF_Path_Planning_2023a_DW.RED_ARM_Control_Mode,
                 &APF_Path_Planning_2023a_DW.RED_Elbow_Command,
                 &APF_Path_Planning_2023a_DW.RED_Rz_Elbow,
                 &APF_Path_Planning_2023a_DW.RED_Rz_Shoulder,
                 &APF_Path_Planning_2023a_DW.RED_Rz_Wrist,
                 &APF_Path_Planning_2023a_DW.RED_Shoulder_Command,
                 &APF_Path_Planning_2023a_DW.RED_Wrist_Command,
                 &APF_Path_Planning_2023a_DW.isSim,
                 &APF_Path_Planning_2023a_B.REDARM_m,
                 &APF_Path_Planning_2023a_DW.REDARM_m,
                 &APF_Path_Planning_2023a_P.REDARM_m);

              // End of Outputs for SubSystem: '<S246>/RED+ARM'
            }

            // End of If: '<S246>/If'
          }

          // End of Outputs for SubSystem: '<S89>/Sub-Phase #3 '
          break;

         case 3:
          // Outputs for IfAction SubSystem: '<S89>/Sub-Phase #4' incorporates:
          //   ActionPort: '<S247>/Action Port'

          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // If: '<S350>/If2' incorporates:
            //   Constant: '<S369>/Constant'

            APF_Path_Planning_2023a_B.rtAction = -1;
            if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo))
            {
              if (APF_Path_Planning_2023a_P.Constant_Value_a == 1.0) {
                APF_Path_Planning_2023a_B.rtAction = 0;
              }

              APF_Path_Planning_2023a_DW.If2_ActiveSubsystem =
                APF_Path_Planning_2023a_B.rtAction;
            } else {
              APF_Path_Planning_2023a_B.rtAction =
                APF_Path_Planning_2023a_DW.If2_ActiveSubsystem;
            }

            if (APF_Path_Planning_2023a_B.rtAction == 0) {
              // Outputs for IfAction SubSystem: '<S350>/Target Finder' incorporates:
              //   ActionPort: '<S370>/Action Port'

              // MATLAB Function: '<S396>/MATLAB Function' incorporates:
              //   Constant: '<S393>/Desired Rate (RED)'
              //   Constant: '<S395>/Constant1'
              //   DataStoreRead: '<S395>/Universal_Time'
              //   Product: '<S393>/Product'
              //   Sum: '<S395>/Subtract'

              APF_Path_Plannin_MATLABFunction(APF_Path_Planning_2023a_P.Red_Rate
                * (APF_Path_Planning_2023a_DW.Univ_Time -
                   APF_Path_Planning_2023a_P.Phase3_SubPhase3_End),
                &APF_Path_Planning_2023a_B.RED_Tz_RW);

              // SignalConversion generated from: '<S370>/Desired States' incorporates:
              //   Constant: '<S393>/Constant'
              //   Constant: '<S394>/Constant1'
              //   Constant: '<S394>/Constant2'
              //   Sum: '<S393>/Sum'

              APF_Path_Planning_2023a_B.OutportBufferForDesiredStates[0] =
                APF_Path_Planning_2023a_P.init_states_RED[0];
              APF_Path_Planning_2023a_B.OutportBufferForDesiredStates[1] =
                APF_Path_Planning_2023a_P.init_states_RED[1];
              APF_Path_Planning_2023a_B.OutportBufferForDesiredStates[2] =
                APF_Path_Planning_2023a_B.RED_Tz_RW +
                APF_Path_Planning_2023a_P.init_states_RED[2];

              // End of Outputs for SubSystem: '<S350>/Target Finder'
            }

            // End of If: '<S350>/If2'
          }

          // DataStoreRead: '<S347>/Data Store Read3'
          APF_Path_Planning_2023a_B.DataStoreRead3 =
            APF_Path_Planning_2023a_DW.BLACK_RzD;

          // DataStoreRead: '<S347>/Data Store Read2'
          APF_Path_Planning_2023a_B.DataStoreRead2 =
            APF_Path_Planning_2023a_DW.BLACK_Vy;

          // DataStoreRead: '<S347>/Data Store Read'
          APF_Path_Planning_2023a_B.DataStoreRead_n =
            APF_Path_Planning_2023a_DW.BLACK_Vx;

          // DataStoreRead: '<S347>/Data Store Read4'
          APF_Path_Planning_2023a_B.DataStoreRead4 =
            APF_Path_Planning_2023a_DW.BLACK_Rz;

          // DataStoreRead: '<S347>/Data Store Read5'
          APF_Path_Planning_2023a_B.DataStoreRead5 =
            APF_Path_Planning_2023a_DW.BLACK_Py;

          // DataStoreRead: '<S347>/Data Store Read6'
          APF_Path_Planning_2023a_B.DataStoreRead6 =
            APF_Path_Planning_2023a_DW.BLACK_Px;

          // DataStoreRead: '<S351>/Data Store Read6'
          APF_Path_Planning_2023a_B.DataStoreRead6_c =
            APF_Path_Planning_2023a_DW.RED_RzD;

          // DataStoreRead: '<S351>/Data Store Read5'
          APF_Path_Planning_2023a_B.DataStoreRead5_b =
            APF_Path_Planning_2023a_DW.RED_Vy;

          // DataStoreRead: '<S351>/Data Store Read4'
          APF_Path_Planning_2023a_B.DataStoreRead4_k =
            APF_Path_Planning_2023a_DW.RED_Vx;

          // DataStoreRead: '<S351>/Data Store Read3'
          APF_Path_Planning_2023a_B.DataStoreRead3_l =
            APF_Path_Planning_2023a_DW.RED_Rz;

          // DataStoreRead: '<S351>/Data Store Read2'
          APF_Path_Planning_2023a_B.DataStoreRead2_j =
            APF_Path_Planning_2023a_DW.RED_Py;

          // DataStoreRead: '<S351>/Data Store Read'
          APF_Path_Planning_2023a_B.DataStoreRead_k =
            APF_Path_Planning_2023a_DW.RED_Px;
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // If: '<S350>/If1' incorporates:
            //   Constant: '<S369>/Constant'

            APF_Path_Planning_2023a_B.rtAction = -1;
            if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo))
            {
              if (APF_Path_Planning_2023a_P.Constant_Value_a == 2.0) {
                APF_Path_Planning_2023a_B.rtAction = 0;
              }

              APF_Path_Planning_2023a_DW.If1_ActiveSubsystem =
                APF_Path_Planning_2023a_B.rtAction;
            } else {
              APF_Path_Planning_2023a_B.rtAction =
                APF_Path_Planning_2023a_DW.If1_ActiveSubsystem;
            }

            if (APF_Path_Planning_2023a_B.rtAction == 0) {
              // Outputs for IfAction SubSystem: '<S350>/Target Tracker' incorporates:
              //   ActionPort: '<S371>/Action Port'

              // MATLAB Function: '<S398>/Looking Angle' incorporates:
              //   SignalConversion generated from: '<S400>/ SFunction '

              APF_Path_Planning_2023a_B.rtb_Oy_kp_n[0] =
                APF_Path_Planning_2023a_B.DataStoreRead_k -
                (APF_Path_Planning_2023a_P.r_off * cos
                 (APF_Path_Planning_2023a_B.DataStoreRead4) +
                 APF_Path_Planning_2023a_B.DataStoreRead6);
              APF_Path_Planning_2023a_B.rtb_Oy_kp_n[1] =
                APF_Path_Planning_2023a_B.DataStoreRead2_j -
                (APF_Path_Planning_2023a_P.r_off * sin
                 (APF_Path_Planning_2023a_B.DataStoreRead4) +
                 APF_Path_Planning_2023a_B.DataStoreRead5);

              // SignalConversion generated from: '<S371>/Desired States' incorporates:
              //   Constant: '<S399>/Constant1'
              //   Constant: '<S399>/Constant2'
              //   DiscreteTransferFcn: '<S371>/Discrete Transfer Fcn1'

              APF_Path_Planning_2023a_B.OutportBufferForDesiredStates_c[0] =
                APF_Path_Planning_2023a_P.init_states_RED[0];
              APF_Path_Planning_2023a_B.OutportBufferForDesiredStates_c[1] =
                APF_Path_Planning_2023a_P.init_states_RED[1];
              APF_Path_Planning_2023a_B.OutportBufferForDesiredStates_c[2] =
                APF_Path_Planning_2023a_P.DiscreteTransferFcn1_NumCoef *
                APF_Path_Planning_2023a_DW.DiscreteTransferFcn1_states;

              // Update for DiscreteTransferFcn: '<S371>/Discrete Transfer Fcn1' incorporates:
              //   MATLAB Function: '<S398>/Looking Angle'

              APF_Path_Planning_2023a_DW.DiscreteTransferFcn1_states =
                ((APF_Path_Planning_rt_atan2d_snf
                  (APF_Path_Planning_2023a_B.rtb_Oy_kp_n[1],
                   APF_Path_Planning_2023a_B.rtb_Oy_kp_n[0]) +
                  3.1415926535897931) -
                 APF_Path_Planning_2023a_P.DiscreteTransferFcn1_DenCoef[1] *
                 APF_Path_Planning_2023a_DW.DiscreteTransferFcn1_states) /
                APF_Path_Planning_2023a_P.DiscreteTransferFcn1_DenCoef[0];

              // End of Outputs for SubSystem: '<S350>/Target Tracker'
            }

            // End of If: '<S350>/If1'
          }

          // If: '<S350>/If' incorporates:
          //   Constant: '<S369>/Constant'
          //   Delay: '<S377>/Delay3'
          //   Delay: '<S379>/Delay1'
          //   Delay: '<S383>/Delay3'
          //   MATLAB Function: '<S372>/MATLAB Function'
          //   MATLAB Function: '<S376>/MATLAB Function1'
          //   MATLAB Function: '<S377>/MATLAB Function1'
          //   MATLAB Function: '<S379>/MATLAB Function1'
          //   MATLAB Function: '<S382>/MATLAB Function1'
          //   MATLAB Function: '<S383>/MATLAB Function1'

          APF_Path_Planning_2023a_B.rtAction = -1;
          if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo))
          {
            if (APF_Path_Planning_2023a_P.Constant_Value_a == 3.0) {
              APF_Path_Planning_2023a_B.rtAction = 0;
            }

            APF_Path_Planning_2023a_DW.If_ActiveSubsystem =
              APF_Path_Planning_2023a_B.rtAction;
          } else {
            APF_Path_Planning_2023a_B.rtAction =
              APF_Path_Planning_2023a_DW.If_ActiveSubsystem;
          }

          if (APF_Path_Planning_2023a_B.rtAction == 0) {
            // Outputs for IfAction SubSystem: '<S350>/APF' incorporates:
            //   ActionPort: '<S368>/Action Port'

            // SignalConversion generated from: '<S374>/ SFunction ' incorporates:
            //   MATLAB Function: '<S368>/Looking Angle'
            //   MATLAB Function: '<S372>/MATLAB Function'
            //   MATLAB Function: '<S380>/Batch'
            //   MATLAB Function: '<S381>/Momentum'
            //   MATLAB Function: '<S382>/MATLAB Function1'
            //   SignalConversion generated from: '<S373>/ SFunction '
            //   SignalConversion generated from: '<S388>/ SFunction '
            //   SignalConversion generated from: '<S389>/ SFunction '
            //   SignalConversion generated from: '<S390>/ SFunction '

            APF_Path_Planning_2023a_B.TmpSignalConversionAtSFunct[0] =
              APF_Path_Planning_2023a_B.DataStoreRead_k;
            APF_Path_Planning_2023a_B.TmpSignalConversionAtSFunct[1] =
              APF_Path_Planning_2023a_B.DataStoreRead2_j;
            APF_Path_Planning_2023a_B.TmpSignalConversionAtSFunct[2] =
              APF_Path_Planning_2023a_B.DataStoreRead3_l;
            APF_Path_Planning_2023a_B.TmpSignalConversionAtSFunct[3] =
              APF_Path_Planning_2023a_B.DataStoreRead4_k;
            APF_Path_Planning_2023a_B.TmpSignalConversionAtSFunct[4] =
              APF_Path_Planning_2023a_B.DataStoreRead5_b;
            APF_Path_Planning_2023a_B.TmpSignalConversionAtSFunct[5] =
              APF_Path_Planning_2023a_B.DataStoreRead6_c;

            // MATLAB Function: '<S372>/MATLAB Function' incorporates:
            //   DataStoreRead: '<S348>/Data Store Read'
            //   DataStoreRead: '<S348>/Data Store Read2'
            //   DataStoreRead: '<S348>/Data Store Read3'
            //   MATLAB Function: '<S382>/MATLAB Function1'
            //   SignalConversion generated from: '<S374>/ SFunction '

            APF_Path_Planning_2023a_B.r_ct[0] =
              APF_Path_Planning_2023a_B.DataStoreRead_k -
              APF_Path_Planning_2023a_B.DataStoreRead6;
            APF_Path_Planning_2023a_B.r_ct[1] =
              APF_Path_Planning_2023a_B.DataStoreRead2_j -
              APF_Path_Planning_2023a_B.DataStoreRead5;
            APF_Path_Planning_2023a_B.rtb_y_g =
              APF_Path_Planning_2023a_B.DataStoreRead4 -
              APF_Path_Planning_2023a_B.DataStoreRead4;
            APF_Path_Planning_2023a_B.r_co[0] =
              APF_Path_Planning_2023a_B.DataStoreRead_k -
              APF_Path_Planning_2023a_DW.BLUE_Px;
            APF_Path_Planning_2023a_B.r_co[1] =
              APF_Path_Planning_2023a_B.DataStoreRead2_j -
              APF_Path_Planning_2023a_DW.BLUE_Py;
            APF_Path_Planning_2023a_B.r_co[2] =
              APF_Path_Planning_2023a_DW.BLUE_Rz -
              APF_Path_Planning_2023a_DW.BLUE_Rz;
            APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp = sin
              (APF_Path_Planning_2023a_B.DataStoreRead4);
            APF_Path_Planning_2023a_B.rtb_path_o_idx_0 = cos
              (APF_Path_Planning_2023a_B.DataStoreRead4);
            APF_Path_Planning_2023a_B.RED_Tz_RW =
              (APF_Path_Planning_rt_atan2d_snf
               (APF_Path_Planning_2023a_B.DataStoreRead_k - (0.165 *
                 APF_Path_Planning_2023a_B.rtb_path_o_idx_0 +
                 APF_Path_Planning_2023a_B.DataStoreRead6),
                (APF_Path_Planning_2023a_B.DataStoreRead2_j - 0.165 *
                 APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp) -
                APF_Path_Planning_2023a_B.DataStoreRead5) + 1.5707963267948966)
              + APF_Path_Planning_2023a_B.DataStoreRead4;

            // End of Outputs for SubSystem: '<S350>/APF'
            APF_Path_Planning_2023a_B.trueCount = 0;

            // Outputs for IfAction SubSystem: '<S350>/APF' incorporates:
            //   ActionPort: '<S368>/Action Port'

            // MATLAB Function: '<S372>/MATLAB Function'
            APF_Path_Planning_2023a_B.p = ((APF_Path_Planning_2023a_B.RED_Tz_RW <
              -3.1415926535897931) || (APF_Path_Planning_2023a_B.RED_Tz_RW >
              3.1415926535897931));
            if (APF_Path_Planning_2023a_B.p) {
              for (APF_Path_Planning_2023a_B.r_b = 0;
                   APF_Path_Planning_2023a_B.r_b < 1;
                   APF_Path_Planning_2023a_B.r_b++) {
                APF_Path_Planning_2023a_B.trueCount++;
              }
            }

            // MATLAB Function: '<S372>/MATLAB Function'
            if (APF_Path_Planning_2023a_B.trueCount - 1 >= 0) {
              if (rtIsNaN(APF_Path_Planning_2023a_B.RED_Tz_RW +
                          3.1415926535897931)) {
                APF_Path_Planning_2023a_B.varargout_1 = (rtNaN);
              } else if (rtIsInf(APF_Path_Planning_2023a_B.RED_Tz_RW +
                                 3.1415926535897931)) {
                APF_Path_Planning_2023a_B.varargout_1 = (rtNaN);
              } else if (APF_Path_Planning_2023a_B.RED_Tz_RW +
                         3.1415926535897931 == 0.0) {
                APF_Path_Planning_2023a_B.varargout_1 = 0.0;
              } else {
                APF_Path_Planning_2023a_B.varargout_1 = fmod
                  (APF_Path_Planning_2023a_B.RED_Tz_RW + 3.1415926535897931,
                   6.2831853071795862);
                APF_Path_Planning_2023a_B.rEQ0 =
                  (APF_Path_Planning_2023a_B.varargout_1 == 0.0);
                if (!APF_Path_Planning_2023a_B.rEQ0) {
                  APF_Path_Planning_2023a_B.q = fabs
                    ((APF_Path_Planning_2023a_B.RED_Tz_RW + 3.1415926535897931) /
                     6.2831853071795862);
                  APF_Path_Planning_2023a_B.rEQ0 = !(fabs
                    (APF_Path_Planning_2023a_B.q - floor
                     (APF_Path_Planning_2023a_B.q + 0.5)) >
                    2.2204460492503131E-16 * APF_Path_Planning_2023a_B.q);
                }

                if (APF_Path_Planning_2023a_B.rEQ0) {
                  APF_Path_Planning_2023a_B.varargout_1 = 0.0;
                } else if (APF_Path_Planning_2023a_B.RED_Tz_RW +
                           3.1415926535897931 < 0.0) {
                  APF_Path_Planning_2023a_B.varargout_1 += 6.2831853071795862;
                }
              }

              APF_Path_Planning_2023a_B.varargin_1_data =
                APF_Path_Planning_2023a_B.varargout_1;
            }

            if (APF_Path_Planning_2023a_B.trueCount - 1 >= 0) {
              APF_Path_Planning_2023a_B.r_b = 0;
              APF_Path_Planning_2023a_B.tmp_data =
                ((APF_Path_Planning_2023a_B.varargin_1_data == 0.0) &&
                 (APF_Path_Planning_2023a_B.RED_Tz_RW + 3.1415926535897931 > 0.0));
            }

            // End of Outputs for SubSystem: '<S350>/APF'
            APF_Path_Planning_2023a_B.br = 0;

            // Outputs for IfAction SubSystem: '<S350>/APF' incorporates:
            //   ActionPort: '<S368>/Action Port'

            if (APF_Path_Planning_2023a_B.tmp_data &&
                (APF_Path_Planning_2023a_B.trueCount - 1 >= 0)) {
              APF_Path_Planning_2023a_B.varargin_1_data = 6.2831853071795862;
            }

            // MATLAB Function: '<S372>/MATLAB Function'
            APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_B.RED_Tz_RW;

            // End of Outputs for SubSystem: '<S350>/APF'
            APF_Path_Planning_2023a_B.trueCount = 0;

            // Outputs for IfAction SubSystem: '<S350>/APF' incorporates:
            //   ActionPort: '<S368>/Action Port'

            if (APF_Path_Planning_2023a_B.p) {
              for (APF_Path_Planning_2023a_B.r_b = 0;
                   APF_Path_Planning_2023a_B.r_b < 1;
                   APF_Path_Planning_2023a_B.r_b++) {
                // MATLAB Function: '<S372>/MATLAB Function'
                APF_Path_Planning_2023a_B.t =
                  APF_Path_Planning_2023a_B.varargin_1_data - 3.1415926535897931;
                APF_Path_Planning_2023a_B.trueCount++;
              }
            }

            // MATLAB Function: '<S372>/MATLAB Function' incorporates:
            //   MATLAB Function: '<S382>/MATLAB Function1'
            //   SignalConversion generated from: '<S374>/ SFunction '

            if ((APF_Path_Planning_2023a_B.t >= 0.0) &&
                (APF_Path_Planning_2023a_B.t < 1.5707963267948966)) {
              APF_Path_Planning_2023a_B.RED_Tz_RW = cos
                (APF_Path_Planning_2023a_B.t);
              APF_Path_Planning_2023a_B.varargout_1 = sin
                (APF_Path_Planning_2023a_B.t);
              APF_Path_Planning_2023a_B.varargout_1 = 2.0 *
                APF_Path_Planning_2023a_P.shape[3] *
                APF_Path_Planning_2023a_P.shape[0] *
                APF_Path_Planning_2023a_P.shape[0] *
                APF_Path_Planning_2023a_B.RED_Tz_RW /
                (APF_Path_Planning_2023a_P.shape[0] *
                 APF_Path_Planning_2023a_P.shape[0] *
                 (APF_Path_Planning_2023a_B.RED_Tz_RW *
                  APF_Path_Planning_2023a_B.RED_Tz_RW) +
                 APF_Path_Planning_2023a_P.shape[3] *
                 APF_Path_Planning_2023a_P.shape[3] *
                 (APF_Path_Planning_2023a_B.varargout_1 *
                  APF_Path_Planning_2023a_B.varargout_1));
            } else if ((APF_Path_Planning_2023a_B.t >= 1.5707963267948966) &&
                       (APF_Path_Planning_2023a_B.t < 3.1415926535897931)) {
              APF_Path_Planning_2023a_B.RED_Tz_RW = cos
                (APF_Path_Planning_2023a_B.t);
              APF_Path_Planning_2023a_B.varargout_1 = sin
                (APF_Path_Planning_2023a_B.t);
              APF_Path_Planning_2023a_B.varargout_1 = -2.0 *
                APF_Path_Planning_2023a_P.shape[4] *
                APF_Path_Planning_2023a_P.shape[1] *
                APF_Path_Planning_2023a_P.shape[1] *
                APF_Path_Planning_2023a_B.RED_Tz_RW /
                (APF_Path_Planning_2023a_P.shape[1] *
                 APF_Path_Planning_2023a_P.shape[1] *
                 (APF_Path_Planning_2023a_B.RED_Tz_RW *
                  APF_Path_Planning_2023a_B.RED_Tz_RW) +
                 APF_Path_Planning_2023a_P.shape[4] *
                 APF_Path_Planning_2023a_P.shape[4] *
                 (APF_Path_Planning_2023a_B.varargout_1 *
                  APF_Path_Planning_2023a_B.varargout_1));
            } else if ((APF_Path_Planning_2023a_B.t >= -3.1415926535897931) &&
                       (APF_Path_Planning_2023a_B.t < -1.5707963267948966)) {
              APF_Path_Planning_2023a_B.RED_Tz_RW = cos
                (APF_Path_Planning_2023a_B.t);
              APF_Path_Planning_2023a_B.varargout_1 = sin
                (APF_Path_Planning_2023a_B.t);
              APF_Path_Planning_2023a_B.varargout_1 = 2.0 *
                APF_Path_Planning_2023a_P.shape[4] *
                APF_Path_Planning_2023a_P.shape[2] / sqrt(4.0 *
                APF_Path_Planning_2023a_P.shape[4] *
                APF_Path_Planning_2023a_P.shape[4] *
                (APF_Path_Planning_2023a_B.varargout_1 *
                 APF_Path_Planning_2023a_B.varargout_1) +
                APF_Path_Planning_2023a_P.shape[2] *
                APF_Path_Planning_2023a_P.shape[2] *
                (APF_Path_Planning_2023a_B.RED_Tz_RW *
                 APF_Path_Planning_2023a_B.RED_Tz_RW));
            } else if (APF_Path_Planning_2023a_B.t >= -1.5707963267948966) {
              if (APF_Path_Planning_2023a_B.t < 0.0) {
                APF_Path_Planning_2023a_B.RED_Tz_RW = cos
                  (APF_Path_Planning_2023a_B.t);
                APF_Path_Planning_2023a_B.varargout_1 = sin
                  (APF_Path_Planning_2023a_B.t);
                APF_Path_Planning_2023a_B.varargout_1 = 2.0 *
                  APF_Path_Planning_2023a_P.shape[3] *
                  APF_Path_Planning_2023a_P.shape[2] / sqrt(4.0 *
                  APF_Path_Planning_2023a_P.shape[4] *
                  APF_Path_Planning_2023a_P.shape[4] *
                  (APF_Path_Planning_2023a_B.varargout_1 *
                   APF_Path_Planning_2023a_B.varargout_1) +
                  APF_Path_Planning_2023a_P.shape[2] *
                  APF_Path_Planning_2023a_P.shape[2] *
                  (APF_Path_Planning_2023a_B.RED_Tz_RW *
                   APF_Path_Planning_2023a_B.RED_Tz_RW));
              } else {
                APF_Path_Planning_2023a_B.varargout_1 = 0.0;
              }
            } else {
              APF_Path_Planning_2023a_B.varargout_1 = 0.0;
            }

            APF_Path_Planning_2023a_B.RED_Tz_RW =
              APF_Path_Planning_2023a_B.varargout_1 * cos
              (APF_Path_Planning_2023a_B.t);
            APF_Path_Planning_2023a_B.varargout_1 *= sin
              (APF_Path_Planning_2023a_B.t);
            APF_Path_Planning_2023a_B.varargout_1 =
              APF_Path_Planning_rt_hypotd_snf
              (APF_Path_Planning_2023a_B.rtb_path_o_idx_0 *
               APF_Path_Planning_2023a_B.RED_Tz_RW +
               -APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp *
               APF_Path_Planning_2023a_B.varargout_1,
               APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp *
               APF_Path_Planning_2023a_B.RED_Tz_RW +
               APF_Path_Planning_2023a_B.rtb_path_o_idx_0 *
               APF_Path_Planning_2023a_B.varargout_1);
            APF_Path_Planning_2023a_B.RED_Tz_RW = 3.3121686421112381E-170;
            APF_Path_Planning_2023a_B.q = fabs(APF_Path_Planning_2023a_B.r_ct[0]);
            if (APF_Path_Planning_2023a_B.q > 3.3121686421112381E-170) {
              APF_Path_Planning_2023a_B.Derivative2 = 1.0;
              APF_Path_Planning_2023a_B.RED_Tz_RW = APF_Path_Planning_2023a_B.q;
            } else {
              APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_B.q /
                3.3121686421112381E-170;
              APF_Path_Planning_2023a_B.Derivative2 =
                APF_Path_Planning_2023a_B.t * APF_Path_Planning_2023a_B.t;
            }

            APF_Path_Planning_2023a_B.q = fabs(APF_Path_Planning_2023a_B.r_ct[1]);
            if (APF_Path_Planning_2023a_B.q >
                APF_Path_Planning_2023a_B.RED_Tz_RW) {
              APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_B.RED_Tz_RW /
                APF_Path_Planning_2023a_B.q;
              APF_Path_Planning_2023a_B.Derivative2 =
                APF_Path_Planning_2023a_B.Derivative2 *
                APF_Path_Planning_2023a_B.t * APF_Path_Planning_2023a_B.t + 1.0;
              APF_Path_Planning_2023a_B.RED_Tz_RW = APF_Path_Planning_2023a_B.q;
            } else {
              APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_B.q /
                APF_Path_Planning_2023a_B.RED_Tz_RW;
              APF_Path_Planning_2023a_B.Derivative2 +=
                APF_Path_Planning_2023a_B.t * APF_Path_Planning_2023a_B.t;
            }

            APF_Path_Planning_2023a_B.q = fabs(APF_Path_Planning_2023a_B.rtb_y_g);
            if (APF_Path_Planning_2023a_B.q >
                APF_Path_Planning_2023a_B.RED_Tz_RW) {
              APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_B.RED_Tz_RW /
                APF_Path_Planning_2023a_B.q;
              APF_Path_Planning_2023a_B.Derivative2 =
                APF_Path_Planning_2023a_B.Derivative2 *
                APF_Path_Planning_2023a_B.t * APF_Path_Planning_2023a_B.t + 1.0;
              APF_Path_Planning_2023a_B.RED_Tz_RW = APF_Path_Planning_2023a_B.q;
            } else {
              APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_B.q /
                APF_Path_Planning_2023a_B.RED_Tz_RW;
              APF_Path_Planning_2023a_B.Derivative2 +=
                APF_Path_Planning_2023a_B.t * APF_Path_Planning_2023a_B.t;
            }

            APF_Path_Planning_2023a_B.Derivative2 =
              APF_Path_Planning_2023a_B.RED_Tz_RW * sqrt
              (APF_Path_Planning_2023a_B.Derivative2);
            APF_Path_Planning_2023a_B.RED_Tz_RW =
              APF_Path_Planning_2023a_B.r_ct[0] -
              APF_Path_Planning_2023a_B.varargout_1 *
              APF_Path_Planning_2023a_B.r_ct[0] /
              APF_Path_Planning_2023a_B.Derivative2;
            APF_Path_Planning_2023a_B.r_ct[0] =
              APF_Path_Planning_2023a_B.RED_Tz_RW;
            APF_Path_Planning_2023a_B.q = -APF_Path_Planning_2023a_B.RED_Tz_RW;
            APF_Path_Planning_2023a_B.RED_Tz_RW =
              APF_Path_Planning_2023a_B.r_ct[1] -
              APF_Path_Planning_2023a_B.varargout_1 *
              APF_Path_Planning_2023a_B.r_ct[1] /
              APF_Path_Planning_2023a_B.Derivative2;
            APF_Path_Planning_2023a_B.r_ct[1] =
              APF_Path_Planning_2023a_B.RED_Tz_RW;
            APF_Path_Planning_2023a_B.t = -APF_Path_Planning_2023a_B.RED_Tz_RW;
            APF_Path_Planning_2023a_B.RED_Tz_RW =
              APF_Path_Planning_2023a_B.rtb_y_g -
              APF_Path_Planning_2023a_B.varargout_1 *
              APF_Path_Planning_2023a_B.rtb_y_g /
              APF_Path_Planning_2023a_B.Derivative2;
            APF_Path_Planning_2023a_B.r_ct[2] =
              APF_Path_Planning_2023a_B.RED_Tz_RW;
            APF_Path_Planning_2023a_B.varargout_1 = 0.0;
            APF_Path_Planning_2023a_B.rtb_path_b_idx_1 =
              -APF_Path_Planning_2023a_B.r_co[0];
            APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0 =
              -APF_Path_Planning_2023a_B.r_co[1];
            APF_Path_Planning_2023a_B.link2_com_y =
              -APF_Path_Planning_2023a_B.r_co[2];
            APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 = 0.0;
            for (APF_Path_Planning_2023a_B.r_b = 0;
                 APF_Path_Planning_2023a_B.r_b < 3;
                 APF_Path_Planning_2023a_B.r_b++) {
              APF_Path_Planning_2023a_B.trueCount = 3 *
                APF_Path_Planning_2023a_B.r_b + 1;
              APF_Path_Planning_2023a_B.vcol = 3 * APF_Path_Planning_2023a_B.r_b
                + 2;
              APF_Path_Planning_2023a_B.varargout_1 +=
                ((APF_Path_Planning_2023a_P.P_b[3 *
                  APF_Path_Planning_2023a_B.r_b] * APF_Path_Planning_2023a_B.q +
                  APF_Path_Planning_2023a_P.P_b[APF_Path_Planning_2023a_B.trueCount]
                  * APF_Path_Planning_2023a_B.t) +
                 APF_Path_Planning_2023a_P.P_b[APF_Path_Planning_2023a_B.vcol] *
                 -APF_Path_Planning_2023a_B.RED_Tz_RW) *
                APF_Path_Planning_2023a_B.r_ct[APF_Path_Planning_2023a_B.r_b];
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 +=
                ((APF_Path_Planning_2023a_P.Nmat[3 *
                  APF_Path_Planning_2023a_B.r_b] *
                  APF_Path_Planning_2023a_B.rtb_path_b_idx_1 +
                  APF_Path_Planning_2023a_P.Nmat[APF_Path_Planning_2023a_B.trueCount]
                  * APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0) +
                 APF_Path_Planning_2023a_P.Nmat[APF_Path_Planning_2023a_B.vcol] *
                 APF_Path_Planning_2023a_B.link2_com_y) *
                APF_Path_Planning_2023a_B.r_co[APF_Path_Planning_2023a_B.r_b];
            }

            for (APF_Path_Planning_2023a_B.r_b = 0;
                 APF_Path_Planning_2023a_B.r_b < 9;
                 APF_Path_Planning_2023a_B.r_b++) {
              APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp[APF_Path_Planning_2023a_B.r_b]
                = APF_Path_Planning_2023a_P.ka *
                APF_Path_Planning_2023a_P.Q_a[APF_Path_Planning_2023a_B.r_b];
            }

            APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[0] =
              (APF_Path_Planning_2023a_B.DataStoreRead6 -
               APF_Path_Planning_2023a_P.r_hold *
               APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp) +
              APF_Path_Planning_2023a_P.r_off *
              APF_Path_Planning_2023a_B.rtb_path_o_idx_0;
            APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[1] =
              (APF_Path_Planning_2023a_P.r_off *
               APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp +
               APF_Path_Planning_2023a_B.DataStoreRead5) +
              APF_Path_Planning_2023a_P.r_hold *
              APF_Path_Planning_2023a_B.rtb_path_o_idx_0;
            APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[2] =
              APF_Path_Planning_2023a_B.DataStoreRead4 + 3.1415926535897931;
            APF_Path_Planning_2023a_B.Derivative2 =
              (APF_Path_Planning_2023a_B.DataStoreRead_n -
               APF_Path_Planning_2023a_P.r_hold *
               APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp *
               APF_Path_Planning_2023a_B.DataStoreRead3) +
              APF_Path_Planning_2023a_P.r_off * cos
              (APF_Path_Planning_2023a_B.DataStoreRead4) *
              APF_Path_Planning_2023a_B.DataStoreRead3;
            APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[3] =
              APF_Path_Planning_2023a_B.Derivative2;
            APF_Path_Planning_2023a_B.rtb_path_o_idx_2 =
              (APF_Path_Planning_2023a_P.r_hold *
               APF_Path_Planning_2023a_B.rtb_path_o_idx_0 *
               APF_Path_Planning_2023a_B.DataStoreRead3 +
               APF_Path_Planning_2023a_B.DataStoreRead2) +
              APF_Path_Planning_2023a_P.r_off * sin
              (APF_Path_Planning_2023a_B.DataStoreRead4) *
              APF_Path_Planning_2023a_B.DataStoreRead3;
            APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[4] =
              APF_Path_Planning_2023a_B.rtb_path_o_idx_2;
            APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[5] =
              APF_Path_Planning_2023a_B.DataStoreRead3;
            APF_Path_Planning_2023a_B.t = 2.0 * APF_Path_Planning_2023a_P.kr *
              exp(APF_Path_Planning_2023a_B.varargout_1);
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 = 2.0 *
              APF_Path_Planning_2023a_P.psi / APF_Path_Planning_2023a_P.sigma;
            APF_Path_Planning_2023a_B.t21_tmp = exp
              (APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 /
               APF_Path_Planning_2023a_P.sigma) *
              APF_Path_Planning_2023a_B.rtb_path_b_idx_0;
            APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 =
              APF_Path_Planning_2023a_B.r_co[1];
            APF_Path_Planning_2023a_B.rtb_path_b_idx_1 =
              APF_Path_Planning_2023a_B.r_co[0];
            APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0 =
              APF_Path_Planning_2023a_B.r_co[2];
            APF_Path_Planning_2023a_B.varargout_1 =
              APF_Path_Planning_2023a_B.r_ct[1];
            APF_Path_Planning_2023a_B.q = APF_Path_Planning_2023a_B.r_ct[0];
            for (APF_Path_Planning_2023a_B.r_b = 0;
                 APF_Path_Planning_2023a_B.r_b < 3;
                 APF_Path_Planning_2023a_B.r_b++) {
              APF_Path_Planning_2023a_B.phi_tot_grad[APF_Path_Planning_2023a_B.r_b]
                =
                APF_Path_Planning_2023a_B.TmpSignalConversionAtSFunct[APF_Path_Planning_2023a_B.r_b]
                - APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[APF_Path_Planning_2023a_B.r_b];
              APF_Path_Planning_2023a_B.dv1[APF_Path_Planning_2023a_B.r_b] =
                (APF_Path_Planning_2023a_P.Nmat[APF_Path_Planning_2023a_B.r_b +
                 3] * APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 +
                 APF_Path_Planning_2023a_P.Nmat[APF_Path_Planning_2023a_B.r_b] *
                 APF_Path_Planning_2023a_B.rtb_path_b_idx_1) +
                APF_Path_Planning_2023a_P.Nmat[APF_Path_Planning_2023a_B.r_b + 6]
                * APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0;
              APF_Path_Planning_2023a_B.dv[APF_Path_Planning_2023a_B.r_b] =
                (APF_Path_Planning_2023a_P.P_b[APF_Path_Planning_2023a_B.r_b + 3]
                 * APF_Path_Planning_2023a_B.varargout_1 +
                 APF_Path_Planning_2023a_P.P_b[APF_Path_Planning_2023a_B.r_b] *
                 APF_Path_Planning_2023a_B.q) +
                APF_Path_Planning_2023a_P.P_b[APF_Path_Planning_2023a_B.r_b + 6]
                * APF_Path_Planning_2023a_B.RED_Tz_RW;
            }

            APF_Path_Planning_2023a_B.RED_Tz_RW =
              APF_Path_Planning_2023a_B.phi_tot_grad[1];
            APF_Path_Planning_2023a_B.varargout_1 =
              APF_Path_Planning_2023a_B.phi_tot_grad[0];
            APF_Path_Planning_2023a_B.q =
              APF_Path_Planning_2023a_B.phi_tot_grad[2];
            for (APF_Path_Planning_2023a_B.r_b = 0;
                 APF_Path_Planning_2023a_B.r_b < 3;
                 APF_Path_Planning_2023a_B.r_b++) {
              APF_Path_Planning_2023a_B.phi_tot_grad[APF_Path_Planning_2023a_B.r_b]
                =
                (((APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp[APF_Path_Planning_2023a_B.r_b
                   + 3] * APF_Path_Planning_2023a_B.RED_Tz_RW +
                   APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp[APF_Path_Planning_2023a_B.r_b]
                   * APF_Path_Planning_2023a_B.varargout_1) +
                  APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp[APF_Path_Planning_2023a_B.r_b
                  + 6] * APF_Path_Planning_2023a_B.q) -
                 APF_Path_Planning_2023a_B.t *
                 APF_Path_Planning_2023a_B.dv[APF_Path_Planning_2023a_B.r_b]) -
                APF_Path_Planning_2023a_B.t21_tmp *
                APF_Path_Planning_2023a_B.dv1[APF_Path_Planning_2023a_B.r_b];
            }

            if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
              // Delay: '<S381>/Delay'
              APF_Path_Planning_2023a_B.Delay_n[0] =
                APF_Path_Planning_2023a_DW.Delay_DSTATE_c[0];
              APF_Path_Planning_2023a_B.Delay_n[1] =
                APF_Path_Planning_2023a_DW.Delay_DSTATE_c[1];
              APF_Path_Planning_2023a_B.Delay_n[2] =
                APF_Path_Planning_2023a_DW.Delay_DSTATE_c[2];

              // Delay: '<S382>/Delay'
              APF_Path_Planning_2023a_B.Delay_b[0] =
                APF_Path_Planning_2023a_DW.Delay_DSTATE_o[0];
              APF_Path_Planning_2023a_B.Delay_b[1] =
                APF_Path_Planning_2023a_DW.Delay_DSTATE_o[1];
              APF_Path_Planning_2023a_B.Delay_b[2] =
                APF_Path_Planning_2023a_DW.Delay_DSTATE_o[2];
            }

            // MATLAB Function: '<S381>/Momentum'
            APF_Path_Planning_2023a_B.Sum3[0] =
              -APF_Path_Planning_2023a_P.momentum_gamma *
              APF_Path_Planning_2023a_B.Delay_n[0] -
              APF_Path_Planning_2023a_P.momentum_eta *
              APF_Path_Planning_2023a_B.phi_tot_grad[0];
            APF_Path_Planning_2023a_B.Sum3[1] =
              -APF_Path_Planning_2023a_P.momentum_gamma *
              APF_Path_Planning_2023a_B.Delay_n[1] -
              APF_Path_Planning_2023a_P.momentum_eta *
              APF_Path_Planning_2023a_B.phi_tot_grad[1];
            APF_Path_Planning_2023a_B.Sum3[2] =
              -APF_Path_Planning_2023a_P.momentum_gamma *
              APF_Path_Planning_2023a_B.Delay_n[2] -
              APF_Path_Planning_2023a_P.momentum_eta *
              APF_Path_Planning_2023a_B.phi_tot_grad[2];

            // MATLAB Function: '<S382>/MATLAB Function1' incorporates:
            //   DataStoreRead: '<S348>/Data Store Read'
            //   DataStoreRead: '<S348>/Data Store Read2'
            //   DataStoreRead: '<S348>/Data Store Read3'
            //   MATLAB Function: '<S372>/MATLAB Function'
            //   SignalConversion generated from: '<S374>/ SFunction '

            APF_Path_Planning_2023a_B.state_red[0] =
              APF_Path_Planning_2023a_P.nesterov_gamma *
              APF_Path_Planning_2023a_B.Delay_b[0] +
              APF_Path_Planning_2023a_B.DataStoreRead_k;
            APF_Path_Planning_2023a_B.state_red[1] =
              APF_Path_Planning_2023a_P.nesterov_gamma *
              APF_Path_Planning_2023a_B.Delay_b[1] +
              APF_Path_Planning_2023a_B.DataStoreRead2_j;
            APF_Path_Planning_2023a_B.state_red[2] =
              APF_Path_Planning_2023a_P.nesterov_gamma *
              APF_Path_Planning_2023a_B.Delay_b[2] +
              APF_Path_Planning_2023a_B.DataStoreRead3_l;
            APF_Path_Planning_2023a_B.state_red[3] =
              APF_Path_Planning_2023a_P.nesterov_gamma * 0.0 +
              APF_Path_Planning_2023a_B.DataStoreRead4_k;
            APF_Path_Planning_2023a_B.state_red[4] =
              APF_Path_Planning_2023a_P.nesterov_gamma * 0.0 +
              APF_Path_Planning_2023a_B.DataStoreRead5_b;
            APF_Path_Planning_2023a_B.state_red[5] =
              APF_Path_Planning_2023a_P.nesterov_gamma * 0.0 +
              APF_Path_Planning_2023a_B.DataStoreRead6_c;
            APF_Path_Planning_2023a_B.r_ct[0] =
              APF_Path_Planning_2023a_B.state_red[0] -
              APF_Path_Planning_2023a_B.DataStoreRead6;
            APF_Path_Planning_2023a_B.r_ct[1] =
              APF_Path_Planning_2023a_B.state_red[1] -
              APF_Path_Planning_2023a_B.DataStoreRead5;
            APF_Path_Planning_2023a_B.r_co[0] =
              APF_Path_Planning_2023a_B.state_red[0] -
              APF_Path_Planning_2023a_DW.BLUE_Px;
            APF_Path_Planning_2023a_B.r_co[1] =
              APF_Path_Planning_2023a_B.state_red[1] -
              APF_Path_Planning_2023a_DW.BLUE_Py;
            APF_Path_Planning_2023a_B.r_co[2] =
              APF_Path_Planning_2023a_DW.BLUE_Rz -
              APF_Path_Planning_2023a_DW.BLUE_Rz;
            APF_Path_Planning_2023a_B.RED_Tz_RW =
              (APF_Path_Planning_rt_atan2d_snf
               (APF_Path_Planning_2023a_B.state_red[0] - (0.165 *
                 APF_Path_Planning_2023a_B.rtb_path_o_idx_0 +
                 APF_Path_Planning_2023a_B.DataStoreRead6),
                (APF_Path_Planning_2023a_B.state_red[1] - 0.165 *
                 APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp) -
                APF_Path_Planning_2023a_B.DataStoreRead5) + 1.5707963267948966)
              + APF_Path_Planning_2023a_B.DataStoreRead4;

            // End of Outputs for SubSystem: '<S350>/APF'
            APF_Path_Planning_2023a_B.trueCount = 0;

            // Outputs for IfAction SubSystem: '<S350>/APF' incorporates:
            //   ActionPort: '<S368>/Action Port'

            // MATLAB Function: '<S382>/MATLAB Function1'
            APF_Path_Planning_2023a_B.p = ((APF_Path_Planning_2023a_B.RED_Tz_RW <
              -3.1415926535897931) || (APF_Path_Planning_2023a_B.RED_Tz_RW >
              3.1415926535897931));
            if (APF_Path_Planning_2023a_B.p) {
              for (APF_Path_Planning_2023a_B.r_b = 0;
                   APF_Path_Planning_2023a_B.r_b < 1;
                   APF_Path_Planning_2023a_B.r_b++) {
                APF_Path_Planning_2023a_B.trueCount++;
              }
            }

            // MATLAB Function: '<S382>/MATLAB Function1'
            if (APF_Path_Planning_2023a_B.trueCount - 1 >= 0) {
              if (rtIsNaN(APF_Path_Planning_2023a_B.RED_Tz_RW +
                          3.1415926535897931)) {
                APF_Path_Planning_2023a_B.varargout_1 = (rtNaN);
              } else if (rtIsInf(APF_Path_Planning_2023a_B.RED_Tz_RW +
                                 3.1415926535897931)) {
                APF_Path_Planning_2023a_B.varargout_1 = (rtNaN);
              } else if (APF_Path_Planning_2023a_B.RED_Tz_RW +
                         3.1415926535897931 == 0.0) {
                APF_Path_Planning_2023a_B.varargout_1 = 0.0;
              } else {
                APF_Path_Planning_2023a_B.varargout_1 = fmod
                  (APF_Path_Planning_2023a_B.RED_Tz_RW + 3.1415926535897931,
                   6.2831853071795862);
                APF_Path_Planning_2023a_B.rEQ0 =
                  (APF_Path_Planning_2023a_B.varargout_1 == 0.0);
                if (!APF_Path_Planning_2023a_B.rEQ0) {
                  APF_Path_Planning_2023a_B.q = fabs
                    ((APF_Path_Planning_2023a_B.RED_Tz_RW + 3.1415926535897931) /
                     6.2831853071795862);
                  APF_Path_Planning_2023a_B.rEQ0 = !(fabs
                    (APF_Path_Planning_2023a_B.q - floor
                     (APF_Path_Planning_2023a_B.q + 0.5)) >
                    2.2204460492503131E-16 * APF_Path_Planning_2023a_B.q);
                }

                if (APF_Path_Planning_2023a_B.rEQ0) {
                  APF_Path_Planning_2023a_B.varargout_1 = 0.0;
                } else if (APF_Path_Planning_2023a_B.RED_Tz_RW +
                           3.1415926535897931 < 0.0) {
                  APF_Path_Planning_2023a_B.varargout_1 += 6.2831853071795862;
                }
              }

              APF_Path_Planning_2023a_B.varargin_1_data =
                APF_Path_Planning_2023a_B.varargout_1;
            }

            if (APF_Path_Planning_2023a_B.trueCount - 1 >= 0) {
              APF_Path_Planning_2023a_B.tmp_data =
                ((APF_Path_Planning_2023a_B.varargin_1_data == 0.0) &&
                 (APF_Path_Planning_2023a_B.RED_Tz_RW + 3.1415926535897931 > 0.0));
            }

            if (APF_Path_Planning_2023a_B.tmp_data &&
                (APF_Path_Planning_2023a_B.trueCount - 1 >= 0)) {
              APF_Path_Planning_2023a_B.varargin_1_data = 6.2831853071795862;
            }

            // MATLAB Function: '<S382>/MATLAB Function1'
            APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_B.RED_Tz_RW;

            // End of Outputs for SubSystem: '<S350>/APF'
            APF_Path_Planning_2023a_B.trueCount = 0;

            // Outputs for IfAction SubSystem: '<S350>/APF' incorporates:
            //   ActionPort: '<S368>/Action Port'

            if (APF_Path_Planning_2023a_B.p) {
              for (APF_Path_Planning_2023a_B.r_b = 0;
                   APF_Path_Planning_2023a_B.r_b < 1;
                   APF_Path_Planning_2023a_B.r_b++) {
                // MATLAB Function: '<S382>/MATLAB Function1'
                APF_Path_Planning_2023a_B.t =
                  APF_Path_Planning_2023a_B.varargin_1_data - 3.1415926535897931;
                APF_Path_Planning_2023a_B.trueCount++;
              }
            }

            // MATLAB Function: '<S382>/MATLAB Function1' incorporates:
            //   MATLAB Function: '<S372>/MATLAB Function'
            //   SignalConversion generated from: '<S374>/ SFunction '

            if ((APF_Path_Planning_2023a_B.t >= 0.0) &&
                (APF_Path_Planning_2023a_B.t < 1.5707963267948966)) {
              APF_Path_Planning_2023a_B.RED_Tz_RW = cos
                (APF_Path_Planning_2023a_B.t);
              APF_Path_Planning_2023a_B.varargout_1 = sin
                (APF_Path_Planning_2023a_B.t);
              APF_Path_Planning_2023a_B.varargout_1 = 2.0 *
                APF_Path_Planning_2023a_P.shape[3] *
                APF_Path_Planning_2023a_P.shape[0] *
                APF_Path_Planning_2023a_P.shape[0] *
                APF_Path_Planning_2023a_B.RED_Tz_RW /
                (APF_Path_Planning_2023a_P.shape[0] *
                 APF_Path_Planning_2023a_P.shape[0] *
                 (APF_Path_Planning_2023a_B.RED_Tz_RW *
                  APF_Path_Planning_2023a_B.RED_Tz_RW) +
                 APF_Path_Planning_2023a_P.shape[3] *
                 APF_Path_Planning_2023a_P.shape[3] *
                 (APF_Path_Planning_2023a_B.varargout_1 *
                  APF_Path_Planning_2023a_B.varargout_1));
            } else if ((APF_Path_Planning_2023a_B.t >= 1.5707963267948966) &&
                       (APF_Path_Planning_2023a_B.t < 3.1415926535897931)) {
              APF_Path_Planning_2023a_B.RED_Tz_RW = cos
                (APF_Path_Planning_2023a_B.t);
              APF_Path_Planning_2023a_B.varargout_1 = sin
                (APF_Path_Planning_2023a_B.t);
              APF_Path_Planning_2023a_B.varargout_1 = -2.0 *
                APF_Path_Planning_2023a_P.shape[4] *
                APF_Path_Planning_2023a_P.shape[1] *
                APF_Path_Planning_2023a_P.shape[1] *
                APF_Path_Planning_2023a_B.RED_Tz_RW /
                (APF_Path_Planning_2023a_P.shape[1] *
                 APF_Path_Planning_2023a_P.shape[1] *
                 (APF_Path_Planning_2023a_B.RED_Tz_RW *
                  APF_Path_Planning_2023a_B.RED_Tz_RW) +
                 APF_Path_Planning_2023a_P.shape[4] *
                 APF_Path_Planning_2023a_P.shape[4] *
                 (APF_Path_Planning_2023a_B.varargout_1 *
                  APF_Path_Planning_2023a_B.varargout_1));
            } else if ((APF_Path_Planning_2023a_B.t >= -3.1415926535897931) &&
                       (APF_Path_Planning_2023a_B.t < -1.5707963267948966)) {
              APF_Path_Planning_2023a_B.RED_Tz_RW = cos
                (APF_Path_Planning_2023a_B.t);
              APF_Path_Planning_2023a_B.varargout_1 = sin
                (APF_Path_Planning_2023a_B.t);
              APF_Path_Planning_2023a_B.varargout_1 = 2.0 *
                APF_Path_Planning_2023a_P.shape[4] *
                APF_Path_Planning_2023a_P.shape[2] / sqrt(4.0 *
                APF_Path_Planning_2023a_P.shape[4] *
                APF_Path_Planning_2023a_P.shape[4] *
                (APF_Path_Planning_2023a_B.varargout_1 *
                 APF_Path_Planning_2023a_B.varargout_1) +
                APF_Path_Planning_2023a_P.shape[2] *
                APF_Path_Planning_2023a_P.shape[2] *
                (APF_Path_Planning_2023a_B.RED_Tz_RW *
                 APF_Path_Planning_2023a_B.RED_Tz_RW));
            } else if (APF_Path_Planning_2023a_B.t >= -1.5707963267948966) {
              if (APF_Path_Planning_2023a_B.t < 0.0) {
                APF_Path_Planning_2023a_B.RED_Tz_RW = cos
                  (APF_Path_Planning_2023a_B.t);
                APF_Path_Planning_2023a_B.varargout_1 = sin
                  (APF_Path_Planning_2023a_B.t);
                APF_Path_Planning_2023a_B.varargout_1 = 2.0 *
                  APF_Path_Planning_2023a_P.shape[3] *
                  APF_Path_Planning_2023a_P.shape[2] / sqrt(4.0 *
                  APF_Path_Planning_2023a_P.shape[4] *
                  APF_Path_Planning_2023a_P.shape[4] *
                  (APF_Path_Planning_2023a_B.varargout_1 *
                   APF_Path_Planning_2023a_B.varargout_1) +
                  APF_Path_Planning_2023a_P.shape[2] *
                  APF_Path_Planning_2023a_P.shape[2] *
                  (APF_Path_Planning_2023a_B.RED_Tz_RW *
                   APF_Path_Planning_2023a_B.RED_Tz_RW));
              } else {
                APF_Path_Planning_2023a_B.varargout_1 = 0.0;
              }
            } else {
              APF_Path_Planning_2023a_B.varargout_1 = 0.0;
            }

            APF_Path_Planning_2023a_B.RED_Tz_RW =
              APF_Path_Planning_2023a_B.varargout_1 * cos
              (APF_Path_Planning_2023a_B.t);
            APF_Path_Planning_2023a_B.varargout_1 *= sin
              (APF_Path_Planning_2023a_B.t);
            APF_Path_Planning_2023a_B.varargout_1 =
              APF_Path_Planning_rt_hypotd_snf
              (APF_Path_Planning_2023a_B.rtb_path_o_idx_0 *
               APF_Path_Planning_2023a_B.RED_Tz_RW +
               -APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp *
               APF_Path_Planning_2023a_B.varargout_1,
               APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp *
               APF_Path_Planning_2023a_B.RED_Tz_RW +
               APF_Path_Planning_2023a_B.rtb_path_o_idx_0 *
               APF_Path_Planning_2023a_B.varargout_1);
            APF_Path_Planning_2023a_B.RED_Tz_RW = 3.3121686421112381E-170;
            APF_Path_Planning_2023a_B.q = fabs(APF_Path_Planning_2023a_B.r_ct[0]);
            if (APF_Path_Planning_2023a_B.q > 3.3121686421112381E-170) {
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 = 1.0;
              APF_Path_Planning_2023a_B.RED_Tz_RW = APF_Path_Planning_2023a_B.q;
            } else {
              APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_B.q /
                3.3121686421112381E-170;
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 =
                APF_Path_Planning_2023a_B.t * APF_Path_Planning_2023a_B.t;
            }

            APF_Path_Planning_2023a_B.q = fabs(APF_Path_Planning_2023a_B.r_ct[1]);
            if (APF_Path_Planning_2023a_B.q >
                APF_Path_Planning_2023a_B.RED_Tz_RW) {
              APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_B.RED_Tz_RW /
                APF_Path_Planning_2023a_B.q;
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 =
                APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 *
                APF_Path_Planning_2023a_B.t * APF_Path_Planning_2023a_B.t + 1.0;
              APF_Path_Planning_2023a_B.RED_Tz_RW = APF_Path_Planning_2023a_B.q;
            } else {
              APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_B.q /
                APF_Path_Planning_2023a_B.RED_Tz_RW;
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 +=
                APF_Path_Planning_2023a_B.t * APF_Path_Planning_2023a_B.t;
            }

            APF_Path_Planning_2023a_B.q = fabs(APF_Path_Planning_2023a_B.rtb_y_g);
            if (APF_Path_Planning_2023a_B.q >
                APF_Path_Planning_2023a_B.RED_Tz_RW) {
              APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_B.RED_Tz_RW /
                APF_Path_Planning_2023a_B.q;
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 =
                APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 *
                APF_Path_Planning_2023a_B.t * APF_Path_Planning_2023a_B.t + 1.0;
              APF_Path_Planning_2023a_B.RED_Tz_RW = APF_Path_Planning_2023a_B.q;
            } else {
              APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_B.q /
                APF_Path_Planning_2023a_B.RED_Tz_RW;
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 +=
                APF_Path_Planning_2023a_B.t * APF_Path_Planning_2023a_B.t;
            }

            APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 =
              APF_Path_Planning_2023a_B.RED_Tz_RW * sqrt
              (APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1);
            APF_Path_Planning_2023a_B.RED_Tz_RW =
              APF_Path_Planning_2023a_B.r_ct[0] -
              APF_Path_Planning_2023a_B.varargout_1 *
              APF_Path_Planning_2023a_B.r_ct[0] /
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1;
            APF_Path_Planning_2023a_B.r_ct[0] =
              APF_Path_Planning_2023a_B.RED_Tz_RW;
            APF_Path_Planning_2023a_B.q = -APF_Path_Planning_2023a_B.RED_Tz_RW;
            APF_Path_Planning_2023a_B.RED_Tz_RW =
              APF_Path_Planning_2023a_B.r_ct[1] -
              APF_Path_Planning_2023a_B.varargout_1 *
              APF_Path_Planning_2023a_B.r_ct[1] /
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1;
            APF_Path_Planning_2023a_B.r_ct[1] =
              APF_Path_Planning_2023a_B.RED_Tz_RW;
            APF_Path_Planning_2023a_B.t = -APF_Path_Planning_2023a_B.RED_Tz_RW;
            APF_Path_Planning_2023a_B.RED_Tz_RW =
              APF_Path_Planning_2023a_B.rtb_y_g -
              APF_Path_Planning_2023a_B.varargout_1 *
              APF_Path_Planning_2023a_B.rtb_y_g /
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1;
            APF_Path_Planning_2023a_B.r_ct[2] =
              APF_Path_Planning_2023a_B.RED_Tz_RW;
            APF_Path_Planning_2023a_B.varargout_1 = 0.0;
            APF_Path_Planning_2023a_B.rtb_path_b_idx_1 =
              -APF_Path_Planning_2023a_B.r_co[0];
            APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0 =
              -APF_Path_Planning_2023a_B.r_co[1];
            APF_Path_Planning_2023a_B.link2_com_y =
              -APF_Path_Planning_2023a_B.r_co[2];
            APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 = 0.0;
            APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[0] =
              (APF_Path_Planning_2023a_B.DataStoreRead6 -
               APF_Path_Planning_2023a_P.r_hold *
               APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp) +
              APF_Path_Planning_2023a_P.r_off *
              APF_Path_Planning_2023a_B.rtb_path_o_idx_0;
            APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[1] =
              (APF_Path_Planning_2023a_P.r_off *
               APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp +
               APF_Path_Planning_2023a_B.DataStoreRead5) +
              APF_Path_Planning_2023a_P.r_hold *
              APF_Path_Planning_2023a_B.rtb_path_o_idx_0;
            APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[2] =
              APF_Path_Planning_2023a_B.DataStoreRead4 + 3.1415926535897931;
            APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[3] =
              APF_Path_Planning_2023a_B.Derivative2;
            APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[4] =
              APF_Path_Planning_2023a_B.rtb_path_o_idx_2;
            APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[5] =
              APF_Path_Planning_2023a_B.DataStoreRead3;
            for (APF_Path_Planning_2023a_B.r_b = 0;
                 APF_Path_Planning_2023a_B.r_b < 3;
                 APF_Path_Planning_2023a_B.r_b++) {
              APF_Path_Planning_2023a_B.trueCount = 3 *
                APF_Path_Planning_2023a_B.r_b + 1;
              APF_Path_Planning_2023a_B.vcol = 3 * APF_Path_Planning_2023a_B.r_b
                + 2;
              APF_Path_Planning_2023a_B.varargout_1 +=
                ((APF_Path_Planning_2023a_P.P_b[3 *
                  APF_Path_Planning_2023a_B.r_b] * APF_Path_Planning_2023a_B.q +
                  APF_Path_Planning_2023a_P.P_b[APF_Path_Planning_2023a_B.trueCount]
                  * APF_Path_Planning_2023a_B.t) +
                 APF_Path_Planning_2023a_P.P_b[APF_Path_Planning_2023a_B.vcol] *
                 -APF_Path_Planning_2023a_B.RED_Tz_RW) *
                APF_Path_Planning_2023a_B.r_ct[APF_Path_Planning_2023a_B.r_b];
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 +=
                ((APF_Path_Planning_2023a_P.Nmat[3 *
                  APF_Path_Planning_2023a_B.r_b] *
                  APF_Path_Planning_2023a_B.rtb_path_b_idx_1 +
                  APF_Path_Planning_2023a_P.Nmat[APF_Path_Planning_2023a_B.trueCount]
                  * APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0) +
                 APF_Path_Planning_2023a_P.Nmat[APF_Path_Planning_2023a_B.vcol] *
                 APF_Path_Planning_2023a_B.link2_com_y) *
                APF_Path_Planning_2023a_B.r_co[APF_Path_Planning_2023a_B.r_b];
              APF_Path_Planning_2023a_B.state_red_m[APF_Path_Planning_2023a_B.r_b]
                =
                APF_Path_Planning_2023a_B.state_red[APF_Path_Planning_2023a_B.r_b]
                - APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[APF_Path_Planning_2023a_B.r_b];
              APF_Path_Planning_2023a_B.dv1[APF_Path_Planning_2023a_B.r_b] =
                (APF_Path_Planning_2023a_P.Nmat[APF_Path_Planning_2023a_B.r_b +
                 3] * APF_Path_Planning_2023a_B.r_co[1] +
                 APF_Path_Planning_2023a_P.Nmat[APF_Path_Planning_2023a_B.r_b] *
                 APF_Path_Planning_2023a_B.r_co[0]) +
                APF_Path_Planning_2023a_P.Nmat[APF_Path_Planning_2023a_B.r_b + 6]
                * APF_Path_Planning_2023a_B.r_co[2];
              APF_Path_Planning_2023a_B.dv[APF_Path_Planning_2023a_B.r_b] =
                (APF_Path_Planning_2023a_P.P_b[APF_Path_Planning_2023a_B.r_b + 3]
                 * APF_Path_Planning_2023a_B.r_ct[1] +
                 APF_Path_Planning_2023a_P.P_b[APF_Path_Planning_2023a_B.r_b] *
                 APF_Path_Planning_2023a_B.r_ct[0]) +
                APF_Path_Planning_2023a_P.P_b[APF_Path_Planning_2023a_B.r_b + 6]
                * APF_Path_Planning_2023a_B.RED_Tz_RW;
            }

            APF_Path_Planning_2023a_B.t = 2.0 * APF_Path_Planning_2023a_P.kr *
              exp(APF_Path_Planning_2023a_B.varargout_1);
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 *= exp
              (APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 /
               APF_Path_Planning_2023a_P.sigma);
            APF_Path_Planning_2023a_B.RED_Tz_RW =
              APF_Path_Planning_2023a_B.state_red_m[1];
            APF_Path_Planning_2023a_B.rtb_y_g =
              APF_Path_Planning_2023a_B.state_red_m[0];
            APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp =
              APF_Path_Planning_2023a_B.state_red_m[2];
            for (APF_Path_Planning_2023a_B.r_b = 0;
                 APF_Path_Planning_2023a_B.r_b < 3;
                 APF_Path_Planning_2023a_B.r_b++) {
              APF_Path_Planning_2023a_B.Sum_n[APF_Path_Planning_2023a_B.r_b] =
                -APF_Path_Planning_2023a_P.nesterov_gamma *
                APF_Path_Planning_2023a_B.Delay_b[APF_Path_Planning_2023a_B.r_b]
                - ((((APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp[APF_Path_Planning_2023a_B.r_b
                      + 3] * APF_Path_Planning_2023a_B.RED_Tz_RW +
                      APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp[APF_Path_Planning_2023a_B.r_b]
                      * APF_Path_Planning_2023a_B.rtb_y_g) +
                     APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp[APF_Path_Planning_2023a_B.r_b
                     + 6] * APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp) -
                    APF_Path_Planning_2023a_B.t *
                    APF_Path_Planning_2023a_B.dv[APF_Path_Planning_2023a_B.r_b])
                   - APF_Path_Planning_2023a_B.rtb_path_b_idx_0 *
                   APF_Path_Planning_2023a_B.dv1[APF_Path_Planning_2023a_B.r_b])
                * APF_Path_Planning_2023a_P.nesterov_eta;
            }

            if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
              // Delay: '<S377>/Delay3'
              APF_Path_Planning_2023a_B.Delay3[0] =
                APF_Path_Planning_2023a_DW.Delay3_DSTATE[0];
              APF_Path_Planning_2023a_B.Delay3[1] =
                APF_Path_Planning_2023a_DW.Delay3_DSTATE[1];
              APF_Path_Planning_2023a_B.Delay3[2] =
                APF_Path_Planning_2023a_DW.Delay3_DSTATE[2];

              // Delay: '<S376>/Delay'
              APF_Path_Planning_2023a_B.Delay_l[0] =
                APF_Path_Planning_2023a_DW.Delay_DSTATE_d[0];

              // Delay: '<S376>/Delay1'
              APF_Path_Planning_2023a_B.Delay1[0] =
                APF_Path_Planning_2023a_DW.Delay1_DSTATE[0];

              // Delay: '<S376>/Delay'
              APF_Path_Planning_2023a_B.Delay_l[1] =
                APF_Path_Planning_2023a_DW.Delay_DSTATE_d[1];

              // Delay: '<S376>/Delay1'
              APF_Path_Planning_2023a_B.Delay1[1] =
                APF_Path_Planning_2023a_DW.Delay1_DSTATE[1];

              // Delay: '<S376>/Delay'
              APF_Path_Planning_2023a_B.Delay_l[2] =
                APF_Path_Planning_2023a_DW.Delay_DSTATE_d[2];

              // Delay: '<S376>/Delay1'
              APF_Path_Planning_2023a_B.Delay1[2] =
                APF_Path_Planning_2023a_DW.Delay1_DSTATE[2];
            }

            // MATLAB Function: '<S377>/MATLAB Function1' incorporates:
            //   Delay: '<S377>/Delay3'
            //   MATLAB Function: '<S376>/MATLAB Function1'
            //   MATLAB Function: '<S379>/MATLAB Function1'
            //   MATLAB Function: '<S383>/MATLAB Function1'

            APF_Path_Planning_2023a_B.Derivative2 =
              APF_Path_Planning_2023a_B.phi_tot_grad[0] *
              APF_Path_Planning_2023a_B.phi_tot_grad[0];
            APF_Path_Planning_2023a_B.RED_Tz_RW =
              APF_Path_Planning_2023a_B.Derivative2 +
              APF_Path_Planning_2023a_B.Delay3[0];
            APF_Path_Planning_2023a_B.Gt[0] =
              APF_Path_Planning_2023a_B.RED_Tz_RW;

            // MATLAB Function: '<S377>/MATLAB Function1' incorporates:
            //   Delay: '<S377>/Delay3'
            //   MATLAB Function: '<S376>/MATLAB Function1'
            //   MATLAB Function: '<S379>/MATLAB Function1'
            //   MATLAB Function: '<S383>/MATLAB Function1'
            //   SignalConversion generated from: '<S385>/ SFunction '

            APF_Path_Planning_2023a_B.MultiportSwitch[0] =
              APF_Path_Planning_2023a_B.RED_Tz_RW +
              APF_Path_Planning_2023a_P.adagrad_epsilon;
            APF_Path_Planning_2023a_B.MultiportSwitch[0] = sqrt
              (APF_Path_Planning_2023a_B.MultiportSwitch[0]);
            APF_Path_Planning_2023a_B.MultiportSwitch[0] =
              APF_Path_Planning_2023a_B.DataStoreRead_k -
              APF_Path_Planning_2023a_P.adagrad_eta /
              APF_Path_Planning_2023a_B.MultiportSwitch[0] *
              APF_Path_Planning_2023a_B.phi_tot_grad[0];
            APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 =
              APF_Path_Planning_2023a_B.phi_tot_grad[1] *
              APF_Path_Planning_2023a_B.phi_tot_grad[1];
            APF_Path_Planning_2023a_B.RED_Tz_RW =
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 +
              APF_Path_Planning_2023a_B.Delay3[1];
            APF_Path_Planning_2023a_B.Gt[1] =
              APF_Path_Planning_2023a_B.RED_Tz_RW;

            // MATLAB Function: '<S377>/MATLAB Function1' incorporates:
            //   Delay: '<S377>/Delay3'
            //   MATLAB Function: '<S376>/MATLAB Function1'
            //   MATLAB Function: '<S379>/MATLAB Function1'
            //   MATLAB Function: '<S383>/MATLAB Function1'
            //   SignalConversion generated from: '<S385>/ SFunction '

            APF_Path_Planning_2023a_B.MultiportSwitch[1] =
              APF_Path_Planning_2023a_B.RED_Tz_RW +
              APF_Path_Planning_2023a_P.adagrad_epsilon;
            APF_Path_Planning_2023a_B.MultiportSwitch[1] = sqrt
              (APF_Path_Planning_2023a_B.MultiportSwitch[1]);
            APF_Path_Planning_2023a_B.MultiportSwitch[1] =
              APF_Path_Planning_2023a_B.DataStoreRead2_j -
              APF_Path_Planning_2023a_P.adagrad_eta /
              APF_Path_Planning_2023a_B.MultiportSwitch[1] *
              APF_Path_Planning_2023a_B.phi_tot_grad[1];
            APF_Path_Planning_2023a_B.rtb_path_o_idx_2 =
              APF_Path_Planning_2023a_B.phi_tot_grad[2] *
              APF_Path_Planning_2023a_B.phi_tot_grad[2];
            APF_Path_Planning_2023a_B.RED_Tz_RW =
              APF_Path_Planning_2023a_B.rtb_path_o_idx_2 +
              APF_Path_Planning_2023a_B.Delay3[2];
            APF_Path_Planning_2023a_B.Gt[2] =
              APF_Path_Planning_2023a_B.RED_Tz_RW;

            // MATLAB Function: '<S377>/MATLAB Function1' incorporates:
            //   Delay: '<S377>/Delay3'
            //   SignalConversion generated from: '<S385>/ SFunction '

            APF_Path_Planning_2023a_B.MultiportSwitch[2] =
              APF_Path_Planning_2023a_B.RED_Tz_RW +
              APF_Path_Planning_2023a_P.adagrad_epsilon;
            APF_Path_Planning_2023a_B.MultiportSwitch[2] = sqrt
              (APF_Path_Planning_2023a_B.MultiportSwitch[2]);
            APF_Path_Planning_2023a_B.MultiportSwitch[2] =
              APF_Path_Planning_2023a_B.DataStoreRead3_l -
              APF_Path_Planning_2023a_P.adagrad_eta /
              APF_Path_Planning_2023a_B.MultiportSwitch[2] *
              APF_Path_Planning_2023a_B.phi_tot_grad[2];

            // MATLAB Function: '<S376>/MATLAB Function1'
            APF_Path_Planning_2023a_B.RED_Tz_RW = (1.0 -
              APF_Path_Planning_2023a_P.adadelta_gamma) *
              APF_Path_Planning_2023a_B.Derivative2 +
              APF_Path_Planning_2023a_P.adadelta_gamma *
              APF_Path_Planning_2023a_B.Delay_l[0];
            APF_Path_Planning_2023a_B.Eg_n[0] =
              APF_Path_Planning_2023a_B.RED_Tz_RW;

            // MATLAB Function: '<S376>/MATLAB Function1'
            APF_Path_Planning_2023a_B.RED_Tz_RW = sqrt
              (APF_Path_Planning_2023a_B.Delay1[0] +
               APF_Path_Planning_2023a_P.adadelta_epsilon) / sqrt
              (APF_Path_Planning_2023a_B.RED_Tz_RW +
               APF_Path_Planning_2023a_P.adadelta_epsilon) *
              APF_Path_Planning_2023a_B.phi_tot_grad[0];
            APF_Path_Planning_2023a_B.Etheta[0] = (1.0 -
              APF_Path_Planning_2023a_P.adadelta_gamma) *
              (APF_Path_Planning_2023a_B.RED_Tz_RW *
               APF_Path_Planning_2023a_B.RED_Tz_RW) +
              APF_Path_Planning_2023a_P.adadelta_gamma *
              APF_Path_Planning_2023a_B.Delay1[0];

            // MATLAB Function: '<S376>/MATLAB Function1' incorporates:
            //   SignalConversion generated from: '<S384>/ SFunction '

            APF_Path_Planning_2023a_B.varargout_1 =
              APF_Path_Planning_2023a_B.DataStoreRead_k -
              APF_Path_Planning_2023a_B.RED_Tz_RW;
            APF_Path_Planning_2023a_B.RED_Tz_RW = (1.0 -
              APF_Path_Planning_2023a_P.adadelta_gamma) *
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 +
              APF_Path_Planning_2023a_P.adadelta_gamma *
              APF_Path_Planning_2023a_B.Delay_l[1];
            APF_Path_Planning_2023a_B.Eg_n[1] =
              APF_Path_Planning_2023a_B.RED_Tz_RW;

            // MATLAB Function: '<S376>/MATLAB Function1'
            APF_Path_Planning_2023a_B.RED_Tz_RW = sqrt
              (APF_Path_Planning_2023a_B.Delay1[1] +
               APF_Path_Planning_2023a_P.adadelta_epsilon) / sqrt
              (APF_Path_Planning_2023a_B.RED_Tz_RW +
               APF_Path_Planning_2023a_P.adadelta_epsilon) *
              APF_Path_Planning_2023a_B.phi_tot_grad[1];
            APF_Path_Planning_2023a_B.Etheta[1] = (1.0 -
              APF_Path_Planning_2023a_P.adadelta_gamma) *
              (APF_Path_Planning_2023a_B.RED_Tz_RW *
               APF_Path_Planning_2023a_B.RED_Tz_RW) +
              APF_Path_Planning_2023a_P.adadelta_gamma *
              APF_Path_Planning_2023a_B.Delay1[1];

            // MATLAB Function: '<S376>/MATLAB Function1' incorporates:
            //   SignalConversion generated from: '<S384>/ SFunction '

            APF_Path_Planning_2023a_B.q =
              APF_Path_Planning_2023a_B.DataStoreRead2_j -
              APF_Path_Planning_2023a_B.RED_Tz_RW;
            APF_Path_Planning_2023a_B.RED_Tz_RW = (1.0 -
              APF_Path_Planning_2023a_P.adadelta_gamma) *
              APF_Path_Planning_2023a_B.rtb_path_o_idx_2 +
              APF_Path_Planning_2023a_P.adadelta_gamma *
              APF_Path_Planning_2023a_B.Delay_l[2];
            APF_Path_Planning_2023a_B.Eg_n[2] =
              APF_Path_Planning_2023a_B.RED_Tz_RW;

            // MATLAB Function: '<S376>/MATLAB Function1'
            APF_Path_Planning_2023a_B.RED_Tz_RW = sqrt
              (APF_Path_Planning_2023a_B.Delay1[2] +
               APF_Path_Planning_2023a_P.adadelta_epsilon) / sqrt
              (APF_Path_Planning_2023a_B.RED_Tz_RW +
               APF_Path_Planning_2023a_P.adadelta_epsilon) *
              APF_Path_Planning_2023a_B.phi_tot_grad[2];
            APF_Path_Planning_2023a_B.Etheta[2] = (1.0 -
              APF_Path_Planning_2023a_P.adadelta_gamma) *
              (APF_Path_Planning_2023a_B.RED_Tz_RW *
               APF_Path_Planning_2023a_B.RED_Tz_RW) +
              APF_Path_Planning_2023a_P.adadelta_gamma *
              APF_Path_Planning_2023a_B.Delay1[2];
            if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
              // Delay: '<S383>/Delay3'
              APF_Path_Planning_2023a_B.Delay3_f[0] =
                APF_Path_Planning_2023a_DW.Delay3_DSTATE_d[0];
              APF_Path_Planning_2023a_B.Delay3_f[1] =
                APF_Path_Planning_2023a_DW.Delay3_DSTATE_d[1];
              APF_Path_Planning_2023a_B.Delay3_f[2] =
                APF_Path_Planning_2023a_DW.Delay3_DSTATE_d[2];

              // Delay: '<S379>/Delay3'
              APF_Path_Planning_2023a_B.Delay3_j[0] =
                APF_Path_Planning_2023a_DW.Delay3_DSTATE_a[0];

              // Delay: '<S379>/Delay1'
              APF_Path_Planning_2023a_B.Delay1_o[0] =
                APF_Path_Planning_2023a_DW.Delay1_DSTATE_d[0];

              // Delay: '<S379>/Delay3'
              APF_Path_Planning_2023a_B.Delay3_j[1] =
                APF_Path_Planning_2023a_DW.Delay3_DSTATE_a[1];

              // Delay: '<S379>/Delay1'
              APF_Path_Planning_2023a_B.Delay1_o[1] =
                APF_Path_Planning_2023a_DW.Delay1_DSTATE_d[1];

              // Delay: '<S379>/Delay3'
              APF_Path_Planning_2023a_B.Delay3_j[2] =
                APF_Path_Planning_2023a_DW.Delay3_DSTATE_a[2];

              // Delay: '<S379>/Delay1'
              APF_Path_Planning_2023a_B.Delay1_o[2] =
                APF_Path_Planning_2023a_DW.Delay1_DSTATE_d[2];
            }

            // MATLAB Function: '<S383>/MATLAB Function1' incorporates:
            //   Delay: '<S383>/Delay3'
            //   MATLAB Function: '<S376>/MATLAB Function1'

            APF_Path_Planning_2023a_B.rtb_y_g = (1.0 -
              APF_Path_Planning_2023a_P.RMSprop_gamma) *
              APF_Path_Planning_2023a_B.Derivative2 +
              APF_Path_Planning_2023a_P.RMSprop_gamma *
              APF_Path_Planning_2023a_B.Delay3_f[0];
            APF_Path_Planning_2023a_B.Eg[0] = APF_Path_Planning_2023a_B.rtb_y_g;

            // MATLAB Function: '<S383>/MATLAB Function1' incorporates:
            //   Delay: '<S383>/Delay3'
            //   SignalConversion generated from: '<S391>/ SFunction '

            APF_Path_Planning_2023a_B.r_co[0] =
              APF_Path_Planning_2023a_B.DataStoreRead_k -
              APF_Path_Planning_2023a_P.RMSprop_eta / sqrt
              (APF_Path_Planning_2023a_B.rtb_y_g +
               APF_Path_Planning_2023a_P.RMSprop_epsilon) *
              APF_Path_Planning_2023a_B.phi_tot_grad[0];
            APF_Path_Planning_2023a_B.rtb_y_g = (1.0 -
              APF_Path_Planning_2023a_P.RMSprop_gamma) *
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 +
              APF_Path_Planning_2023a_P.RMSprop_gamma *
              APF_Path_Planning_2023a_B.Delay3_f[1];
            APF_Path_Planning_2023a_B.Eg[1] = APF_Path_Planning_2023a_B.rtb_y_g;

            // MATLAB Function: '<S383>/MATLAB Function1' incorporates:
            //   Delay: '<S383>/Delay3'
            //   SignalConversion generated from: '<S391>/ SFunction '

            APF_Path_Planning_2023a_B.r_co[1] =
              APF_Path_Planning_2023a_B.DataStoreRead2_j -
              APF_Path_Planning_2023a_P.RMSprop_eta / sqrt
              (APF_Path_Planning_2023a_B.rtb_y_g +
               APF_Path_Planning_2023a_P.RMSprop_epsilon) *
              APF_Path_Planning_2023a_B.phi_tot_grad[1];
            APF_Path_Planning_2023a_B.rtb_y_g = (1.0 -
              APF_Path_Planning_2023a_P.RMSprop_gamma) *
              APF_Path_Planning_2023a_B.rtb_path_o_idx_2 +
              APF_Path_Planning_2023a_P.RMSprop_gamma *
              APF_Path_Planning_2023a_B.Delay3_f[2];
            APF_Path_Planning_2023a_B.Eg[2] = APF_Path_Planning_2023a_B.rtb_y_g;

            // MATLAB Function: '<S379>/MATLAB Function1' incorporates:
            //   Clock: '<S379>/Clock'
            //   Delay: '<S379>/Delay3'
            //   Delay: '<S383>/Delay3'
            //   MATLAB Function: '<S383>/MATLAB Function1'

            APF_Path_Planning_2023a_B.rtb_path_o_idx_0 =
              APF_Path_Planning_2023a_M->Timing.t[0] / 0.1 + 1.0;
            APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp =
              APF_Path_Planning_2_rt_powd_snf
              (APF_Path_Planning_2023a_P.adam_beta_2,
               APF_Path_Planning_2023a_B.rtb_path_o_idx_0);
            APF_Path_Planning_2023a_B.t = 1.0 - APF_Path_Planning_2_rt_powd_snf
              (APF_Path_Planning_2023a_P.adam_beta_1,
               APF_Path_Planning_2023a_B.rtb_path_o_idx_0);
            APF_Path_Planning_2023a_B.rtb_path_o_idx_0 = (1.0 -
              APF_Path_Planning_2023a_P.adam_beta_1) *
              APF_Path_Planning_2023a_B.phi_tot_grad[0] +
              APF_Path_Planning_2023a_P.adam_beta_1 *
              APF_Path_Planning_2023a_B.Delay3_j[0];

            // End of Outputs for SubSystem: '<S350>/APF'
            APF_Path_Planning_2023a_B.m[0] =
              APF_Path_Planning_2023a_B.rtb_path_o_idx_0;

            // Outputs for IfAction SubSystem: '<S350>/APF' incorporates:
            //   ActionPort: '<S368>/Action Port'

            // MATLAB Function: '<S379>/MATLAB Function1' incorporates:
            //   Delay: '<S379>/Delay1'

            APF_Path_Planning_2023a_B.Derivative2 = (1.0 -
              APF_Path_Planning_2023a_P.adam_beta_2) *
              APF_Path_Planning_2023a_B.Derivative2 +
              APF_Path_Planning_2023a_P.adam_beta_2 *
              APF_Path_Planning_2023a_B.Delay1_o[0];
            APF_Path_Planning_2023a_B.v[0] =
              APF_Path_Planning_2023a_B.Derivative2;

            // MATLAB Function: '<S379>/MATLAB Function1' incorporates:
            //   Delay: '<S379>/Delay1'
            //   Delay: '<S379>/Delay3'
            //   SignalConversion generated from: '<S387>/ SFunction '

            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
              APF_Path_Planning_2023a_B.DataStoreRead_k -
              APF_Path_Planning_2023a_P.adam_eta / (sqrt
              (APF_Path_Planning_2023a_B.Derivative2 / (1.0 -
              APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp)) +
              APF_Path_Planning_2023a_P.adam_epsilon) *
              (APF_Path_Planning_2023a_B.rtb_path_o_idx_0 /
               APF_Path_Planning_2023a_B.t);
            APF_Path_Planning_2023a_B.rtb_path_o_idx_0 = (1.0 -
              APF_Path_Planning_2023a_P.adam_beta_1) *
              APF_Path_Planning_2023a_B.phi_tot_grad[1] +
              APF_Path_Planning_2023a_P.adam_beta_1 *
              APF_Path_Planning_2023a_B.Delay3_j[1];

            // End of Outputs for SubSystem: '<S350>/APF'
            APF_Path_Planning_2023a_B.m[1] =
              APF_Path_Planning_2023a_B.rtb_path_o_idx_0;

            // Outputs for IfAction SubSystem: '<S350>/APF' incorporates:
            //   ActionPort: '<S368>/Action Port'

            // MATLAB Function: '<S379>/MATLAB Function1' incorporates:
            //   Delay: '<S379>/Delay1'

            APF_Path_Planning_2023a_B.Derivative2 = (1.0 -
              APF_Path_Planning_2023a_P.adam_beta_2) *
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 +
              APF_Path_Planning_2023a_P.adam_beta_2 *
              APF_Path_Planning_2023a_B.Delay1_o[1];
            APF_Path_Planning_2023a_B.v[1] =
              APF_Path_Planning_2023a_B.Derivative2;

            // MATLAB Function: '<S379>/MATLAB Function1' incorporates:
            //   Delay: '<S379>/Delay1'
            //   Delay: '<S379>/Delay3'
            //   SignalConversion generated from: '<S387>/ SFunction '

            APF_Path_Planning_2023a_B.rtb_path_b_idx_1 =
              APF_Path_Planning_2023a_B.DataStoreRead2_j -
              APF_Path_Planning_2023a_P.adam_eta / (sqrt
              (APF_Path_Planning_2023a_B.Derivative2 / (1.0 -
              APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp)) +
              APF_Path_Planning_2023a_P.adam_epsilon) *
              (APF_Path_Planning_2023a_B.rtb_path_o_idx_0 /
               APF_Path_Planning_2023a_B.t);
            APF_Path_Planning_2023a_B.rtb_path_o_idx_0 = (1.0 -
              APF_Path_Planning_2023a_P.adam_beta_1) *
              APF_Path_Planning_2023a_B.phi_tot_grad[2] +
              APF_Path_Planning_2023a_P.adam_beta_1 *
              APF_Path_Planning_2023a_B.Delay3_j[2];

            // End of Outputs for SubSystem: '<S350>/APF'
            APF_Path_Planning_2023a_B.m[2] =
              APF_Path_Planning_2023a_B.rtb_path_o_idx_0;

            // Outputs for IfAction SubSystem: '<S350>/APF' incorporates:
            //   ActionPort: '<S368>/Action Port'

            // MATLAB Function: '<S379>/MATLAB Function1' incorporates:
            //   Delay: '<S379>/Delay1'

            APF_Path_Planning_2023a_B.Derivative2 = (1.0 -
              APF_Path_Planning_2023a_P.adam_beta_2) *
              APF_Path_Planning_2023a_B.rtb_path_o_idx_2 +
              APF_Path_Planning_2023a_P.adam_beta_2 *
              APF_Path_Planning_2023a_B.Delay1_o[2];
            APF_Path_Planning_2023a_B.v[2] =
              APF_Path_Planning_2023a_B.Derivative2;
            if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
              // Delay: '<S378>/Delay3'
              APF_Path_Planning_2023a_B.Delay3_i[0] =
                APF_Path_Planning_2023a_DW.Delay3_DSTATE_j[0];
              APF_Path_Planning_2023a_B.Delay3_i[1] =
                APF_Path_Planning_2023a_DW.Delay3_DSTATE_j[1];
              APF_Path_Planning_2023a_B.Delay3_i[2] =
                APF_Path_Planning_2023a_DW.Delay3_DSTATE_j[2];

              // Delay: '<S378>/Delay1'
              APF_Path_Planning_2023a_B.Delay1_m =
                APF_Path_Planning_2023a_DW.Delay1_DSTATE_l;
            }

            // MATLAB Function: '<S378>/MATLAB Function1' incorporates:
            //   Clock: '<S378>/Clock'
            //   Constant: '<S378>/Constant'
            //   Delay: '<S378>/Delay3'
            //   Delay: '<S379>/Delay1'
            //   MATLAB Function: '<S379>/MATLAB Function1'
            //   Sum: '<S378>/Sum'

            APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 = 0.0;
            APF_Path_Planning_2023a_B.m_b[0] = (1.0 -
              APF_Path_Planning_2023a_P.adamax_beta_1) *
              APF_Path_Planning_2023a_B.phi_tot_grad[0] +
              APF_Path_Planning_2023a_P.adamax_beta_1 *
              APF_Path_Planning_2023a_B.Delay3_i[0];
            APF_Path_Planning_2023a_B.rtb_path_o_idx_2 = fabs
              (APF_Path_Planning_2023a_B.phi_tot_grad[0]);
            APF_Path_Planning_2023a_B.p = rtIsNaN
              (APF_Path_Planning_2023a_B.rtb_path_o_idx_2);
            if (APF_Path_Planning_2023a_B.p) {
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 = (rtNaN);
            } else if (APF_Path_Planning_2023a_B.rtb_path_o_idx_2 > 0.0) {
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 =
                APF_Path_Planning_2023a_B.rtb_path_o_idx_2;
            }

            APF_Path_Planning_2023a_B.m_b[1] = (1.0 -
              APF_Path_Planning_2023a_P.adamax_beta_1) *
              APF_Path_Planning_2023a_B.phi_tot_grad[1] +
              APF_Path_Planning_2023a_P.adamax_beta_1 *
              APF_Path_Planning_2023a_B.Delay3_i[1];
            APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0 = fabs
              (APF_Path_Planning_2023a_B.phi_tot_grad[1]);
            APF_Path_Planning_2023a_B.rEQ0 = rtIsNaN
              (APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0);
            if (APF_Path_Planning_2023a_B.rEQ0) {
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 = (rtNaN);
            } else if (APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0 >
                       APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1) {
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 =
                APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0;
            }

            APF_Path_Planning_2023a_B.m_b[2] = (1.0 -
              APF_Path_Planning_2023a_P.adamax_beta_1) *
              APF_Path_Planning_2023a_B.phi_tot_grad[2] +
              APF_Path_Planning_2023a_P.adamax_beta_1 *
              APF_Path_Planning_2023a_B.Delay3_i[2];
            APF_Path_Planning_2023a_B.link2_com_y = fabs
              (APF_Path_Planning_2023a_B.phi_tot_grad[2]);
            APF_Path_Planning_2023a_B.b_ja = rtIsNaN
              (APF_Path_Planning_2023a_B.link2_com_y);
            if (APF_Path_Planning_2023a_B.b_ja) {
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 = (rtNaN);
            } else if (APF_Path_Planning_2023a_B.link2_com_y >
                       APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1) {
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 =
                APF_Path_Planning_2023a_B.link2_com_y;
            }

            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 =
              APF_Path_Planning_2023a_P.adamax_beta_2 *
              APF_Path_Planning_2023a_B.Delay1_m;
            APF_Path_Planning_2023a_B.v_d = (1.0 -
              APF_Path_Planning_2023a_P.adamax_beta_2) *
              APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 +
              APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
            APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 =
              APF_Path_Planning_2_rt_powd_snf
              (APF_Path_Planning_2023a_P.adamax_beta_1,
               (APF_Path_Planning_2023a_M->Timing.t[0] -
                APF_Path_Planning_2023a_P.Phase2_End) / 0.1 + 1.0);
            if ((APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 >=
                 APF_Path_Planning_2023a_B.rtb_path_o_idx_2) ||
                APF_Path_Planning_2023a_B.p) {
              APF_Path_Planning_2023a_B.rtb_path_o_idx_2 =
                APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
            }

            if ((APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 >=
                 APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0) ||
                APF_Path_Planning_2023a_B.rEQ0) {
              APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0 =
                APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
            }

            // MultiPortSwitch: '<S375>/Multiport Switch' incorporates:
            //   Constant: '<S375>/Constant3'

            switch (static_cast<int32_T>(APF_Path_Planning_2023a_P.Method)) {
             case 1:
              // MultiPortSwitch: '<S375>/Multiport Switch' incorporates:
              //   MATLAB Function: '<S372>/MATLAB Function'
              //   MATLAB Function: '<S380>/Batch'
              //   SignalConversion generated from: '<S374>/ SFunction '

              APF_Path_Planning_2023a_B.MultiportSwitch[0] =
                APF_Path_Planning_2023a_B.DataStoreRead_k -
                APF_Path_Planning_2023a_P.batch_eta *
                APF_Path_Planning_2023a_B.phi_tot_grad[0];
              APF_Path_Planning_2023a_B.MultiportSwitch[1] =
                APF_Path_Planning_2023a_B.DataStoreRead2_j -
                APF_Path_Planning_2023a_P.batch_eta *
                APF_Path_Planning_2023a_B.phi_tot_grad[1];
              APF_Path_Planning_2023a_B.MultiportSwitch[2] =
                APF_Path_Planning_2023a_B.DataStoreRead3_l -
                APF_Path_Planning_2023a_P.batch_eta *
                APF_Path_Planning_2023a_B.phi_tot_grad[2];
              break;

             case 2:
              // MultiPortSwitch: '<S375>/Multiport Switch' incorporates:
              //   MATLAB Function: '<S372>/MATLAB Function'
              //   MATLAB Function: '<S381>/Momentum'
              //   SignalConversion generated from: '<S374>/ SFunction '

              APF_Path_Planning_2023a_B.MultiportSwitch[0] =
                APF_Path_Planning_2023a_B.DataStoreRead_k +
                APF_Path_Planning_2023a_B.Sum3[0];
              APF_Path_Planning_2023a_B.MultiportSwitch[1] =
                APF_Path_Planning_2023a_B.DataStoreRead2_j +
                APF_Path_Planning_2023a_B.Sum3[1];
              APF_Path_Planning_2023a_B.MultiportSwitch[2] =
                APF_Path_Planning_2023a_B.DataStoreRead3_l +
                APF_Path_Planning_2023a_B.Sum3[2];
              break;

             case 3:
              // MultiPortSwitch: '<S375>/Multiport Switch' incorporates:
              //   MATLAB Function: '<S372>/MATLAB Function'
              //   MATLAB Function: '<S382>/MATLAB Function1'
              //   SignalConversion generated from: '<S374>/ SFunction '

              APF_Path_Planning_2023a_B.MultiportSwitch[0] =
                APF_Path_Planning_2023a_B.DataStoreRead_k +
                APF_Path_Planning_2023a_B.Sum_n[0];
              APF_Path_Planning_2023a_B.MultiportSwitch[1] =
                APF_Path_Planning_2023a_B.DataStoreRead2_j +
                APF_Path_Planning_2023a_B.Sum_n[1];
              APF_Path_Planning_2023a_B.MultiportSwitch[2] =
                APF_Path_Planning_2023a_B.DataStoreRead3_l +
                APF_Path_Planning_2023a_B.Sum_n[2];
              break;

             case 4:
              break;

             case 5:
              // MultiPortSwitch: '<S375>/Multiport Switch' incorporates:
              //   MATLAB Function: '<S376>/MATLAB Function1'
              //   SignalConversion generated from: '<S384>/ SFunction '

              APF_Path_Planning_2023a_B.MultiportSwitch[0] =
                APF_Path_Planning_2023a_B.varargout_1;
              APF_Path_Planning_2023a_B.MultiportSwitch[1] =
                APF_Path_Planning_2023a_B.q;
              APF_Path_Planning_2023a_B.MultiportSwitch[2] =
                APF_Path_Planning_2023a_B.DataStoreRead3_l -
                APF_Path_Planning_2023a_B.RED_Tz_RW;
              break;

             case 6:
              // MultiPortSwitch: '<S375>/Multiport Switch' incorporates:
              //   MATLAB Function: '<S383>/MATLAB Function1'
              //   SignalConversion generated from: '<S391>/ SFunction '

              APF_Path_Planning_2023a_B.MultiportSwitch[0] =
                APF_Path_Planning_2023a_B.r_co[0];
              APF_Path_Planning_2023a_B.MultiportSwitch[1] =
                APF_Path_Planning_2023a_B.r_co[1];
              APF_Path_Planning_2023a_B.MultiportSwitch[2] =
                APF_Path_Planning_2023a_B.DataStoreRead3_l -
                APF_Path_Planning_2023a_P.RMSprop_eta / sqrt
                (APF_Path_Planning_2023a_B.rtb_y_g +
                 APF_Path_Planning_2023a_P.RMSprop_epsilon) *
                APF_Path_Planning_2023a_B.phi_tot_grad[2];
              break;

             case 7:
              // MultiPortSwitch: '<S375>/Multiport Switch' incorporates:
              //   MATLAB Function: '<S379>/MATLAB Function1'
              //   SignalConversion generated from: '<S387>/ SFunction '

              APF_Path_Planning_2023a_B.MultiportSwitch[0] =
                APF_Path_Planning_2023a_B.rtb_path_b_idx_0;
              APF_Path_Planning_2023a_B.MultiportSwitch[1] =
                APF_Path_Planning_2023a_B.rtb_path_b_idx_1;
              APF_Path_Planning_2023a_B.MultiportSwitch[2] =
                APF_Path_Planning_2023a_B.DataStoreRead3_l -
                APF_Path_Planning_2023a_P.adam_eta / (sqrt
                (APF_Path_Planning_2023a_B.Derivative2 / (1.0 -
                APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp)) +
                APF_Path_Planning_2023a_P.adam_epsilon) *
                (APF_Path_Planning_2023a_B.rtb_path_o_idx_0 /
                 APF_Path_Planning_2023a_B.t);
              break;

             default:
              // MultiPortSwitch: '<S375>/Multiport Switch' incorporates:
              //   MATLAB Function: '<S378>/MATLAB Function1'
              //   SignalConversion generated from: '<S386>/ SFunction '

              APF_Path_Planning_2023a_B.MultiportSwitch[0] =
                APF_Path_Planning_2023a_B.DataStoreRead_k -
                APF_Path_Planning_2023a_B.m_b[0] / (1.0 -
                APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1) *
                (APF_Path_Planning_2023a_P.adamax_eta /
                 APF_Path_Planning_2023a_B.rtb_path_o_idx_2);
              APF_Path_Planning_2023a_B.MultiportSwitch[1] =
                APF_Path_Planning_2023a_B.DataStoreRead2_j -
                APF_Path_Planning_2023a_B.m_b[1] / (1.0 -
                APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1) *
                (APF_Path_Planning_2023a_P.adamax_eta /
                 APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0);

              // MATLAB Function: '<S378>/MATLAB Function1'
              if ((APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 >=
                   APF_Path_Planning_2023a_B.link2_com_y) ||
                  APF_Path_Planning_2023a_B.b_ja) {
                APF_Path_Planning_2023a_B.link2_com_y =
                  APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
              }

              // MultiPortSwitch: '<S375>/Multiport Switch' incorporates:
              //   MATLAB Function: '<S378>/MATLAB Function1'
              //   SignalConversion generated from: '<S386>/ SFunction '

              APF_Path_Planning_2023a_B.MultiportSwitch[2] =
                APF_Path_Planning_2023a_B.DataStoreRead3_l -
                APF_Path_Planning_2023a_B.m_b[2] / (1.0 -
                APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1) *
                (APF_Path_Planning_2023a_P.adamax_eta /
                 APF_Path_Planning_2023a_B.link2_com_y);
              break;
            }

            // End of MultiPortSwitch: '<S375>/Multiport Switch'

            // DataStoreWrite: '<S372>/Data Store Write'
            APF_Path_Planning_2023a_DW.Command_Px =
              APF_Path_Planning_2023a_B.MultiportSwitch[0];

            // DataStoreWrite: '<S372>/Data Store Write1'
            APF_Path_Planning_2023a_DW.Command_Py =
              APF_Path_Planning_2023a_B.MultiportSwitch[1];

            // DataStoreWrite: '<S372>/Data Store Write2'
            APF_Path_Planning_2023a_DW.Command_Rz =
              APF_Path_Planning_2023a_B.MultiportSwitch[2];

            // Sum: '<S381>/Sum3' incorporates:
            //   Constant: '<S381>/Constant'

            APF_Path_Planning_2023a_B.Sum3[0] +=
              APF_Path_Planning_2023a_P.Constant_Value_j[0];

            // Sum: '<S382>/Sum' incorporates:
            //   Constant: '<S382>/Constant1'

            APF_Path_Planning_2023a_B.Sum_n[0] +=
              APF_Path_Planning_2023a_P.Constant1_Value[0];

            // Sum: '<S381>/Sum3' incorporates:
            //   Constant: '<S381>/Constant'

            APF_Path_Planning_2023a_B.Sum3[1] +=
              APF_Path_Planning_2023a_P.Constant_Value_j[1];

            // Sum: '<S382>/Sum' incorporates:
            //   Constant: '<S382>/Constant1'

            APF_Path_Planning_2023a_B.Sum_n[1] +=
              APF_Path_Planning_2023a_P.Constant1_Value[1];

            // Sum: '<S381>/Sum3' incorporates:
            //   Constant: '<S381>/Constant'

            APF_Path_Planning_2023a_B.Sum3[2] +=
              APF_Path_Planning_2023a_P.Constant_Value_j[2];

            // Sum: '<S382>/Sum' incorporates:
            //   Constant: '<S382>/Constant1'

            APF_Path_Planning_2023a_B.Sum_n[2] +=
              APF_Path_Planning_2023a_P.Constant1_Value[2];

            // MATLAB Function: '<S368>/Looking Angle' incorporates:
            //   MATLAB Function: '<S372>/MATLAB Function'
            //   SignalConversion generated from: '<S374>/ SFunction '

            APF_Path_Planning_2023a_B.rtb_Oy_kp_n[0] =
              APF_Path_Planning_2023a_B.DataStoreRead_k -
              (APF_Path_Planning_2023a_P.r_off * cos
               (APF_Path_Planning_2023a_B.DataStoreRead4) +
               APF_Path_Planning_2023a_B.DataStoreRead6);
            APF_Path_Planning_2023a_B.rtb_Oy_kp_n[1] =
              APF_Path_Planning_2023a_B.DataStoreRead2_j -
              (APF_Path_Planning_2023a_P.r_off * sin
               (APF_Path_Planning_2023a_B.DataStoreRead4) +
               APF_Path_Planning_2023a_B.DataStoreRead5);

            // Switch: '<S368>/Switch' incorporates:
            //   Constant: '<S368>/Constant2'

            if (APF_Path_Planning_2023a_P.Att_Mode >
                APF_Path_Planning_2023a_P.Switch_Threshold_d) {
              // Switch: '<S368>/Switch'
              APF_Path_Planning_2023a_B.Switch =
                APF_Path_Planning_2023a_B.MultiportSwitch[2];
            } else {
              // Switch: '<S368>/Switch' incorporates:
              //   MATLAB Function: '<S368>/Looking Angle'

              APF_Path_Planning_2023a_B.Switch = APF_Path_Planning_rt_atan2d_snf
                (APF_Path_Planning_2023a_B.rtb_Oy_kp_n[1],
                 APF_Path_Planning_2023a_B.rtb_Oy_kp_n[0]) + 3.1415926535897931;
            }

            // End of Switch: '<S368>/Switch'
            // End of Outputs for SubSystem: '<S350>/APF'
          }

          // End of If: '<S350>/If'

          // MultiPortSwitch: '<S350>/Multiport Switch' incorporates:
          //   Constant: '<S369>/Constant'

          switch (static_cast<int32_T>
                  (APF_Path_Planning_2023a_P.Constant_Value_a)) {
           case 1:
            // MultiPortSwitch: '<S350>/Multiport Switch'
            APF_Path_Planning_2023a_B.phi_tot_grad[0] =
              APF_Path_Planning_2023a_B.OutportBufferForDesiredStates[0];
            APF_Path_Planning_2023a_B.phi_tot_grad[1] =
              APF_Path_Planning_2023a_B.OutportBufferForDesiredStates[1];
            APF_Path_Planning_2023a_B.phi_tot_grad[2] =
              APF_Path_Planning_2023a_B.OutportBufferForDesiredStates[2];
            break;

           case 2:
            // MultiPortSwitch: '<S350>/Multiport Switch'
            APF_Path_Planning_2023a_B.phi_tot_grad[0] =
              APF_Path_Planning_2023a_B.OutportBufferForDesiredStates_c[0];
            APF_Path_Planning_2023a_B.phi_tot_grad[1] =
              APF_Path_Planning_2023a_B.OutportBufferForDesiredStates_c[1];
            APF_Path_Planning_2023a_B.phi_tot_grad[2] =
              APF_Path_Planning_2023a_B.OutportBufferForDesiredStates_c[2];
            break;

           default:
            // MultiPortSwitch: '<S350>/Multiport Switch'
            APF_Path_Planning_2023a_B.phi_tot_grad[0] =
              APF_Path_Planning_2023a_B.MultiportSwitch[0];
            APF_Path_Planning_2023a_B.phi_tot_grad[1] =
              APF_Path_Planning_2023a_B.MultiportSwitch[1];
            APF_Path_Planning_2023a_B.phi_tot_grad[2] =
              APF_Path_Planning_2023a_B.Switch;
            break;
          }

          // End of MultiPortSwitch: '<S350>/Multiport Switch'

          // Sum: '<S349>/Sum'
          APF_Path_Planning_2023a_B.Sum =
            APF_Path_Planning_2023a_B.phi_tot_grad[0] -
            APF_Path_Planning_2023a_B.DataStoreRead_k;

          // Sum: '<S349>/Sum1'
          APF_Path_Planning_2023a_B.Sum1 =
            APF_Path_Planning_2023a_B.phi_tot_grad[1] -
            APF_Path_Planning_2023a_B.DataStoreRead2_j;

          // MATLAB Function: '<S353>/MATLAB Function2'
          APF_Path_Planni_MATLABFunction2
            (APF_Path_Planning_2023a_B.phi_tot_grad[2],
             APF_Path_Planning_2023a_B.rtb_Oy_kp_n,
             APF_Path_Planning_2023a_B.rtb_Ox_pc_l);

          // MATLAB Function: '<S353>/MATLAB Function3'
          APF_Path_Planni_MATLABFunction3
            (APF_Path_Planning_2023a_B.DataStoreRead3_l,
             APF_Path_Planning_2023a_B.rtb_Ox_pr_p);

          // Sum: '<S353>/Subtract2'
          APF_Path_Planning_2023a_B.rtb_Ox_pc_l[0] -=
            APF_Path_Planning_2023a_B.rtb_Ox_pr_p[0];
          APF_Path_Planning_2023a_B.rtb_Ox_pc_l[1] -=
            APF_Path_Planning_2023a_B.rtb_Ox_pr_p[1];

          // MATLAB Function: '<S353>/MATLAB Function4'
          APF_Path_Planni_MATLABFunction4(APF_Path_Planning_2023a_B.rtb_Oy_kp_n,
            APF_Path_Planning_2023a_B.rtb_Ox_pc_l,
            &APF_Path_Planning_2023a_B.e_out);

          // If: '<S349>/If2' incorporates:
          //   Constant: '<S369>/Constant'

          APF_Path_Planning_2023a_B.rtAction = -1;
          if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo))
          {
            if (APF_Path_Planning_2023a_P.Constant_Value_a == 1.0) {
              APF_Path_Planning_2023a_B.rtAction = 0;
            }

            APF_Path_Planning_2023a_DW.If2_ActiveSubsystem_m =
              APF_Path_Planning_2023a_B.rtAction;
          } else {
            APF_Path_Planning_2023a_B.rtAction =
              APF_Path_Planning_2023a_DW.If2_ActiveSubsystem_m;
          }

          if (APF_Path_Planning_2023a_B.rtAction == 0) {
            // Outputs for IfAction SubSystem: '<S349>/Target Finder' incorporates:
            //   ActionPort: '<S355>/Action Port'

            APF_Path_Planning_TargetTracker(APF_Path_Planning_2023a_B.Sum,
              APF_Path_Planning_2023a_B.Sum1, APF_Path_Planning_2023a_B.e_out,
              APF_Path_Planning_2023a_B.u,
              &APF_Path_Planning_2023a_P.TargetFinder,
              &APF_Path_Planning_2023a_X.TargetFinder);

            // End of Outputs for SubSystem: '<S349>/Target Finder'
          }

          // End of If: '<S349>/If2'

          // If: '<S349>/If1' incorporates:
          //   Constant: '<S369>/Constant'

          APF_Path_Planning_2023a_B.rtAction = -1;
          if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo))
          {
            if (APF_Path_Planning_2023a_P.Constant_Value_a == 2.0) {
              APF_Path_Planning_2023a_B.rtAction = 0;
            }

            APF_Path_Planning_2023a_DW.If1_ActiveSubsystem_a =
              APF_Path_Planning_2023a_B.rtAction;
          } else {
            APF_Path_Planning_2023a_B.rtAction =
              APF_Path_Planning_2023a_DW.If1_ActiveSubsystem_a;
          }

          if (APF_Path_Planning_2023a_B.rtAction == 0) {
            // Outputs for IfAction SubSystem: '<S349>/Target Tracker' incorporates:
            //   ActionPort: '<S356>/Action Port'

            APF_Path_Planning_TargetTracker(APF_Path_Planning_2023a_B.Sum,
              APF_Path_Planning_2023a_B.Sum1, APF_Path_Planning_2023a_B.e_out,
              APF_Path_Planning_2023a_B.u_l,
              &APF_Path_Planning_2023a_P.TargetTracker,
              &APF_Path_Planning_2023a_X.TargetTracker);

            // End of Outputs for SubSystem: '<S349>/Target Tracker'
          }

          // End of If: '<S349>/If1'

          // If: '<S349>/If' incorporates:
          //   Constant: '<S369>/Constant'

          APF_Path_Planning_2023a_B.rtAction = -1;
          if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo))
          {
            if (APF_Path_Planning_2023a_P.Constant_Value_a == 3.0) {
              APF_Path_Planning_2023a_B.rtAction = 0;
            }

            APF_Path_Planning_2023a_DW.If_ActiveSubsystem_m =
              APF_Path_Planning_2023a_B.rtAction;
          } else {
            APF_Path_Planning_2023a_B.rtAction =
              APF_Path_Planning_2023a_DW.If_ActiveSubsystem_m;
          }

          if (APF_Path_Planning_2023a_B.rtAction == 0) {
            // Outputs for IfAction SubSystem: '<S349>/If Action Subsystem' incorporates:
            //   ActionPort: '<S354>/Action Port'

            // Derivative: '<S360>/Derivative2'
            if ((APF_Path_Planning_2023a_DW.TimeStampA >=
                 APF_Path_Planning_2023a_M->Timing.t[0]) &&
                (APF_Path_Planning_2023a_DW.TimeStampB >=
                 APF_Path_Planning_2023a_M->Timing.t[0])) {
              APF_Path_Planning_2023a_B.Derivative2 = 0.0;
            } else {
              APF_Path_Planning_2023a_B.Derivative2 =
                APF_Path_Planning_2023a_DW.TimeStampA;
              lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeA;
              if (APF_Path_Planning_2023a_DW.TimeStampA <
                  APF_Path_Planning_2023a_DW.TimeStampB) {
                if (APF_Path_Planning_2023a_DW.TimeStampB <
                    APF_Path_Planning_2023a_M->Timing.t[0]) {
                  APF_Path_Planning_2023a_B.Derivative2 =
                    APF_Path_Planning_2023a_DW.TimeStampB;
                  lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeB;
                }
              } else if (APF_Path_Planning_2023a_DW.TimeStampA >=
                         APF_Path_Planning_2023a_M->Timing.t[0]) {
                APF_Path_Planning_2023a_B.Derivative2 =
                  APF_Path_Planning_2023a_DW.TimeStampB;
                lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeB;
              }

              APF_Path_Planning_2023a_B.Derivative2 =
                (APF_Path_Planning_2023a_B.Sum - *lastU) /
                (APF_Path_Planning_2023a_M->Timing.t[0] -
                 APF_Path_Planning_2023a_B.Derivative2);
            }

            // End of Derivative: '<S360>/Derivative2'
            if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
              // DiscreteIntegrator: '<S360>/Discrete-Time Integrator4'
              APF_Path_Planning_2023a_B.DiscreteTimeIntegrator4 =
                APF_Path_Planning_2023a_DW.DiscreteTimeIntegrator4_DSTATE;

              // DiscreteIntegrator: '<S360>/Discrete-Time Integrator5'
              APF_Path_Planning_2023a_B.DiscreteTimeIntegrator5 =
                APF_Path_Planning_2023a_DW.DiscreteTimeIntegrator5_DSTATE;
            }

            // MATLAB Function: '<S360>/Fx Gain Derivatives' incorporates:
            //   MATLAB Function: '<S360>/Fy Gain Derivatives'

            APF_Path_Planning_2023a_B.rtb_path_o_idx_2 =
              APF_Path_Planning_2023a_B.Derivative2 *
              APF_Path_Planning_2023a_B.Derivative2;
            APF_Path_Planning_2023a_B.varargout_1 =
              APF_Path_Planning_2023a_B.Sum * APF_Path_Planning_2023a_B.Sum;
            APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp =
              -APF_Path_Planning_2023a_P.lambda1 * APF_Path_Planning_2023a_P.p;
            APF_Path_Planning_2023a_B.rtb_path_o_idx_0 =
              APF_Path_Planning_2023a_P.p * APF_Path_Planning_2023a_P.lambda12 +
              APF_Path_Planning_2023a_P.lambda1;
            APF_Path_Planning_2023a_B.k1_dot_o =
              (APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp *
               APF_Path_Planning_2023a_B.varargout_1 -
               APF_Path_Planning_2023a_B.rtb_path_o_idx_0 *
               APF_Path_Planning_2023a_B.Sum *
               APF_Path_Planning_2023a_B.Derivative2) -
              APF_Path_Planning_2023a_B.rtb_path_o_idx_2 *
              APF_Path_Planning_2023a_P.lambda12;
            APF_Path_Planning_2023a_B.RED_Tz_RW =
              -APF_Path_Planning_2023a_P.lambda12 * APF_Path_Planning_2023a_P.p;
            APF_Path_Planning_2023a_B.rtb_y_g = APF_Path_Planning_2023a_P.p *
              APF_Path_Planning_2023a_P.lambda2 +
              APF_Path_Planning_2023a_P.lambda12;
            APF_Path_Planning_2023a_B.k2_dot_ch =
              (APF_Path_Planning_2023a_B.RED_Tz_RW *
               APF_Path_Planning_2023a_B.varargout_1 -
               APF_Path_Planning_2023a_B.rtb_y_g * APF_Path_Planning_2023a_B.Sum
               * APF_Path_Planning_2023a_B.Derivative2) -
              APF_Path_Planning_2023a_B.rtb_path_o_idx_2 *
              APF_Path_Planning_2023a_P.lambda2;

            // Sum: '<S360>/u_x' incorporates:
            //   Product: '<S360>/k_1*q_1_x'
            //   Product: '<S360>/k_2*q2_x'

            APF_Path_Planning_2023a_B.u_x =
              APF_Path_Planning_2023a_B.Derivative2 *
              APF_Path_Planning_2023a_B.DiscreteTimeIntegrator4 +
              APF_Path_Planning_2023a_B.DiscreteTimeIntegrator5 *
              APF_Path_Planning_2023a_B.Sum;

            // Derivative: '<S360>/Derivative1'
            if ((APF_Path_Planning_2023a_DW.TimeStampA_i >=
                 APF_Path_Planning_2023a_M->Timing.t[0]) &&
                (APF_Path_Planning_2023a_DW.TimeStampB_p >=
                 APF_Path_Planning_2023a_M->Timing.t[0])) {
              APF_Path_Planning_2023a_B.Derivative2 = 0.0;
            } else {
              APF_Path_Planning_2023a_B.Derivative2 =
                APF_Path_Planning_2023a_DW.TimeStampA_i;
              lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeA_h;
              if (APF_Path_Planning_2023a_DW.TimeStampA_i <
                  APF_Path_Planning_2023a_DW.TimeStampB_p) {
                if (APF_Path_Planning_2023a_DW.TimeStampB_p <
                    APF_Path_Planning_2023a_M->Timing.t[0]) {
                  APF_Path_Planning_2023a_B.Derivative2 =
                    APF_Path_Planning_2023a_DW.TimeStampB_p;
                  lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeB_o;
                }
              } else if (APF_Path_Planning_2023a_DW.TimeStampA_i >=
                         APF_Path_Planning_2023a_M->Timing.t[0]) {
                APF_Path_Planning_2023a_B.Derivative2 =
                  APF_Path_Planning_2023a_DW.TimeStampB_p;
                lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeB_o;
              }

              APF_Path_Planning_2023a_B.Derivative2 =
                (APF_Path_Planning_2023a_B.Sum1 - *lastU) /
                (APF_Path_Planning_2023a_M->Timing.t[0] -
                 APF_Path_Planning_2023a_B.Derivative2);
            }

            // End of Derivative: '<S360>/Derivative1'
            if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
              // DiscreteIntegrator: '<S360>/Discrete-Time Integrator2'
              APF_Path_Planning_2023a_B.DiscreteTimeIntegrator2 =
                APF_Path_Planning_2023a_DW.DiscreteTimeIntegrator2_DSTATE;

              // DiscreteIntegrator: '<S360>/Discrete-Time Integrator3'
              APF_Path_Planning_2023a_B.DiscreteTimeIntegrator3 =
                APF_Path_Planning_2023a_DW.DiscreteTimeIntegrator3_DSTATE;

              // DiscreteIntegrator: '<S360>/Discrete-Time Integrator1'
              APF_Path_Planning_2023a_B.DiscreteTimeIntegrator1 =
                APF_Path_Planning_2023a_DW.DiscreteTimeIntegrator1_DSTATE;

              // DiscreteIntegrator: '<S360>/Discrete-Time Integrator'
              APF_Path_Planning_2023a_B.DiscreteTimeIntegrator =
                APF_Path_Planning_2023a_DW.DiscreteTimeIntegrator_DSTATE;
            }

            // MATLAB Function: '<S360>/Fy Gain Derivatives'
            APF_Path_Planning_2023a_B.rtb_path_o_idx_2 =
              APF_Path_Planning_2023a_B.Derivative2 *
              APF_Path_Planning_2023a_B.Derivative2;
            APF_Path_Planning_2023a_B.varargout_1 =
              APF_Path_Planning_2023a_B.Sum1 * APF_Path_Planning_2023a_B.Sum1;
            APF_Path_Planning_2023a_B.k1_dot_g =
              (APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp *
               APF_Path_Planning_2023a_B.varargout_1 -
               APF_Path_Planning_2023a_B.rtb_path_o_idx_0 *
               APF_Path_Planning_2023a_B.Sum1 *
               APF_Path_Planning_2023a_B.Derivative2) -
              APF_Path_Planning_2023a_B.rtb_path_o_idx_2 *
              APF_Path_Planning_2023a_P.lambda12;
            APF_Path_Planning_2023a_B.k2_dot_c =
              (APF_Path_Planning_2023a_B.RED_Tz_RW *
               APF_Path_Planning_2023a_B.varargout_1 -
               APF_Path_Planning_2023a_B.rtb_y_g *
               APF_Path_Planning_2023a_B.Sum1 *
               APF_Path_Planning_2023a_B.Derivative2) -
              APF_Path_Planning_2023a_B.rtb_path_o_idx_2 *
              APF_Path_Planning_2023a_P.lambda2;

            // Sum: '<S360>/u_y' incorporates:
            //   Product: '<S360>/k_1*q_1_y'
            //   Product: '<S360>/k_2*q2_y'

            APF_Path_Planning_2023a_B.u_y =
              APF_Path_Planning_2023a_B.Derivative2 *
              APF_Path_Planning_2023a_B.DiscreteTimeIntegrator2 +
              APF_Path_Planning_2023a_B.DiscreteTimeIntegrator3 *
              APF_Path_Planning_2023a_B.Sum1;

            // Derivative: '<S360>/Derivative3'
            if ((APF_Path_Planning_2023a_DW.TimeStampA_h >=
                 APF_Path_Planning_2023a_M->Timing.t[0]) &&
                (APF_Path_Planning_2023a_DW.TimeStampB_e >=
                 APF_Path_Planning_2023a_M->Timing.t[0])) {
              APF_Path_Planning_2023a_B.RED_Tz_RW = 0.0;
            } else {
              APF_Path_Planning_2023a_B.Derivative2 =
                APF_Path_Planning_2023a_DW.TimeStampA_h;
              lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeA_c;
              if (APF_Path_Planning_2023a_DW.TimeStampA_h <
                  APF_Path_Planning_2023a_DW.TimeStampB_e) {
                if (APF_Path_Planning_2023a_DW.TimeStampB_e <
                    APF_Path_Planning_2023a_M->Timing.t[0]) {
                  APF_Path_Planning_2023a_B.Derivative2 =
                    APF_Path_Planning_2023a_DW.TimeStampB_e;
                  lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeB_f;
                }
              } else if (APF_Path_Planning_2023a_DW.TimeStampA_h >=
                         APF_Path_Planning_2023a_M->Timing.t[0]) {
                APF_Path_Planning_2023a_B.Derivative2 =
                  APF_Path_Planning_2023a_DW.TimeStampB_e;
                lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeB_f;
              }

              APF_Path_Planning_2023a_B.RED_Tz_RW =
                (APF_Path_Planning_2023a_B.e_out - *lastU) /
                (APF_Path_Planning_2023a_M->Timing.t[0] -
                 APF_Path_Planning_2023a_B.Derivative2);
            }

            // End of Derivative: '<S360>/Derivative3'

            // Sum: '<S360>/Add2' incorporates:
            //   Product: '<S360>/Product4'
            //   Product: '<S360>/Product5'

            APF_Path_Planning_2023a_B.Add2 = APF_Path_Planning_2023a_B.e_out *
              APF_Path_Planning_2023a_B.DiscreteTimeIntegrator1 +
              APF_Path_Planning_2023a_B.DiscreteTimeIntegrator *
              APF_Path_Planning_2023a_B.RED_Tz_RW;

            // MATLAB Function: '<S360>/Torque Gain Derivatives'
            APF_Path_Planning_2023a_B.rtb_y_g =
              APF_Path_Planning_2023a_B.RED_Tz_RW *
              APF_Path_Planning_2023a_B.RED_Tz_RW;
            APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp =
              APF_Path_Planning_2023a_B.e_out * APF_Path_Planning_2023a_B.e_out;
            APF_Path_Planning_2023a_B.k1_dot =
              (-APF_Path_Planning_2023a_P.lambda1_t *
               APF_Path_Planning_2023a_P.p_t *
               APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp -
               (APF_Path_Planning_2023a_P.p_t *
                APF_Path_Planning_2023a_P.lambda12_t +
                APF_Path_Planning_2023a_P.lambda1_t) *
               APF_Path_Planning_2023a_B.e_out *
               APF_Path_Planning_2023a_B.RED_Tz_RW) -
              APF_Path_Planning_2023a_B.rtb_y_g *
              APF_Path_Planning_2023a_P.lambda12_t;
            APF_Path_Planning_2023a_B.k2_dot =
              (-APF_Path_Planning_2023a_P.lambda12_t *
               APF_Path_Planning_2023a_P.p_t *
               APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp -
               (APF_Path_Planning_2023a_P.p_t *
                APF_Path_Planning_2023a_P.lambda2_t +
                APF_Path_Planning_2023a_P.lambda12_t) *
               APF_Path_Planning_2023a_B.e_out *
               APF_Path_Planning_2023a_B.RED_Tz_RW) -
              APF_Path_Planning_2023a_B.rtb_y_g *
              APF_Path_Planning_2023a_P.lambda2_t;

            // End of Outputs for SubSystem: '<S349>/If Action Subsystem'
          }

          // End of If: '<S349>/If'

          // MultiPortSwitch: '<S349>/Multiport Switch' incorporates:
          //   Constant: '<S369>/Constant'

          switch (static_cast<int32_T>
                  (APF_Path_Planning_2023a_P.Constant_Value_a)) {
           case 1:
            APF_Path_Planning_2023a_B.phi_tot_grad[0] =
              APF_Path_Planning_2023a_B.u[0];
            APF_Path_Planning_2023a_B.phi_tot_grad[1] =
              APF_Path_Planning_2023a_B.u[1];
            APF_Path_Planning_2023a_B.phi_tot_grad[2] =
              APF_Path_Planning_2023a_B.u[2];
            break;

           case 2:
            APF_Path_Planning_2023a_B.phi_tot_grad[0] =
              APF_Path_Planning_2023a_B.u_l[0];
            APF_Path_Planning_2023a_B.phi_tot_grad[1] =
              APF_Path_Planning_2023a_B.u_l[1];
            APF_Path_Planning_2023a_B.phi_tot_grad[2] =
              APF_Path_Planning_2023a_B.u_l[2];
            break;

           default:
            APF_Path_Planning_2023a_B.phi_tot_grad[0] =
              APF_Path_Planning_2023a_B.u_x;
            APF_Path_Planning_2023a_B.phi_tot_grad[1] =
              APF_Path_Planning_2023a_B.u_y;
            APF_Path_Planning_2023a_B.phi_tot_grad[2] =
              APF_Path_Planning_2023a_B.Add2;
            break;
          }

          // End of MultiPortSwitch: '<S349>/Multiport Switch'

          // DataStoreWrite: '<S247>/RED_Fx'
          APF_Path_Planning_2023a_DW.RED_Fx =
            APF_Path_Planning_2023a_B.phi_tot_grad[0];

          // DataStoreWrite: '<S247>/RED_Fy'
          APF_Path_Planning_2023a_DW.RED_Fy =
            APF_Path_Planning_2023a_B.phi_tot_grad[1];

          // DataStoreWrite: '<S247>/RED_Tz'
          APF_Path_Planning_2023a_DW.RED_Tz =
            APF_Path_Planning_2023a_B.phi_tot_grad[2];
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // DataStoreWrite: '<S347>/Data Store Write'
            APF_Path_Planning_2023a_DW.BLACK_Px_Est = 0.0;

            // DataStoreWrite: '<S347>/Data Store Write1'
            APF_Path_Planning_2023a_DW.BLACK_Py_Est = 0.0;

            // DataStoreWrite: '<S347>/Data Store Write2'
            APF_Path_Planning_2023a_DW.BLACK_Rz_Est = 0.0;

            // DataStoreWrite: '<S347>/Data Store Write3'
            APF_Path_Planning_2023a_DW.BLACK_Px_preKalm = 0.0;

            // DataStoreWrite: '<S347>/Data Store Write4'
            APF_Path_Planning_2023a_DW.BLACK_Py_preKalm = 0.0;

            // DataStoreWrite: '<S347>/Data Store Write5'
            APF_Path_Planning_2023a_DW.BLACK_Rz_preKalm = 0.0;

            // DataStoreWrite: '<S247>/Data Store Write3' incorporates:
            //   Constant: '<S247>/Puck State'

            APF_Path_Planning_2023a_DW.Float_State =
              APF_Path_Planning_2023a_P.PuckState_Value_a;

            // Delay: '<S369>/Delay'
            APF_Path_Planning_2023a_B.Delay =
              APF_Path_Planning_2023a_DW.Delay_DSTATE;
          }

          // Step: '<S347>/Step' incorporates:
          //   Step: '<S347>/Step1'
          //   Step: '<S347>/Step2'

          APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_M->Timing.t[0];
          if (APF_Path_Planning_2023a_B.t < APF_Path_Planning_2023a_P.Step_Time)
          {
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
              APF_Path_Planning_2023a_P.Step_Y0;
          } else {
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
              APF_Path_Planning_2023a_P.Step_YFinal;
          }

          // Step: '<S347>/Step1'
          if (APF_Path_Planning_2023a_B.t < APF_Path_Planning_2023a_P.Step1_Time)
          {
            APF_Path_Planning_2023a_B.t21_tmp =
              APF_Path_Planning_2023a_P.Step1_Y0;
          } else {
            APF_Path_Planning_2023a_B.t21_tmp =
              APF_Path_Planning_2023a_P.Step1_YFinal;
          }

          // Step: '<S347>/Step2'
          if (APF_Path_Planning_2023a_B.t < APF_Path_Planning_2023a_P.Step2_Time)
          {
            APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_P.Step2_Y0;
          } else {
            APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_P.Step2_YFinal;
          }

          // MATLAB Function: '<S369>/Switch logic' incorporates:
          //   Step: '<S347>/Step'
          //   Step: '<S347>/Step1'
          //   Step: '<S347>/Step2'
          //   Sum: '<S347>/Add'

          if ((APF_Path_Planning_2023a_B.rtb_path_b_idx_0 +
               APF_Path_Planning_2023a_B.t21_tmp) + APF_Path_Planning_2023a_B.t ==
              1.0) {
            APF_Path_Planning_2023a_B.k = 0.0;
          } else {
            APF_Path_Planning_2023a_B.k = APF_Path_Planning_2023a_B.Delay + 1.0;
          }

          // End of MATLAB Function: '<S369>/Switch logic'
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // If: '<S247>/If' incorporates:
            //   Constant: '<S247>/Constant3'

            APF_Path_Planning_2023a_B.rtAction = -1;
            if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo))
            {
              if ((APF_Path_Planning_2023a_P.platformSelection == 4.0) ||
                  (APF_Path_Planning_2023a_P.platformSelection == 5.0) ||
                  (APF_Path_Planning_2023a_P.platformSelection == 10.0) ||
                  (APF_Path_Planning_2023a_P.platformSelection == 11.0)) {
                APF_Path_Planning_2023a_B.rtAction = 0;
              }

              APF_Path_Planning_2023a_DW.If_ActiveSubsystem_l =
                APF_Path_Planning_2023a_B.rtAction;
            } else {
              APF_Path_Planning_2023a_B.rtAction =
                APF_Path_Planning_2023a_DW.If_ActiveSubsystem_l;
            }

            if (APF_Path_Planning_2023a_B.rtAction == 0) {
              // Outputs for IfAction SubSystem: '<S247>/RED+ARM' incorporates:
              //   ActionPort: '<S352>/Action Port'

              // If: '<S352>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' incorporates:
              //   DataStoreRead: '<S352>/Data Store Read1'

              if (APF_Path_Planning_2023a_DW.isSim == 1.0) {
                // Outputs for IfAction SubSystem: '<S352>/Simulated Position Controller' incorporates:
                //   ActionPort: '<S402>/Action Port'

                // DataStoreWrite: '<S352>/Data Store Write2' incorporates:
                //   Constant: '<S352>/Constant4'
                //   Constant: '<S352>/Constant5'
                //   Constant: '<S352>/Constant6'
                //   DataStoreWrite: '<S352>/Data Store Write'
                //   DataStoreWrite: '<S352>/Data Store Write1'

                APF_SimulatedPositionController
                  (APF_Path_Planning_2023a_P.Constant4_Value_k,
                   APF_Path_Planning_2023a_P.Constant5_Value,
                   APF_Path_Planning_2023a_P.Constant6_Value,
                   &APF_Path_Planning_2023a_DW.RED_Shoulder_Command,
                   &APF_Path_Planning_2023a_DW.RED_Elbow_Command,
                   &APF_Path_Planning_2023a_DW.RED_Wrist_Command,
                   &APF_Path_Planning_2023a_DW.RED_Rz_Elbow,
                   &APF_Path_Planning_2023a_DW.RED_Rz_Shoulder,
                   &APF_Path_Planning_2023a_DW.RED_Rz_Wrist,
                   &APF_Path_Planning_2023a_B.SimulatedPositionController,
                   &APF_Path_Planning_2023a_DW.SimulatedPositionController);

                // End of Outputs for SubSystem: '<S352>/Simulated Position Controller' 
              } else {
                // Outputs for IfAction SubSystem: '<S352>/Passthrough for Experiment' incorporates:
                //   ActionPort: '<S401>/Action Port'

                // DataStoreWrite: '<S352>/Data Store Write2' incorporates:
                //   Constant: '<S352>/Constant6'
                //   DataStoreWrite: '<S352>/Data Store Write'
                //   DataStoreWrite: '<S352>/Data Store Write1'

                APF_Pa_PassthroughforExperiment(0.0, 0.0,
                  APF_Path_Planning_2023a_P.Constant6_Value,
                  &APF_Path_Planning_2023a_DW.RED_Shoulder_Command,
                  &APF_Path_Planning_2023a_DW.RED_Elbow_Command,
                  &APF_Path_Planning_2023a_DW.RED_Wrist_Command);

                // End of Outputs for SubSystem: '<S352>/Passthrough for Experiment' 
              }

              // End of If: '<S352>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 

              // DataStoreWrite: '<S352>/Data Store Write3' incorporates:
              //   Constant: '<S352>/Constant7'

              APF_Path_Planning_2023a_DW.RED_ARM_Control_Mode =
                APF_Path_Planning_2023a_P.Constant7_Value;

              // End of Outputs for SubSystem: '<S247>/RED+ARM'
            }

            // End of If: '<S247>/If'
          }

          // End of Outputs for SubSystem: '<S89>/Sub-Phase #4'
          break;
        }

        // End of If: '<S89>/Experiment Sub-Phases'
        // End of Outputs for SubSystem: '<S9>/Change RED Behavior'
      }

      // End of If: '<S9>/This IF block determines whether or not to run the RED sim//exp ' 
      // End of Outputs for SubSystem: '<Root>/Phase #3: Experiment'
      break;

     case 4:
      // Outputs for IfAction SubSystem: '<Root>/Phase #4: Return Home' incorporates:
      //   ActionPort: '<S10>/Action Port'

      APF_Path_Plann_Phase4ReturnHome(APF_Path_Planning_2023a_M,
        &APF_Path_Planning_2023a_DW.BLACK_Fx,
        &APF_Path_Planning_2023a_DW.BLACK_Fy,
        &APF_Path_Planning_2023a_DW.BLACK_Px,
        &APF_Path_Planning_2023a_DW.BLACK_Py,
        &APF_Path_Planning_2023a_DW.BLACK_Rz,
        &APF_Path_Planning_2023a_DW.BLACK_Tz,
        &APF_Path_Planning_2023a_DW.BLUE_Fx, &APF_Path_Planning_2023a_DW.BLUE_Fy,
        &APF_Path_Planning_2023a_DW.BLUE_Px, &APF_Path_Planning_2023a_DW.BLUE_Py,
        &APF_Path_Planning_2023a_DW.BLUE_Rz, &APF_Path_Planning_2023a_DW.BLUE_Tz,
        &APF_Path_Planning_2023a_DW.Float_State,
        &APF_Path_Planning_2023a_DW.RED_ARM_Control_Mode,
        &APF_Path_Planning_2023a_DW.RED_Elbow_Command,
        &APF_Path_Planning_2023a_DW.RED_Fx, &APF_Path_Planning_2023a_DW.RED_Fy,
        &APF_Path_Planning_2023a_DW.RED_Px, &APF_Path_Planning_2023a_DW.RED_Py,
        &APF_Path_Planning_2023a_DW.RED_Rz,
        &APF_Path_Planning_2023a_DW.RED_Rz_Elbow,
        &APF_Path_Planning_2023a_DW.RED_Rz_Shoulder,
        &APF_Path_Planning_2023a_DW.RED_Rz_Wrist,
        &APF_Path_Planning_2023a_DW.RED_Shoulder_Command,
        &APF_Path_Planning_2023a_DW.RED_Tz, &APF_Path_Planning_2023a_B.RED_Tz_RW,
        &APF_Path_Planning_2023a_DW.RED_Wrist_Command,
        &APF_Path_Planning_2023a_DW.WhoAmI, &APF_Path_Planning_2023a_DW.isSim,
        &APF_Path_Planning_2023a_B.Phase4ReturnHome,
        &APF_Path_Planning_2023a_DW.Phase4ReturnHome,
        &APF_Path_Planning_2023a_P.Phase4ReturnHome);

      // End of Outputs for SubSystem: '<Root>/Phase #4: Return Home'
      break;

     case 5:
      // Outputs for IfAction SubSystem: '<Root>/Phase #5: Hold Home' incorporates:
      //   ActionPort: '<S11>/Action Port'

      APF_Path_Plann_Phase4ReturnHome(APF_Path_Planning_2023a_M,
        &APF_Path_Planning_2023a_DW.BLACK_Fx,
        &APF_Path_Planning_2023a_DW.BLACK_Fy,
        &APF_Path_Planning_2023a_DW.BLACK_Px,
        &APF_Path_Planning_2023a_DW.BLACK_Py,
        &APF_Path_Planning_2023a_DW.BLACK_Rz,
        &APF_Path_Planning_2023a_DW.BLACK_Tz,
        &APF_Path_Planning_2023a_DW.BLUE_Fx, &APF_Path_Planning_2023a_DW.BLUE_Fy,
        &APF_Path_Planning_2023a_DW.BLUE_Px, &APF_Path_Planning_2023a_DW.BLUE_Py,
        &APF_Path_Planning_2023a_DW.BLUE_Rz, &APF_Path_Planning_2023a_DW.BLUE_Tz,
        &APF_Path_Planning_2023a_DW.Float_State,
        &APF_Path_Planning_2023a_DW.RED_ARM_Control_Mode,
        &APF_Path_Planning_2023a_DW.RED_Elbow_Command,
        &APF_Path_Planning_2023a_DW.RED_Fx, &APF_Path_Planning_2023a_DW.RED_Fy,
        &APF_Path_Planning_2023a_DW.RED_Px, &APF_Path_Planning_2023a_DW.RED_Py,
        &APF_Path_Planning_2023a_DW.RED_Rz,
        &APF_Path_Planning_2023a_DW.RED_Rz_Elbow,
        &APF_Path_Planning_2023a_DW.RED_Rz_Shoulder,
        &APF_Path_Planning_2023a_DW.RED_Rz_Wrist,
        &APF_Path_Planning_2023a_DW.RED_Shoulder_Command,
        &APF_Path_Planning_2023a_DW.RED_Tz, &APF_Path_Planning_2023a_B.RED_Tz_RW,
        &APF_Path_Planning_2023a_DW.RED_Wrist_Command,
        &APF_Path_Planning_2023a_DW.WhoAmI, &APF_Path_Planning_2023a_DW.isSim,
        &APF_Path_Planning_2023a_B.Phase5HoldHome,
        &APF_Path_Planning_2023a_DW.Phase5HoldHome,
        &APF_Path_Planning_2023a_P.Phase5HoldHome);

      // End of Outputs for SubSystem: '<Root>/Phase #5: Hold Home'
      break;

     case 6:
      // Outputs for IfAction SubSystem: '<Root>/Phase #6: Clean Shutdown' incorporates:
      //   ActionPort: '<S12>/Action Port'

      // If: '<S12>/This IF block determines whether or not to run the BLACK sim//exp' incorporates:
      //   DataStoreRead: '<S12>/Data Store Read'
      //   DataStoreRead: '<S12>/Data Store Read1'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if ((APF_Path_Planning_2023a_DW.WhoAmI == 2.0) ||
            (APF_Path_Planning_2023a_DW.isSim == 1.0)) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_dt =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_dt;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S12>/Change BLACK Behavior' incorporates:
        //   ActionPort: '<S520>/Action Port'

        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          // DataStoreWrite: '<S520>/BLACK_Fx' incorporates:
          //   Constant: '<S520>/Constant3'

          APF_Path_Planning_2023a_DW.BLACK_Fx =
            APF_Path_Planning_2023a_P.Constant3_Value;

          // DataStoreWrite: '<S520>/BLACK_Fy' incorporates:
          //   Constant: '<S520>/Constant4'

          APF_Path_Planning_2023a_DW.BLACK_Fy =
            APF_Path_Planning_2023a_P.Constant4_Value_g;

          // DataStoreWrite: '<S520>/BLACK_Tz' incorporates:
          //   Constant: '<S520>/Constant5'

          APF_Path_Planning_2023a_DW.BLACK_Tz =
            APF_Path_Planning_2023a_P.Constant5_Value_d;

          // DataStoreWrite: '<S520>/Data Store Write3' incorporates:
          //   Constant: '<S520>/Puck State'

          APF_Path_Planning_2023a_DW.Float_State =
            APF_Path_Planning_2023a_P.PuckState_Value_d;
        }

        // End of Outputs for SubSystem: '<S12>/Change BLACK Behavior'
      }

      // End of If: '<S12>/This IF block determines whether or not to run the BLACK sim//exp' 

      // If: '<S12>/This IF block determines whether or not to run the BLUE sim//exp' incorporates:
      //   DataStoreRead: '<S12>/Data Store Read'
      //   DataStoreRead: '<S12>/Data Store Read1'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if ((APF_Path_Planning_2023a_DW.WhoAmI == 3.0) ||
            (APF_Path_Planning_2023a_DW.isSim == 1.0)) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_f =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_f;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S12>/Change BLUE Behavior' incorporates:
        //   ActionPort: '<S521>/Action Port'

        APF_Path_Pla_ChangeBLUEBehavior(APF_Path_Planning_2023a_M,
          &APF_Path_Planning_2023a_DW.BLUE_Fx,
          &APF_Path_Planning_2023a_DW.BLUE_Fy,
          &APF_Path_Planning_2023a_DW.BLUE_Tz,
          &APF_Path_Planning_2023a_DW.Float_State,
          &APF_Path_Planning_2023a_P.ChangeBLUEBehavior_l);

        // End of Outputs for SubSystem: '<S12>/Change BLUE Behavior'
      }

      // End of If: '<S12>/This IF block determines whether or not to run the BLUE sim//exp' 

      // If: '<S12>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
      //   DataStoreRead: '<S12>/Data Store Read'
      //   DataStoreRead: '<S12>/Data Store Read1'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if ((APF_Path_Planning_2023a_DW.WhoAmI == 1.0) ||
            (APF_Path_Planning_2023a_DW.isSim == 1.0)) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_l =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_l;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S12>/Change RED Behavior' incorporates:
        //   ActionPort: '<S522>/Action Port'

        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          // DataStoreWrite: '<S522>/RED_Fx' incorporates:
          //   Constant: '<S522>/Constant'

          APF_Path_Planning_2023a_DW.RED_Fx =
            APF_Path_Planning_2023a_P.Constant_Value_b;

          // DataStoreWrite: '<S522>/RED_Fy' incorporates:
          //   Constant: '<S522>/Constant1'

          APF_Path_Planning_2023a_DW.RED_Fy =
            APF_Path_Planning_2023a_P.Constant1_Value_f;

          // DataStoreWrite: '<S522>/RED_Tz' incorporates:
          //   Constant: '<S522>/Constant2'

          APF_Path_Planning_2023a_DW.RED_Tz =
            APF_Path_Planning_2023a_P.Constant2_Value_h;

          // DataStoreWrite: '<S522>/Data Store Write1' incorporates:
          //   Constant: '<S522>/Constant3'

          APF_Path_Planning_2023a_DW.RED_ARM_Control_Mode =
            APF_Path_Planning_2023a_P.Constant3_Value_h;

          // DataStoreWrite: '<S522>/Data Store Write3' incorporates:
          //   Constant: '<S522>/Puck State'

          APF_Path_Planning_2023a_DW.Float_State =
            APF_Path_Planning_2023a_P.PuckState_Value_e;
        }

        // End of Outputs for SubSystem: '<S12>/Change RED Behavior'
      }

      // End of If: '<S12>/This IF block determines whether or not to run the RED sim//exp ' 
      // End of Outputs for SubSystem: '<Root>/Phase #6: Clean Shutdown'
      break;
    }

    // End of If: '<Root>/Separate Phases'
    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // If: '<Root>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' incorporates:
      //   DataStoreRead: '<Root>/Data Store Read1'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_DW.isSim == 1.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.IfsimModesetto1thenthisisasimul =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.IfsimModesetto1thenthisisasimul;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<Root>/Simulate Plant Dynamics' incorporates:
        //   ActionPort: '<S17>/Action Port'

        // DiscreteIntegrator: '<S571>/Acceleration  to Velocity' incorporates:
        //   DataStoreRead: '<S568>/BLACK_Fx_Sat'
        //   MATLAB Function: '<S571>/MATLAB Function'
        //   SignalConversion generated from: '<S578>/ SFunction '

        APF_Path_Planning_2023a_B.rtb_y_g =
          APF_Path_Planning_2023a_DW.BLACK_Fx_Sat /
          APF_Path_Planning_2023a_P.mBLACK *
          APF_Path_Planning_2023a_P.AccelerationtoVelocity_gainva_j +
          APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE[0];
        APF_Path_Planning_2023a_B.x_ddot_d[0] =
          APF_Path_Planning_2023a_B.rtb_y_g;

        // DiscreteIntegrator: '<S571>/Velocity to Position'
        APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp =
          APF_Path_Planning_2023a_P.VelocitytoPosition_gainval_n *
          APF_Path_Planning_2023a_B.rtb_y_g +
          APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE[0];

        // End of Outputs for SubSystem: '<Root>/Simulate Plant Dynamics'
        APF_Path_Planning_2023a_B.phi_tot_grad[0] =
          APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp;

        // Outputs for IfAction SubSystem: '<Root>/Simulate Plant Dynamics' incorporates:
        //   ActionPort: '<S17>/Action Port'

        // Sum: '<S571>/Sum' incorporates:
        //   RandomNumber: '<S571>/Random Number'

        APF_Path_Planning_2023a_B.rtb_path_o_idx_0 =
          APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp +
          APF_Path_Planning_2023a_DW.NextOutput;

        // DiscreteIntegrator: '<S571>/Acceleration  to Velocity' incorporates:
        //   DataStoreRead: '<S568>/BLACK_Fy_Sat'
        //   MATLAB Function: '<S571>/MATLAB Function'
        //   SignalConversion generated from: '<S578>/ SFunction '

        APF_Path_Planning_2023a_B.rtb_y_g =
          APF_Path_Planning_2023a_DW.BLACK_Fy_Sat /
          APF_Path_Planning_2023a_P.mBLACK *
          APF_Path_Planning_2023a_P.AccelerationtoVelocity_gainva_j +
          APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE[1];
        APF_Path_Planning_2023a_B.x_ddot_d[1] =
          APF_Path_Planning_2023a_B.rtb_y_g;

        // DiscreteIntegrator: '<S571>/Velocity to Position'
        APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp =
          APF_Path_Planning_2023a_P.VelocitytoPosition_gainval_n *
          APF_Path_Planning_2023a_B.rtb_y_g +
          APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE[1];

        // End of Outputs for SubSystem: '<Root>/Simulate Plant Dynamics'
        APF_Path_Planning_2023a_B.phi_tot_grad[1] =
          APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp;

        // Outputs for IfAction SubSystem: '<Root>/Simulate Plant Dynamics' incorporates:
        //   ActionPort: '<S17>/Action Port'

        // Sum: '<S571>/Sum' incorporates:
        //   RandomNumber: '<S571>/Random Number'

        APF_Path_Planning_2023a_B.Derivative2 =
          APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp +
          APF_Path_Planning_2023a_DW.NextOutput;

        // DiscreteIntegrator: '<S571>/Acceleration  to Velocity' incorporates:
        //   DataStoreRead: '<S568>/BLACK_Tz_Sat'
        //   MATLAB Function: '<S571>/MATLAB Function'
        //   SignalConversion generated from: '<S578>/ SFunction '

        APF_Path_Planning_2023a_B.rtb_y_g =
          APF_Path_Planning_2023a_DW.BLACK_Tz_Sat /
          APF_Path_Planning_2023a_P.IBLACK *
          APF_Path_Planning_2023a_P.AccelerationtoVelocity_gainva_j +
          APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE[2];

        // DiscreteIntegrator: '<S571>/Velocity to Position'
        APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp =
          APF_Path_Planning_2023a_P.VelocitytoPosition_gainval_n *
          APF_Path_Planning_2023a_B.rtb_y_g +
          APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE[2];

        // Sum: '<S571>/Sum' incorporates:
        //   RandomNumber: '<S571>/Random Number'

        APF_Path_Planning_2023a_B.rtb_path_o_idx_2 =
          APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp +
          APF_Path_Planning_2023a_DW.NextOutput;

        // Delay: '<S577>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_ou) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_f =
            APF_Path_Planning_2023a_B.rtb_path_o_idx_0;
        }

        // Sum: '<S577>/Sum6' incorporates:
        //   Delay: '<S577>/Delay1'

        APF_Path_Planning_2023a_B.RED_Tz_RW =
          APF_Path_Planning_2023a_B.rtb_path_o_idx_0 -
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_f;

        // If: '<S577>/if we went through a "step"'
        if (APF_Path_Planning_2023a_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S577>/Hold this value' incorporates:
          //   ActionPort: '<S584>/Action Port'

          // SignalConversion generated from: '<S584>/In1'
          APF_Path_Planning_2023a_B.In1_ps = APF_Path_Planning_2023a_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S577>/Hold this value'
        }

        // End of If: '<S577>/if we went through a "step"'

        // Gain: '<S577>/divide by delta T' incorporates:
        //   DataStoreWrite: '<S568>/BLACK_Vx'

        APF_Path_Planning_2023a_DW.BLACK_Vx = 1.0 /
          APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_ps;

        // Delay: '<S574>/Delay1' incorporates:
        //   DataStoreWrite: '<S568>/BLACK_Vx'

        if (APF_Path_Planning_2023a_DW.icLoad_p4) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_lg =
            APF_Path_Planning_2023a_DW.BLACK_Vx;
        }

        // Sum: '<S574>/Sum6' incorporates:
        //   DataStoreWrite: '<S568>/BLACK_Vx'
        //   Delay: '<S574>/Delay1'

        APF_Path_Planning_2023a_B.RED_Tz_RW =
          APF_Path_Planning_2023a_DW.BLACK_Vx -
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_lg;

        // If: '<S574>/if we went through a "step"'
        if (APF_Path_Planning_2023a_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S574>/Hold this value' incorporates:
          //   ActionPort: '<S581>/Action Port'

          // SignalConversion generated from: '<S581>/In1'
          APF_Path_Planning_2023a_B.In1_j = APF_Path_Planning_2023a_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S574>/Hold this value'
        }

        // End of If: '<S574>/if we went through a "step"'

        // Sum: '<S568>/Sum1' incorporates:
        //   DataStoreWrite: '<S568>/BLACK_IMU_Ax_I'
        //   Gain: '<S574>/divide by delta T'
        //   RandomNumber: '<S568>/Random Number1'

        APF_Path_Planning_2023a_DW.BLACK_Ay = 1.0 /
          APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_j +
          APF_Path_Planning_2023a_DW.NextOutput_b;

        // Delay: '<S572>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_jc) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_d3a =
            APF_Path_Planning_2023a_B.Derivative2;
        }

        // Sum: '<S572>/Sum6' incorporates:
        //   Delay: '<S572>/Delay1'

        APF_Path_Planning_2023a_B.RED_Tz_RW =
          APF_Path_Planning_2023a_B.Derivative2 -
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_d3a;

        // If: '<S572>/if we went through a "step"'
        if (APF_Path_Planning_2023a_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S572>/Hold this value' incorporates:
          //   ActionPort: '<S579>/Action Port'

          // SignalConversion generated from: '<S579>/In1'
          APF_Path_Planning_2023a_B.In1_pg = APF_Path_Planning_2023a_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S572>/Hold this value'
        }

        // End of If: '<S572>/if we went through a "step"'

        // Gain: '<S572>/divide by delta T' incorporates:
        //   DataStoreWrite: '<S568>/BLACK_Vy'

        APF_Path_Planning_2023a_DW.BLACK_Vy = 1.0 /
          APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_pg;

        // Delay: '<S575>/Delay1' incorporates:
        //   DataStoreWrite: '<S568>/BLACK_Vy'

        if (APF_Path_Planning_2023a_DW.icLoad_jk) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_ea =
            APF_Path_Planning_2023a_DW.BLACK_Vy;
        }

        // Sum: '<S575>/Sum6' incorporates:
        //   DataStoreWrite: '<S568>/BLACK_Vy'
        //   Delay: '<S575>/Delay1'

        APF_Path_Planning_2023a_B.RED_Tz_RW =
          APF_Path_Planning_2023a_DW.BLACK_Vy -
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_ea;

        // If: '<S575>/if we went through a "step"'
        if (APF_Path_Planning_2023a_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S575>/Hold this value' incorporates:
          //   ActionPort: '<S582>/Action Port'

          // SignalConversion generated from: '<S582>/In1'
          APF_Path_Planning_2023a_B.In1_ex = APF_Path_Planning_2023a_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S575>/Hold this value'
        }

        // End of If: '<S575>/if we went through a "step"'

        // Sum: '<S568>/Sum2' incorporates:
        //   DataStoreWrite: '<S568>/BLACK_IMU_Ay_I'
        //   Gain: '<S575>/divide by delta T'
        //   RandomNumber: '<S568>/Random Number'

        APF_Path_Planning_2023a_DW.BLACK_RzDD = 1.0 /
          APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_ex
          + APF_Path_Planning_2023a_DW.NextOutput_j;

        // Delay: '<S573>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_jr) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_cx =
            APF_Path_Planning_2023a_B.rtb_path_o_idx_2;
        }

        // Sum: '<S573>/Sum6' incorporates:
        //   Delay: '<S573>/Delay1'

        APF_Path_Planning_2023a_B.RED_Tz_RW =
          APF_Path_Planning_2023a_B.rtb_path_o_idx_2 -
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_cx;

        // If: '<S573>/if we went through a "step"'
        if (APF_Path_Planning_2023a_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S573>/Hold this value' incorporates:
          //   ActionPort: '<S580>/Action Port'

          // SignalConversion generated from: '<S580>/In1'
          APF_Path_Planning_2023a_B.In1_ib = APF_Path_Planning_2023a_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S573>/Hold this value'
        }

        // End of If: '<S573>/if we went through a "step"'

        // Gain: '<S573>/divide by delta T' incorporates:
        //   DataStoreWrite: '<S568>/BLACK_RzD'

        APF_Path_Planning_2023a_DW.BLACK_RzD = 1.0 /
          APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_ib;

        // Delay: '<S576>/Delay1' incorporates:
        //   DataStoreWrite: '<S568>/BLACK_RzD'

        if (APF_Path_Planning_2023a_DW.icLoad_jko) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_ab =
            APF_Path_Planning_2023a_DW.BLACK_RzD;
        }

        // Sum: '<S576>/Sum6' incorporates:
        //   DataStoreWrite: '<S568>/BLACK_RzD'
        //   Delay: '<S576>/Delay1'

        APF_Path_Planning_2023a_B.RED_Tz_RW =
          APF_Path_Planning_2023a_DW.BLACK_RzD -
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_ab;

        // If: '<S576>/if we went through a "step"'
        if (APF_Path_Planning_2023a_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S576>/Hold this value' incorporates:
          //   ActionPort: '<S583>/Action Port'

          // SignalConversion generated from: '<S583>/In1'
          APF_Path_Planning_2023a_B.In1_cz = APF_Path_Planning_2023a_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S576>/Hold this value'
        }

        // End of If: '<S576>/if we went through a "step"'

        // Sum: '<S568>/Sum3' incorporates:
        //   DataStoreWrite: '<S568>/BLACK_IMU_R'
        //   Gain: '<S576>/divide by delta T'
        //   RandomNumber: '<S568>/Random Number2'

        APF_Path_Planning_2023a_DW.BLACK_Ax = 1.0 /
          APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_cz
          + APF_Path_Planning_2023a_DW.NextOutput_g;

        // DataStoreWrite: '<S568>/BLACK_Px'
        APF_Path_Planning_2023a_DW.BLACK_Px =
          APF_Path_Planning_2023a_B.rtb_path_o_idx_0;
        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          rtsiSetBlockStateForSolverChangedAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
          rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
        }

        // End of DataStoreWrite: '<S568>/BLACK_Px'

        // DataStoreWrite: '<S568>/BLACK_Py'
        APF_Path_Planning_2023a_DW.BLACK_Py =
          APF_Path_Planning_2023a_B.Derivative2;
        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          rtsiSetBlockStateForSolverChangedAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
          rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
        }

        // End of DataStoreWrite: '<S568>/BLACK_Py'

        // DataStoreWrite: '<S568>/BLACK_Rz' incorporates:
        //   DataStoreWrite: '<S568>/BLACK_RzD'
        //   DataStoreWrite: '<S568>/BLACK_Vx'
        //   DataStoreWrite: '<S568>/BLACK_Vy'

        APF_Path_Planning_2023a_DW.BLACK_Rz =
          APF_Path_Planning_2023a_B.rtb_path_o_idx_2;
        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          rtsiSetBlockStateForSolverChangedAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
          rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
          rtsiSetBlockStateForSolverChangedAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
          rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
          rtsiSetBlockStateForSolverChangedAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
          rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
          rtsiSetBlockStateForSolverChangedAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
          rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
        }

        // End of DataStoreWrite: '<S568>/BLACK_Rz'

        // DiscreteIntegrator: '<S585>/Acceleration  to Velocity' incorporates:
        //   DataStoreRead: '<S569>/BLUE_Fx_Sat '
        //   MATLAB Function: '<S585>/MATLAB Function'
        //   SignalConversion generated from: '<S592>/ SFunction '

        APF_Path_Planning_2023a_B.varargout_1 =
          APF_Path_Planning_2023a_DW.BLUE_Fx_Sat /
          APF_Path_Planning_2023a_P.mBLUE *
          APF_Path_Planning_2023a_P.AccelerationtoVelocity_gainva_p +
          APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_i[0];

        // End of Outputs for SubSystem: '<Root>/Simulate Plant Dynamics'
        APF_Path_Planning_2023a_B.q = APF_Path_Planning_2023a_B.varargout_1;

        // Outputs for IfAction SubSystem: '<Root>/Simulate Plant Dynamics' incorporates:
        //   ActionPort: '<S17>/Action Port'

        // DiscreteIntegrator: '<S585>/Velocity to Position'
        APF_Path_Planning_2023a_B.RED_Tz_RW =
          APF_Path_Planning_2023a_P.VelocitytoPosition_gainval_e *
          APF_Path_Planning_2023a_B.varargout_1 +
          APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE_a[0];

        // End of Outputs for SubSystem: '<Root>/Simulate Plant Dynamics'
        APF_Path_Planning_2023a_B.r_ct[0] = APF_Path_Planning_2023a_B.RED_Tz_RW;

        // Outputs for IfAction SubSystem: '<Root>/Simulate Plant Dynamics' incorporates:
        //   ActionPort: '<S17>/Action Port'

        // Sum: '<S585>/Sum' incorporates:
        //   RandomNumber: '<S585>/Random Number'

        APF_Path_Planning_2023a_B.r_co[0] = APF_Path_Planning_2023a_B.RED_Tz_RW
          + APF_Path_Planning_2023a_DW.NextOutput_a;

        // DiscreteIntegrator: '<S585>/Acceleration  to Velocity' incorporates:
        //   DataStoreRead: '<S569>/BLUE_Fy_Sat'
        //   MATLAB Function: '<S585>/MATLAB Function'
        //   SignalConversion generated from: '<S592>/ SFunction '

        APF_Path_Planning_2023a_B.varargout_1 =
          APF_Path_Planning_2023a_DW.BLUE_Fy_Sat /
          APF_Path_Planning_2023a_P.mBLUE *
          APF_Path_Planning_2023a_P.AccelerationtoVelocity_gainva_p +
          APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_i[1];

        // End of Outputs for SubSystem: '<Root>/Simulate Plant Dynamics'
        APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 =
          APF_Path_Planning_2023a_B.varargout_1;

        // Outputs for IfAction SubSystem: '<Root>/Simulate Plant Dynamics' incorporates:
        //   ActionPort: '<S17>/Action Port'

        // DiscreteIntegrator: '<S585>/Velocity to Position'
        APF_Path_Planning_2023a_B.RED_Tz_RW =
          APF_Path_Planning_2023a_P.VelocitytoPosition_gainval_e *
          APF_Path_Planning_2023a_B.varargout_1 +
          APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE_a[1];

        // End of Outputs for SubSystem: '<Root>/Simulate Plant Dynamics'
        APF_Path_Planning_2023a_B.r_ct[1] = APF_Path_Planning_2023a_B.RED_Tz_RW;

        // Outputs for IfAction SubSystem: '<Root>/Simulate Plant Dynamics' incorporates:
        //   ActionPort: '<S17>/Action Port'

        // Sum: '<S585>/Sum' incorporates:
        //   RandomNumber: '<S585>/Random Number'

        APF_Path_Planning_2023a_B.r_co[1] = APF_Path_Planning_2023a_B.RED_Tz_RW
          + APF_Path_Planning_2023a_DW.NextOutput_a;

        // DiscreteIntegrator: '<S585>/Acceleration  to Velocity' incorporates:
        //   DataStoreRead: '<S569>/BLUE_Tz_Sat'
        //   MATLAB Function: '<S585>/MATLAB Function'
        //   SignalConversion generated from: '<S592>/ SFunction '

        APF_Path_Planning_2023a_B.varargout_1 =
          APF_Path_Planning_2023a_DW.BLUE_Tz_Sat /
          APF_Path_Planning_2023a_P.IBLUE *
          APF_Path_Planning_2023a_P.AccelerationtoVelocity_gainva_p +
          APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_i[2];

        // DiscreteIntegrator: '<S585>/Velocity to Position'
        APF_Path_Planning_2023a_B.RED_Tz_RW =
          APF_Path_Planning_2023a_P.VelocitytoPosition_gainval_e *
          APF_Path_Planning_2023a_B.varargout_1 +
          APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE_a[2];

        // Sum: '<S585>/Sum' incorporates:
        //   RandomNumber: '<S585>/Random Number'

        APF_Path_Planning_2023a_B.r_co[2] = APF_Path_Planning_2023a_B.RED_Tz_RW
          + APF_Path_Planning_2023a_DW.NextOutput_a;

        // Delay: '<S591>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_do) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_gv =
            APF_Path_Planning_2023a_B.r_co[0];
        }

        // Sum: '<S591>/Sum6' incorporates:
        //   Delay: '<S591>/Delay1'

        APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
          APF_Path_Planning_2023a_B.r_co[0] -
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_gv;

        // If: '<S591>/if we went through a "step"'
        if (APF_Path_Planning_2023a_B.rtb_path_b_idx_0 != 0.0) {
          // Outputs for IfAction SubSystem: '<S591>/Hold this value' incorporates:
          //   ActionPort: '<S598>/Action Port'

          // SignalConversion generated from: '<S598>/In1'
          APF_Path_Planning_2023a_B.In1_hq =
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0;

          // End of Outputs for SubSystem: '<S591>/Hold this value'
        }

        // End of If: '<S591>/if we went through a "step"'

        // Gain: '<S591>/divide by delta T' incorporates:
        //   DataStoreWrite: '<S569>/BLUE_Vx'

        APF_Path_Planning_2023a_DW.BLUE_Vx = 1.0 /
          APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_hq;

        // Delay: '<S588>/Delay1' incorporates:
        //   DataStoreWrite: '<S569>/BLUE_Vx'

        if (APF_Path_Planning_2023a_DW.icLoad_nk) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_ds =
            APF_Path_Planning_2023a_DW.BLUE_Vx;
        }

        // End of Delay: '<S588>/Delay1'

        // Delay: '<S586>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_ip) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_i5 =
            APF_Path_Planning_2023a_B.r_co[1];
        }

        // Sum: '<S586>/Sum6' incorporates:
        //   Delay: '<S586>/Delay1'

        APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
          APF_Path_Planning_2023a_B.r_co[1] -
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_i5;

        // If: '<S586>/if we went through a "step"'
        if (APF_Path_Planning_2023a_B.rtb_path_b_idx_0 != 0.0) {
          // Outputs for IfAction SubSystem: '<S586>/Hold this value' incorporates:
          //   ActionPort: '<S593>/Action Port'

          // SignalConversion generated from: '<S593>/In1'
          APF_Path_Planning_2023a_B.In1_gg =
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0;

          // End of Outputs for SubSystem: '<S586>/Hold this value'
        }

        // End of If: '<S586>/if we went through a "step"'

        // Gain: '<S586>/divide by delta T' incorporates:
        //   DataStoreWrite: '<S569>/BLUE_Vy'

        APF_Path_Planning_2023a_DW.BLUE_Vy = 1.0 /
          APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_gg;

        // Delay: '<S589>/Delay1' incorporates:
        //   DataStoreWrite: '<S569>/BLUE_Vy'

        if (APF_Path_Planning_2023a_DW.icLoad_az) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_l0 =
            APF_Path_Planning_2023a_DW.BLUE_Vy;
        }

        // End of Delay: '<S589>/Delay1'

        // Delay: '<S587>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_dh) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_iq =
            APF_Path_Planning_2023a_B.r_co[2];
        }

        // Sum: '<S587>/Sum6' incorporates:
        //   Delay: '<S587>/Delay1'

        APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
          APF_Path_Planning_2023a_B.r_co[2] -
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_iq;

        // If: '<S587>/if we went through a "step"'
        if (APF_Path_Planning_2023a_B.rtb_path_b_idx_0 != 0.0) {
          // Outputs for IfAction SubSystem: '<S587>/Hold this value' incorporates:
          //   ActionPort: '<S594>/Action Port'

          // SignalConversion generated from: '<S594>/In1'
          APF_Path_Planning_2023a_B.In1_bh =
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0;

          // End of Outputs for SubSystem: '<S587>/Hold this value'
        }

        // End of If: '<S587>/if we went through a "step"'

        // Gain: '<S587>/divide by delta T' incorporates:
        //   DataStoreWrite: '<S569>/BLUE_RzD'

        APF_Path_Planning_2023a_DW.BLUE_RzD = 1.0 /
          APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_bh;

        // Delay: '<S590>/Delay1' incorporates:
        //   DataStoreWrite: '<S569>/BLUE_RzD'

        if (APF_Path_Planning_2023a_DW.icLoad_ex) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_eq =
            APF_Path_Planning_2023a_DW.BLUE_RzD;
        }

        // End of Delay: '<S590>/Delay1'

        // DataStoreWrite: '<S569>/BLUE_Px '
        APF_Path_Planning_2023a_DW.BLUE_Px = APF_Path_Planning_2023a_B.r_co[0];
        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          rtsiSetBlockStateForSolverChangedAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
          rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
        }

        // End of DataStoreWrite: '<S569>/BLUE_Px '

        // DataStoreWrite: '<S569>/BLUE_Py'
        APF_Path_Planning_2023a_DW.BLUE_Py = APF_Path_Planning_2023a_B.r_co[1];
        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          rtsiSetBlockStateForSolverChangedAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
          rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
        }

        // End of DataStoreWrite: '<S569>/BLUE_Py'

        // DataStoreWrite: '<S569>/BLUE_Rz' incorporates:
        //   DataStoreWrite: '<S569>/BLUE_RzD'
        //   DataStoreWrite: '<S569>/BLUE_Vx'
        //   DataStoreWrite: '<S569>/BLUE_Vy'

        APF_Path_Planning_2023a_DW.BLUE_Rz = APF_Path_Planning_2023a_B.r_co[2];
        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          rtsiSetBlockStateForSolverChangedAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
          rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
          rtsiSetBlockStateForSolverChangedAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
          rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
          rtsiSetBlockStateForSolverChangedAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
          rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
          rtsiSetBlockStateForSolverChangedAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
          rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
        }

        // End of DataStoreWrite: '<S569>/BLUE_Rz'

        // If: '<S570>/If' incorporates:
        //   Constant: '<S570>/Constant'

        if ((APF_Path_Planning_2023a_P.platformSelection == 4.0) ||
            (APF_Path_Planning_2023a_P.platformSelection == 5.0) ||
            (APF_Path_Planning_2023a_P.platformSelection == 10.0) ||
            (APF_Path_Planning_2023a_P.platformSelection == 11.0)) {
          // Outputs for IfAction SubSystem: '<S570>/RED + ARM' incorporates:
          //   ActionPort: '<S599>/Action Port'

          // MATLAB Function: '<S601>/Inertia Function 1' incorporates:
          //   Delay: '<S601>/Delay'
          //   MATLAB Function: '<S601>/Coriolis Function1'

          APF_Path_Planning_2023a_B.rtb_path_b_idx_1 =
            APF_Path_Planning_2023a_P.a1 + APF_Path_Planning_2023a_P.b1;
          APF_Path_Planning_2023a_B.t6_tmp =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[2] +
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[3];
          APF_Path_Planning_2023a_B.t7 = cos(APF_Path_Planning_2023a_B.t6_tmp);
          APF_Path_Planning_2023a_B.t21 = APF_Path_Planning_2023a_P.a1 *
            APF_Path_Planning_2023a_P.mPROX;
          APF_Path_Planning_2023a_B.t8 = (APF_Path_Planning_2023a_P.mDIST *
            APF_Path_Planning_2023a_B.rtb_path_b_idx_1 +
            APF_Path_Planning_2023a_B.t21) + APF_Path_Planning_2023a_P.mEE *
            APF_Path_Planning_2023a_B.rtb_path_b_idx_1;
          APF_Path_Planning_2023a_B.t_tmp = APF_Path_Planning_2023a_P.a2 *
            APF_Path_Planning_2023a_P.mDIST;
          APF_Path_Planning_2023a_B.t12_tmp = APF_Path_Planning_2023a_B.t6_tmp +
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[4];
          APF_Path_Planning_2023a_B.t13 = cos(APF_Path_Planning_2023a_B.t12_tmp);
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0 =
            APF_Path_Planning_2023a_P.a2 + APF_Path_Planning_2023a_P.b2;
          APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
            APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0 *
            APF_Path_Planning_2023a_P.mEE + APF_Path_Planning_2023a_B.t_tmp;
          APF_Path_Planning_2023a_B.link2_com_y =
            APF_Path_Planning_2023a_B.t12_tmp +
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[5];
          APF_Path_Planning_2023a_B.t16 = cos
            (APF_Path_Planning_2023a_B.link2_com_y);
          APF_Path_Planning_2023a_B.t17 = ((APF_Path_Planning_2023a_P.mRED +
            APF_Path_Planning_2023a_P.mPROX) + APF_Path_Planning_2023a_P.mDIST)
            + APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.t21_tmp = (APF_Path_Planning_2023a_P.b0 *
            APF_Path_Planning_2023a_P.mPROX + APF_Path_Planning_2023a_P.b0 *
            APF_Path_Planning_2023a_P.mDIST) + APF_Path_Planning_2023a_P.b0 *
            APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.t22_tmp = (1.5707963267948966 -
            APF_Path_Planning_2023a_P.Phi) +
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[2];
          APF_Path_Planning_2023a_B.t23 = sin(APF_Path_Planning_2023a_B.t6_tmp);
          APF_Path_Planning_2023a_B.t24 = sin(APF_Path_Planning_2023a_B.t12_tmp);
          APF_Path_Planning_2023a_B.t25 = sin
            (APF_Path_Planning_2023a_B.link2_com_y);
          APF_Path_Planning_2023a_B.t28 = (APF_Path_Planning_2023a_P.a2 *
            APF_Path_Planning_2023a_P.mEE + APF_Path_Planning_2023a_B.t_tmp) +
            APF_Path_Planning_2023a_P.b2 * APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.t91 = APF_Path_Planning_2023a_B.t13 *
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0;
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 =
            APF_Path_Planning_2023a_P.a3 * APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.t93 =
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 *
            APF_Path_Planning_2023a_B.t16;
          APF_Path_Planning_2023a_B.t96 = (-(APF_Path_Planning_2023a_B.t7 *
            APF_Path_Planning_2023a_B.t8) - APF_Path_Planning_2023a_B.t91) -
            APF_Path_Planning_2023a_B.t93;
          APF_Path_Planning_2023a_B.t30_tmp = sin
            (APF_Path_Planning_2023a_B.t22_tmp);
          APF_Path_Planning_2023a_B.t30 = APF_Path_Planning_2023a_B.t96 -
            APF_Path_Planning_2023a_B.t21_tmp *
            APF_Path_Planning_2023a_B.t30_tmp;
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1 =
            APF_Path_Planning_2023a_B.t8 * APF_Path_Planning_2023a_B.t23;
          APF_Path_Planning_2023a_B.t104 =
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 *
            APF_Path_Planning_2023a_B.t24;
          APF_Path_Planning_2023a_B.t105 =
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 *
            APF_Path_Planning_2023a_B.t25;
          APF_Path_Planning_2023a_B.t22_tmp = cos
            (APF_Path_Planning_2023a_B.t22_tmp);
          APF_Path_Planning_2023a_B.t33 = ((APF_Path_Planning_2023a_B.t21_tmp *
            APF_Path_Planning_2023a_B.t22_tmp -
            APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1) -
            APF_Path_Planning_2023a_B.t104) - APF_Path_Planning_2023a_B.t105;
          APF_Path_Planning_2023a_B.t34 = APF_Path_Planning_2023a_P.a1 *
            APF_Path_Planning_2023a_P.a1;
          APF_Path_Planning_2023a_B.t35 = APF_Path_Planning_2023a_P.a2 *
            APF_Path_Planning_2023a_P.a2;
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_1 =
            APF_Path_Planning_2023a_P.b0 * APF_Path_Planning_2023a_P.b0;
          APF_Path_Planning_2023a_B.t37 = APF_Path_Planning_2023a_P.b1 *
            APF_Path_Planning_2023a_P.b1;
          APF_Path_Planning_2023a_B.t45 = cos
            (APF_Path_Planning_2023a_DW.Delay_DSTATE_of[4]);
          APF_Path_Planning_2023a_B.t101 = APF_Path_Planning_2023a_P.a1 *
            APF_Path_Planning_2023a_P.a2;
          APF_Path_Planning_2023a_B.t95 = APF_Path_Planning_2023a_P.a2 *
            APF_Path_Planning_2023a_P.b1;
          APF_Path_Planning_2023a_B.t100 = APF_Path_Planning_2023a_B.t101 *
            APF_Path_Planning_2023a_P.mDIST;
          APF_Path_Planning_2023a_B.t101 *= APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.t92 = APF_Path_Planning_2023a_B.t95 *
            APF_Path_Planning_2023a_P.mDIST;
          APF_Path_Planning_2023a_B.t94 = APF_Path_Planning_2023a_P.a1 *
            APF_Path_Planning_2023a_P.b2 * APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.t95 *= APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.t97 = APF_Path_Planning_2023a_P.b1 *
            APF_Path_Planning_2023a_P.b2 * APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_2 =
            (((((APF_Path_Planning_2023a_B.t100 * 2.0 +
                 APF_Path_Planning_2023a_B.t101 * 2.0) +
                APF_Path_Planning_2023a_B.t92 * 2.0) +
               APF_Path_Planning_2023a_B.t94 * 2.0) +
              APF_Path_Planning_2023a_B.t95 * 2.0) +
             APF_Path_Planning_2023a_B.t97 * 2.0) *
            APF_Path_Planning_2023a_B.t45;
          APF_Path_Planning_2023a_B.t50 = cos
            (APF_Path_Planning_2023a_DW.Delay_DSTATE_of[5]);
          APF_Path_Planning_2023a_B.t51_tmp = APF_Path_Planning_2023a_P.a2 *
            APF_Path_Planning_2023a_P.a3 * APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.t79 = APF_Path_Planning_2023a_P.a3 *
            APF_Path_Planning_2023a_P.b2 * APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.t51 = (APF_Path_Planning_2023a_B.t51_tmp *
            2.0 + APF_Path_Planning_2023a_B.t79 * 2.0) *
            APF_Path_Planning_2023a_B.t50;
          APF_Path_Planning_2023a_B.t80 =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[4] +
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[5];
          APF_Path_Planning_2023a_B.t56 = cos(APF_Path_Planning_2023a_B.t80);
          APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
            APF_Path_Planning_2023a_P.a1 * APF_Path_Planning_2023a_P.a3 *
            APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_P.a3 *
            APF_Path_Planning_2023a_P.b1 * APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.t57 =
            (APF_Path_Planning_2023a_B.rtb_path_b_idx_0 * 2.0 +
             APF_Path_Planning_2023a_B.t * 2.0) * APF_Path_Planning_2023a_B.t56;
          APF_Path_Planning_2023a_B.t54 = (1.5707963267948966 -
            APF_Path_Planning_2023a_P.Phi) -
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[3];
          APF_Path_Planning_2023a_B.Sum6_b3 = sin(APF_Path_Planning_2023a_B.t54);
          APF_Path_Planning_2023a_B.t81 = (-(1.5707963267948966 -
            APF_Path_Planning_2023a_P.Phi) +
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[3]) +
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[4];
          APF_Path_Planning_2023a_B.t61 = sin(APF_Path_Planning_2023a_B.t81);
          APF_Path_Planning_2023a_B.t63_tmp = APF_Path_Planning_2023a_B.t81 +
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[5];
          APF_Path_Planning_2023a_B.t63 = sin(APF_Path_Planning_2023a_B.t63_tmp);
          APF_Path_Planning_2023a_B.t64 = APF_Path_Planning_2023a_P.mPROX *
            APF_Path_Planning_2023a_B.t34;
          APF_Path_Planning_2023a_B.t65 = APF_Path_Planning_2023a_P.mDIST *
            APF_Path_Planning_2023a_B.t34;
          APF_Path_Planning_2023a_B.t34 *= APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.t67 = APF_Path_Planning_2023a_P.mDIST *
            APF_Path_Planning_2023a_B.t35;
          APF_Path_Planning_2023a_B.t68 = APF_Path_Planning_2023a_P.mEE *
            APF_Path_Planning_2023a_B.t35;
          APF_Path_Planning_2023a_B.t35 = APF_Path_Planning_2023a_P.a3 *
            APF_Path_Planning_2023a_P.a3 * APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.t71 = APF_Path_Planning_2023a_P.mDIST *
            APF_Path_Planning_2023a_B.t37;
          APF_Path_Planning_2023a_B.t72 = APF_Path_Planning_2023a_P.mEE *
            APF_Path_Planning_2023a_B.t37;
          APF_Path_Planning_2023a_B.t74 = APF_Path_Planning_2023a_P.b2 *
            APF_Path_Planning_2023a_P.b2 * APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.t37 = APF_Path_Planning_2023a_P.a1 *
            APF_Path_Planning_2023a_P.b1;
          APF_Path_Planning_2023a_B.t75 = APF_Path_Planning_2023a_B.t37 *
            APF_Path_Planning_2023a_P.mDIST * 2.0;
          APF_Path_Planning_2023a_B.t76 = APF_Path_Planning_2023a_B.t37 *
            APF_Path_Planning_2023a_P.mEE * 2.0;
          APF_Path_Planning_2023a_B.t37 = APF_Path_Planning_2023a_P.a2 *
            APF_Path_Planning_2023a_P.b2 * APF_Path_Planning_2023a_P.mEE * 2.0;
          APF_Path_Planning_2023a_B.t82 = APF_Path_Planning_2023a_P.a2 *
            APF_Path_Planning_2023a_P.b0;
          APF_Path_Planning_2023a_B.t83 = APF_Path_Planning_2023a_B.t82 *
            APF_Path_Planning_2023a_P.mDIST;
          APF_Path_Planning_2023a_B.t82 *= APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.t81_tmp = APF_Path_Planning_2023a_P.b0 *
            APF_Path_Planning_2023a_P.b2 * APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.t56 *=
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 +
            APF_Path_Planning_2023a_B.t;
          APF_Path_Planning_2023a_B.t112_tmp = ((APF_Path_Planning_2023a_B.t83 +
            APF_Path_Planning_2023a_B.t82) + APF_Path_Planning_2023a_B.t81_tmp) *
            APF_Path_Planning_2023a_B.t61;
          APF_Path_Planning_2023a_B.t113_tmp_tmp = APF_Path_Planning_2023a_P.a3 *
            APF_Path_Planning_2023a_P.b0 * APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.t113_tmp =
            APF_Path_Planning_2023a_B.t113_tmp_tmp *
            APF_Path_Planning_2023a_B.t63;
          APF_Path_Planning_2023a_B.t99_tmp = APF_Path_Planning_2023a_P.a1 *
            APF_Path_Planning_2023a_P.b0;
          APF_Path_Planning_2023a_B.t99_tmp_l = APF_Path_Planning_2023a_P.b0 *
            APF_Path_Planning_2023a_P.b1;
          APF_Path_Planning_2023a_B.t99_tmp_d =
            APF_Path_Planning_2023a_B.t99_tmp * APF_Path_Planning_2023a_P.mPROX;
          APF_Path_Planning_2023a_B.t99_tmp_dy =
            APF_Path_Planning_2023a_B.t99_tmp * APF_Path_Planning_2023a_P.mDIST;
          APF_Path_Planning_2023a_B.t99_tmp *= APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.t99_tmp_lx =
            APF_Path_Planning_2023a_B.t99_tmp_l *
            APF_Path_Planning_2023a_P.mDIST;
          APF_Path_Planning_2023a_B.t99_tmp_l *= APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.t99_tmp_o =
            ((((((((((((((((APF_Path_Planning_2023a_P.IPROX +
                            APF_Path_Planning_2023a_P.IDIST) +
                           APF_Path_Planning_2023a_P.IEE) +
                          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_2) +
                         APF_Path_Planning_2023a_B.t51) +
                        APF_Path_Planning_2023a_B.t57) +
                       APF_Path_Planning_2023a_B.t64) +
                      APF_Path_Planning_2023a_B.t65) +
                     APF_Path_Planning_2023a_B.t34) +
                    APF_Path_Planning_2023a_B.t67) +
                   APF_Path_Planning_2023a_B.t68) +
                  APF_Path_Planning_2023a_B.t35) + APF_Path_Planning_2023a_B.t71)
                + APF_Path_Planning_2023a_B.t72) + APF_Path_Planning_2023a_B.t74)
              + APF_Path_Planning_2023a_B.t75) + APF_Path_Planning_2023a_B.t76)
            + APF_Path_Planning_2023a_B.t37;
          APF_Path_Planning_2023a_B.t99 =
            ((((((APF_Path_Planning_2023a_B.t99_tmp_d +
                  APF_Path_Planning_2023a_B.t99_tmp_dy) +
                 APF_Path_Planning_2023a_B.t99_tmp) +
                APF_Path_Planning_2023a_B.t99_tmp_lx) +
               APF_Path_Planning_2023a_B.t99_tmp_l) *
              APF_Path_Planning_2023a_B.Sum6_b3 +
              APF_Path_Planning_2023a_B.t99_tmp_o) -
             APF_Path_Planning_2023a_B.t112_tmp) -
            APF_Path_Planning_2023a_B.t113_tmp;
          APF_Path_Planning_2023a_B.t50 *= APF_Path_Planning_2023a_B.t51_tmp +
            APF_Path_Planning_2023a_B.t79;
          APF_Path_Planning_2023a_B.t114_tmp_tmp =
            ((((((APF_Path_Planning_2023a_P.IDIST +
                  APF_Path_Planning_2023a_P.IEE) + APF_Path_Planning_2023a_B.t51)
                + APF_Path_Planning_2023a_B.t67) + APF_Path_Planning_2023a_B.t68)
              + APF_Path_Planning_2023a_B.t35) + APF_Path_Planning_2023a_B.t74)
            + APF_Path_Planning_2023a_B.t37;
          APF_Path_Planning_2023a_B.t114_tmp =
            (((((APF_Path_Planning_2023a_B.t100 + APF_Path_Planning_2023a_B.t101)
                + APF_Path_Planning_2023a_B.t92) + APF_Path_Planning_2023a_B.t94)
              + APF_Path_Planning_2023a_B.t95) + APF_Path_Planning_2023a_B.t97) *
            APF_Path_Planning_2023a_B.t45 +
            (APF_Path_Planning_2023a_B.t114_tmp_tmp +
             APF_Path_Planning_2023a_B.t56);
          APF_Path_Planning_2023a_B.t45 = APF_Path_Planning_2023a_P.IEE +
            APF_Path_Planning_2023a_B.t35;
          APF_Path_Planning_2023a_B.t115_tmp = (APF_Path_Planning_2023a_B.t45 +
            APF_Path_Planning_2023a_B.t56) + APF_Path_Planning_2023a_B.t50;
          APF_Path_Planning_2023a_B.t116 = APF_Path_Planning_2023a_B.t45 +
            APF_Path_Planning_2023a_B.t50;
          APF_Path_Planning_2023a_B.InertiaS[0] = APF_Path_Planning_2023a_B.t17;
          APF_Path_Planning_2023a_B.InertiaS[1] = 0.0;
          APF_Path_Planning_2023a_B.InertiaS[2] = APF_Path_Planning_2023a_B.t30;
          APF_Path_Planning_2023a_B.InertiaS[3] = APF_Path_Planning_2023a_B.t96;
          APF_Path_Planning_2023a_B.InertiaS[4] = -APF_Path_Planning_2023a_B.t93
            - APF_Path_Planning_2023a_B.t13 * APF_Path_Planning_2023a_B.t28;
          APF_Path_Planning_2023a_B.InertiaS[5] = -APF_Path_Planning_2023a_B.t93;
          APF_Path_Planning_2023a_B.InertiaS[6] = 0.0;
          APF_Path_Planning_2023a_B.InertiaS[7] = APF_Path_Planning_2023a_B.t17;
          APF_Path_Planning_2023a_B.InertiaS[8] = APF_Path_Planning_2023a_B.t33;
          APF_Path_Planning_2023a_B.InertiaS[9] =
            (-APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1 -
             APF_Path_Planning_2023a_B.t104) - APF_Path_Planning_2023a_B.t105;
          APF_Path_Planning_2023a_B.InertiaS[10] =
            -APF_Path_Planning_2023a_B.t105 - APF_Path_Planning_2023a_B.t24 *
            APF_Path_Planning_2023a_B.t28;
          APF_Path_Planning_2023a_B.InertiaS[11] =
            -APF_Path_Planning_2023a_B.t105;
          APF_Path_Planning_2023a_B.InertiaS[12] = APF_Path_Planning_2023a_B.t30;
          APF_Path_Planning_2023a_B.InertiaS[13] = APF_Path_Planning_2023a_B.t33;
          APF_Path_Planning_2023a_B.InertiaS[14] =
            (((((((((((((((((((((((APF_Path_Planning_2023a_P.IRED +
            APF_Path_Planning_2023a_P.IPROX) + APF_Path_Planning_2023a_P.IDIST)
            + APF_Path_Planning_2023a_P.IEE) +
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_2) +
                               APF_Path_Planning_2023a_B.t51) +
                              APF_Path_Planning_2023a_B.t57) +
                             APF_Path_Planning_2023a_B.t64) +
                            APF_Path_Planning_2023a_B.t65) +
                           APF_Path_Planning_2023a_B.t34) +
                          APF_Path_Planning_2023a_B.t67) +
                         APF_Path_Planning_2023a_B.t68) +
                        APF_Path_Planning_2023a_B.t35) +
                       APF_Path_Planning_2023a_B.t71) +
                      APF_Path_Planning_2023a_B.t72) +
                     APF_Path_Planning_2023a_B.t74) +
                    APF_Path_Planning_2023a_B.t75) +
                   APF_Path_Planning_2023a_B.t76) +
                  APF_Path_Planning_2023a_B.t37) +
                 ((((APF_Path_Planning_2023a_B.t99_tmp_d * 2.0 +
                     APF_Path_Planning_2023a_B.t99_tmp_dy * 2.0) +
                    APF_Path_Planning_2023a_B.t99_tmp * 2.0) +
                   APF_Path_Planning_2023a_B.t99_tmp_lx * 2.0) +
                  APF_Path_Planning_2023a_B.t99_tmp_l * 2.0) *
                 APF_Path_Planning_2023a_B.Sum6_b3) +
                APF_Path_Planning_2023a_P.mPROX *
                APF_Path_Planning_2023a_B.rtb_Sum_b_idx_1) +
               APF_Path_Planning_2023a_P.mDIST *
               APF_Path_Planning_2023a_B.rtb_Sum_b_idx_1) +
              APF_Path_Planning_2023a_P.mEE *
              APF_Path_Planning_2023a_B.rtb_Sum_b_idx_1) -
             ((APF_Path_Planning_2023a_B.t83 * 2.0 +
               APF_Path_Planning_2023a_B.t82 * 2.0) +
              APF_Path_Planning_2023a_B.t81_tmp * 2.0) *
             APF_Path_Planning_2023a_B.t61) - APF_Path_Planning_2023a_B.t113_tmp
            * 2.0;
          APF_Path_Planning_2023a_B.InertiaS[15] = APF_Path_Planning_2023a_B.t99;
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1 =
            (APF_Path_Planning_2023a_B.t114_tmp -
             APF_Path_Planning_2023a_B.t112_tmp) -
            APF_Path_Planning_2023a_B.t113_tmp;
          APF_Path_Planning_2023a_B.InertiaS[16] =
            APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
          APF_Path_Planning_2023a_B.InertiaS[17] =
            APF_Path_Planning_2023a_B.t115_tmp -
            APF_Path_Planning_2023a_B.t113_tmp;
          APF_Path_Planning_2023a_B.InertiaS[18] =
            (-APF_Path_Planning_2023a_B.t7 * APF_Path_Planning_2023a_B.t8 -
             APF_Path_Planning_2023a_B.t91) - APF_Path_Planning_2023a_B.t93;
          APF_Path_Planning_2023a_B.InertiaS[19] =
            (-APF_Path_Planning_2023a_B.t8 * APF_Path_Planning_2023a_B.t23 -
             APF_Path_Planning_2023a_B.t104) - APF_Path_Planning_2023a_B.t105;
          APF_Path_Planning_2023a_B.InertiaS[20] = APF_Path_Planning_2023a_B.t99;
          APF_Path_Planning_2023a_B.InertiaS[21] =
            APF_Path_Planning_2023a_B.t99_tmp_o;
          APF_Path_Planning_2023a_B.InertiaS[22] =
            APF_Path_Planning_2023a_B.t114_tmp;
          APF_Path_Planning_2023a_B.InertiaS[23] =
            APF_Path_Planning_2023a_B.t115_tmp;
          APF_Path_Planning_2023a_B.InertiaS[24] =
            -APF_Path_Planning_2023a_B.t13 * APF_Path_Planning_2023a_B.t28 -
            APF_Path_Planning_2023a_B.t93;
          APF_Path_Planning_2023a_B.InertiaS[25] =
            -APF_Path_Planning_2023a_B.t24 * APF_Path_Planning_2023a_B.t28 -
            APF_Path_Planning_2023a_B.t105;
          APF_Path_Planning_2023a_B.InertiaS[26] =
            APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
          APF_Path_Planning_2023a_B.InertiaS[27] =
            APF_Path_Planning_2023a_B.t114_tmp;
          APF_Path_Planning_2023a_B.InertiaS[28] =
            APF_Path_Planning_2023a_B.t114_tmp_tmp;
          APF_Path_Planning_2023a_B.InertiaS[29] =
            APF_Path_Planning_2023a_B.t116;
          APF_Path_Planning_2023a_B.t7 = -APF_Path_Planning_2023a_P.a3 *
            APF_Path_Planning_2023a_P.mEE;
          APF_Path_Planning_2023a_B.InertiaS[30] = APF_Path_Planning_2023a_B.t7 *
            APF_Path_Planning_2023a_B.t16;
          APF_Path_Planning_2023a_B.InertiaS[31] = APF_Path_Planning_2023a_B.t7 *
            APF_Path_Planning_2023a_B.t25;
          APF_Path_Planning_2023a_B.InertiaS[32] =
            (((APF_Path_Planning_2023a_P.IEE + APF_Path_Planning_2023a_B.t35) +
              APF_Path_Planning_2023a_B.t56) + APF_Path_Planning_2023a_B.t50) -
            APF_Path_Planning_2023a_P.a3 * APF_Path_Planning_2023a_P.b0 *
            APF_Path_Planning_2023a_P.mEE * APF_Path_Planning_2023a_B.t63;
          APF_Path_Planning_2023a_B.InertiaS[33] =
            APF_Path_Planning_2023a_B.t115_tmp;
          APF_Path_Planning_2023a_B.InertiaS[34] =
            APF_Path_Planning_2023a_B.t116;
          APF_Path_Planning_2023a_B.InertiaS[35] = APF_Path_Planning_2023a_B.t45;

          // MATLAB Function: '<S601>/Coriolis Function1' incorporates:
          //   Delay: '<S601>/Delay'

          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_1 =
            (APF_Path_Planning_2023a_P.mDIST *
             APF_Path_Planning_2023a_B.rtb_path_b_idx_1 +
             APF_Path_Planning_2023a_B.t21) + APF_Path_Planning_2023a_P.mEE *
            APF_Path_Planning_2023a_B.rtb_path_b_idx_1;
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1 =
            APF_Path_Planning_2023a_P.mEE *
            APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0 +
            APF_Path_Planning_2023a_B.t_tmp;
          APF_Path_Planning_2023a_B.t16 =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8] *
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_1 +
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9] *
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_1;
          APF_Path_Planning_2023a_B.t21 = cos(APF_Path_Planning_2023a_B.t12_tmp
            + 1.5707963267948966);
          APF_Path_Planning_2023a_B.t25 =
            (APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8] *
             APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1 +
             APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9] *
             APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1) +
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10] *
            APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
          APF_Path_Planning_2023a_B.t13 =
            ((APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 *
              APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8] +
              APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 *
              APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9]) +
             APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 *
             APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10]) +
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[11];
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_1 = sin
            (APF_Path_Planning_2023a_B.t12_tmp + 1.5707963267948966);
          APF_Path_Planning_2023a_B.t12_tmp =
            (APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8] +
             APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9]) +
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10];
          APF_Path_Planning_2023a_B.t8 = APF_Path_Planning_2023a_B.t12_tmp +
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[11];
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_2 = cos
            (APF_Path_Planning_2023a_B.t54);
          APF_Path_Planning_2023a_B.t54 = cos(APF_Path_Planning_2023a_B.t81);
          APF_Path_Planning_2023a_B.Sum6_b3 = cos
            (APF_Path_Planning_2023a_B.t63_tmp);
          APF_Path_Planning_2023a_B.t34 = sin
            (APF_Path_Planning_2023a_DW.Delay_DSTATE_of[4]);
          APF_Path_Planning_2023a_B.t63_tmp = ((((APF_Path_Planning_2023a_B.t92 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10] +
            APF_Path_Planning_2023a_B.t94 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10]) +
            APF_Path_Planning_2023a_B.t95 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10]) +
            APF_Path_Planning_2023a_B.t97 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10]) +
            APF_Path_Planning_2023a_B.t100 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10]) +
            APF_Path_Planning_2023a_B.t101 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10];
          APF_Path_Planning_2023a_B.t35 = sin
            (APF_Path_Planning_2023a_DW.Delay_DSTATE_of[5]);
          APF_Path_Planning_2023a_B.t71 = APF_Path_Planning_2023a_B.t79 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[11] +
            APF_Path_Planning_2023a_B.t51_tmp *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[11];
          APF_Path_Planning_2023a_B.t37 = sin(APF_Path_Planning_2023a_B.t80);
          APF_Path_Planning_2023a_B.t51_tmp = ((APF_Path_Planning_2023a_B.t *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10] +
            APF_Path_Planning_2023a_B.t *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[11]) +
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10]) +
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[11];
          APF_Path_Planning_2023a_B.t79 = APF_Path_Planning_2023a_B.t83 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];
          APF_Path_Planning_2023a_B.t80 = APF_Path_Planning_2023a_B.t82 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];
          APF_Path_Planning_2023a_B.t81 = APF_Path_Planning_2023a_B.t81_tmp *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];
          APF_Path_Planning_2023a_B.t81_tmp = ((((APF_Path_Planning_2023a_B.t83 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9] +
            APF_Path_Planning_2023a_B.t83 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10]) +
            APF_Path_Planning_2023a_B.t82 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9]) +
            APF_Path_Planning_2023a_B.t82 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10]) +
            APF_Path_Planning_2023a_B.t81_tmp *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9]) +
            APF_Path_Planning_2023a_B.t81_tmp *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10];
          APF_Path_Planning_2023a_B.t82 = ((APF_Path_Planning_2023a_B.t81_tmp +
            APF_Path_Planning_2023a_B.t79) + APF_Path_Planning_2023a_B.t80) +
            APF_Path_Planning_2023a_B.t81;
          APF_Path_Planning_2023a_B.t83 = APF_Path_Planning_2023a_B.t113_tmp_tmp
            * APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];
          APF_Path_Planning_2023a_B.t113_tmp_tmp =
            (APF_Path_Planning_2023a_B.t113_tmp_tmp *
             APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9] +
             APF_Path_Planning_2023a_B.t113_tmp_tmp *
             APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10]) +
            APF_Path_Planning_2023a_B.t113_tmp_tmp *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[11];
          APF_Path_Planning_2023a_B.t56 = APF_Path_Planning_2023a_B.t99_tmp_d *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];
          APF_Path_Planning_2023a_B.t17 = APF_Path_Planning_2023a_B.t99_tmp_dy *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];
          APF_Path_Planning_2023a_B.t23 = APF_Path_Planning_2023a_B.t99_tmp *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];
          APF_Path_Planning_2023a_B.t24 = APF_Path_Planning_2023a_B.t99_tmp_lx *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1 =
            APF_Path_Planning_2023a_B.t99_tmp_l *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];
          APF_Path_Planning_2023a_B.t28 = APF_Path_Planning_2023a_B.t92 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];
          APF_Path_Planning_2023a_B.t91 = APF_Path_Planning_2023a_B.t94 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];
          APF_Path_Planning_2023a_B.t92 *=
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9];
          APF_Path_Planning_2023a_B.t93 = APF_Path_Planning_2023a_B.t95 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];
          APF_Path_Planning_2023a_B.t94 *=
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9];
          APF_Path_Planning_2023a_B.t95 *=
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9];
          APF_Path_Planning_2023a_B.t96 = APF_Path_Planning_2023a_B.t97 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];
          APF_Path_Planning_2023a_B.t97 *=
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9];
          APF_Path_Planning_2023a_B.t30 = APF_Path_Planning_2023a_B.t100 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];
          APF_Path_Planning_2023a_B.t99 = APF_Path_Planning_2023a_B.t100 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9];
          APF_Path_Planning_2023a_B.t100 = APF_Path_Planning_2023a_B.t101 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];
          APF_Path_Planning_2023a_B.t101 *=
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9];
          APF_Path_Planning_2023a_B.t63 = APF_Path_Planning_2023a_B.t *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];
          APF_Path_Planning_2023a_B.t104 = APF_Path_Planning_2023a_B.t *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9];
          APF_Path_Planning_2023a_B.t105 =
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];
          APF_Path_Planning_2023a_B.t33 =
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9];
          APF_Path_Planning_2023a_B.t51 = APF_Path_Planning_2023a_B.Sum6_b3 *
            APF_Path_Planning_2023a_B.t83;
          APF_Path_Planning_2023a_B.t57 =
            (((((((((((APF_Path_Planning_2023a_B.t28 +
                       APF_Path_Planning_2023a_B.t91) +
                      APF_Path_Planning_2023a_B.t92) +
                     APF_Path_Planning_2023a_B.t93) +
                    APF_Path_Planning_2023a_B.t94) +
                   APF_Path_Planning_2023a_B.t95) +
                  APF_Path_Planning_2023a_B.t96) + APF_Path_Planning_2023a_B.t97)
                + APF_Path_Planning_2023a_B.t30) + APF_Path_Planning_2023a_B.t99)
              + APF_Path_Planning_2023a_B.t100) + APF_Path_Planning_2023a_B.t101)
            * APF_Path_Planning_2023a_B.t34;
          APF_Path_Planning_2023a_B.t61 = (((APF_Path_Planning_2023a_B.t63 +
            APF_Path_Planning_2023a_B.t104) + APF_Path_Planning_2023a_B.t105) +
            APF_Path_Planning_2023a_B.t33) * APF_Path_Planning_2023a_B.t37;
          APF_Path_Planning_2023a_B.t64 = (((((APF_Path_Planning_2023a_P.a2 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8] +
            APF_Path_Planning_2023a_P.a2 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9]) +
            APF_Path_Planning_2023a_P.a2 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10]) +
            APF_Path_Planning_2023a_P.b2 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8]) +
            APF_Path_Planning_2023a_P.b2 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9]) +
            APF_Path_Planning_2023a_P.b2 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10]) *
            (APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 *
             APF_Path_Planning_2023a_B.t35);
          APF_Path_Planning_2023a_B.t65 = (((APF_Path_Planning_2023a_P.a1 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8] +
            APF_Path_Planning_2023a_P.a1 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9]) +
            APF_Path_Planning_2023a_P.b1 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8]) +
            APF_Path_Planning_2023a_P.b1 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9]) *
            (APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 *
             APF_Path_Planning_2023a_B.t37);

          // MATLAB Function: '<S601>/Dynamics Model'
          APF_Path_Planning_2023a_B.p = true;
          for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
               36; APF_Path_Planning_2023a_B.r_b++) {
            APF_Path_Planning_2023a_B.a[APF_Path_Planning_2023a_B.r_b] = 0.0;
            if (APF_Path_Planning_2023a_B.p) {
              APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
                APF_Path_Planning_2023a_B.InertiaS[APF_Path_Planning_2023a_B.r_b];
              if (rtIsInf(APF_Path_Planning_2023a_B.rtb_path_b_idx_0) || rtIsNaN
                  (APF_Path_Planning_2023a_B.rtb_path_b_idx_0)) {
                APF_Path_Planning_2023a_B.p = false;
              }
            }
          }

          if (!APF_Path_Planning_2023a_B.p) {
            for (APF_Path_Planning_2023a_B.r_b = 0;
                 APF_Path_Planning_2023a_B.r_b < 36;
                 APF_Path_Planning_2023a_B.r_b++) {
              APF_Path_Planning_2023a_B.a[APF_Path_Planning_2023a_B.r_b] =
                (rtNaN);
            }
          } else {
            APF_Path_Planning_2023a_svd(APF_Path_Planning_2023a_B.InertiaS,
              APF_Path_Planning_2023a_B.U,
              APF_Path_Planning_2023a_B.TmpSignalConversionAtSFunct,
              APF_Path_Planning_2023a_B.V);
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 = fabs
              (APF_Path_Planning_2023a_B.TmpSignalConversionAtSFunct[0]);
            if (rtIsInf(APF_Path_Planning_2023a_B.rtb_path_b_idx_0) || rtIsNaN
                (APF_Path_Planning_2023a_B.rtb_path_b_idx_0)) {
              APF_Path_Planning_2023a_B.rtb_path_b_idx_0 = (rtNaN);
            } else if (APF_Path_Planning_2023a_B.rtb_path_b_idx_0 <
                       4.4501477170144028E-308) {
              APF_Path_Planning_2023a_B.rtb_path_b_idx_0 = 4.94065645841247E-324;
            } else {
              frexp(APF_Path_Planning_2023a_B.rtb_path_b_idx_0,
                    &APF_Path_Planning_2023a_B.exponent);
              APF_Path_Planning_2023a_B.rtb_path_b_idx_0 = ldexp(1.0,
                APF_Path_Planning_2023a_B.exponent - 53);
            }

            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 *= 6.0;
            APF_Path_Planning_2023a_B.r_b = -1;
            APF_Path_Planning_2023a_B.exponent = 0;
            while ((APF_Path_Planning_2023a_B.exponent < 6) &&
                   (APF_Path_Planning_2023a_B.TmpSignalConversionAtSFunct[APF_Path_Planning_2023a_B.exponent]
                    > APF_Path_Planning_2023a_B.rtb_path_b_idx_0)) {
              APF_Path_Planning_2023a_B.r_b++;
              APF_Path_Planning_2023a_B.exponent++;
            }

            if (APF_Path_Planning_2023a_B.r_b + 1 > 0) {
              APF_Path_Planning_2023a_B.vcol = 1;
              for (APF_Path_Planning_2023a_B.exponent = 0;
                   APF_Path_Planning_2023a_B.exponent <=
                   APF_Path_Planning_2023a_B.r_b;
                   APF_Path_Planning_2023a_B.exponent++) {
                APF_Path_Planning_2023a_B.rtb_path_b_idx_0 = 1.0 /
                  APF_Path_Planning_2023a_B.TmpSignalConversionAtSFunct[APF_Path_Planning_2023a_B.exponent];
                for (APF_Path_Planning_2023a_B.trueCount =
                     APF_Path_Planning_2023a_B.vcol;
                     APF_Path_Planning_2023a_B.trueCount <=
                     APF_Path_Planning_2023a_B.vcol + 5;
                     APF_Path_Planning_2023a_B.trueCount++) {
                  APF_Path_Planning_2023a_B.V[APF_Path_Planning_2023a_B.trueCount
                    - 1] *= APF_Path_Planning_2023a_B.rtb_path_b_idx_0;
                }

                APF_Path_Planning_2023a_B.vcol += 6;
              }

              for (APF_Path_Planning_2023a_B.exponent = 0;
                   APF_Path_Planning_2023a_B.exponent <= 30;
                   APF_Path_Planning_2023a_B.exponent += 6) {
                for (APF_Path_Planning_2023a_B.trueCount =
                     APF_Path_Planning_2023a_B.exponent + 1;
                     APF_Path_Planning_2023a_B.trueCount <=
                     APF_Path_Planning_2023a_B.exponent + 6;
                     APF_Path_Planning_2023a_B.trueCount++) {
                  APF_Path_Planning_2023a_B.a[APF_Path_Planning_2023a_B.trueCount
                    - 1] = 0.0;
                }
              }

              APF_Path_Planning_2023a_B.br = 0;
              for (APF_Path_Planning_2023a_B.exponent = 0;
                   APF_Path_Planning_2023a_B.exponent <= 30;
                   APF_Path_Planning_2023a_B.exponent += 6) {
                APF_Path_Planning_2023a_B.ar = -1;
                APF_Path_Planning_2023a_B.br++;
                APF_Path_Planning_2023a_B.b_j = 6 *
                  APF_Path_Planning_2023a_B.r_b + APF_Path_Planning_2023a_B.br;
                for (APF_Path_Planning_2023a_B.trueCount =
                     APF_Path_Planning_2023a_B.br;
                     APF_Path_Planning_2023a_B.trueCount <=
                     APF_Path_Planning_2023a_B.b_j;
                     APF_Path_Planning_2023a_B.trueCount += 6) {
                  for (APF_Path_Planning_2023a_B.vcol =
                       APF_Path_Planning_2023a_B.exponent + 1;
                       APF_Path_Planning_2023a_B.vcol <=
                       APF_Path_Planning_2023a_B.exponent + 6;
                       APF_Path_Planning_2023a_B.vcol++) {
                    APF_Path_Planning_2023a_B.a[APF_Path_Planning_2023a_B.vcol -
                      1] += APF_Path_Planning_2023a_B.V
                      [(APF_Path_Planning_2023a_B.ar +
                        APF_Path_Planning_2023a_B.vcol) -
                      APF_Path_Planning_2023a_B.exponent] *
                      APF_Path_Planning_2023a_B.U[APF_Path_Planning_2023a_B.trueCount
                      - 1];
                  }

                  APF_Path_Planning_2023a_B.ar += 6;
                }
              }
            }
          }

          // MATLAB Function: '<S601>/Coriolis Function1' incorporates:
          //   Delay: '<S601>/Delay'

          memset(&APF_Path_Planning_2023a_B.InertiaS[0], 0, 12U * sizeof(real_T));
          APF_Path_Planning_2023a_B.t = cos
            (APF_Path_Planning_2023a_B.link2_com_y + 1.5707963267948966) *
            APF_Path_Planning_2023a_B.t13;
          APF_Path_Planning_2023a_B.rtb_path_b_idx_0 = (-cos
            (APF_Path_Planning_2023a_B.t6_tmp + 1.5707963267948966) *
            APF_Path_Planning_2023a_B.t16 - APF_Path_Planning_2023a_B.t21 *
            APF_Path_Planning_2023a_B.t25) - APF_Path_Planning_2023a_B.t;
          APF_Path_Planning_2023a_B.t21_tmp *=
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];
          APF_Path_Planning_2023a_B.InertiaS[12] =
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 -
            APF_Path_Planning_2023a_B.t21_tmp *
            APF_Path_Planning_2023a_B.t22_tmp;
          APF_Path_Planning_2023a_B.t13 *= sin
            (APF_Path_Planning_2023a_B.link2_com_y + 1.5707963267948966);
          APF_Path_Planning_2023a_B.t6_tmp = (sin
            (APF_Path_Planning_2023a_B.t6_tmp + 1.5707963267948966) *
            -APF_Path_Planning_2023a_B.t16 - APF_Path_Planning_2023a_B.t25 *
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_1) -
            APF_Path_Planning_2023a_B.t13;
          APF_Path_Planning_2023a_B.InertiaS[13] =
            APF_Path_Planning_2023a_B.t6_tmp - APF_Path_Planning_2023a_B.t21_tmp
            * APF_Path_Planning_2023a_B.t30_tmp;
          APF_Path_Planning_2023a_B.t21_tmp = APF_Path_Planning_2023a_B.t35 *
            APF_Path_Planning_2023a_B.t71;
          APF_Path_Planning_2023a_B.t22_tmp = APF_Path_Planning_2023a_B.t37 *
            APF_Path_Planning_2023a_B.t51_tmp;
          APF_Path_Planning_2023a_B.t16 = -APF_Path_Planning_2023a_B.t34 *
            APF_Path_Planning_2023a_B.t63_tmp;
          APF_Path_Planning_2023a_B.t99_tmp =
            (((APF_Path_Planning_2023a_B.t99_tmp_d *
               APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9] +
               APF_Path_Planning_2023a_B.t99_tmp_dy *
               APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9]) +
              APF_Path_Planning_2023a_B.t99_tmp *
              APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9]) +
             APF_Path_Planning_2023a_B.t99_tmp_lx *
             APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9]) +
            APF_Path_Planning_2023a_B.t99_tmp_l *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9];
          APF_Path_Planning_2023a_B.t99_tmp_l = (APF_Path_Planning_2023a_B.t16 -
            APF_Path_Planning_2023a_B.t21_tmp) -
            APF_Path_Planning_2023a_B.t22_tmp;
          APF_Path_Planning_2023a_B.InertiaS[14] =
            ((APF_Path_Planning_2023a_B.t99_tmp_l -
              APF_Path_Planning_2023a_B.t99_tmp *
              APF_Path_Planning_2023a_B.rtb_Sum_b_idx_2) -
             APF_Path_Planning_2023a_B.t113_tmp_tmp *
             APF_Path_Planning_2023a_B.Sum6_b3) -
            APF_Path_Planning_2023a_B.t81_tmp * APF_Path_Planning_2023a_B.t54;
          APF_Path_Planning_2023a_B.t99_tmp_d = ((APF_Path_Planning_2023a_B.t79
            + APF_Path_Planning_2023a_B.t80) + APF_Path_Planning_2023a_B.t81) *
            APF_Path_Planning_2023a_B.t54 + APF_Path_Planning_2023a_B.t51;
          APF_Path_Planning_2023a_B.InertiaS[15] =
            ((((APF_Path_Planning_2023a_B.t56 + APF_Path_Planning_2023a_B.t17) +
               APF_Path_Planning_2023a_B.t23) + APF_Path_Planning_2023a_B.t24) +
             APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1) *
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_2 +
            (((APF_Path_Planning_2023a_B.t99_tmp_d -
               APF_Path_Planning_2023a_B.t34 * APF_Path_Planning_2023a_B.t63_tmp)
              - APF_Path_Planning_2023a_B.t21_tmp) -
             APF_Path_Planning_2023a_B.t22_tmp);
          APF_Path_Planning_2023a_B.InertiaS[16] =
            ((APF_Path_Planning_2023a_B.t99_tmp_d +
              APF_Path_Planning_2023a_B.t57) + APF_Path_Planning_2023a_B.t61) -
            APF_Path_Planning_2023a_B.t21_tmp;
          APF_Path_Planning_2023a_B.InertiaS[17] =
            (APF_Path_Planning_2023a_B.t51 + APF_Path_Planning_2023a_B.t64) +
            APF_Path_Planning_2023a_B.t65;
          APF_Path_Planning_2023a_B.InertiaS[18] =
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0;
          APF_Path_Planning_2023a_B.InertiaS[19] =
            APF_Path_Planning_2023a_B.t6_tmp;
          APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
            (APF_Path_Planning_2023a_B.t113_tmp_tmp +
             APF_Path_Planning_2023a_B.t83) * APF_Path_Planning_2023a_B.Sum6_b3;
          APF_Path_Planning_2023a_B.InertiaS[20] =
            ((((APF_Path_Planning_2023a_B.t16 - APF_Path_Planning_2023a_B.t54 *
                APF_Path_Planning_2023a_B.t82) -
               APF_Path_Planning_2023a_B.t21_tmp) -
              APF_Path_Planning_2023a_B.rtb_path_b_idx_0) -
             APF_Path_Planning_2023a_B.t22_tmp) -
            (((((APF_Path_Planning_2023a_B.t99_tmp +
                 APF_Path_Planning_2023a_B.t56) + APF_Path_Planning_2023a_B.t17)
               + APF_Path_Planning_2023a_B.t23) + APF_Path_Planning_2023a_B.t24)
             + APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1) *
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_2;
          APF_Path_Planning_2023a_B.InertiaS[21] =
            APF_Path_Planning_2023a_B.t99_tmp_l;
          APF_Path_Planning_2023a_B.InertiaS[22] =
            (APF_Path_Planning_2023a_B.t57 + APF_Path_Planning_2023a_B.t61) -
            APF_Path_Planning_2023a_B.t21_tmp;
          APF_Path_Planning_2023a_B.InertiaS[23] = APF_Path_Planning_2023a_B.t64
            + APF_Path_Planning_2023a_B.t65;
          APF_Path_Planning_2023a_B.InertiaS[24] =
            -APF_Path_Planning_2023a_B.t21 * APF_Path_Planning_2023a_B.t25 -
            APF_Path_Planning_2023a_B.t;
          APF_Path_Planning_2023a_B.InertiaS[25] =
            -APF_Path_Planning_2023a_B.t25 *
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_1 -
            APF_Path_Planning_2023a_B.t13;
          APF_Path_Planning_2023a_B.t =
            ((((((((((((APF_Path_Planning_2023a_B.t63_tmp +
                        APF_Path_Planning_2023a_B.t28) +
                       APF_Path_Planning_2023a_B.t91) +
                      APF_Path_Planning_2023a_B.t92) +
                     APF_Path_Planning_2023a_B.t93) +
                    APF_Path_Planning_2023a_B.t94) +
                   APF_Path_Planning_2023a_B.t95) +
                  APF_Path_Planning_2023a_B.t96) + APF_Path_Planning_2023a_B.t97)
                + APF_Path_Planning_2023a_B.t30) + APF_Path_Planning_2023a_B.t99)
              + APF_Path_Planning_2023a_B.t100) + APF_Path_Planning_2023a_B.t101)
            * APF_Path_Planning_2023a_B.t34;
          APF_Path_Planning_2023a_B.t13 = ((((APF_Path_Planning_2023a_B.t51_tmp
            + APF_Path_Planning_2023a_B.t63) + APF_Path_Planning_2023a_B.t104) +
            APF_Path_Planning_2023a_B.t105) + APF_Path_Planning_2023a_B.t33) *
            APF_Path_Planning_2023a_B.t37;
          APF_Path_Planning_2023a_B.InertiaS[26] =
            (((-APF_Path_Planning_2023a_B.t54 * APF_Path_Planning_2023a_B.t82 -
               APF_Path_Planning_2023a_B.t21_tmp) -
              APF_Path_Planning_2023a_B.rtb_path_b_idx_0) -
             APF_Path_Planning_2023a_B.t) - APF_Path_Planning_2023a_B.t13;
          APF_Path_Planning_2023a_B.InertiaS[27] =
            (-APF_Path_Planning_2023a_B.t35 * APF_Path_Planning_2023a_B.t71 -
             APF_Path_Planning_2023a_B.t) - APF_Path_Planning_2023a_B.t13;
          APF_Path_Planning_2023a_B.InertiaS[28] = APF_Path_Planning_2023a_B.t7 *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[11] *
            APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0 *
            APF_Path_Planning_2023a_B.t35;
          APF_Path_Planning_2023a_B.t =
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 *
            APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0;
          APF_Path_Planning_2023a_B.InertiaS[29] = APF_Path_Planning_2023a_B.t *
            APF_Path_Planning_2023a_B.t35 * APF_Path_Planning_2023a_B.t12_tmp;
          APF_Path_Planning_2023a_B.InertiaS[30] =
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 *
            APF_Path_Planning_2023a_B.t8 * sin
            (APF_Path_Planning_2023a_B.link2_com_y);
          APF_Path_Planning_2023a_B.InertiaS[31] = APF_Path_Planning_2023a_B.t7 *
            APF_Path_Planning_2023a_B.t8 * cos
            (APF_Path_Planning_2023a_B.link2_com_y);
          APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 *
            APF_Path_Planning_2023a_B.rtb_path_b_idx_1 *
            APF_Path_Planning_2023a_B.t8 * APF_Path_Planning_2023a_B.t37;
          APF_Path_Planning_2023a_B.InertiaS[32] =
            (-APF_Path_Planning_2023a_P.a3 * APF_Path_Planning_2023a_P.b0 *
             APF_Path_Planning_2023a_P.mEE * APF_Path_Planning_2023a_B.t8 *
             APF_Path_Planning_2023a_B.Sum6_b3 - APF_Path_Planning_2023a_B.t *
             APF_Path_Planning_2023a_B.t8 * APF_Path_Planning_2023a_B.t35) -
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0;
          APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_B.t7 *
            APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0 *
            APF_Path_Planning_2023a_B.t8 * APF_Path_Planning_2023a_B.t35;
          APF_Path_Planning_2023a_B.InertiaS[33] = APF_Path_Planning_2023a_B.t -
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0;
          APF_Path_Planning_2023a_B.InertiaS[34] = APF_Path_Planning_2023a_B.t;
          APF_Path_Planning_2023a_B.InertiaS[35] = 0.0;

          // SignalConversion generated from: '<S603>/ SFunction ' incorporates:
          //   DataStoreRead: '<S601>/RED_Fx_Sat1'
          //   DataStoreRead: '<S601>/RED_Fy_Sat1'
          //   DataStoreRead: '<S601>/RED_Tz_Sat1'
          //   DataStoreRead: '<S601>/RED_Tz_Sat2'
          //   DataStoreRead: '<S601>/RED_Tz_Sat3'
          //   DataStoreRead: '<S601>/RED_Tz_Sat4'
          //   MATLAB Function: '<S601>/Dynamics Model'

          APF_Path_Planning_2023a_B.TmpSignalConversionAtSFunct[0] =
            APF_Path_Planning_2023a_DW.RED_Fx_Sat;
          APF_Path_Planning_2023a_B.TmpSignalConversionAtSFunct[1] =
            APF_Path_Planning_2023a_DW.RED_Fy_Sat;
          APF_Path_Planning_2023a_B.TmpSignalConversionAtSFunct[2] =
            APF_Path_Planning_2023a_DW.RED_Tz_Sat;
          APF_Path_Planning_2023a_B.TmpSignalConversionAtSFunct[3] =
            APF_Path_Planning_2023a_DW.RED_Shoulder_Command;
          APF_Path_Planning_2023a_B.TmpSignalConversionAtSFunct[4] =
            APF_Path_Planning_2023a_DW.RED_Elbow_Command;
          APF_Path_Planning_2023a_B.TmpSignalConversionAtSFunct[5] =
            APF_Path_Planning_2023a_DW.RED_Wrist_Command;

          // MATLAB Function: '<S601>/Dynamics Model' incorporates:
          //   Delay: '<S601>/Delay'

          APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[0] = 0.0;
          APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[1] = 0.0;
          APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[2] = 0.0;
          APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[3] = ((tanh
            (APF_Path_Planning_2023a_P.Gamma2_sh *
             APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9]) - tanh
            (APF_Path_Planning_2023a_P.Gamma3_sh *
             APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9])) *
            APF_Path_Planning_2023a_P.Gamma1_sh + tanh
            (APF_Path_Planning_2023a_P.Gamma5_sh *
             APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9]) *
            APF_Path_Planning_2023a_P.Gamma4_sh) +
            APF_Path_Planning_2023a_P.Gamma6_sh *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9];
          APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[4] = ((tanh
            (APF_Path_Planning_2023a_P.Gamma2_el *
             APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10]) - tanh
            (APF_Path_Planning_2023a_P.Gamma3_el *
             APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10])) *
            APF_Path_Planning_2023a_P.Gamma1_el + tanh
            (APF_Path_Planning_2023a_P.Gamma5_el *
             APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10]) *
            APF_Path_Planning_2023a_P.Gamma4_el) +
            APF_Path_Planning_2023a_P.Gamma6_el *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10];
          APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[5] = ((tanh
            (APF_Path_Planning_2023a_P.Gamma2_wr *
             APF_Path_Planning_2023a_DW.Delay_DSTATE_of[11]) - tanh
            (APF_Path_Planning_2023a_P.Gamma3_wr *
             APF_Path_Planning_2023a_DW.Delay_DSTATE_of[11])) *
            APF_Path_Planning_2023a_P.Gamma1_wr + tanh
            (APF_Path_Planning_2023a_P.Gamma5_wr *
             APF_Path_Planning_2023a_DW.Delay_DSTATE_of[11]) *
            APF_Path_Planning_2023a_P.Gamma4_wr) +
            APF_Path_Planning_2023a_P.Gamma6_wr *
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[11];
          for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
               6; APF_Path_Planning_2023a_B.r_b++) {
            APF_Path_Planning_2023a_B.t = 0.0;
            for (APF_Path_Planning_2023a_B.exponent = 0;
                 APF_Path_Planning_2023a_B.exponent < 6;
                 APF_Path_Planning_2023a_B.exponent++) {
              APF_Path_Planning_2023a_B.t += APF_Path_Planning_2023a_B.InertiaS
                [6 * APF_Path_Planning_2023a_B.exponent +
                APF_Path_Planning_2023a_B.r_b] *
                APF_Path_Planning_2023a_DW.Delay_DSTATE_of[APF_Path_Planning_2023a_B.exponent
                + 6];
            }

            APF_Path_Planning_2023a_B.state_red[APF_Path_Planning_2023a_B.r_b] =
              (APF_Path_Planning_2023a_B.TmpSignalConversionAtSFunct[APF_Path_Planning_2023a_B.r_b]
               - APF_Path_Planning_2023a_B.t) -
              APF_Path_Planning_2023a_B.rtb_TmpSignalConversionAtSFun_g[APF_Path_Planning_2023a_B.r_b];
          }

          for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
               6; APF_Path_Planning_2023a_B.r_b++) {
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0 = 0.0;
            for (APF_Path_Planning_2023a_B.exponent = 0;
                 APF_Path_Planning_2023a_B.exponent < 6;
                 APF_Path_Planning_2023a_B.exponent++) {
              APF_Path_Planning_2023a_B.rtb_path_b_idx_0 +=
                APF_Path_Planning_2023a_B.a[6 *
                APF_Path_Planning_2023a_B.exponent +
                APF_Path_Planning_2023a_B.r_b] *
                APF_Path_Planning_2023a_B.state_red[APF_Path_Planning_2023a_B.exponent];
            }

            // DiscreteIntegrator: '<S601>/Acceleration  to Velocity'
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[APF_Path_Planning_2023a_B.r_b]
              =
              APF_Path_Planning_2023a_DW.Delay_DSTATE_of[APF_Path_Planning_2023a_B.r_b
              + 6] * APF_Path_Planning_2023a_P.AccelerationtoVelocity_gainval +
              APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_f[APF_Path_Planning_2023a_B.r_b];
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[APF_Path_Planning_2023a_B.r_b
              + 6] =
              APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_f[APF_Path_Planning_2023a_B.r_b
              + 6] + APF_Path_Planning_2023a_P.AccelerationtoVelocity_gainval *
              APF_Path_Planning_2023a_B.rtb_path_b_idx_0;
          }

          // DataStoreWrite: '<S601>/Data Store Write' incorporates:
          //   Delay: '<S601>/Delay'

          APF_Path_Planning_2023a_DW.RED_Rz_Shoulder =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[3];

          // DataStoreWrite: '<S601>/Data Store Write1' incorporates:
          //   Delay: '<S601>/Delay'

          APF_Path_Planning_2023a_DW.RED_Rz_Elbow =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[4];

          // DataStoreWrite: '<S601>/Data Store Write2' incorporates:
          //   Delay: '<S601>/Delay'

          APF_Path_Planning_2023a_DW.RED_Rz_Wrist =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[5];

          // DataStoreWrite: '<S601>/Data Store Write6' incorporates:
          //   Delay: '<S601>/Delay'

          APF_Path_Planning_2023a_DW.RED_RzD_Shoulder =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[9];

          // DataStoreWrite: '<S601>/Data Store Write7' incorporates:
          //   Delay: '<S601>/Delay'

          APF_Path_Planning_2023a_DW.RED_RzD_Elbow =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[10];

          // DataStoreWrite: '<S601>/Data Store Write8' incorporates:
          //   Delay: '<S601>/Delay'

          APF_Path_Planning_2023a_DW.RED_RzD_Wrist =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[11];

          // Delay: '<S606>/Delay1' incorporates:
          //   Delay: '<S601>/Delay'

          if (APF_Path_Planning_2023a_DW.icLoad_bs) {
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_by =
              APF_Path_Planning_2023a_DW.Delay_DSTATE_of[6];
          }

          // Sum: '<S606>/Sum6' incorporates:
          //   Delay: '<S601>/Delay'
          //   Delay: '<S606>/Delay1'

          APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[6] -
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_by;

          // If: '<S606>/if we went through a "step"'
          if (APF_Path_Planning_2023a_B.rtb_path_b_idx_0 != 0.0) {
            // Outputs for IfAction SubSystem: '<S606>/Hold this value' incorporates:
            //   ActionPort: '<S609>/Action Port'

            // SignalConversion generated from: '<S609>/In1'
            APF_Path_Planning_2023a_B.In1_ff =
              APF_Path_Planning_2023a_B.rtb_path_b_idx_0;

            // End of Outputs for SubSystem: '<S606>/Hold this value'
          }

          // End of If: '<S606>/if we went through a "step"'

          // Sum: '<S601>/Sum2' incorporates:
          //   DataStoreWrite: '<S601>/RED_IMU_Ay1'
          //   Gain: '<S606>/divide by delta T'
          //   RandomNumber: '<S601>/Random Number2'

          APF_Path_Planning_2023a_DW.RED_Ax = 1.0 /
            APF_Path_Planning_2023a_P.baseRate *
            APF_Path_Planning_2023a_B.In1_ff +
            APF_Path_Planning_2023a_DW.NextOutput_f;

          // Delay: '<S605>/Delay1' incorporates:
          //   Delay: '<S601>/Delay'

          if (APF_Path_Planning_2023a_DW.icLoad_n5) {
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_ny =
              APF_Path_Planning_2023a_DW.Delay_DSTATE_of[7];
          }

          // Sum: '<S605>/Sum6' incorporates:
          //   Delay: '<S601>/Delay'
          //   Delay: '<S605>/Delay1'

          APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[7] -
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_ny;

          // If: '<S605>/if we went through a "step"'
          if (APF_Path_Planning_2023a_B.rtb_path_b_idx_0 != 0.0) {
            // Outputs for IfAction SubSystem: '<S605>/Hold this value' incorporates:
            //   ActionPort: '<S608>/Action Port'

            // SignalConversion generated from: '<S608>/In1'
            APF_Path_Planning_2023a_B.In1_n =
              APF_Path_Planning_2023a_B.rtb_path_b_idx_0;

            // End of Outputs for SubSystem: '<S605>/Hold this value'
          }

          // End of If: '<S605>/if we went through a "step"'

          // Sum: '<S601>/Sum3' incorporates:
          //   DataStoreWrite: '<S601>/RED_IMU_Ay_I1'
          //   Gain: '<S605>/divide by delta T'
          //   RandomNumber: '<S601>/Random Number1'

          APF_Path_Planning_2023a_DW.RED_Ay = 1.0 /
            APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_n
            + APF_Path_Planning_2023a_DW.NextOutput_h;

          // Delay: '<S607>/Delay1' incorporates:
          //   Delay: '<S601>/Delay'

          if (APF_Path_Planning_2023a_DW.icLoad_mj) {
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_nb =
              APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];
          }

          // Sum: '<S607>/Sum6' incorporates:
          //   Delay: '<S601>/Delay'
          //   Delay: '<S607>/Delay1'

          APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8] -
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_nb;

          // If: '<S607>/if we went through a "step"'
          if (APF_Path_Planning_2023a_B.rtb_path_b_idx_0 != 0.0) {
            // Outputs for IfAction SubSystem: '<S607>/Hold this value' incorporates:
            //   ActionPort: '<S610>/Action Port'

            // SignalConversion generated from: '<S610>/In1'
            APF_Path_Planning_2023a_B.In1_h =
              APF_Path_Planning_2023a_B.rtb_path_b_idx_0;

            // End of Outputs for SubSystem: '<S607>/Hold this value'
          }

          // End of If: '<S607>/if we went through a "step"'

          // Sum: '<S601>/Sum4' incorporates:
          //   DataStoreWrite: '<S601>/RED_IMU_R1'
          //   Gain: '<S607>/divide by delta T'
          //   RandomNumber: '<S601>/Random Number3'

          APF_Path_Planning_2023a_DW.RED_RzDD = 1.0 /
            APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_h
            + APF_Path_Planning_2023a_DW.NextOutput_go;

          // DataStoreWrite: '<S601>/RED_Px1' incorporates:
          //   Delay: '<S601>/Delay'

          APF_Path_Planning_2023a_DW.RED_Px =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[0];
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            rtsiSetBlockStateForSolverChangedAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
            rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
          }

          // End of DataStoreWrite: '<S601>/RED_Px1'

          // DataStoreWrite: '<S601>/RED_Py1' incorporates:
          //   Delay: '<S601>/Delay'

          APF_Path_Planning_2023a_DW.RED_Py =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[1];
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            rtsiSetBlockStateForSolverChangedAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
            rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
          }

          // End of DataStoreWrite: '<S601>/RED_Py1'

          // DataStoreWrite: '<S601>/RED_Rz1' incorporates:
          //   Delay: '<S601>/Delay'

          APF_Path_Planning_2023a_DW.RED_Rz =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[2];
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            rtsiSetBlockStateForSolverChangedAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
            rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
          }

          // End of DataStoreWrite: '<S601>/RED_Rz1'

          // DataStoreWrite: '<S601>/RED_RzD1' incorporates:
          //   Delay: '<S601>/Delay'

          APF_Path_Planning_2023a_DW.RED_RzD =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            rtsiSetBlockStateForSolverChangedAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
            rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
          }

          // End of DataStoreWrite: '<S601>/RED_RzD1'

          // DataStoreWrite: '<S601>/RED_Vx1' incorporates:
          //   Delay: '<S601>/Delay'

          APF_Path_Planning_2023a_DW.RED_Vx =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[6];
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            rtsiSetBlockStateForSolverChangedAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
            rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
          }

          // End of DataStoreWrite: '<S601>/RED_Vx1'

          // DataStoreWrite: '<S601>/RED_Vy1' incorporates:
          //   Delay: '<S601>/Delay'

          APF_Path_Planning_2023a_DW.RED_Vy =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[7];
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            rtsiSetBlockStateForSolverChangedAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
            rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
          }

          // End of DataStoreWrite: '<S601>/RED_Vy1'

          // Update for DiscreteIntegrator: '<S601>/Acceleration  to Velocity' incorporates:
          //   Delay: '<S601>/Delay'

          memcpy(&APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_f[0],
                 &APF_Path_Planning_2023a_DW.Delay_DSTATE_of[0], 12U * sizeof
                 (real_T));

          // Update for Delay: '<S606>/Delay1' incorporates:
          //   Delay: '<S601>/Delay'

          APF_Path_Planning_2023a_DW.icLoad_bs = false;
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_by =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[6];

          // Update for RandomNumber: '<S601>/Random Number2'
          APF_Path_Planning_2023a_DW.NextOutput_f =
            APF__rt_nrand_Upu32_Yd_f_pw_snf
            (&APF_Path_Planning_2023a_DW.RandSeed_av) *
            APF_Path_Planning_2023a_P.RandomNumber2_StdDev +
            APF_Path_Planning_2023a_P.RandomNumber2_Mean;

          // Update for Delay: '<S605>/Delay1' incorporates:
          //   Delay: '<S601>/Delay'

          APF_Path_Planning_2023a_DW.icLoad_n5 = false;
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_ny =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[7];

          // Update for RandomNumber: '<S601>/Random Number1'
          APF_Path_Planning_2023a_DW.NextOutput_h =
            APF__rt_nrand_Upu32_Yd_f_pw_snf
            (&APF_Path_Planning_2023a_DW.RandSeed_a4) *
            APF_Path_Planning_2023a_P.RandomNumber1_StdDev +
            APF_Path_Planning_2023a_P.RandomNumber1_Mean;

          // Update for Delay: '<S607>/Delay1' incorporates:
          //   Delay: '<S601>/Delay'

          APF_Path_Planning_2023a_DW.icLoad_mj = false;
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_nb =
            APF_Path_Planning_2023a_DW.Delay_DSTATE_of[8];

          // Update for RandomNumber: '<S601>/Random Number3'
          APF_Path_Planning_2023a_DW.NextOutput_go =
            APF__rt_nrand_Upu32_Yd_f_pw_snf
            (&APF_Path_Planning_2023a_DW.RandSeed_i) *
            APF_Path_Planning_2023a_P.RandomNumber3_StdDev +
            APF_Path_Planning_2023a_P.RandomNumber3_Mean;

          // End of Outputs for SubSystem: '<S570>/RED + ARM'
        } else {
          // Outputs for IfAction SubSystem: '<S570>/RED Only' incorporates:
          //   ActionPort: '<S600>/Action Port'

          // DiscreteIntegrator: '<S612>/Acceleration  to Velocity' incorporates:
          //   DataStoreRead: '<S611>/RED_Fx_Sat'
          //   MATLAB Function: '<S612>/MATLAB Function'
          //   SignalConversion generated from: '<S619>/ SFunction '

          APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_DW.RED_Fx_Sat /
            APF_Path_Planning_2023a_P.mRED *
            APF_Path_Planning_2023a_P.AccelerationtoVelocity_gainva_g +
            APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_b[0];

          // End of Outputs for SubSystem: '<S570>/RED Only'
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0 =
            APF_Path_Planning_2023a_B.t;

          // Outputs for IfAction SubSystem: '<S570>/RED Only' incorporates:
          //   ActionPort: '<S600>/Action Port'

          // DiscreteIntegrator: '<S612>/Velocity to Position'
          APF_Path_Planning_2023a_B.link2_com_y =
            APF_Path_Planning_2023a_P.VelocitytoPosition_gainval *
            APF_Path_Planning_2023a_B.t +
            APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE_m[0];

          // End of Outputs for SubSystem: '<S570>/RED Only'
          APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
            APF_Path_Planning_2023a_B.link2_com_y;

          // Outputs for IfAction SubSystem: '<S570>/RED Only' incorporates:
          //   ActionPort: '<S600>/Action Port'

          // Sum: '<S612>/Sum' incorporates:
          //   RandomNumber: '<S612>/Random Number'

          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 =
            APF_Path_Planning_2023a_B.link2_com_y +
            APF_Path_Planning_2023a_DW.NextOutput_i;

          // DiscreteIntegrator: '<S612>/Acceleration  to Velocity' incorporates:
          //   DataStoreRead: '<S611>/RED_Fy_Sat'
          //   MATLAB Function: '<S612>/MATLAB Function'
          //   SignalConversion generated from: '<S619>/ SFunction '

          APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_DW.RED_Fy_Sat /
            APF_Path_Planning_2023a_P.mRED *
            APF_Path_Planning_2023a_P.AccelerationtoVelocity_gainva_g +
            APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_b[1];

          // End of Outputs for SubSystem: '<S570>/RED Only'
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1 =
            APF_Path_Planning_2023a_B.t;

          // Outputs for IfAction SubSystem: '<S570>/RED Only' incorporates:
          //   ActionPort: '<S600>/Action Port'

          // DiscreteIntegrator: '<S612>/Velocity to Position'
          APF_Path_Planning_2023a_B.link2_com_y =
            APF_Path_Planning_2023a_P.VelocitytoPosition_gainval *
            APF_Path_Planning_2023a_B.t +
            APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE_m[1];

          // End of Outputs for SubSystem: '<S570>/RED Only'
          APF_Path_Planning_2023a_B.rtb_path_b_idx_1 =
            APF_Path_Planning_2023a_B.link2_com_y;

          // Outputs for IfAction SubSystem: '<S570>/RED Only' incorporates:
          //   ActionPort: '<S600>/Action Port'

          // Sum: '<S612>/Sum' incorporates:
          //   RandomNumber: '<S612>/Random Number'

          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_1 =
            APF_Path_Planning_2023a_B.link2_com_y +
            APF_Path_Planning_2023a_DW.NextOutput_i;

          // DiscreteIntegrator: '<S612>/Acceleration  to Velocity' incorporates:
          //   DataStoreRead: '<S611>/Data Store Read'
          //   DataStoreRead: '<S611>/RED_Tz_Sat'
          //   MATLAB Function: '<S612>/MATLAB Function'
          //   Sum: '<S611>/Sum'

          APF_Path_Planning_2023a_B.t = (APF_Path_Planning_2023a_DW.RED_Tz_Sat +
            APF_Path_Planning_2023a_DW.RED_Tz_RW_Sat) /
            APF_Path_Planning_2023a_P.IRED *
            APF_Path_Planning_2023a_P.AccelerationtoVelocity_gainva_g +
            APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_b[2];

          // DiscreteIntegrator: '<S612>/Velocity to Position'
          APF_Path_Planning_2023a_B.link2_com_y =
            APF_Path_Planning_2023a_P.VelocitytoPosition_gainval *
            APF_Path_Planning_2023a_B.t +
            APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE_m[2];

          // Sum: '<S612>/Sum' incorporates:
          //   RandomNumber: '<S612>/Random Number'

          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_2 =
            APF_Path_Planning_2023a_B.link2_com_y +
            APF_Path_Planning_2023a_DW.NextOutput_i;

          // Delay: '<S614>/Delay1'
          if (APF_Path_Planning_2023a_DW.icLoad_nn) {
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_n2 =
              APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
          }

          // Sum: '<S614>/Sum6' incorporates:
          //   Delay: '<S614>/Delay1'

          APF_Path_Planning_2023a_B.Sum6_b3 =
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 -
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_n2;

          // If: '<S614>/if we went through a "step"'
          if (APF_Path_Planning_2023a_B.Sum6_b3 != 0.0) {
            // Outputs for IfAction SubSystem: '<S614>/Hold this value' incorporates:
            //   ActionPort: '<S621>/Action Port'

            // SignalConversion generated from: '<S621>/In1'
            APF_Path_Planning_2023a_B.In1_g0 = APF_Path_Planning_2023a_B.Sum6_b3;

            // End of Outputs for SubSystem: '<S614>/Hold this value'
          }

          // End of If: '<S614>/if we went through a "step"'

          // Gain: '<S614>/divide by delta T' incorporates:
          //   DataStoreWrite: '<S611>/RED_Vx'

          APF_Path_Planning_2023a_DW.RED_Vx = 1.0 /
            APF_Path_Planning_2023a_P.baseRate *
            APF_Path_Planning_2023a_B.In1_g0;

          // Delay: '<S616>/Delay1' incorporates:
          //   DataStoreWrite: '<S611>/RED_Vx'

          if (APF_Path_Planning_2023a_DW.icLoad_kb) {
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_pc3 =
              APF_Path_Planning_2023a_DW.RED_Vx;
          }

          // Sum: '<S616>/Sum6' incorporates:
          //   DataStoreWrite: '<S611>/RED_Vx'
          //   Delay: '<S616>/Delay1'

          APF_Path_Planning_2023a_B.Sum6_b3 = APF_Path_Planning_2023a_DW.RED_Vx
            - APF_Path_Planning_2023a_DW.Delay1_DSTATE_pc3;

          // If: '<S616>/if we went through a "step"'
          if (APF_Path_Planning_2023a_B.Sum6_b3 != 0.0) {
            // Outputs for IfAction SubSystem: '<S616>/Hold this value' incorporates:
            //   ActionPort: '<S623>/Action Port'

            // SignalConversion generated from: '<S623>/In1'
            APF_Path_Planning_2023a_B.In1_gt = APF_Path_Planning_2023a_B.Sum6_b3;

            // End of Outputs for SubSystem: '<S616>/Hold this value'
          }

          // End of If: '<S616>/if we went through a "step"'

          // Sum: '<S611>/Sum7' incorporates:
          //   DataStoreWrite: '<S611>/RED_IMU_Ay'
          //   Gain: '<S616>/divide by delta T'
          //   RandomNumber: '<S611>/Random Number7'

          APF_Path_Planning_2023a_DW.RED_Ay = 1.0 /
            APF_Path_Planning_2023a_P.baseRate *
            APF_Path_Planning_2023a_B.In1_gt +
            APF_Path_Planning_2023a_DW.NextOutput_n;

          // Delay: '<S613>/Delay1'
          if (APF_Path_Planning_2023a_DW.icLoad_jf) {
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_k4 =
              APF_Path_Planning_2023a_B.rtb_Sum_b_idx_1;
          }

          // Sum: '<S613>/Sum6' incorporates:
          //   Delay: '<S613>/Delay1'

          APF_Path_Planning_2023a_B.Sum6_b3 =
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_1 -
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_k4;

          // If: '<S613>/if we went through a "step"'
          if (APF_Path_Planning_2023a_B.Sum6_b3 != 0.0) {
            // Outputs for IfAction SubSystem: '<S613>/Hold this value' incorporates:
            //   ActionPort: '<S620>/Action Port'

            // SignalConversion generated from: '<S620>/In1'
            APF_Path_Planning_2023a_B.In1_fv = APF_Path_Planning_2023a_B.Sum6_b3;

            // End of Outputs for SubSystem: '<S613>/Hold this value'
          }

          // End of If: '<S613>/if we went through a "step"'

          // Gain: '<S613>/divide by delta T' incorporates:
          //   DataStoreWrite: '<S611>/RED_Vy'

          APF_Path_Planning_2023a_DW.RED_Vy = 1.0 /
            APF_Path_Planning_2023a_P.baseRate *
            APF_Path_Planning_2023a_B.In1_fv;

          // Delay: '<S617>/Delay1' incorporates:
          //   DataStoreWrite: '<S611>/RED_Vy'

          if (APF_Path_Planning_2023a_DW.icLoad_dk) {
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_dh =
              APF_Path_Planning_2023a_DW.RED_Vy;
          }

          // Sum: '<S617>/Sum6' incorporates:
          //   DataStoreWrite: '<S611>/RED_Vy'
          //   Delay: '<S617>/Delay1'

          APF_Path_Planning_2023a_B.Sum6_b3 = APF_Path_Planning_2023a_DW.RED_Vy
            - APF_Path_Planning_2023a_DW.Delay1_DSTATE_dh;

          // If: '<S617>/if we went through a "step"'
          if (APF_Path_Planning_2023a_B.Sum6_b3 != 0.0) {
            // Outputs for IfAction SubSystem: '<S617>/Hold this value' incorporates:
            //   ActionPort: '<S624>/Action Port'

            // SignalConversion generated from: '<S624>/In1'
            APF_Path_Planning_2023a_B.In1_p = APF_Path_Planning_2023a_B.Sum6_b3;

            // End of Outputs for SubSystem: '<S617>/Hold this value'
          }

          // End of If: '<S617>/if we went through a "step"'

          // Sum: '<S611>/Sum8' incorporates:
          //   DataStoreWrite: '<S611>/RED_IMU_Ay_I'
          //   Gain: '<S617>/divide by delta T'
          //   RandomNumber: '<S611>/Random Number6'

          APF_Path_Planning_2023a_DW.RED_RzDD = 1.0 /
            APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_p
            + APF_Path_Planning_2023a_DW.NextOutput_ga;

          // Delay: '<S615>/Delay1'
          if (APF_Path_Planning_2023a_DW.icLoad_l1) {
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_lh =
              APF_Path_Planning_2023a_B.rtb_Sum_b_idx_2;
          }

          // Sum: '<S615>/Sum6' incorporates:
          //   Delay: '<S615>/Delay1'

          APF_Path_Planning_2023a_B.Sum6_b3 =
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_2 -
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_lh;

          // If: '<S615>/if we went through a "step"'
          if (APF_Path_Planning_2023a_B.Sum6_b3 != 0.0) {
            // Outputs for IfAction SubSystem: '<S615>/Hold this value' incorporates:
            //   ActionPort: '<S622>/Action Port'

            // SignalConversion generated from: '<S622>/In1'
            APF_Path_Planning_2023a_B.In1_aw = APF_Path_Planning_2023a_B.Sum6_b3;

            // End of Outputs for SubSystem: '<S615>/Hold this value'
          }

          // End of If: '<S615>/if we went through a "step"'

          // Gain: '<S615>/divide by delta T' incorporates:
          //   DataStoreWrite: '<S611>/RED_RzD'

          APF_Path_Planning_2023a_DW.RED_RzD = 1.0 /
            APF_Path_Planning_2023a_P.baseRate *
            APF_Path_Planning_2023a_B.In1_aw;

          // Delay: '<S618>/Delay1' incorporates:
          //   DataStoreWrite: '<S611>/RED_RzD'

          if (APF_Path_Planning_2023a_DW.icLoad_kp) {
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_jb =
              APF_Path_Planning_2023a_DW.RED_RzD;
          }

          // Sum: '<S618>/Sum6' incorporates:
          //   DataStoreWrite: '<S611>/RED_RzD'
          //   Delay: '<S618>/Delay1'

          APF_Path_Planning_2023a_B.Sum6_b3 = APF_Path_Planning_2023a_DW.RED_RzD
            - APF_Path_Planning_2023a_DW.Delay1_DSTATE_jb;

          // If: '<S618>/if we went through a "step"'
          if (APF_Path_Planning_2023a_B.Sum6_b3 != 0.0) {
            // Outputs for IfAction SubSystem: '<S618>/Hold this value' incorporates:
            //   ActionPort: '<S625>/Action Port'

            // SignalConversion generated from: '<S625>/In1'
            APF_Path_Planning_2023a_B.In1_c = APF_Path_Planning_2023a_B.Sum6_b3;

            // End of Outputs for SubSystem: '<S618>/Hold this value'
          }

          // End of If: '<S618>/if we went through a "step"'

          // Sum: '<S611>/Sum9' incorporates:
          //   DataStoreWrite: '<S611>/RED_IMU_R'
          //   Gain: '<S618>/divide by delta T'
          //   RandomNumber: '<S611>/Random Number8'

          APF_Path_Planning_2023a_DW.RED_Ax = 1.0 /
            APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_c
            + APF_Path_Planning_2023a_DW.NextOutput_l;

          // DataStoreWrite: '<S611>/RED_Px'
          APF_Path_Planning_2023a_DW.RED_Px =
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            rtsiSetBlockStateForSolverChangedAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
            rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
          }

          // End of DataStoreWrite: '<S611>/RED_Px'

          // DataStoreWrite: '<S611>/RED_Py'
          APF_Path_Planning_2023a_DW.RED_Py =
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_1;
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            rtsiSetBlockStateForSolverChangedAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
            rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
          }

          // End of DataStoreWrite: '<S611>/RED_Py'

          // DataStoreWrite: '<S611>/RED_Rz' incorporates:
          //   DataStoreWrite: '<S611>/RED_RzD'
          //   DataStoreWrite: '<S611>/RED_Vx'
          //   DataStoreWrite: '<S611>/RED_Vy'

          APF_Path_Planning_2023a_DW.RED_Rz =
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_2;
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            rtsiSetBlockStateForSolverChangedAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
            rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
            rtsiSetBlockStateForSolverChangedAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
            rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
            rtsiSetBlockStateForSolverChangedAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
            rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
            rtsiSetBlockStateForSolverChangedAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
            rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
              (&APF_Path_Planning_2023a_M->solverInfo, true);
          }

          // End of DataStoreWrite: '<S611>/RED_Rz'

          // Update for DiscreteIntegrator: '<S612>/Acceleration  to Velocity'
          APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_b[0] =
            APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0;

          // Update for DiscreteIntegrator: '<S612>/Velocity to Position'
          APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE_m[0] =
            APF_Path_Planning_2023a_B.rtb_path_b_idx_0;

          // Update for DiscreteIntegrator: '<S612>/Acceleration  to Velocity'
          APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_b[1] =
            APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;

          // Update for DiscreteIntegrator: '<S612>/Velocity to Position'
          APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE_m[1] =
            APF_Path_Planning_2023a_B.rtb_path_b_idx_1;

          // Update for DiscreteIntegrator: '<S612>/Acceleration  to Velocity'
          APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_b[2] =
            APF_Path_Planning_2023a_B.t;

          // Update for DiscreteIntegrator: '<S612>/Velocity to Position'
          APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE_m[2] =
            APF_Path_Planning_2023a_B.link2_com_y;

          // Update for RandomNumber: '<S612>/Random Number'
          APF_Path_Planning_2023a_DW.NextOutput_i =
            APF__rt_nrand_Upu32_Yd_f_pw_snf
            (&APF_Path_Planning_2023a_DW.RandSeed_k) * sqrt
            (APF_Path_Planning_2023a_P.noise_variance_RED) +
            APF_Path_Planning_2023a_P.RandomNumber_Mean;

          // Update for Delay: '<S614>/Delay1'
          APF_Path_Planning_2023a_DW.icLoad_nn = false;
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_n2 =
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;

          // Update for Delay: '<S616>/Delay1' incorporates:
          //   DataStoreWrite: '<S611>/RED_Vx'

          APF_Path_Planning_2023a_DW.icLoad_kb = false;
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_pc3 =
            APF_Path_Planning_2023a_DW.RED_Vx;

          // Update for RandomNumber: '<S611>/Random Number7'
          APF_Path_Planning_2023a_DW.NextOutput_n =
            APF__rt_nrand_Upu32_Yd_f_pw_snf
            (&APF_Path_Planning_2023a_DW.RandSeed_a) *
            APF_Path_Planning_2023a_P.RandomNumber7_StdDev +
            APF_Path_Planning_2023a_P.RandomNumber7_Mean;

          // Update for Delay: '<S613>/Delay1'
          APF_Path_Planning_2023a_DW.icLoad_jf = false;
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_k4 =
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_1;

          // Update for Delay: '<S617>/Delay1' incorporates:
          //   DataStoreWrite: '<S611>/RED_Vy'

          APF_Path_Planning_2023a_DW.icLoad_dk = false;
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_dh =
            APF_Path_Planning_2023a_DW.RED_Vy;

          // Update for RandomNumber: '<S611>/Random Number6'
          APF_Path_Planning_2023a_DW.NextOutput_ga =
            APF__rt_nrand_Upu32_Yd_f_pw_snf
            (&APF_Path_Planning_2023a_DW.RandSeed_f) *
            APF_Path_Planning_2023a_P.RandomNumber6_StdDev +
            APF_Path_Planning_2023a_P.RandomNumber6_Mean;

          // Update for Delay: '<S615>/Delay1'
          APF_Path_Planning_2023a_DW.icLoad_l1 = false;
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_lh =
            APF_Path_Planning_2023a_B.rtb_Sum_b_idx_2;

          // Update for Delay: '<S618>/Delay1' incorporates:
          //   DataStoreWrite: '<S611>/RED_RzD'

          APF_Path_Planning_2023a_DW.icLoad_kp = false;
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_jb =
            APF_Path_Planning_2023a_DW.RED_RzD;

          // Update for RandomNumber: '<S611>/Random Number8'
          APF_Path_Planning_2023a_DW.NextOutput_l =
            APF__rt_nrand_Upu32_Yd_f_pw_snf
            (&APF_Path_Planning_2023a_DW.RandSeed_h) *
            APF_Path_Planning_2023a_P.RandomNumber8_StdDev +
            APF_Path_Planning_2023a_P.RandomNumber8_Mean;

          // End of Outputs for SubSystem: '<S570>/RED Only'
        }

        // End of If: '<S570>/If'

        // Update for RandomNumber: '<S571>/Random Number'
        APF_Path_Planning_2023a_DW.NextOutput = APF__rt_nrand_Upu32_Yd_f_pw_snf(
          &APF_Path_Planning_2023a_DW.RandSeed) * sqrt
          (APF_Path_Planning_2023a_P.noise_variance_BLACK) +
          APF_Path_Planning_2023a_P.RandomNumber_Mean_d;

        // Update for Delay: '<S577>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_ou = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_f =
          APF_Path_Planning_2023a_B.rtb_path_o_idx_0;

        // Update for Delay: '<S574>/Delay1' incorporates:
        //   DataStoreWrite: '<S568>/BLACK_Vx'

        APF_Path_Planning_2023a_DW.icLoad_p4 = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_lg =
          APF_Path_Planning_2023a_DW.BLACK_Vx;

        // Update for RandomNumber: '<S568>/Random Number1'
        APF_Path_Planning_2023a_DW.NextOutput_b =
          APF__rt_nrand_Upu32_Yd_f_pw_snf(&APF_Path_Planning_2023a_DW.RandSeed_n)
          * APF_Path_Planning_2023a_P.RandomNumber1_StdDev_e +
          APF_Path_Planning_2023a_P.RandomNumber1_Mean_j;

        // Update for Delay: '<S572>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_jc = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_d3a =
          APF_Path_Planning_2023a_B.Derivative2;

        // Update for Delay: '<S575>/Delay1' incorporates:
        //   DataStoreWrite: '<S568>/BLACK_Vy'

        APF_Path_Planning_2023a_DW.icLoad_jk = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_ea =
          APF_Path_Planning_2023a_DW.BLACK_Vy;

        // Update for RandomNumber: '<S568>/Random Number'
        APF_Path_Planning_2023a_DW.NextOutput_j =
          APF__rt_nrand_Upu32_Yd_f_pw_snf(&APF_Path_Planning_2023a_DW.RandSeed_g)
          * APF_Path_Planning_2023a_P.RandomNumber_StdDev +
          APF_Path_Planning_2023a_P.RandomNumber_Mean_g;

        // Update for Delay: '<S573>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_jr = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_cx =
          APF_Path_Planning_2023a_B.rtb_path_o_idx_2;

        // Update for Delay: '<S576>/Delay1' incorporates:
        //   DataStoreWrite: '<S568>/BLACK_RzD'

        APF_Path_Planning_2023a_DW.icLoad_jko = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_ab =
          APF_Path_Planning_2023a_DW.BLACK_RzD;

        // Update for RandomNumber: '<S568>/Random Number2'
        APF_Path_Planning_2023a_DW.NextOutput_g =
          APF__rt_nrand_Upu32_Yd_f_pw_snf(&APF_Path_Planning_2023a_DW.RandSeed_m)
          * APF_Path_Planning_2023a_P.RandomNumber2_StdDev_c +
          APF_Path_Planning_2023a_P.RandomNumber2_Mean_b;

        // Update for DiscreteIntegrator: '<S571>/Acceleration  to Velocity'
        APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE[0] =
          APF_Path_Planning_2023a_B.x_ddot_d[0];

        // Update for DiscreteIntegrator: '<S571>/Velocity to Position'
        APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE[0] =
          APF_Path_Planning_2023a_B.phi_tot_grad[0];

        // Update for DiscreteIntegrator: '<S585>/Acceleration  to Velocity'
        APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_i[0] =
          APF_Path_Planning_2023a_B.q;

        // Update for DiscreteIntegrator: '<S585>/Velocity to Position'
        APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE_a[0] =
          APF_Path_Planning_2023a_B.r_ct[0];

        // Update for DiscreteIntegrator: '<S571>/Acceleration  to Velocity'
        APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE[1] =
          APF_Path_Planning_2023a_B.x_ddot_d[1];

        // Update for DiscreteIntegrator: '<S571>/Velocity to Position'
        APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE[1] =
          APF_Path_Planning_2023a_B.phi_tot_grad[1];

        // Update for DiscreteIntegrator: '<S585>/Acceleration  to Velocity'
        APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_i[1] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1;

        // Update for DiscreteIntegrator: '<S585>/Velocity to Position'
        APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE_a[1] =
          APF_Path_Planning_2023a_B.r_ct[1];

        // Update for DiscreteIntegrator: '<S571>/Acceleration  to Velocity'
        APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE[2] =
          APF_Path_Planning_2023a_B.rtb_y_g;

        // Update for DiscreteIntegrator: '<S571>/Velocity to Position'
        APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE[2] =
          APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp;

        // Update for DiscreteIntegrator: '<S585>/Acceleration  to Velocity'
        APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_i[2] =
          APF_Path_Planning_2023a_B.varargout_1;

        // Update for DiscreteIntegrator: '<S585>/Velocity to Position'
        APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE_a[2] =
          APF_Path_Planning_2023a_B.RED_Tz_RW;

        // Update for RandomNumber: '<S585>/Random Number'
        APF_Path_Planning_2023a_DW.NextOutput_a =
          APF__rt_nrand_Upu32_Yd_f_pw_snf(&APF_Path_Planning_2023a_DW.RandSeed_o)
          * sqrt(APF_Path_Planning_2023a_P.noise_variance_BLUE) +
          APF_Path_Planning_2023a_P.RandomNumber_Mean_dq;

        // Update for Delay: '<S591>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_do = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_gv =
          APF_Path_Planning_2023a_B.r_co[0];

        // Update for Delay: '<S588>/Delay1' incorporates:
        //   DataStoreWrite: '<S569>/BLUE_Vx'

        APF_Path_Planning_2023a_DW.icLoad_nk = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_ds =
          APF_Path_Planning_2023a_DW.BLUE_Vx;

        // Update for RandomNumber: '<S569>/Random Number4'
        APF__rt_nrand_Upu32_Yd_f_pw_snf(&APF_Path_Planning_2023a_DW.RandSeed_n0);

        // Update for Delay: '<S586>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_ip = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_i5 =
          APF_Path_Planning_2023a_B.r_co[1];

        // Update for Delay: '<S589>/Delay1' incorporates:
        //   DataStoreWrite: '<S569>/BLUE_Vy'

        APF_Path_Planning_2023a_DW.icLoad_az = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_l0 =
          APF_Path_Planning_2023a_DW.BLUE_Vy;

        // Update for RandomNumber: '<S569>/Random Number3'
        APF__rt_nrand_Upu32_Yd_f_pw_snf(&APF_Path_Planning_2023a_DW.RandSeed_e);

        // Update for Delay: '<S587>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_dh = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_iq =
          APF_Path_Planning_2023a_B.r_co[2];

        // Update for Delay: '<S590>/Delay1' incorporates:
        //   DataStoreWrite: '<S569>/BLUE_RzD'

        APF_Path_Planning_2023a_DW.icLoad_ex = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_eq =
          APF_Path_Planning_2023a_DW.BLUE_RzD;

        // Update for RandomNumber: '<S569>/Random Number5'
        APF__rt_nrand_Upu32_Yd_f_pw_snf(&APF_Path_Planning_2023a_DW.RandSeed_c);

        // End of Outputs for SubSystem: '<Root>/Simulate Plant Dynamics'
      }

      // End of If: '<Root>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 

      // If: '<S1>/This IF block determines whether or not to run the BLACK sim//exp' incorporates:
      //   DataStoreRead: '<S1>/Data Store Read'
      //   DataStoreRead: '<S1>/Data Store Read1'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if ((APF_Path_Planning_2023a_DW.WhoAmI == 2.0) &&
            (APF_Path_Planning_2023a_DW.isSim == 0.0)) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhetherorn =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhetherorn;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S1>/Change BLACK Behavior' incorporates:
        //   ActionPort: '<S20>/Action Port'

        APF_Path_Pl_ChangeBLACKBehavior(APF_Path_Planning_2023a_M,
          &APF_Path_Planning_2023a_DW.ChangeBLACKBehavior,
          &APF_Path_Planning_2023a_P.ChangeBLACKBehavior);

        // End of Outputs for SubSystem: '<S1>/Change BLACK Behavior'
      }

      // End of If: '<S1>/This IF block determines whether or not to run the BLACK sim//exp' 

      // If: '<S1>/This IF block determines whether or not to run the BLUE sim//exp' incorporates:
      //   DataStoreRead: '<S1>/Data Store Read'
      //   DataStoreRead: '<S1>/Data Store Read1'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if ((APF_Path_Planning_2023a_DW.WhoAmI == 3.0) &&
            (APF_Path_Planning_2023a_DW.isSim == 0.0)) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_j =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_j;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S1>/Change BLUE Behavior' incorporates:
        //   ActionPort: '<S21>/Action Port'

        APF_Path_Pl_ChangeBLACKBehavior(APF_Path_Planning_2023a_M,
          &APF_Path_Planning_2023a_DW.ChangeBLUEBehavior,
          &APF_Path_Planning_2023a_P.ChangeBLUEBehavior);

        // End of Outputs for SubSystem: '<S1>/Change BLUE Behavior'
      }

      // End of If: '<S1>/This IF block determines whether or not to run the BLUE sim//exp' 

      // If: '<S1>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
      //   DataStoreRead: '<S1>/Data Store Read'
      //   DataStoreRead: '<S1>/Data Store Read1'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if ((APF_Path_Planning_2023a_DW.WhoAmI == 1.0) &&
            (APF_Path_Planning_2023a_DW.isSim == 0.0)) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_o =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_o;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S1>/Change RED Behavior' incorporates:
        //   ActionPort: '<S22>/Action Port'

        // Update for S-Function (sdspToNetwork): '<S22>/UDP Send' incorporates:
        //   Constant: '<S22>/Constant1'

        sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_l
                              [0U]);
        LibUpdate_Network(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_l[0U],
                          &APF_Path_Planning_2023a_P.Constant1_Value_i, 1);
        if (*sErr != 0) {
          rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
          rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
        }

        // End of Update for S-Function (sdspToNetwork): '<S22>/UDP Send'
        // End of Outputs for SubSystem: '<S1>/Change RED Behavior'
      }

      // End of If: '<S1>/This IF block determines whether or not to run the RED sim//exp ' 

      // MATLABSystem: '<S23>/MATLAB System' incorporates:
      //   DataStoreRead: '<S3>/ARM_Command_Mode'
      //   DataStoreRead: '<S3>/BLACK_Ax'
      //   DataStoreRead: '<S3>/BLACK_Ay'
      //   DataStoreRead: '<S3>/BLACK_Fx_Sat'
      //   DataStoreRead: '<S3>/BLACK_Fy_Sat'
      //   DataStoreRead: '<S3>/BLACK_Px'
      //   DataStoreRead: '<S3>/BLACK_Py'
      //   DataStoreRead: '<S3>/BLACK_Rz'
      //   DataStoreRead: '<S3>/BLACK_RzD'
      //   DataStoreRead: '<S3>/BLACK_RzDD'
      //   DataStoreRead: '<S3>/BLACK_Thruster_ON_Count'
      //   DataStoreRead: '<S3>/BLACK_Tz_Sat'
      //   DataStoreRead: '<S3>/BLACK_Vx'
      //   DataStoreRead: '<S3>/BLACK_Vy'
      //   DataStoreRead: '<S3>/BLUE_Fx_Sat'
      //   DataStoreRead: '<S3>/BLUE_Fy_Sat'
      //   DataStoreRead: '<S3>/BLUE_Px'
      //   DataStoreRead: '<S3>/BLUE_Py'
      //   DataStoreRead: '<S3>/BLUE_Rz'
      //   DataStoreRead: '<S3>/BLUE_RzD'
      //   DataStoreRead: '<S3>/BLUE_Thruster_ON_Count'
      //   DataStoreRead: '<S3>/BLUE_Tz_Sat'
      //   DataStoreRead: '<S3>/BLUE_Vx'
      //   DataStoreRead: '<S3>/BLUE_Vy'
      //   DataStoreRead: '<S3>/Command_Px'
      //   DataStoreRead: '<S3>/Command_Py'
      //   DataStoreRead: '<S3>/Command_Rz'
      //   DataStoreRead: '<S3>/DAC_Attitude_k_1'
      //   DataStoreRead: '<S3>/DAC_Attitude_k_2'
      //   DataStoreRead: '<S3>/DAC_Posx_k_1'
      //   DataStoreRead: '<S3>/DAC_Posx_k_2'
      //   DataStoreRead: '<S3>/DAC_Posy_k_1'
      //   DataStoreRead: '<S3>/DAC_Posy_k_2'
      //   DataStoreRead: '<S3>/Data Store Read'
      //   DataStoreRead: '<S3>/Data Store Read1'
      //   DataStoreRead: '<S3>/Data Store Read2'
      //   DataStoreRead: '<S3>/Data Store Read3'
      //   DataStoreRead: '<S3>/Data Store Read4'
      //   DataStoreRead: '<S3>/Data Store Read5'
      //   DataStoreRead: '<S3>/Data Store Read6'
      //   DataStoreRead: '<S3>/Data Store Read7'
      //   DataStoreRead: '<S3>/Data Store Read8'
      //   DataStoreRead: '<S3>/RED_Ax'
      //   DataStoreRead: '<S3>/RED_Ay'
      //   DataStoreRead: '<S3>/RED_Fx_Sat'
      //   DataStoreRead: '<S3>/RED_Fy_Sat'
      //   DataStoreRead: '<S3>/RED_Px'
      //   DataStoreRead: '<S3>/RED_Py '
      //   DataStoreRead: '<S3>/RED_Rz'
      //   DataStoreRead: '<S3>/RED_RzDD'
      //   DataStoreRead: '<S3>/RED_RzD_Elbow'
      //   DataStoreRead: '<S3>/RED_RzD_Shoulder'
      //   DataStoreRead: '<S3>/RED_RzD_Wrist'
      //   DataStoreRead: '<S3>/RED_Rz_Elbow'
      //   DataStoreRead: '<S3>/RED_Rz_Shoulder'
      //   DataStoreRead: '<S3>/RED_Rz_Wrist'
      //   DataStoreRead: '<S3>/RED_Thruster_ON_Count'
      //   DataStoreRead: '<S3>/RED_Tz_Elbow'
      //   DataStoreRead: '<S3>/RED_Tz_Sat'
      //   DataStoreRead: '<S3>/RED_Tz_Shoulder'
      //   DataStoreRead: '<S3>/RED_Tz_Wrist'
      //   DataStoreRead: '<S3>/RED_Vx '
      //   DataStoreRead: '<S3>/RED_Vy'
      //   DataStoreRead: '<S3>/RED_Vz'
      //   DataStoreRead: '<S3>/Universal_Time'
      //   MATLAB Function: '<S23>/MATLAB Function'
      //   SignalConversion generated from: '<S23>/MATLAB System'

      //         %% Define input properties
      //  Call C-function implementing device output
      APF_Path_Planning_2023a_B.b_u1[0] = APF_Path_Planning_2023a_DW.Univ_Time;
      APF_Path_Planning_2023a_B.b_u1[1] = APF_Path_Planning_2023a_DW.RED_Fx_Sat;
      APF_Path_Planning_2023a_B.b_u1[2] = APF_Path_Planning_2023a_DW.RED_Fy_Sat;
      APF_Path_Planning_2023a_B.b_u1[3] = APF_Path_Planning_2023a_DW.RED_Tz_Sat;
      APF_Path_Planning_2023a_B.b_u1[4] = APF_Path_Planning_2023a_DW.RED_Px;
      APF_Path_Planning_2023a_B.b_u1[5] = APF_Path_Planning_2023a_DW.RED_Py;
      APF_Path_Planning_2023a_B.b_u1[6] = APF_Path_Planning_2023a_DW.RED_Rz;
      APF_Path_Planning_2023a_B.b_u1[7] = APF_Path_Planning_2023a_DW.RED_Vx;
      APF_Path_Planning_2023a_B.b_u1[8] = APF_Path_Planning_2023a_DW.RED_Vy;
      APF_Path_Planning_2023a_B.b_u1[9] = APF_Path_Planning_2023a_DW.RED_RzD;
      APF_Path_Planning_2023a_B.b_u1[10] = APF_Path_Planning_2023a_DW.RED_Ax;
      APF_Path_Planning_2023a_B.b_u1[11] = APF_Path_Planning_2023a_DW.RED_Ay;
      APF_Path_Planning_2023a_B.b_u1[12] = APF_Path_Planning_2023a_DW.RED_RzDD;
      APF_Path_Planning_2023a_B.b_u1[13] =
        APF_Path_Planning_2023a_DW.BLACK_Fx_Sat;
      APF_Path_Planning_2023a_B.b_u1[14] =
        APF_Path_Planning_2023a_DW.BLACK_Fy_Sat;
      APF_Path_Planning_2023a_B.b_u1[15] =
        APF_Path_Planning_2023a_DW.BLACK_Tz_Sat;
      APF_Path_Planning_2023a_B.b_u1[16] = APF_Path_Planning_2023a_DW.BLACK_Px;
      APF_Path_Planning_2023a_B.b_u1[17] = APF_Path_Planning_2023a_DW.BLACK_Py;
      APF_Path_Planning_2023a_B.b_u1[18] = APF_Path_Planning_2023a_DW.BLACK_Rz;
      APF_Path_Planning_2023a_B.b_u1[19] = APF_Path_Planning_2023a_DW.BLACK_Vx;
      APF_Path_Planning_2023a_B.b_u1[20] = APF_Path_Planning_2023a_DW.BLACK_Vy;
      APF_Path_Planning_2023a_B.b_u1[21] = APF_Path_Planning_2023a_DW.BLACK_RzD;
      APF_Path_Planning_2023a_B.b_u1[22] = APF_Path_Planning_2023a_DW.BLACK_Ax;
      APF_Path_Planning_2023a_B.b_u1[23] = APF_Path_Planning_2023a_DW.BLACK_Ay;
      APF_Path_Planning_2023a_B.b_u1[24] = APF_Path_Planning_2023a_DW.BLACK_RzDD;
      APF_Path_Planning_2023a_B.b_u1[25] =
        APF_Path_Planning_2023a_DW.BLUE_Fx_Sat;
      APF_Path_Planning_2023a_B.b_u1[26] =
        APF_Path_Planning_2023a_DW.BLUE_Fy_Sat;
      APF_Path_Planning_2023a_B.b_u1[27] =
        APF_Path_Planning_2023a_DW.BLUE_Tz_Sat;
      APF_Path_Planning_2023a_B.b_u1[28] = APF_Path_Planning_2023a_DW.BLUE_Px;
      APF_Path_Planning_2023a_B.b_u1[29] = APF_Path_Planning_2023a_DW.BLUE_Py;
      APF_Path_Planning_2023a_B.b_u1[30] = APF_Path_Planning_2023a_DW.BLUE_Rz;
      APF_Path_Planning_2023a_B.b_u1[31] = APF_Path_Planning_2023a_DW.BLUE_Vx;
      APF_Path_Planning_2023a_B.b_u1[32] = APF_Path_Planning_2023a_DW.BLUE_Vy;
      APF_Path_Planning_2023a_B.b_u1[33] = APF_Path_Planning_2023a_DW.BLUE_RzD;
      APF_Path_Planning_2023a_B.b_u1[34] =
        APF_Path_Planning_2023a_DW.RED_Rz_Shoulder;
      APF_Path_Planning_2023a_B.b_u1[35] =
        APF_Path_Planning_2023a_DW.RED_Rz_Elbow;
      APF_Path_Planning_2023a_B.b_u1[36] =
        APF_Path_Planning_2023a_DW.RED_Rz_Wrist;
      APF_Path_Planning_2023a_B.b_u1[37] =
        APF_Path_Planning_2023a_DW.RED_RzD_Shoulder;
      APF_Path_Planning_2023a_B.b_u1[38] =
        APF_Path_Planning_2023a_DW.RED_RzD_Elbow;
      APF_Path_Planning_2023a_B.b_u1[39] =
        APF_Path_Planning_2023a_DW.RED_RzD_Wrist;
      APF_Path_Planning_2023a_B.b_u1[40] =
        APF_Path_Planning_2023a_DW.RED_ARM_Control_Mode;
      APF_Path_Planning_2023a_B.b_u1[41] =
        APF_Path_Planning_2023a_DW.RED_Shoulder_Command;
      APF_Path_Planning_2023a_B.b_u1[42] =
        APF_Path_Planning_2023a_DW.RED_Elbow_Command;
      APF_Path_Planning_2023a_B.b_u1[43] =
        APF_Path_Planning_2023a_DW.RED_Wrist_Command;
      APF_Path_Planning_2023a_B.b_u1[44] =
        APF_Path_Planning_2023a_DW.RED_Thruster_ON_Count;
      APF_Path_Planning_2023a_B.b_u1[45] =
        APF_Path_Planning_2023a_DW.BLACK_Thruster_ON_Count;
      APF_Path_Planning_2023a_B.b_u1[46] =
        APF_Path_Planning_2023a_DW.BLUE_Thruster_ON_Count;
      APF_Path_Planning_2023a_B.b_u1[47] = APF_Path_Planning_2023a_DW.Command_Px;
      APF_Path_Planning_2023a_B.b_u1[48] = APF_Path_Planning_2023a_DW.Command_Py;
      APF_Path_Planning_2023a_B.b_u1[49] = APF_Path_Planning_2023a_DW.Command_Rz;
      APF_Path_Planning_2023a_B.b_u1[50] =
        APF_Path_Planning_2023a_DW.DAC_Posx_k_1;
      APF_Path_Planning_2023a_B.b_u1[51] =
        APF_Path_Planning_2023a_DW.DAC_Posx_k_2;
      APF_Path_Planning_2023a_B.b_u1[52] =
        APF_Path_Planning_2023a_DW.DAC_Posy_k_1;
      APF_Path_Planning_2023a_B.b_u1[53] =
        APF_Path_Planning_2023a_DW.DAC_Posy_k_2;
      APF_Path_Planning_2023a_B.b_u1[54] =
        APF_Path_Planning_2023a_DW.DAC_Attitude_k_1;
      APF_Path_Planning_2023a_B.b_u1[55] =
        APF_Path_Planning_2023a_DW.DAC_Attitude_k_2;
      APF_Path_Planning_2023a_B.b_u1[56] = APF_Path_Planning_2023a_DW.TX2_data1;
      APF_Path_Planning_2023a_B.b_u1[57] = APF_Path_Planning_2023a_DW.TX2_data2;
      APF_Path_Planning_2023a_B.b_u1[58] = APF_Path_Planning_2023a_DW.TX2_data3;
      APF_Path_Planning_2023a_B.b_u1[59] =
        APF_Path_Planning_2023a_DW.BLACK_Px_Est;
      APF_Path_Planning_2023a_B.b_u1[60] =
        APF_Path_Planning_2023a_DW.BLACK_Py_Est;
      APF_Path_Planning_2023a_B.b_u1[61] =
        APF_Path_Planning_2023a_DW.BLACK_Rz_Est;
      APF_Path_Planning_2023a_B.b_u1[62] =
        APF_Path_Planning_2023a_DW.BLACK_Px_preKalm;
      APF_Path_Planning_2023a_B.b_u1[63] =
        APF_Path_Planning_2023a_DW.BLACK_Py_preKalm;
      APF_Path_Planning_2023a_B.b_u1[64] =
        APF_Path_Planning_2023a_DW.BLACK_Rz_preKalm;
      appendDataToFile(&APF_Path_Planning_2023a_B.b_u1[0], 65.0);

      // If: '<S4>/This IF block determines whether or not to run the exp code' incorporates:
      //   DataStoreRead: '<S4>/Data Store Read'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_DW.isSim == 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_d =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_d;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S4>/Enable Pucks' incorporates:
        //   ActionPort: '<S25>/Action Port'

        // MATLABSystem: '<S25>/Set Pin 428 (Pucks) to HIGH' incorporates:
        //   DataStoreRead: '<S25>/Data Store Read1'

        if (APF_Path_Planning_2023a_DW.obj_p.gpioPin !=
            APF_Path_Planning_2023a_P.SetPin428PuckstoHIGH_gpioPin) {
          APF_Path_Planning_2023a_DW.obj_p.gpioPin =
            APF_Path_Planning_2023a_P.SetPin428PuckstoHIGH_gpioPin;
        }

        if (APF_Path_Planning_2023a_DW.obj_p.pinDirection !=
            APF_Path_Planning_2023a_P.SetPin428PuckstoHIGH_pinDirecti) {
          APF_Path_Planning_2023a_DW.obj_p.pinDirection =
            APF_Path_Planning_2023a_P.SetPin428PuckstoHIGH_pinDirecti;
        }

        //         %% Define input properties
        //  Call C-function implementing device output
        // coder.ceval('export_gpio', obj.gpioPin);
        set_pin_direction(APF_Path_Planning_2023a_DW.obj_p.gpioPin,
                          APF_Path_Planning_2023a_DW.obj_p.pinDirection);
        change_gpio_value(APF_Path_Planning_2023a_DW.obj_p.gpioPin,
                          APF_Path_Planning_2023a_DW.Float_State);

        // End of MATLABSystem: '<S25>/Set Pin 428 (Pucks) to HIGH'
        // End of Outputs for SubSystem: '<S4>/Enable Pucks'
      }

      // End of If: '<S4>/This IF block determines whether or not to run the exp code' 

      // If: '<S5>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
      //   DataStoreRead: '<S5>/Data Store Read1'
      //   DataStoreRead: '<S5>/Data Store Read2'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if ((APF_Path_Planning_2023a_DW.WhoAmI == 1.0) &&
            (APF_Path_Planning_2023a_DW.isSim == 0.0)) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_a =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_a;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S5>/Change RED Behavior' incorporates:
        //   ActionPort: '<S26>/Action Port'

        // MATLABSystem: '<S26>/Read Joint Positions using  Dynamixel Encoders' incorporates:
        //   DataStoreWrite: '<S26>/Data Store Write3'
        //   DataStoreWrite: '<S26>/Data Store Write4'
        //   DataStoreWrite: '<S26>/Data Store Write5'
        //   Delay: '<S26>/Delay'
        //   Delay: '<S26>/Delay1'
        //   Delay: '<S26>/Delay2'

        if (APF_Path_Planning_2023a_DW.obj_d.SampleTime !=
            APF_Path_Planning_2023a_P.baseRate) {
          if (((!rtIsInf(APF_Path_Planning_2023a_P.baseRate)) && (!rtIsNaN
                (APF_Path_Planning_2023a_P.baseRate))) || rtIsInf
              (APF_Path_Planning_2023a_P.baseRate)) {
            APF_Path_Planning_2023a_B.sampleTime =
              APF_Path_Planning_2023a_P.baseRate;
          }

          APF_Path_Planning_2023a_DW.obj_d.SampleTime =
            APF_Path_Planning_2023a_B.sampleTime;
        }

        //         %% Define input properties
        //         %% Define output properties
        APF_Path_Planning_2023a_B.sampleTime = 0.0;
        APF_Path_Planning_2023a_B.RED_Tz_RW = 0.0;
        APF_Path_Planning_2023a_B.rtb_y_g = 0.0;
        APF_Path_Planning_2023a_DW.RED_RzD_Shoulder = 0.0;
        APF_Path_Planning_2023a_DW.RED_RzD_Elbow = 0.0;
        APF_Path_Planning_2023a_DW.RED_RzD_Wrist = 0.0;
        read_dynamixel_position(&APF_Path_Planning_2023a_B.sampleTime,
          &APF_Path_Planning_2023a_B.RED_Tz_RW,
          &APF_Path_Planning_2023a_B.rtb_y_g,
          &APF_Path_Planning_2023a_DW.RED_RzD_Shoulder,
          &APF_Path_Planning_2023a_DW.RED_RzD_Elbow,
          &APF_Path_Planning_2023a_DW.RED_RzD_Wrist,
          APF_Path_Planning_2023a_DW.Delay_DSTATE_a,
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_pw,
          APF_Path_Planning_2023a_DW.Delay2_DSTATE);
        APF_Path_Planning_2023a_DW.Delay_DSTATE_a =
          APF_Path_Planning_2023a_B.sampleTime;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_pw =
          APF_Path_Planning_2023a_B.RED_Tz_RW;
        APF_Path_Planning_2023a_DW.Delay2_DSTATE =
          APF_Path_Planning_2023a_B.rtb_y_g;

        // End of MATLABSystem: '<S26>/Read Joint Positions using  Dynamixel Encoders' 

        // DataStoreWrite: '<S26>/Data Store Write' incorporates:
        //   Delay: '<S26>/Delay'

        APF_Path_Planning_2023a_DW.RED_Rz_Shoulder =
          APF_Path_Planning_2023a_DW.Delay_DSTATE_a;

        // DataStoreWrite: '<S26>/Data Store Write1' incorporates:
        //   Delay: '<S26>/Delay1'

        APF_Path_Planning_2023a_DW.RED_Rz_Elbow =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_pw;

        // DataStoreWrite: '<S26>/Data Store Write2' incorporates:
        //   Delay: '<S26>/Delay2'

        APF_Path_Planning_2023a_DW.RED_Rz_Wrist =
          APF_Path_Planning_2023a_DW.Delay2_DSTATE;

        // End of Outputs for SubSystem: '<S5>/Change RED Behavior'
      }

      // End of If: '<S5>/This IF block determines whether or not to run the RED sim//exp ' 
    }

    // If: '<S13>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' incorporates:
    //   Constant: '<S525>/Constant'
    //   DataStoreRead: '<S13>/Data Store Read2'
    //   RelationalOperator: '<S525>/Relational Operator'
    //   RelationalOperator: '<S525>/Relational Operator1'

    APF_Path_Planning_2023a_B.rtPrevAction =
      APF_Path_Planning_2023a_DW.Ifperforminganexperimentgrabthe;
    APF_Path_Planning_2023a_B.rtAction = -1;
    if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
      if (APF_Path_Planning_2023a_DW.isSim == 0.0) {
        APF_Path_Planning_2023a_B.rtAction = 0;
      } else if (APF_Path_Planning_2023a_DW.isSim == 1.0) {
        APF_Path_Planning_2023a_B.rtAction = 1;
      }

      APF_Path_Planning_2023a_DW.Ifperforminganexperimentgrabthe =
        APF_Path_Planning_2023a_B.rtAction;
    } else {
      APF_Path_Planning_2023a_B.rtAction =
        APF_Path_Planning_2023a_DW.Ifperforminganexperimentgrabthe;
    }

    if ((APF_Path_Planning_2023a_B.rtPrevAction !=
         APF_Path_Planning_2023a_B.rtAction) &&
        (APF_Path_Planning_2023a_B.rtPrevAction == 0)) {
      // Disable for If: '<S534>/if we went through a "step"'
      APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_jt = -1;

      // Disable for If: '<S531>/if we went through a "step"'
      APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_lg = -1;

      // Disable for If: '<S539>/if we went through a "step"'
      APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ch = -1;

      // Disable for If: '<S528>/if we went through a "step"'
      APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_c5 = -1;

      // Disable for If: '<S540>/if we went through a "step"'
      APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ls = -1;

      // Disable for If: '<S529>/if we went through a "step"'
      APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_i2 = -1;

      // Disable for If: '<S541>/if we went through a "step"'
      APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_kz = -1;

      // Disable for If: '<S530>/if we went through a "step"'
      APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ed = -1;

      // Disable for If: '<S535>/if we went through a "step"'
      APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_o2 = -1;

      // Disable for If: '<S532>/if we went through a "step"'
      APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_cu = -1;

      // Disable for If: '<S536>/if we went through a "step"'
      APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_hb = -1;

      // Disable for If: '<S533>/if we went through a "step"'
      APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_fj = -1;

      // Disable for If: '<S527>/if we went through a "step"'
      APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ca = -1;

      // Disable for If: '<S542>/if we went through a "step"'
      APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ez = -1;

      // Disable for If: '<S537>/if we went through a "step"'
      APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_oo = -1;

      // Disable for If: '<S543>/if we went through a "step"'
      APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_hv = -1;

      // Disable for If: '<S538>/if we went through a "step"'
      APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_lu = -1;

      // Disable for If: '<S544>/if we went through a "step"'
      APF_Path_Planning_2023a_DW.ifwewentthroughastep_Active_lgb = -1;

      // Disable for Enabled SubSystem: '<S525>/Enabled Subsystem1'
      APF_Path_Planning_2023a_DW.EnabledSubsystem1_MODE = false;

      // End of Disable for SubSystem: '<S525>/Enabled Subsystem1'
    }

    switch (APF_Path_Planning_2023a_B.rtAction) {
     case 0:
      // Outputs for IfAction SubSystem: '<S13>/Use Hardware to Obtain States' incorporates:
      //   ActionPort: '<S524>/Action Port'

      // S-Function (sdspFromNetwork): '<S524>/UDP Receive1'
      sErr = GetErrorBuffer
        (&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib_b[0U]);
      APF_Path_Planning_2023a_B.ntIdx0 = 10;
      LibOutputs_Network(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib_b[0U],
                         &APF_Path_Planning_2023a_B.UDPReceive1_o1[0U],
                         &APF_Path_Planning_2023a_B.ntIdx0);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
      }

      // End of S-Function (sdspFromNetwork): '<S524>/UDP Receive1'

      // Gain: '<S524>/Convert REDX from [mm] to [m]'
      APF_Path_Planning_2023a_B.ConvertREDXfrommmtom =
        APF_Path_Planning_2023a_P.ConvertREDXfrommmtom_Gain *
        APF_Path_Planning_2023a_B.UDPReceive1_o1[1];

      // DataStoreWrite: '<S524>/RED_Px1'
      APF_Path_Planning_2023a_DW.RED_Px =
        APF_Path_Planning_2023a_B.ConvertREDXfrommmtom;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
      }

      // End of DataStoreWrite: '<S524>/RED_Px1'

      // Gain: '<S524>/Convert BLUX from [mm] to [m]'
      APF_Path_Planning_2023a_B.ConvertBLUXfrommmtom =
        APF_Path_Planning_2023a_P.ConvertBLUXfrommmtom_Gain *
        APF_Path_Planning_2023a_B.UDPReceive1_o1[7];
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // Delay: '<S534>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_lu) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_eo =
            APF_Path_Planning_2023a_B.ConvertBLUXfrommmtom;
        }

        // Delay: '<S534>/Delay1'
        APF_Path_Planning_2023a_B.Delay1_hy =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_eo;
      }

      // Sum: '<S534>/Sum6'
      APF_Path_Planning_2023a_B.sampleTime =
        APF_Path_Planning_2023a_B.ConvertBLUXfrommmtom -
        APF_Path_Planning_2023a_B.Delay1_hy;

      // If: '<S534>/if we went through a "step"'
      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_B.sampleTime != 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_jt =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_jt;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S534>/Hold this value' incorporates:
        //   ActionPort: '<S554>/Action Port'

        // SignalConversion generated from: '<S554>/In1'
        APF_Path_Planning_2023a_B.In1_em = APF_Path_Planning_2023a_B.sampleTime;

        // End of Outputs for SubSystem: '<S534>/Hold this value'
      }

      // End of If: '<S534>/if we went through a "step"'

      // Gain: '<S534>/divide by delta T'
      APF_Path_Planning_2023a_B.dividebydeltaT = 1.0 /
        APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_em;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // Delay: '<S531>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_ld) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_gs =
            APF_Path_Planning_2023a_B.dividebydeltaT;
        }

        // Delay: '<S531>/Delay1'
        APF_Path_Planning_2023a_B.Delay1_g =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_gs;
      }

      // If: '<S531>/if we went through a "step"' incorporates:
      //   Sum: '<S531>/Sum6'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_B.dividebydeltaT -
            APF_Path_Planning_2023a_B.Delay1_g != 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_lg =
          APF_Path_Planning_2023a_B.rtAction;
      }

      // End of If: '<S531>/if we went through a "step"'

      // Gain: '<S524>/Convert BLAX from [mm] to [m]'
      APF_Path_Planning_2023a_B.ConvertBLAXfrommmtom =
        APF_Path_Planning_2023a_P.ConvertBLAXfrommmtom_Gain *
        APF_Path_Planning_2023a_B.UDPReceive1_o1[4];
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // Delay: '<S539>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_dc) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_bm =
            APF_Path_Planning_2023a_B.ConvertBLAXfrommmtom;
        }

        // Delay: '<S539>/Delay1'
        APF_Path_Planning_2023a_B.Delay1_ha =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_bm;
      }

      // Sum: '<S539>/Sum6'
      APF_Path_Planning_2023a_B.sampleTime =
        APF_Path_Planning_2023a_B.ConvertBLAXfrommmtom -
        APF_Path_Planning_2023a_B.Delay1_ha;

      // If: '<S539>/if we went through a "step"'
      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_B.sampleTime != 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ch =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ch;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S539>/Hold this value' incorporates:
        //   ActionPort: '<S559>/Action Port'

        // SignalConversion generated from: '<S559>/In1'
        APF_Path_Planning_2023a_B.In1_f = APF_Path_Planning_2023a_B.sampleTime;

        // End of Outputs for SubSystem: '<S539>/Hold this value'
      }

      // End of If: '<S539>/if we went through a "step"'

      // Gain: '<S539>/divide by delta T'
      APF_Path_Planning_2023a_B.dividebydeltaT_f = 1.0 /
        APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_f;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // Delay: '<S528>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_k) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_p4 =
            APF_Path_Planning_2023a_B.dividebydeltaT_f;
        }

        // Delay: '<S528>/Delay1'
        APF_Path_Planning_2023a_B.Delay1_gd =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_p4;
      }

      // Sum: '<S528>/Sum6'
      APF_Path_Planning_2023a_B.sampleTime =
        APF_Path_Planning_2023a_B.dividebydeltaT_f -
        APF_Path_Planning_2023a_B.Delay1_gd;

      // If: '<S528>/if we went through a "step"'
      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_B.sampleTime != 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_c5 =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_c5;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S528>/Hold this value' incorporates:
        //   ActionPort: '<S548>/Action Port'

        // SignalConversion generated from: '<S548>/In1'
        APF_Path_Planning_2023a_B.In1_i = APF_Path_Planning_2023a_B.sampleTime;

        // End of Outputs for SubSystem: '<S528>/Hold this value'
      }

      // End of If: '<S528>/if we went through a "step"'

      // Gain: '<S528>/divide by delta T' incorporates:
      //   DataStoreWrite: '<S524>/RED_Px11'

      APF_Path_Planning_2023a_DW.BLACK_Ax = 1.0 /
        APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_i;

      // Gain: '<S524>/Convert BLAY from [mm] to [m]'
      APF_Path_Planning_2023a_B.ConvertBLAYfrommmtom =
        APF_Path_Planning_2023a_P.ConvertBLAYfrommmtom_Gain *
        APF_Path_Planning_2023a_B.UDPReceive1_o1[5];
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // Delay: '<S540>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_fv) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_md =
            APF_Path_Planning_2023a_B.ConvertBLAYfrommmtom;
        }

        // Delay: '<S540>/Delay1'
        APF_Path_Planning_2023a_B.Delay1_pp =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_md;
      }

      // Sum: '<S540>/Sum6'
      APF_Path_Planning_2023a_B.sampleTime =
        APF_Path_Planning_2023a_B.ConvertBLAYfrommmtom -
        APF_Path_Planning_2023a_B.Delay1_pp;

      // If: '<S540>/if we went through a "step"'
      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_B.sampleTime != 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ls =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ls;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S540>/Hold this value' incorporates:
        //   ActionPort: '<S560>/Action Port'

        // SignalConversion generated from: '<S560>/In1'
        APF_Path_Planning_2023a_B.In1_l = APF_Path_Planning_2023a_B.sampleTime;

        // End of Outputs for SubSystem: '<S540>/Hold this value'
      }

      // End of If: '<S540>/if we went through a "step"'

      // Gain: '<S540>/divide by delta T'
      APF_Path_Planning_2023a_B.dividebydeltaT_l = 1.0 /
        APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_l;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // Delay: '<S529>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_na) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_j =
            APF_Path_Planning_2023a_B.dividebydeltaT_l;
        }

        // Delay: '<S529>/Delay1'
        APF_Path_Planning_2023a_B.Delay1_jr =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_j;
      }

      // Sum: '<S529>/Sum6'
      APF_Path_Planning_2023a_B.sampleTime =
        APF_Path_Planning_2023a_B.dividebydeltaT_l -
        APF_Path_Planning_2023a_B.Delay1_jr;

      // If: '<S529>/if we went through a "step"'
      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_B.sampleTime != 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_i2 =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_i2;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S529>/Hold this value' incorporates:
        //   ActionPort: '<S549>/Action Port'

        // SignalConversion generated from: '<S549>/In1'
        APF_Path_Planning_2023a_B.In1_bk = APF_Path_Planning_2023a_B.sampleTime;

        // End of Outputs for SubSystem: '<S529>/Hold this value'
      }

      // End of If: '<S529>/if we went through a "step"'

      // Gain: '<S529>/divide by delta T' incorporates:
      //   DataStoreWrite: '<S524>/RED_Px12'

      APF_Path_Planning_2023a_DW.BLACK_Ay = 1.0 /
        APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_bk;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // S-Function (sdspunwrap2): '<S524>/Unwrap1'
        if (APF_Path_Planning_2023a_DW.Unwrap1_FirstStep) {
          APF_Path_Planning_2023a_DW.Unwrap1_Prev =
            APF_Path_Planning_2023a_B.UDPReceive1_o1[6];
          APF_Path_Planning_2023a_DW.Unwrap1_FirstStep = false;
        }

        APF_Path_Planning_2023a_B.sampleTime =
          APF_Path_Planning_2023a_B.UDPReceive1_o1[6] -
          APF_Path_Planning_2023a_DW.Unwrap1_Prev;
        APF_Path_Planning_2023a_B.RED_Tz_RW =
          APF_Path_Planning_2023a_B.sampleTime - floor
          ((APF_Path_Planning_2023a_B.sampleTime + 3.1415926535897931) /
           6.2831853071795862) * 6.2831853071795862;
        if ((APF_Path_Planning_2023a_B.RED_Tz_RW == -3.1415926535897931) &&
            (APF_Path_Planning_2023a_B.sampleTime > 0.0)) {
          APF_Path_Planning_2023a_B.RED_Tz_RW = 3.1415926535897931;
        }

        APF_Path_Planning_2023a_B.sampleTime =
          APF_Path_Planning_2023a_B.RED_Tz_RW -
          APF_Path_Planning_2023a_B.sampleTime;
        if (fabs(APF_Path_Planning_2023a_B.sampleTime) > 3.1415926535897931) {
          APF_Path_Planning_2023a_DW.Unwrap1_Cumsum +=
            APF_Path_Planning_2023a_B.sampleTime;
        }

        APF_Path_Planning_2023a_DW.Unwrap1_Prev =
          APF_Path_Planning_2023a_B.UDPReceive1_o1[6];

        // S-Function (sdspunwrap2): '<S524>/Unwrap1'
        APF_Path_Planning_2023a_B.Unwrap1 =
          APF_Path_Planning_2023a_B.UDPReceive1_o1[6] +
          APF_Path_Planning_2023a_DW.Unwrap1_Cumsum;

        // Delay: '<S541>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_gx) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_p4s =
            APF_Path_Planning_2023a_B.Unwrap1;
        }

        // Delay: '<S541>/Delay1'
        APF_Path_Planning_2023a_B.Delay1_ma =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_p4s;
      }

      // Sum: '<S541>/Sum6'
      APF_Path_Planning_2023a_B.sampleTime = APF_Path_Planning_2023a_B.Unwrap1 -
        APF_Path_Planning_2023a_B.Delay1_ma;

      // If: '<S541>/if we went through a "step"'
      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_B.sampleTime != 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_kz =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_kz;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S541>/Hold this value' incorporates:
        //   ActionPort: '<S561>/Action Port'

        // SignalConversion generated from: '<S561>/In1'
        APF_Path_Planning_2023a_B.In1_e0 = APF_Path_Planning_2023a_B.sampleTime;

        // End of Outputs for SubSystem: '<S541>/Hold this value'
      }

      // End of If: '<S541>/if we went through a "step"'

      // Gain: '<S541>/divide by delta T'
      APF_Path_Planning_2023a_B.dividebydeltaT_e = 1.0 /
        APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_e0;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // Delay: '<S530>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_m) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_k =
            APF_Path_Planning_2023a_B.dividebydeltaT_e;
        }

        // Delay: '<S530>/Delay1'
        APF_Path_Planning_2023a_B.Delay1_ez =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_k;
      }

      // Sum: '<S530>/Sum6'
      APF_Path_Planning_2023a_B.sampleTime =
        APF_Path_Planning_2023a_B.dividebydeltaT_e -
        APF_Path_Planning_2023a_B.Delay1_ez;

      // If: '<S530>/if we went through a "step"'
      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_B.sampleTime != 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ed =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ed;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S530>/Hold this value' incorporates:
        //   ActionPort: '<S550>/Action Port'

        // SignalConversion generated from: '<S550>/In1'
        APF_Path_Planning_2023a_B.In1_gr = APF_Path_Planning_2023a_B.sampleTime;

        // End of Outputs for SubSystem: '<S530>/Hold this value'
      }

      // End of If: '<S530>/if we went through a "step"'

      // Gain: '<S530>/divide by delta T' incorporates:
      //   DataStoreWrite: '<S524>/RED_Px13'

      APF_Path_Planning_2023a_DW.BLACK_RzDD = 1.0 /
        APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_gr;

      // Gain: '<S524>/Convert BLUY from [mm] to [m]'
      APF_Path_Planning_2023a_B.ConvertBLUYfrommmtom =
        APF_Path_Planning_2023a_P.ConvertBLUYfrommmtom_Gain *
        APF_Path_Planning_2023a_B.UDPReceive1_o1[8];
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // Delay: '<S535>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_e) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_mi =
            APF_Path_Planning_2023a_B.ConvertBLUYfrommmtom;
        }

        // Delay: '<S535>/Delay1'
        APF_Path_Planning_2023a_B.Delay1_pz =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_mi;
      }

      // Sum: '<S535>/Sum6'
      APF_Path_Planning_2023a_B.sampleTime =
        APF_Path_Planning_2023a_B.ConvertBLUYfrommmtom -
        APF_Path_Planning_2023a_B.Delay1_pz;

      // If: '<S535>/if we went through a "step"'
      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_B.sampleTime != 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_o2 =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_o2;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S535>/Hold this value' incorporates:
        //   ActionPort: '<S555>/Action Port'

        // SignalConversion generated from: '<S555>/In1'
        APF_Path_Planning_2023a_B.In1_en = APF_Path_Planning_2023a_B.sampleTime;

        // End of Outputs for SubSystem: '<S535>/Hold this value'
      }

      // End of If: '<S535>/if we went through a "step"'

      // Gain: '<S535>/divide by delta T'
      APF_Path_Planning_2023a_B.dividebydeltaT_c = 1.0 /
        APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_en;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // Delay: '<S532>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_fpv) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_pc =
            APF_Path_Planning_2023a_B.dividebydeltaT_c;
        }

        // Delay: '<S532>/Delay1'
        APF_Path_Planning_2023a_B.Delay1_pt =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_pc;
      }

      // If: '<S532>/if we went through a "step"' incorporates:
      //   Sum: '<S532>/Sum6'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_B.dividebydeltaT_c -
            APF_Path_Planning_2023a_B.Delay1_pt != 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_cu =
          APF_Path_Planning_2023a_B.rtAction;
      }

      // End of If: '<S532>/if we went through a "step"'
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // S-Function (sdspunwrap2): '<S524>/Unwrap2'
        if (APF_Path_Planning_2023a_DW.Unwrap2_FirstStep) {
          APF_Path_Planning_2023a_DW.Unwrap2_Prev =
            APF_Path_Planning_2023a_B.UDPReceive1_o1[9];
          APF_Path_Planning_2023a_DW.Unwrap2_FirstStep = false;
        }

        APF_Path_Planning_2023a_B.sampleTime =
          APF_Path_Planning_2023a_B.UDPReceive1_o1[9] -
          APF_Path_Planning_2023a_DW.Unwrap2_Prev;
        APF_Path_Planning_2023a_B.RED_Tz_RW =
          APF_Path_Planning_2023a_B.sampleTime - floor
          ((APF_Path_Planning_2023a_B.sampleTime + 3.1415926535897931) /
           6.2831853071795862) * 6.2831853071795862;
        if ((APF_Path_Planning_2023a_B.RED_Tz_RW == -3.1415926535897931) &&
            (APF_Path_Planning_2023a_B.sampleTime > 0.0)) {
          APF_Path_Planning_2023a_B.RED_Tz_RW = 3.1415926535897931;
        }

        APF_Path_Planning_2023a_B.sampleTime =
          APF_Path_Planning_2023a_B.RED_Tz_RW -
          APF_Path_Planning_2023a_B.sampleTime;
        if (fabs(APF_Path_Planning_2023a_B.sampleTime) > 3.1415926535897931) {
          APF_Path_Planning_2023a_DW.Unwrap2_Cumsum +=
            APF_Path_Planning_2023a_B.sampleTime;
        }

        APF_Path_Planning_2023a_DW.Unwrap2_Prev =
          APF_Path_Planning_2023a_B.UDPReceive1_o1[9];

        // S-Function (sdspunwrap2): '<S524>/Unwrap2'
        APF_Path_Planning_2023a_B.Unwrap2 =
          APF_Path_Planning_2023a_B.UDPReceive1_o1[9] +
          APF_Path_Planning_2023a_DW.Unwrap2_Cumsum;

        // Delay: '<S536>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_mt) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_cu =
            APF_Path_Planning_2023a_B.Unwrap2;
        }

        // Delay: '<S536>/Delay1'
        APF_Path_Planning_2023a_B.Delay1_ph =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_cu;
      }

      // Sum: '<S536>/Sum6'
      APF_Path_Planning_2023a_B.sampleTime = APF_Path_Planning_2023a_B.Unwrap2 -
        APF_Path_Planning_2023a_B.Delay1_ph;

      // If: '<S536>/if we went through a "step"'
      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_B.sampleTime != 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_hb =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_hb;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S536>/Hold this value' incorporates:
        //   ActionPort: '<S556>/Action Port'

        // SignalConversion generated from: '<S556>/In1'
        APF_Path_Planning_2023a_B.In1_m = APF_Path_Planning_2023a_B.sampleTime;

        // End of Outputs for SubSystem: '<S536>/Hold this value'
      }

      // End of If: '<S536>/if we went through a "step"'

      // Gain: '<S536>/divide by delta T'
      APF_Path_Planning_2023a_B.dividebydeltaT_cy = 1.0 /
        APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_m;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // Delay: '<S533>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_nw) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_a0 =
            APF_Path_Planning_2023a_B.dividebydeltaT_cy;
        }

        // Delay: '<S533>/Delay1'
        APF_Path_Planning_2023a_B.Delay1_k =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_a0;
      }

      // If: '<S533>/if we went through a "step"' incorporates:
      //   Sum: '<S533>/Sum6'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_B.dividebydeltaT_cy -
            APF_Path_Planning_2023a_B.Delay1_k != 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_fj =
          APF_Path_Planning_2023a_B.rtAction;
      }

      // End of If: '<S533>/if we went through a "step"'

      // DataStoreWrite: '<S524>/RED_Px17'
      APF_Path_Planning_2023a_DW.BLUE_Vx =
        APF_Path_Planning_2023a_B.dividebydeltaT;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
      }

      // End of DataStoreWrite: '<S524>/RED_Px17'

      // DataStoreWrite: '<S524>/RED_Px18'
      APF_Path_Planning_2023a_DW.BLUE_Px =
        APF_Path_Planning_2023a_B.ConvertBLUXfrommmtom;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
      }

      // End of DataStoreWrite: '<S524>/RED_Px18'

      // DataStoreWrite: '<S524>/RED_Px19'
      APF_Path_Planning_2023a_DW.BLUE_Py =
        APF_Path_Planning_2023a_B.ConvertBLUYfrommmtom;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
      }

      // End of DataStoreWrite: '<S524>/RED_Px19'
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // Delay: '<S527>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_h) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_h =
            APF_Path_Planning_2023a_B.ConvertREDXfrommmtom;
        }

        // Delay: '<S527>/Delay1'
        APF_Path_Planning_2023a_B.Delay1_f5 =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_h;
      }

      // Sum: '<S527>/Sum6'
      APF_Path_Planning_2023a_B.sampleTime =
        APF_Path_Planning_2023a_B.ConvertREDXfrommmtom -
        APF_Path_Planning_2023a_B.Delay1_f5;

      // If: '<S527>/if we went through a "step"'
      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_B.sampleTime != 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ca =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ca;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S527>/Hold this value' incorporates:
        //   ActionPort: '<S547>/Action Port'

        // SignalConversion generated from: '<S547>/In1'
        APF_Path_Planning_2023a_B.In1_a = APF_Path_Planning_2023a_B.sampleTime;

        // End of Outputs for SubSystem: '<S527>/Hold this value'
      }

      // End of If: '<S527>/if we went through a "step"'

      // Gain: '<S527>/divide by delta T'
      APF_Path_Planning_2023a_B.dividebydeltaT_n = 1.0 /
        APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_a;

      // DataStoreWrite: '<S524>/RED_Px2'
      APF_Path_Planning_2023a_DW.RED_Vx =
        APF_Path_Planning_2023a_B.dividebydeltaT_n;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
      }

      // End of DataStoreWrite: '<S524>/RED_Px2'

      // DataStoreWrite: '<S524>/RED_Px20'
      APF_Path_Planning_2023a_DW.BLUE_Rz =
        APF_Path_Planning_2023a_B.UDPReceive1_o1[9];
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
      }

      // End of DataStoreWrite: '<S524>/RED_Px20'

      // DataStoreWrite: '<S524>/RED_Px3'
      APF_Path_Planning_2023a_DW.BLACK_Vx =
        APF_Path_Planning_2023a_B.dividebydeltaT_f;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
      }

      // End of DataStoreWrite: '<S524>/RED_Px3'

      // DataStoreWrite: '<S524>/RED_Px4'
      APF_Path_Planning_2023a_DW.BLACK_Px =
        APF_Path_Planning_2023a_B.ConvertBLAXfrommmtom;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
      }

      // End of DataStoreWrite: '<S524>/RED_Px4'

      // DataStoreWrite: '<S524>/RED_Px5'
      APF_Path_Planning_2023a_DW.BLACK_Py =
        APF_Path_Planning_2023a_B.ConvertBLAYfrommmtom;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
      }

      // End of DataStoreWrite: '<S524>/RED_Px5'

      // DataStoreWrite: '<S524>/RED_Px6'
      APF_Path_Planning_2023a_DW.BLACK_Rz =
        APF_Path_Planning_2023a_B.UDPReceive1_o1[6];
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
      }

      // End of DataStoreWrite: '<S524>/RED_Px6'
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // Delay: '<S542>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_au) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_ah =
            APF_Path_Planning_2023a_B.dividebydeltaT_n;
        }

        // Delay: '<S542>/Delay1'
        APF_Path_Planning_2023a_B.Delay1_cz =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_ah;
      }

      // Sum: '<S542>/Sum6'
      APF_Path_Planning_2023a_B.sampleTime =
        APF_Path_Planning_2023a_B.dividebydeltaT_n -
        APF_Path_Planning_2023a_B.Delay1_cz;

      // If: '<S542>/if we went through a "step"'
      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_B.sampleTime != 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ez =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ez;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S542>/Hold this value' incorporates:
        //   ActionPort: '<S562>/Action Port'

        // SignalConversion generated from: '<S562>/In1'
        APF_Path_Planning_2023a_B.In1_o = APF_Path_Planning_2023a_B.sampleTime;

        // End of Outputs for SubSystem: '<S542>/Hold this value'
      }

      // End of If: '<S542>/if we went through a "step"'

      // Gain: '<S542>/divide by delta T' incorporates:
      //   DataStoreWrite: '<S524>/RED_Px7'

      APF_Path_Planning_2023a_DW.RED_Ax = 1.0 /
        APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_o;

      // Gain: '<S524>/Convert REDY from [mm] to [m]'
      APF_Path_Planning_2023a_B.ConvertREDYfrommmtom =
        APF_Path_Planning_2023a_P.ConvertREDYfrommmtom_Gain *
        APF_Path_Planning_2023a_B.UDPReceive1_o1[2];
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // Delay: '<S537>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_eo) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_lx =
            APF_Path_Planning_2023a_B.ConvertREDYfrommmtom;
        }

        // Delay: '<S537>/Delay1'
        APF_Path_Planning_2023a_B.Delay1_lh =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_lx;
      }

      // Sum: '<S537>/Sum6'
      APF_Path_Planning_2023a_B.sampleTime =
        APF_Path_Planning_2023a_B.ConvertREDYfrommmtom -
        APF_Path_Planning_2023a_B.Delay1_lh;

      // If: '<S537>/if we went through a "step"'
      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_B.sampleTime != 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_oo =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_oo;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S537>/Hold this value' incorporates:
        //   ActionPort: '<S557>/Action Port'

        // SignalConversion generated from: '<S557>/In1'
        APF_Path_Planning_2023a_B.In1_b = APF_Path_Planning_2023a_B.sampleTime;

        // End of Outputs for SubSystem: '<S537>/Hold this value'
      }

      // End of If: '<S537>/if we went through a "step"'

      // Gain: '<S537>/divide by delta T'
      APF_Path_Planning_2023a_B.dividebydeltaT_n1 = 1.0 /
        APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_b;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // Delay: '<S543>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_fh) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_j3 =
            APF_Path_Planning_2023a_B.dividebydeltaT_n1;
        }

        // Delay: '<S543>/Delay1'
        APF_Path_Planning_2023a_B.Delay1_jo =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_j3;
      }

      // Sum: '<S543>/Sum6'
      APF_Path_Planning_2023a_B.sampleTime =
        APF_Path_Planning_2023a_B.dividebydeltaT_n1 -
        APF_Path_Planning_2023a_B.Delay1_jo;

      // If: '<S543>/if we went through a "step"'
      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_B.sampleTime != 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_hv =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_hv;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S543>/Hold this value' incorporates:
        //   ActionPort: '<S563>/Action Port'

        // SignalConversion generated from: '<S563>/In1'
        APF_Path_Planning_2023a_B.In1_e = APF_Path_Planning_2023a_B.sampleTime;

        // End of Outputs for SubSystem: '<S543>/Hold this value'
      }

      // End of If: '<S543>/if we went through a "step"'

      // Gain: '<S543>/divide by delta T' incorporates:
      //   DataStoreWrite: '<S524>/RED_Px8'

      APF_Path_Planning_2023a_DW.RED_Ay = 1.0 /
        APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_e;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // S-Function (sdspunwrap2): '<S524>/Unwrap'
        if (APF_Path_Planning_2023a_DW.Unwrap_FirstStep) {
          APF_Path_Planning_2023a_DW.Unwrap_Prev =
            APF_Path_Planning_2023a_B.UDPReceive1_o1[3];
          APF_Path_Planning_2023a_DW.Unwrap_FirstStep = false;
        }

        APF_Path_Planning_2023a_B.sampleTime =
          APF_Path_Planning_2023a_B.UDPReceive1_o1[3] -
          APF_Path_Planning_2023a_DW.Unwrap_Prev;
        APF_Path_Planning_2023a_B.RED_Tz_RW =
          APF_Path_Planning_2023a_B.sampleTime - floor
          ((APF_Path_Planning_2023a_B.sampleTime + 3.1415926535897931) /
           6.2831853071795862) * 6.2831853071795862;
        if ((APF_Path_Planning_2023a_B.RED_Tz_RW == -3.1415926535897931) &&
            (APF_Path_Planning_2023a_B.sampleTime > 0.0)) {
          APF_Path_Planning_2023a_B.RED_Tz_RW = 3.1415926535897931;
        }

        APF_Path_Planning_2023a_B.sampleTime =
          APF_Path_Planning_2023a_B.RED_Tz_RW -
          APF_Path_Planning_2023a_B.sampleTime;
        if (fabs(APF_Path_Planning_2023a_B.sampleTime) > 3.1415926535897931) {
          APF_Path_Planning_2023a_DW.Unwrap_Cumsum +=
            APF_Path_Planning_2023a_B.sampleTime;
        }

        APF_Path_Planning_2023a_DW.Unwrap_Prev =
          APF_Path_Planning_2023a_B.UDPReceive1_o1[3];

        // S-Function (sdspunwrap2): '<S524>/Unwrap'
        APF_Path_Planning_2023a_B.Unwrap =
          APF_Path_Planning_2023a_B.UDPReceive1_o1[3] +
          APF_Path_Planning_2023a_DW.Unwrap_Cumsum;

        // Delay: '<S538>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_fow) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_m2 =
            APF_Path_Planning_2023a_B.Unwrap;
        }

        // Delay: '<S538>/Delay1'
        APF_Path_Planning_2023a_B.Delay1_gm =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_m2;
      }

      // Sum: '<S538>/Sum6'
      APF_Path_Planning_2023a_B.sampleTime = APF_Path_Planning_2023a_B.Unwrap -
        APF_Path_Planning_2023a_B.Delay1_gm;

      // If: '<S538>/if we went through a "step"'
      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_B.sampleTime != 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_lu =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_lu;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S538>/Hold this value' incorporates:
        //   ActionPort: '<S558>/Action Port'

        // SignalConversion generated from: '<S558>/In1'
        APF_Path_Planning_2023a_B.In1_eg = APF_Path_Planning_2023a_B.sampleTime;

        // End of Outputs for SubSystem: '<S538>/Hold this value'
      }

      // End of If: '<S538>/if we went through a "step"'

      // Gain: '<S538>/divide by delta T'
      APF_Path_Planning_2023a_B.dividebydeltaT_m = 1.0 /
        APF_Path_Planning_2023a_P.baseRate * APF_Path_Planning_2023a_B.In1_eg;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // Delay: '<S544>/Delay1'
        if (APF_Path_Planning_2023a_DW.icLoad_aq) {
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_hi =
            APF_Path_Planning_2023a_B.dividebydeltaT_m;
        }

        // Delay: '<S544>/Delay1'
        APF_Path_Planning_2023a_B.Delay1_dd =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_hi;
      }

      // Sum: '<S544>/Sum6'
      APF_Path_Planning_2023a_B.sampleTime =
        APF_Path_Planning_2023a_B.dividebydeltaT_m -
        APF_Path_Planning_2023a_B.Delay1_dd;

      // If: '<S544>/if we went through a "step"'
      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_B.sampleTime != 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ifwewentthroughastep_Active_lgb =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ifwewentthroughastep_Active_lgb;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S544>/Hold this value' incorporates:
        //   ActionPort: '<S564>/Action Port'

        // SignalConversion generated from: '<S564>/In1'
        APF_Path_Planning_2023a_B.In1_g20asdtgi0cdyix =
          APF_Path_Planning_2023a_B.sampleTime;

        // End of Outputs for SubSystem: '<S544>/Hold this value'
      }

      // End of If: '<S544>/if we went through a "step"'

      // Gain: '<S544>/divide by delta T' incorporates:
      //   DataStoreWrite: '<S524>/RED_Px9'

      APF_Path_Planning_2023a_DW.RED_RzDD = 1.0 /
        APF_Path_Planning_2023a_P.baseRate *
        APF_Path_Planning_2023a_B.In1_g20asdtgi0cdyix;

      // DataStoreWrite: '<S524>/RED_Py1'
      APF_Path_Planning_2023a_DW.RED_Py =
        APF_Path_Planning_2023a_B.ConvertREDYfrommmtom;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
      }

      // End of DataStoreWrite: '<S524>/RED_Py1'

      // DataStoreWrite: '<S524>/RED_Py2'
      APF_Path_Planning_2023a_DW.RED_Vy =
        APF_Path_Planning_2023a_B.dividebydeltaT_n1;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
      }

      // End of DataStoreWrite: '<S524>/RED_Py2'

      // DataStoreWrite: '<S524>/RED_Py3'
      APF_Path_Planning_2023a_DW.BLACK_Vy =
        APF_Path_Planning_2023a_B.dividebydeltaT_l;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
      }

      // End of DataStoreWrite: '<S524>/RED_Py3'

      // DataStoreWrite: '<S524>/RED_Py4'
      APF_Path_Planning_2023a_DW.BLUE_Vy =
        APF_Path_Planning_2023a_B.dividebydeltaT_c;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
      }

      // End of DataStoreWrite: '<S524>/RED_Py4'

      // DataStoreWrite: '<S524>/RED_Rz1'
      APF_Path_Planning_2023a_DW.RED_Rz =
        APF_Path_Planning_2023a_B.UDPReceive1_o1[3];
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
      }

      // End of DataStoreWrite: '<S524>/RED_Rz1'

      // DataStoreWrite: '<S524>/RED_Rz2'
      APF_Path_Planning_2023a_DW.RED_RzD =
        APF_Path_Planning_2023a_B.dividebydeltaT_m;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
      }

      // End of DataStoreWrite: '<S524>/RED_Rz2'

      // DataStoreWrite: '<S524>/RED_Rz3'
      APF_Path_Planning_2023a_DW.BLACK_RzD =
        APF_Path_Planning_2023a_B.dividebydeltaT_e;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
      }

      // End of DataStoreWrite: '<S524>/RED_Rz3'

      // DataStoreWrite: '<S524>/RED_Rz4'
      APF_Path_Planning_2023a_DW.BLUE_RzD =
        APF_Path_Planning_2023a_B.dividebydeltaT_cy;
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, true);
      }

      // End of DataStoreWrite: '<S524>/RED_Rz4'
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // Delay: '<S524>/Delay'
        APF_Path_Planning_2023a_B.Delay_g =
          APF_Path_Planning_2023a_DW.Delay_DSTATE_l[0];

        // Delay: '<S524>/Delay1'
        APF_Path_Planning_2023a_B.Delay1_cj =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_hu[0];

        // Delay: '<S524>/Delay2'
        APF_Path_Planning_2023a_B.Delay2 =
          APF_Path_Planning_2023a_DW.Delay2_DSTATE_k[0];
      }

      // MATLAB Function: '<S524>/MATLAB Function'
      APF_Path_Planning_2023a_B.StartClock = 0;
      if (APF_Path_Planning_2023a_P.platformSelection == 1.0) {
        APF_Path_Planning_2023a_B.StartClock =
          (APF_Path_Planning_2023a_B.Delay_g == 1);
      } else if (APF_Path_Planning_2023a_P.platformSelection == 2.0) {
        APF_Path_Planning_2023a_B.StartClock =
          (APF_Path_Planning_2023a_B.Delay1_cj == 1);
      } else if (APF_Path_Planning_2023a_P.platformSelection == 3.0) {
        APF_Path_Planning_2023a_B.StartClock =
          ((APF_Path_Planning_2023a_B.Delay_g == 1) &&
           (APF_Path_Planning_2023a_B.Delay1_cj == 1));
      } else if (APF_Path_Planning_2023a_P.platformSelection == 4.0) {
        APF_Path_Planning_2023a_B.StartClock =
          ((APF_Path_Planning_2023a_B.Delay_g == 1) &&
           (APF_Path_Planning_2023a_B.Delay1_cj == 1));
      } else if (APF_Path_Planning_2023a_P.platformSelection == 5.0) {
        APF_Path_Planning_2023a_B.StartClock =
          (APF_Path_Planning_2023a_B.Delay_g == 1);
      } else if (APF_Path_Planning_2023a_P.platformSelection == 6.0) {
        APF_Path_Planning_2023a_B.StartClock = (APF_Path_Planning_2023a_B.Delay2
          == 1);
      } else if (APF_Path_Planning_2023a_P.platformSelection == 7.0) {
        APF_Path_Planning_2023a_B.StartClock =
          ((APF_Path_Planning_2023a_B.Delay_g == 1) &&
           (APF_Path_Planning_2023a_B.Delay2 == 1));
      } else if (APF_Path_Planning_2023a_P.platformSelection == 8.0) {
        APF_Path_Planning_2023a_B.StartClock =
          ((APF_Path_Planning_2023a_B.Delay_g == 1) &&
           (APF_Path_Planning_2023a_B.Delay1_cj == 1) &&
           (APF_Path_Planning_2023a_B.Delay2 == 1));
      } else if (APF_Path_Planning_2023a_P.platformSelection == 9.0) {
        APF_Path_Planning_2023a_B.StartClock =
          ((APF_Path_Planning_2023a_B.Delay1_cj == 1) &&
           (APF_Path_Planning_2023a_B.Delay2 == 1));
      } else if (APF_Path_Planning_2023a_P.platformSelection == 10.0) {
        APF_Path_Planning_2023a_B.StartClock =
          ((APF_Path_Planning_2023a_B.Delay_g == 1) &&
           (APF_Path_Planning_2023a_B.Delay2 == 1));
      } else if (APF_Path_Planning_2023a_P.platformSelection == 11.0) {
        APF_Path_Planning_2023a_B.StartClock =
          ((APF_Path_Planning_2023a_B.Delay_g == 1) &&
           (APF_Path_Planning_2023a_B.Delay1_cj == 1) &&
           (APF_Path_Planning_2023a_B.Delay2 == 1));
      }

      // End of MATLAB Function: '<S524>/MATLAB Function'
      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // Outputs for Enabled SubSystem: '<S525>/Enabled Subsystem' incorporates:
        //   EnablePort: '<S545>/Enable'

        if (APF_Path_Planning_2023a_B.StartClock !=
            APF_Path_Planning_2023a_P.Constant_Value) {
          // Memory: '<S545>/Memory'
          APF_Path_Planning_2023a_B.Memory =
            APF_Path_Planning_2023a_DW.Memory_PreviousInput;

          // Update for Memory: '<S545>/Memory'
          APF_Path_Planning_2023a_DW.Memory_PreviousInput =
            APF_Path_Planning_2023a_B.UDPReceive1_o1[0];
        }

        // End of Outputs for SubSystem: '<S525>/Enabled Subsystem'

        // Outputs for Enabled SubSystem: '<S525>/Enabled Subsystem1' incorporates:
        //   EnablePort: '<S546>/Enable'

        if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
          APF_Path_Planning_2023a_DW.EnabledSubsystem1_MODE =
            (APF_Path_Planning_2023a_B.StartClock ==
             APF_Path_Planning_2023a_P.Constant_Value);
        }

        // End of Outputs for SubSystem: '<S525>/Enabled Subsystem1'
      }

      // Outputs for Enabled SubSystem: '<S525>/Enabled Subsystem1' incorporates:
      //   EnablePort: '<S546>/Enable'

      if (APF_Path_Planning_2023a_DW.EnabledSubsystem1_MODE) {
        // Sum: '<S546>/Subtract'
        APF_Path_Planning_2023a_B.Subtract_l =
          APF_Path_Planning_2023a_B.UDPReceive1_o1[0] -
          APF_Path_Planning_2023a_B.Memory;
      }

      // End of Outputs for SubSystem: '<S525>/Enabled Subsystem1'

      // DataStoreWrite: '<S524>/Universal_Time' incorporates:
      //   Constant: '<S525>/Constant'
      //   RelationalOperator: '<S525>/Relational Operator'
      //   RelationalOperator: '<S525>/Relational Operator1'

      APF_Path_Planning_2023a_DW.Univ_Time =
        APF_Path_Planning_2023a_B.Subtract_l;

      // S-Function (sdspFromNetwork): '<S524>/UDP Receive'
      sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPReceive_NetworkLib[0U]);
      APF_Path_Planning_2023a_B.StartClock = 1;
      LibOutputs_Network(&APF_Path_Planning_2023a_DW.UDPReceive_NetworkLib[0U],
                         &APF_Path_Planning_2023a_B.UDPReceive_o1,
                         &APF_Path_Planning_2023a_B.StartClock);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
      }

      // End of S-Function (sdspFromNetwork): '<S524>/UDP Receive'

      // S-Function (sdspFromNetwork): '<S524>/UDP Receive2'
      sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPReceive2_NetworkLib
                            [0U]);
      APF_Path_Planning_2023a_B.yElIdx = 1;
      LibOutputs_Network(&APF_Path_Planning_2023a_DW.UDPReceive2_NetworkLib[0U],
                         &APF_Path_Planning_2023a_B.UDPReceive2_o1,
                         &APF_Path_Planning_2023a_B.yElIdx);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
      }

      // End of S-Function (sdspFromNetwork): '<S524>/UDP Receive2'

      // S-Function (sdspFromNetwork): '<S524>/UDP Receive3'
      sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPReceive3_NetworkLib
                            [0U]);
      APF_Path_Planning_2023a_B.uElOffset1 = 1;
      LibOutputs_Network(&APF_Path_Planning_2023a_DW.UDPReceive3_NetworkLib[0U],
                         &APF_Path_Planning_2023a_B.UDPReceive3_o1,
                         &APF_Path_Planning_2023a_B.uElOffset1);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
      }

      // End of S-Function (sdspFromNetwork): '<S524>/UDP Receive3'
      // End of Outputs for SubSystem: '<S13>/Use Hardware to Obtain States'
      break;

     case 1:
      // Outputs for IfAction SubSystem: '<S13>/Initialize Universal Time (Simulation)' incorporates:
      //   ActionPort: '<S523>/Action Port'

      // Clock: '<S523>/Set Universal Time (If this is a simulation)' incorporates:
      //   DataStoreWrite: '<S523>/Universal_Time'

      APF_Path_Planning_2023a_DW.Univ_Time = APF_Path_Planning_2023a_M->
        Timing.t[0];

      // End of Outputs for SubSystem: '<S13>/Initialize Universal Time (Simulation)' 
      break;
    }

    // End of If: '<S13>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 
    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // If: '<S14>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' incorporates:
      //   DataStoreRead: '<S14>/Data Store Read1'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_DW.isSim == 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.IfsimModesetto1thenthisisasim_f =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.IfsimModesetto1thenthisisasim_f;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S14>/Subsystem' incorporates:
        //   ActionPort: '<S565>/Action Port'

        // MATLABSystem: '<S565>/WhoAmI' incorporates:
        //   DataStoreWrite: '<S565>/Data Store Write'

        if (APF_Path_Planning_2023a_DW.obj_dk.SampleTime !=
            APF_Path_Planning_2023a_P.baseRate) {
          if (((!rtIsInf(APF_Path_Planning_2023a_P.baseRate)) && (!rtIsNaN
                (APF_Path_Planning_2023a_P.baseRate))) || rtIsInf
              (APF_Path_Planning_2023a_P.baseRate)) {
            APF_Path_Planning_2023a_B.sampleTime_j =
              APF_Path_Planning_2023a_P.baseRate;
          }

          APF_Path_Planning_2023a_DW.obj_dk.SampleTime =
            APF_Path_Planning_2023a_B.sampleTime_j;
        }

        //         %% Define output properties
        //  Call C-function implementing device output
        APF_Path_Planning_2023a_DW.WhoAmI = WhoAmI();

        // End of MATLABSystem: '<S565>/WhoAmI'

        // DataStoreWrite: '<S565>/Data Store Write'
        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          rtsiSetBlockStateForSolverChangedAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
          rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
            (&APF_Path_Planning_2023a_M->solverInfo, true);
        }

        // End of Outputs for SubSystem: '<S14>/Subsystem'
      }

      // End of If: '<S14>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 

      // If: '<S15>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
      //   DataStoreRead: '<S15>/Data Store Read'
      //   DataStoreRead: '<S15>/Data Store Read1'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if ((APF_Path_Planning_2023a_DW.WhoAmI == 1.0) &&
            (APF_Path_Planning_2023a_DW.isSim == 0.0)) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_g =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_g;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S15>/Change RED Behavior' incorporates:
        //   ActionPort: '<S566>/Action Port'

        // MATLABSystem: '<S566>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' incorporates:
        //   DataStoreRead: '<S566>/Arm Control Mode'
        //   DataStoreRead: '<S566>/Elbow Command'
        //   DataStoreRead: '<S566>/Shoulder Command'
        //   DataStoreRead: '<S566>/Wrist Command'

        if (APF_Path_Planning_2023a_DW.obj.POSITION_P_GAIN !=
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsineith) {
          APF_Path_Planning_2023a_DW.obj.POSITION_P_GAIN =
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsineith;
        }

        if (APF_Path_Planning_2023a_DW.obj.POSITION_I_GAIN !=
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_c) {
          APF_Path_Planning_2023a_DW.obj.POSITION_I_GAIN =
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_c;
        }

        if (APF_Path_Planning_2023a_DW.obj.POSITION_D_GAIN !=
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_d) {
          APF_Path_Planning_2023a_DW.obj.POSITION_D_GAIN =
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_d;
        }

        if (APF_Path_Planning_2023a_DW.obj.MAX_POSITION !=
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_n) {
          APF_Path_Planning_2023a_DW.obj.MAX_POSITION =
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_n;
        }

        if (APF_Path_Planning_2023a_DW.obj.MIN_POSITION !=
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_g) {
          APF_Path_Planning_2023a_DW.obj.MIN_POSITION =
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_g;
        }

        if (APF_Path_Planning_2023a_DW.obj.MOVE_TIME !=
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsine_cw) {
          APF_Path_Planning_2023a_DW.obj.MOVE_TIME =
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsine_cw;
        }

        if (APF_Path_Planning_2023a_DW.obj.CURRENT_LIMIT !=
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_e) {
          APF_Path_Planning_2023a_DW.obj.CURRENT_LIMIT =
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_e;
        }

        if (APF_Path_Planning_2023a_DW.obj.SPEED_P_GAIN !=
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_k) {
          APF_Path_Planning_2023a_DW.obj.SPEED_P_GAIN =
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_k;
        }

        if (APF_Path_Planning_2023a_DW.obj.SPEED_I_GAIN !=
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_j) {
          APF_Path_Planning_2023a_DW.obj.SPEED_I_GAIN =
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_j;
        }

        if (APF_Path_Planning_2023a_DW.obj.VELOCITY_LIMIT !=
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_l) {
          APF_Path_Planning_2023a_DW.obj.VELOCITY_LIMIT =
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_l;
        }

        if (APF_Path_Planning_2023a_DW.obj.ACCELERATION_TIME !=
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_o) {
          APF_Path_Planning_2023a_DW.obj.ACCELERATION_TIME =
            APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_o;
        }

        if (APF_Path_Planning_2023a_DW.obj.SampleTime !=
            APF_Path_Planning_2023a_P.baseRate) {
          if (((!rtIsInf(APF_Path_Planning_2023a_P.baseRate)) && (!rtIsNaN
                (APF_Path_Planning_2023a_P.baseRate))) || rtIsInf
              (APF_Path_Planning_2023a_P.baseRate)) {
            APF_Path_Planning_2023a_B.sampleTime_d =
              APF_Path_Planning_2023a_P.baseRate;
          }

          APF_Path_Planning_2023a_DW.obj.SampleTime =
            APF_Path_Planning_2023a_B.sampleTime_d;
        }

        //         %% Define input properties
        //  Call C-function implementing device output
        //  include the dynamicel functions
        //  Run the main controller code. If the switch state is
        //  true then this code will initialize the parameters and
        //  then start the actuator, and THEN run the command. If the
        //  switch state is false, it will not reinitialize the
        //  motor
        dynamixel_controller(APF_Path_Planning_2023a_DW.RED_ARM_Control_Mode,
                             APF_Path_Planning_2023a_DW.obj.POSITION_P_GAIN,
                             APF_Path_Planning_2023a_DW.obj.POSITION_I_GAIN,
                             APF_Path_Planning_2023a_DW.obj.POSITION_D_GAIN,
                             APF_Path_Planning_2023a_DW.obj.MAX_POSITION,
                             APF_Path_Planning_2023a_DW.obj.MIN_POSITION,
                             APF_Path_Planning_2023a_DW.obj.MOVE_TIME,
                             APF_Path_Planning_2023a_DW.RED_Shoulder_Command,
                             APF_Path_Planning_2023a_DW.RED_Elbow_Command,
                             APF_Path_Planning_2023a_DW.RED_Wrist_Command,
                             APF_Path_Planning_2023a_DW.obj.CURRENT_LIMIT,
                             APF_Path_Planning_2023a_DW.RED_Shoulder_Command,
                             APF_Path_Planning_2023a_DW.RED_Elbow_Command,
                             APF_Path_Planning_2023a_DW.RED_Wrist_Command,
                             APF_Path_Planning_2023a_DW.obj.SPEED_P_GAIN,
                             APF_Path_Planning_2023a_DW.obj.SPEED_I_GAIN,
                             APF_Path_Planning_2023a_DW.obj.VELOCITY_LIMIT,
                             APF_Path_Planning_2023a_DW.RED_Shoulder_Command,
                             APF_Path_Planning_2023a_DW.RED_Elbow_Command,
                             APF_Path_Planning_2023a_DW.RED_Wrist_Command,
                             APF_Path_Planning_2023a_DW.obj.ACCELERATION_TIME);

        // End of MATLABSystem: '<S566>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
        // End of Outputs for SubSystem: '<S15>/Change RED Behavior'
      }

      // End of If: '<S15>/This IF block determines whether or not to run the RED sim//exp ' 

      // If: '<S16>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' incorporates:
      //   DataStoreRead: '<S16>/Data Store Read1'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if (APF_Path_Planning_2023a_DW.isSim == 0.0) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.IfsimModesetto1thenthisisasim_h =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.IfsimModesetto1thenthisisasim_h;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S16>/Subsystem' incorporates:
        //   ActionPort: '<S567>/Action Port'

        // SignalConversion generated from: '<S567>/UDP Send' incorporates:
        //   DataStoreRead: '<S567>/BLACK_Px'
        //   DataStoreRead: '<S567>/BLACK_Py'
        //   DataStoreRead: '<S567>/BLACK_Rz'
        //   DataStoreRead: '<S567>/BLACK_RzD'
        //   DataStoreRead: '<S567>/BLACK_Vx'
        //   DataStoreRead: '<S567>/BLACK_Vy'
        //   DataStoreRead: '<S567>/BLUE_Px'
        //   DataStoreRead: '<S567>/BLUE_Py'
        //   DataStoreRead: '<S567>/BLUE_Rz'
        //   DataStoreRead: '<S567>/BLUE_RzD'
        //   DataStoreRead: '<S567>/BLUE_Vx'
        //   DataStoreRead: '<S567>/BLUE_Vy'
        //   DataStoreRead: '<S567>/RED_Px'
        //   DataStoreRead: '<S567>/RED_Py '
        //   DataStoreRead: '<S567>/RED_Rz'
        //   DataStoreRead: '<S567>/RED_Vx '
        //   DataStoreRead: '<S567>/RED_Vy'
        //   DataStoreRead: '<S567>/RED_Vz'
        //   DataStoreRead: '<S567>/Time'

        APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendI_o[0] =
          APF_Path_Planning_2023a_DW.Univ_Time;
        APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendI_o[1] =
          APF_Path_Planning_2023a_DW.RED_Px;
        APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendI_o[2] =
          APF_Path_Planning_2023a_DW.RED_Py;
        APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendI_o[3] =
          APF_Path_Planning_2023a_DW.RED_Rz;
        APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendI_o[4] =
          APF_Path_Planning_2023a_DW.RED_Vx;
        APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendI_o[5] =
          APF_Path_Planning_2023a_DW.RED_Vy;
        APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendI_o[6] =
          APF_Path_Planning_2023a_DW.RED_RzD;
        APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendI_o[7] =
          APF_Path_Planning_2023a_DW.BLACK_Px;
        APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendI_o[8] =
          APF_Path_Planning_2023a_DW.BLACK_Py;
        APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendI_o[9] =
          APF_Path_Planning_2023a_DW.BLACK_Rz;
        APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendI_o[10] =
          APF_Path_Planning_2023a_DW.BLACK_Vx;
        APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendI_o[11] =
          APF_Path_Planning_2023a_DW.BLACK_Vy;
        APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendI_o[12] =
          APF_Path_Planning_2023a_DW.BLACK_RzD;
        APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendI_o[13] =
          APF_Path_Planning_2023a_DW.BLUE_Px;
        APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendI_o[14] =
          APF_Path_Planning_2023a_DW.BLUE_Py;
        APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendI_o[15] =
          APF_Path_Planning_2023a_DW.BLUE_Rz;
        APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendI_o[16] =
          APF_Path_Planning_2023a_DW.BLUE_Vx;
        APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendI_o[17] =
          APF_Path_Planning_2023a_DW.BLUE_Vy;
        APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendI_o[18] =
          APF_Path_Planning_2023a_DW.BLUE_RzD;

        // Update for S-Function (sdspToNetwork): '<S567>/UDP Send' incorporates:
        //   SignalConversion generated from: '<S567>/UDP Send'
        //
        sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_m
                              [0U]);
        LibUpdate_Network(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_m[0U],
                          &APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendI_o
                          [0U], 19);
        if (*sErr != 0) {
          rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
          rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
        }

        // End of Update for S-Function (sdspToNetwork): '<S567>/UDP Send'
        // End of Outputs for SubSystem: '<S16>/Subsystem'
      }

      // End of If: '<S16>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 

      // If: '<S19>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
      //   DataStoreRead: '<S19>/Data Store Read'
      //   DataStoreRead: '<S19>/Data Store Read1'
      //   If: '<S653>/If'
      //   If: '<S653>/If1'
      //   If: '<S653>/If2'
      //   MATLAB Function: '<S653>/MATLAB Function4'
      //   MATLAB Function: '<S653>/MATLAB Function7'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if ((APF_Path_Planning_2023a_DW.WhoAmI == 1.0) ||
            (APF_Path_Planning_2023a_DW.isSim == 1.0)) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_p =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_p;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S19>/Change RED Behavior' incorporates:
        //   ActionPort: '<S628>/Action Port'

        // MATLAB Function: '<S653>/MATLAB Function3'
        memset(&APF_Path_Planning_2023a_B.y[0], 0, sizeof(real_T) << 6U);

        // MATLAB Function: '<S653>/MATLAB Function' incorporates:
        //   DataStoreRead: '<S653>/Data Store Read'
        //   DataStoreRead: '<S653>/Data Store Read7'
        //   DataStoreRead: '<S653>/Data Store Read8'
        //   MATLAB Function: '<S653>/MATLAB Function4'
        //   MATLAB Function: '<S653>/MATLAB Function6'

        APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp = cos
          (APF_Path_Planning_2023a_DW.RED_Rz_Shoulder + 1.5707963267948966);
        APF_Path_Planning_2023a_B.rtb_y_g = APF_Path_Planning_2023a_P.b0 * cos
          (APF_Path_Planning_2023a_P.Phi);
        APF_Path_Planning_2023a_B.rtb_path_b_idx_1 =
          APF_Path_Planning_2023a_P.a1 *
          APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp +
          APF_Path_Planning_2023a_B.rtb_y_g;
        APF_Path_Planning_2023a_B.rtb_path_o_idx_0 = sin
          (APF_Path_Planning_2023a_DW.RED_Rz_Shoulder + 1.5707963267948966);
        APF_Path_Planning_2023a_B.RED_Tz_RW = APF_Path_Planning_2023a_P.b0 * sin
          (APF_Path_Planning_2023a_P.Phi);
        APF_Path_Planning_2023a_B.q = APF_Path_Planning_2023a_P.a1 *
          APF_Path_Planning_2023a_B.rtb_path_o_idx_0 +
          APF_Path_Planning_2023a_B.RED_Tz_RW;
        APF_Path_Planning_2023a_B.sampleTime_j =
          (APF_Path_Planning_2023a_DW.RED_Rz_Shoulder + 1.5707963267948966) +
          APF_Path_Planning_2023a_DW.RED_Rz_Elbow;
        APF_Path_Planning_2023a_B.Derivative2 = cos
          (APF_Path_Planning_2023a_B.sampleTime_j);
        APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0 =
          (APF_Path_Planning_2023a_P.b1 *
           APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp +
           APF_Path_Planning_2023a_B.rtb_path_b_idx_1) +
          APF_Path_Planning_2023a_P.a2 * APF_Path_Planning_2023a_B.Derivative2;
        APF_Path_Planning_2023a_B.rtb_path_o_idx_2 = sin
          (APF_Path_Planning_2023a_B.sampleTime_j);
        APF_Path_Planning_2023a_B.link2_com_y = (APF_Path_Planning_2023a_P.b1 *
          APF_Path_Planning_2023a_B.rtb_path_o_idx_0 +
          APF_Path_Planning_2023a_B.q) + APF_Path_Planning_2023a_P.a2 *
          APF_Path_Planning_2023a_B.rtb_path_o_idx_2;
        APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 =
          APF_Path_Planning_2023a_B.sampleTime_j +
          APF_Path_Planning_2023a_DW.RED_Rz_Wrist;
        APF_Path_Planning_2023a_B.sampleTime = ((APF_Path_Planning_2023a_P.mRED
          + APF_Path_Planning_2023a_P.mPROX) + APF_Path_Planning_2023a_P.mDIST)
          + APF_Path_Planning_2023a_P.mEE;
        APF_Path_Planning_2023a_B.varargout_1 = cos
          (APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1) *
          APF_Path_Planning_2023a_P.a3;
        APF_Path_Planning_2023a_B.sampleTime_j = (((APF_Path_Planning_2023a_P.b2
          * APF_Path_Planning_2023a_B.Derivative2 +
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0) +
          APF_Path_Planning_2023a_B.varargout_1) * APF_Path_Planning_2023a_P.mEE
          + (APF_Path_Planning_2023a_P.mPROX *
             APF_Path_Planning_2023a_B.rtb_path_b_idx_1 +
             APF_Path_Planning_2023a_P.mDIST *
             APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0)) /
          APF_Path_Planning_2023a_B.sampleTime * 1000.0;
        APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 = sin
          (APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1) *
          APF_Path_Planning_2023a_P.a3;
        APF_Path_Planning_2023a_B.sampleTime_d = (((APF_Path_Planning_2023a_P.b2
          * APF_Path_Planning_2023a_B.rtb_path_o_idx_2 +
          APF_Path_Planning_2023a_B.link2_com_y) +
          APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1) *
          APF_Path_Planning_2023a_P.mEE + (APF_Path_Planning_2023a_P.mPROX *
          APF_Path_Planning_2023a_B.q + APF_Path_Planning_2023a_P.mDIST *
          APF_Path_Planning_2023a_B.link2_com_y)) /
          APF_Path_Planning_2023a_B.sampleTime * 1000.0;
        for (APF_Path_Planning_2023a_B.exponent = 0;
             APF_Path_Planning_2023a_B.exponent < 8;
             APF_Path_Planning_2023a_B.exponent++) {
          // MATLAB Function: '<S653>/MATLAB Function3'
          APF_Path_Planning_2023a_B.q =
            APF_Path_Planning_2023a_P.F_thrusters_RED[APF_Path_Planning_2023a_B.exponent];
          APF_Path_Planning_2023a_B.y[APF_Path_Planning_2023a_B.exponent +
            (APF_Path_Planning_2023a_B.exponent << 3)] =
            APF_Path_Planning_2023a_B.q;

          // MATLAB Function: '<S653>/MATLAB Function'
          APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.exponent]
            = APF_Path_Planning_2023a_B.q / 2.0;
        }

        // MATLAB Function: '<S653>/MATLAB Function'
        memset(&APF_Path_Planning_2023a_B.y_m[0], 0, sizeof(real_T) << 6U);

        // If: '<S653>/If' incorporates:
        //   Constant: '<S653>/Constant'

        APF_Path_Planning_2023a_B.p =
          ((APF_Path_Planning_2023a_P.platformSelection == 4.0) ||
           (APF_Path_Planning_2023a_P.platformSelection == 5.0) ||
           (APF_Path_Planning_2023a_P.platformSelection == 10.0) ||
           (APF_Path_Planning_2023a_P.platformSelection == 11.0));

        // MATLAB Function: '<S653>/MATLAB Function'
        for (APF_Path_Planning_2023a_B.exponent = 0;
             APF_Path_Planning_2023a_B.exponent < 8;
             APF_Path_Planning_2023a_B.exponent++) {
          APF_Path_Planning_2023a_B.y_m[APF_Path_Planning_2023a_B.exponent +
            (APF_Path_Planning_2023a_B.exponent << 3)] =
            APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.exponent];
          APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.exponent] =
            b[APF_Path_Planning_2023a_B.exponent];
          APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.exponent + 1]
            = c[APF_Path_Planning_2023a_B.exponent];
        }

        APF_Path_Planning_2023a_B.b[2] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[0] -
           APF_Path_Planning_2023a_B.sampleTime_d) / 1000.0;
        APF_Path_Planning_2023a_B.b[5] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[1] -
           APF_Path_Planning_2023a_B.sampleTime_d) / 1000.0;
        APF_Path_Planning_2023a_B.b[8] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[2] -
           APF_Path_Planning_2023a_B.sampleTime_j) / 1000.0;
        APF_Path_Planning_2023a_B.b[11] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[3] -
           APF_Path_Planning_2023a_B.sampleTime_j) / 1000.0;
        APF_Path_Planning_2023a_B.b[14] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[4] +
           APF_Path_Planning_2023a_B.sampleTime_d) / 1000.0;
        APF_Path_Planning_2023a_B.b[17] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[5] +
           APF_Path_Planning_2023a_B.sampleTime_d) / 1000.0;
        APF_Path_Planning_2023a_B.b[20] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[6] +
           APF_Path_Planning_2023a_B.sampleTime_j) / 1000.0;
        APF_Path_Planning_2023a_B.b[23] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[7] +
           APF_Path_Planning_2023a_B.sampleTime_j) / 1000.0;
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.q = 0.0;
            for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
                 APF_Path_Planning_2023a_B.ntIdx1 < 8;
                 APF_Path_Planning_2023a_B.ntIdx1++) {
              APF_Path_Planning_2023a_B.q += APF_Path_Planning_2023a_B.b[3 *
                APF_Path_Planning_2023a_B.ntIdx1 +
                APF_Path_Planning_2023a_B.exponent] *
                APF_Path_Planning_2023a_B.y_m[(APF_Path_Planning_2023a_B.r_b <<
                3) + APF_Path_Planning_2023a_B.ntIdx1];
            }

            APF_Path_Planning_2023a_B.b_c[APF_Path_Planning_2023a_B.exponent + 3
              * APF_Path_Planning_2023a_B.r_b] = APF_Path_Planning_2023a_B.q;
          }

          // MATLAB Function: '<S653>/MATLAB Function3'
          APF_Path_Planning_2023a_B.Product2_m[3 * APF_Path_Planning_2023a_B.r_b]
            = b[APF_Path_Planning_2023a_B.r_b];
          APF_Path_Planning_2023a_B.Product2_m[3 * APF_Path_Planning_2023a_B.r_b
            + 1] = c[APF_Path_Planning_2023a_B.r_b];
          APF_Path_Planning_2023a_B.Product2_m[3 * APF_Path_Planning_2023a_B.r_b
            + 2] =
            APF_Path_Planning_2023a_P.thruster_dist2CG_RED[APF_Path_Planning_2023a_B.r_b]
            / 1000.0;
        }

        // MATLAB Function: '<S653>/MATLAB Function3'
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.q = 0.0;
            for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
                 APF_Path_Planning_2023a_B.ntIdx1 < 8;
                 APF_Path_Planning_2023a_B.ntIdx1++) {
              APF_Path_Planning_2023a_B.q +=
                APF_Path_Planning_2023a_B.Product2_m[3 *
                APF_Path_Planning_2023a_B.ntIdx1 +
                APF_Path_Planning_2023a_B.exponent] *
                APF_Path_Planning_2023a_B.y[(APF_Path_Planning_2023a_B.r_b << 3)
                + APF_Path_Planning_2023a_B.ntIdx1];
            }

            APF_Path_Planning_2023a_B.b[APF_Path_Planning_2023a_B.exponent + 3 *
              APF_Path_Planning_2023a_B.r_b] = APF_Path_Planning_2023a_B.q;
          }
        }

        if (APF_Path_Planning_2023a_B.p) {
          // Outputs for IfAction SubSystem: '<S653>/If Action Subsystem' incorporates:
          //   ActionPort: '<S655>/Action Port'

          // Outputs for IfAction SubSystem: '<S653>/If Action Subsystem1' incorporates:
          //   ActionPort: '<S656>/Action Port'

          // SignalConversion generated from: '<S655>/In1' incorporates:
          //   MATLAB Function: '<S653>/MATLAB Function'
          //   Product: '<S671>/Product2'
          //   SignalConversion generated from: '<S656>/In1'

          memcpy(&APF_Path_Planning_2023a_B.Product2_m[0],
                 &APF_Path_Planning_2023a_B.b_c[0], 24U * sizeof(real_T));

          // End of Outputs for SubSystem: '<S653>/If Action Subsystem1'
          // End of Outputs for SubSystem: '<S653>/If Action Subsystem'
        } else {
          // Outputs for IfAction SubSystem: '<S653>/If Action Subsystem1' incorporates:
          //   ActionPort: '<S656>/Action Port'

          // Outputs for IfAction SubSystem: '<S653>/If Action Subsystem' incorporates:
          //   ActionPort: '<S655>/Action Port'

          // SignalConversion generated from: '<S656>/In1' incorporates:
          //   MATLAB Function: '<S653>/MATLAB Function'
          //   MATLAB Function: '<S653>/MATLAB Function3'
          //   Product: '<S671>/Product2'
          //   SignalConversion generated from: '<S655>/In1'

          memcpy(&APF_Path_Planning_2023a_B.Product2_m[0],
                 &APF_Path_Planning_2023a_B.b[0], 24U * sizeof(real_T));

          // End of Outputs for SubSystem: '<S653>/If Action Subsystem'
          // End of Outputs for SubSystem: '<S653>/If Action Subsystem1'
        }

        // PermuteDimensions: '<S670>/transpose' incorporates:
        //   If: '<S653>/If'
        //   Merge: '<S653>/Merge1'
        //   Product: '<S671>/Product2'

        APF_Path_Planning_2023a_B.yElIdx = 0;
        APF_Path_Planning_2023a_B.uElOffset1 = 0;
        for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
             APF_Path_Planning_2023a_B.ntIdx1 < 3;
             APF_Path_Planning_2023a_B.ntIdx1++) {
          APF_Path_Planning_2023a_B.StartClock =
            APF_Path_Planning_2023a_B.uElOffset1;
          for (APF_Path_Planning_2023a_B.ntIdx0 = 0;
               APF_Path_Planning_2023a_B.ntIdx0 < 8;
               APF_Path_Planning_2023a_B.ntIdx0++) {
            APF_Path_Planning_2023a_B.Merge1_d[APF_Path_Planning_2023a_B.yElIdx]
              =
              APF_Path_Planning_2023a_B.Product2_m[APF_Path_Planning_2023a_B.StartClock];
            APF_Path_Planning_2023a_B.yElIdx++;
            APF_Path_Planning_2023a_B.StartClock += 3;
          }

          APF_Path_Planning_2023a_B.uElOffset1++;
        }

        // End of PermuteDimensions: '<S670>/transpose'

        // MATLAB Function: '<S654>/Create Rotation Matrix' incorporates:
        //   DataStoreRead: '<S628>/RED_Rz'
        //   Product: '<S653>/Product2'

        APF_Path_CreateRotationMatrix_g(APF_Path_Planning_2023a_DW.RED_Rz,
          &APF_Path_Planning_2023a_B.Product2_b[0]);

        // Product: '<S654>/Rotate F_I to F_b' incorporates:
        //   DataStoreRead: '<S628>/RED_Fx'
        //   DataStoreRead: '<S628>/RED_Fy'
        //   SignalConversion generated from: '<S654>/Rotate F_I to F_b'

        APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_B.Product2_b[0] *
          APF_Path_Planning_2023a_DW.RED_Fx +
          APF_Path_Planning_2023a_B.Product2_b[2] *
          APF_Path_Planning_2023a_DW.RED_Fy;

        // SignalConversion generated from: '<S653>/Product'
        APF_Path_Planning_2023a_B.x_ddot_d[0] = APF_Path_Planning_2023a_B.t;

        // Product: '<S654>/Rotate F_I to F_b' incorporates:
        //   DataStoreRead: '<S628>/RED_Fx'
        //   DataStoreRead: '<S628>/RED_Fy'
        //   SignalConversion generated from: '<S654>/Rotate F_I to F_b'

        APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
          APF_Path_Planning_2023a_B.Product2_b[1] *
          APF_Path_Planning_2023a_DW.RED_Fx +
          APF_Path_Planning_2023a_B.Product2_b[3] *
          APF_Path_Planning_2023a_DW.RED_Fy;

        // SignalConversion generated from: '<S653>/Product' incorporates:
        //   DataStoreRead: '<S628>/RED_Tz'

        APF_Path_Planning_2023a_B.x_ddot_d[1] =
          APF_Path_Planning_2023a_B.rtb_path_b_idx_0;
        APF_Path_Planning_2023a_B.x_ddot_d[2] =
          APF_Path_Planning_2023a_DW.RED_Tz;

        // Product: '<S670>/Product' incorporates:
        //   Merge: '<S653>/Merge1'
        //   Product: '<S671>/Product2'

        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             3; APF_Path_Planning_2023a_B.r_b++) {
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.q = 0.0;
            for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
                 APF_Path_Planning_2023a_B.ntIdx1 < 8;
                 APF_Path_Planning_2023a_B.ntIdx1++) {
              APF_Path_Planning_2023a_B.q +=
                APF_Path_Planning_2023a_B.Product2_m[3 *
                APF_Path_Planning_2023a_B.ntIdx1 +
                APF_Path_Planning_2023a_B.exponent] *
                APF_Path_Planning_2023a_B.Merge1_d
                [(APF_Path_Planning_2023a_B.r_b << 3) +
                APF_Path_Planning_2023a_B.ntIdx1];
            }

            APF_Path_Planning_2023a_B.rtb_Product2_m_b[APF_Path_Planning_2023a_B.exponent
              + 3 * APF_Path_Planning_2023a_B.r_b] = APF_Path_Planning_2023a_B.q;
          }
        }

        // Product: '<S670>/Product1' incorporates:
        //   Product: '<S670>/Product'

        APF_Path_Plannin_rt_invd3x3_snf
          (APF_Path_Planning_2023a_B.rtb_Product2_m_b,
           APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp);
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          // Product: '<S653>/Product'
          APF_Path_Planning_2023a_B.sampleTime_d = 0.0;

          // Product: '<S670>/Product2' incorporates:
          //   Merge: '<S653>/Merge1'

          APF_Path_Planning_2023a_B.sampleTime_j =
            APF_Path_Planning_2023a_B.Merge1_d[APF_Path_Planning_2023a_B.r_b + 8];
          APF_Path_Planning_2023a_B.q =
            APF_Path_Planning_2023a_B.Merge1_d[APF_Path_Planning_2023a_B.r_b];
          APF_Path_Planning_2023a_B.rtb_path_b_idx_1 =
            APF_Path_Planning_2023a_B.Merge1_d[APF_Path_Planning_2023a_B.r_b +
            16];
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            // Product: '<S653>/Product'
            APF_Path_Planning_2023a_B.sampleTime_d +=
              ((APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp[3 *
                APF_Path_Planning_2023a_B.exponent + 1] *
                APF_Path_Planning_2023a_B.sampleTime_j +
                APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp[3 *
                APF_Path_Planning_2023a_B.exponent] *
                APF_Path_Planning_2023a_B.q) +
               APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp[3 *
               APF_Path_Planning_2023a_B.exponent + 2] *
               APF_Path_Planning_2023a_B.rtb_path_b_idx_1) *
              APF_Path_Planning_2023a_B.x_ddot_d[APF_Path_Planning_2023a_B.exponent];
          }

          // End of Product: '<S670>/Product2'

          // Product: '<S653>/Product'
          APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.r_b]
            = APF_Path_Planning_2023a_B.sampleTime_d;
        }

        // DataStoreWrite: '<S653>/Data Store Write1' incorporates:
        //   MATLAB Function: '<S653>/MATLAB Function5'

        APF_Path_Plann_MATLABFunction10(APF_Path_Planning_2023a_B.rtb_Product_f,
          &APF_Path_Planning_2023a_B.sampleTime_j,
          &APF_Path_Planning_2023a_DW.RED_Thruster_ON_Count,
          &APF_Path_Planning_2023a_B.sf_MATLABFunction5);

        // MATLAB Function: '<S669>/Create Rotation Matrix' incorporates:
        //   DataStoreRead: '<S653>/RED_Rz'

        APF_Path_P_CreateRotationMatrix(APF_Path_Planning_2023a_DW.RED_Rz,
          APF_Path_Planning_2023a_B.rtb_C_Ib_g);

        // MATLAB Function: '<S653>/MATLAB Function7' incorporates:
        //   MATLAB Function: '<S653>/MATLAB Function11'
        //   MATLAB Function: '<S653>/MATLAB Function4'

        APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 =
          APF_Path_Planning_2023a_P.F_red_X_nominal *
          APF_Path_Planning_2023a_B.sampleTime_j;
        APF_Path_Planning_2023a_B.rtb_Product_f[0] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_Product_f[1] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1 =
          APF_Path_Planning_2023a_P.F_red_Y_nominal *
          APF_Path_Planning_2023a_B.sampleTime_j;
        APF_Path_Planning_2023a_B.rtb_Product_f[2] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        APF_Path_Planning_2023a_B.rtb_Product_f[3] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        APF_Path_Planning_2023a_B.rtb_Product_f[4] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_Product_f[5] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_Product_f[6] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        APF_Path_Planning_2023a_B.rtb_Product_f[7] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        memset(&APF_Path_Planning_2023a_B.y[0], 0, sizeof(real_T) << 6U);
        for (APF_Path_Planning_2023a_B.exponent = 0;
             APF_Path_Planning_2023a_B.exponent < 8;
             APF_Path_Planning_2023a_B.exponent++) {
          APF_Path_Planning_2023a_B.y[APF_Path_Planning_2023a_B.exponent +
            (APF_Path_Planning_2023a_B.exponent << 3)] =
            APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.exponent];
        }

        // MATLAB Function: '<S653>/MATLAB Function4'
        APF_Path_Planning_2023a_B.rtb_path_b_idx_1 =
          APF_Path_Planning_2023a_P.a1 *
          APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp +
          APF_Path_Planning_2023a_B.rtb_y_g;
        APF_Path_Planning_2023a_B.q = APF_Path_Planning_2023a_P.a1 *
          APF_Path_Planning_2023a_B.rtb_path_o_idx_0 +
          APF_Path_Planning_2023a_B.RED_Tz_RW;
        APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0 =
          (APF_Path_Planning_2023a_P.b1 *
           APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp +
           APF_Path_Planning_2023a_B.rtb_path_b_idx_1) +
          APF_Path_Planning_2023a_P.a2 * APF_Path_Planning_2023a_B.Derivative2;
        APF_Path_Planning_2023a_B.link2_com_y = (APF_Path_Planning_2023a_P.b1 *
          APF_Path_Planning_2023a_B.rtb_path_o_idx_0 +
          APF_Path_Planning_2023a_B.q) + APF_Path_Planning_2023a_P.a2 *
          APF_Path_Planning_2023a_B.rtb_path_o_idx_2;
        APF_Path_Planning_2023a_B.sampleTime_j = (((APF_Path_Planning_2023a_P.b2
          * APF_Path_Planning_2023a_B.Derivative2 +
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0) +
          APF_Path_Planning_2023a_B.varargout_1) * APF_Path_Planning_2023a_P.mEE
          + (APF_Path_Planning_2023a_P.mPROX *
             APF_Path_Planning_2023a_B.rtb_path_b_idx_1 +
             APF_Path_Planning_2023a_P.mDIST *
             APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0)) /
          APF_Path_Planning_2023a_B.sampleTime * 1000.0;
        APF_Path_Planning_2023a_B.sampleTime_d = (((APF_Path_Planning_2023a_P.b2
          * APF_Path_Planning_2023a_B.rtb_path_o_idx_2 +
          APF_Path_Planning_2023a_B.link2_com_y) +
          APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1) *
          APF_Path_Planning_2023a_P.mEE + (APF_Path_Planning_2023a_P.mPROX *
          APF_Path_Planning_2023a_B.q + APF_Path_Planning_2023a_P.mDIST *
          APF_Path_Planning_2023a_B.link2_com_y)) /
          APF_Path_Planning_2023a_B.sampleTime * 1000.0;
        memset(&APF_Path_Planning_2023a_B.y_m[0], 0, sizeof(real_T) << 6U);
        for (APF_Path_Planning_2023a_B.exponent = 0;
             APF_Path_Planning_2023a_B.exponent < 8;
             APF_Path_Planning_2023a_B.exponent++) {
          APF_Path_Planning_2023a_B.y_m[APF_Path_Planning_2023a_B.exponent +
            (APF_Path_Planning_2023a_B.exponent << 3)] =
            APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.exponent];
        }

        // MATLAB Function: '<S653>/MATLAB Function11' incorporates:
        //   MATLAB Function: '<S653>/MATLAB Function6'

        APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 /= 2.0;
        APF_Path_Planning_2023a_B.rtb_Product_f[0] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_Product_f[1] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1 /= 2.0;
        APF_Path_Planning_2023a_B.rtb_Product_f[2] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        APF_Path_Planning_2023a_B.rtb_Product_f[3] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        APF_Path_Planning_2023a_B.rtb_Product_f[4] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_Product_f[5] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_Product_f[6] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        APF_Path_Planning_2023a_B.rtb_Product_f[7] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        memset(&APF_Path_Planning_2023a_B.y_c[0], 0, sizeof(real_T) << 6U);
        for (APF_Path_Planning_2023a_B.exponent = 0;
             APF_Path_Planning_2023a_B.exponent < 8;
             APF_Path_Planning_2023a_B.exponent++) {
          APF_Path_Planning_2023a_B.y_c[APF_Path_Planning_2023a_B.exponent +
            (APF_Path_Planning_2023a_B.exponent << 3)] =
            APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.exponent];
        }

        // MATLAB Function: '<S653>/MATLAB Function6' incorporates:
        //   DataStoreRead: '<S653>/Data Store Read1'
        //   DataStoreRead: '<S653>/Data Store Read2'
        //   DataStoreRead: '<S653>/Data Store Read3'

        APF_Path_Planning_2023a_B.Derivative2 = cos
          (APF_Path_Planning_2023a_DW.RED_Rz_Shoulder + 1.5707963267948966);
        APF_Path_Planning_2023a_B.rtb_path_b_idx_1 =
          APF_Path_Planning_2023a_B.Derivative2 * APF_Path_Planning_2023a_P.a1 +
          APF_Path_Planning_2023a_B.rtb_y_g;
        APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp = sin
          (APF_Path_Planning_2023a_DW.RED_Rz_Shoulder + 1.5707963267948966);
        APF_Path_Planning_2023a_B.q =
          APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp *
          APF_Path_Planning_2023a_P.a1 + APF_Path_Planning_2023a_B.RED_Tz_RW;
        APF_Path_Planning_2023a_B.rtb_path_o_idx_0 =
          (APF_Path_Planning_2023a_DW.RED_Rz_Shoulder + 1.5707963267948966) +
          APF_Path_Planning_2023a_DW.RED_Rz_Elbow;
        APF_Path_Planning_2023a_B.RED_Tz_RW = cos
          (APF_Path_Planning_2023a_B.rtb_path_o_idx_0);
        APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0 =
          (APF_Path_Planning_2023a_B.Derivative2 * APF_Path_Planning_2023a_P.b1
           + APF_Path_Planning_2023a_B.rtb_path_b_idx_1) +
          APF_Path_Planning_2023a_B.RED_Tz_RW * APF_Path_Planning_2023a_P.a2;
        APF_Path_Planning_2023a_B.rtb_y_g = sin
          (APF_Path_Planning_2023a_B.rtb_path_o_idx_0);
        APF_Path_Planning_2023a_B.link2_com_y =
          (APF_Path_Planning_2023a_B.alpha_pol_tmp_tmp_tmp *
           APF_Path_Planning_2023a_P.b1 + APF_Path_Planning_2023a_B.q) +
          APF_Path_Planning_2023a_B.rtb_y_g * APF_Path_Planning_2023a_P.a2;
        APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1 =
          APF_Path_Planning_2023a_B.rtb_path_o_idx_0 +
          APF_Path_Planning_2023a_DW.RED_Rz_Wrist;
        APF_Path_Planning_2023a_B.RED_Tz_RW =
          (((APF_Path_Planning_2023a_B.RED_Tz_RW * APF_Path_Planning_2023a_P.b2
             + APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0) + cos
            (APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1) *
            APF_Path_Planning_2023a_P.a3) * APF_Path_Planning_2023a_P.mEE +
           (APF_Path_Planning_2023a_P.mPROX *
            APF_Path_Planning_2023a_B.rtb_path_b_idx_1 +
            APF_Path_Planning_2023a_P.mDIST *
            APF_Path_Planning_2023a_B.rtb_x_ddot_idx_0)) /
          APF_Path_Planning_2023a_B.sampleTime * 1000.0;
        APF_Path_Planning_2023a_B.sampleTime =
          (((APF_Path_Planning_2023a_B.rtb_y_g * APF_Path_Planning_2023a_P.b2 +
             APF_Path_Planning_2023a_B.link2_com_y) + sin
            (APF_Path_Planning_2023a_B.rtb_x_ddot_o_idx_1) *
            APF_Path_Planning_2023a_P.a3) * APF_Path_Planning_2023a_P.mEE +
           (APF_Path_Planning_2023a_P.mPROX * APF_Path_Planning_2023a_B.q +
            APF_Path_Planning_2023a_P.mDIST *
            APF_Path_Planning_2023a_B.link2_com_y)) /
          APF_Path_Planning_2023a_B.sampleTime * 1000.0;
        memset(&APF_Path_Planning_2023a_B.y_k[0], 0, sizeof(real_T) << 6U);

        // If: '<S653>/If2' incorporates:
        //   Constant: '<S653>/Constant2'

        APF_Path_Planning_2023a_B.p =
          ((APF_Path_Planning_2023a_P.platformSelection == 4.0) ||
           (APF_Path_Planning_2023a_P.platformSelection == 5.0) ||
           (APF_Path_Planning_2023a_P.platformSelection == 10.0) ||
           (APF_Path_Planning_2023a_P.platformSelection == 11.0));

        // MATLAB Function: '<S653>/MATLAB Function6'
        for (APF_Path_Planning_2023a_B.exponent = 0;
             APF_Path_Planning_2023a_B.exponent < 8;
             APF_Path_Planning_2023a_B.exponent++) {
          APF_Path_Planning_2023a_B.y_k[APF_Path_Planning_2023a_B.exponent +
            (APF_Path_Planning_2023a_B.exponent << 3)] =
            APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.exponent];
          APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.exponent] =
            b[APF_Path_Planning_2023a_B.exponent];
          APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.exponent + 1]
            = c[APF_Path_Planning_2023a_B.exponent];
        }

        APF_Path_Planning_2023a_B.b[2] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[0] -
           APF_Path_Planning_2023a_B.sampleTime) / 1000.0;
        APF_Path_Planning_2023a_B.b[5] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[1] -
           APF_Path_Planning_2023a_B.sampleTime) / 1000.0;
        APF_Path_Planning_2023a_B.b[8] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[2] -
           APF_Path_Planning_2023a_B.RED_Tz_RW) / 1000.0;
        APF_Path_Planning_2023a_B.b[11] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[3] -
           APF_Path_Planning_2023a_B.RED_Tz_RW) / 1000.0;
        APF_Path_Planning_2023a_B.b[14] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[4] +
           APF_Path_Planning_2023a_B.sampleTime) / 1000.0;
        APF_Path_Planning_2023a_B.b[17] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[5] +
           APF_Path_Planning_2023a_B.sampleTime) / 1000.0;
        APF_Path_Planning_2023a_B.b[20] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[6] +
           APF_Path_Planning_2023a_B.RED_Tz_RW) / 1000.0;
        APF_Path_Planning_2023a_B.b[23] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[7] +
           APF_Path_Planning_2023a_B.RED_Tz_RW) / 1000.0;
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.q = 0.0;
            for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
                 APF_Path_Planning_2023a_B.ntIdx1 < 8;
                 APF_Path_Planning_2023a_B.ntIdx1++) {
              APF_Path_Planning_2023a_B.q += APF_Path_Planning_2023a_B.b[3 *
                APF_Path_Planning_2023a_B.ntIdx1 +
                APF_Path_Planning_2023a_B.exponent] *
                APF_Path_Planning_2023a_B.y_k[(APF_Path_Planning_2023a_B.r_b <<
                3) + APF_Path_Planning_2023a_B.ntIdx1];
            }

            APF_Path_Planning_2023a_B.b_c[APF_Path_Planning_2023a_B.exponent + 3
              * APF_Path_Planning_2023a_B.r_b] = APF_Path_Planning_2023a_B.q;
          }

          // MATLAB Function: '<S653>/MATLAB Function11'
          APF_Path_Planning_2023a_B.Product2_m[3 * APF_Path_Planning_2023a_B.r_b]
            = b[APF_Path_Planning_2023a_B.r_b];
          APF_Path_Planning_2023a_B.Product2_m[3 * APF_Path_Planning_2023a_B.r_b
            + 1] = c[APF_Path_Planning_2023a_B.r_b];
        }

        // MATLAB Function: '<S653>/MATLAB Function11'
        APF_Path_Planning_2023a_B.Product2_m[2] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_RED[0] / 1000.0;
        APF_Path_Planning_2023a_B.Product2_m[5] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_RED[1] / 1000.0;
        APF_Path_Planning_2023a_B.Product2_m[8] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_RED[2] / 1000.0;
        APF_Path_Planning_2023a_B.Product2_m[11] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_RED[3] / 1000.0;
        APF_Path_Planning_2023a_B.Product2_m[14] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_RED[4] / 1000.0;
        APF_Path_Planning_2023a_B.Product2_m[17] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_RED[5] / 1000.0;
        APF_Path_Planning_2023a_B.Product2_m[20] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_RED[6] / 1000.0;
        APF_Path_Planning_2023a_B.Product2_m[23] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_RED[7] / 1000.0;
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.q = 0.0;
            for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
                 APF_Path_Planning_2023a_B.ntIdx1 < 8;
                 APF_Path_Planning_2023a_B.ntIdx1++) {
              APF_Path_Planning_2023a_B.q +=
                APF_Path_Planning_2023a_B.Product2_m[3 *
                APF_Path_Planning_2023a_B.ntIdx1 +
                APF_Path_Planning_2023a_B.exponent] *
                APF_Path_Planning_2023a_B.y_c[(APF_Path_Planning_2023a_B.r_b <<
                3) + APF_Path_Planning_2023a_B.ntIdx1];
            }

            APF_Path_Planning_2023a_B.b[APF_Path_Planning_2023a_B.exponent + 3 *
              APF_Path_Planning_2023a_B.r_b] = APF_Path_Planning_2023a_B.q;
          }
        }

        if (APF_Path_Planning_2023a_B.p) {
          // Outputs for IfAction SubSystem: '<S653>/If Action Subsystem4' incorporates:
          //   ActionPort: '<S659>/Action Port'

          // Outputs for IfAction SubSystem: '<S653>/If Action Subsystem5' incorporates:
          //   ActionPort: '<S660>/Action Port'

          // SignalConversion generated from: '<S659>/H' incorporates:
          //   MATLAB Function: '<S653>/MATLAB Function6'
          //   Product: '<S671>/Product2'
          //   SignalConversion generated from: '<S660>/In1'

          memcpy(&APF_Path_Planning_2023a_B.Product2_m[0],
                 &APF_Path_Planning_2023a_B.b_c[0], 24U * sizeof(real_T));

          // End of Outputs for SubSystem: '<S653>/If Action Subsystem5'
          // End of Outputs for SubSystem: '<S653>/If Action Subsystem4'
        } else {
          // Outputs for IfAction SubSystem: '<S653>/If Action Subsystem5' incorporates:
          //   ActionPort: '<S660>/Action Port'

          // Outputs for IfAction SubSystem: '<S653>/If Action Subsystem4' incorporates:
          //   ActionPort: '<S659>/Action Port'

          // SignalConversion generated from: '<S660>/In1' incorporates:
          //   MATLAB Function: '<S653>/MATLAB Function11'
          //   MATLAB Function: '<S653>/MATLAB Function6'
          //   Product: '<S671>/Product2'
          //   SignalConversion generated from: '<S659>/H'

          memcpy(&APF_Path_Planning_2023a_B.Product2_m[0],
                 &APF_Path_Planning_2023a_B.b[0], 24U * sizeof(real_T));

          // End of Outputs for SubSystem: '<S653>/If Action Subsystem4'
          // End of Outputs for SubSystem: '<S653>/If Action Subsystem5'
        }

        // PermuteDimensions: '<S671>/transpose' incorporates:
        //   If: '<S653>/If2'
        //   Product: '<S671>/Product2'

        APF_Path_Planning_2023a_B.yElIdx = 0;
        APF_Path_Planning_2023a_B.uElOffset1 = 0;
        for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
             APF_Path_Planning_2023a_B.ntIdx1 < 3;
             APF_Path_Planning_2023a_B.ntIdx1++) {
          APF_Path_Planning_2023a_B.StartClock =
            APF_Path_Planning_2023a_B.uElOffset1;
          for (APF_Path_Planning_2023a_B.ntIdx0 = 0;
               APF_Path_Planning_2023a_B.ntIdx0 < 8;
               APF_Path_Planning_2023a_B.ntIdx0++) {
            APF_Path_Planning_2023a_B.transpose[APF_Path_Planning_2023a_B.yElIdx]
              =
              APF_Path_Planning_2023a_B.Product2_m[APF_Path_Planning_2023a_B.StartClock];
            APF_Path_Planning_2023a_B.yElIdx++;
            APF_Path_Planning_2023a_B.StartClock += 3;
          }

          APF_Path_Planning_2023a_B.uElOffset1++;
        }

        // End of PermuteDimensions: '<S671>/transpose'
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             3; APF_Path_Planning_2023a_B.r_b++) {
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            // Product: '<S671>/Product' incorporates:
            //   Product: '<S653>/Product2'

            APF_Path_Planning_2023a_B.sampleTime = 0.0;
            for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
                 APF_Path_Planning_2023a_B.ntIdx1 < 8;
                 APF_Path_Planning_2023a_B.ntIdx1++) {
              // Product: '<S653>/Product2' incorporates:
              //   PermuteDimensions: '<S671>/transpose'
              //   Product: '<S671>/Product'
              //   Product: '<S671>/Product2'

              APF_Path_Planning_2023a_B.sampleTime +=
                APF_Path_Planning_2023a_B.Product2_m[3 *
                APF_Path_Planning_2023a_B.ntIdx1 +
                APF_Path_Planning_2023a_B.exponent] *
                APF_Path_Planning_2023a_B.transpose
                [(APF_Path_Planning_2023a_B.r_b << 3) +
                APF_Path_Planning_2023a_B.ntIdx1];
            }

            // Product: '<S671>/Product' incorporates:
            //   Product: '<S653>/Product2'

            APF_Path_Planning_2023a_B.Product2_b[APF_Path_Planning_2023a_B.exponent
              + 3 * APF_Path_Planning_2023a_B.r_b] =
              APF_Path_Planning_2023a_B.sampleTime;
          }
        }

        // Product: '<S671>/Product1' incorporates:
        //   Product: '<S653>/Product2'

        memcpy(&APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp[0],
               &APF_Path_Planning_2023a_B.Product2_b[0], 9U * sizeof(real_T));
        APF_Path_Plannin_rt_invd3x3_snf
          (APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp,
           APF_Path_Planning_2023a_B.Product2_b);

        // Product: '<S671>/Product2' incorporates:
        //   PermuteDimensions: '<S671>/transpose'
        //   Product: '<S653>/Product2'

        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          APF_Path_Planning_2023a_B.sampleTime =
            APF_Path_Planning_2023a_B.transpose[APF_Path_Planning_2023a_B.r_b +
            8];
          APF_Path_Planning_2023a_B.RED_Tz_RW =
            APF_Path_Planning_2023a_B.transpose[APF_Path_Planning_2023a_B.r_b];
          APF_Path_Planning_2023a_B.rtb_y_g =
            APF_Path_Planning_2023a_B.transpose[APF_Path_Planning_2023a_B.r_b +
            16];
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.Product2_m[APF_Path_Planning_2023a_B.r_b +
              (APF_Path_Planning_2023a_B.exponent << 3)] =
              (APF_Path_Planning_2023a_B.Product2_b[3 *
               APF_Path_Planning_2023a_B.exponent + 1] *
               APF_Path_Planning_2023a_B.sampleTime +
               APF_Path_Planning_2023a_B.Product2_b[3 *
               APF_Path_Planning_2023a_B.exponent] *
               APF_Path_Planning_2023a_B.RED_Tz_RW) +
              APF_Path_Planning_2023a_B.Product2_b[3 *
              APF_Path_Planning_2023a_B.exponent + 2] *
              APF_Path_Planning_2023a_B.rtb_y_g;
          }
        }

        // End of Product: '<S671>/Product2'
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          // Product: '<S653>/Product2' incorporates:
          //   DataStoreRead: '<S628>/RED_Tz'
          //   Product: '<S654>/Rotate F_I to F_b'
          //   Product: '<S671>/Product2'
          //   SignalConversion generated from: '<S653>/Product'

          APF_Path_Planning_2023a_B.RED_Tz_RW =
            (APF_Path_Planning_2023a_B.Product2_m[APF_Path_Planning_2023a_B.r_b
             + 8] * APF_Path_Planning_2023a_B.rtb_path_b_idx_0 +
             APF_Path_Planning_2023a_B.Product2_m[APF_Path_Planning_2023a_B.r_b]
             * APF_Path_Planning_2023a_B.t) +
            APF_Path_Planning_2023a_B.Product2_m[APF_Path_Planning_2023a_B.r_b +
            16] * APF_Path_Planning_2023a_DW.RED_Tz;

          // Product: '<S653>/Product2'
          APF_Path_Planning_2023a_B.Product2_b[APF_Path_Planning_2023a_B.r_b] =
            APF_Path_Planning_2023a_B.RED_Tz_RW;

          // Saturate: '<S653>/Remove Negatives' incorporates:
          //   Product: '<S653>/Product2'

          if (APF_Path_Planning_2023a_B.RED_Tz_RW >
              APF_Path_Planning_2023a_P.RemoveNegatives_UpperSat_k) {
            // Saturate: '<S653>/Remove Negatives'
            APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.r_b]
              = APF_Path_Planning_2023a_P.RemoveNegatives_UpperSat_k;
          } else if (APF_Path_Planning_2023a_B.RED_Tz_RW <
                     APF_Path_Planning_2023a_P.RemoveNegatives_LowerSat_k) {
            // Saturate: '<S653>/Remove Negatives'
            APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.r_b]
              = APF_Path_Planning_2023a_P.RemoveNegatives_LowerSat_k;
          } else {
            // Saturate: '<S653>/Remove Negatives'
            APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.r_b]
              = APF_Path_Planning_2023a_B.RED_Tz_RW;
          }

          // End of Saturate: '<S653>/Remove Negatives'
        }

        // MATLAB Function: '<S653>/MATLAB Function2'
        APF_Path_Plan_MATLABFunction1_l(APF_Path_Planning_2023a_B.rtb_Product_f,
          APF_Path_Planning_2023a_B.ThrustPer_Final);

        // If: '<S653>/If1' incorporates:
        //   Constant: '<S653>/Constant1'

        APF_Path_Planning_2023a_B.p =
          ((APF_Path_Planning_2023a_P.platformSelection == 4.0) ||
           (APF_Path_Planning_2023a_P.platformSelection == 5.0) ||
           (APF_Path_Planning_2023a_P.platformSelection == 10.0) ||
           (APF_Path_Planning_2023a_P.platformSelection == 11.0));

        // MATLAB Function: '<S653>/MATLAB Function4'
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.r_b] =
            b[APF_Path_Planning_2023a_B.r_b];
          APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.r_b + 1] =
            c[APF_Path_Planning_2023a_B.r_b];
        }

        APF_Path_Planning_2023a_B.b[2] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[0] -
           APF_Path_Planning_2023a_B.sampleTime_d) / 1000.0;
        APF_Path_Planning_2023a_B.b[5] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[1] -
           APF_Path_Planning_2023a_B.sampleTime_d) / 1000.0;
        APF_Path_Planning_2023a_B.b[8] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[2] -
           APF_Path_Planning_2023a_B.sampleTime_j) / 1000.0;
        APF_Path_Planning_2023a_B.b[11] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[3] -
           APF_Path_Planning_2023a_B.sampleTime_j) / 1000.0;
        APF_Path_Planning_2023a_B.b[14] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[4] +
           APF_Path_Planning_2023a_B.sampleTime_d) / 1000.0;
        APF_Path_Planning_2023a_B.b[17] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[5] +
           APF_Path_Planning_2023a_B.sampleTime_d) / 1000.0;
        APF_Path_Planning_2023a_B.b[20] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[6] +
           APF_Path_Planning_2023a_B.sampleTime_j) / 1000.0;
        APF_Path_Planning_2023a_B.b[23] =
          (APF_Path_Planning_2023a_P.thruster_dist2CG_RED[7] +
           APF_Path_Planning_2023a_B.sampleTime_j) / 1000.0;
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.q = 0.0;
            for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
                 APF_Path_Planning_2023a_B.ntIdx1 < 8;
                 APF_Path_Planning_2023a_B.ntIdx1++) {
              APF_Path_Planning_2023a_B.q += APF_Path_Planning_2023a_B.b[3 *
                APF_Path_Planning_2023a_B.ntIdx1 +
                APF_Path_Planning_2023a_B.exponent] *
                APF_Path_Planning_2023a_B.y_m[(APF_Path_Planning_2023a_B.r_b <<
                3) + APF_Path_Planning_2023a_B.ntIdx1];
            }

            APF_Path_Planning_2023a_B.b_c[APF_Path_Planning_2023a_B.exponent + 3
              * APF_Path_Planning_2023a_B.r_b] = APF_Path_Planning_2023a_B.q;
          }

          // MATLAB Function: '<S653>/MATLAB Function7'
          APF_Path_Planning_2023a_B.Product2_m[3 * APF_Path_Planning_2023a_B.r_b]
            = b[APF_Path_Planning_2023a_B.r_b];
          APF_Path_Planning_2023a_B.Product2_m[3 * APF_Path_Planning_2023a_B.r_b
            + 1] = c[APF_Path_Planning_2023a_B.r_b];
        }

        // MATLAB Function: '<S653>/MATLAB Function7'
        APF_Path_Planning_2023a_B.Product2_m[2] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_RED[0] / 1000.0;
        APF_Path_Planning_2023a_B.Product2_m[5] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_RED[1] / 1000.0;
        APF_Path_Planning_2023a_B.Product2_m[8] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_RED[2] / 1000.0;
        APF_Path_Planning_2023a_B.Product2_m[11] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_RED[3] / 1000.0;
        APF_Path_Planning_2023a_B.Product2_m[14] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_RED[4] / 1000.0;
        APF_Path_Planning_2023a_B.Product2_m[17] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_RED[5] / 1000.0;
        APF_Path_Planning_2023a_B.Product2_m[20] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_RED[6] / 1000.0;
        APF_Path_Planning_2023a_B.Product2_m[23] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_RED[7] / 1000.0;
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.q = 0.0;
            for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
                 APF_Path_Planning_2023a_B.ntIdx1 < 8;
                 APF_Path_Planning_2023a_B.ntIdx1++) {
              APF_Path_Planning_2023a_B.q +=
                APF_Path_Planning_2023a_B.Product2_m[3 *
                APF_Path_Planning_2023a_B.ntIdx1 +
                APF_Path_Planning_2023a_B.exponent] *
                APF_Path_Planning_2023a_B.y[(APF_Path_Planning_2023a_B.r_b << 3)
                + APF_Path_Planning_2023a_B.ntIdx1];
            }

            APF_Path_Planning_2023a_B.b[APF_Path_Planning_2023a_B.exponent + 3 *
              APF_Path_Planning_2023a_B.r_b] = APF_Path_Planning_2023a_B.q;
          }
        }

        if (APF_Path_Planning_2023a_B.p) {
          memcpy(&APF_Path_Planning_2023a_B.Merge1_d[0],
                 &APF_Path_Planning_2023a_B.b_c[0], 24U * sizeof(real_T));
        } else {
          memcpy(&APF_Path_Planning_2023a_B.Merge1_d[0],
                 &APF_Path_Planning_2023a_B.b[0], 24U * sizeof(real_T));
        }

        // Product: '<S653>/Product1' incorporates:
        //   If: '<S653>/If1'
        //   MATLAB Function: '<S653>/MATLAB Function4'
        //   MATLAB Function: '<S653>/MATLAB Function7'

        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             3; APF_Path_Planning_2023a_B.r_b++) {
          APF_Path_Planning_2023a_B.rtb_y_g = 0.0;
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 8;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.rtb_y_g +=
              APF_Path_Planning_2023a_B.Merge1_d[3 *
              APF_Path_Planning_2023a_B.exponent + APF_Path_Planning_2023a_B.r_b]
              * APF_Path_Planning_2023a_B.ThrustPer_Final[APF_Path_Planning_2023a_B.exponent];
          }

          APF_Path_Planning_2023a_B.x_ddot_d[APF_Path_Planning_2023a_B.r_b] =
            APF_Path_Planning_2023a_B.rtb_y_g;
        }

        // End of Product: '<S653>/Product1'

        // DataStoreWrite: '<S653>/RED_Fx_Sat' incorporates:
        //   Product: '<S669>/Rotate F_b to F_I'

        APF_Path_Planning_2023a_DW.RED_Fx_Sat =
          APF_Path_Planning_2023a_B.rtb_C_Ib_g[0] *
          APF_Path_Planning_2023a_B.x_ddot_d[0] +
          APF_Path_Planning_2023a_B.x_ddot_d[1] *
          APF_Path_Planning_2023a_B.rtb_C_Ib_g[2];

        // DataStoreWrite: '<S653>/RED_Fy_Sat' incorporates:
        //   Product: '<S669>/Rotate F_b to F_I'

        APF_Path_Planning_2023a_DW.RED_Fy_Sat =
          APF_Path_Planning_2023a_B.x_ddot_d[0] *
          APF_Path_Planning_2023a_B.rtb_C_Ib_g[1] +
          APF_Path_Planning_2023a_B.x_ddot_d[1] *
          APF_Path_Planning_2023a_B.rtb_C_Ib_g[3];

        // DataStoreWrite: '<S653>/RED_Tz_Sat'
        APF_Path_Planning_2023a_DW.RED_Tz_Sat =
          APF_Path_Planning_2023a_B.x_ddot_d[2];

        // End of Outputs for SubSystem: '<S19>/Change RED Behavior'
      }

      // End of If: '<S19>/This IF block determines whether or not to run the RED sim//exp ' 

      // If: '<S19>/This IF block determines whether or not to run the BLACK sim//exp' incorporates:
      //   DataStoreRead: '<S19>/Data Store Read'
      //   DataStoreRead: '<S19>/Data Store Read1'
      //   Product: '<S638>/Product1'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if ((APF_Path_Planning_2023a_DW.WhoAmI == 2.0) ||
            (APF_Path_Planning_2023a_DW.isSim == 1.0)) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_am =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_am;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S19>/Change BLACK Behavior' incorporates:
        //   ActionPort: '<S626>/Action Port'

        // MATLAB Function: '<S636>/Create Rotation Matrix' incorporates:
        //   DataStoreRead: '<S629>/BLACK_Rz'

        APF_Path_P_CreateRotationMatrix(APF_Path_Planning_2023a_DW.BLACK_Rz,
          APF_Path_Planning_2023a_B.rtb_C_Ib_g);

        // MATLAB Function: '<S629>/MATLAB Function'
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.r_b]
            =
            APF_Path_Planning_2023a_P.F_thrusters_BLACK[APF_Path_Planning_2023a_B.r_b]
            / 2.0;
        }

        memset(&APF_Path_Planning_2023a_B.y[0], 0, sizeof(real_T) << 6U);
        for (APF_Path_Planning_2023a_B.exponent = 0;
             APF_Path_Planning_2023a_B.exponent < 8;
             APF_Path_Planning_2023a_B.exponent++) {
          APF_Path_Planning_2023a_B.y[APF_Path_Planning_2023a_B.exponent +
            (APF_Path_Planning_2023a_B.exponent << 3)] =
            APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.exponent];
          APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.exponent] =
            b[APF_Path_Planning_2023a_B.exponent];
          APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.exponent + 1]
            = c[APF_Path_Planning_2023a_B.exponent];
          APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.exponent + 2]
            =
            APF_Path_Planning_2023a_P.thruster_dist2CG_BLACK[APF_Path_Planning_2023a_B.exponent]
            / 1000.0;
        }

        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.sampleTime_j = 0.0;
            for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
                 APF_Path_Planning_2023a_B.ntIdx1 < 8;
                 APF_Path_Planning_2023a_B.ntIdx1++) {
              APF_Path_Planning_2023a_B.sampleTime_j +=
                APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.ntIdx1
                + APF_Path_Planning_2023a_B.exponent] *
                APF_Path_Planning_2023a_B.y[(APF_Path_Planning_2023a_B.r_b << 3)
                + APF_Path_Planning_2023a_B.ntIdx1];
            }

            APF_Path_Planning_2023a_B.Merge1_d[APF_Path_Planning_2023a_B.exponent
              + 3 * APF_Path_Planning_2023a_B.r_b] =
              APF_Path_Planning_2023a_B.sampleTime_j;
          }
        }

        // End of MATLAB Function: '<S629>/MATLAB Function'

        // PermuteDimensions: '<S637>/transpose' incorporates:
        //   Product: '<S638>/Product1'

        APF_Path_Planning_2023a_B.yElIdx = 0;
        APF_Path_Planning_2023a_B.uElOffset1 = 0;
        for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
             APF_Path_Planning_2023a_B.ntIdx1 < 3;
             APF_Path_Planning_2023a_B.ntIdx1++) {
          APF_Path_Planning_2023a_B.StartClock =
            APF_Path_Planning_2023a_B.uElOffset1;
          for (APF_Path_Planning_2023a_B.ntIdx0 = 0;
               APF_Path_Planning_2023a_B.ntIdx0 < 8;
               APF_Path_Planning_2023a_B.ntIdx0++) {
            APF_Path_Planning_2023a_B.Product1_e[APF_Path_Planning_2023a_B.yElIdx]
              =
              APF_Path_Planning_2023a_B.Merge1_d[APF_Path_Planning_2023a_B.StartClock];
            APF_Path_Planning_2023a_B.yElIdx++;
            APF_Path_Planning_2023a_B.StartClock += 3;
          }

          APF_Path_Planning_2023a_B.uElOffset1++;
        }

        // End of PermuteDimensions: '<S637>/transpose'

        // Product: '<S637>/Product' incorporates:
        //   Product: '<S638>/Product1'

        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             3; APF_Path_Planning_2023a_B.r_b++) {
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.sampleTime_j = 0.0;
            for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
                 APF_Path_Planning_2023a_B.ntIdx1 < 8;
                 APF_Path_Planning_2023a_B.ntIdx1++) {
              APF_Path_Planning_2023a_B.sampleTime_j +=
                APF_Path_Planning_2023a_B.Merge1_d[3 *
                APF_Path_Planning_2023a_B.ntIdx1 +
                APF_Path_Planning_2023a_B.exponent] *
                APF_Path_Planning_2023a_B.Product1_e
                [(APF_Path_Planning_2023a_B.r_b << 3) +
                APF_Path_Planning_2023a_B.ntIdx1];
            }

            APF_Path_Planning_2023a_B.rtb_Product2_m_b[APF_Path_Planning_2023a_B.exponent
              + 3 * APF_Path_Planning_2023a_B.r_b] =
              APF_Path_Planning_2023a_B.sampleTime_j;
          }
        }

        // Product: '<S637>/Product1' incorporates:
        //   Product: '<S637>/Product'

        APF_Path_Plannin_rt_invd3x3_snf
          (APF_Path_Planning_2023a_B.rtb_Product2_m_b,
           APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp);

        // Product: '<S637>/Product2' incorporates:
        //   Product: '<S629>/Product5'
        //   Product: '<S638>/Product1'

        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          APF_Path_Planning_2023a_B.sampleTime_d =
            APF_Path_Planning_2023a_B.Product1_e[APF_Path_Planning_2023a_B.r_b +
            8];
          APF_Path_Planning_2023a_B.sampleTime =
            APF_Path_Planning_2023a_B.Product1_e[APF_Path_Planning_2023a_B.r_b];
          APF_Path_Planning_2023a_B.RED_Tz_RW =
            APF_Path_Planning_2023a_B.Product1_e[APF_Path_Planning_2023a_B.r_b +
            16];
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.Product2_m[APF_Path_Planning_2023a_B.r_b +
              (APF_Path_Planning_2023a_B.exponent << 3)] =
              (APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp[3 *
               APF_Path_Planning_2023a_B.exponent + 1] *
               APF_Path_Planning_2023a_B.sampleTime_d +
               APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp[3 *
               APF_Path_Planning_2023a_B.exponent] *
               APF_Path_Planning_2023a_B.sampleTime) +
              APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp[3 *
              APF_Path_Planning_2023a_B.exponent + 2] *
              APF_Path_Planning_2023a_B.RED_Tz_RW;
          }
        }

        // End of Product: '<S637>/Product2'

        // MATLAB Function: '<S630>/Create Rotation Matrix' incorporates:
        //   DataStoreRead: '<S626>/BLACK_Rz'
        //   Product: '<S638>/Product2'

        APF_Path_CreateRotationMatrix_g(APF_Path_Planning_2023a_DW.BLACK_Rz,
          &APF_Path_Planning_2023a_B.Product2_n[0]);

        // Product: '<S630>/Rotate F_I to F_b' incorporates:
        //   DataStoreRead: '<S626>/BLACK_Fx'
        //   DataStoreRead: '<S626>/BLACK_Fy'
        //   SignalConversion generated from: '<S630>/Rotate F_I to F_b'

        APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_B.Product2_n[0] *
          APF_Path_Planning_2023a_DW.BLACK_Fx +
          APF_Path_Planning_2023a_B.Product2_n[2] *
          APF_Path_Planning_2023a_DW.BLACK_Fy;

        // SignalConversion generated from: '<S629>/Product' incorporates:
        //   Product: '<S630>/Rotate F_I to F_b'

        APF_Path_Planning_2023a_B.x_ddot_d[0] = APF_Path_Planning_2023a_B.t;

        // Product: '<S630>/Rotate F_I to F_b' incorporates:
        //   DataStoreRead: '<S626>/BLACK_Fx'
        //   DataStoreRead: '<S626>/BLACK_Fy'
        //   SignalConversion generated from: '<S630>/Rotate F_I to F_b'

        APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
          APF_Path_Planning_2023a_B.Product2_n[1] *
          APF_Path_Planning_2023a_DW.BLACK_Fx +
          APF_Path_Planning_2023a_B.Product2_n[3] *
          APF_Path_Planning_2023a_DW.BLACK_Fy;

        // SignalConversion generated from: '<S629>/Product' incorporates:
        //   DataStoreRead: '<S626>/BLACK_Tz'

        APF_Path_Planning_2023a_B.x_ddot_d[1] =
          APF_Path_Planning_2023a_B.rtb_path_b_idx_0;
        APF_Path_Planning_2023a_B.x_ddot_d[2] =
          APF_Path_Planning_2023a_DW.BLACK_Tz;
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          // Product: '<S629>/Product' incorporates:
          //   DataStoreRead: '<S626>/BLACK_Tz'
          //   Product: '<S629>/Product5'
          //   Product: '<S630>/Rotate F_I to F_b'
          //   SignalConversion generated from: '<S629>/Product'

          APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.r_b]
            =
            (APF_Path_Planning_2023a_B.Product2_m[APF_Path_Planning_2023a_B.r_b
             + 8] * APF_Path_Planning_2023a_B.rtb_path_b_idx_0 +
             APF_Path_Planning_2023a_B.Product2_m[APF_Path_Planning_2023a_B.r_b]
             * APF_Path_Planning_2023a_B.t) +
            APF_Path_Planning_2023a_B.Product2_m[APF_Path_Planning_2023a_B.r_b +
            16] * APF_Path_Planning_2023a_DW.BLACK_Tz;
        }

        // DataStoreWrite: '<S629>/Data Store Write2' incorporates:
        //   MATLAB Function: '<S629>/MATLAB Function10'

        APF_Path_Plann_MATLABFunction10(APF_Path_Planning_2023a_B.rtb_Product_f,
          &APF_Path_Planning_2023a_B.sampleTime_j,
          &APF_Path_Planning_2023a_DW.BLACK_Thruster_ON_Count,
          &APF_Path_Planning_2023a_B.sf_MATLABFunction10);

        // MATLAB Function: '<S629>/MATLAB Function3' incorporates:
        //   MATLAB Function: '<S629>/MATLAB Function11'

        APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 =
          APF_Path_Planning_2023a_P.F_Black_X_nominal *
          APF_Path_Planning_2023a_B.sampleTime_j;
        APF_Path_Planning_2023a_B.rtb_Product_f[0] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_Product_f[1] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1 =
          APF_Path_Planning_2023a_P.F_Black_Y_nominal *
          APF_Path_Planning_2023a_B.sampleTime_j;
        APF_Path_Planning_2023a_B.rtb_Product_f[2] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        APF_Path_Planning_2023a_B.rtb_Product_f[3] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        APF_Path_Planning_2023a_B.rtb_Product_f[4] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_Product_f[5] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_Product_f[6] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        APF_Path_Planning_2023a_B.rtb_Product_f[7] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        memset(&APF_Path_Planning_2023a_B.y[0], 0, sizeof(real_T) << 6U);
        for (APF_Path_Planning_2023a_B.exponent = 0;
             APF_Path_Planning_2023a_B.exponent < 8;
             APF_Path_Planning_2023a_B.exponent++) {
          APF_Path_Planning_2023a_B.y[APF_Path_Planning_2023a_B.exponent +
            (APF_Path_Planning_2023a_B.exponent << 3)] =
            APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.exponent];
        }

        // MATLAB Function: '<S629>/MATLAB Function11'
        APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 /= 2.0;
        APF_Path_Planning_2023a_B.rtb_Product_f[0] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_Product_f[1] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1 /= 2.0;
        APF_Path_Planning_2023a_B.rtb_Product_f[2] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        APF_Path_Planning_2023a_B.rtb_Product_f[3] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        APF_Path_Planning_2023a_B.rtb_Product_f[4] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_Product_f[5] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_Product_f[6] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        APF_Path_Planning_2023a_B.rtb_Product_f[7] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        memset(&APF_Path_Planning_2023a_B.y_m[0], 0, sizeof(real_T) << 6U);
        for (APF_Path_Planning_2023a_B.exponent = 0;
             APF_Path_Planning_2023a_B.exponent < 8;
             APF_Path_Planning_2023a_B.exponent++) {
          APF_Path_Planning_2023a_B.y_m[APF_Path_Planning_2023a_B.exponent +
            (APF_Path_Planning_2023a_B.exponent << 3)] =
            APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.exponent];
          APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.exponent] =
            b[APF_Path_Planning_2023a_B.exponent];
          APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.exponent + 1]
            = c[APF_Path_Planning_2023a_B.exponent];
        }

        APF_Path_Planning_2023a_B.b[2] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLACK[0] / 1000.0;
        APF_Path_Planning_2023a_B.b[5] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLACK[1] / 1000.0;
        APF_Path_Planning_2023a_B.b[8] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLACK[2] / 1000.0;
        APF_Path_Planning_2023a_B.b[11] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLACK[3] / 1000.0;
        APF_Path_Planning_2023a_B.b[14] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLACK[4] / 1000.0;
        APF_Path_Planning_2023a_B.b[17] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLACK[5] / 1000.0;
        APF_Path_Planning_2023a_B.b[20] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLACK[6] / 1000.0;
        APF_Path_Planning_2023a_B.b[23] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLACK[7] / 1000.0;
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.sampleTime_d = 0.0;
            for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
                 APF_Path_Planning_2023a_B.ntIdx1 < 8;
                 APF_Path_Planning_2023a_B.ntIdx1++) {
              APF_Path_Planning_2023a_B.sampleTime_d +=
                APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.ntIdx1
                + APF_Path_Planning_2023a_B.exponent] *
                APF_Path_Planning_2023a_B.y_m[(APF_Path_Planning_2023a_B.r_b <<
                3) + APF_Path_Planning_2023a_B.ntIdx1];
            }

            APF_Path_Planning_2023a_B.Product1_e[APF_Path_Planning_2023a_B.exponent
              + 3 * APF_Path_Planning_2023a_B.r_b] =
              APF_Path_Planning_2023a_B.sampleTime_d;
          }
        }

        // PermuteDimensions: '<S638>/transpose' incorporates:
        //   Product: '<S629>/Product5'

        APF_Path_Planning_2023a_B.yElIdx = 0;
        APF_Path_Planning_2023a_B.uElOffset1 = 0;
        for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
             APF_Path_Planning_2023a_B.ntIdx1 < 3;
             APF_Path_Planning_2023a_B.ntIdx1++) {
          APF_Path_Planning_2023a_B.StartClock =
            APF_Path_Planning_2023a_B.uElOffset1;
          for (APF_Path_Planning_2023a_B.ntIdx0 = 0;
               APF_Path_Planning_2023a_B.ntIdx0 < 8;
               APF_Path_Planning_2023a_B.ntIdx0++) {
            APF_Path_Planning_2023a_B.Product2_m[APF_Path_Planning_2023a_B.yElIdx]
              =
              APF_Path_Planning_2023a_B.Product1_e[APF_Path_Planning_2023a_B.StartClock];
            APF_Path_Planning_2023a_B.yElIdx++;
            APF_Path_Planning_2023a_B.StartClock += 3;
          }

          APF_Path_Planning_2023a_B.uElOffset1++;
        }

        // End of PermuteDimensions: '<S638>/transpose'

        // Product: '<S638>/Product' incorporates:
        //   Product: '<S629>/Product5'

        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             3; APF_Path_Planning_2023a_B.r_b++) {
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.sampleTime_d = 0.0;
            for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
                 APF_Path_Planning_2023a_B.ntIdx1 < 8;
                 APF_Path_Planning_2023a_B.ntIdx1++) {
              APF_Path_Planning_2023a_B.sampleTime_d +=
                APF_Path_Planning_2023a_B.Product1_e[3 *
                APF_Path_Planning_2023a_B.ntIdx1 +
                APF_Path_Planning_2023a_B.exponent] *
                APF_Path_Planning_2023a_B.Product2_m
                [(APF_Path_Planning_2023a_B.r_b << 3) +
                APF_Path_Planning_2023a_B.ntIdx1];
            }

            APF_Path_Planning_2023a_B.rtb_Product2_m_b[APF_Path_Planning_2023a_B.exponent
              + 3 * APF_Path_Planning_2023a_B.r_b] =
              APF_Path_Planning_2023a_B.sampleTime_d;
          }
        }

        // Product: '<S638>/Product1' incorporates:
        //   Product: '<S638>/Product'

        APF_Path_Plannin_rt_invd3x3_snf
          (APF_Path_Planning_2023a_B.rtb_Product2_m_b,
           APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp);
        memcpy(&APF_Path_Planning_2023a_B.rtb_Product2_m_b[0],
               &APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp[0], 9U * sizeof
               (real_T));
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          // Product: '<S638>/Product2' incorporates:
          //   Product: '<S629>/Product5'

          APF_Path_Planning_2023a_B.q =
            APF_Path_Planning_2023a_B.Product2_m[APF_Path_Planning_2023a_B.r_b +
            8];
          APF_Path_Planning_2023a_B.sampleTime_d =
            APF_Path_Planning_2023a_B.Product2_m[APF_Path_Planning_2023a_B.r_b];
          APF_Path_Planning_2023a_B.sampleTime =
            APF_Path_Planning_2023a_B.Product2_m[APF_Path_Planning_2023a_B.r_b +
            16];

          // Product: '<S629>/Product5'
          APF_Path_Planning_2023a_B.sampleTime_j = 0.0;
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            // Product: '<S638>/Product2'
            APF_Path_Planning_2023a_B.RED_Tz_RW =
              (APF_Path_Planning_2023a_B.rtb_Product2_m_b[3 *
               APF_Path_Planning_2023a_B.exponent + 1] *
               APF_Path_Planning_2023a_B.q +
               APF_Path_Planning_2023a_B.rtb_Product2_m_b[3 *
               APF_Path_Planning_2023a_B.exponent] *
               APF_Path_Planning_2023a_B.sampleTime_d) +
              APF_Path_Planning_2023a_B.rtb_Product2_m_b[3 *
              APF_Path_Planning_2023a_B.exponent + 2] *
              APF_Path_Planning_2023a_B.sampleTime;

            // Product: '<S638>/Product2'
            APF_Path_Planning_2023a_B.Product2_n[APF_Path_Planning_2023a_B.r_b +
              (APF_Path_Planning_2023a_B.exponent << 3)] =
              APF_Path_Planning_2023a_B.RED_Tz_RW;

            // Product: '<S629>/Product5' incorporates:
            //   Product: '<S638>/Product2'

            APF_Path_Planning_2023a_B.sampleTime_j +=
              APF_Path_Planning_2023a_B.RED_Tz_RW *
              APF_Path_Planning_2023a_B.x_ddot_d[APF_Path_Planning_2023a_B.exponent];
          }

          // Saturate: '<S629>/Remove Negatives' incorporates:
          //   Product: '<S629>/Product5'

          if (APF_Path_Planning_2023a_B.sampleTime_j >
              APF_Path_Planning_2023a_P.RemoveNegatives_UpperSat) {
            // Saturate: '<S629>/Remove Negatives'
            APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.r_b]
              = APF_Path_Planning_2023a_P.RemoveNegatives_UpperSat;
          } else if (APF_Path_Planning_2023a_B.sampleTime_j <
                     APF_Path_Planning_2023a_P.RemoveNegatives_LowerSat) {
            // Saturate: '<S629>/Remove Negatives'
            APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.r_b]
              = APF_Path_Planning_2023a_P.RemoveNegatives_LowerSat;
          } else {
            // Saturate: '<S629>/Remove Negatives'
            APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.r_b]
              = APF_Path_Planning_2023a_B.sampleTime_j;
          }

          // End of Saturate: '<S629>/Remove Negatives'
        }

        // MATLAB Function: '<S629>/MATLAB Function1' incorporates:
        //   Product: '<S638>/Product1'

        APF_Path_Plan_MATLABFunction1_l(APF_Path_Planning_2023a_B.rtb_Product_f,
          APF_Path_Planning_2023a_B.ThrustPer_Final_d);

        // MATLAB Function: '<S629>/MATLAB Function3'
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.r_b] =
            b[APF_Path_Planning_2023a_B.r_b];
          APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.r_b + 1] =
            c[APF_Path_Planning_2023a_B.r_b];
        }

        APF_Path_Planning_2023a_B.b[2] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLACK[0] / 1000.0;
        APF_Path_Planning_2023a_B.b[5] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLACK[1] / 1000.0;
        APF_Path_Planning_2023a_B.b[8] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLACK[2] / 1000.0;
        APF_Path_Planning_2023a_B.b[11] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLACK[3] / 1000.0;
        APF_Path_Planning_2023a_B.b[14] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLACK[4] / 1000.0;
        APF_Path_Planning_2023a_B.b[17] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLACK[5] / 1000.0;
        APF_Path_Planning_2023a_B.b[20] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLACK[6] / 1000.0;
        APF_Path_Planning_2023a_B.b[23] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLACK[7] / 1000.0;
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             3; APF_Path_Planning_2023a_B.r_b++) {
          // Product: '<S629>/Product1'
          APF_Path_Planning_2023a_B.x_ddot_d[APF_Path_Planning_2023a_B.r_b] =
            0.0;
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 8;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.q = 0.0;
            for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
                 APF_Path_Planning_2023a_B.ntIdx1 < 8;
                 APF_Path_Planning_2023a_B.ntIdx1++) {
              APF_Path_Planning_2023a_B.q += APF_Path_Planning_2023a_B.b[3 *
                APF_Path_Planning_2023a_B.ntIdx1 + APF_Path_Planning_2023a_B.r_b]
                * APF_Path_Planning_2023a_B.y
                [(APF_Path_Planning_2023a_B.exponent << 3) +
                APF_Path_Planning_2023a_B.ntIdx1];
            }

            APF_Path_Planning_2023a_B.x_ddot_d[APF_Path_Planning_2023a_B.r_b] +=
              APF_Path_Planning_2023a_B.q *
              APF_Path_Planning_2023a_B.ThrustPer_Final_d[APF_Path_Planning_2023a_B.exponent];
          }

          // End of Product: '<S629>/Product1'
        }

        // DataStoreWrite: '<S629>/BLACK_Fx_Sat' incorporates:
        //   Product: '<S636>/Rotate F_b to F_I'

        APF_Path_Planning_2023a_DW.BLACK_Fx_Sat =
          APF_Path_Planning_2023a_B.rtb_C_Ib_g[0] *
          APF_Path_Planning_2023a_B.x_ddot_d[0] +
          APF_Path_Planning_2023a_B.x_ddot_d[1] *
          APF_Path_Planning_2023a_B.rtb_C_Ib_g[2];

        // DataStoreWrite: '<S629>/BLACK_Fy_Sat' incorporates:
        //   Product: '<S636>/Rotate F_b to F_I'

        APF_Path_Planning_2023a_DW.BLACK_Fy_Sat =
          APF_Path_Planning_2023a_B.x_ddot_d[0] *
          APF_Path_Planning_2023a_B.rtb_C_Ib_g[1] +
          APF_Path_Planning_2023a_B.x_ddot_d[1] *
          APF_Path_Planning_2023a_B.rtb_C_Ib_g[3];

        // DataStoreWrite: '<S629>/BLACK_Tz_Sat'
        APF_Path_Planning_2023a_DW.BLACK_Tz_Sat =
          APF_Path_Planning_2023a_B.x_ddot_d[2];

        // End of Outputs for SubSystem: '<S19>/Change BLACK Behavior'
      }

      // End of If: '<S19>/This IF block determines whether or not to run the BLACK sim//exp' 

      // If: '<S19>/This IF block determines whether or not to run the BLUE sim//exp' incorporates:
      //   DataStoreRead: '<S19>/Data Store Read'
      //   DataStoreRead: '<S19>/Data Store Read1'
      //   Product: '<S650>/Product1'

      APF_Path_Planning_2023a_B.rtAction = -1;
      if (rtsiIsModeUpdateTimeStep(&APF_Path_Planning_2023a_M->solverInfo)) {
        if ((APF_Path_Planning_2023a_DW.WhoAmI == 3.0) ||
            (APF_Path_Planning_2023a_DW.isSim == 1.0)) {
          APF_Path_Planning_2023a_B.rtAction = 0;
        }

        APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_h =
          APF_Path_Planning_2023a_B.rtAction;
      } else {
        APF_Path_Planning_2023a_B.rtAction =
          APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_h;
      }

      if (APF_Path_Planning_2023a_B.rtAction == 0) {
        // Outputs for IfAction SubSystem: '<S19>/Change BLUE Behavior' incorporates:
        //   ActionPort: '<S627>/Action Port'

        // MATLAB Function: '<S648>/Create Rotation Matrix' incorporates:
        //   DataStoreRead: '<S641>/BLUE_Rz'

        APF_Path_P_CreateRotationMatrix(APF_Path_Planning_2023a_DW.BLUE_Rz,
          APF_Path_Planning_2023a_B.rtb_C_Ib_g);

        // MATLAB Function: '<S641>/MATLAB Function'
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.r_b]
            =
            APF_Path_Planning_2023a_P.F_thrusters_BLUE[APF_Path_Planning_2023a_B.r_b]
            / 2.0;
        }

        memset(&APF_Path_Planning_2023a_B.y[0], 0, sizeof(real_T) << 6U);
        for (APF_Path_Planning_2023a_B.exponent = 0;
             APF_Path_Planning_2023a_B.exponent < 8;
             APF_Path_Planning_2023a_B.exponent++) {
          APF_Path_Planning_2023a_B.y[APF_Path_Planning_2023a_B.exponent +
            (APF_Path_Planning_2023a_B.exponent << 3)] =
            APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.exponent];
          APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.exponent] =
            b[APF_Path_Planning_2023a_B.exponent];
          APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.exponent + 1]
            = c[APF_Path_Planning_2023a_B.exponent];
          APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.exponent + 2]
            =
            APF_Path_Planning_2023a_P.thruster_dist2CG_BLUE[APF_Path_Planning_2023a_B.exponent]
            / 1000.0;
        }

        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.q = 0.0;
            for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
                 APF_Path_Planning_2023a_B.ntIdx1 < 8;
                 APF_Path_Planning_2023a_B.ntIdx1++) {
              APF_Path_Planning_2023a_B.q += APF_Path_Planning_2023a_B.b[3 *
                APF_Path_Planning_2023a_B.ntIdx1 +
                APF_Path_Planning_2023a_B.exponent] *
                APF_Path_Planning_2023a_B.y[(APF_Path_Planning_2023a_B.r_b << 3)
                + APF_Path_Planning_2023a_B.ntIdx1];
            }

            APF_Path_Planning_2023a_B.Product2_m[APF_Path_Planning_2023a_B.exponent
              + 3 * APF_Path_Planning_2023a_B.r_b] = APF_Path_Planning_2023a_B.q;
          }
        }

        // End of MATLAB Function: '<S641>/MATLAB Function'

        // PermuteDimensions: '<S649>/transpose' incorporates:
        //   Product: '<S650>/Product1'

        APF_Path_Planning_2023a_B.yElIdx = 0;
        APF_Path_Planning_2023a_B.uElOffset1 = 0;
        for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
             APF_Path_Planning_2023a_B.ntIdx1 < 3;
             APF_Path_Planning_2023a_B.ntIdx1++) {
          APF_Path_Planning_2023a_B.StartClock =
            APF_Path_Planning_2023a_B.uElOffset1;
          for (APF_Path_Planning_2023a_B.ntIdx0 = 0;
               APF_Path_Planning_2023a_B.ntIdx0 < 8;
               APF_Path_Planning_2023a_B.ntIdx0++) {
            APF_Path_Planning_2023a_B.Product1_it[APF_Path_Planning_2023a_B.yElIdx]
              =
              APF_Path_Planning_2023a_B.Product2_m[APF_Path_Planning_2023a_B.StartClock];
            APF_Path_Planning_2023a_B.yElIdx++;
            APF_Path_Planning_2023a_B.StartClock += 3;
          }

          APF_Path_Planning_2023a_B.uElOffset1++;
        }

        // End of PermuteDimensions: '<S649>/transpose'

        // Product: '<S649>/Product' incorporates:
        //   Product: '<S650>/Product1'

        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             3; APF_Path_Planning_2023a_B.r_b++) {
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.q = 0.0;
            for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
                 APF_Path_Planning_2023a_B.ntIdx1 < 8;
                 APF_Path_Planning_2023a_B.ntIdx1++) {
              APF_Path_Planning_2023a_B.q +=
                APF_Path_Planning_2023a_B.Product2_m[3 *
                APF_Path_Planning_2023a_B.ntIdx1 +
                APF_Path_Planning_2023a_B.exponent] *
                APF_Path_Planning_2023a_B.Product1_it
                [(APF_Path_Planning_2023a_B.r_b << 3) +
                APF_Path_Planning_2023a_B.ntIdx1];
            }

            APF_Path_Planning_2023a_B.rtb_Product2_m_b[APF_Path_Planning_2023a_B.exponent
              + 3 * APF_Path_Planning_2023a_B.r_b] = APF_Path_Planning_2023a_B.q;
          }
        }

        // Product: '<S649>/Product1' incorporates:
        //   Product: '<S649>/Product'

        APF_Path_Plannin_rt_invd3x3_snf
          (APF_Path_Planning_2023a_B.rtb_Product2_m_b,
           APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp);

        // Product: '<S649>/Product2' incorporates:
        //   Product: '<S641>/Product4'
        //   Product: '<S650>/Product1'

        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          APF_Path_Planning_2023a_B.sampleTime_j =
            APF_Path_Planning_2023a_B.Product1_it[APF_Path_Planning_2023a_B.r_b
            + 8];
          APF_Path_Planning_2023a_B.sampleTime_d =
            APF_Path_Planning_2023a_B.Product1_it[APF_Path_Planning_2023a_B.r_b];
          APF_Path_Planning_2023a_B.sampleTime =
            APF_Path_Planning_2023a_B.Product1_it[APF_Path_Planning_2023a_B.r_b
            + 16];
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.Product1_e[APF_Path_Planning_2023a_B.r_b +
              (APF_Path_Planning_2023a_B.exponent << 3)] =
              (APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp[3 *
               APF_Path_Planning_2023a_B.exponent + 1] *
               APF_Path_Planning_2023a_B.sampleTime_j +
               APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp[3 *
               APF_Path_Planning_2023a_B.exponent] *
               APF_Path_Planning_2023a_B.sampleTime_d) +
              APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp[3 *
              APF_Path_Planning_2023a_B.exponent + 2] *
              APF_Path_Planning_2023a_B.sampleTime;
          }
        }

        // End of Product: '<S649>/Product2'

        // MATLAB Function: '<S642>/Create Rotation Matrix' incorporates:
        //   DataStoreRead: '<S627>/BLUE_Rz'
        //   Product: '<S650>/Product2'

        APF_Path_CreateRotationMatrix_g(APF_Path_Planning_2023a_DW.BLUE_Rz,
          &APF_Path_Planning_2023a_B.Product2[0]);

        // Product: '<S642>/Rotate F_I to F_b' incorporates:
        //   DataStoreRead: '<S627>/BLUE_Fx'
        //   DataStoreRead: '<S627>/BLUE_Fy'
        //   SignalConversion generated from: '<S642>/Rotate F_I to F_b'

        APF_Path_Planning_2023a_B.t = APF_Path_Planning_2023a_B.Product2[0] *
          APF_Path_Planning_2023a_DW.BLUE_Fx +
          APF_Path_Planning_2023a_B.Product2[2] *
          APF_Path_Planning_2023a_DW.BLUE_Fy;

        // SignalConversion generated from: '<S641>/Product' incorporates:
        //   Product: '<S642>/Rotate F_I to F_b'

        APF_Path_Planning_2023a_B.x_ddot_d[0] = APF_Path_Planning_2023a_B.t;

        // Product: '<S642>/Rotate F_I to F_b' incorporates:
        //   DataStoreRead: '<S627>/BLUE_Fx'
        //   DataStoreRead: '<S627>/BLUE_Fy'
        //   SignalConversion generated from: '<S642>/Rotate F_I to F_b'

        APF_Path_Planning_2023a_B.rtb_path_b_idx_0 =
          APF_Path_Planning_2023a_B.Product2[1] *
          APF_Path_Planning_2023a_DW.BLUE_Fx +
          APF_Path_Planning_2023a_B.Product2[3] *
          APF_Path_Planning_2023a_DW.BLUE_Fy;

        // SignalConversion generated from: '<S641>/Product' incorporates:
        //   DataStoreRead: '<S627>/BLUE_Tz'

        APF_Path_Planning_2023a_B.x_ddot_d[1] =
          APF_Path_Planning_2023a_B.rtb_path_b_idx_0;
        APF_Path_Planning_2023a_B.x_ddot_d[2] =
          APF_Path_Planning_2023a_DW.BLUE_Tz;
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          // Product: '<S641>/Product' incorporates:
          //   DataStoreRead: '<S627>/BLUE_Tz'
          //   Product: '<S641>/Product4'
          //   Product: '<S642>/Rotate F_I to F_b'
          //   SignalConversion generated from: '<S641>/Product'

          APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.r_b]
            =
            (APF_Path_Planning_2023a_B.Product1_e[APF_Path_Planning_2023a_B.r_b
             + 8] * APF_Path_Planning_2023a_B.rtb_path_b_idx_0 +
             APF_Path_Planning_2023a_B.Product1_e[APF_Path_Planning_2023a_B.r_b]
             * APF_Path_Planning_2023a_B.t) +
            APF_Path_Planning_2023a_B.Product1_e[APF_Path_Planning_2023a_B.r_b +
            16] * APF_Path_Planning_2023a_DW.BLUE_Tz;
        }

        // DataStoreWrite: '<S641>/Data Store Write1' incorporates:
        //   MATLAB Function: '<S641>/MATLAB Function6'

        APF_Path_Plann_MATLABFunction10(APF_Path_Planning_2023a_B.rtb_Product_f,
          &APF_Path_Planning_2023a_B.sampleTime_j,
          &APF_Path_Planning_2023a_DW.BLUE_Thruster_ON_Count,
          &APF_Path_Planning_2023a_B.sf_MATLABFunction6);

        // MATLAB Function: '<S641>/MATLAB Function1' incorporates:
        //   MATLAB Function: '<S641>/MATLAB Function7'

        APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 =
          APF_Path_Planning_2023a_P.F_Blue_X_nominal *
          APF_Path_Planning_2023a_B.sampleTime_j;
        APF_Path_Planning_2023a_B.rtb_Product_f[0] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_Product_f[1] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1 =
          APF_Path_Planning_2023a_P.F_Blue_Y_nominal *
          APF_Path_Planning_2023a_B.sampleTime_j;
        APF_Path_Planning_2023a_B.rtb_Product_f[2] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        APF_Path_Planning_2023a_B.rtb_Product_f[3] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        APF_Path_Planning_2023a_B.rtb_Product_f[4] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_Product_f[5] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_Product_f[6] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        APF_Path_Planning_2023a_B.rtb_Product_f[7] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        memset(&APF_Path_Planning_2023a_B.y[0], 0, sizeof(real_T) << 6U);
        for (APF_Path_Planning_2023a_B.exponent = 0;
             APF_Path_Planning_2023a_B.exponent < 8;
             APF_Path_Planning_2023a_B.exponent++) {
          APF_Path_Planning_2023a_B.y[APF_Path_Planning_2023a_B.exponent +
            (APF_Path_Planning_2023a_B.exponent << 3)] =
            APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.exponent];
        }

        // MATLAB Function: '<S641>/MATLAB Function7'
        APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0 /= 2.0;
        APF_Path_Planning_2023a_B.rtb_Product_f[0] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_Product_f[1] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1 /= 2.0;
        APF_Path_Planning_2023a_B.rtb_Product_f[2] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        APF_Path_Planning_2023a_B.rtb_Product_f[3] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        APF_Path_Planning_2023a_B.rtb_Product_f[4] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_Product_f[5] =
          APF_Path_Planning_2023a_B.rtb_Sum_b_idx_0;
        APF_Path_Planning_2023a_B.rtb_Product_f[6] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        APF_Path_Planning_2023a_B.rtb_Product_f[7] =
          APF_Path_Planning_2023a_B.rtb_x_ddot_idx_1;
        memset(&APF_Path_Planning_2023a_B.y_m[0], 0, sizeof(real_T) << 6U);
        for (APF_Path_Planning_2023a_B.exponent = 0;
             APF_Path_Planning_2023a_B.exponent < 8;
             APF_Path_Planning_2023a_B.exponent++) {
          APF_Path_Planning_2023a_B.y_m[APF_Path_Planning_2023a_B.exponent +
            (APF_Path_Planning_2023a_B.exponent << 3)] =
            APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.exponent];
          APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.exponent] =
            b[APF_Path_Planning_2023a_B.exponent];
          APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.exponent + 1]
            = c[APF_Path_Planning_2023a_B.exponent];
        }

        APF_Path_Planning_2023a_B.b[2] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLUE[0] / 1000.0;
        APF_Path_Planning_2023a_B.b[5] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLUE[1] / 1000.0;
        APF_Path_Planning_2023a_B.b[8] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLUE[2] / 1000.0;
        APF_Path_Planning_2023a_B.b[11] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLUE[3] / 1000.0;
        APF_Path_Planning_2023a_B.b[14] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLUE[4] / 1000.0;
        APF_Path_Planning_2023a_B.b[17] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLUE[5] / 1000.0;
        APF_Path_Planning_2023a_B.b[20] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLUE[6] / 1000.0;
        APF_Path_Planning_2023a_B.b[23] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLUE[7] / 1000.0;
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.sampleTime_j = 0.0;
            for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
                 APF_Path_Planning_2023a_B.ntIdx1 < 8;
                 APF_Path_Planning_2023a_B.ntIdx1++) {
              APF_Path_Planning_2023a_B.sampleTime_j +=
                APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.ntIdx1
                + APF_Path_Planning_2023a_B.exponent] *
                APF_Path_Planning_2023a_B.y_m[(APF_Path_Planning_2023a_B.r_b <<
                3) + APF_Path_Planning_2023a_B.ntIdx1];
            }

            APF_Path_Planning_2023a_B.Product1_it[APF_Path_Planning_2023a_B.exponent
              + 3 * APF_Path_Planning_2023a_B.r_b] =
              APF_Path_Planning_2023a_B.sampleTime_j;
          }
        }

        // PermuteDimensions: '<S650>/transpose' incorporates:
        //   Product: '<S641>/Product4'

        APF_Path_Planning_2023a_B.yElIdx = 0;
        APF_Path_Planning_2023a_B.uElOffset1 = 0;
        for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
             APF_Path_Planning_2023a_B.ntIdx1 < 3;
             APF_Path_Planning_2023a_B.ntIdx1++) {
          APF_Path_Planning_2023a_B.StartClock =
            APF_Path_Planning_2023a_B.uElOffset1;
          for (APF_Path_Planning_2023a_B.ntIdx0 = 0;
               APF_Path_Planning_2023a_B.ntIdx0 < 8;
               APF_Path_Planning_2023a_B.ntIdx0++) {
            APF_Path_Planning_2023a_B.Product1_e[APF_Path_Planning_2023a_B.yElIdx]
              =
              APF_Path_Planning_2023a_B.Product1_it[APF_Path_Planning_2023a_B.StartClock];
            APF_Path_Planning_2023a_B.yElIdx++;
            APF_Path_Planning_2023a_B.StartClock += 3;
          }

          APF_Path_Planning_2023a_B.uElOffset1++;
        }

        // End of PermuteDimensions: '<S650>/transpose'

        // Product: '<S650>/Product' incorporates:
        //   Product: '<S641>/Product4'

        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             3; APF_Path_Planning_2023a_B.r_b++) {
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.sampleTime_j = 0.0;
            for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
                 APF_Path_Planning_2023a_B.ntIdx1 < 8;
                 APF_Path_Planning_2023a_B.ntIdx1++) {
              APF_Path_Planning_2023a_B.sampleTime_j +=
                APF_Path_Planning_2023a_B.Product1_it[3 *
                APF_Path_Planning_2023a_B.ntIdx1 +
                APF_Path_Planning_2023a_B.exponent] *
                APF_Path_Planning_2023a_B.Product1_e
                [(APF_Path_Planning_2023a_B.r_b << 3) +
                APF_Path_Planning_2023a_B.ntIdx1];
            }

            APF_Path_Planning_2023a_B.rtb_Product2_m_b[APF_Path_Planning_2023a_B.exponent
              + 3 * APF_Path_Planning_2023a_B.r_b] =
              APF_Path_Planning_2023a_B.sampleTime_j;
          }
        }

        // Product: '<S650>/Product1' incorporates:
        //   Product: '<S650>/Product'

        APF_Path_Plannin_rt_invd3x3_snf
          (APF_Path_Planning_2023a_B.rtb_Product2_m_b,
           APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp);
        memcpy(&APF_Path_Planning_2023a_B.rtb_Product2_m_b[0],
               &APF_Path_Planning_2023a_B.rtb_phi_tot_grad_tmp[0], 9U * sizeof
               (real_T));
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          // Product: '<S650>/Product2' incorporates:
          //   Product: '<S641>/Product4'

          APF_Path_Planning_2023a_B.sampleTime_d =
            APF_Path_Planning_2023a_B.Product1_e[APF_Path_Planning_2023a_B.r_b +
            8];
          APF_Path_Planning_2023a_B.sampleTime =
            APF_Path_Planning_2023a_B.Product1_e[APF_Path_Planning_2023a_B.r_b];
          APF_Path_Planning_2023a_B.RED_Tz_RW =
            APF_Path_Planning_2023a_B.Product1_e[APF_Path_Planning_2023a_B.r_b +
            16];

          // Product: '<S641>/Product4'
          APF_Path_Planning_2023a_B.sampleTime_j = 0.0;
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 3;
               APF_Path_Planning_2023a_B.exponent++) {
            // Product: '<S650>/Product2'
            APF_Path_Planning_2023a_B.rtb_y_g =
              (APF_Path_Planning_2023a_B.rtb_Product2_m_b[3 *
               APF_Path_Planning_2023a_B.exponent + 1] *
               APF_Path_Planning_2023a_B.sampleTime_d +
               APF_Path_Planning_2023a_B.rtb_Product2_m_b[3 *
               APF_Path_Planning_2023a_B.exponent] *
               APF_Path_Planning_2023a_B.sampleTime) +
              APF_Path_Planning_2023a_B.rtb_Product2_m_b[3 *
              APF_Path_Planning_2023a_B.exponent + 2] *
              APF_Path_Planning_2023a_B.RED_Tz_RW;

            // Product: '<S650>/Product2'
            APF_Path_Planning_2023a_B.Product2[APF_Path_Planning_2023a_B.r_b +
              (APF_Path_Planning_2023a_B.exponent << 3)] =
              APF_Path_Planning_2023a_B.rtb_y_g;

            // Product: '<S641>/Product4' incorporates:
            //   Product: '<S650>/Product2'

            APF_Path_Planning_2023a_B.sampleTime_j +=
              APF_Path_Planning_2023a_B.rtb_y_g *
              APF_Path_Planning_2023a_B.x_ddot_d[APF_Path_Planning_2023a_B.exponent];
          }

          // Saturate: '<S641>/Remove Negatives' incorporates:
          //   Product: '<S641>/Product4'

          if (APF_Path_Planning_2023a_B.sampleTime_j >
              APF_Path_Planning_2023a_P.RemoveNegatives_UpperSat_m) {
            // Saturate: '<S641>/Remove Negatives'
            APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.r_b]
              = APF_Path_Planning_2023a_P.RemoveNegatives_UpperSat_m;
          } else if (APF_Path_Planning_2023a_B.sampleTime_j <
                     APF_Path_Planning_2023a_P.RemoveNegatives_LowerSat_a) {
            // Saturate: '<S641>/Remove Negatives'
            APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.r_b]
              = APF_Path_Planning_2023a_P.RemoveNegatives_LowerSat_a;
          } else {
            // Saturate: '<S641>/Remove Negatives'
            APF_Path_Planning_2023a_B.rtb_Product_f[APF_Path_Planning_2023a_B.r_b]
              = APF_Path_Planning_2023a_B.sampleTime_j;
          }

          // End of Saturate: '<S641>/Remove Negatives'
        }

        // MATLAB Function: '<S641>/MATLAB Function2' incorporates:
        //   Product: '<S650>/Product1'

        APF_Path_Plan_MATLABFunction1_l(APF_Path_Planning_2023a_B.rtb_Product_f,
          APF_Path_Planning_2023a_B.ThrustPer_Final_e);

        // MATLAB Function: '<S641>/MATLAB Function1'
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             8; APF_Path_Planning_2023a_B.r_b++) {
          APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.r_b] =
            b[APF_Path_Planning_2023a_B.r_b];
          APF_Path_Planning_2023a_B.b[3 * APF_Path_Planning_2023a_B.r_b + 1] =
            c[APF_Path_Planning_2023a_B.r_b];
        }

        APF_Path_Planning_2023a_B.b[2] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLUE[0] / 1000.0;
        APF_Path_Planning_2023a_B.b[5] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLUE[1] / 1000.0;
        APF_Path_Planning_2023a_B.b[8] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLUE[2] / 1000.0;
        APF_Path_Planning_2023a_B.b[11] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLUE[3] / 1000.0;
        APF_Path_Planning_2023a_B.b[14] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLUE[4] / 1000.0;
        APF_Path_Planning_2023a_B.b[17] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLUE[5] / 1000.0;
        APF_Path_Planning_2023a_B.b[20] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLUE[6] / 1000.0;
        APF_Path_Planning_2023a_B.b[23] =
          APF_Path_Planning_2023a_P.thruster_dist2CG_BLUE[7] / 1000.0;
        for (APF_Path_Planning_2023a_B.r_b = 0; APF_Path_Planning_2023a_B.r_b <
             3; APF_Path_Planning_2023a_B.r_b++) {
          // Product: '<S641>/Product1'
          APF_Path_Planning_2023a_B.x_ddot_d[APF_Path_Planning_2023a_B.r_b] =
            0.0;
          for (APF_Path_Planning_2023a_B.exponent = 0;
               APF_Path_Planning_2023a_B.exponent < 8;
               APF_Path_Planning_2023a_B.exponent++) {
            APF_Path_Planning_2023a_B.q = 0.0;
            for (APF_Path_Planning_2023a_B.ntIdx1 = 0;
                 APF_Path_Planning_2023a_B.ntIdx1 < 8;
                 APF_Path_Planning_2023a_B.ntIdx1++) {
              APF_Path_Planning_2023a_B.q += APF_Path_Planning_2023a_B.b[3 *
                APF_Path_Planning_2023a_B.ntIdx1 + APF_Path_Planning_2023a_B.r_b]
                * APF_Path_Planning_2023a_B.y
                [(APF_Path_Planning_2023a_B.exponent << 3) +
                APF_Path_Planning_2023a_B.ntIdx1];
            }

            APF_Path_Planning_2023a_B.x_ddot_d[APF_Path_Planning_2023a_B.r_b] +=
              APF_Path_Planning_2023a_B.q *
              APF_Path_Planning_2023a_B.ThrustPer_Final_e[APF_Path_Planning_2023a_B.exponent];
          }

          // End of Product: '<S641>/Product1'
        }

        // DataStoreWrite: '<S641>/BLUE_Fx_Sat' incorporates:
        //   Product: '<S648>/Rotate F_b to F_I'

        APF_Path_Planning_2023a_DW.BLUE_Fx_Sat =
          APF_Path_Planning_2023a_B.rtb_C_Ib_g[0] *
          APF_Path_Planning_2023a_B.x_ddot_d[0] +
          APF_Path_Planning_2023a_B.x_ddot_d[1] *
          APF_Path_Planning_2023a_B.rtb_C_Ib_g[2];

        // DataStoreWrite: '<S641>/BLUE_Fy_Sat' incorporates:
        //   Product: '<S648>/Rotate F_b to F_I'

        APF_Path_Planning_2023a_DW.BLUE_Fy_Sat =
          APF_Path_Planning_2023a_B.x_ddot_d[0] *
          APF_Path_Planning_2023a_B.rtb_C_Ib_g[1] +
          APF_Path_Planning_2023a_B.x_ddot_d[1] *
          APF_Path_Planning_2023a_B.rtb_C_Ib_g[3];

        // DataStoreWrite: '<S641>/BLUE_Tz_Sat'
        APF_Path_Planning_2023a_DW.BLUE_Tz_Sat =
          APF_Path_Planning_2023a_B.x_ddot_d[2];

        // End of Outputs for SubSystem: '<S19>/Change BLUE Behavior'
      }

      // End of If: '<S19>/This IF block determines whether or not to run the BLUE sim//exp' 

      // SignalConversion generated from: '<S19>/UDP Send' incorporates:
      //   Constant: '<S19>/PWM Frequency'
      //   Constant: '<S19>/Safety Number'
      //   Gain: '<S19>/Gain'
      //   Gain: '<S19>/Gain1'
      //   Gain: '<S19>/Gain2'
      //   Gain: '<S19>/Gain3'
      //   Gain: '<S19>/Gain4'
      //   Gain: '<S19>/Gain5'
      //   Gain: '<S19>/Gain6'
      //   Gain: '<S19>/Gain7'
      //   Sum: '<S19>/Sum'
      //   Sum: '<S19>/Sum1'
      //   Sum: '<S19>/Sum2'
      //   Sum: '<S19>/Sum3'
      //   Sum: '<S19>/Sum4'
      //   Sum: '<S19>/Sum5'
      //   Sum: '<S19>/Sum6'
      //   Sum: '<S19>/Sum7'

      APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendInp[0] =
        APF_Path_Planning_2023a_P.SafetyNumber_Value;
      APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendInp[1] =
        APF_Path_Planning_2023a_P.PWMFreq;
      APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendInp[2] =
        ((APF_Path_Planning_2023a_B.ThrustPer_Final[0] +
          APF_Path_Planning_2023a_B.ThrustPer_Final_d[0]) +
         APF_Path_Planning_2023a_B.ThrustPer_Final_e[0]) *
        APF_Path_Planning_2023a_P.Gain_Gain_c;
      APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendInp[3] =
        ((APF_Path_Planning_2023a_B.ThrustPer_Final[1] +
          APF_Path_Planning_2023a_B.ThrustPer_Final_d[1]) +
         APF_Path_Planning_2023a_B.ThrustPer_Final_e[1]) *
        APF_Path_Planning_2023a_P.Gain1_Gain;
      APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendInp[4] =
        ((APF_Path_Planning_2023a_B.ThrustPer_Final[2] +
          APF_Path_Planning_2023a_B.ThrustPer_Final_d[2]) +
         APF_Path_Planning_2023a_B.ThrustPer_Final_e[2]) *
        APF_Path_Planning_2023a_P.Gain2_Gain;
      APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendInp[5] =
        ((APF_Path_Planning_2023a_B.ThrustPer_Final[3] +
          APF_Path_Planning_2023a_B.ThrustPer_Final_d[3]) +
         APF_Path_Planning_2023a_B.ThrustPer_Final_e[3]) *
        APF_Path_Planning_2023a_P.Gain3_Gain;
      APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendInp[6] =
        ((APF_Path_Planning_2023a_B.ThrustPer_Final[4] +
          APF_Path_Planning_2023a_B.ThrustPer_Final_d[4]) +
         APF_Path_Planning_2023a_B.ThrustPer_Final_e[4]) *
        APF_Path_Planning_2023a_P.Gain4_Gain;
      APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendInp[7] =
        ((APF_Path_Planning_2023a_B.ThrustPer_Final[5] +
          APF_Path_Planning_2023a_B.ThrustPer_Final_d[5]) +
         APF_Path_Planning_2023a_B.ThrustPer_Final_e[5]) *
        APF_Path_Planning_2023a_P.Gain5_Gain;
      APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendInp[8] =
        ((APF_Path_Planning_2023a_B.ThrustPer_Final[6] +
          APF_Path_Planning_2023a_B.ThrustPer_Final_d[6]) +
         APF_Path_Planning_2023a_B.ThrustPer_Final_e[6]) *
        APF_Path_Planning_2023a_P.Gain6_Gain;
      APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendInp[9] =
        ((APF_Path_Planning_2023a_B.ThrustPer_Final[7] +
          APF_Path_Planning_2023a_B.ThrustPer_Final_d[7]) +
         APF_Path_Planning_2023a_B.ThrustPer_Final_e[7]) *
        APF_Path_Planning_2023a_P.Gain7_Gain;
    }
  }

  if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
    real_T *lastU;
    char_T *sErr;

    // Update for If: '<Root>/Separate Phases'
    switch (APF_Path_Planning_2023a_DW.SeparatePhases_ActiveSubsystem) {
     case 0:
     case 1:
     case 6:
      break;

     case 2:
      // Update for IfAction SubSystem: '<Root>/Phase #2: Initial Position' incorporates:
      //   ActionPort: '<S8>/Action Port'

      // Update for If: '<S8>/This IF block determines whether or not to run the BLACK sim//exp' 
      if (APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_h2 == 0) {
        // Update for IfAction SubSystem: '<S8>/Change BLACK Behavior' incorporates:
        //   ActionPort: '<S33>/Action Port'

        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          // Update for Delay: '<S42>/Delay1'
          APF_Path_Planning_2023a_DW.icLoad_fp = false;
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_i =
            APF_Path_Planning_2023a_B.Subtract_d;

          // Update for Delay: '<S44>/Delay1'
          APF_Path_Planning_2023a_DW.icLoad_ig = false;
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_c =
            APF_Path_Planning_2023a_B.Subtract1_g;

          // Update for Delay: '<S40>/Delay1'
          APF_Path_Planning_2023a_DW.icLoad_p = false;
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_c1 =
            APF_Path_Planning_2023a_B.e_out_m2;
        }

        // End of Update for SubSystem: '<S8>/Change BLACK Behavior'
      }

      // End of Update for If: '<S8>/This IF block determines whether or not to run the BLACK sim//exp' 

      // Update for If: '<S8>/This IF block determines whether or not to run the BLUE sim//exp' 
      if (APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_l2 == 0) {
        // Update for IfAction SubSystem: '<S8>/Change BLUE Behavior' incorporates:
        //   ActionPort: '<S34>/Action Port'

        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          // Update for Delay: '<S55>/Delay1'
          APF_Path_Planning_2023a_DW.icLoad_o = false;
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_mw =
            APF_Path_Planning_2023a_B.Subtract_n;

          // Update for Delay: '<S57>/Delay1'
          APF_Path_Planning_2023a_DW.icLoad_n = false;
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_et =
            APF_Path_Planning_2023a_B.Subtract1_ld;

          // Update for Delay: '<S53>/Delay1'
          APF_Path_Planning_2023a_DW.icLoad_bb = false;
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_a =
            APF_Path_Planning_2023a_B.e_out_m;
        }

        // End of Update for SubSystem: '<S8>/Change BLUE Behavior'
      }

      // End of Update for If: '<S8>/This IF block determines whether or not to run the BLUE sim//exp' 

      // Update for If: '<S8>/This IF block determines whether or not to run the RED sim//exp ' 
      if (APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_gv == 0) {
        // Update for IfAction SubSystem: '<S8>/Change RED Behavior' incorporates:
        //   ActionPort: '<S35>/Action Port'

        if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
          // Update for Delay: '<S67>/Delay1'
          APF_Path_Planning_2023a_DW.icLoad_g = false;
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_gi =
            APF_Path_Planning_2023a_B.e_out_k;

          // Update for Delay: '<S69>/Delay1'
          APF_Path_Planning_2023a_DW.icLoad_a = false;
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_m =
            APF_Path_Planning_2023a_B.Subtract_j;

          // Update for Delay: '<S71>/Delay1'
          APF_Path_Planning_2023a_DW.icLoad_b = false;
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_ej =
            APF_Path_Planning_2023a_B.Subtract1_n;
        }

        // End of Update for SubSystem: '<S8>/Change RED Behavior'
      }

      // End of Update for If: '<S8>/This IF block determines whether or not to run the RED sim//exp ' 
      // End of Update for SubSystem: '<Root>/Phase #2: Initial Position'
      break;

     case 3:
      // Update for IfAction SubSystem: '<Root>/Phase #3: Experiment' incorporates:
      //   ActionPort: '<S9>/Action Port'

      // Update for If: '<S9>/This IF block determines whether or not to run the BLACK sim//exp' 
      if (APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_n == 0) {
        // Update for IfAction SubSystem: '<S9>/Change BLACK Behavior' incorporates:
        //   ActionPort: '<S87>/Action Port'

        // Update for If: '<S87>/Experiment Sub-Phases'
        switch (APF_Path_Planning_2023a_DW.ExperimentSubPhases_ActiveSub_l) {
         case 0:
          // Update for IfAction SubSystem: '<S87>/Sub-Phase #1' incorporates:
          //   ActionPort: '<S90>/Action Port'

          APF_Path_Plann_SubPhase1_Update(APF_Path_Planning_2023a_M,
            &APF_Path_Planning_2023a_B.SubPhase1,
            &APF_Path_Planning_2023a_DW.SubPhase1);

          // End of Update for SubSystem: '<S87>/Sub-Phase #1'
          break;

         case 1:
          // Update for IfAction SubSystem: '<S87>/Sub-Phase #2 ' incorporates:
          //   ActionPort: '<S91>/Action Port'

          APF_Path_Plann_SubPhase1_Update(APF_Path_Planning_2023a_M,
            &APF_Path_Planning_2023a_B.SubPhase2,
            &APF_Path_Planning_2023a_DW.SubPhase2);

          // End of Update for SubSystem: '<S87>/Sub-Phase #2 '
          break;

         case 2:
          // Update for IfAction SubSystem: '<S87>/Sub-Phase #3 ' incorporates:
          //   ActionPort: '<S92>/Action Port'

          APF_Path_Plann_SubPhase1_Update(APF_Path_Planning_2023a_M,
            &APF_Path_Planning_2023a_B.SubPhase3,
            &APF_Path_Planning_2023a_DW.SubPhase3);

          // End of Update for SubSystem: '<S87>/Sub-Phase #3 '
          break;

         case 3:
          // Update for IfAction SubSystem: '<S87>/Sub-Phase #4' incorporates:
          //   ActionPort: '<S93>/Action Port'

          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // Update for DiscreteIntegrator: '<S149>/Start Pos' incorporates:
            //   Constant: '<S149>/Velocity'

            APF_Path_Planning_2023a_DW.StartPos_DSTATE_p +=
              APF_Path_Planning_2023a_P.StartPos_gainval *
              APF_Path_Planning_2023a_P.BLACK_ini[3];

            // Update for Delay: '<S154>/Delay1'
            APF_Path_Planning_2023a_DW.icLoad_c = false;
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_p =
              APF_Path_Planning_2023a_B.Subtract_k;

            // Update for DiscreteIntegrator: '<S150>/Start Pos' incorporates:
            //   Constant: '<S150>/Velocity'

            APF_Path_Planning_2023a_DW.StartPos_DSTATE_b +=
              APF_Path_Planning_2023a_P.StartPos_gainval_k *
              APF_Path_Planning_2023a_P.BLACK_ini[4];

            // Update for Delay: '<S156>/Delay1'
            APF_Path_Planning_2023a_DW.icLoad_j = false;
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_n =
              APF_Path_Planning_2023a_B.Subtract1_l;

            // Update for DiscreteIntegrator: '<S151>/Start Pos' incorporates:
            //   Constant: '<S151>/Velocity'

            APF_Path_Planning_2023a_DW.StartPos_DSTATE_l4 +=
              APF_Path_Planning_2023a_P.StartPos_gainval_l *
              APF_Path_Planning_2023a_P.BLACK_ini[5];

            // Update for Delay: '<S152>/Delay1'
            APF_Path_Planning_2023a_DW.icLoad_fo = false;
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_p2 =
              APF_Path_Planning_2023a_B.e_out_b;
          }

          // End of Update for SubSystem: '<S87>/Sub-Phase #4'
          break;
        }

        // End of Update for If: '<S87>/Experiment Sub-Phases'
        // End of Update for SubSystem: '<S9>/Change BLACK Behavior'
      }

      // End of Update for If: '<S9>/This IF block determines whether or not to run the BLACK sim//exp' 

      // Update for If: '<S9>/This IF block determines whether or not to run the BLUE sim//exp' 
      if (APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_al == 0) {
        // Update for IfAction SubSystem: '<S9>/Change BLUE Behavior' incorporates:
        //   ActionPort: '<S88>/Action Port'

        // Update for If: '<S88>/Experiment Sub-Phases'
        switch (APF_Path_Planning_2023a_DW.ExperimentSubPhases_ActiveSub_c) {
         case 0:
          // Update for IfAction SubSystem: '<S88>/Sub-Phase #1' incorporates:
          //   ActionPort: '<S161>/Action Port'

          APF_Path_Pla_SubPhase1_f_Update(APF_Path_Planning_2023a_M,
            &APF_Path_Planning_2023a_B.SubPhase1_g,
            &APF_Path_Planning_2023a_DW.SubPhase1_g);

          // End of Update for SubSystem: '<S88>/Sub-Phase #1'
          break;

         case 1:
          // Update for IfAction SubSystem: '<S88>/Sub-Phase #2 ' incorporates:
          //   ActionPort: '<S162>/Action Port'

          APF_Path_Pla_SubPhase1_f_Update(APF_Path_Planning_2023a_M,
            &APF_Path_Planning_2023a_B.SubPhase2_c,
            &APF_Path_Planning_2023a_DW.SubPhase2_c);

          // End of Update for SubSystem: '<S88>/Sub-Phase #2 '
          break;

         case 2:
          // Update for IfAction SubSystem: '<S88>/Sub-Phase #3 ' incorporates:
          //   ActionPort: '<S163>/Action Port'

          APF_Path_Pla_SubPhase1_f_Update(APF_Path_Planning_2023a_M,
            &APF_Path_Planning_2023a_B.SubPhase3_e,
            &APF_Path_Planning_2023a_DW.SubPhase3_e);

          // End of Update for SubSystem: '<S88>/Sub-Phase #3 '
          break;

         case 3:
          // Update for IfAction SubSystem: '<S88>/Sub-Phase #4' incorporates:
          //   ActionPort: '<S164>/Action Port'

          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // Update for DiscreteIntegrator: '<S232>/Start Pos' incorporates:
            //   Constant: '<S232>/Velocity'

            APF_Path_Planning_2023a_DW.StartPos_DSTATE +=
              APF_Path_Planning_2023a_P.StartPos_gainval_i *
              APF_Path_Planning_2023a_P.BLUE_ini[3];

            // Update for Delay: '<S237>/Delay1'
            APF_Path_Planning_2023a_DW.icLoad_d = false;
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_b =
              APF_Path_Planning_2023a_B.Subtract_p;

            // Update for DiscreteIntegrator: '<S233>/Start Pos' incorporates:
            //   Constant: '<S233>/Velocity'

            APF_Path_Planning_2023a_DW.StartPos_DSTATE_j +=
              APF_Path_Planning_2023a_P.StartPos_gainval_j *
              APF_Path_Planning_2023a_P.BLUE_ini[4];

            // Update for Delay: '<S239>/Delay1'
            APF_Path_Planning_2023a_DW.icLoad_d4 = false;
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_e =
              APF_Path_Planning_2023a_B.Subtract1;

            // Update for DiscreteIntegrator: '<S234>/Start Pos' incorporates:
            //   Constant: '<S234>/Velocity'

            APF_Path_Planning_2023a_DW.StartPos_DSTATE_l +=
              APF_Path_Planning_2023a_P.StartPos_gainval_a *
              APF_Path_Planning_2023a_P.BLUE_ini[5];

            // Update for Delay: '<S235>/Delay1'
            APF_Path_Planning_2023a_DW.icLoad_l = false;
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_do =
              APF_Path_Planning_2023a_B.e_out_pv;
          }

          // End of Update for SubSystem: '<S88>/Sub-Phase #4'
          break;
        }

        // End of Update for If: '<S88>/Experiment Sub-Phases'
        // End of Update for SubSystem: '<S9>/Change BLUE Behavior'
      }

      // End of Update for If: '<S9>/This IF block determines whether or not to run the BLUE sim//exp' 

      // Update for If: '<S9>/This IF block determines whether or not to run the RED sim//exp ' 
      if (APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_fg == 0) {
        // Update for IfAction SubSystem: '<S9>/Change RED Behavior' incorporates:
        //   ActionPort: '<S89>/Action Port'

        // Update for If: '<S89>/Experiment Sub-Phases'
        switch (APF_Path_Planning_2023a_DW.ExperimentSubPhases_ActiveSubsy) {
         case 0:
          // Update for IfAction SubSystem: '<S89>/Sub-Phase #1' incorporates:
          //   ActionPort: '<S244>/Action Port'

          APF_Path_Pla_SubPhase1_e_Update(APF_Path_Planning_2023a_M,
            &APF_Path_Planning_2023a_B.SubPhase1_p,
            &APF_Path_Planning_2023a_DW.SubPhase1_p);

          // End of Update for SubSystem: '<S89>/Sub-Phase #1'
          break;

         case 1:
          // Update for IfAction SubSystem: '<S89>/Sub-Phase #2 ' incorporates:
          //   ActionPort: '<S245>/Action Port'

          APF_Path_Pla_SubPhase1_e_Update(APF_Path_Planning_2023a_M,
            &APF_Path_Planning_2023a_B.SubPhase2_p,
            &APF_Path_Planning_2023a_DW.SubPhase2_p);

          // End of Update for SubSystem: '<S89>/Sub-Phase #2 '
          break;

         case 2:
          // Update for IfAction SubSystem: '<S89>/Sub-Phase #3 ' incorporates:
          //   ActionPort: '<S246>/Action Port'

          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // Update for Delay: '<S323>/Delay1'
            APF_Path_Planning_2023a_DW.icLoad = false;
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_da =
              APF_Path_Planning_2023a_B.e_out_p;

            // Update for Delay: '<S325>/Delay1'
            APF_Path_Planning_2023a_DW.icLoad_f = false;
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_d3 =
              APF_Path_Planning_2023a_B.Subtract;

            // Update for Delay: '<S327>/Delay1'
            APF_Path_Planning_2023a_DW.icLoad_i = false;
            APF_Path_Planning_2023a_DW.Delay1_DSTATE_g =
              APF_Path_Planning_2023a_B.Subtract2;
          }

          // End of Update for SubSystem: '<S89>/Sub-Phase #3 '
          break;

         case 3:
          // Update for IfAction SubSystem: '<S89>/Sub-Phase #4' incorporates:
          //   ActionPort: '<S247>/Action Port'

          // Update for If: '<S350>/If'
          if (APF_Path_Planning_2023a_DW.If_ActiveSubsystem == 0) {
            // Update for IfAction SubSystem: '<S350>/APF' incorporates:
            //   ActionPort: '<S368>/Action Port'

            if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
              // Update for Delay: '<S381>/Delay'
              APF_Path_Planning_2023a_DW.Delay_DSTATE_c[0] =
                APF_Path_Planning_2023a_B.Sum3[0];

              // Update for Delay: '<S382>/Delay' incorporates:
              //   Sum: '<S382>/Sum'

              APF_Path_Planning_2023a_DW.Delay_DSTATE_o[0] =
                APF_Path_Planning_2023a_B.Sum_n[0];

              // Update for Delay: '<S377>/Delay3'
              APF_Path_Planning_2023a_DW.Delay3_DSTATE[0] =
                APF_Path_Planning_2023a_B.Gt[0];

              // Update for Delay: '<S376>/Delay'
              APF_Path_Planning_2023a_DW.Delay_DSTATE_d[0] =
                APF_Path_Planning_2023a_B.Eg_n[0];

              // Update for Delay: '<S376>/Delay1'
              APF_Path_Planning_2023a_DW.Delay1_DSTATE[0] =
                APF_Path_Planning_2023a_B.Etheta[0];

              // Update for Delay: '<S383>/Delay3'
              APF_Path_Planning_2023a_DW.Delay3_DSTATE_d[0] =
                APF_Path_Planning_2023a_B.Eg[0];

              // Update for Delay: '<S379>/Delay3'
              APF_Path_Planning_2023a_DW.Delay3_DSTATE_a[0] =
                APF_Path_Planning_2023a_B.m[0];

              // Update for Delay: '<S379>/Delay1'
              APF_Path_Planning_2023a_DW.Delay1_DSTATE_d[0] =
                APF_Path_Planning_2023a_B.v[0];

              // Update for Delay: '<S378>/Delay3'
              APF_Path_Planning_2023a_DW.Delay3_DSTATE_j[0] =
                APF_Path_Planning_2023a_B.m_b[0];

              // Update for Delay: '<S381>/Delay'
              APF_Path_Planning_2023a_DW.Delay_DSTATE_c[1] =
                APF_Path_Planning_2023a_B.Sum3[1];

              // Update for Delay: '<S382>/Delay' incorporates:
              //   Sum: '<S382>/Sum'

              APF_Path_Planning_2023a_DW.Delay_DSTATE_o[1] =
                APF_Path_Planning_2023a_B.Sum_n[1];

              // Update for Delay: '<S377>/Delay3'
              APF_Path_Planning_2023a_DW.Delay3_DSTATE[1] =
                APF_Path_Planning_2023a_B.Gt[1];

              // Update for Delay: '<S376>/Delay'
              APF_Path_Planning_2023a_DW.Delay_DSTATE_d[1] =
                APF_Path_Planning_2023a_B.Eg_n[1];

              // Update for Delay: '<S376>/Delay1'
              APF_Path_Planning_2023a_DW.Delay1_DSTATE[1] =
                APF_Path_Planning_2023a_B.Etheta[1];

              // Update for Delay: '<S383>/Delay3'
              APF_Path_Planning_2023a_DW.Delay3_DSTATE_d[1] =
                APF_Path_Planning_2023a_B.Eg[1];

              // Update for Delay: '<S379>/Delay3'
              APF_Path_Planning_2023a_DW.Delay3_DSTATE_a[1] =
                APF_Path_Planning_2023a_B.m[1];

              // Update for Delay: '<S379>/Delay1'
              APF_Path_Planning_2023a_DW.Delay1_DSTATE_d[1] =
                APF_Path_Planning_2023a_B.v[1];

              // Update for Delay: '<S378>/Delay3'
              APF_Path_Planning_2023a_DW.Delay3_DSTATE_j[1] =
                APF_Path_Planning_2023a_B.m_b[1];

              // Update for Delay: '<S381>/Delay'
              APF_Path_Planning_2023a_DW.Delay_DSTATE_c[2] =
                APF_Path_Planning_2023a_B.Sum3[2];

              // Update for Delay: '<S382>/Delay' incorporates:
              //   Sum: '<S382>/Sum'

              APF_Path_Planning_2023a_DW.Delay_DSTATE_o[2] =
                APF_Path_Planning_2023a_B.Sum_n[2];

              // Update for Delay: '<S377>/Delay3'
              APF_Path_Planning_2023a_DW.Delay3_DSTATE[2] =
                APF_Path_Planning_2023a_B.Gt[2];

              // Update for Delay: '<S376>/Delay'
              APF_Path_Planning_2023a_DW.Delay_DSTATE_d[2] =
                APF_Path_Planning_2023a_B.Eg_n[2];

              // Update for Delay: '<S376>/Delay1'
              APF_Path_Planning_2023a_DW.Delay1_DSTATE[2] =
                APF_Path_Planning_2023a_B.Etheta[2];

              // Update for Delay: '<S383>/Delay3'
              APF_Path_Planning_2023a_DW.Delay3_DSTATE_d[2] =
                APF_Path_Planning_2023a_B.Eg[2];

              // Update for Delay: '<S379>/Delay3'
              APF_Path_Planning_2023a_DW.Delay3_DSTATE_a[2] =
                APF_Path_Planning_2023a_B.m[2];

              // Update for Delay: '<S379>/Delay1'
              APF_Path_Planning_2023a_DW.Delay1_DSTATE_d[2] =
                APF_Path_Planning_2023a_B.v[2];

              // Update for Delay: '<S378>/Delay3'
              APF_Path_Planning_2023a_DW.Delay3_DSTATE_j[2] =
                APF_Path_Planning_2023a_B.m_b[2];

              // Update for Delay: '<S378>/Delay1'
              APF_Path_Planning_2023a_DW.Delay1_DSTATE_l =
                APF_Path_Planning_2023a_B.v_d;
            }

            // End of Update for SubSystem: '<S350>/APF'
          }

          // End of Update for If: '<S350>/If'

          // Update for If: '<S349>/If'
          if (APF_Path_Planning_2023a_DW.If_ActiveSubsystem_m == 0) {
            // Update for IfAction SubSystem: '<S349>/If Action Subsystem' incorporates:
            //   ActionPort: '<S354>/Action Port'

            // Update for Derivative: '<S360>/Derivative2'
            if (APF_Path_Planning_2023a_DW.TimeStampA == (rtInf)) {
              APF_Path_Planning_2023a_DW.TimeStampA =
                APF_Path_Planning_2023a_M->Timing.t[0];
              lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeA;
            } else if (APF_Path_Planning_2023a_DW.TimeStampB == (rtInf)) {
              APF_Path_Planning_2023a_DW.TimeStampB =
                APF_Path_Planning_2023a_M->Timing.t[0];
              lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeB;
            } else if (APF_Path_Planning_2023a_DW.TimeStampA <
                       APF_Path_Planning_2023a_DW.TimeStampB) {
              APF_Path_Planning_2023a_DW.TimeStampA =
                APF_Path_Planning_2023a_M->Timing.t[0];
              lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeA;
            } else {
              APF_Path_Planning_2023a_DW.TimeStampB =
                APF_Path_Planning_2023a_M->Timing.t[0];
              lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeB;
            }

            *lastU = APF_Path_Planning_2023a_B.Sum;

            // End of Update for Derivative: '<S360>/Derivative2'
            if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
              // Update for DiscreteIntegrator: '<S360>/Discrete-Time Integrator4' 
              APF_Path_Planning_2023a_DW.DiscreteTimeIntegrator4_DSTATE +=
                APF_Path_Planning_2023a_P.DiscreteTimeIntegrator4_gainval *
                APF_Path_Planning_2023a_B.k2_dot_ch;

              // Update for DiscreteIntegrator: '<S360>/Discrete-Time Integrator5' 
              APF_Path_Planning_2023a_DW.DiscreteTimeIntegrator5_DSTATE +=
                APF_Path_Planning_2023a_P.DiscreteTimeIntegrator5_gainval *
                APF_Path_Planning_2023a_B.k1_dot_o;
            }

            // Update for Derivative: '<S360>/Derivative1'
            if (APF_Path_Planning_2023a_DW.TimeStampA_i == (rtInf)) {
              APF_Path_Planning_2023a_DW.TimeStampA_i =
                APF_Path_Planning_2023a_M->Timing.t[0];
              lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeA_h;
            } else if (APF_Path_Planning_2023a_DW.TimeStampB_p == (rtInf)) {
              APF_Path_Planning_2023a_DW.TimeStampB_p =
                APF_Path_Planning_2023a_M->Timing.t[0];
              lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeB_o;
            } else if (APF_Path_Planning_2023a_DW.TimeStampA_i <
                       APF_Path_Planning_2023a_DW.TimeStampB_p) {
              APF_Path_Planning_2023a_DW.TimeStampA_i =
                APF_Path_Planning_2023a_M->Timing.t[0];
              lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeA_h;
            } else {
              APF_Path_Planning_2023a_DW.TimeStampB_p =
                APF_Path_Planning_2023a_M->Timing.t[0];
              lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeB_o;
            }

            *lastU = APF_Path_Planning_2023a_B.Sum1;

            // End of Update for Derivative: '<S360>/Derivative1'
            if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
              // Update for DiscreteIntegrator: '<S360>/Discrete-Time Integrator2' 
              APF_Path_Planning_2023a_DW.DiscreteTimeIntegrator2_DSTATE +=
                APF_Path_Planning_2023a_P.DiscreteTimeIntegrator2_gainval *
                APF_Path_Planning_2023a_B.k2_dot_c;

              // Update for DiscreteIntegrator: '<S360>/Discrete-Time Integrator3' 
              APF_Path_Planning_2023a_DW.DiscreteTimeIntegrator3_DSTATE +=
                APF_Path_Planning_2023a_P.DiscreteTimeIntegrator3_gainval *
                APF_Path_Planning_2023a_B.k1_dot_g;

              // Update for DiscreteIntegrator: '<S360>/Discrete-Time Integrator1' 
              APF_Path_Planning_2023a_DW.DiscreteTimeIntegrator1_DSTATE +=
                APF_Path_Planning_2023a_P.DiscreteTimeIntegrator1_gainval *
                APF_Path_Planning_2023a_B.k1_dot;

              // Update for DiscreteIntegrator: '<S360>/Discrete-Time Integrator' 
              APF_Path_Planning_2023a_DW.DiscreteTimeIntegrator_DSTATE +=
                APF_Path_Planning_2023a_P.DiscreteTimeIntegrator_gainval *
                APF_Path_Planning_2023a_B.k2_dot;
            }

            // Update for Derivative: '<S360>/Derivative3'
            if (APF_Path_Planning_2023a_DW.TimeStampA_h == (rtInf)) {
              APF_Path_Planning_2023a_DW.TimeStampA_h =
                APF_Path_Planning_2023a_M->Timing.t[0];
              lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeA_c;
            } else if (APF_Path_Planning_2023a_DW.TimeStampB_e == (rtInf)) {
              APF_Path_Planning_2023a_DW.TimeStampB_e =
                APF_Path_Planning_2023a_M->Timing.t[0];
              lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeB_f;
            } else if (APF_Path_Planning_2023a_DW.TimeStampA_h <
                       APF_Path_Planning_2023a_DW.TimeStampB_e) {
              APF_Path_Planning_2023a_DW.TimeStampA_h =
                APF_Path_Planning_2023a_M->Timing.t[0];
              lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeA_c;
            } else {
              APF_Path_Planning_2023a_DW.TimeStampB_e =
                APF_Path_Planning_2023a_M->Timing.t[0];
              lastU = &APF_Path_Planning_2023a_DW.LastUAtTimeB_f;
            }

            *lastU = APF_Path_Planning_2023a_B.e_out;

            // End of Update for Derivative: '<S360>/Derivative3'
            // End of Update for SubSystem: '<S349>/If Action Subsystem'
          }

          // End of Update for If: '<S349>/If'
          if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
            // Update for Delay: '<S369>/Delay'
            APF_Path_Planning_2023a_DW.Delay_DSTATE =
              APF_Path_Planning_2023a_B.k;
          }

          // End of Update for SubSystem: '<S89>/Sub-Phase #4'
          break;
        }

        // End of Update for If: '<S89>/Experiment Sub-Phases'
        // End of Update for SubSystem: '<S9>/Change RED Behavior'
      }

      // End of Update for If: '<S9>/This IF block determines whether or not to run the RED sim//exp ' 
      // End of Update for SubSystem: '<Root>/Phase #3: Experiment'
      break;

     case 4:
      // Update for IfAction SubSystem: '<Root>/Phase #4: Return Home' incorporates:
      //   ActionPort: '<S10>/Action Port'

      APF_Pat_Phase4ReturnHome_Update(APF_Path_Planning_2023a_M,
        &APF_Path_Planning_2023a_B.Phase4ReturnHome,
        &APF_Path_Planning_2023a_DW.Phase4ReturnHome);

      // End of Update for SubSystem: '<Root>/Phase #4: Return Home'
      break;

     case 5:
      // Update for IfAction SubSystem: '<Root>/Phase #5: Hold Home' incorporates:
      //   ActionPort: '<S11>/Action Port'

      APF_Pat_Phase4ReturnHome_Update(APF_Path_Planning_2023a_M,
        &APF_Path_Planning_2023a_B.Phase5HoldHome,
        &APF_Path_Planning_2023a_DW.Phase5HoldHome);

      // End of Update for SubSystem: '<Root>/Phase #5: Hold Home'
      break;
    }

    // End of Update for If: '<Root>/Separate Phases'

    // Update for If: '<S13>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 
    if (APF_Path_Planning_2023a_DW.Ifperforminganexperimentgrabthe == 0) {
      // Update for IfAction SubSystem: '<S13>/Use Hardware to Obtain States' incorporates:
      //   ActionPort: '<S524>/Action Port'

      if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
        // Update for Delay: '<S534>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_lu = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_eo =
          APF_Path_Planning_2023a_B.ConvertBLUXfrommmtom;

        // Update for Delay: '<S531>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_ld = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_gs =
          APF_Path_Planning_2023a_B.dividebydeltaT;

        // Update for Delay: '<S539>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_dc = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_bm =
          APF_Path_Planning_2023a_B.ConvertBLAXfrommmtom;

        // Update for Delay: '<S528>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_k = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_p4 =
          APF_Path_Planning_2023a_B.dividebydeltaT_f;

        // Update for Delay: '<S540>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_fv = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_md =
          APF_Path_Planning_2023a_B.ConvertBLAYfrommmtom;

        // Update for Delay: '<S529>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_na = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_j =
          APF_Path_Planning_2023a_B.dividebydeltaT_l;

        // Update for Delay: '<S541>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_gx = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_p4s =
          APF_Path_Planning_2023a_B.Unwrap1;

        // Update for Delay: '<S530>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_m = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_k =
          APF_Path_Planning_2023a_B.dividebydeltaT_e;

        // Update for Delay: '<S535>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_e = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_mi =
          APF_Path_Planning_2023a_B.ConvertBLUYfrommmtom;

        // Update for Delay: '<S532>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_fpv = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_pc =
          APF_Path_Planning_2023a_B.dividebydeltaT_c;

        // Update for Delay: '<S536>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_mt = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_cu =
          APF_Path_Planning_2023a_B.Unwrap2;

        // Update for Delay: '<S533>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_nw = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_a0 =
          APF_Path_Planning_2023a_B.dividebydeltaT_cy;

        // Update for Delay: '<S527>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_h = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_h =
          APF_Path_Planning_2023a_B.ConvertREDXfrommmtom;

        // Update for Delay: '<S542>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_au = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_ah =
          APF_Path_Planning_2023a_B.dividebydeltaT_n;

        // Update for Delay: '<S537>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_eo = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_lx =
          APF_Path_Planning_2023a_B.ConvertREDYfrommmtom;

        // Update for Delay: '<S543>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_fh = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_j3 =
          APF_Path_Planning_2023a_B.dividebydeltaT_n1;

        // Update for Delay: '<S538>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_fow = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_m2 =
          APF_Path_Planning_2023a_B.Unwrap;

        // Update for Delay: '<S544>/Delay1'
        APF_Path_Planning_2023a_DW.icLoad_aq = false;
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_hi =
          APF_Path_Planning_2023a_B.dividebydeltaT_m;

        // Update for Delay: '<S524>/Delay'
        APF_Path_Planning_2023a_DW.Delay_DSTATE_l[0] =
          APF_Path_Planning_2023a_DW.Delay_DSTATE_l[1];

        // Update for Delay: '<S524>/Delay1'
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_hu[0] =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_hu[1];

        // Update for Delay: '<S524>/Delay2'
        APF_Path_Planning_2023a_DW.Delay2_DSTATE_k[0] =
          APF_Path_Planning_2023a_DW.Delay2_DSTATE_k[1];

        // Update for Delay: '<S524>/Delay'
        APF_Path_Planning_2023a_DW.Delay_DSTATE_l[1] =
          APF_Path_Planning_2023a_DW.Delay_DSTATE_l[2];

        // Update for Delay: '<S524>/Delay1'
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_hu[1] =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_hu[2];

        // Update for Delay: '<S524>/Delay2'
        APF_Path_Planning_2023a_DW.Delay2_DSTATE_k[1] =
          APF_Path_Planning_2023a_DW.Delay2_DSTATE_k[2];

        // Update for Delay: '<S524>/Delay'
        APF_Path_Planning_2023a_DW.Delay_DSTATE_l[2] =
          APF_Path_Planning_2023a_DW.Delay_DSTATE_l[3];

        // Update for Delay: '<S524>/Delay1'
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_hu[2] =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_hu[3];

        // Update for Delay: '<S524>/Delay2'
        APF_Path_Planning_2023a_DW.Delay2_DSTATE_k[2] =
          APF_Path_Planning_2023a_DW.Delay2_DSTATE_k[3];

        // Update for Delay: '<S524>/Delay'
        APF_Path_Planning_2023a_DW.Delay_DSTATE_l[3] =
          APF_Path_Planning_2023a_DW.Delay_DSTATE_l[4];

        // Update for Delay: '<S524>/Delay1'
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_hu[3] =
          APF_Path_Planning_2023a_DW.Delay1_DSTATE_hu[4];

        // Update for Delay: '<S524>/Delay2'
        APF_Path_Planning_2023a_DW.Delay2_DSTATE_k[3] =
          APF_Path_Planning_2023a_DW.Delay2_DSTATE_k[4];

        // Update for Delay: '<S524>/Delay'
        APF_Path_Planning_2023a_DW.Delay_DSTATE_l[4] =
          APF_Path_Planning_2023a_B.UDPReceive_o1;

        // Update for Delay: '<S524>/Delay1'
        APF_Path_Planning_2023a_DW.Delay1_DSTATE_hu[4] =
          APF_Path_Planning_2023a_B.UDPReceive2_o1;

        // Update for Delay: '<S524>/Delay2'
        APF_Path_Planning_2023a_DW.Delay2_DSTATE_k[4] =
          APF_Path_Planning_2023a_B.UDPReceive3_o1;
      }

      // End of Update for SubSystem: '<S13>/Use Hardware to Obtain States'
    }

    // End of Update for If: '<S13>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 
    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      // Update for S-Function (sdspToNetwork): '<S19>/UDP Send' incorporates:
      //   SignalConversion generated from: '<S19>/UDP Send'

      sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib[0U]);
      LibUpdate_Network(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib[0U],
                        &APF_Path_Planning_2023a_B.TmpSignalConversionAtUDPSendInp
                        [0U], 10);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
      }

      // End of Update for S-Function (sdspToNetwork): '<S19>/UDP Send'
    }

    // ContTimeOutputInconsistentWithStateAtMajorOutputFlag is set, need to run a minor output 
    if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
      if (rtsiGetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo)) {
        rtsiSetSimTimeStep(&APF_Path_Planning_2023a_M->solverInfo,
                           MINOR_TIME_STEP);
        rtsiSetContTimeOutputInconsistentWithStateAtMajorStep
          (&APF_Path_Planning_2023a_M->solverInfo, false);
        APF_Path_Planning_2023a_step();
        rtsiSetSimTimeStep(&APF_Path_Planning_2023a_M->solverInfo,
                           MAJOR_TIME_STEP);
      }
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(APF_Path_Planning_2023a_M)) {
    rt_ertODEUpdateContinuousStates(&APF_Path_Planning_2023a_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++APF_Path_Planning_2023a_M->Timing.clockTick0;
    APF_Path_Planning_2023a_M->Timing.t[0] = rtsiGetSolverStopTime
      (&APF_Path_Planning_2023a_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.01s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.01, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      APF_Path_Planning_2023a_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void APF_Path_Planning_2023a_derivatives(void)
{
  XDot_APF_Path_Planning_2023a_T *_rtXdot;
  _rtXdot = ((XDot_APF_Path_Planning_2023a_T *)
             APF_Path_Planning_2023a_M->derivs);

  // Derivatives for If: '<Root>/Separate Phases'
  {
    real_T *dx;
    int_T i;
    dx = &(((XDot_APF_Path_Planning_2023a_T *) APF_Path_Planning_2023a_M->derivs)
           ->TargetFinder.PseudoDerivative_CSTATE);
    for (i=0; i < 6; i++) {
      dx[i] = 0.0;
    }
  }

  if (APF_Path_Planning_2023a_DW.SeparatePhases_ActiveSubsystem == 3) {
    // Derivatives for IfAction SubSystem: '<Root>/Phase #3: Experiment' incorporates:
    //   ActionPort: '<S9>/Action Port'

    // Derivatives for If: '<S9>/This IF block determines whether or not to run the RED sim//exp ' 
    {
      real_T *dx;
      int_T i;
      dx = &(((XDot_APF_Path_Planning_2023a_T *)
              APF_Path_Planning_2023a_M->derivs)
             ->TargetFinder.PseudoDerivative_CSTATE);
      for (i=0; i < 6; i++) {
        dx[i] = 0.0;
      }
    }

    if (APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_fg == 0) {
      // Derivatives for IfAction SubSystem: '<S9>/Change RED Behavior' incorporates:
      //   ActionPort: '<S89>/Action Port'

      // Derivatives for If: '<S89>/Experiment Sub-Phases'
      {
        real_T *dx;
        int_T i;
        dx = &(((XDot_APF_Path_Planning_2023a_T *)
                APF_Path_Planning_2023a_M->derivs)
               ->TargetFinder.PseudoDerivative_CSTATE);
        for (i=0; i < 6; i++) {
          dx[i] = 0.0;
        }
      }

      if (APF_Path_Planning_2023a_DW.ExperimentSubPhases_ActiveSubsy == 3) {
        // Derivatives for IfAction SubSystem: '<S89>/Sub-Phase #4' incorporates:
        //   ActionPort: '<S247>/Action Port'

        // Derivatives for If: '<S349>/If2'
        {
          real_T *dx;
          int_T i;
          dx = &(((XDot_APF_Path_Planning_2023a_T *)
                  APF_Path_Planning_2023a_M->derivs)
                 ->TargetFinder.PseudoDerivative_CSTATE);
          for (i=0; i < 3; i++) {
            dx[i] = 0.0;
          }
        }

        if (APF_Path_Planning_2023a_DW.If2_ActiveSubsystem_m == 0) {
          // Derivatives for IfAction SubSystem: '<S349>/Target Finder' incorporates:
          //   ActionPort: '<S355>/Action Port'

          APF_Path_Pl_TargetTracker_Deriv(APF_Path_Planning_2023a_B.Sum,
            APF_Path_Planning_2023a_B.Sum1, APF_Path_Planning_2023a_B.e_out,
            &APF_Path_Planning_2023a_P.TargetFinder,
            &APF_Path_Planning_2023a_X.TargetFinder, &_rtXdot->TargetFinder);

          // End of Derivatives for SubSystem: '<S349>/Target Finder'
        }

        // End of Derivatives for If: '<S349>/If2'

        // Derivatives for If: '<S349>/If1'
        {
          real_T *dx;
          int_T i;
          dx = &(((XDot_APF_Path_Planning_2023a_T *)
                  APF_Path_Planning_2023a_M->derivs)
                 ->TargetTracker.PseudoDerivative_CSTATE);
          for (i=0; i < 3; i++) {
            dx[i] = 0.0;
          }
        }

        if (APF_Path_Planning_2023a_DW.If1_ActiveSubsystem_a == 0) {
          // Derivatives for IfAction SubSystem: '<S349>/Target Tracker' incorporates:
          //   ActionPort: '<S356>/Action Port'

          APF_Path_Pl_TargetTracker_Deriv(APF_Path_Planning_2023a_B.Sum,
            APF_Path_Planning_2023a_B.Sum1, APF_Path_Planning_2023a_B.e_out,
            &APF_Path_Planning_2023a_P.TargetTracker,
            &APF_Path_Planning_2023a_X.TargetTracker, &_rtXdot->TargetTracker);

          // End of Derivatives for SubSystem: '<S349>/Target Tracker'
        }

        // End of Derivatives for If: '<S349>/If1'
        // End of Derivatives for SubSystem: '<S89>/Sub-Phase #4'
      }

      // End of Derivatives for If: '<S89>/Experiment Sub-Phases'
      // End of Derivatives for SubSystem: '<S9>/Change RED Behavior'
    }

    // End of Derivatives for If: '<S9>/This IF block determines whether or not to run the RED sim//exp ' 
    // End of Derivatives for SubSystem: '<Root>/Phase #3: Experiment'
  }

  // End of Derivatives for If: '<Root>/Separate Phases'
}

// Model initialize function
void APF_Path_Planning_2023a_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&APF_Path_Planning_2023a_M->solverInfo,
                          &APF_Path_Planning_2023a_M->Timing.simTimeStep);
    rtsiSetTPtr(&APF_Path_Planning_2023a_M->solverInfo, &rtmGetTPtr
                (APF_Path_Planning_2023a_M));
    rtsiSetStepSizePtr(&APF_Path_Planning_2023a_M->solverInfo,
                       &APF_Path_Planning_2023a_M->Timing.stepSize0);
    rtsiSetdXPtr(&APF_Path_Planning_2023a_M->solverInfo,
                 &APF_Path_Planning_2023a_M->derivs);
    rtsiSetContStatesPtr(&APF_Path_Planning_2023a_M->solverInfo, (real_T **)
                         &APF_Path_Planning_2023a_M->contStates);
    rtsiSetNumContStatesPtr(&APF_Path_Planning_2023a_M->solverInfo,
      &APF_Path_Planning_2023a_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&APF_Path_Planning_2023a_M->solverInfo,
      &APF_Path_Planning_2023a_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&APF_Path_Planning_2023a_M->solverInfo,
      &APF_Path_Planning_2023a_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&APF_Path_Planning_2023a_M->solverInfo,
      &APF_Path_Planning_2023a_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&APF_Path_Planning_2023a_M->solverInfo,
                          (&rtmGetErrorStatus(APF_Path_Planning_2023a_M)));
    rtsiSetRTModelPtr(&APF_Path_Planning_2023a_M->solverInfo,
                      APF_Path_Planning_2023a_M);
  }

  rtsiSetSimTimeStep(&APF_Path_Planning_2023a_M->solverInfo, MAJOR_TIME_STEP);
  APF_Path_Planning_2023a_M->intgData.y = APF_Path_Planning_2023a_M->odeY;
  APF_Path_Planning_2023a_M->intgData.f[0] = APF_Path_Planning_2023a_M->odeF[0];
  APF_Path_Planning_2023a_M->intgData.f[1] = APF_Path_Planning_2023a_M->odeF[1];
  APF_Path_Planning_2023a_M->intgData.f[2] = APF_Path_Planning_2023a_M->odeF[2];
  APF_Path_Planning_2023a_M->intgData.f[3] = APF_Path_Planning_2023a_M->odeF[3];
  APF_Path_Planning_2023a_M->contStates = ((X_APF_Path_Planning_2023a_T *)
    &APF_Path_Planning_2023a_X);
  rtsiSetSolverData(&APF_Path_Planning_2023a_M->solverInfo, static_cast<void *>(
    &APF_Path_Planning_2023a_M->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&APF_Path_Planning_2023a_M->solverInfo,
    false);
  rtsiSetSolverName(&APF_Path_Planning_2023a_M->solverInfo,"ode4");
  rtmSetTPtr(APF_Path_Planning_2023a_M,
             &APF_Path_Planning_2023a_M->Timing.tArray[0]);
  APF_Path_Planning_2023a_M->Timing.stepSize0 = 0.01;

  {
    real_T sampleTime;
    real_T sampleTime_0;
    real_T sampleTime_1;
    real_T tmp;
    int32_T i;
    int32_T t;
    uint32_T tseed;
    char_T *sErr;

    // Start for S-Function (sdspFromNetwork): '<S2>/UDP Receive1'
    sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib[0U]);
    CreateUDPInterface(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib[0U],
                        0, "0.0.0.0",
                        APF_Path_Planning_2023a_P.UDPReceive1_Port_f, "0.0.0.0",
                        -1, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S2>/UDP Receive1'

    // Start for If: '<Root>/Separate Phases'
    APF_Path_Planning_2023a_DW.SeparatePhases_ActiveSubsystem = -1;

    // Start for If: '<Root>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 
    APF_Path_Planning_2023a_DW.IfsimModesetto1thenthisisasimul = -1;

    // Start for If: '<S1>/This IF block determines whether or not to run the BLACK sim//exp' 
    APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhetherorn = -1;

    // Start for If: '<S1>/This IF block determines whether or not to run the BLUE sim//exp' 
    APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_j = -1;

    // Start for If: '<S1>/This IF block determines whether or not to run the RED sim//exp ' 
    APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_o = -1;

    // Start for If: '<S4>/This IF block determines whether or not to run the exp code' 
    APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_d = -1;

    // Start for If: '<S5>/This IF block determines whether or not to run the RED sim//exp ' 
    APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_a = -1;

    // Start for If: '<S13>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 
    APF_Path_Planning_2023a_DW.Ifperforminganexperimentgrabthe = -1;

    // Start for If: '<S14>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 
    APF_Path_Planning_2023a_DW.IfsimModesetto1thenthisisasim_f = -1;

    // Start for If: '<S15>/This IF block determines whether or not to run the RED sim//exp ' 
    APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_g = -1;

    // Start for If: '<S16>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 
    APF_Path_Planning_2023a_DW.IfsimModesetto1thenthisisasim_h = -1;

    // Start for If: '<S19>/This IF block determines whether or not to run the RED sim//exp ' 
    APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_p = -1;

    // Start for If: '<S19>/This IF block determines whether or not to run the BLACK sim//exp' 
    APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_am = -1;

    // Start for If: '<S19>/This IF block determines whether or not to run the BLUE sim//exp' 
    APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_h = -1;

    // Start for S-Function (sdspToNetwork): '<S19>/UDP Send'
    sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib[0U]);
    CreateUDPInterface(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib[0U], 1,
                        "0.0.0.0", -1, "127.0.0.1",
                        APF_Path_Planning_2023a_P.UDPSend_Port_d5, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S19>/UDP Send'

    // Start for DataStoreMemory: '<Root>/BLACK_Fx'
    APF_Path_Planning_2023a_DW.BLACK_Fx =
      APF_Path_Planning_2023a_P.BLACK_Fx_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Fx1'
    APF_Path_Planning_2023a_DW.BLUE_Fx =
      APF_Path_Planning_2023a_P.BLACK_Fx1_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Fx_Sat'
    APF_Path_Planning_2023a_DW.BLACK_Fx_Sat =
      APF_Path_Planning_2023a_P.BLACK_Fx_Sat_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Fx_Sat2'
    APF_Path_Planning_2023a_DW.BLUE_Fx_Sat =
      APF_Path_Planning_2023a_P.BLACK_Fx_Sat2_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Fy'
    APF_Path_Planning_2023a_DW.BLACK_Fy =
      APF_Path_Planning_2023a_P.BLACK_Fy_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Fy1'
    APF_Path_Planning_2023a_DW.BLUE_Fy =
      APF_Path_Planning_2023a_P.BLACK_Fy1_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Fy_Sat'
    APF_Path_Planning_2023a_DW.BLACK_Fy_Sat =
      APF_Path_Planning_2023a_P.BLACK_Fy_Sat_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Fy_Sat2'
    APF_Path_Planning_2023a_DW.BLUE_Fy_Sat =
      APF_Path_Planning_2023a_P.BLACK_Fy_Sat2_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Px'
    APF_Path_Planning_2023a_DW.BLACK_Px =
      APF_Path_Planning_2023a_P.BLACK_Px_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Px1'
    APF_Path_Planning_2023a_DW.BLUE_Px =
      APF_Path_Planning_2023a_P.BLACK_Px1_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Px2'
    APF_Path_Planning_2023a_DW.BLACK_Px_Est =
      APF_Path_Planning_2023a_P.BLACK_Px2_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Px3'
    APF_Path_Planning_2023a_DW.BLACK_Px_preKalm =
      APF_Path_Planning_2023a_P.BLACK_Px3_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Py'
    APF_Path_Planning_2023a_DW.BLACK_Py =
      APF_Path_Planning_2023a_P.BLACK_Py_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Py1'
    APF_Path_Planning_2023a_DW.BLUE_Py =
      APF_Path_Planning_2023a_P.BLACK_Py1_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Py2'
    APF_Path_Planning_2023a_DW.BLACK_Py_Est =
      APF_Path_Planning_2023a_P.BLACK_Py2_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Py3'
    APF_Path_Planning_2023a_DW.BLACK_Py_preKalm =
      APF_Path_Planning_2023a_P.BLACK_Py3_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Rz'
    APF_Path_Planning_2023a_DW.BLACK_Rz =
      APF_Path_Planning_2023a_P.BLACK_Rz_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Rz1'
    APF_Path_Planning_2023a_DW.BLUE_Rz =
      APF_Path_Planning_2023a_P.BLACK_Rz1_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Rz2'
    APF_Path_Planning_2023a_DW.BLACK_Rz_Est =
      APF_Path_Planning_2023a_P.BLACK_Rz2_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Rz3'
    APF_Path_Planning_2023a_DW.BLACK_Rz_preKalm =
      APF_Path_Planning_2023a_P.BLACK_Rz3_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Tz'
    APF_Path_Planning_2023a_DW.BLACK_Tz =
      APF_Path_Planning_2023a_P.BLACK_Tz_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Tz1'
    APF_Path_Planning_2023a_DW.BLUE_Tz =
      APF_Path_Planning_2023a_P.BLACK_Tz1_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Tz_Sat'
    APF_Path_Planning_2023a_DW.BLACK_Tz_Sat =
      APF_Path_Planning_2023a_P.BLACK_Tz_Sat_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Tz_Sat2'
    APF_Path_Planning_2023a_DW.BLUE_Tz_Sat =
      APF_Path_Planning_2023a_P.BLACK_Tz_Sat2_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Fx1'
    APF_Path_Planning_2023a_DW.RED_Fx =
      APF_Path_Planning_2023a_P.RED_Fx1_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Fx_Sat'
    APF_Path_Planning_2023a_DW.RED_Fx_Sat =
      APF_Path_Planning_2023a_P.RED_Fx_Sat_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Fy'
    APF_Path_Planning_2023a_DW.RED_Fy =
      APF_Path_Planning_2023a_P.RED_Fy_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Fy_Sat'
    APF_Path_Planning_2023a_DW.RED_Fy_Sat =
      APF_Path_Planning_2023a_P.RED_Fy_Sat_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Px'
    APF_Path_Planning_2023a_DW.RED_Px =
      APF_Path_Planning_2023a_P.RED_Px_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Py'
    APF_Path_Planning_2023a_DW.RED_Py =
      APF_Path_Planning_2023a_P.RED_Py_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Rz'
    APF_Path_Planning_2023a_DW.RED_Rz =
      APF_Path_Planning_2023a_P.RED_Rz_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz'
    APF_Path_Planning_2023a_DW.RED_Tz =
      APF_Path_Planning_2023a_P.RED_Tz_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz12'
    APF_Path_Planning_2023a_DW.RED_RzD_Shoulder =
      APF_Path_Planning_2023a_P.RED_Tz12_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz13'
    APF_Path_Planning_2023a_DW.RED_RzD_Elbow =
      APF_Path_Planning_2023a_P.RED_Tz13_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz14'
    APF_Path_Planning_2023a_DW.RED_RzD_Wrist =
      APF_Path_Planning_2023a_P.RED_Tz14_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz15'
    APF_Path_Planning_2023a_DW.RED_ARM_Control_Mode =
      APF_Path_Planning_2023a_P.RED_Tz15_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz16'
    APF_Path_Planning_2023a_DW.RED_Shoulder_Command =
      APF_Path_Planning_2023a_P.RED_Tz16_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz4'
    APF_Path_Planning_2023a_DW.RED_Rz_Shoulder =
      APF_Path_Planning_2023a_P.RED_Tz4_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz5'
    APF_Path_Planning_2023a_DW.RED_Rz_Elbow =
      APF_Path_Planning_2023a_P.RED_Tz5_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz6'
    APF_Path_Planning_2023a_DW.RED_Rz_Wrist =
      APF_Path_Planning_2023a_P.RED_Tz6_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz7'
    APF_Path_Planning_2023a_DW.Float_State =
      APF_Path_Planning_2023a_P.RED_Tz7_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz_RW Sat'
    APF_Path_Planning_2023a_DW.RED_Tz_RW_Sat =
      APF_Path_Planning_2023a_P.RED_Tz_RWSat_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz_Sat'
    APF_Path_Planning_2023a_DW.RED_Tz_Sat =
      APF_Path_Planning_2023a_P.RED_Tz_Sat_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat1'
    APF_Path_Planning_2023a_DW.Command_Px =
      APF_Path_Planning_2023a_P.RED_dRz_RWSat1_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat10'
    APF_Path_Planning_2023a_DW.TX2_data1 =
      APF_Path_Planning_2023a_P.RED_dRz_RWSat10_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat11'
    APF_Path_Planning_2023a_DW.TX2_data2 =
      APF_Path_Planning_2023a_P.RED_dRz_RWSat11_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat12'
    APF_Path_Planning_2023a_DW.TX2_data3 =
      APF_Path_Planning_2023a_P.RED_dRz_RWSat12_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat2'
    APF_Path_Planning_2023a_DW.Command_Py =
      APF_Path_Planning_2023a_P.RED_dRz_RWSat2_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat3'
    APF_Path_Planning_2023a_DW.Command_Rz =
      APF_Path_Planning_2023a_P.RED_dRz_RWSat3_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat4'
    APF_Path_Planning_2023a_DW.DAC_Posx_k_1 =
      APF_Path_Planning_2023a_P.RED_dRz_RWSat4_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat5'
    APF_Path_Planning_2023a_DW.DAC_Posx_k_2 =
      APF_Path_Planning_2023a_P.RED_dRz_RWSat5_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat6'
    APF_Path_Planning_2023a_DW.DAC_Posy_k_1 =
      APF_Path_Planning_2023a_P.RED_dRz_RWSat6_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat7'
    APF_Path_Planning_2023a_DW.DAC_Posy_k_2 =
      APF_Path_Planning_2023a_P.RED_dRz_RWSat7_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat8'
    APF_Path_Planning_2023a_DW.DAC_Attitude_k_1 =
      APF_Path_Planning_2023a_P.RED_dRz_RWSat8_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat9'
    APF_Path_Planning_2023a_DW.DAC_Attitude_k_2 =
      APF_Path_Planning_2023a_P.RED_dRz_RWSat9_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time'
    APF_Path_Planning_2023a_DW.Univ_Time =
      APF_Path_Planning_2023a_P.Universal_Time_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time1'
    APF_Path_Planning_2023a_DW.RED_Vx =
      APF_Path_Planning_2023a_P.Universal_Time1_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time10'
    APF_Path_Planning_2023a_DW.RED_Ax =
      APF_Path_Planning_2023a_P.Universal_Time10_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time11'
    APF_Path_Planning_2023a_DW.RED_Ay =
      APF_Path_Planning_2023a_P.Universal_Time11_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time12'
    APF_Path_Planning_2023a_DW.BLACK_Ax =
      APF_Path_Planning_2023a_P.Universal_Time12_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time13'
    APF_Path_Planning_2023a_DW.BLACK_Ay =
      APF_Path_Planning_2023a_P.Universal_Time13_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time14'
    APF_Path_Planning_2023a_DW.BLACK_RzDD =
      APF_Path_Planning_2023a_P.Universal_Time14_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time15'
    APF_Path_Planning_2023a_DW.RED_RzDD =
      APF_Path_Planning_2023a_P.Universal_Time15_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time16'
    APF_Path_Planning_2023a_DW.RED_Thruster_ON_Count =
      APF_Path_Planning_2023a_P.Universal_Time16_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time17'
    APF_Path_Planning_2023a_DW.BLACK_Thruster_ON_Count =
      APF_Path_Planning_2023a_P.Universal_Time17_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time18'
    APF_Path_Planning_2023a_DW.BLUE_Thruster_ON_Count =
      APF_Path_Planning_2023a_P.Universal_Time18_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time19'
    APF_Path_Planning_2023a_DW.WhoAmI =
      APF_Path_Planning_2023a_P.Universal_Time19_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time2'
    APF_Path_Planning_2023a_DW.RED_Vy =
      APF_Path_Planning_2023a_P.Universal_Time2_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time20'
    APF_Path_Planning_2023a_DW.isSim =
      APF_Path_Planning_2023a_P.Universal_Time20_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time21'
    APF_Path_Planning_2023a_DW.RED_Elbow_Command =
      APF_Path_Planning_2023a_P.Universal_Time21_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time22'
    APF_Path_Planning_2023a_DW.RED_Wrist_Command =
      APF_Path_Planning_2023a_P.Universal_Time22_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time3'
    APF_Path_Planning_2023a_DW.RED_RzD =
      APF_Path_Planning_2023a_P.Universal_Time3_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time4'
    APF_Path_Planning_2023a_DW.BLACK_Vx =
      APF_Path_Planning_2023a_P.Universal_Time4_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time5'
    APF_Path_Planning_2023a_DW.BLACK_Vy =
      APF_Path_Planning_2023a_P.Universal_Time5_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time6'
    APF_Path_Planning_2023a_DW.BLACK_RzD =
      APF_Path_Planning_2023a_P.Universal_Time6_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time7'
    APF_Path_Planning_2023a_DW.BLUE_Vx =
      APF_Path_Planning_2023a_P.Universal_Time7_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time8'
    APF_Path_Planning_2023a_DW.BLUE_Vy =
      APF_Path_Planning_2023a_P.Universal_Time8_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time9'
    APF_Path_Planning_2023a_DW.BLUE_RzD =
      APF_Path_Planning_2023a_P.Universal_Time9_InitialValue;

    // SystemInitialize for IfAction SubSystem: '<Root>/Phase #0: Synchronization' 
    APF__Phase0Synchronization_Init
      (&APF_Path_Planning_2023a_DW.Phase0Synchronization);

    // End of SystemInitialize for SubSystem: '<Root>/Phase #0: Synchronization' 

    // SystemInitialize for IfAction SubSystem: '<Root>/Phase #1: Start Floating ' 
    APF__Phase0Synchronization_Init
      (&APF_Path_Planning_2023a_DW.Phase1StartFloating);

    // End of SystemInitialize for SubSystem: '<Root>/Phase #1: Start Floating ' 

    // SystemInitialize for IfAction SubSystem: '<Root>/Phase #2: Initial Position' 
    // Start for If: '<S8>/This IF block determines whether or not to run the BLACK sim//exp' 
    APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_h2 = -1;

    // Start for If: '<S8>/This IF block determines whether or not to run the BLUE sim//exp' 
    APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_l2 = -1;

    // Start for If: '<S8>/This IF block determines whether or not to run the RED sim//exp ' 
    APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_gv = -1;

    // SystemInitialize for IfAction SubSystem: '<S8>/Change BLACK Behavior'
    // Start for If: '<S42>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ba = -1;

    // Start for If: '<S44>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_il = -1;

    // Start for If: '<S40>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_m = -1;

    // InitializeConditions for Delay: '<S42>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_fp = true;

    // InitializeConditions for Delay: '<S44>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_ig = true;

    // InitializeConditions for Delay: '<S40>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_p = true;

    // SystemInitialize for IfAction SubSystem: '<S42>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S43>/In1' incorporates:
    //   Outport: '<S43>/Out1'

    APF_Path_Planning_2023a_B.In1_g20asdtgi0cdy =
      APF_Path_Planning_2023a_P.Out1_Y0_nx;

    // End of SystemInitialize for SubSystem: '<S42>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S44>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S45>/In1' incorporates:
    //   Outport: '<S45>/Out1'

    APF_Path_Planning_2023a_B.In1_g20asdtgi0cd =
      APF_Path_Planning_2023a_P.Out1_Y0_g4;

    // End of SystemInitialize for SubSystem: '<S44>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S40>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S41>/In1' incorporates:
    //   Outport: '<S41>/Out1'

    APF_Path_Planning_2023a_B.In1_g20asdtgi0cdyi =
      APF_Path_Planning_2023a_P.Out1_Y0_gf;

    // End of SystemInitialize for SubSystem: '<S40>/Hold this value'
    // End of SystemInitialize for SubSystem: '<S8>/Change BLACK Behavior'

    // SystemInitialize for IfAction SubSystem: '<S8>/Change BLUE Behavior'
    // Start for If: '<S55>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_e = -1;

    // Start for If: '<S57>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_f = -1;

    // Start for If: '<S53>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_jh = -1;

    // InitializeConditions for Delay: '<S55>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_o = true;

    // InitializeConditions for Delay: '<S57>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_n = true;

    // InitializeConditions for Delay: '<S53>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_bb = true;

    // SystemInitialize for IfAction SubSystem: '<S55>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S56>/In1' incorporates:
    //   Outport: '<S56>/Out1'

    APF_Path_Planning_2023a_B.In1_g20asdtgi0 =
      APF_Path_Planning_2023a_P.Out1_Y0_bq;

    // End of SystemInitialize for SubSystem: '<S55>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S57>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S58>/In1' incorporates:
    //   Outport: '<S58>/Out1'

    APF_Path_Planning_2023a_B.In1_g20asdtgi =
      APF_Path_Planning_2023a_P.Out1_Y0_c1;

    // End of SystemInitialize for SubSystem: '<S57>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S53>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S54>/In1' incorporates:
    //   Outport: '<S54>/Out1'

    APF_Path_Planning_2023a_B.In1_g20asdtgi0c =
      APF_Path_Planning_2023a_P.Out1_Y0_nj;

    // End of SystemInitialize for SubSystem: '<S53>/Hold this value'
    // End of SystemInitialize for SubSystem: '<S8>/Change BLUE Behavior'

    // SystemInitialize for IfAction SubSystem: '<S8>/Change RED Behavior'
    // Start for If: '<S67>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_n = -1;

    // Start for If: '<S69>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_c = -1;

    // Start for If: '<S71>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_j = -1;

    // InitializeConditions for Delay: '<S67>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_g = true;

    // InitializeConditions for Delay: '<S69>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_a = true;

    // InitializeConditions for Delay: '<S71>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_b = true;

    // SystemInitialize for IfAction SubSystem: '<S67>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S68>/In1' incorporates:
    //   Outport: '<S68>/Out1'

    APF_Path_Planning_2023a_B.In1_g20asdtg =
      APF_Path_Planning_2023a_P.Out1_Y0_hs;

    // End of SystemInitialize for SubSystem: '<S67>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S69>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S70>/In1' incorporates:
    //   Outport: '<S70>/Out1'

    APF_Path_Planning_2023a_B.In1_g20asdt = APF_Path_Planning_2023a_P.Out1_Y0_cr;

    // End of SystemInitialize for SubSystem: '<S69>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S71>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S72>/In1' incorporates:
    //   Outport: '<S72>/Out1'

    APF_Path_Planning_2023a_B.In1_g20asd = APF_Path_Planning_2023a_P.Out1_Y0_dg;

    // End of SystemInitialize for SubSystem: '<S71>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S35>/RED+ARM'
    APF_Path_Planning_2_REDARM_Init(&APF_Path_Planning_2023a_B.REDARM_e,
      &APF_Path_Planning_2023a_DW.REDARM_e, &APF_Path_Planning_2023a_P.REDARM_e);

    // End of SystemInitialize for SubSystem: '<S35>/RED+ARM'
    // End of SystemInitialize for SubSystem: '<S8>/Change RED Behavior'
    // End of SystemInitialize for SubSystem: '<Root>/Phase #2: Initial Position' 

    // SystemInitialize for IfAction SubSystem: '<Root>/Phase #3: Experiment'
    // Start for If: '<S9>/This IF block determines whether or not to run the BLACK sim//exp' 
    APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_n = -1;

    // Start for If: '<S9>/This IF block determines whether or not to run the BLUE sim//exp' 
    APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_al = -1;

    // Start for If: '<S9>/This IF block determines whether or not to run the RED sim//exp ' 
    APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_fg = -1;

    // SystemInitialize for IfAction SubSystem: '<S9>/Change BLACK Behavior'
    // Start for If: '<S87>/Experiment Sub-Phases'
    APF_Path_Planning_2023a_DW.ExperimentSubPhases_ActiveSub_l = -1;

    // SystemInitialize for IfAction SubSystem: '<S87>/Sub-Phase #1'
    APF_Path_Plannin_SubPhase1_Init(&APF_Path_Planning_2023a_B.SubPhase1,
      &APF_Path_Planning_2023a_DW.SubPhase1,
      &APF_Path_Planning_2023a_P.SubPhase1);

    // End of SystemInitialize for SubSystem: '<S87>/Sub-Phase #1'

    // SystemInitialize for IfAction SubSystem: '<S87>/Sub-Phase #2 '
    APF_Path_Plannin_SubPhase1_Init(&APF_Path_Planning_2023a_B.SubPhase2,
      &APF_Path_Planning_2023a_DW.SubPhase2,
      &APF_Path_Planning_2023a_P.SubPhase2);

    // End of SystemInitialize for SubSystem: '<S87>/Sub-Phase #2 '

    // SystemInitialize for IfAction SubSystem: '<S87>/Sub-Phase #3 '
    APF_Path_Plannin_SubPhase1_Init(&APF_Path_Planning_2023a_B.SubPhase3,
      &APF_Path_Planning_2023a_DW.SubPhase3,
      &APF_Path_Planning_2023a_P.SubPhase3);

    // End of SystemInitialize for SubSystem: '<S87>/Sub-Phase #3 '

    // SystemInitialize for IfAction SubSystem: '<S87>/Sub-Phase #4'
    // InitializeConditions for DiscreteIntegrator: '<S149>/Start Pos'
    APF_Path_Planning_2023a_DW.StartPos_DSTATE_p =
      APF_Path_Planning_2023a_P.BLACK_ini[0];

    // InitializeConditions for Delay: '<S154>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_c = true;

    // InitializeConditions for DiscreteIntegrator: '<S150>/Start Pos'
    APF_Path_Planning_2023a_DW.StartPos_DSTATE_b =
      APF_Path_Planning_2023a_P.BLACK_ini[1];

    // InitializeConditions for Delay: '<S156>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_j = true;

    // InitializeConditions for DiscreteIntegrator: '<S151>/Start Pos'
    APF_Path_Planning_2023a_DW.StartPos_DSTATE_l4 =
      APF_Path_Planning_2023a_P.BLACK_ini[2];

    // InitializeConditions for Delay: '<S152>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_fo = true;

    // End of SystemInitialize for SubSystem: '<S87>/Sub-Phase #4'
    // End of SystemInitialize for SubSystem: '<S9>/Change BLACK Behavior'

    // SystemInitialize for IfAction SubSystem: '<S9>/Change BLUE Behavior'
    // Start for If: '<S88>/Experiment Sub-Phases'
    APF_Path_Planning_2023a_DW.ExperimentSubPhases_ActiveSub_c = -1;

    // SystemInitialize for IfAction SubSystem: '<S88>/Sub-Phase #1'
    APF_Path_Plann_SubPhase1_p_Init(&APF_Path_Planning_2023a_B.SubPhase1_g,
      &APF_Path_Planning_2023a_DW.SubPhase1_g,
      &APF_Path_Planning_2023a_P.SubPhase1_g);

    // End of SystemInitialize for SubSystem: '<S88>/Sub-Phase #1'

    // SystemInitialize for IfAction SubSystem: '<S88>/Sub-Phase #2 '
    APF_Path_Plann_SubPhase1_p_Init(&APF_Path_Planning_2023a_B.SubPhase2_c,
      &APF_Path_Planning_2023a_DW.SubPhase2_c,
      &APF_Path_Planning_2023a_P.SubPhase2_c);

    // End of SystemInitialize for SubSystem: '<S88>/Sub-Phase #2 '

    // SystemInitialize for IfAction SubSystem: '<S88>/Sub-Phase #3 '
    APF_Path_Plann_SubPhase1_p_Init(&APF_Path_Planning_2023a_B.SubPhase3_e,
      &APF_Path_Planning_2023a_DW.SubPhase3_e,
      &APF_Path_Planning_2023a_P.SubPhase3_e);

    // End of SystemInitialize for SubSystem: '<S88>/Sub-Phase #3 '

    // SystemInitialize for IfAction SubSystem: '<S88>/Sub-Phase #4'
    // Start for If: '<S237>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_p = -1;

    // Start for If: '<S239>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_i = -1;

    // Start for If: '<S235>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_k = -1;

    // InitializeConditions for DiscreteIntegrator: '<S232>/Start Pos'
    APF_Path_Planning_2023a_DW.StartPos_DSTATE =
      APF_Path_Planning_2023a_P.BLUE_ini[0];

    // InitializeConditions for Delay: '<S237>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_d = true;

    // InitializeConditions for DiscreteIntegrator: '<S233>/Start Pos'
    APF_Path_Planning_2023a_DW.StartPos_DSTATE_j =
      APF_Path_Planning_2023a_P.BLUE_ini[1];

    // InitializeConditions for Delay: '<S239>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_d4 = true;

    // InitializeConditions for DiscreteIntegrator: '<S234>/Start Pos'
    APF_Path_Planning_2023a_DW.StartPos_DSTATE_l =
      APF_Path_Planning_2023a_P.BLUE_ini[2];

    // InitializeConditions for Delay: '<S235>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_l = true;

    // SystemInitialize for IfAction SubSystem: '<S237>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S238>/In1' incorporates:
    //   Outport: '<S238>/Out1'

    APF_Path_Planning_2023a_B.In1_g20a = APF_Path_Planning_2023a_P.Out1_Y0_me;

    // End of SystemInitialize for SubSystem: '<S237>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S239>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S240>/In1' incorporates:
    //   Outport: '<S240>/Out1'

    APF_Path_Planning_2023a_B.In1_g20 = APF_Path_Planning_2023a_P.Out1_Y0_bg;

    // End of SystemInitialize for SubSystem: '<S239>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S235>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S236>/In1' incorporates:
    //   Outport: '<S236>/Out1'

    APF_Path_Planning_2023a_B.In1_g20as = APF_Path_Planning_2023a_P.Out1_Y0_ep;

    // End of SystemInitialize for SubSystem: '<S235>/Hold this value'
    // End of SystemInitialize for SubSystem: '<S88>/Sub-Phase #4'
    // End of SystemInitialize for SubSystem: '<S9>/Change BLUE Behavior'

    // SystemInitialize for IfAction SubSystem: '<S9>/Change RED Behavior'
    // Start for If: '<S89>/Experiment Sub-Phases'
    APF_Path_Planning_2023a_DW.ExperimentSubPhases_ActiveSubsy = -1;

    // SystemInitialize for IfAction SubSystem: '<S89>/Sub-Phase #1'
    APF_Path_Plann_SubPhase1_k_Init(&APF_Path_Planning_2023a_B.SubPhase1_p,
      &APF_Path_Planning_2023a_DW.SubPhase1_p,
      &APF_Path_Planning_2023a_P.SubPhase1_p);

    // End of SystemInitialize for SubSystem: '<S89>/Sub-Phase #1'

    // SystemInitialize for IfAction SubSystem: '<S89>/Sub-Phase #2 '
    APF_Path_Plann_SubPhase1_k_Init(&APF_Path_Planning_2023a_B.SubPhase2_p,
      &APF_Path_Planning_2023a_DW.SubPhase2_p,
      &APF_Path_Planning_2023a_P.SubPhase2_p);

    // End of SystemInitialize for SubSystem: '<S89>/Sub-Phase #2 '

    // SystemInitialize for IfAction SubSystem: '<S89>/Sub-Phase #3 '
    // Start for If: '<S323>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSubs = -1;

    // Start for If: '<S325>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_h = -1;

    // Start for If: '<S327>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveSu_l = -1;

    // InitializeConditions for Delay: '<S323>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad = true;

    // InitializeConditions for Delay: '<S325>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_f = true;

    // InitializeConditions for Delay: '<S327>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_i = true;

    // SystemInitialize for IfAction SubSystem: '<S323>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S324>/In1' incorporates:
    //   Outport: '<S324>/Out1'

    APF_Path_Planning_2023a_B.In1_g2 = APF_Path_Planning_2023a_P.Out1_Y0_ig;

    // End of SystemInitialize for SubSystem: '<S323>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S325>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S326>/In1' incorporates:
    //   Outport: '<S326>/Out1'

    APF_Path_Planning_2023a_B.In1_g = APF_Path_Planning_2023a_P.Out1_Y0_fb;

    // End of SystemInitialize for SubSystem: '<S325>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S327>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S328>/In1' incorporates:
    //   Outport: '<S328>/Out1'

    APF_Path_Planning_2023a_B.In1 = APF_Path_Planning_2023a_P.Out1_Y0_bj;

    // End of SystemInitialize for SubSystem: '<S327>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S246>/RED+ARM'
    APF_Path_Planning_2_REDARM_Init(&APF_Path_Planning_2023a_B.REDARM_m,
      &APF_Path_Planning_2023a_DW.REDARM_m, &APF_Path_Planning_2023a_P.REDARM_m);

    // End of SystemInitialize for SubSystem: '<S246>/RED+ARM'
    // End of SystemInitialize for SubSystem: '<S89>/Sub-Phase #3 '

    // SystemInitialize for IfAction SubSystem: '<S89>/Sub-Phase #4'
    // Start for If: '<S350>/If2'
    APF_Path_Planning_2023a_DW.If2_ActiveSubsystem = -1;

    // Start for If: '<S350>/If1'
    APF_Path_Planning_2023a_DW.If1_ActiveSubsystem = -1;

    // Start for If: '<S350>/If'
    APF_Path_Planning_2023a_DW.If_ActiveSubsystem = -1;

    // Start for If: '<S349>/If2'
    APF_Path_Planning_2023a_DW.If2_ActiveSubsystem_m = -1;

    // Start for If: '<S349>/If1'
    APF_Path_Planning_2023a_DW.If1_ActiveSubsystem_a = -1;

    // Start for If: '<S349>/If'
    APF_Path_Planning_2023a_DW.If_ActiveSubsystem_m = -1;

    // Start for If: '<S247>/If'
    APF_Path_Planning_2023a_DW.If_ActiveSubsystem_l = -1;

    // InitializeConditions for Delay: '<S369>/Delay'
    APF_Path_Planning_2023a_DW.Delay_DSTATE =
      APF_Path_Planning_2023a_P.Delay_InitialCondition_c;

    // SystemInitialize for IfAction SubSystem: '<S350>/Target Tracker'
    // InitializeConditions for DiscreteTransferFcn: '<S371>/Discrete Transfer Fcn1' 
    APF_Path_Planning_2023a_DW.DiscreteTransferFcn1_states =
      APF_Path_Planning_2023a_P.DiscreteTransferFcn1_InitialSta;

    // End of SystemInitialize for SubSystem: '<S350>/Target Tracker'

    // SystemInitialize for IfAction SubSystem: '<S350>/Target Finder'
    // SystemInitialize for SignalConversion generated from: '<S370>/Desired States' incorporates:
    //   Outport: '<S370>/Desired States'

    APF_Path_Planning_2023a_B.OutportBufferForDesiredStates[0] =
      APF_Path_Planning_2023a_P.DesiredStates_Y0_g;

    // End of SystemInitialize for SubSystem: '<S350>/Target Finder'

    // SystemInitialize for IfAction SubSystem: '<S350>/Target Tracker'
    // SystemInitialize for SignalConversion generated from: '<S371>/Desired States' incorporates:
    //   Outport: '<S371>/Desired States'

    APF_Path_Planning_2023a_B.OutportBufferForDesiredStates_c[0] =
      APF_Path_Planning_2023a_P.DesiredStates_Y0;

    // End of SystemInitialize for SubSystem: '<S350>/Target Tracker'

    // SystemInitialize for IfAction SubSystem: '<S350>/APF'
    // InitializeConditions for Delay: '<S381>/Delay'
    APF_Path_Planning_2023a_DW.Delay_DSTATE_c[0] =
      APF_Path_Planning_2023a_P.Delay_InitialCondition_n;

    // InitializeConditions for Delay: '<S382>/Delay'
    APF_Path_Planning_2023a_DW.Delay_DSTATE_o[0] =
      APF_Path_Planning_2023a_P.Delay_InitialCondition_l;

    // InitializeConditions for Delay: '<S377>/Delay3'
    APF_Path_Planning_2023a_DW.Delay3_DSTATE[0] =
      APF_Path_Planning_2023a_P.Delay3_InitialCondition;

    // InitializeConditions for Delay: '<S376>/Delay'
    APF_Path_Planning_2023a_DW.Delay_DSTATE_d[0] =
      APF_Path_Planning_2023a_P.Delay_InitialCondition_p[0];

    // InitializeConditions for Delay: '<S376>/Delay1'
    APF_Path_Planning_2023a_DW.Delay1_DSTATE[0] =
      APF_Path_Planning_2023a_P.Delay1_InitialCondition_d[0];

    // InitializeConditions for Delay: '<S383>/Delay3'
    APF_Path_Planning_2023a_DW.Delay3_DSTATE_d[0] =
      APF_Path_Planning_2023a_P.Delay3_InitialCondition_a;

    // InitializeConditions for Delay: '<S379>/Delay3'
    APF_Path_Planning_2023a_DW.Delay3_DSTATE_a[0] =
      APF_Path_Planning_2023a_P.Delay3_InitialCondition_e;

    // InitializeConditions for Delay: '<S379>/Delay1'
    APF_Path_Planning_2023a_DW.Delay1_DSTATE_d[0] =
      APF_Path_Planning_2023a_P.Delay1_InitialCondition_o;

    // InitializeConditions for Delay: '<S378>/Delay3'
    APF_Path_Planning_2023a_DW.Delay3_DSTATE_j[0] =
      APF_Path_Planning_2023a_P.Delay3_InitialCondition_p;

    // End of SystemInitialize for SubSystem: '<S350>/APF'

    // SystemInitialize for IfAction SubSystem: '<S350>/Target Finder'
    // SystemInitialize for SignalConversion generated from: '<S370>/Desired States' incorporates:
    //   Outport: '<S370>/Desired States'

    APF_Path_Planning_2023a_B.OutportBufferForDesiredStates[1] =
      APF_Path_Planning_2023a_P.DesiredStates_Y0_g;

    // End of SystemInitialize for SubSystem: '<S350>/Target Finder'

    // SystemInitialize for IfAction SubSystem: '<S350>/Target Tracker'
    // SystemInitialize for SignalConversion generated from: '<S371>/Desired States' incorporates:
    //   Outport: '<S371>/Desired States'

    APF_Path_Planning_2023a_B.OutportBufferForDesiredStates_c[1] =
      APF_Path_Planning_2023a_P.DesiredStates_Y0;

    // End of SystemInitialize for SubSystem: '<S350>/Target Tracker'

    // SystemInitialize for IfAction SubSystem: '<S350>/APF'
    // InitializeConditions for Delay: '<S381>/Delay'
    APF_Path_Planning_2023a_DW.Delay_DSTATE_c[1] =
      APF_Path_Planning_2023a_P.Delay_InitialCondition_n;

    // InitializeConditions for Delay: '<S382>/Delay'
    APF_Path_Planning_2023a_DW.Delay_DSTATE_o[1] =
      APF_Path_Planning_2023a_P.Delay_InitialCondition_l;

    // InitializeConditions for Delay: '<S377>/Delay3'
    APF_Path_Planning_2023a_DW.Delay3_DSTATE[1] =
      APF_Path_Planning_2023a_P.Delay3_InitialCondition;

    // InitializeConditions for Delay: '<S376>/Delay'
    APF_Path_Planning_2023a_DW.Delay_DSTATE_d[1] =
      APF_Path_Planning_2023a_P.Delay_InitialCondition_p[1];

    // InitializeConditions for Delay: '<S376>/Delay1'
    APF_Path_Planning_2023a_DW.Delay1_DSTATE[1] =
      APF_Path_Planning_2023a_P.Delay1_InitialCondition_d[1];

    // InitializeConditions for Delay: '<S383>/Delay3'
    APF_Path_Planning_2023a_DW.Delay3_DSTATE_d[1] =
      APF_Path_Planning_2023a_P.Delay3_InitialCondition_a;

    // InitializeConditions for Delay: '<S379>/Delay3'
    APF_Path_Planning_2023a_DW.Delay3_DSTATE_a[1] =
      APF_Path_Planning_2023a_P.Delay3_InitialCondition_e;

    // InitializeConditions for Delay: '<S379>/Delay1'
    APF_Path_Planning_2023a_DW.Delay1_DSTATE_d[1] =
      APF_Path_Planning_2023a_P.Delay1_InitialCondition_o;

    // InitializeConditions for Delay: '<S378>/Delay3'
    APF_Path_Planning_2023a_DW.Delay3_DSTATE_j[1] =
      APF_Path_Planning_2023a_P.Delay3_InitialCondition_p;

    // End of SystemInitialize for SubSystem: '<S350>/APF'

    // SystemInitialize for IfAction SubSystem: '<S350>/Target Finder'
    // SystemInitialize for SignalConversion generated from: '<S370>/Desired States' incorporates:
    //   Outport: '<S370>/Desired States'

    APF_Path_Planning_2023a_B.OutportBufferForDesiredStates[2] =
      APF_Path_Planning_2023a_P.DesiredStates_Y0_g;

    // End of SystemInitialize for SubSystem: '<S350>/Target Finder'

    // SystemInitialize for IfAction SubSystem: '<S350>/Target Tracker'
    // SystemInitialize for SignalConversion generated from: '<S371>/Desired States' incorporates:
    //   Outport: '<S371>/Desired States'

    APF_Path_Planning_2023a_B.OutportBufferForDesiredStates_c[2] =
      APF_Path_Planning_2023a_P.DesiredStates_Y0;

    // End of SystemInitialize for SubSystem: '<S350>/Target Tracker'

    // SystemInitialize for IfAction SubSystem: '<S350>/APF'
    // InitializeConditions for Delay: '<S381>/Delay'
    APF_Path_Planning_2023a_DW.Delay_DSTATE_c[2] =
      APF_Path_Planning_2023a_P.Delay_InitialCondition_n;

    // InitializeConditions for Delay: '<S382>/Delay'
    APF_Path_Planning_2023a_DW.Delay_DSTATE_o[2] =
      APF_Path_Planning_2023a_P.Delay_InitialCondition_l;

    // InitializeConditions for Delay: '<S377>/Delay3'
    APF_Path_Planning_2023a_DW.Delay3_DSTATE[2] =
      APF_Path_Planning_2023a_P.Delay3_InitialCondition;

    // InitializeConditions for Delay: '<S376>/Delay'
    APF_Path_Planning_2023a_DW.Delay_DSTATE_d[2] =
      APF_Path_Planning_2023a_P.Delay_InitialCondition_p[2];

    // InitializeConditions for Delay: '<S376>/Delay1'
    APF_Path_Planning_2023a_DW.Delay1_DSTATE[2] =
      APF_Path_Planning_2023a_P.Delay1_InitialCondition_d[2];

    // InitializeConditions for Delay: '<S383>/Delay3'
    APF_Path_Planning_2023a_DW.Delay3_DSTATE_d[2] =
      APF_Path_Planning_2023a_P.Delay3_InitialCondition_a;

    // InitializeConditions for Delay: '<S379>/Delay3'
    APF_Path_Planning_2023a_DW.Delay3_DSTATE_a[2] =
      APF_Path_Planning_2023a_P.Delay3_InitialCondition_e;

    // InitializeConditions for Delay: '<S379>/Delay1'
    APF_Path_Planning_2023a_DW.Delay1_DSTATE_d[2] =
      APF_Path_Planning_2023a_P.Delay1_InitialCondition_o;

    // InitializeConditions for Delay: '<S378>/Delay3'
    APF_Path_Planning_2023a_DW.Delay3_DSTATE_j[2] =
      APF_Path_Planning_2023a_P.Delay3_InitialCondition_p;

    // InitializeConditions for Delay: '<S378>/Delay1'
    APF_Path_Planning_2023a_DW.Delay1_DSTATE_l =
      APF_Path_Planning_2023a_P.Delay1_InitialCondition_p;

    // SystemInitialize for Outport: '<S368>/Out1' incorporates:
    //   MultiPortSwitch: '<S375>/Multiport Switch'

    APF_Path_Planning_2023a_B.MultiportSwitch[0] =
      APF_Path_Planning_2023a_P.Out1_Y0_bjy;
    APF_Path_Planning_2023a_B.MultiportSwitch[1] =
      APF_Path_Planning_2023a_P.Out1_Y0_bjy;

    // SystemInitialize for Switch: '<S368>/Switch' incorporates:
    //   Outport: '<S368>/Out1'

    APF_Path_Planning_2023a_B.Switch = APF_Path_Planning_2023a_P.Out1_Y0_bjy;

    // End of SystemInitialize for SubSystem: '<S350>/APF'

    // SystemInitialize for IfAction SubSystem: '<S349>/Target Finder'
    APF_Path_Pla_TargetTracker_Init(APF_Path_Planning_2023a_B.u,
      &APF_Path_Planning_2023a_P.TargetFinder,
      &APF_Path_Planning_2023a_X.TargetFinder);

    // End of SystemInitialize for SubSystem: '<S349>/Target Finder'

    // SystemInitialize for IfAction SubSystem: '<S349>/Target Tracker'
    APF_Path_Pla_TargetTracker_Init(APF_Path_Planning_2023a_B.u_l,
      &APF_Path_Planning_2023a_P.TargetTracker,
      &APF_Path_Planning_2023a_X.TargetTracker);

    // End of SystemInitialize for SubSystem: '<S349>/Target Tracker'

    // SystemInitialize for IfAction SubSystem: '<S349>/If Action Subsystem'
    // InitializeConditions for Derivative: '<S360>/Derivative2'
    APF_Path_Planning_2023a_DW.TimeStampA = (rtInf);
    APF_Path_Planning_2023a_DW.TimeStampB = (rtInf);

    // InitializeConditions for DiscreteIntegrator: '<S360>/Discrete-Time Integrator4' 
    APF_Path_Planning_2023a_DW.DiscreteTimeIntegrator4_DSTATE =
      APF_Path_Planning_2023a_P.k_2_0;

    // InitializeConditions for DiscreteIntegrator: '<S360>/Discrete-Time Integrator5' 
    APF_Path_Planning_2023a_DW.DiscreteTimeIntegrator5_DSTATE =
      APF_Path_Planning_2023a_P.k_1_0;

    // InitializeConditions for Derivative: '<S360>/Derivative1'
    APF_Path_Planning_2023a_DW.TimeStampA_i = (rtInf);
    APF_Path_Planning_2023a_DW.TimeStampB_p = (rtInf);

    // InitializeConditions for DiscreteIntegrator: '<S360>/Discrete-Time Integrator2' 
    APF_Path_Planning_2023a_DW.DiscreteTimeIntegrator2_DSTATE =
      APF_Path_Planning_2023a_P.k_2_0;

    // InitializeConditions for DiscreteIntegrator: '<S360>/Discrete-Time Integrator3' 
    APF_Path_Planning_2023a_DW.DiscreteTimeIntegrator3_DSTATE =
      APF_Path_Planning_2023a_P.k_1_0;

    // InitializeConditions for DiscreteIntegrator: '<S360>/Discrete-Time Integrator1' 
    APF_Path_Planning_2023a_DW.DiscreteTimeIntegrator1_DSTATE =
      APF_Path_Planning_2023a_P.k_1_t_0;

    // InitializeConditions for DiscreteIntegrator: '<S360>/Discrete-Time Integrator' 
    APF_Path_Planning_2023a_DW.DiscreteTimeIntegrator_DSTATE =
      APF_Path_Planning_2023a_P.k_2_t_0;

    // InitializeConditions for Derivative: '<S360>/Derivative3'
    APF_Path_Planning_2023a_DW.TimeStampA_h = (rtInf);
    APF_Path_Planning_2023a_DW.TimeStampB_e = (rtInf);

    // SystemInitialize for Sum: '<S360>/u_x' incorporates:
    //   Outport: '<S354>/Out1'

    APF_Path_Planning_2023a_B.u_x = APF_Path_Planning_2023a_P.Out1_Y0_ll;

    // SystemInitialize for Sum: '<S360>/u_y' incorporates:
    //   Outport: '<S354>/Out1'

    APF_Path_Planning_2023a_B.u_y = APF_Path_Planning_2023a_P.Out1_Y0_ll;

    // SystemInitialize for Sum: '<S360>/Add2' incorporates:
    //   Outport: '<S354>/Out1'

    APF_Path_Planning_2023a_B.Add2 = APF_Path_Planning_2023a_P.Out1_Y0_ll;

    // End of SystemInitialize for SubSystem: '<S349>/If Action Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S247>/RED+ARM'
    // SystemInitialize for IfAction SubSystem: '<S352>/Simulated Position Controller' 
    SimulatedPositionControlle_Init
      (&APF_Path_Planning_2023a_B.SimulatedPositionController,
       &APF_Path_Planning_2023a_DW.SimulatedPositionController,
       &APF_Path_Planning_2023a_P.SimulatedPositionController);

    // End of SystemInitialize for SubSystem: '<S352>/Simulated Position Controller' 
    // End of SystemInitialize for SubSystem: '<S247>/RED+ARM'
    // End of SystemInitialize for SubSystem: '<S89>/Sub-Phase #4'
    // End of SystemInitialize for SubSystem: '<S9>/Change RED Behavior'
    // End of SystemInitialize for SubSystem: '<Root>/Phase #3: Experiment'

    // SystemInitialize for IfAction SubSystem: '<Root>/Phase #4: Return Home'
    APF_Path__Phase4ReturnHome_Init(&APF_Path_Planning_2023a_B.Phase4ReturnHome,
      &APF_Path_Planning_2023a_DW.Phase4ReturnHome,
      &APF_Path_Planning_2023a_P.Phase4ReturnHome);

    // End of SystemInitialize for SubSystem: '<Root>/Phase #4: Return Home'

    // SystemInitialize for IfAction SubSystem: '<Root>/Phase #5: Hold Home'
    APF_Path__Phase4ReturnHome_Init(&APF_Path_Planning_2023a_B.Phase5HoldHome,
      &APF_Path_Planning_2023a_DW.Phase5HoldHome,
      &APF_Path_Planning_2023a_P.Phase5HoldHome);

    // End of SystemInitialize for SubSystem: '<Root>/Phase #5: Hold Home'

    // SystemInitialize for IfAction SubSystem: '<Root>/Phase #6: Clean Shutdown' 
    // Start for If: '<S12>/This IF block determines whether or not to run the BLACK sim//exp' 
    APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhether_dt = -1;

    // Start for If: '<S12>/This IF block determines whether or not to run the BLUE sim//exp' 
    APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_f = -1;

    // Start for If: '<S12>/This IF block determines whether or not to run the RED sim//exp ' 
    APF_Path_Planning_2023a_DW.ThisIFblockdetermineswhethero_l = -1;

    // End of SystemInitialize for SubSystem: '<Root>/Phase #6: Clean Shutdown'

    // SystemInitialize for IfAction SubSystem: '<Root>/Simulate Plant Dynamics' 
    // InitializeConditions for DiscreteIntegrator: '<S571>/Acceleration  to Velocity' 
    APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE[0] =
      APF_Path_Planning_2023a_P.AccelerationtoVelocity_IC_p;

    // InitializeConditions for DiscreteIntegrator: '<S571>/Velocity to Position' 
    APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE[0] =
      APF_Path_Planning_2023a_P.drop_states_BLACK[0];

    // InitializeConditions for DiscreteIntegrator: '<S571>/Acceleration  to Velocity' 
    APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE[1] =
      APF_Path_Planning_2023a_P.AccelerationtoVelocity_IC_p;

    // InitializeConditions for DiscreteIntegrator: '<S571>/Velocity to Position' 
    APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE[1] =
      APF_Path_Planning_2023a_P.drop_states_BLACK[1];

    // InitializeConditions for DiscreteIntegrator: '<S571>/Acceleration  to Velocity' 
    APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE[2] =
      APF_Path_Planning_2023a_P.AccelerationtoVelocity_IC_p;

    // InitializeConditions for DiscreteIntegrator: '<S571>/Velocity to Position' 
    APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE[2] =
      APF_Path_Planning_2023a_P.drop_states_BLACK[2];

    // InitializeConditions for RandomNumber: '<S571>/Random Number'
    tmp = floor(APF_Path_Planning_2023a_P.RandomNumber_Seed_g);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_DW.RandSeed = ((((tseed - (static_cast<uint32_T>(i) <<
      16U)) + static_cast<uint32_T>(t)) << 16U) + static_cast<uint32_T>(t)) +
      static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_DW.RandSeed < 1U) {
      APF_Path_Planning_2023a_DW.RandSeed = 1144108930U;
    } else if (APF_Path_Planning_2023a_DW.RandSeed > 2147483646U) {
      APF_Path_Planning_2023a_DW.RandSeed = 2147483646U;
    }

    APF_Path_Planning_2023a_DW.NextOutput = APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_DW.RandSeed) * sqrt
      (APF_Path_Planning_2023a_P.noise_variance_BLACK) +
      APF_Path_Planning_2023a_P.RandomNumber_Mean_d;

    // End of InitializeConditions for RandomNumber: '<S571>/Random Number'

    // InitializeConditions for Delay: '<S577>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_ou = true;

    // InitializeConditions for Delay: '<S574>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_p4 = true;

    // InitializeConditions for RandomNumber: '<S568>/Random Number1'
    tmp = floor(APF_Path_Planning_2023a_P.RandomNumber1_Seed_j);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_DW.RandSeed_n = ((((tseed - (static_cast<uint32_T>(i)
      << 16U)) + static_cast<uint32_T>(t)) << 16U) + static_cast<uint32_T>(t)) +
      static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_DW.RandSeed_n < 1U) {
      APF_Path_Planning_2023a_DW.RandSeed_n = 1144108930U;
    } else if (APF_Path_Planning_2023a_DW.RandSeed_n > 2147483646U) {
      APF_Path_Planning_2023a_DW.RandSeed_n = 2147483646U;
    }

    APF_Path_Planning_2023a_DW.NextOutput_b = APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_DW.RandSeed_n) *
      APF_Path_Planning_2023a_P.RandomNumber1_StdDev_e +
      APF_Path_Planning_2023a_P.RandomNumber1_Mean_j;

    // End of InitializeConditions for RandomNumber: '<S568>/Random Number1'

    // InitializeConditions for Delay: '<S572>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_jc = true;

    // InitializeConditions for Delay: '<S575>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_jk = true;

    // InitializeConditions for RandomNumber: '<S568>/Random Number'
    tmp = floor(APF_Path_Planning_2023a_P.RandomNumber_Seed_d);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_DW.RandSeed_g = ((((tseed - (static_cast<uint32_T>(i)
      << 16U)) + static_cast<uint32_T>(t)) << 16U) + static_cast<uint32_T>(t)) +
      static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_DW.RandSeed_g < 1U) {
      APF_Path_Planning_2023a_DW.RandSeed_g = 1144108930U;
    } else if (APF_Path_Planning_2023a_DW.RandSeed_g > 2147483646U) {
      APF_Path_Planning_2023a_DW.RandSeed_g = 2147483646U;
    }

    APF_Path_Planning_2023a_DW.NextOutput_j = APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_DW.RandSeed_g) *
      APF_Path_Planning_2023a_P.RandomNumber_StdDev +
      APF_Path_Planning_2023a_P.RandomNumber_Mean_g;

    // End of InitializeConditions for RandomNumber: '<S568>/Random Number'

    // InitializeConditions for Delay: '<S573>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_jr = true;

    // InitializeConditions for Delay: '<S576>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_jko = true;

    // InitializeConditions for RandomNumber: '<S568>/Random Number2'
    tmp = floor(APF_Path_Planning_2023a_P.RandomNumber2_Seed_g);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_DW.RandSeed_m = ((((tseed - (static_cast<uint32_T>(i)
      << 16U)) + static_cast<uint32_T>(t)) << 16U) + static_cast<uint32_T>(t)) +
      static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_DW.RandSeed_m < 1U) {
      APF_Path_Planning_2023a_DW.RandSeed_m = 1144108930U;
    } else if (APF_Path_Planning_2023a_DW.RandSeed_m > 2147483646U) {
      APF_Path_Planning_2023a_DW.RandSeed_m = 2147483646U;
    }

    APF_Path_Planning_2023a_DW.NextOutput_g = APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_DW.RandSeed_m) *
      APF_Path_Planning_2023a_P.RandomNumber2_StdDev_c +
      APF_Path_Planning_2023a_P.RandomNumber2_Mean_b;

    // End of InitializeConditions for RandomNumber: '<S568>/Random Number2'

    // InitializeConditions for DiscreteIntegrator: '<S585>/Acceleration  to Velocity' 
    APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_i[0] =
      APF_Path_Planning_2023a_P.AccelerationtoVelocity_IC_e;

    // InitializeConditions for DiscreteIntegrator: '<S585>/Velocity to Position' 
    APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE_a[0] =
      APF_Path_Planning_2023a_P.drop_states_BLUE[0];

    // InitializeConditions for DiscreteIntegrator: '<S585>/Acceleration  to Velocity' 
    APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_i[1] =
      APF_Path_Planning_2023a_P.AccelerationtoVelocity_IC_e;

    // InitializeConditions for DiscreteIntegrator: '<S585>/Velocity to Position' 
    APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE_a[1] =
      APF_Path_Planning_2023a_P.drop_states_BLUE[1];

    // InitializeConditions for DiscreteIntegrator: '<S585>/Acceleration  to Velocity' 
    APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_i[2] =
      APF_Path_Planning_2023a_P.AccelerationtoVelocity_IC_e;

    // InitializeConditions for DiscreteIntegrator: '<S585>/Velocity to Position' 
    APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE_a[2] =
      APF_Path_Planning_2023a_P.drop_states_BLUE[2];

    // InitializeConditions for RandomNumber: '<S585>/Random Number'
    tmp = floor(APF_Path_Planning_2023a_P.RandomNumber_Seed_p);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_DW.RandSeed_o = ((((tseed - (static_cast<uint32_T>(i)
      << 16U)) + static_cast<uint32_T>(t)) << 16U) + static_cast<uint32_T>(t)) +
      static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_DW.RandSeed_o < 1U) {
      APF_Path_Planning_2023a_DW.RandSeed_o = 1144108930U;
    } else if (APF_Path_Planning_2023a_DW.RandSeed_o > 2147483646U) {
      APF_Path_Planning_2023a_DW.RandSeed_o = 2147483646U;
    }

    APF_Path_Planning_2023a_DW.NextOutput_a = APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_DW.RandSeed_o) * sqrt
      (APF_Path_Planning_2023a_P.noise_variance_BLUE) +
      APF_Path_Planning_2023a_P.RandomNumber_Mean_dq;

    // End of InitializeConditions for RandomNumber: '<S585>/Random Number'

    // InitializeConditions for Delay: '<S591>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_do = true;

    // InitializeConditions for Delay: '<S588>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_nk = true;

    // InitializeConditions for RandomNumber: '<S569>/Random Number4'
    tmp = floor(APF_Path_Planning_2023a_P.RandomNumber4_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_DW.RandSeed_n0 = ((((tseed - (static_cast<uint32_T>
      (i) << 16U)) + static_cast<uint32_T>(t)) << 16U) + static_cast<uint32_T>(t))
      + static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_DW.RandSeed_n0 < 1U) {
      APF_Path_Planning_2023a_DW.RandSeed_n0 = 1144108930U;
    } else if (APF_Path_Planning_2023a_DW.RandSeed_n0 > 2147483646U) {
      APF_Path_Planning_2023a_DW.RandSeed_n0 = 2147483646U;
    }

    APF__rt_nrand_Upu32_Yd_f_pw_snf(&APF_Path_Planning_2023a_DW.RandSeed_n0);

    // End of InitializeConditions for RandomNumber: '<S569>/Random Number4'

    // InitializeConditions for Delay: '<S586>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_ip = true;

    // InitializeConditions for Delay: '<S589>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_az = true;

    // InitializeConditions for RandomNumber: '<S569>/Random Number3'
    tmp = floor(APF_Path_Planning_2023a_P.RandomNumber3_Seed_m);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_DW.RandSeed_e = ((((tseed - (static_cast<uint32_T>(i)
      << 16U)) + static_cast<uint32_T>(t)) << 16U) + static_cast<uint32_T>(t)) +
      static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_DW.RandSeed_e < 1U) {
      APF_Path_Planning_2023a_DW.RandSeed_e = 1144108930U;
    } else if (APF_Path_Planning_2023a_DW.RandSeed_e > 2147483646U) {
      APF_Path_Planning_2023a_DW.RandSeed_e = 2147483646U;
    }

    APF__rt_nrand_Upu32_Yd_f_pw_snf(&APF_Path_Planning_2023a_DW.RandSeed_e);

    // End of InitializeConditions for RandomNumber: '<S569>/Random Number3'

    // InitializeConditions for Delay: '<S587>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_dh = true;

    // InitializeConditions for Delay: '<S590>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_ex = true;

    // InitializeConditions for RandomNumber: '<S569>/Random Number5'
    tmp = floor(APF_Path_Planning_2023a_P.RandomNumber5_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_DW.RandSeed_c = ((((tseed - (static_cast<uint32_T>(i)
      << 16U)) + static_cast<uint32_T>(t)) << 16U) + static_cast<uint32_T>(t)) +
      static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_DW.RandSeed_c < 1U) {
      APF_Path_Planning_2023a_DW.RandSeed_c = 1144108930U;
    } else if (APF_Path_Planning_2023a_DW.RandSeed_c > 2147483646U) {
      APF_Path_Planning_2023a_DW.RandSeed_c = 2147483646U;
    }

    APF__rt_nrand_Upu32_Yd_f_pw_snf(&APF_Path_Planning_2023a_DW.RandSeed_c);

    // End of InitializeConditions for RandomNumber: '<S569>/Random Number5'

    // SystemInitialize for IfAction SubSystem: '<S577>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S584>/In1' incorporates:
    //   Outport: '<S584>/Out1'

    APF_Path_Planning_2023a_B.In1_ps = APF_Path_Planning_2023a_P.Out1_Y0_n;

    // End of SystemInitialize for SubSystem: '<S577>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S574>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S581>/In1' incorporates:
    //   Outport: '<S581>/Out1'

    APF_Path_Planning_2023a_B.In1_j = APF_Path_Planning_2023a_P.Out1_Y0_g;

    // End of SystemInitialize for SubSystem: '<S574>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S572>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S579>/In1' incorporates:
    //   Outport: '<S579>/Out1'

    APF_Path_Planning_2023a_B.In1_pg = APF_Path_Planning_2023a_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S572>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S575>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S582>/In1' incorporates:
    //   Outport: '<S582>/Out1'

    APF_Path_Planning_2023a_B.In1_ex = APF_Path_Planning_2023a_P.Out1_Y0_gc;

    // End of SystemInitialize for SubSystem: '<S575>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S573>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S580>/In1' incorporates:
    //   Outport: '<S580>/Out1'

    APF_Path_Planning_2023a_B.In1_ib = APF_Path_Planning_2023a_P.Out1_Y0_a;

    // End of SystemInitialize for SubSystem: '<S573>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S576>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S583>/In1' incorporates:
    //   Outport: '<S583>/Out1'

    APF_Path_Planning_2023a_B.In1_cz = APF_Path_Planning_2023a_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S576>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S591>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S598>/In1' incorporates:
    //   Outport: '<S598>/Out1'

    APF_Path_Planning_2023a_B.In1_hq = APF_Path_Planning_2023a_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S591>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S586>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S593>/In1' incorporates:
    //   Outport: '<S593>/Out1'

    APF_Path_Planning_2023a_B.In1_gg = APF_Path_Planning_2023a_P.Out1_Y0_o;

    // End of SystemInitialize for SubSystem: '<S586>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S587>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S594>/In1' incorporates:
    //   Outport: '<S594>/Out1'

    APF_Path_Planning_2023a_B.In1_bh = APF_Path_Planning_2023a_P.Out1_Y0_ow;

    // End of SystemInitialize for SubSystem: '<S587>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S570>/RED + ARM'
    for (i = 0; i < 12; i++) {
      // InitializeConditions for Delay: '<S601>/Delay'
      APF_Path_Planning_2023a_DW.Delay_DSTATE_of[i] =
        APF_Path_Planning_2023a_P.Delay_InitialCondition;

      // InitializeConditions for DiscreteIntegrator: '<S601>/Acceleration  to Velocity' 
      APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_f[i] =
        APF_Path_Planning_2023a_P.AccelerationtoVelocity_IC[i];
    }

    // InitializeConditions for Delay: '<S606>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_bs = true;

    // InitializeConditions for RandomNumber: '<S601>/Random Number2'
    tmp = floor(APF_Path_Planning_2023a_P.RandomNumber2_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_DW.RandSeed_av = ((((tseed - (static_cast<uint32_T>
      (i) << 16U)) + static_cast<uint32_T>(t)) << 16U) + static_cast<uint32_T>(t))
      + static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_DW.RandSeed_av < 1U) {
      APF_Path_Planning_2023a_DW.RandSeed_av = 1144108930U;
    } else if (APF_Path_Planning_2023a_DW.RandSeed_av > 2147483646U) {
      APF_Path_Planning_2023a_DW.RandSeed_av = 2147483646U;
    }

    APF_Path_Planning_2023a_DW.NextOutput_f = APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_DW.RandSeed_av) *
      APF_Path_Planning_2023a_P.RandomNumber2_StdDev +
      APF_Path_Planning_2023a_P.RandomNumber2_Mean;

    // End of InitializeConditions for RandomNumber: '<S601>/Random Number2'

    // InitializeConditions for Delay: '<S605>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_n5 = true;

    // InitializeConditions for RandomNumber: '<S601>/Random Number1'
    tmp = floor(APF_Path_Planning_2023a_P.RandomNumber1_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_DW.RandSeed_a4 = ((((tseed - (static_cast<uint32_T>
      (i) << 16U)) + static_cast<uint32_T>(t)) << 16U) + static_cast<uint32_T>(t))
      + static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_DW.RandSeed_a4 < 1U) {
      APF_Path_Planning_2023a_DW.RandSeed_a4 = 1144108930U;
    } else if (APF_Path_Planning_2023a_DW.RandSeed_a4 > 2147483646U) {
      APF_Path_Planning_2023a_DW.RandSeed_a4 = 2147483646U;
    }

    APF_Path_Planning_2023a_DW.NextOutput_h = APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_DW.RandSeed_a4) *
      APF_Path_Planning_2023a_P.RandomNumber1_StdDev +
      APF_Path_Planning_2023a_P.RandomNumber1_Mean;

    // End of InitializeConditions for RandomNumber: '<S601>/Random Number1'

    // InitializeConditions for Delay: '<S607>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_mj = true;

    // InitializeConditions for RandomNumber: '<S601>/Random Number3'
    tmp = floor(APF_Path_Planning_2023a_P.RandomNumber3_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_DW.RandSeed_i = ((((tseed - (static_cast<uint32_T>(i)
      << 16U)) + static_cast<uint32_T>(t)) << 16U) + static_cast<uint32_T>(t)) +
      static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_DW.RandSeed_i < 1U) {
      APF_Path_Planning_2023a_DW.RandSeed_i = 1144108930U;
    } else if (APF_Path_Planning_2023a_DW.RandSeed_i > 2147483646U) {
      APF_Path_Planning_2023a_DW.RandSeed_i = 2147483646U;
    }

    APF_Path_Planning_2023a_DW.NextOutput_go = APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_DW.RandSeed_i) *
      APF_Path_Planning_2023a_P.RandomNumber3_StdDev +
      APF_Path_Planning_2023a_P.RandomNumber3_Mean;

    // End of InitializeConditions for RandomNumber: '<S601>/Random Number3'

    // SystemInitialize for IfAction SubSystem: '<S606>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S609>/In1' incorporates:
    //   Outport: '<S609>/Out1'

    APF_Path_Planning_2023a_B.In1_ff = APF_Path_Planning_2023a_P.Out1_Y0_asw;

    // End of SystemInitialize for SubSystem: '<S606>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S605>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S608>/In1' incorporates:
    //   Outport: '<S608>/Out1'

    APF_Path_Planning_2023a_B.In1_n = APF_Path_Planning_2023a_P.Out1_Y0_b;

    // End of SystemInitialize for SubSystem: '<S605>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S607>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S610>/In1' incorporates:
    //   Outport: '<S610>/Out1'

    APF_Path_Planning_2023a_B.In1_h = APF_Path_Planning_2023a_P.Out1_Y0_ea;

    // End of SystemInitialize for SubSystem: '<S607>/Hold this value'
    // End of SystemInitialize for SubSystem: '<S570>/RED + ARM'

    // SystemInitialize for IfAction SubSystem: '<S570>/RED Only'
    // InitializeConditions for DiscreteIntegrator: '<S612>/Acceleration  to Velocity' 
    APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_b[0] =
      APF_Path_Planning_2023a_P.AccelerationtoVelocity_IC_n;

    // InitializeConditions for DiscreteIntegrator: '<S612>/Velocity to Position' 
    APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE_m[0] =
      APF_Path_Planning_2023a_P.drop_states_RED[0];

    // InitializeConditions for DiscreteIntegrator: '<S612>/Acceleration  to Velocity' 
    APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_b[1] =
      APF_Path_Planning_2023a_P.AccelerationtoVelocity_IC_n;

    // InitializeConditions for DiscreteIntegrator: '<S612>/Velocity to Position' 
    APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE_m[1] =
      APF_Path_Planning_2023a_P.drop_states_RED[1];

    // InitializeConditions for DiscreteIntegrator: '<S612>/Acceleration  to Velocity' 
    APF_Path_Planning_2023a_DW.AccelerationtoVelocity_DSTATE_b[2] =
      APF_Path_Planning_2023a_P.AccelerationtoVelocity_IC_n;

    // InitializeConditions for DiscreteIntegrator: '<S612>/Velocity to Position' 
    APF_Path_Planning_2023a_DW.VelocitytoPosition_DSTATE_m[2] =
      APF_Path_Planning_2023a_P.drop_states_RED[2];

    // InitializeConditions for RandomNumber: '<S612>/Random Number'
    tmp = floor(APF_Path_Planning_2023a_P.RandomNumber_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_DW.RandSeed_k = ((((tseed - (static_cast<uint32_T>(i)
      << 16U)) + static_cast<uint32_T>(t)) << 16U) + static_cast<uint32_T>(t)) +
      static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_DW.RandSeed_k < 1U) {
      APF_Path_Planning_2023a_DW.RandSeed_k = 1144108930U;
    } else if (APF_Path_Planning_2023a_DW.RandSeed_k > 2147483646U) {
      APF_Path_Planning_2023a_DW.RandSeed_k = 2147483646U;
    }

    APF_Path_Planning_2023a_DW.NextOutput_i = APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_DW.RandSeed_k) * sqrt
      (APF_Path_Planning_2023a_P.noise_variance_RED) +
      APF_Path_Planning_2023a_P.RandomNumber_Mean;

    // End of InitializeConditions for RandomNumber: '<S612>/Random Number'

    // InitializeConditions for Delay: '<S614>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_nn = true;

    // InitializeConditions for Delay: '<S616>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_kb = true;

    // InitializeConditions for RandomNumber: '<S611>/Random Number7'
    tmp = floor(APF_Path_Planning_2023a_P.RandomNumber7_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_DW.RandSeed_a = ((((tseed - (static_cast<uint32_T>(i)
      << 16U)) + static_cast<uint32_T>(t)) << 16U) + static_cast<uint32_T>(t)) +
      static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_DW.RandSeed_a < 1U) {
      APF_Path_Planning_2023a_DW.RandSeed_a = 1144108930U;
    } else if (APF_Path_Planning_2023a_DW.RandSeed_a > 2147483646U) {
      APF_Path_Planning_2023a_DW.RandSeed_a = 2147483646U;
    }

    APF_Path_Planning_2023a_DW.NextOutput_n = APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_DW.RandSeed_a) *
      APF_Path_Planning_2023a_P.RandomNumber7_StdDev +
      APF_Path_Planning_2023a_P.RandomNumber7_Mean;

    // End of InitializeConditions for RandomNumber: '<S611>/Random Number7'

    // InitializeConditions for Delay: '<S613>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_jf = true;

    // InitializeConditions for Delay: '<S617>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_dk = true;

    // InitializeConditions for RandomNumber: '<S611>/Random Number6'
    tmp = floor(APF_Path_Planning_2023a_P.RandomNumber6_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_DW.RandSeed_f = ((((tseed - (static_cast<uint32_T>(i)
      << 16U)) + static_cast<uint32_T>(t)) << 16U) + static_cast<uint32_T>(t)) +
      static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_DW.RandSeed_f < 1U) {
      APF_Path_Planning_2023a_DW.RandSeed_f = 1144108930U;
    } else if (APF_Path_Planning_2023a_DW.RandSeed_f > 2147483646U) {
      APF_Path_Planning_2023a_DW.RandSeed_f = 2147483646U;
    }

    APF_Path_Planning_2023a_DW.NextOutput_ga = APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_DW.RandSeed_f) *
      APF_Path_Planning_2023a_P.RandomNumber6_StdDev +
      APF_Path_Planning_2023a_P.RandomNumber6_Mean;

    // End of InitializeConditions for RandomNumber: '<S611>/Random Number6'

    // InitializeConditions for Delay: '<S615>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_l1 = true;

    // InitializeConditions for Delay: '<S618>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_kp = true;

    // InitializeConditions for RandomNumber: '<S611>/Random Number8'
    tmp = floor(APF_Path_Planning_2023a_P.RandomNumber8_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_DW.RandSeed_h = ((((tseed - (static_cast<uint32_T>(i)
      << 16U)) + static_cast<uint32_T>(t)) << 16U) + static_cast<uint32_T>(t)) +
      static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_DW.RandSeed_h < 1U) {
      APF_Path_Planning_2023a_DW.RandSeed_h = 1144108930U;
    } else if (APF_Path_Planning_2023a_DW.RandSeed_h > 2147483646U) {
      APF_Path_Planning_2023a_DW.RandSeed_h = 2147483646U;
    }

    APF_Path_Planning_2023a_DW.NextOutput_l = APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_DW.RandSeed_h) *
      APF_Path_Planning_2023a_P.RandomNumber8_StdDev +
      APF_Path_Planning_2023a_P.RandomNumber8_Mean;

    // End of InitializeConditions for RandomNumber: '<S611>/Random Number8'

    // SystemInitialize for IfAction SubSystem: '<S614>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S621>/In1' incorporates:
    //   Outport: '<S621>/Out1'

    APF_Path_Planning_2023a_B.In1_g0 = APF_Path_Planning_2023a_P.Out1_Y0_l;

    // End of SystemInitialize for SubSystem: '<S614>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S616>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S623>/In1' incorporates:
    //   Outport: '<S623>/Out1'

    APF_Path_Planning_2023a_B.In1_gt = APF_Path_Planning_2023a_P.Out1_Y0_bf;

    // End of SystemInitialize for SubSystem: '<S616>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S613>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S620>/In1' incorporates:
    //   Outport: '<S620>/Out1'

    APF_Path_Planning_2023a_B.In1_fv = APF_Path_Planning_2023a_P.Out1_Y0_j;

    // End of SystemInitialize for SubSystem: '<S613>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S617>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S624>/In1' incorporates:
    //   Outport: '<S624>/Out1'

    APF_Path_Planning_2023a_B.In1_p = APF_Path_Planning_2023a_P.Out1_Y0_gt;

    // End of SystemInitialize for SubSystem: '<S617>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S615>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S622>/In1' incorporates:
    //   Outport: '<S622>/Out1'

    APF_Path_Planning_2023a_B.In1_aw = APF_Path_Planning_2023a_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S615>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S618>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S625>/In1' incorporates:
    //   Outport: '<S625>/Out1'

    APF_Path_Planning_2023a_B.In1_c = APF_Path_Planning_2023a_P.Out1_Y0_em;

    // End of SystemInitialize for SubSystem: '<S618>/Hold this value'
    // End of SystemInitialize for SubSystem: '<S570>/RED Only'
    // End of SystemInitialize for SubSystem: '<Root>/Simulate Plant Dynamics'

    // SystemInitialize for IfAction SubSystem: '<S1>/Change BLACK Behavior'
    APF_Pa_ChangeBLACKBehavior_Init(APF_Path_Planning_2023a_M,
      &APF_Path_Planning_2023a_DW.ChangeBLACKBehavior,
      &APF_Path_Planning_2023a_P.ChangeBLACKBehavior);

    // End of SystemInitialize for SubSystem: '<S1>/Change BLACK Behavior'

    // SystemInitialize for IfAction SubSystem: '<S1>/Change BLUE Behavior'
    APF_Pa_ChangeBLACKBehavior_Init(APF_Path_Planning_2023a_M,
      &APF_Path_Planning_2023a_DW.ChangeBLUEBehavior,
      &APF_Path_Planning_2023a_P.ChangeBLUEBehavior);

    // End of SystemInitialize for SubSystem: '<S1>/Change BLUE Behavior'

    // SystemInitialize for IfAction SubSystem: '<S1>/Change RED Behavior'
    // Start for S-Function (sdspToNetwork): '<S22>/UDP Send'
    sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_l[0U]);
    CreateUDPInterface(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_l[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_l[0U], 1,
                        "0.0.0.0", -1, "255.255.255.255",
                        APF_Path_Planning_2023a_P.UDPSend_Port, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_l[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_l[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S22>/UDP Send'
    // End of SystemInitialize for SubSystem: '<S1>/Change RED Behavior'

    // SystemInitialize for IfAction SubSystem: '<S4>/Enable Pucks'
    // Start for MATLABSystem: '<S25>/Set Pin 428 (Pucks) to HIGH'
    //  Constructor
    //  Support name-value pair arguments when constructing the object.
    APF_Path_Planning_2023a_DW.obj_p.matlabCodegenIsDeleted = false;
    APF_Path_Planning_2023a_DW.obj_p.gpioPin =
      APF_Path_Planning_2023a_P.SetPin428PuckstoHIGH_gpioPin;
    APF_Path_Planning_2023a_DW.obj_p.pinDirection =
      APF_Path_Planning_2023a_P.SetPin428PuckstoHIGH_pinDirecti;
    APF_Path_Planning_2023a_DW.obj_p.isInitialized = 1;

    //         %% Define input properties
    //  Call C-function implementing device initialization
    export_gpio(APF_Path_Planning_2023a_DW.obj_p.gpioPin);
    set_pin_direction(APF_Path_Planning_2023a_DW.obj_p.gpioPin,
                      APF_Path_Planning_2023a_DW.obj_p.pinDirection);
    APF_Path_Planning_2023a_DW.obj_p.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S4>/Enable Pucks'

    // SystemInitialize for IfAction SubSystem: '<S5>/Change RED Behavior'
    // InitializeConditions for Delay: '<S26>/Delay'
    APF_Path_Planning_2023a_DW.Delay_DSTATE_a =
      APF_Path_Planning_2023a_P.Delay_InitialCondition_f;

    // InitializeConditions for Delay: '<S26>/Delay1'
    APF_Path_Planning_2023a_DW.Delay1_DSTATE_pw =
      APF_Path_Planning_2023a_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S26>/Delay2'
    APF_Path_Planning_2023a_DW.Delay2_DSTATE =
      APF_Path_Planning_2023a_P.Delay2_InitialCondition;

    // Start for MATLABSystem: '<S26>/Read Joint Positions using  Dynamixel Encoders' 
    APF_Path_Planning_2023a_DW.obj_d.matlabCodegenIsDeleted = false;
    if (((!rtIsInf(APF_Path_Planning_2023a_P.baseRate)) && (!rtIsNaN
          (APF_Path_Planning_2023a_P.baseRate))) || rtIsInf
        (APF_Path_Planning_2023a_P.baseRate)) {
      sampleTime = APF_Path_Planning_2023a_P.baseRate;
    }

    APF_Path_Planning_2023a_DW.obj_d.SampleTime = sampleTime;
    APF_Path_Planning_2023a_DW.obj_d.isInitialized = 1;

    //         %% Define input properties
    //  Call C-function implementing device initialization
    APF_Path_Planning_2023a_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S26>/Read Joint Positions using  Dynamixel Encoders' 
    // End of SystemInitialize for SubSystem: '<S5>/Change RED Behavior'

    // SystemInitialize for IfAction SubSystem: '<S13>/Use Hardware to Obtain States' 
    // Start for S-Function (sdspFromNetwork): '<S524>/UDP Receive1'
    sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib_b
                          [0U]);
    CreateUDPInterface(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib_b[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib_b[0U],
                        0, "0.0.0.0", APF_Path_Planning_2023a_P.UDPReceive1_Port,
                        "0.0.0.0", -1, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib_b[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib_b
                          [0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S524>/UDP Receive1'

    // Start for If: '<S534>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_jt = -1;

    // Start for If: '<S531>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_lg = -1;

    // Start for If: '<S539>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ch = -1;

    // Start for If: '<S528>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_c5 = -1;

    // Start for If: '<S540>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ls = -1;

    // Start for If: '<S529>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_i2 = -1;

    // Start for If: '<S541>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_kz = -1;

    // Start for If: '<S530>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ed = -1;

    // Start for If: '<S535>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_o2 = -1;

    // Start for If: '<S532>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_cu = -1;

    // Start for If: '<S536>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_hb = -1;

    // Start for If: '<S533>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_fj = -1;

    // Start for If: '<S527>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ca = -1;

    // Start for If: '<S542>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_ez = -1;

    // Start for If: '<S537>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_oo = -1;

    // Start for If: '<S543>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_hv = -1;

    // Start for If: '<S538>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_ActiveS_lu = -1;

    // Start for If: '<S544>/if we went through a "step"'
    APF_Path_Planning_2023a_DW.ifwewentthroughastep_Active_lgb = -1;

    // Start for S-Function (sdspFromNetwork): '<S524>/UDP Receive'
    sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPReceive_NetworkLib[0U]);
    CreateUDPInterface(&APF_Path_Planning_2023a_DW.UDPReceive_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&APF_Path_Planning_2023a_DW.UDPReceive_NetworkLib[0U], 0,
                        "0.0.0.0", APF_Path_Planning_2023a_P.UDPReceive_Port,
                        "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&APF_Path_Planning_2023a_DW.UDPReceive_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&APF_Path_Planning_2023a_DW.UDPReceive_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S524>/UDP Receive'

    // Start for S-Function (sdspFromNetwork): '<S524>/UDP Receive2'
    sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPReceive2_NetworkLib[0U]);
    CreateUDPInterface(&APF_Path_Planning_2023a_DW.UDPReceive2_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&APF_Path_Planning_2023a_DW.UDPReceive2_NetworkLib[0U],
                        0, "0.0.0.0", APF_Path_Planning_2023a_P.UDPReceive2_Port,
                        "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&APF_Path_Planning_2023a_DW.UDPReceive2_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&APF_Path_Planning_2023a_DW.UDPReceive2_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S524>/UDP Receive2'

    // Start for S-Function (sdspFromNetwork): '<S524>/UDP Receive3'
    sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPReceive3_NetworkLib[0U]);
    CreateUDPInterface(&APF_Path_Planning_2023a_DW.UDPReceive3_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&APF_Path_Planning_2023a_DW.UDPReceive3_NetworkLib[0U],
                        0, "0.0.0.0", APF_Path_Planning_2023a_P.UDPReceive3_Port,
                        "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&APF_Path_Planning_2023a_DW.UDPReceive3_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&APF_Path_Planning_2023a_DW.UDPReceive3_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S524>/UDP Receive3'

    // InitializeConditions for Delay: '<S534>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_lu = true;

    // InitializeConditions for Delay: '<S531>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_ld = true;

    // InitializeConditions for Delay: '<S539>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_dc = true;

    // InitializeConditions for Delay: '<S528>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_k = true;

    // InitializeConditions for Delay: '<S540>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_fv = true;

    // InitializeConditions for Delay: '<S529>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_na = true;

    // InitializeConditions for S-Function (sdspunwrap2): '<S524>/Unwrap1'
    APF_Path_Planning_2023a_DW.Unwrap1_FirstStep = true;

    // InitializeConditions for Delay: '<S541>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_gx = true;

    // InitializeConditions for Delay: '<S530>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_m = true;

    // InitializeConditions for Delay: '<S535>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_e = true;

    // InitializeConditions for Delay: '<S532>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_fpv = true;

    // InitializeConditions for S-Function (sdspunwrap2): '<S524>/Unwrap2'
    APF_Path_Planning_2023a_DW.Unwrap2_FirstStep = true;

    // InitializeConditions for Delay: '<S536>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_mt = true;

    // InitializeConditions for Delay: '<S533>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_nw = true;

    // InitializeConditions for Delay: '<S527>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_h = true;

    // InitializeConditions for Delay: '<S542>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_au = true;

    // InitializeConditions for Delay: '<S537>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_eo = true;

    // InitializeConditions for Delay: '<S543>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_fh = true;

    // InitializeConditions for S-Function (sdspunwrap2): '<S524>/Unwrap'
    APF_Path_Planning_2023a_DW.Unwrap_FirstStep = true;

    // InitializeConditions for Delay: '<S538>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_fow = true;

    // InitializeConditions for Delay: '<S544>/Delay1'
    APF_Path_Planning_2023a_DW.icLoad_aq = true;
    for (i = 0; i < 5; i++) {
      // InitializeConditions for Delay: '<S524>/Delay'
      APF_Path_Planning_2023a_DW.Delay_DSTATE_l[i] =
        APF_Path_Planning_2023a_P.Delay_InitialCondition_g;

      // InitializeConditions for Delay: '<S524>/Delay1'
      APF_Path_Planning_2023a_DW.Delay1_DSTATE_hu[i] =
        APF_Path_Planning_2023a_P.Delay1_InitialCondition_h;

      // InitializeConditions for Delay: '<S524>/Delay2'
      APF_Path_Planning_2023a_DW.Delay2_DSTATE_k[i] =
        APF_Path_Planning_2023a_P.Delay2_InitialCondition_j;
    }

    // SystemInitialize for IfAction SubSystem: '<S534>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S554>/In1' incorporates:
    //   Outport: '<S554>/Out1'

    APF_Path_Planning_2023a_B.In1_em = APF_Path_Planning_2023a_P.Out1_Y0_hp;

    // End of SystemInitialize for SubSystem: '<S534>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S539>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S559>/In1' incorporates:
    //   Outport: '<S559>/Out1'

    APF_Path_Planning_2023a_B.In1_f = APF_Path_Planning_2023a_P.Out1_Y0_ck;

    // End of SystemInitialize for SubSystem: '<S539>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S528>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S548>/In1' incorporates:
    //   Outport: '<S548>/Out1'

    APF_Path_Planning_2023a_B.In1_i = APF_Path_Planning_2023a_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S528>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S540>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S560>/In1' incorporates:
    //   Outport: '<S560>/Out1'

    APF_Path_Planning_2023a_B.In1_l = APF_Path_Planning_2023a_P.Out1_Y0_ii;

    // End of SystemInitialize for SubSystem: '<S540>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S529>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S549>/In1' incorporates:
    //   Outport: '<S549>/Out1'

    APF_Path_Planning_2023a_B.In1_bk = APF_Path_Planning_2023a_P.Out1_Y0_m3;

    // End of SystemInitialize for SubSystem: '<S529>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S541>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S561>/In1' incorporates:
    //   Outport: '<S561>/Out1'

    APF_Path_Planning_2023a_B.In1_e0 = APF_Path_Planning_2023a_P.Out1_Y0_l2;

    // End of SystemInitialize for SubSystem: '<S541>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S530>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S550>/In1' incorporates:
    //   Outport: '<S550>/Out1'

    APF_Path_Planning_2023a_B.In1_gr = APF_Path_Planning_2023a_P.Out1_Y0_m34;

    // End of SystemInitialize for SubSystem: '<S530>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S535>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S555>/In1' incorporates:
    //   Outport: '<S555>/Out1'

    APF_Path_Planning_2023a_B.In1_en = APF_Path_Planning_2023a_P.Out1_Y0_p0;

    // End of SystemInitialize for SubSystem: '<S535>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S536>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S556>/In1' incorporates:
    //   Outport: '<S556>/Out1'

    APF_Path_Planning_2023a_B.In1_m = APF_Path_Planning_2023a_P.Out1_Y0_iy;

    // End of SystemInitialize for SubSystem: '<S536>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S527>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S547>/In1' incorporates:
    //   Outport: '<S547>/Out1'

    APF_Path_Planning_2023a_B.In1_a = APF_Path_Planning_2023a_P.Out1_Y0_lf;

    // End of SystemInitialize for SubSystem: '<S527>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S542>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S562>/In1' incorporates:
    //   Outport: '<S562>/Out1'

    APF_Path_Planning_2023a_B.In1_o = APF_Path_Planning_2023a_P.Out1_Y0_nz;

    // End of SystemInitialize for SubSystem: '<S542>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S537>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S557>/In1' incorporates:
    //   Outport: '<S557>/Out1'

    APF_Path_Planning_2023a_B.In1_b = APF_Path_Planning_2023a_P.Out1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S537>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S543>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S563>/In1' incorporates:
    //   Outport: '<S563>/Out1'

    APF_Path_Planning_2023a_B.In1_e = APF_Path_Planning_2023a_P.Out1_Y0_fr;

    // End of SystemInitialize for SubSystem: '<S543>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S538>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S558>/In1' incorporates:
    //   Outport: '<S558>/Out1'

    APF_Path_Planning_2023a_B.In1_eg = APF_Path_Planning_2023a_P.Out1_Y0_d0;

    // End of SystemInitialize for SubSystem: '<S538>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S544>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S564>/In1' incorporates:
    //   Outport: '<S564>/Out1'

    APF_Path_Planning_2023a_B.In1_g20asdtgi0cdyix =
      APF_Path_Planning_2023a_P.Out1_Y0_e1;

    // End of SystemInitialize for SubSystem: '<S544>/Hold this value'

    // SystemInitialize for Enabled SubSystem: '<S525>/Enabled Subsystem'
    // InitializeConditions for Memory: '<S545>/Memory'
    APF_Path_Planning_2023a_DW.Memory_PreviousInput =
      APF_Path_Planning_2023a_P.Memory_InitialCondition;

    // SystemInitialize for Memory: '<S545>/Memory' incorporates:
    //   Outport: '<S545>/Out1'

    APF_Path_Planning_2023a_B.Memory = APF_Path_Planning_2023a_P.Out1_Y0_m;

    // End of SystemInitialize for SubSystem: '<S525>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S525>/Enabled Subsystem1'
    // SystemInitialize for Sum: '<S546>/Subtract' incorporates:
    //   Outport: '<S546>/Out1'

    APF_Path_Planning_2023a_B.Subtract_l = APF_Path_Planning_2023a_P.Out1_Y0_ei;

    // End of SystemInitialize for SubSystem: '<S525>/Enabled Subsystem1'
    // End of SystemInitialize for SubSystem: '<S13>/Use Hardware to Obtain States' 

    // SystemInitialize for IfAction SubSystem: '<S14>/Subsystem'
    // Start for MATLABSystem: '<S565>/WhoAmI'
    //  Constructor
    //  Support name-value pair arguments when constructing the object.
    APF_Path_Planning_2023a_DW.obj_dk.matlabCodegenIsDeleted = false;
    if (((!rtIsInf(APF_Path_Planning_2023a_P.baseRate)) && (!rtIsNaN
          (APF_Path_Planning_2023a_P.baseRate))) || rtIsInf
        (APF_Path_Planning_2023a_P.baseRate)) {
      sampleTime_0 = APF_Path_Planning_2023a_P.baseRate;
    }

    APF_Path_Planning_2023a_DW.obj_dk.SampleTime = sampleTime_0;
    APF_Path_Planning_2023a_DW.obj_dk.isInitialized = 1;

    //         %% Define output properties
    //  Call C-function implementing device initialization
    APF_Path_Planning_2023a_DW.obj_dk.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S565>/WhoAmI'
    // End of SystemInitialize for SubSystem: '<S14>/Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S15>/Change RED Behavior'
    // Start for MATLABSystem: '<S566>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
    //  Constructor
    //  Support name-value pair arguments when constructing the object.
    APF_Path_Planning_2023a_DW.obj.matlabCodegenIsDeleted = false;
    APF_Path_Planning_2023a_DW.obj.POSITION_P_GAIN =
      APF_Path_Planning_2023a_P.ControlDynamixelActuatorsineith;
    APF_Path_Planning_2023a_DW.obj.POSITION_I_GAIN =
      APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_c;
    APF_Path_Planning_2023a_DW.obj.POSITION_D_GAIN =
      APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_d;
    APF_Path_Planning_2023a_DW.obj.MAX_POSITION =
      APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_n;
    APF_Path_Planning_2023a_DW.obj.MIN_POSITION =
      APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_g;
    APF_Path_Planning_2023a_DW.obj.MOVE_TIME =
      APF_Path_Planning_2023a_P.ControlDynamixelActuatorsine_cw;
    APF_Path_Planning_2023a_DW.obj.CURRENT_LIMIT =
      APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_e;
    APF_Path_Planning_2023a_DW.obj.SPEED_P_GAIN =
      APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_k;
    APF_Path_Planning_2023a_DW.obj.SPEED_I_GAIN =
      APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_j;
    APF_Path_Planning_2023a_DW.obj.VELOCITY_LIMIT =
      APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_l;
    APF_Path_Planning_2023a_DW.obj.ACCELERATION_TIME =
      APF_Path_Planning_2023a_P.ControlDynamixelActuatorsinei_o;
    if (((!rtIsInf(APF_Path_Planning_2023a_P.baseRate)) && (!rtIsNaN
          (APF_Path_Planning_2023a_P.baseRate))) || rtIsInf
        (APF_Path_Planning_2023a_P.baseRate)) {
      sampleTime_1 = APF_Path_Planning_2023a_P.baseRate;
    }

    APF_Path_Planning_2023a_DW.obj.SampleTime = sampleTime_1;
    APF_Path_Planning_2023a_DW.obj.isInitialized = 1;

    //         %% Define input properties
    initialize_dynamixel();
    APF_Path_Planning_2023a_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S566>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
    // End of SystemInitialize for SubSystem: '<S15>/Change RED Behavior'

    // SystemInitialize for IfAction SubSystem: '<S16>/Subsystem'
    // Start for S-Function (sdspToNetwork): '<S567>/UDP Send'
    sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_m[0U]);
    CreateUDPInterface(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_m[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_m[0U], 1,
                        "0.0.0.0", -1, "192.168.1.113",
                        APF_Path_Planning_2023a_P.UDPSend_Port_d, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_m[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_m[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S567>/UDP Send'
    // End of SystemInitialize for SubSystem: '<S16>/Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S19>/Change BLUE Behavior'
    // SystemInitialize for IfAction SubSystem: '<S19>/Change BLACK Behavior'
    // SystemInitialize for IfAction SubSystem: '<S19>/Change RED Behavior'
    for (i = 0; i < 8; i++) {
      // SystemInitialize for Outport: '<S628>/RED PWM'
      APF_Path_Planning_2023a_B.ThrustPer_Final[i] =
        APF_Path_Planning_2023a_P.REDPWM_Y0;

      // SystemInitialize for Outport: '<S626>/BLACK PWM'
      APF_Path_Planning_2023a_B.ThrustPer_Final_d[i] =
        APF_Path_Planning_2023a_P.BLACKPWM_Y0;

      // SystemInitialize for Outport: '<S627>/BLUE PWM'
      APF_Path_Planning_2023a_B.ThrustPer_Final_e[i] =
        APF_Path_Planning_2023a_P.BLUEPWM_Y0;
    }

    // End of SystemInitialize for SubSystem: '<S19>/Change RED Behavior'
    // End of SystemInitialize for SubSystem: '<S19>/Change BLACK Behavior'
    // End of SystemInitialize for SubSystem: '<S19>/Change BLUE Behavior'

    // Start for MATLABSystem: '<S23>/MATLAB System'
    //  Constructor
    //  Support name-value pair arguments when constructing the object.
    APF_Path_Planning_2023a_DW.obj_i.matlabCodegenIsDeleted = false;
    APF_Path_Planning_2023a_DW.obj_i.isInitialized = 1;

    //         %% Define input properties
    //  Call C-function implementing device initialization
    createFile();
    APF_Path_Planning_2023a_DW.obj_i.isSetupComplete = true;
  }
}

// Model terminate function
void APF_Path_Planning_2023a_terminate(void)
{
  char_T *sErr;

  // Terminate for S-Function (sdspFromNetwork): '<S2>/UDP Receive1'
  sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib[0U]);
  LibTerminate(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
    rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
  }

  LibDestroy(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib[0U], 0);
  DestroyUDPInterface(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S2>/UDP Receive1'

  // Terminate for IfAction SubSystem: '<S1>/Change BLACK Behavior'
  APF_Pa_ChangeBLACKBehavior_Term(APF_Path_Planning_2023a_M,
    &APF_Path_Planning_2023a_DW.ChangeBLACKBehavior);

  // End of Terminate for SubSystem: '<S1>/Change BLACK Behavior'

  // Terminate for IfAction SubSystem: '<S1>/Change BLUE Behavior'
  APF_Pa_ChangeBLACKBehavior_Term(APF_Path_Planning_2023a_M,
    &APF_Path_Planning_2023a_DW.ChangeBLUEBehavior);

  // End of Terminate for SubSystem: '<S1>/Change BLUE Behavior'

  // Terminate for IfAction SubSystem: '<S1>/Change RED Behavior'
  // Terminate for S-Function (sdspToNetwork): '<S22>/UDP Send'
  sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_l[0U]);
  LibTerminate(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_l[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
    rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
  }

  LibDestroy(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_l[0U], 1);
  DestroyUDPInterface(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_l[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S22>/UDP Send'
  // End of Terminate for SubSystem: '<S1>/Change RED Behavior'

  // Terminate for MATLABSystem: '<S23>/MATLAB System'
  if (!APF_Path_Planning_2023a_DW.obj_i.matlabCodegenIsDeleted) {
    APF_Path_Planning_2023a_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S23>/MATLAB System'

  // Terminate for IfAction SubSystem: '<S4>/Enable Pucks'
  // Terminate for MATLABSystem: '<S25>/Set Pin 428 (Pucks) to HIGH'
  if (!APF_Path_Planning_2023a_DW.obj_p.matlabCodegenIsDeleted) {
    APF_Path_Planning_2023a_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((APF_Path_Planning_2023a_DW.obj_p.isInitialized == 1) &&
        APF_Path_Planning_2023a_DW.obj_p.isSetupComplete) {
      //  Call C-function implementing device termination
      change_gpio_value(APF_Path_Planning_2023a_DW.obj_p.gpioPin, 0.0);
      unexport_gpio(APF_Path_Planning_2023a_DW.obj_p.gpioPin);
    }
  }

  // End of Terminate for MATLABSystem: '<S25>/Set Pin 428 (Pucks) to HIGH'
  // End of Terminate for SubSystem: '<S4>/Enable Pucks'

  // Terminate for IfAction SubSystem: '<S5>/Change RED Behavior'
  // Terminate for MATLABSystem: '<S26>/Read Joint Positions using  Dynamixel Encoders' 
  if (!APF_Path_Planning_2023a_DW.obj_d.matlabCodegenIsDeleted) {
    APF_Path_Planning_2023a_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S26>/Read Joint Positions using  Dynamixel Encoders' 
  // End of Terminate for SubSystem: '<S5>/Change RED Behavior'

  // Terminate for IfAction SubSystem: '<S13>/Use Hardware to Obtain States'
  // Terminate for S-Function (sdspFromNetwork): '<S524>/UDP Receive1'
  sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib_b[0U]);
  LibTerminate(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib_b[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
    rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
  }

  LibDestroy(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib_b[0U], 0);
  DestroyUDPInterface(&APF_Path_Planning_2023a_DW.UDPReceive1_NetworkLib_b[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S524>/UDP Receive1'

  // Terminate for S-Function (sdspFromNetwork): '<S524>/UDP Receive'
  sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPReceive_NetworkLib[0U]);
  LibTerminate(&APF_Path_Planning_2023a_DW.UDPReceive_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
    rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
  }

  LibDestroy(&APF_Path_Planning_2023a_DW.UDPReceive_NetworkLib[0U], 0);
  DestroyUDPInterface(&APF_Path_Planning_2023a_DW.UDPReceive_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S524>/UDP Receive'

  // Terminate for S-Function (sdspFromNetwork): '<S524>/UDP Receive2'
  sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPReceive2_NetworkLib[0U]);
  LibTerminate(&APF_Path_Planning_2023a_DW.UDPReceive2_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
    rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
  }

  LibDestroy(&APF_Path_Planning_2023a_DW.UDPReceive2_NetworkLib[0U], 0);
  DestroyUDPInterface(&APF_Path_Planning_2023a_DW.UDPReceive2_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S524>/UDP Receive2'

  // Terminate for S-Function (sdspFromNetwork): '<S524>/UDP Receive3'
  sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPReceive3_NetworkLib[0U]);
  LibTerminate(&APF_Path_Planning_2023a_DW.UDPReceive3_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
    rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
  }

  LibDestroy(&APF_Path_Planning_2023a_DW.UDPReceive3_NetworkLib[0U], 0);
  DestroyUDPInterface(&APF_Path_Planning_2023a_DW.UDPReceive3_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S524>/UDP Receive3'
  // End of Terminate for SubSystem: '<S13>/Use Hardware to Obtain States'

  // Terminate for IfAction SubSystem: '<S14>/Subsystem'
  // Terminate for MATLABSystem: '<S565>/WhoAmI'
  if (!APF_Path_Planning_2023a_DW.obj_dk.matlabCodegenIsDeleted) {
    APF_Path_Planning_2023a_DW.obj_dk.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S565>/WhoAmI'
  // End of Terminate for SubSystem: '<S14>/Subsystem'

  // Terminate for IfAction SubSystem: '<S15>/Change RED Behavior'
  // Terminate for MATLABSystem: '<S566>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
  if (!APF_Path_Planning_2023a_DW.obj.matlabCodegenIsDeleted) {
    APF_Path_Planning_2023a_DW.obj.matlabCodegenIsDeleted = true;
    if ((APF_Path_Planning_2023a_DW.obj.isInitialized == 1) &&
        APF_Path_Planning_2023a_DW.obj.isSetupComplete) {
      terminate_dynamixel();
    }
  }

  // End of Terminate for MATLABSystem: '<S566>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
  // End of Terminate for SubSystem: '<S15>/Change RED Behavior'

  // Terminate for IfAction SubSystem: '<S16>/Subsystem'
  // Terminate for S-Function (sdspToNetwork): '<S567>/UDP Send'
  sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_m[0U]);
  LibTerminate(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_m[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
    rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
  }

  LibDestroy(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_m[0U], 1);
  DestroyUDPInterface(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib_m[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S567>/UDP Send'
  // End of Terminate for SubSystem: '<S16>/Subsystem'

  // Terminate for S-Function (sdspToNetwork): '<S19>/UDP Send'
  sErr = GetErrorBuffer(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib[0U]);
  LibTerminate(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(APF_Path_Planning_2023a_M, sErr);
    rtmSetStopRequested(APF_Path_Planning_2023a_M, 1);
  }

  LibDestroy(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib[0U], 1);
  DestroyUDPInterface(&APF_Path_Planning_2023a_DW.UDPSend_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S19>/UDP Send'
}

//
// File trailer for generated code.
//
// [EOF]
//
