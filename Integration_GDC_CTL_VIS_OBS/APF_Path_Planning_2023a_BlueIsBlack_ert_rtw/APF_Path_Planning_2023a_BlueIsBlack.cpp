//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: APF_Path_Planning_2023a_BlueIsBlack.cpp
//
// Code generated for Simulink model 'APF_Path_Planning_2023a_BlueIsBlack'.
//
// Model version                  : 1.1017
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Mon Apr  1 17:55:30 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "APF_Path_Planning_2023a_BlueIsBlack.h"
#include "rtwtypes.h"
#include "APF_Path_Planning_2023a_BlueIsBlack_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"
#include <string.h>

// Block signals (default storage)
B_APF_Path_Planning_2023a_Blu_T APF_Path_Planning_2023a_BlueI_B;

// Block states (default storage)
DW_APF_Path_Planning_2023a_Bl_T APF_Path_Planning_2023a_Blue_DW;

// Real-time model
RT_MODEL_APF_Path_Planning_20_T APF_Path_Planning_2023a_Blue_M_ =
  RT_MODEL_APF_Path_Planning_20_T();
RT_MODEL_APF_Path_Planning_20_T *const APF_Path_Planning_2023a_Blue_M =
  &APF_Path_Planning_2023a_Blue_M_;

// Forward declaration for local functions
static real_T APF_Path_Planning_2023a_maximum(const real_T x[8]);

// Forward declaration for local functions
static real_T APF_Path_Planning_202_maximum_p(const real_T x[8]);

// Forward declaration for local functions
static void APF_Path_Planning_2023a_xzlascl(real_T cfrom, real_T cto, real_T A
  [36]);
static real_T APF_Path_Planning_2023a_xnrm2_m(int32_T n, const real_T x[36],
  int32_T ix0);
static real_T APF_Path_Planning_rt_hypotd_snf(real_T u0, real_T u1);
static real_T APF_Path_Planning_2023a_xzlarfg(int32_T n, real_T *alpha1, real_T
  x[36], int32_T ix0);
static void APF_Path_Planning_2023a_xzgehrd(real_T a[36], int32_T ilo, int32_T
  ihi);
static real_T APF_Path_Planning_2023_xnrm2_mw(int32_T n, const real_T x[3]);
static void APF_Path_Planning_2023a_xdlanv2(real_T *a, real_T *b, real_T *c,
  real_T *d, real_T *rt1r, real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs,
  real_T *sn);
static void APF_Path_Planning_2023a_xdlahqr(int32_T ilo, int32_T ihi, real_T h
  [36], int32_T *info, real_T *z, real_T wr[6], real_T wi[6]);
static void APF_Path_Planning_202_xzlascl_f(real_T cfrom, real_T cto, int32_T
  b_m, real_T A[6], int32_T iA0);
static void APF_Path_Planning_2_eigStandard(const real_T A[36], creal_T V[6]);
static void APF_Path_Planning_20_xzlascl_fe(real_T cfrom, real_T cto, int32_T
  b_m, real_T A[5], int32_T iA0);
static void APF_Path_Planning_2023a_xdlaev2(real_T a, real_T b, real_T c, real_T
  *rt1, real_T *rt2);
static void APF_Path_Planning_insertionsort(real_T x[6], int32_T xstart, int32_T
  xend);
static int32_T APF_Path_Planning_2023a_xdsterf(real_T d[6], real_T e[5]);
static void APF_Path_Planning_2023a_Blu_eig(const real_T A[36], creal_T V[6]);
static void APF_Path_Plann_binary_expand_op(real_T in1_data[], int32_T in1_size
  [2], const real_T in2[36], int32_T in3, int32_T in4);
static real_T APF_Path_Planning_rt_atan2d_snf(real_T u0, real_T u1);
static real_T APF_Path_Planning_2_rt_powd_snf(real_T u0, real_T u1);
static real_T APF__rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
static real_T APF__rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);
static real_T APF_Path_Planning_2023a_B_xnrm2(int32_T n, const real_T x[36],
  int32_T ix0);
static real_T APF_Path_Planning_2023a_B_xdotc(int32_T n, const real_T x[36],
  int32_T ix0, const real_T y[36], int32_T iy0);
static void APF_Path_Planning_2023a_B_xaxpy(int32_T n, real_T a, int32_T ix0,
  real_T y[36], int32_T iy0);
static real_T APF_Path_Planning_2023a_xnrm2_c(int32_T n, const real_T x[6],
  int32_T ix0);
static void APF_Path_Planning_2023a_xaxpy_j(int32_T n, real_T a, const real_T x
  [36], int32_T ix0, real_T y[6], int32_T iy0);
static void APF_Path_Planning_2023_xaxpy_jv(int32_T n, real_T a, const real_T x
  [6], int32_T ix0, real_T y[36], int32_T iy0);
static void APF_Path_Planning_2023a_B_xswap(real_T x[36], int32_T ix0, int32_T
  iy0);
static void APF_Path_Planning_2023a_B_xrotg(real_T *a, real_T *b, real_T *c,
  real_T *s);
static void APF_Path_Planning_2023a_Bl_xrot(real_T x[36], int32_T ix0, int32_T
  iy0, real_T c, real_T s);
static void APF_Path_Planning_2023a_Blu_svd(const real_T A[36], real_T U[36],
  real_T s[6], real_T V[36]);
static void APF_Path_Plannin_rt_invd3x3_snf(const real_T u[9], real_T y[9]);
int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

//
// System initialize for action system:
//    '<S1>/Change BLACK Behavior'
//    '<S1>/Change BLUE Behavior'
//
void APF_Pa_ChangeBLACKBehavior_Init(RT_MODEL_APF_Path_Planning_20_T * const
  APF_Path_Planning_2023a_Blue_M, DW_ChangeBLACKBehavior_APF_Pa_T *localDW,
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
      rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
      rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
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
  APF_Path_Planning_2023a_Blue_M, DW_ChangeBLACKBehavior_APF_Pa_T *localDW,
  P_ChangeBLACKBehavior_APF_Pat_T *localP)
{
  char_T *sErr;

  // Update for S-Function (sdspToNetwork): '<S20>/UDP Send' incorporates:
  //   Constant: '<S20>/Constant1'

  sErr = GetErrorBuffer(&localDW->UDPSend_NetworkLib[0U]);
  LibUpdate_Network(&localDW->UDPSend_NetworkLib[0U], &localP->Constant1_Value,
                    1);
  if (*sErr != 0) {
    rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
    rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
  }

  // End of Update for S-Function (sdspToNetwork): '<S20>/UDP Send'
}

//
// Termination for action system:
//    '<S1>/Change BLACK Behavior'
//    '<S1>/Change BLUE Behavior'
//
void APF_Pa_ChangeBLACKBehavior_Term(RT_MODEL_APF_Path_Planning_20_T * const
  APF_Path_Planning_2023a_Blue_M, DW_ChangeBLACKBehavior_APF_Pa_T *localDW)
{
  char_T *sErr;

  // Terminate for S-Function (sdspToNetwork): '<S20>/UDP Send'
  sErr = GetErrorBuffer(&localDW->UDPSend_NetworkLib[0U]);
  LibTerminate(&localDW->UDPSend_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
    rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
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
void APF_Path_Pla_ChangeBLUEBehavior(real_T *rtd_BLUE_Fx, real_T *rtd_BLUE_Fy,
  real_T *rtd_BLUE_Tz, real_T *rtd_Float_State, P_ChangeBLUEBehavior_APF_Path_T *
  localP)
{
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
void APF_Path__Phase0Synchronization(real_T *rtd_BLACK_Fx, real_T *rtd_BLACK_Fy,
  real_T *rtd_BLACK_Tz, real_T *rtd_BLUE_Fx, real_T *rtd_BLUE_Fy, real_T
  *rtd_BLUE_Tz, real_T *rtd_Float_State, real_T *rtd_RED_ARM_Control_Mode,
  real_T *rtd_RED_Fx, real_T *rtd_RED_Fy, real_T *rtd_RED_Tz, real_T
  *rtd_RED_Tz_RW, const real_T *rtd_WhoAmI, const real_T *rtd_isSim,
  DW_Phase0Synchronization_APF__T *localDW, P_Phase0Synchronization_APF_P_T
  *localP)
{
  // If: '<S6>/This IF block determines whether or not to run the BLACK sim//exp' 
  localDW->ThisIFblockdetermineswhetherorn = -1;
  if ((*rtd_WhoAmI == 2.0) || (*rtd_isSim == 1.0)) {
    localDW->ThisIFblockdetermineswhetherorn = 0;

    // Outputs for IfAction SubSystem: '<S6>/Change BLACK Behavior' incorporates:
    //   ActionPort: '<S27>/Action Port'

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

    // End of Outputs for SubSystem: '<S6>/Change BLACK Behavior'
  }

  // End of If: '<S6>/This IF block determines whether or not to run the BLACK sim//exp' 

  // If: '<S6>/This IF block determines whether or not to run the BLUE sim//exp' 
  localDW->ThisIFblockdetermineswhethero_d = -1;
  if ((*rtd_WhoAmI == 3.0) || (*rtd_isSim == 1.0)) {
    localDW->ThisIFblockdetermineswhethero_d = 0;

    // Outputs for IfAction SubSystem: '<S6>/Change BLUE Behavior' incorporates:
    //   ActionPort: '<S28>/Action Port'

    APF_Path_Pla_ChangeBLUEBehavior(rtd_BLUE_Fx, rtd_BLUE_Fy, rtd_BLUE_Tz,
      rtd_Float_State, &localP->ChangeBLUEBehavior);

    // End of Outputs for SubSystem: '<S6>/Change BLUE Behavior'
  }

  // End of If: '<S6>/This IF block determines whether or not to run the BLUE sim//exp' 

  // If: '<S6>/This IF block determines whether or not to run the RED sim//exp ' 
  localDW->ThisIFblockdetermineswhethero_e = -1;
  if ((*rtd_WhoAmI == 1.0) || (*rtd_isSim == 1.0)) {
    localDW->ThisIFblockdetermineswhethero_e = 0;

    // Outputs for IfAction SubSystem: '<S6>/Change RED Behavior' incorporates:
    //   ActionPort: '<S29>/Action Port'

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

    // End of Outputs for SubSystem: '<S6>/Change RED Behavior'
  }

  // End of If: '<S6>/This IF block determines whether or not to run the RED sim//exp ' 
}

//
// Output and update for atomic system:
//    '<S52>/MATLAB Function2'
//    '<S39>/MATLAB Function2'
//    '<S65>/MATLAB Function2'
//    '<S399>/MATLAB Function2'
//    '<S412>/MATLAB Function2'
//    '<S425>/MATLAB Function2'
//    '<S453>/MATLAB Function2'
//    '<S466>/MATLAB Function2'
//    '<S479>/MATLAB Function2'
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
//    '<S52>/MATLAB Function3'
//    '<S39>/MATLAB Function3'
//    '<S65>/MATLAB Function3'
//    '<S98>/MATLAB Function3'
//    '<S115>/MATLAB Function3'
//    '<S132>/MATLAB Function3'
//    '<S148>/MATLAB Function3'
//    '<S169>/MATLAB Function3'
//    '<S206>/MATLAB Function3'
//    '<S227>/MATLAB Function3'
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
//    '<S52>/MATLAB Function4'
//    '<S39>/MATLAB Function4'
//    '<S65>/MATLAB Function4'
//    '<S98>/MATLAB Function4'
//    '<S115>/MATLAB Function4'
//    '<S132>/MATLAB Function4'
//    '<S148>/MATLAB Function4'
//    '<S169>/MATLAB Function4'
//    '<S206>/MATLAB Function4'
//    '<S227>/MATLAB Function4'
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
//    '<S354>/Simulated Position Controller'
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
//    '<S354>/Simulated Position Controller'
//
void APF_SimulatedPositionController(real_T rtu_q1_desired, real_T
  rtu_q2_desired, real_T rtu_q3_desired, real_T *rty_q1_command, real_T
  *rty_q2_command, real_T *rty_q3_command, const real_T *rtd_RED_Rz_Elbow, const
  real_T *rtd_RED_Rz_Shoulder, const real_T *rtd_RED_Rz_Wrist,
  B_SimulatedPositionController_T *localB, DW_SimulatedPositionControlle_T
  *localDW)
{
  real_T rtb_Subtract2_kc;
  real_T rtb_Sum6_cnt;
  real_T rtb_Sum6_jb;
  real_T rtb_Sum6_pfh;

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

  rtb_Sum6_cnt = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate * localB->In1_g *
    APF_Path_Planning_2023a_BlueI_P.Kd_sharm +
    APF_Path_Planning_2023a_BlueI_P.Kp_sharm * rtb_Subtract2_kc;

  // Saturate: '<S77>/Saturation'
  if (rtb_Sum6_cnt > APF_Path_Planning_2023a_BlueI_P.Tz_lim_sharm) {
    *rty_q1_command = APF_Path_Planning_2023a_BlueI_P.Tz_lim_sharm;
  } else if (rtb_Sum6_cnt < -APF_Path_Planning_2023a_BlueI_P.Tz_lim_sharm) {
    *rty_q1_command = -APF_Path_Planning_2023a_BlueI_P.Tz_lim_sharm;
  } else {
    *rty_q1_command = rtb_Sum6_cnt;
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

  rtb_Sum6_pfh = rtb_Sum6_jb - localDW->Delay1_DSTATE_e;

  // If: '<S81>/if we went through a "step"'
  if (rtb_Sum6_pfh != 0.0) {
    // Outputs for IfAction SubSystem: '<S81>/Hold this value' incorporates:
    //   ActionPort: '<S82>/Action Port'

    // SignalConversion generated from: '<S82>/In1'
    localB->In1_g2 = rtb_Sum6_pfh;

    // End of Outputs for SubSystem: '<S81>/Hold this value'
  }

  // End of If: '<S81>/if we went through a "step"'

  // Sum: '<S78>/Sum3' incorporates:
  //   Gain: '<S78>/kd_elarm'
  //   Gain: '<S78>/kp_elarm'
  //   Gain: '<S81>/divide by delta T'

  rtb_Sum6_cnt = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate * localB->In1_g2
    * APF_Path_Planning_2023a_BlueI_P.Kd_elarm +
    APF_Path_Planning_2023a_BlueI_P.Kp_elarm * rtb_Sum6_jb;

  // Saturate: '<S77>/Saturation1'
  if (rtb_Sum6_cnt > APF_Path_Planning_2023a_BlueI_P.Tz_lim_elarm) {
    *rty_q2_command = APF_Path_Planning_2023a_BlueI_P.Tz_lim_elarm;
  } else if (rtb_Sum6_cnt < -APF_Path_Planning_2023a_BlueI_P.Tz_lim_elarm) {
    *rty_q2_command = -APF_Path_Planning_2023a_BlueI_P.Tz_lim_elarm;
  } else {
    *rty_q2_command = rtb_Sum6_cnt;
  }

  // End of Saturate: '<S77>/Saturation1'

  // Sum: '<S77>/Subtract4' incorporates:
  //   DataStoreRead: '<S77>/Data Store Read6'

  rtb_Sum6_pfh = rtu_q3_desired - *rtd_RED_Rz_Wrist;

  // Delay: '<S85>/Delay1'
  if (localDW->icLoad_m) {
    localDW->Delay1_DSTATE_l = rtb_Sum6_pfh;
  }

  // Sum: '<S85>/Sum6' incorporates:
  //   Delay: '<S85>/Delay1'

  rtb_Sum6_cnt = rtb_Sum6_pfh - localDW->Delay1_DSTATE_l;

  // If: '<S85>/if we went through a "step"'
  if (rtb_Sum6_cnt != 0.0) {
    // Outputs for IfAction SubSystem: '<S85>/Hold this value' incorporates:
    //   ActionPort: '<S86>/Action Port'

    // SignalConversion generated from: '<S86>/In1'
    localB->In1 = rtb_Sum6_cnt;

    // End of Outputs for SubSystem: '<S85>/Hold this value'
  }

  // End of If: '<S85>/if we went through a "step"'

  // Sum: '<S80>/Sum3' incorporates:
  //   Gain: '<S80>/kd_wrarm'
  //   Gain: '<S80>/kp_wrarm'
  //   Gain: '<S85>/divide by delta T'

  rtb_Sum6_cnt = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate * localB->In1 *
    APF_Path_Planning_2023a_BlueI_P.Kd_wrarm +
    APF_Path_Planning_2023a_BlueI_P.Kp_wrarm * rtb_Sum6_pfh;

  // Saturate: '<S77>/Saturation3'
  if (rtb_Sum6_cnt > APF_Path_Planning_2023a_BlueI_P.Tz_lim_wrarm) {
    *rty_q3_command = APF_Path_Planning_2023a_BlueI_P.Tz_lim_wrarm;
  } else if (rtb_Sum6_cnt < -APF_Path_Planning_2023a_BlueI_P.Tz_lim_wrarm) {
    *rty_q3_command = -APF_Path_Planning_2023a_BlueI_P.Tz_lim_wrarm;
  } else {
    *rty_q3_command = rtb_Sum6_cnt;
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
  localDW->Delay1_DSTATE_l = rtb_Sum6_pfh;
}

//
// Output and update for action system:
//    '<S66>/Passthrough for Experiment'
//    '<S254>/Passthrough for Experiment'
//    '<S287>/Passthrough for Experiment'
//    '<S320>/Passthrough for Experiment'
//    '<S354>/Passthrough for Experiment'
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
void APF_Path_Planning_2023a__REDARM(real_T *rtd_RED_ARM_Control_Mode, real_T
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
//    '<S211>/MATLAB Function'
//    '<S232>/MATLAB Function'
//    '<S278>/MATLAB Function'
//    '<S311>/MATLAB Function'
//    '<S344>/MATLAB Function'
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
void APF_Path_Planning_202_SubPhase1(real_T *rtd_BLACK_Fx, real_T *rtd_BLACK_Fy,
  const real_T *rtd_BLACK_Px, const real_T *rtd_BLACK_Py, const real_T
  *rtd_BLACK_Rz, real_T *rtd_BLACK_Tz, real_T *rtd_Float_State, const real_T
  *rtd_Univ_Time, B_SubPhase1_APF_Path_Planning_T *localB,
  DW_SubPhase1_APF_Path_Plannin_T *localDW, P_SubPhase1_APF_Path_Planning_T
  *localP)
{
  real_T rtb_Oy_ik[2];
  real_T rtb_Sum6_jw;

  // Sum: '<S90>/Subtract' incorporates:
  //   Constant: '<S90>/Desired X-Position (BLACK)'

  localB->Subtract = APF_Path_Planning_2023a_BlueI_P.xLength / 2.0 -
    *rtd_BLACK_Px;

  // Delay: '<S104>/Delay1'
  if (localDW->icLoad) {
    localDW->Delay1_DSTATE = localB->Subtract;
  }

  // Delay: '<S104>/Delay1'
  localB->Delay1 = localDW->Delay1_DSTATE;

  // Sum: '<S104>/Sum6'
  rtb_Sum6_jw = localB->Subtract - localB->Delay1;

  // If: '<S104>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSubs = -1;
  if (rtb_Sum6_jw != 0.0) {
    localDW->ifwewentthroughastep_ActiveSubs = 0;

    // Outputs for IfAction SubSystem: '<S104>/Hold this value' incorporates:
    //   ActionPort: '<S105>/Action Port'

    // SignalConversion generated from: '<S105>/In1'
    localB->In1_g = rtb_Sum6_jw;

    // End of Outputs for SubSystem: '<S104>/Hold this value'
  }

  // End of If: '<S104>/if we went through a "step"'

  // Sum: '<S96>/Sum3' incorporates:
  //   DataStoreWrite: '<S90>/BLACK_Fx'
  //   Gain: '<S104>/divide by delta T'
  //   Gain: '<S96>/kd_xb'
  //   Gain: '<S96>/kp_xb'

  *rtd_BLACK_Fx = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate * localB->In1_g
    * APF_Path_Planning_2023a_BlueI_P.Kd_xb +
    APF_Path_Planning_2023a_BlueI_P.Kp_xb * localB->Subtract;

  // Sum: '<S90>/Subtract1' incorporates:
  //   Constant: '<S90>/Desired Y-Position (BLACK)'

  localB->Subtract1 = APF_Path_Planning_2023a_BlueI_P.yLength / 2.0 -
    *rtd_BLACK_Py;

  // Delay: '<S106>/Delay1'
  if (localDW->icLoad_p) {
    localDW->Delay1_DSTATE_n = localB->Subtract1;
  }

  // Delay: '<S106>/Delay1'
  localB->Delay1_l = localDW->Delay1_DSTATE_n;

  // Sum: '<S106>/Sum6'
  rtb_Sum6_jw = localB->Subtract1 - localB->Delay1_l;

  // If: '<S106>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_g = -1;
  if (rtb_Sum6_jw != 0.0) {
    localDW->ifwewentthroughastep_ActiveSu_g = 0;

    // Outputs for IfAction SubSystem: '<S106>/Hold this value' incorporates:
    //   ActionPort: '<S107>/Action Port'

    // SignalConversion generated from: '<S107>/In1'
    localB->In1 = rtb_Sum6_jw;

    // End of Outputs for SubSystem: '<S106>/Hold this value'
  }

  // End of If: '<S106>/if we went through a "step"'

  // Sum: '<S97>/Sum3' incorporates:
  //   DataStoreWrite: '<S90>/BLACK_Fy'
  //   Gain: '<S106>/divide by delta T'
  //   Gain: '<S97>/kd_yb'
  //   Gain: '<S97>/kp_yb'

  *rtd_BLACK_Fy = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate * localB->In1 *
    APF_Path_Planning_2023a_BlueI_P.Kd_yb +
    APF_Path_Planning_2023a_BlueI_P.Kp_yb * localB->Subtract1;

  // MATLAB Function: '<S100>/MATLAB Function' incorporates:
  //   Constant: '<S94>/Desired Rate (BLACK)'
  //   Constant: '<S99>/Constant1'
  //   Product: '<S94>/Product'
  //   Sum: '<S99>/Subtract'

  APF_Path_Plannin_MATLABFunction(localP->DesiredRateBLACK_Value *
    (*rtd_Univ_Time - APF_Path_Planning_2023a_BlueI_P.Phase2_End), &rtb_Sum6_jw);

  // MATLAB Function: '<S98>/MATLAB Function2'
  APF_Path_Planni_MATLABFunction2(rtb_Sum6_jw, rtb_Oy_ik, localB->rtb_Ox_fz_m);

  // MATLAB Function: '<S98>/MATLAB Function3'
  APF_Path_Planni_MATLABFunction3(*rtd_BLACK_Rz, localB->rtb_Ox_a_c);

  // Sum: '<S98>/Subtract2'
  localB->rtb_Ox_fz_m[0] -= localB->rtb_Ox_a_c[0];
  localB->rtb_Ox_fz_m[1] -= localB->rtb_Ox_a_c[1];

  // MATLAB Function: '<S98>/MATLAB Function4'
  APF_Path_Planni_MATLABFunction4(rtb_Oy_ik, localB->rtb_Ox_fz_m, &localB->e_out);

  // Delay: '<S102>/Delay1'
  if (localDW->icLoad_c) {
    localDW->Delay1_DSTATE_j = localB->e_out;
  }

  // Delay: '<S102>/Delay1'
  localB->Delay1_lb = localDW->Delay1_DSTATE_j;

  // Sum: '<S102>/Sum6'
  rtb_Sum6_jw = localB->e_out - localB->Delay1_lb;

  // If: '<S102>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_o = -1;
  if (rtb_Sum6_jw != 0.0) {
    localDW->ifwewentthroughastep_ActiveSu_o = 0;

    // Outputs for IfAction SubSystem: '<S102>/Hold this value' incorporates:
    //   ActionPort: '<S103>/Action Port'

    // SignalConversion generated from: '<S103>/In1'
    localB->In1_g2 = rtb_Sum6_jw;

    // End of Outputs for SubSystem: '<S102>/Hold this value'
  }

  // End of If: '<S102>/if we went through a "step"'

  // Sum: '<S95>/Sum3' incorporates:
  //   DataStoreWrite: '<S90>/BLACK_Tz'
  //   Gain: '<S102>/divide by delta T'
  //   Gain: '<S95>/kd_tb'
  //   Gain: '<S95>/kp_tb'

  *rtd_BLACK_Tz = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate *
    localB->In1_g2 * APF_Path_Planning_2023a_BlueI_P.Kd_tb +
    APF_Path_Planning_2023a_BlueI_P.Kp_tb * localB->e_out;

  // DataStoreWrite: '<S90>/Data Store Write3' incorporates:
  //   Constant: '<S90>/Puck State'

  *rtd_Float_State = localP->PuckState_Value;
}

//
// Update for action system:
//    '<S87>/Sub-Phase #1'
//    '<S87>/Sub-Phase #2 '
//    '<S87>/Sub-Phase #3 '
//
void APF_Path_Plann_SubPhase1_Update(B_SubPhase1_APF_Path_Planning_T *localB,
  DW_SubPhase1_APF_Path_Plannin_T *localDW)
{
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
void APF_Path_Planning_2_SubPhase1_g(real_T *rtd_BLUE_Fx, real_T *rtd_BLUE_Fy,
  const real_T *rtd_BLUE_Px, const real_T *rtd_BLUE_Py, const real_T
  *rtd_BLUE_Rz, real_T *rtd_BLUE_Tz, real_T *rtd_Float_State, const real_T
  *rtd_Univ_Time, B_SubPhase1_APF_Path_Planni_n_T *localB,
  DW_SubPhase1_APF_Path_Plann_o_T *localDW, P_SubPhase1_APF_Path_Planni_a_T
  *localP)
{
  real_T rtb_Oy_c[2];
  real_T rtb_Subtract3_o;
  real_T rtb_Sum6_kr;

  // Sum: '<S172>/Subtract3' incorporates:
  //   Constant: '<S172>/Constant2'

  rtb_Subtract3_o = *rtd_Univ_Time - APF_Path_Planning_2023a_BlueI_P.Phase2_End;

  // Sum: '<S161>/Subtract' incorporates:
  //   MATLAB Function: '<S161>/MATLAB Function2'

  localB->Subtract = (cos(0.03490659 * rtb_Subtract3_o) * -0.85 +
                      APF_Path_Planning_2023a_BlueI_P.xLength / 2.0) -
    *rtd_BLUE_Px;

  // Delay: '<S178>/Delay1'
  if (localDW->icLoad) {
    localDW->Delay1_DSTATE = localB->Subtract;
  }

  // Delay: '<S178>/Delay1'
  localB->Delay1 = localDW->Delay1_DSTATE;

  // Sum: '<S178>/Sum6'
  rtb_Sum6_kr = localB->Subtract - localB->Delay1;

  // If: '<S178>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSubs = -1;
  if (rtb_Sum6_kr != 0.0) {
    localDW->ifwewentthroughastep_ActiveSubs = 0;

    // Outputs for IfAction SubSystem: '<S178>/Hold this value' incorporates:
    //   ActionPort: '<S179>/Action Port'

    // SignalConversion generated from: '<S179>/In1'
    localB->In1_g = rtb_Sum6_kr;

    // End of Outputs for SubSystem: '<S178>/Hold this value'
  }

  // End of If: '<S178>/if we went through a "step"'

  // Sum: '<S167>/Sum3' incorporates:
  //   DataStoreWrite: '<S161>/BLUE_Fx'
  //   Gain: '<S167>/kd_xb'
  //   Gain: '<S167>/kp_xb'
  //   Gain: '<S178>/divide by delta T'

  *rtd_BLUE_Fx = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate * localB->In1_g *
    APF_Path_Planning_2023a_BlueI_P.Kd_xblue +
    APF_Path_Planning_2023a_BlueI_P.Kp_xblue * localB->Subtract;

  // Sum: '<S161>/Subtract1' incorporates:
  //   MATLAB Function: '<S161>/MATLAB Function3'

  localB->Subtract1 = (sin(0.03490659 * rtb_Subtract3_o) * -0.85 +
                       APF_Path_Planning_2023a_BlueI_P.yLength / 2.0) -
    *rtd_BLUE_Py;

  // Delay: '<S180>/Delay1'
  if (localDW->icLoad_j) {
    localDW->Delay1_DSTATE_o = localB->Subtract1;
  }

  // Delay: '<S180>/Delay1'
  localB->Delay1_l = localDW->Delay1_DSTATE_o;

  // Sum: '<S180>/Sum6'
  rtb_Subtract3_o = localB->Subtract1 - localB->Delay1_l;

  // If: '<S180>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_l = -1;
  if (rtb_Subtract3_o != 0.0) {
    localDW->ifwewentthroughastep_ActiveSu_l = 0;

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

  *rtd_BLUE_Fy = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate * localB->In1 *
    APF_Path_Planning_2023a_BlueI_P.Kd_yblue +
    APF_Path_Planning_2023a_BlueI_P.Kp_yblue * localB->Subtract1;

  // MATLAB Function: '<S174>/MATLAB Function' incorporates:
  //   Constant: '<S165>/Desired Rate '
  //   Constant: '<S173>/Constant1'
  //   Product: '<S165>/Product'
  //   Sum: '<S173>/Subtract'

  APF_Path_Plannin_MATLABFunction(localP->DesiredRate_Value * (*rtd_Univ_Time -
    APF_Path_Planning_2023a_BlueI_P.Phase2_End), &rtb_Subtract3_o);

  // MATLAB Function: '<S169>/MATLAB Function2'
  APF_Path_Planni_MATLABFunction2(rtb_Subtract3_o, rtb_Oy_c, localB->rtb_Ox_e_m);

  // MATLAB Function: '<S169>/MATLAB Function3'
  APF_Path_Planni_MATLABFunction3(*rtd_BLUE_Rz, localB->rtb_Ox_kz_c);

  // Sum: '<S169>/Subtract2'
  localB->rtb_Ox_e_m[0] -= localB->rtb_Ox_kz_c[0];
  localB->rtb_Ox_e_m[1] -= localB->rtb_Ox_kz_c[1];

  // MATLAB Function: '<S169>/MATLAB Function4'
  APF_Path_Planni_MATLABFunction4(rtb_Oy_c, localB->rtb_Ox_e_m, &localB->e_out);

  // Delay: '<S176>/Delay1'
  if (localDW->icLoad_h) {
    localDW->Delay1_DSTATE_i = localB->e_out;
  }

  // Delay: '<S176>/Delay1'
  localB->Delay1_k = localDW->Delay1_DSTATE_i;

  // Sum: '<S176>/Sum6'
  rtb_Subtract3_o = localB->e_out - localB->Delay1_k;

  // If: '<S176>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_i = -1;
  if (rtb_Subtract3_o != 0.0) {
    localDW->ifwewentthroughastep_ActiveSu_i = 0;

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

  *rtd_BLUE_Tz = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate * localB->In1_g2
    * APF_Path_Planning_2023a_BlueI_P.Kd_tblue +
    APF_Path_Planning_2023a_BlueI_P.Kp_tblue * localB->e_out;

  // DataStoreWrite: '<S161>/Data Store Write1' incorporates:
  //   Constant: '<S161>/Puck State'

  *rtd_Float_State = localP->PuckState_Value;
}

//
// Update for action system:
//    '<S88>/Sub-Phase #1'
//    '<S88>/Sub-Phase #2 '
//    '<S88>/Sub-Phase #3 '
//
void APF_Path_Pla_SubPhase1_f_Update(B_SubPhase1_APF_Path_Planni_n_T *localB,
  DW_SubPhase1_APF_Path_Plann_o_T *localDW)
{
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

//
// Output and update for atomic system:
//    '<S244>/MATLAB Function'
//    '<S245>/MATLAB Function'
//    '<S246>/MATLAB Function'
//
void APF_Path_Plann_MATLABFunction_o(real_T rtu_t, real_T *rty_x)
{
  *rty_x = cos(0.03490659 * rtu_t) * 0.9 +
    APF_Path_Planning_2023a_BlueI_P.xLength / 2.0;
}

//
// Output and update for atomic system:
//    '<S244>/MATLAB Function1'
//    '<S245>/MATLAB Function1'
//    '<S246>/MATLAB Function1'
//
void APF_Path_Planni_MATLABFunction1(real_T rtu_t, real_T *rty_y)
{
  *rty_y = sin(0.03490659 * rtu_t) * 0.85 +
    APF_Path_Planning_2023a_BlueI_P.yLength / 2.0;
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
void APF_Path_Planning_2_SubPhase1_p(real_T *rtd_Float_State, real_T
  *rtd_RED_ARM_Control_Mode, real_T *rtd_RED_Elbow_Command, real_T *rtd_RED_Fx,
  real_T *rtd_RED_Fy, const real_T *rtd_RED_Px, const real_T *rtd_RED_Py, const
  real_T *rtd_RED_Rz, const real_T *rtd_RED_Rz_Elbow, const real_T
  *rtd_RED_Rz_Shoulder, const real_T *rtd_RED_Rz_Wrist, real_T
  *rtd_RED_Shoulder_Command, real_T *rtd_RED_Tz, real_T *rtd_RED_Tz_RW, real_T
  *rtd_RED_Wrist_Command, const real_T *rtd_Univ_Time, const real_T *rtd_isSim,
  B_SubPhase1_APF_Path_Planni_i_T *localB, DW_SubPhase1_APF_Path_Plann_m_T
  *localDW, P_SubPhase1_APF_Path_Planni_h_T *localP)
{
  real_T rtb_Oy_ke[2];
  real_T rtb_Sum6_gvo;
  real_T rtb_y_g;

  // DataStoreWrite: '<S244>/RED_Tz_RW' incorporates:
  //   Constant: '<S244>/Constant1'

  *rtd_RED_Tz_RW = localP->Constant1_Value;

  // MATLAB Function: '<S278>/MATLAB Function' incorporates:
  //   Constant: '<S255>/Constant'
  //   Constant: '<S255>/Desired Rate '
  //   Constant: '<S277>/Constant1'
  //   Product: '<S255>/Product'
  //   Sum: '<S255>/Sum'
  //   Sum: '<S277>/Subtract'

  APF_Path_Plannin_MATLABFunction(localP->DesiredRate_Value * (*rtd_Univ_Time -
    APF_Path_Planning_2023a_BlueI_P.Phase2_End) + localP->Constant_Value,
    &rtb_y_g);

  // MATLAB Function: '<S251>/MATLAB Function2'
  APF_Path_Planni_MATLABFunction2(rtb_y_g, rtb_Oy_ke, localB->rtb_Ox_o_m);

  // MATLAB Function: '<S251>/MATLAB Function3'
  APF_Path_Planni_MATLABFunction3(*rtd_RED_Rz, localB->rtb_Ox_gy_c);

  // Sum: '<S251>/Subtract2'
  localB->rtb_Ox_o_m[0] -= localB->rtb_Ox_gy_c[0];
  localB->rtb_Ox_o_m[1] -= localB->rtb_Ox_gy_c[1];

  // MATLAB Function: '<S251>/MATLAB Function4'
  APF_Path_Planni_MATLABFunction4(rtb_Oy_ke, localB->rtb_Ox_o_m, &localB->e_out);

  // Delay: '<S257>/Delay1'
  if (localDW->icLoad) {
    localDW->Delay1_DSTATE = localB->e_out;
  }

  // Delay: '<S257>/Delay1'
  localB->Delay1 = localDW->Delay1_DSTATE;

  // Sum: '<S257>/Sum6'
  rtb_Sum6_gvo = localB->e_out - localB->Delay1;

  // If: '<S257>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSubs = -1;
  if (rtb_Sum6_gvo != 0.0) {
    localDW->ifwewentthroughastep_ActiveSubs = 0;

    // Outputs for IfAction SubSystem: '<S257>/Hold this value' incorporates:
    //   ActionPort: '<S258>/Action Port'

    // SignalConversion generated from: '<S258>/In1'
    localB->In1_g2 = rtb_Sum6_gvo;

    // End of Outputs for SubSystem: '<S257>/Hold this value'
  }

  // End of If: '<S257>/if we went through a "step"'

  // Sum: '<S248>/Sum3' incorporates:
  //   DataStoreWrite: '<S244>/RED_Tz'
  //   Gain: '<S248>/kd_tr'
  //   Gain: '<S248>/kp_tr'
  //   Gain: '<S257>/divide by delta T'

  *rtd_RED_Tz = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate * localB->In1_g2 *
    APF_Path_Planning_2023a_BlueI_P.Kd_tr +
    APF_Path_Planning_2023a_BlueI_P.Kp_tr * localB->e_out;

  // Sum: '<S256>/Subtract3' incorporates:
  //   Constant: '<S256>/Constant2'

  rtb_Sum6_gvo = *rtd_Univ_Time - APF_Path_Planning_2023a_BlueI_P.Phase2_End;

  // MATLAB Function: '<S244>/MATLAB Function'
  APF_Path_Plann_MATLABFunction_o(rtb_Sum6_gvo, &rtb_y_g);

  // Sum: '<S244>/Subtract'
  localB->Subtract = rtb_y_g - *rtd_RED_Px;

  // Delay: '<S259>/Delay1'
  if (localDW->icLoad_g) {
    localDW->Delay1_DSTATE_e = localB->Subtract;
  }

  // Delay: '<S259>/Delay1'
  localB->Delay1_c = localDW->Delay1_DSTATE_e;

  // Sum: '<S259>/Sum6'
  rtb_y_g = localB->Subtract - localB->Delay1_c;

  // If: '<S259>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_a = -1;
  if (rtb_y_g != 0.0) {
    localDW->ifwewentthroughastep_ActiveSu_a = 0;

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

  *rtd_RED_Fx = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate * localB->In1_g *
    APF_Path_Planning_2023a_BlueI_P.Kd_xr +
    APF_Path_Planning_2023a_BlueI_P.Kp_xr * localB->Subtract;

  // MATLAB Function: '<S244>/MATLAB Function1'
  APF_Path_Planni_MATLABFunction1(rtb_Sum6_gvo, &rtb_y_g);

  // Sum: '<S244>/Subtract2'
  localB->Subtract2 = rtb_y_g - *rtd_RED_Py;

  // Delay: '<S261>/Delay1'
  if (localDW->icLoad_h) {
    localDW->Delay1_DSTATE_o = localB->Subtract2;
  }

  // Delay: '<S261>/Delay1'
  localB->Delay1_m = localDW->Delay1_DSTATE_o;

  // Sum: '<S261>/Sum6'
  rtb_Sum6_gvo = localB->Subtract2 - localB->Delay1_m;

  // If: '<S261>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_i = -1;
  if (rtb_Sum6_gvo != 0.0) {
    localDW->ifwewentthroughastep_ActiveSu_i = 0;

    // Outputs for IfAction SubSystem: '<S261>/Hold this value' incorporates:
    //   ActionPort: '<S262>/Action Port'

    // SignalConversion generated from: '<S262>/In1'
    localB->In1 = rtb_Sum6_gvo;

    // End of Outputs for SubSystem: '<S261>/Hold this value'
  }

  // End of If: '<S261>/if we went through a "step"'

  // Sum: '<S250>/Sum3' incorporates:
  //   DataStoreWrite: '<S244>/RED_Fy'
  //   Gain: '<S250>/kd_yr'
  //   Gain: '<S250>/kp_yr'
  //   Gain: '<S261>/divide by delta T'

  *rtd_RED_Fy = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate * localB->In1 *
    APF_Path_Planning_2023a_BlueI_P.Kd_yr +
    APF_Path_Planning_2023a_BlueI_P.Kp_yr * localB->Subtract2;

  // DataStoreWrite: '<S244>/Data Store Write3' incorporates:
  //   Constant: '<S244>/Puck State'

  *rtd_Float_State = localP->PuckState_Value;

  // If: '<S244>/If' incorporates:
  //   Constant: '<S244>/Constant4'

  if ((APF_Path_Planning_2023a_BlueI_P.platformSelection == 4.0) ||
      (APF_Path_Planning_2023a_BlueI_P.platformSelection == 5.0) ||
      (APF_Path_Planning_2023a_BlueI_P.platformSelection == 10.0) ||
      (APF_Path_Planning_2023a_BlueI_P.platformSelection == 11.0)) {
    // Outputs for IfAction SubSystem: '<S244>/RED+ARM' incorporates:
    //   ActionPort: '<S254>/Action Port'

    APF_Path_Planning_2023a__REDARM(rtd_RED_ARM_Control_Mode,
      rtd_RED_Elbow_Command, (real_T *)rtd_RED_Rz_Elbow, (real_T *)
      rtd_RED_Rz_Shoulder, (real_T *)rtd_RED_Rz_Wrist, rtd_RED_Shoulder_Command,
      rtd_RED_Wrist_Command, (real_T *)rtd_isSim, &localB->REDARM,
      &localDW->REDARM, &localP->REDARM);

    // End of Outputs for SubSystem: '<S244>/RED+ARM'
  }

  // End of If: '<S244>/If'
}

//
// Update for action system:
//    '<S89>/Sub-Phase #1'
//    '<S89>/Sub-Phase #2 '
//
void APF_Path_Pla_SubPhase1_e_Update(B_SubPhase1_APF_Path_Planni_i_T *localB,
  DW_SubPhase1_APF_Path_Plann_m_T *localDW)
{
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
  // Start for If: '<S402>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_a = -1;

  // Start for If: '<S404>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_l = -1;

  // Start for If: '<S400>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_d = -1;

  // InitializeConditions for Delay: '<S402>/Delay1'
  localDW->icLoad_f = true;

  // InitializeConditions for Delay: '<S404>/Delay1'
  localDW->icLoad_jl = true;

  // InitializeConditions for Delay: '<S400>/Delay1'
  localDW->icLoad_ca = true;

  // SystemInitialize for IfAction SubSystem: '<S402>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S403>/In1' incorporates:
  //   Outport: '<S403>/Out1'

  localB->In1_g20asdtgi0 = localP->Out1_Y0_k;

  // End of SystemInitialize for SubSystem: '<S402>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S404>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S405>/In1' incorporates:
  //   Outport: '<S405>/Out1'

  localB->In1_g20asdtgi = localP->Out1_Y0_d;

  // End of SystemInitialize for SubSystem: '<S404>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S400>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S401>/In1' incorporates:
  //   Outport: '<S401>/Out1'

  localB->In1_g20asdtgi0c = localP->Out1_Y0;

  // End of SystemInitialize for SubSystem: '<S400>/Hold this value'
  // End of SystemInitialize for SubSystem: '<S10>/Change BLACK Behavior'

  // SystemInitialize for IfAction SubSystem: '<S10>/Change BLUE Behavior'
  // Start for If: '<S415>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_i = -1;

  // Start for If: '<S417>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_p = -1;

  // Start for If: '<S413>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_k = -1;

  // InitializeConditions for Delay: '<S415>/Delay1'
  localDW->icLoad_c = true;

  // InitializeConditions for Delay: '<S417>/Delay1'
  localDW->icLoad_p = true;

  // InitializeConditions for Delay: '<S413>/Delay1'
  localDW->icLoad_j = true;

  // SystemInitialize for IfAction SubSystem: '<S415>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S416>/In1' incorporates:
  //   Outport: '<S416>/Out1'

  localB->In1_g20asdt = localP->Out1_Y0_dv;

  // End of SystemInitialize for SubSystem: '<S415>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S417>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S418>/In1' incorporates:
  //   Outport: '<S418>/Out1'

  localB->In1_g20asd = localP->Out1_Y0_p;

  // End of SystemInitialize for SubSystem: '<S417>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S413>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S414>/In1' incorporates:
  //   Outport: '<S414>/Out1'

  localB->In1_g20asdtg = localP->Out1_Y0_b;

  // End of SystemInitialize for SubSystem: '<S413>/Hold this value'
  // End of SystemInitialize for SubSystem: '<S10>/Change BLUE Behavior'

  // SystemInitialize for IfAction SubSystem: '<S10>/Change RED Behavior'
  // Start for If: '<S427>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSubs = -1;

  // Start for If: '<S429>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_c = -1;

  // Start for If: '<S431>/if we went through a "step"'
  localDW->ifwewentthroughastep_ActiveSu_m = -1;

  // InitializeConditions for Delay: '<S427>/Delay1'
  localDW->icLoad = true;

  // InitializeConditions for Delay: '<S429>/Delay1'
  localDW->icLoad_g = true;

  // InitializeConditions for Delay: '<S431>/Delay1'
  localDW->icLoad_d = true;

  // SystemInitialize for IfAction SubSystem: '<S427>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S428>/In1' incorporates:
  //   Outport: '<S428>/Out1'

  localB->In1_g20as = localP->Out1_Y0_b3;

  // End of SystemInitialize for SubSystem: '<S427>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S429>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S430>/In1' incorporates:
  //   Outport: '<S430>/Out1'

  localB->In1_g20a = localP->Out1_Y0_b1;

  // End of SystemInitialize for SubSystem: '<S429>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S431>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S432>/In1' incorporates:
  //   Outport: '<S432>/Out1'

  localB->In1_g20 = localP->Out1_Y0_ba;

  // End of SystemInitialize for SubSystem: '<S431>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S395>/RED+ARM'
  // SystemInitialize for IfAction SubSystem: '<S426>/Simulated Position Controller' 
  // InitializeConditions for Delay: '<S443>/Delay1'
  localDW->icLoad_e = true;

  // InitializeConditions for Delay: '<S441>/Delay1'
  localDW->icLoad_gp = true;

  // InitializeConditions for Delay: '<S445>/Delay1'
  localDW->icLoad_k = true;

  // SystemInitialize for IfAction SubSystem: '<S443>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S444>/In1' incorporates:
  //   Outport: '<S444>/Out1'

  localB->In1_g = localP->Out1_Y0_o;

  // End of SystemInitialize for SubSystem: '<S443>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S441>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S442>/In1' incorporates:
  //   Outport: '<S442>/Out1'

  localB->In1_g2 = localP->Out1_Y0_c;

  // End of SystemInitialize for SubSystem: '<S441>/Hold this value'

  // SystemInitialize for IfAction SubSystem: '<S445>/Hold this value'
  // SystemInitialize for SignalConversion generated from: '<S446>/In1' incorporates:
  //   Outport: '<S446>/Out1'

  localB->In1 = localP->Out1_Y0_a;

  // End of SystemInitialize for SubSystem: '<S445>/Hold this value'
  // End of SystemInitialize for SubSystem: '<S426>/Simulated Position Controller' 
  // End of SystemInitialize for SubSystem: '<S395>/RED+ARM'
  // End of SystemInitialize for SubSystem: '<S10>/Change RED Behavior'
}

//
// Outputs for action system:
//    '<Root>/Phase #4: Return Home'
//    '<Root>/Phase #5: Hold Home'
//
void APF_Path_Plann_Phase4ReturnHome(real_T *rtd_BLACK_Fx, real_T *rtd_BLACK_Fy,
  const real_T *rtd_BLACK_Px, const real_T *rtd_BLACK_Py, const real_T
  *rtd_BLACK_Rz, real_T *rtd_BLACK_Tz, real_T *rtd_BLUE_Fx, real_T *rtd_BLUE_Fy,
  const real_T *rtd_BLUE_Px, const real_T *rtd_BLUE_Py, const real_T
  *rtd_BLUE_Rz, real_T *rtd_BLUE_Tz, real_T *rtd_Float_State, real_T
  *rtd_RED_ARM_Control_Mode, real_T *rtd_RED_Elbow_Command, real_T *rtd_RED_Fx,
  real_T *rtd_RED_Fy, const real_T *rtd_RED_Px, const real_T *rtd_RED_Py, const
  real_T *rtd_RED_Rz, const real_T *rtd_RED_Rz_Elbow, const real_T
  *rtd_RED_Rz_Shoulder, const real_T *rtd_RED_Rz_Wrist, real_T
  *rtd_RED_Shoulder_Command, real_T *rtd_RED_Tz, real_T *rtd_RED_Tz_RW, real_T
  *rtd_RED_Wrist_Command, const real_T *rtd_WhoAmI, const real_T *rtd_isSim,
  B_Phase4ReturnHome_APF_Path_P_T *localB, DW_Phase4ReturnHome_APF_Path__T
  *localDW, P_Phase4ReturnHome_APF_Path_P_T *localP)
{
  real_T rtb_Sum6_an;
  real_T rtb_Sum6_ea;
  real_T rtb_Sum6_j5q;
  real_T rtb_Sum6_oa;

  // If: '<S10>/This IF block determines whether or not to run the BLACK sim//exp' 
  localDW->ThisIFblockdetermineswhetherorn = -1;
  if ((*rtd_WhoAmI == 2.0) || (*rtd_isSim == 1.0)) {
    localDW->ThisIFblockdetermineswhetherorn = 0;

    // Outputs for IfAction SubSystem: '<S10>/Change BLACK Behavior' incorporates:
    //   ActionPort: '<S393>/Action Port'

    // Sum: '<S393>/Subtract' incorporates:
    //   Constant: '<S393>/Desired Px (BLACK)'

    localB->Subtract_c = APF_Path_Planning_2023a_BlueI_P.home_states_BLACK[0] - *
      rtd_BLACK_Px;

    // Delay: '<S402>/Delay1'
    if (localDW->icLoad_f) {
      localDW->Delay1_DSTATE_a = localB->Subtract_c;
    }

    // Delay: '<S402>/Delay1'
    localB->Delay1_j = localDW->Delay1_DSTATE_a;

    // Sum: '<S402>/Sum6'
    rtb_Sum6_an = localB->Subtract_c - localB->Delay1_j;

    // If: '<S402>/if we went through a "step"'
    localDW->ifwewentthroughastep_ActiveSu_a = -1;
    if (rtb_Sum6_an != 0.0) {
      localDW->ifwewentthroughastep_ActiveSu_a = 0;

      // Outputs for IfAction SubSystem: '<S402>/Hold this value' incorporates:
      //   ActionPort: '<S403>/Action Port'

      // SignalConversion generated from: '<S403>/In1'
      localB->In1_g20asdtgi0 = rtb_Sum6_an;

      // End of Outputs for SubSystem: '<S402>/Hold this value'
    }

    // End of If: '<S402>/if we went through a "step"'

    // DataStoreWrite: '<S393>/BLACK_Fx' incorporates:
    //   Gain: '<S397>/kd_xb'
    //   Gain: '<S397>/kp_xb'
    //   Gain: '<S402>/divide by delta T'
    //   Sum: '<S397>/Sum3'

    *rtd_BLACK_Fx = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate *
      localB->In1_g20asdtgi0 * APF_Path_Planning_2023a_BlueI_P.Kd_xb +
      APF_Path_Planning_2023a_BlueI_P.Kp_xb * localB->Subtract_c;

    // Sum: '<S393>/Subtract1' incorporates:
    //   Constant: '<S393>/Desired Py (BLACK)'

    localB->Subtract1_k = APF_Path_Planning_2023a_BlueI_P.home_states_BLACK[1] -
      *rtd_BLACK_Py;

    // Delay: '<S404>/Delay1'
    if (localDW->icLoad_jl) {
      localDW->Delay1_DSTATE_jh = localB->Subtract1_k;
    }

    // Delay: '<S404>/Delay1'
    localB->Delay1_i = localDW->Delay1_DSTATE_jh;

    // Sum: '<S404>/Sum6'
    rtb_Sum6_an = localB->Subtract1_k - localB->Delay1_i;

    // If: '<S404>/if we went through a "step"'
    localDW->ifwewentthroughastep_ActiveSu_l = -1;
    if (rtb_Sum6_an != 0.0) {
      localDW->ifwewentthroughastep_ActiveSu_l = 0;

      // Outputs for IfAction SubSystem: '<S404>/Hold this value' incorporates:
      //   ActionPort: '<S405>/Action Port'

      // SignalConversion generated from: '<S405>/In1'
      localB->In1_g20asdtgi = rtb_Sum6_an;

      // End of Outputs for SubSystem: '<S404>/Hold this value'
    }

    // End of If: '<S404>/if we went through a "step"'

    // DataStoreWrite: '<S393>/BLACK_Fy' incorporates:
    //   Gain: '<S398>/kd_yb'
    //   Gain: '<S398>/kp_yb'
    //   Gain: '<S404>/divide by delta T'
    //   Sum: '<S398>/Sum3'

    *rtd_BLACK_Fy = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate *
      localB->In1_g20asdtgi * APF_Path_Planning_2023a_BlueI_P.Kd_yb +
      APF_Path_Planning_2023a_BlueI_P.Kp_yb * localB->Subtract1_k;

    // MATLAB Function: '<S399>/MATLAB Function2' incorporates:
    //   Constant: '<S393>/Desired Attitude (BLACK)'

    APF_Path_Planni_MATLABFunction2
      (APF_Path_Planning_2023a_BlueI_P.home_states_BLACK[2], localB->rtb_Oy_a_k,
       localB->rtb_Ox_d_m);

    // MATLAB Function: '<S399>/MATLAB Function3'
    APF_Path_Planni_MATLABFunction3(*rtd_BLACK_Rz, localB->rtb_Ox_kr_c);

    // Sum: '<S399>/Subtract2'
    localB->rtb_Ox_d_m[0] -= localB->rtb_Ox_kr_c[0];
    localB->rtb_Ox_d_m[1] -= localB->rtb_Ox_kr_c[1];

    // MATLAB Function: '<S399>/MATLAB Function4'
    APF_Path_Planni_MATLABFunction4(localB->rtb_Oy_a_k, localB->rtb_Ox_d_m,
      &localB->e_out_hp);

    // Delay: '<S400>/Delay1'
    if (localDW->icLoad_ca) {
      localDW->Delay1_DSTATE_h5 = localB->e_out_hp;
    }

    // Delay: '<S400>/Delay1'
    localB->Delay1_c = localDW->Delay1_DSTATE_h5;

    // Sum: '<S400>/Sum6'
    rtb_Sum6_an = localB->e_out_hp - localB->Delay1_c;

    // If: '<S400>/if we went through a "step"'
    localDW->ifwewentthroughastep_ActiveSu_d = -1;
    if (rtb_Sum6_an != 0.0) {
      localDW->ifwewentthroughastep_ActiveSu_d = 0;

      // Outputs for IfAction SubSystem: '<S400>/Hold this value' incorporates:
      //   ActionPort: '<S401>/Action Port'

      // SignalConversion generated from: '<S401>/In1'
      localB->In1_g20asdtgi0c = rtb_Sum6_an;

      // End of Outputs for SubSystem: '<S400>/Hold this value'
    }

    // End of If: '<S400>/if we went through a "step"'

    // DataStoreWrite: '<S393>/BLACK_Tz' incorporates:
    //   Gain: '<S396>/kd_tb'
    //   Gain: '<S396>/kp_tb'
    //   Gain: '<S400>/divide by delta T'
    //   Sum: '<S396>/Sum3'

    *rtd_BLACK_Tz = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate *
      localB->In1_g20asdtgi0c * APF_Path_Planning_2023a_BlueI_P.Kd_tb +
      APF_Path_Planning_2023a_BlueI_P.Kp_tb * localB->e_out_hp;

    // DataStoreWrite: '<S393>/Data Store Write3' incorporates:
    //   Constant: '<S393>/Puck State'

    *rtd_Float_State = localP->PuckState_Value;

    // End of Outputs for SubSystem: '<S10>/Change BLACK Behavior'
  }

  // End of If: '<S10>/This IF block determines whether or not to run the BLACK sim//exp' 

  // If: '<S10>/This IF block determines whether or not to run the BLUE sim//exp' 
  localDW->ThisIFblockdetermineswhethero_j = -1;
  if ((*rtd_WhoAmI == 3.0) || (*rtd_isSim == 1.0)) {
    localDW->ThisIFblockdetermineswhethero_j = 0;

    // Outputs for IfAction SubSystem: '<S10>/Change BLUE Behavior' incorporates:
    //   ActionPort: '<S394>/Action Port'

    // Sum: '<S394>/Subtract' incorporates:
    //   Constant: '<S394>/Desired Px (BLUE)'

    localB->Subtract_k = APF_Path_Planning_2023a_BlueI_P.home_states_BLUE[0] -
      *rtd_BLUE_Px;

    // Delay: '<S415>/Delay1'
    if (localDW->icLoad_c) {
      localDW->Delay1_DSTATE_f = localB->Subtract_k;
    }

    // Delay: '<S415>/Delay1'
    localB->Delay1_k = localDW->Delay1_DSTATE_f;

    // Sum: '<S415>/Sum6'
    rtb_Sum6_an = localB->Subtract_k - localB->Delay1_k;

    // If: '<S415>/if we went through a "step"'
    localDW->ifwewentthroughastep_ActiveSu_i = -1;
    if (rtb_Sum6_an != 0.0) {
      localDW->ifwewentthroughastep_ActiveSu_i = 0;

      // Outputs for IfAction SubSystem: '<S415>/Hold this value' incorporates:
      //   ActionPort: '<S416>/Action Port'

      // SignalConversion generated from: '<S416>/In1'
      localB->In1_g20asdt = rtb_Sum6_an;

      // End of Outputs for SubSystem: '<S415>/Hold this value'
    }

    // End of If: '<S415>/if we went through a "step"'

    // DataStoreWrite: '<S394>/BLUE_Fx' incorporates:
    //   Gain: '<S410>/kd_xb'
    //   Gain: '<S410>/kp_xb'
    //   Gain: '<S415>/divide by delta T'
    //   Sum: '<S410>/Sum3'

    *rtd_BLUE_Fx = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate *
      localB->In1_g20asdt * APF_Path_Planning_2023a_BlueI_P.Kd_xblue +
      APF_Path_Planning_2023a_BlueI_P.Kp_xblue * localB->Subtract_k;

    // Sum: '<S394>/Subtract1' incorporates:
    //   Constant: '<S394>/Desired Py (BLUE)'

    localB->Subtract1_j = APF_Path_Planning_2023a_BlueI_P.home_states_BLUE[1] - *
      rtd_BLUE_Py;

    // Delay: '<S417>/Delay1'
    if (localDW->icLoad_p) {
      localDW->Delay1_DSTATE_i = localB->Subtract1_j;
    }

    // Delay: '<S417>/Delay1'
    localB->Delay1_g = localDW->Delay1_DSTATE_i;

    // Sum: '<S417>/Sum6'
    rtb_Sum6_an = localB->Subtract1_j - localB->Delay1_g;

    // If: '<S417>/if we went through a "step"'
    localDW->ifwewentthroughastep_ActiveSu_p = -1;
    if (rtb_Sum6_an != 0.0) {
      localDW->ifwewentthroughastep_ActiveSu_p = 0;

      // Outputs for IfAction SubSystem: '<S417>/Hold this value' incorporates:
      //   ActionPort: '<S418>/Action Port'

      // SignalConversion generated from: '<S418>/In1'
      localB->In1_g20asd = rtb_Sum6_an;

      // End of Outputs for SubSystem: '<S417>/Hold this value'
    }

    // End of If: '<S417>/if we went through a "step"'

    // DataStoreWrite: '<S394>/BLUE_Fy' incorporates:
    //   Gain: '<S411>/kd_yb'
    //   Gain: '<S411>/kp_yb'
    //   Gain: '<S417>/divide by delta T'
    //   Sum: '<S411>/Sum3'

    *rtd_BLUE_Fy = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate *
      localB->In1_g20asd * APF_Path_Planning_2023a_BlueI_P.Kd_yblue +
      APF_Path_Planning_2023a_BlueI_P.Kp_yblue * localB->Subtract1_j;

    // MATLAB Function: '<S412>/MATLAB Function2' incorporates:
    //   Constant: '<S394>/Desired Attitude (BLUE)'

    APF_Path_Planni_MATLABFunction2
      (APF_Path_Planning_2023a_BlueI_P.home_states_BLUE[2], localB->rtb_Oy_a_k,
       localB->rtb_Ox_d_m);

    // MATLAB Function: '<S412>/MATLAB Function3'
    APF_Path_Planni_MATLABFunction3(*rtd_BLUE_Rz, localB->rtb_Ox_kr_c);

    // Sum: '<S412>/Subtract2'
    localB->rtb_Ox_d_m[0] -= localB->rtb_Ox_kr_c[0];
    localB->rtb_Ox_d_m[1] -= localB->rtb_Ox_kr_c[1];

    // MATLAB Function: '<S412>/MATLAB Function4'
    APF_Path_Planni_MATLABFunction4(localB->rtb_Oy_a_k, localB->rtb_Ox_d_m,
      &localB->e_out_h);

    // Delay: '<S413>/Delay1'
    if (localDW->icLoad_j) {
      localDW->Delay1_DSTATE_ol = localB->e_out_h;
    }

    // Delay: '<S413>/Delay1'
    localB->Delay1_p = localDW->Delay1_DSTATE_ol;

    // Sum: '<S413>/Sum6'
    rtb_Sum6_an = localB->e_out_h - localB->Delay1_p;

    // If: '<S413>/if we went through a "step"'
    localDW->ifwewentthroughastep_ActiveSu_k = -1;
    if (rtb_Sum6_an != 0.0) {
      localDW->ifwewentthroughastep_ActiveSu_k = 0;

      // Outputs for IfAction SubSystem: '<S413>/Hold this value' incorporates:
      //   ActionPort: '<S414>/Action Port'

      // SignalConversion generated from: '<S414>/In1'
      localB->In1_g20asdtg = rtb_Sum6_an;

      // End of Outputs for SubSystem: '<S413>/Hold this value'
    }

    // End of If: '<S413>/if we went through a "step"'

    // DataStoreWrite: '<S394>/BLUE_Tz' incorporates:
    //   Gain: '<S409>/kd_tb'
    //   Gain: '<S409>/kp_tb'
    //   Gain: '<S413>/divide by delta T'
    //   Sum: '<S409>/Sum3'

    *rtd_BLUE_Tz = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate *
      localB->In1_g20asdtg * APF_Path_Planning_2023a_BlueI_P.Kd_tblue +
      APF_Path_Planning_2023a_BlueI_P.Kp_tblue * localB->e_out_h;

    // DataStoreWrite: '<S394>/Data Store Write3' incorporates:
    //   Constant: '<S394>/Puck State'

    *rtd_Float_State = localP->PuckState_Value_d;

    // End of Outputs for SubSystem: '<S10>/Change BLUE Behavior'
  }

  // End of If: '<S10>/This IF block determines whether or not to run the BLUE sim//exp' 

  // If: '<S10>/This IF block determines whether or not to run the RED sim//exp ' 
  localDW->ThisIFblockdetermineswhethero_a = -1;
  if ((*rtd_WhoAmI == 1.0) || (*rtd_isSim == 1.0)) {
    localDW->ThisIFblockdetermineswhethero_a = 0;

    // Outputs for IfAction SubSystem: '<S10>/Change RED Behavior' incorporates:
    //   ActionPort: '<S395>/Action Port'

    // DataStoreWrite: '<S395>/RED_Tz_RW1' incorporates:
    //   Constant: '<S395>/Constant2'

    *rtd_RED_Tz_RW = localP->Constant2_Value;

    // MATLAB Function: '<S425>/MATLAB Function2' incorporates:
    //   Constant: '<S395>/Desired Rz (RED)'

    APF_Path_Planni_MATLABFunction2
      (APF_Path_Planning_2023a_BlueI_P.home_states_RED[2], localB->rtb_Oy_a_k,
       localB->rtb_Ox_d_m);

    // MATLAB Function: '<S425>/MATLAB Function3'
    APF_Path_Planni_MATLABFunction3(*rtd_RED_Rz, localB->rtb_Ox_kr_c);

    // Sum: '<S425>/Subtract2'
    localB->rtb_Ox_d_m[0] -= localB->rtb_Ox_kr_c[0];
    localB->rtb_Ox_d_m[1] -= localB->rtb_Ox_kr_c[1];

    // MATLAB Function: '<S425>/MATLAB Function4'
    APF_Path_Planni_MATLABFunction4(localB->rtb_Oy_a_k, localB->rtb_Ox_d_m,
      &localB->e_out);

    // Delay: '<S427>/Delay1'
    if (localDW->icLoad) {
      localDW->Delay1_DSTATE = localB->e_out;
    }

    // Delay: '<S427>/Delay1'
    localB->Delay1 = localDW->Delay1_DSTATE;

    // Sum: '<S427>/Sum6'
    rtb_Sum6_an = localB->e_out - localB->Delay1;

    // If: '<S427>/if we went through a "step"'
    localDW->ifwewentthroughastep_ActiveSubs = -1;
    if (rtb_Sum6_an != 0.0) {
      localDW->ifwewentthroughastep_ActiveSubs = 0;

      // Outputs for IfAction SubSystem: '<S427>/Hold this value' incorporates:
      //   ActionPort: '<S428>/Action Port'

      // SignalConversion generated from: '<S428>/In1'
      localB->In1_g20as = rtb_Sum6_an;

      // End of Outputs for SubSystem: '<S427>/Hold this value'
    }

    // End of If: '<S427>/if we went through a "step"'

    // DataStoreWrite: '<S395>/RED_Tz' incorporates:
    //   Gain: '<S422>/kd_tr'
    //   Gain: '<S422>/kp_tr'
    //   Gain: '<S427>/divide by delta T'
    //   Sum: '<S422>/Sum3'

    *rtd_RED_Tz = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate *
      localB->In1_g20as * APF_Path_Planning_2023a_BlueI_P.Kd_tr +
      APF_Path_Planning_2023a_BlueI_P.Kp_tr * localB->e_out;

    // Sum: '<S395>/Subtract' incorporates:
    //   Constant: '<S395>/Desired Px (RED)'

    localB->Subtract = APF_Path_Planning_2023a_BlueI_P.home_states_RED[0] -
      *rtd_RED_Px;

    // Delay: '<S429>/Delay1'
    if (localDW->icLoad_g) {
      localDW->Delay1_DSTATE_d = localB->Subtract;
    }

    // Delay: '<S429>/Delay1'
    localB->Delay1_b = localDW->Delay1_DSTATE_d;

    // Sum: '<S429>/Sum6'
    rtb_Sum6_an = localB->Subtract - localB->Delay1_b;

    // If: '<S429>/if we went through a "step"'
    localDW->ifwewentthroughastep_ActiveSu_c = -1;
    if (rtb_Sum6_an != 0.0) {
      localDW->ifwewentthroughastep_ActiveSu_c = 0;

      // Outputs for IfAction SubSystem: '<S429>/Hold this value' incorporates:
      //   ActionPort: '<S430>/Action Port'

      // SignalConversion generated from: '<S430>/In1'
      localB->In1_g20a = rtb_Sum6_an;

      // End of Outputs for SubSystem: '<S429>/Hold this value'
    }

    // End of If: '<S429>/if we went through a "step"'

    // DataStoreWrite: '<S395>/RED_Fx' incorporates:
    //   Gain: '<S423>/kd_xr'
    //   Gain: '<S423>/kp_xr'
    //   Gain: '<S429>/divide by delta T'
    //   Sum: '<S423>/Sum3'

    *rtd_RED_Fx = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate *
      localB->In1_g20a * APF_Path_Planning_2023a_BlueI_P.Kd_xr +
      APF_Path_Planning_2023a_BlueI_P.Kp_xr * localB->Subtract;

    // Sum: '<S395>/Subtract1' incorporates:
    //   Constant: '<S395>/Desired Py (RED)'

    localB->Subtract1 = APF_Path_Planning_2023a_BlueI_P.home_states_RED[1] -
      *rtd_RED_Py;

    // Delay: '<S431>/Delay1'
    if (localDW->icLoad_d) {
      localDW->Delay1_DSTATE_o = localB->Subtract1;
    }

    // Delay: '<S431>/Delay1'
    localB->Delay1_d = localDW->Delay1_DSTATE_o;

    // Sum: '<S431>/Sum6'
    rtb_Sum6_an = localB->Subtract1 - localB->Delay1_d;

    // If: '<S431>/if we went through a "step"'
    localDW->ifwewentthroughastep_ActiveSu_m = -1;
    if (rtb_Sum6_an != 0.0) {
      localDW->ifwewentthroughastep_ActiveSu_m = 0;

      // Outputs for IfAction SubSystem: '<S431>/Hold this value' incorporates:
      //   ActionPort: '<S432>/Action Port'

      // SignalConversion generated from: '<S432>/In1'
      localB->In1_g20 = rtb_Sum6_an;

      // End of Outputs for SubSystem: '<S431>/Hold this value'
    }

    // End of If: '<S431>/if we went through a "step"'

    // DataStoreWrite: '<S395>/RED_Fy' incorporates:
    //   Gain: '<S424>/kd_yr'
    //   Gain: '<S424>/kp_yr'
    //   Gain: '<S431>/divide by delta T'
    //   Sum: '<S424>/Sum3'

    *rtd_RED_Fy = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate *
      localB->In1_g20 * APF_Path_Planning_2023a_BlueI_P.Kd_yr +
      APF_Path_Planning_2023a_BlueI_P.Kp_yr * localB->Subtract1;

    // DataStoreWrite: '<S395>/Data Store Write3' incorporates:
    //   Constant: '<S395>/Puck State'

    *rtd_Float_State = localP->PuckState_Value_c;

    // If: '<S395>/If' incorporates:
    //   Constant: '<S395>/Constant4'

    if ((APF_Path_Planning_2023a_BlueI_P.platformSelection == 4.0) ||
        (APF_Path_Planning_2023a_BlueI_P.platformSelection == 5.0) ||
        (APF_Path_Planning_2023a_BlueI_P.platformSelection == 10.0) ||
        (APF_Path_Planning_2023a_BlueI_P.platformSelection == 11.0)) {
      // Outputs for IfAction SubSystem: '<S395>/RED+ARM' incorporates:
      //   ActionPort: '<S426>/Action Port'

      // If: '<S426>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 
      if (*rtd_isSim == 1.0) {
        // Outputs for IfAction SubSystem: '<S426>/Simulated Position Controller' incorporates:
        //   ActionPort: '<S437>/Action Port'

        // Sum: '<S437>/Subtract2' incorporates:
        //   Constant: '<S426>/Constant1'

        rtb_Sum6_an = localP->Constant1_Value - *rtd_RED_Rz_Shoulder;

        // Delay: '<S443>/Delay1'
        if (localDW->icLoad_e) {
          localDW->Delay1_DSTATE_j = rtb_Sum6_an;
        }

        // Sum: '<S443>/Sum6' incorporates:
        //   Delay: '<S443>/Delay1'

        rtb_Sum6_oa = rtb_Sum6_an - localDW->Delay1_DSTATE_j;

        // If: '<S443>/if we went through a "step"'
        if (rtb_Sum6_oa != 0.0) {
          // Outputs for IfAction SubSystem: '<S443>/Hold this value' incorporates:
          //   ActionPort: '<S444>/Action Port'

          // SignalConversion generated from: '<S444>/In1'
          localB->In1_g = rtb_Sum6_oa;

          // End of Outputs for SubSystem: '<S443>/Hold this value'
        }

        // End of If: '<S443>/if we went through a "step"'

        // Sum: '<S439>/Sum3' incorporates:
        //   Gain: '<S439>/kd_sharm'
        //   Gain: '<S439>/kp_sharm'
        //   Gain: '<S443>/divide by delta T'

        rtb_Sum6_ea = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate *
          localB->In1_g * APF_Path_Planning_2023a_BlueI_P.Kd_sharm +
          APF_Path_Planning_2023a_BlueI_P.Kp_sharm * rtb_Sum6_an;

        // Saturate: '<S437>/Saturation'
        if (rtb_Sum6_ea > APF_Path_Planning_2023a_BlueI_P.Tz_lim_sharm) {
          // DataStoreWrite: '<S426>/Data Store Write'
          *rtd_RED_Shoulder_Command =
            APF_Path_Planning_2023a_BlueI_P.Tz_lim_sharm;
        } else if (rtb_Sum6_ea < -APF_Path_Planning_2023a_BlueI_P.Tz_lim_sharm)
        {
          // DataStoreWrite: '<S426>/Data Store Write'
          *rtd_RED_Shoulder_Command =
            -APF_Path_Planning_2023a_BlueI_P.Tz_lim_sharm;
        } else {
          // DataStoreWrite: '<S426>/Data Store Write'
          *rtd_RED_Shoulder_Command = rtb_Sum6_ea;
        }

        // End of Saturate: '<S437>/Saturation'

        // Sum: '<S437>/Subtract3' incorporates:
        //   Constant: '<S426>/Constant1'

        rtb_Sum6_oa = localP->Constant1_Value - *rtd_RED_Rz_Elbow;

        // Delay: '<S441>/Delay1'
        if (localDW->icLoad_gp) {
          localDW->Delay1_DSTATE_l = rtb_Sum6_oa;
        }

        // Sum: '<S441>/Sum6' incorporates:
        //   Delay: '<S441>/Delay1'

        rtb_Sum6_j5q = rtb_Sum6_oa - localDW->Delay1_DSTATE_l;

        // If: '<S441>/if we went through a "step"'
        if (rtb_Sum6_j5q != 0.0) {
          // Outputs for IfAction SubSystem: '<S441>/Hold this value' incorporates:
          //   ActionPort: '<S442>/Action Port'

          // SignalConversion generated from: '<S442>/In1'
          localB->In1_g2 = rtb_Sum6_j5q;

          // End of Outputs for SubSystem: '<S441>/Hold this value'
        }

        // End of If: '<S441>/if we went through a "step"'

        // Sum: '<S438>/Sum3' incorporates:
        //   Gain: '<S438>/kd_elarm'
        //   Gain: '<S438>/kp_elarm'
        //   Gain: '<S441>/divide by delta T'

        rtb_Sum6_ea = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate *
          localB->In1_g2 * APF_Path_Planning_2023a_BlueI_P.Kd_elarm +
          APF_Path_Planning_2023a_BlueI_P.Kp_elarm * rtb_Sum6_oa;

        // Saturate: '<S437>/Saturation1'
        if (rtb_Sum6_ea > APF_Path_Planning_2023a_BlueI_P.Tz_lim_elarm) {
          // DataStoreWrite: '<S426>/Data Store Write1'
          *rtd_RED_Elbow_Command = APF_Path_Planning_2023a_BlueI_P.Tz_lim_elarm;
        } else if (rtb_Sum6_ea < -APF_Path_Planning_2023a_BlueI_P.Tz_lim_elarm)
        {
          // DataStoreWrite: '<S426>/Data Store Write1'
          *rtd_RED_Elbow_Command = -APF_Path_Planning_2023a_BlueI_P.Tz_lim_elarm;
        } else {
          // DataStoreWrite: '<S426>/Data Store Write1'
          *rtd_RED_Elbow_Command = rtb_Sum6_ea;
        }

        // End of Saturate: '<S437>/Saturation1'

        // Sum: '<S437>/Subtract4' incorporates:
        //   Constant: '<S426>/Constant6'

        rtb_Sum6_j5q = localP->Constant6_Value - *rtd_RED_Rz_Wrist;

        // Delay: '<S445>/Delay1'
        if (localDW->icLoad_k) {
          localDW->Delay1_DSTATE_h = rtb_Sum6_j5q;
        }

        // Sum: '<S445>/Sum6' incorporates:
        //   Delay: '<S445>/Delay1'

        rtb_Sum6_ea = rtb_Sum6_j5q - localDW->Delay1_DSTATE_h;

        // If: '<S445>/if we went through a "step"'
        if (rtb_Sum6_ea != 0.0) {
          // Outputs for IfAction SubSystem: '<S445>/Hold this value' incorporates:
          //   ActionPort: '<S446>/Action Port'

          // SignalConversion generated from: '<S446>/In1'
          localB->In1 = rtb_Sum6_ea;

          // End of Outputs for SubSystem: '<S445>/Hold this value'
        }

        // End of If: '<S445>/if we went through a "step"'

        // Sum: '<S440>/Sum3' incorporates:
        //   Gain: '<S440>/kd_wrarm'
        //   Gain: '<S440>/kp_wrarm'
        //   Gain: '<S445>/divide by delta T'

        rtb_Sum6_ea = 1.0 / APF_Path_Planning_2023a_BlueI_P.baseRate *
          localB->In1 * APF_Path_Planning_2023a_BlueI_P.Kd_wrarm +
          APF_Path_Planning_2023a_BlueI_P.Kp_wrarm * rtb_Sum6_j5q;

        // Saturate: '<S437>/Saturation3'
        if (rtb_Sum6_ea > APF_Path_Planning_2023a_BlueI_P.Tz_lim_wrarm) {
          // DataStoreWrite: '<S426>/Data Store Write2'
          *rtd_RED_Wrist_Command = APF_Path_Planning_2023a_BlueI_P.Tz_lim_wrarm;
        } else if (rtb_Sum6_ea < -APF_Path_Planning_2023a_BlueI_P.Tz_lim_wrarm)
        {
          // DataStoreWrite: '<S426>/Data Store Write2'
          *rtd_RED_Wrist_Command = -APF_Path_Planning_2023a_BlueI_P.Tz_lim_wrarm;
        } else {
          // DataStoreWrite: '<S426>/Data Store Write2'
          *rtd_RED_Wrist_Command = rtb_Sum6_ea;
        }

        // End of Saturate: '<S437>/Saturation3'

        // Update for Delay: '<S443>/Delay1'
        localDW->icLoad_e = false;
        localDW->Delay1_DSTATE_j = rtb_Sum6_an;

        // Update for Delay: '<S441>/Delay1'
        localDW->icLoad_gp = false;
        localDW->Delay1_DSTATE_l = rtb_Sum6_oa;

        // Update for Delay: '<S445>/Delay1'
        localDW->icLoad_k = false;
        localDW->Delay1_DSTATE_h = rtb_Sum6_j5q;

        // End of Outputs for SubSystem: '<S426>/Simulated Position Controller'
      } else {
        // Outputs for IfAction SubSystem: '<S426>/Passthrough for Experiment' incorporates:
        //   ActionPort: '<S436>/Action Port'

        // DataStoreWrite: '<S426>/Data Store Write' incorporates:
        //   Constant: '<S426>/Constant1'
        //   SignalConversion generated from: '<S436>/q1_desired'

        *rtd_RED_Shoulder_Command = localP->Constant1_Value;

        // DataStoreWrite: '<S426>/Data Store Write1' incorporates:
        //   Constant: '<S426>/Constant1'
        //   SignalConversion generated from: '<S436>/q2_desired'

        *rtd_RED_Elbow_Command = localP->Constant1_Value;

        // DataStoreWrite: '<S426>/Data Store Write2' incorporates:
        //   Constant: '<S426>/Constant6'
        //   SignalConversion generated from: '<S436>/q3_desired'

        *rtd_RED_Wrist_Command = localP->Constant6_Value;

        // End of Outputs for SubSystem: '<S426>/Passthrough for Experiment'
      }

      // End of If: '<S426>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 

      // DataStoreWrite: '<S426>/Data Store Write3' incorporates:
      //   Constant: '<S426>/Constant7'

      *rtd_RED_ARM_Control_Mode = localP->Constant7_Value;

      // End of Outputs for SubSystem: '<S395>/RED+ARM'
    }

    // End of If: '<S395>/If'
    // End of Outputs for SubSystem: '<S10>/Change RED Behavior'
  }

  // End of If: '<S10>/This IF block determines whether or not to run the RED sim//exp ' 
}

//
// Update for action system:
//    '<Root>/Phase #4: Return Home'
//    '<Root>/Phase #5: Hold Home'
//
void APF_Pat_Phase4ReturnHome_Update(B_Phase4ReturnHome_APF_Path_P_T *localB,
  DW_Phase4ReturnHome_APF_Path__T *localDW)
{
  // Update for If: '<S10>/This IF block determines whether or not to run the BLACK sim//exp' 
  if (localDW->ThisIFblockdetermineswhetherorn == 0) {
    // Update for IfAction SubSystem: '<S10>/Change BLACK Behavior' incorporates:
    //   ActionPort: '<S393>/Action Port'

    // Update for Delay: '<S402>/Delay1'
    localDW->icLoad_f = false;
    localDW->Delay1_DSTATE_a = localB->Subtract_c;

    // Update for Delay: '<S404>/Delay1'
    localDW->icLoad_jl = false;
    localDW->Delay1_DSTATE_jh = localB->Subtract1_k;

    // Update for Delay: '<S400>/Delay1'
    localDW->icLoad_ca = false;
    localDW->Delay1_DSTATE_h5 = localB->e_out_hp;

    // End of Update for SubSystem: '<S10>/Change BLACK Behavior'
  }

  // End of Update for If: '<S10>/This IF block determines whether or not to run the BLACK sim//exp' 

  // Update for If: '<S10>/This IF block determines whether or not to run the BLUE sim//exp' 
  if (localDW->ThisIFblockdetermineswhethero_j == 0) {
    // Update for IfAction SubSystem: '<S10>/Change BLUE Behavior' incorporates:
    //   ActionPort: '<S394>/Action Port'

    // Update for Delay: '<S415>/Delay1'
    localDW->icLoad_c = false;
    localDW->Delay1_DSTATE_f = localB->Subtract_k;

    // Update for Delay: '<S417>/Delay1'
    localDW->icLoad_p = false;
    localDW->Delay1_DSTATE_i = localB->Subtract1_j;

    // Update for Delay: '<S413>/Delay1'
    localDW->icLoad_j = false;
    localDW->Delay1_DSTATE_ol = localB->e_out_h;

    // End of Update for SubSystem: '<S10>/Change BLUE Behavior'
  }

  // End of Update for If: '<S10>/This IF block determines whether or not to run the BLUE sim//exp' 

  // Update for If: '<S10>/This IF block determines whether or not to run the RED sim//exp ' 
  if (localDW->ThisIFblockdetermineswhethero_a == 0) {
    // Update for IfAction SubSystem: '<S10>/Change RED Behavior' incorporates:
    //   ActionPort: '<S395>/Action Port'

    // Update for Delay: '<S427>/Delay1'
    localDW->icLoad = false;
    localDW->Delay1_DSTATE = localB->e_out;

    // Update for Delay: '<S429>/Delay1'
    localDW->icLoad_g = false;
    localDW->Delay1_DSTATE_d = localB->Subtract;

    // Update for Delay: '<S431>/Delay1'
    localDW->icLoad_d = false;
    localDW->Delay1_DSTATE_o = localB->Subtract1;

    // End of Update for SubSystem: '<S10>/Change RED Behavior'
  }

  // End of Update for If: '<S10>/This IF block determines whether or not to run the RED sim//exp ' 
}

// Function for MATLAB Function: '<S610>/MATLAB Function1'
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
//    '<S610>/MATLAB Function1'
//    '<S622>/MATLAB Function2'
//    '<S634>/MATLAB Function2'
//
void APF_Path_Plan_MATLABFunction1_l(const real_T rtu_ThrustPer[8], real_T
  rty_ThrustPer_Final[8])
{
  real_T TControl;
  real_T ThrustPer_Sat;
  real_T maxval;
  int32_T i;
  TControl = 1.0 / APF_Path_Planning_2023a_BlueI_P.PWMFreq;
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

// Function for MATLAB Function: '<S610>/MATLAB Function10'
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
//    '<S610>/MATLAB Function10'
//    '<S622>/MATLAB Function6'
//    '<S634>/MATLAB Function5'
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

    x[i] = (rtu_PWMs_0 >
            APF_Path_Planning_2023a_BlueI_P.thruster_count_threshold);
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
//    '<S617>/Create Rotation Matrix'
//    '<S629>/Create Rotation Matrix'
//    '<S650>/Create Rotation Matrix'
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
//    '<S611>/Create Rotation Matrix'
//    '<S623>/Create Rotation Matrix'
//    '<S635>/Create Rotation Matrix'
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

// Function for MATLAB Function: '<S356>/MATLAB Function'
static void APF_Path_Planning_2023a_xzlascl(real_T cfrom, real_T cto, real_T A
  [36])
{
  APF_Path_Planning_2023a_BlueI_B.cfromc_i = cfrom;
  APF_Path_Planning_2023a_BlueI_B.ctoc_l = cto;
  APF_Path_Planning_2023a_BlueI_B.notdone_o = true;
  while (APF_Path_Planning_2023a_BlueI_B.notdone_o) {
    APF_Path_Planning_2023a_BlueI_B.cfrom1_o =
      APF_Path_Planning_2023a_BlueI_B.cfromc_i * 2.0041683600089728E-292;
    APF_Path_Planning_2023a_BlueI_B.cto1_o =
      APF_Path_Planning_2023a_BlueI_B.ctoc_l / 4.9896007738368E+291;
    if ((fabs(APF_Path_Planning_2023a_BlueI_B.cfrom1_o) > fabs
         (APF_Path_Planning_2023a_BlueI_B.ctoc_l)) &&
        (APF_Path_Planning_2023a_BlueI_B.ctoc_l != 0.0)) {
      APF_Path_Planning_2023a_BlueI_B.mul_i = 2.0041683600089728E-292;
      APF_Path_Planning_2023a_BlueI_B.cfromc_i =
        APF_Path_Planning_2023a_BlueI_B.cfrom1_o;
    } else if (fabs(APF_Path_Planning_2023a_BlueI_B.cto1_o) > fabs
               (APF_Path_Planning_2023a_BlueI_B.cfromc_i)) {
      APF_Path_Planning_2023a_BlueI_B.mul_i = 4.9896007738368E+291;
      APF_Path_Planning_2023a_BlueI_B.ctoc_l =
        APF_Path_Planning_2023a_BlueI_B.cto1_o;
    } else {
      APF_Path_Planning_2023a_BlueI_B.mul_i =
        APF_Path_Planning_2023a_BlueI_B.ctoc_l /
        APF_Path_Planning_2023a_BlueI_B.cfromc_i;
      APF_Path_Planning_2023a_BlueI_B.notdone_o = false;
    }

    for (APF_Path_Planning_2023a_BlueI_B.i3 = 0;
         APF_Path_Planning_2023a_BlueI_B.i3 < 36;
         APF_Path_Planning_2023a_BlueI_B.i3++) {
      A[APF_Path_Planning_2023a_BlueI_B.i3] *=
        APF_Path_Planning_2023a_BlueI_B.mul_i;
    }
  }
}

// Function for MATLAB Function: '<S356>/MATLAB Function'
static real_T APF_Path_Planning_2023a_xnrm2_m(int32_T n, const real_T x[36],
  int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      APF_Path_Planning_2023a_BlueI_B.scale_m = 3.3121686421112381E-170;
      APF_Path_Planning_2023a_BlueI_B.kend_e = (ix0 + n) - 1;
      for (APF_Path_Planning_2023a_BlueI_B.k_o = ix0;
           APF_Path_Planning_2023a_BlueI_B.k_o <=
           APF_Path_Planning_2023a_BlueI_B.kend_e;
           APF_Path_Planning_2023a_BlueI_B.k_o++) {
        APF_Path_Planning_2023a_BlueI_B.absxk_m = fabs
          (x[APF_Path_Planning_2023a_BlueI_B.k_o - 1]);
        if (APF_Path_Planning_2023a_BlueI_B.absxk_m >
            APF_Path_Planning_2023a_BlueI_B.scale_m) {
          APF_Path_Planning_2023a_BlueI_B.t_j =
            APF_Path_Planning_2023a_BlueI_B.scale_m /
            APF_Path_Planning_2023a_BlueI_B.absxk_m;
          y = y * APF_Path_Planning_2023a_BlueI_B.t_j *
            APF_Path_Planning_2023a_BlueI_B.t_j + 1.0;
          APF_Path_Planning_2023a_BlueI_B.scale_m =
            APF_Path_Planning_2023a_BlueI_B.absxk_m;
        } else {
          APF_Path_Planning_2023a_BlueI_B.t_j =
            APF_Path_Planning_2023a_BlueI_B.absxk_m /
            APF_Path_Planning_2023a_BlueI_B.scale_m;
          y += APF_Path_Planning_2023a_BlueI_B.t_j *
            APF_Path_Planning_2023a_BlueI_B.t_j;
        }
      }

      y = APF_Path_Planning_2023a_BlueI_B.scale_m * sqrt(y);
    }
  }

  return y;
}

static real_T APF_Path_Planning_rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  APF_Path_Planning_2023a_BlueI_B.a = fabs(u0);
  APF_Path_Planning_2023a_BlueI_B.b_n = fabs(u1);
  if (APF_Path_Planning_2023a_BlueI_B.a < APF_Path_Planning_2023a_BlueI_B.b_n) {
    APF_Path_Planning_2023a_BlueI_B.a /= APF_Path_Planning_2023a_BlueI_B.b_n;
    y = sqrt(APF_Path_Planning_2023a_BlueI_B.a *
             APF_Path_Planning_2023a_BlueI_B.a + 1.0) *
      APF_Path_Planning_2023a_BlueI_B.b_n;
  } else if (APF_Path_Planning_2023a_BlueI_B.a >
             APF_Path_Planning_2023a_BlueI_B.b_n) {
    APF_Path_Planning_2023a_BlueI_B.b_n /= APF_Path_Planning_2023a_BlueI_B.a;
    y = sqrt(APF_Path_Planning_2023a_BlueI_B.b_n *
             APF_Path_Planning_2023a_BlueI_B.b_n + 1.0) *
      APF_Path_Planning_2023a_BlueI_B.a;
  } else if (rtIsNaN(APF_Path_Planning_2023a_BlueI_B.b_n)) {
    y = (rtNaN);
  } else {
    y = APF_Path_Planning_2023a_BlueI_B.a * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S356>/MATLAB Function'
static real_T APF_Path_Planning_2023a_xzlarfg(int32_T n, real_T *alpha1, real_T
  x[36], int32_T ix0)
{
  real_T tau;
  tau = 0.0;
  if (n > 0) {
    APF_Path_Planning_2023a_BlueI_B.xnorm = APF_Path_Planning_2023a_xnrm2_m(n -
      1, x, ix0);
    if (APF_Path_Planning_2023a_BlueI_B.xnorm != 0.0) {
      APF_Path_Planning_2023a_BlueI_B.xnorm = APF_Path_Planning_rt_hypotd_snf
        (*alpha1, APF_Path_Planning_2023a_BlueI_B.xnorm);
      if (*alpha1 >= 0.0) {
        APF_Path_Planning_2023a_BlueI_B.xnorm =
          -APF_Path_Planning_2023a_BlueI_B.xnorm;
      }

      if (fabs(APF_Path_Planning_2023a_BlueI_B.xnorm) < 1.0020841800044864E-292)
      {
        APF_Path_Planning_2023a_BlueI_B.knt_p = 0;
        APF_Path_Planning_2023a_BlueI_B.d_tmp_j = (ix0 + n) - 2;
        do {
          APF_Path_Planning_2023a_BlueI_B.knt_p++;
          for (APF_Path_Planning_2023a_BlueI_B.c_a = ix0;
               APF_Path_Planning_2023a_BlueI_B.c_a <=
               APF_Path_Planning_2023a_BlueI_B.d_tmp_j;
               APF_Path_Planning_2023a_BlueI_B.c_a++) {
            x[APF_Path_Planning_2023a_BlueI_B.c_a - 1] *= 9.9792015476736E+291;
          }

          APF_Path_Planning_2023a_BlueI_B.xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((fabs(APF_Path_Planning_2023a_BlueI_B.xnorm) <
                  1.0020841800044864E-292) &&
                 (APF_Path_Planning_2023a_BlueI_B.knt_p < 20));

        APF_Path_Planning_2023a_BlueI_B.xnorm = APF_Path_Planning_rt_hypotd_snf(*
          alpha1, APF_Path_Planning_2023a_xnrm2_m(n - 1, x, ix0));
        if (*alpha1 >= 0.0) {
          APF_Path_Planning_2023a_BlueI_B.xnorm =
            -APF_Path_Planning_2023a_BlueI_B.xnorm;
        }

        tau = (APF_Path_Planning_2023a_BlueI_B.xnorm - *alpha1) /
          APF_Path_Planning_2023a_BlueI_B.xnorm;
        APF_Path_Planning_2023a_BlueI_B.a_c = 1.0 / (*alpha1 -
          APF_Path_Planning_2023a_BlueI_B.xnorm);
        for (APF_Path_Planning_2023a_BlueI_B.c_a = ix0;
             APF_Path_Planning_2023a_BlueI_B.c_a <=
             APF_Path_Planning_2023a_BlueI_B.d_tmp_j;
             APF_Path_Planning_2023a_BlueI_B.c_a++) {
          x[APF_Path_Planning_2023a_BlueI_B.c_a - 1] *=
            APF_Path_Planning_2023a_BlueI_B.a_c;
        }

        for (APF_Path_Planning_2023a_BlueI_B.c_a = 0;
             APF_Path_Planning_2023a_BlueI_B.c_a <
             APF_Path_Planning_2023a_BlueI_B.knt_p;
             APF_Path_Planning_2023a_BlueI_B.c_a++) {
          APF_Path_Planning_2023a_BlueI_B.xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = APF_Path_Planning_2023a_BlueI_B.xnorm;
      } else {
        tau = (APF_Path_Planning_2023a_BlueI_B.xnorm - *alpha1) /
          APF_Path_Planning_2023a_BlueI_B.xnorm;
        APF_Path_Planning_2023a_BlueI_B.a_c = 1.0 / (*alpha1 -
          APF_Path_Planning_2023a_BlueI_B.xnorm);
        APF_Path_Planning_2023a_BlueI_B.c_a = (ix0 + n) - 2;
        for (APF_Path_Planning_2023a_BlueI_B.knt_p = ix0;
             APF_Path_Planning_2023a_BlueI_B.knt_p <=
             APF_Path_Planning_2023a_BlueI_B.c_a;
             APF_Path_Planning_2023a_BlueI_B.knt_p++) {
          x[APF_Path_Planning_2023a_BlueI_B.knt_p - 1] *=
            APF_Path_Planning_2023a_BlueI_B.a_c;
        }

        *alpha1 = APF_Path_Planning_2023a_BlueI_B.xnorm;
      }
    }
  }

  return tau;
}

// Function for MATLAB Function: '<S356>/MATLAB Function'
static void APF_Path_Planning_2023a_xzgehrd(real_T a[36], int32_T ilo, int32_T
  ihi)
{
  int32_T exitg1;
  boolean_T exitg2;
  if ((ihi - ilo) + 1 > 1) {
    APF_Path_Planning_2023a_BlueI_B.b_kl = static_cast<uint8_T>(ilo - 1);
    if (APF_Path_Planning_2023a_BlueI_B.b_kl - 1 >= 0) {
      memset(&APF_Path_Planning_2023a_BlueI_B.tau_g[0], 0, static_cast<uint32_T>
             (APF_Path_Planning_2023a_BlueI_B.b_kl) * sizeof(real_T));
    }

    for (APF_Path_Planning_2023a_BlueI_B.b_kl = ihi;
         APF_Path_Planning_2023a_BlueI_B.b_kl < 6;
         APF_Path_Planning_2023a_BlueI_B.b_kl++) {
      APF_Path_Planning_2023a_BlueI_B.tau_g[APF_Path_Planning_2023a_BlueI_B.b_kl
        - 1] = 0.0;
    }

    for (APF_Path_Planning_2023a_BlueI_B.b_kl = 0;
         APF_Path_Planning_2023a_BlueI_B.b_kl < 6;
         APF_Path_Planning_2023a_BlueI_B.b_kl++) {
      APF_Path_Planning_2023a_BlueI_B.work_j[APF_Path_Planning_2023a_BlueI_B.b_kl]
        = 0.0;
    }

    for (APF_Path_Planning_2023a_BlueI_B.b_kl = ilo;
         APF_Path_Planning_2023a_BlueI_B.b_kl < ihi;
         APF_Path_Planning_2023a_BlueI_B.b_kl++) {
      APF_Path_Planning_2023a_BlueI_B.lastv =
        (APF_Path_Planning_2023a_BlueI_B.b_kl - 1) * 6;
      APF_Path_Planning_2023a_BlueI_B.in = APF_Path_Planning_2023a_BlueI_B.b_kl *
        6;
      APF_Path_Planning_2023a_BlueI_B.b_tmp =
        APF_Path_Planning_2023a_BlueI_B.lastv +
        APF_Path_Planning_2023a_BlueI_B.b_kl;
      APF_Path_Planning_2023a_BlueI_B.alpha1 =
        a[APF_Path_Planning_2023a_BlueI_B.b_tmp];
      if (APF_Path_Planning_2023a_BlueI_B.b_kl + 2 <= 6) {
        APF_Path_Planning_2023a_BlueI_B.lastc =
          APF_Path_Planning_2023a_BlueI_B.b_kl + 2;
      } else {
        APF_Path_Planning_2023a_BlueI_B.lastc = 6;
      }

      APF_Path_Planning_2023a_BlueI_B.b_lastv = ihi -
        APF_Path_Planning_2023a_BlueI_B.b_kl;
      APF_Path_Planning_2023a_BlueI_B.tau_m = APF_Path_Planning_2023a_xzlarfg
        (APF_Path_Planning_2023a_BlueI_B.b_lastv,
         &APF_Path_Planning_2023a_BlueI_B.alpha1, a,
         APF_Path_Planning_2023a_BlueI_B.lastv +
         APF_Path_Planning_2023a_BlueI_B.lastc);
      APF_Path_Planning_2023a_BlueI_B.tau_g[APF_Path_Planning_2023a_BlueI_B.b_kl
        - 1] = APF_Path_Planning_2023a_BlueI_B.tau_m;
      a[APF_Path_Planning_2023a_BlueI_B.b_tmp] = 1.0;
      if (APF_Path_Planning_2023a_BlueI_B.tau_m != 0.0) {
        APF_Path_Planning_2023a_BlueI_B.lastv =
          APF_Path_Planning_2023a_BlueI_B.b_lastv;
        APF_Path_Planning_2023a_BlueI_B.lastc =
          APF_Path_Planning_2023a_BlueI_B.b_tmp +
          APF_Path_Planning_2023a_BlueI_B.b_lastv;
        while ((APF_Path_Planning_2023a_BlueI_B.lastv > 0) &&
               (a[APF_Path_Planning_2023a_BlueI_B.lastc - 1] == 0.0)) {
          APF_Path_Planning_2023a_BlueI_B.lastv--;
          APF_Path_Planning_2023a_BlueI_B.lastc--;
        }

        APF_Path_Planning_2023a_BlueI_B.lastc = ihi;
        exitg2 = false;
        while ((!exitg2) && (APF_Path_Planning_2023a_BlueI_B.lastc > 0)) {
          APF_Path_Planning_2023a_BlueI_B.rowleft =
            APF_Path_Planning_2023a_BlueI_B.in +
            APF_Path_Planning_2023a_BlueI_B.lastc;
          APF_Path_Planning_2023a_BlueI_B.b_ia =
            APF_Path_Planning_2023a_BlueI_B.rowleft;
          do {
            exitg1 = 0;
            if (APF_Path_Planning_2023a_BlueI_B.b_ia <=
                (APF_Path_Planning_2023a_BlueI_B.lastv - 1) * 6 +
                APF_Path_Planning_2023a_BlueI_B.rowleft) {
              if (a[APF_Path_Planning_2023a_BlueI_B.b_ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                APF_Path_Planning_2023a_BlueI_B.b_ia += 6;
              }
            } else {
              APF_Path_Planning_2023a_BlueI_B.lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        APF_Path_Planning_2023a_BlueI_B.lastv = 0;
        APF_Path_Planning_2023a_BlueI_B.lastc = 0;
      }

      if (APF_Path_Planning_2023a_BlueI_B.lastv > 0) {
        if (APF_Path_Planning_2023a_BlueI_B.lastc != 0) {
          APF_Path_Planning_2023a_BlueI_B.b_ia = static_cast<uint8_T>
            (APF_Path_Planning_2023a_BlueI_B.lastc);
          memset(&APF_Path_Planning_2023a_BlueI_B.work_j[0], 0,
                 static_cast<uint32_T>(APF_Path_Planning_2023a_BlueI_B.b_ia) *
                 sizeof(real_T));
          APF_Path_Planning_2023a_BlueI_B.ix =
            APF_Path_Planning_2023a_BlueI_B.b_tmp;
          APF_Path_Planning_2023a_BlueI_B.d_p =
            ((APF_Path_Planning_2023a_BlueI_B.lastv - 1) * 6 +
             APF_Path_Planning_2023a_BlueI_B.in) + 1;
          for (APF_Path_Planning_2023a_BlueI_B.b_ia =
               APF_Path_Planning_2023a_BlueI_B.in + 1;
               APF_Path_Planning_2023a_BlueI_B.b_ia <=
               APF_Path_Planning_2023a_BlueI_B.d_p;
               APF_Path_Planning_2023a_BlueI_B.b_ia += 6) {
            APF_Path_Planning_2023a_BlueI_B.e_p =
              (APF_Path_Planning_2023a_BlueI_B.b_ia +
               APF_Path_Planning_2023a_BlueI_B.lastc) - 1;
            for (APF_Path_Planning_2023a_BlueI_B.ia =
                 APF_Path_Planning_2023a_BlueI_B.b_ia;
                 APF_Path_Planning_2023a_BlueI_B.ia <=
                 APF_Path_Planning_2023a_BlueI_B.e_p;
                 APF_Path_Planning_2023a_BlueI_B.ia++) {
              APF_Path_Planning_2023a_BlueI_B.rowleft =
                APF_Path_Planning_2023a_BlueI_B.ia -
                APF_Path_Planning_2023a_BlueI_B.b_ia;
              APF_Path_Planning_2023a_BlueI_B.work_j[APF_Path_Planning_2023a_BlueI_B.rowleft]
                += a[APF_Path_Planning_2023a_BlueI_B.ia - 1] *
                a[APF_Path_Planning_2023a_BlueI_B.ix];
            }

            APF_Path_Planning_2023a_BlueI_B.ix++;
          }
        }

        APF_Path_Planning_2023a_BlueI_B.tau_m =
          -APF_Path_Planning_2023a_BlueI_B.tau_g[APF_Path_Planning_2023a_BlueI_B.b_kl
          - 1];
        if (!(APF_Path_Planning_2023a_BlueI_B.tau_m == 0.0)) {
          APF_Path_Planning_2023a_BlueI_B.rowleft =
            APF_Path_Planning_2023a_BlueI_B.in + 1;
          APF_Path_Planning_2023a_BlueI_B.ia = static_cast<uint8_T>
            (APF_Path_Planning_2023a_BlueI_B.lastv);
          for (APF_Path_Planning_2023a_BlueI_B.lastv = 0;
               APF_Path_Planning_2023a_BlueI_B.lastv <
               APF_Path_Planning_2023a_BlueI_B.ia;
               APF_Path_Planning_2023a_BlueI_B.lastv++) {
            APF_Path_Planning_2023a_BlueI_B.temp_n =
              a[APF_Path_Planning_2023a_BlueI_B.b_tmp +
              APF_Path_Planning_2023a_BlueI_B.lastv];
            if (APF_Path_Planning_2023a_BlueI_B.temp_n != 0.0) {
              APF_Path_Planning_2023a_BlueI_B.temp_n *=
                APF_Path_Planning_2023a_BlueI_B.tau_m;
              APF_Path_Planning_2023a_BlueI_B.ix =
                (APF_Path_Planning_2023a_BlueI_B.lastc +
                 APF_Path_Planning_2023a_BlueI_B.rowleft) - 1;
              for (APF_Path_Planning_2023a_BlueI_B.b_ia =
                   APF_Path_Planning_2023a_BlueI_B.rowleft;
                   APF_Path_Planning_2023a_BlueI_B.b_ia <=
                   APF_Path_Planning_2023a_BlueI_B.ix;
                   APF_Path_Planning_2023a_BlueI_B.b_ia++) {
                a[APF_Path_Planning_2023a_BlueI_B.b_ia - 1] +=
                  APF_Path_Planning_2023a_BlueI_B.work_j[APF_Path_Planning_2023a_BlueI_B.b_ia
                  - APF_Path_Planning_2023a_BlueI_B.rowleft] *
                  APF_Path_Planning_2023a_BlueI_B.temp_n;
              }
            }

            APF_Path_Planning_2023a_BlueI_B.rowleft += 6;
          }
        }
      }

      APF_Path_Planning_2023a_BlueI_B.in = (APF_Path_Planning_2023a_BlueI_B.b_kl
        + APF_Path_Planning_2023a_BlueI_B.in) + 1;
      APF_Path_Planning_2023a_BlueI_B.tau_m =
        APF_Path_Planning_2023a_BlueI_B.tau_g[APF_Path_Planning_2023a_BlueI_B.b_kl
        - 1];
      if (APF_Path_Planning_2023a_BlueI_B.tau_m != 0.0) {
        APF_Path_Planning_2023a_BlueI_B.lastc =
          APF_Path_Planning_2023a_BlueI_B.b_tmp +
          APF_Path_Planning_2023a_BlueI_B.b_lastv;
        while ((APF_Path_Planning_2023a_BlueI_B.b_lastv > 0) &&
               (a[APF_Path_Planning_2023a_BlueI_B.lastc - 1] == 0.0)) {
          APF_Path_Planning_2023a_BlueI_B.b_lastv--;
          APF_Path_Planning_2023a_BlueI_B.lastc--;
        }

        APF_Path_Planning_2023a_BlueI_B.lastc = 6 -
          APF_Path_Planning_2023a_BlueI_B.b_kl;
        exitg2 = false;
        while ((!exitg2) && (APF_Path_Planning_2023a_BlueI_B.lastc > 0)) {
          APF_Path_Planning_2023a_BlueI_B.lastv =
            (APF_Path_Planning_2023a_BlueI_B.lastc - 1) * 6 +
            APF_Path_Planning_2023a_BlueI_B.in;
          APF_Path_Planning_2023a_BlueI_B.rowleft =
            APF_Path_Planning_2023a_BlueI_B.lastv;
          do {
            exitg1 = 0;
            if (APF_Path_Planning_2023a_BlueI_B.rowleft <=
                (APF_Path_Planning_2023a_BlueI_B.lastv +
                 APF_Path_Planning_2023a_BlueI_B.b_lastv) - 1) {
              if (a[APF_Path_Planning_2023a_BlueI_B.rowleft - 1] != 0.0) {
                exitg1 = 1;
              } else {
                APF_Path_Planning_2023a_BlueI_B.rowleft++;
              }
            } else {
              APF_Path_Planning_2023a_BlueI_B.lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        APF_Path_Planning_2023a_BlueI_B.b_lastv = 0;
        APF_Path_Planning_2023a_BlueI_B.lastc = 0;
      }

      if (APF_Path_Planning_2023a_BlueI_B.b_lastv > 0) {
        if (APF_Path_Planning_2023a_BlueI_B.lastc != 0) {
          APF_Path_Planning_2023a_BlueI_B.rowleft = static_cast<uint8_T>
            (APF_Path_Planning_2023a_BlueI_B.lastc);
          memset(&APF_Path_Planning_2023a_BlueI_B.work_j[0], 0,
                 static_cast<uint32_T>(APF_Path_Planning_2023a_BlueI_B.rowleft) *
                 sizeof(real_T));
          APF_Path_Planning_2023a_BlueI_B.b_ia =
            (APF_Path_Planning_2023a_BlueI_B.lastc - 1) * 6 +
            APF_Path_Planning_2023a_BlueI_B.in;
          for (APF_Path_Planning_2023a_BlueI_B.lastv =
               APF_Path_Planning_2023a_BlueI_B.in;
               APF_Path_Planning_2023a_BlueI_B.lastv <=
               APF_Path_Planning_2023a_BlueI_B.b_ia;
               APF_Path_Planning_2023a_BlueI_B.lastv += 6) {
            APF_Path_Planning_2023a_BlueI_B.temp_n = 0.0;
            APF_Path_Planning_2023a_BlueI_B.ia =
              (APF_Path_Planning_2023a_BlueI_B.lastv +
               APF_Path_Planning_2023a_BlueI_B.b_lastv) - 1;
            for (APF_Path_Planning_2023a_BlueI_B.rowleft =
                 APF_Path_Planning_2023a_BlueI_B.lastv;
                 APF_Path_Planning_2023a_BlueI_B.rowleft <=
                 APF_Path_Planning_2023a_BlueI_B.ia;
                 APF_Path_Planning_2023a_BlueI_B.rowleft++) {
              APF_Path_Planning_2023a_BlueI_B.temp_n += a
                [(APF_Path_Planning_2023a_BlueI_B.b_tmp +
                  APF_Path_Planning_2023a_BlueI_B.rowleft) -
                APF_Path_Planning_2023a_BlueI_B.lastv] *
                a[APF_Path_Planning_2023a_BlueI_B.rowleft - 1];
            }

            APF_Path_Planning_2023a_BlueI_B.rowleft = div_nde_s32_floor
              (APF_Path_Planning_2023a_BlueI_B.lastv -
               APF_Path_Planning_2023a_BlueI_B.in, 6);
            APF_Path_Planning_2023a_BlueI_B.work_j[APF_Path_Planning_2023a_BlueI_B.rowleft]
              += APF_Path_Planning_2023a_BlueI_B.temp_n;
          }
        }

        if (!(-APF_Path_Planning_2023a_BlueI_B.tau_m == 0.0)) {
          APF_Path_Planning_2023a_BlueI_B.rowleft = static_cast<uint8_T>
            (APF_Path_Planning_2023a_BlueI_B.lastc);
          for (APF_Path_Planning_2023a_BlueI_B.lastc = 0;
               APF_Path_Planning_2023a_BlueI_B.lastc <
               APF_Path_Planning_2023a_BlueI_B.rowleft;
               APF_Path_Planning_2023a_BlueI_B.lastc++) {
            APF_Path_Planning_2023a_BlueI_B.temp_n =
              APF_Path_Planning_2023a_BlueI_B.work_j[APF_Path_Planning_2023a_BlueI_B.lastc];
            if (APF_Path_Planning_2023a_BlueI_B.temp_n != 0.0) {
              APF_Path_Planning_2023a_BlueI_B.temp_n *=
                -APF_Path_Planning_2023a_BlueI_B.tau_m;
              APF_Path_Planning_2023a_BlueI_B.b_ia =
                APF_Path_Planning_2023a_BlueI_B.b_lastv +
                APF_Path_Planning_2023a_BlueI_B.in;
              for (APF_Path_Planning_2023a_BlueI_B.lastv =
                   APF_Path_Planning_2023a_BlueI_B.in;
                   APF_Path_Planning_2023a_BlueI_B.lastv <
                   APF_Path_Planning_2023a_BlueI_B.b_ia;
                   APF_Path_Planning_2023a_BlueI_B.lastv++) {
                a[APF_Path_Planning_2023a_BlueI_B.lastv - 1] += a
                  [(APF_Path_Planning_2023a_BlueI_B.b_tmp +
                    APF_Path_Planning_2023a_BlueI_B.lastv) -
                  APF_Path_Planning_2023a_BlueI_B.in] *
                  APF_Path_Planning_2023a_BlueI_B.temp_n;
              }
            }

            APF_Path_Planning_2023a_BlueI_B.in += 6;
          }
        }
      }

      a[APF_Path_Planning_2023a_BlueI_B.b_tmp] =
        APF_Path_Planning_2023a_BlueI_B.alpha1;
    }
  }
}

// Function for MATLAB Function: '<S356>/MATLAB Function'
static real_T APF_Path_Planning_2023_xnrm2_mw(int32_T n, const real_T x[3])
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[1]);
    } else {
      APF_Path_Planning_2023a_BlueI_B.scale_mv = 3.3121686421112381E-170;
      APF_Path_Planning_2023a_BlueI_B.absxk_mj = fabs(x[1]);
      if (APF_Path_Planning_2023a_BlueI_B.absxk_mj > 3.3121686421112381E-170) {
        y = 1.0;
        APF_Path_Planning_2023a_BlueI_B.scale_mv =
          APF_Path_Planning_2023a_BlueI_B.absxk_mj;
      } else {
        APF_Path_Planning_2023a_BlueI_B.t_c =
          APF_Path_Planning_2023a_BlueI_B.absxk_mj / 3.3121686421112381E-170;
        y = APF_Path_Planning_2023a_BlueI_B.t_c *
          APF_Path_Planning_2023a_BlueI_B.t_c;
      }

      APF_Path_Planning_2023a_BlueI_B.absxk_mj = fabs(x[2]);
      if (APF_Path_Planning_2023a_BlueI_B.absxk_mj >
          APF_Path_Planning_2023a_BlueI_B.scale_mv) {
        APF_Path_Planning_2023a_BlueI_B.t_c =
          APF_Path_Planning_2023a_BlueI_B.scale_mv /
          APF_Path_Planning_2023a_BlueI_B.absxk_mj;
        y = y * APF_Path_Planning_2023a_BlueI_B.t_c *
          APF_Path_Planning_2023a_BlueI_B.t_c + 1.0;
        APF_Path_Planning_2023a_BlueI_B.scale_mv =
          APF_Path_Planning_2023a_BlueI_B.absxk_mj;
      } else {
        APF_Path_Planning_2023a_BlueI_B.t_c =
          APF_Path_Planning_2023a_BlueI_B.absxk_mj /
          APF_Path_Planning_2023a_BlueI_B.scale_mv;
        y += APF_Path_Planning_2023a_BlueI_B.t_c *
          APF_Path_Planning_2023a_BlueI_B.t_c;
      }

      y = APF_Path_Planning_2023a_BlueI_B.scale_mv * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S356>/MATLAB Function'
static void APF_Path_Planning_2023a_xdlanv2(real_T *a, real_T *b, real_T *c,
  real_T *d, real_T *rt1r, real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs,
  real_T *sn)
{
  if (*c == 0.0) {
    *cs = 1.0;
    *sn = 0.0;
  } else if (*b == 0.0) {
    *cs = 0.0;
    *sn = 1.0;
    APF_Path_Planning_2023a_BlueI_B.temp = *d;
    *d = *a;
    *a = APF_Path_Planning_2023a_BlueI_B.temp;
    *b = -*c;
    *c = 0.0;
  } else {
    APF_Path_Planning_2023a_BlueI_B.temp = *a - *d;
    if ((APF_Path_Planning_2023a_BlueI_B.temp == 0.0) && ((*b < 0.0) != (*c <
          0.0))) {
      *cs = 1.0;
      *sn = 0.0;
    } else {
      APF_Path_Planning_2023a_BlueI_B.p = 0.5 *
        APF_Path_Planning_2023a_BlueI_B.temp;
      APF_Path_Planning_2023a_BlueI_B.scale_o = fabs(*b);
      APF_Path_Planning_2023a_BlueI_B.bcmis = fabs(*c);
      APF_Path_Planning_2023a_BlueI_B.b1 = rtIsNaN
        (APF_Path_Planning_2023a_BlueI_B.bcmis);
      if ((APF_Path_Planning_2023a_BlueI_B.scale_o >=
           APF_Path_Planning_2023a_BlueI_B.bcmis) ||
          APF_Path_Planning_2023a_BlueI_B.b1) {
        APF_Path_Planning_2023a_BlueI_B.bcmax =
          APF_Path_Planning_2023a_BlueI_B.scale_o;
      } else {
        APF_Path_Planning_2023a_BlueI_B.bcmax =
          APF_Path_Planning_2023a_BlueI_B.bcmis;
      }

      if ((APF_Path_Planning_2023a_BlueI_B.scale_o <=
           APF_Path_Planning_2023a_BlueI_B.bcmis) ||
          APF_Path_Planning_2023a_BlueI_B.b1) {
        APF_Path_Planning_2023a_BlueI_B.bcmis =
          APF_Path_Planning_2023a_BlueI_B.scale_o;
      }

      if (!(*b < 0.0)) {
        APF_Path_Planning_2023a_BlueI_B.count = 1;
      } else {
        APF_Path_Planning_2023a_BlueI_B.count = -1;
      }

      if (!(*c < 0.0)) {
        APF_Path_Planning_2023a_BlueI_B.i_h3 = 1;
      } else {
        APF_Path_Planning_2023a_BlueI_B.i_h3 = -1;
      }

      APF_Path_Planning_2023a_BlueI_B.bcmis =
        APF_Path_Planning_2023a_BlueI_B.bcmis * static_cast<real_T>
        (APF_Path_Planning_2023a_BlueI_B.count) * static_cast<real_T>
        (APF_Path_Planning_2023a_BlueI_B.i_h3);
      APF_Path_Planning_2023a_BlueI_B.scale_o = fabs
        (APF_Path_Planning_2023a_BlueI_B.p);
      if ((!(APF_Path_Planning_2023a_BlueI_B.scale_o >=
             APF_Path_Planning_2023a_BlueI_B.bcmax)) && (!rtIsNaN
           (APF_Path_Planning_2023a_BlueI_B.bcmax))) {
        APF_Path_Planning_2023a_BlueI_B.scale_o =
          APF_Path_Planning_2023a_BlueI_B.bcmax;
      }

      APF_Path_Planning_2023a_BlueI_B.z = APF_Path_Planning_2023a_BlueI_B.p /
        APF_Path_Planning_2023a_BlueI_B.scale_o *
        APF_Path_Planning_2023a_BlueI_B.p +
        APF_Path_Planning_2023a_BlueI_B.bcmax /
        APF_Path_Planning_2023a_BlueI_B.scale_o *
        APF_Path_Planning_2023a_BlueI_B.bcmis;
      if (APF_Path_Planning_2023a_BlueI_B.z >= 8.8817841970012523E-16) {
        if (!(APF_Path_Planning_2023a_BlueI_B.p < 0.0)) {
          APF_Path_Planning_2023a_BlueI_B.temp = sqrt
            (APF_Path_Planning_2023a_BlueI_B.scale_o) * sqrt
            (APF_Path_Planning_2023a_BlueI_B.z);
        } else {
          APF_Path_Planning_2023a_BlueI_B.temp = -(sqrt
            (APF_Path_Planning_2023a_BlueI_B.scale_o) * sqrt
            (APF_Path_Planning_2023a_BlueI_B.z));
        }

        APF_Path_Planning_2023a_BlueI_B.z = APF_Path_Planning_2023a_BlueI_B.p +
          APF_Path_Planning_2023a_BlueI_B.temp;
        *a = *d + APF_Path_Planning_2023a_BlueI_B.z;
        *d -= APF_Path_Planning_2023a_BlueI_B.bcmax /
          APF_Path_Planning_2023a_BlueI_B.z *
          APF_Path_Planning_2023a_BlueI_B.bcmis;
        APF_Path_Planning_2023a_BlueI_B.bcmax = APF_Path_Planning_rt_hypotd_snf(*
          c, APF_Path_Planning_2023a_BlueI_B.z);
        *cs = APF_Path_Planning_2023a_BlueI_B.z /
          APF_Path_Planning_2023a_BlueI_B.bcmax;
        *sn = *c / APF_Path_Planning_2023a_BlueI_B.bcmax;
        *b -= *c;
        *c = 0.0;
      } else {
        APF_Path_Planning_2023a_BlueI_B.p = *b + *c;
        APF_Path_Planning_2023a_BlueI_B.bcmax = fabs
          (APF_Path_Planning_2023a_BlueI_B.temp);
        APF_Path_Planning_2023a_BlueI_B.scale_o = fabs
          (APF_Path_Planning_2023a_BlueI_B.p);
        if ((APF_Path_Planning_2023a_BlueI_B.bcmax >=
             APF_Path_Planning_2023a_BlueI_B.scale_o) || rtIsNaN
            (APF_Path_Planning_2023a_BlueI_B.scale_o)) {
          APF_Path_Planning_2023a_BlueI_B.scale_o =
            APF_Path_Planning_2023a_BlueI_B.bcmax;
        }

        APF_Path_Planning_2023a_BlueI_B.count = 0;
        while ((APF_Path_Planning_2023a_BlueI_B.scale_o >=
                7.4428285367870146E+137) &&
               (APF_Path_Planning_2023a_BlueI_B.count <= 20)) {
          APF_Path_Planning_2023a_BlueI_B.p *= 1.3435752215134178E-138;
          APF_Path_Planning_2023a_BlueI_B.temp *= 1.3435752215134178E-138;
          APF_Path_Planning_2023a_BlueI_B.bcmax = fabs
            (APF_Path_Planning_2023a_BlueI_B.temp);
          APF_Path_Planning_2023a_BlueI_B.scale_o = fabs
            (APF_Path_Planning_2023a_BlueI_B.p);
          if ((APF_Path_Planning_2023a_BlueI_B.bcmax >=
               APF_Path_Planning_2023a_BlueI_B.scale_o) || rtIsNaN
              (APF_Path_Planning_2023a_BlueI_B.scale_o)) {
            APF_Path_Planning_2023a_BlueI_B.scale_o =
              APF_Path_Planning_2023a_BlueI_B.bcmax;
          }

          APF_Path_Planning_2023a_BlueI_B.count++;
        }

        while ((APF_Path_Planning_2023a_BlueI_B.scale_o <=
                1.3435752215134178E-138) &&
               (APF_Path_Planning_2023a_BlueI_B.count <= 20)) {
          APF_Path_Planning_2023a_BlueI_B.p *= 7.4428285367870146E+137;
          APF_Path_Planning_2023a_BlueI_B.temp *= 7.4428285367870146E+137;
          APF_Path_Planning_2023a_BlueI_B.bcmax = fabs
            (APF_Path_Planning_2023a_BlueI_B.temp);
          APF_Path_Planning_2023a_BlueI_B.scale_o = fabs
            (APF_Path_Planning_2023a_BlueI_B.p);
          if ((APF_Path_Planning_2023a_BlueI_B.bcmax >=
               APF_Path_Planning_2023a_BlueI_B.scale_o) || rtIsNaN
              (APF_Path_Planning_2023a_BlueI_B.scale_o)) {
            APF_Path_Planning_2023a_BlueI_B.scale_o =
              APF_Path_Planning_2023a_BlueI_B.bcmax;
          }

          APF_Path_Planning_2023a_BlueI_B.count++;
        }

        APF_Path_Planning_2023a_BlueI_B.bcmax = APF_Path_Planning_rt_hypotd_snf
          (APF_Path_Planning_2023a_BlueI_B.p,
           APF_Path_Planning_2023a_BlueI_B.temp);
        *cs = sqrt((fabs(APF_Path_Planning_2023a_BlueI_B.p) /
                    APF_Path_Planning_2023a_BlueI_B.bcmax + 1.0) * 0.5);
        if (!(APF_Path_Planning_2023a_BlueI_B.p < 0.0)) {
          APF_Path_Planning_2023a_BlueI_B.count = 1;
        } else {
          APF_Path_Planning_2023a_BlueI_B.count = -1;
        }

        *sn = -(0.5 * APF_Path_Planning_2023a_BlueI_B.temp /
                (APF_Path_Planning_2023a_BlueI_B.bcmax * *cs)) *
          static_cast<real_T>(APF_Path_Planning_2023a_BlueI_B.count);
        APF_Path_Planning_2023a_BlueI_B.temp = *a * *cs + *b * *sn;
        APF_Path_Planning_2023a_BlueI_B.p = -*a * *sn + *b * *cs;
        APF_Path_Planning_2023a_BlueI_B.bcmax = *c * *cs + *d * *sn;
        APF_Path_Planning_2023a_BlueI_B.scale_o = -*c * *sn + *d * *cs;
        *b = APF_Path_Planning_2023a_BlueI_B.p * *cs +
          APF_Path_Planning_2023a_BlueI_B.scale_o * *sn;
        *c = -APF_Path_Planning_2023a_BlueI_B.temp * *sn +
          APF_Path_Planning_2023a_BlueI_B.bcmax * *cs;
        APF_Path_Planning_2023a_BlueI_B.temp =
          ((APF_Path_Planning_2023a_BlueI_B.temp * *cs +
            APF_Path_Planning_2023a_BlueI_B.bcmax * *sn) +
           (-APF_Path_Planning_2023a_BlueI_B.p * *sn +
            APF_Path_Planning_2023a_BlueI_B.scale_o * *cs)) * 0.5;
        *a = APF_Path_Planning_2023a_BlueI_B.temp;
        *d = APF_Path_Planning_2023a_BlueI_B.temp;
        if (*c != 0.0) {
          if (*b != 0.0) {
            if ((*b < 0.0) == (*c < 0.0)) {
              APF_Path_Planning_2023a_BlueI_B.bcmis = sqrt(fabs(*b));
              APF_Path_Planning_2023a_BlueI_B.scale_o = sqrt(fabs(*c));
              if (!(*c < 0.0)) {
                APF_Path_Planning_2023a_BlueI_B.p =
                  APF_Path_Planning_2023a_BlueI_B.bcmis *
                  APF_Path_Planning_2023a_BlueI_B.scale_o;
              } else {
                APF_Path_Planning_2023a_BlueI_B.p =
                  -(APF_Path_Planning_2023a_BlueI_B.bcmis *
                    APF_Path_Planning_2023a_BlueI_B.scale_o);
              }

              APF_Path_Planning_2023a_BlueI_B.bcmax = 1.0 / sqrt(fabs(*b + *c));
              *a = APF_Path_Planning_2023a_BlueI_B.temp +
                APF_Path_Planning_2023a_BlueI_B.p;
              *d = APF_Path_Planning_2023a_BlueI_B.temp -
                APF_Path_Planning_2023a_BlueI_B.p;
              *b -= *c;
              *c = 0.0;
              APF_Path_Planning_2023a_BlueI_B.p =
                APF_Path_Planning_2023a_BlueI_B.bcmis *
                APF_Path_Planning_2023a_BlueI_B.bcmax;
              APF_Path_Planning_2023a_BlueI_B.bcmax *=
                APF_Path_Planning_2023a_BlueI_B.scale_o;
              APF_Path_Planning_2023a_BlueI_B.temp = *cs *
                APF_Path_Planning_2023a_BlueI_B.p - *sn *
                APF_Path_Planning_2023a_BlueI_B.bcmax;
              *sn = *cs * APF_Path_Planning_2023a_BlueI_B.bcmax + *sn *
                APF_Path_Planning_2023a_BlueI_B.p;
              *cs = APF_Path_Planning_2023a_BlueI_B.temp;
            }
          } else {
            *b = -*c;
            *c = 0.0;
            APF_Path_Planning_2023a_BlueI_B.temp = *cs;
            *cs = -*sn;
            *sn = APF_Path_Planning_2023a_BlueI_B.temp;
          }
        }
      }
    }
  }

  *rt1r = *a;
  *rt2r = *d;
  if (*c == 0.0) {
    *rt1i = 0.0;
    *rt2i = 0.0;
  } else {
    *rt1i = sqrt(fabs(*b)) * sqrt(fabs(*c));
    *rt2i = -*rt1i;
  }
}

// Function for MATLAB Function: '<S356>/MATLAB Function'
static void APF_Path_Planning_2023a_xdlahqr(int32_T ilo, int32_T ihi, real_T h
  [36], int32_T *info, real_T *z, real_T wr[6], real_T wi[6])
{
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  *z = 1.0;
  *info = 0;
  APF_Path_Planning_2023a_BlueI_B.l = static_cast<uint8_T>(ilo - 1);
  for (APF_Path_Planning_2023a_BlueI_B.b_i = 0;
       APF_Path_Planning_2023a_BlueI_B.b_i < APF_Path_Planning_2023a_BlueI_B.l;
       APF_Path_Planning_2023a_BlueI_B.b_i++) {
    wr[APF_Path_Planning_2023a_BlueI_B.b_i] = h[6 *
      APF_Path_Planning_2023a_BlueI_B.b_i + APF_Path_Planning_2023a_BlueI_B.b_i];
    wi[APF_Path_Planning_2023a_BlueI_B.b_i] = 0.0;
  }

  for (APF_Path_Planning_2023a_BlueI_B.b_i = ihi + 1;
       APF_Path_Planning_2023a_BlueI_B.b_i < 7;
       APF_Path_Planning_2023a_BlueI_B.b_i++) {
    wr[APF_Path_Planning_2023a_BlueI_B.b_i - 1] = h
      [((APF_Path_Planning_2023a_BlueI_B.b_i - 1) * 6 +
        APF_Path_Planning_2023a_BlueI_B.b_i) - 1];
    wi[APF_Path_Planning_2023a_BlueI_B.b_i - 1] = 0.0;
  }

  if (ilo == ihi) {
    wr[ilo - 1] = h[((ilo - 1) * 6 + ilo) - 1];
    wi[ilo - 1] = 0.0;
  } else {
    for (APF_Path_Planning_2023a_BlueI_B.b_i = ilo;
         APF_Path_Planning_2023a_BlueI_B.b_i <= ihi - 3;
         APF_Path_Planning_2023a_BlueI_B.b_i++) {
      APF_Path_Planning_2023a_BlueI_B.knt = (APF_Path_Planning_2023a_BlueI_B.b_i
        - 1) * 6 + APF_Path_Planning_2023a_BlueI_B.b_i;
      h[APF_Path_Planning_2023a_BlueI_B.knt + 1] = 0.0;
      h[APF_Path_Planning_2023a_BlueI_B.knt + 2] = 0.0;
    }

    if (ilo <= ihi - 2) {
      h[(ihi + 6 * (ihi - 3)) - 1] = 0.0;
    }

    APF_Path_Planning_2023a_BlueI_B.smlnum = static_cast<real_T>((ihi - ilo) + 1)
      / 2.2204460492503131E-16 * 2.2250738585072014E-308;
    APF_Path_Planning_2023a_BlueI_B.kdefl = 0;
    APF_Path_Planning_2023a_BlueI_B.b_i = ihi - 1;
    exitg1 = false;
    while ((!exitg1) && (APF_Path_Planning_2023a_BlueI_B.b_i + 1 >= ilo)) {
      APF_Path_Planning_2023a_BlueI_B.l = ilo;
      APF_Path_Planning_2023a_BlueI_B.converged = false;
      APF_Path_Planning_2023a_BlueI_B.its = 0;
      exitg2 = false;
      while ((!exitg2) && (APF_Path_Planning_2023a_BlueI_B.its < 301)) {
        APF_Path_Planning_2023a_BlueI_B.k_m =
          APF_Path_Planning_2023a_BlueI_B.b_i;
        exitg3 = false;
        while ((!exitg3) && (APF_Path_Planning_2023a_BlueI_B.k_m + 1 >
                             APF_Path_Planning_2023a_BlueI_B.l)) {
          APF_Path_Planning_2023a_BlueI_B.knt =
            (APF_Path_Planning_2023a_BlueI_B.k_m - 1) * 6 +
            APF_Path_Planning_2023a_BlueI_B.k_m;
          APF_Path_Planning_2023a_BlueI_B.h11 = fabs
            (h[APF_Path_Planning_2023a_BlueI_B.knt]);
          if (APF_Path_Planning_2023a_BlueI_B.h11 <=
              APF_Path_Planning_2023a_BlueI_B.smlnum) {
            exitg3 = true;
          } else {
            APF_Path_Planning_2023a_BlueI_B.b_m = 6 *
              APF_Path_Planning_2023a_BlueI_B.k_m +
              APF_Path_Planning_2023a_BlueI_B.k_m;
            APF_Path_Planning_2023a_BlueI_B.tr =
              h[APF_Path_Planning_2023a_BlueI_B.b_m];
            APF_Path_Planning_2023a_BlueI_B.s_j = fabs
              (APF_Path_Planning_2023a_BlueI_B.tr);
            APF_Path_Planning_2023a_BlueI_B.aa =
              h[APF_Path_Planning_2023a_BlueI_B.knt - 1];
            APF_Path_Planning_2023a_BlueI_B.tst = fabs
              (APF_Path_Planning_2023a_BlueI_B.aa) +
              APF_Path_Planning_2023a_BlueI_B.s_j;
            if (APF_Path_Planning_2023a_BlueI_B.tst == 0.0) {
              if (APF_Path_Planning_2023a_BlueI_B.k_m - 1 >= ilo) {
                APF_Path_Planning_2023a_BlueI_B.tst = fabs(h
                  [((APF_Path_Planning_2023a_BlueI_B.k_m - 2) * 6 +
                    APF_Path_Planning_2023a_BlueI_B.k_m) - 1]);
              }

              if (APF_Path_Planning_2023a_BlueI_B.k_m + 2 <= ihi) {
                APF_Path_Planning_2023a_BlueI_B.tst += fabs
                  (h[APF_Path_Planning_2023a_BlueI_B.b_m + 1]);
              }
            }

            if (APF_Path_Planning_2023a_BlueI_B.h11 <= 2.2204460492503131E-16 *
                APF_Path_Planning_2023a_BlueI_B.tst) {
              APF_Path_Planning_2023a_BlueI_B.tst = fabs
                (APF_Path_Planning_2023a_BlueI_B.aa -
                 APF_Path_Planning_2023a_BlueI_B.tr);
              APF_Path_Planning_2023a_BlueI_B.b_o = rtIsNaN
                (APF_Path_Planning_2023a_BlueI_B.tst);
              if ((APF_Path_Planning_2023a_BlueI_B.s_j >=
                   APF_Path_Planning_2023a_BlueI_B.tst) ||
                  APF_Path_Planning_2023a_BlueI_B.b_o) {
                APF_Path_Planning_2023a_BlueI_B.aa =
                  APF_Path_Planning_2023a_BlueI_B.s_j;
              } else {
                APF_Path_Planning_2023a_BlueI_B.aa =
                  APF_Path_Planning_2023a_BlueI_B.tst;
              }

              if ((APF_Path_Planning_2023a_BlueI_B.s_j <=
                   APF_Path_Planning_2023a_BlueI_B.tst) ||
                  APF_Path_Planning_2023a_BlueI_B.b_o) {
                APF_Path_Planning_2023a_BlueI_B.tst =
                  APF_Path_Planning_2023a_BlueI_B.s_j;
              }

              APF_Path_Planning_2023a_BlueI_B.s_j =
                APF_Path_Planning_2023a_BlueI_B.aa +
                APF_Path_Planning_2023a_BlueI_B.tst;
              APF_Path_Planning_2023a_BlueI_B.tr = fabs
                (h[APF_Path_Planning_2023a_BlueI_B.b_m - 1]);
              APF_Path_Planning_2023a_BlueI_B.aa =
                APF_Path_Planning_2023a_BlueI_B.aa /
                APF_Path_Planning_2023a_BlueI_B.s_j *
                APF_Path_Planning_2023a_BlueI_B.tst * 2.2204460492503131E-16;
              APF_Path_Planning_2023a_BlueI_B.b_o = rtIsNaN
                (APF_Path_Planning_2023a_BlueI_B.tr);
              if ((APF_Path_Planning_2023a_BlueI_B.h11 <=
                   APF_Path_Planning_2023a_BlueI_B.tr) ||
                  APF_Path_Planning_2023a_BlueI_B.b_o) {
                APF_Path_Planning_2023a_BlueI_B.tst =
                  APF_Path_Planning_2023a_BlueI_B.h11;
              } else {
                APF_Path_Planning_2023a_BlueI_B.tst =
                  APF_Path_Planning_2023a_BlueI_B.tr;
              }

              if ((APF_Path_Planning_2023a_BlueI_B.h11 >=
                   APF_Path_Planning_2023a_BlueI_B.tr) ||
                  APF_Path_Planning_2023a_BlueI_B.b_o) {
                APF_Path_Planning_2023a_BlueI_B.tr =
                  APF_Path_Planning_2023a_BlueI_B.h11;
              }

              if ((APF_Path_Planning_2023a_BlueI_B.smlnum >=
                   APF_Path_Planning_2023a_BlueI_B.aa) || rtIsNaN
                  (APF_Path_Planning_2023a_BlueI_B.aa)) {
                APF_Path_Planning_2023a_BlueI_B.aa =
                  APF_Path_Planning_2023a_BlueI_B.smlnum;
              }

              if (APF_Path_Planning_2023a_BlueI_B.tr /
                  APF_Path_Planning_2023a_BlueI_B.s_j *
                  APF_Path_Planning_2023a_BlueI_B.tst <=
                  APF_Path_Planning_2023a_BlueI_B.aa) {
                exitg3 = true;
              } else {
                APF_Path_Planning_2023a_BlueI_B.k_m--;
              }
            } else {
              APF_Path_Planning_2023a_BlueI_B.k_m--;
            }
          }
        }

        APF_Path_Planning_2023a_BlueI_B.l = APF_Path_Planning_2023a_BlueI_B.k_m
          + 1;
        if (APF_Path_Planning_2023a_BlueI_B.k_m + 1 > ilo) {
          h[APF_Path_Planning_2023a_BlueI_B.k_m + 6 *
            (APF_Path_Planning_2023a_BlueI_B.k_m - 1)] = 0.0;
        }

        if (APF_Path_Planning_2023a_BlueI_B.k_m + 1 >=
            APF_Path_Planning_2023a_BlueI_B.b_i) {
          APF_Path_Planning_2023a_BlueI_B.converged = true;
          exitg2 = true;
        } else {
          APF_Path_Planning_2023a_BlueI_B.kdefl++;
          if (APF_Path_Planning_2023a_BlueI_B.kdefl -
              APF_Path_Planning_2023a_BlueI_B.kdefl / 20 * 20 == 0) {
            APF_Path_Planning_2023a_BlueI_B.s_j = fabs(h
              [((APF_Path_Planning_2023a_BlueI_B.b_i - 2) * 6 +
                APF_Path_Planning_2023a_BlueI_B.b_i) - 1]) + fabs(h
              [(APF_Path_Planning_2023a_BlueI_B.b_i - 1) * 6 +
              APF_Path_Planning_2023a_BlueI_B.b_i]);
            APF_Path_Planning_2023a_BlueI_B.h11 = h[6 *
              APF_Path_Planning_2023a_BlueI_B.b_i +
              APF_Path_Planning_2023a_BlueI_B.b_i] + 0.75 *
              APF_Path_Planning_2023a_BlueI_B.s_j;
            APF_Path_Planning_2023a_BlueI_B.h12 = -0.4375 *
              APF_Path_Planning_2023a_BlueI_B.s_j;
            APF_Path_Planning_2023a_BlueI_B.tst =
              APF_Path_Planning_2023a_BlueI_B.s_j;
            APF_Path_Planning_2023a_BlueI_B.aa =
              APF_Path_Planning_2023a_BlueI_B.h11;
          } else if (APF_Path_Planning_2023a_BlueI_B.kdefl -
                     APF_Path_Planning_2023a_BlueI_B.kdefl / 10 * 10 == 0) {
            APF_Path_Planning_2023a_BlueI_B.s_tmp_m = 6 *
              APF_Path_Planning_2023a_BlueI_B.k_m +
              APF_Path_Planning_2023a_BlueI_B.k_m;
            APF_Path_Planning_2023a_BlueI_B.s_j = fabs(h
              [((APF_Path_Planning_2023a_BlueI_B.k_m + 1) * 6 +
                APF_Path_Planning_2023a_BlueI_B.k_m) + 2]) + fabs
              (h[APF_Path_Planning_2023a_BlueI_B.s_tmp_m + 1]);
            APF_Path_Planning_2023a_BlueI_B.h11 = 0.75 *
              APF_Path_Planning_2023a_BlueI_B.s_j +
              h[APF_Path_Planning_2023a_BlueI_B.s_tmp_m];
            APF_Path_Planning_2023a_BlueI_B.h12 = -0.4375 *
              APF_Path_Planning_2023a_BlueI_B.s_j;
            APF_Path_Planning_2023a_BlueI_B.tst =
              APF_Path_Planning_2023a_BlueI_B.s_j;
            APF_Path_Planning_2023a_BlueI_B.aa =
              APF_Path_Planning_2023a_BlueI_B.h11;
          } else {
            APF_Path_Planning_2023a_BlueI_B.b_m =
              (APF_Path_Planning_2023a_BlueI_B.b_i - 1) * 6 +
              APF_Path_Planning_2023a_BlueI_B.b_i;
            APF_Path_Planning_2023a_BlueI_B.h11 =
              h[APF_Path_Planning_2023a_BlueI_B.b_m - 1];
            APF_Path_Planning_2023a_BlueI_B.tst =
              h[APF_Path_Planning_2023a_BlueI_B.b_m];
            APF_Path_Planning_2023a_BlueI_B.b_m = 6 *
              APF_Path_Planning_2023a_BlueI_B.b_i +
              APF_Path_Planning_2023a_BlueI_B.b_i;
            APF_Path_Planning_2023a_BlueI_B.h12 =
              h[APF_Path_Planning_2023a_BlueI_B.b_m - 1];
            APF_Path_Planning_2023a_BlueI_B.aa =
              h[APF_Path_Planning_2023a_BlueI_B.b_m];
          }

          APF_Path_Planning_2023a_BlueI_B.s_j = ((fabs
            (APF_Path_Planning_2023a_BlueI_B.h11) + fabs
            (APF_Path_Planning_2023a_BlueI_B.h12)) + fabs
            (APF_Path_Planning_2023a_BlueI_B.tst)) + fabs
            (APF_Path_Planning_2023a_BlueI_B.aa);
          if (APF_Path_Planning_2023a_BlueI_B.s_j == 0.0) {
            APF_Path_Planning_2023a_BlueI_B.h11 = 0.0;
            APF_Path_Planning_2023a_BlueI_B.aa = 0.0;
            APF_Path_Planning_2023a_BlueI_B.tr = 0.0;
            APF_Path_Planning_2023a_BlueI_B.tst = 0.0;
          } else {
            APF_Path_Planning_2023a_BlueI_B.h11 /=
              APF_Path_Planning_2023a_BlueI_B.s_j;
            APF_Path_Planning_2023a_BlueI_B.aa /=
              APF_Path_Planning_2023a_BlueI_B.s_j;
            APF_Path_Planning_2023a_BlueI_B.tr =
              (APF_Path_Planning_2023a_BlueI_B.h11 +
               APF_Path_Planning_2023a_BlueI_B.aa) / 2.0;
            APF_Path_Planning_2023a_BlueI_B.h11 =
              (APF_Path_Planning_2023a_BlueI_B.h11 -
               APF_Path_Planning_2023a_BlueI_B.tr) *
              (APF_Path_Planning_2023a_BlueI_B.aa -
               APF_Path_Planning_2023a_BlueI_B.tr) -
              APF_Path_Planning_2023a_BlueI_B.h12 /
              APF_Path_Planning_2023a_BlueI_B.s_j *
              (APF_Path_Planning_2023a_BlueI_B.tst /
               APF_Path_Planning_2023a_BlueI_B.s_j);
            APF_Path_Planning_2023a_BlueI_B.tst = sqrt(fabs
              (APF_Path_Planning_2023a_BlueI_B.h11));
            if (APF_Path_Planning_2023a_BlueI_B.h11 >= 0.0) {
              APF_Path_Planning_2023a_BlueI_B.h11 =
                APF_Path_Planning_2023a_BlueI_B.tr *
                APF_Path_Planning_2023a_BlueI_B.s_j;
              APF_Path_Planning_2023a_BlueI_B.tr =
                APF_Path_Planning_2023a_BlueI_B.h11;
              APF_Path_Planning_2023a_BlueI_B.aa =
                APF_Path_Planning_2023a_BlueI_B.tst *
                APF_Path_Planning_2023a_BlueI_B.s_j;
              APF_Path_Planning_2023a_BlueI_B.tst =
                -APF_Path_Planning_2023a_BlueI_B.aa;
            } else {
              APF_Path_Planning_2023a_BlueI_B.h11 =
                APF_Path_Planning_2023a_BlueI_B.tr +
                APF_Path_Planning_2023a_BlueI_B.tst;
              APF_Path_Planning_2023a_BlueI_B.tr -=
                APF_Path_Planning_2023a_BlueI_B.tst;
              if (fabs(APF_Path_Planning_2023a_BlueI_B.h11 -
                       APF_Path_Planning_2023a_BlueI_B.aa) <= fabs
                  (APF_Path_Planning_2023a_BlueI_B.tr -
                   APF_Path_Planning_2023a_BlueI_B.aa)) {
                APF_Path_Planning_2023a_BlueI_B.h11 *=
                  APF_Path_Planning_2023a_BlueI_B.s_j;
                APF_Path_Planning_2023a_BlueI_B.tr =
                  APF_Path_Planning_2023a_BlueI_B.h11;
              } else {
                APF_Path_Planning_2023a_BlueI_B.tr *=
                  APF_Path_Planning_2023a_BlueI_B.s_j;
                APF_Path_Planning_2023a_BlueI_B.h11 =
                  APF_Path_Planning_2023a_BlueI_B.tr;
              }

              APF_Path_Planning_2023a_BlueI_B.aa = 0.0;
              APF_Path_Planning_2023a_BlueI_B.tst = 0.0;
            }
          }

          APF_Path_Planning_2023a_BlueI_B.b_m =
            APF_Path_Planning_2023a_BlueI_B.b_i - 1;
          exitg3 = false;
          while ((!exitg3) && (APF_Path_Planning_2023a_BlueI_B.b_m >=
                               APF_Path_Planning_2023a_BlueI_B.k_m + 1)) {
            APF_Path_Planning_2023a_BlueI_B.s_tmp_m =
              (APF_Path_Planning_2023a_BlueI_B.b_m - 1) * 6 +
              APF_Path_Planning_2023a_BlueI_B.b_m;
            APF_Path_Planning_2023a_BlueI_B.h21s =
              h[APF_Path_Planning_2023a_BlueI_B.s_tmp_m];
            APF_Path_Planning_2023a_BlueI_B.h12 =
              h[APF_Path_Planning_2023a_BlueI_B.s_tmp_m - 1];
            APF_Path_Planning_2023a_BlueI_B.s_tmp =
              APF_Path_Planning_2023a_BlueI_B.h12 -
              APF_Path_Planning_2023a_BlueI_B.tr;
            APF_Path_Planning_2023a_BlueI_B.s_j = (fabs
              (APF_Path_Planning_2023a_BlueI_B.s_tmp) + fabs
              (APF_Path_Planning_2023a_BlueI_B.tst)) + fabs
              (APF_Path_Planning_2023a_BlueI_B.h21s);
            APF_Path_Planning_2023a_BlueI_B.h21s /=
              APF_Path_Planning_2023a_BlueI_B.s_j;
            APF_Path_Planning_2023a_BlueI_B.s_tmp_m = 6 *
              APF_Path_Planning_2023a_BlueI_B.b_m +
              APF_Path_Planning_2023a_BlueI_B.b_m;
            APF_Path_Planning_2023a_BlueI_B.v_dy[0] =
              (APF_Path_Planning_2023a_BlueI_B.s_tmp /
               APF_Path_Planning_2023a_BlueI_B.s_j *
               APF_Path_Planning_2023a_BlueI_B.s_tmp +
               h[APF_Path_Planning_2023a_BlueI_B.s_tmp_m - 1] *
               APF_Path_Planning_2023a_BlueI_B.h21s) -
              APF_Path_Planning_2023a_BlueI_B.tst /
              APF_Path_Planning_2023a_BlueI_B.s_j *
              APF_Path_Planning_2023a_BlueI_B.aa;
            APF_Path_Planning_2023a_BlueI_B.s_tmp =
              h[APF_Path_Planning_2023a_BlueI_B.s_tmp_m];
            APF_Path_Planning_2023a_BlueI_B.v_dy[1] =
              (((APF_Path_Planning_2023a_BlueI_B.h12 +
                 APF_Path_Planning_2023a_BlueI_B.s_tmp) -
                APF_Path_Planning_2023a_BlueI_B.h11) -
               APF_Path_Planning_2023a_BlueI_B.tr) *
              APF_Path_Planning_2023a_BlueI_B.h21s;
            APF_Path_Planning_2023a_BlueI_B.v_dy[2] =
              h[APF_Path_Planning_2023a_BlueI_B.s_tmp_m + 1] *
              APF_Path_Planning_2023a_BlueI_B.h21s;
            APF_Path_Planning_2023a_BlueI_B.s_j = (fabs
              (APF_Path_Planning_2023a_BlueI_B.v_dy[0]) + fabs
              (APF_Path_Planning_2023a_BlueI_B.v_dy[1])) + fabs
              (APF_Path_Planning_2023a_BlueI_B.v_dy[2]);
            APF_Path_Planning_2023a_BlueI_B.v_dy[0] /=
              APF_Path_Planning_2023a_BlueI_B.s_j;
            APF_Path_Planning_2023a_BlueI_B.v_dy[1] /=
              APF_Path_Planning_2023a_BlueI_B.s_j;
            APF_Path_Planning_2023a_BlueI_B.v_dy[2] /=
              APF_Path_Planning_2023a_BlueI_B.s_j;
            if (APF_Path_Planning_2023a_BlueI_B.k_m + 1 ==
                APF_Path_Planning_2023a_BlueI_B.b_m) {
              exitg3 = true;
            } else {
              APF_Path_Planning_2023a_BlueI_B.knt =
                (APF_Path_Planning_2023a_BlueI_B.b_m - 2) * 6 +
                APF_Path_Planning_2023a_BlueI_B.b_m;
              if (fabs(h[APF_Path_Planning_2023a_BlueI_B.knt - 1]) * (fabs
                   (APF_Path_Planning_2023a_BlueI_B.v_dy[1]) + fabs
                   (APF_Path_Planning_2023a_BlueI_B.v_dy[2])) <= ((fabs
                    (h[APF_Path_Planning_2023a_BlueI_B.knt - 2]) + fabs
                    (APF_Path_Planning_2023a_BlueI_B.h12)) + fabs
                   (APF_Path_Planning_2023a_BlueI_B.s_tmp)) *
                  (2.2204460492503131E-16 * fabs
                   (APF_Path_Planning_2023a_BlueI_B.v_dy[0]))) {
                exitg3 = true;
              } else {
                APF_Path_Planning_2023a_BlueI_B.b_m--;
              }
            }
          }

          for (APF_Path_Planning_2023a_BlueI_B.s_tmp_m =
               APF_Path_Planning_2023a_BlueI_B.b_m;
               APF_Path_Planning_2023a_BlueI_B.s_tmp_m <=
               APF_Path_Planning_2023a_BlueI_B.b_i;
               APF_Path_Planning_2023a_BlueI_B.s_tmp_m++) {
            APF_Path_Planning_2023a_BlueI_B.nr =
              (APF_Path_Planning_2023a_BlueI_B.b_i -
               APF_Path_Planning_2023a_BlueI_B.s_tmp_m) + 2;
            if (APF_Path_Planning_2023a_BlueI_B.nr >= 3) {
              APF_Path_Planning_2023a_BlueI_B.nr = 3;
            }

            if (APF_Path_Planning_2023a_BlueI_B.s_tmp_m >
                APF_Path_Planning_2023a_BlueI_B.b_m) {
              APF_Path_Planning_2023a_BlueI_B.ix0 =
                ((APF_Path_Planning_2023a_BlueI_B.s_tmp_m - 2) * 6 +
                 APF_Path_Planning_2023a_BlueI_B.s_tmp_m) - 1;
              for (APF_Path_Planning_2023a_BlueI_B.knt = 0;
                   APF_Path_Planning_2023a_BlueI_B.knt <
                   APF_Path_Planning_2023a_BlueI_B.nr;
                   APF_Path_Planning_2023a_BlueI_B.knt++) {
                APF_Path_Planning_2023a_BlueI_B.v_dy[APF_Path_Planning_2023a_BlueI_B.knt]
                  = h[APF_Path_Planning_2023a_BlueI_B.ix0 +
                  APF_Path_Planning_2023a_BlueI_B.knt];
              }
            }

            APF_Path_Planning_2023a_BlueI_B.tr =
              APF_Path_Planning_2023a_BlueI_B.v_dy[0];
            APF_Path_Planning_2023a_BlueI_B.s_j = 0.0;
            if (APF_Path_Planning_2023a_BlueI_B.nr > 0) {
              APF_Path_Planning_2023a_BlueI_B.h11 =
                APF_Path_Planning_2023_xnrm2_mw
                (APF_Path_Planning_2023a_BlueI_B.nr - 1,
                 APF_Path_Planning_2023a_BlueI_B.v_dy);
              if (APF_Path_Planning_2023a_BlueI_B.h11 != 0.0) {
                APF_Path_Planning_2023a_BlueI_B.h11 =
                  APF_Path_Planning_rt_hypotd_snf
                  (APF_Path_Planning_2023a_BlueI_B.v_dy[0],
                   APF_Path_Planning_2023a_BlueI_B.h11);
                if (APF_Path_Planning_2023a_BlueI_B.v_dy[0] >= 0.0) {
                  APF_Path_Planning_2023a_BlueI_B.h11 =
                    -APF_Path_Planning_2023a_BlueI_B.h11;
                }

                if (fabs(APF_Path_Planning_2023a_BlueI_B.h11) <
                    1.0020841800044864E-292) {
                  APF_Path_Planning_2023a_BlueI_B.knt = 0;
                  do {
                    APF_Path_Planning_2023a_BlueI_B.knt++;
                    for (APF_Path_Planning_2023a_BlueI_B.ix0 = 2;
                         APF_Path_Planning_2023a_BlueI_B.ix0 <=
                         APF_Path_Planning_2023a_BlueI_B.nr;
                         APF_Path_Planning_2023a_BlueI_B.ix0++) {
                      APF_Path_Planning_2023a_BlueI_B.v_dy[APF_Path_Planning_2023a_BlueI_B.ix0
                        - 1] *= 9.9792015476736E+291;
                    }

                    APF_Path_Planning_2023a_BlueI_B.h11 *= 9.9792015476736E+291;
                    APF_Path_Planning_2023a_BlueI_B.tr *= 9.9792015476736E+291;
                  } while ((fabs(APF_Path_Planning_2023a_BlueI_B.h11) <
                            1.0020841800044864E-292) &&
                           (APF_Path_Planning_2023a_BlueI_B.knt < 20));

                  APF_Path_Planning_2023a_BlueI_B.h11 =
                    APF_Path_Planning_rt_hypotd_snf
                    (APF_Path_Planning_2023a_BlueI_B.tr,
                     APF_Path_Planning_2023_xnrm2_mw
                     (APF_Path_Planning_2023a_BlueI_B.nr - 1,
                      APF_Path_Planning_2023a_BlueI_B.v_dy));
                  if (APF_Path_Planning_2023a_BlueI_B.tr >= 0.0) {
                    APF_Path_Planning_2023a_BlueI_B.h11 =
                      -APF_Path_Planning_2023a_BlueI_B.h11;
                  }

                  APF_Path_Planning_2023a_BlueI_B.s_j =
                    (APF_Path_Planning_2023a_BlueI_B.h11 -
                     APF_Path_Planning_2023a_BlueI_B.tr) /
                    APF_Path_Planning_2023a_BlueI_B.h11;
                  APF_Path_Planning_2023a_BlueI_B.tr = 1.0 /
                    (APF_Path_Planning_2023a_BlueI_B.tr -
                     APF_Path_Planning_2023a_BlueI_B.h11);
                  for (APF_Path_Planning_2023a_BlueI_B.ix0 = 2;
                       APF_Path_Planning_2023a_BlueI_B.ix0 <=
                       APF_Path_Planning_2023a_BlueI_B.nr;
                       APF_Path_Planning_2023a_BlueI_B.ix0++) {
                    APF_Path_Planning_2023a_BlueI_B.v_dy[APF_Path_Planning_2023a_BlueI_B.ix0
                      - 1] *= APF_Path_Planning_2023a_BlueI_B.tr;
                  }

                  for (APF_Path_Planning_2023a_BlueI_B.ix0 = 0;
                       APF_Path_Planning_2023a_BlueI_B.ix0 <
                       APF_Path_Planning_2023a_BlueI_B.knt;
                       APF_Path_Planning_2023a_BlueI_B.ix0++) {
                    APF_Path_Planning_2023a_BlueI_B.h11 *=
                      1.0020841800044864E-292;
                  }

                  APF_Path_Planning_2023a_BlueI_B.tr =
                    APF_Path_Planning_2023a_BlueI_B.h11;
                } else {
                  APF_Path_Planning_2023a_BlueI_B.s_j =
                    (APF_Path_Planning_2023a_BlueI_B.h11 -
                     APF_Path_Planning_2023a_BlueI_B.v_dy[0]) /
                    APF_Path_Planning_2023a_BlueI_B.h11;
                  APF_Path_Planning_2023a_BlueI_B.tr = 1.0 /
                    (APF_Path_Planning_2023a_BlueI_B.v_dy[0] -
                     APF_Path_Planning_2023a_BlueI_B.h11);
                  for (APF_Path_Planning_2023a_BlueI_B.knt = 2;
                       APF_Path_Planning_2023a_BlueI_B.knt <=
                       APF_Path_Planning_2023a_BlueI_B.nr;
                       APF_Path_Planning_2023a_BlueI_B.knt++) {
                    APF_Path_Planning_2023a_BlueI_B.v_dy[APF_Path_Planning_2023a_BlueI_B.knt
                      - 1] *= APF_Path_Planning_2023a_BlueI_B.tr;
                  }

                  APF_Path_Planning_2023a_BlueI_B.tr =
                    APF_Path_Planning_2023a_BlueI_B.h11;
                }
              }
            }

            if (APF_Path_Planning_2023a_BlueI_B.s_tmp_m >
                APF_Path_Planning_2023a_BlueI_B.b_m) {
              APF_Path_Planning_2023a_BlueI_B.knt =
                (APF_Path_Planning_2023a_BlueI_B.s_tmp_m - 2) * 6 +
                APF_Path_Planning_2023a_BlueI_B.s_tmp_m;
              h[APF_Path_Planning_2023a_BlueI_B.knt - 1] =
                APF_Path_Planning_2023a_BlueI_B.tr;
              h[APF_Path_Planning_2023a_BlueI_B.knt] = 0.0;
              if (APF_Path_Planning_2023a_BlueI_B.s_tmp_m <
                  APF_Path_Planning_2023a_BlueI_B.b_i) {
                h[APF_Path_Planning_2023a_BlueI_B.knt + 1] = 0.0;
              }
            } else if (APF_Path_Planning_2023a_BlueI_B.b_m >
                       APF_Path_Planning_2023a_BlueI_B.k_m + 1) {
              APF_Path_Planning_2023a_BlueI_B.knt =
                ((APF_Path_Planning_2023a_BlueI_B.s_tmp_m - 2) * 6 +
                 APF_Path_Planning_2023a_BlueI_B.s_tmp_m) - 1;
              h[APF_Path_Planning_2023a_BlueI_B.knt] *= 1.0 -
                APF_Path_Planning_2023a_BlueI_B.s_j;
            }

            APF_Path_Planning_2023a_BlueI_B.h11 =
              APF_Path_Planning_2023a_BlueI_B.v_dy[1];
            APF_Path_Planning_2023a_BlueI_B.tr =
              APF_Path_Planning_2023a_BlueI_B.s_j *
              APF_Path_Planning_2023a_BlueI_B.v_dy[1];
            switch (APF_Path_Planning_2023a_BlueI_B.nr) {
             case 3:
              APF_Path_Planning_2023a_BlueI_B.aa =
                APF_Path_Planning_2023a_BlueI_B.v_dy[2];
              APF_Path_Planning_2023a_BlueI_B.tst =
                APF_Path_Planning_2023a_BlueI_B.s_j *
                APF_Path_Planning_2023a_BlueI_B.v_dy[2];
              for (APF_Path_Planning_2023a_BlueI_B.knt =
                   APF_Path_Planning_2023a_BlueI_B.s_tmp_m;
                   APF_Path_Planning_2023a_BlueI_B.knt <=
                   APF_Path_Planning_2023a_BlueI_B.b_i + 1;
                   APF_Path_Planning_2023a_BlueI_B.knt++) {
                APF_Path_Planning_2023a_BlueI_B.nr =
                  (APF_Path_Planning_2023a_BlueI_B.knt - 1) * 6 +
                  APF_Path_Planning_2023a_BlueI_B.s_tmp_m;
                APF_Path_Planning_2023a_BlueI_B.h12 =
                  h[APF_Path_Planning_2023a_BlueI_B.nr - 1];
                APF_Path_Planning_2023a_BlueI_B.s_tmp =
                  h[APF_Path_Planning_2023a_BlueI_B.nr];
                APF_Path_Planning_2023a_BlueI_B.h21s =
                  h[APF_Path_Planning_2023a_BlueI_B.nr + 1];
                APF_Path_Planning_2023a_BlueI_B.sum =
                  (APF_Path_Planning_2023a_BlueI_B.h11 *
                   APF_Path_Planning_2023a_BlueI_B.s_tmp +
                   APF_Path_Planning_2023a_BlueI_B.h12) +
                  APF_Path_Planning_2023a_BlueI_B.aa *
                  APF_Path_Planning_2023a_BlueI_B.h21s;
                h[APF_Path_Planning_2023a_BlueI_B.nr - 1] =
                  APF_Path_Planning_2023a_BlueI_B.h12 -
                  APF_Path_Planning_2023a_BlueI_B.sum *
                  APF_Path_Planning_2023a_BlueI_B.s_j;
                h[APF_Path_Planning_2023a_BlueI_B.nr] =
                  APF_Path_Planning_2023a_BlueI_B.s_tmp -
                  APF_Path_Planning_2023a_BlueI_B.sum *
                  APF_Path_Planning_2023a_BlueI_B.tr;
                h[APF_Path_Planning_2023a_BlueI_B.nr + 1] =
                  APF_Path_Planning_2023a_BlueI_B.h21s -
                  APF_Path_Planning_2023a_BlueI_B.sum *
                  APF_Path_Planning_2023a_BlueI_B.tst;
              }

              if (APF_Path_Planning_2023a_BlueI_B.s_tmp_m + 3 <=
                  APF_Path_Planning_2023a_BlueI_B.b_i + 1) {
                APF_Path_Planning_2023a_BlueI_B.n =
                  APF_Path_Planning_2023a_BlueI_B.s_tmp_m + 3;
              } else {
                APF_Path_Planning_2023a_BlueI_B.n =
                  APF_Path_Planning_2023a_BlueI_B.b_i + 1;
              }

              for (APF_Path_Planning_2023a_BlueI_B.knt =
                   APF_Path_Planning_2023a_BlueI_B.k_m + 1;
                   APF_Path_Planning_2023a_BlueI_B.knt <=
                   APF_Path_Planning_2023a_BlueI_B.n;
                   APF_Path_Planning_2023a_BlueI_B.knt++) {
                APF_Path_Planning_2023a_BlueI_B.nr =
                  ((APF_Path_Planning_2023a_BlueI_B.s_tmp_m - 1) * 6 +
                   APF_Path_Planning_2023a_BlueI_B.knt) - 1;
                APF_Path_Planning_2023a_BlueI_B.h12 =
                  h[APF_Path_Planning_2023a_BlueI_B.nr];
                APF_Path_Planning_2023a_BlueI_B.ix0 = (6 *
                  APF_Path_Planning_2023a_BlueI_B.s_tmp_m +
                  APF_Path_Planning_2023a_BlueI_B.knt) - 1;
                APF_Path_Planning_2023a_BlueI_B.s_tmp =
                  h[APF_Path_Planning_2023a_BlueI_B.ix0];
                APF_Path_Planning_2023a_BlueI_B.h_tmp =
                  ((APF_Path_Planning_2023a_BlueI_B.s_tmp_m + 1) * 6 +
                   APF_Path_Planning_2023a_BlueI_B.knt) - 1;
                APF_Path_Planning_2023a_BlueI_B.h21s =
                  h[APF_Path_Planning_2023a_BlueI_B.h_tmp];
                APF_Path_Planning_2023a_BlueI_B.sum =
                  (APF_Path_Planning_2023a_BlueI_B.h11 *
                   APF_Path_Planning_2023a_BlueI_B.s_tmp +
                   APF_Path_Planning_2023a_BlueI_B.h12) +
                  APF_Path_Planning_2023a_BlueI_B.aa *
                  APF_Path_Planning_2023a_BlueI_B.h21s;
                h[APF_Path_Planning_2023a_BlueI_B.nr] =
                  APF_Path_Planning_2023a_BlueI_B.h12 -
                  APF_Path_Planning_2023a_BlueI_B.sum *
                  APF_Path_Planning_2023a_BlueI_B.s_j;
                h[APF_Path_Planning_2023a_BlueI_B.ix0] =
                  APF_Path_Planning_2023a_BlueI_B.s_tmp -
                  APF_Path_Planning_2023a_BlueI_B.sum *
                  APF_Path_Planning_2023a_BlueI_B.tr;
                h[APF_Path_Planning_2023a_BlueI_B.h_tmp] =
                  APF_Path_Planning_2023a_BlueI_B.h21s -
                  APF_Path_Planning_2023a_BlueI_B.sum *
                  APF_Path_Planning_2023a_BlueI_B.tst;
              }
              break;

             case 2:
              for (APF_Path_Planning_2023a_BlueI_B.knt =
                   APF_Path_Planning_2023a_BlueI_B.s_tmp_m;
                   APF_Path_Planning_2023a_BlueI_B.knt <=
                   APF_Path_Planning_2023a_BlueI_B.b_i + 1;
                   APF_Path_Planning_2023a_BlueI_B.knt++) {
                APF_Path_Planning_2023a_BlueI_B.nr =
                  (APF_Path_Planning_2023a_BlueI_B.knt - 1) * 6 +
                  APF_Path_Planning_2023a_BlueI_B.s_tmp_m;
                APF_Path_Planning_2023a_BlueI_B.h12 =
                  h[APF_Path_Planning_2023a_BlueI_B.nr - 1];
                APF_Path_Planning_2023a_BlueI_B.s_tmp =
                  h[APF_Path_Planning_2023a_BlueI_B.nr];
                APF_Path_Planning_2023a_BlueI_B.sum =
                  APF_Path_Planning_2023a_BlueI_B.h11 *
                  APF_Path_Planning_2023a_BlueI_B.s_tmp +
                  APF_Path_Planning_2023a_BlueI_B.h12;
                h[APF_Path_Planning_2023a_BlueI_B.nr - 1] =
                  APF_Path_Planning_2023a_BlueI_B.h12 -
                  APF_Path_Planning_2023a_BlueI_B.sum *
                  APF_Path_Planning_2023a_BlueI_B.s_j;
                h[APF_Path_Planning_2023a_BlueI_B.nr] =
                  APF_Path_Planning_2023a_BlueI_B.s_tmp -
                  APF_Path_Planning_2023a_BlueI_B.sum *
                  APF_Path_Planning_2023a_BlueI_B.tr;
              }

              for (APF_Path_Planning_2023a_BlueI_B.knt =
                   APF_Path_Planning_2023a_BlueI_B.k_m + 1;
                   APF_Path_Planning_2023a_BlueI_B.knt <=
                   APF_Path_Planning_2023a_BlueI_B.b_i + 1;
                   APF_Path_Planning_2023a_BlueI_B.knt++) {
                APF_Path_Planning_2023a_BlueI_B.nr =
                  ((APF_Path_Planning_2023a_BlueI_B.s_tmp_m - 1) * 6 +
                   APF_Path_Planning_2023a_BlueI_B.knt) - 1;
                APF_Path_Planning_2023a_BlueI_B.h12 =
                  h[APF_Path_Planning_2023a_BlueI_B.nr];
                APF_Path_Planning_2023a_BlueI_B.ix0 = (6 *
                  APF_Path_Planning_2023a_BlueI_B.s_tmp_m +
                  APF_Path_Planning_2023a_BlueI_B.knt) - 1;
                APF_Path_Planning_2023a_BlueI_B.s_tmp =
                  h[APF_Path_Planning_2023a_BlueI_B.ix0];
                APF_Path_Planning_2023a_BlueI_B.sum =
                  APF_Path_Planning_2023a_BlueI_B.h11 *
                  APF_Path_Planning_2023a_BlueI_B.s_tmp +
                  APF_Path_Planning_2023a_BlueI_B.h12;
                h[APF_Path_Planning_2023a_BlueI_B.nr] =
                  APF_Path_Planning_2023a_BlueI_B.h12 -
                  APF_Path_Planning_2023a_BlueI_B.sum *
                  APF_Path_Planning_2023a_BlueI_B.s_j;
                h[APF_Path_Planning_2023a_BlueI_B.ix0] =
                  APF_Path_Planning_2023a_BlueI_B.s_tmp -
                  APF_Path_Planning_2023a_BlueI_B.sum *
                  APF_Path_Planning_2023a_BlueI_B.tr;
              }
              break;
            }
          }

          APF_Path_Planning_2023a_BlueI_B.its++;
        }
      }

      if (!APF_Path_Planning_2023a_BlueI_B.converged) {
        *info = APF_Path_Planning_2023a_BlueI_B.b_i + 1;
        exitg1 = true;
      } else {
        if (APF_Path_Planning_2023a_BlueI_B.b_i + 1 ==
            APF_Path_Planning_2023a_BlueI_B.l) {
          wr[APF_Path_Planning_2023a_BlueI_B.b_i] = h[6 *
            APF_Path_Planning_2023a_BlueI_B.b_i +
            APF_Path_Planning_2023a_BlueI_B.b_i];
          wi[APF_Path_Planning_2023a_BlueI_B.b_i] = 0.0;
        } else if (APF_Path_Planning_2023a_BlueI_B.l ==
                   APF_Path_Planning_2023a_BlueI_B.b_i) {
          APF_Path_Planning_2023a_BlueI_B.kdefl = 6 *
            APF_Path_Planning_2023a_BlueI_B.b_i +
            APF_Path_Planning_2023a_BlueI_B.b_i;
          APF_Path_Planning_2023a_BlueI_B.s_j =
            h[APF_Path_Planning_2023a_BlueI_B.kdefl - 1];
          APF_Path_Planning_2023a_BlueI_B.its =
            (APF_Path_Planning_2023a_BlueI_B.b_i - 1) * 6 +
            APF_Path_Planning_2023a_BlueI_B.b_i;
          APF_Path_Planning_2023a_BlueI_B.h11 =
            h[APF_Path_Planning_2023a_BlueI_B.its];
          APF_Path_Planning_2023a_BlueI_B.tr =
            h[APF_Path_Planning_2023a_BlueI_B.kdefl];
          APF_Path_Planning_2023a_xdlanv2(&h[APF_Path_Planning_2023a_BlueI_B.its
            - 1], &APF_Path_Planning_2023a_BlueI_B.s_j,
            &APF_Path_Planning_2023a_BlueI_B.h11,
            &APF_Path_Planning_2023a_BlueI_B.tr,
            &wr[APF_Path_Planning_2023a_BlueI_B.b_i - 1],
            &wi[APF_Path_Planning_2023a_BlueI_B.b_i - 1],
            &APF_Path_Planning_2023a_BlueI_B.aa,
            &APF_Path_Planning_2023a_BlueI_B.tst,
            &APF_Path_Planning_2023a_BlueI_B.h12,
            &APF_Path_Planning_2023a_BlueI_B.s_tmp);
          wr[APF_Path_Planning_2023a_BlueI_B.b_i] =
            APF_Path_Planning_2023a_BlueI_B.aa;
          wi[APF_Path_Planning_2023a_BlueI_B.b_i] =
            APF_Path_Planning_2023a_BlueI_B.tst;
          h[APF_Path_Planning_2023a_BlueI_B.kdefl - 1] =
            APF_Path_Planning_2023a_BlueI_B.s_j;
          h[APF_Path_Planning_2023a_BlueI_B.its] =
            APF_Path_Planning_2023a_BlueI_B.h11;
          h[APF_Path_Planning_2023a_BlueI_B.kdefl] =
            APF_Path_Planning_2023a_BlueI_B.tr;
        }

        APF_Path_Planning_2023a_BlueI_B.kdefl = 0;
        APF_Path_Planning_2023a_BlueI_B.b_i = APF_Path_Planning_2023a_BlueI_B.l
          - 2;
      }
    }

    if (*info != 0) {
      for (APF_Path_Planning_2023a_BlueI_B.b_i = 0;
           APF_Path_Planning_2023a_BlueI_B.b_i < 4;
           APF_Path_Planning_2023a_BlueI_B.b_i++) {
        for (APF_Path_Planning_2023a_BlueI_B.l =
             APF_Path_Planning_2023a_BlueI_B.b_i + 3;
             APF_Path_Planning_2023a_BlueI_B.l < 7;
             APF_Path_Planning_2023a_BlueI_B.l++) {
          h[(APF_Path_Planning_2023a_BlueI_B.l + 6 *
             APF_Path_Planning_2023a_BlueI_B.b_i) - 1] = 0.0;
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S356>/MATLAB Function'
static void APF_Path_Planning_202_xzlascl_f(real_T cfrom, real_T cto, int32_T
  b_m, real_T A[6], int32_T iA0)
{
  APF_Path_Planning_2023a_BlueI_B.cfromc = cfrom;
  APF_Path_Planning_2023a_BlueI_B.ctoc = cto;
  APF_Path_Planning_2023a_BlueI_B.notdone_k = true;
  while (APF_Path_Planning_2023a_BlueI_B.notdone_k) {
    APF_Path_Planning_2023a_BlueI_B.cfrom1 =
      APF_Path_Planning_2023a_BlueI_B.cfromc * 2.0041683600089728E-292;
    APF_Path_Planning_2023a_BlueI_B.cto1 = APF_Path_Planning_2023a_BlueI_B.ctoc /
      4.9896007738368E+291;
    if ((fabs(APF_Path_Planning_2023a_BlueI_B.cfrom1) > fabs
         (APF_Path_Planning_2023a_BlueI_B.ctoc)) &&
        (APF_Path_Planning_2023a_BlueI_B.ctoc != 0.0)) {
      APF_Path_Planning_2023a_BlueI_B.mul = 2.0041683600089728E-292;
      APF_Path_Planning_2023a_BlueI_B.cfromc =
        APF_Path_Planning_2023a_BlueI_B.cfrom1;
    } else if (fabs(APF_Path_Planning_2023a_BlueI_B.cto1) > fabs
               (APF_Path_Planning_2023a_BlueI_B.cfromc)) {
      APF_Path_Planning_2023a_BlueI_B.mul = 4.9896007738368E+291;
      APF_Path_Planning_2023a_BlueI_B.ctoc =
        APF_Path_Planning_2023a_BlueI_B.cto1;
    } else {
      APF_Path_Planning_2023a_BlueI_B.mul = APF_Path_Planning_2023a_BlueI_B.ctoc
        / APF_Path_Planning_2023a_BlueI_B.cfromc;
      APF_Path_Planning_2023a_BlueI_B.notdone_k = false;
    }

    for (APF_Path_Planning_2023a_BlueI_B.b_i_g = 0;
         APF_Path_Planning_2023a_BlueI_B.b_i_g < b_m;
         APF_Path_Planning_2023a_BlueI_B.b_i_g++) {
      APF_Path_Planning_2023a_BlueI_B.i1 =
        (APF_Path_Planning_2023a_BlueI_B.b_i_g + iA0) - 1;
      A[APF_Path_Planning_2023a_BlueI_B.i1] *=
        APF_Path_Planning_2023a_BlueI_B.mul;
    }
  }
}

// Function for MATLAB Function: '<S356>/MATLAB Function'
static void APF_Path_Planning_2_eigStandard(const real_T A[36], creal_T V[6])
{
  int32_T exitg2;
  int32_T exitg3;
  int32_T exitg4;
  int32_T exitg5;
  boolean_T exitg1;
  boolean_T exitg6;
  boolean_T exitg7;
  memcpy(&APF_Path_Planning_2023a_BlueI_B.b_A_p[0], &A[0], 36U * sizeof(real_T));
  APF_Path_Planning_2023a_BlueI_B.anrm_b = 0.0;
  APF_Path_Planning_2023a_BlueI_B.b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (APF_Path_Planning_2023a_BlueI_B.b_k < 36)) {
    APF_Path_Planning_2023a_BlueI_B.absxk_j = fabs
      (A[APF_Path_Planning_2023a_BlueI_B.b_k]);
    if (rtIsNaN(APF_Path_Planning_2023a_BlueI_B.absxk_j)) {
      APF_Path_Planning_2023a_BlueI_B.anrm_b = (rtNaN);
      exitg1 = true;
    } else {
      if (APF_Path_Planning_2023a_BlueI_B.absxk_j >
          APF_Path_Planning_2023a_BlueI_B.anrm_b) {
        APF_Path_Planning_2023a_BlueI_B.anrm_b =
          APF_Path_Planning_2023a_BlueI_B.absxk_j;
      }

      APF_Path_Planning_2023a_BlueI_B.b_k++;
    }
  }

  if (rtIsInf(APF_Path_Planning_2023a_BlueI_B.anrm_b) || rtIsNaN
      (APF_Path_Planning_2023a_BlueI_B.anrm_b)) {
    for (APF_Path_Planning_2023a_BlueI_B.i_h2 = 0;
         APF_Path_Planning_2023a_BlueI_B.i_h2 < 6;
         APF_Path_Planning_2023a_BlueI_B.i_h2++) {
      V[APF_Path_Planning_2023a_BlueI_B.i_h2].re = (rtNaN);
      V[APF_Path_Planning_2023a_BlueI_B.i_h2].im = 0.0;
    }
  } else {
    APF_Path_Planning_2023a_BlueI_B.absxk_j =
      APF_Path_Planning_2023a_BlueI_B.anrm_b;
    APF_Path_Planning_2023a_BlueI_B.scalea = false;
    if ((APF_Path_Planning_2023a_BlueI_B.anrm_b > 0.0) &&
        (APF_Path_Planning_2023a_BlueI_B.anrm_b < 6.7178761075670888E-139)) {
      APF_Path_Planning_2023a_BlueI_B.scalea = true;
      APF_Path_Planning_2023a_BlueI_B.absxk_j = 6.7178761075670888E-139;
      APF_Path_Planning_2023a_xzlascl(APF_Path_Planning_2023a_BlueI_B.anrm_b,
        APF_Path_Planning_2023a_BlueI_B.absxk_j,
        APF_Path_Planning_2023a_BlueI_B.b_A_p);
    } else if (APF_Path_Planning_2023a_BlueI_B.anrm_b > 1.4885657073574029E+138)
    {
      APF_Path_Planning_2023a_BlueI_B.scalea = true;
      APF_Path_Planning_2023a_BlueI_B.absxk_j = 1.4885657073574029E+138;
      APF_Path_Planning_2023a_xzlascl(APF_Path_Planning_2023a_BlueI_B.anrm_b,
        APF_Path_Planning_2023a_BlueI_B.absxk_j,
        APF_Path_Planning_2023a_BlueI_B.b_A_p);
    }

    for (APF_Path_Planning_2023a_BlueI_B.i_h2 = 0;
         APF_Path_Planning_2023a_BlueI_B.i_h2 < 6;
         APF_Path_Planning_2023a_BlueI_B.i_h2++) {
      APF_Path_Planning_2023a_BlueI_B.wr[APF_Path_Planning_2023a_BlueI_B.i_h2] =
        1.0;
    }

    APF_Path_Planning_2023a_BlueI_B.b_k = 1;
    APF_Path_Planning_2023a_BlueI_B.i_h2 = 6;
    APF_Path_Planning_2023a_BlueI_B.notdone = true;
    do {
      exitg5 = 0;
      if (APF_Path_Planning_2023a_BlueI_B.notdone) {
        APF_Path_Planning_2023a_BlueI_B.notdone = false;
        APF_Path_Planning_2023a_BlueI_B.kend =
          APF_Path_Planning_2023a_BlueI_B.i_h2;
        do {
          exitg4 = 0;
          if (APF_Path_Planning_2023a_BlueI_B.kend > 0) {
            APF_Path_Planning_2023a_BlueI_B.skipThisColumn = false;
            APF_Path_Planning_2023a_BlueI_B.d_i = 0;
            exitg6 = false;
            while ((!exitg6) && (APF_Path_Planning_2023a_BlueI_B.d_i <=
                                 static_cast<uint8_T>
                                 (APF_Path_Planning_2023a_BlueI_B.i_h2) - 1)) {
              if ((APF_Path_Planning_2023a_BlueI_B.d_i + 1 ==
                   APF_Path_Planning_2023a_BlueI_B.kend) ||
                  (!(APF_Path_Planning_2023a_BlueI_B.b_A_p[(6 *
                     APF_Path_Planning_2023a_BlueI_B.d_i +
                     APF_Path_Planning_2023a_BlueI_B.kend) - 1] != 0.0))) {
                APF_Path_Planning_2023a_BlueI_B.d_i++;
              } else {
                APF_Path_Planning_2023a_BlueI_B.skipThisColumn = true;
                exitg6 = true;
              }
            }

            if (APF_Path_Planning_2023a_BlueI_B.skipThisColumn) {
              APF_Path_Planning_2023a_BlueI_B.kend--;
            } else {
              APF_Path_Planning_2023a_BlueI_B.wr[APF_Path_Planning_2023a_BlueI_B.i_h2
                - 1] = APF_Path_Planning_2023a_BlueI_B.kend;
              if (APF_Path_Planning_2023a_BlueI_B.kend !=
                  APF_Path_Planning_2023a_BlueI_B.i_h2) {
                APF_Path_Planning_2023a_BlueI_B.d_iy =
                  (APF_Path_Planning_2023a_BlueI_B.kend - 1) * 6;
                APF_Path_Planning_2023a_BlueI_B.ica =
                  (APF_Path_Planning_2023a_BlueI_B.i_h2 - 1) * 6;
                APF_Path_Planning_2023a_BlueI_B.ira = static_cast<uint8_T>
                  (APF_Path_Planning_2023a_BlueI_B.i_h2);
                for (APF_Path_Planning_2023a_BlueI_B.f_k = 0;
                     APF_Path_Planning_2023a_BlueI_B.f_k <
                     APF_Path_Planning_2023a_BlueI_B.ira;
                     APF_Path_Planning_2023a_BlueI_B.f_k++) {
                  APF_Path_Planning_2023a_BlueI_B.c_temp_tmp =
                    APF_Path_Planning_2023a_BlueI_B.d_iy +
                    APF_Path_Planning_2023a_BlueI_B.f_k;
                  APF_Path_Planning_2023a_BlueI_B.c =
                    APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.c_temp_tmp];
                  APF_Path_Planning_2023a_BlueI_B.d_i =
                    APF_Path_Planning_2023a_BlueI_B.ica +
                    APF_Path_Planning_2023a_BlueI_B.f_k;
                  APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.c_temp_tmp]
                    =
                    APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.d_i];
                  APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.d_i]
                    = APF_Path_Planning_2023a_BlueI_B.c;
                }

                for (APF_Path_Planning_2023a_BlueI_B.d_iy = 0;
                     APF_Path_Planning_2023a_BlueI_B.d_iy < 6;
                     APF_Path_Planning_2023a_BlueI_B.d_iy++) {
                  APF_Path_Planning_2023a_BlueI_B.ica =
                    (APF_Path_Planning_2023a_BlueI_B.d_iy * 6 +
                     APF_Path_Planning_2023a_BlueI_B.kend) - 1;
                  APF_Path_Planning_2023a_BlueI_B.c =
                    APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.ica];
                  APF_Path_Planning_2023a_BlueI_B.d_i =
                    (APF_Path_Planning_2023a_BlueI_B.d_iy * 6 +
                     APF_Path_Planning_2023a_BlueI_B.i_h2) - 1;
                  APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.ica]
                    =
                    APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.d_i];
                  APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.d_i]
                    = APF_Path_Planning_2023a_BlueI_B.c;
                }
              }

              exitg4 = 1;
            }
          } else {
            exitg4 = 2;
          }
        } while (exitg4 == 0);

        if (exitg4 == 1) {
          if (APF_Path_Planning_2023a_BlueI_B.i_h2 == 1) {
            APF_Path_Planning_2023a_BlueI_B.b_k = 1;
            APF_Path_Planning_2023a_BlueI_B.i_h2 = 1;
            exitg5 = 1;
          } else {
            APF_Path_Planning_2023a_BlueI_B.i_h2--;
            APF_Path_Planning_2023a_BlueI_B.notdone = true;
          }
        }
      } else {
        APF_Path_Planning_2023a_BlueI_B.notdone = true;
        while (APF_Path_Planning_2023a_BlueI_B.notdone) {
          APF_Path_Planning_2023a_BlueI_B.notdone = false;
          APF_Path_Planning_2023a_BlueI_B.kend =
            APF_Path_Planning_2023a_BlueI_B.b_k;
          exitg6 = false;
          while ((!exitg6) && (APF_Path_Planning_2023a_BlueI_B.kend <=
                               APF_Path_Planning_2023a_BlueI_B.i_h2)) {
            APF_Path_Planning_2023a_BlueI_B.skipThisColumn = false;
            APF_Path_Planning_2023a_BlueI_B.d_i =
              APF_Path_Planning_2023a_BlueI_B.b_k;
            exitg7 = false;
            while ((!exitg7) && (APF_Path_Planning_2023a_BlueI_B.d_i <=
                                 APF_Path_Planning_2023a_BlueI_B.i_h2)) {
              if ((APF_Path_Planning_2023a_BlueI_B.d_i ==
                   APF_Path_Planning_2023a_BlueI_B.kend) ||
                  (!(APF_Path_Planning_2023a_BlueI_B.b_A_p
                     [((APF_Path_Planning_2023a_BlueI_B.kend - 1) * 6 +
                       APF_Path_Planning_2023a_BlueI_B.d_i) - 1] != 0.0))) {
                APF_Path_Planning_2023a_BlueI_B.d_i++;
              } else {
                APF_Path_Planning_2023a_BlueI_B.skipThisColumn = true;
                exitg7 = true;
              }
            }

            if (APF_Path_Planning_2023a_BlueI_B.skipThisColumn) {
              APF_Path_Planning_2023a_BlueI_B.kend++;
            } else {
              APF_Path_Planning_2023a_BlueI_B.wr[APF_Path_Planning_2023a_BlueI_B.b_k
                - 1] = APF_Path_Planning_2023a_BlueI_B.kend;
              if (APF_Path_Planning_2023a_BlueI_B.kend !=
                  APF_Path_Planning_2023a_BlueI_B.b_k) {
                APF_Path_Planning_2023a_BlueI_B.ica =
                  (APF_Path_Planning_2023a_BlueI_B.kend - 1) * 6;
                APF_Path_Planning_2023a_BlueI_B.d_iy =
                  (APF_Path_Planning_2023a_BlueI_B.b_k - 1) * 6;
                APF_Path_Planning_2023a_BlueI_B.ira = static_cast<uint8_T>
                  (APF_Path_Planning_2023a_BlueI_B.i_h2);
                for (APF_Path_Planning_2023a_BlueI_B.f_k = 0;
                     APF_Path_Planning_2023a_BlueI_B.f_k <
                     APF_Path_Planning_2023a_BlueI_B.ira;
                     APF_Path_Planning_2023a_BlueI_B.f_k++) {
                  APF_Path_Planning_2023a_BlueI_B.c_temp_tmp =
                    APF_Path_Planning_2023a_BlueI_B.ica +
                    APF_Path_Planning_2023a_BlueI_B.f_k;
                  APF_Path_Planning_2023a_BlueI_B.c =
                    APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.c_temp_tmp];
                  APF_Path_Planning_2023a_BlueI_B.d_i =
                    APF_Path_Planning_2023a_BlueI_B.d_iy +
                    APF_Path_Planning_2023a_BlueI_B.f_k;
                  APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.c_temp_tmp]
                    =
                    APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.d_i];
                  APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.d_i]
                    = APF_Path_Planning_2023a_BlueI_B.c;
                }

                APF_Path_Planning_2023a_BlueI_B.kend =
                  (APF_Path_Planning_2023a_BlueI_B.d_iy +
                   APF_Path_Planning_2023a_BlueI_B.kend) - 1;
                APF_Path_Planning_2023a_BlueI_B.d_iy =
                  (APF_Path_Planning_2023a_BlueI_B.d_iy +
                   APF_Path_Planning_2023a_BlueI_B.b_k) - 1;
                APF_Path_Planning_2023a_BlueI_B.ica = static_cast<uint8_T>(7 -
                  APF_Path_Planning_2023a_BlueI_B.b_k);
                for (APF_Path_Planning_2023a_BlueI_B.ira = 0;
                     APF_Path_Planning_2023a_BlueI_B.ira <
                     APF_Path_Planning_2023a_BlueI_B.ica;
                     APF_Path_Planning_2023a_BlueI_B.ira++) {
                  APF_Path_Planning_2023a_BlueI_B.f_k =
                    APF_Path_Planning_2023a_BlueI_B.ira * 6 +
                    APF_Path_Planning_2023a_BlueI_B.kend;
                  APF_Path_Planning_2023a_BlueI_B.c =
                    APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.f_k];
                  APF_Path_Planning_2023a_BlueI_B.d_i =
                    APF_Path_Planning_2023a_BlueI_B.ira * 6 +
                    APF_Path_Planning_2023a_BlueI_B.d_iy;
                  APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.f_k]
                    =
                    APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.d_i];
                  APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.d_i]
                    = APF_Path_Planning_2023a_BlueI_B.c;
                }
              }

              APF_Path_Planning_2023a_BlueI_B.b_k++;
              APF_Path_Planning_2023a_BlueI_B.notdone = true;
              exitg6 = true;
            }
          }
        }

        APF_Path_Planning_2023a_BlueI_B.notdone = false;
        exitg5 = 2;
      }
    } while (exitg5 == 0);

    if (exitg5 == 1) {
    } else {
      exitg1 = false;
      while ((!exitg1) && (!APF_Path_Planning_2023a_BlueI_B.notdone)) {
        APF_Path_Planning_2023a_BlueI_B.notdone = true;
        APF_Path_Planning_2023a_BlueI_B.d_i =
          APF_Path_Planning_2023a_BlueI_B.b_k - 1;
        do {
          exitg3 = 0;
          if (APF_Path_Planning_2023a_BlueI_B.d_i + 1 <=
              APF_Path_Planning_2023a_BlueI_B.i_h2) {
            APF_Path_Planning_2023a_BlueI_B.kend =
              (APF_Path_Planning_2023a_BlueI_B.i_h2 -
               APF_Path_Planning_2023a_BlueI_B.b_k) + 1;
            APF_Path_Planning_2023a_BlueI_B.c = APF_Path_Planning_2023a_xnrm2_m
              (APF_Path_Planning_2023a_BlueI_B.kend,
               APF_Path_Planning_2023a_BlueI_B.b_A_p,
               APF_Path_Planning_2023a_BlueI_B.d_i * 6 +
               APF_Path_Planning_2023a_BlueI_B.b_k);
            APF_Path_Planning_2023a_BlueI_B.d_iy =
              (APF_Path_Planning_2023a_BlueI_B.b_k - 1) * 6 +
              APF_Path_Planning_2023a_BlueI_B.d_i;
            APF_Path_Planning_2023a_BlueI_B.r = 0.0;
            if (APF_Path_Planning_2023a_BlueI_B.kend >= 1) {
              if (APF_Path_Planning_2023a_BlueI_B.kend == 1) {
                APF_Path_Planning_2023a_BlueI_B.r = fabs
                  (APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.d_iy]);
              } else {
                APF_Path_Planning_2023a_BlueI_B.scale = 3.3121686421112381E-170;
                APF_Path_Planning_2023a_BlueI_B.kend =
                  ((APF_Path_Planning_2023a_BlueI_B.kend - 1) * 6 +
                   APF_Path_Planning_2023a_BlueI_B.d_iy) + 1;
                for (APF_Path_Planning_2023a_BlueI_B.ica =
                     APF_Path_Planning_2023a_BlueI_B.d_iy + 1;
                     APF_Path_Planning_2023a_BlueI_B.ica <=
                     APF_Path_Planning_2023a_BlueI_B.kend;
                     APF_Path_Planning_2023a_BlueI_B.ica += 6) {
                  APF_Path_Planning_2023a_BlueI_B.b_absxk = fabs
                    (APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.ica
                     - 1]);
                  if (APF_Path_Planning_2023a_BlueI_B.b_absxk >
                      APF_Path_Planning_2023a_BlueI_B.scale) {
                    APF_Path_Planning_2023a_BlueI_B.t_f =
                      APF_Path_Planning_2023a_BlueI_B.scale /
                      APF_Path_Planning_2023a_BlueI_B.b_absxk;
                    APF_Path_Planning_2023a_BlueI_B.r =
                      APF_Path_Planning_2023a_BlueI_B.r *
                      APF_Path_Planning_2023a_BlueI_B.t_f *
                      APF_Path_Planning_2023a_BlueI_B.t_f + 1.0;
                    APF_Path_Planning_2023a_BlueI_B.scale =
                      APF_Path_Planning_2023a_BlueI_B.b_absxk;
                  } else {
                    APF_Path_Planning_2023a_BlueI_B.t_f =
                      APF_Path_Planning_2023a_BlueI_B.b_absxk /
                      APF_Path_Planning_2023a_BlueI_B.scale;
                    APF_Path_Planning_2023a_BlueI_B.r +=
                      APF_Path_Planning_2023a_BlueI_B.t_f *
                      APF_Path_Planning_2023a_BlueI_B.t_f;
                  }
                }

                APF_Path_Planning_2023a_BlueI_B.r =
                  APF_Path_Planning_2023a_BlueI_B.scale * sqrt
                  (APF_Path_Planning_2023a_BlueI_B.r);
              }
            }

            APF_Path_Planning_2023a_BlueI_B.kend =
              APF_Path_Planning_2023a_BlueI_B.d_i * 6;
            APF_Path_Planning_2023a_BlueI_B.ica = 1;
            if (APF_Path_Planning_2023a_BlueI_B.i_h2 > 1) {
              APF_Path_Planning_2023a_BlueI_B.scale = fabs
                (APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.kend]);
              for (APF_Path_Planning_2023a_BlueI_B.ira = 2;
                   APF_Path_Planning_2023a_BlueI_B.ira <=
                   APF_Path_Planning_2023a_BlueI_B.i_h2;
                   APF_Path_Planning_2023a_BlueI_B.ira++) {
                APF_Path_Planning_2023a_BlueI_B.b_absxk = fabs
                  (APF_Path_Planning_2023a_BlueI_B.b_A_p
                   [(APF_Path_Planning_2023a_BlueI_B.kend +
                     APF_Path_Planning_2023a_BlueI_B.ira) - 1]);
                if (APF_Path_Planning_2023a_BlueI_B.b_absxk >
                    APF_Path_Planning_2023a_BlueI_B.scale) {
                  APF_Path_Planning_2023a_BlueI_B.ica =
                    APF_Path_Planning_2023a_BlueI_B.ira;
                  APF_Path_Planning_2023a_BlueI_B.scale =
                    APF_Path_Planning_2023a_BlueI_B.b_absxk;
                }
              }
            }

            APF_Path_Planning_2023a_BlueI_B.scale = fabs
              (APF_Path_Planning_2023a_BlueI_B.b_A_p[(6 *
                APF_Path_Planning_2023a_BlueI_B.d_i +
                APF_Path_Planning_2023a_BlueI_B.ica) - 1]);
            APF_Path_Planning_2023a_BlueI_B.ica = 7 -
              APF_Path_Planning_2023a_BlueI_B.b_k;
            if (7 - APF_Path_Planning_2023a_BlueI_B.b_k < 1) {
              APF_Path_Planning_2023a_BlueI_B.ira = 0;
            } else {
              APF_Path_Planning_2023a_BlueI_B.ira = 1;
              if (7 - APF_Path_Planning_2023a_BlueI_B.b_k > 1) {
                APF_Path_Planning_2023a_BlueI_B.b_absxk = fabs
                  (APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.d_iy]);
                for (APF_Path_Planning_2023a_BlueI_B.f_k = 2;
                     APF_Path_Planning_2023a_BlueI_B.f_k <=
                     APF_Path_Planning_2023a_BlueI_B.ica;
                     APF_Path_Planning_2023a_BlueI_B.f_k++) {
                  APF_Path_Planning_2023a_BlueI_B.t_f = fabs
                    (APF_Path_Planning_2023a_BlueI_B.b_A_p
                     [(APF_Path_Planning_2023a_BlueI_B.f_k - 1) * 6 +
                     APF_Path_Planning_2023a_BlueI_B.d_iy]);
                  if (APF_Path_Planning_2023a_BlueI_B.t_f >
                      APF_Path_Planning_2023a_BlueI_B.b_absxk) {
                    APF_Path_Planning_2023a_BlueI_B.ira =
                      APF_Path_Planning_2023a_BlueI_B.f_k;
                    APF_Path_Planning_2023a_BlueI_B.b_absxk =
                      APF_Path_Planning_2023a_BlueI_B.t_f;
                  }
                }
              }
            }

            APF_Path_Planning_2023a_BlueI_B.t_f = fabs
              (APF_Path_Planning_2023a_BlueI_B.b_A_p
               [((APF_Path_Planning_2023a_BlueI_B.ira +
                  APF_Path_Planning_2023a_BlueI_B.b_k) - 2) * 6 +
               APF_Path_Planning_2023a_BlueI_B.d_i]);
            if ((APF_Path_Planning_2023a_BlueI_B.c == 0.0) ||
                (APF_Path_Planning_2023a_BlueI_B.r == 0.0)) {
              APF_Path_Planning_2023a_BlueI_B.d_i++;
            } else {
              APF_Path_Planning_2023a_BlueI_B.g =
                APF_Path_Planning_2023a_BlueI_B.r / 2.0;
              APF_Path_Planning_2023a_BlueI_B.b_absxk = 1.0;
              APF_Path_Planning_2023a_BlueI_B.s =
                APF_Path_Planning_2023a_BlueI_B.c +
                APF_Path_Planning_2023a_BlueI_B.r;
              do {
                exitg2 = 0;
                if (APF_Path_Planning_2023a_BlueI_B.c <
                    APF_Path_Planning_2023a_BlueI_B.g) {
                  if ((APF_Path_Planning_2023a_BlueI_B.c >=
                       APF_Path_Planning_2023a_BlueI_B.scale) || rtIsNaN
                      (APF_Path_Planning_2023a_BlueI_B.scale)) {
                    APF_Path_Planning_2023a_BlueI_B.y_a =
                      APF_Path_Planning_2023a_BlueI_B.c;
                  } else {
                    APF_Path_Planning_2023a_BlueI_B.y_a =
                      APF_Path_Planning_2023a_BlueI_B.scale;
                  }

                  if (APF_Path_Planning_2023a_BlueI_B.b_absxk >=
                      APF_Path_Planning_2023a_BlueI_B.y_a) {
                    APF_Path_Planning_2023a_BlueI_B.y_a =
                      APF_Path_Planning_2023a_BlueI_B.b_absxk;
                  }

                  if (APF_Path_Planning_2023a_BlueI_B.y_a < 4.9896007738368E+291)
                  {
                    if ((APF_Path_Planning_2023a_BlueI_B.g <=
                         APF_Path_Planning_2023a_BlueI_B.t_f) || rtIsNaN
                        (APF_Path_Planning_2023a_BlueI_B.t_f)) {
                      APF_Path_Planning_2023a_BlueI_B.y_a =
                        APF_Path_Planning_2023a_BlueI_B.g;
                    } else {
                      APF_Path_Planning_2023a_BlueI_B.y_a =
                        APF_Path_Planning_2023a_BlueI_B.t_f;
                    }

                    if (APF_Path_Planning_2023a_BlueI_B.r <=
                        APF_Path_Planning_2023a_BlueI_B.y_a) {
                      APF_Path_Planning_2023a_BlueI_B.y_a =
                        APF_Path_Planning_2023a_BlueI_B.r;
                    }

                    if (APF_Path_Planning_2023a_BlueI_B.y_a >
                        2.0041683600089728E-292) {
                      if (rtIsNaN(((((APF_Path_Planning_2023a_BlueI_B.c +
                                      APF_Path_Planning_2023a_BlueI_B.b_absxk) +
                                     APF_Path_Planning_2023a_BlueI_B.scale) +
                                    APF_Path_Planning_2023a_BlueI_B.r) +
                                   APF_Path_Planning_2023a_BlueI_B.g) +
                                  APF_Path_Planning_2023a_BlueI_B.t_f)) {
                        exitg2 = 1;
                      } else {
                        APF_Path_Planning_2023a_BlueI_B.b_absxk *= 2.0;
                        APF_Path_Planning_2023a_BlueI_B.c *= 2.0;
                        APF_Path_Planning_2023a_BlueI_B.scale *= 2.0;
                        APF_Path_Planning_2023a_BlueI_B.r /= 2.0;
                        APF_Path_Planning_2023a_BlueI_B.g /= 2.0;
                        APF_Path_Planning_2023a_BlueI_B.t_f /= 2.0;
                      }
                    } else {
                      exitg2 = 2;
                    }
                  } else {
                    exitg2 = 2;
                  }
                } else {
                  exitg2 = 2;
                }
              } while (exitg2 == 0);

              if (exitg2 == 1) {
                exitg3 = 2;
              } else {
                APF_Path_Planning_2023a_BlueI_B.g =
                  APF_Path_Planning_2023a_BlueI_B.c / 2.0;
                exitg6 = false;
                while ((!exitg6) && (APF_Path_Planning_2023a_BlueI_B.g >=
                                     APF_Path_Planning_2023a_BlueI_B.r)) {
                  if ((APF_Path_Planning_2023a_BlueI_B.r >=
                       APF_Path_Planning_2023a_BlueI_B.t_f) || rtIsNaN
                      (APF_Path_Planning_2023a_BlueI_B.t_f)) {
                    APF_Path_Planning_2023a_BlueI_B.y_a =
                      APF_Path_Planning_2023a_BlueI_B.r;
                  } else {
                    APF_Path_Planning_2023a_BlueI_B.y_a =
                      APF_Path_Planning_2023a_BlueI_B.t_f;
                  }

                  if (APF_Path_Planning_2023a_BlueI_B.y_a < 4.9896007738368E+291)
                  {
                    if ((APF_Path_Planning_2023a_BlueI_B.b_absxk <=
                         APF_Path_Planning_2023a_BlueI_B.c) || rtIsNaN
                        (APF_Path_Planning_2023a_BlueI_B.c)) {
                      APF_Path_Planning_2023a_BlueI_B.y_a =
                        APF_Path_Planning_2023a_BlueI_B.b_absxk;
                    } else {
                      APF_Path_Planning_2023a_BlueI_B.y_a =
                        APF_Path_Planning_2023a_BlueI_B.c;
                    }

                    if ((APF_Path_Planning_2023a_BlueI_B.g <=
                         APF_Path_Planning_2023a_BlueI_B.scale) || rtIsNaN
                        (APF_Path_Planning_2023a_BlueI_B.scale)) {
                      APF_Path_Planning_2023a_BlueI_B.y_j =
                        APF_Path_Planning_2023a_BlueI_B.g;
                    } else {
                      APF_Path_Planning_2023a_BlueI_B.y_j =
                        APF_Path_Planning_2023a_BlueI_B.scale;
                    }

                    if (APF_Path_Planning_2023a_BlueI_B.y_a <=
                        APF_Path_Planning_2023a_BlueI_B.y_j) {
                      APF_Path_Planning_2023a_BlueI_B.y_j =
                        APF_Path_Planning_2023a_BlueI_B.y_a;
                    }

                    if (APF_Path_Planning_2023a_BlueI_B.y_j >
                        2.0041683600089728E-292) {
                      APF_Path_Planning_2023a_BlueI_B.b_absxk /= 2.0;
                      APF_Path_Planning_2023a_BlueI_B.c /= 2.0;
                      APF_Path_Planning_2023a_BlueI_B.g /= 2.0;
                      APF_Path_Planning_2023a_BlueI_B.scale /= 2.0;
                      APF_Path_Planning_2023a_BlueI_B.r *= 2.0;
                      APF_Path_Planning_2023a_BlueI_B.t_f *= 2.0;
                    } else {
                      exitg6 = true;
                    }
                  } else {
                    exitg6 = true;
                  }
                }

                if ((APF_Path_Planning_2023a_BlueI_B.c +
                     APF_Path_Planning_2023a_BlueI_B.r >= 0.95 *
                     APF_Path_Planning_2023a_BlueI_B.s) ||
                    ((APF_Path_Planning_2023a_BlueI_B.b_absxk < 1.0) &&
                     (APF_Path_Planning_2023a_BlueI_B.wr[APF_Path_Planning_2023a_BlueI_B.d_i]
                      < 1.0) && (APF_Path_Planning_2023a_BlueI_B.b_absxk *
                                 APF_Path_Planning_2023a_BlueI_B.wr[APF_Path_Planning_2023a_BlueI_B.d_i]
                                 <= 1.0020841800044864E-292)) ||
                    ((APF_Path_Planning_2023a_BlueI_B.b_absxk > 1.0) &&
                     (APF_Path_Planning_2023a_BlueI_B.wr[APF_Path_Planning_2023a_BlueI_B.d_i]
                      > 1.0) &&
                     (APF_Path_Planning_2023a_BlueI_B.wr[APF_Path_Planning_2023a_BlueI_B.d_i]
                      >= 9.9792015476736E+291 /
                      APF_Path_Planning_2023a_BlueI_B.b_absxk))) {
                } else {
                  APF_Path_Planning_2023a_BlueI_B.c = 1.0 /
                    APF_Path_Planning_2023a_BlueI_B.b_absxk;
                  APF_Path_Planning_2023a_BlueI_B.wr[APF_Path_Planning_2023a_BlueI_B.d_i]
                    *= APF_Path_Planning_2023a_BlueI_B.b_absxk;
                  APF_Path_Planning_2023a_BlueI_B.ica =
                    APF_Path_Planning_2023a_BlueI_B.d_iy + 1;
                  APF_Path_Planning_2023a_BlueI_B.d_iy = ((6 -
                    APF_Path_Planning_2023a_BlueI_B.b_k) * 6 +
                    APF_Path_Planning_2023a_BlueI_B.d_iy) + 1;
                  for (APF_Path_Planning_2023a_BlueI_B.ira =
                       APF_Path_Planning_2023a_BlueI_B.ica;
                       APF_Path_Planning_2023a_BlueI_B.ira <=
                       APF_Path_Planning_2023a_BlueI_B.d_iy;
                       APF_Path_Planning_2023a_BlueI_B.ira += 6) {
                    APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.ira
                      - 1] *= APF_Path_Planning_2023a_BlueI_B.c;
                  }

                  APF_Path_Planning_2023a_BlueI_B.d_iy =
                    APF_Path_Planning_2023a_BlueI_B.kend +
                    APF_Path_Planning_2023a_BlueI_B.i_h2;
                  for (APF_Path_Planning_2023a_BlueI_B.ica =
                       APF_Path_Planning_2023a_BlueI_B.kend + 1;
                       APF_Path_Planning_2023a_BlueI_B.ica <=
                       APF_Path_Planning_2023a_BlueI_B.d_iy;
                       APF_Path_Planning_2023a_BlueI_B.ica++) {
                    APF_Path_Planning_2023a_BlueI_B.b_A_p[APF_Path_Planning_2023a_BlueI_B.ica
                      - 1] *= APF_Path_Planning_2023a_BlueI_B.b_absxk;
                  }

                  APF_Path_Planning_2023a_BlueI_B.notdone = false;
                }

                APF_Path_Planning_2023a_BlueI_B.d_i++;
              }
            }
          } else {
            exitg3 = 1;
          }
        } while (exitg3 == 0);

        if (exitg3 == 1) {
        } else {
          exitg1 = true;
        }
      }
    }

    APF_Path_Planning_2023a_xzgehrd(APF_Path_Planning_2023a_BlueI_B.b_A_p,
      APF_Path_Planning_2023a_BlueI_B.b_k, APF_Path_Planning_2023a_BlueI_B.i_h2);
    APF_Path_Planning_2023a_xdlahqr(APF_Path_Planning_2023a_BlueI_B.b_k,
      APF_Path_Planning_2023a_BlueI_B.i_h2,
      APF_Path_Planning_2023a_BlueI_B.b_A_p,
      &APF_Path_Planning_2023a_BlueI_B.d_i, &APF_Path_Planning_2023a_BlueI_B.c,
      APF_Path_Planning_2023a_BlueI_B.wr, APF_Path_Planning_2023a_BlueI_B.wi_l);
    if (APF_Path_Planning_2023a_BlueI_B.scalea) {
      APF_Path_Planning_202_xzlascl_f(APF_Path_Planning_2023a_BlueI_B.absxk_j,
        APF_Path_Planning_2023a_BlueI_B.anrm_b, 6 -
        APF_Path_Planning_2023a_BlueI_B.d_i, APF_Path_Planning_2023a_BlueI_B.wr,
        APF_Path_Planning_2023a_BlueI_B.d_i + 1);
      APF_Path_Planning_202_xzlascl_f(APF_Path_Planning_2023a_BlueI_B.absxk_j,
        APF_Path_Planning_2023a_BlueI_B.anrm_b, 6 -
        APF_Path_Planning_2023a_BlueI_B.d_i,
        APF_Path_Planning_2023a_BlueI_B.wi_l,
        APF_Path_Planning_2023a_BlueI_B.d_i + 1);
      if (APF_Path_Planning_2023a_BlueI_B.d_i != 0) {
        APF_Path_Planning_202_xzlascl_f(APF_Path_Planning_2023a_BlueI_B.absxk_j,
          APF_Path_Planning_2023a_BlueI_B.anrm_b,
          APF_Path_Planning_2023a_BlueI_B.b_k - 1,
          APF_Path_Planning_2023a_BlueI_B.wr, 1);
        APF_Path_Planning_202_xzlascl_f(APF_Path_Planning_2023a_BlueI_B.absxk_j,
          APF_Path_Planning_2023a_BlueI_B.anrm_b,
          APF_Path_Planning_2023a_BlueI_B.b_k - 1,
          APF_Path_Planning_2023a_BlueI_B.wi_l, 1);
      }
    }

    if (APF_Path_Planning_2023a_BlueI_B.d_i != 0) {
      for (APF_Path_Planning_2023a_BlueI_B.i_h2 =
           APF_Path_Planning_2023a_BlueI_B.b_k;
           APF_Path_Planning_2023a_BlueI_B.i_h2 <=
           APF_Path_Planning_2023a_BlueI_B.d_i;
           APF_Path_Planning_2023a_BlueI_B.i_h2++) {
        APF_Path_Planning_2023a_BlueI_B.wr[APF_Path_Planning_2023a_BlueI_B.i_h2
          - 1] = (rtNaN);
        APF_Path_Planning_2023a_BlueI_B.wi_l[APF_Path_Planning_2023a_BlueI_B.i_h2
          - 1] = 0.0;
      }
    }

    for (APF_Path_Planning_2023a_BlueI_B.i_h2 = 0;
         APF_Path_Planning_2023a_BlueI_B.i_h2 < 6;
         APF_Path_Planning_2023a_BlueI_B.i_h2++) {
      V[APF_Path_Planning_2023a_BlueI_B.i_h2].re =
        APF_Path_Planning_2023a_BlueI_B.wr[APF_Path_Planning_2023a_BlueI_B.i_h2];
      V[APF_Path_Planning_2023a_BlueI_B.i_h2].im =
        APF_Path_Planning_2023a_BlueI_B.wi_l[APF_Path_Planning_2023a_BlueI_B.i_h2];
    }
  }
}

// Function for MATLAB Function: '<S356>/MATLAB Function'
static void APF_Path_Planning_20_xzlascl_fe(real_T cfrom, real_T cto, int32_T
  b_m, real_T A[5], int32_T iA0)
{
  APF_Path_Planning_2023a_BlueI_B.cfromc_p = cfrom;
  APF_Path_Planning_2023a_BlueI_B.ctoc_a = cto;
  APF_Path_Planning_2023a_BlueI_B.notdone_i = true;
  while (APF_Path_Planning_2023a_BlueI_B.notdone_i) {
    APF_Path_Planning_2023a_BlueI_B.cfrom1_e =
      APF_Path_Planning_2023a_BlueI_B.cfromc_p * 2.0041683600089728E-292;
    APF_Path_Planning_2023a_BlueI_B.cto1_a =
      APF_Path_Planning_2023a_BlueI_B.ctoc_a / 4.9896007738368E+291;
    if ((fabs(APF_Path_Planning_2023a_BlueI_B.cfrom1_e) > fabs
         (APF_Path_Planning_2023a_BlueI_B.ctoc_a)) &&
        (APF_Path_Planning_2023a_BlueI_B.ctoc_a != 0.0)) {
      APF_Path_Planning_2023a_BlueI_B.mul_a = 2.0041683600089728E-292;
      APF_Path_Planning_2023a_BlueI_B.cfromc_p =
        APF_Path_Planning_2023a_BlueI_B.cfrom1_e;
    } else if (fabs(APF_Path_Planning_2023a_BlueI_B.cto1_a) > fabs
               (APF_Path_Planning_2023a_BlueI_B.cfromc_p)) {
      APF_Path_Planning_2023a_BlueI_B.mul_a = 4.9896007738368E+291;
      APF_Path_Planning_2023a_BlueI_B.ctoc_a =
        APF_Path_Planning_2023a_BlueI_B.cto1_a;
    } else {
      APF_Path_Planning_2023a_BlueI_B.mul_a =
        APF_Path_Planning_2023a_BlueI_B.ctoc_a /
        APF_Path_Planning_2023a_BlueI_B.cfromc_p;
      APF_Path_Planning_2023a_BlueI_B.notdone_i = false;
    }

    for (APF_Path_Planning_2023a_BlueI_B.b_i_e = 0;
         APF_Path_Planning_2023a_BlueI_B.b_i_e < b_m;
         APF_Path_Planning_2023a_BlueI_B.b_i_e++) {
      APF_Path_Planning_2023a_BlueI_B.i2 =
        (APF_Path_Planning_2023a_BlueI_B.b_i_e + iA0) - 1;
      A[APF_Path_Planning_2023a_BlueI_B.i2] *=
        APF_Path_Planning_2023a_BlueI_B.mul_a;
    }
  }
}

// Function for MATLAB Function: '<S356>/MATLAB Function'
static void APF_Path_Planning_2023a_xdlaev2(real_T a, real_T b, real_T c, real_T
  *rt1, real_T *rt2)
{
  APF_Path_Planning_2023a_BlueI_B.sm = a + c;
  APF_Path_Planning_2023a_BlueI_B.adf = fabs(a - c);
  APF_Path_Planning_2023a_BlueI_B.ab = fabs(b + b);
  if (fabs(a) > fabs(c)) {
    APF_Path_Planning_2023a_BlueI_B.acmx = a;
    APF_Path_Planning_2023a_BlueI_B.acmn = c;
  } else {
    APF_Path_Planning_2023a_BlueI_B.acmx = c;
    APF_Path_Planning_2023a_BlueI_B.acmn = a;
  }

  if (APF_Path_Planning_2023a_BlueI_B.adf > APF_Path_Planning_2023a_BlueI_B.ab)
  {
    APF_Path_Planning_2023a_BlueI_B.ab /= APF_Path_Planning_2023a_BlueI_B.adf;
    APF_Path_Planning_2023a_BlueI_B.adf *= sqrt
      (APF_Path_Planning_2023a_BlueI_B.ab * APF_Path_Planning_2023a_BlueI_B.ab +
       1.0);
  } else if (APF_Path_Planning_2023a_BlueI_B.adf <
             APF_Path_Planning_2023a_BlueI_B.ab) {
    APF_Path_Planning_2023a_BlueI_B.adf /= APF_Path_Planning_2023a_BlueI_B.ab;
    APF_Path_Planning_2023a_BlueI_B.adf = sqrt
      (APF_Path_Planning_2023a_BlueI_B.adf * APF_Path_Planning_2023a_BlueI_B.adf
       + 1.0) * APF_Path_Planning_2023a_BlueI_B.ab;
  } else {
    APF_Path_Planning_2023a_BlueI_B.adf = APF_Path_Planning_2023a_BlueI_B.ab *
      1.4142135623730951;
  }

  if (APF_Path_Planning_2023a_BlueI_B.sm < 0.0) {
    *rt1 = (APF_Path_Planning_2023a_BlueI_B.sm -
            APF_Path_Planning_2023a_BlueI_B.adf) * 0.5;
    *rt2 = APF_Path_Planning_2023a_BlueI_B.acmx / *rt1 *
      APF_Path_Planning_2023a_BlueI_B.acmn - b / *rt1 * b;
  } else if (APF_Path_Planning_2023a_BlueI_B.sm > 0.0) {
    *rt1 = (APF_Path_Planning_2023a_BlueI_B.sm +
            APF_Path_Planning_2023a_BlueI_B.adf) * 0.5;
    *rt2 = APF_Path_Planning_2023a_BlueI_B.acmx / *rt1 *
      APF_Path_Planning_2023a_BlueI_B.acmn - b / *rt1 * b;
  } else {
    *rt1 = 0.5 * APF_Path_Planning_2023a_BlueI_B.adf;
    *rt2 = -0.5 * APF_Path_Planning_2023a_BlueI_B.adf;
  }
}

// Function for MATLAB Function: '<S356>/MATLAB Function'
static void APF_Path_Planning_insertionsort(real_T x[6], int32_T xstart, int32_T
  xend)
{
  for (APF_Path_Planning_2023a_BlueI_B.k_af = xstart + 1;
       APF_Path_Planning_2023a_BlueI_B.k_af <= xend;
       APF_Path_Planning_2023a_BlueI_B.k_af++) {
    boolean_T exitg1;
    APF_Path_Planning_2023a_BlueI_B.xc = x[APF_Path_Planning_2023a_BlueI_B.k_af
      - 1];
    APF_Path_Planning_2023a_BlueI_B.idx = APF_Path_Planning_2023a_BlueI_B.k_af -
      1;
    exitg1 = false;
    while ((!exitg1) && (APF_Path_Planning_2023a_BlueI_B.idx >= xstart)) {
      APF_Path_Planning_2023a_BlueI_B.d = x[APF_Path_Planning_2023a_BlueI_B.idx
        - 1];
      if (APF_Path_Planning_2023a_BlueI_B.xc < APF_Path_Planning_2023a_BlueI_B.d)
      {
        x[APF_Path_Planning_2023a_BlueI_B.idx] =
          APF_Path_Planning_2023a_BlueI_B.d;
        APF_Path_Planning_2023a_BlueI_B.idx--;
      } else {
        exitg1 = true;
      }
    }

    x[APF_Path_Planning_2023a_BlueI_B.idx] = APF_Path_Planning_2023a_BlueI_B.xc;
  }
}

// Function for MATLAB Function: '<S356>/MATLAB Function'
static int32_T APF_Path_Planning_2023a_xdsterf(real_T d[6], real_T e[5])
{
  int32_T exitg1;
  int32_T exitg3;
  int32_T exitg4;
  int32_T info;
  boolean_T exitg2;
  info = 0;
  APF_Path_Planning_2023a_BlueI_B.jtot = 0;
  APF_Path_Planning_2023a_BlueI_B.l1 = 1;
  do {
    exitg1 = 0;
    if (APF_Path_Planning_2023a_BlueI_B.l1 > 6) {
      APF_Path_Planning_insertionsort(d, 1, 6);
      exitg1 = 1;
    } else {
      if (APF_Path_Planning_2023a_BlueI_B.l1 > 1) {
        e[APF_Path_Planning_2023a_BlueI_B.l1 - 2] = 0.0;
      }

      APF_Path_Planning_2023a_BlueI_B.b_m_b = APF_Path_Planning_2023a_BlueI_B.l1;
      exitg2 = false;
      while ((!exitg2) && (APF_Path_Planning_2023a_BlueI_B.b_m_b < 6)) {
        if (fabs(e[APF_Path_Planning_2023a_BlueI_B.b_m_b - 1]) <= sqrt(fabs
             (d[APF_Path_Planning_2023a_BlueI_B.b_m_b - 1])) * sqrt(fabs
             (d[APF_Path_Planning_2023a_BlueI_B.b_m_b])) *
            2.2204460492503131E-16) {
          e[APF_Path_Planning_2023a_BlueI_B.b_m_b - 1] = 0.0;
          exitg2 = true;
        } else {
          APF_Path_Planning_2023a_BlueI_B.b_m_b++;
        }
      }

      APF_Path_Planning_2023a_BlueI_B.l_a = APF_Path_Planning_2023a_BlueI_B.l1;
      APF_Path_Planning_2023a_BlueI_B.lsv = APF_Path_Planning_2023a_BlueI_B.l1;
      APF_Path_Planning_2023a_BlueI_B.lend =
        APF_Path_Planning_2023a_BlueI_B.b_m_b;
      APF_Path_Planning_2023a_BlueI_B.lendsv_tmp =
        APF_Path_Planning_2023a_BlueI_B.b_m_b + 1;
      APF_Path_Planning_2023a_BlueI_B.l1 = APF_Path_Planning_2023a_BlueI_B.b_m_b
        + 1;
      if (APF_Path_Planning_2023a_BlueI_B.b_m_b ==
          APF_Path_Planning_2023a_BlueI_B.l_a) {
      } else {
        APF_Path_Planning_2023a_BlueI_B.n_tmp =
          APF_Path_Planning_2023a_BlueI_B.b_m_b -
          APF_Path_Planning_2023a_BlueI_B.l_a;
        if (APF_Path_Planning_2023a_BlueI_B.n_tmp + 1 <= 0) {
          APF_Path_Planning_2023a_BlueI_B.anorm = 0.0;
        } else {
          APF_Path_Planning_2023a_BlueI_B.anorm = fabs(d
            [(APF_Path_Planning_2023a_BlueI_B.l_a +
              APF_Path_Planning_2023a_BlueI_B.n_tmp) - 1]);
          APF_Path_Planning_2023a_BlueI_B.iscale = -1;
          exitg2 = false;
          while ((!exitg2) && (APF_Path_Planning_2023a_BlueI_B.iscale + 1 <=
                               APF_Path_Planning_2023a_BlueI_B.n_tmp - 1)) {
            APF_Path_Planning_2023a_BlueI_B.b_anorm_tmp =
              APF_Path_Planning_2023a_BlueI_B.l_a +
              APF_Path_Planning_2023a_BlueI_B.iscale;
            APF_Path_Planning_2023a_BlueI_B.b_anorm = fabs
              (d[APF_Path_Planning_2023a_BlueI_B.b_anorm_tmp]);
            if (rtIsNaN(APF_Path_Planning_2023a_BlueI_B.b_anorm)) {
              APF_Path_Planning_2023a_BlueI_B.anorm = (rtNaN);
              exitg2 = true;
            } else {
              if (APF_Path_Planning_2023a_BlueI_B.b_anorm >
                  APF_Path_Planning_2023a_BlueI_B.anorm) {
                APF_Path_Planning_2023a_BlueI_B.anorm =
                  APF_Path_Planning_2023a_BlueI_B.b_anorm;
              }

              APF_Path_Planning_2023a_BlueI_B.b_anorm = fabs
                (e[APF_Path_Planning_2023a_BlueI_B.b_anorm_tmp]);
              if (rtIsNaN(APF_Path_Planning_2023a_BlueI_B.b_anorm)) {
                APF_Path_Planning_2023a_BlueI_B.anorm = (rtNaN);
                exitg2 = true;
              } else {
                if (APF_Path_Planning_2023a_BlueI_B.b_anorm >
                    APF_Path_Planning_2023a_BlueI_B.anorm) {
                  APF_Path_Planning_2023a_BlueI_B.anorm =
                    APF_Path_Planning_2023a_BlueI_B.b_anorm;
                }

                APF_Path_Planning_2023a_BlueI_B.iscale++;
              }
            }
          }
        }

        if (APF_Path_Planning_2023a_BlueI_B.anorm == 0.0) {
        } else {
          APF_Path_Planning_2023a_BlueI_B.iscale = 0;
          if (APF_Path_Planning_2023a_BlueI_B.anorm > 2.2346346549904327E+153) {
            APF_Path_Planning_2023a_BlueI_B.iscale = 1;
            APF_Path_Planning_202_xzlascl_f
              (APF_Path_Planning_2023a_BlueI_B.anorm, 2.2346346549904327E+153,
               APF_Path_Planning_2023a_BlueI_B.n_tmp + 1, d,
               APF_Path_Planning_2023a_BlueI_B.l_a);
            APF_Path_Planning_20_xzlascl_fe
              (APF_Path_Planning_2023a_BlueI_B.anorm, 2.2346346549904327E+153,
               APF_Path_Planning_2023a_BlueI_B.n_tmp, e,
               APF_Path_Planning_2023a_BlueI_B.l_a);
          } else if (APF_Path_Planning_2023a_BlueI_B.anorm <
                     3.02546243347603E-123) {
            APF_Path_Planning_2023a_BlueI_B.iscale = 2;
            APF_Path_Planning_202_xzlascl_f
              (APF_Path_Planning_2023a_BlueI_B.anorm, 3.02546243347603E-123,
               APF_Path_Planning_2023a_BlueI_B.n_tmp + 1, d,
               APF_Path_Planning_2023a_BlueI_B.l_a);
            APF_Path_Planning_20_xzlascl_fe
              (APF_Path_Planning_2023a_BlueI_B.anorm, 3.02546243347603E-123,
               APF_Path_Planning_2023a_BlueI_B.n_tmp, e,
               APF_Path_Planning_2023a_BlueI_B.l_a);
          }

          for (APF_Path_Planning_2023a_BlueI_B.n_tmp =
               APF_Path_Planning_2023a_BlueI_B.l_a;
               APF_Path_Planning_2023a_BlueI_B.n_tmp <
               APF_Path_Planning_2023a_BlueI_B.b_m_b;
               APF_Path_Planning_2023a_BlueI_B.n_tmp++) {
            APF_Path_Planning_2023a_BlueI_B.rte =
              e[APF_Path_Planning_2023a_BlueI_B.n_tmp - 1];
            e[APF_Path_Planning_2023a_BlueI_B.n_tmp - 1] =
              APF_Path_Planning_2023a_BlueI_B.rte *
              APF_Path_Planning_2023a_BlueI_B.rte;
          }

          if (fabs(d[APF_Path_Planning_2023a_BlueI_B.b_m_b - 1]) < fabs
              (d[APF_Path_Planning_2023a_BlueI_B.l_a - 1])) {
            APF_Path_Planning_2023a_BlueI_B.lend =
              APF_Path_Planning_2023a_BlueI_B.lsv;
            APF_Path_Planning_2023a_BlueI_B.l_a =
              APF_Path_Planning_2023a_BlueI_B.b_m_b;
          }

          if (APF_Path_Planning_2023a_BlueI_B.lend >=
              APF_Path_Planning_2023a_BlueI_B.l_a) {
            do {
              exitg4 = 0;
              if (APF_Path_Planning_2023a_BlueI_B.l_a !=
                  APF_Path_Planning_2023a_BlueI_B.lend) {
                APF_Path_Planning_2023a_BlueI_B.b_m_b =
                  APF_Path_Planning_2023a_BlueI_B.l_a;
                while ((APF_Path_Planning_2023a_BlueI_B.b_m_b <
                        APF_Path_Planning_2023a_BlueI_B.lend) && (!(fabs
                         (e[APF_Path_Planning_2023a_BlueI_B.b_m_b - 1]) <= fabs
                         (d[APF_Path_Planning_2023a_BlueI_B.b_m_b - 1]) *
                         4.9303806576313238E-32 * fabs
                         (d[APF_Path_Planning_2023a_BlueI_B.b_m_b])))) {
                  APF_Path_Planning_2023a_BlueI_B.b_m_b++;
                }
              } else {
                APF_Path_Planning_2023a_BlueI_B.b_m_b =
                  APF_Path_Planning_2023a_BlueI_B.lend;
              }

              if (APF_Path_Planning_2023a_BlueI_B.b_m_b <
                  APF_Path_Planning_2023a_BlueI_B.lend) {
                e[APF_Path_Planning_2023a_BlueI_B.b_m_b - 1] = 0.0;
              }

              if (APF_Path_Planning_2023a_BlueI_B.b_m_b ==
                  APF_Path_Planning_2023a_BlueI_B.l_a) {
                APF_Path_Planning_2023a_BlueI_B.l_a++;
                if (APF_Path_Planning_2023a_BlueI_B.l_a >
                    APF_Path_Planning_2023a_BlueI_B.lend) {
                  exitg4 = 1;
                }
              } else if (APF_Path_Planning_2023a_BlueI_B.l_a + 1 ==
                         APF_Path_Planning_2023a_BlueI_B.b_m_b) {
                APF_Path_Planning_2023a_xdlaev2
                  (d[APF_Path_Planning_2023a_BlueI_B.l_a - 1], sqrt
                   (e[APF_Path_Planning_2023a_BlueI_B.l_a - 1]),
                   d[APF_Path_Planning_2023a_BlueI_B.l_a],
                   &d[APF_Path_Planning_2023a_BlueI_B.l_a - 1],
                   &APF_Path_Planning_2023a_BlueI_B.b_anorm);
                d[APF_Path_Planning_2023a_BlueI_B.l_a] =
                  APF_Path_Planning_2023a_BlueI_B.b_anorm;
                e[APF_Path_Planning_2023a_BlueI_B.l_a - 1] = 0.0;
                APF_Path_Planning_2023a_BlueI_B.l_a += 2;
                if (APF_Path_Planning_2023a_BlueI_B.l_a >
                    APF_Path_Planning_2023a_BlueI_B.lend) {
                  exitg4 = 1;
                }
              } else if (APF_Path_Planning_2023a_BlueI_B.jtot == 180) {
                exitg4 = 1;
              } else {
                APF_Path_Planning_2023a_BlueI_B.jtot++;
                APF_Path_Planning_2023a_BlueI_B.rte = sqrt
                  (e[APF_Path_Planning_2023a_BlueI_B.l_a - 1]);
                APF_Path_Planning_2023a_BlueI_B.c_c =
                  d[APF_Path_Planning_2023a_BlueI_B.l_a - 1];
                APF_Path_Planning_2023a_BlueI_B.b_anorm =
                  (d[APF_Path_Planning_2023a_BlueI_B.l_a] -
                   APF_Path_Planning_2023a_BlueI_B.c_c) / (2.0 *
                  APF_Path_Planning_2023a_BlueI_B.rte);
                APF_Path_Planning_2023a_BlueI_B.s_p =
                  APF_Path_Planning_rt_hypotd_snf
                  (APF_Path_Planning_2023a_BlueI_B.b_anorm, 1.0);
                if (!(APF_Path_Planning_2023a_BlueI_B.b_anorm >= 0.0)) {
                  APF_Path_Planning_2023a_BlueI_B.s_p =
                    -APF_Path_Planning_2023a_BlueI_B.s_p;
                }

                APF_Path_Planning_2023a_BlueI_B.b_anorm =
                  APF_Path_Planning_2023a_BlueI_B.c_c -
                  APF_Path_Planning_2023a_BlueI_B.rte /
                  (APF_Path_Planning_2023a_BlueI_B.b_anorm +
                   APF_Path_Planning_2023a_BlueI_B.s_p);
                APF_Path_Planning_2023a_BlueI_B.c_c = 1.0;
                APF_Path_Planning_2023a_BlueI_B.s_p = 0.0;
                APF_Path_Planning_2023a_BlueI_B.b_gamma =
                  d[APF_Path_Planning_2023a_BlueI_B.b_m_b - 1] -
                  APF_Path_Planning_2023a_BlueI_B.b_anorm;
                APF_Path_Planning_2023a_BlueI_B.p_h =
                  APF_Path_Planning_2023a_BlueI_B.b_gamma *
                  APF_Path_Planning_2023a_BlueI_B.b_gamma;
                for (APF_Path_Planning_2023a_BlueI_B.n_tmp =
                     APF_Path_Planning_2023a_BlueI_B.b_m_b - 1;
                     APF_Path_Planning_2023a_BlueI_B.n_tmp >=
                     APF_Path_Planning_2023a_BlueI_B.l_a;
                     APF_Path_Planning_2023a_BlueI_B.n_tmp--) {
                  APF_Path_Planning_2023a_BlueI_B.rte =
                    e[APF_Path_Planning_2023a_BlueI_B.n_tmp - 1];
                  APF_Path_Planning_2023a_BlueI_B.r_c =
                    APF_Path_Planning_2023a_BlueI_B.p_h +
                    APF_Path_Planning_2023a_BlueI_B.rte;
                  if (APF_Path_Planning_2023a_BlueI_B.b_m_b - 1 !=
                      APF_Path_Planning_2023a_BlueI_B.n_tmp) {
                    e[APF_Path_Planning_2023a_BlueI_B.n_tmp] =
                      APF_Path_Planning_2023a_BlueI_B.s_p *
                      APF_Path_Planning_2023a_BlueI_B.r_c;
                  }

                  APF_Path_Planning_2023a_BlueI_B.oldc =
                    APF_Path_Planning_2023a_BlueI_B.c_c;
                  APF_Path_Planning_2023a_BlueI_B.c_c =
                    APF_Path_Planning_2023a_BlueI_B.p_h /
                    APF_Path_Planning_2023a_BlueI_B.r_c;
                  APF_Path_Planning_2023a_BlueI_B.s_p =
                    APF_Path_Planning_2023a_BlueI_B.rte /
                    APF_Path_Planning_2023a_BlueI_B.r_c;
                  APF_Path_Planning_2023a_BlueI_B.p_h =
                    APF_Path_Planning_2023a_BlueI_B.b_gamma;
                  APF_Path_Planning_2023a_BlueI_B.r_c =
                    d[APF_Path_Planning_2023a_BlueI_B.n_tmp - 1];
                  APF_Path_Planning_2023a_BlueI_B.b_gamma =
                    (APF_Path_Planning_2023a_BlueI_B.r_c -
                     APF_Path_Planning_2023a_BlueI_B.b_anorm) *
                    APF_Path_Planning_2023a_BlueI_B.c_c -
                    APF_Path_Planning_2023a_BlueI_B.s_p *
                    APF_Path_Planning_2023a_BlueI_B.b_gamma;
                  d[APF_Path_Planning_2023a_BlueI_B.n_tmp] =
                    (APF_Path_Planning_2023a_BlueI_B.r_c -
                     APF_Path_Planning_2023a_BlueI_B.b_gamma) +
                    APF_Path_Planning_2023a_BlueI_B.p_h;
                  if (APF_Path_Planning_2023a_BlueI_B.c_c != 0.0) {
                    APF_Path_Planning_2023a_BlueI_B.p_h =
                      APF_Path_Planning_2023a_BlueI_B.b_gamma *
                      APF_Path_Planning_2023a_BlueI_B.b_gamma /
                      APF_Path_Planning_2023a_BlueI_B.c_c;
                  } else {
                    APF_Path_Planning_2023a_BlueI_B.p_h =
                      APF_Path_Planning_2023a_BlueI_B.oldc *
                      APF_Path_Planning_2023a_BlueI_B.rte;
                  }
                }

                e[APF_Path_Planning_2023a_BlueI_B.l_a - 1] =
                  APF_Path_Planning_2023a_BlueI_B.s_p *
                  APF_Path_Planning_2023a_BlueI_B.p_h;
                d[APF_Path_Planning_2023a_BlueI_B.l_a - 1] =
                  APF_Path_Planning_2023a_BlueI_B.b_anorm +
                  APF_Path_Planning_2023a_BlueI_B.b_gamma;
              }
            } while (exitg4 == 0);
          } else {
            do {
              exitg3 = 0;
              APF_Path_Planning_2023a_BlueI_B.b_m_b =
                APF_Path_Planning_2023a_BlueI_B.l_a;
              while ((APF_Path_Planning_2023a_BlueI_B.b_m_b >
                      APF_Path_Planning_2023a_BlueI_B.lend) && (!(fabs
                       (e[APF_Path_Planning_2023a_BlueI_B.b_m_b - 2]) <= fabs
                       (d[APF_Path_Planning_2023a_BlueI_B.b_m_b - 1]) *
                       4.9303806576313238E-32 * fabs
                       (d[APF_Path_Planning_2023a_BlueI_B.b_m_b - 2])))) {
                APF_Path_Planning_2023a_BlueI_B.b_m_b--;
              }

              if (APF_Path_Planning_2023a_BlueI_B.b_m_b >
                  APF_Path_Planning_2023a_BlueI_B.lend) {
                e[APF_Path_Planning_2023a_BlueI_B.b_m_b - 2] = 0.0;
              }

              if (APF_Path_Planning_2023a_BlueI_B.b_m_b ==
                  APF_Path_Planning_2023a_BlueI_B.l_a) {
                APF_Path_Planning_2023a_BlueI_B.l_a--;
                if (APF_Path_Planning_2023a_BlueI_B.l_a <
                    APF_Path_Planning_2023a_BlueI_B.lend) {
                  exitg3 = 1;
                }
              } else if (APF_Path_Planning_2023a_BlueI_B.l_a - 1 ==
                         APF_Path_Planning_2023a_BlueI_B.b_m_b) {
                APF_Path_Planning_2023a_xdlaev2
                  (d[APF_Path_Planning_2023a_BlueI_B.l_a - 1], sqrt
                   (e[APF_Path_Planning_2023a_BlueI_B.l_a - 2]),
                   d[APF_Path_Planning_2023a_BlueI_B.l_a - 2],
                   &d[APF_Path_Planning_2023a_BlueI_B.l_a - 1],
                   &APF_Path_Planning_2023a_BlueI_B.b_anorm);
                d[APF_Path_Planning_2023a_BlueI_B.l_a - 2] =
                  APF_Path_Planning_2023a_BlueI_B.b_anorm;
                e[APF_Path_Planning_2023a_BlueI_B.l_a - 2] = 0.0;
                APF_Path_Planning_2023a_BlueI_B.l_a -= 2;
                if (APF_Path_Planning_2023a_BlueI_B.l_a <
                    APF_Path_Planning_2023a_BlueI_B.lend) {
                  exitg3 = 1;
                }
              } else if (APF_Path_Planning_2023a_BlueI_B.jtot == 180) {
                exitg3 = 1;
              } else {
                APF_Path_Planning_2023a_BlueI_B.jtot++;
                APF_Path_Planning_2023a_BlueI_B.rte = sqrt
                  (e[APF_Path_Planning_2023a_BlueI_B.l_a - 2]);
                APF_Path_Planning_2023a_BlueI_B.c_c =
                  d[APF_Path_Planning_2023a_BlueI_B.l_a - 1];
                APF_Path_Planning_2023a_BlueI_B.b_anorm =
                  (d[APF_Path_Planning_2023a_BlueI_B.l_a - 2] -
                   APF_Path_Planning_2023a_BlueI_B.c_c) / (2.0 *
                  APF_Path_Planning_2023a_BlueI_B.rte);
                APF_Path_Planning_2023a_BlueI_B.s_p =
                  APF_Path_Planning_rt_hypotd_snf
                  (APF_Path_Planning_2023a_BlueI_B.b_anorm, 1.0);
                if (!(APF_Path_Planning_2023a_BlueI_B.b_anorm >= 0.0)) {
                  APF_Path_Planning_2023a_BlueI_B.s_p =
                    -APF_Path_Planning_2023a_BlueI_B.s_p;
                }

                APF_Path_Planning_2023a_BlueI_B.b_anorm =
                  APF_Path_Planning_2023a_BlueI_B.c_c -
                  APF_Path_Planning_2023a_BlueI_B.rte /
                  (APF_Path_Planning_2023a_BlueI_B.b_anorm +
                   APF_Path_Planning_2023a_BlueI_B.s_p);
                APF_Path_Planning_2023a_BlueI_B.c_c = 1.0;
                APF_Path_Planning_2023a_BlueI_B.s_p = 0.0;
                APF_Path_Planning_2023a_BlueI_B.b_gamma =
                  d[APF_Path_Planning_2023a_BlueI_B.b_m_b - 1] -
                  APF_Path_Planning_2023a_BlueI_B.b_anorm;
                APF_Path_Planning_2023a_BlueI_B.p_h =
                  APF_Path_Planning_2023a_BlueI_B.b_gamma *
                  APF_Path_Planning_2023a_BlueI_B.b_gamma;
                for (APF_Path_Planning_2023a_BlueI_B.n_tmp =
                     APF_Path_Planning_2023a_BlueI_B.b_m_b;
                     APF_Path_Planning_2023a_BlueI_B.n_tmp <
                     APF_Path_Planning_2023a_BlueI_B.l_a;
                     APF_Path_Planning_2023a_BlueI_B.n_tmp++) {
                  APF_Path_Planning_2023a_BlueI_B.rte =
                    e[APF_Path_Planning_2023a_BlueI_B.n_tmp - 1];
                  APF_Path_Planning_2023a_BlueI_B.r_c =
                    APF_Path_Planning_2023a_BlueI_B.p_h +
                    APF_Path_Planning_2023a_BlueI_B.rte;
                  if (APF_Path_Planning_2023a_BlueI_B.n_tmp !=
                      APF_Path_Planning_2023a_BlueI_B.b_m_b) {
                    e[APF_Path_Planning_2023a_BlueI_B.n_tmp - 2] =
                      APF_Path_Planning_2023a_BlueI_B.s_p *
                      APF_Path_Planning_2023a_BlueI_B.r_c;
                  }

                  APF_Path_Planning_2023a_BlueI_B.oldc =
                    APF_Path_Planning_2023a_BlueI_B.c_c;
                  APF_Path_Planning_2023a_BlueI_B.c_c =
                    APF_Path_Planning_2023a_BlueI_B.p_h /
                    APF_Path_Planning_2023a_BlueI_B.r_c;
                  APF_Path_Planning_2023a_BlueI_B.s_p =
                    APF_Path_Planning_2023a_BlueI_B.rte /
                    APF_Path_Planning_2023a_BlueI_B.r_c;
                  APF_Path_Planning_2023a_BlueI_B.p_h =
                    APF_Path_Planning_2023a_BlueI_B.b_gamma;
                  APF_Path_Planning_2023a_BlueI_B.b_gamma =
                    (d[APF_Path_Planning_2023a_BlueI_B.n_tmp] -
                     APF_Path_Planning_2023a_BlueI_B.b_anorm) *
                    APF_Path_Planning_2023a_BlueI_B.c_c -
                    APF_Path_Planning_2023a_BlueI_B.s_p *
                    APF_Path_Planning_2023a_BlueI_B.b_gamma;
                  d[APF_Path_Planning_2023a_BlueI_B.n_tmp - 1] =
                    (d[APF_Path_Planning_2023a_BlueI_B.n_tmp] -
                     APF_Path_Planning_2023a_BlueI_B.b_gamma) +
                    APF_Path_Planning_2023a_BlueI_B.p_h;
                  if (APF_Path_Planning_2023a_BlueI_B.c_c != 0.0) {
                    APF_Path_Planning_2023a_BlueI_B.p_h =
                      APF_Path_Planning_2023a_BlueI_B.b_gamma *
                      APF_Path_Planning_2023a_BlueI_B.b_gamma /
                      APF_Path_Planning_2023a_BlueI_B.c_c;
                  } else {
                    APF_Path_Planning_2023a_BlueI_B.p_h =
                      APF_Path_Planning_2023a_BlueI_B.oldc *
                      APF_Path_Planning_2023a_BlueI_B.rte;
                  }
                }

                e[APF_Path_Planning_2023a_BlueI_B.l_a - 2] =
                  APF_Path_Planning_2023a_BlueI_B.s_p *
                  APF_Path_Planning_2023a_BlueI_B.p_h;
                d[APF_Path_Planning_2023a_BlueI_B.l_a - 1] =
                  APF_Path_Planning_2023a_BlueI_B.b_anorm +
                  APF_Path_Planning_2023a_BlueI_B.b_gamma;
              }
            } while (exitg3 == 0);
          }

          switch (APF_Path_Planning_2023a_BlueI_B.iscale) {
           case 1:
            APF_Path_Planning_202_xzlascl_f(2.2346346549904327E+153,
              APF_Path_Planning_2023a_BlueI_B.anorm,
              APF_Path_Planning_2023a_BlueI_B.lendsv_tmp -
              APF_Path_Planning_2023a_BlueI_B.lsv, d,
              APF_Path_Planning_2023a_BlueI_B.lsv);
            break;

           case 2:
            APF_Path_Planning_202_xzlascl_f(3.02546243347603E-123,
              APF_Path_Planning_2023a_BlueI_B.anorm,
              APF_Path_Planning_2023a_BlueI_B.lendsv_tmp -
              APF_Path_Planning_2023a_BlueI_B.lsv, d,
              APF_Path_Planning_2023a_BlueI_B.lsv);
            break;
          }

          if (APF_Path_Planning_2023a_BlueI_B.jtot >= 180) {
            for (APF_Path_Planning_2023a_BlueI_B.jtot = 0;
                 APF_Path_Planning_2023a_BlueI_B.jtot < 5;
                 APF_Path_Planning_2023a_BlueI_B.jtot++) {
              if (e[APF_Path_Planning_2023a_BlueI_B.jtot] != 0.0) {
                info++;
              }
            }

            exitg1 = 1;
          }
        }
      }
    }
  } while (exitg1 == 0);

  return info;
}

// Function for MATLAB Function: '<S356>/MATLAB Function'
static void APF_Path_Planning_2023a_Blu_eig(const real_T A[36], creal_T V[6])
{
  int32_T exitg1;
  boolean_T exitg2;
  APF_Path_Planning_2023a_BlueI_B.iscale_i = true;
  for (APF_Path_Planning_2023a_BlueI_B.k = 0; APF_Path_Planning_2023a_BlueI_B.k <
       36; APF_Path_Planning_2023a_BlueI_B.k++) {
    if (APF_Path_Planning_2023a_BlueI_B.iscale_i) {
      APF_Path_Planning_2023a_BlueI_B.anrm = A[APF_Path_Planning_2023a_BlueI_B.k];
      if (rtIsInf(APF_Path_Planning_2023a_BlueI_B.anrm) || rtIsNaN
          (APF_Path_Planning_2023a_BlueI_B.anrm)) {
        APF_Path_Planning_2023a_BlueI_B.iscale_i = false;
      }
    }
  }

  if (!APF_Path_Planning_2023a_BlueI_B.iscale_i) {
    for (APF_Path_Planning_2023a_BlueI_B.i_h = 0;
         APF_Path_Planning_2023a_BlueI_B.i_h < 6;
         APF_Path_Planning_2023a_BlueI_B.i_h++) {
      V[APF_Path_Planning_2023a_BlueI_B.i_h].re = (rtNaN);
      V[APF_Path_Planning_2023a_BlueI_B.i_h].im = 0.0;
    }
  } else {
    APF_Path_Planning_2023a_BlueI_B.iscale_i = true;
    APF_Path_Planning_2023a_BlueI_B.k = 0;
    exitg2 = false;
    while ((!exitg2) && (APF_Path_Planning_2023a_BlueI_B.k < 6)) {
      APF_Path_Planning_2023a_BlueI_B.i_h = 0;
      do {
        exitg1 = 0;
        if (APF_Path_Planning_2023a_BlueI_B.i_h <=
            APF_Path_Planning_2023a_BlueI_B.k) {
          if (!(A[6 * APF_Path_Planning_2023a_BlueI_B.k +
                APF_Path_Planning_2023a_BlueI_B.i_h] == A[6 *
                APF_Path_Planning_2023a_BlueI_B.i_h +
                APF_Path_Planning_2023a_BlueI_B.k])) {
            APF_Path_Planning_2023a_BlueI_B.iscale_i = false;
            exitg1 = 1;
          } else {
            APF_Path_Planning_2023a_BlueI_B.i_h++;
          }
        } else {
          APF_Path_Planning_2023a_BlueI_B.k++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    if (APF_Path_Planning_2023a_BlueI_B.iscale_i) {
      memcpy(&APF_Path_Planning_2023a_BlueI_B.b_A[0], &A[0], 36U * sizeof(real_T));
      APF_Path_Planning_2023a_BlueI_B.anrm = 0.0;
      APF_Path_Planning_2023a_BlueI_B.k = 0;
      exitg2 = false;
      while ((!exitg2) && (APF_Path_Planning_2023a_BlueI_B.k < 6)) {
        APF_Path_Planning_2023a_BlueI_B.i_h = 0;
        do {
          exitg1 = 0;
          if (APF_Path_Planning_2023a_BlueI_B.i_h <=
              APF_Path_Planning_2023a_BlueI_B.k) {
            APF_Path_Planning_2023a_BlueI_B.absx = fabs(A[6 *
              APF_Path_Planning_2023a_BlueI_B.k +
              APF_Path_Planning_2023a_BlueI_B.i_h]);
            if (rtIsNaN(APF_Path_Planning_2023a_BlueI_B.absx)) {
              APF_Path_Planning_2023a_BlueI_B.anrm = (rtNaN);
              exitg1 = 1;
            } else {
              if (APF_Path_Planning_2023a_BlueI_B.absx >
                  APF_Path_Planning_2023a_BlueI_B.anrm) {
                APF_Path_Planning_2023a_BlueI_B.anrm =
                  APF_Path_Planning_2023a_BlueI_B.absx;
              }

              APF_Path_Planning_2023a_BlueI_B.i_h++;
            }
          } else {
            APF_Path_Planning_2023a_BlueI_B.k++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }

      if (rtIsInf(APF_Path_Planning_2023a_BlueI_B.anrm) || rtIsNaN
          (APF_Path_Planning_2023a_BlueI_B.anrm)) {
        for (APF_Path_Planning_2023a_BlueI_B.i_h = 0;
             APF_Path_Planning_2023a_BlueI_B.i_h < 6;
             APF_Path_Planning_2023a_BlueI_B.i_h++) {
          APF_Path_Planning_2023a_BlueI_B.a__3[APF_Path_Planning_2023a_BlueI_B.i_h]
            = (rtNaN);
        }
      } else {
        APF_Path_Planning_2023a_BlueI_B.iscale_i = false;
        if ((APF_Path_Planning_2023a_BlueI_B.anrm > 0.0) &&
            (APF_Path_Planning_2023a_BlueI_B.anrm < 1.0010415475915505E-146)) {
          APF_Path_Planning_2023a_BlueI_B.iscale_i = true;
          APF_Path_Planning_2023a_BlueI_B.anrm = 1.0010415475915505E-146 /
            APF_Path_Planning_2023a_BlueI_B.anrm;
          APF_Path_Planning_2023a_xzlascl(1.0,
            APF_Path_Planning_2023a_BlueI_B.anrm,
            APF_Path_Planning_2023a_BlueI_B.b_A);
        } else if (APF_Path_Planning_2023a_BlueI_B.anrm >
                   9.9895953610111751E+145) {
          APF_Path_Planning_2023a_BlueI_B.iscale_i = true;
          APF_Path_Planning_2023a_BlueI_B.anrm = 9.9895953610111751E+145 /
            APF_Path_Planning_2023a_BlueI_B.anrm;
          APF_Path_Planning_2023a_xzlascl(1.0,
            APF_Path_Planning_2023a_BlueI_B.anrm,
            APF_Path_Planning_2023a_BlueI_B.b_A);
        }

        for (APF_Path_Planning_2023a_BlueI_B.k = 0;
             APF_Path_Planning_2023a_BlueI_B.k < 5;
             APF_Path_Planning_2023a_BlueI_B.k++) {
          APF_Path_Planning_2023a_BlueI_B.i_h = 6 *
            APF_Path_Planning_2023a_BlueI_B.k +
            APF_Path_Planning_2023a_BlueI_B.k;
          APF_Path_Planning_2023a_BlueI_B.e_d[APF_Path_Planning_2023a_BlueI_B.k]
            =
            APF_Path_Planning_2023a_BlueI_B.b_A[APF_Path_Planning_2023a_BlueI_B.i_h
            + 1];
          if (APF_Path_Planning_2023a_BlueI_B.k + 3 <= 6) {
            APF_Path_Planning_2023a_BlueI_B.c_i =
              APF_Path_Planning_2023a_BlueI_B.k + 3;
          } else {
            APF_Path_Planning_2023a_BlueI_B.c_i = 6;
          }

          APF_Path_Planning_2023a_BlueI_B.absx = APF_Path_Planning_2023a_xzlarfg
            (5 - APF_Path_Planning_2023a_BlueI_B.k,
             &APF_Path_Planning_2023a_BlueI_B.e_d[APF_Path_Planning_2023a_BlueI_B.k],
             APF_Path_Planning_2023a_BlueI_B.b_A,
             APF_Path_Planning_2023a_BlueI_B.k * 6 +
             APF_Path_Planning_2023a_BlueI_B.c_i);
          if (APF_Path_Planning_2023a_BlueI_B.absx != 0.0) {
            APF_Path_Planning_2023a_BlueI_B.b_A[APF_Path_Planning_2023a_BlueI_B.i_h
              + 1] = 1.0;
            for (APF_Path_Planning_2023a_BlueI_B.c_i =
                 APF_Path_Planning_2023a_BlueI_B.k + 1;
                 APF_Path_Planning_2023a_BlueI_B.c_i < 6;
                 APF_Path_Planning_2023a_BlueI_B.c_i++) {
              APF_Path_Planning_2023a_BlueI_B.tau[APF_Path_Planning_2023a_BlueI_B.c_i
                - 1] = 0.0;
            }

            APF_Path_Planning_2023a_BlueI_B.c_i = 4 -
              APF_Path_Planning_2023a_BlueI_B.k;
            APF_Path_Planning_2023a_BlueI_B.d_tmp = 5 -
              APF_Path_Planning_2023a_BlueI_B.k;
            for (APF_Path_Planning_2023a_BlueI_B.b_jj = 0;
                 APF_Path_Planning_2023a_BlueI_B.b_jj <=
                 APF_Path_Planning_2023a_BlueI_B.c_i;
                 APF_Path_Planning_2023a_BlueI_B.b_jj++) {
              APF_Path_Planning_2023a_BlueI_B.temp1_tmp =
                APF_Path_Planning_2023a_BlueI_B.k +
                APF_Path_Planning_2023a_BlueI_B.b_jj;
              APF_Path_Planning_2023a_BlueI_B.temp1 =
                APF_Path_Planning_2023a_BlueI_B.b_A[(6 *
                APF_Path_Planning_2023a_BlueI_B.k +
                APF_Path_Planning_2023a_BlueI_B.temp1_tmp) + 1] *
                APF_Path_Planning_2023a_BlueI_B.absx;
              APF_Path_Planning_2023a_BlueI_B.temp2 = 0.0;
              APF_Path_Planning_2023a_BlueI_B.tau_tmp_l =
                (APF_Path_Planning_2023a_BlueI_B.temp1_tmp + 1) * 6 +
                APF_Path_Planning_2023a_BlueI_B.k;
              APF_Path_Planning_2023a_BlueI_B.tau[APF_Path_Planning_2023a_BlueI_B.temp1_tmp]
                += APF_Path_Planning_2023a_BlueI_B.b_A
                [(APF_Path_Planning_2023a_BlueI_B.tau_tmp_l +
                  APF_Path_Planning_2023a_BlueI_B.b_jj) + 1] *
                APF_Path_Planning_2023a_BlueI_B.temp1;
              for (APF_Path_Planning_2023a_BlueI_B.ii =
                   APF_Path_Planning_2023a_BlueI_B.b_jj + 2;
                   APF_Path_Planning_2023a_BlueI_B.ii <=
                   APF_Path_Planning_2023a_BlueI_B.d_tmp;
                   APF_Path_Planning_2023a_BlueI_B.ii++) {
                APF_Path_Planning_2023a_BlueI_B.tau_tmp_tmp =
                  APF_Path_Planning_2023a_BlueI_B.k +
                  APF_Path_Planning_2023a_BlueI_B.ii;
                APF_Path_Planning_2023a_BlueI_B.tau_tmp =
                  APF_Path_Planning_2023a_BlueI_B.b_A[APF_Path_Planning_2023a_BlueI_B.tau_tmp_l
                  + APF_Path_Planning_2023a_BlueI_B.ii];
                APF_Path_Planning_2023a_BlueI_B.tau[APF_Path_Planning_2023a_BlueI_B.tau_tmp_tmp
                  - 1] += APF_Path_Planning_2023a_BlueI_B.tau_tmp *
                  APF_Path_Planning_2023a_BlueI_B.temp1;
                APF_Path_Planning_2023a_BlueI_B.temp2 +=
                  APF_Path_Planning_2023a_BlueI_B.b_A[6 *
                  APF_Path_Planning_2023a_BlueI_B.k +
                  APF_Path_Planning_2023a_BlueI_B.tau_tmp_tmp] *
                  APF_Path_Planning_2023a_BlueI_B.tau_tmp;
              }

              APF_Path_Planning_2023a_BlueI_B.tau[APF_Path_Planning_2023a_BlueI_B.temp1_tmp]
                += APF_Path_Planning_2023a_BlueI_B.absx *
                APF_Path_Planning_2023a_BlueI_B.temp2;
            }

            APF_Path_Planning_2023a_BlueI_B.temp1 = 0.0;
            for (APF_Path_Planning_2023a_BlueI_B.temp1_tmp = 0;
                 APF_Path_Planning_2023a_BlueI_B.temp1_tmp <
                 APF_Path_Planning_2023a_BlueI_B.d_tmp;
                 APF_Path_Planning_2023a_BlueI_B.temp1_tmp++) {
              APF_Path_Planning_2023a_BlueI_B.temp1 +=
                APF_Path_Planning_2023a_BlueI_B.b_A
                [(APF_Path_Planning_2023a_BlueI_B.i_h +
                  APF_Path_Planning_2023a_BlueI_B.temp1_tmp) + 1] *
                APF_Path_Planning_2023a_BlueI_B.tau[APF_Path_Planning_2023a_BlueI_B.k
                + APF_Path_Planning_2023a_BlueI_B.temp1_tmp];
            }

            APF_Path_Planning_2023a_BlueI_B.temp1 *= -0.5 *
              APF_Path_Planning_2023a_BlueI_B.absx;
            if (!(APF_Path_Planning_2023a_BlueI_B.temp1 == 0.0)) {
              for (APF_Path_Planning_2023a_BlueI_B.temp1_tmp = 0;
                   APF_Path_Planning_2023a_BlueI_B.temp1_tmp <
                   APF_Path_Planning_2023a_BlueI_B.d_tmp;
                   APF_Path_Planning_2023a_BlueI_B.temp1_tmp++) {
                APF_Path_Planning_2023a_BlueI_B.tau_tmp_l =
                  APF_Path_Planning_2023a_BlueI_B.k +
                  APF_Path_Planning_2023a_BlueI_B.temp1_tmp;
                APF_Path_Planning_2023a_BlueI_B.tau[APF_Path_Planning_2023a_BlueI_B.tau_tmp_l]
                  += APF_Path_Planning_2023a_BlueI_B.b_A
                  [(APF_Path_Planning_2023a_BlueI_B.i_h +
                    APF_Path_Planning_2023a_BlueI_B.temp1_tmp) + 1] *
                  APF_Path_Planning_2023a_BlueI_B.temp1;
              }
            }

            for (APF_Path_Planning_2023a_BlueI_B.tau_tmp_l = 0;
                 APF_Path_Planning_2023a_BlueI_B.tau_tmp_l <=
                 APF_Path_Planning_2023a_BlueI_B.c_i;
                 APF_Path_Planning_2023a_BlueI_B.tau_tmp_l++) {
              APF_Path_Planning_2023a_BlueI_B.temp1_tmp =
                APF_Path_Planning_2023a_BlueI_B.k +
                APF_Path_Planning_2023a_BlueI_B.tau_tmp_l;
              APF_Path_Planning_2023a_BlueI_B.temp1 =
                APF_Path_Planning_2023a_BlueI_B.b_A[(6 *
                APF_Path_Planning_2023a_BlueI_B.k +
                APF_Path_Planning_2023a_BlueI_B.temp1_tmp) + 1];
              APF_Path_Planning_2023a_BlueI_B.temp2 =
                APF_Path_Planning_2023a_BlueI_B.tau[APF_Path_Planning_2023a_BlueI_B.temp1_tmp];
              APF_Path_Planning_2023a_BlueI_B.tau_tmp =
                APF_Path_Planning_2023a_BlueI_B.temp2 *
                APF_Path_Planning_2023a_BlueI_B.temp1;
              APF_Path_Planning_2023a_BlueI_B.b_jj =
                (APF_Path_Planning_2023a_BlueI_B.temp1_tmp + 1) * 6;
              APF_Path_Planning_2023a_BlueI_B.ii =
                APF_Path_Planning_2023a_BlueI_B.b_jj +
                APF_Path_Planning_2023a_BlueI_B.k;
              APF_Path_Planning_2023a_BlueI_B.b_A
                [(APF_Path_Planning_2023a_BlueI_B.temp1_tmp +
                  APF_Path_Planning_2023a_BlueI_B.b_jj) + 1] =
                (APF_Path_Planning_2023a_BlueI_B.b_A
                 [(APF_Path_Planning_2023a_BlueI_B.ii +
                   APF_Path_Planning_2023a_BlueI_B.tau_tmp_l) + 1] -
                 APF_Path_Planning_2023a_BlueI_B.tau_tmp) -
                APF_Path_Planning_2023a_BlueI_B.tau_tmp;
              for (APF_Path_Planning_2023a_BlueI_B.temp1_tmp =
                   APF_Path_Planning_2023a_BlueI_B.tau_tmp_l + 2;
                   APF_Path_Planning_2023a_BlueI_B.temp1_tmp <=
                   APF_Path_Planning_2023a_BlueI_B.d_tmp;
                   APF_Path_Planning_2023a_BlueI_B.temp1_tmp++) {
                APF_Path_Planning_2023a_BlueI_B.tau_tmp_tmp =
                  APF_Path_Planning_2023a_BlueI_B.k +
                  APF_Path_Planning_2023a_BlueI_B.temp1_tmp;
                APF_Path_Planning_2023a_BlueI_B.b_A[APF_Path_Planning_2023a_BlueI_B.tau_tmp_tmp
                  + APF_Path_Planning_2023a_BlueI_B.b_jj] =
                  (APF_Path_Planning_2023a_BlueI_B.b_A[APF_Path_Planning_2023a_BlueI_B.ii
                   + APF_Path_Planning_2023a_BlueI_B.temp1_tmp] -
                   APF_Path_Planning_2023a_BlueI_B.tau[APF_Path_Planning_2023a_BlueI_B.tau_tmp_tmp
                   - 1] * APF_Path_Planning_2023a_BlueI_B.temp1) -
                  APF_Path_Planning_2023a_BlueI_B.b_A[6 *
                  APF_Path_Planning_2023a_BlueI_B.k +
                  APF_Path_Planning_2023a_BlueI_B.tau_tmp_tmp] *
                  APF_Path_Planning_2023a_BlueI_B.temp2;
              }
            }
          }

          APF_Path_Planning_2023a_BlueI_B.b_A[APF_Path_Planning_2023a_BlueI_B.i_h
            + 1] =
            APF_Path_Planning_2023a_BlueI_B.e_d[APF_Path_Planning_2023a_BlueI_B.k];
          APF_Path_Planning_2023a_BlueI_B.a__3[APF_Path_Planning_2023a_BlueI_B.k]
            =
            APF_Path_Planning_2023a_BlueI_B.b_A[APF_Path_Planning_2023a_BlueI_B.i_h];
          APF_Path_Planning_2023a_BlueI_B.tau[APF_Path_Planning_2023a_BlueI_B.k]
            = APF_Path_Planning_2023a_BlueI_B.absx;
        }

        APF_Path_Planning_2023a_BlueI_B.a__3[5] =
          APF_Path_Planning_2023a_BlueI_B.b_A[35];
        APF_Path_Planning_2023a_BlueI_B.k = APF_Path_Planning_2023a_xdsterf
          (APF_Path_Planning_2023a_BlueI_B.a__3,
           APF_Path_Planning_2023a_BlueI_B.e_d);
        if (APF_Path_Planning_2023a_BlueI_B.k != 0) {
          for (APF_Path_Planning_2023a_BlueI_B.i_h = 0;
               APF_Path_Planning_2023a_BlueI_B.i_h < 6;
               APF_Path_Planning_2023a_BlueI_B.i_h++) {
            APF_Path_Planning_2023a_BlueI_B.a__3[APF_Path_Planning_2023a_BlueI_B.i_h]
              = (rtNaN);
          }
        } else if (APF_Path_Planning_2023a_BlueI_B.iscale_i) {
          APF_Path_Planning_2023a_BlueI_B.anrm = 1.0 /
            APF_Path_Planning_2023a_BlueI_B.anrm;
          for (APF_Path_Planning_2023a_BlueI_B.k = 0;
               APF_Path_Planning_2023a_BlueI_B.k < 6;
               APF_Path_Planning_2023a_BlueI_B.k++) {
            APF_Path_Planning_2023a_BlueI_B.a__3[APF_Path_Planning_2023a_BlueI_B.k]
              *= APF_Path_Planning_2023a_BlueI_B.anrm;
          }
        }
      }

      for (APF_Path_Planning_2023a_BlueI_B.i_h = 0;
           APF_Path_Planning_2023a_BlueI_B.i_h < 6;
           APF_Path_Planning_2023a_BlueI_B.i_h++) {
        V[APF_Path_Planning_2023a_BlueI_B.i_h].re =
          APF_Path_Planning_2023a_BlueI_B.a__3[APF_Path_Planning_2023a_BlueI_B.i_h];
        V[APF_Path_Planning_2023a_BlueI_B.i_h].im = 0.0;
      }
    } else {
      APF_Path_Planning_2023a_BlueI_B.iscale_i = true;
      APF_Path_Planning_2023a_BlueI_B.k = 0;
      exitg2 = false;
      while ((!exitg2) && (APF_Path_Planning_2023a_BlueI_B.k < 6)) {
        APF_Path_Planning_2023a_BlueI_B.i_h = 0;
        do {
          exitg1 = 0;
          if (APF_Path_Planning_2023a_BlueI_B.i_h <=
              APF_Path_Planning_2023a_BlueI_B.k) {
            if (!(A[6 * APF_Path_Planning_2023a_BlueI_B.k +
                  APF_Path_Planning_2023a_BlueI_B.i_h] == -A[6 *
                  APF_Path_Planning_2023a_BlueI_B.i_h +
                  APF_Path_Planning_2023a_BlueI_B.k])) {
              APF_Path_Planning_2023a_BlueI_B.iscale_i = false;
              exitg1 = 1;
            } else {
              APF_Path_Planning_2023a_BlueI_B.i_h++;
            }
          } else {
            APF_Path_Planning_2023a_BlueI_B.k++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }

      if (APF_Path_Planning_2023a_BlueI_B.iscale_i) {
        memcpy(&APF_Path_Planning_2023a_BlueI_B.b_A[0], &A[0], 36U * sizeof
               (real_T));
        APF_Path_Planning_2023a_xzgehrd(APF_Path_Planning_2023a_BlueI_B.b_A, 1,
          6);
        APF_Path_Planning_2023a_xdlahqr(1, 6,
          APF_Path_Planning_2023a_BlueI_B.b_A,
          &APF_Path_Planning_2023a_BlueI_B.k,
          &APF_Path_Planning_2023a_BlueI_B.anrm,
          APF_Path_Planning_2023a_BlueI_B.a__3,
          APF_Path_Planning_2023a_BlueI_B.wi);
        APF_Path_Planning_2023a_BlueI_B.i_h = static_cast<uint8_T>
          (APF_Path_Planning_2023a_BlueI_B.k);
        for (APF_Path_Planning_2023a_BlueI_B.c_i = 0;
             APF_Path_Planning_2023a_BlueI_B.c_i <
             APF_Path_Planning_2023a_BlueI_B.i_h;
             APF_Path_Planning_2023a_BlueI_B.c_i++) {
          V[APF_Path_Planning_2023a_BlueI_B.c_i].re = (rtNaN);
          V[APF_Path_Planning_2023a_BlueI_B.c_i].im = 0.0;
        }

        for (APF_Path_Planning_2023a_BlueI_B.i_h =
             APF_Path_Planning_2023a_BlueI_B.k + 1;
             APF_Path_Planning_2023a_BlueI_B.i_h < 7;
             APF_Path_Planning_2023a_BlueI_B.i_h++) {
          V[APF_Path_Planning_2023a_BlueI_B.i_h - 1].re = 0.0;
          V[APF_Path_Planning_2023a_BlueI_B.i_h - 1].im =
            APF_Path_Planning_2023a_BlueI_B.wi[APF_Path_Planning_2023a_BlueI_B.i_h
            - 1];
        }
      } else {
        APF_Path_Planning_2_eigStandard(A, V);
      }
    }
  }
}

static void APF_Path_Plann_binary_expand_op(real_T in1_data[], int32_T in1_size
  [2], const real_T in2[36], int32_T in3, int32_T in4)
{
  // Outputs for IfAction SubSystem: '<Root>/Phase #3: Experiment' incorporates:
  //   ActionPort: '<S9>/Action Port'

  // Outputs for IfAction SubSystem: '<S9>/Change RED Behavior' incorporates:
  //   ActionPort: '<S89>/Action Port'

  // Outputs for IfAction SubSystem: '<S89>/Sub-Phase #4' incorporates:
  //   ActionPort: '<S247>/Action Port'

  // If: '<S89>/Experiment Sub-Phases' incorporates:
  //   If: '<Root>/Separate Phases'
  //   If: '<S9>/This IF block determines whether or not to run the RED sim//exp '
  //   MATLAB Function: '<S356>/MATLAB Function'

  if (in4 < 1) {
    APF_Path_Planning_2023a_BlueI_B.i5 = -1;
  } else {
    APF_Path_Planning_2023a_BlueI_B.i5 = in4 - 1;
  }

  if (in4 < 1) {
    APF_Path_Planning_2023a_BlueI_B.stride_1_1 = -1;
  } else {
    APF_Path_Planning_2023a_BlueI_B.stride_1_1 = in4 - 1;
  }

  in1_size[0] = 1;
  APF_Path_Planning_2023a_BlueI_B.loop_ub_o =
    APF_Path_Planning_2023a_BlueI_B.stride_1_1 + 1 == 1 ?
    APF_Path_Planning_2023a_BlueI_B.i5 + 1 :
    APF_Path_Planning_2023a_BlueI_B.stride_1_1 + 1;
  in1_size[1] = APF_Path_Planning_2023a_BlueI_B.loop_ub_o;
  APF_Path_Planning_2023a_BlueI_B.stride_0_1 =
    (APF_Path_Planning_2023a_BlueI_B.i5 + 1 != 1);
  APF_Path_Planning_2023a_BlueI_B.stride_1_1 =
    (APF_Path_Planning_2023a_BlueI_B.stride_1_1 + 1 != 1);
  for (APF_Path_Planning_2023a_BlueI_B.i5 = 0;
       APF_Path_Planning_2023a_BlueI_B.i5 <
       APF_Path_Planning_2023a_BlueI_B.loop_ub_o;
       APF_Path_Planning_2023a_BlueI_B.i5++) {
    in1_data[APF_Path_Planning_2023a_BlueI_B.i5] =
      in2[APF_Path_Planning_2023a_BlueI_B.i5 *
      APF_Path_Planning_2023a_BlueI_B.stride_0_1 * 6 + in3] *
      in2[APF_Path_Planning_2023a_BlueI_B.i5 *
      APF_Path_Planning_2023a_BlueI_B.stride_1_1 * 6 + in4];
  }

  // End of If: '<S89>/Experiment Sub-Phases'
  // End of Outputs for SubSystem: '<S89>/Sub-Phase #4'
  // End of Outputs for SubSystem: '<S9>/Change RED Behavior'
  // End of Outputs for SubSystem: '<Root>/Phase #3: Experiment'
}

static real_T APF_Path_Planning_rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      APF_Path_Planning_2023a_BlueI_B.i9 = 1;
    } else {
      APF_Path_Planning_2023a_BlueI_B.i9 = -1;
    }

    if (u1 > 0.0) {
      APF_Path_Planning_2023a_BlueI_B.i10 = 1;
    } else {
      APF_Path_Planning_2023a_BlueI_B.i10 = -1;
    }

    y = atan2(static_cast<real_T>(APF_Path_Planning_2023a_BlueI_B.i9),
              static_cast<real_T>(APF_Path_Planning_2023a_BlueI_B.i10));
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

static real_T APF_Path_Planning_2_rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    APF_Path_Planning_2023a_BlueI_B.d1 = fabs(u0);
    APF_Path_Planning_2023a_BlueI_B.d2 = fabs(u1);
    if (rtIsInf(u1)) {
      if (APF_Path_Planning_2023a_BlueI_B.d1 == 1.0) {
        y = 1.0;
      } else if (APF_Path_Planning_2023a_BlueI_B.d1 > 1.0) {
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
    } else if (APF_Path_Planning_2023a_BlueI_B.d2 == 0.0) {
      y = 1.0;
    } else if (APF_Path_Planning_2023a_BlueI_B.d2 == 1.0) {
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

  APF_Path_Planning_2023a_BlueI_B.lo = *u % 127773U * 16807U;
  APF_Path_Planning_2023a_BlueI_B.hi = *u / 127773U * 2836U;
  if (APF_Path_Planning_2023a_BlueI_B.lo < APF_Path_Planning_2023a_BlueI_B.hi) {
    *u = 2147483647U - (APF_Path_Planning_2023a_BlueI_B.hi -
                        APF_Path_Planning_2023a_BlueI_B.lo);
  } else {
    *u = APF_Path_Planning_2023a_BlueI_B.lo - APF_Path_Planning_2023a_BlueI_B.hi;
  }

  return static_cast<real_T>(*u) * 4.6566128752457969E-10;
}

static real_T APF__rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;

  // Normal (Gaussian) random number generator
  do {
    APF_Path_Planning_2023a_BlueI_B.sr = 2.0 * APF__rt_urand_Upu32_Yd_f_pw_snf(u)
      - 1.0;
    APF_Path_Planning_2023a_BlueI_B.si = 2.0 * APF__rt_urand_Upu32_Yd_f_pw_snf(u)
      - 1.0;
    APF_Path_Planning_2023a_BlueI_B.si = APF_Path_Planning_2023a_BlueI_B.sr *
      APF_Path_Planning_2023a_BlueI_B.sr + APF_Path_Planning_2023a_BlueI_B.si *
      APF_Path_Planning_2023a_BlueI_B.si;
  } while (APF_Path_Planning_2023a_BlueI_B.si > 1.0);

  y = sqrt(-2.0 * log(APF_Path_Planning_2023a_BlueI_B.si) /
           APF_Path_Planning_2023a_BlueI_B.si) *
    APF_Path_Planning_2023a_BlueI_B.sr;
  return y;
}

// Function for MATLAB Function: '<S582>/Dynamics Model'
static real_T APF_Path_Planning_2023a_B_xnrm2(int32_T n, const real_T x[36],
  int32_T ix0)
{
  real_T y;
  y = 0.0;
  APF_Path_Planning_2023a_BlueI_B.scale_g = 3.3121686421112381E-170;
  APF_Path_Planning_2023a_BlueI_B.kend_ei = (ix0 + n) - 1;
  for (APF_Path_Planning_2023a_BlueI_B.k_c = ix0;
       APF_Path_Planning_2023a_BlueI_B.k_c <=
       APF_Path_Planning_2023a_BlueI_B.kend_ei;
       APF_Path_Planning_2023a_BlueI_B.k_c++) {
    APF_Path_Planning_2023a_BlueI_B.absxk_c = fabs
      (x[APF_Path_Planning_2023a_BlueI_B.k_c - 1]);
    if (APF_Path_Planning_2023a_BlueI_B.absxk_c >
        APF_Path_Planning_2023a_BlueI_B.scale_g) {
      APF_Path_Planning_2023a_BlueI_B.t_o =
        APF_Path_Planning_2023a_BlueI_B.scale_g /
        APF_Path_Planning_2023a_BlueI_B.absxk_c;
      y = y * APF_Path_Planning_2023a_BlueI_B.t_o *
        APF_Path_Planning_2023a_BlueI_B.t_o + 1.0;
      APF_Path_Planning_2023a_BlueI_B.scale_g =
        APF_Path_Planning_2023a_BlueI_B.absxk_c;
    } else {
      APF_Path_Planning_2023a_BlueI_B.t_o =
        APF_Path_Planning_2023a_BlueI_B.absxk_c /
        APF_Path_Planning_2023a_BlueI_B.scale_g;
      y += APF_Path_Planning_2023a_BlueI_B.t_o *
        APF_Path_Planning_2023a_BlueI_B.t_o;
    }
  }

  return APF_Path_Planning_2023a_BlueI_B.scale_g * sqrt(y);
}

// Function for MATLAB Function: '<S582>/Dynamics Model'
static real_T APF_Path_Planning_2023a_B_xdotc(int32_T n, const real_T x[36],
  int32_T ix0, const real_T y[36], int32_T iy0)
{
  real_T d;
  d = 0.0;
  APF_Path_Planning_2023a_BlueI_B.b_l = static_cast<uint8_T>(n);
  for (APF_Path_Planning_2023a_BlueI_B.k_pe = 0;
       APF_Path_Planning_2023a_BlueI_B.k_pe <
       APF_Path_Planning_2023a_BlueI_B.b_l; APF_Path_Planning_2023a_BlueI_B.k_pe
       ++) {
    d += x[(ix0 + APF_Path_Planning_2023a_BlueI_B.k_pe) - 1] * y[(iy0 +
      APF_Path_Planning_2023a_BlueI_B.k_pe) - 1];
  }

  return d;
}

// Function for MATLAB Function: '<S582>/Dynamics Model'
static void APF_Path_Planning_2023a_B_xaxpy(int32_T n, real_T a, int32_T ix0,
  real_T y[36], int32_T iy0)
{
  if (!(a == 0.0)) {
    for (APF_Path_Planning_2023a_BlueI_B.k_n = 0;
         APF_Path_Planning_2023a_BlueI_B.k_n < n;
         APF_Path_Planning_2023a_BlueI_B.k_n++) {
      APF_Path_Planning_2023a_BlueI_B.i6 = (iy0 +
        APF_Path_Planning_2023a_BlueI_B.k_n) - 1;
      y[APF_Path_Planning_2023a_BlueI_B.i6] += y[(ix0 +
        APF_Path_Planning_2023a_BlueI_B.k_n) - 1] * a;
    }
  }
}

// Function for MATLAB Function: '<S582>/Dynamics Model'
static real_T APF_Path_Planning_2023a_xnrm2_c(int32_T n, const real_T x[6],
  int32_T ix0)
{
  real_T y;
  y = 0.0;
  APF_Path_Planning_2023a_BlueI_B.scale_f = 3.3121686421112381E-170;
  APF_Path_Planning_2023a_BlueI_B.kend_f = (ix0 + n) - 1;
  for (APF_Path_Planning_2023a_BlueI_B.k_h = ix0;
       APF_Path_Planning_2023a_BlueI_B.k_h <=
       APF_Path_Planning_2023a_BlueI_B.kend_f;
       APF_Path_Planning_2023a_BlueI_B.k_h++) {
    APF_Path_Planning_2023a_BlueI_B.absxk_i = fabs
      (x[APF_Path_Planning_2023a_BlueI_B.k_h - 1]);
    if (APF_Path_Planning_2023a_BlueI_B.absxk_i >
        APF_Path_Planning_2023a_BlueI_B.scale_f) {
      APF_Path_Planning_2023a_BlueI_B.t_ff =
        APF_Path_Planning_2023a_BlueI_B.scale_f /
        APF_Path_Planning_2023a_BlueI_B.absxk_i;
      y = y * APF_Path_Planning_2023a_BlueI_B.t_ff *
        APF_Path_Planning_2023a_BlueI_B.t_ff + 1.0;
      APF_Path_Planning_2023a_BlueI_B.scale_f =
        APF_Path_Planning_2023a_BlueI_B.absxk_i;
    } else {
      APF_Path_Planning_2023a_BlueI_B.t_ff =
        APF_Path_Planning_2023a_BlueI_B.absxk_i /
        APF_Path_Planning_2023a_BlueI_B.scale_f;
      y += APF_Path_Planning_2023a_BlueI_B.t_ff *
        APF_Path_Planning_2023a_BlueI_B.t_ff;
    }
  }

  return APF_Path_Planning_2023a_BlueI_B.scale_f * sqrt(y);
}

// Function for MATLAB Function: '<S582>/Dynamics Model'
static void APF_Path_Planning_2023a_xaxpy_j(int32_T n, real_T a, const real_T x
  [36], int32_T ix0, real_T y[6], int32_T iy0)
{
  if (!(a == 0.0)) {
    for (APF_Path_Planning_2023a_BlueI_B.k_f = 0;
         APF_Path_Planning_2023a_BlueI_B.k_f < n;
         APF_Path_Planning_2023a_BlueI_B.k_f++) {
      APF_Path_Planning_2023a_BlueI_B.i8 = (iy0 +
        APF_Path_Planning_2023a_BlueI_B.k_f) - 1;
      y[APF_Path_Planning_2023a_BlueI_B.i8] += x[(ix0 +
        APF_Path_Planning_2023a_BlueI_B.k_f) - 1] * a;
    }
  }
}

// Function for MATLAB Function: '<S582>/Dynamics Model'
static void APF_Path_Planning_2023_xaxpy_jv(int32_T n, real_T a, const real_T x
  [6], int32_T ix0, real_T y[36], int32_T iy0)
{
  if (!(a == 0.0)) {
    for (APF_Path_Planning_2023a_BlueI_B.k_pt = 0;
         APF_Path_Planning_2023a_BlueI_B.k_pt < n;
         APF_Path_Planning_2023a_BlueI_B.k_pt++) {
      APF_Path_Planning_2023a_BlueI_B.i7 = (iy0 +
        APF_Path_Planning_2023a_BlueI_B.k_pt) - 1;
      y[APF_Path_Planning_2023a_BlueI_B.i7] += x[(ix0 +
        APF_Path_Planning_2023a_BlueI_B.k_pt) - 1] * a;
    }
  }
}

// Function for MATLAB Function: '<S582>/Dynamics Model'
static void APF_Path_Planning_2023a_B_xswap(real_T x[36], int32_T ix0, int32_T
  iy0)
{
  for (APF_Path_Planning_2023a_BlueI_B.k_p = 0;
       APF_Path_Planning_2023a_BlueI_B.k_p < 6;
       APF_Path_Planning_2023a_BlueI_B.k_p++) {
    APF_Path_Planning_2023a_BlueI_B.temp_tmp_m = (ix0 +
      APF_Path_Planning_2023a_BlueI_B.k_p) - 1;
    APF_Path_Planning_2023a_BlueI_B.temp_f =
      x[APF_Path_Planning_2023a_BlueI_B.temp_tmp_m];
    APF_Path_Planning_2023a_BlueI_B.i4 = (iy0 +
      APF_Path_Planning_2023a_BlueI_B.k_p) - 1;
    x[APF_Path_Planning_2023a_BlueI_B.temp_tmp_m] =
      x[APF_Path_Planning_2023a_BlueI_B.i4];
    x[APF_Path_Planning_2023a_BlueI_B.i4] =
      APF_Path_Planning_2023a_BlueI_B.temp_f;
  }
}

// Function for MATLAB Function: '<S582>/Dynamics Model'
static void APF_Path_Planning_2023a_B_xrotg(real_T *a, real_T *b, real_T *c,
  real_T *s)
{
  APF_Path_Planning_2023a_BlueI_B.roe = *b;
  APF_Path_Planning_2023a_BlueI_B.absa = fabs(*a);
  APF_Path_Planning_2023a_BlueI_B.absb = fabs(*b);
  if (APF_Path_Planning_2023a_BlueI_B.absa >
      APF_Path_Planning_2023a_BlueI_B.absb) {
    APF_Path_Planning_2023a_BlueI_B.roe = *a;
  }

  APF_Path_Planning_2023a_BlueI_B.scale_oy =
    APF_Path_Planning_2023a_BlueI_B.absa + APF_Path_Planning_2023a_BlueI_B.absb;
  if (APF_Path_Planning_2023a_BlueI_B.scale_oy == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    APF_Path_Planning_2023a_BlueI_B.ads = APF_Path_Planning_2023a_BlueI_B.absa /
      APF_Path_Planning_2023a_BlueI_B.scale_oy;
    APF_Path_Planning_2023a_BlueI_B.bds = APF_Path_Planning_2023a_BlueI_B.absb /
      APF_Path_Planning_2023a_BlueI_B.scale_oy;
    APF_Path_Planning_2023a_BlueI_B.scale_oy *= sqrt
      (APF_Path_Planning_2023a_BlueI_B.ads * APF_Path_Planning_2023a_BlueI_B.ads
       + APF_Path_Planning_2023a_BlueI_B.bds *
       APF_Path_Planning_2023a_BlueI_B.bds);
    if (APF_Path_Planning_2023a_BlueI_B.roe < 0.0) {
      APF_Path_Planning_2023a_BlueI_B.scale_oy =
        -APF_Path_Planning_2023a_BlueI_B.scale_oy;
    }

    *c = *a / APF_Path_Planning_2023a_BlueI_B.scale_oy;
    *s = *b / APF_Path_Planning_2023a_BlueI_B.scale_oy;
    if (APF_Path_Planning_2023a_BlueI_B.absa >
        APF_Path_Planning_2023a_BlueI_B.absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = APF_Path_Planning_2023a_BlueI_B.scale_oy;
  }
}

// Function for MATLAB Function: '<S582>/Dynamics Model'
static void APF_Path_Planning_2023a_Bl_xrot(real_T x[36], int32_T ix0, int32_T
  iy0, real_T c, real_T s)
{
  for (APF_Path_Planning_2023a_BlueI_B.k_a = 0;
       APF_Path_Planning_2023a_BlueI_B.k_a < 6;
       APF_Path_Planning_2023a_BlueI_B.k_a++) {
    APF_Path_Planning_2023a_BlueI_B.temp_tmp_tmp = (iy0 +
      APF_Path_Planning_2023a_BlueI_B.k_a) - 1;
    APF_Path_Planning_2023a_BlueI_B.temp_tmp =
      x[APF_Path_Planning_2023a_BlueI_B.temp_tmp_tmp];
    APF_Path_Planning_2023a_BlueI_B.temp_tmp_tmp_d = (ix0 +
      APF_Path_Planning_2023a_BlueI_B.k_a) - 1;
    APF_Path_Planning_2023a_BlueI_B.temp_tmp_l =
      x[APF_Path_Planning_2023a_BlueI_B.temp_tmp_tmp_d];
    x[APF_Path_Planning_2023a_BlueI_B.temp_tmp_tmp] =
      APF_Path_Planning_2023a_BlueI_B.temp_tmp * c -
      APF_Path_Planning_2023a_BlueI_B.temp_tmp_l * s;
    x[APF_Path_Planning_2023a_BlueI_B.temp_tmp_tmp_d] =
      APF_Path_Planning_2023a_BlueI_B.temp_tmp_l * c +
      APF_Path_Planning_2023a_BlueI_B.temp_tmp * s;
  }
}

// Function for MATLAB Function: '<S582>/Dynamics Model'
static void APF_Path_Planning_2023a_Blu_svd(const real_T A[36], real_T U[36],
  real_T s[6], real_T V[36])
{
  boolean_T exitg1;
  memcpy(&APF_Path_Planning_2023a_BlueI_B.b_A_c[0], &A[0], 36U * sizeof(real_T));
  for (APF_Path_Planning_2023a_BlueI_B.i_c = 0;
       APF_Path_Planning_2023a_BlueI_B.i_c < 6;
       APF_Path_Planning_2023a_BlueI_B.i_c++) {
    APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.i_c] =
      0.0;
    APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.i_c] = 0.0;
    APF_Path_Planning_2023a_BlueI_B.work[APF_Path_Planning_2023a_BlueI_B.i_c] =
      0.0;
  }

  memset(&U[0], 0, 36U * sizeof(real_T));
  memset(&APF_Path_Planning_2023a_BlueI_B.Vf[0], 0, 36U * sizeof(real_T));
  for (APF_Path_Planning_2023a_BlueI_B.i_c = 0;
       APF_Path_Planning_2023a_BlueI_B.i_c < 5;
       APF_Path_Planning_2023a_BlueI_B.i_c++) {
    APF_Path_Planning_2023a_BlueI_B.qp1 = APF_Path_Planning_2023a_BlueI_B.i_c +
      2;
    APF_Path_Planning_2023a_BlueI_B.qs = 6 * APF_Path_Planning_2023a_BlueI_B.i_c
      + APF_Path_Planning_2023a_BlueI_B.i_c;
    APF_Path_Planning_2023a_BlueI_B.qq = APF_Path_Planning_2023a_BlueI_B.qs + 1;
    APF_Path_Planning_2023a_BlueI_B.apply_transform = false;
    APF_Path_Planning_2023a_BlueI_B.nrm = APF_Path_Planning_2023a_B_xnrm2(6 -
      APF_Path_Planning_2023a_BlueI_B.i_c, APF_Path_Planning_2023a_BlueI_B.b_A_c,
      APF_Path_Planning_2023a_BlueI_B.qs + 1);
    if (APF_Path_Planning_2023a_BlueI_B.nrm > 0.0) {
      APF_Path_Planning_2023a_BlueI_B.apply_transform = true;
      if (APF_Path_Planning_2023a_BlueI_B.b_A_c[APF_Path_Planning_2023a_BlueI_B.qs]
          < 0.0) {
        APF_Path_Planning_2023a_BlueI_B.nrm =
          -APF_Path_Planning_2023a_BlueI_B.nrm;
      }

      APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.i_c] =
        APF_Path_Planning_2023a_BlueI_B.nrm;
      if (fabs(APF_Path_Planning_2023a_BlueI_B.nrm) >= 1.0020841800044864E-292)
      {
        APF_Path_Planning_2023a_BlueI_B.nrm = 1.0 /
          APF_Path_Planning_2023a_BlueI_B.nrm;
        APF_Path_Planning_2023a_BlueI_B.qjj =
          (APF_Path_Planning_2023a_BlueI_B.qs -
           APF_Path_Planning_2023a_BlueI_B.i_c) + 6;
        for (APF_Path_Planning_2023a_BlueI_B.e_k =
             APF_Path_Planning_2023a_BlueI_B.qq;
             APF_Path_Planning_2023a_BlueI_B.e_k <=
             APF_Path_Planning_2023a_BlueI_B.qjj;
             APF_Path_Planning_2023a_BlueI_B.e_k++) {
          APF_Path_Planning_2023a_BlueI_B.b_A_c[APF_Path_Planning_2023a_BlueI_B.e_k
            - 1] *= APF_Path_Planning_2023a_BlueI_B.nrm;
        }
      } else {
        APF_Path_Planning_2023a_BlueI_B.qjj =
          (APF_Path_Planning_2023a_BlueI_B.qs -
           APF_Path_Planning_2023a_BlueI_B.i_c) + 6;
        for (APF_Path_Planning_2023a_BlueI_B.e_k =
             APF_Path_Planning_2023a_BlueI_B.qq;
             APF_Path_Planning_2023a_BlueI_B.e_k <=
             APF_Path_Planning_2023a_BlueI_B.qjj;
             APF_Path_Planning_2023a_BlueI_B.e_k++) {
          APF_Path_Planning_2023a_BlueI_B.b_A_c[APF_Path_Planning_2023a_BlueI_B.e_k
            - 1] /=
            APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.i_c];
        }
      }

      APF_Path_Planning_2023a_BlueI_B.b_A_c[APF_Path_Planning_2023a_BlueI_B.qs]
        ++;
      APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.i_c] =
        -APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.i_c];
    } else {
      APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.i_c] =
        0.0;
    }

    for (APF_Path_Planning_2023a_BlueI_B.qq =
         APF_Path_Planning_2023a_BlueI_B.qp1; APF_Path_Planning_2023a_BlueI_B.qq
         < 7; APF_Path_Planning_2023a_BlueI_B.qq++) {
      APF_Path_Planning_2023a_BlueI_B.qjj = (APF_Path_Planning_2023a_BlueI_B.qq
        - 1) * 6 + APF_Path_Planning_2023a_BlueI_B.i_c;
      if (APF_Path_Planning_2023a_BlueI_B.apply_transform) {
        APF_Path_Planning_2023a_B_xaxpy(6 - APF_Path_Planning_2023a_BlueI_B.i_c,
          -(APF_Path_Planning_2023a_B_xdotc(6 -
          APF_Path_Planning_2023a_BlueI_B.i_c,
          APF_Path_Planning_2023a_BlueI_B.b_A_c,
          APF_Path_Planning_2023a_BlueI_B.qs + 1,
          APF_Path_Planning_2023a_BlueI_B.b_A_c,
          APF_Path_Planning_2023a_BlueI_B.qjj + 1) /
            APF_Path_Planning_2023a_BlueI_B.b_A_c[APF_Path_Planning_2023a_BlueI_B.qs]),
          APF_Path_Planning_2023a_BlueI_B.qs + 1,
          APF_Path_Planning_2023a_BlueI_B.b_A_c,
          APF_Path_Planning_2023a_BlueI_B.qjj + 1);
      }

      APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qq - 1] =
        APF_Path_Planning_2023a_BlueI_B.b_A_c[APF_Path_Planning_2023a_BlueI_B.qjj];
    }

    for (APF_Path_Planning_2023a_BlueI_B.qq =
         APF_Path_Planning_2023a_BlueI_B.i_c + 1;
         APF_Path_Planning_2023a_BlueI_B.qq < 7;
         APF_Path_Planning_2023a_BlueI_B.qq++) {
      APF_Path_Planning_2023a_BlueI_B.qs = (6 *
        APF_Path_Planning_2023a_BlueI_B.i_c + APF_Path_Planning_2023a_BlueI_B.qq)
        - 1;
      U[APF_Path_Planning_2023a_BlueI_B.qs] =
        APF_Path_Planning_2023a_BlueI_B.b_A_c[APF_Path_Planning_2023a_BlueI_B.qs];
    }

    if (APF_Path_Planning_2023a_BlueI_B.i_c + 1 <= 4) {
      APF_Path_Planning_2023a_BlueI_B.nrm = APF_Path_Planning_2023a_xnrm2_c(5 -
        APF_Path_Planning_2023a_BlueI_B.i_c, APF_Path_Planning_2023a_BlueI_B.e,
        APF_Path_Planning_2023a_BlueI_B.i_c + 2);
      if (APF_Path_Planning_2023a_BlueI_B.nrm == 0.0) {
        APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.i_c] =
          0.0;
      } else {
        if (APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.i_c
            + 1] < 0.0) {
          APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.i_c]
            = -APF_Path_Planning_2023a_BlueI_B.nrm;
        } else {
          APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.i_c]
            = APF_Path_Planning_2023a_BlueI_B.nrm;
        }

        APF_Path_Planning_2023a_BlueI_B.nrm =
          APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.i_c];
        if (fabs
            (APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.i_c])
            >= 1.0020841800044864E-292) {
          APF_Path_Planning_2023a_BlueI_B.nrm = 1.0 /
            APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.i_c];
          for (APF_Path_Planning_2023a_BlueI_B.qq =
               APF_Path_Planning_2023a_BlueI_B.qp1;
               APF_Path_Planning_2023a_BlueI_B.qq < 7;
               APF_Path_Planning_2023a_BlueI_B.qq++) {
            APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qq
              - 1] *= APF_Path_Planning_2023a_BlueI_B.nrm;
          }
        } else {
          for (APF_Path_Planning_2023a_BlueI_B.qq =
               APF_Path_Planning_2023a_BlueI_B.qp1;
               APF_Path_Planning_2023a_BlueI_B.qq < 7;
               APF_Path_Planning_2023a_BlueI_B.qq++) {
            APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qq
              - 1] /= APF_Path_Planning_2023a_BlueI_B.nrm;
          }
        }

        APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.i_c +
          1]++;
        APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.i_c] =
          -APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.i_c];
        for (APF_Path_Planning_2023a_BlueI_B.qq =
             APF_Path_Planning_2023a_BlueI_B.qp1;
             APF_Path_Planning_2023a_BlueI_B.qq < 7;
             APF_Path_Planning_2023a_BlueI_B.qq++) {
          APF_Path_Planning_2023a_BlueI_B.work[APF_Path_Planning_2023a_BlueI_B.qq
            - 1] = 0.0;
        }

        for (APF_Path_Planning_2023a_BlueI_B.qq =
             APF_Path_Planning_2023a_BlueI_B.qp1;
             APF_Path_Planning_2023a_BlueI_B.qq < 7;
             APF_Path_Planning_2023a_BlueI_B.qq++) {
          APF_Path_Planning_2023a_xaxpy_j(5 -
            APF_Path_Planning_2023a_BlueI_B.i_c,
            APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qq
            - 1], APF_Path_Planning_2023a_BlueI_B.b_A_c,
            (APF_Path_Planning_2023a_BlueI_B.i_c + 6 *
             (APF_Path_Planning_2023a_BlueI_B.qq - 1)) + 2,
            APF_Path_Planning_2023a_BlueI_B.work,
            APF_Path_Planning_2023a_BlueI_B.i_c + 2);
        }

        for (APF_Path_Planning_2023a_BlueI_B.qq =
             APF_Path_Planning_2023a_BlueI_B.qp1;
             APF_Path_Planning_2023a_BlueI_B.qq < 7;
             APF_Path_Planning_2023a_BlueI_B.qq++) {
          APF_Path_Planning_2023_xaxpy_jv(5 -
            APF_Path_Planning_2023a_BlueI_B.i_c,
            -APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qq
            - 1] /
            APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.i_c
            + 1], APF_Path_Planning_2023a_BlueI_B.work,
            APF_Path_Planning_2023a_BlueI_B.i_c + 2,
            APF_Path_Planning_2023a_BlueI_B.b_A_c,
            (APF_Path_Planning_2023a_BlueI_B.i_c + 6 *
             (APF_Path_Planning_2023a_BlueI_B.qq - 1)) + 2);
        }
      }

      for (APF_Path_Planning_2023a_BlueI_B.qq =
           APF_Path_Planning_2023a_BlueI_B.qp1;
           APF_Path_Planning_2023a_BlueI_B.qq < 7;
           APF_Path_Planning_2023a_BlueI_B.qq++) {
        APF_Path_Planning_2023a_BlueI_B.Vf[(APF_Path_Planning_2023a_BlueI_B.qq +
          6 * APF_Path_Planning_2023a_BlueI_B.i_c) - 1] =
          APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qq -
          1];
      }
    }
  }

  APF_Path_Planning_2023a_BlueI_B.i_c = 4;
  APF_Path_Planning_2023a_BlueI_B.b_s[5] =
    APF_Path_Planning_2023a_BlueI_B.b_A_c[35];
  APF_Path_Planning_2023a_BlueI_B.e[4] = APF_Path_Planning_2023a_BlueI_B.b_A_c
    [34];
  APF_Path_Planning_2023a_BlueI_B.e[5] = 0.0;
  for (APF_Path_Planning_2023a_BlueI_B.qp1 = 0;
       APF_Path_Planning_2023a_BlueI_B.qp1 < 6;
       APF_Path_Planning_2023a_BlueI_B.qp1++) {
    U[APF_Path_Planning_2023a_BlueI_B.qp1 + 30] = 0.0;
  }

  U[35] = 1.0;
  for (APF_Path_Planning_2023a_BlueI_B.qp1 = 4;
       APF_Path_Planning_2023a_BlueI_B.qp1 >= 0;
       APF_Path_Planning_2023a_BlueI_B.qp1--) {
    APF_Path_Planning_2023a_BlueI_B.qq = 6 * APF_Path_Planning_2023a_BlueI_B.qp1
      + APF_Path_Planning_2023a_BlueI_B.qp1;
    if (APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qp1]
        != 0.0) {
      for (APF_Path_Planning_2023a_BlueI_B.qs =
           APF_Path_Planning_2023a_BlueI_B.qp1 + 2;
           APF_Path_Planning_2023a_BlueI_B.qs < 7;
           APF_Path_Planning_2023a_BlueI_B.qs++) {
        APF_Path_Planning_2023a_BlueI_B.qjj =
          ((APF_Path_Planning_2023a_BlueI_B.qs - 1) * 6 +
           APF_Path_Planning_2023a_BlueI_B.qp1) + 1;
        APF_Path_Planning_2023a_B_xaxpy(6 - APF_Path_Planning_2023a_BlueI_B.qp1,
          -(APF_Path_Planning_2023a_B_xdotc(6 -
          APF_Path_Planning_2023a_BlueI_B.qp1, U,
          APF_Path_Planning_2023a_BlueI_B.qq + 1, U,
          APF_Path_Planning_2023a_BlueI_B.qjj) /
            U[APF_Path_Planning_2023a_BlueI_B.qq]),
          APF_Path_Planning_2023a_BlueI_B.qq + 1, U,
          APF_Path_Planning_2023a_BlueI_B.qjj);
      }

      for (APF_Path_Planning_2023a_BlueI_B.qjj =
           APF_Path_Planning_2023a_BlueI_B.qp1 + 1;
           APF_Path_Planning_2023a_BlueI_B.qjj < 7;
           APF_Path_Planning_2023a_BlueI_B.qjj++) {
        APF_Path_Planning_2023a_BlueI_B.qs = (6 *
          APF_Path_Planning_2023a_BlueI_B.qp1 +
          APF_Path_Planning_2023a_BlueI_B.qjj) - 1;
        U[APF_Path_Planning_2023a_BlueI_B.qs] =
          -U[APF_Path_Planning_2023a_BlueI_B.qs];
      }

      U[APF_Path_Planning_2023a_BlueI_B.qq]++;
      for (APF_Path_Planning_2023a_BlueI_B.qq = 0;
           APF_Path_Planning_2023a_BlueI_B.qq <
           APF_Path_Planning_2023a_BlueI_B.qp1;
           APF_Path_Planning_2023a_BlueI_B.qq++) {
        U[APF_Path_Planning_2023a_BlueI_B.qq + 6 *
          APF_Path_Planning_2023a_BlueI_B.qp1] = 0.0;
      }
    } else {
      for (APF_Path_Planning_2023a_BlueI_B.qs = 0;
           APF_Path_Planning_2023a_BlueI_B.qs < 6;
           APF_Path_Planning_2023a_BlueI_B.qs++) {
        U[APF_Path_Planning_2023a_BlueI_B.qs + 6 *
          APF_Path_Planning_2023a_BlueI_B.qp1] = 0.0;
      }

      U[APF_Path_Planning_2023a_BlueI_B.qq] = 1.0;
    }
  }

  for (APF_Path_Planning_2023a_BlueI_B.qp1 = 5;
       APF_Path_Planning_2023a_BlueI_B.qp1 >= 0;
       APF_Path_Planning_2023a_BlueI_B.qp1--) {
    if ((APF_Path_Planning_2023a_BlueI_B.qp1 + 1 <= 4) &&
        (APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qp1]
         != 0.0)) {
      APF_Path_Planning_2023a_BlueI_B.qq = (6 *
        APF_Path_Planning_2023a_BlueI_B.qp1 +
        APF_Path_Planning_2023a_BlueI_B.qp1) + 2;
      for (APF_Path_Planning_2023a_BlueI_B.qs =
           APF_Path_Planning_2023a_BlueI_B.qp1 + 2;
           APF_Path_Planning_2023a_BlueI_B.qs < 7;
           APF_Path_Planning_2023a_BlueI_B.qs++) {
        APF_Path_Planning_2023a_BlueI_B.qjj =
          ((APF_Path_Planning_2023a_BlueI_B.qs - 1) * 6 +
           APF_Path_Planning_2023a_BlueI_B.qp1) + 2;
        APF_Path_Planning_2023a_B_xaxpy(5 - APF_Path_Planning_2023a_BlueI_B.qp1,
          -(APF_Path_Planning_2023a_B_xdotc(5 -
          APF_Path_Planning_2023a_BlueI_B.qp1,
          APF_Path_Planning_2023a_BlueI_B.Vf, APF_Path_Planning_2023a_BlueI_B.qq,
          APF_Path_Planning_2023a_BlueI_B.Vf,
          APF_Path_Planning_2023a_BlueI_B.qjj) /
            APF_Path_Planning_2023a_BlueI_B.Vf[APF_Path_Planning_2023a_BlueI_B.qq
            - 1]), APF_Path_Planning_2023a_BlueI_B.qq,
          APF_Path_Planning_2023a_BlueI_B.Vf,
          APF_Path_Planning_2023a_BlueI_B.qjj);
      }
    }

    for (APF_Path_Planning_2023a_BlueI_B.qq = 0;
         APF_Path_Planning_2023a_BlueI_B.qq < 6;
         APF_Path_Planning_2023a_BlueI_B.qq++) {
      APF_Path_Planning_2023a_BlueI_B.Vf[APF_Path_Planning_2023a_BlueI_B.qq + 6 *
        APF_Path_Planning_2023a_BlueI_B.qp1] = 0.0;
    }

    APF_Path_Planning_2023a_BlueI_B.Vf[APF_Path_Planning_2023a_BlueI_B.qp1 + 6 *
      APF_Path_Planning_2023a_BlueI_B.qp1] = 1.0;
  }

  APF_Path_Planning_2023a_BlueI_B.qp1 = 0;
  APF_Path_Planning_2023a_BlueI_B.nrm = 0.0;
  for (APF_Path_Planning_2023a_BlueI_B.qq = 0;
       APF_Path_Planning_2023a_BlueI_B.qq < 6;
       APF_Path_Planning_2023a_BlueI_B.qq++) {
    APF_Path_Planning_2023a_BlueI_B.r_i =
      APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qq];
    if (APF_Path_Planning_2023a_BlueI_B.r_i != 0.0) {
      APF_Path_Planning_2023a_BlueI_B.rt = fabs
        (APF_Path_Planning_2023a_BlueI_B.r_i);
      APF_Path_Planning_2023a_BlueI_B.r_i /= APF_Path_Planning_2023a_BlueI_B.rt;
      APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qq] =
        APF_Path_Planning_2023a_BlueI_B.rt;
      if (APF_Path_Planning_2023a_BlueI_B.qq + 1 < 6) {
        APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qq] /=
          APF_Path_Planning_2023a_BlueI_B.r_i;
      }

      APF_Path_Planning_2023a_BlueI_B.qs = 6 *
        APF_Path_Planning_2023a_BlueI_B.qq + 1;
      for (APF_Path_Planning_2023a_BlueI_B.qjj =
           APF_Path_Planning_2023a_BlueI_B.qs;
           APF_Path_Planning_2023a_BlueI_B.qjj <=
           APF_Path_Planning_2023a_BlueI_B.qs + 5;
           APF_Path_Planning_2023a_BlueI_B.qjj++) {
        U[APF_Path_Planning_2023a_BlueI_B.qjj - 1] *=
          APF_Path_Planning_2023a_BlueI_B.r_i;
      }
    }

    if (APF_Path_Planning_2023a_BlueI_B.qq + 1 < 6) {
      APF_Path_Planning_2023a_BlueI_B.r_i =
        APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qq];
      if (APF_Path_Planning_2023a_BlueI_B.r_i != 0.0) {
        APF_Path_Planning_2023a_BlueI_B.rt = fabs
          (APF_Path_Planning_2023a_BlueI_B.r_i);
        APF_Path_Planning_2023a_BlueI_B.r_i = APF_Path_Planning_2023a_BlueI_B.rt
          / APF_Path_Planning_2023a_BlueI_B.r_i;
        APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qq] =
          APF_Path_Planning_2023a_BlueI_B.rt;
        APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qq +
          1] *= APF_Path_Planning_2023a_BlueI_B.r_i;
        APF_Path_Planning_2023a_BlueI_B.qs = (APF_Path_Planning_2023a_BlueI_B.qq
          + 1) * 6 + 1;
        for (APF_Path_Planning_2023a_BlueI_B.qjj =
             APF_Path_Planning_2023a_BlueI_B.qs;
             APF_Path_Planning_2023a_BlueI_B.qjj <=
             APF_Path_Planning_2023a_BlueI_B.qs + 5;
             APF_Path_Planning_2023a_BlueI_B.qjj++) {
          APF_Path_Planning_2023a_BlueI_B.Vf[APF_Path_Planning_2023a_BlueI_B.qjj
            - 1] *= APF_Path_Planning_2023a_BlueI_B.r_i;
        }
      }
    }

    APF_Path_Planning_2023a_BlueI_B.r_i = fabs
      (APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qq]);
    APF_Path_Planning_2023a_BlueI_B.rt = fabs
      (APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qq]);
    if ((APF_Path_Planning_2023a_BlueI_B.r_i >=
         APF_Path_Planning_2023a_BlueI_B.rt) || rtIsNaN
        (APF_Path_Planning_2023a_BlueI_B.rt)) {
      APF_Path_Planning_2023a_BlueI_B.rt = APF_Path_Planning_2023a_BlueI_B.r_i;
    }

    if ((!(APF_Path_Planning_2023a_BlueI_B.nrm >=
           APF_Path_Planning_2023a_BlueI_B.rt)) && (!rtIsNaN
         (APF_Path_Planning_2023a_BlueI_B.rt))) {
      APF_Path_Planning_2023a_BlueI_B.nrm = APF_Path_Planning_2023a_BlueI_B.rt;
    }
  }

  while ((APF_Path_Planning_2023a_BlueI_B.i_c + 2 > 0) &&
         (APF_Path_Planning_2023a_BlueI_B.qp1 < 75)) {
    APF_Path_Planning_2023a_BlueI_B.qq = APF_Path_Planning_2023a_BlueI_B.i_c + 1;
    exitg1 = false;
    while (!(exitg1 || (APF_Path_Planning_2023a_BlueI_B.qq == 0))) {
      APF_Path_Planning_2023a_BlueI_B.rt = fabs
        (APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qq -
         1]);
      if (APF_Path_Planning_2023a_BlueI_B.rt <= (fabs
           (APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qq
            - 1]) + fabs
           (APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qq]))
          * 2.2204460492503131E-16) {
        APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qq - 1]
          = 0.0;
        exitg1 = true;
      } else if ((APF_Path_Planning_2023a_BlueI_B.rt <= 1.0020841800044864E-292)
                 || ((APF_Path_Planning_2023a_BlueI_B.qp1 > 20) &&
                     (APF_Path_Planning_2023a_BlueI_B.rt <=
                      2.2204460492503131E-16 *
                      APF_Path_Planning_2023a_BlueI_B.nrm))) {
        APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qq - 1]
          = 0.0;
        exitg1 = true;
      } else {
        APF_Path_Planning_2023a_BlueI_B.qq--;
      }
    }

    if (APF_Path_Planning_2023a_BlueI_B.i_c + 1 ==
        APF_Path_Planning_2023a_BlueI_B.qq) {
      APF_Path_Planning_2023a_BlueI_B.qjj = 4;
    } else {
      APF_Path_Planning_2023a_BlueI_B.qs = APF_Path_Planning_2023a_BlueI_B.i_c +
        2;
      APF_Path_Planning_2023a_BlueI_B.qjj = APF_Path_Planning_2023a_BlueI_B.i_c
        + 2;
      exitg1 = false;
      while ((!exitg1) && (APF_Path_Planning_2023a_BlueI_B.qjj >=
                           APF_Path_Planning_2023a_BlueI_B.qq)) {
        APF_Path_Planning_2023a_BlueI_B.qs = APF_Path_Planning_2023a_BlueI_B.qjj;
        if (APF_Path_Planning_2023a_BlueI_B.qjj ==
            APF_Path_Planning_2023a_BlueI_B.qq) {
          exitg1 = true;
        } else {
          APF_Path_Planning_2023a_BlueI_B.rt = 0.0;
          if (APF_Path_Planning_2023a_BlueI_B.qjj <
              APF_Path_Planning_2023a_BlueI_B.i_c + 2) {
            APF_Path_Planning_2023a_BlueI_B.rt = fabs
              (APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qjj
               - 1]);
          }

          if (APF_Path_Planning_2023a_BlueI_B.qjj >
              APF_Path_Planning_2023a_BlueI_B.qq + 1) {
            APF_Path_Planning_2023a_BlueI_B.rt += fabs
              (APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qjj
               - 2]);
          }

          APF_Path_Planning_2023a_BlueI_B.r_i = fabs
            (APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qjj
             - 1]);
          if ((APF_Path_Planning_2023a_BlueI_B.r_i <= 2.2204460492503131E-16 *
               APF_Path_Planning_2023a_BlueI_B.rt) ||
              (APF_Path_Planning_2023a_BlueI_B.r_i <= 1.0020841800044864E-292))
          {
            APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qjj
              - 1] = 0.0;
            exitg1 = true;
          } else {
            APF_Path_Planning_2023a_BlueI_B.qjj--;
          }
        }
      }

      if (APF_Path_Planning_2023a_BlueI_B.qs ==
          APF_Path_Planning_2023a_BlueI_B.qq) {
        APF_Path_Planning_2023a_BlueI_B.qjj = 3;
      } else if (APF_Path_Planning_2023a_BlueI_B.i_c + 2 ==
                 APF_Path_Planning_2023a_BlueI_B.qs) {
        APF_Path_Planning_2023a_BlueI_B.qjj = 1;
      } else {
        APF_Path_Planning_2023a_BlueI_B.qjj = 2;
        APF_Path_Planning_2023a_BlueI_B.qq = APF_Path_Planning_2023a_BlueI_B.qs;
      }
    }

    switch (APF_Path_Planning_2023a_BlueI_B.qjj) {
     case 1:
      APF_Path_Planning_2023a_BlueI_B.rt =
        APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.i_c];
      APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.i_c] =
        0.0;
      for (APF_Path_Planning_2023a_BlueI_B.qs =
           APF_Path_Planning_2023a_BlueI_B.i_c + 1;
           APF_Path_Planning_2023a_BlueI_B.qs >=
           APF_Path_Planning_2023a_BlueI_B.qq + 1;
           APF_Path_Planning_2023a_BlueI_B.qs--) {
        APF_Path_Planning_2023a_B_xrotg
          (&APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qs
           - 1], &APF_Path_Planning_2023a_BlueI_B.rt,
           &APF_Path_Planning_2023a_BlueI_B.sqds,
           &APF_Path_Planning_2023a_BlueI_B.smm1);
        if (APF_Path_Planning_2023a_BlueI_B.qs >
            APF_Path_Planning_2023a_BlueI_B.qq + 1) {
          APF_Path_Planning_2023a_BlueI_B.r_i =
            APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qs
            - 2];
          APF_Path_Planning_2023a_BlueI_B.rt =
            -APF_Path_Planning_2023a_BlueI_B.smm1 *
            APF_Path_Planning_2023a_BlueI_B.r_i;
          APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qs -
            2] = APF_Path_Planning_2023a_BlueI_B.r_i *
            APF_Path_Planning_2023a_BlueI_B.sqds;
        }

        APF_Path_Planning_2023a_Bl_xrot(APF_Path_Planning_2023a_BlueI_B.Vf, 6 *
          (APF_Path_Planning_2023a_BlueI_B.qs - 1) + 1, 6 *
          (APF_Path_Planning_2023a_BlueI_B.i_c + 1) + 1,
          APF_Path_Planning_2023a_BlueI_B.sqds,
          APF_Path_Planning_2023a_BlueI_B.smm1);
      }
      break;

     case 2:
      APF_Path_Planning_2023a_BlueI_B.rt =
        APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qq - 1];
      APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qq - 1] =
        0.0;
      for (APF_Path_Planning_2023a_BlueI_B.qs =
           APF_Path_Planning_2023a_BlueI_B.qq + 1;
           APF_Path_Planning_2023a_BlueI_B.qs <=
           APF_Path_Planning_2023a_BlueI_B.i_c + 2;
           APF_Path_Planning_2023a_BlueI_B.qs++) {
        APF_Path_Planning_2023a_B_xrotg
          (&APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qs
           - 1], &APF_Path_Planning_2023a_BlueI_B.rt,
           &APF_Path_Planning_2023a_BlueI_B.sqds,
           &APF_Path_Planning_2023a_BlueI_B.smm1);
        APF_Path_Planning_2023a_BlueI_B.r_i =
          APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qs -
          1];
        APF_Path_Planning_2023a_BlueI_B.rt =
          -APF_Path_Planning_2023a_BlueI_B.smm1 *
          APF_Path_Planning_2023a_BlueI_B.r_i;
        APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qs - 1]
          = APF_Path_Planning_2023a_BlueI_B.r_i *
          APF_Path_Planning_2023a_BlueI_B.sqds;
        APF_Path_Planning_2023a_Bl_xrot(U, 6 *
          (APF_Path_Planning_2023a_BlueI_B.qs - 1) + 1, 6 *
          (APF_Path_Planning_2023a_BlueI_B.qq - 1) + 1,
          APF_Path_Planning_2023a_BlueI_B.sqds,
          APF_Path_Planning_2023a_BlueI_B.smm1);
      }
      break;

     case 3:
      APF_Path_Planning_2023a_BlueI_B.sqds =
        APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.i_c
        + 1];
      APF_Path_Planning_2023a_BlueI_B.r_i = fabs
        (APF_Path_Planning_2023a_BlueI_B.sqds);
      APF_Path_Planning_2023a_BlueI_B.rt = fabs
        (APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.i_c]);
      if ((APF_Path_Planning_2023a_BlueI_B.r_i >=
           APF_Path_Planning_2023a_BlueI_B.rt) || rtIsNaN
          (APF_Path_Planning_2023a_BlueI_B.rt)) {
        APF_Path_Planning_2023a_BlueI_B.rt = APF_Path_Planning_2023a_BlueI_B.r_i;
      }

      APF_Path_Planning_2023a_BlueI_B.r_i = fabs
        (APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.i_c]);
      if ((APF_Path_Planning_2023a_BlueI_B.rt >=
           APF_Path_Planning_2023a_BlueI_B.r_i) || rtIsNaN
          (APF_Path_Planning_2023a_BlueI_B.r_i)) {
        APF_Path_Planning_2023a_BlueI_B.r_i = APF_Path_Planning_2023a_BlueI_B.rt;
      }

      APF_Path_Planning_2023a_BlueI_B.rt = fabs
        (APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qq]);
      if ((APF_Path_Planning_2023a_BlueI_B.r_i >=
           APF_Path_Planning_2023a_BlueI_B.rt) || rtIsNaN
          (APF_Path_Planning_2023a_BlueI_B.rt)) {
        APF_Path_Planning_2023a_BlueI_B.rt = APF_Path_Planning_2023a_BlueI_B.r_i;
      }

      APF_Path_Planning_2023a_BlueI_B.r_i = fabs
        (APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qq]);
      if ((APF_Path_Planning_2023a_BlueI_B.rt >=
           APF_Path_Planning_2023a_BlueI_B.r_i) || rtIsNaN
          (APF_Path_Planning_2023a_BlueI_B.r_i)) {
        APF_Path_Planning_2023a_BlueI_B.r_i = APF_Path_Planning_2023a_BlueI_B.rt;
      }

      APF_Path_Planning_2023a_BlueI_B.rt = APF_Path_Planning_2023a_BlueI_B.sqds /
        APF_Path_Planning_2023a_BlueI_B.r_i;
      APF_Path_Planning_2023a_BlueI_B.smm1 =
        APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.i_c]
        / APF_Path_Planning_2023a_BlueI_B.r_i;
      APF_Path_Planning_2023a_BlueI_B.emm1 =
        APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.i_c] /
        APF_Path_Planning_2023a_BlueI_B.r_i;
      APF_Path_Planning_2023a_BlueI_B.sqds =
        APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qq] /
        APF_Path_Planning_2023a_BlueI_B.r_i;
      APF_Path_Planning_2023a_BlueI_B.smm1 =
        ((APF_Path_Planning_2023a_BlueI_B.smm1 +
          APF_Path_Planning_2023a_BlueI_B.rt) *
         (APF_Path_Planning_2023a_BlueI_B.smm1 -
          APF_Path_Planning_2023a_BlueI_B.rt) +
         APF_Path_Planning_2023a_BlueI_B.emm1 *
         APF_Path_Planning_2023a_BlueI_B.emm1) / 2.0;
      APF_Path_Planning_2023a_BlueI_B.emm1 *= APF_Path_Planning_2023a_BlueI_B.rt;
      APF_Path_Planning_2023a_BlueI_B.emm1 *=
        APF_Path_Planning_2023a_BlueI_B.emm1;
      if ((APF_Path_Planning_2023a_BlueI_B.smm1 != 0.0) ||
          (APF_Path_Planning_2023a_BlueI_B.emm1 != 0.0)) {
        APF_Path_Planning_2023a_BlueI_B.shift = sqrt
          (APF_Path_Planning_2023a_BlueI_B.smm1 *
           APF_Path_Planning_2023a_BlueI_B.smm1 +
           APF_Path_Planning_2023a_BlueI_B.emm1);
        if (APF_Path_Planning_2023a_BlueI_B.smm1 < 0.0) {
          APF_Path_Planning_2023a_BlueI_B.shift =
            -APF_Path_Planning_2023a_BlueI_B.shift;
        }

        APF_Path_Planning_2023a_BlueI_B.shift =
          APF_Path_Planning_2023a_BlueI_B.emm1 /
          (APF_Path_Planning_2023a_BlueI_B.smm1 +
           APF_Path_Planning_2023a_BlueI_B.shift);
      } else {
        APF_Path_Planning_2023a_BlueI_B.shift = 0.0;
      }

      APF_Path_Planning_2023a_BlueI_B.rt = (APF_Path_Planning_2023a_BlueI_B.sqds
        + APF_Path_Planning_2023a_BlueI_B.rt) *
        (APF_Path_Planning_2023a_BlueI_B.sqds -
         APF_Path_Planning_2023a_BlueI_B.rt) +
        APF_Path_Planning_2023a_BlueI_B.shift;
      APF_Path_Planning_2023a_BlueI_B.r_i =
        APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.qq] /
        APF_Path_Planning_2023a_BlueI_B.r_i *
        APF_Path_Planning_2023a_BlueI_B.sqds;
      for (APF_Path_Planning_2023a_BlueI_B.e_k =
           APF_Path_Planning_2023a_BlueI_B.qq + 1;
           APF_Path_Planning_2023a_BlueI_B.e_k <=
           APF_Path_Planning_2023a_BlueI_B.i_c + 1;
           APF_Path_Planning_2023a_BlueI_B.e_k++) {
        APF_Path_Planning_2023a_B_xrotg(&APF_Path_Planning_2023a_BlueI_B.rt,
          &APF_Path_Planning_2023a_BlueI_B.r_i,
          &APF_Path_Planning_2023a_BlueI_B.sqds,
          &APF_Path_Planning_2023a_BlueI_B.smm1);
        if (APF_Path_Planning_2023a_BlueI_B.e_k >
            APF_Path_Planning_2023a_BlueI_B.qq + 1) {
          APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.e_k
            - 2] = APF_Path_Planning_2023a_BlueI_B.rt;
        }

        APF_Path_Planning_2023a_BlueI_B.emm1 =
          APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.e_k
          - 1];
        APF_Path_Planning_2023a_BlueI_B.r_i =
          APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.e_k
          - 1];
        APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.e_k -
          1] = APF_Path_Planning_2023a_BlueI_B.emm1 *
          APF_Path_Planning_2023a_BlueI_B.sqds -
          APF_Path_Planning_2023a_BlueI_B.r_i *
          APF_Path_Planning_2023a_BlueI_B.smm1;
        APF_Path_Planning_2023a_BlueI_B.rt =
          APF_Path_Planning_2023a_BlueI_B.smm1 *
          APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.e_k];
        APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.e_k]
          *= APF_Path_Planning_2023a_BlueI_B.sqds;
        APF_Path_Planning_2023a_BlueI_B.qs =
          (APF_Path_Planning_2023a_BlueI_B.e_k - 1) * 6 + 1;
        APF_Path_Planning_2023a_BlueI_B.qjj = 6 *
          APF_Path_Planning_2023a_BlueI_B.e_k + 1;
        APF_Path_Planning_2023a_Bl_xrot(APF_Path_Planning_2023a_BlueI_B.Vf,
          APF_Path_Planning_2023a_BlueI_B.qs,
          APF_Path_Planning_2023a_BlueI_B.qjj,
          APF_Path_Planning_2023a_BlueI_B.sqds,
          APF_Path_Planning_2023a_BlueI_B.smm1);
        APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.e_k
          - 1] = APF_Path_Planning_2023a_BlueI_B.r_i *
          APF_Path_Planning_2023a_BlueI_B.sqds +
          APF_Path_Planning_2023a_BlueI_B.emm1 *
          APF_Path_Planning_2023a_BlueI_B.smm1;
        APF_Path_Planning_2023a_B_xrotg
          (&APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.e_k
           - 1], &APF_Path_Planning_2023a_BlueI_B.rt,
           &APF_Path_Planning_2023a_BlueI_B.sqds,
           &APF_Path_Planning_2023a_BlueI_B.smm1);
        APF_Path_Planning_2023a_BlueI_B.r_i =
          APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.e_k
          - 1];
        APF_Path_Planning_2023a_BlueI_B.rt = APF_Path_Planning_2023a_BlueI_B.r_i
          * APF_Path_Planning_2023a_BlueI_B.sqds +
          APF_Path_Planning_2023a_BlueI_B.smm1 *
          APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.e_k];
        APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.e_k]
          = APF_Path_Planning_2023a_BlueI_B.r_i *
          -APF_Path_Planning_2023a_BlueI_B.smm1 +
          APF_Path_Planning_2023a_BlueI_B.sqds *
          APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.e_k];
        APF_Path_Planning_2023a_BlueI_B.r_i =
          APF_Path_Planning_2023a_BlueI_B.smm1 *
          APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.e_k];
        APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.e_k] *=
          APF_Path_Planning_2023a_BlueI_B.sqds;
        APF_Path_Planning_2023a_Bl_xrot(U, APF_Path_Planning_2023a_BlueI_B.qs,
          APF_Path_Planning_2023a_BlueI_B.qjj,
          APF_Path_Planning_2023a_BlueI_B.sqds,
          APF_Path_Planning_2023a_BlueI_B.smm1);
      }

      APF_Path_Planning_2023a_BlueI_B.e[APF_Path_Planning_2023a_BlueI_B.i_c] =
        APF_Path_Planning_2023a_BlueI_B.rt;
      APF_Path_Planning_2023a_BlueI_B.qp1++;
      break;

     default:
      if (APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qq]
          < 0.0) {
        APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qq] =
          -APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qq];
        APF_Path_Planning_2023a_BlueI_B.qp1 = 6 *
          APF_Path_Planning_2023a_BlueI_B.qq + 1;
        for (APF_Path_Planning_2023a_BlueI_B.qs =
             APF_Path_Planning_2023a_BlueI_B.qp1;
             APF_Path_Planning_2023a_BlueI_B.qs <=
             APF_Path_Planning_2023a_BlueI_B.qp1 + 5;
             APF_Path_Planning_2023a_BlueI_B.qs++) {
          APF_Path_Planning_2023a_BlueI_B.Vf[APF_Path_Planning_2023a_BlueI_B.qs
            - 1] =
            -APF_Path_Planning_2023a_BlueI_B.Vf[APF_Path_Planning_2023a_BlueI_B.qs
            - 1];
        }
      }

      APF_Path_Planning_2023a_BlueI_B.qp1 = APF_Path_Planning_2023a_BlueI_B.qq +
        1;
      while ((APF_Path_Planning_2023a_BlueI_B.qq + 1 < 6) &&
             (APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qq]
              <
              APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qp1]))
      {
        APF_Path_Planning_2023a_BlueI_B.rt =
          APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qq];
        APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qq] =
          APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qp1];
        APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qp1]
          = APF_Path_Planning_2023a_BlueI_B.rt;
        APF_Path_Planning_2023a_BlueI_B.qs = 6 *
          APF_Path_Planning_2023a_BlueI_B.qq + 1;
        APF_Path_Planning_2023a_BlueI_B.qjj =
          (APF_Path_Planning_2023a_BlueI_B.qq + 1) * 6 + 1;
        APF_Path_Planning_2023a_B_xswap(APF_Path_Planning_2023a_BlueI_B.Vf,
          APF_Path_Planning_2023a_BlueI_B.qs,
          APF_Path_Planning_2023a_BlueI_B.qjj);
        APF_Path_Planning_2023a_B_xswap(U, APF_Path_Planning_2023a_BlueI_B.qs,
          APF_Path_Planning_2023a_BlueI_B.qjj);
        APF_Path_Planning_2023a_BlueI_B.qq = APF_Path_Planning_2023a_BlueI_B.qp1;
        APF_Path_Planning_2023a_BlueI_B.qp1++;
      }

      APF_Path_Planning_2023a_BlueI_B.qp1 = 0;
      APF_Path_Planning_2023a_BlueI_B.i_c--;
      break;
    }
  }

  for (APF_Path_Planning_2023a_BlueI_B.qp1 = 0;
       APF_Path_Planning_2023a_BlueI_B.qp1 < 6;
       APF_Path_Planning_2023a_BlueI_B.qp1++) {
    s[APF_Path_Planning_2023a_BlueI_B.qp1] =
      APF_Path_Planning_2023a_BlueI_B.b_s[APF_Path_Planning_2023a_BlueI_B.qp1];
    for (APF_Path_Planning_2023a_BlueI_B.i_c = 0;
         APF_Path_Planning_2023a_BlueI_B.i_c < 6;
         APF_Path_Planning_2023a_BlueI_B.i_c++) {
      V[APF_Path_Planning_2023a_BlueI_B.i_c + 6 *
        APF_Path_Planning_2023a_BlueI_B.qp1] =
        APF_Path_Planning_2023a_BlueI_B.Vf[6 *
        APF_Path_Planning_2023a_BlueI_B.qp1 +
        APF_Path_Planning_2023a_BlueI_B.i_c];
    }
  }
}

static void APF_Path_Plannin_rt_invd3x3_snf(const real_T u[9], real_T y[9])
{
  memcpy(&APF_Path_Planning_2023a_BlueI_B.x[0], &u[0], 9U * sizeof(real_T));
  APF_Path_Planning_2023a_BlueI_B.p1 = 1;
  APF_Path_Planning_2023a_BlueI_B.p2 = 3;
  APF_Path_Planning_2023a_BlueI_B.p3 = 6;
  APF_Path_Planning_2023a_BlueI_B.absx11 = fabs(u[0]);
  APF_Path_Planning_2023a_BlueI_B.absx21 = fabs(u[1]);
  APF_Path_Planning_2023a_BlueI_B.absx31 = fabs(u[2]);
  if ((APF_Path_Planning_2023a_BlueI_B.absx21 >
       APF_Path_Planning_2023a_BlueI_B.absx11) &&
      (APF_Path_Planning_2023a_BlueI_B.absx21 >
       APF_Path_Planning_2023a_BlueI_B.absx31)) {
    APF_Path_Planning_2023a_BlueI_B.p1 = 4;
    APF_Path_Planning_2023a_BlueI_B.p2 = 0;
    APF_Path_Planning_2023a_BlueI_B.x[0] = u[1];
    APF_Path_Planning_2023a_BlueI_B.x[1] = u[0];
    APF_Path_Planning_2023a_BlueI_B.x[3] = u[4];
    APF_Path_Planning_2023a_BlueI_B.x[4] = u[3];
    APF_Path_Planning_2023a_BlueI_B.x[6] = u[7];
    APF_Path_Planning_2023a_BlueI_B.x[7] = u[6];
  } else if (APF_Path_Planning_2023a_BlueI_B.absx31 >
             APF_Path_Planning_2023a_BlueI_B.absx11) {
    APF_Path_Planning_2023a_BlueI_B.p1 = 7;
    APF_Path_Planning_2023a_BlueI_B.p3 = 0;
    APF_Path_Planning_2023a_BlueI_B.x[2] = APF_Path_Planning_2023a_BlueI_B.x[0];
    APF_Path_Planning_2023a_BlueI_B.x[0] = u[2];
    APF_Path_Planning_2023a_BlueI_B.x[5] = APF_Path_Planning_2023a_BlueI_B.x[3];
    APF_Path_Planning_2023a_BlueI_B.x[3] = u[5];
    APF_Path_Planning_2023a_BlueI_B.x[8] = APF_Path_Planning_2023a_BlueI_B.x[6];
    APF_Path_Planning_2023a_BlueI_B.x[6] = u[8];
  }

  APF_Path_Planning_2023a_BlueI_B.absx11 = APF_Path_Planning_2023a_BlueI_B.x[1] /
    APF_Path_Planning_2023a_BlueI_B.x[0];
  APF_Path_Planning_2023a_BlueI_B.x[1] = APF_Path_Planning_2023a_BlueI_B.absx11;
  APF_Path_Planning_2023a_BlueI_B.absx21 = APF_Path_Planning_2023a_BlueI_B.x[2] /
    APF_Path_Planning_2023a_BlueI_B.x[0];
  APF_Path_Planning_2023a_BlueI_B.x[2] = APF_Path_Planning_2023a_BlueI_B.absx21;
  APF_Path_Planning_2023a_BlueI_B.x[4] -= APF_Path_Planning_2023a_BlueI_B.absx11
    * APF_Path_Planning_2023a_BlueI_B.x[3];
  APF_Path_Planning_2023a_BlueI_B.x[5] -= APF_Path_Planning_2023a_BlueI_B.absx21
    * APF_Path_Planning_2023a_BlueI_B.x[3];
  APF_Path_Planning_2023a_BlueI_B.x[7] -= APF_Path_Planning_2023a_BlueI_B.absx11
    * APF_Path_Planning_2023a_BlueI_B.x[6];
  APF_Path_Planning_2023a_BlueI_B.x[8] -= APF_Path_Planning_2023a_BlueI_B.absx21
    * APF_Path_Planning_2023a_BlueI_B.x[6];
  if (fabs(APF_Path_Planning_2023a_BlueI_B.x[5]) > fabs
      (APF_Path_Planning_2023a_BlueI_B.x[4])) {
    APF_Path_Planning_2023a_BlueI_B.itmp = APF_Path_Planning_2023a_BlueI_B.p2;
    APF_Path_Planning_2023a_BlueI_B.p2 = APF_Path_Planning_2023a_BlueI_B.p3;
    APF_Path_Planning_2023a_BlueI_B.p3 = APF_Path_Planning_2023a_BlueI_B.itmp;
    APF_Path_Planning_2023a_BlueI_B.x[1] =
      APF_Path_Planning_2023a_BlueI_B.absx21;
    APF_Path_Planning_2023a_BlueI_B.x[2] =
      APF_Path_Planning_2023a_BlueI_B.absx11;
    APF_Path_Planning_2023a_BlueI_B.absx11 = APF_Path_Planning_2023a_BlueI_B.x[4];
    APF_Path_Planning_2023a_BlueI_B.x[4] = APF_Path_Planning_2023a_BlueI_B.x[5];
    APF_Path_Planning_2023a_BlueI_B.x[5] =
      APF_Path_Planning_2023a_BlueI_B.absx11;
    APF_Path_Planning_2023a_BlueI_B.absx11 = APF_Path_Planning_2023a_BlueI_B.x[7];
    APF_Path_Planning_2023a_BlueI_B.x[7] = APF_Path_Planning_2023a_BlueI_B.x[8];
    APF_Path_Planning_2023a_BlueI_B.x[8] =
      APF_Path_Planning_2023a_BlueI_B.absx11;
  }

  APF_Path_Planning_2023a_BlueI_B.absx11 = APF_Path_Planning_2023a_BlueI_B.x[5] /
    APF_Path_Planning_2023a_BlueI_B.x[4];
  APF_Path_Planning_2023a_BlueI_B.x[8] -= APF_Path_Planning_2023a_BlueI_B.absx11
    * APF_Path_Planning_2023a_BlueI_B.x[7];
  APF_Path_Planning_2023a_BlueI_B.absx21 = (APF_Path_Planning_2023a_BlueI_B.x[1]
    * APF_Path_Planning_2023a_BlueI_B.absx11 -
    APF_Path_Planning_2023a_BlueI_B.x[2]) / APF_Path_Planning_2023a_BlueI_B.x[8];
  APF_Path_Planning_2023a_BlueI_B.absx31 = -(APF_Path_Planning_2023a_BlueI_B.x[7]
    * APF_Path_Planning_2023a_BlueI_B.absx21 +
    APF_Path_Planning_2023a_BlueI_B.x[1]) / APF_Path_Planning_2023a_BlueI_B.x[4];
  y[APF_Path_Planning_2023a_BlueI_B.p1 - 1] = ((1.0 -
    APF_Path_Planning_2023a_BlueI_B.x[3] *
    APF_Path_Planning_2023a_BlueI_B.absx31) - APF_Path_Planning_2023a_BlueI_B.x
    [6] * APF_Path_Planning_2023a_BlueI_B.absx21) /
    APF_Path_Planning_2023a_BlueI_B.x[0];
  y[APF_Path_Planning_2023a_BlueI_B.p1] = APF_Path_Planning_2023a_BlueI_B.absx31;
  y[APF_Path_Planning_2023a_BlueI_B.p1 + 1] =
    APF_Path_Planning_2023a_BlueI_B.absx21;
  APF_Path_Planning_2023a_BlueI_B.absx21 =
    -APF_Path_Planning_2023a_BlueI_B.absx11 / APF_Path_Planning_2023a_BlueI_B.x
    [8];
  APF_Path_Planning_2023a_BlueI_B.absx31 = (1.0 -
    APF_Path_Planning_2023a_BlueI_B.x[7] *
    APF_Path_Planning_2023a_BlueI_B.absx21) / APF_Path_Planning_2023a_BlueI_B.x
    [4];
  y[APF_Path_Planning_2023a_BlueI_B.p2] = -(APF_Path_Planning_2023a_BlueI_B.x[3]
    * APF_Path_Planning_2023a_BlueI_B.absx31 +
    APF_Path_Planning_2023a_BlueI_B.x[6] *
    APF_Path_Planning_2023a_BlueI_B.absx21) / APF_Path_Planning_2023a_BlueI_B.x
    [0];
  y[APF_Path_Planning_2023a_BlueI_B.p2 + 1] =
    APF_Path_Planning_2023a_BlueI_B.absx31;
  y[APF_Path_Planning_2023a_BlueI_B.p2 + 2] =
    APF_Path_Planning_2023a_BlueI_B.absx21;
  APF_Path_Planning_2023a_BlueI_B.absx21 = 1.0 /
    APF_Path_Planning_2023a_BlueI_B.x[8];
  APF_Path_Planning_2023a_BlueI_B.absx31 = -APF_Path_Planning_2023a_BlueI_B.x[7]
    * APF_Path_Planning_2023a_BlueI_B.absx21 /
    APF_Path_Planning_2023a_BlueI_B.x[4];
  y[APF_Path_Planning_2023a_BlueI_B.p3] = -(APF_Path_Planning_2023a_BlueI_B.x[3]
    * APF_Path_Planning_2023a_BlueI_B.absx31 +
    APF_Path_Planning_2023a_BlueI_B.x[6] *
    APF_Path_Planning_2023a_BlueI_B.absx21) / APF_Path_Planning_2023a_BlueI_B.x
    [0];
  y[APF_Path_Planning_2023a_BlueI_B.p3 + 1] =
    APF_Path_Planning_2023a_BlueI_B.absx31;
  y[APF_Path_Planning_2023a_BlueI_B.p3 + 2] =
    APF_Path_Planning_2023a_BlueI_B.absx21;
}

// Model step function
void APF_Path_Planning_2023a_BlueIsBlack_step(void)
{
  {
    real_T *lastU;
    char_T *sErr;
    static const int8_T b_a[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    static const int8_T g[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
      0, 1 };

    static const int8_T b[8] = { -1, -1, 0, 0, 1, 1, 0, 0 };

    static const int8_T c[8] = { 0, 0, 1, 1, 0, 0, -1, -1 };

    // S-Function (sdspFromNetwork): '<S2>/UDP Receive1'
    sErr = GetErrorBuffer
      (&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib[0U]);
    APF_Path_Planning_2023a_BlueI_B.ntIdx1 = 12;
    LibOutputs_Network(&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib
                       [0U], &APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1_k
                       [0U], &APF_Path_Planning_2023a_BlueI_B.ntIdx1);
    if (*sErr != 0) {
      rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
      rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
    }

    // End of S-Function (sdspFromNetwork): '<S2>/UDP Receive1'

    // S-Function (byte2any): '<S2>/Byte Unpack'

    // Unpack: <S2>/Byte Unpack
    (void) memcpy(&APF_Path_Planning_2023a_BlueI_B.ByteUnpack_o1,
                  &APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1_k[0],
                  4);
    (void) memcpy(&APF_Path_Planning_2023a_BlueI_B.ByteUnpack_o2,
                  &APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1_k[4],
                  4);
    (void) memcpy(&APF_Path_Planning_2023a_BlueI_B.ByteUnpack_o3,
                  &APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1_k[8],
                  4);

    // MATLABSystem: '<S23>/MATLAB System' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion'
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   DataTypeConversion: '<S2>/Data Type Conversion2'

    APF_Path_Planning_2023a_BlueI_B.b_u1[56] =
      APF_Path_Planning_2023a_BlueI_B.ByteUnpack_o1;
    APF_Path_Planning_2023a_BlueI_B.b_u1[57] =
      APF_Path_Planning_2023a_BlueI_B.ByteUnpack_o2;
    APF_Path_Planning_2023a_BlueI_B.b_u1[58] =
      APF_Path_Planning_2023a_BlueI_B.ByteUnpack_o3;

    // DataStoreWrite: '<S18>/Data Store Write' incorporates:
    //   Constant: '<S18>/Constant'

    APF_Path_Planning_2023a_BlueI_B.isSim =
      APF_Path_Planning_2023a_BlueI_P.simMode;

    // If: '<Root>/Separate Phases' incorporates:
    //   Constant: '<Root>/Constant'
    //   Constant: '<Root>/Constant1'
    //   Constant: '<Root>/Constant2'
    //   Constant: '<Root>/Constant3'
    //   Constant: '<Root>/Constant4'
    //   Constant: '<Root>/Constant6'
    //   DataStoreRead: '<Root>/Universal_Time25'

    APF_Path_Planning_2023a_Blue_DW.SeparatePhases_ActiveSubsystem = -1;
    if (APF_Path_Planning_2023a_Blue_DW.Univ_Time <
        APF_Path_Planning_2023a_BlueI_P.Phase0_End) {
      APF_Path_Planning_2023a_Blue_DW.SeparatePhases_ActiveSubsystem = 0;

      // Outputs for IfAction SubSystem: '<Root>/Phase #0: Synchronization' incorporates:
      //   ActionPort: '<S6>/Action Port'

      APF_Path__Phase0Synchronization(&APF_Path_Planning_2023a_Blue_DW.BLACK_Fx,
        &APF_Path_Planning_2023a_Blue_DW.BLACK_Fy,
        &APF_Path_Planning_2023a_Blue_DW.BLACK_Tz,
        &APF_Path_Planning_2023a_Blue_DW.BLUE_Fx,
        &APF_Path_Planning_2023a_Blue_DW.BLUE_Fy,
        &APF_Path_Planning_2023a_Blue_DW.BLUE_Tz,
        &APF_Path_Planning_2023a_Blue_DW.Float_State,
        &APF_Path_Planning_2023a_Blue_DW.RED_ARM_Control_Mode,
        &APF_Path_Planning_2023a_Blue_DW.RED_Fx,
        &APF_Path_Planning_2023a_Blue_DW.RED_Fy,
        &APF_Path_Planning_2023a_Blue_DW.RED_Tz,
        &APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW,
        &APF_Path_Planning_2023a_Blue_DW.WhoAmI,
        &APF_Path_Planning_2023a_BlueI_B.isSim,
        &APF_Path_Planning_2023a_Blue_DW.Phase0Synchronization,
        &APF_Path_Planning_2023a_BlueI_P.Phase0Synchronization);

      // End of Outputs for SubSystem: '<Root>/Phase #0: Synchronization'
    } else if ((APF_Path_Planning_2023a_Blue_DW.Univ_Time <
                APF_Path_Planning_2023a_BlueI_P.Phase1_End) &&
               (APF_Path_Planning_2023a_Blue_DW.Univ_Time >=
                APF_Path_Planning_2023a_BlueI_P.Phase0_End)) {
      APF_Path_Planning_2023a_Blue_DW.SeparatePhases_ActiveSubsystem = 1;

      // Outputs for IfAction SubSystem: '<Root>/Phase #1: Start Floating ' incorporates:
      //   ActionPort: '<S7>/Action Port'

      APF_Path__Phase0Synchronization(&APF_Path_Planning_2023a_Blue_DW.BLACK_Fx,
        &APF_Path_Planning_2023a_Blue_DW.BLACK_Fy,
        &APF_Path_Planning_2023a_Blue_DW.BLACK_Tz,
        &APF_Path_Planning_2023a_Blue_DW.BLUE_Fx,
        &APF_Path_Planning_2023a_Blue_DW.BLUE_Fy,
        &APF_Path_Planning_2023a_Blue_DW.BLUE_Tz,
        &APF_Path_Planning_2023a_Blue_DW.Float_State,
        &APF_Path_Planning_2023a_Blue_DW.RED_ARM_Control_Mode,
        &APF_Path_Planning_2023a_Blue_DW.RED_Fx,
        &APF_Path_Planning_2023a_Blue_DW.RED_Fy,
        &APF_Path_Planning_2023a_Blue_DW.RED_Tz,
        &APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW,
        &APF_Path_Planning_2023a_Blue_DW.WhoAmI,
        &APF_Path_Planning_2023a_BlueI_B.isSim,
        &APF_Path_Planning_2023a_Blue_DW.Phase1StartFloating,
        &APF_Path_Planning_2023a_BlueI_P.Phase1StartFloating);

      // End of Outputs for SubSystem: '<Root>/Phase #1: Start Floating '
    } else if ((APF_Path_Planning_2023a_Blue_DW.Univ_Time <
                APF_Path_Planning_2023a_BlueI_P.Phase2_End) &&
               (APF_Path_Planning_2023a_Blue_DW.Univ_Time >=
                APF_Path_Planning_2023a_BlueI_P.Phase1_End)) {
      APF_Path_Planning_2023a_Blue_DW.SeparatePhases_ActiveSubsystem = 2;

      // Outputs for IfAction SubSystem: '<Root>/Phase #2: Initial Position' incorporates:
      //   ActionPort: '<S8>/Action Port'

      // If: '<S8>/This IF block determines whether or not to run the BLUE sim//exp' incorporates:
      //   Constant: '<S18>/Constant'
      //   DataStoreRead: '<S8>/Data Store Read'
      //   DataStoreWrite: '<S18>/Data Store Write'

      APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhether_l2 = -1;
      if ((APF_Path_Planning_2023a_Blue_DW.WhoAmI == 3.0) ||
          (APF_Path_Planning_2023a_BlueI_P.simMode == 1.0)) {
        APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhether_l2 = 0;

        // Outputs for IfAction SubSystem: '<S8>/Change BLACK Behavior' incorporates:
        //   ActionPort: '<S33>/Action Port'

        // Sum: '<S33>/Subtract' incorporates:
        //   Constant: '<S33>/Desired Px (BLACK)'
        //   DataStoreRead: '<S33>/BLACK_Px'

        APF_Path_Planning_2023a_BlueI_B.Subtract_d =
          APF_Path_Planning_2023a_BlueI_P.init_states_BLACK[0] -
          APF_Path_Planning_2023a_Blue_DW.BLACK_Px;

        // Delay: '<S42>/Delay1'
        if (APF_Path_Planning_2023a_Blue_DW.icLoad_fp) {
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_i =
            APF_Path_Planning_2023a_BlueI_B.Subtract_d;
        }

        // Sum: '<S42>/Sum6' incorporates:
        //   Delay: '<S42>/Delay1'

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_B.Subtract_d -
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_i;

        // If: '<S42>/if we went through a "step"'
        if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S42>/Hold this value' incorporates:
          //   ActionPort: '<S43>/Action Port'

          // SignalConversion generated from: '<S43>/In1'
          APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi0cdy =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S42>/Hold this value'
        }

        // End of If: '<S42>/if we went through a "step"'

        // Sum: '<S37>/Sum3' incorporates:
        //   DataStoreWrite: '<S33>/BLACK_Fx'
        //   Gain: '<S37>/kd_xb'
        //   Gain: '<S37>/kp_xb'
        //   Gain: '<S42>/divide by delta T'

        APF_Path_Planning_2023a_Blue_DW.BLACK_Fx = 1.0 /
          APF_Path_Planning_2023a_BlueI_P.baseRate *
          APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi0cdy *
          APF_Path_Planning_2023a_BlueI_P.Kd_xb +
          APF_Path_Planning_2023a_BlueI_P.Kp_xb *
          APF_Path_Planning_2023a_BlueI_B.Subtract_d;

        // Sum: '<S33>/Subtract1' incorporates:
        //   Constant: '<S33>/Desired Py (BLACK)'
        //   DataStoreRead: '<S33>/BLACK_Py '

        APF_Path_Planning_2023a_BlueI_B.Subtract1_g =
          APF_Path_Planning_2023a_BlueI_P.init_states_BLACK[1] -
          APF_Path_Planning_2023a_Blue_DW.BLACK_Py;

        // Delay: '<S44>/Delay1'
        if (APF_Path_Planning_2023a_Blue_DW.icLoad_ig) {
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_c =
            APF_Path_Planning_2023a_BlueI_B.Subtract1_g;
        }

        // Sum: '<S44>/Sum6' incorporates:
        //   Delay: '<S44>/Delay1'

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_B.Subtract1_g -
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_c;

        // If: '<S44>/if we went through a "step"'
        if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S44>/Hold this value' incorporates:
          //   ActionPort: '<S45>/Action Port'

          // SignalConversion generated from: '<S45>/In1'
          APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi0cd =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S44>/Hold this value'
        }

        // End of If: '<S44>/if we went through a "step"'

        // Sum: '<S38>/Sum3' incorporates:
        //   DataStoreWrite: '<S33>/BLACK_Fy'
        //   Gain: '<S38>/kd_yb'
        //   Gain: '<S38>/kp_yb'
        //   Gain: '<S44>/divide by delta T'

        APF_Path_Planning_2023a_Blue_DW.BLACK_Fy = 1.0 /
          APF_Path_Planning_2023a_BlueI_P.baseRate *
          APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi0cd *
          APF_Path_Planning_2023a_BlueI_P.Kd_yb +
          APF_Path_Planning_2023a_BlueI_P.Kp_yb *
          APF_Path_Planning_2023a_BlueI_B.Subtract1_g;

        // MATLAB Function: '<S39>/MATLAB Function2' incorporates:
        //   Constant: '<S33>/Desired Attitude (BLACK)'

        APF_Path_Planni_MATLABFunction2
          (APF_Path_Planning_2023a_BlueI_P.init_states_BLACK[2],
           APF_Path_Planning_2023a_BlueI_B.rtb_Oy_f_l,
           APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b);

        // MATLAB Function: '<S39>/MATLAB Function3' incorporates:
        //   DataStoreRead: '<S33>/BLACK_Rz'

        APF_Path_Planni_MATLABFunction3(APF_Path_Planning_2023a_Blue_DW.BLACK_Rz,
          APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o);

        // Sum: '<S39>/Subtract2'
        APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b[0] -=
          APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o[0];
        APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b[1] -=
          APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o[1];

        // MATLAB Function: '<S39>/MATLAB Function4'
        APF_Path_Planni_MATLABFunction4
          (APF_Path_Planning_2023a_BlueI_B.rtb_Oy_f_l,
           APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b,
           &APF_Path_Planning_2023a_BlueI_B.e_out_m);

        // Delay: '<S40>/Delay1'
        if (APF_Path_Planning_2023a_Blue_DW.icLoad_p) {
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_c1 =
            APF_Path_Planning_2023a_BlueI_B.e_out_m;
        }

        // Sum: '<S40>/Sum6' incorporates:
        //   Delay: '<S40>/Delay1'

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_B.e_out_m -
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_c1;

        // If: '<S40>/if we went through a "step"'
        if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S40>/Hold this value' incorporates:
          //   ActionPort: '<S41>/Action Port'

          // SignalConversion generated from: '<S41>/In1'
          APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi0cdyi =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S40>/Hold this value'
        }

        // End of If: '<S40>/if we went through a "step"'

        // Sum: '<S36>/Sum3' incorporates:
        //   DataStoreWrite: '<S33>/BLACK_Tz'
        //   Gain: '<S36>/kd_tb'
        //   Gain: '<S36>/kp_tb'
        //   Gain: '<S40>/divide by delta T'

        APF_Path_Planning_2023a_Blue_DW.BLACK_Tz = 1.0 /
          APF_Path_Planning_2023a_BlueI_P.baseRate *
          APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi0cdyi *
          APF_Path_Planning_2023a_BlueI_P.Kd_tb +
          APF_Path_Planning_2023a_BlueI_P.Kp_tb *
          APF_Path_Planning_2023a_BlueI_B.e_out_m;

        // DataStoreWrite: '<S33>/Data Store Write3' incorporates:
        //   Constant: '<S33>/Puck State'

        APF_Path_Planning_2023a_Blue_DW.Float_State =
          APF_Path_Planning_2023a_BlueI_P.PuckState_Value_o;

        // End of Outputs for SubSystem: '<S8>/Change BLACK Behavior'
      }

      // End of If: '<S8>/This IF block determines whether or not to run the BLUE sim//exp' 

      // If: '<S8>/This IF block determines whether or not to run the BLACK sim//exp' incorporates:
      //   Constant: '<S18>/Constant'
      //   DataStoreRead: '<S8>/Data Store Read'
      //   DataStoreWrite: '<S18>/Data Store Write'

      APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhethero_h = -1;
      if ((APF_Path_Planning_2023a_Blue_DW.WhoAmI == 2.0) ||
          (APF_Path_Planning_2023a_BlueI_P.simMode == 1.0)) {
        APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhethero_h = 0;

        // Outputs for IfAction SubSystem: '<S8>/Change BLUE Behavior' incorporates:
        //   ActionPort: '<S34>/Action Port'

        // Sum: '<S34>/Subtract' incorporates:
        //   Constant: '<S34>/Desired Px (BLUE)'
        //   DataStoreRead: '<S34>/BLUE_Px'

        APF_Path_Planning_2023a_BlueI_B.Subtract_n =
          APF_Path_Planning_2023a_BlueI_P.init_states_BLUE[0] -
          APF_Path_Planning_2023a_Blue_DW.BLUE_Px;

        // Delay: '<S55>/Delay1'
        if (APF_Path_Planning_2023a_Blue_DW.icLoad_o) {
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_mw =
            APF_Path_Planning_2023a_BlueI_B.Subtract_n;
        }

        // Sum: '<S55>/Sum6' incorporates:
        //   Delay: '<S55>/Delay1'

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_B.Subtract_n -
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_mw;

        // If: '<S55>/if we went through a "step"'
        if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S55>/Hold this value' incorporates:
          //   ActionPort: '<S56>/Action Port'

          // SignalConversion generated from: '<S56>/In1'
          APF_Path_Planning_2023a_BlueI_B.In1_e =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S55>/Hold this value'
        }

        // End of If: '<S55>/if we went through a "step"'

        // Sum: '<S50>/Sum3' incorporates:
        //   DataStoreWrite: '<S34>/BLUE_Fx'
        //   Gain: '<S50>/kd_xb'
        //   Gain: '<S50>/kp_xb'
        //   Gain: '<S55>/divide by delta T'

        APF_Path_Planning_2023a_Blue_DW.BLUE_Fx = 1.0 /
          APF_Path_Planning_2023a_BlueI_P.baseRate *
          APF_Path_Planning_2023a_BlueI_B.In1_e *
          APF_Path_Planning_2023a_BlueI_P.Kd_xblue +
          APF_Path_Planning_2023a_BlueI_P.Kp_xblue *
          APF_Path_Planning_2023a_BlueI_B.Subtract_n;

        // Sum: '<S34>/Subtract1' incorporates:
        //   Constant: '<S34>/Desired Py (BLUE)'
        //   DataStoreRead: '<S34>/BLUE_Py '

        APF_Path_Planning_2023a_BlueI_B.Subtract1_ld =
          APF_Path_Planning_2023a_BlueI_P.init_states_BLUE[1] -
          APF_Path_Planning_2023a_Blue_DW.BLUE_Py;

        // Delay: '<S57>/Delay1'
        if (APF_Path_Planning_2023a_Blue_DW.icLoad_n) {
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_et =
            APF_Path_Planning_2023a_BlueI_B.Subtract1_ld;
        }

        // Sum: '<S57>/Sum6' incorporates:
        //   Delay: '<S57>/Delay1'

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_B.Subtract1_ld -
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_et;

        // If: '<S57>/if we went through a "step"'
        if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S57>/Hold this value' incorporates:
          //   ActionPort: '<S58>/Action Port'

          // SignalConversion generated from: '<S58>/In1'
          APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi0cdyix =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S57>/Hold this value'
        }

        // End of If: '<S57>/if we went through a "step"'

        // Sum: '<S51>/Sum3' incorporates:
        //   DataStoreWrite: '<S34>/BLUE_Fy'
        //   Gain: '<S51>/kd_yb'
        //   Gain: '<S51>/kp_yb'
        //   Gain: '<S57>/divide by delta T'

        APF_Path_Planning_2023a_Blue_DW.BLUE_Fy = 1.0 /
          APF_Path_Planning_2023a_BlueI_P.baseRate *
          APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi0cdyix *
          APF_Path_Planning_2023a_BlueI_P.Kd_yblue +
          APF_Path_Planning_2023a_BlueI_P.Kp_yblue *
          APF_Path_Planning_2023a_BlueI_B.Subtract1_ld;

        // MATLAB Function: '<S52>/MATLAB Function2' incorporates:
        //   Constant: '<S34>/Desired Attitude (BLUE)'

        APF_Path_Planni_MATLABFunction2
          (APF_Path_Planning_2023a_BlueI_P.init_states_BLUE[2],
           APF_Path_Planning_2023a_BlueI_B.rtb_Oy_f_l,
           APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b);

        // MATLAB Function: '<S52>/MATLAB Function3' incorporates:
        //   DataStoreRead: '<S34>/BLUE_Rz'

        APF_Path_Planni_MATLABFunction3(APF_Path_Planning_2023a_Blue_DW.BLUE_Rz,
          APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o);

        // Sum: '<S52>/Subtract2'
        APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b[0] -=
          APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o[0];
        APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b[1] -=
          APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o[1];

        // MATLAB Function: '<S52>/MATLAB Function4'
        APF_Path_Planni_MATLABFunction4
          (APF_Path_Planning_2023a_BlueI_B.rtb_Oy_f_l,
           APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b,
           &APF_Path_Planning_2023a_BlueI_B.e_out_md);

        // Delay: '<S53>/Delay1'
        if (APF_Path_Planning_2023a_Blue_DW.icLoad_bb) {
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_av =
            APF_Path_Planning_2023a_BlueI_B.e_out_md;
        }

        // Sum: '<S53>/Sum6' incorporates:
        //   Delay: '<S53>/Delay1'

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_B.e_out_md -
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_av;

        // If: '<S53>/if we went through a "step"'
        if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S53>/Hold this value' incorporates:
          //   ActionPort: '<S54>/Action Port'

          // SignalConversion generated from: '<S54>/In1'
          APF_Path_Planning_2023a_BlueI_B.In1_o =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S53>/Hold this value'
        }

        // End of If: '<S53>/if we went through a "step"'

        // Sum: '<S49>/Sum3' incorporates:
        //   DataStoreWrite: '<S34>/BLUE_Tz'
        //   Gain: '<S49>/kd_tb'
        //   Gain: '<S49>/kp_tb'
        //   Gain: '<S53>/divide by delta T'

        APF_Path_Planning_2023a_Blue_DW.BLUE_Tz = 1.0 /
          APF_Path_Planning_2023a_BlueI_P.baseRate *
          APF_Path_Planning_2023a_BlueI_B.In1_o *
          APF_Path_Planning_2023a_BlueI_P.Kd_tblue +
          APF_Path_Planning_2023a_BlueI_P.Kp_tblue *
          APF_Path_Planning_2023a_BlueI_B.e_out_md;

        // DataStoreWrite: '<S34>/Data Store Write3' incorporates:
        //   Constant: '<S34>/Puck State'

        APF_Path_Planning_2023a_Blue_DW.Float_State =
          APF_Path_Planning_2023a_BlueI_P.PuckState_Value;

        // End of Outputs for SubSystem: '<S8>/Change BLUE Behavior'
      }

      // End of If: '<S8>/This IF block determines whether or not to run the BLACK sim//exp' 

      // If: '<S8>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
      //   Constant: '<S18>/Constant'
      //   DataStoreRead: '<S8>/Data Store Read'
      //   DataStoreWrite: '<S18>/Data Store Write'

      APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhethero_g = -1;
      if ((APF_Path_Planning_2023a_Blue_DW.WhoAmI == 1.0) ||
          (APF_Path_Planning_2023a_BlueI_P.simMode == 1.0)) {
        APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhethero_g = 0;

        // Outputs for IfAction SubSystem: '<S8>/Change RED Behavior' incorporates:
        //   ActionPort: '<S35>/Action Port'

        // MATLAB Function: '<S65>/MATLAB Function2' incorporates:
        //   Constant: '<S35>/Constant'

        APF_Path_Planni_MATLABFunction2
          (APF_Path_Planning_2023a_BlueI_P.init_states_RED[2],
           APF_Path_Planning_2023a_BlueI_B.rtb_Oy_f_l,
           APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b);

        // MATLAB Function: '<S65>/MATLAB Function3' incorporates:
        //   DataStoreRead: '<S35>/RED_Rz'

        APF_Path_Planni_MATLABFunction3(APF_Path_Planning_2023a_Blue_DW.RED_Rz,
          APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o);

        // Sum: '<S65>/Subtract2'
        APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b[0] -=
          APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o[0];
        APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b[1] -=
          APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o[1];

        // MATLAB Function: '<S65>/MATLAB Function4'
        APF_Path_Planni_MATLABFunction4
          (APF_Path_Planning_2023a_BlueI_B.rtb_Oy_f_l,
           APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b,
           &APF_Path_Planning_2023a_BlueI_B.e_out_k);

        // Delay: '<S67>/Delay1'
        if (APF_Path_Planning_2023a_Blue_DW.icLoad_g) {
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_gi =
            APF_Path_Planning_2023a_BlueI_B.e_out_k;
        }

        // Sum: '<S67>/Sum6' incorporates:
        //   Delay: '<S67>/Delay1'

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_B.e_out_k -
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_gi;

        // If: '<S67>/if we went through a "step"'
        if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S67>/Hold this value' incorporates:
          //   ActionPort: '<S68>/Action Port'

          // SignalConversion generated from: '<S68>/In1'
          APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi0c =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S67>/Hold this value'
        }

        // End of If: '<S67>/if we went through a "step"'

        // Sum: '<S62>/Sum3' incorporates:
        //   DataStoreWrite: '<S35>/RED_Tz'
        //   Gain: '<S62>/kd_tr'
        //   Gain: '<S62>/kp_tr'
        //   Gain: '<S67>/divide by delta T'

        APF_Path_Planning_2023a_Blue_DW.RED_Tz = 1.0 /
          APF_Path_Planning_2023a_BlueI_P.baseRate *
          APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi0c *
          APF_Path_Planning_2023a_BlueI_P.Kd_tr +
          APF_Path_Planning_2023a_BlueI_P.Kp_tr *
          APF_Path_Planning_2023a_BlueI_B.e_out_k;

        // Sum: '<S35>/Subtract' incorporates:
        //   Constant: '<S35>/Constant1'
        //   DataStoreRead: '<S35>/RED_Px'

        APF_Path_Planning_2023a_BlueI_B.Subtract_j =
          APF_Path_Planning_2023a_BlueI_P.init_states_RED[0] -
          APF_Path_Planning_2023a_Blue_DW.RED_Px;

        // Delay: '<S69>/Delay1'
        if (APF_Path_Planning_2023a_Blue_DW.icLoad_a) {
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_m =
            APF_Path_Planning_2023a_BlueI_B.Subtract_j;
        }

        // Sum: '<S69>/Sum6' incorporates:
        //   Delay: '<S69>/Delay1'

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_B.Subtract_j -
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_m;

        // If: '<S69>/if we went through a "step"'
        if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S69>/Hold this value' incorporates:
          //   ActionPort: '<S70>/Action Port'

          // SignalConversion generated from: '<S70>/In1'
          APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi0 =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S69>/Hold this value'
        }

        // End of If: '<S69>/if we went through a "step"'

        // Sum: '<S63>/Sum3' incorporates:
        //   DataStoreWrite: '<S35>/RED_Fx'
        //   Gain: '<S63>/kd_xr'
        //   Gain: '<S63>/kp_xr'
        //   Gain: '<S69>/divide by delta T'

        APF_Path_Planning_2023a_Blue_DW.RED_Fx = 1.0 /
          APF_Path_Planning_2023a_BlueI_P.baseRate *
          APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi0 *
          APF_Path_Planning_2023a_BlueI_P.Kd_xr +
          APF_Path_Planning_2023a_BlueI_P.Kp_xr *
          APF_Path_Planning_2023a_BlueI_B.Subtract_j;

        // Sum: '<S35>/Subtract1' incorporates:
        //   Constant: '<S35>/Constant3'
        //   DataStoreRead: '<S35>/RED_Py '

        APF_Path_Planning_2023a_BlueI_B.Subtract1_n =
          APF_Path_Planning_2023a_BlueI_P.init_states_RED[1] -
          APF_Path_Planning_2023a_Blue_DW.RED_Py;

        // Delay: '<S71>/Delay1'
        if (APF_Path_Planning_2023a_Blue_DW.icLoad_b) {
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_ej =
            APF_Path_Planning_2023a_BlueI_B.Subtract1_n;
        }

        // Sum: '<S71>/Sum6' incorporates:
        //   Delay: '<S71>/Delay1'

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_B.Subtract1_n -
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_ej;

        // If: '<S71>/if we went through a "step"'
        if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S71>/Hold this value' incorporates:
          //   ActionPort: '<S72>/Action Port'

          // SignalConversion generated from: '<S72>/In1'
          APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S71>/Hold this value'
        }

        // End of If: '<S71>/if we went through a "step"'

        // Sum: '<S64>/Sum3' incorporates:
        //   DataStoreWrite: '<S35>/RED_Fy'
        //   Gain: '<S64>/kd_yr'
        //   Gain: '<S64>/kp_yr'
        //   Gain: '<S71>/divide by delta T'

        APF_Path_Planning_2023a_Blue_DW.RED_Fy = 1.0 /
          APF_Path_Planning_2023a_BlueI_P.baseRate *
          APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi *
          APF_Path_Planning_2023a_BlueI_P.Kd_yr +
          APF_Path_Planning_2023a_BlueI_P.Kp_yr *
          APF_Path_Planning_2023a_BlueI_B.Subtract1_n;

        // DataStoreWrite: '<S35>/Data Store Write3' incorporates:
        //   Constant: '<S35>/Puck State'

        APF_Path_Planning_2023a_Blue_DW.Float_State =
          APF_Path_Planning_2023a_BlueI_P.PuckState_Value_h;

        // If: '<S35>/If' incorporates:
        //   Constant: '<S35>/Constant4'

        if ((APF_Path_Planning_2023a_BlueI_P.platformSelection == 4.0) ||
            (APF_Path_Planning_2023a_BlueI_P.platformSelection == 5.0) ||
            (APF_Path_Planning_2023a_BlueI_P.platformSelection == 10.0) ||
            (APF_Path_Planning_2023a_BlueI_P.platformSelection == 11.0)) {
          // Outputs for IfAction SubSystem: '<S35>/RED+ARM' incorporates:
          //   ActionPort: '<S66>/Action Port'

          APF_Path_Planning_2023a__REDARM
            (&APF_Path_Planning_2023a_Blue_DW.RED_ARM_Control_Mode,
             &APF_Path_Planning_2023a_Blue_DW.RED_Elbow_Command,
             &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Elbow,
             &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder,
             &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Wrist,
             &APF_Path_Planning_2023a_Blue_DW.RED_Shoulder_Command,
             &APF_Path_Planning_2023a_Blue_DW.RED_Wrist_Command,
             &APF_Path_Planning_2023a_BlueI_B.isSim,
             &APF_Path_Planning_2023a_BlueI_B.REDARM_e,
             &APF_Path_Planning_2023a_Blue_DW.REDARM_e,
             &APF_Path_Planning_2023a_BlueI_P.REDARM_e);

          // End of Outputs for SubSystem: '<S35>/RED+ARM'
        }

        // End of If: '<S35>/If'
        // End of Outputs for SubSystem: '<S8>/Change RED Behavior'
      }

      // End of If: '<S8>/This IF block determines whether or not to run the RED sim//exp ' 
      // End of Outputs for SubSystem: '<Root>/Phase #2: Initial Position'
    } else if ((APF_Path_Planning_2023a_Blue_DW.Univ_Time <
                APF_Path_Planning_2023a_BlueI_P.Phase3_End) &&
               (APF_Path_Planning_2023a_Blue_DW.Univ_Time >=
                APF_Path_Planning_2023a_BlueI_P.Phase2_End)) {
      APF_Path_Planning_2023a_Blue_DW.SeparatePhases_ActiveSubsystem = 3;

      // Outputs for IfAction SubSystem: '<Root>/Phase #3: Experiment' incorporates:
      //   ActionPort: '<S9>/Action Port'

      // If: '<S9>/This IF block determines whether or not to run the BLACK sim//exp' incorporates:
      //   Constant: '<S18>/Constant'
      //   DataStoreRead: '<S9>/Data Store Read'
      //   DataStoreWrite: '<S18>/Data Store Write'

      APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhethero_n = -1;
      if ((APF_Path_Planning_2023a_Blue_DW.WhoAmI == 2.0) ||
          (APF_Path_Planning_2023a_BlueI_P.simMode == 1.0)) {
        APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhethero_n = 0;

        // Outputs for IfAction SubSystem: '<S9>/Change BLACK Behavior' incorporates:
        //   ActionPort: '<S87>/Action Port'

        // If: '<S87>/Experiment Sub-Phases' incorporates:
        //   Constant: '<S87>/Constant1'
        //   Constant: '<S87>/Constant2'
        //   Constant: '<S87>/Constant3'
        //   Constant: '<S87>/Constant4'
        //   DataStoreRead: '<S87>/Universal_Time'

        APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSub_l = -1;
        if (APF_Path_Planning_2023a_Blue_DW.Univ_Time <
            APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase1_End) {
          APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSub_l = 0;

          // Outputs for IfAction SubSystem: '<S87>/Sub-Phase #1' incorporates:
          //   ActionPort: '<S90>/Action Port'

          APF_Path_Planning_202_SubPhase1
            (&APF_Path_Planning_2023a_Blue_DW.BLACK_Fx,
             &APF_Path_Planning_2023a_Blue_DW.BLACK_Fy,
             &APF_Path_Planning_2023a_Blue_DW.BLACK_Px,
             &APF_Path_Planning_2023a_Blue_DW.BLACK_Py,
             &APF_Path_Planning_2023a_Blue_DW.BLACK_Rz,
             &APF_Path_Planning_2023a_Blue_DW.BLACK_Tz,
             &APF_Path_Planning_2023a_Blue_DW.Float_State,
             &APF_Path_Planning_2023a_Blue_DW.Univ_Time,
             &APF_Path_Planning_2023a_BlueI_B.SubPhase1,
             &APF_Path_Planning_2023a_Blue_DW.SubPhase1,
             &APF_Path_Planning_2023a_BlueI_P.SubPhase1);

          // End of Outputs for SubSystem: '<S87>/Sub-Phase #1'
        } else if ((APF_Path_Planning_2023a_Blue_DW.Univ_Time <
                    APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase2_End) &&
                   (APF_Path_Planning_2023a_Blue_DW.Univ_Time >=
                    APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase1_End)) {
          APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSub_l = 1;

          // Outputs for IfAction SubSystem: '<S87>/Sub-Phase #2 ' incorporates:
          //   ActionPort: '<S91>/Action Port'

          APF_Path_Planning_202_SubPhase1
            (&APF_Path_Planning_2023a_Blue_DW.BLACK_Fx,
             &APF_Path_Planning_2023a_Blue_DW.BLACK_Fy,
             &APF_Path_Planning_2023a_Blue_DW.BLACK_Px,
             &APF_Path_Planning_2023a_Blue_DW.BLACK_Py,
             &APF_Path_Planning_2023a_Blue_DW.BLACK_Rz,
             &APF_Path_Planning_2023a_Blue_DW.BLACK_Tz,
             &APF_Path_Planning_2023a_Blue_DW.Float_State,
             &APF_Path_Planning_2023a_Blue_DW.Univ_Time,
             &APF_Path_Planning_2023a_BlueI_B.SubPhase2,
             &APF_Path_Planning_2023a_Blue_DW.SubPhase2,
             &APF_Path_Planning_2023a_BlueI_P.SubPhase2);

          // End of Outputs for SubSystem: '<S87>/Sub-Phase #2 '
        } else if ((APF_Path_Planning_2023a_Blue_DW.Univ_Time <
                    APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase3_End) &&
                   (APF_Path_Planning_2023a_Blue_DW.Univ_Time >=
                    APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase2_End)) {
          APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSub_l = 2;

          // Outputs for IfAction SubSystem: '<S87>/Sub-Phase #3 ' incorporates:
          //   ActionPort: '<S92>/Action Port'

          APF_Path_Planning_202_SubPhase1
            (&APF_Path_Planning_2023a_Blue_DW.BLACK_Fx,
             &APF_Path_Planning_2023a_Blue_DW.BLACK_Fy,
             &APF_Path_Planning_2023a_Blue_DW.BLACK_Px,
             &APF_Path_Planning_2023a_Blue_DW.BLACK_Py,
             &APF_Path_Planning_2023a_Blue_DW.BLACK_Rz,
             &APF_Path_Planning_2023a_Blue_DW.BLACK_Tz,
             &APF_Path_Planning_2023a_Blue_DW.Float_State,
             &APF_Path_Planning_2023a_Blue_DW.Univ_Time,
             &APF_Path_Planning_2023a_BlueI_B.SubPhase3,
             &APF_Path_Planning_2023a_Blue_DW.SubPhase3,
             &APF_Path_Planning_2023a_BlueI_P.SubPhase3);

          // End of Outputs for SubSystem: '<S87>/Sub-Phase #3 '
        } else if ((APF_Path_Planning_2023a_Blue_DW.Univ_Time <
                    APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase4_End) &&
                   (APF_Path_Planning_2023a_Blue_DW.Univ_Time >=
                    APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase3_End)) {
          APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSub_l = 3;

          // Outputs for IfAction SubSystem: '<S87>/Sub-Phase #4' incorporates:
          //   ActionPort: '<S93>/Action Port'

          // Step: '<S149>/End Time' incorporates:
          //   Step: '<S150>/End Time'
          //   Step: '<S151>/End Time'

          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
            APF_Path_Planning_2023a_Blue_M->Timing.t[0];
          if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW <
              APF_Path_Planning_2023a_BlueI_P.end_time_black) {
            APF_Path_Planning_2023a_BlueI_B.Sum6_a =
              APF_Path_Planning_2023a_BlueI_P.EndTime_Y0;
          } else {
            APF_Path_Planning_2023a_BlueI_B.Sum6_a =
              APF_Path_Planning_2023a_BlueI_P.EndTime_YFinal;
          }

          // Switch: '<S149>/Switch' incorporates:
          //   Constant: '<S149>/End Pos'
          //   DiscreteIntegrator: '<S149>/Start Pos'
          //   Step: '<S149>/End Time'

          if (APF_Path_Planning_2023a_BlueI_B.Sum6_a >
              APF_Path_Planning_2023a_BlueI_P.Switch_Threshold) {
            APF_Path_Planning_2023a_BlueI_B.Sum6_a =
              APF_Path_Planning_2023a_Blue_DW.StartPos_DSTATE_p;
          } else {
            APF_Path_Planning_2023a_BlueI_B.Sum6_a =
              APF_Path_Planning_2023a_BlueI_P.BLACK_end[0];
          }

          // Sum: '<S93>/Subtract' incorporates:
          //   DataStoreRead: '<S93>/BLACK_Px'
          //   Switch: '<S149>/Switch'

          APF_Path_Planning_2023a_BlueI_B.Subtract_k =
            APF_Path_Planning_2023a_BlueI_B.Sum6_a -
            APF_Path_Planning_2023a_Blue_DW.BLACK_Px;

          // Delay: '<S154>/Delay1'
          if (APF_Path_Planning_2023a_Blue_DW.icLoad_c) {
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_p =
              APF_Path_Planning_2023a_BlueI_B.Subtract_k;
          }

          // Sum: '<S154>/Sum6' incorporates:
          //   Delay: '<S154>/Delay1'

          APF_Path_Planning_2023a_BlueI_B.Sum6_a =
            APF_Path_Planning_2023a_BlueI_B.Subtract_k -
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_p;

          // If: '<S154>/if we went through a "step"'
          if (APF_Path_Planning_2023a_BlueI_B.Sum6_a != 0.0) {
            // Outputs for IfAction SubSystem: '<S154>/Hold this value' incorporates:
            //   ActionPort: '<S155>/Action Port'

            // SignalConversion generated from: '<S155>/In1'
            APF_Path_Planning_2023a_BlueI_B.In1_g20asdt =
              APF_Path_Planning_2023a_BlueI_B.Sum6_a;

            // End of Outputs for SubSystem: '<S154>/Hold this value'
          }

          // End of If: '<S154>/if we went through a "step"'

          // Sum: '<S146>/Sum3' incorporates:
          //   DataStoreWrite: '<S93>/BLACK_Fx'
          //   Gain: '<S146>/kd_xb'
          //   Gain: '<S146>/kp_xb'
          //   Gain: '<S154>/divide by delta T'

          APF_Path_Planning_2023a_Blue_DW.BLACK_Fx = 1.0 /
            APF_Path_Planning_2023a_BlueI_P.baseRate *
            APF_Path_Planning_2023a_BlueI_B.In1_g20asdt *
            APF_Path_Planning_2023a_BlueI_P.Kd_xb +
            APF_Path_Planning_2023a_BlueI_P.Kp_xb *
            APF_Path_Planning_2023a_BlueI_B.Subtract_k;

          // Step: '<S150>/End Time'
          if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW <
              APF_Path_Planning_2023a_BlueI_P.end_time_black) {
            APF_Path_Planning_2023a_BlueI_B.Sum6_a =
              APF_Path_Planning_2023a_BlueI_P.EndTime_Y0_f;
          } else {
            APF_Path_Planning_2023a_BlueI_B.Sum6_a =
              APF_Path_Planning_2023a_BlueI_P.EndTime_YFinal_h;
          }

          // Switch: '<S150>/Switch' incorporates:
          //   Constant: '<S150>/End Pos'
          //   DiscreteIntegrator: '<S150>/Start Pos'
          //   Step: '<S150>/End Time'

          if (APF_Path_Planning_2023a_BlueI_B.Sum6_a >
              APF_Path_Planning_2023a_BlueI_P.Switch_Threshold_g) {
            APF_Path_Planning_2023a_BlueI_B.Sum6_a =
              APF_Path_Planning_2023a_Blue_DW.StartPos_DSTATE_b;
          } else {
            APF_Path_Planning_2023a_BlueI_B.Sum6_a =
              APF_Path_Planning_2023a_BlueI_P.BLACK_end[1];
          }

          // Sum: '<S93>/Subtract1' incorporates:
          //   DataStoreRead: '<S93>/BLACK_Py '
          //   Switch: '<S150>/Switch'

          APF_Path_Planning_2023a_BlueI_B.Subtract1_l =
            APF_Path_Planning_2023a_BlueI_B.Sum6_a -
            APF_Path_Planning_2023a_Blue_DW.BLACK_Py;

          // Delay: '<S156>/Delay1'
          if (APF_Path_Planning_2023a_Blue_DW.icLoad_j) {
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_na =
              APF_Path_Planning_2023a_BlueI_B.Subtract1_l;
          }

          // Sum: '<S156>/Sum6' incorporates:
          //   Delay: '<S156>/Delay1'

          APF_Path_Planning_2023a_BlueI_B.Sum6_a =
            APF_Path_Planning_2023a_BlueI_B.Subtract1_l -
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_na;

          // If: '<S156>/if we went through a "step"'
          if (APF_Path_Planning_2023a_BlueI_B.Sum6_a != 0.0) {
            // Outputs for IfAction SubSystem: '<S156>/Hold this value' incorporates:
            //   ActionPort: '<S157>/Action Port'

            // SignalConversion generated from: '<S157>/In1'
            APF_Path_Planning_2023a_BlueI_B.In1_g20asd =
              APF_Path_Planning_2023a_BlueI_B.Sum6_a;

            // End of Outputs for SubSystem: '<S156>/Hold this value'
          }

          // End of If: '<S156>/if we went through a "step"'

          // Sum: '<S147>/Sum3' incorporates:
          //   DataStoreWrite: '<S93>/BLACK_Fy'
          //   Gain: '<S147>/kd_yb'
          //   Gain: '<S147>/kp_yb'
          //   Gain: '<S156>/divide by delta T'

          APF_Path_Planning_2023a_Blue_DW.BLACK_Fy = 1.0 /
            APF_Path_Planning_2023a_BlueI_P.baseRate *
            APF_Path_Planning_2023a_BlueI_B.In1_g20asd *
            APF_Path_Planning_2023a_BlueI_P.Kd_yb +
            APF_Path_Planning_2023a_BlueI_P.Kp_yb *
            APF_Path_Planning_2023a_BlueI_B.Subtract1_l;

          // Step: '<S151>/End Time'
          if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW <
              APF_Path_Planning_2023a_BlueI_P.end_time_black) {
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
              APF_Path_Planning_2023a_BlueI_P.EndTime_Y0_c;
          } else {
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
              APF_Path_Planning_2023a_BlueI_P.EndTime_YFinal_c;
          }

          // Switch: '<S151>/Switch' incorporates:
          //   Constant: '<S151>/End Pos'
          //   DiscreteIntegrator: '<S151>/Start Pos'
          //   Step: '<S151>/End Time'

          if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW >
              APF_Path_Planning_2023a_BlueI_P.Switch_Threshold_o) {
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
              APF_Path_Planning_2023a_Blue_DW.StartPos_DSTATE_l;
          } else {
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
              APF_Path_Planning_2023a_BlueI_P.BLACK_end[2];
          }

          // MATLAB Function: '<S148>/MATLAB Function2' incorporates:
          //   Switch: '<S151>/Switch'

          APF_Path_Planni_MATLABFunction2
            (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW,
             APF_Path_Planning_2023a_BlueI_B.rtb_Oy_f_l,
             APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b);

          // MATLAB Function: '<S148>/MATLAB Function3' incorporates:
          //   DataStoreRead: '<S93>/BLACK_Rz'

          APF_Path_Planni_MATLABFunction3
            (APF_Path_Planning_2023a_Blue_DW.BLACK_Rz,
             APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o);

          // Sum: '<S148>/Subtract2'
          APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b[0] -=
            APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o[0];
          APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b[1] -=
            APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o[1];

          // MATLAB Function: '<S148>/MATLAB Function4'
          APF_Path_Planni_MATLABFunction4
            (APF_Path_Planning_2023a_BlueI_B.rtb_Oy_f_l,
             APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b,
             &APF_Path_Planning_2023a_BlueI_B.e_out_b);

          // Delay: '<S152>/Delay1'
          if (APF_Path_Planning_2023a_Blue_DW.icLoad_fo) {
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_p2 =
              APF_Path_Planning_2023a_BlueI_B.e_out_b;
          }

          // Sum: '<S152>/Sum6' incorporates:
          //   Delay: '<S152>/Delay1'

          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
            APF_Path_Planning_2023a_BlueI_B.e_out_b -
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_p2;

          // If: '<S152>/if we went through a "step"'
          if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
            // Outputs for IfAction SubSystem: '<S152>/Hold this value' incorporates:
            //   ActionPort: '<S153>/Action Port'

            // SignalConversion generated from: '<S153>/In1'
            APF_Path_Planning_2023a_BlueI_B.In1_g20asdtg =
              APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

            // End of Outputs for SubSystem: '<S152>/Hold this value'
          }

          // End of If: '<S152>/if we went through a "step"'

          // Sum: '<S145>/Sum3' incorporates:
          //   DataStoreWrite: '<S93>/BLACK_Tz'
          //   Gain: '<S145>/kd_tb'
          //   Gain: '<S145>/kp_tb'
          //   Gain: '<S152>/divide by delta T'

          APF_Path_Planning_2023a_Blue_DW.BLACK_Tz = 1.0 /
            APF_Path_Planning_2023a_BlueI_P.baseRate *
            APF_Path_Planning_2023a_BlueI_B.In1_g20asdtg *
            APF_Path_Planning_2023a_BlueI_P.Kd_tb +
            APF_Path_Planning_2023a_BlueI_P.Kp_tb *
            APF_Path_Planning_2023a_BlueI_B.e_out_b;

          // DataStoreWrite: '<S93>/Data Store Write3' incorporates:
          //   Constant: '<S93>/Puck State'

          APF_Path_Planning_2023a_Blue_DW.Float_State =
            APF_Path_Planning_2023a_BlueI_P.PuckState_Value_c;

          // End of Outputs for SubSystem: '<S87>/Sub-Phase #4'
        }

        // End of If: '<S87>/Experiment Sub-Phases'
        // End of Outputs for SubSystem: '<S9>/Change BLACK Behavior'
      }

      // End of If: '<S9>/This IF block determines whether or not to run the BLACK sim//exp' 

      // If: '<S9>/This IF block determines whether or not to run the BLUE sim//exp' incorporates:
      //   Constant: '<S18>/Constant'
      //   DataStoreRead: '<S9>/Data Store Read'
      //   DataStoreWrite: '<S18>/Data Store Write'

      APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhethero_a = -1;
      if ((APF_Path_Planning_2023a_Blue_DW.WhoAmI == 3.0) ||
          (APF_Path_Planning_2023a_BlueI_P.simMode == 1.0)) {
        APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhethero_a = 0;

        // Outputs for IfAction SubSystem: '<S9>/Change BLUE Behavior' incorporates:
        //   ActionPort: '<S88>/Action Port'

        // If: '<S88>/Experiment Sub-Phases' incorporates:
        //   Constant: '<S88>/Constant1'
        //   Constant: '<S88>/Constant2'
        //   Constant: '<S88>/Constant3'
        //   Constant: '<S88>/Constant4'
        //   DataStoreRead: '<S88>/Universal_Time'

        APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSub_c = -1;
        if (APF_Path_Planning_2023a_Blue_DW.Univ_Time <
            APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase1_End) {
          APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSub_c = 0;

          // Outputs for IfAction SubSystem: '<S88>/Sub-Phase #1' incorporates:
          //   ActionPort: '<S161>/Action Port'

          APF_Path_Planning_2_SubPhase1_g
            (&APF_Path_Planning_2023a_Blue_DW.BLUE_Fx,
             &APF_Path_Planning_2023a_Blue_DW.BLUE_Fy,
             &APF_Path_Planning_2023a_Blue_DW.BLUE_Px,
             &APF_Path_Planning_2023a_Blue_DW.BLUE_Py,
             &APF_Path_Planning_2023a_Blue_DW.BLUE_Rz,
             &APF_Path_Planning_2023a_Blue_DW.BLUE_Tz,
             &APF_Path_Planning_2023a_Blue_DW.Float_State,
             &APF_Path_Planning_2023a_Blue_DW.Univ_Time,
             &APF_Path_Planning_2023a_BlueI_B.SubPhase1_g,
             &APF_Path_Planning_2023a_Blue_DW.SubPhase1_g,
             &APF_Path_Planning_2023a_BlueI_P.SubPhase1_g);

          // End of Outputs for SubSystem: '<S88>/Sub-Phase #1'
        } else if ((APF_Path_Planning_2023a_Blue_DW.Univ_Time <
                    APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase2_End) &&
                   (APF_Path_Planning_2023a_Blue_DW.Univ_Time >=
                    APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase1_End)) {
          APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSub_c = 1;

          // Outputs for IfAction SubSystem: '<S88>/Sub-Phase #2 ' incorporates:
          //   ActionPort: '<S163>/Action Port'

          APF_Path_Planning_2_SubPhase1_g
            (&APF_Path_Planning_2023a_Blue_DW.BLUE_Fx,
             &APF_Path_Planning_2023a_Blue_DW.BLUE_Fy,
             &APF_Path_Planning_2023a_Blue_DW.BLUE_Px,
             &APF_Path_Planning_2023a_Blue_DW.BLUE_Py,
             &APF_Path_Planning_2023a_Blue_DW.BLUE_Rz,
             &APF_Path_Planning_2023a_Blue_DW.BLUE_Tz,
             &APF_Path_Planning_2023a_Blue_DW.Float_State,
             &APF_Path_Planning_2023a_Blue_DW.Univ_Time,
             &APF_Path_Planning_2023a_BlueI_B.SubPhase2_c,
             &APF_Path_Planning_2023a_Blue_DW.SubPhase2_c,
             &APF_Path_Planning_2023a_BlueI_P.SubPhase2_c);

          // End of Outputs for SubSystem: '<S88>/Sub-Phase #2 '
        } else if ((APF_Path_Planning_2023a_Blue_DW.Univ_Time <
                    APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase3_End) &&
                   (APF_Path_Planning_2023a_Blue_DW.Univ_Time >=
                    APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase2_End)) {
          APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSub_c = 2;

          // Outputs for IfAction SubSystem: '<S88>/Sub-Phase #3 ' incorporates:
          //   ActionPort: '<S164>/Action Port'

          APF_Path_Planning_2_SubPhase1_g
            (&APF_Path_Planning_2023a_Blue_DW.BLUE_Fx,
             &APF_Path_Planning_2023a_Blue_DW.BLUE_Fy,
             &APF_Path_Planning_2023a_Blue_DW.BLUE_Px,
             &APF_Path_Planning_2023a_Blue_DW.BLUE_Py,
             &APF_Path_Planning_2023a_Blue_DW.BLUE_Rz,
             &APF_Path_Planning_2023a_Blue_DW.BLUE_Tz,
             &APF_Path_Planning_2023a_Blue_DW.Float_State,
             &APF_Path_Planning_2023a_Blue_DW.Univ_Time,
             &APF_Path_Planning_2023a_BlueI_B.SubPhase3_e,
             &APF_Path_Planning_2023a_Blue_DW.SubPhase3_e,
             &APF_Path_Planning_2023a_BlueI_P.SubPhase3_e);

          // End of Outputs for SubSystem: '<S88>/Sub-Phase #3 '
        } else if ((APF_Path_Planning_2023a_Blue_DW.Univ_Time <
                    APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase4_End) &&
                   (APF_Path_Planning_2023a_Blue_DW.Univ_Time >=
                    APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase3_End)) {
          APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSub_c = 3;

          // Outputs for IfAction SubSystem: '<S88>/Sub-Phase #2' incorporates:
          //   ActionPort: '<S162>/Action Port'

          // Step: '<S190>/End Time' incorporates:
          //   Step: '<S191>/End Time'
          //   Step: '<S192>/End Time'

          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
            APF_Path_Planning_2023a_Blue_M->Timing.t[0];
          if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW <
              APF_Path_Planning_2023a_BlueI_P.end_time_black) {
            APF_Path_Planning_2023a_BlueI_B.Sum6_a =
              APF_Path_Planning_2023a_BlueI_P.EndTime_Y0_k;
          } else {
            APF_Path_Planning_2023a_BlueI_B.Sum6_a =
              APF_Path_Planning_2023a_BlueI_P.EndTime_YFinal_e;
          }

          // Switch: '<S190>/Switch' incorporates:
          //   Constant: '<S190>/End Pos'
          //   DiscreteIntegrator: '<S190>/Start Pos'
          //   Step: '<S190>/End Time'

          if (APF_Path_Planning_2023a_BlueI_B.Sum6_a >
              APF_Path_Planning_2023a_BlueI_P.Switch_Threshold_j) {
            APF_Path_Planning_2023a_BlueI_B.Sum6_a =
              APF_Path_Planning_2023a_Blue_DW.StartPos_DSTATE;
          } else {
            APF_Path_Planning_2023a_BlueI_B.Sum6_a =
              APF_Path_Planning_2023a_BlueI_P.BLACK_end[0];
          }

          // Sum: '<S162>/Subtract' incorporates:
          //   DataStoreRead: '<S162>/BLACK_Px'
          //   Switch: '<S190>/Switch'

          APF_Path_Planning_2023a_BlueI_B.Subtract_c =
            APF_Path_Planning_2023a_BlueI_B.Sum6_a -
            APF_Path_Planning_2023a_Blue_DW.BLUE_Px;

          // Delay: '<S195>/Delay1'
          if (APF_Path_Planning_2023a_Blue_DW.icLoad_e) {
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_a =
              APF_Path_Planning_2023a_BlueI_B.Subtract_c;
          }

          // Sum: '<S195>/Sum6' incorporates:
          //   Delay: '<S195>/Delay1'

          APF_Path_Planning_2023a_BlueI_B.Sum6_a =
            APF_Path_Planning_2023a_BlueI_B.Subtract_c -
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_a;

          // If: '<S195>/if we went through a "step"'
          if (APF_Path_Planning_2023a_BlueI_B.Sum6_a != 0.0) {
            // Outputs for IfAction SubSystem: '<S195>/Hold this value' incorporates:
            //   ActionPort: '<S196>/Action Port'

            // SignalConversion generated from: '<S196>/In1'
            APF_Path_Planning_2023a_BlueI_B.In1_g20a =
              APF_Path_Planning_2023a_BlueI_B.Sum6_a;

            // End of Outputs for SubSystem: '<S195>/Hold this value'
          }

          // End of If: '<S195>/if we went through a "step"'

          // Sum: '<S187>/Sum3' incorporates:
          //   DataStoreWrite: '<S162>/BLACK_Fx'
          //   Gain: '<S187>/kd_xb'
          //   Gain: '<S187>/kp_xb'
          //   Gain: '<S195>/divide by delta T'

          APF_Path_Planning_2023a_Blue_DW.BLUE_Fx = 1.0 /
            APF_Path_Planning_2023a_BlueI_P.baseRate *
            APF_Path_Planning_2023a_BlueI_B.In1_g20a *
            APF_Path_Planning_2023a_BlueI_P.Kd_xb +
            APF_Path_Planning_2023a_BlueI_P.Kp_xb *
            APF_Path_Planning_2023a_BlueI_B.Subtract_c;

          // Step: '<S191>/End Time'
          if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW <
              APF_Path_Planning_2023a_BlueI_P.end_time_black) {
            APF_Path_Planning_2023a_BlueI_B.Sum6_a =
              APF_Path_Planning_2023a_BlueI_P.EndTime_Y0_e;
          } else {
            APF_Path_Planning_2023a_BlueI_B.Sum6_a =
              APF_Path_Planning_2023a_BlueI_P.EndTime_YFinal_j;
          }

          // Switch: '<S191>/Switch' incorporates:
          //   Constant: '<S191>/End Pos'
          //   DiscreteIntegrator: '<S191>/Start Pos'
          //   Step: '<S191>/End Time'

          if (APF_Path_Planning_2023a_BlueI_B.Sum6_a >
              APF_Path_Planning_2023a_BlueI_P.Switch_Threshold_jo) {
            APF_Path_Planning_2023a_BlueI_B.Sum6_a =
              APF_Path_Planning_2023a_Blue_DW.StartPos_DSTATE_n;
          } else {
            APF_Path_Planning_2023a_BlueI_B.Sum6_a =
              APF_Path_Planning_2023a_BlueI_P.BLACK_end[1];
          }

          // Sum: '<S162>/Subtract1' incorporates:
          //   DataStoreRead: '<S162>/BLACK_Py '
          //   Switch: '<S191>/Switch'

          APF_Path_Planning_2023a_BlueI_B.Subtract1 =
            APF_Path_Planning_2023a_BlueI_B.Sum6_a -
            APF_Path_Planning_2023a_Blue_DW.BLUE_Py;

          // Delay: '<S197>/Delay1'
          if (APF_Path_Planning_2023a_Blue_DW.icLoad_fr) {
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_j =
              APF_Path_Planning_2023a_BlueI_B.Subtract1;
          }

          // Sum: '<S197>/Sum6' incorporates:
          //   Delay: '<S197>/Delay1'

          APF_Path_Planning_2023a_BlueI_B.Sum6_a =
            APF_Path_Planning_2023a_BlueI_B.Subtract1 -
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_j;

          // If: '<S197>/if we went through a "step"'
          if (APF_Path_Planning_2023a_BlueI_B.Sum6_a != 0.0) {
            // Outputs for IfAction SubSystem: '<S197>/Hold this value' incorporates:
            //   ActionPort: '<S198>/Action Port'

            // SignalConversion generated from: '<S198>/In1'
            APF_Path_Planning_2023a_BlueI_B.In1_g20 =
              APF_Path_Planning_2023a_BlueI_B.Sum6_a;

            // End of Outputs for SubSystem: '<S197>/Hold this value'
          }

          // End of If: '<S197>/if we went through a "step"'

          // Sum: '<S188>/Sum3' incorporates:
          //   DataStoreWrite: '<S162>/BLACK_Fy'
          //   Gain: '<S188>/kd_yb'
          //   Gain: '<S188>/kp_yb'
          //   Gain: '<S197>/divide by delta T'

          APF_Path_Planning_2023a_Blue_DW.BLUE_Fy = 1.0 /
            APF_Path_Planning_2023a_BlueI_P.baseRate *
            APF_Path_Planning_2023a_BlueI_B.In1_g20 *
            APF_Path_Planning_2023a_BlueI_P.Kd_yb +
            APF_Path_Planning_2023a_BlueI_P.Kp_yb *
            APF_Path_Planning_2023a_BlueI_B.Subtract1;

          // Step: '<S192>/End Time'
          if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW <
              APF_Path_Planning_2023a_BlueI_P.end_time_black) {
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
              APF_Path_Planning_2023a_BlueI_P.EndTime_Y0_g;
          } else {
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
              APF_Path_Planning_2023a_BlueI_P.EndTime_YFinal_cq;
          }

          // Switch: '<S192>/Switch' incorporates:
          //   Constant: '<S192>/End Pos'
          //   DiscreteIntegrator: '<S192>/Start Pos'
          //   Step: '<S192>/End Time'

          if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW >
              APF_Path_Planning_2023a_BlueI_P.Switch_Threshold_i) {
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
              APF_Path_Planning_2023a_Blue_DW.StartPos_DSTATE_f;
          } else {
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
              APF_Path_Planning_2023a_BlueI_P.BLACK_end[2];
          }

          // MATLAB Function: '<S189>/MATLAB Function2' incorporates:
          //   Switch: '<S192>/Switch'

          APF_Path_Planni_MATLABFunction2
            (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW,
             APF_Path_Planning_2023a_BlueI_B.rtb_Oy_f_l,
             APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b);

          // MATLAB Function: '<S189>/MATLAB Function3' incorporates:
          //   DataStoreRead: '<S162>/BLACK_Rz'

          APF_Path_Planni_MATLABFunction3
            (APF_Path_Planning_2023a_Blue_DW.BLUE_Rz,
             APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o);

          // Sum: '<S189>/Subtract2'
          APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b[0] -=
            APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o[0];
          APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b[1] -=
            APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o[1];

          // MATLAB Function: '<S189>/MATLAB Function4'
          APF_Path_Planni_MATLABFunction4
            (APF_Path_Planning_2023a_BlueI_B.rtb_Oy_f_l,
             APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b,
             &APF_Path_Planning_2023a_BlueI_B.e_out_i);

          // Delay: '<S193>/Delay1'
          if (APF_Path_Planning_2023a_Blue_DW.icLoad_iy) {
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_e =
              APF_Path_Planning_2023a_BlueI_B.e_out_i;
          }

          // Sum: '<S193>/Sum6' incorporates:
          //   Delay: '<S193>/Delay1'

          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
            APF_Path_Planning_2023a_BlueI_B.e_out_i -
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_e;

          // If: '<S193>/if we went through a "step"'
          if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
            // Outputs for IfAction SubSystem: '<S193>/Hold this value' incorporates:
            //   ActionPort: '<S194>/Action Port'

            // SignalConversion generated from: '<S194>/In1'
            APF_Path_Planning_2023a_BlueI_B.In1_g20as =
              APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

            // End of Outputs for SubSystem: '<S193>/Hold this value'
          }

          // End of If: '<S193>/if we went through a "step"'

          // Sum: '<S186>/Sum3' incorporates:
          //   DataStoreWrite: '<S162>/BLACK_Tz'
          //   Gain: '<S186>/kd_tb'
          //   Gain: '<S186>/kp_tb'
          //   Gain: '<S193>/divide by delta T'

          APF_Path_Planning_2023a_Blue_DW.BLUE_Tz = 1.0 /
            APF_Path_Planning_2023a_BlueI_P.baseRate *
            APF_Path_Planning_2023a_BlueI_B.In1_g20as *
            APF_Path_Planning_2023a_BlueI_P.Kd_tb +
            APF_Path_Planning_2023a_BlueI_P.Kp_tb *
            APF_Path_Planning_2023a_BlueI_B.e_out_i;

          // DataStoreWrite: '<S162>/Data Store Write3' incorporates:
          //   Constant: '<S162>/Puck State'

          APF_Path_Planning_2023a_Blue_DW.Float_State =
            APF_Path_Planning_2023a_BlueI_P.PuckState_Value_p;

          // End of Outputs for SubSystem: '<S88>/Sub-Phase #2'
        }

        // End of If: '<S88>/Experiment Sub-Phases'
        // End of Outputs for SubSystem: '<S9>/Change BLUE Behavior'
      }

      // End of If: '<S9>/This IF block determines whether or not to run the BLUE sim//exp' 

      // If: '<S9>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
      //   Constant: '<S18>/Constant'
      //   DataStoreRead: '<S9>/Data Store Read'
      //   DataStoreWrite: '<S18>/Data Store Write'

      APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhether_fg = -1;
      if ((APF_Path_Planning_2023a_Blue_DW.WhoAmI == 1.0) ||
          (APF_Path_Planning_2023a_BlueI_P.simMode == 1.0)) {
        APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhether_fg = 0;

        // Outputs for IfAction SubSystem: '<S9>/Change RED Behavior' incorporates:
        //   ActionPort: '<S89>/Action Port'

        // If: '<S89>/Experiment Sub-Phases' incorporates:
        //   Constant: '<S89>/Constant1'
        //   Constant: '<S89>/Constant2'
        //   Constant: '<S89>/Constant3'
        //   Constant: '<S89>/Constant4'
        //   DataStoreRead: '<S89>/Universal_Time'
        //   Delay: '<S366>/Delay1'
        //   Delay: '<S370>/Delay3'
        //   MATLAB Function: '<S350>/MATLAB Function'
        //   MATLAB Function: '<S351>/MATLAB Function2'
        //   MATLAB Function: '<S369>/MATLAB Function1'

        APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSubsy = -1;
        if (APF_Path_Planning_2023a_Blue_DW.Univ_Time <
            APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase1_End) {
          APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSubsy = 0;

          // Outputs for IfAction SubSystem: '<S89>/Sub-Phase #1' incorporates:
          //   ActionPort: '<S244>/Action Port'

          APF_Path_Planning_2_SubPhase1_p
            (&APF_Path_Planning_2023a_Blue_DW.Float_State,
             &APF_Path_Planning_2023a_Blue_DW.RED_ARM_Control_Mode,
             &APF_Path_Planning_2023a_Blue_DW.RED_Elbow_Command,
             &APF_Path_Planning_2023a_Blue_DW.RED_Fx,
             &APF_Path_Planning_2023a_Blue_DW.RED_Fy,
             &APF_Path_Planning_2023a_Blue_DW.RED_Px,
             &APF_Path_Planning_2023a_Blue_DW.RED_Py,
             &APF_Path_Planning_2023a_Blue_DW.RED_Rz,
             &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Elbow,
             &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder,
             &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Wrist,
             &APF_Path_Planning_2023a_Blue_DW.RED_Shoulder_Command,
             &APF_Path_Planning_2023a_Blue_DW.RED_Tz,
             &APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW,
             &APF_Path_Planning_2023a_Blue_DW.RED_Wrist_Command,
             &APF_Path_Planning_2023a_Blue_DW.Univ_Time,
             &APF_Path_Planning_2023a_BlueI_B.isSim,
             &APF_Path_Planning_2023a_BlueI_B.SubPhase1_p,
             &APF_Path_Planning_2023a_Blue_DW.SubPhase1_p,
             &APF_Path_Planning_2023a_BlueI_P.SubPhase1_p);

          // End of Outputs for SubSystem: '<S89>/Sub-Phase #1'
        } else if ((APF_Path_Planning_2023a_Blue_DW.Univ_Time <
                    APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase2_End) &&
                   (APF_Path_Planning_2023a_Blue_DW.Univ_Time >=
                    APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase1_End)) {
          APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSubsy = 1;

          // Outputs for IfAction SubSystem: '<S89>/Sub-Phase #2 ' incorporates:
          //   ActionPort: '<S245>/Action Port'

          APF_Path_Planning_2_SubPhase1_p
            (&APF_Path_Planning_2023a_Blue_DW.Float_State,
             &APF_Path_Planning_2023a_Blue_DW.RED_ARM_Control_Mode,
             &APF_Path_Planning_2023a_Blue_DW.RED_Elbow_Command,
             &APF_Path_Planning_2023a_Blue_DW.RED_Fx,
             &APF_Path_Planning_2023a_Blue_DW.RED_Fy,
             &APF_Path_Planning_2023a_Blue_DW.RED_Px,
             &APF_Path_Planning_2023a_Blue_DW.RED_Py,
             &APF_Path_Planning_2023a_Blue_DW.RED_Rz,
             &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Elbow,
             &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder,
             &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Wrist,
             &APF_Path_Planning_2023a_Blue_DW.RED_Shoulder_Command,
             &APF_Path_Planning_2023a_Blue_DW.RED_Tz,
             &APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW,
             &APF_Path_Planning_2023a_Blue_DW.RED_Wrist_Command,
             &APF_Path_Planning_2023a_Blue_DW.Univ_Time,
             &APF_Path_Planning_2023a_BlueI_B.isSim,
             &APF_Path_Planning_2023a_BlueI_B.SubPhase2_p,
             &APF_Path_Planning_2023a_Blue_DW.SubPhase2_p,
             &APF_Path_Planning_2023a_BlueI_P.SubPhase2_p);

          // End of Outputs for SubSystem: '<S89>/Sub-Phase #2 '
        } else if ((APF_Path_Planning_2023a_Blue_DW.Univ_Time <
                    APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase3_End) &&
                   (APF_Path_Planning_2023a_Blue_DW.Univ_Time >=
                    APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase2_End)) {
          APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSubsy = 2;

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
            (APF_Path_Planning_2023a_BlueI_P.DesiredRate_Value *
             (APF_Path_Planning_2023a_Blue_DW.Univ_Time -
              APF_Path_Planning_2023a_BlueI_P.Phase2_End) +
             APF_Path_Planning_2023a_BlueI_P.Constant_Value_n,
             &APF_Path_Planning_2023a_BlueI_B.Sum6_a);

          // MATLAB Function: '<S317>/MATLAB Function2'
          APF_Path_Planni_MATLABFunction2(APF_Path_Planning_2023a_BlueI_B.Sum6_a,
            APF_Path_Planning_2023a_BlueI_B.rtb_Oy_f_l,
            APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b);

          // MATLAB Function: '<S317>/MATLAB Function3' incorporates:
          //   DataStoreRead: '<S246>/RED_Rz'

          APF_Path_Planni_MATLABFunction3(APF_Path_Planning_2023a_Blue_DW.RED_Rz,
            APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o);

          // Sum: '<S317>/Subtract2'
          APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b[0] -=
            APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o[0];
          APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b[1] -=
            APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o[1];

          // MATLAB Function: '<S317>/MATLAB Function4'
          APF_Path_Planni_MATLABFunction4
            (APF_Path_Planning_2023a_BlueI_B.rtb_Oy_f_l,
             APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b,
             &APF_Path_Planning_2023a_BlueI_B.e_out_p);

          // Delay: '<S323>/Delay1'
          if (APF_Path_Planning_2023a_Blue_DW.icLoad) {
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_da =
              APF_Path_Planning_2023a_BlueI_B.e_out_p;
          }

          // Sum: '<S323>/Sum6' incorporates:
          //   Delay: '<S323>/Delay1'

          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
            APF_Path_Planning_2023a_BlueI_B.e_out_p -
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_da;

          // If: '<S323>/if we went through a "step"'
          if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
            // Outputs for IfAction SubSystem: '<S323>/Hold this value' incorporates:
            //   ActionPort: '<S324>/Action Port'

            // SignalConversion generated from: '<S324>/In1'
            APF_Path_Planning_2023a_BlueI_B.In1_g2 =
              APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

            // End of Outputs for SubSystem: '<S323>/Hold this value'
          }

          // End of If: '<S323>/if we went through a "step"'

          // Sum: '<S314>/Sum3' incorporates:
          //   DataStoreWrite: '<S246>/RED_Tz'
          //   Gain: '<S314>/kd_tr'
          //   Gain: '<S314>/kp_tr'
          //   Gain: '<S323>/divide by delta T'

          APF_Path_Planning_2023a_Blue_DW.RED_Tz = 1.0 /
            APF_Path_Planning_2023a_BlueI_P.baseRate *
            APF_Path_Planning_2023a_BlueI_B.In1_g2 *
            APF_Path_Planning_2023a_BlueI_P.Kd_tr +
            APF_Path_Planning_2023a_BlueI_P.Kp_tr *
            APF_Path_Planning_2023a_BlueI_B.e_out_p;

          // Sum: '<S322>/Subtract3' incorporates:
          //   Constant: '<S322>/Constant2'
          //   DataStoreRead: '<S346>/Universal_Time'

          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
            APF_Path_Planning_2023a_Blue_DW.Univ_Time -
            APF_Path_Planning_2023a_BlueI_P.Phase2_End;

          // MATLAB Function: '<S246>/MATLAB Function'
          APF_Path_Plann_MATLABFunction_o
            (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW,
             &APF_Path_Planning_2023a_BlueI_B.Sum6_a);

          // Sum: '<S246>/Subtract' incorporates:
          //   DataStoreRead: '<S246>/RED_Px1'

          APF_Path_Planning_2023a_BlueI_B.Subtract =
            APF_Path_Planning_2023a_BlueI_B.Sum6_a -
            APF_Path_Planning_2023a_Blue_DW.RED_Px;

          // Delay: '<S325>/Delay1'
          if (APF_Path_Planning_2023a_Blue_DW.icLoad_f) {
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_d3 =
              APF_Path_Planning_2023a_BlueI_B.Subtract;
          }

          // Sum: '<S325>/Sum6' incorporates:
          //   Delay: '<S325>/Delay1'

          APF_Path_Planning_2023a_BlueI_B.Sum6_a =
            APF_Path_Planning_2023a_BlueI_B.Subtract -
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_d3;

          // If: '<S325>/if we went through a "step"'
          if (APF_Path_Planning_2023a_BlueI_B.Sum6_a != 0.0) {
            // Outputs for IfAction SubSystem: '<S325>/Hold this value' incorporates:
            //   ActionPort: '<S326>/Action Port'

            // SignalConversion generated from: '<S326>/In1'
            APF_Path_Planning_2023a_BlueI_B.In1_g =
              APF_Path_Planning_2023a_BlueI_B.Sum6_a;

            // End of Outputs for SubSystem: '<S325>/Hold this value'
          }

          // End of If: '<S325>/if we went through a "step"'

          // Sum: '<S315>/Sum3' incorporates:
          //   DataStoreWrite: '<S246>/RED_Fx'
          //   Gain: '<S315>/kd_xr'
          //   Gain: '<S315>/kp_xr'
          //   Gain: '<S325>/divide by delta T'

          APF_Path_Planning_2023a_Blue_DW.RED_Fx = 1.0 /
            APF_Path_Planning_2023a_BlueI_P.baseRate *
            APF_Path_Planning_2023a_BlueI_B.In1_g *
            APF_Path_Planning_2023a_BlueI_P.Kd_xr +
            APF_Path_Planning_2023a_BlueI_P.Kp_xr *
            APF_Path_Planning_2023a_BlueI_B.Subtract;

          // MATLAB Function: '<S246>/MATLAB Function1'
          APF_Path_Planni_MATLABFunction1
            (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW,
             &APF_Path_Planning_2023a_BlueI_B.Sum6_a);

          // Sum: '<S246>/Subtract2' incorporates:
          //   DataStoreRead: '<S246>/RED_Py '

          APF_Path_Planning_2023a_BlueI_B.Subtract2 =
            APF_Path_Planning_2023a_BlueI_B.Sum6_a -
            APF_Path_Planning_2023a_Blue_DW.RED_Py;

          // Delay: '<S327>/Delay1'
          if (APF_Path_Planning_2023a_Blue_DW.icLoad_i) {
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_g =
              APF_Path_Planning_2023a_BlueI_B.Subtract2;
          }

          // Sum: '<S327>/Sum6' incorporates:
          //   Delay: '<S327>/Delay1'

          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
            APF_Path_Planning_2023a_BlueI_B.Subtract2 -
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_g;

          // If: '<S327>/if we went through a "step"'
          if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
            // Outputs for IfAction SubSystem: '<S327>/Hold this value' incorporates:
            //   ActionPort: '<S328>/Action Port'

            // SignalConversion generated from: '<S328>/In1'
            APF_Path_Planning_2023a_BlueI_B.In1 =
              APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

            // End of Outputs for SubSystem: '<S327>/Hold this value'
          }

          // End of If: '<S327>/if we went through a "step"'

          // Sum: '<S316>/Sum3' incorporates:
          //   DataStoreWrite: '<S246>/RED_Fy'
          //   Gain: '<S316>/kd_yr'
          //   Gain: '<S316>/kp_yr'
          //   Gain: '<S327>/divide by delta T'

          APF_Path_Planning_2023a_Blue_DW.RED_Fy = 1.0 /
            APF_Path_Planning_2023a_BlueI_P.baseRate *
            APF_Path_Planning_2023a_BlueI_B.In1 *
            APF_Path_Planning_2023a_BlueI_P.Kd_yr +
            APF_Path_Planning_2023a_BlueI_P.Kp_yr *
            APF_Path_Planning_2023a_BlueI_B.Subtract2;

          // DataStoreWrite: '<S246>/Data Store Write3' incorporates:
          //   Constant: '<S246>/Puck State'

          APF_Path_Planning_2023a_Blue_DW.Float_State =
            APF_Path_Planning_2023a_BlueI_P.PuckState_Value_g;

          // If: '<S246>/If' incorporates:
          //   Constant: '<S246>/Constant1'

          if ((APF_Path_Planning_2023a_BlueI_P.platformSelection == 4.0) ||
              (APF_Path_Planning_2023a_BlueI_P.platformSelection == 5.0) ||
              (APF_Path_Planning_2023a_BlueI_P.platformSelection == 10.0) ||
              (APF_Path_Planning_2023a_BlueI_P.platformSelection == 11.0)) {
            // Outputs for IfAction SubSystem: '<S246>/RED+ARM' incorporates:
            //   ActionPort: '<S320>/Action Port'

            APF_Path_Planning_2023a__REDARM
              (&APF_Path_Planning_2023a_Blue_DW.RED_ARM_Control_Mode,
               &APF_Path_Planning_2023a_Blue_DW.RED_Elbow_Command,
               &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Elbow,
               &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder,
               &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Wrist,
               &APF_Path_Planning_2023a_Blue_DW.RED_Shoulder_Command,
               &APF_Path_Planning_2023a_Blue_DW.RED_Wrist_Command,
               &APF_Path_Planning_2023a_BlueI_B.isSim,
               &APF_Path_Planning_2023a_BlueI_B.REDARM_m,
               &APF_Path_Planning_2023a_Blue_DW.REDARM_m,
               &APF_Path_Planning_2023a_BlueI_P.REDARM_m);

            // End of Outputs for SubSystem: '<S246>/RED+ARM'
          }

          // End of If: '<S246>/If'
          // End of Outputs for SubSystem: '<S89>/Sub-Phase #3 '
        } else if ((APF_Path_Planning_2023a_Blue_DW.Univ_Time <
                    APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase4_End) &&
                   (APF_Path_Planning_2023a_Blue_DW.Univ_Time >=
                    APF_Path_Planning_2023a_BlueI_P.Phase3_SubPhase3_End)) {
          APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSubsy = 3;

          // Outputs for IfAction SubSystem: '<S89>/Sub-Phase #4' incorporates:
          //   ActionPort: '<S247>/Action Port'

          // MATLAB Function: '<S347>/Ryan's Transform' incorporates:
          //   DataStoreRead: '<S347>/Data Store Read10'
          //   DataStoreRead: '<S347>/Data Store Read11'
          //   DataStoreRead: '<S347>/Data Store Read9'
          //   DataTypeConversion: '<S2>/Data Type Conversion'
          //   DataTypeConversion: '<S2>/Data Type Conversion1'
          //   DataTypeConversion: '<S2>/Data Type Conversion2'

          APF_Path_Planning_2023a_BlueI_B.Z_k[2] =
            APF_Path_Planning_2023a_BlueI_B.ByteUnpack_o3 * 3.1415926535897931 /
            180.0;
          if (rtIsNaN(APF_Path_Planning_2023a_Blue_DW.RED_Rz +
                      3.1415926535897931)) {
            APF_Path_Planning_2023a_BlueI_B.alpha_pol = (rtNaN);
          } else if (rtIsInf(APF_Path_Planning_2023a_Blue_DW.RED_Rz +
                             3.1415926535897931)) {
            APF_Path_Planning_2023a_BlueI_B.alpha_pol = (rtNaN);
          } else if (APF_Path_Planning_2023a_Blue_DW.RED_Rz + 3.1415926535897931
                     == 0.0) {
            APF_Path_Planning_2023a_BlueI_B.alpha_pol = 0.0;
          } else {
            APF_Path_Planning_2023a_BlueI_B.alpha_pol = fmod
              (APF_Path_Planning_2023a_Blue_DW.RED_Rz + 3.1415926535897931,
               6.2831853071795862);
            APF_Path_Planning_2023a_BlueI_B.rEQ0 =
              (APF_Path_Planning_2023a_BlueI_B.alpha_pol == 0.0);
            if (!APF_Path_Planning_2023a_BlueI_B.rEQ0) {
              APF_Path_Planning_2023a_BlueI_B.q = fabs
                ((APF_Path_Planning_2023a_Blue_DW.RED_Rz + 3.1415926535897931) /
                 6.2831853071795862);
              APF_Path_Planning_2023a_BlueI_B.rEQ0 = !(fabs
                (APF_Path_Planning_2023a_BlueI_B.q - floor
                 (APF_Path_Planning_2023a_BlueI_B.q + 0.5)) >
                2.2204460492503131E-16 * APF_Path_Planning_2023a_BlueI_B.q);
            }

            if (APF_Path_Planning_2023a_BlueI_B.rEQ0) {
              APF_Path_Planning_2023a_BlueI_B.alpha_pol = 0.0;
            } else if (APF_Path_Planning_2023a_Blue_DW.RED_Rz +
                       3.1415926535897931 < 0.0) {
              APF_Path_Planning_2023a_BlueI_B.alpha_pol += 6.2831853071795862;
            }
          }

          APF_Path_Planning_2023a_BlueI_B.Sum6_a =
            APF_Path_Planning_2023a_BlueI_P.delta * 3.1415926535897931 / 180.0 +
            (APF_Path_Planning_2023a_BlueI_B.alpha_pol - 3.1415926535897931);
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = sin
            (APF_Path_Planning_2023a_BlueI_B.Sum6_a);
          APF_Path_Planning_2023a_BlueI_B.Sum6_a = cos
            (APF_Path_Planning_2023a_BlueI_B.Sum6_a);
          APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[0] =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
          APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[3] =
            APF_Path_Planning_2023a_BlueI_B.Sum6_a;
          APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[6] =
            0.0;
          APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[1] =
            APF_Path_Planning_2023a_BlueI_B.Sum6_a;
          APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[4] =
            -APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
          APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[7] =
            0.0;
          APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[2] =
            0.0;
          APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[5] =
            0.0;
          APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[8] =
            1.0;
          APF_Path_Planning_2023a_BlueI_B.q =
            APF_Path_Planning_2023a_BlueI_B.ByteUnpack_o2 / 100.0;
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
            APF_Path_Planning_2023a_BlueI_B.ByteUnpack_o1 / 100.0;
          APF_Path_Planning_2023a_BlueI_B.Sum6_a =
            APF_Path_Planning_2023a_BlueI_B.Z_k[2];
          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 3;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtSFunct[APF_Path_Planning_2023a_BlueI_B.i_o]
              =
              (APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[APF_Path_Planning_2023a_BlueI_B.i_o
               + 3] * APF_Path_Planning_2023a_BlueI_B.q +
               APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[APF_Path_Planning_2023a_BlueI_B.i_o]
               * APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW) +
              APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[APF_Path_Planning_2023a_BlueI_B.i_o
              + 6] * APF_Path_Planning_2023a_BlueI_B.Sum6_a;
          }

          APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtSFunct[0] +=
            APF_Path_Planning_2023a_Blue_DW.RED_Px;
          APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtSFunct[1] =
            -APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtSFunct[1] +
            APF_Path_Planning_2023a_Blue_DW.RED_Py;
          APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtSFunct[2] =
            ((APF_Path_Planning_2023a_BlueI_B.alpha_pol - 3.1415926535897931) +
             APF_Path_Planning_2023a_BlueI_B.Z_k[2]) - 1.5707963267948966;

          // End of MATLAB Function: '<S347>/Ryan's Transform'

          // InitialCondition: '<S356>/IC1'
          if (APF_Path_Planning_2023a_Blue_DW.IC1_FirstOutputTime) {
            APF_Path_Planning_2023a_Blue_DW.IC1_FirstOutputTime = false;

            // InitialCondition: '<S356>/IC1'
            for (APF_Path_Planning_2023a_BlueI_B.i = 0;
                 APF_Path_Planning_2023a_BlueI_B.i < 6;
                 APF_Path_Planning_2023a_BlueI_B.i++) {
              APF_Path_Planning_2023a_BlueI_B.IC1[APF_Path_Planning_2023a_BlueI_B.i]
                =
                APF_Path_Planning_2023a_BlueI_P.x_in[APF_Path_Planning_2023a_BlueI_B.i];
            }
          } else {
            // InitialCondition: '<S356>/IC1' incorporates:
            //   Delay: '<S356>/Delay1'

            for (APF_Path_Planning_2023a_BlueI_B.i = 0;
                 APF_Path_Planning_2023a_BlueI_B.i < 6;
                 APF_Path_Planning_2023a_BlueI_B.i++) {
              APF_Path_Planning_2023a_BlueI_B.IC1[APF_Path_Planning_2023a_BlueI_B.i]
                =
                APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE[APF_Path_Planning_2023a_BlueI_B.i];
            }
          }

          // End of InitialCondition: '<S356>/IC1'

          // InitialCondition: '<S356>/IC'
          if (APF_Path_Planning_2023a_Blue_DW.IC_FirstOutputTime) {
            APF_Path_Planning_2023a_Blue_DW.IC_FirstOutputTime = false;

            // InitialCondition: '<S356>/IC'
            memcpy(&APF_Path_Planning_2023a_BlueI_B.IC[0],
                   &APF_Path_Planning_2023a_BlueI_P.P_IC[0], 36U * sizeof(real_T));
          } else {
            // InitialCondition: '<S356>/IC' incorporates:
            //   Delay: '<S356>/Delay'

            memcpy(&APF_Path_Planning_2023a_BlueI_B.IC[0],
                   &APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE[0], 36U *
                   sizeof(real_T));
          }

          // End of InitialCondition: '<S356>/IC'

          // MATLAB Function: '<S356>/MATLAB Function' incorporates:
          //   Constant: '<S356>/Force'
          //   InitialCondition: '<S356>/IC'
          //   Reshape: '<S356>/Reshape'

          memset(&APF_Path_Planning_2023a_BlueI_B.X_Cal[0], 0, 78U * sizeof
                 (real_T));
          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 6;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.X_Cal[APF_Path_Planning_2023a_BlueI_B.i_o]
              =
              APF_Path_Planning_2023a_BlueI_B.IC1[APF_Path_Planning_2023a_BlueI_B.i_o];
          }

          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 36;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.IC[APF_Path_Planning_2023a_BlueI_B.i_o]
              *= APF_Path_Planning_2023a_BlueI_P.lamda + 6.0;
          }

          APF_Path_Planning_2023a_Blu_eig(APF_Path_Planning_2023a_BlueI_B.IC,
            APF_Path_Planning_2023a_BlueI_B.unusedExpr);
          memset(&APF_Path_Planning_2023a_BlueI_B.sigma[0], 0, 36U * sizeof
                 (real_T));
          for (APF_Path_Planning_2023a_BlueI_B.i = 0;
               APF_Path_Planning_2023a_BlueI_B.i < 6;
               APF_Path_Planning_2023a_BlueI_B.i++) {
            if (APF_Path_Planning_2023a_BlueI_B.i < 1) {
              APF_Path_Planning_2023a_BlueI_B.loop_ub = -1;
            } else {
              APF_Path_Planning_2023a_BlueI_B.loop_ub =
                APF_Path_Planning_2023a_BlueI_B.i - 1;
            }

            APF_Path_Planning_2023a_BlueI_B.b_x_size[0] = 1;
            APF_Path_Planning_2023a_BlueI_B.b_x_size[1] =
              APF_Path_Planning_2023a_BlueI_B.loop_ub + 1;
            for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
                 APF_Path_Planning_2023a_BlueI_B.i_o <=
                 APF_Path_Planning_2023a_BlueI_B.loop_ub;
                 APF_Path_Planning_2023a_BlueI_B.i_o++) {
              APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
                APF_Path_Planning_2023a_BlueI_B.sigma[6 *
                APF_Path_Planning_2023a_BlueI_B.i_o +
                APF_Path_Planning_2023a_BlueI_B.i];
              APF_Path_Planning_2023a_BlueI_B.b_x_data[APF_Path_Planning_2023a_BlueI_B.i_o]
                = APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW *
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
            }

            APF_Path_Planning_2023a_BlueI_B.ar =
              APF_Path_Planning_2023a_BlueI_B.loop_ub + 1;
            if (APF_Path_Planning_2023a_BlueI_B.loop_ub + 1 == 0) {
              APF_Path_Planning_2023a_BlueI_B.link1_com_y = 0.0;
            } else {
              APF_Path_Planning_2023a_BlueI_B.link1_com_y =
                APF_Path_Planning_2023a_BlueI_B.b_x_data[0];
              for (APF_Path_Planning_2023a_BlueI_B.i_o = 2;
                   APF_Path_Planning_2023a_BlueI_B.i_o <=
                   APF_Path_Planning_2023a_BlueI_B.ar;
                   APF_Path_Planning_2023a_BlueI_B.i_o++) {
                APF_Path_Planning_2023a_BlueI_B.link1_com_y +=
                  APF_Path_Planning_2023a_BlueI_B.b_x_data[APF_Path_Planning_2023a_BlueI_B.i_o
                  - 1];
              }
            }

            APF_Path_Planning_2023a_BlueI_B.sigma_tmp = 6 *
              APF_Path_Planning_2023a_BlueI_B.i +
              APF_Path_Planning_2023a_BlueI_B.i;
            APF_Path_Planning_2023a_BlueI_B.sigma[APF_Path_Planning_2023a_BlueI_B.sigma_tmp]
              = sqrt
              (APF_Path_Planning_2023a_BlueI_B.IC[APF_Path_Planning_2023a_BlueI_B.sigma_tmp]
               - APF_Path_Planning_2023a_BlueI_B.link1_com_y);
            APF_Path_Planning_2023a_BlueI_B.d_e = 4 -
              APF_Path_Planning_2023a_BlueI_B.i;
            if (4 - APF_Path_Planning_2023a_BlueI_B.i >= 0) {
              if (APF_Path_Planning_2023a_BlueI_B.i < 1) {
                APF_Path_Planning_2023a_BlueI_B.b_xoffset = -1;
                APF_Path_Planning_2023a_BlueI_B.xoffset = -1;
              } else {
                APF_Path_Planning_2023a_BlueI_B.b_xoffset =
                  APF_Path_Planning_2023a_BlueI_B.i - 1;
                APF_Path_Planning_2023a_BlueI_B.xoffset =
                  APF_Path_Planning_2023a_BlueI_B.i - 1;
              }
            }

            for (APF_Path_Planning_2023a_BlueI_B.ar = 0;
                 APF_Path_Planning_2023a_BlueI_B.ar <=
                 APF_Path_Planning_2023a_BlueI_B.d_e;
                 APF_Path_Planning_2023a_BlueI_B.ar++) {
              APF_Path_Planning_2023a_BlueI_B.b_j =
                (APF_Path_Planning_2023a_BlueI_B.i +
                 APF_Path_Planning_2023a_BlueI_B.ar) + 1;
              if (APF_Path_Planning_2023a_BlueI_B.b_xoffset + 1 ==
                  APF_Path_Planning_2023a_BlueI_B.xoffset + 1) {
                if (APF_Path_Planning_2023a_BlueI_B.i < 1) {
                  APF_Path_Planning_2023a_BlueI_B.loop_ub = -1;
                } else {
                  APF_Path_Planning_2023a_BlueI_B.loop_ub =
                    APF_Path_Planning_2023a_BlueI_B.i - 1;
                }

                APF_Path_Planning_2023a_BlueI_B.b_x_size[0] = 1;
                APF_Path_Planning_2023a_BlueI_B.b_x_size[1] =
                  APF_Path_Planning_2023a_BlueI_B.loop_ub + 1;
                for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
                     APF_Path_Planning_2023a_BlueI_B.i_o <=
                     APF_Path_Planning_2023a_BlueI_B.loop_ub;
                     APF_Path_Planning_2023a_BlueI_B.i_o++) {
                  APF_Path_Planning_2023a_BlueI_B.b_x_data[APF_Path_Planning_2023a_BlueI_B.i_o]
                    = APF_Path_Planning_2023a_BlueI_B.sigma[6 *
                    APF_Path_Planning_2023a_BlueI_B.i_o +
                    APF_Path_Planning_2023a_BlueI_B.b_j] *
                    APF_Path_Planning_2023a_BlueI_B.sigma[6 *
                    APF_Path_Planning_2023a_BlueI_B.i_o +
                    APF_Path_Planning_2023a_BlueI_B.i];
                }
              } else {
                APF_Path_Plann_binary_expand_op
                  (APF_Path_Planning_2023a_BlueI_B.b_x_data,
                   APF_Path_Planning_2023a_BlueI_B.b_x_size,
                   APF_Path_Planning_2023a_BlueI_B.sigma,
                   APF_Path_Planning_2023a_BlueI_B.b_j,
                   APF_Path_Planning_2023a_BlueI_B.i);
              }

              APF_Path_Planning_2023a_BlueI_B.loop_ub =
                APF_Path_Planning_2023a_BlueI_B.b_x_size[1];
              if (APF_Path_Planning_2023a_BlueI_B.b_x_size[1] == 0) {
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 0.0;
              } else {
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
                  APF_Path_Planning_2023a_BlueI_B.b_x_data[0];
                for (APF_Path_Planning_2023a_BlueI_B.i_o = 2;
                     APF_Path_Planning_2023a_BlueI_B.i_o <=
                     APF_Path_Planning_2023a_BlueI_B.loop_ub;
                     APF_Path_Planning_2023a_BlueI_B.i_o++) {
                  APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +=
                    APF_Path_Planning_2023a_BlueI_B.b_x_data[APF_Path_Planning_2023a_BlueI_B.i_o
                    - 1];
                }
              }

              APF_Path_Planning_2023a_BlueI_B.i_o = 6 *
                APF_Path_Planning_2023a_BlueI_B.i +
                APF_Path_Planning_2023a_BlueI_B.b_j;
              APF_Path_Planning_2023a_BlueI_B.sigma[APF_Path_Planning_2023a_BlueI_B.i_o]
                =
                (APF_Path_Planning_2023a_BlueI_B.IC[APF_Path_Planning_2023a_BlueI_B.i_o]
                 - APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW) /
                APF_Path_Planning_2023a_BlueI_B.sigma[APF_Path_Planning_2023a_BlueI_B.sigma_tmp];
            }
          }

          for (APF_Path_Planning_2023a_BlueI_B.i = 0;
               APF_Path_Planning_2023a_BlueI_B.i < 6;
               APF_Path_Planning_2023a_BlueI_B.i++) {
            for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
                 APF_Path_Planning_2023a_BlueI_B.i_o < 6;
                 APF_Path_Planning_2023a_BlueI_B.i_o++) {
              APF_Path_Planning_2023a_BlueI_B.fill[APF_Path_Planning_2023a_BlueI_B.i_o]
                = 0.0;
            }

            APF_Path_Planning_2023a_BlueI_B.fill[APF_Path_Planning_2023a_BlueI_B.i]
              = APF_Path_Planning_2023a_BlueI_B.sigma[6 *
              APF_Path_Planning_2023a_BlueI_B.i +
              APF_Path_Planning_2023a_BlueI_B.i];
            for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
                 APF_Path_Planning_2023a_BlueI_B.i_o < 6;
                 APF_Path_Planning_2023a_BlueI_B.i_o++) {
              APF_Path_Planning_2023a_BlueI_B.X_Cal[APF_Path_Planning_2023a_BlueI_B.i_o
                + 6 * (APF_Path_Planning_2023a_BlueI_B.i + 1)] =
                APF_Path_Planning_2023a_BlueI_B.IC1[APF_Path_Planning_2023a_BlueI_B.i_o]
                + APF_Path_Planning_2023a_BlueI_B.fill[APF_Path_Planning_2023a_BlueI_B.i_o];
            }
          }

          for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.b_xoffset < 6;
               APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
            for (APF_Path_Planning_2023a_BlueI_B.i = 0;
                 APF_Path_Planning_2023a_BlueI_B.i < 6;
                 APF_Path_Planning_2023a_BlueI_B.i++) {
              APF_Path_Planning_2023a_BlueI_B.fill[APF_Path_Planning_2023a_BlueI_B.i]
                = 0.0;
            }

            APF_Path_Planning_2023a_BlueI_B.fill[APF_Path_Planning_2023a_BlueI_B.b_xoffset]
              = APF_Path_Planning_2023a_BlueI_B.sigma[6 *
              APF_Path_Planning_2023a_BlueI_B.b_xoffset +
              APF_Path_Planning_2023a_BlueI_B.b_xoffset];
            for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
                 APF_Path_Planning_2023a_BlueI_B.i_o < 6;
                 APF_Path_Planning_2023a_BlueI_B.i_o++) {
              APF_Path_Planning_2023a_BlueI_B.X_Cal[APF_Path_Planning_2023a_BlueI_B.i_o
                + 6 * (APF_Path_Planning_2023a_BlueI_B.b_xoffset + 7)] =
                APF_Path_Planning_2023a_BlueI_B.IC1[APF_Path_Planning_2023a_BlueI_B.i_o]
                - APF_Path_Planning_2023a_BlueI_B.fill[APF_Path_Planning_2023a_BlueI_B.i_o];
            }
          }

          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 9;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[APF_Path_Planning_2023a_BlueI_B.i_o]
              = b_a[APF_Path_Planning_2023a_BlueI_B.i_o];
          }

          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 3;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.b_xoffset = static_cast<int32_T>
              (APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[3
               * APF_Path_Planning_2023a_BlueI_B.i_o]);
            APF_Path_Planning_2023a_BlueI_B.IC[6 *
              APF_Path_Planning_2023a_BlueI_B.i_o] =
              APF_Path_Planning_2023a_BlueI_B.b_xoffset;
            APF_Path_Planning_2023a_BlueI_B.xoffset =
              (APF_Path_Planning_2023a_BlueI_B.i_o + 3) * 6;
            APF_Path_Planning_2023a_BlueI_B.IC[APF_Path_Planning_2023a_BlueI_B.xoffset]
              = static_cast<real_T>(APF_Path_Planning_2023a_BlueI_B.b_xoffset) *
              APF_Path_Planning_2023a_BlueI_P.dt;
            APF_Path_Planning_2023a_BlueI_B.b_xoffset = static_cast<int32_T>
              (APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[3
               * APF_Path_Planning_2023a_BlueI_B.i_o + 1]);
            APF_Path_Planning_2023a_BlueI_B.IC[6 *
              APF_Path_Planning_2023a_BlueI_B.i_o + 1] =
              APF_Path_Planning_2023a_BlueI_B.b_xoffset;
            APF_Path_Planning_2023a_BlueI_B.IC[APF_Path_Planning_2023a_BlueI_B.xoffset
              + 1] = static_cast<real_T>
              (APF_Path_Planning_2023a_BlueI_B.b_xoffset) *
              APF_Path_Planning_2023a_BlueI_P.dt;
            APF_Path_Planning_2023a_BlueI_B.b_xoffset = static_cast<int32_T>
              (APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[3
               * APF_Path_Planning_2023a_BlueI_B.i_o + 2]);
            APF_Path_Planning_2023a_BlueI_B.IC[6 *
              APF_Path_Planning_2023a_BlueI_B.i_o + 2] =
              APF_Path_Planning_2023a_BlueI_B.b_xoffset;
            APF_Path_Planning_2023a_BlueI_B.IC[APF_Path_Planning_2023a_BlueI_B.xoffset
              + 2] = static_cast<real_T>
              (APF_Path_Planning_2023a_BlueI_B.b_xoffset) *
              APF_Path_Planning_2023a_BlueI_P.dt;
          }

          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 6;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.IC[6 *
              APF_Path_Planning_2023a_BlueI_B.i_o + 3] = g[3 *
              APF_Path_Planning_2023a_BlueI_B.i_o];
            APF_Path_Planning_2023a_BlueI_B.IC[6 *
              APF_Path_Planning_2023a_BlueI_B.i_o + 4] = g[3 *
              APF_Path_Planning_2023a_BlueI_B.i_o + 1];
            APF_Path_Planning_2023a_BlueI_B.IC[6 *
              APF_Path_Planning_2023a_BlueI_B.i_o + 5] = g[3 *
              APF_Path_Planning_2023a_BlueI_B.i_o + 2];
          }

          APF_Path_Planning_2023a_BlueI_B.Derivative2 =
            APF_Path_Planning_2023a_BlueI_P.dt *
            APF_Path_Planning_2023a_BlueI_P.dt;
          APF_Path_Planning_2023a_BlueI_B.rtb_C_Ib_l[0] = 1.0;
          APF_Path_Planning_2023a_BlueI_B.rtb_C_Ib_l[1] = 0.0;
          APF_Path_Planning_2023a_BlueI_B.rtb_C_Ib_l[2] = 0.0;
          APF_Path_Planning_2023a_BlueI_B.rtb_C_Ib_l[3] = 1.0;
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 2.0 *
            APF_Path_Planning_2023a_BlueI_P.m;
          APF_Path_Planning_2023a_BlueI_B.B[2] = 0.0;
          APF_Path_Planning_2023a_BlueI_B.B[8] = 0.0;
          APF_Path_Planning_2023a_BlueI_B.B[14] =
            APF_Path_Planning_2023a_BlueI_B.Derivative2 / (2.0 *
            APF_Path_Planning_2023a_BlueI_P.J);
          APF_Path_Planning_2023a_BlueI_B.Sum6_a =
            APF_Path_Planning_2023a_BlueI_B.Derivative2 /
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
          APF_Path_Planning_2023a_BlueI_B.B[0] =
            APF_Path_Planning_2023a_BlueI_B.Sum6_a;
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 0.0 *
            APF_Path_Planning_2023a_BlueI_B.Derivative2 /
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
          APF_Path_Planning_2023a_BlueI_B.B[1] =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
          APF_Path_Planning_2023a_BlueI_B.B[12] = 0.0;
          APF_Path_Planning_2023a_BlueI_B.Derivative2 =
            APF_Path_Planning_2023a_BlueI_P.dt /
            APF_Path_Planning_2023a_BlueI_P.m;
          APF_Path_Planning_2023a_BlueI_B.B[3] =
            APF_Path_Planning_2023a_BlueI_B.Derivative2;
          APF_Path_Planning_2023a_BlueI_B.Switch = 0.0 *
            APF_Path_Planning_2023a_BlueI_P.dt /
            APF_Path_Planning_2023a_BlueI_P.m;
          APF_Path_Planning_2023a_BlueI_B.B[4] =
            APF_Path_Planning_2023a_BlueI_B.Switch;
          APF_Path_Planning_2023a_BlueI_B.B[15] = 0.0;
          APF_Path_Planning_2023a_BlueI_B.B[6] =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
          APF_Path_Planning_2023a_BlueI_B.B[7] =
            APF_Path_Planning_2023a_BlueI_B.Sum6_a;
          APF_Path_Planning_2023a_BlueI_B.B[13] = 0.0;
          APF_Path_Planning_2023a_BlueI_B.B[9] =
            APF_Path_Planning_2023a_BlueI_B.Switch;
          APF_Path_Planning_2023a_BlueI_B.B[10] =
            APF_Path_Planning_2023a_BlueI_B.Derivative2;
          APF_Path_Planning_2023a_BlueI_B.B[16] = 0.0;
          APF_Path_Planning_2023a_BlueI_B.B[5] = 0.0;
          APF_Path_Planning_2023a_BlueI_B.B[11] = 0.0;
          APF_Path_Planning_2023a_BlueI_B.B[17] =
            APF_Path_Planning_2023a_BlueI_P.dt /
            APF_Path_Planning_2023a_BlueI_P.J;
          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 13;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
                 APF_Path_Planning_2023a_BlueI_B.i_o < 6;
                 APF_Path_Planning_2023a_BlueI_B.i_o++) {
              APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 0.0;
              for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
                   APF_Path_Planning_2023a_BlueI_B.b_xoffset < 6;
                   APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +=
                  APF_Path_Planning_2023a_BlueI_B.IC[6 *
                  APF_Path_Planning_2023a_BlueI_B.b_xoffset +
                  APF_Path_Planning_2023a_BlueI_B.i_o] *
                  APF_Path_Planning_2023a_BlueI_B.X_Cal[6 *
                  APF_Path_Planning_2023a_BlueI_B.xoffset +
                  APF_Path_Planning_2023a_BlueI_B.b_xoffset];
              }

              APF_Path_Planning_2023a_BlueI_B.X_Cal_k1[APF_Path_Planning_2023a_BlueI_B.i_o
                + 6 * APF_Path_Planning_2023a_BlueI_B.xoffset] =
                ((APF_Path_Planning_2023a_BlueI_B.B[APF_Path_Planning_2023a_BlueI_B.i_o
                  + 6] * APF_Path_Planning_2023a_BlueI_P.Force_Value[1] +
                  APF_Path_Planning_2023a_BlueI_B.B[APF_Path_Planning_2023a_BlueI_B.i_o]
                  * APF_Path_Planning_2023a_BlueI_P.Force_Value[0]) +
                 APF_Path_Planning_2023a_BlueI_B.B[APF_Path_Planning_2023a_BlueI_B.i_o
                 + 12] * APF_Path_Planning_2023a_BlueI_P.Force_Value[2]) +
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
            }
          }

          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 1.0 /
            ((APF_Path_Planning_2023a_BlueI_P.lamda + 6.0) * 2.0);
          APF_Path_Planning_2023a_BlueI_B.Sum6_a =
            APF_Path_Planning_2023a_BlueI_P.lamda /
            (APF_Path_Planning_2023a_BlueI_P.lamda + 6.0);
          APF_Path_Planning_2023a_BlueI_B.v_g[0] =
            APF_Path_Planning_2023a_BlueI_B.Sum6_a;
          APF_Path_Planning_2023a_BlueI_B.b_v[0] = (1.0 -
            APF_Path_Planning_2023a_BlueI_P.alpha *
            APF_Path_Planning_2023a_BlueI_P.alpha) +
            (APF_Path_Planning_2023a_BlueI_B.Sum6_a +
             APF_Path_Planning_2023a_BlueI_P.beta);
          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 12;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.v_g[APF_Path_Planning_2023a_BlueI_B.i_o
              + 1] = APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
            APF_Path_Planning_2023a_BlueI_B.b_v[APF_Path_Planning_2023a_BlueI_B.i_o
              + 1] = APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
          }

          memset(&APF_Path_Planning_2023a_BlueI_B.w_m[0], 0, 169U * sizeof
                 (real_T));
          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 13;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.w_m[APF_Path_Planning_2023a_BlueI_B.i_o
              + 13 * APF_Path_Planning_2023a_BlueI_B.i_o] =
              APF_Path_Planning_2023a_BlueI_B.v_g[APF_Path_Planning_2023a_BlueI_B.i_o];
          }

          memset(&APF_Path_Planning_2023a_BlueI_B.w_c[0], 0, 169U * sizeof
                 (real_T));
          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 13;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            APF_Path_Planning_2023a_BlueI_B.w_c[APF_Path_Planning_2023a_BlueI_B.xoffset
              + 13 * APF_Path_Planning_2023a_BlueI_B.xoffset] =
              APF_Path_Planning_2023a_BlueI_B.b_v[APF_Path_Planning_2023a_BlueI_B.xoffset];
            for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
                 APF_Path_Planning_2023a_BlueI_B.i_o < 6;
                 APF_Path_Planning_2023a_BlueI_B.i_o++) {
              APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 0.0;
              for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
                   APF_Path_Planning_2023a_BlueI_B.b_xoffset < 13;
                   APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +=
                  APF_Path_Planning_2023a_BlueI_B.X_Cal_k1[6 *
                  APF_Path_Planning_2023a_BlueI_B.b_xoffset +
                  APF_Path_Planning_2023a_BlueI_B.i_o] *
                  APF_Path_Planning_2023a_BlueI_B.w_m[13 *
                  APF_Path_Planning_2023a_BlueI_B.xoffset +
                  APF_Path_Planning_2023a_BlueI_B.b_xoffset];
              }

              APF_Path_Planning_2023a_BlueI_B.c_x[APF_Path_Planning_2023a_BlueI_B.i_o
                + 6 * APF_Path_Planning_2023a_BlueI_B.xoffset] =
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
            }
          }

          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 6;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.fill[APF_Path_Planning_2023a_BlueI_B.i_o]
              =
              APF_Path_Planning_2023a_BlueI_B.c_x[APF_Path_Planning_2023a_BlueI_B.i_o];
          }

          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 12;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.xoffset =
              (APF_Path_Planning_2023a_BlueI_B.i_o + 1) * 6;
            for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset < 6;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
              APF_Path_Planning_2023a_BlueI_B.fill[APF_Path_Planning_2023a_BlueI_B.b_xoffset]
                +=
                APF_Path_Planning_2023a_BlueI_B.c_x[APF_Path_Planning_2023a_BlueI_B.xoffset
                + APF_Path_Planning_2023a_BlueI_B.b_xoffset];
            }
          }

          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 13;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset < 6;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
              APF_Path_Planning_2023a_BlueI_B.xoffset = 6 *
                APF_Path_Planning_2023a_BlueI_B.i_o +
                APF_Path_Planning_2023a_BlueI_B.b_xoffset;
              APF_Path_Planning_2023a_BlueI_B.c_x[APF_Path_Planning_2023a_BlueI_B.xoffset]
                =
                APF_Path_Planning_2023a_BlueI_B.X_Cal_k1[APF_Path_Planning_2023a_BlueI_B.xoffset]
                - APF_Path_Planning_2023a_BlueI_B.fill[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
            }
          }

          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 6;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset < 13;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
              APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 0.0;
              for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
                   APF_Path_Planning_2023a_BlueI_B.xoffset < 13;
                   APF_Path_Planning_2023a_BlueI_B.xoffset++) {
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +=
                  APF_Path_Planning_2023a_BlueI_B.c_x[6 *
                  APF_Path_Planning_2023a_BlueI_B.xoffset +
                  APF_Path_Planning_2023a_BlueI_B.i_o] *
                  APF_Path_Planning_2023a_BlueI_B.w_c[13 *
                  APF_Path_Planning_2023a_BlueI_B.b_xoffset +
                  APF_Path_Planning_2023a_BlueI_B.xoffset];
              }

              APF_Path_Planning_2023a_BlueI_B.c_x_m[APF_Path_Planning_2023a_BlueI_B.i_o
                + 6 * APF_Path_Planning_2023a_BlueI_B.b_xoffset] =
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
            }

            for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset < 6;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
              APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 0.0;
              for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
                   APF_Path_Planning_2023a_BlueI_B.xoffset < 13;
                   APF_Path_Planning_2023a_BlueI_B.xoffset++) {
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +=
                  APF_Path_Planning_2023a_BlueI_B.c_x_m[6 *
                  APF_Path_Planning_2023a_BlueI_B.xoffset +
                  APF_Path_Planning_2023a_BlueI_B.i_o] *
                  APF_Path_Planning_2023a_BlueI_B.c_x[6 *
                  APF_Path_Planning_2023a_BlueI_B.xoffset +
                  APF_Path_Planning_2023a_BlueI_B.b_xoffset];
              }

              APF_Path_Planning_2023a_BlueI_B.xoffset = 6 *
                APF_Path_Planning_2023a_BlueI_B.b_xoffset +
                APF_Path_Planning_2023a_BlueI_B.i_o;
              APF_Path_Planning_2023a_BlueI_B.IC[APF_Path_Planning_2023a_BlueI_B.xoffset]
                =
                APF_Path_Planning_2023a_BlueI_P.Q[APF_Path_Planning_2023a_BlueI_B.xoffset]
                + APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
            }
          }

          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 13;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
                 APF_Path_Planning_2023a_BlueI_B.i_o < 3;
                 APF_Path_Planning_2023a_BlueI_B.i_o++) {
              APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 0.0;
              for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
                   APF_Path_Planning_2023a_BlueI_B.b_xoffset < 6;
                   APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +=
                  APF_Path_Planning_2023a_BlueI_P.H[3 *
                  APF_Path_Planning_2023a_BlueI_B.b_xoffset +
                  APF_Path_Planning_2023a_BlueI_B.i_o] *
                  APF_Path_Planning_2023a_BlueI_B.X_Cal_k1[6 *
                  APF_Path_Planning_2023a_BlueI_B.xoffset +
                  APF_Path_Planning_2023a_BlueI_B.b_xoffset];
              }

              APF_Path_Planning_2023a_BlueI_B.Z_Cal[APF_Path_Planning_2023a_BlueI_B.i_o
                + 3 * APF_Path_Planning_2023a_BlueI_B.xoffset] =
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
            }
          }

          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 13;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
              APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 0.0;
              for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
                   APF_Path_Planning_2023a_BlueI_B.xoffset < 13;
                   APF_Path_Planning_2023a_BlueI_B.xoffset++) {
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +=
                  APF_Path_Planning_2023a_BlueI_B.Z_Cal[3 *
                  APF_Path_Planning_2023a_BlueI_B.xoffset +
                  APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
                  APF_Path_Planning_2023a_BlueI_B.w_m[13 *
                  APF_Path_Planning_2023a_BlueI_B.i_o +
                  APF_Path_Planning_2023a_BlueI_B.xoffset];
              }

              APF_Path_Planning_2023a_BlueI_B.d_x[APF_Path_Planning_2023a_BlueI_B.b_xoffset
                + 3 * APF_Path_Planning_2023a_BlueI_B.i_o] =
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
            }
          }

          APF_Path_Planning_2023a_BlueI_B.alpha_pol =
            APF_Path_Planning_2023a_BlueI_B.d_x[0];
          APF_Path_Planning_2023a_BlueI_B.absxk =
            APF_Path_Planning_2023a_BlueI_B.d_x[1];
          APF_Path_Planning_2023a_BlueI_B.t =
            APF_Path_Planning_2023a_BlueI_B.d_x[2];
          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 12;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.b_xoffset =
              (APF_Path_Planning_2023a_BlueI_B.i_o + 1) * 3;
            APF_Path_Planning_2023a_BlueI_B.alpha_pol +=
              APF_Path_Planning_2023a_BlueI_B.d_x[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
            APF_Path_Planning_2023a_BlueI_B.absxk +=
              APF_Path_Planning_2023a_BlueI_B.d_x[APF_Path_Planning_2023a_BlueI_B.b_xoffset
              + 1];
            APF_Path_Planning_2023a_BlueI_B.t +=
              APF_Path_Planning_2023a_BlueI_B.d_x[APF_Path_Planning_2023a_BlueI_B.b_xoffset
              + 2];
          }

          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 13;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.Z_Cal_b[3 *
              APF_Path_Planning_2023a_BlueI_B.i_o] =
              APF_Path_Planning_2023a_BlueI_B.Z_Cal[3 *
              APF_Path_Planning_2023a_BlueI_B.i_o] -
              APF_Path_Planning_2023a_BlueI_B.alpha_pol;
            APF_Path_Planning_2023a_BlueI_B.b_xoffset = 3 *
              APF_Path_Planning_2023a_BlueI_B.i_o + 1;
            APF_Path_Planning_2023a_BlueI_B.Z_Cal_b[APF_Path_Planning_2023a_BlueI_B.b_xoffset]
              =
              APF_Path_Planning_2023a_BlueI_B.Z_Cal[APF_Path_Planning_2023a_BlueI_B.b_xoffset]
              - APF_Path_Planning_2023a_BlueI_B.absxk;
            APF_Path_Planning_2023a_BlueI_B.b_xoffset = 3 *
              APF_Path_Planning_2023a_BlueI_B.i_o + 2;
            APF_Path_Planning_2023a_BlueI_B.Z_Cal_b[APF_Path_Planning_2023a_BlueI_B.b_xoffset]
              =
              APF_Path_Planning_2023a_BlueI_B.Z_Cal[APF_Path_Planning_2023a_BlueI_B.b_xoffset]
              - APF_Path_Planning_2023a_BlueI_B.t;
          }

          memcpy(&APF_Path_Planning_2023a_BlueI_B.Z_Cal[0],
                 &APF_Path_Planning_2023a_BlueI_B.Z_Cal_b[0], 39U * sizeof
                 (real_T));
          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 13;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.d_x[APF_Path_Planning_2023a_BlueI_B.i_o]
              = APF_Path_Planning_2023a_BlueI_B.Z_Cal[3 *
              APF_Path_Planning_2023a_BlueI_B.i_o];
            APF_Path_Planning_2023a_BlueI_B.d_x[APF_Path_Planning_2023a_BlueI_B.i_o
              + 13] = APF_Path_Planning_2023a_BlueI_B.Z_Cal[3 *
              APF_Path_Planning_2023a_BlueI_B.i_o + 1];
            APF_Path_Planning_2023a_BlueI_B.d_x[APF_Path_Planning_2023a_BlueI_B.i_o
              + 26] = APF_Path_Planning_2023a_BlueI_B.Z_Cal[3 *
              APF_Path_Planning_2023a_BlueI_B.i_o + 2];
          }

          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 3;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset < 13;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
              APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 0.0;
              for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
                   APF_Path_Planning_2023a_BlueI_B.xoffset < 13;
                   APF_Path_Planning_2023a_BlueI_B.xoffset++) {
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +=
                  APF_Path_Planning_2023a_BlueI_B.Z_Cal[3 *
                  APF_Path_Planning_2023a_BlueI_B.xoffset +
                  APF_Path_Planning_2023a_BlueI_B.i_o] *
                  APF_Path_Planning_2023a_BlueI_B.w_c[13 *
                  APF_Path_Planning_2023a_BlueI_B.b_xoffset +
                  APF_Path_Planning_2023a_BlueI_B.xoffset];
              }

              APF_Path_Planning_2023a_BlueI_B.Z_Cal_b[APF_Path_Planning_2023a_BlueI_B.i_o
                + 3 * APF_Path_Planning_2023a_BlueI_B.b_xoffset] =
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
            }

            for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
              APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 0.0;
              for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
                   APF_Path_Planning_2023a_BlueI_B.xoffset < 13;
                   APF_Path_Planning_2023a_BlueI_B.xoffset++) {
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +=
                  APF_Path_Planning_2023a_BlueI_B.Z_Cal_b[3 *
                  APF_Path_Planning_2023a_BlueI_B.xoffset +
                  APF_Path_Planning_2023a_BlueI_B.i_o] *
                  APF_Path_Planning_2023a_BlueI_B.d_x[13 *
                  APF_Path_Planning_2023a_BlueI_B.b_xoffset +
                  APF_Path_Planning_2023a_BlueI_B.xoffset];
              }

              APF_Path_Planning_2023a_BlueI_B.xoffset = 3 *
                APF_Path_Planning_2023a_BlueI_B.b_xoffset +
                APF_Path_Planning_2023a_BlueI_B.i_o;
              APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[APF_Path_Planning_2023a_BlueI_B.xoffset]
                =
                APF_Path_Planning_2023a_BlueI_P.R[APF_Path_Planning_2023a_BlueI_B.xoffset]
                + APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
            }
          }

          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 13;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset < 6;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
              APF_Path_Planning_2023a_BlueI_B.xoffset = 6 *
                APF_Path_Planning_2023a_BlueI_B.i_o +
                APF_Path_Planning_2023a_BlueI_B.b_xoffset;
              APF_Path_Planning_2023a_BlueI_B.X_Cal_k1[APF_Path_Planning_2023a_BlueI_B.xoffset]
                =
                APF_Path_Planning_2023a_BlueI_B.X_Cal[APF_Path_Planning_2023a_BlueI_B.xoffset]
                - APF_Path_Planning_2023a_BlueI_B.fill[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
            }
          }

          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 6;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset < 13;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
              APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 0.0;
              for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
                   APF_Path_Planning_2023a_BlueI_B.xoffset < 13;
                   APF_Path_Planning_2023a_BlueI_B.xoffset++) {
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +=
                  APF_Path_Planning_2023a_BlueI_B.X_Cal_k1[6 *
                  APF_Path_Planning_2023a_BlueI_B.xoffset +
                  APF_Path_Planning_2023a_BlueI_B.i_o] *
                  APF_Path_Planning_2023a_BlueI_B.w_c[13 *
                  APF_Path_Planning_2023a_BlueI_B.b_xoffset +
                  APF_Path_Planning_2023a_BlueI_B.xoffset];
              }

              APF_Path_Planning_2023a_BlueI_B.X_Cal[APF_Path_Planning_2023a_BlueI_B.i_o
                + 6 * APF_Path_Planning_2023a_BlueI_B.b_xoffset] =
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
            }

            for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
              APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 0.0;
              for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
                   APF_Path_Planning_2023a_BlueI_B.xoffset < 13;
                   APF_Path_Planning_2023a_BlueI_B.xoffset++) {
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +=
                  APF_Path_Planning_2023a_BlueI_B.X_Cal[6 *
                  APF_Path_Planning_2023a_BlueI_B.xoffset +
                  APF_Path_Planning_2023a_BlueI_B.i_o] *
                  APF_Path_Planning_2023a_BlueI_B.d_x[13 *
                  APF_Path_Planning_2023a_BlueI_B.b_xoffset +
                  APF_Path_Planning_2023a_BlueI_B.xoffset];
              }

              APF_Path_Planning_2023a_BlueI_B.X_Cal_g[APF_Path_Planning_2023a_BlueI_B.i_o
                + 6 * APF_Path_Planning_2023a_BlueI_B.b_xoffset] =
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
            }

            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
              APF_Path_Planning_2023a_BlueI_B.X_Cal_g[APF_Path_Planning_2023a_BlueI_B.i_o
              + 6];
            APF_Path_Planning_2023a_BlueI_B.Sum6_a =
              APF_Path_Planning_2023a_BlueI_B.X_Cal_g[APF_Path_Planning_2023a_BlueI_B.i_o];
            APF_Path_Planning_2023a_BlueI_B.Derivative2 =
              APF_Path_Planning_2023a_BlueI_B.X_Cal_g[APF_Path_Planning_2023a_BlueI_B.i_o
              + 12];
            for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
              APF_Path_Planning_2023a_BlueI_B.B[APF_Path_Planning_2023a_BlueI_B.i_o
                + 6 * APF_Path_Planning_2023a_BlueI_B.b_xoffset] =
                (APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset + 3] *
                 APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
                 APF_Path_Planning_2023a_BlueI_B.Sum6_a *
                 APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset]) +
                APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[APF_Path_Planning_2023a_BlueI_B.b_xoffset
                + 6] * APF_Path_Planning_2023a_BlueI_B.Derivative2;
            }
          }

          APF_Path_Planning_2023a_BlueI_B.rEQ0 = rtIsNaN
            (APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtSFunct[0]);
          if (!APF_Path_Planning_2023a_BlueI_B.rEQ0) {
            APF_Path_Planning_2023a_BlueI_B.rEQ0 = rtIsNaN
              (APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtSFunct[1]);
          }

          if (!APF_Path_Planning_2023a_BlueI_B.rEQ0) {
            APF_Path_Planning_2023a_BlueI_B.rEQ0 = rtIsNaN
              (APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtSFunct[2]);
          }

          if (APF_Path_Planning_2023a_BlueI_B.rEQ0) {
            APF_Path_Planning_2023a_BlueI_B.q = 1000.0;
          } else {
            APF_Path_Planning_2023a_BlueI_B.q =
              APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtSFunct[0];
          }

          APF_Path_Planning_2023a_BlueI_B.Switch =
            APF_Path_Planning_2023a_BlueI_B.q -
            APF_Path_Planning_2023a_BlueI_B.alpha_pol;
          APF_Path_Planning_2023a_BlueI_B.r_co[0] =
            APF_Path_Planning_2023a_BlueI_B.Switch;
          if (APF_Path_Planning_2023a_BlueI_B.rEQ0) {
            APF_Path_Planning_2023a_BlueI_B.q = 1000.0;
          } else {
            APF_Path_Planning_2023a_BlueI_B.q =
              APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtSFunct[1];
          }

          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
            APF_Path_Planning_2023a_BlueI_B.q -
            APF_Path_Planning_2023a_BlueI_B.absxk;
          APF_Path_Planning_2023a_BlueI_B.r_co[1] =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
          if (APF_Path_Planning_2023a_BlueI_B.rEQ0) {
            APF_Path_Planning_2023a_BlueI_B.q = 1000.0;
          } else {
            APF_Path_Planning_2023a_BlueI_B.q =
              APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtSFunct[2];
          }

          APF_Path_Planning_2023a_BlueI_B.Sum6_a =
            APF_Path_Planning_2023a_BlueI_B.q -
            APF_Path_Planning_2023a_BlueI_B.t;
          APF_Path_Planning_2023a_BlueI_B.r_co[2] =
            APF_Path_Planning_2023a_BlueI_B.Sum6_a;
          APF_Path_Planning_2023a_BlueI_B.q = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 3;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.q +=
              ((APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m
                [3 * APF_Path_Planning_2023a_BlueI_B.i_o + 1] *
                APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
                APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m
                [3 * APF_Path_Planning_2023a_BlueI_B.i_o] *
                APF_Path_Planning_2023a_BlueI_B.Switch) +
               APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[3
               * APF_Path_Planning_2023a_BlueI_B.i_o + 2] *
               APF_Path_Planning_2023a_BlueI_B.Sum6_a) *
              APF_Path_Planning_2023a_BlueI_B.r_co[APF_Path_Planning_2023a_BlueI_B.i_o];
          }

          APF_Path_Planning_2023a_BlueI_B.i_o =
            !(APF_Path_Planning_2023a_BlueI_B.q <
              APF_Path_Planning_2023a_BlueI_P.thresh);
          APF_Path_Planning_2023a_BlueI_B.rEQ0 =
            (APF_Path_Planning_2023a_BlueI_B.i_o == 0);
          APF_Path_Planning_2023a_BlueI_B.Z_k[0] =
            APF_Path_Planning_2023a_BlueI_B.Switch;
          APF_Path_Planning_2023a_BlueI_B.Z_k[1] =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
          APF_Path_Planning_2023a_BlueI_B.Z_k[2] =
            APF_Path_Planning_2023a_BlueI_B.Sum6_a;
          APF_Path_Planning_2023a_BlueI_B.Reject =
            (APF_Path_Planning_2023a_BlueI_B.i_o == 0);
          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 6;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 0.0;
            for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
              APF_Path_Planning_2023a_BlueI_B.xoffset = 6 *
                APF_Path_Planning_2023a_BlueI_B.b_xoffset +
                APF_Path_Planning_2023a_BlueI_B.i_o;
              APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +=
                APF_Path_Planning_2023a_BlueI_B.B[APF_Path_Planning_2023a_BlueI_B.xoffset]
                * APF_Path_Planning_2023a_BlueI_B.Z_k[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
              APF_Path_Planning_2023a_BlueI_B.X_Cal_g[APF_Path_Planning_2023a_BlueI_B.xoffset]
                =
                (APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[
                 3 * APF_Path_Planning_2023a_BlueI_B.b_xoffset + 1] *
                 APF_Path_Planning_2023a_BlueI_B.B[APF_Path_Planning_2023a_BlueI_B.i_o
                 + 6] +
                 APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[
                 3 * APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
                 APF_Path_Planning_2023a_BlueI_B.B[APF_Path_Planning_2023a_BlueI_B.i_o])
                + APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m
                [3 * APF_Path_Planning_2023a_BlueI_B.b_xoffset + 2] *
                APF_Path_Planning_2023a_BlueI_B.B[APF_Path_Planning_2023a_BlueI_B.i_o
                + 12];
            }

            if (APF_Path_Planning_2023a_BlueI_B.rEQ0) {
              APF_Path_Planning_2023a_BlueI_B.States[APF_Path_Planning_2023a_BlueI_B.i_o]
                =
                APF_Path_Planning_2023a_BlueI_B.fill[APF_Path_Planning_2023a_BlueI_B.i_o]
                + APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
            } else {
              APF_Path_Planning_2023a_BlueI_B.States[APF_Path_Planning_2023a_BlueI_B.i_o]
                =
                APF_Path_Planning_2023a_BlueI_B.fill[APF_Path_Planning_2023a_BlueI_B.i_o];
            }

            for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset < 6;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
              if (APF_Path_Planning_2023a_BlueI_B.Reject) {
                APF_Path_Planning_2023a_BlueI_B.xoffset = 6 *
                  APF_Path_Planning_2023a_BlueI_B.b_xoffset +
                  APF_Path_Planning_2023a_BlueI_B.i_o;
                APF_Path_Planning_2023a_BlueI_B.P_K[APF_Path_Planning_2023a_BlueI_B.xoffset]
                  =
                  APF_Path_Planning_2023a_BlueI_B.IC[APF_Path_Planning_2023a_BlueI_B.xoffset]
                  - ((APF_Path_Planning_2023a_BlueI_B.X_Cal_g[APF_Path_Planning_2023a_BlueI_B.i_o
                      + 6] *
                      APF_Path_Planning_2023a_BlueI_B.B[APF_Path_Planning_2023a_BlueI_B.b_xoffset
                      + 6] +
                      APF_Path_Planning_2023a_BlueI_B.X_Cal_g[APF_Path_Planning_2023a_BlueI_B.i_o]
                      * APF_Path_Planning_2023a_BlueI_B.B[APF_Path_Planning_2023a_BlueI_B.b_xoffset])
                     + APF_Path_Planning_2023a_BlueI_B.X_Cal_g[APF_Path_Planning_2023a_BlueI_B.i_o
                     + 12] *
                     APF_Path_Planning_2023a_BlueI_B.B[APF_Path_Planning_2023a_BlueI_B.b_xoffset
                     + 12]);
              } else {
                APF_Path_Planning_2023a_BlueI_B.P_K[APF_Path_Planning_2023a_BlueI_B.i_o
                  + 6 * APF_Path_Planning_2023a_BlueI_B.b_xoffset] =
                  APF_Path_Planning_2023a_BlueI_B.IC[6 *
                  APF_Path_Planning_2023a_BlueI_B.b_xoffset +
                  APF_Path_Planning_2023a_BlueI_B.i_o];
              }
            }
          }

          // End of MATLAB Function: '<S356>/MATLAB Function'

          // SignalConversion generated from: '<S361>/ SFunction ' incorporates:
          //   DataStoreRead: '<S353>/Data Store Read'
          //   DataStoreRead: '<S353>/Data Store Read2'
          //   DataStoreRead: '<S353>/Data Store Read3'
          //   DataStoreRead: '<S353>/Data Store Read4'
          //   DataStoreRead: '<S353>/Data Store Read5'
          //   DataStoreRead: '<S353>/Data Store Read6'
          //   MATLAB Function: '<S350>/MATLAB Function'

          APF_Path_Planning_2023a_BlueI_B.fill[0] =
            APF_Path_Planning_2023a_Blue_DW.RED_Px;
          APF_Path_Planning_2023a_BlueI_B.fill[1] =
            APF_Path_Planning_2023a_Blue_DW.RED_Py;
          APF_Path_Planning_2023a_BlueI_B.fill[2] =
            APF_Path_Planning_2023a_Blue_DW.RED_Rz;
          APF_Path_Planning_2023a_BlueI_B.fill[3] =
            APF_Path_Planning_2023a_Blue_DW.RED_Vx;
          APF_Path_Planning_2023a_BlueI_B.fill[4] =
            APF_Path_Planning_2023a_Blue_DW.RED_Vy;
          APF_Path_Planning_2023a_BlueI_B.fill[5] =
            APF_Path_Planning_2023a_Blue_DW.RED_RzD;

          // MATLAB Function: '<S350>/MATLAB Function' incorporates:
          //   DataStoreRead: '<S348>/Data Store Read'
          //   DataStoreRead: '<S348>/Data Store Read2'
          //   DataStoreRead: '<S348>/Data Store Read3'
          //   DataStoreRead: '<S353>/Data Store Read'
          //   DataStoreRead: '<S353>/Data Store Read2'
          //   MATLAB Function: '<S369>/MATLAB Function1'

          APF_Path_Planning_2023a_BlueI_B.path_m[0] =
            APF_Path_Planning_2023a_Blue_DW.RED_Px -
            APF_Path_Planning_2023a_BlueI_B.States[0];
          APF_Path_Planning_2023a_BlueI_B.path_m[1] =
            APF_Path_Planning_2023a_Blue_DW.RED_Py -
            APF_Path_Planning_2023a_BlueI_B.States[1];
          APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp =
            APF_Path_Planning_2023a_BlueI_B.States[2] -
            APF_Path_Planning_2023a_BlueI_B.States[2];
          APF_Path_Planning_2023a_BlueI_B.r_co[0] =
            APF_Path_Planning_2023a_Blue_DW.RED_Px -
            APF_Path_Planning_2023a_Blue_DW.BLUE_Px;
          APF_Path_Planning_2023a_BlueI_B.r_co[1] =
            APF_Path_Planning_2023a_Blue_DW.RED_Py -
            APF_Path_Planning_2023a_Blue_DW.BLUE_Py;
          APF_Path_Planning_2023a_BlueI_B.Switch =
            APF_Path_Planning_2023a_Blue_DW.BLUE_Rz -
            APF_Path_Planning_2023a_Blue_DW.BLUE_Rz;
          APF_Path_Planning_2023a_BlueI_B.r_co[2] =
            APF_Path_Planning_2023a_BlueI_B.Switch;
          APF_Path_Planning_2023a_BlueI_B.link1_com_y = sin
            (APF_Path_Planning_2023a_BlueI_B.States[2]);
          APF_Path_Planning_2023a_BlueI_B.link1_com_x = cos
            (APF_Path_Planning_2023a_BlueI_B.States[2]);
          APF_Path_Planning_2023a_BlueI_B.alpha_pol =
            (APF_Path_Planning_rt_atan2d_snf
             (APF_Path_Planning_2023a_Blue_DW.RED_Px - (0.165 *
               APF_Path_Planning_2023a_BlueI_B.link1_com_x +
               APF_Path_Planning_2023a_BlueI_B.States[0]),
              (APF_Path_Planning_2023a_Blue_DW.RED_Py - 0.165 *
               APF_Path_Planning_2023a_BlueI_B.link1_com_y) -
              APF_Path_Planning_2023a_BlueI_B.States[1]) + 1.5707963267948966) +
            APF_Path_Planning_2023a_BlueI_B.States[2];

          // End of Outputs for SubSystem: '<S89>/Sub-Phase #4'
          APF_Path_Planning_2023a_BlueI_B.i_o = 0;

          // Outputs for IfAction SubSystem: '<S89>/Sub-Phase #4' incorporates:
          //   ActionPort: '<S247>/Action Port'

          // MATLAB Function: '<S350>/MATLAB Function'
          APF_Path_Planning_2023a_BlueI_B.Reject =
            ((APF_Path_Planning_2023a_BlueI_B.alpha_pol < -3.1415926535897931) ||
             (APF_Path_Planning_2023a_BlueI_B.alpha_pol > 3.1415926535897931));
          if (APF_Path_Planning_2023a_BlueI_B.Reject) {
            for (APF_Path_Planning_2023a_BlueI_B.i = 0;
                 APF_Path_Planning_2023a_BlueI_B.i < 1;
                 APF_Path_Planning_2023a_BlueI_B.i++) {
              APF_Path_Planning_2023a_BlueI_B.i_o++;
            }
          }

          // MATLAB Function: '<S350>/MATLAB Function'
          if (APF_Path_Planning_2023a_BlueI_B.i_o - 1 >= 0) {
            if (rtIsNaN(APF_Path_Planning_2023a_BlueI_B.alpha_pol +
                        3.1415926535897931)) {
              APF_Path_Planning_2023a_BlueI_B.absxk = (rtNaN);
            } else if (rtIsInf(APF_Path_Planning_2023a_BlueI_B.alpha_pol +
                               3.1415926535897931)) {
              APF_Path_Planning_2023a_BlueI_B.absxk = (rtNaN);
            } else if (APF_Path_Planning_2023a_BlueI_B.alpha_pol +
                       3.1415926535897931 == 0.0) {
              APF_Path_Planning_2023a_BlueI_B.absxk = 0.0;
            } else {
              APF_Path_Planning_2023a_BlueI_B.absxk = fmod
                (APF_Path_Planning_2023a_BlueI_B.alpha_pol + 3.1415926535897931,
                 6.2831853071795862);
              APF_Path_Planning_2023a_BlueI_B.rEQ0 =
                (APF_Path_Planning_2023a_BlueI_B.absxk == 0.0);
              if (!APF_Path_Planning_2023a_BlueI_B.rEQ0) {
                APF_Path_Planning_2023a_BlueI_B.q = fabs
                  ((APF_Path_Planning_2023a_BlueI_B.alpha_pol +
                    3.1415926535897931) / 6.2831853071795862);
                APF_Path_Planning_2023a_BlueI_B.rEQ0 = !(fabs
                  (APF_Path_Planning_2023a_BlueI_B.q - floor
                   (APF_Path_Planning_2023a_BlueI_B.q + 0.5)) >
                  2.2204460492503131E-16 * APF_Path_Planning_2023a_BlueI_B.q);
              }

              if (APF_Path_Planning_2023a_BlueI_B.rEQ0) {
                APF_Path_Planning_2023a_BlueI_B.absxk = 0.0;
              } else if (APF_Path_Planning_2023a_BlueI_B.alpha_pol +
                         3.1415926535897931 < 0.0) {
                APF_Path_Planning_2023a_BlueI_B.absxk += 6.2831853071795862;
              }
            }

            APF_Path_Planning_2023a_BlueI_B.varargin_1_data =
              APF_Path_Planning_2023a_BlueI_B.absxk;
          }

          if (APF_Path_Planning_2023a_BlueI_B.i_o - 1 >= 0) {
            APF_Path_Planning_2023a_BlueI_B.i = 0;
            APF_Path_Planning_2023a_BlueI_B.tmp_data =
              ((APF_Path_Planning_2023a_BlueI_B.varargin_1_data == 0.0) &&
               (APF_Path_Planning_2023a_BlueI_B.alpha_pol + 3.1415926535897931 >
                0.0));
          }

          // End of Outputs for SubSystem: '<S89>/Sub-Phase #4'
          APF_Path_Planning_2023a_BlueI_B.ar = 0;

          // Outputs for IfAction SubSystem: '<S89>/Sub-Phase #4' incorporates:
          //   ActionPort: '<S247>/Action Port'

          if (APF_Path_Planning_2023a_BlueI_B.tmp_data &&
              (APF_Path_Planning_2023a_BlueI_B.i_o - 1 >= 0)) {
            APF_Path_Planning_2023a_BlueI_B.varargin_1_data = 6.2831853071795862;
          }

          // MATLAB Function: '<S350>/MATLAB Function'
          APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 =
            APF_Path_Planning_2023a_BlueI_B.alpha_pol;

          // End of Outputs for SubSystem: '<S89>/Sub-Phase #4'
          APF_Path_Planning_2023a_BlueI_B.i_o = 0;

          // Outputs for IfAction SubSystem: '<S89>/Sub-Phase #4' incorporates:
          //   ActionPort: '<S247>/Action Port'

          if (APF_Path_Planning_2023a_BlueI_B.Reject) {
            for (APF_Path_Planning_2023a_BlueI_B.i = 0;
                 APF_Path_Planning_2023a_BlueI_B.i < 1;
                 APF_Path_Planning_2023a_BlueI_B.i++) {
              // MATLAB Function: '<S350>/MATLAB Function'
              APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 =
                APF_Path_Planning_2023a_BlueI_B.varargin_1_data -
                3.1415926535897931;
              APF_Path_Planning_2023a_BlueI_B.i_o++;
            }
          }

          // MATLAB Function: '<S350>/MATLAB Function' incorporates:
          //   MATLAB Function: '<S247>/Looking Angle'
          //   MATLAB Function: '<S369>/MATLAB Function1'

          if ((APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 >= 0.0) &&
              (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 <
               1.5707963267948966)) {
            APF_Path_Planning_2023a_BlueI_B.q = cos
              (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
            APF_Path_Planning_2023a_BlueI_B.alpha_pol = sin
              (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
            APF_Path_Planning_2023a_BlueI_B.alpha_pol = 2.0 *
              APF_Path_Planning_2023a_BlueI_P.shape[3] *
              APF_Path_Planning_2023a_BlueI_P.shape[0] *
              APF_Path_Planning_2023a_BlueI_P.shape[0] *
              APF_Path_Planning_2023a_BlueI_B.q /
              (APF_Path_Planning_2023a_BlueI_P.shape[0] *
               APF_Path_Planning_2023a_BlueI_P.shape[0] *
               (APF_Path_Planning_2023a_BlueI_B.q *
                APF_Path_Planning_2023a_BlueI_B.q) +
               APF_Path_Planning_2023a_BlueI_P.shape[3] *
               APF_Path_Planning_2023a_BlueI_P.shape[3] *
               (APF_Path_Planning_2023a_BlueI_B.alpha_pol *
                APF_Path_Planning_2023a_BlueI_B.alpha_pol));
          } else if ((APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 >=
                      1.5707963267948966) &&
                     (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 <
                      3.1415926535897931)) {
            APF_Path_Planning_2023a_BlueI_B.q = cos
              (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
            APF_Path_Planning_2023a_BlueI_B.alpha_pol = sin
              (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
            APF_Path_Planning_2023a_BlueI_B.alpha_pol = -2.0 *
              APF_Path_Planning_2023a_BlueI_P.shape[4] *
              APF_Path_Planning_2023a_BlueI_P.shape[1] *
              APF_Path_Planning_2023a_BlueI_P.shape[1] *
              APF_Path_Planning_2023a_BlueI_B.q /
              (APF_Path_Planning_2023a_BlueI_P.shape[1] *
               APF_Path_Planning_2023a_BlueI_P.shape[1] *
               (APF_Path_Planning_2023a_BlueI_B.q *
                APF_Path_Planning_2023a_BlueI_B.q) +
               APF_Path_Planning_2023a_BlueI_P.shape[4] *
               APF_Path_Planning_2023a_BlueI_P.shape[4] *
               (APF_Path_Planning_2023a_BlueI_B.alpha_pol *
                APF_Path_Planning_2023a_BlueI_B.alpha_pol));
          } else if ((APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 >=
                      -3.1415926535897931) &&
                     (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 <
                      -1.5707963267948966)) {
            APF_Path_Planning_2023a_BlueI_B.q = cos
              (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
            APF_Path_Planning_2023a_BlueI_B.alpha_pol = sin
              (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
            APF_Path_Planning_2023a_BlueI_B.alpha_pol = 2.0 *
              APF_Path_Planning_2023a_BlueI_P.shape[4] *
              APF_Path_Planning_2023a_BlueI_P.shape[2] / sqrt(4.0 *
              APF_Path_Planning_2023a_BlueI_P.shape[4] *
              APF_Path_Planning_2023a_BlueI_P.shape[4] *
              (APF_Path_Planning_2023a_BlueI_B.alpha_pol *
               APF_Path_Planning_2023a_BlueI_B.alpha_pol) +
              APF_Path_Planning_2023a_BlueI_P.shape[2] *
              APF_Path_Planning_2023a_BlueI_P.shape[2] *
              (APF_Path_Planning_2023a_BlueI_B.q *
               APF_Path_Planning_2023a_BlueI_B.q));
          } else if (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 >=
                     -1.5707963267948966) {
            if (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 < 0.0) {
              APF_Path_Planning_2023a_BlueI_B.q = cos
                (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
              APF_Path_Planning_2023a_BlueI_B.alpha_pol = sin
                (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
              APF_Path_Planning_2023a_BlueI_B.alpha_pol = 2.0 *
                APF_Path_Planning_2023a_BlueI_P.shape[3] *
                APF_Path_Planning_2023a_BlueI_P.shape[2] / sqrt(4.0 *
                APF_Path_Planning_2023a_BlueI_P.shape[4] *
                APF_Path_Planning_2023a_BlueI_P.shape[4] *
                (APF_Path_Planning_2023a_BlueI_B.alpha_pol *
                 APF_Path_Planning_2023a_BlueI_B.alpha_pol) +
                APF_Path_Planning_2023a_BlueI_P.shape[2] *
                APF_Path_Planning_2023a_BlueI_P.shape[2] *
                (APF_Path_Planning_2023a_BlueI_B.q *
                 APF_Path_Planning_2023a_BlueI_B.q));
            } else {
              APF_Path_Planning_2023a_BlueI_B.alpha_pol = 0.0;
            }
          } else {
            APF_Path_Planning_2023a_BlueI_B.alpha_pol = 0.0;
          }

          APF_Path_Planning_2023a_BlueI_B.q =
            APF_Path_Planning_2023a_BlueI_B.alpha_pol * cos
            (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
          APF_Path_Planning_2023a_BlueI_B.alpha_pol *= sin
            (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
          APF_Path_Planning_2023a_BlueI_B.q = APF_Path_Planning_rt_hypotd_snf
            (APF_Path_Planning_2023a_BlueI_B.link1_com_x *
             APF_Path_Planning_2023a_BlueI_B.q +
             -APF_Path_Planning_2023a_BlueI_B.link1_com_y *
             APF_Path_Planning_2023a_BlueI_B.alpha_pol,
             APF_Path_Planning_2023a_BlueI_B.link1_com_y *
             APF_Path_Planning_2023a_BlueI_B.q +
             APF_Path_Planning_2023a_BlueI_B.link1_com_x *
             APF_Path_Planning_2023a_BlueI_B.alpha_pol);
          APF_Path_Planning_2023a_BlueI_B.alpha_pol = 3.3121686421112381E-170;
          APF_Path_Planning_2023a_BlueI_B.absxk = fabs
            (APF_Path_Planning_2023a_BlueI_B.path_m[0]);
          if (APF_Path_Planning_2023a_BlueI_B.absxk > 3.3121686421112381E-170) {
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 1.0;
            APF_Path_Planning_2023a_BlueI_B.alpha_pol =
              APF_Path_Planning_2023a_BlueI_B.absxk;
          } else {
            APF_Path_Planning_2023a_BlueI_B.t =
              APF_Path_Planning_2023a_BlueI_B.absxk / 3.3121686421112381E-170;
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
              APF_Path_Planning_2023a_BlueI_B.t *
              APF_Path_Planning_2023a_BlueI_B.t;
          }

          APF_Path_Planning_2023a_BlueI_B.absxk = fabs
            (APF_Path_Planning_2023a_BlueI_B.path_m[1]);
          if (APF_Path_Planning_2023a_BlueI_B.absxk >
              APF_Path_Planning_2023a_BlueI_B.alpha_pol) {
            APF_Path_Planning_2023a_BlueI_B.t =
              APF_Path_Planning_2023a_BlueI_B.alpha_pol /
              APF_Path_Planning_2023a_BlueI_B.absxk;
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
              APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW *
              APF_Path_Planning_2023a_BlueI_B.t *
              APF_Path_Planning_2023a_BlueI_B.t + 1.0;
            APF_Path_Planning_2023a_BlueI_B.alpha_pol =
              APF_Path_Planning_2023a_BlueI_B.absxk;
          } else {
            APF_Path_Planning_2023a_BlueI_B.t =
              APF_Path_Planning_2023a_BlueI_B.absxk /
              APF_Path_Planning_2023a_BlueI_B.alpha_pol;
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +=
              APF_Path_Planning_2023a_BlueI_B.t *
              APF_Path_Planning_2023a_BlueI_B.t;
          }

          APF_Path_Planning_2023a_BlueI_B.absxk = fabs
            (APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp);
          if (APF_Path_Planning_2023a_BlueI_B.absxk >
              APF_Path_Planning_2023a_BlueI_B.alpha_pol) {
            APF_Path_Planning_2023a_BlueI_B.t =
              APF_Path_Planning_2023a_BlueI_B.alpha_pol /
              APF_Path_Planning_2023a_BlueI_B.absxk;
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
              APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW *
              APF_Path_Planning_2023a_BlueI_B.t *
              APF_Path_Planning_2023a_BlueI_B.t + 1.0;
            APF_Path_Planning_2023a_BlueI_B.alpha_pol =
              APF_Path_Planning_2023a_BlueI_B.absxk;
          } else {
            APF_Path_Planning_2023a_BlueI_B.t =
              APF_Path_Planning_2023a_BlueI_B.absxk /
              APF_Path_Planning_2023a_BlueI_B.alpha_pol;
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +=
              APF_Path_Planning_2023a_BlueI_B.t *
              APF_Path_Planning_2023a_BlueI_B.t;
          }

          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
            APF_Path_Planning_2023a_BlueI_B.alpha_pol * sqrt
            (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW);
          APF_Path_Planning_2023a_BlueI_B.alpha_pol =
            APF_Path_Planning_2023a_BlueI_B.path_m[0] -
            APF_Path_Planning_2023a_BlueI_B.q *
            APF_Path_Planning_2023a_BlueI_B.path_m[0] /
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
          APF_Path_Planning_2023a_BlueI_B.path_m[0] =
            APF_Path_Planning_2023a_BlueI_B.alpha_pol;
          APF_Path_Planning_2023a_BlueI_B.t =
            -APF_Path_Planning_2023a_BlueI_B.alpha_pol;
          APF_Path_Planning_2023a_BlueI_B.alpha_pol =
            APF_Path_Planning_2023a_BlueI_B.path_m[1] -
            APF_Path_Planning_2023a_BlueI_B.q *
            APF_Path_Planning_2023a_BlueI_B.path_m[1] /
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
          APF_Path_Planning_2023a_BlueI_B.path_m[1] =
            APF_Path_Planning_2023a_BlueI_B.alpha_pol;
          APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 =
            -APF_Path_Planning_2023a_BlueI_B.alpha_pol;
          APF_Path_Planning_2023a_BlueI_B.alpha_pol =
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp -
            APF_Path_Planning_2023a_BlueI_B.q *
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp /
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
          APF_Path_Planning_2023a_BlueI_B.path_m[2] =
            APF_Path_Planning_2023a_BlueI_B.alpha_pol;
          APF_Path_Planning_2023a_BlueI_B.absxk = 0.0;
          APF_Path_Planning_2023a_BlueI_B.t34 =
            -APF_Path_Planning_2023a_BlueI_B.r_co[0];
          APF_Path_Planning_2023a_BlueI_B.t35 =
            -APF_Path_Planning_2023a_BlueI_B.r_co[1];
          APF_Path_Planning_2023a_BlueI_B.q = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 3;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.b_xoffset = 3 *
              APF_Path_Planning_2023a_BlueI_B.i_o + 1;
            APF_Path_Planning_2023a_BlueI_B.xoffset = 3 *
              APF_Path_Planning_2023a_BlueI_B.i_o + 2;
            APF_Path_Planning_2023a_BlueI_B.absxk +=
              ((APF_Path_Planning_2023a_BlueI_P.P_b[3 *
                APF_Path_Planning_2023a_BlueI_B.i_o] *
                APF_Path_Planning_2023a_BlueI_B.t +
                APF_Path_Planning_2023a_BlueI_P.P_b[APF_Path_Planning_2023a_BlueI_B.b_xoffset]
                * APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1) +
               APF_Path_Planning_2023a_BlueI_P.P_b[APF_Path_Planning_2023a_BlueI_B.xoffset]
               * -APF_Path_Planning_2023a_BlueI_B.alpha_pol) *
              APF_Path_Planning_2023a_BlueI_B.path_m[APF_Path_Planning_2023a_BlueI_B.i_o];
            APF_Path_Planning_2023a_BlueI_B.q +=
              ((APF_Path_Planning_2023a_BlueI_P.Nmat[3 *
                APF_Path_Planning_2023a_BlueI_B.i_o] *
                APF_Path_Planning_2023a_BlueI_B.t34 +
                APF_Path_Planning_2023a_BlueI_P.Nmat[APF_Path_Planning_2023a_BlueI_B.b_xoffset]
                * APF_Path_Planning_2023a_BlueI_B.t35) +
               APF_Path_Planning_2023a_BlueI_P.Nmat[APF_Path_Planning_2023a_BlueI_B.xoffset]
               * -APF_Path_Planning_2023a_BlueI_B.Switch) *
              APF_Path_Planning_2023a_BlueI_B.r_co[APF_Path_Planning_2023a_BlueI_B.i_o];
          }

          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 9;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[APF_Path_Planning_2023a_BlueI_B.i_o]
              = APF_Path_Planning_2023a_BlueI_P.ka *
              APF_Path_Planning_2023a_BlueI_P.Q_a[APF_Path_Planning_2023a_BlueI_B.i_o];
          }

          APF_Path_Planning_2023a_BlueI_B.IC1[0] =
            (APF_Path_Planning_2023a_BlueI_B.States[0] -
             APF_Path_Planning_2023a_BlueI_P.r_hold *
             APF_Path_Planning_2023a_BlueI_B.link1_com_y) +
            APF_Path_Planning_2023a_BlueI_P.r_off *
            APF_Path_Planning_2023a_BlueI_B.link1_com_x;
          APF_Path_Planning_2023a_BlueI_B.IC1[1] =
            (APF_Path_Planning_2023a_BlueI_P.r_off *
             APF_Path_Planning_2023a_BlueI_B.link1_com_y +
             APF_Path_Planning_2023a_BlueI_B.States[1]) +
            APF_Path_Planning_2023a_BlueI_P.r_hold *
            APF_Path_Planning_2023a_BlueI_B.link1_com_x;
          APF_Path_Planning_2023a_BlueI_B.IC1[2] =
            APF_Path_Planning_2023a_BlueI_B.States[2] + 3.1415926535897931;
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
            APF_Path_Planning_2023a_BlueI_P.r_off * cos
            (APF_Path_Planning_2023a_BlueI_B.States[2]);
          APF_Path_Planning_2023a_BlueI_B.Sum6_a =
            (APF_Path_Planning_2023a_BlueI_B.States[3] -
             APF_Path_Planning_2023a_BlueI_P.r_hold * sin
             (APF_Path_Planning_2023a_BlueI_B.States[2]) *
             APF_Path_Planning_2023a_BlueI_B.States[5]) +
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW *
            APF_Path_Planning_2023a_BlueI_B.States[5];
          APF_Path_Planning_2023a_BlueI_B.IC1[3] =
            APF_Path_Planning_2023a_BlueI_B.Sum6_a;
          APF_Path_Planning_2023a_BlueI_B.Derivative2 =
            (APF_Path_Planning_2023a_BlueI_P.r_hold * cos
             (APF_Path_Planning_2023a_BlueI_B.States[2]) *
             APF_Path_Planning_2023a_BlueI_B.States[5] +
             APF_Path_Planning_2023a_BlueI_B.States[4]) +
            APF_Path_Planning_2023a_BlueI_P.r_off * sin
            (APF_Path_Planning_2023a_BlueI_B.States[2]) *
            APF_Path_Planning_2023a_BlueI_B.States[5];
          APF_Path_Planning_2023a_BlueI_B.IC1[4] =
            APF_Path_Planning_2023a_BlueI_B.Derivative2;
          APF_Path_Planning_2023a_BlueI_B.IC1[5] =
            APF_Path_Planning_2023a_BlueI_B.States[5];
          APF_Path_Planning_2023a_BlueI_B.rtb_path_idx_1 = 2.0 *
            APF_Path_Planning_2023a_BlueI_P.kr * exp
            (APF_Path_Planning_2023a_BlueI_B.absxk);
          APF_Path_Planning_2023a_BlueI_B.absx_tmp = 2.0 *
            APF_Path_Planning_2023a_BlueI_P.psi /
            APF_Path_Planning_2023a_BlueI_P.sigma;
          APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 = exp
            (APF_Path_Planning_2023a_BlueI_B.q /
             APF_Path_Planning_2023a_BlueI_P.sigma) *
            APF_Path_Planning_2023a_BlueI_B.absx_tmp;
          APF_Path_Planning_2023a_BlueI_B.q =
            APF_Path_Planning_2023a_BlueI_B.r_co[1];
          APF_Path_Planning_2023a_BlueI_B.t34 =
            APF_Path_Planning_2023a_BlueI_B.r_co[0];
          APF_Path_Planning_2023a_BlueI_B.absxk =
            APF_Path_Planning_2023a_BlueI_B.path_m[1];
          APF_Path_Planning_2023a_BlueI_B.t =
            APF_Path_Planning_2023a_BlueI_B.path_m[0];
          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 3;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.Z_k[APF_Path_Planning_2023a_BlueI_B.i_o]
              =
              APF_Path_Planning_2023a_BlueI_B.fill[APF_Path_Planning_2023a_BlueI_B.i_o]
              - APF_Path_Planning_2023a_BlueI_B.IC1[APF_Path_Planning_2023a_BlueI_B.i_o];
            APF_Path_Planning_2023a_BlueI_B.dv1[APF_Path_Planning_2023a_BlueI_B.i_o]
              =
              (APF_Path_Planning_2023a_BlueI_P.Nmat[APF_Path_Planning_2023a_BlueI_B.i_o
               + 3] * APF_Path_Planning_2023a_BlueI_B.q +
               APF_Path_Planning_2023a_BlueI_P.Nmat[APF_Path_Planning_2023a_BlueI_B.i_o]
               * APF_Path_Planning_2023a_BlueI_B.t34) +
              APF_Path_Planning_2023a_BlueI_P.Nmat[APF_Path_Planning_2023a_BlueI_B.i_o
              + 6] * APF_Path_Planning_2023a_BlueI_B.Switch;
            APF_Path_Planning_2023a_BlueI_B.dv[APF_Path_Planning_2023a_BlueI_B.i_o]
              =
              (APF_Path_Planning_2023a_BlueI_P.P_b[APF_Path_Planning_2023a_BlueI_B.i_o
               + 3] * APF_Path_Planning_2023a_BlueI_B.absxk +
               APF_Path_Planning_2023a_BlueI_P.P_b[APF_Path_Planning_2023a_BlueI_B.i_o]
               * APF_Path_Planning_2023a_BlueI_B.t) +
              APF_Path_Planning_2023a_BlueI_P.P_b[APF_Path_Planning_2023a_BlueI_B.i_o
              + 6] * APF_Path_Planning_2023a_BlueI_B.alpha_pol;
          }

          APF_Path_Planning_2023a_BlueI_B.alpha_pol =
            APF_Path_Planning_2023a_BlueI_B.Z_k[1];
          APF_Path_Planning_2023a_BlueI_B.absxk =
            APF_Path_Planning_2023a_BlueI_B.Z_k[0];
          APF_Path_Planning_2023a_BlueI_B.t =
            APF_Path_Planning_2023a_BlueI_B.Z_k[2];
          for (APF_Path_Planning_2023a_BlueI_B.i = 0;
               APF_Path_Planning_2023a_BlueI_B.i < 3;
               APF_Path_Planning_2023a_BlueI_B.i++) {
            APF_Path_Planning_2023a_BlueI_B.q =
              (((APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[
                 APF_Path_Planning_2023a_BlueI_B.i + 3] *
                 APF_Path_Planning_2023a_BlueI_B.alpha_pol +
                 APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[
                 APF_Path_Planning_2023a_BlueI_B.i] *
                 APF_Path_Planning_2023a_BlueI_B.absxk) +
                APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[APF_Path_Planning_2023a_BlueI_B.i
                + 6] * APF_Path_Planning_2023a_BlueI_B.t) -
               APF_Path_Planning_2023a_BlueI_B.rtb_path_idx_1 *
               APF_Path_Planning_2023a_BlueI_B.dv[APF_Path_Planning_2023a_BlueI_B.i])
              - APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 *
              APF_Path_Planning_2023a_BlueI_B.dv1[APF_Path_Planning_2023a_BlueI_B.i];
            APF_Path_Planning_2023a_BlueI_B.Z_k[APF_Path_Planning_2023a_BlueI_B.i]
              = APF_Path_Planning_2023a_BlueI_B.q;

            // MATLAB Function: '<S368>/Momentum' incorporates:
            //   Delay: '<S368>/Delay'

            APF_Path_Planning_2023a_BlueI_B.Sum3[APF_Path_Planning_2023a_BlueI_B.i]
              = -APF_Path_Planning_2023a_BlueI_P.momentum_gamma *
              APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_c[APF_Path_Planning_2023a_BlueI_B.i]
              - APF_Path_Planning_2023a_BlueI_P.momentum_eta *
              APF_Path_Planning_2023a_BlueI_B.q;
          }

          // MATLAB Function: '<S369>/MATLAB Function1' incorporates:
          //   DataStoreRead: '<S348>/Data Store Read'
          //   DataStoreRead: '<S348>/Data Store Read2'
          //   DataStoreRead: '<S353>/Data Store Read'
          //   DataStoreRead: '<S353>/Data Store Read2'
          //   DataStoreRead: '<S353>/Data Store Read3'
          //   DataStoreRead: '<S353>/Data Store Read4'
          //   DataStoreRead: '<S353>/Data Store Read5'
          //   DataStoreRead: '<S353>/Data Store Read6'

          APF_Path_Planning_2023a_BlueI_B.state_red[0] =
            APF_Path_Planning_2023a_BlueI_P.nesterov_gamma *
            APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_o[0] +
            APF_Path_Planning_2023a_Blue_DW.RED_Px;
          APF_Path_Planning_2023a_BlueI_B.state_red[1] =
            APF_Path_Planning_2023a_BlueI_P.nesterov_gamma *
            APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_o[1] +
            APF_Path_Planning_2023a_Blue_DW.RED_Py;
          APF_Path_Planning_2023a_BlueI_B.state_red[2] =
            APF_Path_Planning_2023a_BlueI_P.nesterov_gamma *
            APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_o[2] +
            APF_Path_Planning_2023a_Blue_DW.RED_Rz;
          APF_Path_Planning_2023a_BlueI_B.state_red[3] =
            APF_Path_Planning_2023a_BlueI_P.nesterov_gamma * 0.0 +
            APF_Path_Planning_2023a_Blue_DW.RED_Vx;
          APF_Path_Planning_2023a_BlueI_B.state_red[4] =
            APF_Path_Planning_2023a_BlueI_P.nesterov_gamma * 0.0 +
            APF_Path_Planning_2023a_Blue_DW.RED_Vy;
          APF_Path_Planning_2023a_BlueI_B.state_red[5] =
            APF_Path_Planning_2023a_BlueI_P.nesterov_gamma * 0.0 +
            APF_Path_Planning_2023a_Blue_DW.RED_RzD;
          APF_Path_Planning_2023a_BlueI_B.path_m[0] =
            APF_Path_Planning_2023a_BlueI_B.state_red[0] -
            APF_Path_Planning_2023a_BlueI_B.States[0];
          APF_Path_Planning_2023a_BlueI_B.path_m[1] =
            APF_Path_Planning_2023a_BlueI_B.state_red[1] -
            APF_Path_Planning_2023a_BlueI_B.States[1];
          APF_Path_Planning_2023a_BlueI_B.r_co[0] =
            APF_Path_Planning_2023a_BlueI_B.state_red[0] -
            APF_Path_Planning_2023a_Blue_DW.BLUE_Px;
          APF_Path_Planning_2023a_BlueI_B.r_co[1] =
            APF_Path_Planning_2023a_BlueI_B.state_red[1] -
            APF_Path_Planning_2023a_Blue_DW.BLUE_Py;
          APF_Path_Planning_2023a_BlueI_B.r_co[2] =
            APF_Path_Planning_2023a_BlueI_B.Switch;
          APF_Path_Planning_2023a_BlueI_B.alpha_pol =
            (APF_Path_Planning_rt_atan2d_snf
             (APF_Path_Planning_2023a_BlueI_B.state_red[0] - (0.165 * cos
               (APF_Path_Planning_2023a_BlueI_B.States[2]) +
               APF_Path_Planning_2023a_BlueI_B.States[0]),
              (APF_Path_Planning_2023a_BlueI_B.state_red[1] - 0.165 * sin
               (APF_Path_Planning_2023a_BlueI_B.States[2])) -
              APF_Path_Planning_2023a_BlueI_B.States[1]) + 1.5707963267948966) +
            APF_Path_Planning_2023a_BlueI_B.States[2];

          // End of Outputs for SubSystem: '<S89>/Sub-Phase #4'
          APF_Path_Planning_2023a_BlueI_B.i_o = 0;

          // Outputs for IfAction SubSystem: '<S89>/Sub-Phase #4' incorporates:
          //   ActionPort: '<S247>/Action Port'

          // MATLAB Function: '<S369>/MATLAB Function1'
          APF_Path_Planning_2023a_BlueI_B.Reject =
            ((APF_Path_Planning_2023a_BlueI_B.alpha_pol < -3.1415926535897931) ||
             (APF_Path_Planning_2023a_BlueI_B.alpha_pol > 3.1415926535897931));
          if (APF_Path_Planning_2023a_BlueI_B.Reject) {
            for (APF_Path_Planning_2023a_BlueI_B.i = 0;
                 APF_Path_Planning_2023a_BlueI_B.i < 1;
                 APF_Path_Planning_2023a_BlueI_B.i++) {
              APF_Path_Planning_2023a_BlueI_B.i_o++;
            }
          }

          // MATLAB Function: '<S369>/MATLAB Function1'
          if (APF_Path_Planning_2023a_BlueI_B.i_o - 1 >= 0) {
            if (rtIsNaN(APF_Path_Planning_2023a_BlueI_B.alpha_pol +
                        3.1415926535897931)) {
              APF_Path_Planning_2023a_BlueI_B.absxk = (rtNaN);
            } else if (rtIsInf(APF_Path_Planning_2023a_BlueI_B.alpha_pol +
                               3.1415926535897931)) {
              APF_Path_Planning_2023a_BlueI_B.absxk = (rtNaN);
            } else if (APF_Path_Planning_2023a_BlueI_B.alpha_pol +
                       3.1415926535897931 == 0.0) {
              APF_Path_Planning_2023a_BlueI_B.absxk = 0.0;
            } else {
              APF_Path_Planning_2023a_BlueI_B.absxk = fmod
                (APF_Path_Planning_2023a_BlueI_B.alpha_pol + 3.1415926535897931,
                 6.2831853071795862);
              APF_Path_Planning_2023a_BlueI_B.rEQ0 =
                (APF_Path_Planning_2023a_BlueI_B.absxk == 0.0);
              if (!APF_Path_Planning_2023a_BlueI_B.rEQ0) {
                APF_Path_Planning_2023a_BlueI_B.q = fabs
                  ((APF_Path_Planning_2023a_BlueI_B.alpha_pol +
                    3.1415926535897931) / 6.2831853071795862);
                APF_Path_Planning_2023a_BlueI_B.rEQ0 = !(fabs
                  (APF_Path_Planning_2023a_BlueI_B.q - floor
                   (APF_Path_Planning_2023a_BlueI_B.q + 0.5)) >
                  2.2204460492503131E-16 * APF_Path_Planning_2023a_BlueI_B.q);
              }

              if (APF_Path_Planning_2023a_BlueI_B.rEQ0) {
                APF_Path_Planning_2023a_BlueI_B.absxk = 0.0;
              } else if (APF_Path_Planning_2023a_BlueI_B.alpha_pol +
                         3.1415926535897931 < 0.0) {
                APF_Path_Planning_2023a_BlueI_B.absxk += 6.2831853071795862;
              }
            }

            APF_Path_Planning_2023a_BlueI_B.varargin_1_data =
              APF_Path_Planning_2023a_BlueI_B.absxk;
          }

          if (APF_Path_Planning_2023a_BlueI_B.i_o - 1 >= 0) {
            APF_Path_Planning_2023a_BlueI_B.tmp_data =
              ((APF_Path_Planning_2023a_BlueI_B.varargin_1_data == 0.0) &&
               (APF_Path_Planning_2023a_BlueI_B.alpha_pol + 3.1415926535897931 >
                0.0));
          }

          if (APF_Path_Planning_2023a_BlueI_B.tmp_data &&
              (APF_Path_Planning_2023a_BlueI_B.i_o - 1 >= 0)) {
            APF_Path_Planning_2023a_BlueI_B.varargin_1_data = 6.2831853071795862;
          }

          // MATLAB Function: '<S369>/MATLAB Function1'
          APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 =
            APF_Path_Planning_2023a_BlueI_B.alpha_pol;

          // End of Outputs for SubSystem: '<S89>/Sub-Phase #4'
          APF_Path_Planning_2023a_BlueI_B.i_o = 0;

          // Outputs for IfAction SubSystem: '<S89>/Sub-Phase #4' incorporates:
          //   ActionPort: '<S247>/Action Port'

          if (APF_Path_Planning_2023a_BlueI_B.Reject) {
            for (APF_Path_Planning_2023a_BlueI_B.i = 0;
                 APF_Path_Planning_2023a_BlueI_B.i < 1;
                 APF_Path_Planning_2023a_BlueI_B.i++) {
              // MATLAB Function: '<S369>/MATLAB Function1'
              APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 =
                APF_Path_Planning_2023a_BlueI_B.varargin_1_data -
                3.1415926535897931;
              APF_Path_Planning_2023a_BlueI_B.i_o++;
            }
          }

          // MATLAB Function: '<S369>/MATLAB Function1'
          if ((APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 >= 0.0) &&
              (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 <
               1.5707963267948966)) {
            APF_Path_Planning_2023a_BlueI_B.q = cos
              (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
            APF_Path_Planning_2023a_BlueI_B.alpha_pol = sin
              (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
            APF_Path_Planning_2023a_BlueI_B.alpha_pol = 2.0 *
              APF_Path_Planning_2023a_BlueI_P.shape[3] *
              APF_Path_Planning_2023a_BlueI_P.shape[0] *
              APF_Path_Planning_2023a_BlueI_P.shape[0] *
              APF_Path_Planning_2023a_BlueI_B.q /
              (APF_Path_Planning_2023a_BlueI_P.shape[0] *
               APF_Path_Planning_2023a_BlueI_P.shape[0] *
               (APF_Path_Planning_2023a_BlueI_B.q *
                APF_Path_Planning_2023a_BlueI_B.q) +
               APF_Path_Planning_2023a_BlueI_P.shape[3] *
               APF_Path_Planning_2023a_BlueI_P.shape[3] *
               (APF_Path_Planning_2023a_BlueI_B.alpha_pol *
                APF_Path_Planning_2023a_BlueI_B.alpha_pol));
          } else if ((APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 >=
                      1.5707963267948966) &&
                     (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 <
                      3.1415926535897931)) {
            APF_Path_Planning_2023a_BlueI_B.q = cos
              (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
            APF_Path_Planning_2023a_BlueI_B.alpha_pol = sin
              (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
            APF_Path_Planning_2023a_BlueI_B.alpha_pol = -2.0 *
              APF_Path_Planning_2023a_BlueI_P.shape[4] *
              APF_Path_Planning_2023a_BlueI_P.shape[1] *
              APF_Path_Planning_2023a_BlueI_P.shape[1] *
              APF_Path_Planning_2023a_BlueI_B.q /
              (APF_Path_Planning_2023a_BlueI_P.shape[1] *
               APF_Path_Planning_2023a_BlueI_P.shape[1] *
               (APF_Path_Planning_2023a_BlueI_B.q *
                APF_Path_Planning_2023a_BlueI_B.q) +
               APF_Path_Planning_2023a_BlueI_P.shape[4] *
               APF_Path_Planning_2023a_BlueI_P.shape[4] *
               (APF_Path_Planning_2023a_BlueI_B.alpha_pol *
                APF_Path_Planning_2023a_BlueI_B.alpha_pol));
          } else if ((APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 >=
                      -3.1415926535897931) &&
                     (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 <
                      -1.5707963267948966)) {
            APF_Path_Planning_2023a_BlueI_B.q = cos
              (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
            APF_Path_Planning_2023a_BlueI_B.alpha_pol = sin
              (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
            APF_Path_Planning_2023a_BlueI_B.alpha_pol = 2.0 *
              APF_Path_Planning_2023a_BlueI_P.shape[4] *
              APF_Path_Planning_2023a_BlueI_P.shape[2] / sqrt(4.0 *
              APF_Path_Planning_2023a_BlueI_P.shape[4] *
              APF_Path_Planning_2023a_BlueI_P.shape[4] *
              (APF_Path_Planning_2023a_BlueI_B.alpha_pol *
               APF_Path_Planning_2023a_BlueI_B.alpha_pol) +
              APF_Path_Planning_2023a_BlueI_P.shape[2] *
              APF_Path_Planning_2023a_BlueI_P.shape[2] *
              (APF_Path_Planning_2023a_BlueI_B.q *
               APF_Path_Planning_2023a_BlueI_B.q));
          } else if (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 >=
                     -1.5707963267948966) {
            if (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 < 0.0) {
              APF_Path_Planning_2023a_BlueI_B.q = cos
                (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
              APF_Path_Planning_2023a_BlueI_B.alpha_pol = sin
                (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
              APF_Path_Planning_2023a_BlueI_B.alpha_pol = 2.0 *
                APF_Path_Planning_2023a_BlueI_P.shape[3] *
                APF_Path_Planning_2023a_BlueI_P.shape[2] / sqrt(4.0 *
                APF_Path_Planning_2023a_BlueI_P.shape[4] *
                APF_Path_Planning_2023a_BlueI_P.shape[4] *
                (APF_Path_Planning_2023a_BlueI_B.alpha_pol *
                 APF_Path_Planning_2023a_BlueI_B.alpha_pol) +
                APF_Path_Planning_2023a_BlueI_P.shape[2] *
                APF_Path_Planning_2023a_BlueI_P.shape[2] *
                (APF_Path_Planning_2023a_BlueI_B.q *
                 APF_Path_Planning_2023a_BlueI_B.q));
            } else {
              APF_Path_Planning_2023a_BlueI_B.alpha_pol = 0.0;
            }
          } else {
            APF_Path_Planning_2023a_BlueI_B.alpha_pol = 0.0;
          }

          APF_Path_Planning_2023a_BlueI_B.q =
            APF_Path_Planning_2023a_BlueI_B.alpha_pol * cos
            (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
          APF_Path_Planning_2023a_BlueI_B.alpha_pol *= sin
            (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
          APF_Path_Planning_2023a_BlueI_B.q = APF_Path_Planning_rt_hypotd_snf
            (APF_Path_Planning_2023a_BlueI_B.link1_com_x *
             APF_Path_Planning_2023a_BlueI_B.q + -sin
             (APF_Path_Planning_2023a_BlueI_B.States[2]) *
             APF_Path_Planning_2023a_BlueI_B.alpha_pol,
             APF_Path_Planning_2023a_BlueI_B.link1_com_y *
             APF_Path_Planning_2023a_BlueI_B.q +
             APF_Path_Planning_2023a_BlueI_B.link1_com_x *
             APF_Path_Planning_2023a_BlueI_B.alpha_pol);
          APF_Path_Planning_2023a_BlueI_B.alpha_pol = 3.3121686421112381E-170;
          APF_Path_Planning_2023a_BlueI_B.absxk = fabs
            (APF_Path_Planning_2023a_BlueI_B.path_m[0]);
          if (APF_Path_Planning_2023a_BlueI_B.absxk > 3.3121686421112381E-170) {
            APF_Path_Planning_2023a_BlueI_B.link1_com_y = 1.0;
            APF_Path_Planning_2023a_BlueI_B.alpha_pol =
              APF_Path_Planning_2023a_BlueI_B.absxk;
          } else {
            APF_Path_Planning_2023a_BlueI_B.t =
              APF_Path_Planning_2023a_BlueI_B.absxk / 3.3121686421112381E-170;
            APF_Path_Planning_2023a_BlueI_B.link1_com_y =
              APF_Path_Planning_2023a_BlueI_B.t *
              APF_Path_Planning_2023a_BlueI_B.t;
          }

          APF_Path_Planning_2023a_BlueI_B.absxk = fabs
            (APF_Path_Planning_2023a_BlueI_B.path_m[1]);
          if (APF_Path_Planning_2023a_BlueI_B.absxk >
              APF_Path_Planning_2023a_BlueI_B.alpha_pol) {
            APF_Path_Planning_2023a_BlueI_B.t =
              APF_Path_Planning_2023a_BlueI_B.alpha_pol /
              APF_Path_Planning_2023a_BlueI_B.absxk;
            APF_Path_Planning_2023a_BlueI_B.link1_com_y =
              APF_Path_Planning_2023a_BlueI_B.link1_com_y *
              APF_Path_Planning_2023a_BlueI_B.t *
              APF_Path_Planning_2023a_BlueI_B.t + 1.0;
            APF_Path_Planning_2023a_BlueI_B.alpha_pol =
              APF_Path_Planning_2023a_BlueI_B.absxk;
          } else {
            APF_Path_Planning_2023a_BlueI_B.t =
              APF_Path_Planning_2023a_BlueI_B.absxk /
              APF_Path_Planning_2023a_BlueI_B.alpha_pol;
            APF_Path_Planning_2023a_BlueI_B.link1_com_y +=
              APF_Path_Planning_2023a_BlueI_B.t *
              APF_Path_Planning_2023a_BlueI_B.t;
          }

          APF_Path_Planning_2023a_BlueI_B.absxk = fabs
            (APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp);
          if (APF_Path_Planning_2023a_BlueI_B.absxk >
              APF_Path_Planning_2023a_BlueI_B.alpha_pol) {
            APF_Path_Planning_2023a_BlueI_B.t =
              APF_Path_Planning_2023a_BlueI_B.alpha_pol /
              APF_Path_Planning_2023a_BlueI_B.absxk;
            APF_Path_Planning_2023a_BlueI_B.link1_com_y =
              APF_Path_Planning_2023a_BlueI_B.link1_com_y *
              APF_Path_Planning_2023a_BlueI_B.t *
              APF_Path_Planning_2023a_BlueI_B.t + 1.0;
            APF_Path_Planning_2023a_BlueI_B.alpha_pol =
              APF_Path_Planning_2023a_BlueI_B.absxk;
          } else {
            APF_Path_Planning_2023a_BlueI_B.t =
              APF_Path_Planning_2023a_BlueI_B.absxk /
              APF_Path_Planning_2023a_BlueI_B.alpha_pol;
            APF_Path_Planning_2023a_BlueI_B.link1_com_y +=
              APF_Path_Planning_2023a_BlueI_B.t *
              APF_Path_Planning_2023a_BlueI_B.t;
          }

          APF_Path_Planning_2023a_BlueI_B.link1_com_y =
            APF_Path_Planning_2023a_BlueI_B.alpha_pol * sqrt
            (APF_Path_Planning_2023a_BlueI_B.link1_com_y);
          APF_Path_Planning_2023a_BlueI_B.alpha_pol =
            APF_Path_Planning_2023a_BlueI_B.path_m[0] -
            APF_Path_Planning_2023a_BlueI_B.q *
            APF_Path_Planning_2023a_BlueI_B.path_m[0] /
            APF_Path_Planning_2023a_BlueI_B.link1_com_y;
          APF_Path_Planning_2023a_BlueI_B.path_m[0] =
            APF_Path_Planning_2023a_BlueI_B.alpha_pol;
          APF_Path_Planning_2023a_BlueI_B.t =
            -APF_Path_Planning_2023a_BlueI_B.alpha_pol;
          APF_Path_Planning_2023a_BlueI_B.alpha_pol =
            APF_Path_Planning_2023a_BlueI_B.path_m[1] -
            APF_Path_Planning_2023a_BlueI_B.q *
            APF_Path_Planning_2023a_BlueI_B.path_m[1] /
            APF_Path_Planning_2023a_BlueI_B.link1_com_y;
          APF_Path_Planning_2023a_BlueI_B.path_m[1] =
            APF_Path_Planning_2023a_BlueI_B.alpha_pol;
          APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 =
            -APF_Path_Planning_2023a_BlueI_B.alpha_pol;
          APF_Path_Planning_2023a_BlueI_B.alpha_pol =
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp -
            APF_Path_Planning_2023a_BlueI_B.q *
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp /
            APF_Path_Planning_2023a_BlueI_B.link1_com_y;
          APF_Path_Planning_2023a_BlueI_B.path_m[2] =
            APF_Path_Planning_2023a_BlueI_B.alpha_pol;
          APF_Path_Planning_2023a_BlueI_B.absxk = 0.0;
          APF_Path_Planning_2023a_BlueI_B.t34 =
            -APF_Path_Planning_2023a_BlueI_B.r_co[0];
          APF_Path_Planning_2023a_BlueI_B.t35 =
            -APF_Path_Planning_2023a_BlueI_B.r_co[1];
          APF_Path_Planning_2023a_BlueI_B.q = 0.0;
          APF_Path_Planning_2023a_BlueI_B.IC1[0] =
            (APF_Path_Planning_2023a_BlueI_B.States[0] -
             APF_Path_Planning_2023a_BlueI_P.r_hold * sin
             (APF_Path_Planning_2023a_BlueI_B.States[2])) +
            APF_Path_Planning_2023a_BlueI_P.r_off * cos
            (APF_Path_Planning_2023a_BlueI_B.States[2]);
          APF_Path_Planning_2023a_BlueI_B.IC1[1] =
            (APF_Path_Planning_2023a_BlueI_P.r_off * sin
             (APF_Path_Planning_2023a_BlueI_B.States[2]) +
             APF_Path_Planning_2023a_BlueI_B.States[1]) +
            APF_Path_Planning_2023a_BlueI_P.r_hold * cos
            (APF_Path_Planning_2023a_BlueI_B.States[2]);
          APF_Path_Planning_2023a_BlueI_B.IC1[2] =
            APF_Path_Planning_2023a_BlueI_B.States[2] + 3.1415926535897931;
          APF_Path_Planning_2023a_BlueI_B.IC1[3] =
            APF_Path_Planning_2023a_BlueI_B.Sum6_a;
          APF_Path_Planning_2023a_BlueI_B.IC1[4] =
            APF_Path_Planning_2023a_BlueI_B.Derivative2;
          APF_Path_Planning_2023a_BlueI_B.IC1[5] =
            APF_Path_Planning_2023a_BlueI_B.States[5];
          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 3;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.b_xoffset = 3 *
              APF_Path_Planning_2023a_BlueI_B.i_o + 1;
            APF_Path_Planning_2023a_BlueI_B.xoffset = 3 *
              APF_Path_Planning_2023a_BlueI_B.i_o + 2;
            APF_Path_Planning_2023a_BlueI_B.absxk +=
              ((APF_Path_Planning_2023a_BlueI_P.P_b[3 *
                APF_Path_Planning_2023a_BlueI_B.i_o] *
                APF_Path_Planning_2023a_BlueI_B.t +
                APF_Path_Planning_2023a_BlueI_P.P_b[APF_Path_Planning_2023a_BlueI_B.b_xoffset]
                * APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1) +
               APF_Path_Planning_2023a_BlueI_P.P_b[APF_Path_Planning_2023a_BlueI_B.xoffset]
               * -APF_Path_Planning_2023a_BlueI_B.alpha_pol) *
              APF_Path_Planning_2023a_BlueI_B.path_m[APF_Path_Planning_2023a_BlueI_B.i_o];
            APF_Path_Planning_2023a_BlueI_B.q +=
              ((APF_Path_Planning_2023a_BlueI_P.Nmat[3 *
                APF_Path_Planning_2023a_BlueI_B.i_o] *
                APF_Path_Planning_2023a_BlueI_B.t34 +
                APF_Path_Planning_2023a_BlueI_P.Nmat[APF_Path_Planning_2023a_BlueI_B.b_xoffset]
                * APF_Path_Planning_2023a_BlueI_B.t35) +
               APF_Path_Planning_2023a_BlueI_P.Nmat[APF_Path_Planning_2023a_BlueI_B.xoffset]
               * -APF_Path_Planning_2023a_BlueI_B.Switch) *
              APF_Path_Planning_2023a_BlueI_B.r_co[APF_Path_Planning_2023a_BlueI_B.i_o];
            APF_Path_Planning_2023a_BlueI_B.state_red_d[APF_Path_Planning_2023a_BlueI_B.i_o]
              =
              APF_Path_Planning_2023a_BlueI_B.state_red[APF_Path_Planning_2023a_BlueI_B.i_o]
              - APF_Path_Planning_2023a_BlueI_B.IC1[APF_Path_Planning_2023a_BlueI_B.i_o];
            APF_Path_Planning_2023a_BlueI_B.dv1[APF_Path_Planning_2023a_BlueI_B.i_o]
              =
              (APF_Path_Planning_2023a_BlueI_P.Nmat[APF_Path_Planning_2023a_BlueI_B.i_o
               + 3] * APF_Path_Planning_2023a_BlueI_B.r_co[1] +
               APF_Path_Planning_2023a_BlueI_P.Nmat[APF_Path_Planning_2023a_BlueI_B.i_o]
               * APF_Path_Planning_2023a_BlueI_B.r_co[0]) +
              APF_Path_Planning_2023a_BlueI_P.Nmat[APF_Path_Planning_2023a_BlueI_B.i_o
              + 6] * APF_Path_Planning_2023a_BlueI_B.Switch;
            APF_Path_Planning_2023a_BlueI_B.dv[APF_Path_Planning_2023a_BlueI_B.i_o]
              =
              (APF_Path_Planning_2023a_BlueI_P.P_b[APF_Path_Planning_2023a_BlueI_B.i_o
               + 3] * APF_Path_Planning_2023a_BlueI_B.path_m[1] +
               APF_Path_Planning_2023a_BlueI_P.P_b[APF_Path_Planning_2023a_BlueI_B.i_o]
               * APF_Path_Planning_2023a_BlueI_B.path_m[0]) +
              APF_Path_Planning_2023a_BlueI_P.P_b[APF_Path_Planning_2023a_BlueI_B.i_o
              + 6] * APF_Path_Planning_2023a_BlueI_B.alpha_pol;
          }

          APF_Path_Planning_2023a_BlueI_B.Sum6_a = 2.0 *
            APF_Path_Planning_2023a_BlueI_P.kr * exp
            (APF_Path_Planning_2023a_BlueI_B.absxk);
          APF_Path_Planning_2023a_BlueI_B.Derivative2 = exp
            (APF_Path_Planning_2023a_BlueI_B.q /
             APF_Path_Planning_2023a_BlueI_P.sigma) *
            APF_Path_Planning_2023a_BlueI_B.absx_tmp;

          // SignalConversion generated from: '<S372>/ SFunction ' incorporates:
          //   DataStoreRead: '<S353>/Data Store Read'
          //   DataStoreRead: '<S353>/Data Store Read2'
          //   DataStoreRead: '<S353>/Data Store Read3'
          //   DataStoreRead: '<S353>/Data Store Read4'
          //   DataStoreRead: '<S353>/Data Store Read5'
          //   DataStoreRead: '<S353>/Data Store Read6'
          //   MATLAB Function: '<S364>/MATLAB Function1'

          APF_Path_Planning_2023a_BlueI_B.IC1[0] =
            APF_Path_Planning_2023a_Blue_DW.RED_Px;
          APF_Path_Planning_2023a_BlueI_B.IC1[1] =
            APF_Path_Planning_2023a_Blue_DW.RED_Py;
          APF_Path_Planning_2023a_BlueI_B.IC1[2] =
            APF_Path_Planning_2023a_Blue_DW.RED_Rz;
          APF_Path_Planning_2023a_BlueI_B.IC1[3] =
            APF_Path_Planning_2023a_Blue_DW.RED_Vx;
          APF_Path_Planning_2023a_BlueI_B.IC1[4] =
            APF_Path_Planning_2023a_Blue_DW.RED_Vy;
          APF_Path_Planning_2023a_BlueI_B.IC1[5] =
            APF_Path_Planning_2023a_Blue_DW.RED_RzD;

          // MATLAB Function: '<S369>/MATLAB Function1' incorporates:
          //   Delay: '<S363>/Delay'
          //   Delay: '<S364>/Delay3'
          //   MATLAB Function: '<S363>/MATLAB Function1'

          APF_Path_Planning_2023a_BlueI_B.Switch =
            APF_Path_Planning_2023a_BlueI_B.state_red_d[1];
          APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp =
            APF_Path_Planning_2023a_BlueI_B.state_red_d[0];
          APF_Path_Planning_2023a_BlueI_B.link1_com_y =
            APF_Path_Planning_2023a_BlueI_B.state_red_d[2];
          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 3;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.Sum_n[APF_Path_Planning_2023a_BlueI_B.i_o]
              = -APF_Path_Planning_2023a_BlueI_P.nesterov_gamma *
              APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_o[APF_Path_Planning_2023a_BlueI_B.i_o]
              - ((((APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m
                    [APF_Path_Planning_2023a_BlueI_B.i_o + 3] *
                    APF_Path_Planning_2023a_BlueI_B.Switch +
                    APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m
                    [APF_Path_Planning_2023a_BlueI_B.i_o] *
                    APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp) +
                   APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m
                   [APF_Path_Planning_2023a_BlueI_B.i_o + 6] *
                   APF_Path_Planning_2023a_BlueI_B.link1_com_y) -
                  APF_Path_Planning_2023a_BlueI_B.Sum6_a *
                  APF_Path_Planning_2023a_BlueI_B.dv[APF_Path_Planning_2023a_BlueI_B.i_o])
                 - APF_Path_Planning_2023a_BlueI_B.Derivative2 *
                 APF_Path_Planning_2023a_BlueI_B.dv1[APF_Path_Planning_2023a_BlueI_B.i_o])
              * APF_Path_Planning_2023a_BlueI_P.nesterov_eta;

            // MATLAB Function: '<S364>/MATLAB Function1' incorporates:
            //   Delay: '<S364>/Delay3'
            //   MATLAB Function: '<S363>/MATLAB Function1'

            APF_Path_Planning_2023a_BlueI_B.q =
              APF_Path_Planning_2023a_BlueI_B.Z_k[APF_Path_Planning_2023a_BlueI_B.i_o];
            APF_Path_Planning_2023a_BlueI_B.link1_com_x =
              APF_Path_Planning_2023a_BlueI_B.q *
              APF_Path_Planning_2023a_BlueI_B.q;
            APF_Path_Planning_2023a_BlueI_B.alpha_pol =
              APF_Path_Planning_2023a_BlueI_B.link1_com_x +
              APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE[APF_Path_Planning_2023a_BlueI_B.i_o];
            APF_Path_Planning_2023a_BlueI_B.Gt[APF_Path_Planning_2023a_BlueI_B.i_o]
              = APF_Path_Planning_2023a_BlueI_B.alpha_pol;

            // MATLAB Function: '<S364>/MATLAB Function1' incorporates:
            //   Delay: '<S364>/Delay3'

            APF_Path_Planning_2023a_BlueI_B.path_m[APF_Path_Planning_2023a_BlueI_B.i_o]
              =
              APF_Path_Planning_2023a_BlueI_B.IC1[APF_Path_Planning_2023a_BlueI_B.i_o]
              - APF_Path_Planning_2023a_BlueI_P.adagrad_eta / sqrt
              (APF_Path_Planning_2023a_BlueI_B.alpha_pol +
               APF_Path_Planning_2023a_BlueI_P.adagrad_epsilon) *
              APF_Path_Planning_2023a_BlueI_B.q;

            // MATLAB Function: '<S363>/MATLAB Function1' incorporates:
            //   Delay: '<S363>/Delay'

            APF_Path_Planning_2023a_BlueI_B.alpha_pol = (1.0 -
              APF_Path_Planning_2023a_BlueI_P.adadelta_gamma) *
              APF_Path_Planning_2023a_BlueI_B.link1_com_x +
              APF_Path_Planning_2023a_BlueI_P.adadelta_gamma *
              APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_d[APF_Path_Planning_2023a_BlueI_B.i_o];
            APF_Path_Planning_2023a_BlueI_B.Eg_n[APF_Path_Planning_2023a_BlueI_B.i_o]
              = APF_Path_Planning_2023a_BlueI_B.alpha_pol;

            // MATLAB Function: '<S363>/MATLAB Function1' incorporates:
            //   Delay: '<S363>/Delay'

            APF_Path_Planning_2023a_BlueI_B.link1_com_x =
              APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_n[APF_Path_Planning_2023a_BlueI_B.i_o];
            APF_Path_Planning_2023a_BlueI_B.q *= sqrt
              (APF_Path_Planning_2023a_BlueI_B.link1_com_x +
               APF_Path_Planning_2023a_BlueI_P.adadelta_epsilon) / sqrt
              (APF_Path_Planning_2023a_BlueI_B.alpha_pol +
               APF_Path_Planning_2023a_BlueI_P.adadelta_epsilon);
            APF_Path_Planning_2023a_BlueI_B.r_co[APF_Path_Planning_2023a_BlueI_B.i_o]
              = APF_Path_Planning_2023a_BlueI_B.q;
            APF_Path_Planning_2023a_BlueI_B.Etheta[APF_Path_Planning_2023a_BlueI_B.i_o]
              = (1.0 - APF_Path_Planning_2023a_BlueI_P.adadelta_gamma) *
              (APF_Path_Planning_2023a_BlueI_B.q *
               APF_Path_Planning_2023a_BlueI_B.q) +
              APF_Path_Planning_2023a_BlueI_P.adadelta_gamma *
              APF_Path_Planning_2023a_BlueI_B.link1_com_x;
          }

          // MATLAB Function: '<S366>/MATLAB Function1' incorporates:
          //   Clock: '<S366>/Clock'

          APF_Path_Planning_2023a_BlueI_B.Sum6_a =
            APF_Path_Planning_2023a_Blue_M->Timing.t[0] / 0.1 + 1.0;
          APF_Path_Planning_2023a_BlueI_B.Derivative2 =
            APF_Path_Planning_2_rt_powd_snf
            (APF_Path_Planning_2023a_BlueI_P.adam_beta_2,
             APF_Path_Planning_2023a_BlueI_B.Sum6_a);
          APF_Path_Planning_2023a_BlueI_B.Sum6_a = 1.0 -
            APF_Path_Planning_2_rt_powd_snf
            (APF_Path_Planning_2023a_BlueI_P.adam_beta_1,
             APF_Path_Planning_2023a_BlueI_B.Sum6_a);

          // MATLAB Function: '<S365>/MATLAB Function1' incorporates:
          //   Clock: '<S365>/Clock'
          //   Constant: '<S365>/Constant'
          //   Delay: '<S365>/Delay1'
          //   Sum: '<S365>/Sum'

          APF_Path_Planning_2023a_BlueI_B.link1_com_y = 0.0;
          APF_Path_Planning_2023a_BlueI_B.Switch =
            APF_Path_Planning_2_rt_powd_snf
            (APF_Path_Planning_2023a_BlueI_P.adamax_beta_1,
             (APF_Path_Planning_2023a_Blue_M->Timing.t[0] -
              APF_Path_Planning_2023a_BlueI_P.Phase2_End) / 0.1 + 1.0);
          APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp =
            APF_Path_Planning_2023a_BlueI_P.adamax_beta_2 *
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_l;

          // MATLAB Function: '<S363>/MATLAB Function1' incorporates:
          //   DataStoreRead: '<S353>/Data Store Read'

          APF_Path_Planning_2023a_BlueI_B.r_co[0] =
            APF_Path_Planning_2023a_Blue_DW.RED_Px -
            APF_Path_Planning_2023a_BlueI_B.r_co[0];

          // MATLAB Function: '<S370>/MATLAB Function1' incorporates:
          //   Delay: '<S370>/Delay3'
          //   MATLAB Function: '<S366>/MATLAB Function1'

          APF_Path_Planning_2023a_BlueI_B.t34 =
            APF_Path_Planning_2023a_BlueI_B.Z_k[0] *
            APF_Path_Planning_2023a_BlueI_B.Z_k[0];
          APF_Path_Planning_2023a_BlueI_B.link1_com_x = (1.0 -
            APF_Path_Planning_2023a_BlueI_P.RMSprop_gamma) *
            APF_Path_Planning_2023a_BlueI_B.t34 +
            APF_Path_Planning_2023a_BlueI_P.RMSprop_gamma *
            APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_d[0];
          APF_Path_Planning_2023a_BlueI_B.Eg[0] =
            APF_Path_Planning_2023a_BlueI_B.link1_com_x;

          // MATLAB Function: '<S370>/MATLAB Function1' incorporates:
          //   DataStoreRead: '<S353>/Data Store Read'
          //   Delay: '<S370>/Delay3'

          APF_Path_Planning_2023a_BlueI_B.t35 =
            APF_Path_Planning_2023a_Blue_DW.RED_Px -
            APF_Path_Planning_2023a_BlueI_P.RMSprop_eta / sqrt
            (APF_Path_Planning_2023a_BlueI_B.link1_com_x +
             APF_Path_Planning_2023a_BlueI_P.RMSprop_epsilon) *
            APF_Path_Planning_2023a_BlueI_B.Z_k[0];

          // MATLAB Function: '<S366>/MATLAB Function1' incorporates:
          //   Delay: '<S366>/Delay3'
          //   MATLAB Function: '<S370>/MATLAB Function1'

          APF_Path_Planning_2023a_BlueI_B.q = (1.0 -
            APF_Path_Planning_2023a_BlueI_P.adam_beta_1) *
            APF_Path_Planning_2023a_BlueI_B.Z_k[0] +
            APF_Path_Planning_2023a_BlueI_P.adam_beta_1 *
            APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_a[0];

          // End of Outputs for SubSystem: '<S89>/Sub-Phase #4'
          APF_Path_Planning_2023a_BlueI_B.m[0] =
            APF_Path_Planning_2023a_BlueI_B.q;

          // Outputs for IfAction SubSystem: '<S89>/Sub-Phase #4' incorporates:
          //   ActionPort: '<S247>/Action Port'

          // MATLAB Function: '<S366>/MATLAB Function1' incorporates:
          //   Delay: '<S366>/Delay1'

          APF_Path_Planning_2023a_BlueI_B.t34 = (1.0 -
            APF_Path_Planning_2023a_BlueI_P.adam_beta_2) *
            APF_Path_Planning_2023a_BlueI_B.t34 +
            APF_Path_Planning_2023a_BlueI_P.adam_beta_2 *
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_d[0];
          APF_Path_Planning_2023a_BlueI_B.v[0] =
            APF_Path_Planning_2023a_BlueI_B.t34;

          // MATLAB Function: '<S366>/MATLAB Function1' incorporates:
          //   DataStoreRead: '<S353>/Data Store Read'
          //   Delay: '<S366>/Delay1'

          APF_Path_Planning_2023a_BlueI_B.alpha_pol =
            APF_Path_Planning_2023a_Blue_DW.RED_Px -
            APF_Path_Planning_2023a_BlueI_P.adam_eta / (sqrt
            (APF_Path_Planning_2023a_BlueI_B.t34 / (1.0 -
            APF_Path_Planning_2023a_BlueI_B.Derivative2)) +
            APF_Path_Planning_2023a_BlueI_P.adam_epsilon) *
            (APF_Path_Planning_2023a_BlueI_B.q /
             APF_Path_Planning_2023a_BlueI_B.Sum6_a);

          // MATLAB Function: '<S365>/MATLAB Function1' incorporates:
          //   Delay: '<S365>/Delay3'
          //   MATLAB Function: '<S370>/MATLAB Function1'

          APF_Path_Planning_2023a_BlueI_B.m_b[0] = (1.0 -
            APF_Path_Planning_2023a_BlueI_P.adamax_beta_1) *
            APF_Path_Planning_2023a_BlueI_B.Z_k[0] +
            APF_Path_Planning_2023a_BlueI_P.adamax_beta_1 *
            APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_j[0];
          APF_Path_Planning_2023a_BlueI_B.absxk = fabs
            (APF_Path_Planning_2023a_BlueI_B.Z_k[0]);
          APF_Path_Planning_2023a_BlueI_B.Reject = rtIsNaN
            (APF_Path_Planning_2023a_BlueI_B.absxk);
          if (APF_Path_Planning_2023a_BlueI_B.Reject) {
            APF_Path_Planning_2023a_BlueI_B.link1_com_y = (rtNaN);
          } else if (APF_Path_Planning_2023a_BlueI_B.absxk > 0.0) {
            APF_Path_Planning_2023a_BlueI_B.link1_com_y =
              APF_Path_Planning_2023a_BlueI_B.absxk;
          }

          if ((APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp >=
               APF_Path_Planning_2023a_BlueI_B.absxk) ||
              APF_Path_Planning_2023a_BlueI_B.Reject) {
            APF_Path_Planning_2023a_BlueI_B.absxk =
              APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
          }

          // MATLAB Function: '<S363>/MATLAB Function1' incorporates:
          //   DataStoreRead: '<S353>/Data Store Read2'

          APF_Path_Planning_2023a_BlueI_B.r_co[1] =
            APF_Path_Planning_2023a_Blue_DW.RED_Py -
            APF_Path_Planning_2023a_BlueI_B.r_co[1];

          // MATLAB Function: '<S370>/MATLAB Function1' incorporates:
          //   Delay: '<S370>/Delay3'
          //   MATLAB Function: '<S366>/MATLAB Function1'

          APF_Path_Planning_2023a_BlueI_B.t34 =
            APF_Path_Planning_2023a_BlueI_B.Z_k[1] *
            APF_Path_Planning_2023a_BlueI_B.Z_k[1];
          APF_Path_Planning_2023a_BlueI_B.link1_com_x = (1.0 -
            APF_Path_Planning_2023a_BlueI_P.RMSprop_gamma) *
            APF_Path_Planning_2023a_BlueI_B.t34 +
            APF_Path_Planning_2023a_BlueI_P.RMSprop_gamma *
            APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_d[1];
          APF_Path_Planning_2023a_BlueI_B.Eg[1] =
            APF_Path_Planning_2023a_BlueI_B.link1_com_x;

          // MATLAB Function: '<S370>/MATLAB Function1' incorporates:
          //   DataStoreRead: '<S353>/Data Store Read2'
          //   Delay: '<S370>/Delay3'

          APF_Path_Planning_2023a_BlueI_B.rtb_path_idx_1 =
            APF_Path_Planning_2023a_Blue_DW.RED_Py -
            APF_Path_Planning_2023a_BlueI_P.RMSprop_eta / sqrt
            (APF_Path_Planning_2023a_BlueI_B.link1_com_x +
             APF_Path_Planning_2023a_BlueI_P.RMSprop_epsilon) *
            APF_Path_Planning_2023a_BlueI_B.Z_k[1];

          // MATLAB Function: '<S366>/MATLAB Function1' incorporates:
          //   Delay: '<S366>/Delay3'
          //   MATLAB Function: '<S370>/MATLAB Function1'

          APF_Path_Planning_2023a_BlueI_B.q = (1.0 -
            APF_Path_Planning_2023a_BlueI_P.adam_beta_1) *
            APF_Path_Planning_2023a_BlueI_B.Z_k[1] +
            APF_Path_Planning_2023a_BlueI_P.adam_beta_1 *
            APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_a[1];

          // End of Outputs for SubSystem: '<S89>/Sub-Phase #4'
          APF_Path_Planning_2023a_BlueI_B.m[1] =
            APF_Path_Planning_2023a_BlueI_B.q;

          // Outputs for IfAction SubSystem: '<S89>/Sub-Phase #4' incorporates:
          //   ActionPort: '<S247>/Action Port'

          // MATLAB Function: '<S366>/MATLAB Function1' incorporates:
          //   Delay: '<S366>/Delay1'

          APF_Path_Planning_2023a_BlueI_B.t34 = (1.0 -
            APF_Path_Planning_2023a_BlueI_P.adam_beta_2) *
            APF_Path_Planning_2023a_BlueI_B.t34 +
            APF_Path_Planning_2023a_BlueI_P.adam_beta_2 *
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_d[1];
          APF_Path_Planning_2023a_BlueI_B.v[1] =
            APF_Path_Planning_2023a_BlueI_B.t34;

          // MATLAB Function: '<S366>/MATLAB Function1' incorporates:
          //   DataStoreRead: '<S353>/Data Store Read2'
          //   Delay: '<S366>/Delay1'

          APF_Path_Planning_2023a_BlueI_B.t =
            APF_Path_Planning_2023a_Blue_DW.RED_Py -
            APF_Path_Planning_2023a_BlueI_P.adam_eta / (sqrt
            (APF_Path_Planning_2023a_BlueI_B.t34 / (1.0 -
            APF_Path_Planning_2023a_BlueI_B.Derivative2)) +
            APF_Path_Planning_2023a_BlueI_P.adam_epsilon) *
            (APF_Path_Planning_2023a_BlueI_B.q /
             APF_Path_Planning_2023a_BlueI_B.Sum6_a);

          // MATLAB Function: '<S365>/MATLAB Function1' incorporates:
          //   Delay: '<S365>/Delay3'
          //   MATLAB Function: '<S370>/MATLAB Function1'

          APF_Path_Planning_2023a_BlueI_B.m_b[1] = (1.0 -
            APF_Path_Planning_2023a_BlueI_P.adamax_beta_1) *
            APF_Path_Planning_2023a_BlueI_B.Z_k[1] +
            APF_Path_Planning_2023a_BlueI_P.adamax_beta_1 *
            APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_j[1];
          APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 = fabs
            (APF_Path_Planning_2023a_BlueI_B.Z_k[1]);
          APF_Path_Planning_2023a_BlueI_B.Reject = rtIsNaN
            (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
          if (APF_Path_Planning_2023a_BlueI_B.Reject) {
            APF_Path_Planning_2023a_BlueI_B.link1_com_y = (rtNaN);
          } else if (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 >
                     APF_Path_Planning_2023a_BlueI_B.link1_com_y) {
            APF_Path_Planning_2023a_BlueI_B.link1_com_y =
              APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1;
          }

          if ((APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp >=
               APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1) ||
              APF_Path_Planning_2023a_BlueI_B.Reject) {
            APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 =
              APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
          }

          // MATLAB Function: '<S363>/MATLAB Function1' incorporates:
          //   DataStoreRead: '<S353>/Data Store Read3'

          APF_Path_Planning_2023a_BlueI_B.r_co[2] =
            APF_Path_Planning_2023a_Blue_DW.RED_Rz -
            APF_Path_Planning_2023a_BlueI_B.r_co[2];

          // MATLAB Function: '<S370>/MATLAB Function1' incorporates:
          //   Delay: '<S370>/Delay3'
          //   MATLAB Function: '<S366>/MATLAB Function1'

          APF_Path_Planning_2023a_BlueI_B.t34 =
            APF_Path_Planning_2023a_BlueI_B.Z_k[2] *
            APF_Path_Planning_2023a_BlueI_B.Z_k[2];
          APF_Path_Planning_2023a_BlueI_B.link1_com_x = (1.0 -
            APF_Path_Planning_2023a_BlueI_P.RMSprop_gamma) *
            APF_Path_Planning_2023a_BlueI_B.t34 +
            APF_Path_Planning_2023a_BlueI_P.RMSprop_gamma *
            APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_d[2];
          APF_Path_Planning_2023a_BlueI_B.Eg[2] =
            APF_Path_Planning_2023a_BlueI_B.link1_com_x;

          // MATLAB Function: '<S366>/MATLAB Function1' incorporates:
          //   Delay: '<S366>/Delay3'
          //   Delay: '<S370>/Delay3'
          //   MATLAB Function: '<S370>/MATLAB Function1'

          APF_Path_Planning_2023a_BlueI_B.q = (1.0 -
            APF_Path_Planning_2023a_BlueI_P.adam_beta_1) *
            APF_Path_Planning_2023a_BlueI_B.Z_k[2] +
            APF_Path_Planning_2023a_BlueI_P.adam_beta_1 *
            APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_a[2];

          // End of Outputs for SubSystem: '<S89>/Sub-Phase #4'
          APF_Path_Planning_2023a_BlueI_B.m[2] =
            APF_Path_Planning_2023a_BlueI_B.q;

          // Outputs for IfAction SubSystem: '<S89>/Sub-Phase #4' incorporates:
          //   ActionPort: '<S247>/Action Port'

          // MATLAB Function: '<S366>/MATLAB Function1' incorporates:
          //   Delay: '<S366>/Delay1'

          APF_Path_Planning_2023a_BlueI_B.t34 = (1.0 -
            APF_Path_Planning_2023a_BlueI_P.adam_beta_2) *
            APF_Path_Planning_2023a_BlueI_B.t34 +
            APF_Path_Planning_2023a_BlueI_P.adam_beta_2 *
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_d[2];
          APF_Path_Planning_2023a_BlueI_B.v[2] =
            APF_Path_Planning_2023a_BlueI_B.t34;

          // MATLAB Function: '<S365>/MATLAB Function1' incorporates:
          //   DataStoreRead: '<S353>/Data Store Read'
          //   DataStoreRead: '<S353>/Data Store Read2'
          //   Delay: '<S365>/Delay3'
          //   Delay: '<S366>/Delay1'
          //   MATLAB Function: '<S370>/MATLAB Function1'

          APF_Path_Planning_2023a_BlueI_B.m_b[2] = (1.0 -
            APF_Path_Planning_2023a_BlueI_P.adamax_beta_1) *
            APF_Path_Planning_2023a_BlueI_B.Z_k[2] +
            APF_Path_Planning_2023a_BlueI_P.adamax_beta_1 *
            APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_j[2];
          APF_Path_Planning_2023a_BlueI_B.absx_tmp = fabs
            (APF_Path_Planning_2023a_BlueI_B.Z_k[2]);
          APF_Path_Planning_2023a_BlueI_B.Reject = rtIsNaN
            (APF_Path_Planning_2023a_BlueI_B.absx_tmp);
          if (APF_Path_Planning_2023a_BlueI_B.Reject) {
            APF_Path_Planning_2023a_BlueI_B.link1_com_y = (rtNaN);
          } else if (APF_Path_Planning_2023a_BlueI_B.absx_tmp >
                     APF_Path_Planning_2023a_BlueI_B.link1_com_y) {
            APF_Path_Planning_2023a_BlueI_B.link1_com_y =
              APF_Path_Planning_2023a_BlueI_B.absx_tmp;
          }

          APF_Path_Planning_2023a_BlueI_B.v_d = (1.0 -
            APF_Path_Planning_2023a_BlueI_P.adamax_beta_2) *
            APF_Path_Planning_2023a_BlueI_B.link1_com_y +
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
          APF_Path_Planning_2023a_BlueI_B.absxk =
            APF_Path_Planning_2023a_Blue_DW.RED_Px -
            APF_Path_Planning_2023a_BlueI_B.m_b[0] / (1.0 -
            APF_Path_Planning_2023a_BlueI_B.Switch) *
            (APF_Path_Planning_2023a_BlueI_P.adamax_eta /
             APF_Path_Planning_2023a_BlueI_B.absxk);
          APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 =
            APF_Path_Planning_2023a_Blue_DW.RED_Py -
            APF_Path_Planning_2023a_BlueI_B.m_b[1] / (1.0 -
            APF_Path_Planning_2023a_BlueI_B.Switch) *
            (APF_Path_Planning_2023a_BlueI_P.adamax_eta /
             APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);

          // MultiPortSwitch: '<S362>/Multiport Switch' incorporates:
          //   Constant: '<S362>/Constant3'
          //   DataStoreRead: '<S353>/Data Store Read'
          //   DataStoreRead: '<S353>/Data Store Read2'
          //   DataStoreRead: '<S353>/Data Store Read3'
          //   MATLAB Function: '<S365>/MATLAB Function1'
          //   MATLAB Function: '<S366>/MATLAB Function1'
          //   MATLAB Function: '<S367>/Batch'
          //   MATLAB Function: '<S368>/Momentum'
          //   MATLAB Function: '<S369>/MATLAB Function1'
          //   MATLAB Function: '<S370>/MATLAB Function1'

          switch (static_cast<int32_T>(APF_Path_Planning_2023a_BlueI_P.Method))
      {
           case 1:
            APF_Path_Planning_2023a_BlueI_B.path_m[0] =
              APF_Path_Planning_2023a_Blue_DW.RED_Px -
              APF_Path_Planning_2023a_BlueI_P.batch_eta *
              APF_Path_Planning_2023a_BlueI_B.Z_k[0];
            APF_Path_Planning_2023a_BlueI_B.path_m[1] =
              APF_Path_Planning_2023a_Blue_DW.RED_Py -
              APF_Path_Planning_2023a_BlueI_P.batch_eta *
              APF_Path_Planning_2023a_BlueI_B.Z_k[1];
            APF_Path_Planning_2023a_BlueI_B.path_m[2] =
              APF_Path_Planning_2023a_Blue_DW.RED_Rz -
              APF_Path_Planning_2023a_BlueI_P.batch_eta *
              APF_Path_Planning_2023a_BlueI_B.Z_k[2];
            break;

           case 2:
            APF_Path_Planning_2023a_BlueI_B.path_m[0] =
              APF_Path_Planning_2023a_Blue_DW.RED_Px +
              APF_Path_Planning_2023a_BlueI_B.Sum3[0];
            APF_Path_Planning_2023a_BlueI_B.path_m[1] =
              APF_Path_Planning_2023a_Blue_DW.RED_Py +
              APF_Path_Planning_2023a_BlueI_B.Sum3[1];
            APF_Path_Planning_2023a_BlueI_B.path_m[2] =
              APF_Path_Planning_2023a_Blue_DW.RED_Rz +
              APF_Path_Planning_2023a_BlueI_B.Sum3[2];
            break;

           case 3:
            APF_Path_Planning_2023a_BlueI_B.path_m[0] =
              APF_Path_Planning_2023a_Blue_DW.RED_Px +
              APF_Path_Planning_2023a_BlueI_B.Sum_n[0];
            APF_Path_Planning_2023a_BlueI_B.path_m[1] =
              APF_Path_Planning_2023a_Blue_DW.RED_Py +
              APF_Path_Planning_2023a_BlueI_B.Sum_n[1];
            APF_Path_Planning_2023a_BlueI_B.path_m[2] =
              APF_Path_Planning_2023a_Blue_DW.RED_Rz +
              APF_Path_Planning_2023a_BlueI_B.Sum_n[2];
            break;

           case 4:
            break;

           case 5:
            APF_Path_Planning_2023a_BlueI_B.path_m[0] =
              APF_Path_Planning_2023a_BlueI_B.r_co[0];
            APF_Path_Planning_2023a_BlueI_B.path_m[1] =
              APF_Path_Planning_2023a_BlueI_B.r_co[1];
            APF_Path_Planning_2023a_BlueI_B.path_m[2] =
              APF_Path_Planning_2023a_BlueI_B.r_co[2];
            break;

           case 6:
            APF_Path_Planning_2023a_BlueI_B.path_m[0] =
              APF_Path_Planning_2023a_BlueI_B.t35;
            APF_Path_Planning_2023a_BlueI_B.path_m[1] =
              APF_Path_Planning_2023a_BlueI_B.rtb_path_idx_1;
            APF_Path_Planning_2023a_BlueI_B.path_m[2] =
              APF_Path_Planning_2023a_Blue_DW.RED_Rz -
              APF_Path_Planning_2023a_BlueI_P.RMSprop_eta / sqrt
              (APF_Path_Planning_2023a_BlueI_B.link1_com_x +
               APF_Path_Planning_2023a_BlueI_P.RMSprop_epsilon) *
              APF_Path_Planning_2023a_BlueI_B.Z_k[2];
            break;

           case 7:
            APF_Path_Planning_2023a_BlueI_B.path_m[0] =
              APF_Path_Planning_2023a_BlueI_B.alpha_pol;
            APF_Path_Planning_2023a_BlueI_B.path_m[1] =
              APF_Path_Planning_2023a_BlueI_B.t;
            APF_Path_Planning_2023a_BlueI_B.path_m[2] =
              APF_Path_Planning_2023a_Blue_DW.RED_Rz -
              APF_Path_Planning_2023a_BlueI_P.adam_eta / (sqrt
              (APF_Path_Planning_2023a_BlueI_B.t34 / (1.0 -
              APF_Path_Planning_2023a_BlueI_B.Derivative2)) +
              APF_Path_Planning_2023a_BlueI_P.adam_epsilon) *
              (APF_Path_Planning_2023a_BlueI_B.q /
               APF_Path_Planning_2023a_BlueI_B.Sum6_a);
            break;

           default:
            APF_Path_Planning_2023a_BlueI_B.path_m[0] =
              APF_Path_Planning_2023a_BlueI_B.absxk;
            APF_Path_Planning_2023a_BlueI_B.path_m[1] =
              APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1;

            // MATLAB Function: '<S365>/MATLAB Function1' incorporates:
            //   MultiPortSwitch: '<S362>/Multiport Switch'

            if ((APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp >=
                 APF_Path_Planning_2023a_BlueI_B.absx_tmp) ||
                APF_Path_Planning_2023a_BlueI_B.Reject) {
              APF_Path_Planning_2023a_BlueI_B.absx_tmp =
                APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
            }

            APF_Path_Planning_2023a_BlueI_B.path_m[2] =
              APF_Path_Planning_2023a_Blue_DW.RED_Rz -
              APF_Path_Planning_2023a_BlueI_B.m_b[2] / (1.0 -
              APF_Path_Planning_2023a_BlueI_B.Switch) *
              (APF_Path_Planning_2023a_BlueI_P.adamax_eta /
               APF_Path_Planning_2023a_BlueI_B.absx_tmp);
            break;
          }

          // End of MultiPortSwitch: '<S362>/Multiport Switch'

          // Sum: '<S247>/Sum' incorporates:
          //   DataStoreRead: '<S353>/Data Store Read'

          APF_Path_Planning_2023a_BlueI_B.Sum =
            APF_Path_Planning_2023a_BlueI_B.path_m[0] -
            APF_Path_Planning_2023a_Blue_DW.RED_Px;

          // Derivative: '<S349>/Derivative2'
          if ((APF_Path_Planning_2023a_Blue_DW.TimeStampA >=
               APF_Path_Planning_2023a_Blue_M->Timing.t[0]) &&
              (APF_Path_Planning_2023a_Blue_DW.TimeStampB >=
               APF_Path_Planning_2023a_Blue_M->Timing.t[0])) {
            APF_Path_Planning_2023a_BlueI_B.Derivative2 = 0.0;
          } else {
            APF_Path_Planning_2023a_BlueI_B.Switch =
              APF_Path_Planning_2023a_Blue_DW.TimeStampA;
            lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeA;
            if (APF_Path_Planning_2023a_Blue_DW.TimeStampA <
                APF_Path_Planning_2023a_Blue_DW.TimeStampB) {
              if (APF_Path_Planning_2023a_Blue_DW.TimeStampB <
                  APF_Path_Planning_2023a_Blue_M->Timing.t[0]) {
                APF_Path_Planning_2023a_BlueI_B.Switch =
                  APF_Path_Planning_2023a_Blue_DW.TimeStampB;
                lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeB;
              }
            } else if (APF_Path_Planning_2023a_Blue_DW.TimeStampA >=
                       APF_Path_Planning_2023a_Blue_M->Timing.t[0]) {
              APF_Path_Planning_2023a_BlueI_B.Switch =
                APF_Path_Planning_2023a_Blue_DW.TimeStampB;
              lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeB;
            }

            APF_Path_Planning_2023a_BlueI_B.Derivative2 =
              (APF_Path_Planning_2023a_BlueI_B.Sum - *lastU) /
              (APF_Path_Planning_2023a_Blue_M->Timing.t[0] -
               APF_Path_Planning_2023a_BlueI_B.Switch);
          }

          // End of Derivative: '<S349>/Derivative2'

          // Sum: '<S349>/u_x' incorporates:
          //   DataStoreWrite: '<S247>/RED_Fx'
          //   DiscreteIntegrator: '<S349>/Discrete-Time Integrator4'
          //   DiscreteIntegrator: '<S349>/Discrete-Time Integrator5'
          //   Product: '<S349>/k_1*q_1_x'
          //   Product: '<S349>/k_2*q2_x'

          APF_Path_Planning_2023a_Blue_DW.RED_Fx =
            APF_Path_Planning_2023a_BlueI_B.Derivative2 *
            APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator4_DSTATE +
            APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator5_DSTATE *
            APF_Path_Planning_2023a_BlueI_B.Sum;

          // Sum: '<S247>/Sum1' incorporates:
          //   DataStoreRead: '<S353>/Data Store Read2'

          APF_Path_Planning_2023a_BlueI_B.Sum1 =
            APF_Path_Planning_2023a_BlueI_B.path_m[1] -
            APF_Path_Planning_2023a_Blue_DW.RED_Py;

          // Derivative: '<S349>/Derivative1'
          if ((APF_Path_Planning_2023a_Blue_DW.TimeStampA_n >=
               APF_Path_Planning_2023a_Blue_M->Timing.t[0]) &&
              (APF_Path_Planning_2023a_Blue_DW.TimeStampB_h >=
               APF_Path_Planning_2023a_Blue_M->Timing.t[0])) {
            APF_Path_Planning_2023a_BlueI_B.Sum6_a = 0.0;
          } else {
            APF_Path_Planning_2023a_BlueI_B.Switch =
              APF_Path_Planning_2023a_Blue_DW.TimeStampA_n;
            lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeA_d;
            if (APF_Path_Planning_2023a_Blue_DW.TimeStampA_n <
                APF_Path_Planning_2023a_Blue_DW.TimeStampB_h) {
              if (APF_Path_Planning_2023a_Blue_DW.TimeStampB_h <
                  APF_Path_Planning_2023a_Blue_M->Timing.t[0]) {
                APF_Path_Planning_2023a_BlueI_B.Switch =
                  APF_Path_Planning_2023a_Blue_DW.TimeStampB_h;
                lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeB_l;
              }
            } else if (APF_Path_Planning_2023a_Blue_DW.TimeStampA_n >=
                       APF_Path_Planning_2023a_Blue_M->Timing.t[0]) {
              APF_Path_Planning_2023a_BlueI_B.Switch =
                APF_Path_Planning_2023a_Blue_DW.TimeStampB_h;
              lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeB_l;
            }

            APF_Path_Planning_2023a_BlueI_B.Sum6_a =
              (APF_Path_Planning_2023a_BlueI_B.Sum1 - *lastU) /
              (APF_Path_Planning_2023a_Blue_M->Timing.t[0] -
               APF_Path_Planning_2023a_BlueI_B.Switch);
          }

          // End of Derivative: '<S349>/Derivative1'

          // Sum: '<S349>/u_y' incorporates:
          //   DataStoreWrite: '<S247>/RED_Fy'
          //   DiscreteIntegrator: '<S349>/Discrete-Time Integrator2'
          //   DiscreteIntegrator: '<S349>/Discrete-Time Integrator3'
          //   Product: '<S349>/k_1*q_1_y'
          //   Product: '<S349>/k_2*q2_y'

          APF_Path_Planning_2023a_Blue_DW.RED_Fy =
            APF_Path_Planning_2023a_BlueI_B.Sum6_a *
            APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator2_DSTATE +
            APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator3_DSTATE *
            APF_Path_Planning_2023a_BlueI_B.Sum1;

          // Switch: '<S247>/Switch' incorporates:
          //   Constant: '<S247>/Constant2'
          //   DataStoreRead: '<S353>/Data Store Read'
          //   DataStoreRead: '<S353>/Data Store Read2'
          //   MATLAB Function: '<S247>/Looking Angle'

          if (APF_Path_Planning_2023a_BlueI_P.Att_Mode >
              APF_Path_Planning_2023a_BlueI_P.Switch_Threshold_d) {
            APF_Path_Planning_2023a_BlueI_B.Switch =
              APF_Path_Planning_2023a_BlueI_B.path_m[2];
          } else {
            APF_Path_Planning_2023a_BlueI_B.Switch =
              APF_Path_Planning_rt_atan2d_snf
              (APF_Path_Planning_2023a_Blue_DW.RED_Py -
               (APF_Path_Planning_2023a_BlueI_P.r_off * sin
                (APF_Path_Planning_2023a_BlueI_B.States[2]) +
                APF_Path_Planning_2023a_BlueI_B.States[1]),
               APF_Path_Planning_2023a_Blue_DW.RED_Px -
               (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
                APF_Path_Planning_2023a_BlueI_B.States[0])) + 3.1415926535897931;
          }

          // End of Switch: '<S247>/Switch'

          // MATLAB Function: '<S351>/MATLAB Function2'
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = sin
            (APF_Path_Planning_2023a_BlueI_B.Switch);
          APF_Path_Planning_2023a_BlueI_B.Switch = cos
            (APF_Path_Planning_2023a_BlueI_B.Switch);
          APF_Path_Planning_2023a_BlueI_B.rtb_Oy_f_l[0] =
            APF_Path_Planning_2023a_BlueI_B.Switch * 0.0 +
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
          APF_Path_Planning_2023a_BlueI_B.rtb_Oy_f_l[1] =
            -APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW * 0.0 +
            APF_Path_Planning_2023a_BlueI_B.Switch;

          // MATLAB Function: '<S351>/MATLAB Function3' incorporates:
          //   DataStoreRead: '<S353>/Data Store Read3'
          //   MATLAB Function: '<S351>/MATLAB Function2'

          APF_Path_Planni_MATLABFunction3(APF_Path_Planning_2023a_Blue_DW.RED_Rz,
            APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b);

          // Sum: '<S351>/Subtract2' incorporates:
          //   MATLAB Function: '<S351>/MATLAB Function2'

          APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o[0] =
            (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW * 0.0 +
             APF_Path_Planning_2023a_BlueI_B.Switch) -
            APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b[0];
          APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o[1] =
            (APF_Path_Planning_2023a_BlueI_B.Switch * 0.0 -
             APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW) -
            APF_Path_Planning_2023a_BlueI_B.rtb_Ox_p_b[1];

          // MATLAB Function: '<S351>/MATLAB Function4'
          APF_Path_Planni_MATLABFunction4
            (APF_Path_Planning_2023a_BlueI_B.rtb_Oy_f_l,
             APF_Path_Planning_2023a_BlueI_B.rtb_Ox_g4_o,
             &APF_Path_Planning_2023a_BlueI_B.e_out);

          // Derivative: '<S349>/Derivative3'
          if ((APF_Path_Planning_2023a_Blue_DW.TimeStampA_m >=
               APF_Path_Planning_2023a_Blue_M->Timing.t[0]) &&
              (APF_Path_Planning_2023a_Blue_DW.TimeStampB_a >=
               APF_Path_Planning_2023a_Blue_M->Timing.t[0])) {
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 0.0;
          } else {
            APF_Path_Planning_2023a_BlueI_B.Switch =
              APF_Path_Planning_2023a_Blue_DW.TimeStampA_m;
            lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeA_m;
            if (APF_Path_Planning_2023a_Blue_DW.TimeStampA_m <
                APF_Path_Planning_2023a_Blue_DW.TimeStampB_a) {
              if (APF_Path_Planning_2023a_Blue_DW.TimeStampB_a <
                  APF_Path_Planning_2023a_Blue_M->Timing.t[0]) {
                APF_Path_Planning_2023a_BlueI_B.Switch =
                  APF_Path_Planning_2023a_Blue_DW.TimeStampB_a;
                lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeB_k;
              }
            } else if (APF_Path_Planning_2023a_Blue_DW.TimeStampA_m >=
                       APF_Path_Planning_2023a_Blue_M->Timing.t[0]) {
              APF_Path_Planning_2023a_BlueI_B.Switch =
                APF_Path_Planning_2023a_Blue_DW.TimeStampB_a;
              lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeB_k;
            }

            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
              (APF_Path_Planning_2023a_BlueI_B.e_out - *lastU) /
              (APF_Path_Planning_2023a_Blue_M->Timing.t[0] -
               APF_Path_Planning_2023a_BlueI_B.Switch);
          }

          // End of Derivative: '<S349>/Derivative3'

          // Sum: '<S349>/Add2' incorporates:
          //   DataStoreWrite: '<S247>/RED_Tz'
          //   DiscreteIntegrator: '<S349>/Discrete-Time Integrator'
          //   DiscreteIntegrator: '<S349>/Discrete-Time Integrator1'
          //   Product: '<S349>/Product4'
          //   Product: '<S349>/Product5'

          APF_Path_Planning_2023a_Blue_DW.RED_Tz =
            APF_Path_Planning_2023a_BlueI_B.e_out *
            APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator1_DSTATE +
            APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator_DSTATE *
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // DataStoreWrite: '<S347>/Data Store Write'
          APF_Path_Planning_2023a_Blue_DW.BLACK_Px_Est =
            APF_Path_Planning_2023a_BlueI_B.States[0];

          // DataStoreWrite: '<S347>/Data Store Write1'
          APF_Path_Planning_2023a_Blue_DW.BLACK_Py_Est =
            APF_Path_Planning_2023a_BlueI_B.States[1];

          // DataStoreWrite: '<S347>/Data Store Write2'
          APF_Path_Planning_2023a_Blue_DW.BLACK_Rz_Est =
            APF_Path_Planning_2023a_BlueI_B.States[2];

          // DataStoreWrite: '<S347>/Data Store Write3'
          APF_Path_Planning_2023a_Blue_DW.BLACK_Px_preKalm =
            APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtSFunct[0];

          // DataStoreWrite: '<S347>/Data Store Write4'
          APF_Path_Planning_2023a_Blue_DW.BLACK_Py_preKalm =
            APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtSFunct[1];

          // DataStoreWrite: '<S347>/Data Store Write5'
          APF_Path_Planning_2023a_Blue_DW.BLACK_Rz_preKalm =
            APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtSFunct[2];

          // DataStoreWrite: '<S349>/Data Store Write' incorporates:
          //   DiscreteIntegrator: '<S349>/Discrete-Time Integrator5'

          APF_Path_Planning_2023a_Blue_DW.DAC_Posx_k_1 =
            APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator5_DSTATE;

          // DataStoreWrite: '<S349>/Data Store Write1' incorporates:
          //   DiscreteIntegrator: '<S349>/Discrete-Time Integrator4'

          APF_Path_Planning_2023a_Blue_DW.DAC_Posx_k_2 =
            APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator4_DSTATE;

          // DataStoreWrite: '<S349>/Data Store Write2' incorporates:
          //   DiscreteIntegrator: '<S349>/Discrete-Time Integrator3'

          APF_Path_Planning_2023a_Blue_DW.DAC_Posy_k_1 =
            APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator3_DSTATE;

          // DataStoreWrite: '<S349>/Data Store Write3' incorporates:
          //   DiscreteIntegrator: '<S349>/Discrete-Time Integrator2'

          APF_Path_Planning_2023a_Blue_DW.DAC_Posy_k_2 =
            APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator2_DSTATE;

          // DataStoreWrite: '<S349>/Data Store Write4' incorporates:
          //   DiscreteIntegrator: '<S349>/Discrete-Time Integrator'

          APF_Path_Planning_2023a_Blue_DW.DAC_Attitude_k_1 =
            APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator_DSTATE;

          // DataStoreWrite: '<S349>/Data Store Write5' incorporates:
          //   DiscreteIntegrator: '<S349>/Discrete-Time Integrator1'

          APF_Path_Planning_2023a_Blue_DW.DAC_Attitude_k_2 =
            APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator1_DSTATE;

          // MATLAB Function: '<S349>/Fx Gain Derivatives' incorporates:
          //   MATLAB Function: '<S349>/Fy Gain Derivatives'

          APF_Path_Planning_2023a_BlueI_B.q =
            APF_Path_Planning_2023a_BlueI_B.Derivative2 *
            APF_Path_Planning_2023a_BlueI_B.Derivative2;
          APF_Path_Planning_2023a_BlueI_B.alpha_pol =
            APF_Path_Planning_2023a_BlueI_B.Sum *
            APF_Path_Planning_2023a_BlueI_B.Sum;
          APF_Path_Planning_2023a_BlueI_B.link1_com_y =
            -APF_Path_Planning_2023a_BlueI_P.lambda1 *
            APF_Path_Planning_2023a_BlueI_P.p;
          APF_Path_Planning_2023a_BlueI_B.link1_com_x =
            APF_Path_Planning_2023a_BlueI_P.p *
            APF_Path_Planning_2023a_BlueI_P.lambda12 +
            APF_Path_Planning_2023a_BlueI_P.lambda1;
          APF_Path_Planning_2023a_BlueI_B.k1_dot_e =
            (APF_Path_Planning_2023a_BlueI_B.link1_com_y *
             APF_Path_Planning_2023a_BlueI_B.alpha_pol -
             APF_Path_Planning_2023a_BlueI_B.link1_com_x *
             APF_Path_Planning_2023a_BlueI_B.Sum *
             APF_Path_Planning_2023a_BlueI_B.Derivative2) -
            APF_Path_Planning_2023a_BlueI_B.q *
            APF_Path_Planning_2023a_BlueI_P.lambda12;
          APF_Path_Planning_2023a_BlueI_B.Switch =
            -APF_Path_Planning_2023a_BlueI_P.lambda12 *
            APF_Path_Planning_2023a_BlueI_P.p;
          APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp =
            APF_Path_Planning_2023a_BlueI_P.p *
            APF_Path_Planning_2023a_BlueI_P.lambda2 +
            APF_Path_Planning_2023a_BlueI_P.lambda12;
          APF_Path_Planning_2023a_BlueI_B.k2_dot_d =
            (APF_Path_Planning_2023a_BlueI_B.Switch *
             APF_Path_Planning_2023a_BlueI_B.alpha_pol -
             APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp *
             APF_Path_Planning_2023a_BlueI_B.Sum *
             APF_Path_Planning_2023a_BlueI_B.Derivative2) -
            APF_Path_Planning_2023a_BlueI_B.q *
            APF_Path_Planning_2023a_BlueI_P.lambda2;

          // MATLAB Function: '<S349>/Fy Gain Derivatives'
          APF_Path_Planning_2023a_BlueI_B.Derivative2 =
            APF_Path_Planning_2023a_BlueI_B.Sum6_a *
            APF_Path_Planning_2023a_BlueI_B.Sum6_a;
          APF_Path_Planning_2023a_BlueI_B.q =
            APF_Path_Planning_2023a_BlueI_B.Sum1 *
            APF_Path_Planning_2023a_BlueI_B.Sum1;
          APF_Path_Planning_2023a_BlueI_B.k1_dot_j =
            (APF_Path_Planning_2023a_BlueI_B.link1_com_y *
             APF_Path_Planning_2023a_BlueI_B.q -
             APF_Path_Planning_2023a_BlueI_B.link1_com_x *
             APF_Path_Planning_2023a_BlueI_B.Sum1 *
             APF_Path_Planning_2023a_BlueI_B.Sum6_a) -
            APF_Path_Planning_2023a_BlueI_B.Derivative2 *
            APF_Path_Planning_2023a_BlueI_P.lambda12;
          APF_Path_Planning_2023a_BlueI_B.k2_dot_a =
            (APF_Path_Planning_2023a_BlueI_B.Switch *
             APF_Path_Planning_2023a_BlueI_B.q -
             APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp *
             APF_Path_Planning_2023a_BlueI_B.Sum1 *
             APF_Path_Planning_2023a_BlueI_B.Sum6_a) -
            APF_Path_Planning_2023a_BlueI_B.Derivative2 *
            APF_Path_Planning_2023a_BlueI_P.lambda2;

          // MATLAB Function: '<S349>/Torque Gain Derivatives'
          APF_Path_Planning_2023a_BlueI_B.Sum6_a =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW *
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
          APF_Path_Planning_2023a_BlueI_B.Derivative2 =
            APF_Path_Planning_2023a_BlueI_B.e_out *
            APF_Path_Planning_2023a_BlueI_B.e_out;
          APF_Path_Planning_2023a_BlueI_B.k1_dot =
            (-APF_Path_Planning_2023a_BlueI_P.lambda1_t *
             APF_Path_Planning_2023a_BlueI_P.p_t *
             APF_Path_Planning_2023a_BlueI_B.Derivative2 -
             (APF_Path_Planning_2023a_BlueI_P.p_t *
              APF_Path_Planning_2023a_BlueI_P.lambda12_t +
              APF_Path_Planning_2023a_BlueI_P.lambda1_t) *
             APF_Path_Planning_2023a_BlueI_B.e_out *
             APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW) -
            APF_Path_Planning_2023a_BlueI_B.Sum6_a *
            APF_Path_Planning_2023a_BlueI_P.lambda12_t;
          APF_Path_Planning_2023a_BlueI_B.k2_dot =
            (-APF_Path_Planning_2023a_BlueI_P.lambda12_t *
             APF_Path_Planning_2023a_BlueI_P.p_t *
             APF_Path_Planning_2023a_BlueI_B.Derivative2 -
             (APF_Path_Planning_2023a_BlueI_P.p_t *
              APF_Path_Planning_2023a_BlueI_P.lambda2_t +
              APF_Path_Planning_2023a_BlueI_P.lambda12_t) *
             APF_Path_Planning_2023a_BlueI_B.e_out *
             APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW) -
            APF_Path_Planning_2023a_BlueI_B.Sum6_a *
            APF_Path_Planning_2023a_BlueI_P.lambda2_t;

          // DataStoreWrite: '<S350>/Data Store Write'
          APF_Path_Planning_2023a_Blue_DW.Command_Px =
            APF_Path_Planning_2023a_BlueI_B.path_m[0];

          // DataStoreWrite: '<S350>/Data Store Write1'
          APF_Path_Planning_2023a_Blue_DW.Command_Py =
            APF_Path_Planning_2023a_BlueI_B.path_m[1];

          // DataStoreWrite: '<S350>/Data Store Write2'
          APF_Path_Planning_2023a_Blue_DW.Command_Rz =
            APF_Path_Planning_2023a_BlueI_B.path_m[2];

          // Sum: '<S368>/Sum3' incorporates:
          //   Constant: '<S368>/Constant'

          APF_Path_Planning_2023a_BlueI_B.Sum3[0] +=
            APF_Path_Planning_2023a_BlueI_P.Constant_Value_j[0];

          // Sum: '<S369>/Sum' incorporates:
          //   Constant: '<S369>/Constant1'

          APF_Path_Planning_2023a_BlueI_B.Sum_n[0] +=
            APF_Path_Planning_2023a_BlueI_P.Constant1_Value[0];

          // Sum: '<S368>/Sum3' incorporates:
          //   Constant: '<S368>/Constant'

          APF_Path_Planning_2023a_BlueI_B.Sum3[1] +=
            APF_Path_Planning_2023a_BlueI_P.Constant_Value_j[1];

          // Sum: '<S369>/Sum' incorporates:
          //   Constant: '<S369>/Constant1'

          APF_Path_Planning_2023a_BlueI_B.Sum_n[1] +=
            APF_Path_Planning_2023a_BlueI_P.Constant1_Value[1];

          // Sum: '<S368>/Sum3' incorporates:
          //   Constant: '<S368>/Constant'

          APF_Path_Planning_2023a_BlueI_B.Sum3[2] +=
            APF_Path_Planning_2023a_BlueI_P.Constant_Value_j[2];

          // Sum: '<S369>/Sum' incorporates:
          //   Constant: '<S369>/Constant1'

          APF_Path_Planning_2023a_BlueI_B.Sum_n[2] +=
            APF_Path_Planning_2023a_BlueI_P.Constant1_Value[2];

          // DataStoreWrite: '<S247>/Data Store Write3' incorporates:
          //   Constant: '<S247>/Puck State'

          APF_Path_Planning_2023a_Blue_DW.Float_State =
            APF_Path_Planning_2023a_BlueI_P.PuckState_Value_a;

          // If: '<S247>/If' incorporates:
          //   Constant: '<S247>/Constant3'

          if ((APF_Path_Planning_2023a_BlueI_P.platformSelection == 4.0) ||
              (APF_Path_Planning_2023a_BlueI_P.platformSelection == 5.0) ||
              (APF_Path_Planning_2023a_BlueI_P.platformSelection == 10.0) ||
              (APF_Path_Planning_2023a_BlueI_P.platformSelection == 11.0)) {
            // Outputs for IfAction SubSystem: '<S247>/RED+ARM' incorporates:
            //   ActionPort: '<S354>/Action Port'

            // If: '<S354>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 
            if (APF_Path_Planning_2023a_BlueI_P.simMode == 1.0) {
              // Outputs for IfAction SubSystem: '<S354>/Simulated Position Controller' incorporates:
              //   ActionPort: '<S383>/Action Port'

              // DataStoreWrite: '<S354>/Data Store Write2' incorporates:
              //   Constant: '<S354>/Constant4'
              //   Constant: '<S354>/Constant5'
              //   Constant: '<S354>/Constant6'
              //   DataStoreWrite: '<S354>/Data Store Write'
              //   DataStoreWrite: '<S354>/Data Store Write1'

              APF_SimulatedPositionController
                (APF_Path_Planning_2023a_BlueI_P.Constant4_Value_k,
                 APF_Path_Planning_2023a_BlueI_P.Constant5_Value,
                 APF_Path_Planning_2023a_BlueI_P.Constant6_Value,
                 &APF_Path_Planning_2023a_Blue_DW.RED_Shoulder_Command,
                 &APF_Path_Planning_2023a_Blue_DW.RED_Elbow_Command,
                 &APF_Path_Planning_2023a_Blue_DW.RED_Wrist_Command,
                 &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Elbow,
                 &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder,
                 &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Wrist,
                 &APF_Path_Planning_2023a_BlueI_B.SimulatedPositionController,
                 &APF_Path_Planning_2023a_Blue_DW.SimulatedPositionController);

              // End of Outputs for SubSystem: '<S354>/Simulated Position Controller' 
            } else {
              // Outputs for IfAction SubSystem: '<S354>/Passthrough for Experiment' incorporates:
              //   ActionPort: '<S382>/Action Port'

              // DataStoreWrite: '<S354>/Data Store Write2' incorporates:
              //   Constant: '<S354>/Constant6'
              //   DataStoreWrite: '<S354>/Data Store Write'
              //   DataStoreWrite: '<S354>/Data Store Write1'

              APF_Pa_PassthroughforExperiment(0.0, 0.0,
                APF_Path_Planning_2023a_BlueI_P.Constant6_Value,
                &APF_Path_Planning_2023a_Blue_DW.RED_Shoulder_Command,
                &APF_Path_Planning_2023a_Blue_DW.RED_Elbow_Command,
                &APF_Path_Planning_2023a_Blue_DW.RED_Wrist_Command);

              // End of Outputs for SubSystem: '<S354>/Passthrough for Experiment' 
            }

            // End of If: '<S354>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 

            // DataStoreWrite: '<S354>/Data Store Write3' incorporates:
            //   Constant: '<S354>/Constant7'

            APF_Path_Planning_2023a_Blue_DW.RED_ARM_Control_Mode =
              APF_Path_Planning_2023a_BlueI_P.Constant7_Value;

            // End of Outputs for SubSystem: '<S247>/RED+ARM'
          }

          // End of If: '<S247>/If'
          // End of Outputs for SubSystem: '<S89>/Sub-Phase #4'
        }

        // End of If: '<S89>/Experiment Sub-Phases'
        // End of Outputs for SubSystem: '<S9>/Change RED Behavior'
      }

      // End of If: '<S9>/This IF block determines whether or not to run the RED sim//exp ' 
      // End of Outputs for SubSystem: '<Root>/Phase #3: Experiment'
    } else if ((APF_Path_Planning_2023a_Blue_DW.Univ_Time <
                APF_Path_Planning_2023a_BlueI_P.Phase4_End) &&
               (APF_Path_Planning_2023a_Blue_DW.Univ_Time >=
                APF_Path_Planning_2023a_BlueI_P.Phase3_End)) {
      APF_Path_Planning_2023a_Blue_DW.SeparatePhases_ActiveSubsystem = 4;

      // Outputs for IfAction SubSystem: '<Root>/Phase #4: Return Home' incorporates:
      //   ActionPort: '<S10>/Action Port'

      APF_Path_Plann_Phase4ReturnHome(&APF_Path_Planning_2023a_Blue_DW.BLACK_Fx,
        &APF_Path_Planning_2023a_Blue_DW.BLACK_Fy,
        &APF_Path_Planning_2023a_Blue_DW.BLACK_Px,
        &APF_Path_Planning_2023a_Blue_DW.BLACK_Py,
        &APF_Path_Planning_2023a_Blue_DW.BLACK_Rz,
        &APF_Path_Planning_2023a_Blue_DW.BLACK_Tz,
        &APF_Path_Planning_2023a_Blue_DW.BLUE_Fx,
        &APF_Path_Planning_2023a_Blue_DW.BLUE_Fy,
        &APF_Path_Planning_2023a_Blue_DW.BLUE_Px,
        &APF_Path_Planning_2023a_Blue_DW.BLUE_Py,
        &APF_Path_Planning_2023a_Blue_DW.BLUE_Rz,
        &APF_Path_Planning_2023a_Blue_DW.BLUE_Tz,
        &APF_Path_Planning_2023a_Blue_DW.Float_State,
        &APF_Path_Planning_2023a_Blue_DW.RED_ARM_Control_Mode,
        &APF_Path_Planning_2023a_Blue_DW.RED_Elbow_Command,
        &APF_Path_Planning_2023a_Blue_DW.RED_Fx,
        &APF_Path_Planning_2023a_Blue_DW.RED_Fy,
        &APF_Path_Planning_2023a_Blue_DW.RED_Px,
        &APF_Path_Planning_2023a_Blue_DW.RED_Py,
        &APF_Path_Planning_2023a_Blue_DW.RED_Rz,
        &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Elbow,
        &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder,
        &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Wrist,
        &APF_Path_Planning_2023a_Blue_DW.RED_Shoulder_Command,
        &APF_Path_Planning_2023a_Blue_DW.RED_Tz,
        &APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW,
        &APF_Path_Planning_2023a_Blue_DW.RED_Wrist_Command,
        &APF_Path_Planning_2023a_Blue_DW.WhoAmI,
        &APF_Path_Planning_2023a_BlueI_B.isSim,
        &APF_Path_Planning_2023a_BlueI_B.Phase4ReturnHome,
        &APF_Path_Planning_2023a_Blue_DW.Phase4ReturnHome,
        &APF_Path_Planning_2023a_BlueI_P.Phase4ReturnHome);

      // End of Outputs for SubSystem: '<Root>/Phase #4: Return Home'
    } else if ((APF_Path_Planning_2023a_Blue_DW.Univ_Time <
                APF_Path_Planning_2023a_BlueI_P.Phase5_End) &&
               (APF_Path_Planning_2023a_Blue_DW.Univ_Time >=
                APF_Path_Planning_2023a_BlueI_P.Phase4_End)) {
      APF_Path_Planning_2023a_Blue_DW.SeparatePhases_ActiveSubsystem = 5;

      // Outputs for IfAction SubSystem: '<Root>/Phase #5: Hold Home' incorporates:
      //   ActionPort: '<S11>/Action Port'

      APF_Path_Plann_Phase4ReturnHome(&APF_Path_Planning_2023a_Blue_DW.BLACK_Fx,
        &APF_Path_Planning_2023a_Blue_DW.BLACK_Fy,
        &APF_Path_Planning_2023a_Blue_DW.BLACK_Px,
        &APF_Path_Planning_2023a_Blue_DW.BLACK_Py,
        &APF_Path_Planning_2023a_Blue_DW.BLACK_Rz,
        &APF_Path_Planning_2023a_Blue_DW.BLACK_Tz,
        &APF_Path_Planning_2023a_Blue_DW.BLUE_Fx,
        &APF_Path_Planning_2023a_Blue_DW.BLUE_Fy,
        &APF_Path_Planning_2023a_Blue_DW.BLUE_Px,
        &APF_Path_Planning_2023a_Blue_DW.BLUE_Py,
        &APF_Path_Planning_2023a_Blue_DW.BLUE_Rz,
        &APF_Path_Planning_2023a_Blue_DW.BLUE_Tz,
        &APF_Path_Planning_2023a_Blue_DW.Float_State,
        &APF_Path_Planning_2023a_Blue_DW.RED_ARM_Control_Mode,
        &APF_Path_Planning_2023a_Blue_DW.RED_Elbow_Command,
        &APF_Path_Planning_2023a_Blue_DW.RED_Fx,
        &APF_Path_Planning_2023a_Blue_DW.RED_Fy,
        &APF_Path_Planning_2023a_Blue_DW.RED_Px,
        &APF_Path_Planning_2023a_Blue_DW.RED_Py,
        &APF_Path_Planning_2023a_Blue_DW.RED_Rz,
        &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Elbow,
        &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder,
        &APF_Path_Planning_2023a_Blue_DW.RED_Rz_Wrist,
        &APF_Path_Planning_2023a_Blue_DW.RED_Shoulder_Command,
        &APF_Path_Planning_2023a_Blue_DW.RED_Tz,
        &APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW,
        &APF_Path_Planning_2023a_Blue_DW.RED_Wrist_Command,
        &APF_Path_Planning_2023a_Blue_DW.WhoAmI,
        &APF_Path_Planning_2023a_BlueI_B.isSim,
        &APF_Path_Planning_2023a_BlueI_B.Phase5HoldHome,
        &APF_Path_Planning_2023a_Blue_DW.Phase5HoldHome,
        &APF_Path_Planning_2023a_BlueI_P.Phase5HoldHome);

      // End of Outputs for SubSystem: '<Root>/Phase #5: Hold Home'
    } else if (APF_Path_Planning_2023a_Blue_DW.Univ_Time >=
               APF_Path_Planning_2023a_BlueI_P.Phase5_End) {
      APF_Path_Planning_2023a_Blue_DW.SeparatePhases_ActiveSubsystem = 6;

      // Outputs for IfAction SubSystem: '<Root>/Phase #6: Clean Shutdown' incorporates:
      //   ActionPort: '<S12>/Action Port'

      // If: '<S12>/This IF block determines whether or not to run the BLACK sim//exp' incorporates:
      //   Constant: '<S18>/Constant'
      //   DataStoreRead: '<S12>/Data Store Read'
      //   DataStoreWrite: '<S18>/Data Store Write'

      if ((APF_Path_Planning_2023a_Blue_DW.WhoAmI == 2.0) ||
          (APF_Path_Planning_2023a_BlueI_P.simMode == 1.0)) {
        // Outputs for IfAction SubSystem: '<S12>/Change BLACK Behavior' incorporates:
        //   ActionPort: '<S501>/Action Port'

        // DataStoreWrite: '<S501>/BLACK_Fx' incorporates:
        //   Constant: '<S501>/Constant3'

        APF_Path_Planning_2023a_Blue_DW.BLACK_Fx =
          APF_Path_Planning_2023a_BlueI_P.Constant3_Value;

        // DataStoreWrite: '<S501>/BLACK_Fy' incorporates:
        //   Constant: '<S501>/Constant4'

        APF_Path_Planning_2023a_Blue_DW.BLACK_Fy =
          APF_Path_Planning_2023a_BlueI_P.Constant4_Value_g;

        // DataStoreWrite: '<S501>/BLACK_Tz' incorporates:
        //   Constant: '<S501>/Constant5'

        APF_Path_Planning_2023a_Blue_DW.BLACK_Tz =
          APF_Path_Planning_2023a_BlueI_P.Constant5_Value_d;

        // DataStoreWrite: '<S501>/Data Store Write3' incorporates:
        //   Constant: '<S501>/Puck State'

        APF_Path_Planning_2023a_Blue_DW.Float_State =
          APF_Path_Planning_2023a_BlueI_P.PuckState_Value_d;

        // End of Outputs for SubSystem: '<S12>/Change BLACK Behavior'
      }

      // End of If: '<S12>/This IF block determines whether or not to run the BLACK sim//exp' 

      // If: '<S12>/This IF block determines whether or not to run the BLUE sim//exp' incorporates:
      //   Constant: '<S18>/Constant'
      //   DataStoreRead: '<S12>/Data Store Read'
      //   DataStoreWrite: '<S18>/Data Store Write'

      if ((APF_Path_Planning_2023a_Blue_DW.WhoAmI == 3.0) ||
          (APF_Path_Planning_2023a_BlueI_P.simMode == 1.0)) {
        // Outputs for IfAction SubSystem: '<S12>/Change BLUE Behavior' incorporates:
        //   ActionPort: '<S502>/Action Port'

        APF_Path_Pla_ChangeBLUEBehavior(&APF_Path_Planning_2023a_Blue_DW.BLUE_Fx,
          &APF_Path_Planning_2023a_Blue_DW.BLUE_Fy,
          &APF_Path_Planning_2023a_Blue_DW.BLUE_Tz,
          &APF_Path_Planning_2023a_Blue_DW.Float_State,
          &APF_Path_Planning_2023a_BlueI_P.ChangeBLUEBehavior_l);

        // End of Outputs for SubSystem: '<S12>/Change BLUE Behavior'
      }

      // End of If: '<S12>/This IF block determines whether or not to run the BLUE sim//exp' 

      // If: '<S12>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
      //   Constant: '<S18>/Constant'
      //   DataStoreRead: '<S12>/Data Store Read'
      //   DataStoreWrite: '<S18>/Data Store Write'

      if ((APF_Path_Planning_2023a_Blue_DW.WhoAmI == 1.0) ||
          (APF_Path_Planning_2023a_BlueI_P.simMode == 1.0)) {
        // Outputs for IfAction SubSystem: '<S12>/Change RED Behavior' incorporates:
        //   ActionPort: '<S503>/Action Port'

        // DataStoreWrite: '<S503>/RED_Fx' incorporates:
        //   Constant: '<S503>/Constant'

        APF_Path_Planning_2023a_Blue_DW.RED_Fx =
          APF_Path_Planning_2023a_BlueI_P.Constant_Value_b;

        // DataStoreWrite: '<S503>/RED_Fy' incorporates:
        //   Constant: '<S503>/Constant1'

        APF_Path_Planning_2023a_Blue_DW.RED_Fy =
          APF_Path_Planning_2023a_BlueI_P.Constant1_Value_f;

        // DataStoreWrite: '<S503>/RED_Tz' incorporates:
        //   Constant: '<S503>/Constant2'

        APF_Path_Planning_2023a_Blue_DW.RED_Tz =
          APF_Path_Planning_2023a_BlueI_P.Constant2_Value_h;

        // DataStoreWrite: '<S503>/Data Store Write1' incorporates:
        //   Constant: '<S503>/Constant3'

        APF_Path_Planning_2023a_Blue_DW.RED_ARM_Control_Mode =
          APF_Path_Planning_2023a_BlueI_P.Constant3_Value_h;

        // DataStoreWrite: '<S503>/Data Store Write3' incorporates:
        //   Constant: '<S503>/Puck State'

        APF_Path_Planning_2023a_Blue_DW.Float_State =
          APF_Path_Planning_2023a_BlueI_P.PuckState_Value_e;

        // End of Outputs for SubSystem: '<S12>/Change RED Behavior'
      }

      // End of If: '<S12>/This IF block determines whether or not to run the RED sim//exp ' 
      // End of Outputs for SubSystem: '<Root>/Phase #6: Clean Shutdown'
    }

    // End of If: '<Root>/Separate Phases'

    // If: '<Root>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' incorporates:
    //   DataStoreRead: '<Root>/Data Store Read1'

    if (APF_Path_Planning_2023a_BlueI_B.isSim == 1.0) {
      // Outputs for IfAction SubSystem: '<Root>/Simulate Plant Dynamics' incorporates:
      //   ActionPort: '<S17>/Action Port'

      // DiscreteIntegrator: '<S552>/Acceleration  to Velocity' incorporates:
      //   DataStoreRead: '<S549>/BLACK_Fx_Sat'
      //   MATLAB Function: '<S552>/MATLAB Function'
      //   SignalConversion generated from: '<S559>/ SFunction '

      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_Blue_DW.BLACK_Fx_Sat /
        APF_Path_Planning_2023a_BlueI_P.mBLACK *
        APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_gainva_j +
        APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE[0];
      APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE[0] =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

      // DiscreteIntegrator: '<S552>/Velocity to Position'
      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_BlueI_P.VelocitytoPosition_gainval_n *
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
        APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE[0];
      APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE[0] =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

      // Sum: '<S552>/Sum' incorporates:
      //   RandomNumber: '<S552>/Random Number'

      APF_Path_Planning_2023a_Blue_DW.BLACK_Px =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
        APF_Path_Planning_2023a_Blue_DW.NextOutput;

      // DiscreteIntegrator: '<S552>/Acceleration  to Velocity' incorporates:
      //   DataStoreRead: '<S549>/BLACK_Fy_Sat'
      //   MATLAB Function: '<S552>/MATLAB Function'
      //   SignalConversion generated from: '<S559>/ SFunction '

      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_Blue_DW.BLACK_Fy_Sat /
        APF_Path_Planning_2023a_BlueI_P.mBLACK *
        APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_gainva_j +
        APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE[1];
      APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE[1] =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

      // DiscreteIntegrator: '<S552>/Velocity to Position'
      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_BlueI_P.VelocitytoPosition_gainval_n *
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
        APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE[1];
      APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE[1] =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

      // Sum: '<S552>/Sum' incorporates:
      //   RandomNumber: '<S552>/Random Number'

      APF_Path_Planning_2023a_Blue_DW.BLACK_Py =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
        APF_Path_Planning_2023a_Blue_DW.NextOutput;

      // DiscreteIntegrator: '<S552>/Acceleration  to Velocity' incorporates:
      //   DataStoreRead: '<S549>/BLACK_Tz_Sat'
      //   MATLAB Function: '<S552>/MATLAB Function'
      //   SignalConversion generated from: '<S559>/ SFunction '

      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_Blue_DW.BLACK_Tz_Sat /
        APF_Path_Planning_2023a_BlueI_P.IBLACK *
        APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_gainva_j +
        APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE[2];
      APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE[2] =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

      // DiscreteIntegrator: '<S552>/Velocity to Position'
      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_BlueI_P.VelocitytoPosition_gainval_n *
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
        APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE[2];
      APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE[2] =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

      // Sum: '<S552>/Sum' incorporates:
      //   RandomNumber: '<S552>/Random Number'

      APF_Path_Planning_2023a_Blue_DW.BLACK_Rz =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
        APF_Path_Planning_2023a_Blue_DW.NextOutput;

      // Delay: '<S558>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_ou) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_f =
          APF_Path_Planning_2023a_Blue_DW.BLACK_Px;
      }

      // Sum: '<S558>/Sum6' incorporates:
      //   Delay: '<S558>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_Blue_DW.BLACK_Px -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_f;

      // If: '<S558>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
        // Outputs for IfAction SubSystem: '<S558>/Hold this value' incorporates:
        //   ActionPort: '<S565>/Action Port'

        // SignalConversion generated from: '<S565>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_j =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

        // End of Outputs for SubSystem: '<S558>/Hold this value'
      }

      // End of If: '<S558>/if we went through a "step"'

      // Gain: '<S558>/divide by delta T' incorporates:
      //   DataStoreWrite: '<S549>/BLACK_Vx'

      APF_Path_Planning_2023a_Blue_DW.BLACK_Vx = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_j;

      // Delay: '<S555>/Delay1' incorporates:
      //   DataStoreWrite: '<S549>/BLACK_Vx'

      if (APF_Path_Planning_2023a_Blue_DW.icLoad_p4) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_lg =
          APF_Path_Planning_2023a_Blue_DW.BLACK_Vx;
      }

      // Sum: '<S555>/Sum6' incorporates:
      //   DataStoreWrite: '<S549>/BLACK_Vx'
      //   Delay: '<S555>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_Blue_DW.BLACK_Vx -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_lg;

      // If: '<S555>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
        // Outputs for IfAction SubSystem: '<S555>/Hold this value' incorporates:
        //   ActionPort: '<S562>/Action Port'

        // SignalConversion generated from: '<S562>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_d =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

        // End of Outputs for SubSystem: '<S555>/Hold this value'
      }

      // End of If: '<S555>/if we went through a "step"'

      // Sum: '<S549>/Sum1' incorporates:
      //   DataStoreWrite: '<S549>/BLACK_IMU_Ax_I'
      //   Gain: '<S555>/divide by delta T'
      //   RandomNumber: '<S549>/Random Number1'

      APF_Path_Planning_2023a_Blue_DW.BLACK_Ay = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_d +
        APF_Path_Planning_2023a_Blue_DW.NextOutput_b;

      // Delay: '<S553>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_jc) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_d3a =
          APF_Path_Planning_2023a_Blue_DW.BLACK_Py;
      }

      // Sum: '<S553>/Sum6' incorporates:
      //   Delay: '<S553>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_Blue_DW.BLACK_Py -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_d3a;

      // If: '<S553>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
        // Outputs for IfAction SubSystem: '<S553>/Hold this value' incorporates:
        //   ActionPort: '<S560>/Action Port'

        // SignalConversion generated from: '<S560>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_pk =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

        // End of Outputs for SubSystem: '<S553>/Hold this value'
      }

      // End of If: '<S553>/if we went through a "step"'

      // Gain: '<S553>/divide by delta T' incorporates:
      //   DataStoreWrite: '<S549>/BLACK_Vy'

      APF_Path_Planning_2023a_Blue_DW.BLACK_Vy = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_pk;

      // Delay: '<S556>/Delay1' incorporates:
      //   DataStoreWrite: '<S549>/BLACK_Vy'

      if (APF_Path_Planning_2023a_Blue_DW.icLoad_jk) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_ea =
          APF_Path_Planning_2023a_Blue_DW.BLACK_Vy;
      }

      // Sum: '<S556>/Sum6' incorporates:
      //   DataStoreWrite: '<S549>/BLACK_Vy'
      //   Delay: '<S556>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_Blue_DW.BLACK_Vy -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_ea;

      // If: '<S556>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
        // Outputs for IfAction SubSystem: '<S556>/Hold this value' incorporates:
        //   ActionPort: '<S563>/Action Port'

        // SignalConversion generated from: '<S563>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_pg =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

        // End of Outputs for SubSystem: '<S556>/Hold this value'
      }

      // End of If: '<S556>/if we went through a "step"'

      // Sum: '<S549>/Sum2' incorporates:
      //   DataStoreWrite: '<S549>/BLACK_IMU_Ay_I'
      //   Gain: '<S556>/divide by delta T'
      //   RandomNumber: '<S549>/Random Number'

      APF_Path_Planning_2023a_Blue_DW.BLACK_RzDD = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_pg +
        APF_Path_Planning_2023a_Blue_DW.NextOutput_j;

      // Delay: '<S554>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_jr) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_cx =
          APF_Path_Planning_2023a_Blue_DW.BLACK_Rz;
      }

      // Sum: '<S554>/Sum6' incorporates:
      //   Delay: '<S554>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_Blue_DW.BLACK_Rz -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_cx;

      // If: '<S554>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
        // Outputs for IfAction SubSystem: '<S554>/Hold this value' incorporates:
        //   ActionPort: '<S561>/Action Port'

        // SignalConversion generated from: '<S561>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_c5 =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

        // End of Outputs for SubSystem: '<S554>/Hold this value'
      }

      // End of If: '<S554>/if we went through a "step"'

      // Gain: '<S554>/divide by delta T' incorporates:
      //   DataStoreWrite: '<S549>/BLACK_RzD'

      APF_Path_Planning_2023a_Blue_DW.BLACK_RzD = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_c5;

      // Delay: '<S557>/Delay1' incorporates:
      //   DataStoreWrite: '<S549>/BLACK_RzD'

      if (APF_Path_Planning_2023a_Blue_DW.icLoad_jko) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_ab =
          APF_Path_Planning_2023a_Blue_DW.BLACK_RzD;
      }

      // Sum: '<S557>/Sum6' incorporates:
      //   DataStoreWrite: '<S549>/BLACK_RzD'
      //   Delay: '<S557>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_Blue_DW.BLACK_RzD -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_ab;

      // If: '<S557>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
        // Outputs for IfAction SubSystem: '<S557>/Hold this value' incorporates:
        //   ActionPort: '<S564>/Action Port'

        // SignalConversion generated from: '<S564>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_ib =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

        // End of Outputs for SubSystem: '<S557>/Hold this value'
      }

      // End of If: '<S557>/if we went through a "step"'

      // Sum: '<S549>/Sum3' incorporates:
      //   DataStoreWrite: '<S549>/BLACK_IMU_R'
      //   Gain: '<S557>/divide by delta T'
      //   RandomNumber: '<S549>/Random Number2'

      APF_Path_Planning_2023a_Blue_DW.BLACK_Ax = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_ib +
        APF_Path_Planning_2023a_Blue_DW.NextOutput_g;

      // DiscreteIntegrator: '<S566>/Acceleration  to Velocity' incorporates:
      //   DataStoreRead: '<S550>/BLUE_Fx_Sat '
      //   MATLAB Function: '<S566>/MATLAB Function'
      //   SignalConversion generated from: '<S573>/ SFunction '

      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_Blue_DW.BLUE_Fx_Sat /
        APF_Path_Planning_2023a_BlueI_P.mBLUE *
        APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_gainva_p +
        APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_i[0];
      APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_i[0] =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

      // DiscreteIntegrator: '<S566>/Velocity to Position'
      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_BlueI_P.VelocitytoPosition_gainval_e *
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
        APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE_a[0];
      APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE_a[0] =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

      // Sum: '<S566>/Sum' incorporates:
      //   RandomNumber: '<S566>/Random Number'

      APF_Path_Planning_2023a_Blue_DW.BLUE_Px =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
        APF_Path_Planning_2023a_Blue_DW.NextOutput_a;

      // DiscreteIntegrator: '<S566>/Acceleration  to Velocity' incorporates:
      //   DataStoreRead: '<S550>/BLUE_Fy_Sat'
      //   MATLAB Function: '<S566>/MATLAB Function'
      //   SignalConversion generated from: '<S573>/ SFunction '

      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_Blue_DW.BLUE_Fy_Sat /
        APF_Path_Planning_2023a_BlueI_P.mBLUE *
        APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_gainva_p +
        APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_i[1];
      APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_i[1] =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

      // DiscreteIntegrator: '<S566>/Velocity to Position'
      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_BlueI_P.VelocitytoPosition_gainval_e *
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
        APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE_a[1];
      APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE_a[1] =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

      // Sum: '<S566>/Sum' incorporates:
      //   RandomNumber: '<S566>/Random Number'

      APF_Path_Planning_2023a_Blue_DW.BLUE_Py =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
        APF_Path_Planning_2023a_Blue_DW.NextOutput_a;

      // DiscreteIntegrator: '<S566>/Acceleration  to Velocity' incorporates:
      //   DataStoreRead: '<S550>/BLUE_Tz_Sat'
      //   MATLAB Function: '<S566>/MATLAB Function'
      //   SignalConversion generated from: '<S573>/ SFunction '

      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_Blue_DW.BLUE_Tz_Sat /
        APF_Path_Planning_2023a_BlueI_P.IBLUE *
        APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_gainva_p +
        APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_i[2];
      APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_i[2] =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

      // DiscreteIntegrator: '<S566>/Velocity to Position'
      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_BlueI_P.VelocitytoPosition_gainval_e *
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
        APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE_a[2];
      APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE_a[2] =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

      // Sum: '<S566>/Sum' incorporates:
      //   RandomNumber: '<S566>/Random Number'

      APF_Path_Planning_2023a_Blue_DW.BLUE_Rz =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
        APF_Path_Planning_2023a_Blue_DW.NextOutput_a;

      // Delay: '<S572>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_do) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_gv =
          APF_Path_Planning_2023a_Blue_DW.BLUE_Px;
      }

      // Sum: '<S572>/Sum6' incorporates:
      //   Delay: '<S572>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_Blue_DW.BLUE_Px -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_gv;

      // If: '<S572>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
        // Outputs for IfAction SubSystem: '<S572>/Hold this value' incorporates:
        //   ActionPort: '<S579>/Action Port'

        // SignalConversion generated from: '<S579>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_ir =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

        // End of Outputs for SubSystem: '<S572>/Hold this value'
      }

      // End of If: '<S572>/if we went through a "step"'

      // Gain: '<S572>/divide by delta T' incorporates:
      //   DataStoreWrite: '<S550>/BLUE_Vx'

      APF_Path_Planning_2023a_Blue_DW.BLUE_Vx = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_ir;

      // Delay: '<S569>/Delay1' incorporates:
      //   DataStoreWrite: '<S550>/BLUE_Vx'

      if (APF_Path_Planning_2023a_Blue_DW.icLoad_nk) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_ds =
          APF_Path_Planning_2023a_Blue_DW.BLUE_Vx;
      }

      // End of Delay: '<S569>/Delay1'

      // Delay: '<S567>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_ip) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_i5 =
          APF_Path_Planning_2023a_Blue_DW.BLUE_Py;
      }

      // Sum: '<S567>/Sum6' incorporates:
      //   Delay: '<S567>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_Blue_DW.BLUE_Py -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_i5;

      // If: '<S567>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
        // Outputs for IfAction SubSystem: '<S567>/Hold this value' incorporates:
        //   ActionPort: '<S574>/Action Port'

        // SignalConversion generated from: '<S574>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_ex =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

        // End of Outputs for SubSystem: '<S567>/Hold this value'
      }

      // End of If: '<S567>/if we went through a "step"'

      // Gain: '<S567>/divide by delta T' incorporates:
      //   DataStoreWrite: '<S550>/BLUE_Vy'

      APF_Path_Planning_2023a_Blue_DW.BLUE_Vy = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_ex;

      // Delay: '<S570>/Delay1' incorporates:
      //   DataStoreWrite: '<S550>/BLUE_Vy'

      if (APF_Path_Planning_2023a_Blue_DW.icLoad_az) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_l0 =
          APF_Path_Planning_2023a_Blue_DW.BLUE_Vy;
      }

      // End of Delay: '<S570>/Delay1'

      // Delay: '<S568>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_dh) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_iq =
          APF_Path_Planning_2023a_Blue_DW.BLUE_Rz;
      }

      // Sum: '<S568>/Sum6' incorporates:
      //   Delay: '<S568>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_Blue_DW.BLUE_Rz -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_iq;

      // If: '<S568>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
        // Outputs for IfAction SubSystem: '<S568>/Hold this value' incorporates:
        //   ActionPort: '<S575>/Action Port'

        // SignalConversion generated from: '<S575>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_cz =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

        // End of Outputs for SubSystem: '<S568>/Hold this value'
      }

      // End of If: '<S568>/if we went through a "step"'

      // Gain: '<S568>/divide by delta T' incorporates:
      //   DataStoreWrite: '<S550>/BLUE_RzD'

      APF_Path_Planning_2023a_Blue_DW.BLUE_RzD = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_cz;

      // Delay: '<S571>/Delay1' incorporates:
      //   DataStoreWrite: '<S550>/BLUE_RzD'

      if (APF_Path_Planning_2023a_Blue_DW.icLoad_ex) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_eq =
          APF_Path_Planning_2023a_Blue_DW.BLUE_RzD;
      }

      // End of Delay: '<S571>/Delay1'

      // If: '<S551>/If' incorporates:
      //   Constant: '<S551>/Constant'

      if ((APF_Path_Planning_2023a_BlueI_P.platformSelection == 4.0) ||
          (APF_Path_Planning_2023a_BlueI_P.platformSelection == 5.0) ||
          (APF_Path_Planning_2023a_BlueI_P.platformSelection == 10.0) ||
          (APF_Path_Planning_2023a_BlueI_P.platformSelection == 11.0)) {
        // Outputs for IfAction SubSystem: '<S551>/RED + ARM' incorporates:
        //   ActionPort: '<S580>/Action Port'

        // MATLAB Function: '<S582>/Inertia Function 1' incorporates:
        //   Delay: '<S582>/Delay'
        //   MATLAB Function: '<S582>/Coriolis Function1'

        APF_Path_Planning_2023a_BlueI_B.Switch =
          APF_Path_Planning_2023a_BlueI_P.a1 +
          APF_Path_Planning_2023a_BlueI_P.b1;
        APF_Path_Planning_2023a_BlueI_B.absx_tmp =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[2] +
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[3];
        APF_Path_Planning_2023a_BlueI_B.t7 = cos
          (APF_Path_Planning_2023a_BlueI_B.absx_tmp);
        APF_Path_Planning_2023a_BlueI_B.t21 = APF_Path_Planning_2023a_BlueI_P.a1
          * APF_Path_Planning_2023a_BlueI_P.mPROX;
        APF_Path_Planning_2023a_BlueI_B.t8 =
          (APF_Path_Planning_2023a_BlueI_P.mDIST *
           APF_Path_Planning_2023a_BlueI_B.Switch +
           APF_Path_Planning_2023a_BlueI_B.t21) +
          APF_Path_Planning_2023a_BlueI_P.mEE *
          APF_Path_Planning_2023a_BlueI_B.Switch;
        APF_Path_Planning_2023a_BlueI_B.rtb_Sum6_a_tmp =
          APF_Path_Planning_2023a_BlueI_P.a2 *
          APF_Path_Planning_2023a_BlueI_P.mDIST;
        APF_Path_Planning_2023a_BlueI_B.t12_tmp =
          APF_Path_Planning_2023a_BlueI_B.absx_tmp +
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[4];
        APF_Path_Planning_2023a_BlueI_B.t13 = cos
          (APF_Path_Planning_2023a_BlueI_B.t12_tmp);
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp =
          APF_Path_Planning_2023a_BlueI_P.a2 +
          APF_Path_Planning_2023a_BlueI_P.b2;
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp *
          APF_Path_Planning_2023a_BlueI_P.mEE +
          APF_Path_Planning_2023a_BlueI_B.rtb_Sum6_a_tmp;
        APF_Path_Planning_2023a_BlueI_B.link1_com_y =
          APF_Path_Planning_2023a_BlueI_B.t12_tmp +
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[5];
        APF_Path_Planning_2023a_BlueI_B.t16 = cos
          (APF_Path_Planning_2023a_BlueI_B.link1_com_y);
        APF_Path_Planning_2023a_BlueI_B.t17 =
          ((APF_Path_Planning_2023a_BlueI_P.mRED +
            APF_Path_Planning_2023a_BlueI_P.mPROX) +
           APF_Path_Planning_2023a_BlueI_P.mDIST) +
          APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.Derivative2 =
          (APF_Path_Planning_2023a_BlueI_P.b0 *
           APF_Path_Planning_2023a_BlueI_P.mPROX +
           APF_Path_Planning_2023a_BlueI_P.b0 *
           APF_Path_Planning_2023a_BlueI_P.mDIST) +
          APF_Path_Planning_2023a_BlueI_P.b0 *
          APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 = (1.5707963267948966 -
          APF_Path_Planning_2023a_BlueI_P.Phi) +
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[2];
        APF_Path_Planning_2023a_BlueI_B.t23 = sin
          (APF_Path_Planning_2023a_BlueI_B.absx_tmp);
        APF_Path_Planning_2023a_BlueI_B.t24 = sin
          (APF_Path_Planning_2023a_BlueI_B.t12_tmp);
        APF_Path_Planning_2023a_BlueI_B.t25 = sin
          (APF_Path_Planning_2023a_BlueI_B.link1_com_y);
        APF_Path_Planning_2023a_BlueI_B.t28 =
          (APF_Path_Planning_2023a_BlueI_P.a2 *
           APF_Path_Planning_2023a_BlueI_P.mEE +
           APF_Path_Planning_2023a_BlueI_B.rtb_Sum6_a_tmp) +
          APF_Path_Planning_2023a_BlueI_P.b2 *
          APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.t91 =
          APF_Path_Planning_2023a_BlueI_B.t13 *
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
        APF_Path_Planning_2023a_BlueI_B.link1_com_x =
          APF_Path_Planning_2023a_BlueI_P.a3 *
          APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.t93 =
          APF_Path_Planning_2023a_BlueI_B.link1_com_x *
          APF_Path_Planning_2023a_BlueI_B.t16;
        APF_Path_Planning_2023a_BlueI_B.t96 =
          (-(APF_Path_Planning_2023a_BlueI_B.t7 *
             APF_Path_Planning_2023a_BlueI_B.t8) -
           APF_Path_Planning_2023a_BlueI_B.t91) -
          APF_Path_Planning_2023a_BlueI_B.t93;
        APF_Path_Planning_2023a_BlueI_B.t30 =
          APF_Path_Planning_2023a_BlueI_B.t96 -
          APF_Path_Planning_2023a_BlueI_B.Derivative2 * sin
          (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
        APF_Path_Planning_2023a_BlueI_B.q = APF_Path_Planning_2023a_BlueI_B.t8 *
          APF_Path_Planning_2023a_BlueI_B.t23;
        APF_Path_Planning_2023a_BlueI_B.t103 =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW *
          APF_Path_Planning_2023a_BlueI_B.t24;
        APF_Path_Planning_2023a_BlueI_B.t104 =
          APF_Path_Planning_2023a_BlueI_B.link1_com_x *
          APF_Path_Planning_2023a_BlueI_B.t25;
        APF_Path_Planning_2023a_BlueI_B.t33 =
          ((APF_Path_Planning_2023a_BlueI_B.Derivative2 * cos
            (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1) -
            APF_Path_Planning_2023a_BlueI_B.q) -
           APF_Path_Planning_2023a_BlueI_B.t103) -
          APF_Path_Planning_2023a_BlueI_B.t104;
        APF_Path_Planning_2023a_BlueI_B.t34 = APF_Path_Planning_2023a_BlueI_P.a1
          * APF_Path_Planning_2023a_BlueI_P.a1;
        APF_Path_Planning_2023a_BlueI_B.t35 = APF_Path_Planning_2023a_BlueI_P.a2
          * APF_Path_Planning_2023a_BlueI_P.a2;
        APF_Path_Planning_2023a_BlueI_B.alpha_pol =
          APF_Path_Planning_2023a_BlueI_P.b0 *
          APF_Path_Planning_2023a_BlueI_P.b0;
        APF_Path_Planning_2023a_BlueI_B.t37 = APF_Path_Planning_2023a_BlueI_P.b1
          * APF_Path_Planning_2023a_BlueI_P.b1;
        APF_Path_Planning_2023a_BlueI_B.t45 = cos
          (APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[4]);
        APF_Path_Planning_2023a_BlueI_B.rtb_path_idx_1 =
          APF_Path_Planning_2023a_BlueI_P.a1 *
          APF_Path_Planning_2023a_BlueI_P.a2;
        APF_Path_Planning_2023a_BlueI_B.t95 = APF_Path_Planning_2023a_BlueI_P.a2
          * APF_Path_Planning_2023a_BlueI_P.b1;
        APF_Path_Planning_2023a_BlueI_B.t100 =
          APF_Path_Planning_2023a_BlueI_B.rtb_path_idx_1 *
          APF_Path_Planning_2023a_BlueI_P.mDIST;
        APF_Path_Planning_2023a_BlueI_B.rtb_path_idx_1 *=
          APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.t92 =
          APF_Path_Planning_2023a_BlueI_B.t95 *
          APF_Path_Planning_2023a_BlueI_P.mDIST;
        APF_Path_Planning_2023a_BlueI_B.t94 = APF_Path_Planning_2023a_BlueI_P.a1
          * APF_Path_Planning_2023a_BlueI_P.b2 *
          APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.t95 *=
          APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.t97 = APF_Path_Planning_2023a_BlueI_P.b1
          * APF_Path_Planning_2023a_BlueI_P.b2 *
          APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.absxk =
          (((((APF_Path_Planning_2023a_BlueI_B.t100 * 2.0 +
               APF_Path_Planning_2023a_BlueI_B.rtb_path_idx_1 * 2.0) +
              APF_Path_Planning_2023a_BlueI_B.t92 * 2.0) +
             APF_Path_Planning_2023a_BlueI_B.t94 * 2.0) +
            APF_Path_Planning_2023a_BlueI_B.t95 * 2.0) +
           APF_Path_Planning_2023a_BlueI_B.t97 * 2.0) *
          APF_Path_Planning_2023a_BlueI_B.t45;
        APF_Path_Planning_2023a_BlueI_B.t50 = cos
          (APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[5]);
        APF_Path_Planning_2023a_BlueI_B.t51_tmp =
          APF_Path_Planning_2023a_BlueI_P.a2 *
          APF_Path_Planning_2023a_BlueI_P.a3 *
          APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.t79 = APF_Path_Planning_2023a_BlueI_P.a3
          * APF_Path_Planning_2023a_BlueI_P.b2 *
          APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.t51 =
          (APF_Path_Planning_2023a_BlueI_B.t51_tmp * 2.0 +
           APF_Path_Planning_2023a_BlueI_B.t79 * 2.0) *
          APF_Path_Planning_2023a_BlueI_B.t50;
        APF_Path_Planning_2023a_BlueI_B.t80 =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[4] +
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[5];
        APF_Path_Planning_2023a_BlueI_B.t56 = cos
          (APF_Path_Planning_2023a_BlueI_B.t80);
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_P.a1 *
          APF_Path_Planning_2023a_BlueI_P.a3 *
          APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.Sum6_a =
          APF_Path_Planning_2023a_BlueI_P.a3 *
          APF_Path_Planning_2023a_BlueI_P.b1 *
          APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.t57 =
          (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW * 2.0 +
           APF_Path_Planning_2023a_BlueI_B.Sum6_a * 2.0) *
          APF_Path_Planning_2023a_BlueI_B.t56;
        APF_Path_Planning_2023a_BlueI_B.t54 = (1.5707963267948966 -
          APF_Path_Planning_2023a_BlueI_P.Phi) -
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[3];
        APF_Path_Planning_2023a_BlueI_B.t = sin
          (APF_Path_Planning_2023a_BlueI_B.t54);
        APF_Path_Planning_2023a_BlueI_B.t81 = (-(1.5707963267948966 -
          APF_Path_Planning_2023a_BlueI_P.Phi) +
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[3]) +
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[4];
        APF_Path_Planning_2023a_BlueI_B.t61 = sin
          (APF_Path_Planning_2023a_BlueI_B.t81);
        APF_Path_Planning_2023a_BlueI_B.t63_tmp =
          APF_Path_Planning_2023a_BlueI_B.t81 +
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[5];
        APF_Path_Planning_2023a_BlueI_B.t63 = sin
          (APF_Path_Planning_2023a_BlueI_B.t63_tmp);
        APF_Path_Planning_2023a_BlueI_B.t64 =
          APF_Path_Planning_2023a_BlueI_P.mPROX *
          APF_Path_Planning_2023a_BlueI_B.t34;
        APF_Path_Planning_2023a_BlueI_B.t65 =
          APF_Path_Planning_2023a_BlueI_P.mDIST *
          APF_Path_Planning_2023a_BlueI_B.t34;
        APF_Path_Planning_2023a_BlueI_B.t34 *=
          APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.t67 =
          APF_Path_Planning_2023a_BlueI_P.mDIST *
          APF_Path_Planning_2023a_BlueI_B.t35;
        APF_Path_Planning_2023a_BlueI_B.t68 =
          APF_Path_Planning_2023a_BlueI_P.mEE *
          APF_Path_Planning_2023a_BlueI_B.t35;
        APF_Path_Planning_2023a_BlueI_B.t35 = APF_Path_Planning_2023a_BlueI_P.a3
          * APF_Path_Planning_2023a_BlueI_P.a3 *
          APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.t71 =
          APF_Path_Planning_2023a_BlueI_P.mDIST *
          APF_Path_Planning_2023a_BlueI_B.t37;
        APF_Path_Planning_2023a_BlueI_B.t72 =
          APF_Path_Planning_2023a_BlueI_P.mEE *
          APF_Path_Planning_2023a_BlueI_B.t37;
        APF_Path_Planning_2023a_BlueI_B.t74 = APF_Path_Planning_2023a_BlueI_P.b2
          * APF_Path_Planning_2023a_BlueI_P.b2 *
          APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.t37 = APF_Path_Planning_2023a_BlueI_P.a1
          * APF_Path_Planning_2023a_BlueI_P.b1;
        APF_Path_Planning_2023a_BlueI_B.t75 =
          APF_Path_Planning_2023a_BlueI_B.t37 *
          APF_Path_Planning_2023a_BlueI_P.mDIST * 2.0;
        APF_Path_Planning_2023a_BlueI_B.t76 =
          APF_Path_Planning_2023a_BlueI_B.t37 *
          APF_Path_Planning_2023a_BlueI_P.mEE * 2.0;
        APF_Path_Planning_2023a_BlueI_B.t37 = APF_Path_Planning_2023a_BlueI_P.a2
          * APF_Path_Planning_2023a_BlueI_P.b2 *
          APF_Path_Planning_2023a_BlueI_P.mEE * 2.0;
        APF_Path_Planning_2023a_BlueI_B.t82 = APF_Path_Planning_2023a_BlueI_P.a2
          * APF_Path_Planning_2023a_BlueI_P.b0;
        APF_Path_Planning_2023a_BlueI_B.t83 =
          APF_Path_Planning_2023a_BlueI_B.t82 *
          APF_Path_Planning_2023a_BlueI_P.mDIST;
        APF_Path_Planning_2023a_BlueI_B.t82 *=
          APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.t81_tmp =
          APF_Path_Planning_2023a_BlueI_P.b0 *
          APF_Path_Planning_2023a_BlueI_P.b2 *
          APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.t56 *=
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
          APF_Path_Planning_2023a_BlueI_B.Sum6_a;
        APF_Path_Planning_2023a_BlueI_B.t112_tmp =
          ((APF_Path_Planning_2023a_BlueI_B.t83 +
            APF_Path_Planning_2023a_BlueI_B.t82) +
           APF_Path_Planning_2023a_BlueI_B.t81_tmp) *
          APF_Path_Planning_2023a_BlueI_B.t61;
        APF_Path_Planning_2023a_BlueI_B.t113_tmp_tmp =
          APF_Path_Planning_2023a_BlueI_P.a3 *
          APF_Path_Planning_2023a_BlueI_P.b0 *
          APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.t113_tmp =
          APF_Path_Planning_2023a_BlueI_B.t113_tmp_tmp *
          APF_Path_Planning_2023a_BlueI_B.t63;
        APF_Path_Planning_2023a_BlueI_B.t99_tmp =
          APF_Path_Planning_2023a_BlueI_P.a1 *
          APF_Path_Planning_2023a_BlueI_P.b0;
        APF_Path_Planning_2023a_BlueI_B.t99_tmp_l =
          APF_Path_Planning_2023a_BlueI_P.b0 *
          APF_Path_Planning_2023a_BlueI_P.b1;
        APF_Path_Planning_2023a_BlueI_B.t99_tmp_h =
          APF_Path_Planning_2023a_BlueI_B.t99_tmp *
          APF_Path_Planning_2023a_BlueI_P.mPROX;
        APF_Path_Planning_2023a_BlueI_B.t99_tmp_b =
          APF_Path_Planning_2023a_BlueI_B.t99_tmp *
          APF_Path_Planning_2023a_BlueI_P.mDIST;
        APF_Path_Planning_2023a_BlueI_B.t99_tmp *=
          APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.t99_tmp_d =
          APF_Path_Planning_2023a_BlueI_B.t99_tmp_l *
          APF_Path_Planning_2023a_BlueI_P.mDIST;
        APF_Path_Planning_2023a_BlueI_B.t99_tmp_l *=
          APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.t99_tmp_e =
          ((((((((((((((((APF_Path_Planning_2023a_BlueI_P.IPROX +
                          APF_Path_Planning_2023a_BlueI_P.IDIST) +
                         APF_Path_Planning_2023a_BlueI_P.IEE) +
                        APF_Path_Planning_2023a_BlueI_B.absxk) +
                       APF_Path_Planning_2023a_BlueI_B.t51) +
                      APF_Path_Planning_2023a_BlueI_B.t57) +
                     APF_Path_Planning_2023a_BlueI_B.t64) +
                    APF_Path_Planning_2023a_BlueI_B.t65) +
                   APF_Path_Planning_2023a_BlueI_B.t34) +
                  APF_Path_Planning_2023a_BlueI_B.t67) +
                 APF_Path_Planning_2023a_BlueI_B.t68) +
                APF_Path_Planning_2023a_BlueI_B.t35) +
               APF_Path_Planning_2023a_BlueI_B.t71) +
              APF_Path_Planning_2023a_BlueI_B.t72) +
             APF_Path_Planning_2023a_BlueI_B.t74) +
            APF_Path_Planning_2023a_BlueI_B.t75) +
           APF_Path_Planning_2023a_BlueI_B.t76) +
          APF_Path_Planning_2023a_BlueI_B.t37;
        APF_Path_Planning_2023a_BlueI_B.t99 =
          ((((((APF_Path_Planning_2023a_BlueI_B.t99_tmp_h +
                APF_Path_Planning_2023a_BlueI_B.t99_tmp_b) +
               APF_Path_Planning_2023a_BlueI_B.t99_tmp) +
              APF_Path_Planning_2023a_BlueI_B.t99_tmp_d) +
             APF_Path_Planning_2023a_BlueI_B.t99_tmp_l) *
            APF_Path_Planning_2023a_BlueI_B.t +
            APF_Path_Planning_2023a_BlueI_B.t99_tmp_e) -
           APF_Path_Planning_2023a_BlueI_B.t112_tmp) -
          APF_Path_Planning_2023a_BlueI_B.t113_tmp;
        APF_Path_Planning_2023a_BlueI_B.t50 *=
          APF_Path_Planning_2023a_BlueI_B.t51_tmp +
          APF_Path_Planning_2023a_BlueI_B.t79;
        APF_Path_Planning_2023a_BlueI_B.t114_tmp_tmp =
          ((((((APF_Path_Planning_2023a_BlueI_P.IDIST +
                APF_Path_Planning_2023a_BlueI_P.IEE) +
               APF_Path_Planning_2023a_BlueI_B.t51) +
              APF_Path_Planning_2023a_BlueI_B.t67) +
             APF_Path_Planning_2023a_BlueI_B.t68) +
            APF_Path_Planning_2023a_BlueI_B.t35) +
           APF_Path_Planning_2023a_BlueI_B.t74) +
          APF_Path_Planning_2023a_BlueI_B.t37;
        APF_Path_Planning_2023a_BlueI_B.t114_tmp =
          (((((APF_Path_Planning_2023a_BlueI_B.t100 +
               APF_Path_Planning_2023a_BlueI_B.rtb_path_idx_1) +
              APF_Path_Planning_2023a_BlueI_B.t92) +
             APF_Path_Planning_2023a_BlueI_B.t94) +
            APF_Path_Planning_2023a_BlueI_B.t95) +
           APF_Path_Planning_2023a_BlueI_B.t97) *
          APF_Path_Planning_2023a_BlueI_B.t45 +
          (APF_Path_Planning_2023a_BlueI_B.t114_tmp_tmp +
           APF_Path_Planning_2023a_BlueI_B.t56);
        APF_Path_Planning_2023a_BlueI_B.t45 =
          APF_Path_Planning_2023a_BlueI_P.IEE +
          APF_Path_Planning_2023a_BlueI_B.t35;
        APF_Path_Planning_2023a_BlueI_B.t115_tmp =
          (APF_Path_Planning_2023a_BlueI_B.t45 +
           APF_Path_Planning_2023a_BlueI_B.t56) +
          APF_Path_Planning_2023a_BlueI_B.t50;
        APF_Path_Planning_2023a_BlueI_B.t116 =
          APF_Path_Planning_2023a_BlueI_B.t45 +
          APF_Path_Planning_2023a_BlueI_B.t50;
        APF_Path_Planning_2023a_BlueI_B.IC[0] =
          APF_Path_Planning_2023a_BlueI_B.t17;
        APF_Path_Planning_2023a_BlueI_B.IC[1] = 0.0;
        APF_Path_Planning_2023a_BlueI_B.IC[2] =
          APF_Path_Planning_2023a_BlueI_B.t30;
        APF_Path_Planning_2023a_BlueI_B.IC[3] =
          APF_Path_Planning_2023a_BlueI_B.t96;
        APF_Path_Planning_2023a_BlueI_B.IC[4] =
          -APF_Path_Planning_2023a_BlueI_B.t93 -
          APF_Path_Planning_2023a_BlueI_B.t13 *
          APF_Path_Planning_2023a_BlueI_B.t28;
        APF_Path_Planning_2023a_BlueI_B.IC[5] =
          -APF_Path_Planning_2023a_BlueI_B.t93;
        APF_Path_Planning_2023a_BlueI_B.IC[6] = 0.0;
        APF_Path_Planning_2023a_BlueI_B.IC[7] =
          APF_Path_Planning_2023a_BlueI_B.t17;
        APF_Path_Planning_2023a_BlueI_B.IC[8] =
          APF_Path_Planning_2023a_BlueI_B.t33;
        APF_Path_Planning_2023a_BlueI_B.IC[9] =
          (-APF_Path_Planning_2023a_BlueI_B.q -
           APF_Path_Planning_2023a_BlueI_B.t103) -
          APF_Path_Planning_2023a_BlueI_B.t104;
        APF_Path_Planning_2023a_BlueI_B.IC[10] =
          -APF_Path_Planning_2023a_BlueI_B.t104 -
          APF_Path_Planning_2023a_BlueI_B.t24 *
          APF_Path_Planning_2023a_BlueI_B.t28;
        APF_Path_Planning_2023a_BlueI_B.IC[11] =
          -APF_Path_Planning_2023a_BlueI_B.t104;
        APF_Path_Planning_2023a_BlueI_B.IC[12] =
          APF_Path_Planning_2023a_BlueI_B.t30;
        APF_Path_Planning_2023a_BlueI_B.IC[13] =
          APF_Path_Planning_2023a_BlueI_B.t33;
        APF_Path_Planning_2023a_BlueI_B.IC[14] =
          (((((((((((((((((((((((APF_Path_Planning_2023a_BlueI_P.IRED +
          APF_Path_Planning_2023a_BlueI_P.IPROX) +
          APF_Path_Planning_2023a_BlueI_P.IDIST) +
          APF_Path_Planning_2023a_BlueI_P.IEE) +
          APF_Path_Planning_2023a_BlueI_B.absxk) +
                             APF_Path_Planning_2023a_BlueI_B.t51) +
                            APF_Path_Planning_2023a_BlueI_B.t57) +
                           APF_Path_Planning_2023a_BlueI_B.t64) +
                          APF_Path_Planning_2023a_BlueI_B.t65) +
                         APF_Path_Planning_2023a_BlueI_B.t34) +
                        APF_Path_Planning_2023a_BlueI_B.t67) +
                       APF_Path_Planning_2023a_BlueI_B.t68) +
                      APF_Path_Planning_2023a_BlueI_B.t35) +
                     APF_Path_Planning_2023a_BlueI_B.t71) +
                    APF_Path_Planning_2023a_BlueI_B.t72) +
                   APF_Path_Planning_2023a_BlueI_B.t74) +
                  APF_Path_Planning_2023a_BlueI_B.t75) +
                 APF_Path_Planning_2023a_BlueI_B.t76) +
                APF_Path_Planning_2023a_BlueI_B.t37) +
               ((((APF_Path_Planning_2023a_BlueI_B.t99_tmp_h * 2.0 +
                   APF_Path_Planning_2023a_BlueI_B.t99_tmp_b * 2.0) +
                  APF_Path_Planning_2023a_BlueI_B.t99_tmp * 2.0) +
                 APF_Path_Planning_2023a_BlueI_B.t99_tmp_d * 2.0) +
                APF_Path_Planning_2023a_BlueI_B.t99_tmp_l * 2.0) *
               APF_Path_Planning_2023a_BlueI_B.t) +
              APF_Path_Planning_2023a_BlueI_P.mPROX *
              APF_Path_Planning_2023a_BlueI_B.alpha_pol) +
             APF_Path_Planning_2023a_BlueI_P.mDIST *
             APF_Path_Planning_2023a_BlueI_B.alpha_pol) +
            APF_Path_Planning_2023a_BlueI_P.mEE *
            APF_Path_Planning_2023a_BlueI_B.alpha_pol) -
           ((APF_Path_Planning_2023a_BlueI_B.t83 * 2.0 +
             APF_Path_Planning_2023a_BlueI_B.t82 * 2.0) +
            APF_Path_Planning_2023a_BlueI_B.t81_tmp * 2.0) *
           APF_Path_Planning_2023a_BlueI_B.t61) -
          APF_Path_Planning_2023a_BlueI_B.t113_tmp * 2.0;
        APF_Path_Planning_2023a_BlueI_B.IC[15] =
          APF_Path_Planning_2023a_BlueI_B.t99;
        APF_Path_Planning_2023a_BlueI_B.alpha_pol =
          (APF_Path_Planning_2023a_BlueI_B.t114_tmp -
           APF_Path_Planning_2023a_BlueI_B.t112_tmp) -
          APF_Path_Planning_2023a_BlueI_B.t113_tmp;
        APF_Path_Planning_2023a_BlueI_B.IC[16] =
          APF_Path_Planning_2023a_BlueI_B.alpha_pol;
        APF_Path_Planning_2023a_BlueI_B.IC[17] =
          APF_Path_Planning_2023a_BlueI_B.t115_tmp -
          APF_Path_Planning_2023a_BlueI_B.t113_tmp;
        APF_Path_Planning_2023a_BlueI_B.IC[18] =
          (-APF_Path_Planning_2023a_BlueI_B.t7 *
           APF_Path_Planning_2023a_BlueI_B.t8 -
           APF_Path_Planning_2023a_BlueI_B.t91) -
          APF_Path_Planning_2023a_BlueI_B.t93;
        APF_Path_Planning_2023a_BlueI_B.IC[19] =
          (-APF_Path_Planning_2023a_BlueI_B.t8 *
           APF_Path_Planning_2023a_BlueI_B.t23 -
           APF_Path_Planning_2023a_BlueI_B.t103) -
          APF_Path_Planning_2023a_BlueI_B.t104;
        APF_Path_Planning_2023a_BlueI_B.IC[20] =
          APF_Path_Planning_2023a_BlueI_B.t99;
        APF_Path_Planning_2023a_BlueI_B.IC[21] =
          APF_Path_Planning_2023a_BlueI_B.t99_tmp_e;
        APF_Path_Planning_2023a_BlueI_B.IC[22] =
          APF_Path_Planning_2023a_BlueI_B.t114_tmp;
        APF_Path_Planning_2023a_BlueI_B.IC[23] =
          APF_Path_Planning_2023a_BlueI_B.t115_tmp;
        APF_Path_Planning_2023a_BlueI_B.IC[24] =
          -APF_Path_Planning_2023a_BlueI_B.t13 *
          APF_Path_Planning_2023a_BlueI_B.t28 -
          APF_Path_Planning_2023a_BlueI_B.t93;
        APF_Path_Planning_2023a_BlueI_B.IC[25] =
          -APF_Path_Planning_2023a_BlueI_B.t24 *
          APF_Path_Planning_2023a_BlueI_B.t28 -
          APF_Path_Planning_2023a_BlueI_B.t104;
        APF_Path_Planning_2023a_BlueI_B.IC[26] =
          APF_Path_Planning_2023a_BlueI_B.alpha_pol;
        APF_Path_Planning_2023a_BlueI_B.IC[27] =
          APF_Path_Planning_2023a_BlueI_B.t114_tmp;
        APF_Path_Planning_2023a_BlueI_B.IC[28] =
          APF_Path_Planning_2023a_BlueI_B.t114_tmp_tmp;
        APF_Path_Planning_2023a_BlueI_B.IC[29] =
          APF_Path_Planning_2023a_BlueI_B.t116;
        APF_Path_Planning_2023a_BlueI_B.t7 = -APF_Path_Planning_2023a_BlueI_P.a3
          * APF_Path_Planning_2023a_BlueI_P.mEE;
        APF_Path_Planning_2023a_BlueI_B.IC[30] =
          APF_Path_Planning_2023a_BlueI_B.t7 *
          APF_Path_Planning_2023a_BlueI_B.t16;
        APF_Path_Planning_2023a_BlueI_B.IC[31] =
          APF_Path_Planning_2023a_BlueI_B.t7 *
          APF_Path_Planning_2023a_BlueI_B.t25;
        APF_Path_Planning_2023a_BlueI_B.IC[32] =
          (((APF_Path_Planning_2023a_BlueI_P.IEE +
             APF_Path_Planning_2023a_BlueI_B.t35) +
            APF_Path_Planning_2023a_BlueI_B.t56) +
           APF_Path_Planning_2023a_BlueI_B.t50) -
          APF_Path_Planning_2023a_BlueI_P.a3 *
          APF_Path_Planning_2023a_BlueI_P.b0 *
          APF_Path_Planning_2023a_BlueI_P.mEE *
          APF_Path_Planning_2023a_BlueI_B.t63;
        APF_Path_Planning_2023a_BlueI_B.IC[33] =
          APF_Path_Planning_2023a_BlueI_B.t115_tmp;
        APF_Path_Planning_2023a_BlueI_B.IC[34] =
          APF_Path_Planning_2023a_BlueI_B.t116;
        APF_Path_Planning_2023a_BlueI_B.IC[35] =
          APF_Path_Planning_2023a_BlueI_B.t45;

        // MATLAB Function: '<S582>/Coriolis Function1' incorporates:
        //   Delay: '<S582>/Delay'

        APF_Path_Planning_2023a_BlueI_B.alpha_pol =
          (APF_Path_Planning_2023a_BlueI_P.mDIST *
           APF_Path_Planning_2023a_BlueI_B.Switch +
           APF_Path_Planning_2023a_BlueI_B.t21) +
          APF_Path_Planning_2023a_BlueI_P.mEE *
          APF_Path_Planning_2023a_BlueI_B.Switch;
        APF_Path_Planning_2023a_BlueI_B.q = APF_Path_Planning_2023a_BlueI_P.mEE *
          APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp +
          APF_Path_Planning_2023a_BlueI_B.rtb_Sum6_a_tmp;
        APF_Path_Planning_2023a_BlueI_B.t16 =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8] *
          APF_Path_Planning_2023a_BlueI_B.alpha_pol +
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9] *
          APF_Path_Planning_2023a_BlueI_B.alpha_pol;
        APF_Path_Planning_2023a_BlueI_B.t21 = cos
          (APF_Path_Planning_2023a_BlueI_B.t12_tmp + 1.5707963267948966);
        APF_Path_Planning_2023a_BlueI_B.t25 =
          (APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8] *
           APF_Path_Planning_2023a_BlueI_B.q +
           APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9] *
           APF_Path_Planning_2023a_BlueI_B.q) +
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10] *
          APF_Path_Planning_2023a_BlueI_B.q;
        APF_Path_Planning_2023a_BlueI_B.t13 =
          ((APF_Path_Planning_2023a_BlueI_B.link1_com_x *
            APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8] +
            APF_Path_Planning_2023a_BlueI_B.link1_com_x *
            APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9]) +
           APF_Path_Planning_2023a_BlueI_B.link1_com_x *
           APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10]) +
          APF_Path_Planning_2023a_BlueI_B.link1_com_x *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[11];
        APF_Path_Planning_2023a_BlueI_B.alpha_pol = sin
          (APF_Path_Planning_2023a_BlueI_B.t12_tmp + 1.5707963267948966);
        APF_Path_Planning_2023a_BlueI_B.t12_tmp =
          (APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8] +
           APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9]) +
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10];
        APF_Path_Planning_2023a_BlueI_B.t8 =
          APF_Path_Planning_2023a_BlueI_B.t12_tmp +
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[11];
        APF_Path_Planning_2023a_BlueI_B.absxk = cos
          (APF_Path_Planning_2023a_BlueI_B.t54);
        APF_Path_Planning_2023a_BlueI_B.t54 = cos
          (APF_Path_Planning_2023a_BlueI_B.t81);
        APF_Path_Planning_2023a_BlueI_B.t = cos
          (APF_Path_Planning_2023a_BlueI_B.t63_tmp);
        APF_Path_Planning_2023a_BlueI_B.t34 = sin
          (APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[4]);
        APF_Path_Planning_2023a_BlueI_B.t63_tmp =
          ((((APF_Path_Planning_2023a_BlueI_B.t92 *
              APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10] +
              APF_Path_Planning_2023a_BlueI_B.t94 *
              APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10]) +
             APF_Path_Planning_2023a_BlueI_B.t95 *
             APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10]) +
            APF_Path_Planning_2023a_BlueI_B.t97 *
            APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10]) +
           APF_Path_Planning_2023a_BlueI_B.t100 *
           APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10]) +
          APF_Path_Planning_2023a_BlueI_B.rtb_path_idx_1 *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10];
        APF_Path_Planning_2023a_BlueI_B.t35 = sin
          (APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[5]);
        APF_Path_Planning_2023a_BlueI_B.t71 =
          APF_Path_Planning_2023a_BlueI_B.t79 *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[11] +
          APF_Path_Planning_2023a_BlueI_B.t51_tmp *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[11];
        APF_Path_Planning_2023a_BlueI_B.t37 = sin
          (APF_Path_Planning_2023a_BlueI_B.t80);
        APF_Path_Planning_2023a_BlueI_B.t51_tmp =
          ((APF_Path_Planning_2023a_BlueI_B.Sum6_a *
            APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10] +
            APF_Path_Planning_2023a_BlueI_B.Sum6_a *
            APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[11]) +
           APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW *
           APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10]) +
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[11];
        APF_Path_Planning_2023a_BlueI_B.t79 =
          APF_Path_Planning_2023a_BlueI_B.t83 *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];
        APF_Path_Planning_2023a_BlueI_B.t80 =
          APF_Path_Planning_2023a_BlueI_B.t82 *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];
        APF_Path_Planning_2023a_BlueI_B.t81 =
          APF_Path_Planning_2023a_BlueI_B.t81_tmp *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];
        APF_Path_Planning_2023a_BlueI_B.t81_tmp =
          ((((APF_Path_Planning_2023a_BlueI_B.t83 *
              APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9] +
              APF_Path_Planning_2023a_BlueI_B.t83 *
              APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10]) +
             APF_Path_Planning_2023a_BlueI_B.t82 *
             APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9]) +
            APF_Path_Planning_2023a_BlueI_B.t82 *
            APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10]) +
           APF_Path_Planning_2023a_BlueI_B.t81_tmp *
           APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9]) +
          APF_Path_Planning_2023a_BlueI_B.t81_tmp *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10];
        APF_Path_Planning_2023a_BlueI_B.t82 =
          ((APF_Path_Planning_2023a_BlueI_B.t81_tmp +
            APF_Path_Planning_2023a_BlueI_B.t79) +
           APF_Path_Planning_2023a_BlueI_B.t80) +
          APF_Path_Planning_2023a_BlueI_B.t81;
        APF_Path_Planning_2023a_BlueI_B.t83 =
          APF_Path_Planning_2023a_BlueI_B.t113_tmp_tmp *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];
        APF_Path_Planning_2023a_BlueI_B.t113_tmp_tmp =
          (APF_Path_Planning_2023a_BlueI_B.t113_tmp_tmp *
           APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9] +
           APF_Path_Planning_2023a_BlueI_B.t113_tmp_tmp *
           APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10]) +
          APF_Path_Planning_2023a_BlueI_B.t113_tmp_tmp *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[11];
        APF_Path_Planning_2023a_BlueI_B.t56 =
          APF_Path_Planning_2023a_BlueI_B.t99_tmp_h *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];
        APF_Path_Planning_2023a_BlueI_B.t17 =
          APF_Path_Planning_2023a_BlueI_B.t99_tmp_b *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];
        APF_Path_Planning_2023a_BlueI_B.t23 =
          APF_Path_Planning_2023a_BlueI_B.t99_tmp *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];
        APF_Path_Planning_2023a_BlueI_B.t24 =
          APF_Path_Planning_2023a_BlueI_B.t99_tmp_d *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];
        APF_Path_Planning_2023a_BlueI_B.q =
          APF_Path_Planning_2023a_BlueI_B.t99_tmp_l *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];
        APF_Path_Planning_2023a_BlueI_B.t28 =
          APF_Path_Planning_2023a_BlueI_B.t92 *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];
        APF_Path_Planning_2023a_BlueI_B.t91 =
          APF_Path_Planning_2023a_BlueI_B.t94 *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];
        APF_Path_Planning_2023a_BlueI_B.t92 *=
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9];
        APF_Path_Planning_2023a_BlueI_B.t93 =
          APF_Path_Planning_2023a_BlueI_B.t95 *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];
        APF_Path_Planning_2023a_BlueI_B.t94 *=
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9];
        APF_Path_Planning_2023a_BlueI_B.t95 *=
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9];
        APF_Path_Planning_2023a_BlueI_B.t96 =
          APF_Path_Planning_2023a_BlueI_B.t97 *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];
        APF_Path_Planning_2023a_BlueI_B.t97 *=
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9];
        APF_Path_Planning_2023a_BlueI_B.t30 =
          APF_Path_Planning_2023a_BlueI_B.t100 *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];
        APF_Path_Planning_2023a_BlueI_B.t99 =
          APF_Path_Planning_2023a_BlueI_B.t100 *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9];
        APF_Path_Planning_2023a_BlueI_B.t100 =
          APF_Path_Planning_2023a_BlueI_B.rtb_path_idx_1 *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];
        APF_Path_Planning_2023a_BlueI_B.t63 =
          APF_Path_Planning_2023a_BlueI_B.rtb_path_idx_1 *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9];
        APF_Path_Planning_2023a_BlueI_B.t103 =
          APF_Path_Planning_2023a_BlueI_B.Sum6_a *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];
        APF_Path_Planning_2023a_BlueI_B.t104 =
          APF_Path_Planning_2023a_BlueI_B.Sum6_a *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9];
        APF_Path_Planning_2023a_BlueI_B.t33 =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];
        APF_Path_Planning_2023a_BlueI_B.t51 =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9];
        APF_Path_Planning_2023a_BlueI_B.t57 = APF_Path_Planning_2023a_BlueI_B.t *
          APF_Path_Planning_2023a_BlueI_B.t83;
        APF_Path_Planning_2023a_BlueI_B.t61 =
          (((((((((((APF_Path_Planning_2023a_BlueI_B.t28 +
                     APF_Path_Planning_2023a_BlueI_B.t91) +
                    APF_Path_Planning_2023a_BlueI_B.t92) +
                   APF_Path_Planning_2023a_BlueI_B.t93) +
                  APF_Path_Planning_2023a_BlueI_B.t94) +
                 APF_Path_Planning_2023a_BlueI_B.t95) +
                APF_Path_Planning_2023a_BlueI_B.t96) +
               APF_Path_Planning_2023a_BlueI_B.t97) +
              APF_Path_Planning_2023a_BlueI_B.t30) +
             APF_Path_Planning_2023a_BlueI_B.t99) +
            APF_Path_Planning_2023a_BlueI_B.t100) +
           APF_Path_Planning_2023a_BlueI_B.t63) *
          APF_Path_Planning_2023a_BlueI_B.t34;
        APF_Path_Planning_2023a_BlueI_B.t64 =
          (((APF_Path_Planning_2023a_BlueI_B.t103 +
             APF_Path_Planning_2023a_BlueI_B.t104) +
            APF_Path_Planning_2023a_BlueI_B.t33) +
           APF_Path_Planning_2023a_BlueI_B.t51) *
          APF_Path_Planning_2023a_BlueI_B.t37;
        APF_Path_Planning_2023a_BlueI_B.t65 =
          (((((APF_Path_Planning_2023a_BlueI_P.a2 *
               APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8] +
               APF_Path_Planning_2023a_BlueI_P.a2 *
               APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9]) +
              APF_Path_Planning_2023a_BlueI_P.a2 *
              APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10]) +
             APF_Path_Planning_2023a_BlueI_P.b2 *
             APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8]) +
            APF_Path_Planning_2023a_BlueI_P.b2 *
            APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9]) +
           APF_Path_Planning_2023a_BlueI_P.b2 *
           APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10]) *
          (APF_Path_Planning_2023a_BlueI_B.link1_com_x *
           APF_Path_Planning_2023a_BlueI_B.t35);
        APF_Path_Planning_2023a_BlueI_B.t67 =
          (((APF_Path_Planning_2023a_BlueI_P.a1 *
             APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8] +
             APF_Path_Planning_2023a_BlueI_P.a1 *
             APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9]) +
            APF_Path_Planning_2023a_BlueI_P.b1 *
            APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8]) +
           APF_Path_Planning_2023a_BlueI_P.b1 *
           APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9]) *
          (APF_Path_Planning_2023a_BlueI_B.link1_com_x *
           APF_Path_Planning_2023a_BlueI_B.t37);

        // MATLAB Function: '<S582>/Dynamics Model'
        APF_Path_Planning_2023a_BlueI_B.rEQ0 = true;
        for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
             APF_Path_Planning_2023a_BlueI_B.i_o < 36;
             APF_Path_Planning_2023a_BlueI_B.i_o++) {
          APF_Path_Planning_2023a_BlueI_B.sigma[APF_Path_Planning_2023a_BlueI_B.i_o]
            = 0.0;
          if (APF_Path_Planning_2023a_BlueI_B.rEQ0) {
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
              APF_Path_Planning_2023a_BlueI_B.IC[APF_Path_Planning_2023a_BlueI_B.i_o];
            if (rtIsInf(APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW) || rtIsNaN
                (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW)) {
              APF_Path_Planning_2023a_BlueI_B.rEQ0 = false;
            }
          }
        }

        if (!APF_Path_Planning_2023a_BlueI_B.rEQ0) {
          for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
               APF_Path_Planning_2023a_BlueI_B.i_o < 36;
               APF_Path_Planning_2023a_BlueI_B.i_o++) {
            APF_Path_Planning_2023a_BlueI_B.sigma[APF_Path_Planning_2023a_BlueI_B.i_o]
              = (rtNaN);
          }
        } else {
          APF_Path_Planning_2023a_Blu_svd(APF_Path_Planning_2023a_BlueI_B.IC,
            APF_Path_Planning_2023a_BlueI_B.U,
            APF_Path_Planning_2023a_BlueI_B.fill,
            APF_Path_Planning_2023a_BlueI_B.V);
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = fabs
            (APF_Path_Planning_2023a_BlueI_B.fill[0]);
          if (rtIsInf(APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW) || rtIsNaN
              (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW)) {
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = (rtNaN);
          } else if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW <
                     4.4501477170144028E-308) {
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 4.94065645841247E-324;
          } else {
            frexp(APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW,
                  &APF_Path_Planning_2023a_BlueI_B.r_p);
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = ldexp(1.0,
              APF_Path_Planning_2023a_BlueI_B.r_p - 53);
          }

          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW *= 6.0;
          APF_Path_Planning_2023a_BlueI_B.r_p = -1;
          APF_Path_Planning_2023a_BlueI_B.i_o = 0;
          while ((APF_Path_Planning_2023a_BlueI_B.i_o < 6) &&
                 (APF_Path_Planning_2023a_BlueI_B.fill[APF_Path_Planning_2023a_BlueI_B.i_o]
                  > APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW)) {
            APF_Path_Planning_2023a_BlueI_B.r_p++;
            APF_Path_Planning_2023a_BlueI_B.i_o++;
          }

          if (APF_Path_Planning_2023a_BlueI_B.r_p + 1 > 0) {
            APF_Path_Planning_2023a_BlueI_B.xoffset = 1;
            for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset <=
                 APF_Path_Planning_2023a_BlueI_B.r_p;
                 APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
              APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 1.0 /
                APF_Path_Planning_2023a_BlueI_B.fill[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
              for (APF_Path_Planning_2023a_BlueI_B.i_o =
                   APF_Path_Planning_2023a_BlueI_B.xoffset;
                   APF_Path_Planning_2023a_BlueI_B.i_o <=
                   APF_Path_Planning_2023a_BlueI_B.xoffset + 5;
                   APF_Path_Planning_2023a_BlueI_B.i_o++) {
                APF_Path_Planning_2023a_BlueI_B.V[APF_Path_Planning_2023a_BlueI_B.i_o
                  - 1] *= APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
              }

              APF_Path_Planning_2023a_BlueI_B.xoffset += 6;
            }

            for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
                 APF_Path_Planning_2023a_BlueI_B.i_o <= 30;
                 APF_Path_Planning_2023a_BlueI_B.i_o += 6) {
              for (APF_Path_Planning_2023a_BlueI_B.b_xoffset =
                   APF_Path_Planning_2023a_BlueI_B.i_o + 1;
                   APF_Path_Planning_2023a_BlueI_B.b_xoffset <=
                   APF_Path_Planning_2023a_BlueI_B.i_o + 6;
                   APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
                APF_Path_Planning_2023a_BlueI_B.sigma[APF_Path_Planning_2023a_BlueI_B.b_xoffset
                  - 1] = 0.0;
              }
            }

            APF_Path_Planning_2023a_BlueI_B.i = 0;
            for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
                 APF_Path_Planning_2023a_BlueI_B.i_o <= 30;
                 APF_Path_Planning_2023a_BlueI_B.i_o += 6) {
              APF_Path_Planning_2023a_BlueI_B.ar = -1;
              APF_Path_Planning_2023a_BlueI_B.i++;
              APF_Path_Planning_2023a_BlueI_B.sigma_tmp = 6 *
                APF_Path_Planning_2023a_BlueI_B.r_p +
                APF_Path_Planning_2023a_BlueI_B.i;
              for (APF_Path_Planning_2023a_BlueI_B.b_xoffset =
                   APF_Path_Planning_2023a_BlueI_B.i;
                   APF_Path_Planning_2023a_BlueI_B.b_xoffset <=
                   APF_Path_Planning_2023a_BlueI_B.sigma_tmp;
                   APF_Path_Planning_2023a_BlueI_B.b_xoffset += 6) {
                for (APF_Path_Planning_2023a_BlueI_B.xoffset =
                     APF_Path_Planning_2023a_BlueI_B.i_o + 1;
                     APF_Path_Planning_2023a_BlueI_B.xoffset <=
                     APF_Path_Planning_2023a_BlueI_B.i_o + 6;
                     APF_Path_Planning_2023a_BlueI_B.xoffset++) {
                  APF_Path_Planning_2023a_BlueI_B.sigma[APF_Path_Planning_2023a_BlueI_B.xoffset
                    - 1] += APF_Path_Planning_2023a_BlueI_B.V
                    [(APF_Path_Planning_2023a_BlueI_B.ar +
                      APF_Path_Planning_2023a_BlueI_B.xoffset) -
                    APF_Path_Planning_2023a_BlueI_B.i_o] *
                    APF_Path_Planning_2023a_BlueI_B.U[APF_Path_Planning_2023a_BlueI_B.b_xoffset
                    - 1];
                }

                APF_Path_Planning_2023a_BlueI_B.ar += 6;
              }
            }
          }
        }

        // MATLAB Function: '<S582>/Coriolis Function1' incorporates:
        //   Delay: '<S582>/Delay'

        memset(&APF_Path_Planning_2023a_BlueI_B.IC[0], 0, 12U * sizeof(real_T));
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = cos
          (APF_Path_Planning_2023a_BlueI_B.link1_com_y + 1.5707963267948966) *
          APF_Path_Planning_2023a_BlueI_B.t13;
        APF_Path_Planning_2023a_BlueI_B.Sum6_a = (-cos
          (APF_Path_Planning_2023a_BlueI_B.absx_tmp + 1.5707963267948966) *
          APF_Path_Planning_2023a_BlueI_B.t16 -
          APF_Path_Planning_2023a_BlueI_B.t21 *
          APF_Path_Planning_2023a_BlueI_B.t25) -
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
        APF_Path_Planning_2023a_BlueI_B.Derivative2 *=
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];
        APF_Path_Planning_2023a_BlueI_B.IC[12] =
          APF_Path_Planning_2023a_BlueI_B.Sum6_a -
          APF_Path_Planning_2023a_BlueI_B.Derivative2 * cos
          (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
        APF_Path_Planning_2023a_BlueI_B.rtb_path_idx_1 = sin
          (APF_Path_Planning_2023a_BlueI_B.link1_com_y + 1.5707963267948966) *
          APF_Path_Planning_2023a_BlueI_B.t13;
        APF_Path_Planning_2023a_BlueI_B.absx_tmp = (sin
          (APF_Path_Planning_2023a_BlueI_B.absx_tmp + 1.5707963267948966) *
          -APF_Path_Planning_2023a_BlueI_B.t16 -
          APF_Path_Planning_2023a_BlueI_B.t25 *
          APF_Path_Planning_2023a_BlueI_B.alpha_pol) -
          APF_Path_Planning_2023a_BlueI_B.rtb_path_idx_1;
        APF_Path_Planning_2023a_BlueI_B.IC[13] =
          APF_Path_Planning_2023a_BlueI_B.absx_tmp -
          APF_Path_Planning_2023a_BlueI_B.Derivative2 * sin
          (APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
        APF_Path_Planning_2023a_BlueI_B.Derivative2 =
          APF_Path_Planning_2023a_BlueI_B.t35 *
          APF_Path_Planning_2023a_BlueI_B.t71;
        APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 =
          APF_Path_Planning_2023a_BlueI_B.t37 *
          APF_Path_Planning_2023a_BlueI_B.t51_tmp;
        APF_Path_Planning_2023a_BlueI_B.t16 =
          -APF_Path_Planning_2023a_BlueI_B.t34 *
          APF_Path_Planning_2023a_BlueI_B.t63_tmp;
        APF_Path_Planning_2023a_BlueI_B.t99_tmp =
          (((APF_Path_Planning_2023a_BlueI_B.t99_tmp_h *
             APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9] +
             APF_Path_Planning_2023a_BlueI_B.t99_tmp_b *
             APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9]) +
            APF_Path_Planning_2023a_BlueI_B.t99_tmp *
            APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9]) +
           APF_Path_Planning_2023a_BlueI_B.t99_tmp_d *
           APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9]) +
          APF_Path_Planning_2023a_BlueI_B.t99_tmp_l *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9];
        APF_Path_Planning_2023a_BlueI_B.t99_tmp_l =
          (APF_Path_Planning_2023a_BlueI_B.t16 -
           APF_Path_Planning_2023a_BlueI_B.Derivative2) -
          APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1;
        APF_Path_Planning_2023a_BlueI_B.IC[14] =
          ((APF_Path_Planning_2023a_BlueI_B.t99_tmp_l -
            APF_Path_Planning_2023a_BlueI_B.t99_tmp *
            APF_Path_Planning_2023a_BlueI_B.absxk) -
           APF_Path_Planning_2023a_BlueI_B.t113_tmp_tmp *
           APF_Path_Planning_2023a_BlueI_B.t) -
          APF_Path_Planning_2023a_BlueI_B.t81_tmp *
          APF_Path_Planning_2023a_BlueI_B.t54;
        APF_Path_Planning_2023a_BlueI_B.t99_tmp_h =
          ((APF_Path_Planning_2023a_BlueI_B.t79 +
            APF_Path_Planning_2023a_BlueI_B.t80) +
           APF_Path_Planning_2023a_BlueI_B.t81) *
          APF_Path_Planning_2023a_BlueI_B.t54 +
          APF_Path_Planning_2023a_BlueI_B.t57;
        APF_Path_Planning_2023a_BlueI_B.IC[15] =
          ((((APF_Path_Planning_2023a_BlueI_B.t56 +
              APF_Path_Planning_2023a_BlueI_B.t17) +
             APF_Path_Planning_2023a_BlueI_B.t23) +
            APF_Path_Planning_2023a_BlueI_B.t24) +
           APF_Path_Planning_2023a_BlueI_B.q) *
          APF_Path_Planning_2023a_BlueI_B.absxk +
          (((APF_Path_Planning_2023a_BlueI_B.t99_tmp_h -
             APF_Path_Planning_2023a_BlueI_B.t34 *
             APF_Path_Planning_2023a_BlueI_B.t63_tmp) -
            APF_Path_Planning_2023a_BlueI_B.Derivative2) -
           APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1);
        APF_Path_Planning_2023a_BlueI_B.IC[16] =
          ((APF_Path_Planning_2023a_BlueI_B.t99_tmp_h +
            APF_Path_Planning_2023a_BlueI_B.t61) +
           APF_Path_Planning_2023a_BlueI_B.t64) -
          APF_Path_Planning_2023a_BlueI_B.Derivative2;
        APF_Path_Planning_2023a_BlueI_B.IC[17] =
          (APF_Path_Planning_2023a_BlueI_B.t57 +
           APF_Path_Planning_2023a_BlueI_B.t65) +
          APF_Path_Planning_2023a_BlueI_B.t67;
        APF_Path_Planning_2023a_BlueI_B.IC[18] =
          APF_Path_Planning_2023a_BlueI_B.Sum6_a;
        APF_Path_Planning_2023a_BlueI_B.IC[19] =
          APF_Path_Planning_2023a_BlueI_B.absx_tmp;
        APF_Path_Planning_2023a_BlueI_B.Sum6_a =
          (APF_Path_Planning_2023a_BlueI_B.t113_tmp_tmp +
           APF_Path_Planning_2023a_BlueI_B.t83) *
          APF_Path_Planning_2023a_BlueI_B.t;
        APF_Path_Planning_2023a_BlueI_B.IC[20] =
          ((((APF_Path_Planning_2023a_BlueI_B.t16 -
              APF_Path_Planning_2023a_BlueI_B.t54 *
              APF_Path_Planning_2023a_BlueI_B.t82) -
             APF_Path_Planning_2023a_BlueI_B.Derivative2) -
            APF_Path_Planning_2023a_BlueI_B.Sum6_a) -
           APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1) -
          (((((APF_Path_Planning_2023a_BlueI_B.t99_tmp +
               APF_Path_Planning_2023a_BlueI_B.t56) +
              APF_Path_Planning_2023a_BlueI_B.t17) +
             APF_Path_Planning_2023a_BlueI_B.t23) +
            APF_Path_Planning_2023a_BlueI_B.t24) +
           APF_Path_Planning_2023a_BlueI_B.q) *
          APF_Path_Planning_2023a_BlueI_B.absxk;
        APF_Path_Planning_2023a_BlueI_B.IC[21] =
          APF_Path_Planning_2023a_BlueI_B.t99_tmp_l;
        APF_Path_Planning_2023a_BlueI_B.IC[22] =
          (APF_Path_Planning_2023a_BlueI_B.t61 +
           APF_Path_Planning_2023a_BlueI_B.t64) -
          APF_Path_Planning_2023a_BlueI_B.Derivative2;
        APF_Path_Planning_2023a_BlueI_B.IC[23] =
          APF_Path_Planning_2023a_BlueI_B.t65 +
          APF_Path_Planning_2023a_BlueI_B.t67;
        APF_Path_Planning_2023a_BlueI_B.IC[24] =
          -APF_Path_Planning_2023a_BlueI_B.t21 *
          APF_Path_Planning_2023a_BlueI_B.t25 -
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
        APF_Path_Planning_2023a_BlueI_B.IC[25] =
          -APF_Path_Planning_2023a_BlueI_B.t25 *
          APF_Path_Planning_2023a_BlueI_B.alpha_pol -
          APF_Path_Planning_2023a_BlueI_B.rtb_path_idx_1;
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          ((((((((((((APF_Path_Planning_2023a_BlueI_B.t63_tmp +
                      APF_Path_Planning_2023a_BlueI_B.t28) +
                     APF_Path_Planning_2023a_BlueI_B.t91) +
                    APF_Path_Planning_2023a_BlueI_B.t92) +
                   APF_Path_Planning_2023a_BlueI_B.t93) +
                  APF_Path_Planning_2023a_BlueI_B.t94) +
                 APF_Path_Planning_2023a_BlueI_B.t95) +
                APF_Path_Planning_2023a_BlueI_B.t96) +
               APF_Path_Planning_2023a_BlueI_B.t97) +
              APF_Path_Planning_2023a_BlueI_B.t30) +
             APF_Path_Planning_2023a_BlueI_B.t99) +
            APF_Path_Planning_2023a_BlueI_B.t100) +
           APF_Path_Planning_2023a_BlueI_B.t63) *
          APF_Path_Planning_2023a_BlueI_B.t34;
        APF_Path_Planning_2023a_BlueI_B.rtb_path_idx_1 =
          ((((APF_Path_Planning_2023a_BlueI_B.t51_tmp +
              APF_Path_Planning_2023a_BlueI_B.t103) +
             APF_Path_Planning_2023a_BlueI_B.t104) +
            APF_Path_Planning_2023a_BlueI_B.t33) +
           APF_Path_Planning_2023a_BlueI_B.t51) *
          APF_Path_Planning_2023a_BlueI_B.t37;
        APF_Path_Planning_2023a_BlueI_B.IC[26] =
          (((-APF_Path_Planning_2023a_BlueI_B.t54 *
             APF_Path_Planning_2023a_BlueI_B.t82 -
             APF_Path_Planning_2023a_BlueI_B.Derivative2) -
            APF_Path_Planning_2023a_BlueI_B.Sum6_a) -
           APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW) -
          APF_Path_Planning_2023a_BlueI_B.rtb_path_idx_1;
        APF_Path_Planning_2023a_BlueI_B.IC[27] =
          (-APF_Path_Planning_2023a_BlueI_B.t35 *
           APF_Path_Planning_2023a_BlueI_B.t71 -
           APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW) -
          APF_Path_Planning_2023a_BlueI_B.rtb_path_idx_1;
        APF_Path_Planning_2023a_BlueI_B.IC[28] =
          APF_Path_Planning_2023a_BlueI_B.t7 *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[11] *
          APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp *
          APF_Path_Planning_2023a_BlueI_B.t35;
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_B.link1_com_x *
          APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
        APF_Path_Planning_2023a_BlueI_B.IC[29] =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW *
          APF_Path_Planning_2023a_BlueI_B.t35 *
          APF_Path_Planning_2023a_BlueI_B.t12_tmp;
        APF_Path_Planning_2023a_BlueI_B.IC[30] =
          APF_Path_Planning_2023a_BlueI_B.link1_com_x *
          APF_Path_Planning_2023a_BlueI_B.t8 * sin
          (APF_Path_Planning_2023a_BlueI_B.link1_com_y);
        APF_Path_Planning_2023a_BlueI_B.IC[31] =
          APF_Path_Planning_2023a_BlueI_B.t7 *
          APF_Path_Planning_2023a_BlueI_B.t8 * cos
          (APF_Path_Planning_2023a_BlueI_B.link1_com_y);
        APF_Path_Planning_2023a_BlueI_B.Sum6_a =
          APF_Path_Planning_2023a_BlueI_B.link1_com_x *
          APF_Path_Planning_2023a_BlueI_B.Switch *
          APF_Path_Planning_2023a_BlueI_B.t8 *
          APF_Path_Planning_2023a_BlueI_B.t37;
        APF_Path_Planning_2023a_BlueI_B.IC[32] =
          (-APF_Path_Planning_2023a_BlueI_P.a3 *
           APF_Path_Planning_2023a_BlueI_P.b0 *
           APF_Path_Planning_2023a_BlueI_P.mEE *
           APF_Path_Planning_2023a_BlueI_B.t8 *
           APF_Path_Planning_2023a_BlueI_B.t -
           APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW *
           APF_Path_Planning_2023a_BlueI_B.t8 *
           APF_Path_Planning_2023a_BlueI_B.t35) -
          APF_Path_Planning_2023a_BlueI_B.Sum6_a;
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_B.t7 *
          APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp *
          APF_Path_Planning_2023a_BlueI_B.t8 *
          APF_Path_Planning_2023a_BlueI_B.t35;
        APF_Path_Planning_2023a_BlueI_B.IC[33] =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW -
          APF_Path_Planning_2023a_BlueI_B.Sum6_a;
        APF_Path_Planning_2023a_BlueI_B.IC[34] =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
        APF_Path_Planning_2023a_BlueI_B.IC[35] = 0.0;

        // SignalConversion generated from: '<S584>/ SFunction ' incorporates:
        //   DataStoreRead: '<S582>/RED_Fx_Sat1'
        //   DataStoreRead: '<S582>/RED_Fy_Sat1'
        //   DataStoreRead: '<S582>/RED_Tz_Sat1'
        //   DataStoreRead: '<S582>/RED_Tz_Sat2'
        //   DataStoreRead: '<S582>/RED_Tz_Sat3'
        //   DataStoreRead: '<S582>/RED_Tz_Sat4'
        //   MATLAB Function: '<S582>/Dynamics Model'

        APF_Path_Planning_2023a_BlueI_B.IC1[0] =
          APF_Path_Planning_2023a_Blue_DW.RED_Fx_Sat;
        APF_Path_Planning_2023a_BlueI_B.IC1[1] =
          APF_Path_Planning_2023a_Blue_DW.RED_Fy_Sat;
        APF_Path_Planning_2023a_BlueI_B.IC1[2] =
          APF_Path_Planning_2023a_Blue_DW.RED_Tz_Sat;
        APF_Path_Planning_2023a_BlueI_B.IC1[3] =
          APF_Path_Planning_2023a_Blue_DW.RED_Shoulder_Command;
        APF_Path_Planning_2023a_BlueI_B.IC1[4] =
          APF_Path_Planning_2023a_Blue_DW.RED_Elbow_Command;
        APF_Path_Planning_2023a_BlueI_B.IC1[5] =
          APF_Path_Planning_2023a_Blue_DW.RED_Wrist_Command;

        // MATLAB Function: '<S582>/Dynamics Model' incorporates:
        //   Delay: '<S582>/Delay'

        APF_Path_Planning_2023a_BlueI_B.fill[0] = 0.0;
        APF_Path_Planning_2023a_BlueI_B.fill[1] = 0.0;
        APF_Path_Planning_2023a_BlueI_B.fill[2] = 0.0;
        APF_Path_Planning_2023a_BlueI_B.fill[3] = ((tanh
          (APF_Path_Planning_2023a_BlueI_P.Gamma2_sh *
           APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9]) - tanh
          (APF_Path_Planning_2023a_BlueI_P.Gamma3_sh *
           APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9])) *
          APF_Path_Planning_2023a_BlueI_P.Gamma1_sh + tanh
          (APF_Path_Planning_2023a_BlueI_P.Gamma5_sh *
           APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9]) *
          APF_Path_Planning_2023a_BlueI_P.Gamma4_sh) +
          APF_Path_Planning_2023a_BlueI_P.Gamma6_sh *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9];
        APF_Path_Planning_2023a_BlueI_B.fill[4] = ((tanh
          (APF_Path_Planning_2023a_BlueI_P.Gamma2_el *
           APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10]) - tanh
          (APF_Path_Planning_2023a_BlueI_P.Gamma3_el *
           APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10])) *
          APF_Path_Planning_2023a_BlueI_P.Gamma1_el + tanh
          (APF_Path_Planning_2023a_BlueI_P.Gamma5_el *
           APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10]) *
          APF_Path_Planning_2023a_BlueI_P.Gamma4_el) +
          APF_Path_Planning_2023a_BlueI_P.Gamma6_el *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10];
        APF_Path_Planning_2023a_BlueI_B.fill[5] = ((tanh
          (APF_Path_Planning_2023a_BlueI_P.Gamma2_wr *
           APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[11]) - tanh
          (APF_Path_Planning_2023a_BlueI_P.Gamma3_wr *
           APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[11])) *
          APF_Path_Planning_2023a_BlueI_P.Gamma1_wr + tanh
          (APF_Path_Planning_2023a_BlueI_P.Gamma5_wr *
           APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[11]) *
          APF_Path_Planning_2023a_BlueI_P.Gamma4_wr) +
          APF_Path_Planning_2023a_BlueI_P.Gamma6_wr *
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[11];
        for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
             APF_Path_Planning_2023a_BlueI_B.i_o < 6;
             APF_Path_Planning_2023a_BlueI_B.i_o++) {
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.b_xoffset < 6;
               APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +=
              APF_Path_Planning_2023a_BlueI_B.IC[6 *
              APF_Path_Planning_2023a_BlueI_B.b_xoffset +
              APF_Path_Planning_2023a_BlueI_B.i_o] *
              APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[APF_Path_Planning_2023a_BlueI_B.b_xoffset
              + 6];
          }

          APF_Path_Planning_2023a_BlueI_B.state_red[APF_Path_Planning_2023a_BlueI_B.i_o]
            =
            (APF_Path_Planning_2023a_BlueI_B.IC1[APF_Path_Planning_2023a_BlueI_B.i_o]
             - APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW) -
            APF_Path_Planning_2023a_BlueI_B.fill[APF_Path_Planning_2023a_BlueI_B.i_o];
        }

        for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
             APF_Path_Planning_2023a_BlueI_B.i_o < 6;
             APF_Path_Planning_2023a_BlueI_B.i_o++) {
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.b_xoffset < 6;
               APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +=
              APF_Path_Planning_2023a_BlueI_B.sigma[6 *
              APF_Path_Planning_2023a_BlueI_B.b_xoffset +
              APF_Path_Planning_2023a_BlueI_B.i_o] *
              APF_Path_Planning_2023a_BlueI_B.state_red[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
          }

          // DiscreteIntegrator: '<S582>/Acceleration  to Velocity'
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[APF_Path_Planning_2023a_BlueI_B.i_o]
            =
            APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[APF_Path_Planning_2023a_BlueI_B.i_o
            + 6] *
            APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_gainval +
            APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_f[APF_Path_Planning_2023a_BlueI_B.i_o];
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[APF_Path_Planning_2023a_BlueI_B.i_o
            + 6] =
            APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_f[APF_Path_Planning_2023a_BlueI_B.i_o
            + 6] +
            APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_gainval *
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
        }

        // DataStoreWrite: '<S582>/Data Store Write' incorporates:
        //   Delay: '<S582>/Delay'

        APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[3];

        // DataStoreWrite: '<S582>/Data Store Write1' incorporates:
        //   Delay: '<S582>/Delay'

        APF_Path_Planning_2023a_Blue_DW.RED_Rz_Elbow =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[4];

        // DataStoreWrite: '<S582>/Data Store Write2' incorporates:
        //   Delay: '<S582>/Delay'

        APF_Path_Planning_2023a_Blue_DW.RED_Rz_Wrist =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[5];

        // DataStoreWrite: '<S582>/Data Store Write6' incorporates:
        //   Delay: '<S582>/Delay'

        APF_Path_Planning_2023a_Blue_DW.RED_RzD_Shoulder =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[9];

        // DataStoreWrite: '<S582>/Data Store Write7' incorporates:
        //   Delay: '<S582>/Delay'

        APF_Path_Planning_2023a_Blue_DW.RED_RzD_Elbow =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[10];

        // DataStoreWrite: '<S582>/Data Store Write8' incorporates:
        //   Delay: '<S582>/Delay'

        APF_Path_Planning_2023a_Blue_DW.RED_RzD_Wrist =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[11];

        // Delay: '<S587>/Delay1' incorporates:
        //   Delay: '<S582>/Delay'

        if (APF_Path_Planning_2023a_Blue_DW.icLoad_bs) {
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_by =
            APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[6];
        }

        // Sum: '<S587>/Sum6' incorporates:
        //   Delay: '<S582>/Delay'
        //   Delay: '<S587>/Delay1'

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[6] -
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_by;

        // If: '<S587>/if we went through a "step"'
        if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S587>/Hold this value' incorporates:
          //   ActionPort: '<S590>/Action Port'

          // SignalConversion generated from: '<S590>/In1'
          APF_Path_Planning_2023a_BlueI_B.In1_pj =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S587>/Hold this value'
        }

        // End of If: '<S587>/if we went through a "step"'

        // Sum: '<S582>/Sum2' incorporates:
        //   DataStoreWrite: '<S582>/RED_IMU_Ay1'
        //   Gain: '<S587>/divide by delta T'
        //   RandomNumber: '<S582>/Random Number2'

        APF_Path_Planning_2023a_Blue_DW.RED_Ax = 1.0 /
          APF_Path_Planning_2023a_BlueI_P.baseRate *
          APF_Path_Planning_2023a_BlueI_B.In1_pj +
          APF_Path_Planning_2023a_Blue_DW.NextOutput_f;

        // Delay: '<S586>/Delay1' incorporates:
        //   Delay: '<S582>/Delay'

        if (APF_Path_Planning_2023a_Blue_DW.icLoad_n5) {
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_ny =
            APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[7];
        }

        // Sum: '<S586>/Sum6' incorporates:
        //   Delay: '<S582>/Delay'
        //   Delay: '<S586>/Delay1'

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[7] -
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_ny;

        // If: '<S586>/if we went through a "step"'
        if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S586>/Hold this value' incorporates:
          //   ActionPort: '<S589>/Action Port'

          // SignalConversion generated from: '<S589>/In1'
          APF_Path_Planning_2023a_BlueI_B.In1_a4 =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S586>/Hold this value'
        }

        // End of If: '<S586>/if we went through a "step"'

        // Sum: '<S582>/Sum3' incorporates:
        //   DataStoreWrite: '<S582>/RED_IMU_Ay_I1'
        //   Gain: '<S586>/divide by delta T'
        //   RandomNumber: '<S582>/Random Number1'

        APF_Path_Planning_2023a_Blue_DW.RED_Ay = 1.0 /
          APF_Path_Planning_2023a_BlueI_P.baseRate *
          APF_Path_Planning_2023a_BlueI_B.In1_a4 +
          APF_Path_Planning_2023a_Blue_DW.NextOutput_h;

        // Delay: '<S588>/Delay1' incorporates:
        //   Delay: '<S582>/Delay'

        if (APF_Path_Planning_2023a_Blue_DW.icLoad_mj) {
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_nb =
            APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];
        }

        // Sum: '<S588>/Sum6' incorporates:
        //   Delay: '<S582>/Delay'
        //   Delay: '<S588>/Delay1'

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8] -
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_nb;

        // If: '<S588>/if we went through a "step"'
        if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S588>/Hold this value' incorporates:
          //   ActionPort: '<S591>/Action Port'

          // SignalConversion generated from: '<S591>/In1'
          APF_Path_Planning_2023a_BlueI_B.In1_hq =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S588>/Hold this value'
        }

        // End of If: '<S588>/if we went through a "step"'

        // Sum: '<S582>/Sum4' incorporates:
        //   DataStoreWrite: '<S582>/RED_IMU_R1'
        //   Gain: '<S588>/divide by delta T'
        //   RandomNumber: '<S582>/Random Number3'

        APF_Path_Planning_2023a_Blue_DW.RED_RzDD = 1.0 /
          APF_Path_Planning_2023a_BlueI_P.baseRate *
          APF_Path_Planning_2023a_BlueI_B.In1_hq +
          APF_Path_Planning_2023a_Blue_DW.NextOutput_go;

        // DataStoreWrite: '<S582>/RED_Px1' incorporates:
        //   Delay: '<S582>/Delay'

        APF_Path_Planning_2023a_Blue_DW.RED_Px =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[0];

        // DataStoreWrite: '<S582>/RED_Py1' incorporates:
        //   Delay: '<S582>/Delay'

        APF_Path_Planning_2023a_Blue_DW.RED_Py =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[1];

        // DataStoreWrite: '<S582>/RED_Rz1' incorporates:
        //   Delay: '<S582>/Delay'

        APF_Path_Planning_2023a_Blue_DW.RED_Rz =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[2];

        // DataStoreWrite: '<S582>/RED_RzD1' incorporates:
        //   Delay: '<S582>/Delay'

        APF_Path_Planning_2023a_Blue_DW.RED_RzD =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];

        // DataStoreWrite: '<S582>/RED_Vx1' incorporates:
        //   Delay: '<S582>/Delay'

        APF_Path_Planning_2023a_Blue_DW.RED_Vx =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[6];

        // DataStoreWrite: '<S582>/RED_Vy1' incorporates:
        //   Delay: '<S582>/Delay'

        APF_Path_Planning_2023a_Blue_DW.RED_Vy =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[7];

        // Update for DiscreteIntegrator: '<S582>/Acceleration  to Velocity' incorporates:
        //   Delay: '<S582>/Delay'

        memcpy(&APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_f
               [0], &APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[0], 12U *
               sizeof(real_T));

        // Update for Delay: '<S587>/Delay1' incorporates:
        //   Delay: '<S582>/Delay'

        APF_Path_Planning_2023a_Blue_DW.icLoad_bs = false;
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_by =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[6];

        // Update for RandomNumber: '<S582>/Random Number2'
        APF_Path_Planning_2023a_Blue_DW.NextOutput_f =
          APF__rt_nrand_Upu32_Yd_f_pw_snf
          (&APF_Path_Planning_2023a_Blue_DW.RandSeed_av) *
          APF_Path_Planning_2023a_BlueI_P.RandomNumber2_StdDev +
          APF_Path_Planning_2023a_BlueI_P.RandomNumber2_Mean;

        // Update for Delay: '<S586>/Delay1' incorporates:
        //   Delay: '<S582>/Delay'

        APF_Path_Planning_2023a_Blue_DW.icLoad_n5 = false;
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_ny =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[7];

        // Update for RandomNumber: '<S582>/Random Number1'
        APF_Path_Planning_2023a_Blue_DW.NextOutput_h =
          APF__rt_nrand_Upu32_Yd_f_pw_snf
          (&APF_Path_Planning_2023a_Blue_DW.RandSeed_a4) *
          APF_Path_Planning_2023a_BlueI_P.RandomNumber1_StdDev +
          APF_Path_Planning_2023a_BlueI_P.RandomNumber1_Mean;

        // Update for Delay: '<S588>/Delay1' incorporates:
        //   Delay: '<S582>/Delay'

        APF_Path_Planning_2023a_Blue_DW.icLoad_mj = false;
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_nb =
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[8];

        // Update for RandomNumber: '<S582>/Random Number3'
        APF_Path_Planning_2023a_Blue_DW.NextOutput_go =
          APF__rt_nrand_Upu32_Yd_f_pw_snf
          (&APF_Path_Planning_2023a_Blue_DW.RandSeed_i) *
          APF_Path_Planning_2023a_BlueI_P.RandomNumber3_StdDev +
          APF_Path_Planning_2023a_BlueI_P.RandomNumber3_Mean;

        // End of Outputs for SubSystem: '<S551>/RED + ARM'
      } else {
        // Outputs for IfAction SubSystem: '<S551>/RED Only' incorporates:
        //   ActionPort: '<S581>/Action Port'

        // DiscreteIntegrator: '<S593>/Acceleration  to Velocity' incorporates:
        //   DataStoreRead: '<S592>/RED_Fx_Sat'
        //   MATLAB Function: '<S593>/MATLAB Function'
        //   SignalConversion generated from: '<S600>/ SFunction '

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_Blue_DW.RED_Fx_Sat /
          APF_Path_Planning_2023a_BlueI_P.mRED *
          APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_gainva_g +
          APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_b[0];
        APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_b[0] =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

        // DiscreteIntegrator: '<S593>/Velocity to Position'
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_P.VelocitytoPosition_gainval *
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
          APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE_m[0];
        APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE_m[0] =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

        // Sum: '<S593>/Sum' incorporates:
        //   RandomNumber: '<S593>/Random Number'

        APF_Path_Planning_2023a_BlueI_B.x_ddot[0] =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
          APF_Path_Planning_2023a_Blue_DW.NextOutput_i;

        // DiscreteIntegrator: '<S593>/Acceleration  to Velocity' incorporates:
        //   DataStoreRead: '<S592>/RED_Fy_Sat'
        //   MATLAB Function: '<S593>/MATLAB Function'
        //   SignalConversion generated from: '<S600>/ SFunction '

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_Blue_DW.RED_Fy_Sat /
          APF_Path_Planning_2023a_BlueI_P.mRED *
          APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_gainva_g +
          APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_b[1];
        APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_b[1] =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

        // DiscreteIntegrator: '<S593>/Velocity to Position'
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_P.VelocitytoPosition_gainval *
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
          APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE_m[1];
        APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE_m[1] =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

        // Sum: '<S593>/Sum' incorporates:
        //   RandomNumber: '<S593>/Random Number'

        APF_Path_Planning_2023a_BlueI_B.x_ddot[1] =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
          APF_Path_Planning_2023a_Blue_DW.NextOutput_i;

        // DiscreteIntegrator: '<S593>/Acceleration  to Velocity' incorporates:
        //   DataStoreRead: '<S592>/Data Store Read'
        //   DataStoreRead: '<S592>/RED_Tz_Sat'
        //   MATLAB Function: '<S593>/MATLAB Function'
        //   Sum: '<S592>/Sum'

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          (APF_Path_Planning_2023a_Blue_DW.RED_Tz_Sat +
           APF_Path_Planning_2023a_Blue_DW.RED_Tz_RW_Sat) /
          APF_Path_Planning_2023a_BlueI_P.IRED *
          APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_gainva_g +
          APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_b[2];
        APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_b[2] =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

        // DiscreteIntegrator: '<S593>/Velocity to Position'
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_P.VelocitytoPosition_gainval *
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
          APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE_m[2];
        APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE_m[2] =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

        // Sum: '<S593>/Sum' incorporates:
        //   RandomNumber: '<S593>/Random Number'

        APF_Path_Planning_2023a_BlueI_B.x_ddot[2] =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW +
          APF_Path_Planning_2023a_Blue_DW.NextOutput_i;

        // Delay: '<S595>/Delay1'
        if (APF_Path_Planning_2023a_Blue_DW.icLoad_nn) {
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_n2 =
            APF_Path_Planning_2023a_BlueI_B.x_ddot[0];
        }

        // Sum: '<S595>/Sum6' incorporates:
        //   Delay: '<S595>/Delay1'

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_B.x_ddot[0] -
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_n2;

        // If: '<S595>/if we went through a "step"'
        if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S595>/Hold this value' incorporates:
          //   ActionPort: '<S602>/Action Port'

          // SignalConversion generated from: '<S602>/In1'
          APF_Path_Planning_2023a_BlueI_B.In1_ff =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S595>/Hold this value'
        }

        // End of If: '<S595>/if we went through a "step"'

        // Gain: '<S595>/divide by delta T' incorporates:
        //   DataStoreWrite: '<S592>/RED_Vx'

        APF_Path_Planning_2023a_Blue_DW.RED_Vx = 1.0 /
          APF_Path_Planning_2023a_BlueI_P.baseRate *
          APF_Path_Planning_2023a_BlueI_B.In1_ff;

        // Delay: '<S597>/Delay1' incorporates:
        //   DataStoreWrite: '<S592>/RED_Vx'

        if (APF_Path_Planning_2023a_Blue_DW.icLoad_kb) {
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_pc3 =
            APF_Path_Planning_2023a_Blue_DW.RED_Vx;
        }

        // Sum: '<S597>/Sum6' incorporates:
        //   DataStoreWrite: '<S592>/RED_Vx'
        //   Delay: '<S597>/Delay1'

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_Blue_DW.RED_Vx -
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_pc3;

        // If: '<S597>/if we went through a "step"'
        if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S597>/Hold this value' incorporates:
          //   ActionPort: '<S604>/Action Port'

          // SignalConversion generated from: '<S604>/In1'
          APF_Path_Planning_2023a_BlueI_B.In1_fv =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S597>/Hold this value'
        }

        // End of If: '<S597>/if we went through a "step"'

        // Sum: '<S592>/Sum7' incorporates:
        //   DataStoreWrite: '<S592>/RED_IMU_Ay'
        //   Gain: '<S597>/divide by delta T'
        //   RandomNumber: '<S592>/Random Number7'

        APF_Path_Planning_2023a_Blue_DW.RED_Ay = 1.0 /
          APF_Path_Planning_2023a_BlueI_P.baseRate *
          APF_Path_Planning_2023a_BlueI_B.In1_fv +
          APF_Path_Planning_2023a_Blue_DW.NextOutput_n;

        // Delay: '<S594>/Delay1'
        if (APF_Path_Planning_2023a_Blue_DW.icLoad_jf) {
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_k4 =
            APF_Path_Planning_2023a_BlueI_B.x_ddot[1];
        }

        // Sum: '<S594>/Sum6' incorporates:
        //   Delay: '<S594>/Delay1'

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_B.x_ddot[1] -
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_k4;

        // If: '<S594>/if we went through a "step"'
        if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S594>/Hold this value' incorporates:
          //   ActionPort: '<S601>/Action Port'

          // SignalConversion generated from: '<S601>/In1'
          APF_Path_Planning_2023a_BlueI_B.In1_n =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S594>/Hold this value'
        }

        // End of If: '<S594>/if we went through a "step"'

        // Gain: '<S594>/divide by delta T' incorporates:
        //   DataStoreWrite: '<S592>/RED_Vy'

        APF_Path_Planning_2023a_Blue_DW.RED_Vy = 1.0 /
          APF_Path_Planning_2023a_BlueI_P.baseRate *
          APF_Path_Planning_2023a_BlueI_B.In1_n;

        // Delay: '<S598>/Delay1' incorporates:
        //   DataStoreWrite: '<S592>/RED_Vy'

        if (APF_Path_Planning_2023a_Blue_DW.icLoad_dk) {
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_dh =
            APF_Path_Planning_2023a_Blue_DW.RED_Vy;
        }

        // Sum: '<S598>/Sum6' incorporates:
        //   DataStoreWrite: '<S592>/RED_Vy'
        //   Delay: '<S598>/Delay1'

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_Blue_DW.RED_Vy -
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_dh;

        // If: '<S598>/if we went through a "step"'
        if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S598>/Hold this value' incorporates:
          //   ActionPort: '<S605>/Action Port'

          // SignalConversion generated from: '<S605>/In1'
          APF_Path_Planning_2023a_BlueI_B.In1_g0 =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S598>/Hold this value'
        }

        // End of If: '<S598>/if we went through a "step"'

        // Sum: '<S592>/Sum8' incorporates:
        //   DataStoreWrite: '<S592>/RED_IMU_Ay_I'
        //   Gain: '<S598>/divide by delta T'
        //   RandomNumber: '<S592>/Random Number6'

        APF_Path_Planning_2023a_Blue_DW.RED_RzDD = 1.0 /
          APF_Path_Planning_2023a_BlueI_P.baseRate *
          APF_Path_Planning_2023a_BlueI_B.In1_g0 +
          APF_Path_Planning_2023a_Blue_DW.NextOutput_ga;

        // Delay: '<S596>/Delay1'
        if (APF_Path_Planning_2023a_Blue_DW.icLoad_l1) {
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_lh =
            APF_Path_Planning_2023a_BlueI_B.x_ddot[2];
        }

        // Sum: '<S596>/Sum6' incorporates:
        //   Delay: '<S596>/Delay1'

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_B.x_ddot[2] -
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_lh;

        // If: '<S596>/if we went through a "step"'
        if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S596>/Hold this value' incorporates:
          //   ActionPort: '<S603>/Action Port'

          // SignalConversion generated from: '<S603>/In1'
          APF_Path_Planning_2023a_BlueI_B.In1_h =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S596>/Hold this value'
        }

        // End of If: '<S596>/if we went through a "step"'

        // Gain: '<S596>/divide by delta T' incorporates:
        //   DataStoreWrite: '<S592>/RED_RzD'

        APF_Path_Planning_2023a_Blue_DW.RED_RzD = 1.0 /
          APF_Path_Planning_2023a_BlueI_P.baseRate *
          APF_Path_Planning_2023a_BlueI_B.In1_h;

        // Delay: '<S599>/Delay1' incorporates:
        //   DataStoreWrite: '<S592>/RED_RzD'

        if (APF_Path_Planning_2023a_Blue_DW.icLoad_kp) {
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_jb =
            APF_Path_Planning_2023a_Blue_DW.RED_RzD;
        }

        // Sum: '<S599>/Sum6' incorporates:
        //   DataStoreWrite: '<S592>/RED_RzD'
        //   Delay: '<S599>/Delay1'

        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_Blue_DW.RED_RzD -
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_jb;

        // If: '<S599>/if we went through a "step"'
        if (APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW != 0.0) {
          // Outputs for IfAction SubSystem: '<S599>/Hold this value' incorporates:
          //   ActionPort: '<S606>/Action Port'

          // SignalConversion generated from: '<S606>/In1'
          APF_Path_Planning_2023a_BlueI_B.In1_aw =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // End of Outputs for SubSystem: '<S599>/Hold this value'
        }

        // End of If: '<S599>/if we went through a "step"'

        // Sum: '<S592>/Sum9' incorporates:
        //   DataStoreWrite: '<S592>/RED_IMU_R'
        //   Gain: '<S599>/divide by delta T'
        //   RandomNumber: '<S592>/Random Number8'

        APF_Path_Planning_2023a_Blue_DW.RED_Ax = 1.0 /
          APF_Path_Planning_2023a_BlueI_P.baseRate *
          APF_Path_Planning_2023a_BlueI_B.In1_aw +
          APF_Path_Planning_2023a_Blue_DW.NextOutput_l;

        // DataStoreWrite: '<S592>/RED_Px'
        APF_Path_Planning_2023a_Blue_DW.RED_Px =
          APF_Path_Planning_2023a_BlueI_B.x_ddot[0];

        // DataStoreWrite: '<S592>/RED_Py'
        APF_Path_Planning_2023a_Blue_DW.RED_Py =
          APF_Path_Planning_2023a_BlueI_B.x_ddot[1];

        // DataStoreWrite: '<S592>/RED_Rz'
        APF_Path_Planning_2023a_Blue_DW.RED_Rz =
          APF_Path_Planning_2023a_BlueI_B.x_ddot[2];

        // Update for RandomNumber: '<S593>/Random Number'
        APF_Path_Planning_2023a_Blue_DW.NextOutput_i =
          APF__rt_nrand_Upu32_Yd_f_pw_snf
          (&APF_Path_Planning_2023a_Blue_DW.RandSeed_k) * sqrt
          (APF_Path_Planning_2023a_BlueI_P.noise_variance_RED) +
          APF_Path_Planning_2023a_BlueI_P.RandomNumber_Mean;

        // Update for Delay: '<S595>/Delay1'
        APF_Path_Planning_2023a_Blue_DW.icLoad_nn = false;
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_n2 =
          APF_Path_Planning_2023a_BlueI_B.x_ddot[0];

        // Update for Delay: '<S597>/Delay1' incorporates:
        //   DataStoreWrite: '<S592>/RED_Vx'

        APF_Path_Planning_2023a_Blue_DW.icLoad_kb = false;
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_pc3 =
          APF_Path_Planning_2023a_Blue_DW.RED_Vx;

        // Update for RandomNumber: '<S592>/Random Number7'
        APF_Path_Planning_2023a_Blue_DW.NextOutput_n =
          APF__rt_nrand_Upu32_Yd_f_pw_snf
          (&APF_Path_Planning_2023a_Blue_DW.RandSeed_a) *
          APF_Path_Planning_2023a_BlueI_P.RandomNumber7_StdDev +
          APF_Path_Planning_2023a_BlueI_P.RandomNumber7_Mean;

        // Update for Delay: '<S594>/Delay1'
        APF_Path_Planning_2023a_Blue_DW.icLoad_jf = false;
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_k4 =
          APF_Path_Planning_2023a_BlueI_B.x_ddot[1];

        // Update for Delay: '<S598>/Delay1' incorporates:
        //   DataStoreWrite: '<S592>/RED_Vy'

        APF_Path_Planning_2023a_Blue_DW.icLoad_dk = false;
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_dh =
          APF_Path_Planning_2023a_Blue_DW.RED_Vy;

        // Update for RandomNumber: '<S592>/Random Number6'
        APF_Path_Planning_2023a_Blue_DW.NextOutput_ga =
          APF__rt_nrand_Upu32_Yd_f_pw_snf
          (&APF_Path_Planning_2023a_Blue_DW.RandSeed_f) *
          APF_Path_Planning_2023a_BlueI_P.RandomNumber6_StdDev +
          APF_Path_Planning_2023a_BlueI_P.RandomNumber6_Mean;

        // Update for Delay: '<S596>/Delay1'
        APF_Path_Planning_2023a_Blue_DW.icLoad_l1 = false;
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_lh =
          APF_Path_Planning_2023a_BlueI_B.x_ddot[2];

        // Update for Delay: '<S599>/Delay1' incorporates:
        //   DataStoreWrite: '<S592>/RED_RzD'

        APF_Path_Planning_2023a_Blue_DW.icLoad_kp = false;
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_jb =
          APF_Path_Planning_2023a_Blue_DW.RED_RzD;

        // Update for RandomNumber: '<S592>/Random Number8'
        APF_Path_Planning_2023a_Blue_DW.NextOutput_l =
          APF__rt_nrand_Upu32_Yd_f_pw_snf
          (&APF_Path_Planning_2023a_Blue_DW.RandSeed_h) *
          APF_Path_Planning_2023a_BlueI_P.RandomNumber8_StdDev +
          APF_Path_Planning_2023a_BlueI_P.RandomNumber8_Mean;

        // End of Outputs for SubSystem: '<S551>/RED Only'
      }

      // End of If: '<S551>/If'

      // Update for RandomNumber: '<S552>/Random Number'
      APF_Path_Planning_2023a_Blue_DW.NextOutput =
        APF__rt_nrand_Upu32_Yd_f_pw_snf
        (&APF_Path_Planning_2023a_Blue_DW.RandSeed) * sqrt
        (APF_Path_Planning_2023a_BlueI_P.noise_variance_BLACK) +
        APF_Path_Planning_2023a_BlueI_P.RandomNumber_Mean_d;

      // Update for Delay: '<S558>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_ou = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_f =
        APF_Path_Planning_2023a_Blue_DW.BLACK_Px;

      // Update for Delay: '<S555>/Delay1' incorporates:
      //   DataStoreWrite: '<S549>/BLACK_Vx'

      APF_Path_Planning_2023a_Blue_DW.icLoad_p4 = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_lg =
        APF_Path_Planning_2023a_Blue_DW.BLACK_Vx;

      // Update for RandomNumber: '<S549>/Random Number1'
      APF_Path_Planning_2023a_Blue_DW.NextOutput_b =
        APF__rt_nrand_Upu32_Yd_f_pw_snf
        (&APF_Path_Planning_2023a_Blue_DW.RandSeed_n) *
        APF_Path_Planning_2023a_BlueI_P.RandomNumber1_StdDev_e +
        APF_Path_Planning_2023a_BlueI_P.RandomNumber1_Mean_j;

      // Update for Delay: '<S553>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_jc = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_d3a =
        APF_Path_Planning_2023a_Blue_DW.BLACK_Py;

      // Update for Delay: '<S556>/Delay1' incorporates:
      //   DataStoreWrite: '<S549>/BLACK_Vy'

      APF_Path_Planning_2023a_Blue_DW.icLoad_jk = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_ea =
        APF_Path_Planning_2023a_Blue_DW.BLACK_Vy;

      // Update for RandomNumber: '<S549>/Random Number'
      APF_Path_Planning_2023a_Blue_DW.NextOutput_j =
        APF__rt_nrand_Upu32_Yd_f_pw_snf
        (&APF_Path_Planning_2023a_Blue_DW.RandSeed_g) *
        APF_Path_Planning_2023a_BlueI_P.RandomNumber_StdDev +
        APF_Path_Planning_2023a_BlueI_P.RandomNumber_Mean_g;

      // Update for Delay: '<S554>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_jr = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_cx =
        APF_Path_Planning_2023a_Blue_DW.BLACK_Rz;

      // Update for Delay: '<S557>/Delay1' incorporates:
      //   DataStoreWrite: '<S549>/BLACK_RzD'

      APF_Path_Planning_2023a_Blue_DW.icLoad_jko = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_ab =
        APF_Path_Planning_2023a_Blue_DW.BLACK_RzD;

      // Update for RandomNumber: '<S549>/Random Number2'
      APF_Path_Planning_2023a_Blue_DW.NextOutput_g =
        APF__rt_nrand_Upu32_Yd_f_pw_snf
        (&APF_Path_Planning_2023a_Blue_DW.RandSeed_m) *
        APF_Path_Planning_2023a_BlueI_P.RandomNumber2_StdDev_c +
        APF_Path_Planning_2023a_BlueI_P.RandomNumber2_Mean_b;

      // Update for RandomNumber: '<S566>/Random Number'
      APF_Path_Planning_2023a_Blue_DW.NextOutput_a =
        APF__rt_nrand_Upu32_Yd_f_pw_snf
        (&APF_Path_Planning_2023a_Blue_DW.RandSeed_o) * sqrt
        (APF_Path_Planning_2023a_BlueI_P.noise_variance_BLUE) +
        APF_Path_Planning_2023a_BlueI_P.RandomNumber_Mean_dq;

      // Update for Delay: '<S572>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_do = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_gv =
        APF_Path_Planning_2023a_Blue_DW.BLUE_Px;

      // Update for Delay: '<S569>/Delay1' incorporates:
      //   DataStoreWrite: '<S550>/BLUE_Vx'

      APF_Path_Planning_2023a_Blue_DW.icLoad_nk = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_ds =
        APF_Path_Planning_2023a_Blue_DW.BLUE_Vx;

      // Update for RandomNumber: '<S550>/Random Number4'
      APF__rt_nrand_Upu32_Yd_f_pw_snf
        (&APF_Path_Planning_2023a_Blue_DW.RandSeed_n0);

      // Update for Delay: '<S567>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_ip = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_i5 =
        APF_Path_Planning_2023a_Blue_DW.BLUE_Py;

      // Update for Delay: '<S570>/Delay1' incorporates:
      //   DataStoreWrite: '<S550>/BLUE_Vy'

      APF_Path_Planning_2023a_Blue_DW.icLoad_az = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_l0 =
        APF_Path_Planning_2023a_Blue_DW.BLUE_Vy;

      // Update for RandomNumber: '<S550>/Random Number3'
      APF__rt_nrand_Upu32_Yd_f_pw_snf
        (&APF_Path_Planning_2023a_Blue_DW.RandSeed_e);

      // Update for Delay: '<S568>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_dh = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_iq =
        APF_Path_Planning_2023a_Blue_DW.BLUE_Rz;

      // Update for Delay: '<S571>/Delay1' incorporates:
      //   DataStoreWrite: '<S550>/BLUE_RzD'

      APF_Path_Planning_2023a_Blue_DW.icLoad_ex = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_eq =
        APF_Path_Planning_2023a_Blue_DW.BLUE_RzD;

      // Update for RandomNumber: '<S550>/Random Number5'
      APF__rt_nrand_Upu32_Yd_f_pw_snf
        (&APF_Path_Planning_2023a_Blue_DW.RandSeed_c);

      // End of Outputs for SubSystem: '<Root>/Simulate Plant Dynamics'
    }

    // End of If: '<Root>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 

    // If: '<S1>/This IF block determines whether or not to run the BLACK sim//exp' incorporates:
    //   DataStoreRead: '<S1>/Data Store Read'
    //   DataStoreRead: '<S1>/Data Store Read1'

    if ((APF_Path_Planning_2023a_Blue_DW.WhoAmI == 2.0) &&
        (APF_Path_Planning_2023a_BlueI_B.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S1>/Change BLACK Behavior' incorporates:
      //   ActionPort: '<S20>/Action Port'

      APF_Path_Pl_ChangeBLACKBehavior(APF_Path_Planning_2023a_Blue_M,
        &APF_Path_Planning_2023a_Blue_DW.ChangeBLACKBehavior,
        &APF_Path_Planning_2023a_BlueI_P.ChangeBLACKBehavior);

      // End of Outputs for SubSystem: '<S1>/Change BLACK Behavior'
    }

    // End of If: '<S1>/This IF block determines whether or not to run the BLACK sim//exp' 

    // If: '<S1>/This IF block determines whether or not to run the BLUE sim//exp' incorporates:
    //   DataStoreRead: '<S1>/Data Store Read'
    //   DataStoreRead: '<S1>/Data Store Read1'

    if ((APF_Path_Planning_2023a_Blue_DW.WhoAmI == 3.0) &&
        (APF_Path_Planning_2023a_BlueI_B.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S1>/Change BLUE Behavior' incorporates:
      //   ActionPort: '<S21>/Action Port'

      APF_Path_Pl_ChangeBLACKBehavior(APF_Path_Planning_2023a_Blue_M,
        &APF_Path_Planning_2023a_Blue_DW.ChangeBLUEBehavior,
        &APF_Path_Planning_2023a_BlueI_P.ChangeBLUEBehavior);

      // End of Outputs for SubSystem: '<S1>/Change BLUE Behavior'
    }

    // End of If: '<S1>/This IF block determines whether or not to run the BLUE sim//exp' 

    // If: '<S1>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
    //   DataStoreRead: '<S1>/Data Store Read'
    //   DataStoreRead: '<S1>/Data Store Read1'

    if ((APF_Path_Planning_2023a_Blue_DW.WhoAmI == 1.0) &&
        (APF_Path_Planning_2023a_BlueI_B.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S1>/Change RED Behavior' incorporates:
      //   ActionPort: '<S22>/Action Port'

      // Update for S-Function (sdspToNetwork): '<S22>/UDP Send' incorporates:
      //   Constant: '<S22>/Constant1'

      sErr = GetErrorBuffer
        (&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_l[0U]);
      LibUpdate_Network(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_l[0U],
                        &APF_Path_Planning_2023a_BlueI_P.Constant1_Value_i, 1);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
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
    APF_Path_Planning_2023a_BlueI_B.b_u1[0] =
      APF_Path_Planning_2023a_Blue_DW.Univ_Time;
    APF_Path_Planning_2023a_BlueI_B.b_u1[1] =
      APF_Path_Planning_2023a_Blue_DW.RED_Fx_Sat;
    APF_Path_Planning_2023a_BlueI_B.b_u1[2] =
      APF_Path_Planning_2023a_Blue_DW.RED_Fy_Sat;
    APF_Path_Planning_2023a_BlueI_B.b_u1[3] =
      APF_Path_Planning_2023a_Blue_DW.RED_Tz_Sat;
    APF_Path_Planning_2023a_BlueI_B.b_u1[4] =
      APF_Path_Planning_2023a_Blue_DW.RED_Px;
    APF_Path_Planning_2023a_BlueI_B.b_u1[5] =
      APF_Path_Planning_2023a_Blue_DW.RED_Py;
    APF_Path_Planning_2023a_BlueI_B.b_u1[6] =
      APF_Path_Planning_2023a_Blue_DW.RED_Rz;
    APF_Path_Planning_2023a_BlueI_B.b_u1[7] =
      APF_Path_Planning_2023a_Blue_DW.RED_Vx;
    APF_Path_Planning_2023a_BlueI_B.b_u1[8] =
      APF_Path_Planning_2023a_Blue_DW.RED_Vy;
    APF_Path_Planning_2023a_BlueI_B.b_u1[9] =
      APF_Path_Planning_2023a_Blue_DW.RED_RzD;
    APF_Path_Planning_2023a_BlueI_B.b_u1[10] =
      APF_Path_Planning_2023a_Blue_DW.RED_Ax;
    APF_Path_Planning_2023a_BlueI_B.b_u1[11] =
      APF_Path_Planning_2023a_Blue_DW.RED_Ay;
    APF_Path_Planning_2023a_BlueI_B.b_u1[12] =
      APF_Path_Planning_2023a_Blue_DW.RED_RzDD;
    APF_Path_Planning_2023a_BlueI_B.b_u1[13] =
      APF_Path_Planning_2023a_Blue_DW.BLACK_Fx_Sat;
    APF_Path_Planning_2023a_BlueI_B.b_u1[14] =
      APF_Path_Planning_2023a_Blue_DW.BLACK_Fy_Sat;
    APF_Path_Planning_2023a_BlueI_B.b_u1[15] =
      APF_Path_Planning_2023a_Blue_DW.BLACK_Tz_Sat;
    APF_Path_Planning_2023a_BlueI_B.b_u1[16] =
      APF_Path_Planning_2023a_Blue_DW.BLACK_Px;
    APF_Path_Planning_2023a_BlueI_B.b_u1[17] =
      APF_Path_Planning_2023a_Blue_DW.BLACK_Py;
    APF_Path_Planning_2023a_BlueI_B.b_u1[18] =
      APF_Path_Planning_2023a_Blue_DW.BLACK_Rz;
    APF_Path_Planning_2023a_BlueI_B.b_u1[19] =
      APF_Path_Planning_2023a_Blue_DW.BLACK_Vx;
    APF_Path_Planning_2023a_BlueI_B.b_u1[20] =
      APF_Path_Planning_2023a_Blue_DW.BLACK_Vy;
    APF_Path_Planning_2023a_BlueI_B.b_u1[21] =
      APF_Path_Planning_2023a_Blue_DW.BLACK_RzD;
    APF_Path_Planning_2023a_BlueI_B.b_u1[22] =
      APF_Path_Planning_2023a_Blue_DW.BLACK_Ax;
    APF_Path_Planning_2023a_BlueI_B.b_u1[23] =
      APF_Path_Planning_2023a_Blue_DW.BLACK_Ay;
    APF_Path_Planning_2023a_BlueI_B.b_u1[24] =
      APF_Path_Planning_2023a_Blue_DW.BLACK_RzDD;
    APF_Path_Planning_2023a_BlueI_B.b_u1[25] =
      APF_Path_Planning_2023a_Blue_DW.BLUE_Fx_Sat;
    APF_Path_Planning_2023a_BlueI_B.b_u1[26] =
      APF_Path_Planning_2023a_Blue_DW.BLUE_Fy_Sat;
    APF_Path_Planning_2023a_BlueI_B.b_u1[27] =
      APF_Path_Planning_2023a_Blue_DW.BLUE_Tz_Sat;
    APF_Path_Planning_2023a_BlueI_B.b_u1[28] =
      APF_Path_Planning_2023a_Blue_DW.BLUE_Px;
    APF_Path_Planning_2023a_BlueI_B.b_u1[29] =
      APF_Path_Planning_2023a_Blue_DW.BLUE_Py;
    APF_Path_Planning_2023a_BlueI_B.b_u1[30] =
      APF_Path_Planning_2023a_Blue_DW.BLUE_Rz;
    APF_Path_Planning_2023a_BlueI_B.b_u1[31] =
      APF_Path_Planning_2023a_Blue_DW.BLUE_Vx;
    APF_Path_Planning_2023a_BlueI_B.b_u1[32] =
      APF_Path_Planning_2023a_Blue_DW.BLUE_Vy;
    APF_Path_Planning_2023a_BlueI_B.b_u1[33] =
      APF_Path_Planning_2023a_Blue_DW.BLUE_RzD;
    APF_Path_Planning_2023a_BlueI_B.b_u1[34] =
      APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder;
    APF_Path_Planning_2023a_BlueI_B.b_u1[35] =
      APF_Path_Planning_2023a_Blue_DW.RED_Rz_Elbow;
    APF_Path_Planning_2023a_BlueI_B.b_u1[36] =
      APF_Path_Planning_2023a_Blue_DW.RED_Rz_Wrist;
    APF_Path_Planning_2023a_BlueI_B.b_u1[37] =
      APF_Path_Planning_2023a_Blue_DW.RED_RzD_Shoulder;
    APF_Path_Planning_2023a_BlueI_B.b_u1[38] =
      APF_Path_Planning_2023a_Blue_DW.RED_RzD_Elbow;
    APF_Path_Planning_2023a_BlueI_B.b_u1[39] =
      APF_Path_Planning_2023a_Blue_DW.RED_RzD_Wrist;
    APF_Path_Planning_2023a_BlueI_B.b_u1[40] =
      APF_Path_Planning_2023a_Blue_DW.RED_ARM_Control_Mode;
    APF_Path_Planning_2023a_BlueI_B.b_u1[41] =
      APF_Path_Planning_2023a_Blue_DW.RED_Shoulder_Command;
    APF_Path_Planning_2023a_BlueI_B.b_u1[42] =
      APF_Path_Planning_2023a_Blue_DW.RED_Elbow_Command;
    APF_Path_Planning_2023a_BlueI_B.b_u1[43] =
      APF_Path_Planning_2023a_Blue_DW.RED_Wrist_Command;
    APF_Path_Planning_2023a_BlueI_B.b_u1[44] =
      APF_Path_Planning_2023a_Blue_DW.RED_Thruster_ON_Count;
    APF_Path_Planning_2023a_BlueI_B.b_u1[45] =
      APF_Path_Planning_2023a_Blue_DW.BLACK_Thruster_ON_Count;
    APF_Path_Planning_2023a_BlueI_B.b_u1[46] =
      APF_Path_Planning_2023a_Blue_DW.BLUE_Thruster_ON_Count;
    APF_Path_Planning_2023a_BlueI_B.b_u1[47] =
      APF_Path_Planning_2023a_Blue_DW.Command_Px;
    APF_Path_Planning_2023a_BlueI_B.b_u1[48] =
      APF_Path_Planning_2023a_Blue_DW.Command_Py;
    APF_Path_Planning_2023a_BlueI_B.b_u1[49] =
      APF_Path_Planning_2023a_Blue_DW.Command_Rz;
    APF_Path_Planning_2023a_BlueI_B.b_u1[50] =
      APF_Path_Planning_2023a_Blue_DW.DAC_Posx_k_1;
    APF_Path_Planning_2023a_BlueI_B.b_u1[51] =
      APF_Path_Planning_2023a_Blue_DW.DAC_Posx_k_2;
    APF_Path_Planning_2023a_BlueI_B.b_u1[52] =
      APF_Path_Planning_2023a_Blue_DW.DAC_Posy_k_1;
    APF_Path_Planning_2023a_BlueI_B.b_u1[53] =
      APF_Path_Planning_2023a_Blue_DW.DAC_Posy_k_2;
    APF_Path_Planning_2023a_BlueI_B.b_u1[54] =
      APF_Path_Planning_2023a_Blue_DW.DAC_Attitude_k_1;
    APF_Path_Planning_2023a_BlueI_B.b_u1[55] =
      APF_Path_Planning_2023a_Blue_DW.DAC_Attitude_k_2;
    APF_Path_Planning_2023a_BlueI_B.b_u1[59] =
      APF_Path_Planning_2023a_Blue_DW.BLACK_Px_Est;
    APF_Path_Planning_2023a_BlueI_B.b_u1[60] =
      APF_Path_Planning_2023a_Blue_DW.BLACK_Py_Est;
    APF_Path_Planning_2023a_BlueI_B.b_u1[61] =
      APF_Path_Planning_2023a_Blue_DW.BLACK_Rz_Est;
    APF_Path_Planning_2023a_BlueI_B.b_u1[62] =
      APF_Path_Planning_2023a_Blue_DW.BLACK_Px_preKalm;
    APF_Path_Planning_2023a_BlueI_B.b_u1[63] =
      APF_Path_Planning_2023a_Blue_DW.BLACK_Py_preKalm;
    APF_Path_Planning_2023a_BlueI_B.b_u1[64] =
      APF_Path_Planning_2023a_Blue_DW.BLACK_Rz_preKalm;
    appendDataToFile(&APF_Path_Planning_2023a_BlueI_B.b_u1[0], 65.0);

    // If: '<S4>/This IF block determines whether or not to run the exp code' incorporates:
    //   DataStoreRead: '<S4>/Data Store Read'

    if (APF_Path_Planning_2023a_BlueI_B.isSim == 0.0) {
      // Outputs for IfAction SubSystem: '<S4>/Enable Pucks' incorporates:
      //   ActionPort: '<S25>/Action Port'

      // MATLABSystem: '<S25>/Set Pin 428 (Pucks) to HIGH' incorporates:
      //   DataStoreRead: '<S25>/Data Store Read1'

      if (APF_Path_Planning_2023a_Blue_DW.obj_p.gpioPin !=
          APF_Path_Planning_2023a_BlueI_P.SetPin428PuckstoHIGH_gpioPin) {
        APF_Path_Planning_2023a_Blue_DW.obj_p.gpioPin =
          APF_Path_Planning_2023a_BlueI_P.SetPin428PuckstoHIGH_gpioPin;
      }

      if (APF_Path_Planning_2023a_Blue_DW.obj_p.pinDirection !=
          APF_Path_Planning_2023a_BlueI_P.SetPin428PuckstoHIGH_pinDirecti) {
        APF_Path_Planning_2023a_Blue_DW.obj_p.pinDirection =
          APF_Path_Planning_2023a_BlueI_P.SetPin428PuckstoHIGH_pinDirecti;
      }

      //         %% Define input properties
      //  Call C-function implementing device output
      // coder.ceval('export_gpio', obj.gpioPin);
      set_pin_direction(APF_Path_Planning_2023a_Blue_DW.obj_p.gpioPin,
                        APF_Path_Planning_2023a_Blue_DW.obj_p.pinDirection);
      change_gpio_value(APF_Path_Planning_2023a_Blue_DW.obj_p.gpioPin,
                        APF_Path_Planning_2023a_Blue_DW.Float_State);

      // End of MATLABSystem: '<S25>/Set Pin 428 (Pucks) to HIGH'
      // End of Outputs for SubSystem: '<S4>/Enable Pucks'
    }

    // End of If: '<S4>/This IF block determines whether or not to run the exp code' 

    // If: '<S5>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
    //   DataStoreRead: '<S5>/Data Store Read1'
    //   DataStoreRead: '<S5>/Data Store Read2'

    if ((APF_Path_Planning_2023a_Blue_DW.WhoAmI == 1.0) &&
        (APF_Path_Planning_2023a_BlueI_B.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S5>/Change RED Behavior' incorporates:
      //   ActionPort: '<S26>/Action Port'

      // MATLABSystem: '<S26>/Read Joint Positions using  Dynamixel Encoders' incorporates:
      //   DataStoreWrite: '<S26>/Data Store Write3'
      //   DataStoreWrite: '<S26>/Data Store Write4'
      //   DataStoreWrite: '<S26>/Data Store Write5'
      //   Delay: '<S26>/Delay'
      //   Delay: '<S26>/Delay1'
      //   Delay: '<S26>/Delay2'

      if (APF_Path_Planning_2023a_Blue_DW.obj_d.SampleTime !=
          APF_Path_Planning_2023a_BlueI_P.baseRate) {
        if (((!rtIsInf(APF_Path_Planning_2023a_BlueI_P.baseRate)) && (!rtIsNaN
              (APF_Path_Planning_2023a_BlueI_P.baseRate))) || rtIsInf
            (APF_Path_Planning_2023a_BlueI_P.baseRate)) {
          APF_Path_Planning_2023a_BlueI_B.sampleTime =
            APF_Path_Planning_2023a_BlueI_P.baseRate;
        }

        APF_Path_Planning_2023a_Blue_DW.obj_d.SampleTime =
          APF_Path_Planning_2023a_BlueI_B.sampleTime;
      }

      //         %% Define input properties
      //         %% Define output properties
      APF_Path_Planning_2023a_BlueI_B.sampleTime = 0.0;
      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 0.0;
      APF_Path_Planning_2023a_BlueI_B.Sum6_a = 0.0;
      APF_Path_Planning_2023a_Blue_DW.RED_RzD_Shoulder = 0.0;
      APF_Path_Planning_2023a_Blue_DW.RED_RzD_Elbow = 0.0;
      APF_Path_Planning_2023a_Blue_DW.RED_RzD_Wrist = 0.0;
      read_dynamixel_position(&APF_Path_Planning_2023a_BlueI_B.sampleTime,
        &APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW,
        &APF_Path_Planning_2023a_BlueI_B.Sum6_a,
        &APF_Path_Planning_2023a_Blue_DW.RED_RzD_Shoulder,
        &APF_Path_Planning_2023a_Blue_DW.RED_RzD_Elbow,
        &APF_Path_Planning_2023a_Blue_DW.RED_RzD_Wrist,
        APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_a,
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_pw,
        APF_Path_Planning_2023a_Blue_DW.Delay2_DSTATE);
      APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_a =
        APF_Path_Planning_2023a_BlueI_B.sampleTime;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_pw =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
      APF_Path_Planning_2023a_Blue_DW.Delay2_DSTATE =
        APF_Path_Planning_2023a_BlueI_B.Sum6_a;

      // End of MATLABSystem: '<S26>/Read Joint Positions using  Dynamixel Encoders' 

      // DataStoreWrite: '<S26>/Data Store Write' incorporates:
      //   Delay: '<S26>/Delay'

      APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder =
        APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_a;

      // DataStoreWrite: '<S26>/Data Store Write1' incorporates:
      //   Delay: '<S26>/Delay1'

      APF_Path_Planning_2023a_Blue_DW.RED_Rz_Elbow =
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_pw;

      // DataStoreWrite: '<S26>/Data Store Write2' incorporates:
      //   Delay: '<S26>/Delay2'

      APF_Path_Planning_2023a_Blue_DW.RED_Rz_Wrist =
        APF_Path_Planning_2023a_Blue_DW.Delay2_DSTATE;

      // End of Outputs for SubSystem: '<S5>/Change RED Behavior'
    }

    // End of If: '<S5>/This IF block determines whether or not to run the RED sim//exp ' 

    // If: '<S13>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' incorporates:
    //   Constant: '<S506>/Constant'
    //   DataStoreRead: '<S13>/Data Store Read2'
    //   RelationalOperator: '<S506>/Relational Operator'
    //   RelationalOperator: '<S506>/Relational Operator1'

    APF_Path_Planning_2023a_Blue_DW.Ifperforminganexperimentgrabthe = -1;
    if (APF_Path_Planning_2023a_BlueI_B.isSim == 0.0) {
      APF_Path_Planning_2023a_Blue_DW.Ifperforminganexperimentgrabthe = 0;
    } else if (APF_Path_Planning_2023a_BlueI_B.isSim == 1.0) {
      APF_Path_Planning_2023a_Blue_DW.Ifperforminganexperimentgrabthe = 1;
    }

    switch (APF_Path_Planning_2023a_Blue_DW.Ifperforminganexperimentgrabthe) {
     case 0:
      // Outputs for IfAction SubSystem: '<S13>/Use Hardware to Obtain States' incorporates:
      //   ActionPort: '<S505>/Action Port'

      // S-Function (sdspFromNetwork): '<S505>/UDP Receive1'
      sErr = GetErrorBuffer
        (&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib_b[0U]);
      APF_Path_Planning_2023a_BlueI_B.ntIdx0 = 10;
      LibOutputs_Network
        (&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib_b[0U],
         &APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[0U],
         &APF_Path_Planning_2023a_BlueI_B.ntIdx0);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
      }

      // End of S-Function (sdspFromNetwork): '<S505>/UDP Receive1'

      // Gain: '<S505>/Convert REDX from [mm] to [m]'
      APF_Path_Planning_2023a_BlueI_B.ConvertREDXfrommmtom =
        APF_Path_Planning_2023a_BlueI_P.ConvertREDXfrommmtom_Gain *
        APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[1];

      // DataStoreWrite: '<S505>/RED_Px1'
      APF_Path_Planning_2023a_Blue_DW.RED_Px =
        APF_Path_Planning_2023a_BlueI_B.ConvertREDXfrommmtom;

      // Gain: '<S505>/Convert BLUX from [mm] to [m]'
      APF_Path_Planning_2023a_BlueI_B.ConvertBLUXfrommmtom =
        APF_Path_Planning_2023a_BlueI_P.ConvertBLUXfrommmtom_Gain *
        APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[7];

      // Delay: '<S515>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_l) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_eo =
          APF_Path_Planning_2023a_BlueI_B.ConvertBLUXfrommmtom;
      }

      // Sum: '<S515>/Sum6' incorporates:
      //   Delay: '<S515>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.ConvertBLUXfrommmtom -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_eo;

      // If: '<S515>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.sampleTime != 0.0) {
        // Outputs for IfAction SubSystem: '<S515>/Hold this value' incorporates:
        //   ActionPort: '<S535>/Action Port'

        // SignalConversion generated from: '<S535>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_lk =
          APF_Path_Planning_2023a_BlueI_B.sampleTime;

        // End of Outputs for SubSystem: '<S515>/Hold this value'
      }

      // End of If: '<S515>/if we went through a "step"'

      // Gain: '<S515>/divide by delta T'
      APF_Path_Planning_2023a_BlueI_B.dividebydeltaT = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_lk;

      // Delay: '<S512>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_ld) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_gs =
          APF_Path_Planning_2023a_BlueI_B.dividebydeltaT;
      }

      // End of Delay: '<S512>/Delay1'

      // Gain: '<S505>/Convert BLAX from [mm] to [m]'
      APF_Path_Planning_2023a_BlueI_B.ConvertBLAXfrommmtom =
        APF_Path_Planning_2023a_BlueI_P.ConvertBLAXfrommmtom_Gain *
        APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[4];

      // Delay: '<S520>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_d) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_b =
          APF_Path_Planning_2023a_BlueI_B.ConvertBLAXfrommmtom;
      }

      // Sum: '<S520>/Sum6' incorporates:
      //   Delay: '<S520>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.ConvertBLAXfrommmtom -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_b;

      // If: '<S520>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.sampleTime != 0.0) {
        // Outputs for IfAction SubSystem: '<S520>/Hold this value' incorporates:
        //   ActionPort: '<S540>/Action Port'

        // SignalConversion generated from: '<S540>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_m =
          APF_Path_Planning_2023a_BlueI_B.sampleTime;

        // End of Outputs for SubSystem: '<S520>/Hold this value'
      }

      // End of If: '<S520>/if we went through a "step"'

      // Gain: '<S520>/divide by delta T'
      APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_f = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_m;

      // Delay: '<S509>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_k) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_p4 =
          APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_f;
      }

      // Sum: '<S509>/Sum6' incorporates:
      //   Delay: '<S509>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_f -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_p4;

      // If: '<S509>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.sampleTime != 0.0) {
        // Outputs for IfAction SubSystem: '<S509>/Hold this value' incorporates:
        //   ActionPort: '<S529>/Action Port'

        // SignalConversion generated from: '<S529>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_p =
          APF_Path_Planning_2023a_BlueI_B.sampleTime;

        // End of Outputs for SubSystem: '<S509>/Hold this value'
      }

      // End of If: '<S509>/if we went through a "step"'

      // Gain: '<S509>/divide by delta T' incorporates:
      //   DataStoreWrite: '<S505>/RED_Px11'

      APF_Path_Planning_2023a_Blue_DW.BLACK_Ax = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_p;

      // Gain: '<S505>/Convert BLAY from [mm] to [m]'
      APF_Path_Planning_2023a_BlueI_B.ConvertBLAYfrommmtom =
        APF_Path_Planning_2023a_BlueI_P.ConvertBLAYfrommmtom_Gain *
        APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[5];

      // Delay: '<S521>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_fv) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_md =
          APF_Path_Planning_2023a_BlueI_B.ConvertBLAYfrommmtom;
      }

      // Sum: '<S521>/Sum6' incorporates:
      //   Delay: '<S521>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.ConvertBLAYfrommmtom -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_md;

      // If: '<S521>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.sampleTime != 0.0) {
        // Outputs for IfAction SubSystem: '<S521>/Hold this value' incorporates:
        //   ActionPort: '<S541>/Action Port'

        // SignalConversion generated from: '<S541>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_b =
          APF_Path_Planning_2023a_BlueI_B.sampleTime;

        // End of Outputs for SubSystem: '<S521>/Hold this value'
      }

      // End of If: '<S521>/if we went through a "step"'

      // Gain: '<S521>/divide by delta T'
      APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_l = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_b;

      // Delay: '<S510>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_na) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_ju =
          APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_l;
      }

      // Sum: '<S510>/Sum6' incorporates:
      //   Delay: '<S510>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_l -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_ju;

      // If: '<S510>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.sampleTime != 0.0) {
        // Outputs for IfAction SubSystem: '<S510>/Hold this value' incorporates:
        //   ActionPort: '<S530>/Action Port'

        // SignalConversion generated from: '<S530>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_c =
          APF_Path_Planning_2023a_BlueI_B.sampleTime;

        // End of Outputs for SubSystem: '<S510>/Hold this value'
      }

      // End of If: '<S510>/if we went through a "step"'

      // Gain: '<S510>/divide by delta T' incorporates:
      //   DataStoreWrite: '<S505>/RED_Px12'

      APF_Path_Planning_2023a_Blue_DW.BLACK_Ay = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_c;

      // S-Function (sdspunwrap2): '<S505>/Unwrap1'
      if (APF_Path_Planning_2023a_Blue_DW.Unwrap1_FirstStep) {
        APF_Path_Planning_2023a_Blue_DW.Unwrap1_Prev =
          APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[6];
        APF_Path_Planning_2023a_Blue_DW.Unwrap1_FirstStep = false;
      }

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[6] -
        APF_Path_Planning_2023a_Blue_DW.Unwrap1_Prev;
      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_BlueI_B.sampleTime - floor
        ((APF_Path_Planning_2023a_BlueI_B.sampleTime + 3.1415926535897931) /
         6.2831853071795862) * 6.2831853071795862;
      if ((APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW == -3.1415926535897931) &&
          (APF_Path_Planning_2023a_BlueI_B.sampleTime > 0.0)) {
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 3.1415926535897931;
      }

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW -
        APF_Path_Planning_2023a_BlueI_B.sampleTime;
      if (fabs(APF_Path_Planning_2023a_BlueI_B.sampleTime) > 3.1415926535897931)
      {
        APF_Path_Planning_2023a_Blue_DW.Unwrap1_Cumsum +=
          APF_Path_Planning_2023a_BlueI_B.sampleTime;
      }

      APF_Path_Planning_2023a_Blue_DW.Unwrap1_Prev =
        APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[6];

      // S-Function (sdspunwrap2): '<S505>/Unwrap1'
      APF_Path_Planning_2023a_BlueI_B.Unwrap1 =
        APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[6] +
        APF_Path_Planning_2023a_Blue_DW.Unwrap1_Cumsum;

      // Delay: '<S522>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_gx) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_p4s =
          APF_Path_Planning_2023a_BlueI_B.Unwrap1;
      }

      // Sum: '<S522>/Sum6' incorporates:
      //   Delay: '<S522>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.Unwrap1 -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_p4s;

      // If: '<S522>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.sampleTime != 0.0) {
        // Outputs for IfAction SubSystem: '<S522>/Hold this value' incorporates:
        //   ActionPort: '<S542>/Action Port'

        // SignalConversion generated from: '<S542>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_eg =
          APF_Path_Planning_2023a_BlueI_B.sampleTime;

        // End of Outputs for SubSystem: '<S522>/Hold this value'
      }

      // End of If: '<S522>/if we went through a "step"'

      // Gain: '<S522>/divide by delta T'
      APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_e = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_eg;

      // Delay: '<S511>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_m) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_k =
          APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_e;
      }

      // Sum: '<S511>/Sum6' incorporates:
      //   Delay: '<S511>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_e -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_k;

      // If: '<S511>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.sampleTime != 0.0) {
        // Outputs for IfAction SubSystem: '<S511>/Hold this value' incorporates:
        //   ActionPort: '<S531>/Action Port'

        // SignalConversion generated from: '<S531>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_a =
          APF_Path_Planning_2023a_BlueI_B.sampleTime;

        // End of Outputs for SubSystem: '<S511>/Hold this value'
      }

      // End of If: '<S511>/if we went through a "step"'

      // Gain: '<S511>/divide by delta T' incorporates:
      //   DataStoreWrite: '<S505>/RED_Px13'

      APF_Path_Planning_2023a_Blue_DW.BLACK_RzDD = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_a;

      // Gain: '<S505>/Convert BLUY from [mm] to [m]'
      APF_Path_Planning_2023a_BlueI_B.ConvertBLUYfrommmtom =
        APF_Path_Planning_2023a_BlueI_P.ConvertBLUYfrommmtom_Gain *
        APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[8];

      // Delay: '<S516>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_eo) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_mi =
          APF_Path_Planning_2023a_BlueI_B.ConvertBLUYfrommmtom;
      }

      // Sum: '<S516>/Sum6' incorporates:
      //   Delay: '<S516>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.ConvertBLUYfrommmtom -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_mi;

      // If: '<S516>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.sampleTime != 0.0) {
        // Outputs for IfAction SubSystem: '<S516>/Hold this value' incorporates:
        //   ActionPort: '<S536>/Action Port'

        // SignalConversion generated from: '<S536>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_fy =
          APF_Path_Planning_2023a_BlueI_B.sampleTime;

        // End of Outputs for SubSystem: '<S516>/Hold this value'
      }

      // End of If: '<S516>/if we went through a "step"'

      // Gain: '<S516>/divide by delta T'
      APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_c = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_fy;

      // Delay: '<S513>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_fpv) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_pc =
          APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_c;
      }

      // End of Delay: '<S513>/Delay1'

      // S-Function (sdspunwrap2): '<S505>/Unwrap2'
      if (APF_Path_Planning_2023a_Blue_DW.Unwrap2_FirstStep) {
        APF_Path_Planning_2023a_Blue_DW.Unwrap2_Prev =
          APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[9];
        APF_Path_Planning_2023a_Blue_DW.Unwrap2_FirstStep = false;
      }

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[9] -
        APF_Path_Planning_2023a_Blue_DW.Unwrap2_Prev;
      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_BlueI_B.sampleTime - floor
        ((APF_Path_Planning_2023a_BlueI_B.sampleTime + 3.1415926535897931) /
         6.2831853071795862) * 6.2831853071795862;
      if ((APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW == -3.1415926535897931) &&
          (APF_Path_Planning_2023a_BlueI_B.sampleTime > 0.0)) {
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 3.1415926535897931;
      }

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW -
        APF_Path_Planning_2023a_BlueI_B.sampleTime;
      if (fabs(APF_Path_Planning_2023a_BlueI_B.sampleTime) > 3.1415926535897931)
      {
        APF_Path_Planning_2023a_Blue_DW.Unwrap2_Cumsum +=
          APF_Path_Planning_2023a_BlueI_B.sampleTime;
      }

      APF_Path_Planning_2023a_Blue_DW.Unwrap2_Prev =
        APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[9];

      // S-Function (sdspunwrap2): '<S505>/Unwrap2'
      APF_Path_Planning_2023a_BlueI_B.Unwrap2 =
        APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[9] +
        APF_Path_Planning_2023a_Blue_DW.Unwrap2_Cumsum;

      // Delay: '<S517>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_mt) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_cu =
          APF_Path_Planning_2023a_BlueI_B.Unwrap2;
      }

      // Sum: '<S517>/Sum6' incorporates:
      //   Delay: '<S517>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.Unwrap2 -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_cu;

      // If: '<S517>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.sampleTime != 0.0) {
        // Outputs for IfAction SubSystem: '<S517>/Hold this value' incorporates:
        //   ActionPort: '<S537>/Action Port'

        // SignalConversion generated from: '<S537>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_gd =
          APF_Path_Planning_2023a_BlueI_B.sampleTime;

        // End of Outputs for SubSystem: '<S517>/Hold this value'
      }

      // End of If: '<S517>/if we went through a "step"'

      // Gain: '<S517>/divide by delta T'
      APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_cy = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_gd;

      // Delay: '<S514>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_nw) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_a0 =
          APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_cy;
      }

      // End of Delay: '<S514>/Delay1'

      // DataStoreWrite: '<S505>/RED_Px17'
      APF_Path_Planning_2023a_Blue_DW.BLUE_Vx =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT;

      // Sum: '<S566>/Sum' incorporates:
      //   DataStoreWrite: '<S505>/RED_Px18'
      //   DataStoreWrite: '<S505>/RED_Px19'

      APF_Path_Planning_2023a_Blue_DW.BLUE_Px =
        APF_Path_Planning_2023a_BlueI_B.ConvertBLUXfrommmtom;
      APF_Path_Planning_2023a_Blue_DW.BLUE_Py =
        APF_Path_Planning_2023a_BlueI_B.ConvertBLUYfrommmtom;

      // Delay: '<S508>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_h) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_h =
          APF_Path_Planning_2023a_BlueI_B.ConvertREDXfrommmtom;
      }

      // Sum: '<S508>/Sum6' incorporates:
      //   Delay: '<S508>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.ConvertREDXfrommmtom -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_h;

      // If: '<S508>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.sampleTime != 0.0) {
        // Outputs for IfAction SubSystem: '<S508>/Hold this value' incorporates:
        //   ActionPort: '<S528>/Action Port'

        // SignalConversion generated from: '<S528>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_gt =
          APF_Path_Planning_2023a_BlueI_B.sampleTime;

        // End of Outputs for SubSystem: '<S508>/Hold this value'
      }

      // End of If: '<S508>/if we went through a "step"'

      // Gain: '<S508>/divide by delta T'
      APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_n = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_gt;

      // DataStoreWrite: '<S505>/RED_Px2'
      APF_Path_Planning_2023a_Blue_DW.RED_Vx =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_n;

      // Sum: '<S566>/Sum' incorporates:
      //   DataStoreWrite: '<S505>/RED_Px20'

      APF_Path_Planning_2023a_Blue_DW.BLUE_Rz =
        APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[9];

      // DataStoreWrite: '<S505>/RED_Px3'
      APF_Path_Planning_2023a_Blue_DW.BLACK_Vx =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_f;

      // Sum: '<S552>/Sum' incorporates:
      //   DataStoreWrite: '<S505>/RED_Px4'
      //   DataStoreWrite: '<S505>/RED_Px5'
      //   DataStoreWrite: '<S505>/RED_Px6'

      APF_Path_Planning_2023a_Blue_DW.BLACK_Px =
        APF_Path_Planning_2023a_BlueI_B.ConvertBLAXfrommmtom;
      APF_Path_Planning_2023a_Blue_DW.BLACK_Py =
        APF_Path_Planning_2023a_BlueI_B.ConvertBLAYfrommmtom;
      APF_Path_Planning_2023a_Blue_DW.BLACK_Rz =
        APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[6];

      // Delay: '<S523>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_au) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_ah =
          APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_n;
      }

      // Sum: '<S523>/Sum6' incorporates:
      //   Delay: '<S523>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_n -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_ah;

      // If: '<S523>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.sampleTime != 0.0) {
        // Outputs for IfAction SubSystem: '<S523>/Hold this value' incorporates:
        //   ActionPort: '<S543>/Action Port'

        // SignalConversion generated from: '<S543>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_f =
          APF_Path_Planning_2023a_BlueI_B.sampleTime;

        // End of Outputs for SubSystem: '<S523>/Hold this value'
      }

      // End of If: '<S523>/if we went through a "step"'

      // Gain: '<S523>/divide by delta T' incorporates:
      //   DataStoreWrite: '<S505>/RED_Px7'

      APF_Path_Planning_2023a_Blue_DW.RED_Ax = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_f;

      // Gain: '<S505>/Convert REDY from [mm] to [m]'
      APF_Path_Planning_2023a_BlueI_B.ConvertREDYfrommmtom =
        APF_Path_Planning_2023a_BlueI_P.ConvertREDYfrommmtom_Gain *
        APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[2];

      // Delay: '<S518>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_eob) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_lx =
          APF_Path_Planning_2023a_BlueI_B.ConvertREDYfrommmtom;
      }

      // Sum: '<S518>/Sum6' incorporates:
      //   Delay: '<S518>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.ConvertREDYfrommmtom -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_lx;

      // If: '<S518>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.sampleTime != 0.0) {
        // Outputs for IfAction SubSystem: '<S518>/Hold this value' incorporates:
        //   ActionPort: '<S538>/Action Port'

        // SignalConversion generated from: '<S538>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_em =
          APF_Path_Planning_2023a_BlueI_B.sampleTime;

        // End of Outputs for SubSystem: '<S518>/Hold this value'
      }

      // End of If: '<S518>/if we went through a "step"'

      // Gain: '<S518>/divide by delta T'
      APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_n1 = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_em;

      // Delay: '<S524>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_fh) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_j3 =
          APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_n1;
      }

      // Sum: '<S524>/Sum6' incorporates:
      //   Delay: '<S524>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_n1 -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_j3;

      // If: '<S524>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.sampleTime != 0.0) {
        // Outputs for IfAction SubSystem: '<S524>/Hold this value' incorporates:
        //   ActionPort: '<S544>/Action Port'

        // SignalConversion generated from: '<S544>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_l =
          APF_Path_Planning_2023a_BlueI_B.sampleTime;

        // End of Outputs for SubSystem: '<S524>/Hold this value'
      }

      // End of If: '<S524>/if we went through a "step"'

      // Gain: '<S524>/divide by delta T' incorporates:
      //   DataStoreWrite: '<S505>/RED_Px8'

      APF_Path_Planning_2023a_Blue_DW.RED_Ay = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_l;

      // S-Function (sdspunwrap2): '<S505>/Unwrap'
      if (APF_Path_Planning_2023a_Blue_DW.Unwrap_FirstStep) {
        APF_Path_Planning_2023a_Blue_DW.Unwrap_Prev =
          APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[3];
        APF_Path_Planning_2023a_Blue_DW.Unwrap_FirstStep = false;
      }

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[3] -
        APF_Path_Planning_2023a_Blue_DW.Unwrap_Prev;
      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_BlueI_B.sampleTime - floor
        ((APF_Path_Planning_2023a_BlueI_B.sampleTime + 3.1415926535897931) /
         6.2831853071795862) * 6.2831853071795862;
      if ((APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW == -3.1415926535897931) &&
          (APF_Path_Planning_2023a_BlueI_B.sampleTime > 0.0)) {
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW = 3.1415926535897931;
      }

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW -
        APF_Path_Planning_2023a_BlueI_B.sampleTime;
      if (fabs(APF_Path_Planning_2023a_BlueI_B.sampleTime) > 3.1415926535897931)
      {
        APF_Path_Planning_2023a_Blue_DW.Unwrap_Cumsum +=
          APF_Path_Planning_2023a_BlueI_B.sampleTime;
      }

      APF_Path_Planning_2023a_Blue_DW.Unwrap_Prev =
        APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[3];

      // S-Function (sdspunwrap2): '<S505>/Unwrap'
      APF_Path_Planning_2023a_BlueI_B.Unwrap =
        APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[3] +
        APF_Path_Planning_2023a_Blue_DW.Unwrap_Cumsum;

      // Delay: '<S519>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_fow) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_m2 =
          APF_Path_Planning_2023a_BlueI_B.Unwrap;
      }

      // Sum: '<S519>/Sum6' incorporates:
      //   Delay: '<S519>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.Unwrap -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_m2;

      // If: '<S519>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.sampleTime != 0.0) {
        // Outputs for IfAction SubSystem: '<S519>/Hold this value' incorporates:
        //   ActionPort: '<S539>/Action Port'

        // SignalConversion generated from: '<S539>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_en =
          APF_Path_Planning_2023a_BlueI_B.sampleTime;

        // End of Outputs for SubSystem: '<S519>/Hold this value'
      }

      // End of If: '<S519>/if we went through a "step"'

      // Gain: '<S519>/divide by delta T'
      APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_m = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_en;

      // Delay: '<S525>/Delay1'
      if (APF_Path_Planning_2023a_Blue_DW.icLoad_aq) {
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_hi =
          APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_m;
      }

      // Sum: '<S525>/Sum6' incorporates:
      //   Delay: '<S525>/Delay1'

      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_m -
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_hi;

      // If: '<S525>/if we went through a "step"'
      if (APF_Path_Planning_2023a_BlueI_B.sampleTime != 0.0) {
        // Outputs for IfAction SubSystem: '<S525>/Hold this value' incorporates:
        //   ActionPort: '<S545>/Action Port'

        // SignalConversion generated from: '<S545>/In1'
        APF_Path_Planning_2023a_BlueI_B.In1_e0 =
          APF_Path_Planning_2023a_BlueI_B.sampleTime;

        // End of Outputs for SubSystem: '<S525>/Hold this value'
      }

      // End of If: '<S525>/if we went through a "step"'

      // Gain: '<S525>/divide by delta T' incorporates:
      //   DataStoreWrite: '<S505>/RED_Px9'

      APF_Path_Planning_2023a_Blue_DW.RED_RzDD = 1.0 /
        APF_Path_Planning_2023a_BlueI_P.baseRate *
        APF_Path_Planning_2023a_BlueI_B.In1_e0;

      // DataStoreWrite: '<S505>/RED_Py1'
      APF_Path_Planning_2023a_Blue_DW.RED_Py =
        APF_Path_Planning_2023a_BlueI_B.ConvertREDYfrommmtom;

      // DataStoreWrite: '<S505>/RED_Py2'
      APF_Path_Planning_2023a_Blue_DW.RED_Vy =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_n1;

      // DataStoreWrite: '<S505>/RED_Py3'
      APF_Path_Planning_2023a_Blue_DW.BLACK_Vy =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_l;

      // DataStoreWrite: '<S505>/RED_Py4'
      APF_Path_Planning_2023a_Blue_DW.BLUE_Vy =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_c;

      // DataStoreWrite: '<S505>/RED_Rz1'
      APF_Path_Planning_2023a_Blue_DW.RED_Rz =
        APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[3];

      // DataStoreWrite: '<S505>/RED_Rz2'
      APF_Path_Planning_2023a_Blue_DW.RED_RzD =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_m;

      // DataStoreWrite: '<S505>/RED_Rz3'
      APF_Path_Planning_2023a_Blue_DW.BLACK_RzD =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_e;

      // DataStoreWrite: '<S505>/RED_Rz4'
      APF_Path_Planning_2023a_Blue_DW.BLUE_RzD =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_cy;

      // MATLAB Function: '<S505>/MATLAB Function' incorporates:
      //   Delay: '<S505>/Delay'
      //   Delay: '<S505>/Delay1'
      //   Delay: '<S505>/Delay2'

      APF_Path_Planning_2023a_BlueI_B.StartClock = 0;
      if (APF_Path_Planning_2023a_BlueI_P.platformSelection == 1.0) {
        APF_Path_Planning_2023a_BlueI_B.StartClock =
          (APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_l[0] == 1);
      } else if (APF_Path_Planning_2023a_BlueI_P.platformSelection == 2.0) {
        APF_Path_Planning_2023a_BlueI_B.StartClock =
          (APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_hu[0] == 1);
      } else if (APF_Path_Planning_2023a_BlueI_P.platformSelection == 3.0) {
        APF_Path_Planning_2023a_BlueI_B.StartClock =
          ((APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_l[0] == 1) &&
           (APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_hu[0] == 1));
      } else if (APF_Path_Planning_2023a_BlueI_P.platformSelection == 4.0) {
        APF_Path_Planning_2023a_BlueI_B.StartClock =
          ((APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_l[0] == 1) &&
           (APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_hu[0] == 1));
      } else if (APF_Path_Planning_2023a_BlueI_P.platformSelection == 5.0) {
        APF_Path_Planning_2023a_BlueI_B.StartClock =
          (APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_l[0] == 1);
      } else if (APF_Path_Planning_2023a_BlueI_P.platformSelection == 6.0) {
        APF_Path_Planning_2023a_BlueI_B.StartClock =
          (APF_Path_Planning_2023a_Blue_DW.Delay2_DSTATE_k[0] == 1);
      } else if (APF_Path_Planning_2023a_BlueI_P.platformSelection == 7.0) {
        APF_Path_Planning_2023a_BlueI_B.StartClock =
          ((APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_l[0] == 1) &&
           (APF_Path_Planning_2023a_Blue_DW.Delay2_DSTATE_k[0] == 1));
      } else if (APF_Path_Planning_2023a_BlueI_P.platformSelection == 8.0) {
        APF_Path_Planning_2023a_BlueI_B.StartClock =
          ((APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_l[0] == 1) &&
           (APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_hu[0] == 1) &&
           (APF_Path_Planning_2023a_Blue_DW.Delay2_DSTATE_k[0] == 1));
      } else if (APF_Path_Planning_2023a_BlueI_P.platformSelection == 9.0) {
        APF_Path_Planning_2023a_BlueI_B.StartClock =
          ((APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_hu[0] == 1) &&
           (APF_Path_Planning_2023a_Blue_DW.Delay2_DSTATE_k[0] == 1));
      } else if (APF_Path_Planning_2023a_BlueI_P.platformSelection == 10.0) {
        APF_Path_Planning_2023a_BlueI_B.StartClock =
          ((APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_l[0] == 1) &&
           (APF_Path_Planning_2023a_Blue_DW.Delay2_DSTATE_k[0] == 1));
      } else if (APF_Path_Planning_2023a_BlueI_P.platformSelection == 11.0) {
        APF_Path_Planning_2023a_BlueI_B.StartClock =
          ((APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_l[0] == 1) &&
           (APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_hu[0] == 1) &&
           (APF_Path_Planning_2023a_Blue_DW.Delay2_DSTATE_k[0] == 1));
      }

      // End of MATLAB Function: '<S505>/MATLAB Function'

      // Outputs for Enabled SubSystem: '<S506>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S526>/Enable'

      if (APF_Path_Planning_2023a_BlueI_B.StartClock !=
          APF_Path_Planning_2023a_BlueI_P.Constant_Value) {
        // Memory: '<S526>/Memory'
        APF_Path_Planning_2023a_BlueI_B.Memory =
          APF_Path_Planning_2023a_Blue_DW.Memory_PreviousInput;

        // Update for Memory: '<S526>/Memory'
        APF_Path_Planning_2023a_Blue_DW.Memory_PreviousInput =
          APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[0];
      }

      // End of Outputs for SubSystem: '<S506>/Enabled Subsystem'

      // Outputs for Enabled SubSystem: '<S506>/Enabled Subsystem1' incorporates:
      //   EnablePort: '<S527>/Enable'

      if (APF_Path_Planning_2023a_BlueI_B.StartClock ==
          APF_Path_Planning_2023a_BlueI_P.Constant_Value) {
        // Sum: '<S527>/Subtract'
        APF_Path_Planning_2023a_BlueI_B.Subtract_l =
          APF_Path_Planning_2023a_BlueI_B.UDPReceive1_o1[0] -
          APF_Path_Planning_2023a_BlueI_B.Memory;
      }

      // End of Outputs for SubSystem: '<S506>/Enabled Subsystem1'

      // DataStoreWrite: '<S505>/Universal_Time' incorporates:
      //   Constant: '<S506>/Constant'
      //   RelationalOperator: '<S506>/Relational Operator'
      //   RelationalOperator: '<S506>/Relational Operator1'

      APF_Path_Planning_2023a_Blue_DW.Univ_Time =
        APF_Path_Planning_2023a_BlueI_B.Subtract_l;

      // S-Function (sdspFromNetwork): '<S505>/UDP Receive'
      sErr = GetErrorBuffer
        (&APF_Path_Planning_2023a_Blue_DW.UDPReceive_NetworkLib[0U]);
      APF_Path_Planning_2023a_BlueI_B.StartClock = 1;
      LibOutputs_Network(&APF_Path_Planning_2023a_Blue_DW.UDPReceive_NetworkLib
                         [0U], &APF_Path_Planning_2023a_BlueI_B.UDPReceive_o1,
                         &APF_Path_Planning_2023a_BlueI_B.StartClock);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
      }

      // End of S-Function (sdspFromNetwork): '<S505>/UDP Receive'

      // S-Function (sdspFromNetwork): '<S505>/UDP Receive2'
      sErr = GetErrorBuffer
        (&APF_Path_Planning_2023a_Blue_DW.UDPReceive2_NetworkLib[0U]);
      APF_Path_Planning_2023a_BlueI_B.yElIdx = 1;
      LibOutputs_Network
        (&APF_Path_Planning_2023a_Blue_DW.UDPReceive2_NetworkLib[0U],
         &APF_Path_Planning_2023a_BlueI_B.UDPReceive2_o1,
         &APF_Path_Planning_2023a_BlueI_B.yElIdx);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
      }

      // End of S-Function (sdspFromNetwork): '<S505>/UDP Receive2'

      // S-Function (sdspFromNetwork): '<S505>/UDP Receive3'
      sErr = GetErrorBuffer
        (&APF_Path_Planning_2023a_Blue_DW.UDPReceive3_NetworkLib[0U]);
      APF_Path_Planning_2023a_BlueI_B.uElOffset1 = 1;
      LibOutputs_Network
        (&APF_Path_Planning_2023a_Blue_DW.UDPReceive3_NetworkLib[0U],
         &APF_Path_Planning_2023a_BlueI_B.UDPReceive3_o1,
         &APF_Path_Planning_2023a_BlueI_B.uElOffset1);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
      }

      // End of S-Function (sdspFromNetwork): '<S505>/UDP Receive3'
      // End of Outputs for SubSystem: '<S13>/Use Hardware to Obtain States'
      break;

     case 1:
      // Outputs for IfAction SubSystem: '<S13>/Initialize Universal Time (Simulation)' incorporates:
      //   ActionPort: '<S504>/Action Port'

      // Clock: '<S504>/Set Universal Time (If this is a simulation)' incorporates:
      //   DataStoreWrite: '<S504>/Universal_Time'

      APF_Path_Planning_2023a_Blue_DW.Univ_Time =
        APF_Path_Planning_2023a_Blue_M->Timing.t[0];

      // End of Outputs for SubSystem: '<S13>/Initialize Universal Time (Simulation)' 
      break;
    }

    // End of If: '<S13>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 

    // If: '<S14>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' incorporates:
    //   DataStoreRead: '<S14>/Data Store Read1'

    if (APF_Path_Planning_2023a_BlueI_B.isSim == 0.0) {
      // Outputs for IfAction SubSystem: '<S14>/Subsystem' incorporates:
      //   ActionPort: '<S546>/Action Port'

      // MATLABSystem: '<S546>/WhoAmI' incorporates:
      //   DataStoreWrite: '<S546>/Data Store Write'

      if (APF_Path_Planning_2023a_Blue_DW.obj_dk.SampleTime !=
          APF_Path_Planning_2023a_BlueI_P.baseRate) {
        if (((!rtIsInf(APF_Path_Planning_2023a_BlueI_P.baseRate)) && (!rtIsNaN
              (APF_Path_Planning_2023a_BlueI_P.baseRate))) || rtIsInf
            (APF_Path_Planning_2023a_BlueI_P.baseRate)) {
          APF_Path_Planning_2023a_BlueI_B.sampleTime_n =
            APF_Path_Planning_2023a_BlueI_P.baseRate;
        }

        APF_Path_Planning_2023a_Blue_DW.obj_dk.SampleTime =
          APF_Path_Planning_2023a_BlueI_B.sampleTime_n;
      }

      //         %% Define output properties
      //  Call C-function implementing device output
      APF_Path_Planning_2023a_Blue_DW.WhoAmI = WhoAmI();

      // End of MATLABSystem: '<S546>/WhoAmI'
      // End of Outputs for SubSystem: '<S14>/Subsystem'
    }

    // End of If: '<S14>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 

    // If: '<S15>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
    //   DataStoreRead: '<S15>/Data Store Read'
    //   DataStoreRead: '<S15>/Data Store Read1'

    if ((APF_Path_Planning_2023a_Blue_DW.WhoAmI == 1.0) &&
        (APF_Path_Planning_2023a_BlueI_B.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S15>/Change RED Behavior' incorporates:
      //   ActionPort: '<S547>/Action Port'

      // MATLABSystem: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' incorporates:
      //   DataStoreRead: '<S547>/Arm Control Mode'
      //   DataStoreRead: '<S547>/Elbow Command'
      //   DataStoreRead: '<S547>/Shoulder Command'
      //   DataStoreRead: '<S547>/Wrist Command'

      if (APF_Path_Planning_2023a_Blue_DW.obj.POSITION_P_GAIN !=
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsineith) {
        APF_Path_Planning_2023a_Blue_DW.obj.POSITION_P_GAIN =
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsineith;
      }

      if (APF_Path_Planning_2023a_Blue_DW.obj.POSITION_I_GAIN !=
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_c) {
        APF_Path_Planning_2023a_Blue_DW.obj.POSITION_I_GAIN =
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_c;
      }

      if (APF_Path_Planning_2023a_Blue_DW.obj.POSITION_D_GAIN !=
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_d) {
        APF_Path_Planning_2023a_Blue_DW.obj.POSITION_D_GAIN =
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_d;
      }

      if (APF_Path_Planning_2023a_Blue_DW.obj.MAX_POSITION !=
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_n) {
        APF_Path_Planning_2023a_Blue_DW.obj.MAX_POSITION =
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_n;
      }

      if (APF_Path_Planning_2023a_Blue_DW.obj.MIN_POSITION !=
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_g) {
        APF_Path_Planning_2023a_Blue_DW.obj.MIN_POSITION =
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_g;
      }

      if (APF_Path_Planning_2023a_Blue_DW.obj.MOVE_TIME !=
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsine_cw) {
        APF_Path_Planning_2023a_Blue_DW.obj.MOVE_TIME =
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsine_cw;
      }

      if (APF_Path_Planning_2023a_Blue_DW.obj.CURRENT_LIMIT !=
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_e) {
        APF_Path_Planning_2023a_Blue_DW.obj.CURRENT_LIMIT =
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_e;
      }

      if (APF_Path_Planning_2023a_Blue_DW.obj.SPEED_P_GAIN !=
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_k) {
        APF_Path_Planning_2023a_Blue_DW.obj.SPEED_P_GAIN =
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_k;
      }

      if (APF_Path_Planning_2023a_Blue_DW.obj.SPEED_I_GAIN !=
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_j) {
        APF_Path_Planning_2023a_Blue_DW.obj.SPEED_I_GAIN =
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_j;
      }

      if (APF_Path_Planning_2023a_Blue_DW.obj.VELOCITY_LIMIT !=
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_l) {
        APF_Path_Planning_2023a_Blue_DW.obj.VELOCITY_LIMIT =
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_l;
      }

      if (APF_Path_Planning_2023a_Blue_DW.obj.ACCELERATION_TIME !=
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_o) {
        APF_Path_Planning_2023a_Blue_DW.obj.ACCELERATION_TIME =
          APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_o;
      }

      if (APF_Path_Planning_2023a_Blue_DW.obj.SampleTime !=
          APF_Path_Planning_2023a_BlueI_P.baseRate) {
        if (((!rtIsInf(APF_Path_Planning_2023a_BlueI_P.baseRate)) && (!rtIsNaN
              (APF_Path_Planning_2023a_BlueI_P.baseRate))) || rtIsInf
            (APF_Path_Planning_2023a_BlueI_P.baseRate)) {
          APF_Path_Planning_2023a_BlueI_B.sampleTime_b =
            APF_Path_Planning_2023a_BlueI_P.baseRate;
        }

        APF_Path_Planning_2023a_Blue_DW.obj.SampleTime =
          APF_Path_Planning_2023a_BlueI_B.sampleTime_b;
      }

      //         %% Define input properties
      //  Call C-function implementing device output
      //  include the dynamicel functions
      //  Run the main controller code. If the switch state is
      //  true then this code will initialize the parameters and
      //  then start the actuator, and THEN run the command. If the
      //  switch state is false, it will not reinitialize the
      //  motor
      dynamixel_controller(APF_Path_Planning_2023a_Blue_DW.RED_ARM_Control_Mode,
                           APF_Path_Planning_2023a_Blue_DW.obj.POSITION_P_GAIN,
                           APF_Path_Planning_2023a_Blue_DW.obj.POSITION_I_GAIN,
                           APF_Path_Planning_2023a_Blue_DW.obj.POSITION_D_GAIN,
                           APF_Path_Planning_2023a_Blue_DW.obj.MAX_POSITION,
                           APF_Path_Planning_2023a_Blue_DW.obj.MIN_POSITION,
                           APF_Path_Planning_2023a_Blue_DW.obj.MOVE_TIME,
                           APF_Path_Planning_2023a_Blue_DW.RED_Shoulder_Command,
                           APF_Path_Planning_2023a_Blue_DW.RED_Elbow_Command,
                           APF_Path_Planning_2023a_Blue_DW.RED_Wrist_Command,
                           APF_Path_Planning_2023a_Blue_DW.obj.CURRENT_LIMIT,
                           APF_Path_Planning_2023a_Blue_DW.RED_Shoulder_Command,
                           APF_Path_Planning_2023a_Blue_DW.RED_Elbow_Command,
                           APF_Path_Planning_2023a_Blue_DW.RED_Wrist_Command,
                           APF_Path_Planning_2023a_Blue_DW.obj.SPEED_P_GAIN,
                           APF_Path_Planning_2023a_Blue_DW.obj.SPEED_I_GAIN,
                           APF_Path_Planning_2023a_Blue_DW.obj.VELOCITY_LIMIT,
                           APF_Path_Planning_2023a_Blue_DW.RED_Shoulder_Command,
                           APF_Path_Planning_2023a_Blue_DW.RED_Elbow_Command,
                           APF_Path_Planning_2023a_Blue_DW.RED_Wrist_Command,
                           APF_Path_Planning_2023a_Blue_DW.obj.ACCELERATION_TIME);

      // End of MATLABSystem: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
      // End of Outputs for SubSystem: '<S15>/Change RED Behavior'
    }

    // End of If: '<S15>/This IF block determines whether or not to run the RED sim//exp ' 

    // If: '<S16>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' incorporates:
    //   DataStoreRead: '<S16>/Data Store Read1'

    if (APF_Path_Planning_2023a_BlueI_B.isSim == 0.0) {
      // Outputs for IfAction SubSystem: '<S16>/Subsystem' incorporates:
      //   ActionPort: '<S548>/Action Port'

      // SignalConversion generated from: '<S548>/UDP Send' incorporates:
      //   DataStoreRead: '<S548>/BLACK_Px'
      //   DataStoreRead: '<S548>/BLACK_Py'
      //   DataStoreRead: '<S548>/BLACK_Rz'
      //   DataStoreRead: '<S548>/BLACK_RzD'
      //   DataStoreRead: '<S548>/BLACK_Vx'
      //   DataStoreRead: '<S548>/BLACK_Vy'
      //   DataStoreRead: '<S548>/BLUE_Px'
      //   DataStoreRead: '<S548>/BLUE_Py'
      //   DataStoreRead: '<S548>/BLUE_Rz'
      //   DataStoreRead: '<S548>/BLUE_RzD'
      //   DataStoreRead: '<S548>/BLUE_Vx'
      //   DataStoreRead: '<S548>/BLUE_Vy'
      //   DataStoreRead: '<S548>/RED_Px'
      //   DataStoreRead: '<S548>/RED_Py '
      //   DataStoreRead: '<S548>/RED_Rz'
      //   DataStoreRead: '<S548>/RED_Vx '
      //   DataStoreRead: '<S548>/RED_Vy'
      //   DataStoreRead: '<S548>/RED_Vz'
      //   DataStoreRead: '<S548>/Time'

      APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendI_o[0] =
        APF_Path_Planning_2023a_Blue_DW.Univ_Time;
      APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendI_o[1] =
        APF_Path_Planning_2023a_Blue_DW.RED_Px;
      APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendI_o[2] =
        APF_Path_Planning_2023a_Blue_DW.RED_Py;
      APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendI_o[3] =
        APF_Path_Planning_2023a_Blue_DW.RED_Rz;
      APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendI_o[4] =
        APF_Path_Planning_2023a_Blue_DW.RED_Vx;
      APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendI_o[5] =
        APF_Path_Planning_2023a_Blue_DW.RED_Vy;
      APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendI_o[6] =
        APF_Path_Planning_2023a_Blue_DW.RED_RzD;
      APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendI_o[7] =
        APF_Path_Planning_2023a_Blue_DW.BLACK_Px;
      APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendI_o[8] =
        APF_Path_Planning_2023a_Blue_DW.BLACK_Py;
      APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendI_o[9] =
        APF_Path_Planning_2023a_Blue_DW.BLACK_Rz;
      APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendI_o[10] =
        APF_Path_Planning_2023a_Blue_DW.BLACK_Vx;
      APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendI_o[11] =
        APF_Path_Planning_2023a_Blue_DW.BLACK_Vy;
      APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendI_o[12] =
        APF_Path_Planning_2023a_Blue_DW.BLACK_RzD;
      APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendI_o[13] =
        APF_Path_Planning_2023a_Blue_DW.BLUE_Px;
      APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendI_o[14] =
        APF_Path_Planning_2023a_Blue_DW.BLUE_Py;
      APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendI_o[15] =
        APF_Path_Planning_2023a_Blue_DW.BLUE_Rz;
      APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendI_o[16] =
        APF_Path_Planning_2023a_Blue_DW.BLUE_Vx;
      APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendI_o[17] =
        APF_Path_Planning_2023a_Blue_DW.BLUE_Vy;
      APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendI_o[18] =
        APF_Path_Planning_2023a_Blue_DW.BLUE_RzD;

      // Update for S-Function (sdspToNetwork): '<S548>/UDP Send' incorporates:
      //   SignalConversion generated from: '<S548>/UDP Send'
      //
      sErr = GetErrorBuffer
        (&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_m[0U]);
      LibUpdate_Network(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_m[0U],
                        &APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendI_o
                        [0U], 19);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
      }

      // End of Update for S-Function (sdspToNetwork): '<S548>/UDP Send'
      // End of Outputs for SubSystem: '<S16>/Subsystem'
    }

    // End of If: '<S16>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 

    // If: '<S19>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
    //   DataStoreRead: '<S19>/Data Store Read'
    //   DataStoreRead: '<S19>/Data Store Read1'
    //   If: '<S634>/If'
    //   If: '<S634>/If1'
    //   If: '<S634>/If2'
    //   MATLAB Function: '<S634>/MATLAB Function4'
    //   MATLAB Function: '<S634>/MATLAB Function7'

    if ((APF_Path_Planning_2023a_Blue_DW.WhoAmI == 1.0) ||
        (APF_Path_Planning_2023a_BlueI_B.isSim == 1.0)) {
      // Outputs for IfAction SubSystem: '<S19>/Change RED Behavior' incorporates:
      //   ActionPort: '<S609>/Action Port'

      // MATLAB Function: '<S634>/MATLAB Function3'
      memset(&APF_Path_Planning_2023a_BlueI_B.y[0], 0, sizeof(real_T) << 6U);

      // MATLAB Function: '<S634>/MATLAB Function' incorporates:
      //   DataStoreRead: '<S634>/Data Store Read'
      //   DataStoreRead: '<S634>/Data Store Read7'
      //   DataStoreRead: '<S634>/Data Store Read8'
      //   MATLAB Function: '<S634>/MATLAB Function4'
      //   MATLAB Function: '<S634>/MATLAB Function6'

      APF_Path_Planning_2023a_BlueI_B.sampleTime = cos
        (APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder + 1.5707963267948966);
      APF_Path_Planning_2023a_BlueI_B.link1_com_x =
        APF_Path_Planning_2023a_BlueI_P.b0 * cos
        (APF_Path_Planning_2023a_BlueI_P.Phi) +
        APF_Path_Planning_2023a_BlueI_P.a1 *
        APF_Path_Planning_2023a_BlueI_B.sampleTime;
      APF_Path_Planning_2023a_BlueI_B.sampleTime_b = sin
        (APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder + 1.5707963267948966);
      APF_Path_Planning_2023a_BlueI_B.link1_com_y =
        APF_Path_Planning_2023a_BlueI_P.b0 * sin
        (APF_Path_Planning_2023a_BlueI_P.Phi) +
        APF_Path_Planning_2023a_BlueI_P.a1 *
        APF_Path_Planning_2023a_BlueI_B.sampleTime_b;
      APF_Path_Planning_2023a_BlueI_B.sampleTime_n =
        (APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder + 1.5707963267948966) +
        APF_Path_Planning_2023a_Blue_DW.RED_Rz_Elbow;
      APF_Path_Planning_2023a_BlueI_B.q = cos
        (APF_Path_Planning_2023a_BlueI_B.sampleTime_n);
      APF_Path_Planning_2023a_BlueI_B.absxk =
        (APF_Path_Planning_2023a_BlueI_P.b1 *
         APF_Path_Planning_2023a_BlueI_B.sampleTime +
         APF_Path_Planning_2023a_BlueI_B.link1_com_x) +
        APF_Path_Planning_2023a_BlueI_P.a2 * APF_Path_Planning_2023a_BlueI_B.q;
      APF_Path_Planning_2023a_BlueI_B.t = sin
        (APF_Path_Planning_2023a_BlueI_B.sampleTime_n);
      APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 =
        (APF_Path_Planning_2023a_BlueI_P.b1 *
         APF_Path_Planning_2023a_BlueI_B.sampleTime_b +
         APF_Path_Planning_2023a_BlueI_B.link1_com_y) +
        APF_Path_Planning_2023a_BlueI_P.a2 * APF_Path_Planning_2023a_BlueI_B.t;
      APF_Path_Planning_2023a_BlueI_B.absx_tmp =
        APF_Path_Planning_2023a_BlueI_B.sampleTime_n +
        APF_Path_Planning_2023a_Blue_DW.RED_Rz_Wrist;
      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        ((APF_Path_Planning_2023a_BlueI_P.mRED +
          APF_Path_Planning_2023a_BlueI_P.mPROX) +
         APF_Path_Planning_2023a_BlueI_P.mDIST) +
        APF_Path_Planning_2023a_BlueI_P.mEE;
      APF_Path_Planning_2023a_BlueI_B.Switch = cos
        (APF_Path_Planning_2023a_BlueI_B.absx_tmp) *
        APF_Path_Planning_2023a_BlueI_P.a3;
      APF_Path_Planning_2023a_BlueI_B.sampleTime_n =
        (((APF_Path_Planning_2023a_BlueI_P.b2 *
           APF_Path_Planning_2023a_BlueI_B.q +
           APF_Path_Planning_2023a_BlueI_B.absxk) +
          APF_Path_Planning_2023a_BlueI_B.Switch) *
         APF_Path_Planning_2023a_BlueI_P.mEE +
         (APF_Path_Planning_2023a_BlueI_P.mPROX *
          APF_Path_Planning_2023a_BlueI_B.link1_com_x +
          APF_Path_Planning_2023a_BlueI_P.mDIST *
          APF_Path_Planning_2023a_BlueI_B.absxk)) /
        APF_Path_Planning_2023a_BlueI_B.sampleTime * 1000.0;
      APF_Path_Planning_2023a_BlueI_B.Derivative2 = sin
        (APF_Path_Planning_2023a_BlueI_B.absx_tmp) *
        APF_Path_Planning_2023a_BlueI_P.a3;
      APF_Path_Planning_2023a_BlueI_B.sampleTime_b =
        (((APF_Path_Planning_2023a_BlueI_P.b2 *
           APF_Path_Planning_2023a_BlueI_B.t +
           APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1) +
          APF_Path_Planning_2023a_BlueI_B.Derivative2) *
         APF_Path_Planning_2023a_BlueI_P.mEE +
         (APF_Path_Planning_2023a_BlueI_P.mPROX *
          APF_Path_Planning_2023a_BlueI_B.link1_com_y +
          APF_Path_Planning_2023a_BlueI_P.mDIST *
          APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1)) /
        APF_Path_Planning_2023a_BlueI_B.sampleTime * 1000.0;
      for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset < 8;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
        // MATLAB Function: '<S634>/MATLAB Function3'
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_P.F_thrusters_RED[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        APF_Path_Planning_2023a_BlueI_B.y[APF_Path_Planning_2023a_BlueI_B.b_xoffset
          + (APF_Path_Planning_2023a_BlueI_B.b_xoffset << 3)] =
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

        // MATLAB Function: '<S634>/MATLAB Function'
        APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.b_xoffset]
          = APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW / 2.0;
      }

      // MATLAB Function: '<S634>/MATLAB Function'
      memset(&APF_Path_Planning_2023a_BlueI_B.y_c[0], 0, sizeof(real_T) << 6U);

      // If: '<S634>/If' incorporates:
      //   Constant: '<S634>/Constant'

      APF_Path_Planning_2023a_BlueI_B.Reject =
        ((APF_Path_Planning_2023a_BlueI_P.platformSelection == 4.0) ||
         (APF_Path_Planning_2023a_BlueI_P.platformSelection == 5.0) ||
         (APF_Path_Planning_2023a_BlueI_P.platformSelection == 10.0) ||
         (APF_Path_Planning_2023a_BlueI_P.platformSelection == 11.0));

      // MATLAB Function: '<S634>/MATLAB Function'
      for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset < 8;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
        APF_Path_Planning_2023a_BlueI_B.y_c[APF_Path_Planning_2023a_BlueI_B.b_xoffset
          + (APF_Path_Planning_2023a_BlueI_B.b_xoffset << 3)] =
          APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        APF_Path_Planning_2023a_BlueI_B.b[3 *
          APF_Path_Planning_2023a_BlueI_B.b_xoffset] =
          b[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        APF_Path_Planning_2023a_BlueI_B.b[3 *
          APF_Path_Planning_2023a_BlueI_B.b_xoffset + 1] =
          c[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
      }

      APF_Path_Planning_2023a_BlueI_B.b[2] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[0] -
         APF_Path_Planning_2023a_BlueI_B.sampleTime_b) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[5] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[1] -
         APF_Path_Planning_2023a_BlueI_B.sampleTime_b) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[8] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[2] -
         APF_Path_Planning_2023a_BlueI_B.sampleTime_n) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[11] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[3] -
         APF_Path_Planning_2023a_BlueI_B.sampleTime_n) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[14] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[4] +
         APF_Path_Planning_2023a_BlueI_B.sampleTime_b) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[17] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[5] +
         APF_Path_Planning_2023a_BlueI_B.sampleTime_b) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[20] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[6] +
         APF_Path_Planning_2023a_BlueI_B.sampleTime_n) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[23] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[7] +
         APF_Path_Planning_2023a_BlueI_B.sampleTime_n) / 1000.0;
      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 8;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp +=
              APF_Path_Planning_2023a_BlueI_B.b[3 *
              APF_Path_Planning_2023a_BlueI_B.xoffset +
              APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
              APF_Path_Planning_2023a_BlueI_B.y_c
              [(APF_Path_Planning_2023a_BlueI_B.i_o << 3) +
              APF_Path_Planning_2023a_BlueI_B.xoffset];
          }

          APF_Path_Planning_2023a_BlueI_B.b_f[APF_Path_Planning_2023a_BlueI_B.b_xoffset
            + 3 * APF_Path_Planning_2023a_BlueI_B.i_o] =
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
        }

        // MATLAB Function: '<S634>/MATLAB Function3'
        APF_Path_Planning_2023a_BlueI_B.Product2_m[3 *
          APF_Path_Planning_2023a_BlueI_B.i_o] =
          b[APF_Path_Planning_2023a_BlueI_B.i_o];
        APF_Path_Planning_2023a_BlueI_B.Product2_m[3 *
          APF_Path_Planning_2023a_BlueI_B.i_o + 1] =
          c[APF_Path_Planning_2023a_BlueI_B.i_o];
        APF_Path_Planning_2023a_BlueI_B.Product2_m[3 *
          APF_Path_Planning_2023a_BlueI_B.i_o + 2] =
          APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[APF_Path_Planning_2023a_BlueI_B.i_o]
          / 1000.0;
      }

      // MATLAB Function: '<S634>/MATLAB Function3'
      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 8;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp +=
              APF_Path_Planning_2023a_BlueI_B.Product2_m[3 *
              APF_Path_Planning_2023a_BlueI_B.xoffset +
              APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
              APF_Path_Planning_2023a_BlueI_B.y
              [(APF_Path_Planning_2023a_BlueI_B.i_o << 3) +
              APF_Path_Planning_2023a_BlueI_B.xoffset];
          }

          APF_Path_Planning_2023a_BlueI_B.b[APF_Path_Planning_2023a_BlueI_B.b_xoffset
            + 3 * APF_Path_Planning_2023a_BlueI_B.i_o] =
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
        }
      }

      if (APF_Path_Planning_2023a_BlueI_B.Reject) {
        // Outputs for IfAction SubSystem: '<S634>/If Action Subsystem' incorporates:
        //   ActionPort: '<S636>/Action Port'

        // Outputs for IfAction SubSystem: '<S634>/If Action Subsystem1' incorporates:
        //   ActionPort: '<S637>/Action Port'

        // SignalConversion generated from: '<S636>/In1' incorporates:
        //   MATLAB Function: '<S634>/MATLAB Function'
        //   Product: '<S652>/Product2'
        //   SignalConversion generated from: '<S637>/In1'

        memcpy(&APF_Path_Planning_2023a_BlueI_B.Product2_m[0],
               &APF_Path_Planning_2023a_BlueI_B.b_f[0], 24U * sizeof(real_T));

        // End of Outputs for SubSystem: '<S634>/If Action Subsystem1'
        // End of Outputs for SubSystem: '<S634>/If Action Subsystem'
      } else {
        // Outputs for IfAction SubSystem: '<S634>/If Action Subsystem1' incorporates:
        //   ActionPort: '<S637>/Action Port'

        // Outputs for IfAction SubSystem: '<S634>/If Action Subsystem' incorporates:
        //   ActionPort: '<S636>/Action Port'

        // SignalConversion generated from: '<S637>/In1' incorporates:
        //   MATLAB Function: '<S634>/MATLAB Function'
        //   MATLAB Function: '<S634>/MATLAB Function3'
        //   Product: '<S652>/Product2'
        //   SignalConversion generated from: '<S636>/In1'

        memcpy(&APF_Path_Planning_2023a_BlueI_B.Product2_m[0],
               &APF_Path_Planning_2023a_BlueI_B.b[0], 24U * sizeof(real_T));

        // End of Outputs for SubSystem: '<S634>/If Action Subsystem'
        // End of Outputs for SubSystem: '<S634>/If Action Subsystem1'
      }

      // PermuteDimensions: '<S651>/transpose' incorporates:
      //   If: '<S634>/If'
      //   Merge: '<S634>/Merge1'
      //   Product: '<S652>/Product2'

      APF_Path_Planning_2023a_BlueI_B.yElIdx = 0;
      APF_Path_Planning_2023a_BlueI_B.uElOffset1 = 0;
      for (APF_Path_Planning_2023a_BlueI_B.ntIdx1 = 0;
           APF_Path_Planning_2023a_BlueI_B.ntIdx1 < 3;
           APF_Path_Planning_2023a_BlueI_B.ntIdx1++) {
        APF_Path_Planning_2023a_BlueI_B.StartClock =
          APF_Path_Planning_2023a_BlueI_B.uElOffset1;
        for (APF_Path_Planning_2023a_BlueI_B.ntIdx0 = 0;
             APF_Path_Planning_2023a_BlueI_B.ntIdx0 < 8;
             APF_Path_Planning_2023a_BlueI_B.ntIdx0++) {
          APF_Path_Planning_2023a_BlueI_B.Merge1_d[APF_Path_Planning_2023a_BlueI_B.yElIdx]
            =
            APF_Path_Planning_2023a_BlueI_B.Product2_m[APF_Path_Planning_2023a_BlueI_B.StartClock];
          APF_Path_Planning_2023a_BlueI_B.yElIdx++;
          APF_Path_Planning_2023a_BlueI_B.StartClock += 3;
        }

        APF_Path_Planning_2023a_BlueI_B.uElOffset1++;
      }

      // End of PermuteDimensions: '<S651>/transpose'

      // MATLAB Function: '<S635>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S609>/RED_Rz'
      //   Product: '<S634>/Product2'

      APF_Path_CreateRotationMatrix_g(APF_Path_Planning_2023a_Blue_DW.RED_Rz,
        &APF_Path_Planning_2023a_BlueI_B.Product2_b[0]);

      // Product: '<S635>/Rotate F_I to F_b' incorporates:
      //   DataStoreRead: '<S609>/RED_Fx'
      //   DataStoreRead: '<S609>/RED_Fy'
      //   SignalConversion generated from: '<S635>/Rotate F_I to F_b'

      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_BlueI_B.Product2_b[0] *
        APF_Path_Planning_2023a_Blue_DW.RED_Fx +
        APF_Path_Planning_2023a_BlueI_B.Product2_b[2] *
        APF_Path_Planning_2023a_Blue_DW.RED_Fy;

      // SignalConversion generated from: '<S634>/Product'
      APF_Path_Planning_2023a_BlueI_B.x_ddot[0] =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

      // Product: '<S635>/Rotate F_I to F_b' incorporates:
      //   DataStoreRead: '<S609>/RED_Fx'
      //   DataStoreRead: '<S609>/RED_Fy'
      //   SignalConversion generated from: '<S635>/Rotate F_I to F_b'

      APF_Path_Planning_2023a_BlueI_B.Sum6_a =
        APF_Path_Planning_2023a_BlueI_B.Product2_b[1] *
        APF_Path_Planning_2023a_Blue_DW.RED_Fx +
        APF_Path_Planning_2023a_BlueI_B.Product2_b[3] *
        APF_Path_Planning_2023a_Blue_DW.RED_Fy;

      // SignalConversion generated from: '<S634>/Product' incorporates:
      //   DataStoreRead: '<S609>/RED_Tz'

      APF_Path_Planning_2023a_BlueI_B.x_ddot[1] =
        APF_Path_Planning_2023a_BlueI_B.Sum6_a;
      APF_Path_Planning_2023a_BlueI_B.x_ddot[2] =
        APF_Path_Planning_2023a_Blue_DW.RED_Tz;

      // Product: '<S651>/Product' incorporates:
      //   Merge: '<S634>/Merge1'
      //   Product: '<S652>/Product2'

      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 3;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 8;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp +=
              APF_Path_Planning_2023a_BlueI_B.Product2_m[3 *
              APF_Path_Planning_2023a_BlueI_B.xoffset +
              APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
              APF_Path_Planning_2023a_BlueI_B.Merge1_d
              [(APF_Path_Planning_2023a_BlueI_B.i_o << 3) +
              APF_Path_Planning_2023a_BlueI_B.xoffset];
          }

          APF_Path_Planning_2023a_BlueI_B.rtb_Product2_m_n[APF_Path_Planning_2023a_BlueI_B.b_xoffset
            + 3 * APF_Path_Planning_2023a_BlueI_B.i_o] =
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
        }
      }

      // Product: '<S651>/Product1' incorporates:
      //   Product: '<S651>/Product'

      APF_Path_Plannin_rt_invd3x3_snf
        (APF_Path_Planning_2023a_BlueI_B.rtb_Product2_m_n,
         APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m);
      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        // Product: '<S634>/Product'
        APF_Path_Planning_2023a_BlueI_B.sampleTime_b = 0.0;

        // Product: '<S651>/Product2' incorporates:
        //   Merge: '<S634>/Merge1'

        APF_Path_Planning_2023a_BlueI_B.sampleTime_n =
          APF_Path_Planning_2023a_BlueI_B.Merge1_d[APF_Path_Planning_2023a_BlueI_B.i_o
          + 8];
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp =
          APF_Path_Planning_2023a_BlueI_B.Merge1_d[APF_Path_Planning_2023a_BlueI_B.i_o];
        APF_Path_Planning_2023a_BlueI_B.link1_com_y =
          APF_Path_Planning_2023a_BlueI_B.Merge1_d[APF_Path_Planning_2023a_BlueI_B.i_o
          + 16];
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          // Product: '<S634>/Product'
          APF_Path_Planning_2023a_BlueI_B.sampleTime_b +=
            ((APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[3 *
              APF_Path_Planning_2023a_BlueI_B.b_xoffset + 1] *
              APF_Path_Planning_2023a_BlueI_B.sampleTime_n +
              APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[3 *
              APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
              APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp) +
             APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[3 *
             APF_Path_Planning_2023a_BlueI_B.b_xoffset + 2] *
             APF_Path_Planning_2023a_BlueI_B.link1_com_y) *
            APF_Path_Planning_2023a_BlueI_B.x_ddot[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        }

        // End of Product: '<S651>/Product2'

        // Product: '<S634>/Product'
        APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.i_o]
          = APF_Path_Planning_2023a_BlueI_B.sampleTime_b;
      }

      // DataStoreWrite: '<S634>/Data Store Write1' incorporates:
      //   MATLAB Function: '<S634>/MATLAB Function5'

      APF_Path_Plann_MATLABFunction10
        (APF_Path_Planning_2023a_BlueI_B.rtb_Product_p,
         &APF_Path_Planning_2023a_BlueI_B.sampleTime_n,
         &APF_Path_Planning_2023a_Blue_DW.RED_Thruster_ON_Count,
         &APF_Path_Planning_2023a_BlueI_B.sf_MATLABFunction5);

      // MATLAB Function: '<S650>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S634>/RED_Rz'

      APF_Path_P_CreateRotationMatrix(APF_Path_Planning_2023a_Blue_DW.RED_Rz,
        APF_Path_Planning_2023a_BlueI_B.rtb_C_Ib_l);

      // MATLAB Function: '<S634>/MATLAB Function7' incorporates:
      //   MATLAB Function: '<S634>/MATLAB Function11'
      //   MATLAB Function: '<S634>/MATLAB Function4'

      APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp =
        APF_Path_Planning_2023a_BlueI_P.F_red_X_nominal *
        APF_Path_Planning_2023a_BlueI_B.sampleTime_n;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[0] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[1] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.alpha_pol =
        APF_Path_Planning_2023a_BlueI_P.F_red_Y_nominal *
        APF_Path_Planning_2023a_BlueI_B.sampleTime_n;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[2] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[3] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[4] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[5] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[6] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[7] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      memset(&APF_Path_Planning_2023a_BlueI_B.y[0], 0, sizeof(real_T) << 6U);
      for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset < 8;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
        APF_Path_Planning_2023a_BlueI_B.y[APF_Path_Planning_2023a_BlueI_B.b_xoffset
          + (APF_Path_Planning_2023a_BlueI_B.b_xoffset << 3)] =
          APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
      }

      // MATLAB Function: '<S634>/MATLAB Function4' incorporates:
      //   DataStoreRead: '<S634>/Data Store Read1'
      //   DataStoreRead: '<S634>/Data Store Read2'
      //   MATLAB Function: '<S634>/MATLAB Function6'

      APF_Path_Planning_2023a_BlueI_B.link1_com_x = cos
        (APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder + 1.5707963267948966) *
        APF_Path_Planning_2023a_BlueI_P.a1 + APF_Path_Planning_2023a_BlueI_P.b0 *
        cos(APF_Path_Planning_2023a_BlueI_P.Phi);
      APF_Path_Planning_2023a_BlueI_B.link1_com_y = sin
        (APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder + 1.5707963267948966) *
        APF_Path_Planning_2023a_BlueI_P.a1 + APF_Path_Planning_2023a_BlueI_P.b0 *
        sin(APF_Path_Planning_2023a_BlueI_P.Phi);
      APF_Path_Planning_2023a_BlueI_B.q = cos
        (APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder + 1.5707963267948966) *
        APF_Path_Planning_2023a_BlueI_P.b1;
      APF_Path_Planning_2023a_BlueI_B.t35 = cos
        ((APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder + 1.5707963267948966)
         + APF_Path_Planning_2023a_Blue_DW.RED_Rz_Elbow) *
        APF_Path_Planning_2023a_BlueI_P.a2;
      APF_Path_Planning_2023a_BlueI_B.absxk = (APF_Path_Planning_2023a_BlueI_B.q
        + APF_Path_Planning_2023a_BlueI_B.link1_com_x) +
        APF_Path_Planning_2023a_BlueI_B.t35;
      APF_Path_Planning_2023a_BlueI_B.t = sin
        (APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder + 1.5707963267948966) *
        APF_Path_Planning_2023a_BlueI_P.b1;
      APF_Path_Planning_2023a_BlueI_B.t71 = sin
        ((APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder + 1.5707963267948966)
         + APF_Path_Planning_2023a_Blue_DW.RED_Rz_Elbow) *
        APF_Path_Planning_2023a_BlueI_P.a2;
      APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 =
        (APF_Path_Planning_2023a_BlueI_B.t +
         APF_Path_Planning_2023a_BlueI_B.link1_com_y) +
        APF_Path_Planning_2023a_BlueI_B.t71;
      APF_Path_Planning_2023a_BlueI_B.absx_tmp = cos
        ((APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder + 1.5707963267948966)
         + APF_Path_Planning_2023a_Blue_DW.RED_Rz_Elbow) *
        APF_Path_Planning_2023a_BlueI_P.b2;
      APF_Path_Planning_2023a_BlueI_B.sampleTime_n =
        (((APF_Path_Planning_2023a_BlueI_B.absx_tmp +
           APF_Path_Planning_2023a_BlueI_B.absxk) +
          APF_Path_Planning_2023a_BlueI_B.Switch) *
         APF_Path_Planning_2023a_BlueI_P.mEE +
         (APF_Path_Planning_2023a_BlueI_P.mPROX *
          APF_Path_Planning_2023a_BlueI_B.link1_com_x +
          APF_Path_Planning_2023a_BlueI_P.mDIST *
          APF_Path_Planning_2023a_BlueI_B.absxk)) /
        APF_Path_Planning_2023a_BlueI_B.sampleTime * 1000.0;
      APF_Path_Planning_2023a_BlueI_B.t34 = sin
        ((APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder + 1.5707963267948966)
         + APF_Path_Planning_2023a_Blue_DW.RED_Rz_Elbow) *
        APF_Path_Planning_2023a_BlueI_P.b2;
      APF_Path_Planning_2023a_BlueI_B.sampleTime_b =
        (((APF_Path_Planning_2023a_BlueI_B.t34 +
           APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1) +
          APF_Path_Planning_2023a_BlueI_B.Derivative2) *
         APF_Path_Planning_2023a_BlueI_P.mEE +
         (APF_Path_Planning_2023a_BlueI_P.mPROX *
          APF_Path_Planning_2023a_BlueI_B.link1_com_y +
          APF_Path_Planning_2023a_BlueI_P.mDIST *
          APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1)) /
        APF_Path_Planning_2023a_BlueI_B.sampleTime * 1000.0;
      memset(&APF_Path_Planning_2023a_BlueI_B.y_c[0], 0, sizeof(real_T) << 6U);
      for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset < 8;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
        APF_Path_Planning_2023a_BlueI_B.y_c[APF_Path_Planning_2023a_BlueI_B.b_xoffset
          + (APF_Path_Planning_2023a_BlueI_B.b_xoffset << 3)] =
          APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
      }

      // MATLAB Function: '<S634>/MATLAB Function11' incorporates:
      //   MATLAB Function: '<S634>/MATLAB Function6'

      APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp /= 2.0;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[0] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[1] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.alpha_pol /= 2.0;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[2] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[3] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[4] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[5] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[6] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[7] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      memset(&APF_Path_Planning_2023a_BlueI_B.y_k[0], 0, sizeof(real_T) << 6U);
      for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset < 8;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
        APF_Path_Planning_2023a_BlueI_B.y_k[APF_Path_Planning_2023a_BlueI_B.b_xoffset
          + (APF_Path_Planning_2023a_BlueI_B.b_xoffset << 3)] =
          APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
      }

      // MATLAB Function: '<S634>/MATLAB Function6' incorporates:
      //   DataStoreRead: '<S634>/Data Store Read1'

      APF_Path_Planning_2023a_BlueI_B.link1_com_x = cos
        (APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder + 1.5707963267948966) *
        APF_Path_Planning_2023a_BlueI_P.a1 + APF_Path_Planning_2023a_BlueI_P.b0 *
        cos(APF_Path_Planning_2023a_BlueI_P.Phi);
      APF_Path_Planning_2023a_BlueI_B.link1_com_y = sin
        (APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder + 1.5707963267948966) *
        APF_Path_Planning_2023a_BlueI_P.a1 + APF_Path_Planning_2023a_BlueI_P.b0 *
        sin(APF_Path_Planning_2023a_BlueI_P.Phi);
      APF_Path_Planning_2023a_BlueI_B.absxk = (APF_Path_Planning_2023a_BlueI_B.q
        + APF_Path_Planning_2023a_BlueI_B.link1_com_x) +
        APF_Path_Planning_2023a_BlueI_B.t35;
      APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1 =
        (APF_Path_Planning_2023a_BlueI_B.t +
         APF_Path_Planning_2023a_BlueI_B.link1_com_y) +
        APF_Path_Planning_2023a_BlueI_B.t71;
      APF_Path_Planning_2023a_BlueI_B.Switch =
        (((APF_Path_Planning_2023a_BlueI_B.absx_tmp +
           APF_Path_Planning_2023a_BlueI_B.absxk) +
          APF_Path_Planning_2023a_BlueI_B.Switch) *
         APF_Path_Planning_2023a_BlueI_P.mEE +
         (APF_Path_Planning_2023a_BlueI_P.mPROX *
          APF_Path_Planning_2023a_BlueI_B.link1_com_x +
          APF_Path_Planning_2023a_BlueI_P.mDIST *
          APF_Path_Planning_2023a_BlueI_B.absxk)) /
        APF_Path_Planning_2023a_BlueI_B.sampleTime * 1000.0;
      APF_Path_Planning_2023a_BlueI_B.sampleTime =
        (((APF_Path_Planning_2023a_BlueI_B.t34 +
           APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1) +
          APF_Path_Planning_2023a_BlueI_B.Derivative2) *
         APF_Path_Planning_2023a_BlueI_P.mEE +
         (APF_Path_Planning_2023a_BlueI_P.mPROX *
          APF_Path_Planning_2023a_BlueI_B.link1_com_y +
          APF_Path_Planning_2023a_BlueI_P.mDIST *
          APF_Path_Planning_2023a_BlueI_B.rtb_path_o_idx_1)) /
        APF_Path_Planning_2023a_BlueI_B.sampleTime * 1000.0;
      memset(&APF_Path_Planning_2023a_BlueI_B.y_cx[0], 0, sizeof(real_T) << 6U);

      // If: '<S634>/If2' incorporates:
      //   Constant: '<S634>/Constant2'

      APF_Path_Planning_2023a_BlueI_B.Reject =
        ((APF_Path_Planning_2023a_BlueI_P.platformSelection == 4.0) ||
         (APF_Path_Planning_2023a_BlueI_P.platformSelection == 5.0) ||
         (APF_Path_Planning_2023a_BlueI_P.platformSelection == 10.0) ||
         (APF_Path_Planning_2023a_BlueI_P.platformSelection == 11.0));

      // MATLAB Function: '<S634>/MATLAB Function6'
      for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset < 8;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
        APF_Path_Planning_2023a_BlueI_B.y_cx[APF_Path_Planning_2023a_BlueI_B.b_xoffset
          + (APF_Path_Planning_2023a_BlueI_B.b_xoffset << 3)] =
          APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        APF_Path_Planning_2023a_BlueI_B.b[3 *
          APF_Path_Planning_2023a_BlueI_B.b_xoffset] =
          b[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        APF_Path_Planning_2023a_BlueI_B.b[3 *
          APF_Path_Planning_2023a_BlueI_B.b_xoffset + 1] =
          c[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
      }

      APF_Path_Planning_2023a_BlueI_B.b[2] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[0] -
         APF_Path_Planning_2023a_BlueI_B.sampleTime) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[5] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[1] -
         APF_Path_Planning_2023a_BlueI_B.sampleTime) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[8] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[2] -
         APF_Path_Planning_2023a_BlueI_B.Switch) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[11] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[3] -
         APF_Path_Planning_2023a_BlueI_B.Switch) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[14] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[4] +
         APF_Path_Planning_2023a_BlueI_B.sampleTime) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[17] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[5] +
         APF_Path_Planning_2023a_BlueI_B.sampleTime) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[20] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[6] +
         APF_Path_Planning_2023a_BlueI_B.Switch) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[23] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[7] +
         APF_Path_Planning_2023a_BlueI_B.Switch) / 1000.0;
      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 8;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp +=
              APF_Path_Planning_2023a_BlueI_B.b[3 *
              APF_Path_Planning_2023a_BlueI_B.xoffset +
              APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
              APF_Path_Planning_2023a_BlueI_B.y_cx
              [(APF_Path_Planning_2023a_BlueI_B.i_o << 3) +
              APF_Path_Planning_2023a_BlueI_B.xoffset];
          }

          APF_Path_Planning_2023a_BlueI_B.b_f[APF_Path_Planning_2023a_BlueI_B.b_xoffset
            + 3 * APF_Path_Planning_2023a_BlueI_B.i_o] =
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
        }

        // MATLAB Function: '<S634>/MATLAB Function11'
        APF_Path_Planning_2023a_BlueI_B.Product2_m[3 *
          APF_Path_Planning_2023a_BlueI_B.i_o] =
          b[APF_Path_Planning_2023a_BlueI_B.i_o];
        APF_Path_Planning_2023a_BlueI_B.Product2_m[3 *
          APF_Path_Planning_2023a_BlueI_B.i_o + 1] =
          c[APF_Path_Planning_2023a_BlueI_B.i_o];
      }

      // MATLAB Function: '<S634>/MATLAB Function11'
      APF_Path_Planning_2023a_BlueI_B.Product2_m[2] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[0] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.Product2_m[5] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[1] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.Product2_m[8] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[2] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.Product2_m[11] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[3] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.Product2_m[14] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[4] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.Product2_m[17] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[5] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.Product2_m[20] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[6] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.Product2_m[23] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[7] / 1000.0;
      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 8;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp +=
              APF_Path_Planning_2023a_BlueI_B.Product2_m[3 *
              APF_Path_Planning_2023a_BlueI_B.xoffset +
              APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
              APF_Path_Planning_2023a_BlueI_B.y_k
              [(APF_Path_Planning_2023a_BlueI_B.i_o << 3) +
              APF_Path_Planning_2023a_BlueI_B.xoffset];
          }

          APF_Path_Planning_2023a_BlueI_B.b[APF_Path_Planning_2023a_BlueI_B.b_xoffset
            + 3 * APF_Path_Planning_2023a_BlueI_B.i_o] =
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
        }
      }

      if (APF_Path_Planning_2023a_BlueI_B.Reject) {
        // Outputs for IfAction SubSystem: '<S634>/If Action Subsystem4' incorporates:
        //   ActionPort: '<S640>/Action Port'

        // Outputs for IfAction SubSystem: '<S634>/If Action Subsystem5' incorporates:
        //   ActionPort: '<S641>/Action Port'

        // SignalConversion generated from: '<S640>/H' incorporates:
        //   MATLAB Function: '<S634>/MATLAB Function6'
        //   Product: '<S652>/Product2'
        //   SignalConversion generated from: '<S641>/In1'

        memcpy(&APF_Path_Planning_2023a_BlueI_B.Product2_m[0],
               &APF_Path_Planning_2023a_BlueI_B.b_f[0], 24U * sizeof(real_T));

        // End of Outputs for SubSystem: '<S634>/If Action Subsystem5'
        // End of Outputs for SubSystem: '<S634>/If Action Subsystem4'
      } else {
        // Outputs for IfAction SubSystem: '<S634>/If Action Subsystem5' incorporates:
        //   ActionPort: '<S641>/Action Port'

        // Outputs for IfAction SubSystem: '<S634>/If Action Subsystem4' incorporates:
        //   ActionPort: '<S640>/Action Port'

        // SignalConversion generated from: '<S641>/In1' incorporates:
        //   MATLAB Function: '<S634>/MATLAB Function11'
        //   MATLAB Function: '<S634>/MATLAB Function6'
        //   Product: '<S652>/Product2'
        //   SignalConversion generated from: '<S640>/H'

        memcpy(&APF_Path_Planning_2023a_BlueI_B.Product2_m[0],
               &APF_Path_Planning_2023a_BlueI_B.b[0], 24U * sizeof(real_T));

        // End of Outputs for SubSystem: '<S634>/If Action Subsystem4'
        // End of Outputs for SubSystem: '<S634>/If Action Subsystem5'
      }

      // PermuteDimensions: '<S652>/transpose' incorporates:
      //   If: '<S634>/If2'
      //   Product: '<S652>/Product2'

      APF_Path_Planning_2023a_BlueI_B.yElIdx = 0;
      APF_Path_Planning_2023a_BlueI_B.uElOffset1 = 0;
      for (APF_Path_Planning_2023a_BlueI_B.ntIdx1 = 0;
           APF_Path_Planning_2023a_BlueI_B.ntIdx1 < 3;
           APF_Path_Planning_2023a_BlueI_B.ntIdx1++) {
        APF_Path_Planning_2023a_BlueI_B.StartClock =
          APF_Path_Planning_2023a_BlueI_B.uElOffset1;
        for (APF_Path_Planning_2023a_BlueI_B.ntIdx0 = 0;
             APF_Path_Planning_2023a_BlueI_B.ntIdx0 < 8;
             APF_Path_Planning_2023a_BlueI_B.ntIdx0++) {
          APF_Path_Planning_2023a_BlueI_B.transpose[APF_Path_Planning_2023a_BlueI_B.yElIdx]
            =
            APF_Path_Planning_2023a_BlueI_B.Product2_m[APF_Path_Planning_2023a_BlueI_B.StartClock];
          APF_Path_Planning_2023a_BlueI_B.yElIdx++;
          APF_Path_Planning_2023a_BlueI_B.StartClock += 3;
        }

        APF_Path_Planning_2023a_BlueI_B.uElOffset1++;
      }

      // End of PermuteDimensions: '<S652>/transpose'
      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 3;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          // Product: '<S652>/Product' incorporates:
          //   Product: '<S634>/Product2'

          APF_Path_Planning_2023a_BlueI_B.sampleTime = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 8;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            // Product: '<S634>/Product2' incorporates:
            //   PermuteDimensions: '<S652>/transpose'
            //   Product: '<S652>/Product'
            //   Product: '<S652>/Product2'

            APF_Path_Planning_2023a_BlueI_B.sampleTime +=
              APF_Path_Planning_2023a_BlueI_B.Product2_m[3 *
              APF_Path_Planning_2023a_BlueI_B.xoffset +
              APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
              APF_Path_Planning_2023a_BlueI_B.transpose
              [(APF_Path_Planning_2023a_BlueI_B.i_o << 3) +
              APF_Path_Planning_2023a_BlueI_B.xoffset];
          }

          // Product: '<S652>/Product' incorporates:
          //   Product: '<S634>/Product2'

          APF_Path_Planning_2023a_BlueI_B.Product2_b[APF_Path_Planning_2023a_BlueI_B.b_xoffset
            + 3 * APF_Path_Planning_2023a_BlueI_B.i_o] =
            APF_Path_Planning_2023a_BlueI_B.sampleTime;
        }
      }

      // Product: '<S652>/Product1' incorporates:
      //   Product: '<S634>/Product2'

      memcpy(&APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[0],
             &APF_Path_Planning_2023a_BlueI_B.Product2_b[0], 9U * sizeof(real_T));
      APF_Path_Plannin_rt_invd3x3_snf
        (APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m,
         APF_Path_Planning_2023a_BlueI_B.Product2_b);

      // Product: '<S652>/Product2' incorporates:
      //   PermuteDimensions: '<S652>/transpose'
      //   Product: '<S634>/Product2'

      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        APF_Path_Planning_2023a_BlueI_B.sampleTime =
          APF_Path_Planning_2023a_BlueI_B.transpose[APF_Path_Planning_2023a_BlueI_B.i_o
          + 8];
        APF_Path_Planning_2023a_BlueI_B.Derivative2 =
          APF_Path_Planning_2023a_BlueI_B.transpose[APF_Path_Planning_2023a_BlueI_B.i_o];
        APF_Path_Planning_2023a_BlueI_B.Switch =
          APF_Path_Planning_2023a_BlueI_B.transpose[APF_Path_Planning_2023a_BlueI_B.i_o
          + 16];
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.Product2_m[APF_Path_Planning_2023a_BlueI_B.i_o
            + (APF_Path_Planning_2023a_BlueI_B.b_xoffset << 3)] =
            (APF_Path_Planning_2023a_BlueI_B.Product2_b[3 *
             APF_Path_Planning_2023a_BlueI_B.b_xoffset + 1] *
             APF_Path_Planning_2023a_BlueI_B.sampleTime +
             APF_Path_Planning_2023a_BlueI_B.Product2_b[3 *
             APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
             APF_Path_Planning_2023a_BlueI_B.Derivative2) +
            APF_Path_Planning_2023a_BlueI_B.Product2_b[3 *
            APF_Path_Planning_2023a_BlueI_B.b_xoffset + 2] *
            APF_Path_Planning_2023a_BlueI_B.Switch;
        }
      }

      // End of Product: '<S652>/Product2'
      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        // Product: '<S634>/Product2' incorporates:
        //   DataStoreRead: '<S609>/RED_Tz'
        //   Product: '<S635>/Rotate F_I to F_b'
        //   Product: '<S652>/Product2'
        //   SignalConversion generated from: '<S634>/Product'

        APF_Path_Planning_2023a_BlueI_B.link1_com_y =
          (APF_Path_Planning_2023a_BlueI_B.Product2_m[APF_Path_Planning_2023a_BlueI_B.i_o
           + 8] * APF_Path_Planning_2023a_BlueI_B.Sum6_a +
           APF_Path_Planning_2023a_BlueI_B.Product2_m[APF_Path_Planning_2023a_BlueI_B.i_o]
           * APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW) +
          APF_Path_Planning_2023a_BlueI_B.Product2_m[APF_Path_Planning_2023a_BlueI_B.i_o
          + 16] * APF_Path_Planning_2023a_Blue_DW.RED_Tz;

        // Product: '<S634>/Product2'
        APF_Path_Planning_2023a_BlueI_B.Product2_b[APF_Path_Planning_2023a_BlueI_B.i_o]
          = APF_Path_Planning_2023a_BlueI_B.link1_com_y;

        // Saturate: '<S634>/Remove Negatives' incorporates:
        //   Product: '<S634>/Product2'

        if (APF_Path_Planning_2023a_BlueI_B.link1_com_y >
            APF_Path_Planning_2023a_BlueI_P.RemoveNegatives_UpperSat_k) {
          // Saturate: '<S634>/Remove Negatives'
          APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.i_o]
            = APF_Path_Planning_2023a_BlueI_P.RemoveNegatives_UpperSat_k;
        } else if (APF_Path_Planning_2023a_BlueI_B.link1_com_y <
                   APF_Path_Planning_2023a_BlueI_P.RemoveNegatives_LowerSat_k) {
          // Saturate: '<S634>/Remove Negatives'
          APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.i_o]
            = APF_Path_Planning_2023a_BlueI_P.RemoveNegatives_LowerSat_k;
        } else {
          // Saturate: '<S634>/Remove Negatives'
          APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.i_o]
            = APF_Path_Planning_2023a_BlueI_B.link1_com_y;
        }

        // End of Saturate: '<S634>/Remove Negatives'
      }

      // MATLAB Function: '<S634>/MATLAB Function2'
      APF_Path_Plan_MATLABFunction1_l
        (APF_Path_Planning_2023a_BlueI_B.rtb_Product_p,
         APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final);

      // If: '<S634>/If1' incorporates:
      //   Constant: '<S634>/Constant1'

      APF_Path_Planning_2023a_BlueI_B.Reject =
        ((APF_Path_Planning_2023a_BlueI_P.platformSelection == 4.0) ||
         (APF_Path_Planning_2023a_BlueI_P.platformSelection == 5.0) ||
         (APF_Path_Planning_2023a_BlueI_P.platformSelection == 10.0) ||
         (APF_Path_Planning_2023a_BlueI_P.platformSelection == 11.0));

      // MATLAB Function: '<S634>/MATLAB Function4'
      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        APF_Path_Planning_2023a_BlueI_B.b[3 *
          APF_Path_Planning_2023a_BlueI_B.i_o] =
          b[APF_Path_Planning_2023a_BlueI_B.i_o];
        APF_Path_Planning_2023a_BlueI_B.b[3 *
          APF_Path_Planning_2023a_BlueI_B.i_o + 1] =
          c[APF_Path_Planning_2023a_BlueI_B.i_o];
      }

      APF_Path_Planning_2023a_BlueI_B.b[2] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[0] -
         APF_Path_Planning_2023a_BlueI_B.sampleTime_b) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[5] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[1] -
         APF_Path_Planning_2023a_BlueI_B.sampleTime_b) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[8] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[2] -
         APF_Path_Planning_2023a_BlueI_B.sampleTime_n) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[11] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[3] -
         APF_Path_Planning_2023a_BlueI_B.sampleTime_n) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[14] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[4] +
         APF_Path_Planning_2023a_BlueI_B.sampleTime_b) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[17] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[5] +
         APF_Path_Planning_2023a_BlueI_B.sampleTime_b) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[20] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[6] +
         APF_Path_Planning_2023a_BlueI_B.sampleTime_n) / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[23] =
        (APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[7] +
         APF_Path_Planning_2023a_BlueI_B.sampleTime_n) / 1000.0;
      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 8;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp +=
              APF_Path_Planning_2023a_BlueI_B.b[3 *
              APF_Path_Planning_2023a_BlueI_B.xoffset +
              APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
              APF_Path_Planning_2023a_BlueI_B.y_c
              [(APF_Path_Planning_2023a_BlueI_B.i_o << 3) +
              APF_Path_Planning_2023a_BlueI_B.xoffset];
          }

          APF_Path_Planning_2023a_BlueI_B.b_f[APF_Path_Planning_2023a_BlueI_B.b_xoffset
            + 3 * APF_Path_Planning_2023a_BlueI_B.i_o] =
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
        }

        // MATLAB Function: '<S634>/MATLAB Function7'
        APF_Path_Planning_2023a_BlueI_B.Product2_m[3 *
          APF_Path_Planning_2023a_BlueI_B.i_o] =
          b[APF_Path_Planning_2023a_BlueI_B.i_o];
        APF_Path_Planning_2023a_BlueI_B.Product2_m[3 *
          APF_Path_Planning_2023a_BlueI_B.i_o + 1] =
          c[APF_Path_Planning_2023a_BlueI_B.i_o];
      }

      // MATLAB Function: '<S634>/MATLAB Function7'
      APF_Path_Planning_2023a_BlueI_B.Product2_m[2] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[0] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.Product2_m[5] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[1] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.Product2_m[8] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[2] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.Product2_m[11] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[3] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.Product2_m[14] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[4] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.Product2_m[17] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[5] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.Product2_m[20] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[6] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.Product2_m[23] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_RED[7] / 1000.0;
      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 8;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp +=
              APF_Path_Planning_2023a_BlueI_B.Product2_m[3 *
              APF_Path_Planning_2023a_BlueI_B.xoffset +
              APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
              APF_Path_Planning_2023a_BlueI_B.y
              [(APF_Path_Planning_2023a_BlueI_B.i_o << 3) +
              APF_Path_Planning_2023a_BlueI_B.xoffset];
          }

          APF_Path_Planning_2023a_BlueI_B.b[APF_Path_Planning_2023a_BlueI_B.b_xoffset
            + 3 * APF_Path_Planning_2023a_BlueI_B.i_o] =
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
        }
      }

      if (APF_Path_Planning_2023a_BlueI_B.Reject) {
        memcpy(&APF_Path_Planning_2023a_BlueI_B.Merge1_d[0],
               &APF_Path_Planning_2023a_BlueI_B.b_f[0], 24U * sizeof(real_T));
      } else {
        memcpy(&APF_Path_Planning_2023a_BlueI_B.Merge1_d[0],
               &APF_Path_Planning_2023a_BlueI_B.b[0], 24U * sizeof(real_T));
      }

      // Product: '<S634>/Product1' incorporates:
      //   If: '<S634>/If1'
      //   MATLAB Function: '<S634>/MATLAB Function4'
      //   MATLAB Function: '<S634>/MATLAB Function7'

      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 3;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        APF_Path_Planning_2023a_BlueI_B.sampleTime_n = 0.0;
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 8;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.sampleTime_n +=
            APF_Path_Planning_2023a_BlueI_B.Merge1_d[3 *
            APF_Path_Planning_2023a_BlueI_B.b_xoffset +
            APF_Path_Planning_2023a_BlueI_B.i_o] *
            APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        }

        APF_Path_Planning_2023a_BlueI_B.x_ddot[APF_Path_Planning_2023a_BlueI_B.i_o]
          = APF_Path_Planning_2023a_BlueI_B.sampleTime_n;
      }

      // End of Product: '<S634>/Product1'

      // DataStoreWrite: '<S634>/RED_Fx_Sat' incorporates:
      //   Product: '<S650>/Rotate F_b to F_I'

      APF_Path_Planning_2023a_Blue_DW.RED_Fx_Sat =
        APF_Path_Planning_2023a_BlueI_B.rtb_C_Ib_l[0] *
        APF_Path_Planning_2023a_BlueI_B.x_ddot[0] +
        APF_Path_Planning_2023a_BlueI_B.x_ddot[1] *
        APF_Path_Planning_2023a_BlueI_B.rtb_C_Ib_l[2];

      // DataStoreWrite: '<S634>/RED_Fy_Sat' incorporates:
      //   Product: '<S650>/Rotate F_b to F_I'

      APF_Path_Planning_2023a_Blue_DW.RED_Fy_Sat =
        APF_Path_Planning_2023a_BlueI_B.x_ddot[0] *
        APF_Path_Planning_2023a_BlueI_B.rtb_C_Ib_l[1] +
        APF_Path_Planning_2023a_BlueI_B.x_ddot[1] *
        APF_Path_Planning_2023a_BlueI_B.rtb_C_Ib_l[3];

      // DataStoreWrite: '<S634>/RED_Tz_Sat'
      APF_Path_Planning_2023a_Blue_DW.RED_Tz_Sat =
        APF_Path_Planning_2023a_BlueI_B.x_ddot[2];

      // End of Outputs for SubSystem: '<S19>/Change RED Behavior'
    }

    // End of If: '<S19>/This IF block determines whether or not to run the RED sim//exp ' 

    // If: '<S19>/This IF block determines whether or not to run the BLACK sim//exp' incorporates:
    //   DataStoreRead: '<S19>/Data Store Read'
    //   DataStoreRead: '<S19>/Data Store Read1'
    //   Product: '<S619>/Product1'

    if ((APF_Path_Planning_2023a_Blue_DW.WhoAmI == 2.0) ||
        (APF_Path_Planning_2023a_BlueI_B.isSim == 1.0)) {
      // Outputs for IfAction SubSystem: '<S19>/Change BLACK Behavior' incorporates:
      //   ActionPort: '<S607>/Action Port'

      // MATLAB Function: '<S617>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S610>/BLACK_Rz'

      APF_Path_P_CreateRotationMatrix(APF_Path_Planning_2023a_Blue_DW.BLACK_Rz,
        APF_Path_Planning_2023a_BlueI_B.rtb_C_Ib_l);

      // MATLAB Function: '<S610>/MATLAB Function'
      for (APF_Path_Planning_2023a_BlueI_B.i = 0;
           APF_Path_Planning_2023a_BlueI_B.i < 8;
           APF_Path_Planning_2023a_BlueI_B.i++) {
        APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.i]
          =
          APF_Path_Planning_2023a_BlueI_P.F_thrusters_BLACK[APF_Path_Planning_2023a_BlueI_B.i]
          / 2.0;
      }

      memset(&APF_Path_Planning_2023a_BlueI_B.y[0], 0, sizeof(real_T) << 6U);
      for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset < 8;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
        APF_Path_Planning_2023a_BlueI_B.y[APF_Path_Planning_2023a_BlueI_B.b_xoffset
          + (APF_Path_Planning_2023a_BlueI_B.b_xoffset << 3)] =
          APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        APF_Path_Planning_2023a_BlueI_B.b[3 *
          APF_Path_Planning_2023a_BlueI_B.b_xoffset] =
          b[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        APF_Path_Planning_2023a_BlueI_B.b[3 *
          APF_Path_Planning_2023a_BlueI_B.b_xoffset + 1] =
          c[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        APF_Path_Planning_2023a_BlueI_B.b[3 *
          APF_Path_Planning_2023a_BlueI_B.b_xoffset + 2] =
          APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLACK[APF_Path_Planning_2023a_BlueI_B.b_xoffset]
          / 1000.0;
      }

      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.sampleTime_n = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 8;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            APF_Path_Planning_2023a_BlueI_B.sampleTime_n +=
              APF_Path_Planning_2023a_BlueI_B.b[3 *
              APF_Path_Planning_2023a_BlueI_B.xoffset +
              APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
              APF_Path_Planning_2023a_BlueI_B.y
              [(APF_Path_Planning_2023a_BlueI_B.i_o << 3) +
              APF_Path_Planning_2023a_BlueI_B.xoffset];
          }

          APF_Path_Planning_2023a_BlueI_B.Merge1_d[APF_Path_Planning_2023a_BlueI_B.b_xoffset
            + 3 * APF_Path_Planning_2023a_BlueI_B.i_o] =
            APF_Path_Planning_2023a_BlueI_B.sampleTime_n;
        }
      }

      // End of MATLAB Function: '<S610>/MATLAB Function'

      // PermuteDimensions: '<S618>/transpose' incorporates:
      //   Product: '<S619>/Product1'

      APF_Path_Planning_2023a_BlueI_B.yElIdx = 0;
      APF_Path_Planning_2023a_BlueI_B.uElOffset1 = 0;
      for (APF_Path_Planning_2023a_BlueI_B.ntIdx1 = 0;
           APF_Path_Planning_2023a_BlueI_B.ntIdx1 < 3;
           APF_Path_Planning_2023a_BlueI_B.ntIdx1++) {
        APF_Path_Planning_2023a_BlueI_B.StartClock =
          APF_Path_Planning_2023a_BlueI_B.uElOffset1;
        for (APF_Path_Planning_2023a_BlueI_B.ntIdx0 = 0;
             APF_Path_Planning_2023a_BlueI_B.ntIdx0 < 8;
             APF_Path_Planning_2023a_BlueI_B.ntIdx0++) {
          APF_Path_Planning_2023a_BlueI_B.Product1_e[APF_Path_Planning_2023a_BlueI_B.yElIdx]
            =
            APF_Path_Planning_2023a_BlueI_B.Merge1_d[APF_Path_Planning_2023a_BlueI_B.StartClock];
          APF_Path_Planning_2023a_BlueI_B.yElIdx++;
          APF_Path_Planning_2023a_BlueI_B.StartClock += 3;
        }

        APF_Path_Planning_2023a_BlueI_B.uElOffset1++;
      }

      // End of PermuteDimensions: '<S618>/transpose'

      // Product: '<S618>/Product' incorporates:
      //   Product: '<S619>/Product1'

      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 3;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.sampleTime_n = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 8;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            APF_Path_Planning_2023a_BlueI_B.sampleTime_n +=
              APF_Path_Planning_2023a_BlueI_B.Merge1_d[3 *
              APF_Path_Planning_2023a_BlueI_B.xoffset +
              APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
              APF_Path_Planning_2023a_BlueI_B.Product1_e
              [(APF_Path_Planning_2023a_BlueI_B.i_o << 3) +
              APF_Path_Planning_2023a_BlueI_B.xoffset];
          }

          APF_Path_Planning_2023a_BlueI_B.rtb_Product2_m_n[APF_Path_Planning_2023a_BlueI_B.b_xoffset
            + 3 * APF_Path_Planning_2023a_BlueI_B.i_o] =
            APF_Path_Planning_2023a_BlueI_B.sampleTime_n;
        }
      }

      // Product: '<S618>/Product1' incorporates:
      //   Product: '<S618>/Product'

      APF_Path_Plannin_rt_invd3x3_snf
        (APF_Path_Planning_2023a_BlueI_B.rtb_Product2_m_n,
         APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m);

      // Product: '<S618>/Product2' incorporates:
      //   Product: '<S610>/Product5'
      //   Product: '<S619>/Product1'

      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        APF_Path_Planning_2023a_BlueI_B.sampleTime_b =
          APF_Path_Planning_2023a_BlueI_B.Product1_e[APF_Path_Planning_2023a_BlueI_B.i_o
          + 8];
        APF_Path_Planning_2023a_BlueI_B.sampleTime =
          APF_Path_Planning_2023a_BlueI_B.Product1_e[APF_Path_Planning_2023a_BlueI_B.i_o];
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_B.Product1_e[APF_Path_Planning_2023a_BlueI_B.i_o
          + 16];
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.Product2_m[APF_Path_Planning_2023a_BlueI_B.i_o
            + (APF_Path_Planning_2023a_BlueI_B.b_xoffset << 3)] =
            (APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[3 *
             APF_Path_Planning_2023a_BlueI_B.b_xoffset + 1] *
             APF_Path_Planning_2023a_BlueI_B.sampleTime_b +
             APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[3 *
             APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
             APF_Path_Planning_2023a_BlueI_B.sampleTime) +
            APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[3 *
            APF_Path_Planning_2023a_BlueI_B.b_xoffset + 2] *
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;
        }
      }

      // End of Product: '<S618>/Product2'

      // MATLAB Function: '<S611>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S607>/BLACK_Rz'
      //   Product: '<S619>/Product2'

      APF_Path_CreateRotationMatrix_g(APF_Path_Planning_2023a_Blue_DW.BLACK_Rz,
        &APF_Path_Planning_2023a_BlueI_B.Product2_n[0]);

      // Product: '<S611>/Rotate F_I to F_b' incorporates:
      //   DataStoreRead: '<S607>/BLACK_Fx'
      //   DataStoreRead: '<S607>/BLACK_Fy'
      //   SignalConversion generated from: '<S611>/Rotate F_I to F_b'

      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_BlueI_B.Product2_n[0] *
        APF_Path_Planning_2023a_Blue_DW.BLACK_Fx +
        APF_Path_Planning_2023a_BlueI_B.Product2_n[2] *
        APF_Path_Planning_2023a_Blue_DW.BLACK_Fy;

      // SignalConversion generated from: '<S610>/Product' incorporates:
      //   Product: '<S611>/Rotate F_I to F_b'

      APF_Path_Planning_2023a_BlueI_B.x_ddot[0] =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

      // Product: '<S611>/Rotate F_I to F_b' incorporates:
      //   DataStoreRead: '<S607>/BLACK_Fx'
      //   DataStoreRead: '<S607>/BLACK_Fy'
      //   SignalConversion generated from: '<S611>/Rotate F_I to F_b'

      APF_Path_Planning_2023a_BlueI_B.Sum6_a =
        APF_Path_Planning_2023a_BlueI_B.Product2_n[1] *
        APF_Path_Planning_2023a_Blue_DW.BLACK_Fx +
        APF_Path_Planning_2023a_BlueI_B.Product2_n[3] *
        APF_Path_Planning_2023a_Blue_DW.BLACK_Fy;

      // SignalConversion generated from: '<S610>/Product' incorporates:
      //   DataStoreRead: '<S607>/BLACK_Tz'

      APF_Path_Planning_2023a_BlueI_B.x_ddot[1] =
        APF_Path_Planning_2023a_BlueI_B.Sum6_a;
      APF_Path_Planning_2023a_BlueI_B.x_ddot[2] =
        APF_Path_Planning_2023a_Blue_DW.BLACK_Tz;
      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        // Product: '<S610>/Product' incorporates:
        //   DataStoreRead: '<S607>/BLACK_Tz'
        //   Product: '<S610>/Product5'
        //   Product: '<S611>/Rotate F_I to F_b'
        //   SignalConversion generated from: '<S610>/Product'

        APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.i_o]
          =
          (APF_Path_Planning_2023a_BlueI_B.Product2_m[APF_Path_Planning_2023a_BlueI_B.i_o
           + 8] * APF_Path_Planning_2023a_BlueI_B.Sum6_a +
           APF_Path_Planning_2023a_BlueI_B.Product2_m[APF_Path_Planning_2023a_BlueI_B.i_o]
           * APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW) +
          APF_Path_Planning_2023a_BlueI_B.Product2_m[APF_Path_Planning_2023a_BlueI_B.i_o
          + 16] * APF_Path_Planning_2023a_Blue_DW.BLACK_Tz;
      }

      // DataStoreWrite: '<S610>/Data Store Write2' incorporates:
      //   MATLAB Function: '<S610>/MATLAB Function10'

      APF_Path_Plann_MATLABFunction10
        (APF_Path_Planning_2023a_BlueI_B.rtb_Product_p,
         &APF_Path_Planning_2023a_BlueI_B.sampleTime_n,
         &APF_Path_Planning_2023a_Blue_DW.BLACK_Thruster_ON_Count,
         &APF_Path_Planning_2023a_BlueI_B.sf_MATLABFunction10);

      // MATLAB Function: '<S610>/MATLAB Function3' incorporates:
      //   MATLAB Function: '<S610>/MATLAB Function11'

      APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp =
        APF_Path_Planning_2023a_BlueI_P.F_Black_X_nominal *
        APF_Path_Planning_2023a_BlueI_B.sampleTime_n;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[0] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[1] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.alpha_pol =
        APF_Path_Planning_2023a_BlueI_P.F_Black_Y_nominal *
        APF_Path_Planning_2023a_BlueI_B.sampleTime_n;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[2] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[3] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[4] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[5] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[6] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[7] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      memset(&APF_Path_Planning_2023a_BlueI_B.y[0], 0, sizeof(real_T) << 6U);
      for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset < 8;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
        APF_Path_Planning_2023a_BlueI_B.y[APF_Path_Planning_2023a_BlueI_B.b_xoffset
          + (APF_Path_Planning_2023a_BlueI_B.b_xoffset << 3)] =
          APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
      }

      // MATLAB Function: '<S610>/MATLAB Function11'
      APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp /= 2.0;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[0] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[1] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.alpha_pol /= 2.0;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[2] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[3] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[4] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[5] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[6] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[7] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      memset(&APF_Path_Planning_2023a_BlueI_B.y_c[0], 0, sizeof(real_T) << 6U);
      for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset < 8;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
        APF_Path_Planning_2023a_BlueI_B.y_c[APF_Path_Planning_2023a_BlueI_B.b_xoffset
          + (APF_Path_Planning_2023a_BlueI_B.b_xoffset << 3)] =
          APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        APF_Path_Planning_2023a_BlueI_B.b[3 *
          APF_Path_Planning_2023a_BlueI_B.b_xoffset] =
          b[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        APF_Path_Planning_2023a_BlueI_B.b[3 *
          APF_Path_Planning_2023a_BlueI_B.b_xoffset + 1] =
          c[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
      }

      APF_Path_Planning_2023a_BlueI_B.b[2] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLACK[0] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[5] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLACK[1] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[8] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLACK[2] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[11] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLACK[3] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[14] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLACK[4] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[17] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLACK[5] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[20] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLACK[6] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[23] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLACK[7] / 1000.0;
      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.sampleTime_b = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 8;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            APF_Path_Planning_2023a_BlueI_B.sampleTime_b +=
              APF_Path_Planning_2023a_BlueI_B.b[3 *
              APF_Path_Planning_2023a_BlueI_B.xoffset +
              APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
              APF_Path_Planning_2023a_BlueI_B.y_c
              [(APF_Path_Planning_2023a_BlueI_B.i_o << 3) +
              APF_Path_Planning_2023a_BlueI_B.xoffset];
          }

          APF_Path_Planning_2023a_BlueI_B.Product1_e[APF_Path_Planning_2023a_BlueI_B.b_xoffset
            + 3 * APF_Path_Planning_2023a_BlueI_B.i_o] =
            APF_Path_Planning_2023a_BlueI_B.sampleTime_b;
        }
      }

      // PermuteDimensions: '<S619>/transpose' incorporates:
      //   Product: '<S610>/Product5'

      APF_Path_Planning_2023a_BlueI_B.yElIdx = 0;
      APF_Path_Planning_2023a_BlueI_B.uElOffset1 = 0;
      for (APF_Path_Planning_2023a_BlueI_B.ntIdx1 = 0;
           APF_Path_Planning_2023a_BlueI_B.ntIdx1 < 3;
           APF_Path_Planning_2023a_BlueI_B.ntIdx1++) {
        APF_Path_Planning_2023a_BlueI_B.StartClock =
          APF_Path_Planning_2023a_BlueI_B.uElOffset1;
        for (APF_Path_Planning_2023a_BlueI_B.ntIdx0 = 0;
             APF_Path_Planning_2023a_BlueI_B.ntIdx0 < 8;
             APF_Path_Planning_2023a_BlueI_B.ntIdx0++) {
          APF_Path_Planning_2023a_BlueI_B.Product2_m[APF_Path_Planning_2023a_BlueI_B.yElIdx]
            =
            APF_Path_Planning_2023a_BlueI_B.Product1_e[APF_Path_Planning_2023a_BlueI_B.StartClock];
          APF_Path_Planning_2023a_BlueI_B.yElIdx++;
          APF_Path_Planning_2023a_BlueI_B.StartClock += 3;
        }

        APF_Path_Planning_2023a_BlueI_B.uElOffset1++;
      }

      // End of PermuteDimensions: '<S619>/transpose'

      // Product: '<S619>/Product' incorporates:
      //   Product: '<S610>/Product5'

      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 3;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.sampleTime_b = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 8;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            APF_Path_Planning_2023a_BlueI_B.sampleTime_b +=
              APF_Path_Planning_2023a_BlueI_B.Product1_e[3 *
              APF_Path_Planning_2023a_BlueI_B.xoffset +
              APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
              APF_Path_Planning_2023a_BlueI_B.Product2_m
              [(APF_Path_Planning_2023a_BlueI_B.i_o << 3) +
              APF_Path_Planning_2023a_BlueI_B.xoffset];
          }

          APF_Path_Planning_2023a_BlueI_B.rtb_Product2_m_n[APF_Path_Planning_2023a_BlueI_B.b_xoffset
            + 3 * APF_Path_Planning_2023a_BlueI_B.i_o] =
            APF_Path_Planning_2023a_BlueI_B.sampleTime_b;
        }
      }

      // Product: '<S619>/Product1' incorporates:
      //   Product: '<S619>/Product'

      APF_Path_Plannin_rt_invd3x3_snf
        (APF_Path_Planning_2023a_BlueI_B.rtb_Product2_m_n,
         APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m);
      memcpy(&APF_Path_Planning_2023a_BlueI_B.rtb_Product2_m_n[0],
             &APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[0],
             9U * sizeof(real_T));
      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        // Product: '<S619>/Product2' incorporates:
        //   Product: '<S610>/Product5'

        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp =
          APF_Path_Planning_2023a_BlueI_B.Product2_m[APF_Path_Planning_2023a_BlueI_B.i_o
          + 8];
        APF_Path_Planning_2023a_BlueI_B.sampleTime_b =
          APF_Path_Planning_2023a_BlueI_B.Product2_m[APF_Path_Planning_2023a_BlueI_B.i_o];
        APF_Path_Planning_2023a_BlueI_B.sampleTime =
          APF_Path_Planning_2023a_BlueI_B.Product2_m[APF_Path_Planning_2023a_BlueI_B.i_o
          + 16];

        // Product: '<S610>/Product5'
        APF_Path_Planning_2023a_BlueI_B.sampleTime_n = 0.0;
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          // Product: '<S619>/Product2'
          APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
            (APF_Path_Planning_2023a_BlueI_B.rtb_Product2_m_n[3 *
             APF_Path_Planning_2023a_BlueI_B.b_xoffset + 1] *
             APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp +
             APF_Path_Planning_2023a_BlueI_B.rtb_Product2_m_n[3 *
             APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
             APF_Path_Planning_2023a_BlueI_B.sampleTime_b) +
            APF_Path_Planning_2023a_BlueI_B.rtb_Product2_m_n[3 *
            APF_Path_Planning_2023a_BlueI_B.b_xoffset + 2] *
            APF_Path_Planning_2023a_BlueI_B.sampleTime;

          // Product: '<S619>/Product2'
          APF_Path_Planning_2023a_BlueI_B.Product2_n[APF_Path_Planning_2023a_BlueI_B.i_o
            + (APF_Path_Planning_2023a_BlueI_B.b_xoffset << 3)] =
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // Product: '<S610>/Product5' incorporates:
          //   Product: '<S619>/Product2'

          APF_Path_Planning_2023a_BlueI_B.sampleTime_n +=
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW *
            APF_Path_Planning_2023a_BlueI_B.x_ddot[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        }

        // Saturate: '<S610>/Remove Negatives' incorporates:
        //   Product: '<S610>/Product5'

        if (APF_Path_Planning_2023a_BlueI_B.sampleTime_n >
            APF_Path_Planning_2023a_BlueI_P.RemoveNegatives_UpperSat) {
          // Saturate: '<S610>/Remove Negatives'
          APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.i_o]
            = APF_Path_Planning_2023a_BlueI_P.RemoveNegatives_UpperSat;
        } else if (APF_Path_Planning_2023a_BlueI_B.sampleTime_n <
                   APF_Path_Planning_2023a_BlueI_P.RemoveNegatives_LowerSat) {
          // Saturate: '<S610>/Remove Negatives'
          APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.i_o]
            = APF_Path_Planning_2023a_BlueI_P.RemoveNegatives_LowerSat;
        } else {
          // Saturate: '<S610>/Remove Negatives'
          APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.i_o]
            = APF_Path_Planning_2023a_BlueI_B.sampleTime_n;
        }

        // End of Saturate: '<S610>/Remove Negatives'
      }

      // MATLAB Function: '<S610>/MATLAB Function1' incorporates:
      //   Product: '<S619>/Product1'

      APF_Path_Plan_MATLABFunction1_l
        (APF_Path_Planning_2023a_BlueI_B.rtb_Product_p,
         APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_d);

      // MATLAB Function: '<S610>/MATLAB Function3'
      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        APF_Path_Planning_2023a_BlueI_B.b[3 *
          APF_Path_Planning_2023a_BlueI_B.i_o] =
          b[APF_Path_Planning_2023a_BlueI_B.i_o];
        APF_Path_Planning_2023a_BlueI_B.b[3 *
          APF_Path_Planning_2023a_BlueI_B.i_o + 1] =
          c[APF_Path_Planning_2023a_BlueI_B.i_o];
      }

      APF_Path_Planning_2023a_BlueI_B.b[2] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLACK[0] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[5] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLACK[1] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[8] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLACK[2] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[11] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLACK[3] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[14] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLACK[4] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[17] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLACK[5] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[20] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLACK[6] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[23] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLACK[7] / 1000.0;
      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 3;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        // Product: '<S610>/Product1'
        APF_Path_Planning_2023a_BlueI_B.x_ddot[APF_Path_Planning_2023a_BlueI_B.i_o]
          = 0.0;
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 8;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 8;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp +=
              APF_Path_Planning_2023a_BlueI_B.b[3 *
              APF_Path_Planning_2023a_BlueI_B.xoffset +
              APF_Path_Planning_2023a_BlueI_B.i_o] *
              APF_Path_Planning_2023a_BlueI_B.y
              [(APF_Path_Planning_2023a_BlueI_B.b_xoffset << 3) +
              APF_Path_Planning_2023a_BlueI_B.xoffset];
          }

          APF_Path_Planning_2023a_BlueI_B.x_ddot[APF_Path_Planning_2023a_BlueI_B.i_o]
            += APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp *
            APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_d[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        }

        // End of Product: '<S610>/Product1'
      }

      // DataStoreWrite: '<S610>/BLACK_Fx_Sat' incorporates:
      //   Product: '<S617>/Rotate F_b to F_I'

      APF_Path_Planning_2023a_Blue_DW.BLACK_Fx_Sat =
        APF_Path_Planning_2023a_BlueI_B.rtb_C_Ib_l[0] *
        APF_Path_Planning_2023a_BlueI_B.x_ddot[0] +
        APF_Path_Planning_2023a_BlueI_B.x_ddot[1] *
        APF_Path_Planning_2023a_BlueI_B.rtb_C_Ib_l[2];

      // DataStoreWrite: '<S610>/BLACK_Fy_Sat' incorporates:
      //   Product: '<S617>/Rotate F_b to F_I'

      APF_Path_Planning_2023a_Blue_DW.BLACK_Fy_Sat =
        APF_Path_Planning_2023a_BlueI_B.x_ddot[0] *
        APF_Path_Planning_2023a_BlueI_B.rtb_C_Ib_l[1] +
        APF_Path_Planning_2023a_BlueI_B.x_ddot[1] *
        APF_Path_Planning_2023a_BlueI_B.rtb_C_Ib_l[3];

      // DataStoreWrite: '<S610>/BLACK_Tz_Sat'
      APF_Path_Planning_2023a_Blue_DW.BLACK_Tz_Sat =
        APF_Path_Planning_2023a_BlueI_B.x_ddot[2];

      // End of Outputs for SubSystem: '<S19>/Change BLACK Behavior'
    }

    // End of If: '<S19>/This IF block determines whether or not to run the BLACK sim//exp' 

    // If: '<S19>/This IF block determines whether or not to run the BLUE sim//exp' incorporates:
    //   DataStoreRead: '<S19>/Data Store Read'
    //   DataStoreRead: '<S19>/Data Store Read1'
    //   Product: '<S631>/Product1'

    if ((APF_Path_Planning_2023a_Blue_DW.WhoAmI == 3.0) ||
        (APF_Path_Planning_2023a_BlueI_B.isSim == 1.0)) {
      // Outputs for IfAction SubSystem: '<S19>/Change BLUE Behavior' incorporates:
      //   ActionPort: '<S608>/Action Port'

      // MATLAB Function: '<S629>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S622>/BLUE_Rz'

      APF_Path_P_CreateRotationMatrix(APF_Path_Planning_2023a_Blue_DW.BLUE_Rz,
        APF_Path_Planning_2023a_BlueI_B.rtb_C_Ib_l);

      // MATLAB Function: '<S622>/MATLAB Function'
      for (APF_Path_Planning_2023a_BlueI_B.i = 0;
           APF_Path_Planning_2023a_BlueI_B.i < 8;
           APF_Path_Planning_2023a_BlueI_B.i++) {
        APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.i]
          =
          APF_Path_Planning_2023a_BlueI_P.F_thrusters_BLUE[APF_Path_Planning_2023a_BlueI_B.i]
          / 2.0;
      }

      memset(&APF_Path_Planning_2023a_BlueI_B.y[0], 0, sizeof(real_T) << 6U);
      for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset < 8;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
        APF_Path_Planning_2023a_BlueI_B.y[APF_Path_Planning_2023a_BlueI_B.b_xoffset
          + (APF_Path_Planning_2023a_BlueI_B.b_xoffset << 3)] =
          APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        APF_Path_Planning_2023a_BlueI_B.b[3 *
          APF_Path_Planning_2023a_BlueI_B.b_xoffset] =
          b[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        APF_Path_Planning_2023a_BlueI_B.b[3 *
          APF_Path_Planning_2023a_BlueI_B.b_xoffset + 1] =
          c[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        APF_Path_Planning_2023a_BlueI_B.b[3 *
          APF_Path_Planning_2023a_BlueI_B.b_xoffset + 2] =
          APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLUE[APF_Path_Planning_2023a_BlueI_B.b_xoffset]
          / 1000.0;
      }

      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 8;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp +=
              APF_Path_Planning_2023a_BlueI_B.b[3 *
              APF_Path_Planning_2023a_BlueI_B.xoffset +
              APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
              APF_Path_Planning_2023a_BlueI_B.y
              [(APF_Path_Planning_2023a_BlueI_B.i_o << 3) +
              APF_Path_Planning_2023a_BlueI_B.xoffset];
          }

          APF_Path_Planning_2023a_BlueI_B.Product2_m[APF_Path_Planning_2023a_BlueI_B.b_xoffset
            + 3 * APF_Path_Planning_2023a_BlueI_B.i_o] =
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
        }
      }

      // End of MATLAB Function: '<S622>/MATLAB Function'

      // PermuteDimensions: '<S630>/transpose' incorporates:
      //   Product: '<S631>/Product1'

      APF_Path_Planning_2023a_BlueI_B.yElIdx = 0;
      APF_Path_Planning_2023a_BlueI_B.uElOffset1 = 0;
      for (APF_Path_Planning_2023a_BlueI_B.ntIdx1 = 0;
           APF_Path_Planning_2023a_BlueI_B.ntIdx1 < 3;
           APF_Path_Planning_2023a_BlueI_B.ntIdx1++) {
        APF_Path_Planning_2023a_BlueI_B.StartClock =
          APF_Path_Planning_2023a_BlueI_B.uElOffset1;
        for (APF_Path_Planning_2023a_BlueI_B.ntIdx0 = 0;
             APF_Path_Planning_2023a_BlueI_B.ntIdx0 < 8;
             APF_Path_Planning_2023a_BlueI_B.ntIdx0++) {
          APF_Path_Planning_2023a_BlueI_B.Product1_it[APF_Path_Planning_2023a_BlueI_B.yElIdx]
            =
            APF_Path_Planning_2023a_BlueI_B.Product2_m[APF_Path_Planning_2023a_BlueI_B.StartClock];
          APF_Path_Planning_2023a_BlueI_B.yElIdx++;
          APF_Path_Planning_2023a_BlueI_B.StartClock += 3;
        }

        APF_Path_Planning_2023a_BlueI_B.uElOffset1++;
      }

      // End of PermuteDimensions: '<S630>/transpose'

      // Product: '<S630>/Product' incorporates:
      //   Product: '<S631>/Product1'

      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 3;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 8;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp +=
              APF_Path_Planning_2023a_BlueI_B.Product2_m[3 *
              APF_Path_Planning_2023a_BlueI_B.xoffset +
              APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
              APF_Path_Planning_2023a_BlueI_B.Product1_it
              [(APF_Path_Planning_2023a_BlueI_B.i_o << 3) +
              APF_Path_Planning_2023a_BlueI_B.xoffset];
          }

          APF_Path_Planning_2023a_BlueI_B.rtb_Product2_m_n[APF_Path_Planning_2023a_BlueI_B.b_xoffset
            + 3 * APF_Path_Planning_2023a_BlueI_B.i_o] =
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
        }
      }

      // Product: '<S630>/Product1' incorporates:
      //   Product: '<S630>/Product'

      APF_Path_Plannin_rt_invd3x3_snf
        (APF_Path_Planning_2023a_BlueI_B.rtb_Product2_m_n,
         APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m);

      // Product: '<S630>/Product2' incorporates:
      //   Product: '<S622>/Product4'
      //   Product: '<S631>/Product1'

      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        APF_Path_Planning_2023a_BlueI_B.isSim =
          APF_Path_Planning_2023a_BlueI_B.Product1_it[APF_Path_Planning_2023a_BlueI_B.i_o
          + 8];
        APF_Path_Planning_2023a_BlueI_B.sampleTime_n =
          APF_Path_Planning_2023a_BlueI_B.Product1_it[APF_Path_Planning_2023a_BlueI_B.i_o];
        APF_Path_Planning_2023a_BlueI_B.sampleTime_b =
          APF_Path_Planning_2023a_BlueI_B.Product1_it[APF_Path_Planning_2023a_BlueI_B.i_o
          + 16];
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.Product1_e[APF_Path_Planning_2023a_BlueI_B.i_o
            + (APF_Path_Planning_2023a_BlueI_B.b_xoffset << 3)] =
            (APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[3 *
             APF_Path_Planning_2023a_BlueI_B.b_xoffset + 1] *
             APF_Path_Planning_2023a_BlueI_B.isSim +
             APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[3 *
             APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
             APF_Path_Planning_2023a_BlueI_B.sampleTime_n) +
            APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[3 *
            APF_Path_Planning_2023a_BlueI_B.b_xoffset + 2] *
            APF_Path_Planning_2023a_BlueI_B.sampleTime_b;
        }
      }

      // End of Product: '<S630>/Product2'

      // MATLAB Function: '<S623>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S608>/BLUE_Rz'
      //   Product: '<S631>/Product2'

      APF_Path_CreateRotationMatrix_g(APF_Path_Planning_2023a_Blue_DW.BLUE_Rz,
        &APF_Path_Planning_2023a_BlueI_B.Product2[0]);

      // Product: '<S623>/Rotate F_I to F_b' incorporates:
      //   DataStoreRead: '<S608>/BLUE_Fx'
      //   DataStoreRead: '<S608>/BLUE_Fy'
      //   SignalConversion generated from: '<S623>/Rotate F_I to F_b'

      APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
        APF_Path_Planning_2023a_BlueI_B.Product2[0] *
        APF_Path_Planning_2023a_Blue_DW.BLUE_Fx +
        APF_Path_Planning_2023a_BlueI_B.Product2[2] *
        APF_Path_Planning_2023a_Blue_DW.BLUE_Fy;

      // SignalConversion generated from: '<S622>/Product' incorporates:
      //   Product: '<S623>/Rotate F_I to F_b'

      APF_Path_Planning_2023a_BlueI_B.x_ddot[0] =
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

      // Product: '<S623>/Rotate F_I to F_b' incorporates:
      //   DataStoreRead: '<S608>/BLUE_Fx'
      //   DataStoreRead: '<S608>/BLUE_Fy'
      //   SignalConversion generated from: '<S623>/Rotate F_I to F_b'

      APF_Path_Planning_2023a_BlueI_B.Sum6_a =
        APF_Path_Planning_2023a_BlueI_B.Product2[1] *
        APF_Path_Planning_2023a_Blue_DW.BLUE_Fx +
        APF_Path_Planning_2023a_BlueI_B.Product2[3] *
        APF_Path_Planning_2023a_Blue_DW.BLUE_Fy;

      // SignalConversion generated from: '<S622>/Product' incorporates:
      //   DataStoreRead: '<S608>/BLUE_Tz'

      APF_Path_Planning_2023a_BlueI_B.x_ddot[1] =
        APF_Path_Planning_2023a_BlueI_B.Sum6_a;
      APF_Path_Planning_2023a_BlueI_B.x_ddot[2] =
        APF_Path_Planning_2023a_Blue_DW.BLUE_Tz;
      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        // Product: '<S622>/Product' incorporates:
        //   DataStoreRead: '<S608>/BLUE_Tz'
        //   Product: '<S622>/Product4'
        //   Product: '<S623>/Rotate F_I to F_b'
        //   SignalConversion generated from: '<S622>/Product'

        APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.i_o]
          =
          (APF_Path_Planning_2023a_BlueI_B.Product1_e[APF_Path_Planning_2023a_BlueI_B.i_o
           + 8] * APF_Path_Planning_2023a_BlueI_B.Sum6_a +
           APF_Path_Planning_2023a_BlueI_B.Product1_e[APF_Path_Planning_2023a_BlueI_B.i_o]
           * APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW) +
          APF_Path_Planning_2023a_BlueI_B.Product1_e[APF_Path_Planning_2023a_BlueI_B.i_o
          + 16] * APF_Path_Planning_2023a_Blue_DW.BLUE_Tz;
      }

      // DataStoreWrite: '<S622>/Data Store Write1' incorporates:
      //   MATLAB Function: '<S622>/MATLAB Function6'

      APF_Path_Plann_MATLABFunction10
        (APF_Path_Planning_2023a_BlueI_B.rtb_Product_p,
         &APF_Path_Planning_2023a_BlueI_B.isSim,
         &APF_Path_Planning_2023a_Blue_DW.BLUE_Thruster_ON_Count,
         &APF_Path_Planning_2023a_BlueI_B.sf_MATLABFunction6);

      // MATLAB Function: '<S622>/MATLAB Function1' incorporates:
      //   MATLAB Function: '<S622>/MATLAB Function7'

      APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp =
        APF_Path_Planning_2023a_BlueI_P.F_Blue_X_nominal *
        APF_Path_Planning_2023a_BlueI_B.isSim;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[0] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[1] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.alpha_pol =
        APF_Path_Planning_2023a_BlueI_P.F_Blue_Y_nominal *
        APF_Path_Planning_2023a_BlueI_B.isSim;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[2] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[3] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[4] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[5] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[6] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[7] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      memset(&APF_Path_Planning_2023a_BlueI_B.y[0], 0, sizeof(real_T) << 6U);
      for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset < 8;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
        APF_Path_Planning_2023a_BlueI_B.y[APF_Path_Planning_2023a_BlueI_B.b_xoffset
          + (APF_Path_Planning_2023a_BlueI_B.b_xoffset << 3)] =
          APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
      }

      // MATLAB Function: '<S622>/MATLAB Function7'
      APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp /= 2.0;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[0] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[1] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.alpha_pol /= 2.0;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[2] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[3] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[4] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[5] =
        APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[6] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[7] =
        APF_Path_Planning_2023a_BlueI_B.alpha_pol;
      memset(&APF_Path_Planning_2023a_BlueI_B.y_c[0], 0, sizeof(real_T) << 6U);
      for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset < 8;
           APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
        APF_Path_Planning_2023a_BlueI_B.y_c[APF_Path_Planning_2023a_BlueI_B.b_xoffset
          + (APF_Path_Planning_2023a_BlueI_B.b_xoffset << 3)] =
          APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        APF_Path_Planning_2023a_BlueI_B.b[3 *
          APF_Path_Planning_2023a_BlueI_B.b_xoffset] =
          b[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        APF_Path_Planning_2023a_BlueI_B.b[3 *
          APF_Path_Planning_2023a_BlueI_B.b_xoffset + 1] =
          c[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
      }

      APF_Path_Planning_2023a_BlueI_B.b[2] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLUE[0] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[5] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLUE[1] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[8] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLUE[2] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[11] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLUE[3] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[14] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLUE[4] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[17] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLUE[5] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[20] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLUE[6] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[23] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLUE[7] / 1000.0;
      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.isSim = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 8;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            APF_Path_Planning_2023a_BlueI_B.isSim +=
              APF_Path_Planning_2023a_BlueI_B.b[3 *
              APF_Path_Planning_2023a_BlueI_B.xoffset +
              APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
              APF_Path_Planning_2023a_BlueI_B.y_c
              [(APF_Path_Planning_2023a_BlueI_B.i_o << 3) +
              APF_Path_Planning_2023a_BlueI_B.xoffset];
          }

          APF_Path_Planning_2023a_BlueI_B.Product1_it[APF_Path_Planning_2023a_BlueI_B.b_xoffset
            + 3 * APF_Path_Planning_2023a_BlueI_B.i_o] =
            APF_Path_Planning_2023a_BlueI_B.isSim;
        }
      }

      // PermuteDimensions: '<S631>/transpose' incorporates:
      //   Product: '<S622>/Product4'

      APF_Path_Planning_2023a_BlueI_B.yElIdx = 0;
      APF_Path_Planning_2023a_BlueI_B.uElOffset1 = 0;
      for (APF_Path_Planning_2023a_BlueI_B.ntIdx1 = 0;
           APF_Path_Planning_2023a_BlueI_B.ntIdx1 < 3;
           APF_Path_Planning_2023a_BlueI_B.ntIdx1++) {
        APF_Path_Planning_2023a_BlueI_B.StartClock =
          APF_Path_Planning_2023a_BlueI_B.uElOffset1;
        for (APF_Path_Planning_2023a_BlueI_B.ntIdx0 = 0;
             APF_Path_Planning_2023a_BlueI_B.ntIdx0 < 8;
             APF_Path_Planning_2023a_BlueI_B.ntIdx0++) {
          APF_Path_Planning_2023a_BlueI_B.Product1_e[APF_Path_Planning_2023a_BlueI_B.yElIdx]
            =
            APF_Path_Planning_2023a_BlueI_B.Product1_it[APF_Path_Planning_2023a_BlueI_B.StartClock];
          APF_Path_Planning_2023a_BlueI_B.yElIdx++;
          APF_Path_Planning_2023a_BlueI_B.StartClock += 3;
        }

        APF_Path_Planning_2023a_BlueI_B.uElOffset1++;
      }

      // End of PermuteDimensions: '<S631>/transpose'

      // Product: '<S631>/Product' incorporates:
      //   Product: '<S622>/Product4'

      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 3;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.isSim = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 8;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            APF_Path_Planning_2023a_BlueI_B.isSim +=
              APF_Path_Planning_2023a_BlueI_B.Product1_it[3 *
              APF_Path_Planning_2023a_BlueI_B.xoffset +
              APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
              APF_Path_Planning_2023a_BlueI_B.Product1_e
              [(APF_Path_Planning_2023a_BlueI_B.i_o << 3) +
              APF_Path_Planning_2023a_BlueI_B.xoffset];
          }

          APF_Path_Planning_2023a_BlueI_B.rtb_Product2_m_n[APF_Path_Planning_2023a_BlueI_B.b_xoffset
            + 3 * APF_Path_Planning_2023a_BlueI_B.i_o] =
            APF_Path_Planning_2023a_BlueI_B.isSim;
        }
      }

      // Product: '<S631>/Product1' incorporates:
      //   Product: '<S631>/Product'

      APF_Path_Plannin_rt_invd3x3_snf
        (APF_Path_Planning_2023a_BlueI_B.rtb_Product2_m_n,
         APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m);
      memcpy(&APF_Path_Planning_2023a_BlueI_B.rtb_Product2_m_n[0],
             &APF_Path_Planning_2023a_BlueI_B.rtb_Black_Measurments_table_r_m[0],
             9U * sizeof(real_T));
      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        // Product: '<S631>/Product2' incorporates:
        //   Product: '<S622>/Product4'

        APF_Path_Planning_2023a_BlueI_B.sampleTime_b =
          APF_Path_Planning_2023a_BlueI_B.Product1_e[APF_Path_Planning_2023a_BlueI_B.i_o
          + 8];
        APF_Path_Planning_2023a_BlueI_B.sampleTime =
          APF_Path_Planning_2023a_BlueI_B.Product1_e[APF_Path_Planning_2023a_BlueI_B.i_o];
        APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW =
          APF_Path_Planning_2023a_BlueI_B.Product1_e[APF_Path_Planning_2023a_BlueI_B.i_o
          + 16];

        // Product: '<S622>/Product4'
        APF_Path_Planning_2023a_BlueI_B.sampleTime_n = 0.0;
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 3;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          // Product: '<S631>/Product2'
          APF_Path_Planning_2023a_BlueI_B.isSim =
            (APF_Path_Planning_2023a_BlueI_B.rtb_Product2_m_n[3 *
             APF_Path_Planning_2023a_BlueI_B.b_xoffset + 1] *
             APF_Path_Planning_2023a_BlueI_B.sampleTime_b +
             APF_Path_Planning_2023a_BlueI_B.rtb_Product2_m_n[3 *
             APF_Path_Planning_2023a_BlueI_B.b_xoffset] *
             APF_Path_Planning_2023a_BlueI_B.sampleTime) +
            APF_Path_Planning_2023a_BlueI_B.rtb_Product2_m_n[3 *
            APF_Path_Planning_2023a_BlueI_B.b_xoffset + 2] *
            APF_Path_Planning_2023a_BlueI_B.RED_Tz_RW;

          // Product: '<S631>/Product2'
          APF_Path_Planning_2023a_BlueI_B.Product2[APF_Path_Planning_2023a_BlueI_B.i_o
            + (APF_Path_Planning_2023a_BlueI_B.b_xoffset << 3)] =
            APF_Path_Planning_2023a_BlueI_B.isSim;

          // Product: '<S622>/Product4' incorporates:
          //   Product: '<S631>/Product2'

          APF_Path_Planning_2023a_BlueI_B.sampleTime_n +=
            APF_Path_Planning_2023a_BlueI_B.isSim *
            APF_Path_Planning_2023a_BlueI_B.x_ddot[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        }

        // Saturate: '<S622>/Remove Negatives' incorporates:
        //   Product: '<S622>/Product4'

        if (APF_Path_Planning_2023a_BlueI_B.sampleTime_n >
            APF_Path_Planning_2023a_BlueI_P.RemoveNegatives_UpperSat_m) {
          // Saturate: '<S622>/Remove Negatives'
          APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.i_o]
            = APF_Path_Planning_2023a_BlueI_P.RemoveNegatives_UpperSat_m;
        } else if (APF_Path_Planning_2023a_BlueI_B.sampleTime_n <
                   APF_Path_Planning_2023a_BlueI_P.RemoveNegatives_LowerSat_a) {
          // Saturate: '<S622>/Remove Negatives'
          APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.i_o]
            = APF_Path_Planning_2023a_BlueI_P.RemoveNegatives_LowerSat_a;
        } else {
          // Saturate: '<S622>/Remove Negatives'
          APF_Path_Planning_2023a_BlueI_B.rtb_Product_p[APF_Path_Planning_2023a_BlueI_B.i_o]
            = APF_Path_Planning_2023a_BlueI_B.sampleTime_n;
        }

        // End of Saturate: '<S622>/Remove Negatives'
      }

      // MATLAB Function: '<S622>/MATLAB Function2' incorporates:
      //   Product: '<S631>/Product1'

      APF_Path_Plan_MATLABFunction1_l
        (APF_Path_Planning_2023a_BlueI_B.rtb_Product_p,
         APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_e);

      // MATLAB Function: '<S622>/MATLAB Function1'
      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 8;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        APF_Path_Planning_2023a_BlueI_B.b[3 *
          APF_Path_Planning_2023a_BlueI_B.i_o] =
          b[APF_Path_Planning_2023a_BlueI_B.i_o];
        APF_Path_Planning_2023a_BlueI_B.b[3 *
          APF_Path_Planning_2023a_BlueI_B.i_o + 1] =
          c[APF_Path_Planning_2023a_BlueI_B.i_o];
      }

      APF_Path_Planning_2023a_BlueI_B.b[2] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLUE[0] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[5] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLUE[1] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[8] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLUE[2] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[11] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLUE[3] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[14] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLUE[4] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[17] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLUE[5] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[20] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLUE[6] / 1000.0;
      APF_Path_Planning_2023a_BlueI_B.b[23] =
        APF_Path_Planning_2023a_BlueI_P.thruster_dist2CG_BLUE[7] / 1000.0;
      for (APF_Path_Planning_2023a_BlueI_B.i_o = 0;
           APF_Path_Planning_2023a_BlueI_B.i_o < 3;
           APF_Path_Planning_2023a_BlueI_B.i_o++) {
        // Product: '<S622>/Product1'
        APF_Path_Planning_2023a_BlueI_B.x_ddot[APF_Path_Planning_2023a_BlueI_B.i_o]
          = 0.0;
        for (APF_Path_Planning_2023a_BlueI_B.b_xoffset = 0;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset < 8;
             APF_Path_Planning_2023a_BlueI_B.b_xoffset++) {
          APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp = 0.0;
          for (APF_Path_Planning_2023a_BlueI_B.xoffset = 0;
               APF_Path_Planning_2023a_BlueI_B.xoffset < 8;
               APF_Path_Planning_2023a_BlueI_B.xoffset++) {
            APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp +=
              APF_Path_Planning_2023a_BlueI_B.b[3 *
              APF_Path_Planning_2023a_BlueI_B.xoffset +
              APF_Path_Planning_2023a_BlueI_B.i_o] *
              APF_Path_Planning_2023a_BlueI_B.y
              [(APF_Path_Planning_2023a_BlueI_B.b_xoffset << 3) +
              APF_Path_Planning_2023a_BlueI_B.xoffset];
          }

          APF_Path_Planning_2023a_BlueI_B.x_ddot[APF_Path_Planning_2023a_BlueI_B.i_o]
            += APF_Path_Planning_2023a_BlueI_B.rtb_path_m_tmp *
            APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_e[APF_Path_Planning_2023a_BlueI_B.b_xoffset];
        }

        // End of Product: '<S622>/Product1'
      }

      // DataStoreWrite: '<S622>/BLUE_Fx_Sat' incorporates:
      //   Product: '<S629>/Rotate F_b to F_I'

      APF_Path_Planning_2023a_Blue_DW.BLUE_Fx_Sat =
        APF_Path_Planning_2023a_BlueI_B.rtb_C_Ib_l[0] *
        APF_Path_Planning_2023a_BlueI_B.x_ddot[0] +
        APF_Path_Planning_2023a_BlueI_B.x_ddot[1] *
        APF_Path_Planning_2023a_BlueI_B.rtb_C_Ib_l[2];

      // DataStoreWrite: '<S622>/BLUE_Fy_Sat' incorporates:
      //   Product: '<S629>/Rotate F_b to F_I'

      APF_Path_Planning_2023a_Blue_DW.BLUE_Fy_Sat =
        APF_Path_Planning_2023a_BlueI_B.x_ddot[0] *
        APF_Path_Planning_2023a_BlueI_B.rtb_C_Ib_l[1] +
        APF_Path_Planning_2023a_BlueI_B.x_ddot[1] *
        APF_Path_Planning_2023a_BlueI_B.rtb_C_Ib_l[3];

      // DataStoreWrite: '<S622>/BLUE_Tz_Sat'
      APF_Path_Planning_2023a_Blue_DW.BLUE_Tz_Sat =
        APF_Path_Planning_2023a_BlueI_B.x_ddot[2];

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

    APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendInp[0] =
      APF_Path_Planning_2023a_BlueI_P.SafetyNumber_Value;
    APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendInp[1] =
      APF_Path_Planning_2023a_BlueI_P.PWMFreq;
    APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendInp[2] =
      ((APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final[0] +
        APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_d[0]) +
       APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_e[0]) *
      APF_Path_Planning_2023a_BlueI_P.Gain_Gain_c;
    APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendInp[3] =
      ((APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final[1] +
        APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_d[1]) +
       APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_e[1]) *
      APF_Path_Planning_2023a_BlueI_P.Gain1_Gain;
    APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendInp[4] =
      ((APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final[2] +
        APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_d[2]) +
       APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_e[2]) *
      APF_Path_Planning_2023a_BlueI_P.Gain2_Gain;
    APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendInp[5] =
      ((APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final[3] +
        APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_d[3]) +
       APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_e[3]) *
      APF_Path_Planning_2023a_BlueI_P.Gain3_Gain;
    APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendInp[6] =
      ((APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final[4] +
        APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_d[4]) +
       APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_e[4]) *
      APF_Path_Planning_2023a_BlueI_P.Gain4_Gain;
    APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendInp[7] =
      ((APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final[5] +
        APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_d[5]) +
       APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_e[5]) *
      APF_Path_Planning_2023a_BlueI_P.Gain5_Gain;
    APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendInp[8] =
      ((APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final[6] +
        APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_d[6]) +
       APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_e[6]) *
      APF_Path_Planning_2023a_BlueI_P.Gain6_Gain;
    APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendInp[9] =
      ((APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final[7] +
        APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_d[7]) +
       APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_e[7]) *
      APF_Path_Planning_2023a_BlueI_P.Gain7_Gain;
  }

  {
    real_T *lastU;
    int32_T i;
    char_T *sErr;

    // Update for If: '<Root>/Separate Phases'
    switch (APF_Path_Planning_2023a_Blue_DW.SeparatePhases_ActiveSubsystem) {
     case 0:
     case 1:
     case 6:
      break;

     case 2:
      // Update for IfAction SubSystem: '<Root>/Phase #2: Initial Position' incorporates:
      //   ActionPort: '<S8>/Action Port'

      // Update for If: '<S8>/This IF block determines whether or not to run the BLUE sim//exp' 
      if (APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhether_l2 == 0)
      {
        // Update for IfAction SubSystem: '<S8>/Change BLACK Behavior' incorporates:
        //   ActionPort: '<S33>/Action Port'

        // Update for Delay: '<S42>/Delay1'
        APF_Path_Planning_2023a_Blue_DW.icLoad_fp = false;
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_i =
          APF_Path_Planning_2023a_BlueI_B.Subtract_d;

        // Update for Delay: '<S44>/Delay1'
        APF_Path_Planning_2023a_Blue_DW.icLoad_ig = false;
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_c =
          APF_Path_Planning_2023a_BlueI_B.Subtract1_g;

        // Update for Delay: '<S40>/Delay1'
        APF_Path_Planning_2023a_Blue_DW.icLoad_p = false;
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_c1 =
          APF_Path_Planning_2023a_BlueI_B.e_out_m;

        // End of Update for SubSystem: '<S8>/Change BLACK Behavior'
      }

      // End of Update for If: '<S8>/This IF block determines whether or not to run the BLUE sim//exp' 

      // Update for If: '<S8>/This IF block determines whether or not to run the BLACK sim//exp' 
      if (APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhethero_h == 0)
      {
        // Update for IfAction SubSystem: '<S8>/Change BLUE Behavior' incorporates:
        //   ActionPort: '<S34>/Action Port'

        // Update for Delay: '<S55>/Delay1'
        APF_Path_Planning_2023a_Blue_DW.icLoad_o = false;
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_mw =
          APF_Path_Planning_2023a_BlueI_B.Subtract_n;

        // Update for Delay: '<S57>/Delay1'
        APF_Path_Planning_2023a_Blue_DW.icLoad_n = false;
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_et =
          APF_Path_Planning_2023a_BlueI_B.Subtract1_ld;

        // Update for Delay: '<S53>/Delay1'
        APF_Path_Planning_2023a_Blue_DW.icLoad_bb = false;
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_av =
          APF_Path_Planning_2023a_BlueI_B.e_out_md;

        // End of Update for SubSystem: '<S8>/Change BLUE Behavior'
      }

      // End of Update for If: '<S8>/This IF block determines whether or not to run the BLACK sim//exp' 

      // Update for If: '<S8>/This IF block determines whether or not to run the RED sim//exp ' 
      if (APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhethero_g == 0)
      {
        // Update for IfAction SubSystem: '<S8>/Change RED Behavior' incorporates:
        //   ActionPort: '<S35>/Action Port'

        // Update for Delay: '<S67>/Delay1'
        APF_Path_Planning_2023a_Blue_DW.icLoad_g = false;
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_gi =
          APF_Path_Planning_2023a_BlueI_B.e_out_k;

        // Update for Delay: '<S69>/Delay1'
        APF_Path_Planning_2023a_Blue_DW.icLoad_a = false;
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_m =
          APF_Path_Planning_2023a_BlueI_B.Subtract_j;

        // Update for Delay: '<S71>/Delay1'
        APF_Path_Planning_2023a_Blue_DW.icLoad_b = false;
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_ej =
          APF_Path_Planning_2023a_BlueI_B.Subtract1_n;

        // End of Update for SubSystem: '<S8>/Change RED Behavior'
      }

      // End of Update for If: '<S8>/This IF block determines whether or not to run the RED sim//exp ' 
      // End of Update for SubSystem: '<Root>/Phase #2: Initial Position'
      break;

     case 3:
      // Update for IfAction SubSystem: '<Root>/Phase #3: Experiment' incorporates:
      //   ActionPort: '<S9>/Action Port'

      // Update for If: '<S9>/This IF block determines whether or not to run the BLACK sim//exp' 
      if (APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhethero_n == 0)
      {
        // Update for IfAction SubSystem: '<S9>/Change BLACK Behavior' incorporates:
        //   ActionPort: '<S87>/Action Port'

        // Update for If: '<S87>/Experiment Sub-Phases'
        switch (APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSub_l)
        {
         case 0:
          // Update for IfAction SubSystem: '<S87>/Sub-Phase #1' incorporates:
          //   ActionPort: '<S90>/Action Port'

          APF_Path_Plann_SubPhase1_Update
            (&APF_Path_Planning_2023a_BlueI_B.SubPhase1,
             &APF_Path_Planning_2023a_Blue_DW.SubPhase1);

          // End of Update for SubSystem: '<S87>/Sub-Phase #1'
          break;

         case 1:
          // Update for IfAction SubSystem: '<S87>/Sub-Phase #2 ' incorporates:
          //   ActionPort: '<S91>/Action Port'

          APF_Path_Plann_SubPhase1_Update
            (&APF_Path_Planning_2023a_BlueI_B.SubPhase2,
             &APF_Path_Planning_2023a_Blue_DW.SubPhase2);

          // End of Update for SubSystem: '<S87>/Sub-Phase #2 '
          break;

         case 2:
          // Update for IfAction SubSystem: '<S87>/Sub-Phase #3 ' incorporates:
          //   ActionPort: '<S92>/Action Port'

          APF_Path_Plann_SubPhase1_Update
            (&APF_Path_Planning_2023a_BlueI_B.SubPhase3,
             &APF_Path_Planning_2023a_Blue_DW.SubPhase3);

          // End of Update for SubSystem: '<S87>/Sub-Phase #3 '
          break;

         case 3:
          // Update for IfAction SubSystem: '<S87>/Sub-Phase #4' incorporates:
          //   ActionPort: '<S93>/Action Port'

          // Update for DiscreteIntegrator: '<S149>/Start Pos' incorporates:
          //   Constant: '<S149>/Velocity'

          APF_Path_Planning_2023a_Blue_DW.StartPos_DSTATE_p +=
            APF_Path_Planning_2023a_BlueI_P.StartPos_gainval *
            APF_Path_Planning_2023a_BlueI_P.BLACK_ini[3];

          // Update for Delay: '<S154>/Delay1'
          APF_Path_Planning_2023a_Blue_DW.icLoad_c = false;
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_p =
            APF_Path_Planning_2023a_BlueI_B.Subtract_k;

          // Update for DiscreteIntegrator: '<S150>/Start Pos' incorporates:
          //   Constant: '<S150>/Velocity'

          APF_Path_Planning_2023a_Blue_DW.StartPos_DSTATE_b +=
            APF_Path_Planning_2023a_BlueI_P.StartPos_gainval_k *
            APF_Path_Planning_2023a_BlueI_P.BLACK_ini[4];

          // Update for Delay: '<S156>/Delay1'
          APF_Path_Planning_2023a_Blue_DW.icLoad_j = false;
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_na =
            APF_Path_Planning_2023a_BlueI_B.Subtract1_l;

          // Update for DiscreteIntegrator: '<S151>/Start Pos' incorporates:
          //   Constant: '<S151>/Velocity'

          APF_Path_Planning_2023a_Blue_DW.StartPos_DSTATE_l +=
            APF_Path_Planning_2023a_BlueI_P.StartPos_gainval_l *
            APF_Path_Planning_2023a_BlueI_P.BLACK_ini[5];

          // Update for Delay: '<S152>/Delay1'
          APF_Path_Planning_2023a_Blue_DW.icLoad_fo = false;
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_p2 =
            APF_Path_Planning_2023a_BlueI_B.e_out_b;

          // End of Update for SubSystem: '<S87>/Sub-Phase #4'
          break;
        }

        // End of Update for If: '<S87>/Experiment Sub-Phases'
        // End of Update for SubSystem: '<S9>/Change BLACK Behavior'
      }

      // End of Update for If: '<S9>/This IF block determines whether or not to run the BLACK sim//exp' 

      // Update for If: '<S9>/This IF block determines whether or not to run the BLUE sim//exp' 
      if (APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhethero_a == 0)
      {
        // Update for IfAction SubSystem: '<S9>/Change BLUE Behavior' incorporates:
        //   ActionPort: '<S88>/Action Port'

        // Update for If: '<S88>/Experiment Sub-Phases'
        switch (APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSub_c)
        {
         case 0:
          // Update for IfAction SubSystem: '<S88>/Sub-Phase #1' incorporates:
          //   ActionPort: '<S161>/Action Port'

          APF_Path_Pla_SubPhase1_f_Update
            (&APF_Path_Planning_2023a_BlueI_B.SubPhase1_g,
             &APF_Path_Planning_2023a_Blue_DW.SubPhase1_g);

          // End of Update for SubSystem: '<S88>/Sub-Phase #1'
          break;

         case 1:
          // Update for IfAction SubSystem: '<S88>/Sub-Phase #2 ' incorporates:
          //   ActionPort: '<S163>/Action Port'

          APF_Path_Pla_SubPhase1_f_Update
            (&APF_Path_Planning_2023a_BlueI_B.SubPhase2_c,
             &APF_Path_Planning_2023a_Blue_DW.SubPhase2_c);

          // End of Update for SubSystem: '<S88>/Sub-Phase #2 '
          break;

         case 2:
          // Update for IfAction SubSystem: '<S88>/Sub-Phase #3 ' incorporates:
          //   ActionPort: '<S164>/Action Port'

          APF_Path_Pla_SubPhase1_f_Update
            (&APF_Path_Planning_2023a_BlueI_B.SubPhase3_e,
             &APF_Path_Planning_2023a_Blue_DW.SubPhase3_e);

          // End of Update for SubSystem: '<S88>/Sub-Phase #3 '
          break;

         case 3:
          // Update for IfAction SubSystem: '<S88>/Sub-Phase #2' incorporates:
          //   ActionPort: '<S162>/Action Port'

          // Update for DiscreteIntegrator: '<S190>/Start Pos' incorporates:
          //   Constant: '<S190>/Velocity'

          APF_Path_Planning_2023a_Blue_DW.StartPos_DSTATE +=
            APF_Path_Planning_2023a_BlueI_P.StartPos_gainval_a *
            APF_Path_Planning_2023a_BlueI_P.BLACK_ini[3];

          // Update for Delay: '<S195>/Delay1'
          APF_Path_Planning_2023a_Blue_DW.icLoad_e = false;
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_a =
            APF_Path_Planning_2023a_BlueI_B.Subtract_c;

          // Update for DiscreteIntegrator: '<S191>/Start Pos' incorporates:
          //   Constant: '<S191>/Velocity'

          APF_Path_Planning_2023a_Blue_DW.StartPos_DSTATE_n +=
            APF_Path_Planning_2023a_BlueI_P.StartPos_gainval_al *
            APF_Path_Planning_2023a_BlueI_P.BLACK_ini[4];

          // Update for Delay: '<S197>/Delay1'
          APF_Path_Planning_2023a_Blue_DW.icLoad_fr = false;
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_j =
            APF_Path_Planning_2023a_BlueI_B.Subtract1;

          // Update for DiscreteIntegrator: '<S192>/Start Pos' incorporates:
          //   Constant: '<S192>/Velocity'

          APF_Path_Planning_2023a_Blue_DW.StartPos_DSTATE_f +=
            APF_Path_Planning_2023a_BlueI_P.StartPos_gainval_j *
            APF_Path_Planning_2023a_BlueI_P.BLACK_ini[5];

          // Update for Delay: '<S193>/Delay1'
          APF_Path_Planning_2023a_Blue_DW.icLoad_iy = false;
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_e =
            APF_Path_Planning_2023a_BlueI_B.e_out_i;

          // End of Update for SubSystem: '<S88>/Sub-Phase #2'
          break;
        }

        // End of Update for If: '<S88>/Experiment Sub-Phases'
        // End of Update for SubSystem: '<S9>/Change BLUE Behavior'
      }

      // End of Update for If: '<S9>/This IF block determines whether or not to run the BLUE sim//exp' 

      // Update for If: '<S9>/This IF block determines whether or not to run the RED sim//exp ' 
      if (APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhether_fg == 0)
      {
        // Update for IfAction SubSystem: '<S9>/Change RED Behavior' incorporates:
        //   ActionPort: '<S89>/Action Port'

        // Update for If: '<S89>/Experiment Sub-Phases'
        switch (APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSubsy)
        {
         case 0:
          // Update for IfAction SubSystem: '<S89>/Sub-Phase #1' incorporates:
          //   ActionPort: '<S244>/Action Port'

          APF_Path_Pla_SubPhase1_e_Update
            (&APF_Path_Planning_2023a_BlueI_B.SubPhase1_p,
             &APF_Path_Planning_2023a_Blue_DW.SubPhase1_p);

          // End of Update for SubSystem: '<S89>/Sub-Phase #1'
          break;

         case 1:
          // Update for IfAction SubSystem: '<S89>/Sub-Phase #2 ' incorporates:
          //   ActionPort: '<S245>/Action Port'

          APF_Path_Pla_SubPhase1_e_Update
            (&APF_Path_Planning_2023a_BlueI_B.SubPhase2_p,
             &APF_Path_Planning_2023a_Blue_DW.SubPhase2_p);

          // End of Update for SubSystem: '<S89>/Sub-Phase #2 '
          break;

         case 2:
          // Update for IfAction SubSystem: '<S89>/Sub-Phase #3 ' incorporates:
          //   ActionPort: '<S246>/Action Port'

          // Update for Delay: '<S323>/Delay1'
          APF_Path_Planning_2023a_Blue_DW.icLoad = false;
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_da =
            APF_Path_Planning_2023a_BlueI_B.e_out_p;

          // Update for Delay: '<S325>/Delay1'
          APF_Path_Planning_2023a_Blue_DW.icLoad_f = false;
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_d3 =
            APF_Path_Planning_2023a_BlueI_B.Subtract;

          // Update for Delay: '<S327>/Delay1'
          APF_Path_Planning_2023a_Blue_DW.icLoad_i = false;
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_g =
            APF_Path_Planning_2023a_BlueI_B.Subtract2;

          // End of Update for SubSystem: '<S89>/Sub-Phase #3 '
          break;

         case 3:
          // Update for IfAction SubSystem: '<S89>/Sub-Phase #4' incorporates:
          //   ActionPort: '<S247>/Action Port'

          // Update for Delay: '<S356>/Delay1'
          for (i = 0; i < 6; i++) {
            APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE[i] =
              APF_Path_Planning_2023a_BlueI_B.States[i];
          }

          // End of Update for Delay: '<S356>/Delay1'

          // Update for Delay: '<S356>/Delay'
          memcpy(&APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE[0],
                 &APF_Path_Planning_2023a_BlueI_B.P_K[0], 36U * sizeof(real_T));

          // Update for Delay: '<S368>/Delay'
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_c[0] =
            APF_Path_Planning_2023a_BlueI_B.Sum3[0];

          // Update for Delay: '<S369>/Delay' incorporates:
          //   Sum: '<S369>/Sum'

          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_o[0] =
            APF_Path_Planning_2023a_BlueI_B.Sum_n[0];

          // Update for Delay: '<S364>/Delay3'
          APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE[0] =
            APF_Path_Planning_2023a_BlueI_B.Gt[0];

          // Update for Delay: '<S363>/Delay'
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_d[0] =
            APF_Path_Planning_2023a_BlueI_B.Eg_n[0];

          // Update for Delay: '<S363>/Delay1'
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_n[0] =
            APF_Path_Planning_2023a_BlueI_B.Etheta[0];

          // Update for Delay: '<S370>/Delay3'
          APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_d[0] =
            APF_Path_Planning_2023a_BlueI_B.Eg[0];

          // Update for Delay: '<S366>/Delay3'
          APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_a[0] =
            APF_Path_Planning_2023a_BlueI_B.m[0];

          // Update for Delay: '<S366>/Delay1'
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_d[0] =
            APF_Path_Planning_2023a_BlueI_B.v[0];

          // Update for Delay: '<S365>/Delay3'
          APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_j[0] =
            APF_Path_Planning_2023a_BlueI_B.m_b[0];

          // Update for Delay: '<S368>/Delay'
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_c[1] =
            APF_Path_Planning_2023a_BlueI_B.Sum3[1];

          // Update for Delay: '<S369>/Delay' incorporates:
          //   Sum: '<S369>/Sum'

          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_o[1] =
            APF_Path_Planning_2023a_BlueI_B.Sum_n[1];

          // Update for Delay: '<S364>/Delay3'
          APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE[1] =
            APF_Path_Planning_2023a_BlueI_B.Gt[1];

          // Update for Delay: '<S363>/Delay'
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_d[1] =
            APF_Path_Planning_2023a_BlueI_B.Eg_n[1];

          // Update for Delay: '<S363>/Delay1'
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_n[1] =
            APF_Path_Planning_2023a_BlueI_B.Etheta[1];

          // Update for Delay: '<S370>/Delay3'
          APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_d[1] =
            APF_Path_Planning_2023a_BlueI_B.Eg[1];

          // Update for Delay: '<S366>/Delay3'
          APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_a[1] =
            APF_Path_Planning_2023a_BlueI_B.m[1];

          // Update for Delay: '<S366>/Delay1'
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_d[1] =
            APF_Path_Planning_2023a_BlueI_B.v[1];

          // Update for Delay: '<S365>/Delay3'
          APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_j[1] =
            APF_Path_Planning_2023a_BlueI_B.m_b[1];

          // Update for Delay: '<S368>/Delay'
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_c[2] =
            APF_Path_Planning_2023a_BlueI_B.Sum3[2];

          // Update for Delay: '<S369>/Delay' incorporates:
          //   Sum: '<S369>/Sum'

          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_o[2] =
            APF_Path_Planning_2023a_BlueI_B.Sum_n[2];

          // Update for Delay: '<S364>/Delay3'
          APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE[2] =
            APF_Path_Planning_2023a_BlueI_B.Gt[2];

          // Update for Delay: '<S363>/Delay'
          APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_d[2] =
            APF_Path_Planning_2023a_BlueI_B.Eg_n[2];

          // Update for Delay: '<S363>/Delay1'
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_n[2] =
            APF_Path_Planning_2023a_BlueI_B.Etheta[2];

          // Update for Delay: '<S370>/Delay3'
          APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_d[2] =
            APF_Path_Planning_2023a_BlueI_B.Eg[2];

          // Update for Delay: '<S366>/Delay3'
          APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_a[2] =
            APF_Path_Planning_2023a_BlueI_B.m[2];

          // Update for Delay: '<S366>/Delay1'
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_d[2] =
            APF_Path_Planning_2023a_BlueI_B.v[2];

          // Update for Delay: '<S365>/Delay3'
          APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_j[2] =
            APF_Path_Planning_2023a_BlueI_B.m_b[2];

          // Update for Delay: '<S365>/Delay1'
          APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_l =
            APF_Path_Planning_2023a_BlueI_B.v_d;

          // Update for Derivative: '<S349>/Derivative2'
          if (APF_Path_Planning_2023a_Blue_DW.TimeStampA == (rtInf)) {
            APF_Path_Planning_2023a_Blue_DW.TimeStampA =
              APF_Path_Planning_2023a_Blue_M->Timing.t[0];
            lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeA;
          } else if (APF_Path_Planning_2023a_Blue_DW.TimeStampB == (rtInf)) {
            APF_Path_Planning_2023a_Blue_DW.TimeStampB =
              APF_Path_Planning_2023a_Blue_M->Timing.t[0];
            lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeB;
          } else if (APF_Path_Planning_2023a_Blue_DW.TimeStampA <
                     APF_Path_Planning_2023a_Blue_DW.TimeStampB) {
            APF_Path_Planning_2023a_Blue_DW.TimeStampA =
              APF_Path_Planning_2023a_Blue_M->Timing.t[0];
            lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeA;
          } else {
            APF_Path_Planning_2023a_Blue_DW.TimeStampB =
              APF_Path_Planning_2023a_Blue_M->Timing.t[0];
            lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeB;
          }

          *lastU = APF_Path_Planning_2023a_BlueI_B.Sum;

          // End of Update for Derivative: '<S349>/Derivative2'

          // Update for DiscreteIntegrator: '<S349>/Discrete-Time Integrator4'
          APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator4_DSTATE +=
            APF_Path_Planning_2023a_BlueI_P.DiscreteTimeIntegrator4_gainval *
            APF_Path_Planning_2023a_BlueI_B.k2_dot_d;

          // Update for DiscreteIntegrator: '<S349>/Discrete-Time Integrator5'
          APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator5_DSTATE +=
            APF_Path_Planning_2023a_BlueI_P.DiscreteTimeIntegrator5_gainval *
            APF_Path_Planning_2023a_BlueI_B.k1_dot_e;

          // Update for Derivative: '<S349>/Derivative1'
          if (APF_Path_Planning_2023a_Blue_DW.TimeStampA_n == (rtInf)) {
            APF_Path_Planning_2023a_Blue_DW.TimeStampA_n =
              APF_Path_Planning_2023a_Blue_M->Timing.t[0];
            lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeA_d;
          } else if (APF_Path_Planning_2023a_Blue_DW.TimeStampB_h == (rtInf)) {
            APF_Path_Planning_2023a_Blue_DW.TimeStampB_h =
              APF_Path_Planning_2023a_Blue_M->Timing.t[0];
            lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeB_l;
          } else if (APF_Path_Planning_2023a_Blue_DW.TimeStampA_n <
                     APF_Path_Planning_2023a_Blue_DW.TimeStampB_h) {
            APF_Path_Planning_2023a_Blue_DW.TimeStampA_n =
              APF_Path_Planning_2023a_Blue_M->Timing.t[0];
            lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeA_d;
          } else {
            APF_Path_Planning_2023a_Blue_DW.TimeStampB_h =
              APF_Path_Planning_2023a_Blue_M->Timing.t[0];
            lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeB_l;
          }

          *lastU = APF_Path_Planning_2023a_BlueI_B.Sum1;

          // End of Update for Derivative: '<S349>/Derivative1'

          // Update for DiscreteIntegrator: '<S349>/Discrete-Time Integrator2'
          APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator2_DSTATE +=
            APF_Path_Planning_2023a_BlueI_P.DiscreteTimeIntegrator2_gainval *
            APF_Path_Planning_2023a_BlueI_B.k2_dot_a;

          // Update for DiscreteIntegrator: '<S349>/Discrete-Time Integrator3'
          APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator3_DSTATE +=
            APF_Path_Planning_2023a_BlueI_P.DiscreteTimeIntegrator3_gainval *
            APF_Path_Planning_2023a_BlueI_B.k1_dot_j;

          // Update for DiscreteIntegrator: '<S349>/Discrete-Time Integrator1'
          APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator1_DSTATE +=
            APF_Path_Planning_2023a_BlueI_P.DiscreteTimeIntegrator1_gainval *
            APF_Path_Planning_2023a_BlueI_B.k1_dot;

          // Update for DiscreteIntegrator: '<S349>/Discrete-Time Integrator'
          APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator_DSTATE +=
            APF_Path_Planning_2023a_BlueI_P.DiscreteTimeIntegrator_gainval *
            APF_Path_Planning_2023a_BlueI_B.k2_dot;

          // Update for Derivative: '<S349>/Derivative3'
          if (APF_Path_Planning_2023a_Blue_DW.TimeStampA_m == (rtInf)) {
            APF_Path_Planning_2023a_Blue_DW.TimeStampA_m =
              APF_Path_Planning_2023a_Blue_M->Timing.t[0];
            lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeA_m;
          } else if (APF_Path_Planning_2023a_Blue_DW.TimeStampB_a == (rtInf)) {
            APF_Path_Planning_2023a_Blue_DW.TimeStampB_a =
              APF_Path_Planning_2023a_Blue_M->Timing.t[0];
            lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeB_k;
          } else if (APF_Path_Planning_2023a_Blue_DW.TimeStampA_m <
                     APF_Path_Planning_2023a_Blue_DW.TimeStampB_a) {
            APF_Path_Planning_2023a_Blue_DW.TimeStampA_m =
              APF_Path_Planning_2023a_Blue_M->Timing.t[0];
            lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeA_m;
          } else {
            APF_Path_Planning_2023a_Blue_DW.TimeStampB_a =
              APF_Path_Planning_2023a_Blue_M->Timing.t[0];
            lastU = &APF_Path_Planning_2023a_Blue_DW.LastUAtTimeB_k;
          }

          *lastU = APF_Path_Planning_2023a_BlueI_B.e_out;

          // End of Update for Derivative: '<S349>/Derivative3'
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

      APF_Pat_Phase4ReturnHome_Update
        (&APF_Path_Planning_2023a_BlueI_B.Phase4ReturnHome,
         &APF_Path_Planning_2023a_Blue_DW.Phase4ReturnHome);

      // End of Update for SubSystem: '<Root>/Phase #4: Return Home'
      break;

     case 5:
      // Update for IfAction SubSystem: '<Root>/Phase #5: Hold Home' incorporates:
      //   ActionPort: '<S11>/Action Port'

      APF_Pat_Phase4ReturnHome_Update
        (&APF_Path_Planning_2023a_BlueI_B.Phase5HoldHome,
         &APF_Path_Planning_2023a_Blue_DW.Phase5HoldHome);

      // End of Update for SubSystem: '<Root>/Phase #5: Hold Home'
      break;
    }

    // End of Update for If: '<Root>/Separate Phases'

    // Update for If: '<S13>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 
    if (APF_Path_Planning_2023a_Blue_DW.Ifperforminganexperimentgrabthe == 0) {
      // Update for IfAction SubSystem: '<S13>/Use Hardware to Obtain States' incorporates:
      //   ActionPort: '<S505>/Action Port'

      // Update for Delay: '<S515>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_l = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_eo =
        APF_Path_Planning_2023a_BlueI_B.ConvertBLUXfrommmtom;

      // Update for Delay: '<S512>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_ld = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_gs =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT;

      // Update for Delay: '<S520>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_d = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_b =
        APF_Path_Planning_2023a_BlueI_B.ConvertBLAXfrommmtom;

      // Update for Delay: '<S509>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_k = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_p4 =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_f;

      // Update for Delay: '<S521>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_fv = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_md =
        APF_Path_Planning_2023a_BlueI_B.ConvertBLAYfrommmtom;

      // Update for Delay: '<S510>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_na = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_ju =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_l;

      // Update for Delay: '<S522>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_gx = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_p4s =
        APF_Path_Planning_2023a_BlueI_B.Unwrap1;

      // Update for Delay: '<S511>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_m = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_k =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_e;

      // Update for Delay: '<S516>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_eo = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_mi =
        APF_Path_Planning_2023a_BlueI_B.ConvertBLUYfrommmtom;

      // Update for Delay: '<S513>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_fpv = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_pc =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_c;

      // Update for Delay: '<S517>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_mt = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_cu =
        APF_Path_Planning_2023a_BlueI_B.Unwrap2;

      // Update for Delay: '<S514>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_nw = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_a0 =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_cy;

      // Update for Delay: '<S508>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_h = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_h =
        APF_Path_Planning_2023a_BlueI_B.ConvertREDXfrommmtom;

      // Update for Delay: '<S523>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_au = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_ah =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_n;

      // Update for Delay: '<S518>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_eob = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_lx =
        APF_Path_Planning_2023a_BlueI_B.ConvertREDYfrommmtom;

      // Update for Delay: '<S524>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_fh = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_j3 =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_n1;

      // Update for Delay: '<S519>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_fow = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_m2 =
        APF_Path_Planning_2023a_BlueI_B.Unwrap;

      // Update for Delay: '<S525>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.icLoad_aq = false;
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_hi =
        APF_Path_Planning_2023a_BlueI_B.dividebydeltaT_m;

      // Update for Delay: '<S505>/Delay'
      APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_l[0] =
        APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_l[1];

      // Update for Delay: '<S505>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_hu[0] =
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_hu[1];

      // Update for Delay: '<S505>/Delay2'
      APF_Path_Planning_2023a_Blue_DW.Delay2_DSTATE_k[0] =
        APF_Path_Planning_2023a_Blue_DW.Delay2_DSTATE_k[1];

      // Update for Delay: '<S505>/Delay'
      APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_l[1] =
        APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_l[2];

      // Update for Delay: '<S505>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_hu[1] =
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_hu[2];

      // Update for Delay: '<S505>/Delay2'
      APF_Path_Planning_2023a_Blue_DW.Delay2_DSTATE_k[1] =
        APF_Path_Planning_2023a_Blue_DW.Delay2_DSTATE_k[2];

      // Update for Delay: '<S505>/Delay'
      APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_l[2] =
        APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_l[3];

      // Update for Delay: '<S505>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_hu[2] =
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_hu[3];

      // Update for Delay: '<S505>/Delay2'
      APF_Path_Planning_2023a_Blue_DW.Delay2_DSTATE_k[2] =
        APF_Path_Planning_2023a_Blue_DW.Delay2_DSTATE_k[3];

      // Update for Delay: '<S505>/Delay'
      APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_l[3] =
        APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_l[4];

      // Update for Delay: '<S505>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_hu[3] =
        APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_hu[4];

      // Update for Delay: '<S505>/Delay2'
      APF_Path_Planning_2023a_Blue_DW.Delay2_DSTATE_k[3] =
        APF_Path_Planning_2023a_Blue_DW.Delay2_DSTATE_k[4];

      // Update for Delay: '<S505>/Delay'
      APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_l[4] =
        APF_Path_Planning_2023a_BlueI_B.UDPReceive_o1;

      // Update for Delay: '<S505>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_hu[4] =
        APF_Path_Planning_2023a_BlueI_B.UDPReceive2_o1;

      // Update for Delay: '<S505>/Delay2'
      APF_Path_Planning_2023a_Blue_DW.Delay2_DSTATE_k[4] =
        APF_Path_Planning_2023a_BlueI_B.UDPReceive3_o1;

      // End of Update for SubSystem: '<S13>/Use Hardware to Obtain States'
    }

    // End of Update for If: '<S13>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 

    // Update for S-Function (sdspToNetwork): '<S19>/UDP Send' incorporates:
    //   SignalConversion generated from: '<S19>/UDP Send'

    sErr = GetErrorBuffer(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib[0U]);
    LibUpdate_Network(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib[0U],
                      &APF_Path_Planning_2023a_BlueI_B.TmpSignalConversionAtUDPSendInp
                      [0U], 10);
    if (*sErr != 0) {
      rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
      rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
    }

    // End of Update for S-Function (sdspToNetwork): '<S19>/UDP Send'
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  APF_Path_Planning_2023a_Blue_M->Timing.t[0] =
    ((time_T)(++APF_Path_Planning_2023a_Blue_M->Timing.clockTick0)) *
    APF_Path_Planning_2023a_Blue_M->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.01s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.01, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    APF_Path_Planning_2023a_Blue_M->Timing.clockTick1++;
  }
}

// Model initialize function
void APF_Path_Planning_2023a_BlueIsBlack_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&APF_Path_Planning_2023a_Blue_M->solverInfo,
                          &APF_Path_Planning_2023a_Blue_M->Timing.simTimeStep);
    rtsiSetTPtr(&APF_Path_Planning_2023a_Blue_M->solverInfo, &rtmGetTPtr
                (APF_Path_Planning_2023a_Blue_M));
    rtsiSetStepSizePtr(&APF_Path_Planning_2023a_Blue_M->solverInfo,
                       &APF_Path_Planning_2023a_Blue_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&APF_Path_Planning_2023a_Blue_M->solverInfo,
                          (&rtmGetErrorStatus(APF_Path_Planning_2023a_Blue_M)));
    rtsiSetRTModelPtr(&APF_Path_Planning_2023a_Blue_M->solverInfo,
                      APF_Path_Planning_2023a_Blue_M);
  }

  rtsiSetSimTimeStep(&APF_Path_Planning_2023a_Blue_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetSolverName(&APF_Path_Planning_2023a_Blue_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(APF_Path_Planning_2023a_Blue_M,
             &APF_Path_Planning_2023a_Blue_M->Timing.tArray[0]);
  APF_Path_Planning_2023a_Blue_M->Timing.stepSize0 = 0.01;

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
    sErr = GetErrorBuffer
      (&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib[0U]);
    CreateUDPInterface(&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib
                       [0U]);
    if (*sErr == 0) {
      LibCreate_Network(&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib
                        [0U], 0, "0.0.0.0",
                        APF_Path_Planning_2023a_BlueI_P.UDPReceive1_Port_f,
                        "0.0.0.0", -1, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface
        (&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S2>/UDP Receive1'

    // Start for If: '<Root>/Separate Phases'
    APF_Path_Planning_2023a_Blue_DW.SeparatePhases_ActiveSubsystem = -1;

    // Start for If: '<S13>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 
    APF_Path_Planning_2023a_Blue_DW.Ifperforminganexperimentgrabthe = -1;

    // Start for S-Function (sdspToNetwork): '<S19>/UDP Send'
    sErr = GetErrorBuffer(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib[0U]);
    CreateUDPInterface(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib[0U],
                        1, "0.0.0.0", -1, "127.0.0.1",
                        APF_Path_Planning_2023a_BlueI_P.UDPSend_Port_d5, 8192, 8,
                        0);
    }

    if (*sErr == 0) {
      LibStart(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S19>/UDP Send'

    // Start for DataStoreMemory: '<Root>/BLACK_Fx'
    APF_Path_Planning_2023a_Blue_DW.BLACK_Fx =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Fx_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Fx1'
    APF_Path_Planning_2023a_Blue_DW.BLUE_Fx =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Fx1_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Fx_Sat'
    APF_Path_Planning_2023a_Blue_DW.BLACK_Fx_Sat =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Fx_Sat_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Fx_Sat2'
    APF_Path_Planning_2023a_Blue_DW.BLUE_Fx_Sat =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Fx_Sat2_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Fy'
    APF_Path_Planning_2023a_Blue_DW.BLACK_Fy =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Fy_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Fy1'
    APF_Path_Planning_2023a_Blue_DW.BLUE_Fy =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Fy1_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Fy_Sat'
    APF_Path_Planning_2023a_Blue_DW.BLACK_Fy_Sat =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Fy_Sat_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Fy_Sat2'
    APF_Path_Planning_2023a_Blue_DW.BLUE_Fy_Sat =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Fy_Sat2_InitialValue;

    // Start for Sum: '<S552>/Sum' incorporates:
    //   DataStoreMemory: '<Root>/BLACK_Px'

    APF_Path_Planning_2023a_Blue_DW.BLACK_Px =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Px_InitialValue;

    // Start for Sum: '<S566>/Sum' incorporates:
    //   DataStoreMemory: '<Root>/BLACK_Px1'

    APF_Path_Planning_2023a_Blue_DW.BLUE_Px =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Px1_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Px2'
    APF_Path_Planning_2023a_Blue_DW.BLACK_Px_Est =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Px2_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Px3'
    APF_Path_Planning_2023a_Blue_DW.BLACK_Px_preKalm =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Px3_InitialValue;

    // Start for Sum: '<S552>/Sum' incorporates:
    //   DataStoreMemory: '<Root>/BLACK_Py'

    APF_Path_Planning_2023a_Blue_DW.BLACK_Py =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Py_InitialValue;

    // Start for Sum: '<S566>/Sum' incorporates:
    //   DataStoreMemory: '<Root>/BLACK_Py1'

    APF_Path_Planning_2023a_Blue_DW.BLUE_Py =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Py1_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Py2'
    APF_Path_Planning_2023a_Blue_DW.BLACK_Py_Est =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Py2_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Py3'
    APF_Path_Planning_2023a_Blue_DW.BLACK_Py_preKalm =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Py3_InitialValue;

    // Start for Sum: '<S552>/Sum' incorporates:
    //   DataStoreMemory: '<Root>/BLACK_Rz'

    APF_Path_Planning_2023a_Blue_DW.BLACK_Rz =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Rz_InitialValue;

    // Start for Sum: '<S566>/Sum' incorporates:
    //   DataStoreMemory: '<Root>/BLACK_Rz1'

    APF_Path_Planning_2023a_Blue_DW.BLUE_Rz =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Rz1_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Rz2'
    APF_Path_Planning_2023a_Blue_DW.BLACK_Rz_Est =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Rz2_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Rz3'
    APF_Path_Planning_2023a_Blue_DW.BLACK_Rz_preKalm =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Rz3_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Tz'
    APF_Path_Planning_2023a_Blue_DW.BLACK_Tz =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Tz_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Tz1'
    APF_Path_Planning_2023a_Blue_DW.BLUE_Tz =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Tz1_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Tz_Sat'
    APF_Path_Planning_2023a_Blue_DW.BLACK_Tz_Sat =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Tz_Sat_InitialValue;

    // Start for DataStoreMemory: '<Root>/BLACK_Tz_Sat2'
    APF_Path_Planning_2023a_Blue_DW.BLUE_Tz_Sat =
      APF_Path_Planning_2023a_BlueI_P.BLACK_Tz_Sat2_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Fx1'
    APF_Path_Planning_2023a_Blue_DW.RED_Fx =
      APF_Path_Planning_2023a_BlueI_P.RED_Fx1_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Fx_Sat'
    APF_Path_Planning_2023a_Blue_DW.RED_Fx_Sat =
      APF_Path_Planning_2023a_BlueI_P.RED_Fx_Sat_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Fy'
    APF_Path_Planning_2023a_Blue_DW.RED_Fy =
      APF_Path_Planning_2023a_BlueI_P.RED_Fy_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Fy_Sat'
    APF_Path_Planning_2023a_Blue_DW.RED_Fy_Sat =
      APF_Path_Planning_2023a_BlueI_P.RED_Fy_Sat_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Px'
    APF_Path_Planning_2023a_Blue_DW.RED_Px =
      APF_Path_Planning_2023a_BlueI_P.RED_Px_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Py'
    APF_Path_Planning_2023a_Blue_DW.RED_Py =
      APF_Path_Planning_2023a_BlueI_P.RED_Py_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Rz'
    APF_Path_Planning_2023a_Blue_DW.RED_Rz =
      APF_Path_Planning_2023a_BlueI_P.RED_Rz_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz'
    APF_Path_Planning_2023a_Blue_DW.RED_Tz =
      APF_Path_Planning_2023a_BlueI_P.RED_Tz_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz12'
    APF_Path_Planning_2023a_Blue_DW.RED_RzD_Shoulder =
      APF_Path_Planning_2023a_BlueI_P.RED_Tz12_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz13'
    APF_Path_Planning_2023a_Blue_DW.RED_RzD_Elbow =
      APF_Path_Planning_2023a_BlueI_P.RED_Tz13_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz14'
    APF_Path_Planning_2023a_Blue_DW.RED_RzD_Wrist =
      APF_Path_Planning_2023a_BlueI_P.RED_Tz14_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz15'
    APF_Path_Planning_2023a_Blue_DW.RED_ARM_Control_Mode =
      APF_Path_Planning_2023a_BlueI_P.RED_Tz15_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz16'
    APF_Path_Planning_2023a_Blue_DW.RED_Shoulder_Command =
      APF_Path_Planning_2023a_BlueI_P.RED_Tz16_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz4'
    APF_Path_Planning_2023a_Blue_DW.RED_Rz_Shoulder =
      APF_Path_Planning_2023a_BlueI_P.RED_Tz4_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz5'
    APF_Path_Planning_2023a_Blue_DW.RED_Rz_Elbow =
      APF_Path_Planning_2023a_BlueI_P.RED_Tz5_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz6'
    APF_Path_Planning_2023a_Blue_DW.RED_Rz_Wrist =
      APF_Path_Planning_2023a_BlueI_P.RED_Tz6_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz7'
    APF_Path_Planning_2023a_Blue_DW.Float_State =
      APF_Path_Planning_2023a_BlueI_P.RED_Tz7_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz_RW Sat'
    APF_Path_Planning_2023a_Blue_DW.RED_Tz_RW_Sat =
      APF_Path_Planning_2023a_BlueI_P.RED_Tz_RWSat_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz_Sat'
    APF_Path_Planning_2023a_Blue_DW.RED_Tz_Sat =
      APF_Path_Planning_2023a_BlueI_P.RED_Tz_Sat_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat1'
    APF_Path_Planning_2023a_Blue_DW.Command_Px =
      APF_Path_Planning_2023a_BlueI_P.RED_dRz_RWSat1_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat2'
    APF_Path_Planning_2023a_Blue_DW.Command_Py =
      APF_Path_Planning_2023a_BlueI_P.RED_dRz_RWSat2_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat3'
    APF_Path_Planning_2023a_Blue_DW.Command_Rz =
      APF_Path_Planning_2023a_BlueI_P.RED_dRz_RWSat3_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat4'
    APF_Path_Planning_2023a_Blue_DW.DAC_Posx_k_1 =
      APF_Path_Planning_2023a_BlueI_P.RED_dRz_RWSat4_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat5'
    APF_Path_Planning_2023a_Blue_DW.DAC_Posx_k_2 =
      APF_Path_Planning_2023a_BlueI_P.RED_dRz_RWSat5_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat6'
    APF_Path_Planning_2023a_Blue_DW.DAC_Posy_k_1 =
      APF_Path_Planning_2023a_BlueI_P.RED_dRz_RWSat6_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat7'
    APF_Path_Planning_2023a_Blue_DW.DAC_Posy_k_2 =
      APF_Path_Planning_2023a_BlueI_P.RED_dRz_RWSat7_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat8'
    APF_Path_Planning_2023a_Blue_DW.DAC_Attitude_k_1 =
      APF_Path_Planning_2023a_BlueI_P.RED_dRz_RWSat8_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_dRz_RW Sat9'
    APF_Path_Planning_2023a_Blue_DW.DAC_Attitude_k_2 =
      APF_Path_Planning_2023a_BlueI_P.RED_dRz_RWSat9_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time'
    APF_Path_Planning_2023a_Blue_DW.Univ_Time =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time1'
    APF_Path_Planning_2023a_Blue_DW.RED_Vx =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time1_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time10'
    APF_Path_Planning_2023a_Blue_DW.RED_Ax =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time10_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time11'
    APF_Path_Planning_2023a_Blue_DW.RED_Ay =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time11_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time12'
    APF_Path_Planning_2023a_Blue_DW.BLACK_Ax =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time12_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time13'
    APF_Path_Planning_2023a_Blue_DW.BLACK_Ay =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time13_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time14'
    APF_Path_Planning_2023a_Blue_DW.BLACK_RzDD =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time14_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time15'
    APF_Path_Planning_2023a_Blue_DW.RED_RzDD =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time15_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time16'
    APF_Path_Planning_2023a_Blue_DW.RED_Thruster_ON_Count =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time16_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time17'
    APF_Path_Planning_2023a_Blue_DW.BLACK_Thruster_ON_Count =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time17_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time18'
    APF_Path_Planning_2023a_Blue_DW.BLUE_Thruster_ON_Count =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time18_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time19'
    APF_Path_Planning_2023a_Blue_DW.WhoAmI =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time19_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time2'
    APF_Path_Planning_2023a_Blue_DW.RED_Vy =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time2_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time21'
    APF_Path_Planning_2023a_Blue_DW.RED_Elbow_Command =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time21_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time22'
    APF_Path_Planning_2023a_Blue_DW.RED_Wrist_Command =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time22_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time3'
    APF_Path_Planning_2023a_Blue_DW.RED_RzD =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time3_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time4'
    APF_Path_Planning_2023a_Blue_DW.BLACK_Vx =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time4_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time5'
    APF_Path_Planning_2023a_Blue_DW.BLACK_Vy =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time5_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time6'
    APF_Path_Planning_2023a_Blue_DW.BLACK_RzD =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time6_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time7'
    APF_Path_Planning_2023a_Blue_DW.BLUE_Vx =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time7_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time8'
    APF_Path_Planning_2023a_Blue_DW.BLUE_Vy =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time8_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time9'
    APF_Path_Planning_2023a_Blue_DW.BLUE_RzD =
      APF_Path_Planning_2023a_BlueI_P.Universal_Time9_InitialValue;

    // SystemInitialize for IfAction SubSystem: '<Root>/Phase #0: Synchronization' 
    APF__Phase0Synchronization_Init
      (&APF_Path_Planning_2023a_Blue_DW.Phase0Synchronization);

    // End of SystemInitialize for SubSystem: '<Root>/Phase #0: Synchronization' 

    // SystemInitialize for IfAction SubSystem: '<Root>/Phase #1: Start Floating ' 
    APF__Phase0Synchronization_Init
      (&APF_Path_Planning_2023a_Blue_DW.Phase1StartFloating);

    // End of SystemInitialize for SubSystem: '<Root>/Phase #1: Start Floating ' 

    // SystemInitialize for IfAction SubSystem: '<Root>/Phase #2: Initial Position' 
    // Start for If: '<S8>/This IF block determines whether or not to run the BLUE sim//exp' 
    APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhether_l2 = -1;

    // Start for If: '<S8>/This IF block determines whether or not to run the BLACK sim//exp' 
    APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhethero_h = -1;

    // Start for If: '<S8>/This IF block determines whether or not to run the RED sim//exp ' 
    APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhethero_g = -1;

    // SystemInitialize for IfAction SubSystem: '<S8>/Change BLACK Behavior'
    // InitializeConditions for Delay: '<S42>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_fp = true;

    // InitializeConditions for Delay: '<S44>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_ig = true;

    // InitializeConditions for Delay: '<S40>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_p = true;

    // SystemInitialize for IfAction SubSystem: '<S42>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S43>/In1' incorporates:
    //   Outport: '<S43>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi0cdy =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_nx;

    // End of SystemInitialize for SubSystem: '<S42>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S44>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S45>/In1' incorporates:
    //   Outport: '<S45>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi0cd =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_g4;

    // End of SystemInitialize for SubSystem: '<S44>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S40>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S41>/In1' incorporates:
    //   Outport: '<S41>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi0cdyi =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_gf;

    // End of SystemInitialize for SubSystem: '<S40>/Hold this value'
    // End of SystemInitialize for SubSystem: '<S8>/Change BLACK Behavior'

    // SystemInitialize for IfAction SubSystem: '<S8>/Change BLUE Behavior'
    // InitializeConditions for Delay: '<S55>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_o = true;

    // InitializeConditions for Delay: '<S57>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_n = true;

    // InitializeConditions for Delay: '<S53>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_bb = true;

    // SystemInitialize for IfAction SubSystem: '<S55>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S56>/In1' incorporates:
    //   Outport: '<S56>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_e =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_bq;

    // End of SystemInitialize for SubSystem: '<S55>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S57>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S58>/In1' incorporates:
    //   Outport: '<S58>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi0cdyix =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_c1;

    // End of SystemInitialize for SubSystem: '<S57>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S53>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S54>/In1' incorporates:
    //   Outport: '<S54>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_o =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_nj;

    // End of SystemInitialize for SubSystem: '<S53>/Hold this value'
    // End of SystemInitialize for SubSystem: '<S8>/Change BLUE Behavior'

    // SystemInitialize for IfAction SubSystem: '<S8>/Change RED Behavior'
    // InitializeConditions for Delay: '<S67>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_g = true;

    // InitializeConditions for Delay: '<S69>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_a = true;

    // InitializeConditions for Delay: '<S71>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_b = true;

    // SystemInitialize for IfAction SubSystem: '<S67>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S68>/In1' incorporates:
    //   Outport: '<S68>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi0c =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_hs;

    // End of SystemInitialize for SubSystem: '<S67>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S69>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S70>/In1' incorporates:
    //   Outport: '<S70>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi0 =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_cr;

    // End of SystemInitialize for SubSystem: '<S69>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S71>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S72>/In1' incorporates:
    //   Outport: '<S72>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_g20asdtgi =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_dg;

    // End of SystemInitialize for SubSystem: '<S71>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S35>/RED+ARM'
    APF_Path_Planning_2_REDARM_Init(&APF_Path_Planning_2023a_BlueI_B.REDARM_e,
      &APF_Path_Planning_2023a_Blue_DW.REDARM_e,
      &APF_Path_Planning_2023a_BlueI_P.REDARM_e);

    // End of SystemInitialize for SubSystem: '<S35>/RED+ARM'
    // End of SystemInitialize for SubSystem: '<S8>/Change RED Behavior'
    // End of SystemInitialize for SubSystem: '<Root>/Phase #2: Initial Position' 

    // SystemInitialize for IfAction SubSystem: '<Root>/Phase #3: Experiment'
    // Start for If: '<S9>/This IF block determines whether or not to run the BLACK sim//exp' 
    APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhethero_n = -1;

    // Start for If: '<S9>/This IF block determines whether or not to run the BLUE sim//exp' 
    APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhethero_a = -1;

    // Start for If: '<S9>/This IF block determines whether or not to run the RED sim//exp ' 
    APF_Path_Planning_2023a_Blue_DW.ThisIFblockdetermineswhether_fg = -1;

    // SystemInitialize for IfAction SubSystem: '<S9>/Change BLACK Behavior'
    // Start for If: '<S87>/Experiment Sub-Phases'
    APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSub_l = -1;

    // SystemInitialize for IfAction SubSystem: '<S87>/Sub-Phase #1'
    APF_Path_Plannin_SubPhase1_Init(&APF_Path_Planning_2023a_BlueI_B.SubPhase1,
      &APF_Path_Planning_2023a_Blue_DW.SubPhase1,
      &APF_Path_Planning_2023a_BlueI_P.SubPhase1);

    // End of SystemInitialize for SubSystem: '<S87>/Sub-Phase #1'

    // SystemInitialize for IfAction SubSystem: '<S87>/Sub-Phase #2 '
    APF_Path_Plannin_SubPhase1_Init(&APF_Path_Planning_2023a_BlueI_B.SubPhase2,
      &APF_Path_Planning_2023a_Blue_DW.SubPhase2,
      &APF_Path_Planning_2023a_BlueI_P.SubPhase2);

    // End of SystemInitialize for SubSystem: '<S87>/Sub-Phase #2 '

    // SystemInitialize for IfAction SubSystem: '<S87>/Sub-Phase #3 '
    APF_Path_Plannin_SubPhase1_Init(&APF_Path_Planning_2023a_BlueI_B.SubPhase3,
      &APF_Path_Planning_2023a_Blue_DW.SubPhase3,
      &APF_Path_Planning_2023a_BlueI_P.SubPhase3);

    // End of SystemInitialize for SubSystem: '<S87>/Sub-Phase #3 '

    // SystemInitialize for IfAction SubSystem: '<S87>/Sub-Phase #4'
    // InitializeConditions for DiscreteIntegrator: '<S149>/Start Pos'
    APF_Path_Planning_2023a_Blue_DW.StartPos_DSTATE_p =
      APF_Path_Planning_2023a_BlueI_P.BLACK_ini[0];

    // InitializeConditions for Delay: '<S154>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_c = true;

    // InitializeConditions for DiscreteIntegrator: '<S150>/Start Pos'
    APF_Path_Planning_2023a_Blue_DW.StartPos_DSTATE_b =
      APF_Path_Planning_2023a_BlueI_P.BLACK_ini[1];

    // InitializeConditions for Delay: '<S156>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_j = true;

    // InitializeConditions for DiscreteIntegrator: '<S151>/Start Pos'
    APF_Path_Planning_2023a_Blue_DW.StartPos_DSTATE_l =
      APF_Path_Planning_2023a_BlueI_P.BLACK_ini[2];

    // InitializeConditions for Delay: '<S152>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_fo = true;

    // SystemInitialize for IfAction SubSystem: '<S154>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S155>/In1' incorporates:
    //   Outport: '<S155>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_g20asdt =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_bh;

    // End of SystemInitialize for SubSystem: '<S154>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S156>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S157>/In1' incorporates:
    //   Outport: '<S157>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_g20asd =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_jy;

    // End of SystemInitialize for SubSystem: '<S156>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S152>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S153>/In1' incorporates:
    //   Outport: '<S153>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_g20asdtg =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_am;

    // End of SystemInitialize for SubSystem: '<S152>/Hold this value'
    // End of SystemInitialize for SubSystem: '<S87>/Sub-Phase #4'
    // End of SystemInitialize for SubSystem: '<S9>/Change BLACK Behavior'

    // SystemInitialize for IfAction SubSystem: '<S9>/Change BLUE Behavior'
    // Start for If: '<S88>/Experiment Sub-Phases'
    APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSub_c = -1;

    // SystemInitialize for IfAction SubSystem: '<S88>/Sub-Phase #1'
    APF_Path_Plann_SubPhase1_p_Init(&APF_Path_Planning_2023a_BlueI_B.SubPhase1_g,
      &APF_Path_Planning_2023a_Blue_DW.SubPhase1_g,
      &APF_Path_Planning_2023a_BlueI_P.SubPhase1_g);

    // End of SystemInitialize for SubSystem: '<S88>/Sub-Phase #1'

    // SystemInitialize for IfAction SubSystem: '<S88>/Sub-Phase #2 '
    APF_Path_Plann_SubPhase1_p_Init(&APF_Path_Planning_2023a_BlueI_B.SubPhase2_c,
      &APF_Path_Planning_2023a_Blue_DW.SubPhase2_c,
      &APF_Path_Planning_2023a_BlueI_P.SubPhase2_c);

    // End of SystemInitialize for SubSystem: '<S88>/Sub-Phase #2 '

    // SystemInitialize for IfAction SubSystem: '<S88>/Sub-Phase #3 '
    APF_Path_Plann_SubPhase1_p_Init(&APF_Path_Planning_2023a_BlueI_B.SubPhase3_e,
      &APF_Path_Planning_2023a_Blue_DW.SubPhase3_e,
      &APF_Path_Planning_2023a_BlueI_P.SubPhase3_e);

    // End of SystemInitialize for SubSystem: '<S88>/Sub-Phase #3 '

    // SystemInitialize for IfAction SubSystem: '<S88>/Sub-Phase #2'
    // InitializeConditions for DiscreteIntegrator: '<S190>/Start Pos'
    APF_Path_Planning_2023a_Blue_DW.StartPos_DSTATE =
      APF_Path_Planning_2023a_BlueI_P.BLACK_ini[0];

    // InitializeConditions for Delay: '<S195>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_e = true;

    // InitializeConditions for DiscreteIntegrator: '<S191>/Start Pos'
    APF_Path_Planning_2023a_Blue_DW.StartPos_DSTATE_n =
      APF_Path_Planning_2023a_BlueI_P.BLACK_ini[1];

    // InitializeConditions for Delay: '<S197>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_fr = true;

    // InitializeConditions for DiscreteIntegrator: '<S192>/Start Pos'
    APF_Path_Planning_2023a_Blue_DW.StartPos_DSTATE_f =
      APF_Path_Planning_2023a_BlueI_P.BLACK_ini[2];

    // InitializeConditions for Delay: '<S193>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_iy = true;

    // SystemInitialize for IfAction SubSystem: '<S195>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S196>/In1' incorporates:
    //   Outport: '<S196>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_g20a =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_ap;

    // End of SystemInitialize for SubSystem: '<S195>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S197>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S198>/In1' incorporates:
    //   Outport: '<S198>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_g20 =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_jf;

    // End of SystemInitialize for SubSystem: '<S197>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S193>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S194>/In1' incorporates:
    //   Outport: '<S194>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_g20as =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_dc;

    // End of SystemInitialize for SubSystem: '<S193>/Hold this value'
    // End of SystemInitialize for SubSystem: '<S88>/Sub-Phase #2'
    // End of SystemInitialize for SubSystem: '<S9>/Change BLUE Behavior'

    // SystemInitialize for IfAction SubSystem: '<S9>/Change RED Behavior'
    // Start for If: '<S89>/Experiment Sub-Phases'
    APF_Path_Planning_2023a_Blue_DW.ExperimentSubPhases_ActiveSubsy = -1;

    // SystemInitialize for IfAction SubSystem: '<S89>/Sub-Phase #1'
    APF_Path_Plann_SubPhase1_k_Init(&APF_Path_Planning_2023a_BlueI_B.SubPhase1_p,
      &APF_Path_Planning_2023a_Blue_DW.SubPhase1_p,
      &APF_Path_Planning_2023a_BlueI_P.SubPhase1_p);

    // End of SystemInitialize for SubSystem: '<S89>/Sub-Phase #1'

    // SystemInitialize for IfAction SubSystem: '<S89>/Sub-Phase #2 '
    APF_Path_Plann_SubPhase1_k_Init(&APF_Path_Planning_2023a_BlueI_B.SubPhase2_p,
      &APF_Path_Planning_2023a_Blue_DW.SubPhase2_p,
      &APF_Path_Planning_2023a_BlueI_P.SubPhase2_p);

    // End of SystemInitialize for SubSystem: '<S89>/Sub-Phase #2 '

    // SystemInitialize for IfAction SubSystem: '<S89>/Sub-Phase #3 '
    // InitializeConditions for Delay: '<S323>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad = true;

    // InitializeConditions for Delay: '<S325>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_f = true;

    // InitializeConditions for Delay: '<S327>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_i = true;

    // SystemInitialize for IfAction SubSystem: '<S323>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S324>/In1' incorporates:
    //   Outport: '<S324>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_g2 =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_ig;

    // End of SystemInitialize for SubSystem: '<S323>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S325>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S326>/In1' incorporates:
    //   Outport: '<S326>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_g =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_fb;

    // End of SystemInitialize for SubSystem: '<S325>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S327>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S328>/In1' incorporates:
    //   Outport: '<S328>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1 =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_bj;

    // End of SystemInitialize for SubSystem: '<S327>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S246>/RED+ARM'
    APF_Path_Planning_2_REDARM_Init(&APF_Path_Planning_2023a_BlueI_B.REDARM_m,
      &APF_Path_Planning_2023a_Blue_DW.REDARM_m,
      &APF_Path_Planning_2023a_BlueI_P.REDARM_m);

    // End of SystemInitialize for SubSystem: '<S246>/RED+ARM'
    // End of SystemInitialize for SubSystem: '<S89>/Sub-Phase #3 '

    // SystemInitialize for IfAction SubSystem: '<S89>/Sub-Phase #4'
    // Start for InitialCondition: '<S356>/IC1'
    APF_Path_Planning_2023a_Blue_DW.IC1_FirstOutputTime = true;

    // Start for InitialCondition: '<S356>/IC'
    APF_Path_Planning_2023a_Blue_DW.IC_FirstOutputTime = true;

    // InitializeConditions for Delay: '<S356>/Delay1'
    for (i = 0; i < 6; i++) {
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE[i] =
        APF_Path_Planning_2023a_BlueI_P.x_in[i];
    }

    // End of InitializeConditions for Delay: '<S356>/Delay1'

    // InitializeConditions for Delay: '<S356>/Delay'
    memcpy(&APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE[0],
           &APF_Path_Planning_2023a_BlueI_P.P_IC[0], 36U * sizeof(real_T));

    // InitializeConditions for Delay: '<S368>/Delay'
    APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_c[0] =
      APF_Path_Planning_2023a_BlueI_P.Delay_InitialCondition_n;

    // InitializeConditions for Delay: '<S369>/Delay'
    APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_o[0] =
      APF_Path_Planning_2023a_BlueI_P.Delay_InitialCondition_l;

    // InitializeConditions for Delay: '<S364>/Delay3'
    APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE[0] =
      APF_Path_Planning_2023a_BlueI_P.Delay3_InitialCondition;

    // InitializeConditions for Delay: '<S363>/Delay'
    APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_d[0] =
      APF_Path_Planning_2023a_BlueI_P.Delay_InitialCondition_p[0];

    // InitializeConditions for Delay: '<S363>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_n[0] =
      APF_Path_Planning_2023a_BlueI_P.Delay1_InitialCondition_d[0];

    // InitializeConditions for Delay: '<S370>/Delay3'
    APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_d[0] =
      APF_Path_Planning_2023a_BlueI_P.Delay3_InitialCondition_a;

    // InitializeConditions for Delay: '<S366>/Delay3'
    APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_a[0] =
      APF_Path_Planning_2023a_BlueI_P.Delay3_InitialCondition_e;

    // InitializeConditions for Delay: '<S366>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_d[0] =
      APF_Path_Planning_2023a_BlueI_P.Delay1_InitialCondition_o;

    // InitializeConditions for Delay: '<S365>/Delay3'
    APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_j[0] =
      APF_Path_Planning_2023a_BlueI_P.Delay3_InitialCondition_p;

    // InitializeConditions for Delay: '<S368>/Delay'
    APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_c[1] =
      APF_Path_Planning_2023a_BlueI_P.Delay_InitialCondition_n;

    // InitializeConditions for Delay: '<S369>/Delay'
    APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_o[1] =
      APF_Path_Planning_2023a_BlueI_P.Delay_InitialCondition_l;

    // InitializeConditions for Delay: '<S364>/Delay3'
    APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE[1] =
      APF_Path_Planning_2023a_BlueI_P.Delay3_InitialCondition;

    // InitializeConditions for Delay: '<S363>/Delay'
    APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_d[1] =
      APF_Path_Planning_2023a_BlueI_P.Delay_InitialCondition_p[1];

    // InitializeConditions for Delay: '<S363>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_n[1] =
      APF_Path_Planning_2023a_BlueI_P.Delay1_InitialCondition_d[1];

    // InitializeConditions for Delay: '<S370>/Delay3'
    APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_d[1] =
      APF_Path_Planning_2023a_BlueI_P.Delay3_InitialCondition_a;

    // InitializeConditions for Delay: '<S366>/Delay3'
    APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_a[1] =
      APF_Path_Planning_2023a_BlueI_P.Delay3_InitialCondition_e;

    // InitializeConditions for Delay: '<S366>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_d[1] =
      APF_Path_Planning_2023a_BlueI_P.Delay1_InitialCondition_o;

    // InitializeConditions for Delay: '<S365>/Delay3'
    APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_j[1] =
      APF_Path_Planning_2023a_BlueI_P.Delay3_InitialCondition_p;

    // InitializeConditions for Delay: '<S368>/Delay'
    APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_c[2] =
      APF_Path_Planning_2023a_BlueI_P.Delay_InitialCondition_n;

    // InitializeConditions for Delay: '<S369>/Delay'
    APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_o[2] =
      APF_Path_Planning_2023a_BlueI_P.Delay_InitialCondition_l;

    // InitializeConditions for Delay: '<S364>/Delay3'
    APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE[2] =
      APF_Path_Planning_2023a_BlueI_P.Delay3_InitialCondition;

    // InitializeConditions for Delay: '<S363>/Delay'
    APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_d[2] =
      APF_Path_Planning_2023a_BlueI_P.Delay_InitialCondition_p[2];

    // InitializeConditions for Delay: '<S363>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_n[2] =
      APF_Path_Planning_2023a_BlueI_P.Delay1_InitialCondition_d[2];

    // InitializeConditions for Delay: '<S370>/Delay3'
    APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_d[2] =
      APF_Path_Planning_2023a_BlueI_P.Delay3_InitialCondition_a;

    // InitializeConditions for Delay: '<S366>/Delay3'
    APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_a[2] =
      APF_Path_Planning_2023a_BlueI_P.Delay3_InitialCondition_e;

    // InitializeConditions for Delay: '<S366>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_d[2] =
      APF_Path_Planning_2023a_BlueI_P.Delay1_InitialCondition_o;

    // InitializeConditions for Delay: '<S365>/Delay3'
    APF_Path_Planning_2023a_Blue_DW.Delay3_DSTATE_j[2] =
      APF_Path_Planning_2023a_BlueI_P.Delay3_InitialCondition_p;

    // InitializeConditions for Delay: '<S365>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_l =
      APF_Path_Planning_2023a_BlueI_P.Delay1_InitialCondition_p;

    // InitializeConditions for Derivative: '<S349>/Derivative2'
    APF_Path_Planning_2023a_Blue_DW.TimeStampA = (rtInf);
    APF_Path_Planning_2023a_Blue_DW.TimeStampB = (rtInf);

    // InitializeConditions for DiscreteIntegrator: '<S349>/Discrete-Time Integrator4' 
    APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator4_DSTATE =
      APF_Path_Planning_2023a_BlueI_P.k_2_0;

    // InitializeConditions for DiscreteIntegrator: '<S349>/Discrete-Time Integrator5' 
    APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator5_DSTATE =
      APF_Path_Planning_2023a_BlueI_P.k_1_0;

    // InitializeConditions for Derivative: '<S349>/Derivative1'
    APF_Path_Planning_2023a_Blue_DW.TimeStampA_n = (rtInf);
    APF_Path_Planning_2023a_Blue_DW.TimeStampB_h = (rtInf);

    // InitializeConditions for DiscreteIntegrator: '<S349>/Discrete-Time Integrator2' 
    APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator2_DSTATE =
      APF_Path_Planning_2023a_BlueI_P.k_2_0;

    // InitializeConditions for DiscreteIntegrator: '<S349>/Discrete-Time Integrator3' 
    APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator3_DSTATE =
      APF_Path_Planning_2023a_BlueI_P.k_1_0;

    // InitializeConditions for DiscreteIntegrator: '<S349>/Discrete-Time Integrator1' 
    APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator1_DSTATE =
      APF_Path_Planning_2023a_BlueI_P.k_1_t_0;

    // InitializeConditions for DiscreteIntegrator: '<S349>/Discrete-Time Integrator' 
    APF_Path_Planning_2023a_Blue_DW.DiscreteTimeIntegrator_DSTATE =
      APF_Path_Planning_2023a_BlueI_P.k_2_t_0;

    // InitializeConditions for Derivative: '<S349>/Derivative3'
    APF_Path_Planning_2023a_Blue_DW.TimeStampA_m = (rtInf);
    APF_Path_Planning_2023a_Blue_DW.TimeStampB_a = (rtInf);

    // SystemInitialize for IfAction SubSystem: '<S247>/RED+ARM'
    // SystemInitialize for IfAction SubSystem: '<S354>/Simulated Position Controller' 
    SimulatedPositionControlle_Init
      (&APF_Path_Planning_2023a_BlueI_B.SimulatedPositionController,
       &APF_Path_Planning_2023a_Blue_DW.SimulatedPositionController,
       &APF_Path_Planning_2023a_BlueI_P.SimulatedPositionController);

    // End of SystemInitialize for SubSystem: '<S354>/Simulated Position Controller' 
    // End of SystemInitialize for SubSystem: '<S247>/RED+ARM'
    // End of SystemInitialize for SubSystem: '<S89>/Sub-Phase #4'
    // End of SystemInitialize for SubSystem: '<S9>/Change RED Behavior'
    // End of SystemInitialize for SubSystem: '<Root>/Phase #3: Experiment'

    // SystemInitialize for IfAction SubSystem: '<Root>/Phase #4: Return Home'
    APF_Path__Phase4ReturnHome_Init
      (&APF_Path_Planning_2023a_BlueI_B.Phase4ReturnHome,
       &APF_Path_Planning_2023a_Blue_DW.Phase4ReturnHome,
       &APF_Path_Planning_2023a_BlueI_P.Phase4ReturnHome);

    // End of SystemInitialize for SubSystem: '<Root>/Phase #4: Return Home'

    // SystemInitialize for IfAction SubSystem: '<Root>/Phase #5: Hold Home'
    APF_Path__Phase4ReturnHome_Init
      (&APF_Path_Planning_2023a_BlueI_B.Phase5HoldHome,
       &APF_Path_Planning_2023a_Blue_DW.Phase5HoldHome,
       &APF_Path_Planning_2023a_BlueI_P.Phase5HoldHome);

    // End of SystemInitialize for SubSystem: '<Root>/Phase #5: Hold Home'

    // SystemInitialize for IfAction SubSystem: '<Root>/Simulate Plant Dynamics' 
    // InitializeConditions for DiscreteIntegrator: '<S552>/Acceleration  to Velocity' 
    APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE[0] =
      APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_IC_p;

    // InitializeConditions for DiscreteIntegrator: '<S552>/Velocity to Position' 
    APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE[0] =
      APF_Path_Planning_2023a_BlueI_P.drop_states_BLACK[0];

    // InitializeConditions for DiscreteIntegrator: '<S552>/Acceleration  to Velocity' 
    APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE[1] =
      APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_IC_p;

    // InitializeConditions for DiscreteIntegrator: '<S552>/Velocity to Position' 
    APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE[1] =
      APF_Path_Planning_2023a_BlueI_P.drop_states_BLACK[1];

    // InitializeConditions for DiscreteIntegrator: '<S552>/Acceleration  to Velocity' 
    APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE[2] =
      APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_IC_p;

    // InitializeConditions for DiscreteIntegrator: '<S552>/Velocity to Position' 
    APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE[2] =
      APF_Path_Planning_2023a_BlueI_P.drop_states_BLACK[2];

    // InitializeConditions for RandomNumber: '<S552>/Random Number'
    tmp = floor(APF_Path_Planning_2023a_BlueI_P.RandomNumber_Seed_g);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_Blue_DW.RandSeed = ((((tseed - (static_cast<uint32_T>
      (i) << 16U)) + static_cast<uint32_T>(t)) << 16U) + static_cast<uint32_T>(t))
      + static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_Blue_DW.RandSeed < 1U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed = 1144108930U;
    } else if (APF_Path_Planning_2023a_Blue_DW.RandSeed > 2147483646U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed = 2147483646U;
    }

    APF_Path_Planning_2023a_Blue_DW.NextOutput = APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_Blue_DW.RandSeed) * sqrt
      (APF_Path_Planning_2023a_BlueI_P.noise_variance_BLACK) +
      APF_Path_Planning_2023a_BlueI_P.RandomNumber_Mean_d;

    // End of InitializeConditions for RandomNumber: '<S552>/Random Number'

    // InitializeConditions for Delay: '<S558>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_ou = true;

    // InitializeConditions for Delay: '<S555>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_p4 = true;

    // InitializeConditions for RandomNumber: '<S549>/Random Number1'
    tmp = floor(APF_Path_Planning_2023a_BlueI_P.RandomNumber1_Seed_j);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_Blue_DW.RandSeed_n = ((((tseed -
      (static_cast<uint32_T>(i) << 16U)) + static_cast<uint32_T>(t)) << 16U) +
      static_cast<uint32_T>(t)) + static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_Blue_DW.RandSeed_n < 1U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_n = 1144108930U;
    } else if (APF_Path_Planning_2023a_Blue_DW.RandSeed_n > 2147483646U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_n = 2147483646U;
    }

    APF_Path_Planning_2023a_Blue_DW.NextOutput_b =
      APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_Blue_DW.RandSeed_n) *
      APF_Path_Planning_2023a_BlueI_P.RandomNumber1_StdDev_e +
      APF_Path_Planning_2023a_BlueI_P.RandomNumber1_Mean_j;

    // End of InitializeConditions for RandomNumber: '<S549>/Random Number1'

    // InitializeConditions for Delay: '<S553>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_jc = true;

    // InitializeConditions for Delay: '<S556>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_jk = true;

    // InitializeConditions for RandomNumber: '<S549>/Random Number'
    tmp = floor(APF_Path_Planning_2023a_BlueI_P.RandomNumber_Seed_d);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_Blue_DW.RandSeed_g = ((((tseed -
      (static_cast<uint32_T>(i) << 16U)) + static_cast<uint32_T>(t)) << 16U) +
      static_cast<uint32_T>(t)) + static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_Blue_DW.RandSeed_g < 1U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_g = 1144108930U;
    } else if (APF_Path_Planning_2023a_Blue_DW.RandSeed_g > 2147483646U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_g = 2147483646U;
    }

    APF_Path_Planning_2023a_Blue_DW.NextOutput_j =
      APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_Blue_DW.RandSeed_g) *
      APF_Path_Planning_2023a_BlueI_P.RandomNumber_StdDev +
      APF_Path_Planning_2023a_BlueI_P.RandomNumber_Mean_g;

    // End of InitializeConditions for RandomNumber: '<S549>/Random Number'

    // InitializeConditions for Delay: '<S554>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_jr = true;

    // InitializeConditions for Delay: '<S557>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_jko = true;

    // InitializeConditions for RandomNumber: '<S549>/Random Number2'
    tmp = floor(APF_Path_Planning_2023a_BlueI_P.RandomNumber2_Seed_g);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_Blue_DW.RandSeed_m = ((((tseed -
      (static_cast<uint32_T>(i) << 16U)) + static_cast<uint32_T>(t)) << 16U) +
      static_cast<uint32_T>(t)) + static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_Blue_DW.RandSeed_m < 1U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_m = 1144108930U;
    } else if (APF_Path_Planning_2023a_Blue_DW.RandSeed_m > 2147483646U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_m = 2147483646U;
    }

    APF_Path_Planning_2023a_Blue_DW.NextOutput_g =
      APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_Blue_DW.RandSeed_m) *
      APF_Path_Planning_2023a_BlueI_P.RandomNumber2_StdDev_c +
      APF_Path_Planning_2023a_BlueI_P.RandomNumber2_Mean_b;

    // End of InitializeConditions for RandomNumber: '<S549>/Random Number2'

    // InitializeConditions for DiscreteIntegrator: '<S566>/Acceleration  to Velocity' 
    APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_i[0] =
      APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_IC_e;

    // InitializeConditions for DiscreteIntegrator: '<S566>/Velocity to Position' 
    APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE_a[0] =
      APF_Path_Planning_2023a_BlueI_P.drop_states_BLUE[0];

    // InitializeConditions for DiscreteIntegrator: '<S566>/Acceleration  to Velocity' 
    APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_i[1] =
      APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_IC_e;

    // InitializeConditions for DiscreteIntegrator: '<S566>/Velocity to Position' 
    APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE_a[1] =
      APF_Path_Planning_2023a_BlueI_P.drop_states_BLUE[1];

    // InitializeConditions for DiscreteIntegrator: '<S566>/Acceleration  to Velocity' 
    APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_i[2] =
      APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_IC_e;

    // InitializeConditions for DiscreteIntegrator: '<S566>/Velocity to Position' 
    APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE_a[2] =
      APF_Path_Planning_2023a_BlueI_P.drop_states_BLUE[2];

    // InitializeConditions for RandomNumber: '<S566>/Random Number'
    tmp = floor(APF_Path_Planning_2023a_BlueI_P.RandomNumber_Seed_p);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_Blue_DW.RandSeed_o = ((((tseed -
      (static_cast<uint32_T>(i) << 16U)) + static_cast<uint32_T>(t)) << 16U) +
      static_cast<uint32_T>(t)) + static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_Blue_DW.RandSeed_o < 1U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_o = 1144108930U;
    } else if (APF_Path_Planning_2023a_Blue_DW.RandSeed_o > 2147483646U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_o = 2147483646U;
    }

    APF_Path_Planning_2023a_Blue_DW.NextOutput_a =
      APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_Blue_DW.RandSeed_o) * sqrt
      (APF_Path_Planning_2023a_BlueI_P.noise_variance_BLUE) +
      APF_Path_Planning_2023a_BlueI_P.RandomNumber_Mean_dq;

    // End of InitializeConditions for RandomNumber: '<S566>/Random Number'

    // InitializeConditions for Delay: '<S572>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_do = true;

    // InitializeConditions for Delay: '<S569>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_nk = true;

    // InitializeConditions for RandomNumber: '<S550>/Random Number4'
    tmp = floor(APF_Path_Planning_2023a_BlueI_P.RandomNumber4_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_Blue_DW.RandSeed_n0 = ((((tseed -
      (static_cast<uint32_T>(i) << 16U)) + static_cast<uint32_T>(t)) << 16U) +
      static_cast<uint32_T>(t)) + static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_Blue_DW.RandSeed_n0 < 1U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_n0 = 1144108930U;
    } else if (APF_Path_Planning_2023a_Blue_DW.RandSeed_n0 > 2147483646U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_n0 = 2147483646U;
    }

    APF__rt_nrand_Upu32_Yd_f_pw_snf(&APF_Path_Planning_2023a_Blue_DW.RandSeed_n0);

    // End of InitializeConditions for RandomNumber: '<S550>/Random Number4'

    // InitializeConditions for Delay: '<S567>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_ip = true;

    // InitializeConditions for Delay: '<S570>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_az = true;

    // InitializeConditions for RandomNumber: '<S550>/Random Number3'
    tmp = floor(APF_Path_Planning_2023a_BlueI_P.RandomNumber3_Seed_m);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_Blue_DW.RandSeed_e = ((((tseed -
      (static_cast<uint32_T>(i) << 16U)) + static_cast<uint32_T>(t)) << 16U) +
      static_cast<uint32_T>(t)) + static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_Blue_DW.RandSeed_e < 1U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_e = 1144108930U;
    } else if (APF_Path_Planning_2023a_Blue_DW.RandSeed_e > 2147483646U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_e = 2147483646U;
    }

    APF__rt_nrand_Upu32_Yd_f_pw_snf(&APF_Path_Planning_2023a_Blue_DW.RandSeed_e);

    // End of InitializeConditions for RandomNumber: '<S550>/Random Number3'

    // InitializeConditions for Delay: '<S568>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_dh = true;

    // InitializeConditions for Delay: '<S571>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_ex = true;

    // InitializeConditions for RandomNumber: '<S550>/Random Number5'
    tmp = floor(APF_Path_Planning_2023a_BlueI_P.RandomNumber5_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_Blue_DW.RandSeed_c = ((((tseed -
      (static_cast<uint32_T>(i) << 16U)) + static_cast<uint32_T>(t)) << 16U) +
      static_cast<uint32_T>(t)) + static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_Blue_DW.RandSeed_c < 1U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_c = 1144108930U;
    } else if (APF_Path_Planning_2023a_Blue_DW.RandSeed_c > 2147483646U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_c = 2147483646U;
    }

    APF__rt_nrand_Upu32_Yd_f_pw_snf(&APF_Path_Planning_2023a_Blue_DW.RandSeed_c);

    // End of InitializeConditions for RandomNumber: '<S550>/Random Number5'

    // SystemInitialize for IfAction SubSystem: '<S558>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S565>/In1' incorporates:
    //   Outport: '<S565>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_j =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_n;

    // End of SystemInitialize for SubSystem: '<S558>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S555>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S562>/In1' incorporates:
    //   Outport: '<S562>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_d =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_g;

    // End of SystemInitialize for SubSystem: '<S555>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S553>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S560>/In1' incorporates:
    //   Outport: '<S560>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_pk =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S553>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S556>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S563>/In1' incorporates:
    //   Outport: '<S563>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_pg =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_gc;

    // End of SystemInitialize for SubSystem: '<S556>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S554>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S561>/In1' incorporates:
    //   Outport: '<S561>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_c5 =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_a;

    // End of SystemInitialize for SubSystem: '<S554>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S557>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S564>/In1' incorporates:
    //   Outport: '<S564>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_ib =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S557>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S572>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S579>/In1' incorporates:
    //   Outport: '<S579>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_ir =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S572>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S567>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S574>/In1' incorporates:
    //   Outport: '<S574>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_ex =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_o;

    // End of SystemInitialize for SubSystem: '<S567>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S568>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S575>/In1' incorporates:
    //   Outport: '<S575>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_cz =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_ow;

    // End of SystemInitialize for SubSystem: '<S568>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S551>/RED + ARM'
    for (i = 0; i < 12; i++) {
      // InitializeConditions for Delay: '<S582>/Delay'
      APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_of[i] =
        APF_Path_Planning_2023a_BlueI_P.Delay_InitialCondition;

      // InitializeConditions for DiscreteIntegrator: '<S582>/Acceleration  to Velocity' 
      APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_f[i] =
        APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_IC[i];
    }

    // InitializeConditions for Delay: '<S587>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_bs = true;

    // InitializeConditions for RandomNumber: '<S582>/Random Number2'
    tmp = floor(APF_Path_Planning_2023a_BlueI_P.RandomNumber2_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>(static_cast<
      uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_Blue_DW.RandSeed_av = ((((tseed -
      (static_cast<uint32_T>(i) << 16U)) + static_cast<uint32_T>(t)) << 16U) +
      static_cast<uint32_T>(t)) + static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_Blue_DW.RandSeed_av < 1U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_av = 1144108930U;
    } else if (APF_Path_Planning_2023a_Blue_DW.RandSeed_av > 2147483646U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_av = 2147483646U;
    }

    APF_Path_Planning_2023a_Blue_DW.NextOutput_f =
      APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_Blue_DW.RandSeed_av) *
      APF_Path_Planning_2023a_BlueI_P.RandomNumber2_StdDev +
      APF_Path_Planning_2023a_BlueI_P.RandomNumber2_Mean;

    // End of InitializeConditions for RandomNumber: '<S582>/Random Number2'

    // InitializeConditions for Delay: '<S586>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_n5 = true;

    // InitializeConditions for RandomNumber: '<S582>/Random Number1'
    tmp = floor(APF_Path_Planning_2023a_BlueI_P.RandomNumber1_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_Blue_DW.RandSeed_a4 = ((((tseed -
      (static_cast<uint32_T>(i) << 16U)) + static_cast<uint32_T>(t)) << 16U) +
      static_cast<uint32_T>(t)) + static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_Blue_DW.RandSeed_a4 < 1U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_a4 = 1144108930U;
    } else if (APF_Path_Planning_2023a_Blue_DW.RandSeed_a4 > 2147483646U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_a4 = 2147483646U;
    }

    APF_Path_Planning_2023a_Blue_DW.NextOutput_h =
      APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_Blue_DW.RandSeed_a4) *
      APF_Path_Planning_2023a_BlueI_P.RandomNumber1_StdDev +
      APF_Path_Planning_2023a_BlueI_P.RandomNumber1_Mean;

    // End of InitializeConditions for RandomNumber: '<S582>/Random Number1'

    // InitializeConditions for Delay: '<S588>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_mj = true;

    // InitializeConditions for RandomNumber: '<S582>/Random Number3'
    tmp = floor(APF_Path_Planning_2023a_BlueI_P.RandomNumber3_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_Blue_DW.RandSeed_i = ((((tseed -
      (static_cast<uint32_T>(i) << 16U)) + static_cast<uint32_T>(t)) << 16U) +
      static_cast<uint32_T>(t)) + static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_Blue_DW.RandSeed_i < 1U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_i = 1144108930U;
    } else if (APF_Path_Planning_2023a_Blue_DW.RandSeed_i > 2147483646U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_i = 2147483646U;
    }

    APF_Path_Planning_2023a_Blue_DW.NextOutput_go =
      APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_Blue_DW.RandSeed_i) *
      APF_Path_Planning_2023a_BlueI_P.RandomNumber3_StdDev +
      APF_Path_Planning_2023a_BlueI_P.RandomNumber3_Mean;

    // End of InitializeConditions for RandomNumber: '<S582>/Random Number3'

    // SystemInitialize for IfAction SubSystem: '<S587>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S590>/In1' incorporates:
    //   Outport: '<S590>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_pj =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_asw;

    // End of SystemInitialize for SubSystem: '<S587>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S586>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S589>/In1' incorporates:
    //   Outport: '<S589>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_a4 =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_b;

    // End of SystemInitialize for SubSystem: '<S586>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S588>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S591>/In1' incorporates:
    //   Outport: '<S591>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_hq =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_ea;

    // End of SystemInitialize for SubSystem: '<S588>/Hold this value'
    // End of SystemInitialize for SubSystem: '<S551>/RED + ARM'

    // SystemInitialize for IfAction SubSystem: '<S551>/RED Only'
    // InitializeConditions for DiscreteIntegrator: '<S593>/Acceleration  to Velocity' 
    APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_b[0] =
      APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_IC_n;

    // InitializeConditions for DiscreteIntegrator: '<S593>/Velocity to Position' 
    APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE_m[0] =
      APF_Path_Planning_2023a_BlueI_P.drop_states_RED[0];

    // InitializeConditions for DiscreteIntegrator: '<S593>/Acceleration  to Velocity' 
    APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_b[1] =
      APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_IC_n;

    // InitializeConditions for DiscreteIntegrator: '<S593>/Velocity to Position' 
    APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE_m[1] =
      APF_Path_Planning_2023a_BlueI_P.drop_states_RED[1];

    // InitializeConditions for DiscreteIntegrator: '<S593>/Acceleration  to Velocity' 
    APF_Path_Planning_2023a_Blue_DW.AccelerationtoVelocity_DSTATE_b[2] =
      APF_Path_Planning_2023a_BlueI_P.AccelerationtoVelocity_IC_n;

    // InitializeConditions for DiscreteIntegrator: '<S593>/Velocity to Position' 
    APF_Path_Planning_2023a_Blue_DW.VelocitytoPosition_DSTATE_m[2] =
      APF_Path_Planning_2023a_BlueI_P.drop_states_RED[2];

    // InitializeConditions for RandomNumber: '<S593>/Random Number'
    tmp = floor(APF_Path_Planning_2023a_BlueI_P.RandomNumber_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_Blue_DW.RandSeed_k = ((((tseed -
      (static_cast<uint32_T>(i) << 16U)) + static_cast<uint32_T>(t)) << 16U) +
      static_cast<uint32_T>(t)) + static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_Blue_DW.RandSeed_k < 1U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_k = 1144108930U;
    } else if (APF_Path_Planning_2023a_Blue_DW.RandSeed_k > 2147483646U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_k = 2147483646U;
    }

    APF_Path_Planning_2023a_Blue_DW.NextOutput_i =
      APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_Blue_DW.RandSeed_k) * sqrt
      (APF_Path_Planning_2023a_BlueI_P.noise_variance_RED) +
      APF_Path_Planning_2023a_BlueI_P.RandomNumber_Mean;

    // End of InitializeConditions for RandomNumber: '<S593>/Random Number'

    // InitializeConditions for Delay: '<S595>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_nn = true;

    // InitializeConditions for Delay: '<S597>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_kb = true;

    // InitializeConditions for RandomNumber: '<S592>/Random Number7'
    tmp = floor(APF_Path_Planning_2023a_BlueI_P.RandomNumber7_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_Blue_DW.RandSeed_a = ((((tseed -
      (static_cast<uint32_T>(i) << 16U)) + static_cast<uint32_T>(t)) << 16U) +
      static_cast<uint32_T>(t)) + static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_Blue_DW.RandSeed_a < 1U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_a = 1144108930U;
    } else if (APF_Path_Planning_2023a_Blue_DW.RandSeed_a > 2147483646U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_a = 2147483646U;
    }

    APF_Path_Planning_2023a_Blue_DW.NextOutput_n =
      APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_Blue_DW.RandSeed_a) *
      APF_Path_Planning_2023a_BlueI_P.RandomNumber7_StdDev +
      APF_Path_Planning_2023a_BlueI_P.RandomNumber7_Mean;

    // End of InitializeConditions for RandomNumber: '<S592>/Random Number7'

    // InitializeConditions for Delay: '<S594>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_jf = true;

    // InitializeConditions for Delay: '<S598>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_dk = true;

    // InitializeConditions for RandomNumber: '<S592>/Random Number6'
    tmp = floor(APF_Path_Planning_2023a_BlueI_P.RandomNumber6_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_Blue_DW.RandSeed_f = ((((tseed -
      (static_cast<uint32_T>(i) << 16U)) + static_cast<uint32_T>(t)) << 16U) +
      static_cast<uint32_T>(t)) + static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_Blue_DW.RandSeed_f < 1U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_f = 1144108930U;
    } else if (APF_Path_Planning_2023a_Blue_DW.RandSeed_f > 2147483646U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_f = 2147483646U;
    }

    APF_Path_Planning_2023a_Blue_DW.NextOutput_ga =
      APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_Blue_DW.RandSeed_f) *
      APF_Path_Planning_2023a_BlueI_P.RandomNumber6_StdDev +
      APF_Path_Planning_2023a_BlueI_P.RandomNumber6_Mean;

    // End of InitializeConditions for RandomNumber: '<S592>/Random Number6'

    // InitializeConditions for Delay: '<S596>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_l1 = true;

    // InitializeConditions for Delay: '<S599>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_kp = true;

    // InitializeConditions for RandomNumber: '<S592>/Random Number8'
    tmp = floor(APF_Path_Planning_2023a_BlueI_P.RandomNumber8_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? static_cast<uint32_T>(-static_cast<int32_T>
      (static_cast<uint32_T>(-tmp))) : static_cast<uint32_T>(tmp);
    i = static_cast<int32_T>(tseed >> 16U);
    t = static_cast<int32_T>(tseed & 32768U);
    APF_Path_Planning_2023a_Blue_DW.RandSeed_h = ((((tseed -
      (static_cast<uint32_T>(i) << 16U)) + static_cast<uint32_T>(t)) << 16U) +
      static_cast<uint32_T>(t)) + static_cast<uint32_T>(i);
    if (APF_Path_Planning_2023a_Blue_DW.RandSeed_h < 1U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_h = 1144108930U;
    } else if (APF_Path_Planning_2023a_Blue_DW.RandSeed_h > 2147483646U) {
      APF_Path_Planning_2023a_Blue_DW.RandSeed_h = 2147483646U;
    }

    APF_Path_Planning_2023a_Blue_DW.NextOutput_l =
      APF__rt_nrand_Upu32_Yd_f_pw_snf
      (&APF_Path_Planning_2023a_Blue_DW.RandSeed_h) *
      APF_Path_Planning_2023a_BlueI_P.RandomNumber8_StdDev +
      APF_Path_Planning_2023a_BlueI_P.RandomNumber8_Mean;

    // End of InitializeConditions for RandomNumber: '<S592>/Random Number8'

    // SystemInitialize for IfAction SubSystem: '<S595>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S602>/In1' incorporates:
    //   Outport: '<S602>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_ff =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_l;

    // End of SystemInitialize for SubSystem: '<S595>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S597>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S604>/In1' incorporates:
    //   Outport: '<S604>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_fv =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_bf;

    // End of SystemInitialize for SubSystem: '<S597>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S594>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S601>/In1' incorporates:
    //   Outport: '<S601>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_n =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_j;

    // End of SystemInitialize for SubSystem: '<S594>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S598>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S605>/In1' incorporates:
    //   Outport: '<S605>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_g0 =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_gt;

    // End of SystemInitialize for SubSystem: '<S598>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S596>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S603>/In1' incorporates:
    //   Outport: '<S603>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_h =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S596>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S599>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S606>/In1' incorporates:
    //   Outport: '<S606>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_aw =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_em;

    // End of SystemInitialize for SubSystem: '<S599>/Hold this value'
    // End of SystemInitialize for SubSystem: '<S551>/RED Only'
    // End of SystemInitialize for SubSystem: '<Root>/Simulate Plant Dynamics'

    // SystemInitialize for IfAction SubSystem: '<S1>/Change BLACK Behavior'
    APF_Pa_ChangeBLACKBehavior_Init(APF_Path_Planning_2023a_Blue_M,
      &APF_Path_Planning_2023a_Blue_DW.ChangeBLACKBehavior,
      &APF_Path_Planning_2023a_BlueI_P.ChangeBLACKBehavior);

    // End of SystemInitialize for SubSystem: '<S1>/Change BLACK Behavior'

    // SystemInitialize for IfAction SubSystem: '<S1>/Change BLUE Behavior'
    APF_Pa_ChangeBLACKBehavior_Init(APF_Path_Planning_2023a_Blue_M,
      &APF_Path_Planning_2023a_Blue_DW.ChangeBLUEBehavior,
      &APF_Path_Planning_2023a_BlueI_P.ChangeBLUEBehavior);

    // End of SystemInitialize for SubSystem: '<S1>/Change BLUE Behavior'

    // SystemInitialize for IfAction SubSystem: '<S1>/Change RED Behavior'
    // Start for S-Function (sdspToNetwork): '<S22>/UDP Send'
    sErr = GetErrorBuffer(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_l
                          [0U]);
    CreateUDPInterface(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_l[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_l[0U],
                        1, "0.0.0.0", -1, "255.255.255.255",
                        APF_Path_Planning_2023a_BlueI_P.UDPSend_Port, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_l[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_l
                          [0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S22>/UDP Send'
    // End of SystemInitialize for SubSystem: '<S1>/Change RED Behavior'

    // SystemInitialize for IfAction SubSystem: '<S4>/Enable Pucks'
    // Start for MATLABSystem: '<S25>/Set Pin 428 (Pucks) to HIGH'
    //  Constructor
    //  Support name-value pair arguments when constructing the object.
    APF_Path_Planning_2023a_Blue_DW.obj_p.matlabCodegenIsDeleted = false;
    APF_Path_Planning_2023a_Blue_DW.obj_p.gpioPin =
      APF_Path_Planning_2023a_BlueI_P.SetPin428PuckstoHIGH_gpioPin;
    APF_Path_Planning_2023a_Blue_DW.obj_p.pinDirection =
      APF_Path_Planning_2023a_BlueI_P.SetPin428PuckstoHIGH_pinDirecti;
    APF_Path_Planning_2023a_Blue_DW.obj_p.isInitialized = 1;

    //         %% Define input properties
    //  Call C-function implementing device initialization
    export_gpio(APF_Path_Planning_2023a_Blue_DW.obj_p.gpioPin);
    set_pin_direction(APF_Path_Planning_2023a_Blue_DW.obj_p.gpioPin,
                      APF_Path_Planning_2023a_Blue_DW.obj_p.pinDirection);
    APF_Path_Planning_2023a_Blue_DW.obj_p.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S4>/Enable Pucks'

    // SystemInitialize for IfAction SubSystem: '<S5>/Change RED Behavior'
    // InitializeConditions for Delay: '<S26>/Delay'
    APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_a =
      APF_Path_Planning_2023a_BlueI_P.Delay_InitialCondition_f;

    // InitializeConditions for Delay: '<S26>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_pw =
      APF_Path_Planning_2023a_BlueI_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S26>/Delay2'
    APF_Path_Planning_2023a_Blue_DW.Delay2_DSTATE =
      APF_Path_Planning_2023a_BlueI_P.Delay2_InitialCondition;

    // Start for MATLABSystem: '<S26>/Read Joint Positions using  Dynamixel Encoders' 
    APF_Path_Planning_2023a_Blue_DW.obj_d.matlabCodegenIsDeleted = false;
    if (((!rtIsInf(APF_Path_Planning_2023a_BlueI_P.baseRate)) && (!rtIsNaN
          (APF_Path_Planning_2023a_BlueI_P.baseRate))) || rtIsInf
        (APF_Path_Planning_2023a_BlueI_P.baseRate)) {
      sampleTime = APF_Path_Planning_2023a_BlueI_P.baseRate;
    }

    APF_Path_Planning_2023a_Blue_DW.obj_d.SampleTime = sampleTime;
    APF_Path_Planning_2023a_Blue_DW.obj_d.isInitialized = 1;

    //         %% Define input properties
    //  Call C-function implementing device initialization
    APF_Path_Planning_2023a_Blue_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S26>/Read Joint Positions using  Dynamixel Encoders' 
    // End of SystemInitialize for SubSystem: '<S5>/Change RED Behavior'

    // SystemInitialize for IfAction SubSystem: '<S13>/Use Hardware to Obtain States' 
    // Start for S-Function (sdspFromNetwork): '<S505>/UDP Receive1'
    sErr = GetErrorBuffer
      (&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib_b[0U]);
    CreateUDPInterface
      (&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib_b[0U]);
    if (*sErr == 0) {
      LibCreate_Network
        (&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib_b[0U], 0,
         "0.0.0.0", APF_Path_Planning_2023a_BlueI_P.UDPReceive1_Port, "0.0.0.0",
         -1, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib_b[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface
        (&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib_b[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S505>/UDP Receive1'

    // Start for S-Function (sdspFromNetwork): '<S505>/UDP Receive'
    sErr = GetErrorBuffer
      (&APF_Path_Planning_2023a_Blue_DW.UDPReceive_NetworkLib[0U]);
    CreateUDPInterface(&APF_Path_Planning_2023a_Blue_DW.UDPReceive_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&APF_Path_Planning_2023a_Blue_DW.UDPReceive_NetworkLib
                        [0U], 0, "0.0.0.0",
                        APF_Path_Planning_2023a_BlueI_P.UDPReceive_Port,
                        "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&APF_Path_Planning_2023a_Blue_DW.UDPReceive_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface
        (&APF_Path_Planning_2023a_Blue_DW.UDPReceive_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S505>/UDP Receive'

    // Start for S-Function (sdspFromNetwork): '<S505>/UDP Receive2'
    sErr = GetErrorBuffer
      (&APF_Path_Planning_2023a_Blue_DW.UDPReceive2_NetworkLib[0U]);
    CreateUDPInterface(&APF_Path_Planning_2023a_Blue_DW.UDPReceive2_NetworkLib
                       [0U]);
    if (*sErr == 0) {
      LibCreate_Network(&APF_Path_Planning_2023a_Blue_DW.UDPReceive2_NetworkLib
                        [0U], 0, "0.0.0.0",
                        APF_Path_Planning_2023a_BlueI_P.UDPReceive2_Port,
                        "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&APF_Path_Planning_2023a_Blue_DW.UDPReceive2_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface
        (&APF_Path_Planning_2023a_Blue_DW.UDPReceive2_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S505>/UDP Receive2'

    // Start for S-Function (sdspFromNetwork): '<S505>/UDP Receive3'
    sErr = GetErrorBuffer
      (&APF_Path_Planning_2023a_Blue_DW.UDPReceive3_NetworkLib[0U]);
    CreateUDPInterface(&APF_Path_Planning_2023a_Blue_DW.UDPReceive3_NetworkLib
                       [0U]);
    if (*sErr == 0) {
      LibCreate_Network(&APF_Path_Planning_2023a_Blue_DW.UDPReceive3_NetworkLib
                        [0U], 0, "0.0.0.0",
                        APF_Path_Planning_2023a_BlueI_P.UDPReceive3_Port,
                        "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&APF_Path_Planning_2023a_Blue_DW.UDPReceive3_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface
        (&APF_Path_Planning_2023a_Blue_DW.UDPReceive3_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S505>/UDP Receive3'

    // InitializeConditions for Delay: '<S515>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_l = true;

    // InitializeConditions for Delay: '<S512>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_ld = true;

    // InitializeConditions for Delay: '<S520>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_d = true;

    // InitializeConditions for Delay: '<S509>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_k = true;

    // InitializeConditions for Delay: '<S521>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_fv = true;

    // InitializeConditions for Delay: '<S510>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_na = true;

    // InitializeConditions for S-Function (sdspunwrap2): '<S505>/Unwrap1'
    APF_Path_Planning_2023a_Blue_DW.Unwrap1_FirstStep = true;

    // InitializeConditions for Delay: '<S522>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_gx = true;

    // InitializeConditions for Delay: '<S511>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_m = true;

    // InitializeConditions for Delay: '<S516>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_eo = true;

    // InitializeConditions for Delay: '<S513>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_fpv = true;

    // InitializeConditions for S-Function (sdspunwrap2): '<S505>/Unwrap2'
    APF_Path_Planning_2023a_Blue_DW.Unwrap2_FirstStep = true;

    // InitializeConditions for Delay: '<S517>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_mt = true;

    // InitializeConditions for Delay: '<S514>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_nw = true;

    // InitializeConditions for Delay: '<S508>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_h = true;

    // InitializeConditions for Delay: '<S523>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_au = true;

    // InitializeConditions for Delay: '<S518>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_eob = true;

    // InitializeConditions for Delay: '<S524>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_fh = true;

    // InitializeConditions for S-Function (sdspunwrap2): '<S505>/Unwrap'
    APF_Path_Planning_2023a_Blue_DW.Unwrap_FirstStep = true;

    // InitializeConditions for Delay: '<S519>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_fow = true;

    // InitializeConditions for Delay: '<S525>/Delay1'
    APF_Path_Planning_2023a_Blue_DW.icLoad_aq = true;
    for (i = 0; i < 5; i++) {
      // InitializeConditions for Delay: '<S505>/Delay'
      APF_Path_Planning_2023a_Blue_DW.Delay_DSTATE_l[i] =
        APF_Path_Planning_2023a_BlueI_P.Delay_InitialCondition_g;

      // InitializeConditions for Delay: '<S505>/Delay1'
      APF_Path_Planning_2023a_Blue_DW.Delay1_DSTATE_hu[i] =
        APF_Path_Planning_2023a_BlueI_P.Delay1_InitialCondition_h;

      // InitializeConditions for Delay: '<S505>/Delay2'
      APF_Path_Planning_2023a_Blue_DW.Delay2_DSTATE_k[i] =
        APF_Path_Planning_2023a_BlueI_P.Delay2_InitialCondition_j;
    }

    // SystemInitialize for IfAction SubSystem: '<S515>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S535>/In1' incorporates:
    //   Outport: '<S535>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_lk =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_hp;

    // End of SystemInitialize for SubSystem: '<S515>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S520>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S540>/In1' incorporates:
    //   Outport: '<S540>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_m =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_ck;

    // End of SystemInitialize for SubSystem: '<S520>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S509>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S529>/In1' incorporates:
    //   Outport: '<S529>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_p =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S509>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S521>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S541>/In1' incorporates:
    //   Outport: '<S541>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_b =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_ii;

    // End of SystemInitialize for SubSystem: '<S521>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S510>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S530>/In1' incorporates:
    //   Outport: '<S530>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_c =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_m3;

    // End of SystemInitialize for SubSystem: '<S510>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S522>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S542>/In1' incorporates:
    //   Outport: '<S542>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_eg =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_l2;

    // End of SystemInitialize for SubSystem: '<S522>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S511>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S531>/In1' incorporates:
    //   Outport: '<S531>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_a =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_m34;

    // End of SystemInitialize for SubSystem: '<S511>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S516>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S536>/In1' incorporates:
    //   Outport: '<S536>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_fy =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_p0;

    // End of SystemInitialize for SubSystem: '<S516>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S517>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S537>/In1' incorporates:
    //   Outport: '<S537>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_gd =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_iy;

    // End of SystemInitialize for SubSystem: '<S517>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S508>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S528>/In1' incorporates:
    //   Outport: '<S528>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_gt =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_lf;

    // End of SystemInitialize for SubSystem: '<S508>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S523>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S543>/In1' incorporates:
    //   Outport: '<S543>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_f =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_nz;

    // End of SystemInitialize for SubSystem: '<S523>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S518>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S538>/In1' incorporates:
    //   Outport: '<S538>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_em =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S518>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S524>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S544>/In1' incorporates:
    //   Outport: '<S544>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_l =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_fr;

    // End of SystemInitialize for SubSystem: '<S524>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S519>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S539>/In1' incorporates:
    //   Outport: '<S539>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_en =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_d0;

    // End of SystemInitialize for SubSystem: '<S519>/Hold this value'

    // SystemInitialize for IfAction SubSystem: '<S525>/Hold this value'
    // SystemInitialize for SignalConversion generated from: '<S545>/In1' incorporates:
    //   Outport: '<S545>/Out1'

    APF_Path_Planning_2023a_BlueI_B.In1_e0 =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_e1;

    // End of SystemInitialize for SubSystem: '<S525>/Hold this value'

    // SystemInitialize for Enabled SubSystem: '<S506>/Enabled Subsystem'
    // InitializeConditions for Memory: '<S526>/Memory'
    APF_Path_Planning_2023a_Blue_DW.Memory_PreviousInput =
      APF_Path_Planning_2023a_BlueI_P.Memory_InitialCondition;

    // SystemInitialize for Memory: '<S526>/Memory' incorporates:
    //   Outport: '<S526>/Out1'

    APF_Path_Planning_2023a_BlueI_B.Memory =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_m;

    // End of SystemInitialize for SubSystem: '<S506>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S506>/Enabled Subsystem1'
    // SystemInitialize for Sum: '<S527>/Subtract' incorporates:
    //   Outport: '<S527>/Out1'

    APF_Path_Planning_2023a_BlueI_B.Subtract_l =
      APF_Path_Planning_2023a_BlueI_P.Out1_Y0_ei;

    // End of SystemInitialize for SubSystem: '<S506>/Enabled Subsystem1'
    // End of SystemInitialize for SubSystem: '<S13>/Use Hardware to Obtain States' 

    // SystemInitialize for IfAction SubSystem: '<S14>/Subsystem'
    // Start for MATLABSystem: '<S546>/WhoAmI'
    //  Constructor
    //  Support name-value pair arguments when constructing the object.
    APF_Path_Planning_2023a_Blue_DW.obj_dk.matlabCodegenIsDeleted = false;
    if (((!rtIsInf(APF_Path_Planning_2023a_BlueI_P.baseRate)) && (!rtIsNaN
          (APF_Path_Planning_2023a_BlueI_P.baseRate))) || rtIsInf
        (APF_Path_Planning_2023a_BlueI_P.baseRate)) {
      sampleTime_0 = APF_Path_Planning_2023a_BlueI_P.baseRate;
    }

    APF_Path_Planning_2023a_Blue_DW.obj_dk.SampleTime = sampleTime_0;
    APF_Path_Planning_2023a_Blue_DW.obj_dk.isInitialized = 1;

    //         %% Define output properties
    //  Call C-function implementing device initialization
    APF_Path_Planning_2023a_Blue_DW.obj_dk.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S546>/WhoAmI'
    // End of SystemInitialize for SubSystem: '<S14>/Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S15>/Change RED Behavior'
    // Start for MATLABSystem: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
    //  Constructor
    //  Support name-value pair arguments when constructing the object.
    APF_Path_Planning_2023a_Blue_DW.obj.matlabCodegenIsDeleted = false;
    APF_Path_Planning_2023a_Blue_DW.obj.POSITION_P_GAIN =
      APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsineith;
    APF_Path_Planning_2023a_Blue_DW.obj.POSITION_I_GAIN =
      APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_c;
    APF_Path_Planning_2023a_Blue_DW.obj.POSITION_D_GAIN =
      APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_d;
    APF_Path_Planning_2023a_Blue_DW.obj.MAX_POSITION =
      APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_n;
    APF_Path_Planning_2023a_Blue_DW.obj.MIN_POSITION =
      APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_g;
    APF_Path_Planning_2023a_Blue_DW.obj.MOVE_TIME =
      APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsine_cw;
    APF_Path_Planning_2023a_Blue_DW.obj.CURRENT_LIMIT =
      APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_e;
    APF_Path_Planning_2023a_Blue_DW.obj.SPEED_P_GAIN =
      APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_k;
    APF_Path_Planning_2023a_Blue_DW.obj.SPEED_I_GAIN =
      APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_j;
    APF_Path_Planning_2023a_Blue_DW.obj.VELOCITY_LIMIT =
      APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_l;
    APF_Path_Planning_2023a_Blue_DW.obj.ACCELERATION_TIME =
      APF_Path_Planning_2023a_BlueI_P.ControlDynamixelActuatorsinei_o;
    if (((!rtIsInf(APF_Path_Planning_2023a_BlueI_P.baseRate)) && (!rtIsNaN
          (APF_Path_Planning_2023a_BlueI_P.baseRate))) || rtIsInf
        (APF_Path_Planning_2023a_BlueI_P.baseRate)) {
      sampleTime_1 = APF_Path_Planning_2023a_BlueI_P.baseRate;
    }

    APF_Path_Planning_2023a_Blue_DW.obj.SampleTime = sampleTime_1;
    APF_Path_Planning_2023a_Blue_DW.obj.isInitialized = 1;

    //         %% Define input properties
    initialize_dynamixel();
    APF_Path_Planning_2023a_Blue_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
    // End of SystemInitialize for SubSystem: '<S15>/Change RED Behavior'

    // SystemInitialize for IfAction SubSystem: '<S16>/Subsystem'
    // Start for S-Function (sdspToNetwork): '<S548>/UDP Send'
    sErr = GetErrorBuffer(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_m
                          [0U]);
    CreateUDPInterface(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_m[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_m[0U],
                        1, "0.0.0.0", -1, "192.168.1.113",
                        APF_Path_Planning_2023a_BlueI_P.UDPSend_Port_d, 8192, 8,
                        0);
    }

    if (*sErr == 0) {
      LibStart(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_m[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_m
                          [0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
        rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S548>/UDP Send'
    // End of SystemInitialize for SubSystem: '<S16>/Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S19>/Change BLUE Behavior'
    // SystemInitialize for IfAction SubSystem: '<S19>/Change BLACK Behavior'
    // SystemInitialize for IfAction SubSystem: '<S19>/Change RED Behavior'
    for (i = 0; i < 8; i++) {
      // SystemInitialize for Outport: '<S609>/RED PWM'
      APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final[i] =
        APF_Path_Planning_2023a_BlueI_P.REDPWM_Y0;

      // SystemInitialize for Outport: '<S607>/BLACK PWM'
      APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_d[i] =
        APF_Path_Planning_2023a_BlueI_P.BLACKPWM_Y0;

      // SystemInitialize for Outport: '<S608>/BLUE PWM'
      APF_Path_Planning_2023a_BlueI_B.ThrustPer_Final_e[i] =
        APF_Path_Planning_2023a_BlueI_P.BLUEPWM_Y0;
    }

    // End of SystemInitialize for SubSystem: '<S19>/Change RED Behavior'
    // End of SystemInitialize for SubSystem: '<S19>/Change BLACK Behavior'
    // End of SystemInitialize for SubSystem: '<S19>/Change BLUE Behavior'

    // Start for MATLABSystem: '<S23>/MATLAB System'
    //  Constructor
    //  Support name-value pair arguments when constructing the object.
    APF_Path_Planning_2023a_Blue_DW.obj_i.matlabCodegenIsDeleted = false;
    APF_Path_Planning_2023a_Blue_DW.obj_i.isInitialized = 1;

    //         %% Define input properties
    //  Call C-function implementing device initialization
    createFile();
    APF_Path_Planning_2023a_Blue_DW.obj_i.isSetupComplete = true;
  }
}

// Model terminate function
void APF_Path_Planning_2023a_BlueIsBlack_terminate(void)
{
  char_T *sErr;

  // Terminate for S-Function (sdspFromNetwork): '<S2>/UDP Receive1'
  sErr = GetErrorBuffer(&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib
                        [0U]);
  LibTerminate(&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
    rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
  }

  LibDestroy(&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib[0U], 0);
  DestroyUDPInterface(&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S2>/UDP Receive1'

  // Terminate for IfAction SubSystem: '<S1>/Change BLACK Behavior'
  APF_Pa_ChangeBLACKBehavior_Term(APF_Path_Planning_2023a_Blue_M,
    &APF_Path_Planning_2023a_Blue_DW.ChangeBLACKBehavior);

  // End of Terminate for SubSystem: '<S1>/Change BLACK Behavior'

  // Terminate for IfAction SubSystem: '<S1>/Change BLUE Behavior'
  APF_Pa_ChangeBLACKBehavior_Term(APF_Path_Planning_2023a_Blue_M,
    &APF_Path_Planning_2023a_Blue_DW.ChangeBLUEBehavior);

  // End of Terminate for SubSystem: '<S1>/Change BLUE Behavior'

  // Terminate for IfAction SubSystem: '<S1>/Change RED Behavior'
  // Terminate for S-Function (sdspToNetwork): '<S22>/UDP Send'
  sErr = GetErrorBuffer(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_l[0U]);
  LibTerminate(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_l[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
    rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
  }

  LibDestroy(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_l[0U], 1);
  DestroyUDPInterface(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_l[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S22>/UDP Send'
  // End of Terminate for SubSystem: '<S1>/Change RED Behavior'

  // Terminate for MATLABSystem: '<S23>/MATLAB System'
  if (!APF_Path_Planning_2023a_Blue_DW.obj_i.matlabCodegenIsDeleted) {
    APF_Path_Planning_2023a_Blue_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S23>/MATLAB System'

  // Terminate for IfAction SubSystem: '<S4>/Enable Pucks'
  // Terminate for MATLABSystem: '<S25>/Set Pin 428 (Pucks) to HIGH'
  if (!APF_Path_Planning_2023a_Blue_DW.obj_p.matlabCodegenIsDeleted) {
    APF_Path_Planning_2023a_Blue_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((APF_Path_Planning_2023a_Blue_DW.obj_p.isInitialized == 1) &&
        APF_Path_Planning_2023a_Blue_DW.obj_p.isSetupComplete) {
      //  Call C-function implementing device termination
      change_gpio_value(APF_Path_Planning_2023a_Blue_DW.obj_p.gpioPin, 0.0);
      unexport_gpio(APF_Path_Planning_2023a_Blue_DW.obj_p.gpioPin);
    }
  }

  // End of Terminate for MATLABSystem: '<S25>/Set Pin 428 (Pucks) to HIGH'
  // End of Terminate for SubSystem: '<S4>/Enable Pucks'

  // Terminate for IfAction SubSystem: '<S5>/Change RED Behavior'
  // Terminate for MATLABSystem: '<S26>/Read Joint Positions using  Dynamixel Encoders' 
  if (!APF_Path_Planning_2023a_Blue_DW.obj_d.matlabCodegenIsDeleted) {
    APF_Path_Planning_2023a_Blue_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S26>/Read Joint Positions using  Dynamixel Encoders' 
  // End of Terminate for SubSystem: '<S5>/Change RED Behavior'

  // Terminate for IfAction SubSystem: '<S13>/Use Hardware to Obtain States'
  // Terminate for S-Function (sdspFromNetwork): '<S505>/UDP Receive1'
  sErr = GetErrorBuffer
    (&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib_b[0U]);
  LibTerminate(&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib_b[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
    rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
  }

  LibDestroy(&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib_b[0U], 0);
  DestroyUDPInterface(&APF_Path_Planning_2023a_Blue_DW.UDPReceive1_NetworkLib_b
                      [0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S505>/UDP Receive1'

  // Terminate for S-Function (sdspFromNetwork): '<S505>/UDP Receive'
  sErr = GetErrorBuffer(&APF_Path_Planning_2023a_Blue_DW.UDPReceive_NetworkLib
                        [0U]);
  LibTerminate(&APF_Path_Planning_2023a_Blue_DW.UDPReceive_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
    rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
  }

  LibDestroy(&APF_Path_Planning_2023a_Blue_DW.UDPReceive_NetworkLib[0U], 0);
  DestroyUDPInterface(&APF_Path_Planning_2023a_Blue_DW.UDPReceive_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S505>/UDP Receive'

  // Terminate for S-Function (sdspFromNetwork): '<S505>/UDP Receive2'
  sErr = GetErrorBuffer(&APF_Path_Planning_2023a_Blue_DW.UDPReceive2_NetworkLib
                        [0U]);
  LibTerminate(&APF_Path_Planning_2023a_Blue_DW.UDPReceive2_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
    rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
  }

  LibDestroy(&APF_Path_Planning_2023a_Blue_DW.UDPReceive2_NetworkLib[0U], 0);
  DestroyUDPInterface(&APF_Path_Planning_2023a_Blue_DW.UDPReceive2_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S505>/UDP Receive2'

  // Terminate for S-Function (sdspFromNetwork): '<S505>/UDP Receive3'
  sErr = GetErrorBuffer(&APF_Path_Planning_2023a_Blue_DW.UDPReceive3_NetworkLib
                        [0U]);
  LibTerminate(&APF_Path_Planning_2023a_Blue_DW.UDPReceive3_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
    rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
  }

  LibDestroy(&APF_Path_Planning_2023a_Blue_DW.UDPReceive3_NetworkLib[0U], 0);
  DestroyUDPInterface(&APF_Path_Planning_2023a_Blue_DW.UDPReceive3_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S505>/UDP Receive3'
  // End of Terminate for SubSystem: '<S13>/Use Hardware to Obtain States'

  // Terminate for IfAction SubSystem: '<S14>/Subsystem'
  // Terminate for MATLABSystem: '<S546>/WhoAmI'
  if (!APF_Path_Planning_2023a_Blue_DW.obj_dk.matlabCodegenIsDeleted) {
    APF_Path_Planning_2023a_Blue_DW.obj_dk.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S546>/WhoAmI'
  // End of Terminate for SubSystem: '<S14>/Subsystem'

  // Terminate for IfAction SubSystem: '<S15>/Change RED Behavior'
  // Terminate for MATLABSystem: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
  if (!APF_Path_Planning_2023a_Blue_DW.obj.matlabCodegenIsDeleted) {
    APF_Path_Planning_2023a_Blue_DW.obj.matlabCodegenIsDeleted = true;
    if ((APF_Path_Planning_2023a_Blue_DW.obj.isInitialized == 1) &&
        APF_Path_Planning_2023a_Blue_DW.obj.isSetupComplete) {
      terminate_dynamixel();
    }
  }

  // End of Terminate for MATLABSystem: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
  // End of Terminate for SubSystem: '<S15>/Change RED Behavior'

  // Terminate for IfAction SubSystem: '<S16>/Subsystem'
  // Terminate for S-Function (sdspToNetwork): '<S548>/UDP Send'
  sErr = GetErrorBuffer(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_m[0U]);
  LibTerminate(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_m[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
    rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
  }

  LibDestroy(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_m[0U], 1);
  DestroyUDPInterface(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib_m[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S548>/UDP Send'
  // End of Terminate for SubSystem: '<S16>/Subsystem'

  // Terminate for S-Function (sdspToNetwork): '<S19>/UDP Send'
  sErr = GetErrorBuffer(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib[0U]);
  LibTerminate(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(APF_Path_Planning_2023a_Blue_M, sErr);
    rtmSetStopRequested(APF_Path_Planning_2023a_Blue_M, 1);
  }

  LibDestroy(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib[0U], 1);
  DestroyUDPInterface(&APF_Path_Planning_2023a_Blue_DW.UDPSend_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S19>/UDP Send'
}

//
// File trailer for generated code.
//
// [EOF]
//
