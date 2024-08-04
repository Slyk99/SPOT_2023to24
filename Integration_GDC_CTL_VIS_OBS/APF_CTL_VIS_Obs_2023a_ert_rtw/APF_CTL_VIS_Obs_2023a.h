//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: APF_CTL_VIS_Obs_2023a.h
//
// Code generated for Simulink model 'APF_CTL_VIS_Obs_2023a'.
//
// Model version                  : 1.1251
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Fri Apr  5 18:31:40 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_APF_CTL_VIS_Obs_2023a_h_
#define RTW_HEADER_APF_CTL_VIS_Obs_2023a_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "DAHostLib_Network.h"
#include "custom_data_logger.h"
#include "gpio_control.h"
#include "dynamixel_functions.h"
#include "dynamixel_sdk.h"
#include "resource_headers.h"
#include "APF_CTL_VIS_Obs_2023a_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>

extern "C"
{

#include "rtGetNaN.h"

}

extern "C"
{

#include "rtGetInf.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
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

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

// Block states (default storage) for system '<S1>/Change BLACK Behavior'
struct DW_ChangeBLACKBehavior_APF_CT_T {
  real_T UDPSend_NetworkLib[137];      // '<S20>/UDP Send'
};

// Block states (default storage) for system '<Root>/Phase #0: Synchronization'
struct DW_Phase0Synchronization_APF__T {
  int8_T ThisIFblockdetermineswhetherorn;
     // '<S6>/This IF block determines whether or not to run the BLUE sim//exp'
  int8_T ThisIFblockdetermineswhethero_p;
    // '<S6>/This IF block determines whether or not to run the BLACK sim//exp'
  int8_T ThisIFblockdetermineswhethero_e;
     // '<S6>/This IF block determines whether or not to run the RED sim//exp '
};

// Block signals for system '<S66>/Simulated Position Controller'
struct B_SimulatedPositionController_T {
  real_T In1;                          // '<S86>/In1'
  real_T In1_g;                        // '<S84>/In1'
  real_T In1_g2;                       // '<S82>/In1'
};

// Block states (default storage) for system '<S66>/Simulated Position Controller' 
struct DW_SimulatedPositionControlle_T {
  real_T Delay1_DSTATE;                // '<S83>/Delay1'
  real_T Delay1_DSTATE_e;              // '<S81>/Delay1'
  real_T Delay1_DSTATE_l;              // '<S85>/Delay1'
  boolean_T icLoad;                    // '<S83>/Delay1'
  boolean_T icLoad_j;                  // '<S81>/Delay1'
  boolean_T icLoad_m;                  // '<S85>/Delay1'
};

// Block signals for system '<S35>/RED+ARM'
struct B_REDARM_APF_CTL_VIS_Obs_2023_T {
  B_SimulatedPositionController_T SimulatedPositionController;// '<S66>/Simulated Position Controller' 
};

// Block states (default storage) for system '<S35>/RED+ARM'
struct DW_REDARM_APF_CTL_VIS_Obs_202_T {
  DW_SimulatedPositionControlle_T SimulatedPositionController;// '<S66>/Simulated Position Controller' 
};

// Block signals for system '<S87>/Sub-Phase #1'
struct B_SubPhase1_APF_CTL_VIS_Obs_2_T {
  real_T rtb_Ox_fz_m[2];
  real_T rtb_Ox_a5_c[2];
  real_T Subtract;                     // '<S90>/Subtract'
  real_T Delay1;                       // '<S104>/Delay1'
  real_T Subtract1;                    // '<S90>/Subtract1'
  real_T Delay1_l;                     // '<S106>/Delay1'
  real_T Delay1_lb;                    // '<S102>/Delay1'
  real_T e_out;                        // '<S98>/MATLAB Function4'
  real_T In1;                          // '<S107>/In1'
  real_T In1_g;                        // '<S105>/In1'
  real_T In1_g2;                       // '<S103>/In1'
};

// Block states (default storage) for system '<S87>/Sub-Phase #1'
struct DW_SubPhase1_APF_CTL_VIS_Obs__T {
  real_T Delay1_DSTATE;                // '<S104>/Delay1'
  real_T Delay1_DSTATE_n;              // '<S106>/Delay1'
  real_T Delay1_DSTATE_j;              // '<S102>/Delay1'
  int8_T ifwewentthroughastep_ActiveSubs;// '<S104>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_g;// '<S106>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_o;// '<S102>/if we went through a "step"' 
  boolean_T icLoad;                    // '<S104>/Delay1'
  boolean_T icLoad_p;                  // '<S106>/Delay1'
  boolean_T icLoad_c;                  // '<S102>/Delay1'
};

// Block signals for system '<S88>/Sub-Phase #1'
struct B_SubPhase1_APF_CTL_VIS_Obs_n_T {
  real_T rtb_Ox_eh_m[2];
  real_T rtb_Ox_kz_c[2];
  real_T rtb_Oy_p_k[2];
  real_T Subtract;                     // '<S161>/Subtract'
  real_T Delay1;                       // '<S178>/Delay1'
  real_T Subtract1;                    // '<S161>/Subtract1'
  real_T Delay1_l;                     // '<S180>/Delay1'
  real_T Delay1_k;                     // '<S176>/Delay1'
  real_T e_out;                        // '<S169>/MATLAB Function4'
  real_T In1;                          // '<S181>/In1'
  real_T In1_g;                        // '<S179>/In1'
  real_T In1_g2;                       // '<S177>/In1'
};

// Block states (default storage) for system '<S88>/Sub-Phase #1'
struct DW_SubPhase1_APF_CTL_VIS_Ob_o_T {
  real_T Delay1_DSTATE;                // '<S178>/Delay1'
  real_T Delay1_DSTATE_o;              // '<S180>/Delay1'
  real_T Delay1_DSTATE_i;              // '<S176>/Delay1'
  int8_T ifwewentthroughastep_ActiveSubs;// '<S178>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_l;// '<S180>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_i;// '<S176>/if we went through a "step"' 
  boolean_T icLoad;                    // '<S178>/Delay1'
  boolean_T icLoad_j;                  // '<S180>/Delay1'
  boolean_T icLoad_h;                  // '<S176>/Delay1'
};

// Block signals for system '<S89>/Sub-Phase #1'
struct B_SubPhase1_APF_CTL_VIS_Obs_i_T {
  real_T rtb_Ox_o_m[2];
  real_T rtb_Ox_gy_c[2];
  real_T rtb_Oy_j5_k[2];
  real_T Delay1;                       // '<S257>/Delay1'
  real_T Subtract;                     // '<S244>/Subtract'
  real_T Delay1_c;                     // '<S259>/Delay1'
  real_T Subtract2;                    // '<S244>/Subtract2'
  real_T Delay1_m;                     // '<S261>/Delay1'
  real_T e_out;                        // '<S251>/MATLAB Function4'
  real_T In1;                          // '<S262>/In1'
  real_T In1_g;                        // '<S260>/In1'
  real_T In1_g2;                       // '<S258>/In1'
  B_REDARM_APF_CTL_VIS_Obs_2023_T REDARM;// '<S244>/RED+ARM'
};

// Block states (default storage) for system '<S89>/Sub-Phase #1'
struct DW_SubPhase1_APF_CTL_VIS_Ob_m_T {
  real_T Delay1_DSTATE;                // '<S257>/Delay1'
  real_T Delay1_DSTATE_e;              // '<S259>/Delay1'
  real_T Delay1_DSTATE_o;              // '<S261>/Delay1'
  int8_T ifwewentthroughastep_ActiveSubs;// '<S257>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_a;// '<S259>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_i;// '<S261>/if we went through a "step"' 
  boolean_T icLoad;                    // '<S257>/Delay1'
  boolean_T icLoad_g;                  // '<S259>/Delay1'
  boolean_T icLoad_h;                  // '<S261>/Delay1'
  DW_REDARM_APF_CTL_VIS_Obs_202_T REDARM;// '<S244>/RED+ARM'
};

// Continuous states for system '<S349>/Target Tracker'
struct X_TargetTracker_APF_CTL_VIS_O_T {
  real_T PseudoDerivative_CSTATE;      // '<S376>/Pseudo Derivative'
  real_T PseudoDerivative1_CSTATE;     // '<S376>/Pseudo Derivative1'
  real_T PseudoDerivative2_CSTATE;     // '<S376>/Pseudo Derivative2'
};

// State derivatives for system '<S349>/Target Tracker'
struct XDot_TargetTracker_APF_CTL_VI_T {
  real_T PseudoDerivative_CSTATE;      // '<S376>/Pseudo Derivative'
  real_T PseudoDerivative1_CSTATE;     // '<S376>/Pseudo Derivative1'
  real_T PseudoDerivative2_CSTATE;     // '<S376>/Pseudo Derivative2'
};

// State Disabled for system '<S349>/Target Tracker'
struct XDis_TargetTracker_APF_CTL_VI_T {
  boolean_T PseudoDerivative_CSTATE;   // '<S376>/Pseudo Derivative'
  boolean_T PseudoDerivative1_CSTATE;  // '<S376>/Pseudo Derivative1'
  boolean_T PseudoDerivative2_CSTATE;  // '<S376>/Pseudo Derivative2'
};

// Block signals for system '<Root>/Phase #4: Return Home'
struct B_Phase4ReturnHome_APF_CTL_VI_T {
  real_T rtb_Ox_d_m[2];
  real_T rtb_Ox_kr_c[2];
  real_T rtb_Oy_a_k[2];
  real_T Delay1;                       // '<S456>/Delay1'
  real_T Subtract;                     // '<S424>/Subtract'
  real_T Delay1_b;                     // '<S458>/Delay1'
  real_T Subtract1;                    // '<S424>/Subtract1'
  real_T Delay1_d;                     // '<S460>/Delay1'
  real_T In1;                          // '<S475>/In1'
  real_T In1_g;                        // '<S473>/In1'
  real_T In1_g2;                       // '<S471>/In1'
  real_T e_out;                        // '<S454>/MATLAB Function4'
  real_T In1_g20;                      // '<S461>/In1'
  real_T In1_g20a;                     // '<S459>/In1'
  real_T In1_g20as;                    // '<S457>/In1'
  real_T Subtract_c;                   // '<S422>/Subtract'
  real_T Delay1_j;                     // '<S431>/Delay1'
  real_T Subtract1_k;                  // '<S422>/Subtract1'
  real_T Delay1_i;                     // '<S433>/Delay1'
  real_T Delay1_c;                     // '<S429>/Delay1'
  real_T e_out_h;                      // '<S428>/MATLAB Function4'
  real_T In1_g20asd;                   // '<S434>/In1'
  real_T In1_g20asdt;                  // '<S432>/In1'
  real_T In1_g20asdtg;                 // '<S430>/In1'
  real_T Subtract_k;                   // '<S423>/Subtract'
  real_T Delay1_k;                     // '<S444>/Delay1'
  real_T Subtract1_j;                  // '<S423>/Subtract1'
  real_T Delay1_g;                     // '<S446>/Delay1'
  real_T Delay1_p;                     // '<S442>/Delay1'
  real_T e_out_h3;                     // '<S441>/MATLAB Function4'
  real_T In1_g20asdtgi;                // '<S447>/In1'
  real_T In1_g20asdtgi0;               // '<S445>/In1'
  real_T In1_g20asdtgi0c;              // '<S443>/In1'
  real_T Sum6_hx;                      // '<S431>/Sum6'
};

// Block states (default storage) for system '<Root>/Phase #4: Return Home'
struct DW_Phase4ReturnHome_APF_CTL_V_T {
  real_T Delay1_DSTATE;                // '<S456>/Delay1'
  real_T Delay1_DSTATE_d;              // '<S458>/Delay1'
  real_T Delay1_DSTATE_o;              // '<S460>/Delay1'
  real_T Delay1_DSTATE_j;              // '<S472>/Delay1'
  real_T Delay1_DSTATE_l;              // '<S470>/Delay1'
  real_T Delay1_DSTATE_h;              // '<S474>/Delay1'
  real_T Delay1_DSTATE_a;              // '<S431>/Delay1'
  real_T Delay1_DSTATE_jh;             // '<S433>/Delay1'
  real_T Delay1_DSTATE_h5;             // '<S429>/Delay1'
  real_T Delay1_DSTATE_f;              // '<S444>/Delay1'
  real_T Delay1_DSTATE_i;              // '<S446>/Delay1'
  real_T Delay1_DSTATE_ol;             // '<S442>/Delay1'
  int8_T ThisIFblockdetermineswhetherorn;
    // '<S10>/This IF block determines whether or not to run the BLUE sim//exp'
  int8_T ThisIFblockdetermineswhethero_n;
  // '<S10>/This IF block determines whether or not to run the BLACK sim//exp'
  int8_T ThisIFblockdetermineswhethero_a;
    // '<S10>/This IF block determines whether or not to run the RED sim//exp '
  int8_T ifwewentthroughastep_ActiveSubs;// '<S456>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_c;// '<S458>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_m;// '<S460>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_a;// '<S431>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_l;// '<S433>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_d;// '<S429>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_i;// '<S444>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_p;// '<S446>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_k;// '<S442>/if we went through a "step"' 
  boolean_T icLoad;                    // '<S456>/Delay1'
  boolean_T icLoad_g;                  // '<S458>/Delay1'
  boolean_T icLoad_d;                  // '<S460>/Delay1'
  boolean_T icLoad_e;                  // '<S472>/Delay1'
  boolean_T icLoad_gp;                 // '<S470>/Delay1'
  boolean_T icLoad_k;                  // '<S474>/Delay1'
  boolean_T icLoad_f;                  // '<S431>/Delay1'
  boolean_T icLoad_j;                  // '<S433>/Delay1'
  boolean_T icLoad_c;                  // '<S429>/Delay1'
  boolean_T icLoad_ce;                 // '<S444>/Delay1'
  boolean_T icLoad_p;                  // '<S446>/Delay1'
  boolean_T icLoad_jr;                 // '<S442>/Delay1'
};

// Block signals for system '<S639>/MATLAB Function10'
struct B_MATLABFunction10_APF_CTL_VI_T {
  real_T PWMs[8];
  real_T positives_only[8];
};

// Block signals (default storage)
struct B_APF_CTL_VIS_Obs_2023a_T {
  real_T w_m[169];
  real_T w_c[169];
  real_T X_Cal[78];
  real_T X_Cal_k1[78];
  real_T e_x[78];
  real_T e_x_m[78];
  real_T b_u1[75];
  creal_T V[36];
  creal_T D[36];
  real_T y[64];
  real_T y_c[64];
  real_T y_k[64];
  real_T y_cx[64];
  real_T Z_Cal[39];
  real_T f_x[39];
  real_T Z_Cal_b[39];
  real_T IC[36];                       // '<S355>/IC'
  real_T increment[36];
  real_T b_B[36];
  real_T b_D[36];
  real_T V_p[36];
  real_T b_A[36];
  real_T Q[36];
  real_T b_A_c[36];
  real_T vr[36];
  real_T b_A_f[36];
  real_T vr_g[36];
  real_T b_A_g[36];
  real_T Q_m[36];
  real_T b_A_n[36];
  real_T Vf[36];
  real_T b_A_p[36];
  real_T b_A_l[36];
  real_T b_A_j[36];
  real_T b_A_d[36];
  real_T Product2_m[24];               // '<S681>/Product2'
  real_T Product1_e[24];               // '<S648>/Product1'
  real_T Merge1_d[24];                 // '<S663>/Merge1'
  real_T Product1_it[24];              // '<S660>/Product1'
  real_T transpose[24];                // '<S681>/transpose'
  real_T b[24];
  real_T b_g[24];
  real_T Product2_n[24];               // '<S648>/Product2'
  real_T Product2[24];                 // '<S660>/Product2'
  real_T TmpSignalConversionAtUDPSendI_o[19];
  real_T B[18];
  real_T X_Cal_l[18];
  real_T work[18];
  real_T work_d[18];
  real_T v_d[13];
  real_T b_v[13];
  creal_T b_x[6];
  creal_T b_dt[6];
  creal_T b_dt_l[6];
  real_T TmpSignalConversionAtUDPSendInp[10];
  real_T UDPReceive1_o1[10];           // '<S534>/UDP Receive1'
  real_T work_o[10];
  real_T work_b[10];
  real_T rtb_Black_Measurments_table_r_n[9];
  real_T rtb_Product2_m_b[9];
  real_T Product2_b[9];                // '<S663>/Product2'
  real_T x[9];
  real_T x_l[9];
  real_T x_h[9];
  real_T ThrustPer_Final[8];           // '<S663>/MATLAB Function2'
  real_T ThrustPer_Final_e[8];         // '<S651>/MATLAB Function2'
  real_T ThrustPer_Final_d[8];         // '<S639>/MATLAB Function1'
  real_T rtb_Product_bn[8];
  real_T s[6];
  real_T state_red[6];
  real_T dv[6];
  real_T a__4[6];
  real_T work_da[6];
  real_T wr[6];
  real_T wi[6];
  real_T scale[6];
  real_T wr_e[6];
  real_T wi_b[6];
  real_T scale_j[6];
  real_T a__4_f[6];
  real_T work_a[6];
  real_T b_s[6];
  real_T e[6];
  real_T work_j[6];
  real_T wr_j[6];
  real_T wi_o[6];
  real_T wr_n[6];
  real_T wi_i[6];
  real_T b_s_o[6];
  real_T e_n[6];
  real_T work_m[6];
  real_T b_s_c[6];
  real_T e_m[6];
  real_T work_m3[6];
  real_T work_ja[6];
  real_T work_h[6];
  real_T work_c[6];
  real_T work_ct[6];
  real_T work_p[6];
  real_T d_x_data[5];
  real_T tau[5];
  real_T e_p[5];
  real_T tau_a[5];
  real_T tau_e[5];
  real_T tau_ax[5];
  real_T e_a[5];
  real_T e_i[5];
  real_T tau_l[5];
  real_T e_o[5];
  real_T tau_o[5];
  real_T rtb_C_Ib_ip[4];
  real_T x_f[4];
  real_T cr[4];
  real_T ci[4];
  real_T x_i[4];
  real_T cr_f[4];
  real_T ci_g[4];
  real_T Delay[3];                     // '<S354>/Delay'
  real_T Delay1[6];                    // '<S355>/Delay1'
  real_T MultiportSwitch[3];           // '<S385>/Multiport Switch'
  real_T Sum_n[3];                     // '<S392>/Sum'
  real_T P_K_g[36];                    // '<S355>/MATLAB Function2'
  real_T r_ct[3];
  real_T r_co[3];
  real_T r_cb[3];
  real_T x_ddot_d[3];                  // '<S581>/MATLAB Function'
  real_T MultiportSwitch_f[3];         // '<S349>/Multiport Switch'
  real_T y_p[3];                       // '<S354>/MATLAB Function'
  real_T Blue_Measurments_table_ref[3];// '<S348>/Ryan's Transform'
  real_T Sum_b[3];                     // '<S622>/Sum'
  real_T Z_k[3];
  real_T dv1[3];
  real_T v_c[3];
  real_T v_o[3];
  real_T v_l[3];
  real_T v_m[3];
  real_T rtb_Oy_kp_m[2];
  real_T rtb_Ox_pr_c[2];
  real_T rtb_Ox_pc_f[2];
  creal_T eig_min;
  real_T Delay3;                       // '<S355>/Delay3'
  real_T Delay2;                       // '<S355>/Delay2'
  real_T Delay_a;                      // '<S379>/Delay'
  real_T Delay_k[2];                   // '<S359>/Delay'
  real_T Delay1_f[6];                  // '<S360>/Delay1'
  real_T IC_e[36];                     // '<S360>/IC'
  real_T Delay3_f;                     // '<S360>/Delay3'
  real_T Delay2_b;                     // '<S360>/Delay2'
  real_T Sum;                          // '<S349>/Sum'
  real_T Sum1;                         // '<S349>/Sum1'
  real_T Step;                         // '<S360>/Step'
  real_T k;                            // '<S379>/Switch logic'
  real_T OutportBufferForDesiredStates[3];
  real_T OutportBufferForDesiredStates_c[3];
  real_T theta_desired;                // '<S408>/Looking Angle'
  real_T Delay_l[3];                   // '<S386>/Delay'
  real_T Delay1_i[3];                  // '<S386>/Delay1'
  real_T Delay3_m[3];                  // '<S387>/Delay3'
  real_T Delay1_m[3];                  // '<S388>/Delay1'
  real_T Delay3_i[3];                  // '<S388>/Delay3'
  real_T Delay1_o[3];                  // '<S389>/Delay1'
  real_T Delay3_j[3];                  // '<S389>/Delay3'
  real_T Delay_n[3];                   // '<S391>/Delay'
  real_T Sum3[3];                      // '<S391>/Sum3'
  real_T Delay_b[3];                   // '<S392>/Delay'
  real_T Delay3_f3[3];                 // '<S393>/Delay3'
  real_T Switch;                       // '<S378>/Switch'
  real_T Eg[3];                        // '<S393>/MATLAB Function1'
  real_T m[3];                         // '<S389>/MATLAB Function1'
  real_T v[3];                         // '<S389>/MATLAB Function1'
  real_T m_b[3];                       // '<S388>/MATLAB Function1'
  real_T u_t[3];                       // '<S388>/MATLAB Function1'
  real_T Gt[3];                        // '<S387>/MATLAB Function1'
  real_T Eg_n[3];                      // '<S386>/MATLAB Function1'
  real_T Etheta[3];                    // '<S386>/MATLAB Function1'
  real_T u[3];                         // '<S374>/MATLAB Function'
  real_T u_l[3];                       // '<S376>/MATLAB Function'
  real_T DiscreteTimeIntegrator4;      // '<S370>/Discrete-Time Integrator4'
  real_T DiscreteTimeIntegrator5;      // '<S370>/Discrete-Time Integrator5'
  real_T DiscreteTimeIntegrator2;      // '<S370>/Discrete-Time Integrator2'
  real_T DiscreteTimeIntegrator3;      // '<S370>/Discrete-Time Integrator3'
  real_T DiscreteTimeIntegrator1;      // '<S370>/Discrete-Time Integrator1'
  real_T DiscreteTimeIntegrator;       // '<S370>/Discrete-Time Integrator'
  real_T u_x;                          // '<S370>/u_x'
  real_T u_y;                          // '<S370>/u_y'
  real_T Add2;                         // '<S370>/Add2'
  real_T k1_dot;                       // '<S370>/Torque Gain Derivatives'
  real_T k2_dot;                       // '<S370>/Torque Gain Derivatives'
  real_T k2_dot_p;                     // '<S370>/Fy Gain Derivatives'
  real_T k1_dot_f;                     // '<S370>/Fy Gain Derivatives'
  real_T k2_dot_l;                     // '<S370>/Fx Gain Derivatives'
  real_T k1_dot_a;                     // '<S370>/Fx Gain Derivatives'
  real_T e_out;                        // '<S363>/MATLAB Function4'
  real_T States[6];                    // '<S360>/MATLAB Function2'
  real_T P_K[36];                      // '<S360>/MATLAB Function2'
  real_T Reject_Sum;                   // '<S360>/MATLAB Function2'
  real_T States_a[6];                  // '<S355>/MATLAB Function2'
  real_T Reject_Sum_b;                 // '<S355>/MATLAB Function2'
  real_T Reject;                       // '<S355>/MATLAB Function2'
  real_T Delay1_e;                     // '<S323>/Delay1'
  real_T Subtract;                     // '<S246>/Subtract'
  real_T Delay1_l;                     // '<S325>/Delay1'
  real_T Subtract2;                    // '<S246>/Subtract2'
  real_T Delay1_a;                     // '<S327>/Delay1'
  real_T e_out_p;                      // '<S317>/MATLAB Function4'
  real_T In1;                          // '<S328>/In1'
  real_T In1_g;                        // '<S326>/In1'
  real_T In1_g2;                       // '<S324>/In1'
  real_T StartPos;                     // '<S232>/Start Pos'
  real_T Subtract_p;                   // '<S164>/Subtract'
  real_T Delay1_n;                     // '<S237>/Delay1'
  real_T StartPos_l;                   // '<S233>/Start Pos'
  real_T Subtract1;                    // '<S164>/Subtract1'
  real_T Delay1_d;                     // '<S239>/Delay1'
  real_T StartPos_e;                   // '<S234>/Start Pos'
  real_T Delay1_fa;                    // '<S235>/Delay1'
  real_T e_out_pv;                     // '<S231>/MATLAB Function4'
  real_T In1_g20;                      // '<S240>/In1'
  real_T In1_g20a;                     // '<S238>/In1'
  real_T In1_g20as;                    // '<S236>/In1'
  real_T StartPos_c;                   // '<S149>/Start Pos'
  real_T Subtract_k;                   // '<S93>/Subtract'
  real_T Delay1_p;                     // '<S154>/Delay1'
  real_T StartPos_m;                   // '<S150>/Start Pos'
  real_T Subtract1_l;                  // '<S93>/Subtract1'
  real_T Delay1_c;                     // '<S156>/Delay1'
  real_T StartPos_j;                   // '<S151>/Start Pos'
  real_T Delay1_h;                     // '<S152>/Delay1'
  real_T e_out_b;                      // '<S148>/MATLAB Function4'
  real_T In1_g20asd;                   // '<S157>/In1'
  real_T In1_g20asdt;                  // '<S155>/In1'
  real_T In1_g20asdtg;                 // '<S153>/In1'
  real_T Delay1_lo;                    // '<S67>/Delay1'
  real_T Subtract_j;                   // '<S35>/Subtract'
  real_T Delay1_nm;                    // '<S69>/Delay1'
  real_T Subtract1_n;                  // '<S35>/Subtract1'
  real_T Delay1_ag;                    // '<S71>/Delay1'
  real_T e_out_k;                      // '<S65>/MATLAB Function4'
  real_T Oy[2];                        // '<S65>/MATLAB Function2'
  real_T Ox[2];                        // '<S65>/MATLAB Function2'
  real_T In1_g20asdtgi;                // '<S72>/In1'
  real_T In1_g20asdtgi0;               // '<S70>/In1'
  real_T In1_g20asdtgi0c;              // '<S68>/In1'
  real_T Subtract_d;                   // '<S33>/Subtract'
  real_T Delay1_mm;                    // '<S42>/Delay1'
  real_T Subtract1_g;                  // '<S33>/Subtract1'
  real_T Delay1_hm;                    // '<S44>/Delay1'
  real_T Delay1_aj;                    // '<S40>/Delay1'
  real_T e_out_m;                      // '<S39>/MATLAB Function4'
  real_T In1_g20asdtgi0cd;             // '<S45>/In1'
  real_T In1_g20asdtgi0cdy;            // '<S43>/In1'
  real_T In1_g20asdtgi0cdyi;           // '<S41>/In1'
  real_T Subtract_n;                   // '<S34>/Subtract'
  real_T Delay1_p4;                    // '<S55>/Delay1'
  real_T Subtract1_ld;                 // '<S34>/Subtract1'
  real_T Delay1_j;                     // '<S57>/Delay1'
  real_T Delay1_ej;                    // '<S53>/Delay1'
  real_T e_out_md;                     // '<S52>/MATLAB Function4'
  real_T In1_g20asdtgi0cdyix;          // '<S58>/In1'
  real_T In1_e;                        // '<S56>/In1'
  real_T In1_o;                        // '<S54>/In1'
  real_T ConvertREDXfrommmtom;        // '<S534>/Convert REDX from [mm] to [m]'
  real_T ConvertBLUXfrommmtom;        // '<S534>/Convert BLUX from [mm] to [m]'
  real_T Delay1_hy;                    // '<S544>/Delay1'
  real_T dividebydeltaT;               // '<S544>/divide by delta T'
  real_T Delay1_g;                     // '<S541>/Delay1'
  real_T ConvertBLAXfrommmtom;        // '<S534>/Convert BLAX from [mm] to [m]'
  real_T Delay1_ha;                    // '<S549>/Delay1'
  real_T dividebydeltaT_f;             // '<S549>/divide by delta T'
  real_T Delay1_gd;                    // '<S538>/Delay1'
  real_T ConvertBLAYfrommmtom;        // '<S534>/Convert BLAY from [mm] to [m]'
  real_T Delay1_pp;                    // '<S550>/Delay1'
  real_T dividebydeltaT_l;             // '<S550>/divide by delta T'
  real_T Delay1_jr;                    // '<S539>/Delay1'
  real_T Unwrap1;                      // '<S534>/Unwrap1'
  real_T Delay1_ma;                    // '<S551>/Delay1'
  real_T dividebydeltaT_e;             // '<S551>/divide by delta T'
  real_T Delay1_ez;                    // '<S540>/Delay1'
  real_T ConvertBLUYfrommmtom;        // '<S534>/Convert BLUY from [mm] to [m]'
  real_T Delay1_pz;                    // '<S545>/Delay1'
  real_T dividebydeltaT_c;             // '<S545>/divide by delta T'
  real_T Delay1_pt;                    // '<S542>/Delay1'
  real_T Unwrap2;                      // '<S534>/Unwrap2'
  real_T Delay1_ph;                    // '<S546>/Delay1'
  real_T dividebydeltaT_cy;            // '<S546>/divide by delta T'
  real_T Delay1_k;                     // '<S543>/Delay1'
  real_T Delay1_f5;                    // '<S537>/Delay1'
  real_T dividebydeltaT_n;             // '<S537>/divide by delta T'
  real_T Delay1_cz;                    // '<S552>/Delay1'
  real_T ConvertREDYfrommmtom;        // '<S534>/Convert REDY from [mm] to [m]'
  real_T Delay1_lh;                    // '<S547>/Delay1'
  real_T dividebydeltaT_n1;            // '<S547>/divide by delta T'
  real_T Delay1_jo;                    // '<S553>/Delay1'
  real_T Unwrap;                       // '<S534>/Unwrap'
  real_T Delay1_gm;                    // '<S548>/Delay1'
  real_T dividebydeltaT_m;             // '<S548>/divide by delta T'
  real_T Delay1_dd;                    // '<S554>/Delay1'
  real_T In1_e0;                       // '<S574>/In1'
  real_T In1_l;                        // '<S573>/In1'
  real_T In1_f;                        // '<S572>/In1'
  real_T In1_eg;                       // '<S571>/In1'
  real_T In1_b;                        // '<S570>/In1'
  real_T In1_m;                        // '<S569>/In1'
  real_T In1_en;                       // '<S568>/In1'
  real_T In1_em;                       // '<S567>/In1'
  real_T In1_gd;                       // '<S566>/In1'
  real_T In1_fy;                       // '<S565>/In1'
  real_T In1_lk;                       // '<S564>/In1'
  real_T In1_a;                        // '<S560>/In1'
  real_T In1_c;                        // '<S559>/In1'
  real_T In1_p;                        // '<S558>/In1'
  real_T In1_gt;                       // '<S557>/In1'
  real_T Subtract_l;                   // '<S556>/Subtract'
  real_T Memory;                       // '<S555>/Memory'
  real_T In1_aw;                       // '<S635>/In1'
  real_T In1_g0;                       // '<S634>/In1'
  real_T In1_fv;                       // '<S633>/In1'
  real_T In1_h;                        // '<S632>/In1'
  real_T In1_ff;                       // '<S631>/In1'
  real_T In1_n;                        // '<S630>/In1'
  real_T In1_hq;                       // '<S620>/In1'
  real_T In1_pj;                       // '<S619>/In1'
  real_T In1_a4;                       // '<S618>/In1'
  real_T In1_ir;                       // '<S608>/In1'
  real_T In1_cz;                       // '<S604>/In1'
  real_T In1_ex;                       // '<S603>/In1'
  real_T In1_j;                        // '<S594>/In1'
  real_T In1_ib;                       // '<S593>/In1'
  real_T In1_pg;                       // '<S592>/In1'
  real_T In1_d;                        // '<S591>/In1'
  real_T In1_c5;                       // '<S590>/In1'
  real_T In1_pk;                       // '<S589>/In1'
  real_T link2_com_y;
  real_T t7;
  real_T t8;
  real_T t13;
  real_T t16;
  real_T t17;
  real_T t23;
  real_T t24;
  real_T t25;
  real_T t28;
  real_T t30;
  real_T t33;
  real_T t36;
  real_T t37;
  real_T t45;
  real_T t50;
  real_T t51;
  real_T t56;
  real_T t57;
  real_T t61;
  real_T t63;
  real_T t64;
  real_T t65;
  real_T t67;
  real_T t68;
  real_T t71;
  real_T t72;
  real_T t74;
  real_T t75;
  real_T t76;
  real_T t99;
  real_T t116;
  real_T t21;
  real_T t54;
  real_T t79;
  real_T t80;
  real_T t81;
  real_T t82;
  real_T t83;
  real_T t91;
  real_T t92;
  real_T t93;
  real_T t94;
  real_T t95;
  real_T t96;
  real_T t97;
  real_T t100;
  real_T t103;
  real_T t104;
  real_T sampleTime;
  real_T sampleTime_p;
  real_T sampleTime_e;
  real_T d;
  real_T Sum6_gv;                      // '<S601>/Sum6'
  real_T Sum6_b3;                      // '<S624>/Sum6'
  real_T Derivative2;                  // '<S370>/Derivative2'
  real_T Derivative3;                  // '<S370>/Derivative3'
  real_T rtb_y_f_o;
  real_T RED_Tz_RW;
  real_T rtb_path_p_idx_0;
  real_T Z_k_idx_2;
  real_T Z_k_idx_1;
  real_T Z_k_idx_0;
  real_T rtb_path_b_idx_1;
  real_T rtb_path_b_idx_0;
  real_T r_co_idx_1;
  real_T rtb_path_h1_idx_2;
  real_T rtb_path_h1_idx_1;
  real_T rtb_path_h1_idx_0;
  real_T rtb_x_ddot_o_idx_1;
  real_T rtb_x_ddot_o_idx_0;
  real_T rtb_x_ddot_idx_1;
  real_T rtb_x_ddot_idx_0;
  real_T rtb_Blue_Measurments_table_re_h;
  real_T t112_tmp;
  real_T t12_tmp;
  real_T t46_tmp;
  real_T t99_tmp;
  real_T t99_tmp_l;
  real_T t51_tmp;
  real_T t99_tmp_h;
  real_T t99_tmp_m;
  real_T t99_tmp_mc;
  real_T t81_tmp;
  real_T t113_tmp;
  real_T t114_tmp;
  real_T t115_tmp;
  real_T t99_tmp_h3;
  real_T t114_tmp_tmp;
  real_T t113_tmp_tmp;
  real_T t63_tmp;
  real_T rtb_x_ddot_idx_0_tmp;
  real_T DataStoreRead3_l;             // '<S351>/Data Store Read3'
  real_T anrm;
  real_T temp1;
  real_T temp2;
  real_T ai;
  real_T tau_tmp;
  real_T anrm_c;
  real_T scl;
  real_T absxk;
  real_T b_scale;
  real_T f1;
  real_T g1;
  real_T b_temp;
  real_T u1;
  real_T wi_k;
  real_T smin;
  real_T scale_p;
  real_T rec;
  real_T emax;
  real_T c_xnorm;
  real_T u0;
  real_T cmax;
  real_T temp;
  real_T ur11r;
  real_T ur22;
  real_T br1;
  real_T br2;
  real_T ui11r;
  real_T li21;
  real_T ur12s;
  real_T ui12s;
  real_T ui22;
  real_T u22abs;
  real_T bi2;
  real_T bi1;
  real_T aa;
  real_T bb;
  real_T cc;
  real_T dd;
  real_T ab;
  real_T cd;
  real_T s_p;
  real_T cd_tmp;
  real_T cd_tmp_p;
  real_T r;
  real_T t;
  real_T br;
  real_T anrm_a;
  real_T scl_j;
  real_T absxk_e;
  real_T b_scale_o;
  real_T f1_b;
  real_T g1_a;
  real_T b_temp_g;
  real_T u1_e;
  real_T smlnum;
  real_T tst;
  real_T aa_f;
  real_T s_h;
  real_T h11;
  real_T h12;
  real_T tr;
  real_T h21s;
  real_T h;
  real_T s_tmp;
  real_T temp_e;
  real_T p;
  real_T bcmax;
  real_T bcmis;
  real_T scale_c;
  real_T z;
  real_T a;
  real_T b_a;
  real_T anrm_d;
  real_T temp1_a;
  real_T temp2_p;
  real_T ai_m;
  real_T tau_tmp_o;
  real_T tst_n;
  real_T p_l;
  real_T g;
  real_T r_p;
  real_T s_pt;
  real_T c;
  real_T b_f;
  real_T b_s_i;
  real_T b_r;
  real_T sm;
  real_T df;
  real_T adf;
  real_T tb;
  real_T ab_o;
  real_T acmx;
  real_T acmn;
  real_T b_a_k;
  real_T nrm;
  real_T rt;
  real_T r_i;
  real_T smm1;
  real_T emm1;
  real_T sqds;
  real_T shift;
  real_T roe;
  real_T absa;
  real_T absb;
  real_T scale_o;
  real_T ads;
  real_T bds;
  real_T b_anrm;
  real_T absxk_m;
  real_T temp1_c;
  real_T temp2_f;
  real_T tau_tmp_h;
  real_T smlnum_m;
  real_T tst_a;
  real_T aa_k;
  real_T s_pc;
  real_T h11_b;
  real_T h12_c;
  real_T tr_n;
  real_T h21s_i;
  real_T sum;
  real_T s_tmp_m;
  real_T xnorm;
  real_T a_j;
  real_T scale_e;
  real_T absxk_mv;
  real_T t_m;
  real_T b_anrm_j;
  real_T absxk_f;
  real_T temp1_a5;
  real_T temp2_g;
  real_T tau_tmp_n;
  real_T anorm;
  real_T p_d;
  real_T rte;
  real_T sigma;
  real_T r_n;
  real_T c_c;
  real_T s_f;
  real_T b_gamma;
  real_T oldc;
  real_T cfromc;
  real_T ctoc;
  real_T cfrom1;
  real_T cto1;
  real_T mul;
  real_T nrm_p;
  real_T rt_p;
  real_T r_nj;
  real_T smm1_k;
  real_T emm1_n;
  real_T sqds_o;
  real_T shift_g;
  real_T scale_cq;
  real_T absxk_c;
  real_T t_m1;
  real_T nrm_j;
  real_T rt_k;
  real_T r_m;
  real_T smm1_p;
  real_T emm1_d;
  real_T sqds_g;
  real_T shift_c;
  real_T wi_c;
  real_T smin_i;
  real_T scale_d;
  real_T rec_g;
  real_T emax_l;
  real_T c_xnorm_f;
  real_T tst_d;
  real_T p_j;
  real_T g_i;
  real_T r_h;
  real_T s_n;
  real_T c_o;
  real_T b_c;
  real_T b_s_b;
  real_T b_r_e;
  real_T scale_dd;
  real_T f1_i;
  real_T g1_g;
  real_T scale_tmp;
  real_T alpha1;
  real_T tau_n;
  real_T xnorm_l;
  real_T a_c;
  real_T scale_n;
  real_T absxk_p;
  real_T t_d;
  real_T alpha1_o;
  real_T tau_j;
  real_T temp_c;
  real_T absx11;
  real_T absx21;
  real_T absx31;
  real_T cmax_h;
  real_T temp_d;
  real_T ur11r_c;
  real_T ur22_p;
  real_T br1_p;
  real_T br2_a;
  real_T ui11r_o;
  real_T li21_j;
  real_T c_p;
  real_T c_ob;
  real_T r_l;
  real_T g_k;
  real_T s_j;
  real_T b_scale_f;
  real_T absxk_cm;
  real_T t_f;
  real_T y_n;
  real_T y_i;
  real_T smlnum_l;
  real_T tst_i;
  real_T aa_k1;
  real_T s_fc;
  real_T h11_a;
  real_T h12_d;
  real_T tr_e;
  real_T h21s_e;
  real_T h_b;
  real_T s_tmp_a;
  real_T cfromc_i;
  real_T ctoc_f;
  real_T cfrom1_j;
  real_T cto1_o;
  real_T mul_f;
  real_T ctemp;
  real_T stemp;
  real_T temp_o;
  real_T smlnum_ln;
  real_T tst_l;
  real_T aa_g;
  real_T s_d;
  real_T h11_d;
  real_T h12_j;
  real_T tr_f;
  real_T h21s_j;
  real_T sum_h;
  real_T s_tmp_c;
  real_T anorm_n;
  real_T p_k;
  real_T rte_a;
  real_T sigma_f;
  real_T r_j;
  real_T c_k;
  real_T s_b;
  real_T b_gamma_h;
  real_T oldc_e;
  real_T sm_h;
  real_T adf_k;
  real_T alpha_pol;
  real_T varargin_1_data;
  real_T alpha_pol_tmp;
  real_T alpha_pol_tmp_j;
  real_T varargout_1;
  real_T q;
  real_T ctemp_o;
  real_T stemp_c;
  real_T temp_h;
  real_T cfromc_iy;
  real_T ctoc_p;
  real_T cfrom1_f;
  real_T cto1_e;
  real_T mul_n;
  real_T ssq;
  real_T b_c_h;
  real_T c_x;
  real_T b_y;
  real_T x_re;
  real_T x_im;
  real_T scale_h;
  real_T absxk_fn;
  real_T t_i;
  real_T temp_tmp;
  real_T temp_tmp_f;
  real_T sr;
  real_T si;
  real_T scale_cy;
  real_T absxk_n;
  real_T t_h;
  real_T xc;
  real_T d_k;
  real_T ab_h;
  real_T acmx_b;
  real_T acmn_o;
  real_T scale_tmp_n;
  real_T u1_m;
  real_T c_ku;
  real_T r_jk;
  real_T g_h;
  real_T s_f2;
  real_T b_scale_d;
  real_T temp_l;
  real_T d1;
  real_T d2;
  real_T anorm_k;
  real_T absx;
  real_T absx_i;
  int32_T d_x_size[2];
  boolean_T c_x_h[6];
  real32_T ByteUnpack_o1;              // '<S2>/Byte Unpack'
  real32_T ByteUnpack_o2;              // '<S2>/Byte Unpack'
  real32_T ByteUnpack_o3;              // '<S2>/Byte Unpack'
  real32_T ByteUnpack_o4;              // '<S2>/Byte Unpack'
  real32_T ByteUnpack_o5;              // '<S2>/Byte Unpack'
  int32_T Delay_g;                     // '<S534>/Delay'
  int32_T Delay1_cj;                   // '<S534>/Delay1'
  int32_T Delay2_c;                    // '<S534>/Delay2'
  int32_T UDPReceive_o1;               // '<S534>/UDP Receive'
  int32_T UDPReceive2_o1;              // '<S534>/UDP Receive2'
  int32_T UDPReceive3_o1;              // '<S534>/UDP Receive3'
  uint8_T UDPReceive1_o1_k[20];        // '<S2>/UDP Receive1'
  int32_T r_mg;
  int32_T vcol;
  int32_T b_j;
  int32_T d_g;
  int32_T d_j;
  int32_T k_l;
  int32_T xoffset;
  int32_T b_xoffset;
  int32_T yElIdx;
  int32_T uElOffset1;
  int32_T ntIdx1;
  int32_T ntIdx0;
  int32_T StartClock;                  // '<S534>/MATLAB Function'
  int32_T i;
  int32_T i_m;
  int32_T loop_ub;
  int32_T increment_tmp;
  int32_T P_K_tmp;
  int32_T b_i;
  int32_T j;
  int32_T sgn;
  int32_T kk;
  int32_T b_jj;
  int32_T ii;
  int32_T tau_tmp_tmp;
  int32_T ar_tmp;
  int32_T ai_tmp;
  int32_T b_k;
  int32_T ihi;
  int32_T info;
  int32_T c_k_n;
  int32_T d_i;
  int32_T i_k;
  int32_T b_temp_tmp;
  int32_T temp_tmp_tmp;
  int32_T temp_tmp_tmp_g;
  int32_T j_d;
  int32_T ip;
  int32_T b_j_m;
  int32_T b_ix;
  int32_T d_f;
  int32_T c_ix;
  int32_T T_tmp;
  int32_T T_tmp_g;
  int32_T icmax;
  int32_T lr21_tmp;
  int32_T lr21_tmp_tmp;
  int32_T b_k_j;
  int32_T ihi_c;
  int32_T info_e;
  int32_T c_k_m;
  int32_T d_i_o;
  int32_T i_k_a;
  int32_T b_temp_tmp_j;
  int32_T temp_tmp_tmp_ga;
  int32_T temp_tmp_tmp_j;
  int32_T b_i_e;
  int32_T j_j;
  int32_T sgn_j;
  int32_T kk_g;
  int32_T b_jj_o;
  int32_T qp1;
  int32_T qq;
  int32_T qjj;
  int32_T qs;
  int32_T e_k;
  int32_T i_h;
  int32_T k_c;
  int32_T ihi_a;
  int32_T b_jj_l;
  int32_T ii_j;
  int32_T i_i;
  int32_T temp1_tmp;
  int32_T tau_tmp_m;
  int32_T tau_tmp_tmp_f;
  int32_T d_tmp;
  int32_T kdefl;
  int32_T l;
  int32_T k_o;
  int32_T b_m;
  int32_T nr;
  int32_T b_i_i;
  int32_T its;
  int32_T n;
  int32_T ix0;
  int32_T d_k_e;
  int32_T s_tmp_j;
  int32_T h_tmp;
  int32_T knt;
  int32_T c_k_o;
  int32_T k_f;
  int32_T ihi_m;
  int32_T b_jj_a;
  int32_T ii_h;
  int32_T i_o;
  int32_T qp1_h;
  int32_T qq_j;
  int32_T qjj_g;
  int32_T qs_j;
  int32_T e_k_l;
  int32_T i_kb;
  int32_T kend;
  int32_T k_d;
  int32_T in;
  int32_T i_n;
  int32_T i_j;
  int32_T im1n_tmp;
  int32_T tau_tmp_a;
  int32_T alpha1_tmp_tmp;
  int32_T knt_h;
  int32_T c_i;
  int32_T d_tmp_d;
  int32_T kend_b;
  int32_T k_h;
  int32_T in_p;
  int32_T b_n;
  int32_T i_jz;
  int32_T i1;
  int32_T tau_tmp_ot;
  int32_T alpha1_tmp_tmp_b;
  int32_T lastv;
  int32_T lastc;
  int32_T ix;
  int32_T c_j;
  int32_T d_e;
  int32_T rowleft;
  int32_T jA;
  int32_T i2;
  int32_T p1;
  int32_T p2;
  int32_T p3;
  int32_T itmp;
  int32_T nh;
  int32_T ia;
  int32_T b_ia;
  int32_T f_i;
  int32_T itau;
  int32_T e_i4;
  int32_T k_n;
  int32_T lastv_i;
  int32_T lastc_p;
  int32_T d_o;
  int32_T coltop;
  int32_T b_ia_m;
  int32_T jA_o;
  int32_T ica;
  int32_T ira;
  int32_T kend_g;
  int32_T f_ix;
  int32_T i_e;
  int32_T c_temp_tmp;
  int32_T ix0_tmp;
  int32_T jtot;
  int32_T l1;
  int32_T b_m_i;
  int32_T l_g;
  int32_T lsv;
  int32_T lend;
  int32_T iscale;
  int32_T lendsv_tmp;
  int32_T anorm_tmp_tmp;
  int32_T b_i_g;
  int32_T i3;
  int32_T jtot_g;
  int32_T l1_g;
  int32_T b_m_c;
  int32_T l_k;
  int32_T lsv_d;
  int32_T lend_k;
  int32_T iscale_p;
  int32_T i_p;
  int32_T anorm_tmp_tmp_m;
  int32_T offsetj;
  int32_T offsetjp1;
  int32_T j_k;
  int32_T i_a;
  int32_T temp_tmp_ft;
  int32_T i4;
  int32_T trueCount;
  int32_T i_c;
  int32_T i5;
  int32_T i6;
  int32_T i_jk;
  int32_T nz;
  int32_T kdefl_k;
  int32_T l_h;
  int32_T k_d1;
  int32_T b_m_j;
  int32_T nr_n;
  int32_T n_j;
  int32_T ix0_l;
  int32_T d_k_p;
  int32_T c_iy;
  int32_T s_tmp_p;
  int32_T h_tmp_l;
  int32_T count;
  int32_T i7;
  int32_T offsetj_l;
  int32_T offsetjp1_h;
  int32_T b_j_c;
  int32_T i_g;
  int32_T temp_tmp_e;
  int32_T i8;
  int32_T i9;
  int32_T idxA1j;
  int32_T idxAjj;
  int32_T b_j_n;
  int32_T k_fn;
  int32_T d_n;
  int32_T e_e;
  int32_T ia_b;
  int32_T k_a;
  int32_T kend_i;
  int32_T k_nq;
  int32_T k_fx;
  int32_T temp_tmp_tmp_i;
  int32_T temp_tmp_tmp_k;
  int32_T idx;
  int32_T k_b;
  int32_T count_d;
  int32_T b_i_h;
  int32_T k_nl;
  int32_T temp_tmp_fj;
  int32_T i10;
  int32_T iyend;
  int32_T ix_a;
  int32_T c_iy_m;
  int32_T b_gu;
  int32_T i11;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T i12;
  int32_T loop_ub_n;
  int32_T i_ch;
  int32_T anorm_tmp;
  int32_T j_d4;
  int32_T i_ky;
  int32_T exponent;
  int32_T b_i_c;
  int32_T i13;
  int32_T k_j;
  int32_T i14;
  int32_T b_mt;
  int32_T k_i;
  int32_T k_bj;
  int32_T i15;
  int32_T k_oq;
  int32_T i16;
  int32_T j_g;
  int32_T i_ed;
  int32_T j_i;
  int32_T i_eb;
  int32_T b_is;
  int32_T k_m;
  int32_T sgn1;
  int32_T sgn2;
  int32_T k_dl;
  uint32_T lo;
  uint32_T hi;
  int8_T rtAction;
  int8_T rtPrevAction;
  boolean_T rEQ0;
  boolean_T Reject_j;
  boolean_T iscale_pe;
  boolean_T scalea;
  boolean_T apply_transform;
  boolean_T scalea_b;
  boolean_T converged;
  boolean_T b_p;
  boolean_T apply_transform_n;
  boolean_T notdone;
  boolean_T skipThisColumn;
  boolean_T notdone_c;
  boolean_T tmp_data;
  boolean_T rEQ0_n;
  boolean_T b1;
  boolean_T converged_d;
  boolean_T b2;
  boolean_T b3;
  boolean_T notdone_i;
  boolean_T p_n;
  boolean_T notdone_b;
  B_MATLABFunction10_APF_CTL_VI_T sf_MATLABFunction5;// '<S663>/MATLAB Function5' 
  B_MATLABFunction10_APF_CTL_VI_T sf_MATLABFunction6;// '<S651>/MATLAB Function6' 
  B_MATLABFunction10_APF_CTL_VI_T sf_MATLABFunction10;// '<S639>/MATLAB Function10' 
  B_Phase4ReturnHome_APF_CTL_VI_T Phase5HoldHome;// '<Root>/Phase #5: Hold Home' 
  B_Phase4ReturnHome_APF_CTL_VI_T Phase4ReturnHome;// '<Root>/Phase #4: Return Home' 
  B_SimulatedPositionController_T SimulatedPositionController;
                                      // '<S352>/Simulated Position Controller'
  B_REDARM_APF_CTL_VIS_Obs_2023_T REDARM_m;// '<S246>/RED+ARM'
  B_SubPhase1_APF_CTL_VIS_Obs_i_T SubPhase2_p;// '<S89>/Sub-Phase #2 '
  B_SubPhase1_APF_CTL_VIS_Obs_i_T SubPhase1_p;// '<S89>/Sub-Phase #1'
  B_SubPhase1_APF_CTL_VIS_Obs_n_T SubPhase3_e;// '<S88>/Sub-Phase #3 '
  B_SubPhase1_APF_CTL_VIS_Obs_n_T SubPhase2_c;// '<S88>/Sub-Phase #2 '
  B_SubPhase1_APF_CTL_VIS_Obs_n_T SubPhase1_g;// '<S88>/Sub-Phase #1'
  B_SubPhase1_APF_CTL_VIS_Obs_2_T SubPhase3;// '<S87>/Sub-Phase #3 '
  B_SubPhase1_APF_CTL_VIS_Obs_2_T SubPhase2;// '<S87>/Sub-Phase #2 '
  B_SubPhase1_APF_CTL_VIS_Obs_2_T SubPhase1;// '<S87>/Sub-Phase #1'
  B_REDARM_APF_CTL_VIS_Obs_2023_T REDARM_e;// '<S35>/RED+ARM'
};

// Block states (default storage) for system '<Root>'
struct DW_APF_CTL_VIS_Obs_2023a_T {
  Dynamixel_Controller_APF_CTL__T obj;
  // '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
  GPIO_Write_APF_CTL_VIS_Obs_20_T obj_p;// '<S25>/Set Pin 428 (Pucks) to HIGH'
  ReadArm_Position_Rates_APF_CT_T obj_d;
                      // '<S26>/Read Joint Positions using  Dynamixel Encoders'
  IdentifyPlatform_APF_CTL_VIS__T obj_dk;// '<S575>/WhoAmI'
  CustomDataLogger_APF_CTL_VIS__T obj_i;// '<S23>/MATLAB System'
  real_T Delay_DSTATE[3];              // '<S354>/Delay'
  real_T Delay1_DSTATE[6];             // '<S355>/Delay1'
  real_T Delay_DSTATE_e[36];           // '<S355>/Delay'
  real_T Delay3_DSTATE;                // '<S355>/Delay3'
  real_T Delay2_DSTATE;                // '<S355>/Delay2'
  real_T Delay_DSTATE_h;               // '<S379>/Delay'
  real_T Delay_DSTATE_b[2];            // '<S359>/Delay'
  real_T Delay1_DSTATE_p[6];           // '<S360>/Delay1'
  real_T Delay_DSTATE_a[36];           // '<S360>/Delay'
  real_T Delay3_DSTATE_o;              // '<S360>/Delay3'
  real_T Delay2_DSTATE_h;              // '<S360>/Delay2'
  real_T DiscreteTransferFcn1_states;  // '<S381>/Discrete Transfer Fcn1'
  real_T Delay_DSTATE_d[3];            // '<S386>/Delay'
  real_T Delay1_DSTATE_n[3];           // '<S386>/Delay1'
  real_T Delay3_DSTATE_a[3];           // '<S387>/Delay3'
  real_T Delay1_DSTATE_l[3];           // '<S388>/Delay1'
  real_T Delay3_DSTATE_j[3];           // '<S388>/Delay3'
  real_T Delay1_DSTATE_d[3];           // '<S389>/Delay1'
  real_T Delay3_DSTATE_a5[3];          // '<S389>/Delay3'
  real_T Delay_DSTATE_c[3];            // '<S391>/Delay'
  real_T Delay_DSTATE_o[3];            // '<S392>/Delay'
  real_T Delay3_DSTATE_d[3];           // '<S393>/Delay3'
  real_T DiscreteTimeIntegrator4_DSTATE;// '<S370>/Discrete-Time Integrator4'
  real_T DiscreteTimeIntegrator5_DSTATE;// '<S370>/Discrete-Time Integrator5'
  real_T DiscreteTimeIntegrator2_DSTATE;// '<S370>/Discrete-Time Integrator2'
  real_T DiscreteTimeIntegrator3_DSTATE;// '<S370>/Discrete-Time Integrator3'
  real_T DiscreteTimeIntegrator1_DSTATE;// '<S370>/Discrete-Time Integrator1'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S370>/Discrete-Time Integrator'
  real_T Delay1_DSTATE_da;             // '<S323>/Delay1'
  real_T Delay1_DSTATE_d3;             // '<S325>/Delay1'
  real_T Delay1_DSTATE_g;              // '<S327>/Delay1'
  real_T StartPos_DSTATE;              // '<S232>/Start Pos'
  real_T Delay1_DSTATE_b;              // '<S237>/Delay1'
  real_T StartPos_DSTATE_b;            // '<S233>/Start Pos'
  real_T Delay1_DSTATE_e;              // '<S239>/Delay1'
  real_T StartPos_DSTATE_p;            // '<S234>/Start Pos'
  real_T Delay1_DSTATE_do;             // '<S235>/Delay1'
  real_T StartPos_DSTATE_k;            // '<S149>/Start Pos'
  real_T Delay1_DSTATE_pn;             // '<S154>/Delay1'
  real_T StartPos_DSTATE_c;            // '<S150>/Start Pos'
  real_T Delay1_DSTATE_na;             // '<S156>/Delay1'
  real_T StartPos_DSTATE_e;            // '<S151>/Start Pos'
  real_T Delay1_DSTATE_p2;             // '<S152>/Delay1'
  real_T Delay1_DSTATE_gi;             // '<S67>/Delay1'
  real_T Delay1_DSTATE_m;              // '<S69>/Delay1'
  real_T Delay1_DSTATE_ej;             // '<S71>/Delay1'
  real_T Delay1_DSTATE_i;              // '<S42>/Delay1'
  real_T Delay1_DSTATE_c;              // '<S44>/Delay1'
  real_T Delay1_DSTATE_c1;             // '<S40>/Delay1'
  real_T Delay1_DSTATE_mw;             // '<S55>/Delay1'
  real_T Delay1_DSTATE_et;             // '<S57>/Delay1'
  real_T Delay1_DSTATE_a;              // '<S53>/Delay1'
  real_T Delay1_DSTATE_eo;             // '<S544>/Delay1'
  real_T Delay1_DSTATE_gs;             // '<S541>/Delay1'
  real_T Delay1_DSTATE_bm;             // '<S549>/Delay1'
  real_T Delay1_DSTATE_p4;             // '<S538>/Delay1'
  real_T Delay1_DSTATE_md;             // '<S550>/Delay1'
  real_T Delay1_DSTATE_j;              // '<S539>/Delay1'
  real_T Delay1_DSTATE_p4s;            // '<S551>/Delay1'
  real_T Delay1_DSTATE_k;              // '<S540>/Delay1'
  real_T Delay1_DSTATE_mi;             // '<S545>/Delay1'
  real_T Delay1_DSTATE_pc;             // '<S542>/Delay1'
  real_T Delay1_DSTATE_cu;             // '<S546>/Delay1'
  real_T Delay1_DSTATE_a0;             // '<S543>/Delay1'
  real_T Delay1_DSTATE_h;              // '<S537>/Delay1'
  real_T Delay1_DSTATE_ah;             // '<S552>/Delay1'
  real_T Delay1_DSTATE_lx;             // '<S547>/Delay1'
  real_T Delay1_DSTATE_j3;             // '<S553>/Delay1'
  real_T Delay1_DSTATE_m2;             // '<S548>/Delay1'
  real_T Delay1_DSTATE_hi;             // '<S554>/Delay1'
  real_T Delay_DSTATE_as;              // '<S26>/Delay'
  real_T Delay1_DSTATE_pw;             // '<S26>/Delay1'
  real_T Delay2_DSTATE_c;              // '<S26>/Delay2'
  real_T AccelerationtoVelocity_DSTATE[3];// '<S581>/Acceleration  to Velocity'
  real_T VelocitytoPosition_DSTATE[3]; // '<S581>/Velocity to Position'
  real_T Delay1_DSTATE_f;              // '<S587>/Delay1'
  real_T Delay1_DSTATE_lg;             // '<S584>/Delay1'
  real_T Delay1_DSTATE_d3a;            // '<S582>/Delay1'
  real_T Delay1_DSTATE_ea;             // '<S585>/Delay1'
  real_T Delay1_DSTATE_cx;             // '<S583>/Delay1'
  real_T Delay1_DSTATE_ab;             // '<S586>/Delay1'
  real_T AccelerationtoVelocity_DSTATE_i[3];// '<S595>/Acceleration  to Velocity' 
  real_T VelocitytoPosition_DSTATE_a[3];// '<S595>/Velocity to Position'
  real_T Delay1_DSTATE_gv;             // '<S601>/Delay1'
  real_T Delay1_DSTATE_ds;             // '<S598>/Delay1'
  real_T Delay1_DSTATE_i5;             // '<S596>/Delay1'
  real_T Delay1_DSTATE_l0;             // '<S599>/Delay1'
  real_T Delay1_DSTATE_iq;             // '<S597>/Delay1'
  real_T Delay1_DSTATE_eq;             // '<S600>/Delay1'
  real_T AccelerationtoVelocity_DSTATE_b[3];// '<S622>/Acceleration  to Velocity' 
  real_T VelocitytoPosition_DSTATE_m[3];// '<S622>/Velocity to Position'
  real_T Delay1_DSTATE_n2;             // '<S624>/Delay1'
  real_T Delay1_DSTATE_pc3;            // '<S626>/Delay1'
  real_T Delay1_DSTATE_k4;             // '<S623>/Delay1'
  real_T Delay1_DSTATE_dh;             // '<S627>/Delay1'
  real_T Delay1_DSTATE_lh;             // '<S625>/Delay1'
  real_T Delay1_DSTATE_jb;             // '<S628>/Delay1'
  real_T Delay_DSTATE_of[12];          // '<S611>/Delay'
  real_T AccelerationtoVelocity_DSTATE_f[12];// '<S611>/Acceleration  to Velocity' 
  real_T Delay1_DSTATE_by;             // '<S616>/Delay1'
  real_T Delay1_DSTATE_ny;             // '<S615>/Delay1'
  real_T Delay1_DSTATE_nb;             // '<S617>/Delay1'
  real_T UDPReceive1_NetworkLib[137];  // '<S2>/UDP Receive1'
  real_T UDPSend_NetworkLib[137];      // '<S19>/UDP Send'
  real_T BLACK_Fx;                     // '<Root>/BLACK_Fx'
  real_T BLUE_Fx;                      // '<Root>/BLACK_Fx1'
  real_T BLACK_Fx_Sat;                 // '<Root>/BLACK_Fx_Sat'
  real_T BLUE_Fx_Sat;                  // '<Root>/BLACK_Fx_Sat2'
  real_T BLACK_Fy;                     // '<Root>/BLACK_Fy'
  real_T BLUE_Fy;                      // '<Root>/BLACK_Fy1'
  real_T BLACK_Fy_Sat;                 // '<Root>/BLACK_Fy_Sat'
  real_T BLUE_Fy_Sat;                  // '<Root>/BLACK_Fy_Sat2'
  real_T BLACK_Px;                     // '<Root>/BLACK_Px'
  real_T BLUE_Px;                      // '<Root>/BLACK_Px1'
  real_T BLACK_Px_Est;                 // '<Root>/BLACK_Px2'
  real_T BLACK_Px_preKalm;             // '<Root>/BLACK_Px3'
  real_T BLUE_Px_Est;                  // '<Root>/BLACK_Px4'
  real_T BLUE_Px_preKalm;              // '<Root>/BLACK_Px5'
  real_T BLACK_Py;                     // '<Root>/BLACK_Py'
  real_T BLUE_Py;                      // '<Root>/BLACK_Py1'
  real_T BLACK_Py_Est;                 // '<Root>/BLACK_Py2'
  real_T BLACK_Py_preKalm;             // '<Root>/BLACK_Py3'
  real_T BLUE_Py_Est;                  // '<Root>/BLACK_Py4'
  real_T BLUE_Py_preKalm;              // '<Root>/BLACK_Py5'
  real_T BLACK_Reject;                 // '<Root>/BLACK_Py6'
  real_T BLUE_Reject;                  // '<Root>/BLACK_Py7'
  real_T Blue_Detection;               // '<Root>/BLACK_Py8'
  real_T Phase;                        // '<Root>/BLACK_Py9'
  real_T BLACK_Rz;                     // '<Root>/BLACK_Rz'
  real_T BLUE_Rz;                      // '<Root>/BLACK_Rz1'
  real_T BLACK_Rz_Est;                 // '<Root>/BLACK_Rz2'
  real_T BLACK_Rz_preKalm;             // '<Root>/BLACK_Rz3'
  real_T BLACK_Tz;                     // '<Root>/BLACK_Tz'
  real_T BLUE_Tz;                      // '<Root>/BLACK_Tz1'
  real_T BLACK_Tz_Sat;                 // '<Root>/BLACK_Tz_Sat'
  real_T BLUE_Tz_Sat;                  // '<Root>/BLACK_Tz_Sat2'
  real_T RED_Fx;                       // '<Root>/RED_Fx1'
  real_T RED_Fx_Sat;                   // '<Root>/RED_Fx_Sat'
  real_T RED_Fy;                       // '<Root>/RED_Fy'
  real_T RED_Fy_Sat;                   // '<Root>/RED_Fy_Sat'
  real_T RED_Px;                       // '<Root>/RED_Px'
  real_T RED_Py;                       // '<Root>/RED_Py'
  real_T RED_Rz;                       // '<Root>/RED_Rz'
  real_T RED_Tz;                       // '<Root>/RED_Tz'
  real_T RED_RzD_Shoulder;             // '<Root>/RED_Tz12'
  real_T RED_RzD_Elbow;                // '<Root>/RED_Tz13'
  real_T RED_RzD_Wrist;                // '<Root>/RED_Tz14'
  real_T RED_ARM_Control_Mode;         // '<Root>/RED_Tz15'
  real_T RED_Shoulder_Command;         // '<Root>/RED_Tz16'
  real_T RED_Rz_Shoulder;              // '<Root>/RED_Tz4'
  real_T RED_Rz_Elbow;                 // '<Root>/RED_Tz5'
  real_T RED_Rz_Wrist;                 // '<Root>/RED_Tz6'
  real_T Float_State;                  // '<Root>/RED_Tz7'
  real_T RED_Tz_RW_Sat;                // '<Root>/RED_Tz_RW Sat'
  real_T RED_Tz_Sat;                   // '<Root>/RED_Tz_Sat'
  real_T Command_Px;                   // '<Root>/RED_dRz_RW Sat1'
  real_T TX2_data1;                    // '<Root>/RED_dRz_RW Sat10'
  real_T TX2_data2;                    // '<Root>/RED_dRz_RW Sat11'
  real_T TX2_data3;                    // '<Root>/RED_dRz_RW Sat12'
  real_T TX2_data4;                    // '<Root>/RED_dRz_RW Sat13'
  real_T TX2_data5;                    // '<Root>/RED_dRz_RW Sat14'
  real_T Command_Py;                   // '<Root>/RED_dRz_RW Sat2'
  real_T Command_Rz;                   // '<Root>/RED_dRz_RW Sat3'
  real_T DAC_Posx_k_1;                 // '<Root>/RED_dRz_RW Sat4'
  real_T DAC_Posx_k_2;                 // '<Root>/RED_dRz_RW Sat5'
  real_T DAC_Posy_k_1;                 // '<Root>/RED_dRz_RW Sat6'
  real_T DAC_Posy_k_2;                 // '<Root>/RED_dRz_RW Sat7'
  real_T DAC_Attitude_k_1;             // '<Root>/RED_dRz_RW Sat8'
  real_T DAC_Attitude_k_2;             // '<Root>/RED_dRz_RW Sat9'
  real_T Univ_Time;                    // '<Root>/Universal_Time'
  real_T RED_Vx;                       // '<Root>/Universal_Time1'
  real_T RED_Ax;                       // '<Root>/Universal_Time10'
  real_T RED_Ay;                       // '<Root>/Universal_Time11'
  real_T BLACK_Ax;                     // '<Root>/Universal_Time12'
  real_T BLACK_Ay;                     // '<Root>/Universal_Time13'
  real_T BLACK_RzDD;                   // '<Root>/Universal_Time14'
  real_T RED_RzDD;                     // '<Root>/Universal_Time15'
  real_T RED_Thruster_ON_Count;        // '<Root>/Universal_Time16'
  real_T BLACK_Thruster_ON_Count;      // '<Root>/Universal_Time17'
  real_T BLUE_Thruster_ON_Count;       // '<Root>/Universal_Time18'
  real_T WhoAmI;                       // '<Root>/Universal_Time19'
  real_T RED_Vy;                       // '<Root>/Universal_Time2'
  real_T isSim;                        // '<Root>/Universal_Time20'
  real_T RED_Elbow_Command;            // '<Root>/Universal_Time21'
  real_T RED_Wrist_Command;            // '<Root>/Universal_Time22'
  real_T RED_RzD;                      // '<Root>/Universal_Time3'
  real_T BLACK_Vx;                     // '<Root>/Universal_Time4'
  real_T BLACK_Vy;                     // '<Root>/Universal_Time5'
  real_T BLACK_RzD;                    // '<Root>/Universal_Time6'
  real_T BLUE_Vx;                      // '<Root>/Universal_Time7'
  real_T BLUE_Vy;                      // '<Root>/Universal_Time8'
  real_T BLUE_RzD;                     // '<Root>/Universal_Time9'
  real_T Product1_DWORK4[9];           // '<S680>/Product1'
  real_T Product1_DWORK4_a[9];         // '<S681>/Product1'
  real_T Product1_DWORK4_av[9];        // '<S659>/Product1'
  real_T Product1_DWORK4_g[9];         // '<S660>/Product1'
  real_T Product1_DWORK4_m[9];         // '<S647>/Product1'
  real_T Product1_DWORK4_f[9];         // '<S648>/Product1'
  real_T TimeStampA;                   // '<S370>/Derivative2'
  real_T LastUAtTimeA;                 // '<S370>/Derivative2'
  real_T TimeStampB;                   // '<S370>/Derivative2'
  real_T LastUAtTimeB;                 // '<S370>/Derivative2'
  real_T TimeStampA_d;                 // '<S370>/Derivative1'
  real_T LastUAtTimeA_k;               // '<S370>/Derivative1'
  real_T TimeStampB_m;                 // '<S370>/Derivative1'
  real_T LastUAtTimeB_j;               // '<S370>/Derivative1'
  real_T TimeStampA_n;                 // '<S370>/Derivative3'
  real_T LastUAtTimeA_d;               // '<S370>/Derivative3'
  real_T TimeStampB_k;                 // '<S370>/Derivative3'
  real_T LastUAtTimeB_f;               // '<S370>/Derivative3'
  real_T UDPSend_NetworkLib_m[137];    // '<S577>/UDP Send'
  real_T UDPReceive1_NetworkLib_b[137];// '<S534>/UDP Receive1'
  real_T Unwrap1_Prev;                 // '<S534>/Unwrap1'
  real_T Unwrap1_Cumsum;               // '<S534>/Unwrap1'
  real_T Unwrap2_Prev;                 // '<S534>/Unwrap2'
  real_T Unwrap2_Cumsum;               // '<S534>/Unwrap2'
  real_T Unwrap_Prev;                  // '<S534>/Unwrap'
  real_T Unwrap_Cumsum;                // '<S534>/Unwrap'
  real_T UDPReceive_NetworkLib[137];   // '<S534>/UDP Receive'
  real_T UDPReceive2_NetworkLib[137];  // '<S534>/UDP Receive2'
  real_T UDPReceive3_NetworkLib[137];  // '<S534>/UDP Receive3'
  real_T Memory_PreviousInput;         // '<S555>/Memory'
  real_T NextOutput;                   // '<S581>/Random Number'
  real_T NextOutput_b;                 // '<S578>/Random Number1'
  real_T NextOutput_j;                 // '<S578>/Random Number'
  real_T NextOutput_g;                 // '<S578>/Random Number2'
  real_T NextOutput_a;                 // '<S595>/Random Number'
  real_T NextOutput_i;                 // '<S622>/Random Number'
  real_T NextOutput_n;                 // '<S621>/Random Number7'
  real_T NextOutput_ga;                // '<S621>/Random Number6'
  real_T NextOutput_l;                 // '<S621>/Random Number8'
  real_T NextOutput_f;                 // '<S611>/Random Number2'
  real_T NextOutput_h;                 // '<S611>/Random Number1'
  real_T NextOutput_go;                // '<S611>/Random Number3'
  real_T UDPSend_NetworkLib_l[137];    // '<S22>/UDP Send'
  int32_T Delay_DSTATE_l[5];           // '<S534>/Delay'
  int32_T Delay1_DSTATE_hu[5];         // '<S534>/Delay1'
  int32_T Delay2_DSTATE_k[5];          // '<S534>/Delay2'
  uint32_T RandSeed;                   // '<S581>/Random Number'
  uint32_T RandSeed_n;                 // '<S578>/Random Number1'
  uint32_T RandSeed_g;                 // '<S578>/Random Number'
  uint32_T RandSeed_m;                 // '<S578>/Random Number2'
  uint32_T RandSeed_o;                 // '<S595>/Random Number'
  uint32_T RandSeed_n0;                // '<S579>/Random Number4'
  uint32_T RandSeed_e;                 // '<S579>/Random Number3'
  uint32_T RandSeed_c;                 // '<S579>/Random Number5'
  uint32_T RandSeed_k;                 // '<S622>/Random Number'
  uint32_T RandSeed_a;                 // '<S621>/Random Number7'
  uint32_T RandSeed_f;                 // '<S621>/Random Number6'
  uint32_T RandSeed_h;                 // '<S621>/Random Number8'
  uint32_T RandSeed_av;                // '<S611>/Random Number2'
  uint32_T RandSeed_a4;                // '<S611>/Random Number1'
  uint32_T RandSeed_i;                 // '<S611>/Random Number3'
  int8_T SeparatePhases_ActiveSubsystem;// '<Root>/Separate Phases'
  int8_T IfsimModesetto1thenthisisasimul;
  // '<Root>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 
  int8_T ThisIFblockdetermineswhetherorn;
    // '<S1>/This IF block determines whether or not to run the BLACK sim//exp'
  int8_T ThisIFblockdetermineswhethero_j;
     // '<S1>/This IF block determines whether or not to run the BLUE sim//exp'
  int8_T ThisIFblockdetermineswhethero_o;
     // '<S1>/This IF block determines whether or not to run the RED sim//exp '
  int8_T ThisIFblockdetermineswhethero_d;
          // '<S4>/This IF block determines whether or not to run the exp code'
  int8_T ThisIFblockdetermineswhethero_a;
     // '<S5>/This IF block determines whether or not to run the RED sim//exp '
  int8_T Ifperforminganexperimentgrabthe;
  // '<S13>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 
  int8_T IfsimModesetto1thenthisisasim_f;
  // '<S14>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 
  int8_T ThisIFblockdetermineswhethero_g;
    // '<S15>/This IF block determines whether or not to run the RED sim//exp '
  int8_T IfsimModesetto1thenthisisasim_h;
  // '<S16>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 
  int8_T ThisIFblockdetermineswhethero_p;
    // '<S19>/This IF block determines whether or not to run the RED sim//exp '
  int8_T ThisIFblockdetermineswhether_am;
  // '<S19>/This IF block determines whether or not to run the BLACK sim//exp'
  int8_T ThisIFblockdetermineswhethero_h;
    // '<S19>/This IF block determines whether or not to run the BLUE sim//exp'
  int8_T ThisIFblockdetermineswhethero_f;
    // '<S12>/This IF block determines whether or not to run the BLUE sim//exp'
  int8_T ThisIFblockdetermineswhether_dt;
  // '<S12>/This IF block determines whether or not to run the BLACK sim//exp'
  int8_T ThisIFblockdetermineswhethero_l;
    // '<S12>/This IF block determines whether or not to run the RED sim//exp '
  int8_T ThisIFblockdetermineswhethero_n;
    // '<S9>/This IF block determines whether or not to run the BLACK sim//exp'
  int8_T ThisIFblockdetermineswhether_al;
     // '<S9>/This IF block determines whether or not to run the BLUE sim//exp'
  int8_T ThisIFblockdetermineswhether_fg;
     // '<S9>/This IF block determines whether or not to run the RED sim//exp '
  int8_T ExperimentSubPhases_ActiveSubsy;// '<S89>/Experiment Sub-Phases'
  int8_T If2_ActiveSubsystem;          // '<S350>/If2'
  int8_T If1_ActiveSubsystem;          // '<S350>/If1'
  int8_T If_ActiveSubsystem;           // '<S350>/If'
  int8_T If2_ActiveSubsystem_m;        // '<S349>/If2'
  int8_T If1_ActiveSubsystem_a;        // '<S349>/If1'
  int8_T If_ActiveSubsystem_m;         // '<S349>/If'
  int8_T If_ActiveSubsystem_l;         // '<S247>/If'
  int8_T ifwewentthroughastep_ActiveSubs;// '<S323>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_h;// '<S325>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_l;// '<S327>/if we went through a "step"' 
  int8_T ExperimentSubPhases_ActiveSub_c;// '<S88>/Experiment Sub-Phases'
  int8_T ifwewentthroughastep_ActiveSu_p;// '<S237>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_i;// '<S239>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_k;// '<S235>/if we went through a "step"' 
  int8_T ExperimentSubPhases_ActiveSub_l;// '<S87>/Experiment Sub-Phases'
  int8_T ifwewentthroughastep_ActiveSu_o;// '<S154>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveS_op;// '<S156>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_b;// '<S152>/if we went through a "step"' 
  int8_T ThisIFblockdetermineswhether_l2;
     // '<S8>/This IF block determines whether or not to run the BLUE sim//exp'
  int8_T ThisIFblockdetermineswhether_h2;
    // '<S8>/This IF block determines whether or not to run the BLACK sim//exp'
  int8_T ThisIFblockdetermineswhether_gv;
     // '<S8>/This IF block determines whether or not to run the RED sim//exp '
  int8_T ifwewentthroughastep_ActiveSu_n;// '<S67>/if we went through a "step"'
  int8_T ifwewentthroughastep_ActiveSu_c;// '<S69>/if we went through a "step"'
  int8_T ifwewentthroughastep_ActiveSu_j;// '<S71>/if we went through a "step"'
  int8_T ifwewentthroughastep_ActiveS_ba;// '<S42>/if we went through a "step"'
  int8_T ifwewentthroughastep_ActiveS_il;// '<S44>/if we went through a "step"'
  int8_T ifwewentthroughastep_ActiveSu_m;// '<S40>/if we went through a "step"'
  int8_T ifwewentthroughastep_ActiveSu_e;// '<S55>/if we went through a "step"'
  int8_T ifwewentthroughastep_ActiveSu_f;// '<S57>/if we went through a "step"'
  int8_T ifwewentthroughastep_ActiveS_jh;// '<S53>/if we went through a "step"'
  int8_T ifwewentthroughastep_ActiveS_jt;// '<S544>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveS_lg;// '<S541>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveS_ch;// '<S549>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveS_c5;// '<S538>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveS_ls;// '<S550>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveS_i2;// '<S539>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveS_kz;// '<S551>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveS_ed;// '<S540>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveS_o2;// '<S545>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveS_cu;// '<S542>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveS_hb;// '<S546>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveS_fj;// '<S543>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveS_ca;// '<S537>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveS_ez;// '<S552>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveS_oo;// '<S547>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveS_hv;// '<S553>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveS_lu;// '<S548>/if we went through a "step"' 
  int8_T ifwewentthroughastep_Active_lgb;// '<S554>/if we went through a "step"' 
  boolean_T IC_FirstOutputTime;        // '<S355>/IC'
  boolean_T IC_FirstOutputTime_b;      // '<S360>/IC'
  boolean_T icLoad;                    // '<S323>/Delay1'
  boolean_T icLoad_f;                  // '<S325>/Delay1'
  boolean_T icLoad_i;                  // '<S327>/Delay1'
  boolean_T icLoad_d;                  // '<S237>/Delay1'
  boolean_T icLoad_d4;                 // '<S239>/Delay1'
  boolean_T icLoad_l;                  // '<S235>/Delay1'
  boolean_T icLoad_c;                  // '<S154>/Delay1'
  boolean_T icLoad_j;                  // '<S156>/Delay1'
  boolean_T icLoad_fo;                 // '<S152>/Delay1'
  boolean_T icLoad_g;                  // '<S67>/Delay1'
  boolean_T icLoad_a;                  // '<S69>/Delay1'
  boolean_T icLoad_b;                  // '<S71>/Delay1'
  boolean_T icLoad_fp;                 // '<S42>/Delay1'
  boolean_T icLoad_ig;                 // '<S44>/Delay1'
  boolean_T icLoad_p;                  // '<S40>/Delay1'
  boolean_T icLoad_o;                  // '<S55>/Delay1'
  boolean_T icLoad_n;                  // '<S57>/Delay1'
  boolean_T icLoad_bb;                 // '<S53>/Delay1'
  boolean_T icLoad_lu;                 // '<S544>/Delay1'
  boolean_T icLoad_ld;                 // '<S541>/Delay1'
  boolean_T icLoad_dc;                 // '<S549>/Delay1'
  boolean_T icLoad_k;                  // '<S538>/Delay1'
  boolean_T icLoad_fv;                 // '<S550>/Delay1'
  boolean_T icLoad_na;                 // '<S539>/Delay1'
  boolean_T Unwrap1_FirstStep;         // '<S534>/Unwrap1'
  boolean_T icLoad_gx;                 // '<S551>/Delay1'
  boolean_T icLoad_m;                  // '<S540>/Delay1'
  boolean_T icLoad_e;                  // '<S545>/Delay1'
  boolean_T icLoad_fpv;                // '<S542>/Delay1'
  boolean_T Unwrap2_FirstStep;         // '<S534>/Unwrap2'
  boolean_T icLoad_mt;                 // '<S546>/Delay1'
  boolean_T icLoad_nw;                 // '<S543>/Delay1'
  boolean_T icLoad_h;                  // '<S537>/Delay1'
  boolean_T icLoad_au;                 // '<S552>/Delay1'
  boolean_T icLoad_eo;                 // '<S547>/Delay1'
  boolean_T icLoad_fh;                 // '<S553>/Delay1'
  boolean_T Unwrap_FirstStep;          // '<S534>/Unwrap'
  boolean_T icLoad_fow;                // '<S548>/Delay1'
  boolean_T icLoad_aq;                 // '<S554>/Delay1'
  boolean_T icLoad_ou;                 // '<S587>/Delay1'
  boolean_T icLoad_p4;                 // '<S584>/Delay1'
  boolean_T icLoad_jc;                 // '<S582>/Delay1'
  boolean_T icLoad_jk;                 // '<S585>/Delay1'
  boolean_T icLoad_jr;                 // '<S583>/Delay1'
  boolean_T icLoad_jko;                // '<S586>/Delay1'
  boolean_T icLoad_do;                 // '<S601>/Delay1'
  boolean_T icLoad_nk;                 // '<S598>/Delay1'
  boolean_T icLoad_ip;                 // '<S596>/Delay1'
  boolean_T icLoad_az;                 // '<S599>/Delay1'
  boolean_T icLoad_dh;                 // '<S597>/Delay1'
  boolean_T icLoad_ex;                 // '<S600>/Delay1'
  boolean_T icLoad_nn;                 // '<S624>/Delay1'
  boolean_T icLoad_kb;                 // '<S626>/Delay1'
  boolean_T icLoad_jf;                 // '<S623>/Delay1'
  boolean_T icLoad_dk;                 // '<S627>/Delay1'
  boolean_T icLoad_l1;                 // '<S625>/Delay1'
  boolean_T icLoad_kp;                 // '<S628>/Delay1'
  boolean_T icLoad_bs;                 // '<S616>/Delay1'
  boolean_T icLoad_n5;                 // '<S615>/Delay1'
  boolean_T icLoad_mj;                 // '<S617>/Delay1'
  boolean_T EnabledSubsystem1_MODE;    // '<S535>/Enabled Subsystem1'
  DW_Phase4ReturnHome_APF_CTL_V_T Phase5HoldHome;// '<Root>/Phase #5: Hold Home' 
  DW_Phase4ReturnHome_APF_CTL_V_T Phase4ReturnHome;// '<Root>/Phase #4: Return Home' 
  DW_SimulatedPositionControlle_T SimulatedPositionController;
                                      // '<S352>/Simulated Position Controller'
  DW_REDARM_APF_CTL_VIS_Obs_202_T REDARM_m;// '<S246>/RED+ARM'
  DW_SubPhase1_APF_CTL_VIS_Ob_m_T SubPhase2_p;// '<S89>/Sub-Phase #2 '
  DW_SubPhase1_APF_CTL_VIS_Ob_m_T SubPhase1_p;// '<S89>/Sub-Phase #1'
  DW_SubPhase1_APF_CTL_VIS_Ob_o_T SubPhase3_e;// '<S88>/Sub-Phase #3 '
  DW_SubPhase1_APF_CTL_VIS_Ob_o_T SubPhase2_c;// '<S88>/Sub-Phase #2 '
  DW_SubPhase1_APF_CTL_VIS_Ob_o_T SubPhase1_g;// '<S88>/Sub-Phase #1'
  DW_SubPhase1_APF_CTL_VIS_Obs__T SubPhase3;// '<S87>/Sub-Phase #3 '
  DW_SubPhase1_APF_CTL_VIS_Obs__T SubPhase2;// '<S87>/Sub-Phase #2 '
  DW_SubPhase1_APF_CTL_VIS_Obs__T SubPhase1;// '<S87>/Sub-Phase #1'
  DW_REDARM_APF_CTL_VIS_Obs_202_T REDARM_e;// '<S35>/RED+ARM'
  DW_Phase0Synchronization_APF__T Phase1StartFloating;// '<Root>/Phase #1: Start Floating ' 
  DW_Phase0Synchronization_APF__T Phase0Synchronization;// '<Root>/Phase #0: Synchronization' 
  DW_ChangeBLACKBehavior_APF_CT_T ChangeBLUEBehavior;// '<S1>/Change BLUE Behavior' 
  DW_ChangeBLACKBehavior_APF_CT_T ChangeBLACKBehavior;// '<S1>/Change BLACK Behavior' 
};

// Continuous states (default storage)
struct X_APF_CTL_VIS_Obs_2023a_T {
  X_TargetTracker_APF_CTL_VIS_O_T TargetFinder;// '<S349>/Target Tracker'
  X_TargetTracker_APF_CTL_VIS_O_T TargetTracker;// '<S349>/Target Tracker'
};

// State derivatives (default storage)
struct XDot_APF_CTL_VIS_Obs_2023a_T {
  XDot_TargetTracker_APF_CTL_VI_T TargetFinder;// '<S349>/Target Tracker'
  XDot_TargetTracker_APF_CTL_VI_T TargetTracker;// '<S349>/Target Tracker'
};

// State disabled
struct XDis_APF_CTL_VIS_Obs_2023a_T {
  XDis_TargetTracker_APF_CTL_VI_T TargetFinder;// '<S349>/Target Tracker'
  XDis_TargetTracker_APF_CTL_VI_T TargetTracker;// '<S349>/Target Tracker'
};

#ifndef ODE4_INTG
#define ODE4_INTG

// ODE4 Integration Data
struct ODE4_IntgData {
  real_T *y;                           // output
  real_T *f[4];                        // derivatives
};

#endif

// Parameters for system: '<S1>/Change BLACK Behavior'
struct P_ChangeBLACKBehavior_APF_CTL_T_ {
  int32_T Constant1_Value;             // Computed Parameter: Constant1_Value
                                          //  Referenced by: '<S20>/Constant1'

  int32_T UDPSend_Port;                // Computed Parameter: UDPSend_Port
                                          //  Referenced by: '<S20>/UDP Send'

};

// Parameters for system: '<S6>/Change BLUE Behavior'
struct P_ChangeBLUEBehavior_APF_CTL__T_ {
  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<S28>/Constant3'

  real_T Constant4_Value;              // Expression: 0
                                          //  Referenced by: '<S28>/Constant4'

  real_T Constant5_Value;              // Expression: 0
                                          //  Referenced by: '<S28>/Constant5'

  real_T PuckState_Value;              // Expression: 0
                                          //  Referenced by: '<S28>/Puck State'

};

// Parameters for system: '<Root>/Phase #0: Synchronization'
struct P_Phase0Synchronization_APF_C_T_ {
  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<S27>/Constant3'

  real_T Constant4_Value;              // Expression: 0
                                          //  Referenced by: '<S27>/Constant4'

  real_T Constant5_Value;              // Expression: 0
                                          //  Referenced by: '<S27>/Constant5'

  real_T PuckState_Value;              // Expression: 0
                                          //  Referenced by: '<S27>/Puck State'

  real_T Constant_Value;               // Expression: 0
                                          //  Referenced by: '<S29>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S29>/Constant1'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S29>/Constant2'

  real_T Constant3_Value_e;            // Expression: 0
                                          //  Referenced by: '<S29>/Constant3'

  real_T Constant4_Value_b;            // Expression: 0
                                          //  Referenced by: '<S29>/Constant4'

  real_T PuckState_Value_h;            // Expression: 0
                                          //  Referenced by: '<S29>/Puck State'

  P_ChangeBLUEBehavior_APF_CTL__T ChangeBLUEBehavior;// '<S6>/Change BLUE Behavior' 
};

// Parameters for system: '<S66>/Simulated Position Controller'
struct P_SimulatedPositionController_T_ {
  real_T Out1_Y0;                      // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S82>/Out1'

  real_T Out1_Y0_h;                    // Computed Parameter: Out1_Y0_h
                                          //  Referenced by: '<S84>/Out1'

  real_T Out1_Y0_k;                    // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S86>/Out1'

};

// Parameters for system: '<S35>/RED+ARM'
struct P_REDARM_APF_CTL_VIS_Obs_2023_T_ {
  real_T Constant4_Value;              // Expression: pi/2
                                          //  Referenced by: '<S66>/Constant4'

  real_T Constant5_Value;              // Expression: pi/2
                                          //  Referenced by: '<S66>/Constant5'

  real_T Constant6_Value;              // Expression: 0
                                          //  Referenced by: '<S66>/Constant6'

  real_T Constant7_Value;              // Expression: 1
                                          //  Referenced by: '<S66>/Constant7'

  P_SimulatedPositionController_T SimulatedPositionController;// '<S66>/Simulated Position Controller' 
};

// Parameters for system: '<S87>/Sub-Phase #1'
struct P_SubPhase1_APF_CTL_VIS_Obs_2_T_ {
  real_T Out1_Y0;                      // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S103>/Out1'

  real_T Out1_Y0_a;                    // Computed Parameter: Out1_Y0_a
                                          //  Referenced by: '<S105>/Out1'

  real_T Out1_Y0_o;                    // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S107>/Out1'

  real_T DesiredRateBLACK_Value;       // Expression: 0.03490659
                                          //  Referenced by: '<S94>/Desired Rate (BLACK)'

  real_T PuckState_Value;              // Expression: 1
                                          //  Referenced by: '<S90>/Puck State'

};

// Parameters for system: '<S88>/Sub-Phase #1'
struct P_SubPhase1_APF_CTL_VIS_Obs_a_T_ {
  real_T Out1_Y0;                      // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S177>/Out1'

  real_T Out1_Y0_p;                    // Computed Parameter: Out1_Y0_p
                                          //  Referenced by: '<S179>/Out1'

  real_T Out1_Y0_j;                    // Computed Parameter: Out1_Y0_j
                                          //  Referenced by: '<S181>/Out1'

  real_T DesiredRate_Value;            // Expression: 0.03490659
                                          //  Referenced by: '<S165>/Desired Rate '

  real_T PuckState_Value;              // Expression: 1
                                          //  Referenced by: '<S161>/Puck State'

};

// Parameters for system: '<S89>/Sub-Phase #1'
struct P_SubPhase1_APF_CTL_VIS_Obs_h_T_ {
  real_T Out1_Y0;                      // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S258>/Out1'

  real_T Out1_Y0_c;                    // Computed Parameter: Out1_Y0_c
                                          //  Referenced by: '<S260>/Out1'

  real_T Out1_Y0_j;                    // Computed Parameter: Out1_Y0_j
                                          //  Referenced by: '<S262>/Out1'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S244>/Constant1'

  real_T DesiredRate_Value;            // Expression: 0.03490659
                                          //  Referenced by: '<S255>/Desired Rate '

  real_T Constant_Value;               // Expression: pi
                                          //  Referenced by: '<S255>/Constant'

  real_T PuckState_Value;              // Expression: 1
                                          //  Referenced by: '<S244>/Puck State'

  P_REDARM_APF_CTL_VIS_Obs_2023_T REDARM;// '<S244>/RED+ARM'
};

// Parameters for system: '<S349>/Target Tracker'
struct P_TargetTracker_APF_CTL_VIS_O_T_ {
  real_T Out1_Y0;                      // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S366>/Out1'

  real_T PseudoDerivative_A;           // Computed Parameter: PseudoDerivative_A
                                          //  Referenced by: '<S376>/Pseudo Derivative'

  real_T PseudoDerivative_C;           // Computed Parameter: PseudoDerivative_C
                                          //  Referenced by: '<S376>/Pseudo Derivative'

  real_T PseudoDerivative_D;           // Computed Parameter: PseudoDerivative_D
                                          //  Referenced by: '<S376>/Pseudo Derivative'

  real_T PseudoDerivative1_A;         // Computed Parameter: PseudoDerivative1_A
                                         //  Referenced by: '<S376>/Pseudo Derivative1'

  real_T PseudoDerivative1_C;         // Computed Parameter: PseudoDerivative1_C
                                         //  Referenced by: '<S376>/Pseudo Derivative1'

  real_T PseudoDerivative1_D;         // Computed Parameter: PseudoDerivative1_D
                                         //  Referenced by: '<S376>/Pseudo Derivative1'

  real_T PseudoDerivative2_A;         // Computed Parameter: PseudoDerivative2_A
                                         //  Referenced by: '<S376>/Pseudo Derivative2'

  real_T PseudoDerivative2_C;         // Computed Parameter: PseudoDerivative2_C
                                         //  Referenced by: '<S376>/Pseudo Derivative2'

  real_T PseudoDerivative2_D;         // Computed Parameter: PseudoDerivative2_D
                                         //  Referenced by: '<S376>/Pseudo Derivative2'

};

// Parameters for system: '<Root>/Phase #4: Return Home'
struct P_Phase4ReturnHome_APF_CTL_VI_T_ {
  real_T Out1_Y0;                      // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S443>/Out1'

  real_T Out1_Y0_d;                    // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S445>/Out1'

  real_T Out1_Y0_p;                    // Computed Parameter: Out1_Y0_p
                                          //  Referenced by: '<S447>/Out1'

  real_T PuckState_Value;              // Expression: 1
                                          //  Referenced by: '<S423>/Puck State'

  real_T Out1_Y0_o;                    // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S430>/Out1'

  real_T Out1_Y0_k;                    // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S432>/Out1'

  real_T Out1_Y0_dj;                   // Computed Parameter: Out1_Y0_dj
                                          //  Referenced by: '<S434>/Out1'

  real_T PuckState_Value_p;            // Expression: 1
                                          //  Referenced by: '<S422>/Puck State'

  real_T Out1_Y0_b;                    // Computed Parameter: Out1_Y0_b
                                          //  Referenced by: '<S457>/Out1'

  real_T Out1_Y0_b1;                   // Computed Parameter: Out1_Y0_b1
                                          //  Referenced by: '<S459>/Out1'

  real_T Out1_Y0_ba;                   // Computed Parameter: Out1_Y0_ba
                                          //  Referenced by: '<S461>/Out1'

  real_T Out1_Y0_c;                    // Computed Parameter: Out1_Y0_c
                                          //  Referenced by: '<S471>/Out1'

  real_T Out1_Y0_o0;                   // Computed Parameter: Out1_Y0_o0
                                          //  Referenced by: '<S473>/Out1'

  real_T Out1_Y0_a;                    // Computed Parameter: Out1_Y0_a
                                          //  Referenced by: '<S475>/Out1'

  real_T Constant1_Value;              // Expression: pi/2
                                          //  Referenced by: '<S455>/Constant1'

  real_T Constant6_Value;              // Expression: 0
                                          //  Referenced by: '<S455>/Constant6'

  real_T Constant7_Value;              // Expression: 1
                                          //  Referenced by: '<S455>/Constant7'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S424>/Constant2'

  real_T PuckState_Value_c;            // Expression: 1
                                          //  Referenced by: '<S424>/Puck State'

};

// Parameters (default storage)
struct P_APF_CTL_VIS_Obs_2023a_T_ {
  real_T Att_Mode;                     // Variable: Att_Mode
                                          //  Referenced by: '<S378>/Constant2'

  real_T BLACK_end[3];                 // Variable: BLACK_end
                                          //  Referenced by:
                                          //    '<S149>/End Pos'
                                          //    '<S150>/End Pos'
                                          //    '<S151>/End Pos'

  real_T BLACK_ini[6];                 // Variable: BLACK_ini
                                          //  Referenced by:
                                          //    '<S149>/Velocity'
                                          //    '<S149>/Start Pos'
                                          //    '<S150>/Velocity'
                                          //    '<S150>/Start Pos'
                                          //    '<S151>/Velocity'
                                          //    '<S151>/Start Pos'

  real_T BLUE_end[3];                  // Variable: BLUE_end
                                          //  Referenced by:
                                          //    '<S232>/End Time'
                                          //    '<S233>/End Time'
                                          //    '<S234>/End Time'

  real_T BLUE_ini[6];                  // Variable: BLUE_ini
                                          //  Referenced by:
                                          //    '<S232>/Velocity'
                                          //    '<S232>/Start Pos'
                                          //    '<S233>/Velocity'
                                          //    '<S233>/Start Pos'
                                          //    '<S234>/Velocity'
                                          //    '<S234>/Start Pos'

  real_T Binv[9];                      // Variable: Binv
                                          //  Referenced by:
                                          //    '<S382>/MATLAB Function'
                                          //    '<S392>/MATLAB Function1'

  real_T F_Black_X_nominal;            // Variable: F_Black_X_nominal
                                          //  Referenced by:
                                          //    '<S639>/MATLAB Function11'
                                          //    '<S639>/MATLAB Function3'

  real_T F_Black_Y_nominal;            // Variable: F_Black_Y_nominal
                                          //  Referenced by:
                                          //    '<S639>/MATLAB Function11'
                                          //    '<S639>/MATLAB Function3'

  real_T F_Blue_X_nominal;             // Variable: F_Blue_X_nominal
                                          //  Referenced by:
                                          //    '<S651>/MATLAB Function1'
                                          //    '<S651>/MATLAB Function7'

  real_T F_Blue_Y_nominal;             // Variable: F_Blue_Y_nominal
                                          //  Referenced by:
                                          //    '<S651>/MATLAB Function1'
                                          //    '<S651>/MATLAB Function7'

  real_T F_red_X_nominal;              // Variable: F_red_X_nominal
                                          //  Referenced by:
                                          //    '<S663>/MATLAB Function11'
                                          //    '<S663>/MATLAB Function4'
                                          //    '<S663>/MATLAB Function6'
                                          //    '<S663>/MATLAB Function7'

  real_T F_red_Y_nominal;              // Variable: F_red_Y_nominal
                                          //  Referenced by:
                                          //    '<S663>/MATLAB Function11'
                                          //    '<S663>/MATLAB Function4'
                                          //    '<S663>/MATLAB Function6'
                                          //    '<S663>/MATLAB Function7'

  real_T F_thrusters_BLACK[8];         // Variable: F_thrusters_BLACK
                                          //  Referenced by: '<S639>/MATLAB Function'

  real_T F_thrusters_BLUE[8];          // Variable: F_thrusters_BLUE
                                          //  Referenced by: '<S651>/MATLAB Function'

  real_T F_thrusters_RED[8];           // Variable: F_thrusters_RED
                                          //  Referenced by:
                                          //    '<S663>/MATLAB Function'
                                          //    '<S663>/MATLAB Function3'

  real_T Gamma1_el;                    // Variable: Gamma1_el
                                          //  Referenced by: '<S611>/Dynamics Model'

  real_T Gamma1_sh;                    // Variable: Gamma1_sh
                                          //  Referenced by: '<S611>/Dynamics Model'

  real_T Gamma1_wr;                    // Variable: Gamma1_wr
                                          //  Referenced by: '<S611>/Dynamics Model'

  real_T Gamma2_el;                    // Variable: Gamma2_el
                                          //  Referenced by: '<S611>/Dynamics Model'

  real_T Gamma2_sh;                    // Variable: Gamma2_sh
                                          //  Referenced by: '<S611>/Dynamics Model'

  real_T Gamma2_wr;                    // Variable: Gamma2_wr
                                          //  Referenced by: '<S611>/Dynamics Model'

  real_T Gamma3_el;                    // Variable: Gamma3_el
                                          //  Referenced by: '<S611>/Dynamics Model'

  real_T Gamma3_sh;                    // Variable: Gamma3_sh
                                          //  Referenced by: '<S611>/Dynamics Model'

  real_T Gamma3_wr;                    // Variable: Gamma3_wr
                                          //  Referenced by: '<S611>/Dynamics Model'

  real_T Gamma4_el;                    // Variable: Gamma4_el
                                          //  Referenced by: '<S611>/Dynamics Model'

  real_T Gamma4_sh;                    // Variable: Gamma4_sh
                                          //  Referenced by: '<S611>/Dynamics Model'

  real_T Gamma4_wr;                    // Variable: Gamma4_wr
                                          //  Referenced by: '<S611>/Dynamics Model'

  real_T Gamma5_el;                    // Variable: Gamma5_el
                                          //  Referenced by: '<S611>/Dynamics Model'

  real_T Gamma5_sh;                    // Variable: Gamma5_sh
                                          //  Referenced by: '<S611>/Dynamics Model'

  real_T Gamma5_wr;                    // Variable: Gamma5_wr
                                          //  Referenced by: '<S611>/Dynamics Model'

  real_T Gamma6_el;                    // Variable: Gamma6_el
                                          //  Referenced by: '<S611>/Dynamics Model'

  real_T Gamma6_sh;                    // Variable: Gamma6_sh
                                          //  Referenced by: '<S611>/Dynamics Model'

  real_T Gamma6_wr;                    // Variable: Gamma6_wr
                                          //  Referenced by: '<S611>/Dynamics Model'

  real_T H[18];                        // Variable: H
                                          //  Referenced by:
                                          //    '<S355>/MATLAB Function2'
                                          //    '<S360>/MATLAB Function2'

  real_T Hz;                           // Variable: Hz
                                          //  Referenced by: '<S379>/Switch logic'

  real_T IBLACK;                       // Variable: IBLACK
                                          //  Referenced by: '<S581>/MATLAB Function'

  real_T IBLUE;                        // Variable: IBLUE
                                          //  Referenced by: '<S595>/MATLAB Function'

  real_T IDIST;                        // Variable: IDIST
                                          //  Referenced by: '<S611>/Inertia Function 1'

  real_T IEE;                          // Variable: IEE
                                          //  Referenced by: '<S611>/Inertia Function 1'

  real_T IPROX;                        // Variable: IPROX
                                          //  Referenced by: '<S611>/Inertia Function 1'

  real_T IRED;                         // Variable: IRED
                                          //  Referenced by:
                                          //    '<S611>/Inertia Function 1'
                                          //    '<S622>/MATLAB Function'

  real_T J;                            // Variable: J
                                          //  Referenced by:
                                          //    '<S355>/MATLAB Function2'
                                          //    '<S360>/MATLAB Function2'

  real_T K_a[9];                       // Variable: K_a
                                          //  Referenced by:
                                          //    '<S382>/MATLAB Function'
                                          //    '<S392>/MATLAB Function1'

  real_T Kd_elarm;                     // Variable: Kd_elarm
                                          //  Referenced by:
                                          //    '<S78>/kd_elarm'
                                          //    '<S467>/kd_elarm'
                                          //    '<S521>/kd_elarm'
                                          //    '<S268>/kd_elarm'
                                          //    '<S301>/kd_elarm'
                                          //    '<S334>/kd_elarm'
                                          //    '<S413>/kd_elarm'

  real_T Kd_sharm;                     // Variable: Kd_sharm
                                          //  Referenced by:
                                          //    '<S79>/kd_sharm'
                                          //    '<S468>/kd_sharm'
                                          //    '<S522>/kd_sharm'
                                          //    '<S269>/kd_sharm'
                                          //    '<S302>/kd_sharm'
                                          //    '<S335>/kd_sharm'
                                          //    '<S414>/kd_sharm'

  real_T Kd_tb;                        // Variable: Kd_tb
                                          //  Referenced by:
                                          //    '<S36>/kd_tb'
                                          //    '<S425>/kd_tb'
                                          //    '<S479>/kd_tb'
                                          //    '<S95>/kd_tb'
                                          //    '<S112>/kd_tb'
                                          //    '<S129>/kd_tb'
                                          //    '<S145>/kd_tb'

  real_T Kd_tblue;                     // Variable: Kd_tblue
                                          //  Referenced by:
                                          //    '<S49>/kd_tb'
                                          //    '<S438>/kd_tb'
                                          //    '<S492>/kd_tb'
                                          //    '<S166>/kd_tb'
                                          //    '<S187>/kd_tb'
                                          //    '<S208>/kd_tb'
                                          //    '<S228>/kd_tb'

  real_T Kd_tr;                        // Variable: Kd_tr
                                          //  Referenced by:
                                          //    '<S62>/kd_tr'
                                          //    '<S451>/kd_tr'
                                          //    '<S505>/kd_tr'
                                          //    '<S248>/kd_tr'
                                          //    '<S281>/kd_tr'
                                          //    '<S314>/kd_tr'

  real_T Kd_wrarm;                     // Variable: Kd_wrarm
                                          //  Referenced by:
                                          //    '<S80>/kd_wrarm'
                                          //    '<S469>/kd_wrarm'
                                          //    '<S523>/kd_wrarm'
                                          //    '<S270>/kd_wrarm'
                                          //    '<S303>/kd_wrarm'
                                          //    '<S336>/kd_wrarm'
                                          //    '<S415>/kd_wrarm'

  real_T Kd_xb;                        // Variable: Kd_xb
                                          //  Referenced by:
                                          //    '<S37>/kd_xb'
                                          //    '<S426>/kd_xb'
                                          //    '<S480>/kd_xb'
                                          //    '<S96>/kd_xb'
                                          //    '<S113>/kd_xb'
                                          //    '<S130>/kd_xb'
                                          //    '<S146>/kd_xb'

  real_T Kd_xblue;                     // Variable: Kd_xblue
                                          //  Referenced by:
                                          //    '<S50>/kd_xb'
                                          //    '<S439>/kd_xb'
                                          //    '<S493>/kd_xb'
                                          //    '<S167>/kd_xb'
                                          //    '<S188>/kd_xb'
                                          //    '<S209>/kd_xb'
                                          //    '<S229>/kd_xb'

  real_T Kd_xr;                        // Variable: Kd_xr
                                          //  Referenced by:
                                          //    '<S63>/kd_xr'
                                          //    '<S452>/kd_xr'
                                          //    '<S506>/kd_xr'
                                          //    '<S249>/kd_xr'
                                          //    '<S282>/kd_xr'
                                          //    '<S315>/kd_xr'

  real_T Kd_yb;                        // Variable: Kd_yb
                                          //  Referenced by:
                                          //    '<S38>/kd_yb'
                                          //    '<S427>/kd_yb'
                                          //    '<S481>/kd_yb'
                                          //    '<S97>/kd_yb'
                                          //    '<S114>/kd_yb'
                                          //    '<S131>/kd_yb'
                                          //    '<S147>/kd_yb'

  real_T Kd_yblue;                     // Variable: Kd_yblue
                                          //  Referenced by:
                                          //    '<S51>/kd_yb'
                                          //    '<S440>/kd_yb'
                                          //    '<S494>/kd_yb'
                                          //    '<S168>/kd_yb'
                                          //    '<S189>/kd_yb'
                                          //    '<S210>/kd_yb'
                                          //    '<S230>/kd_yb'

  real_T Kd_yr;                        // Variable: Kd_yr
                                          //  Referenced by:
                                          //    '<S64>/kd_yr'
                                          //    '<S453>/kd_yr'
                                          //    '<S507>/kd_yr'
                                          //    '<S250>/kd_yr'
                                          //    '<S283>/kd_yr'
                                          //    '<S316>/kd_yr'

  real_T Kp_elarm;                     // Variable: Kp_elarm
                                          //  Referenced by:
                                          //    '<S78>/kp_elarm'
                                          //    '<S467>/kp_elarm'
                                          //    '<S521>/kp_elarm'
                                          //    '<S268>/kp_elarm'
                                          //    '<S301>/kp_elarm'
                                          //    '<S334>/kp_elarm'
                                          //    '<S413>/kp_elarm'

  real_T Kp_sharm;                     // Variable: Kp_sharm
                                          //  Referenced by:
                                          //    '<S79>/kp_sharm'
                                          //    '<S468>/kp_sharm'
                                          //    '<S522>/kp_sharm'
                                          //    '<S269>/kp_sharm'
                                          //    '<S302>/kp_sharm'
                                          //    '<S335>/kp_sharm'
                                          //    '<S414>/kp_sharm'

  real_T Kp_tb;                        // Variable: Kp_tb
                                          //  Referenced by:
                                          //    '<S36>/kp_tb'
                                          //    '<S425>/kp_tb'
                                          //    '<S479>/kp_tb'
                                          //    '<S95>/kp_tb'
                                          //    '<S112>/kp_tb'
                                          //    '<S129>/kp_tb'
                                          //    '<S145>/kp_tb'

  real_T Kp_tblue;                     // Variable: Kp_tblue
                                          //  Referenced by:
                                          //    '<S49>/kp_tb'
                                          //    '<S438>/kp_tb'
                                          //    '<S492>/kp_tb'
                                          //    '<S166>/kp_tb'
                                          //    '<S187>/kp_tb'
                                          //    '<S208>/kp_tb'
                                          //    '<S228>/kp_tb'

  real_T Kp_tr;                        // Variable: Kp_tr
                                          //  Referenced by:
                                          //    '<S62>/kp_tr'
                                          //    '<S451>/kp_tr'
                                          //    '<S505>/kp_tr'
                                          //    '<S248>/kp_tr'
                                          //    '<S281>/kp_tr'
                                          //    '<S314>/kp_tr'

  real_T Kp_wrarm;                     // Variable: Kp_wrarm
                                          //  Referenced by:
                                          //    '<S80>/kp_wrarm'
                                          //    '<S469>/kp_wrarm'
                                          //    '<S523>/kp_wrarm'
                                          //    '<S270>/kp_wrarm'
                                          //    '<S303>/kp_wrarm'
                                          //    '<S336>/kp_wrarm'
                                          //    '<S415>/kp_wrarm'

  real_T Kp_xb;                        // Variable: Kp_xb
                                          //  Referenced by:
                                          //    '<S37>/kp_xb'
                                          //    '<S426>/kp_xb'
                                          //    '<S480>/kp_xb'
                                          //    '<S96>/kp_xb'
                                          //    '<S113>/kp_xb'
                                          //    '<S130>/kp_xb'
                                          //    '<S146>/kp_xb'

  real_T Kp_xblue;                     // Variable: Kp_xblue
                                          //  Referenced by:
                                          //    '<S50>/kp_xb'
                                          //    '<S439>/kp_xb'
                                          //    '<S493>/kp_xb'
                                          //    '<S167>/kp_xb'
                                          //    '<S188>/kp_xb'
                                          //    '<S209>/kp_xb'
                                          //    '<S229>/kp_xb'

  real_T Kp_xr;                        // Variable: Kp_xr
                                          //  Referenced by:
                                          //    '<S63>/kp_xr'
                                          //    '<S452>/kp_xr'
                                          //    '<S506>/kp_xr'
                                          //    '<S249>/kp_xr'
                                          //    '<S282>/kp_xr'
                                          //    '<S315>/kp_xr'

  real_T Kp_yb;                        // Variable: Kp_yb
                                          //  Referenced by:
                                          //    '<S38>/kp_yb'
                                          //    '<S427>/kp_yb'
                                          //    '<S481>/kp_yb'
                                          //    '<S97>/kp_yb'
                                          //    '<S114>/kp_yb'
                                          //    '<S131>/kp_yb'
                                          //    '<S147>/kp_yb'

  real_T Kp_yblue;                     // Variable: Kp_yblue
                                          //  Referenced by:
                                          //    '<S51>/kp_yb'
                                          //    '<S440>/kp_yb'
                                          //    '<S494>/kp_yb'
                                          //    '<S168>/kp_yb'
                                          //    '<S189>/kp_yb'
                                          //    '<S210>/kp_yb'
                                          //    '<S230>/kp_yb'

  real_T Kp_yr;                        // Variable: Kp_yr
                                          //  Referenced by:
                                          //    '<S64>/kp_yr'
                                          //    '<S453>/kp_yr'
                                          //    '<S507>/kp_yr'
                                          //    '<S250>/kp_yr'
                                          //    '<S283>/kp_yr'
                                          //    '<S316>/kp_yr'

  real_T Method;                       // Variable: Method
                                          //  Referenced by: '<S385>/Constant3'

  real_T Nmat[9];                      // Variable: Nmat
                                          //  Referenced by:
                                          //    '<S382>/MATLAB Function'
                                          //    '<S392>/MATLAB Function1'

  real_T PWMFreq;                      // Variable: PWMFreq
                                          //  Referenced by:
                                          //    '<S19>/PWM Frequency'
                                          //    '<S639>/MATLAB Function1'
                                          //    '<S651>/MATLAB Function2'
                                          //    '<S663>/MATLAB Function2'

  real_T P_IC_Black[36];               // Variable: P_IC_Black
                                          //  Referenced by: '<S355>/IC'

  real_T P_IC_Blue[36];                // Variable: P_IC_Blue
                                          //  Referenced by: '<S360>/IC'

  real_T P_b[9];                       // Variable: P_b
                                          //  Referenced by:
                                          //    '<S382>/MATLAB Function'
                                          //    '<S392>/MATLAB Function1'

  real_T Phase0_End;                   // Variable: Phase0_End
                                          //  Referenced by: '<Root>/Constant4'

  real_T Phase1_End;                   // Variable: Phase1_End
                                          //  Referenced by: '<Root>/Constant'

  real_T Phase2_End;                   // Variable: Phase2_End
                                          //  Referenced by:
                                          //    '<Root>/Constant1'
                                          //    '<S172>/Constant2'
                                          //    '<S193>/Constant2'
                                          //    '<S214>/Constant2'
                                          //    '<S256>/Constant2'
                                          //    '<S289>/Constant2'
                                          //    '<S322>/Constant2'
                                          //    '<S99>/Constant1'
                                          //    '<S116>/Constant1'
                                          //    '<S133>/Constant1'
                                          //    '<S173>/Constant1'
                                          //    '<S194>/Constant1'
                                          //    '<S215>/Constant1'
                                          //    '<S277>/Constant1'
                                          //    '<S310>/Constant1'
                                          //    '<S343>/Constant1'
                                          //    '<S388>/Constant'

  real_T Phase3_End;                   // Variable: Phase3_End
                                          //  Referenced by: '<Root>/Constant2'

  real_T Phase3_SubPhase1_End;         // Variable: Phase3_SubPhase1_End
                                          //  Referenced by:
                                          //    '<S87>/Constant4'
                                          //    '<S88>/Constant4'
                                          //    '<S89>/Constant4'

  real_T Phase3_SubPhase2_End;         // Variable: Phase3_SubPhase2_End
                                          //  Referenced by:
                                          //    '<S87>/Constant1'
                                          //    '<S88>/Constant1'
                                          //    '<S89>/Constant1'

  real_T Phase3_SubPhase3_End;         // Variable: Phase3_SubPhase3_End
                                          //  Referenced by:
                                          //    '<S87>/Constant2'
                                          //    '<S88>/Constant2'
                                          //    '<S89>/Constant2'
                                          //    '<S405>/Constant1'

  real_T Phase3_SubPhase4_End;         // Variable: Phase3_SubPhase4_End
                                          //  Referenced by:
                                          //    '<S87>/Constant3'
                                          //    '<S88>/Constant3'
                                          //    '<S89>/Constant3'

  real_T Phase4_End;                   // Variable: Phase4_End
                                          //  Referenced by: '<Root>/Constant3'

  real_T Phase5_End;                   // Variable: Phase5_End
                                          //  Referenced by: '<Root>/Constant6'

  real_T Phi;                          // Variable: Phi
                                          //  Referenced by:
                                          //    '<S663>/MATLAB Function'
                                          //    '<S663>/MATLAB Function4'
                                          //    '<S663>/MATLAB Function6'
                                          //    '<S611>/Coriolis Function1'
                                          //    '<S611>/Inertia Function 1'

  real_T Q_Black[36];                  // Variable: Q_Black
                                          //  Referenced by: '<S355>/MATLAB Function2'

  real_T Q_Blue[36];                   // Variable: Q_Blue
                                          //  Referenced by: '<S360>/MATLAB Function2'

  real_T Q_a[9];                       // Variable: Q_a
                                          //  Referenced by:
                                          //    '<S382>/MATLAB Function'
                                          //    '<S392>/MATLAB Function1'

  real_T Q_b[9];                       // Variable: Q_b
                                          //  Referenced by:
                                          //    '<S382>/MATLAB Function'
                                          //    '<S392>/MATLAB Function1'

  real_T RED_ini[6];                   // Variable: RED_ini
                                          //  Referenced by:
                                          //    '<S403>/Constant'
                                          //    '<S404>/Constant1'
                                          //    '<S404>/Constant2'
                                          //    '<S409>/Constant1'
                                          //    '<S409>/Constant2'

  real_T RMSprop_epsilon;              // Variable: RMSprop_epsilon
                                          //  Referenced by: '<S393>/MATLAB Function1'

  real_T RMSprop_eta;                  // Variable: RMSprop_eta
                                          //  Referenced by: '<S393>/MATLAB Function1'

  real_T RMSprop_gamma;                // Variable: RMSprop_gamma
                                          //  Referenced by: '<S393>/MATLAB Function1'

  real_T R_Black[9];                   // Variable: R_Black
                                          //  Referenced by: '<S355>/MATLAB Function2'

  real_T R_Blue[9];                    // Variable: R_Blue
                                          //  Referenced by: '<S360>/MATLAB Function2'

  real_T Red_Rate;                     // Variable: Red_Rate
                                          //  Referenced by: '<S403>/Desired Rate (RED)'

  real_T Time_Look;                    // Variable: Time_Look
                                          //  Referenced by: '<S379>/Switch logic'

  real_T Tz_lim_elarm;                 // Variable: Tz_lim_elarm
                                          //  Referenced by:
                                          //    '<S77>/Saturation1'
                                          //    '<S466>/Saturation1'
                                          //    '<S520>/Saturation1'
                                          //    '<S267>/Saturation1'
                                          //    '<S300>/Saturation1'
                                          //    '<S333>/Saturation1'
                                          //    '<S412>/Saturation1'

  real_T Tz_lim_sharm;                 // Variable: Tz_lim_sharm
                                          //  Referenced by:
                                          //    '<S77>/Saturation'
                                          //    '<S466>/Saturation'
                                          //    '<S520>/Saturation'
                                          //    '<S267>/Saturation'
                                          //    '<S300>/Saturation'
                                          //    '<S333>/Saturation'
                                          //    '<S412>/Saturation'

  real_T Tz_lim_wrarm;                 // Variable: Tz_lim_wrarm
                                          //  Referenced by:
                                          //    '<S77>/Saturation3'
                                          //    '<S466>/Saturation3'
                                          //    '<S520>/Saturation3'
                                          //    '<S267>/Saturation3'
                                          //    '<S300>/Saturation3'
                                          //    '<S333>/Saturation3'
                                          //    '<S412>/Saturation3'

  real_T a1;                           // Variable: a1
                                          //  Referenced by:
                                          //    '<S663>/MATLAB Function'
                                          //    '<S663>/MATLAB Function4'
                                          //    '<S663>/MATLAB Function6'
                                          //    '<S611>/Coriolis Function1'
                                          //    '<S611>/Inertia Function 1'

  real_T a2;                           // Variable: a2
                                          //  Referenced by:
                                          //    '<S663>/MATLAB Function'
                                          //    '<S663>/MATLAB Function4'
                                          //    '<S663>/MATLAB Function6'
                                          //    '<S611>/Coriolis Function1'
                                          //    '<S611>/Inertia Function 1'

  real_T a3;                           // Variable: a3
                                          //  Referenced by:
                                          //    '<S663>/MATLAB Function'
                                          //    '<S663>/MATLAB Function4'
                                          //    '<S663>/MATLAB Function6'
                                          //    '<S611>/Coriolis Function1'
                                          //    '<S611>/Inertia Function 1'

  real_T adadelta_epsilon;             // Variable: adadelta_epsilon
                                          //  Referenced by: '<S386>/MATLAB Function1'

  real_T adadelta_gamma;               // Variable: adadelta_gamma
                                          //  Referenced by: '<S386>/MATLAB Function1'

  real_T adagrad_epsilon;              // Variable: adagrad_epsilon
                                          //  Referenced by: '<S387>/MATLAB Function1'

  real_T adagrad_eta;                  // Variable: adagrad_eta
                                          //  Referenced by: '<S387>/MATLAB Function1'

  real_T adam_beta_1;                  // Variable: adam_beta_1
                                          //  Referenced by: '<S389>/MATLAB Function1'

  real_T adam_beta_2;                  // Variable: adam_beta_2
                                          //  Referenced by: '<S389>/MATLAB Function1'

  real_T adam_epsilon;                 // Variable: adam_epsilon
                                          //  Referenced by: '<S389>/MATLAB Function1'

  real_T adam_eta;                     // Variable: adam_eta
                                          //  Referenced by: '<S389>/MATLAB Function1'

  real_T adamax_beta_1;                // Variable: adamax_beta_1
                                          //  Referenced by: '<S388>/MATLAB Function1'

  real_T adamax_beta_2;                // Variable: adamax_beta_2
                                          //  Referenced by: '<S388>/MATLAB Function1'

  real_T adamax_eta;                   // Variable: adamax_eta
                                          //  Referenced by: '<S388>/MATLAB Function1'

  real_T alpha_Black;                  // Variable: alpha_Black
                                          //  Referenced by: '<S355>/MATLAB Function2'

  real_T alpha_Blue;                   // Variable: alpha_Blue
                                          //  Referenced by: '<S360>/MATLAB Function2'

  real_T b0;                           // Variable: b0
                                          //  Referenced by:
                                          //    '<S663>/MATLAB Function'
                                          //    '<S663>/MATLAB Function4'
                                          //    '<S663>/MATLAB Function6'
                                          //    '<S611>/Coriolis Function1'
                                          //    '<S611>/Inertia Function 1'

  real_T b1;                           // Variable: b1
                                          //  Referenced by:
                                          //    '<S663>/MATLAB Function'
                                          //    '<S663>/MATLAB Function4'
                                          //    '<S663>/MATLAB Function6'
                                          //    '<S611>/Coriolis Function1'
                                          //    '<S611>/Inertia Function 1'

  real_T b2;                           // Variable: b2
                                          //  Referenced by:
                                          //    '<S663>/MATLAB Function'
                                          //    '<S663>/MATLAB Function4'
                                          //    '<S663>/MATLAB Function6'
                                          //    '<S611>/Coriolis Function1'
                                          //    '<S611>/Inertia Function 1'

  real_T b3;                           // Variable: b3
                                          //  Referenced by:
                                          //    '<S663>/MATLAB Function'
                                          //    '<S663>/MATLAB Function4'
                                          //    '<S663>/MATLAB Function6'
                                          //    '<S611>/Inertia Function 1'

  real_T baseRate;                     // Variable: baseRate
                                          //  Referenced by:
                                          //    '<S26>/Read Joint Positions using  Dynamixel Encoders'
                                          //    '<S575>/WhoAmI'
                                          //    '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'
                                          //    '<S537>/divide by delta T'
                                          //    '<S538>/divide by delta T'
                                          //    '<S539>/divide by delta T'
                                          //    '<S540>/divide by delta T'
                                          //    '<S541>/divide by delta T'
                                          //    '<S542>/divide by delta T'
                                          //    '<S543>/divide by delta T'
                                          //    '<S544>/divide by delta T'
                                          //    '<S545>/divide by delta T'
                                          //    '<S546>/divide by delta T'
                                          //    '<S547>/divide by delta T'
                                          //    '<S548>/divide by delta T'
                                          //    '<S549>/divide by delta T'
                                          //    '<S550>/divide by delta T'
                                          //    '<S551>/divide by delta T'
                                          //    '<S552>/divide by delta T'
                                          //    '<S553>/divide by delta T'
                                          //    '<S554>/divide by delta T'
                                          //    '<S582>/divide by delta T'
                                          //    '<S583>/divide by delta T'
                                          //    '<S584>/divide by delta T'
                                          //    '<S585>/divide by delta T'
                                          //    '<S586>/divide by delta T'
                                          //    '<S587>/divide by delta T'
                                          //    '<S596>/divide by delta T'
                                          //    '<S597>/divide by delta T'
                                          //    '<S598>/divide by delta T'
                                          //    '<S599>/divide by delta T'
                                          //    '<S600>/divide by delta T'
                                          //    '<S601>/divide by delta T'
                                          //    '<S40>/divide by delta T'
                                          //    '<S42>/divide by delta T'
                                          //    '<S44>/divide by delta T'
                                          //    '<S53>/divide by delta T'
                                          //    '<S55>/divide by delta T'
                                          //    '<S57>/divide by delta T'
                                          //    '<S67>/divide by delta T'
                                          //    '<S69>/divide by delta T'
                                          //    '<S71>/divide by delta T'
                                          //    '<S429>/divide by delta T'
                                          //    '<S431>/divide by delta T'
                                          //    '<S433>/divide by delta T'
                                          //    '<S442>/divide by delta T'
                                          //    '<S444>/divide by delta T'
                                          //    '<S446>/divide by delta T'
                                          //    '<S456>/divide by delta T'
                                          //    '<S458>/divide by delta T'
                                          //    '<S460>/divide by delta T'
                                          //    '<S483>/divide by delta T'
                                          //    '<S485>/divide by delta T'
                                          //    '<S487>/divide by delta T'
                                          //    '<S496>/divide by delta T'
                                          //    '<S498>/divide by delta T'
                                          //    '<S500>/divide by delta T'
                                          //    '<S510>/divide by delta T'
                                          //    '<S512>/divide by delta T'
                                          //    '<S514>/divide by delta T'
                                          //    '<S102>/divide by delta T'
                                          //    '<S104>/divide by delta T'
                                          //    '<S106>/divide by delta T'
                                          //    '<S119>/divide by delta T'
                                          //    '<S121>/divide by delta T'
                                          //    '<S123>/divide by delta T'
                                          //    '<S136>/divide by delta T'
                                          //    '<S138>/divide by delta T'
                                          //    '<S140>/divide by delta T'
                                          //    '<S152>/divide by delta T'
                                          //    '<S154>/divide by delta T'
                                          //    '<S156>/divide by delta T'
                                          //    '<S176>/divide by delta T'
                                          //    '<S178>/divide by delta T'
                                          //    '<S180>/divide by delta T'
                                          //    '<S197>/divide by delta T'
                                          //    '<S199>/divide by delta T'
                                          //    '<S201>/divide by delta T'
                                          //    '<S218>/divide by delta T'
                                          //    '<S220>/divide by delta T'
                                          //    '<S222>/divide by delta T'
                                          //    '<S235>/divide by delta T'
                                          //    '<S237>/divide by delta T'
                                          //    '<S239>/divide by delta T'
                                          //    '<S257>/divide by delta T'
                                          //    '<S259>/divide by delta T'
                                          //    '<S261>/divide by delta T'
                                          //    '<S290>/divide by delta T'
                                          //    '<S292>/divide by delta T'
                                          //    '<S294>/divide by delta T'
                                          //    '<S323>/divide by delta T'
                                          //    '<S325>/divide by delta T'
                                          //    '<S327>/divide by delta T'
                                          //    '<S615>/divide by delta T'
                                          //    '<S616>/divide by delta T'
                                          //    '<S617>/divide by delta T'
                                          //    '<S623>/divide by delta T'
                                          //    '<S624>/divide by delta T'
                                          //    '<S625>/divide by delta T'
                                          //    '<S626>/divide by delta T'
                                          //    '<S627>/divide by delta T'
                                          //    '<S628>/divide by delta T'
                                          //    '<S81>/divide by delta T'
                                          //    '<S83>/divide by delta T'
                                          //    '<S85>/divide by delta T'
                                          //    '<S470>/divide by delta T'
                                          //    '<S472>/divide by delta T'
                                          //    '<S474>/divide by delta T'
                                          //    '<S524>/divide by delta T'
                                          //    '<S526>/divide by delta T'
                                          //    '<S528>/divide by delta T'
                                          //    '<S271>/divide by delta T'
                                          //    '<S273>/divide by delta T'
                                          //    '<S275>/divide by delta T'
                                          //    '<S304>/divide by delta T'
                                          //    '<S306>/divide by delta T'
                                          //    '<S308>/divide by delta T'
                                          //    '<S337>/divide by delta T'
                                          //    '<S339>/divide by delta T'
                                          //    '<S341>/divide by delta T'
                                          //    '<S416>/divide by delta T'
                                          //    '<S418>/divide by delta T'
                                          //    '<S420>/divide by delta T'

  real_T batch_eta;                    // Variable: batch_eta
                                          //  Referenced by: '<S390>/Batch'

  real_T beta_Black;                   // Variable: beta_Black
                                          //  Referenced by: '<S355>/MATLAB Function2'

  real_T beta_Blue;                    // Variable: beta_Blue
                                          //  Referenced by: '<S360>/MATLAB Function2'

  real_T delta;                        // Variable: delta
                                          //  Referenced by:
                                          //    '<S347>/Ryan's Transform'
                                          //    '<S348>/Ryan's Transform'

  real_T drop_states_BLACK[3];         // Variable: drop_states_BLACK
                                          //  Referenced by: '<S581>/Velocity to Position'

  real_T drop_states_BLUE[3];          // Variable: drop_states_BLUE
                                          //  Referenced by: '<S595>/Velocity to Position'

  real_T drop_states_RED[3];           // Variable: drop_states_RED
                                          //  Referenced by: '<S622>/Velocity to Position'

  real_T dt;                           // Variable: dt
                                          //  Referenced by:
                                          //    '<S355>/MATLAB Function2'
                                          //    '<S360>/MATLAB Function2'

  real_T end_time_black;               // Variable: end_time_black
                                          //  Referenced by:
                                          //    '<S149>/End Time'
                                          //    '<S150>/End Time'
                                          //    '<S151>/End Time'

  real_T end_time_blue;                // Variable: end_time_blue
                                          //  Referenced by:
                                          //    '<S232>/End Pos'
                                          //    '<S233>/End Pos'
                                          //    '<S234>/End Pos'

  real_T home_states_BLACK[3];         // Variable: home_states_BLACK
                                          //  Referenced by:
                                          //    '<S422>/Desired Attitude (BLACK)'
                                          //    '<S422>/Desired Px (BLACK)'
                                          //    '<S422>/Desired Py (BLACK)'
                                          //    '<S476>/Desired Attitude (BLACK)'
                                          //    '<S476>/Desired Px (BLACK)'
                                          //    '<S476>/Desired Py (BLACK)'

  real_T home_states_BLUE[3];          // Variable: home_states_BLUE
                                          //  Referenced by:
                                          //    '<S423>/Desired Attitude (BLUE)'
                                          //    '<S423>/Desired Px (BLUE)'
                                          //    '<S423>/Desired Py (BLUE)'
                                          //    '<S477>/Desired Attitude (BLUE)'
                                          //    '<S477>/Desired Px (BLUE)'
                                          //    '<S477>/Desired Py (BLUE)'

  real_T home_states_RED[3];           // Variable: home_states_RED
                                          //  Referenced by:
                                          //    '<S424>/Desired Px (RED)'
                                          //    '<S424>/Desired Py (RED)'
                                          //    '<S424>/Desired Rz (RED)'
                                          //    '<S478>/Desired Px (RED)'
                                          //    '<S478>/Desired Py (RED)'
                                          //    '<S478>/Desired Rz (RED)'

  real_T init_states_BLACK[3];         // Variable: init_states_BLACK
                                          //  Referenced by:
                                          //    '<S33>/Desired Attitude (BLACK)'
                                          //    '<S33>/Desired Px (BLACK)'
                                          //    '<S33>/Desired Py (BLACK)'

  real_T init_states_BLUE[3];          // Variable: init_states_BLUE
                                          //  Referenced by:
                                          //    '<S34>/Desired Attitude (BLUE)'
                                          //    '<S34>/Desired Px (BLUE)'
                                          //    '<S34>/Desired Py (BLUE)'

  real_T init_states_RED[3];           // Variable: init_states_RED
                                          //  Referenced by:
                                          //    '<S35>/Constant'
                                          //    '<S35>/Constant1'
                                          //    '<S35>/Constant3'

  real_T k[18];                        // Variable: k
                                          //  Referenced by:
                                          //    '<S374>/Constant'
                                          //    '<S376>/Constant'

  real_T k_1_0;                        // Variable: k_1_0
                                          //  Referenced by:
                                          //    '<S370>/Discrete-Time Integrator3'
                                          //    '<S370>/Discrete-Time Integrator5'

  real_T k_1_t_0;                      // Variable: k_1_t_0
                                          //  Referenced by: '<S370>/Discrete-Time Integrator1'

  real_T k_2_0;                        // Variable: k_2_0
                                          //  Referenced by:
                                          //    '<S370>/Discrete-Time Integrator2'
                                          //    '<S370>/Discrete-Time Integrator4'

  real_T k_2_t_0;                      // Variable: k_2_t_0
                                          //  Referenced by: '<S370>/Discrete-Time Integrator'

  real_T ka;                           // Variable: ka
                                          //  Referenced by:
                                          //    '<S382>/MATLAB Function'
                                          //    '<S392>/MATLAB Function1'

  real_T kr;                           // Variable: kr
                                          //  Referenced by:
                                          //    '<S382>/MATLAB Function'
                                          //    '<S392>/MATLAB Function1'

  real_T lambda1;                      // Variable: lambda1
                                          //  Referenced by:
                                          //    '<S370>/Fx Gain Derivatives'
                                          //    '<S370>/Fy Gain Derivatives'

  real_T lambda12;                     // Variable: lambda12
                                          //  Referenced by:
                                          //    '<S370>/Fx Gain Derivatives'
                                          //    '<S370>/Fy Gain Derivatives'

  real_T lambda12_t;                   // Variable: lambda12_t
                                          //  Referenced by: '<S370>/Torque Gain Derivatives'

  real_T lambda1_t;                    // Variable: lambda1_t
                                          //  Referenced by: '<S370>/Torque Gain Derivatives'

  real_T lambda2;                      // Variable: lambda2
                                          //  Referenced by:
                                          //    '<S370>/Fx Gain Derivatives'
                                          //    '<S370>/Fy Gain Derivatives'

  real_T lambda2_t;                    // Variable: lambda2_t
                                          //  Referenced by: '<S370>/Torque Gain Derivatives'

  real_T lamda_Black;                  // Variable: lamda_Black
                                          //  Referenced by: '<S355>/MATLAB Function2'

  real_T lamda_Blue;                   // Variable: lamda_Blue
                                          //  Referenced by: '<S360>/MATLAB Function2'

  real_T m;                            // Variable: m
                                          //  Referenced by:
                                          //    '<S355>/MATLAB Function2'
                                          //    '<S360>/MATLAB Function2'

  real_T mBLACK;                       // Variable: mBLACK
                                          //  Referenced by: '<S581>/MATLAB Function'

  real_T mBLUE;                        // Variable: mBLUE
                                          //  Referenced by: '<S595>/MATLAB Function'

  real_T mDIST;                        // Variable: mDIST
                                          //  Referenced by:
                                          //    '<S663>/MATLAB Function'
                                          //    '<S663>/MATLAB Function4'
                                          //    '<S663>/MATLAB Function6'
                                          //    '<S611>/Coriolis Function1'
                                          //    '<S611>/Inertia Function 1'

  real_T mEE;                          // Variable: mEE
                                          //  Referenced by:
                                          //    '<S663>/MATLAB Function'
                                          //    '<S663>/MATLAB Function4'
                                          //    '<S663>/MATLAB Function6'
                                          //    '<S611>/Coriolis Function1'
                                          //    '<S611>/Inertia Function 1'

  real_T mPROX;                        // Variable: mPROX
                                          //  Referenced by:
                                          //    '<S663>/MATLAB Function'
                                          //    '<S663>/MATLAB Function4'
                                          //    '<S663>/MATLAB Function6'
                                          //    '<S611>/Coriolis Function1'
                                          //    '<S611>/Inertia Function 1'

  real_T mRED;                         // Variable: mRED
                                          //  Referenced by:
                                          //    '<S663>/MATLAB Function'
                                          //    '<S663>/MATLAB Function4'
                                          //    '<S663>/MATLAB Function6'
                                          //    '<S611>/Inertia Function 1'
                                          //    '<S622>/MATLAB Function'

  real_T method;                       // Variable: method
                                          //  Referenced by:
                                          //    '<S355>/MATLAB Function2'
                                          //    '<S360>/MATLAB Function2'

  real_T momentum_eta;                 // Variable: momentum_eta
                                          //  Referenced by: '<S391>/Momentum'

  real_T momentum_gamma;               // Variable: momentum_gamma
                                          //  Referenced by: '<S391>/Momentum'

  real_T nesterov_eta;                 // Variable: nesterov_eta
                                          //  Referenced by: '<S392>/MATLAB Function1'

  real_T nesterov_gamma;               // Variable: nesterov_gamma
                                          //  Referenced by: '<S392>/MATLAB Function1'

  real_T noise_variance_BLACK;         // Variable: noise_variance_BLACK
                                          //  Referenced by: '<S581>/Random Number'

  real_T noise_variance_BLUE;          // Variable: noise_variance_BLUE
                                          //  Referenced by: '<S595>/Random Number'

  real_T noise_variance_RED;           // Variable: noise_variance_RED
                                          //  Referenced by: '<S622>/Random Number'

  real_T p;                            // Variable: p
                                          //  Referenced by:
                                          //    '<S370>/Fx Gain Derivatives'
                                          //    '<S370>/Fy Gain Derivatives'

  real_T p_t;                          // Variable: p_t
                                          //  Referenced by: '<S370>/Torque Gain Derivatives'

  real_T platformSelection;            // Variable: platformSelection
                                          //  Referenced by:
                                          //    '<S35>/Constant4'
                                          //    '<S424>/Constant4'
                                          //    '<S478>/Constant4'
                                          //    '<S534>/MATLAB Function'
                                          //    '<S580>/Constant'
                                          //    '<S244>/Constant4'
                                          //    '<S245>/Constant4'
                                          //    '<S246>/Constant1'
                                          //    '<S247>/Constant3'
                                          //    '<S663>/Constant'
                                          //    '<S663>/Constant1'
                                          //    '<S663>/Constant2'

  real_T psi;                          // Variable: psi
                                          //  Referenced by:
                                          //    '<S382>/MATLAB Function'
                                          //    '<S392>/MATLAB Function1'

  real_T r_hold;                       // Variable: r_hold
                                          //  Referenced by:
                                          //    '<S382>/MATLAB Function'
                                          //    '<S392>/MATLAB Function1'

  real_T r_off;                        // Variable: r_off
                                          //  Referenced by:
                                          //    '<S378>/Looking Angle'
                                          //    '<S382>/MATLAB Function'
                                          //    '<S408>/Looking Angle'
                                          //    '<S392>/MATLAB Function1'

  real_T shape[5];                     // Variable: shape
                                          //  Referenced by:
                                          //    '<S382>/MATLAB Function'
                                          //    '<S392>/MATLAB Function1'

  real_T sigma;                        // Variable: sigma
                                          //  Referenced by:
                                          //    '<S382>/MATLAB Function'
                                          //    '<S392>/MATLAB Function1'

  real_T simMode;                      // Variable: simMode
                                          //  Referenced by: '<S18>/Constant'

  real_T thresh_Black;                 // Variable: thresh_Black
                                          //  Referenced by: '<S355>/MATLAB Function2'

  real_T thresh_Blue;                  // Variable: thresh_Blue
                                          //  Referenced by: '<S360>/MATLAB Function2'

  real_T thresh_Factor_Black;          // Variable: thresh_Factor_Black
                                          //  Referenced by: '<S355>/MATLAB Function2'

  real_T thresh_Factor_Blue;           // Variable: thresh_Factor_Blue
                                          //  Referenced by: '<S360>/MATLAB Function2'

  real_T thruster_count_threshold;     // Variable: thruster_count_threshold
                                          //  Referenced by:
                                          //    '<S639>/MATLAB Function10'
                                          //    '<S651>/MATLAB Function6'
                                          //    '<S663>/MATLAB Function5'

  real_T thruster_dist2CG_BLACK[8];    // Variable: thruster_dist2CG_BLACK
                                          //  Referenced by:
                                          //    '<S639>/MATLAB Function'
                                          //    '<S639>/MATLAB Function11'
                                          //    '<S639>/MATLAB Function3'

  real_T thruster_dist2CG_BLUE[8];     // Variable: thruster_dist2CG_BLUE
                                          //  Referenced by:
                                          //    '<S651>/MATLAB Function'
                                          //    '<S651>/MATLAB Function1'
                                          //    '<S651>/MATLAB Function7'

  real_T thruster_dist2CG_RED[8];      // Variable: thruster_dist2CG_RED
                                          //  Referenced by:
                                          //    '<S663>/MATLAB Function'
                                          //    '<S663>/MATLAB Function11'
                                          //    '<S663>/MATLAB Function3'
                                          //    '<S663>/MATLAB Function4'
                                          //    '<S663>/MATLAB Function6'
                                          //    '<S663>/MATLAB Function7'

  real_T xLength;                      // Variable: xLength
                                          //  Referenced by:
                                          //    '<S90>/Desired X-Position (BLACK)'
                                          //    '<S91>/Desired X-Position (BLACK)'
                                          //    '<S92>/Desired X-Position (BLACK)'
                                          //    '<S161>/MATLAB Function2'
                                          //    '<S162>/MATLAB Function2'
                                          //    '<S163>/MATLAB Function2'
                                          //    '<S244>/MATLAB Function'
                                          //    '<S245>/MATLAB Function'
                                          //    '<S246>/MATLAB Function'

  real_T yLength;                      // Variable: yLength
                                          //  Referenced by:
                                          //    '<S90>/Desired Y-Position (BLACK)'
                                          //    '<S91>/Desired Y-Position (BLACK)'
                                          //    '<S92>/Desired Y-Position (BLACK)'
                                          //    '<S161>/MATLAB Function3'
                                          //    '<S162>/MATLAB Function3'
                                          //    '<S163>/MATLAB Function3'
                                          //    '<S244>/MATLAB Function1'
                                          //    '<S245>/MATLAB Function1'
                                          //    '<S246>/MATLAB Function1'

  real_T SetPin428PuckstoHIGH_gpioPin; // Expression: 428
                                          //  Referenced by: '<S25>/Set Pin 428 (Pucks) to HIGH'

  real_T SetPin428PuckstoHIGH_pinDirecti;// Expression: 1
                                            //  Referenced by: '<S25>/Set Pin 428 (Pucks) to HIGH'

  real_T Out1_Y0;                      // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S589>/Out1'

  real_T Out1_Y0_a;                    // Computed Parameter: Out1_Y0_a
                                          //  Referenced by: '<S590>/Out1'

  real_T Out1_Y0_g;                    // Computed Parameter: Out1_Y0_g
                                          //  Referenced by: '<S591>/Out1'

  real_T Out1_Y0_gc;                   // Computed Parameter: Out1_Y0_gc
                                          //  Referenced by: '<S592>/Out1'

  real_T Out1_Y0_e;                    // Computed Parameter: Out1_Y0_e
                                          //  Referenced by: '<S593>/Out1'

  real_T Out1_Y0_n;                    // Computed Parameter: Out1_Y0_n
                                          //  Referenced by: '<S594>/Out1'

  real_T Out1_Y0_o;                    // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S603>/Out1'

  real_T Out1_Y0_ow;                   // Computed Parameter: Out1_Y0_ow
                                          //  Referenced by: '<S604>/Out1'

  real_T Out1_Y0_as;                   // Computed Parameter: Out1_Y0_as
                                          //  Referenced by: '<S605>/Out1'

  real_T Out1_Y0_ox;                   // Computed Parameter: Out1_Y0_ox
                                          //  Referenced by: '<S606>/Out1'

  real_T Out1_Y0_e3;                   // Computed Parameter: Out1_Y0_e3
                                          //  Referenced by: '<S607>/Out1'

  real_T Out1_Y0_i;                    // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S608>/Out1'

  real_T Out1_Y0_b;                    // Computed Parameter: Out1_Y0_b
                                          //  Referenced by: '<S618>/Out1'

  real_T Out1_Y0_asw;                  // Computed Parameter: Out1_Y0_asw
                                          //  Referenced by: '<S619>/Out1'

  real_T Out1_Y0_ea;                   // Computed Parameter: Out1_Y0_ea
                                          //  Referenced by: '<S620>/Out1'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S611>/Delay'

  real_T AccelerationtoVelocity_gainval;
                           // Computed Parameter: AccelerationtoVelocity_gainval
                              //  Referenced by: '<S611>/Acceleration  to Velocity'

  real_T AccelerationtoVelocity_IC[12];
                    // Expression: [drop_states_RED,drop_states_ARM,0,0,0,0,0,0]
                       //  Referenced by: '<S611>/Acceleration  to Velocity'

  real_T RandomNumber2_Mean;           // Expression: 0
                                          //  Referenced by: '<S611>/Random Number2'

  real_T RandomNumber2_StdDev;       // Computed Parameter: RandomNumber2_StdDev
                                        //  Referenced by: '<S611>/Random Number2'

  real_T RandomNumber2_Seed;           // Expression: 0
                                          //  Referenced by: '<S611>/Random Number2'

  real_T RandomNumber1_Mean;           // Expression: 0
                                          //  Referenced by: '<S611>/Random Number1'

  real_T RandomNumber1_StdDev;       // Computed Parameter: RandomNumber1_StdDev
                                        //  Referenced by: '<S611>/Random Number1'

  real_T RandomNumber1_Seed;           // Expression: 0
                                          //  Referenced by: '<S611>/Random Number1'

  real_T RandomNumber3_Mean;           // Expression: 0
                                          //  Referenced by: '<S611>/Random Number3'

  real_T RandomNumber3_StdDev;       // Computed Parameter: RandomNumber3_StdDev
                                        //  Referenced by: '<S611>/Random Number3'

  real_T RandomNumber3_Seed;           // Expression: 0
                                          //  Referenced by: '<S611>/Random Number3'

  real_T Out1_Y0_j;                    // Computed Parameter: Out1_Y0_j
                                          //  Referenced by: '<S630>/Out1'

  real_T Out1_Y0_l;                    // Computed Parameter: Out1_Y0_l
                                          //  Referenced by: '<S631>/Out1'

  real_T Out1_Y0_d;                    // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S632>/Out1'

  real_T Out1_Y0_bf;                   // Computed Parameter: Out1_Y0_bf
                                          //  Referenced by: '<S633>/Out1'

  real_T Out1_Y0_gt;                   // Computed Parameter: Out1_Y0_gt
                                          //  Referenced by: '<S634>/Out1'

  real_T Out1_Y0_em;                   // Computed Parameter: Out1_Y0_em
                                          //  Referenced by: '<S635>/Out1'

  real_T AccelerationtoVelocity_gainva_g;
                          // Computed Parameter: AccelerationtoVelocity_gainva_g
                             //  Referenced by: '<S622>/Acceleration  to Velocity'

  real_T AccelerationtoVelocity_IC_n;  // Expression: 0
                                          //  Referenced by: '<S622>/Acceleration  to Velocity'

  real_T VelocitytoPosition_gainval;
                               // Computed Parameter: VelocitytoPosition_gainval
                                  //  Referenced by: '<S622>/Velocity to Position'

  real_T RandomNumber_Mean;            // Expression: 0
                                          //  Referenced by: '<S622>/Random Number'

  real_T RandomNumber_Seed;            // Expression: 0
                                          //  Referenced by: '<S622>/Random Number'

  real_T RandomNumber7_Mean;           // Expression: 0
                                          //  Referenced by: '<S621>/Random Number7'

  real_T RandomNumber7_StdDev;       // Computed Parameter: RandomNumber7_StdDev
                                        //  Referenced by: '<S621>/Random Number7'

  real_T RandomNumber7_Seed;           // Expression: 0
                                          //  Referenced by: '<S621>/Random Number7'

  real_T RandomNumber6_Mean;           // Expression: 0
                                          //  Referenced by: '<S621>/Random Number6'

  real_T RandomNumber6_StdDev;       // Computed Parameter: RandomNumber6_StdDev
                                        //  Referenced by: '<S621>/Random Number6'

  real_T RandomNumber6_Seed;           // Expression: 0
                                          //  Referenced by: '<S621>/Random Number6'

  real_T RandomNumber8_Mean;           // Expression: 0
                                          //  Referenced by: '<S621>/Random Number8'

  real_T RandomNumber8_StdDev;       // Computed Parameter: RandomNumber8_StdDev
                                        //  Referenced by: '<S621>/Random Number8'

  real_T RandomNumber8_Seed;           // Expression: 0
                                          //  Referenced by: '<S621>/Random Number8'

  real_T AccelerationtoVelocity_gainva_j;
                          // Computed Parameter: AccelerationtoVelocity_gainva_j
                             //  Referenced by: '<S581>/Acceleration  to Velocity'

  real_T AccelerationtoVelocity_IC_p;  // Expression: 0
                                          //  Referenced by: '<S581>/Acceleration  to Velocity'

  real_T VelocitytoPosition_gainval_n;
                             // Computed Parameter: VelocitytoPosition_gainval_n
                                //  Referenced by: '<S581>/Velocity to Position'

  real_T RandomNumber_Mean_d;          // Expression: 0
                                          //  Referenced by: '<S581>/Random Number'

  real_T RandomNumber_Seed_g;          // Expression: 0
                                          //  Referenced by: '<S581>/Random Number'

  real_T RandomNumber1_Mean_j;         // Expression: 0
                                          //  Referenced by: '<S578>/Random Number1'

  real_T RandomNumber1_StdDev_e;   // Computed Parameter: RandomNumber1_StdDev_e
                                      //  Referenced by: '<S578>/Random Number1'

  real_T RandomNumber1_Seed_j;         // Expression: 0
                                          //  Referenced by: '<S578>/Random Number1'

  real_T RandomNumber_Mean_g;          // Expression: 0
                                          //  Referenced by: '<S578>/Random Number'

  real_T RandomNumber_StdDev;         // Computed Parameter: RandomNumber_StdDev
                                         //  Referenced by: '<S578>/Random Number'

  real_T RandomNumber_Seed_d;          // Expression: 0
                                          //  Referenced by: '<S578>/Random Number'

  real_T RandomNumber2_Mean_b;         // Expression: 0
                                          //  Referenced by: '<S578>/Random Number2'

  real_T RandomNumber2_StdDev_c;   // Computed Parameter: RandomNumber2_StdDev_c
                                      //  Referenced by: '<S578>/Random Number2'

  real_T RandomNumber2_Seed_g;         // Expression: 0
                                          //  Referenced by: '<S578>/Random Number2'

  real_T AccelerationtoVelocity_gainva_p;
                          // Computed Parameter: AccelerationtoVelocity_gainva_p
                             //  Referenced by: '<S595>/Acceleration  to Velocity'

  real_T AccelerationtoVelocity_IC_e;  // Expression: 0
                                          //  Referenced by: '<S595>/Acceleration  to Velocity'

  real_T VelocitytoPosition_gainval_e;
                             // Computed Parameter: VelocitytoPosition_gainval_e
                                //  Referenced by: '<S595>/Velocity to Position'

  real_T RandomNumber_Mean_dq;         // Expression: 0
                                          //  Referenced by: '<S595>/Random Number'

  real_T RandomNumber_Seed_p;          // Expression: 0
                                          //  Referenced by: '<S595>/Random Number'

  real_T RandomNumber4_Mean;           // Expression: 0
                                          //  Referenced by: '<S579>/Random Number4'

  real_T RandomNumber4_StdDev;       // Computed Parameter: RandomNumber4_StdDev
                                        //  Referenced by: '<S579>/Random Number4'

  real_T RandomNumber4_Seed;           // Expression: 0
                                          //  Referenced by: '<S579>/Random Number4'

  real_T RandomNumber3_Mean_i;         // Expression: 0
                                          //  Referenced by: '<S579>/Random Number3'

  real_T RandomNumber3_StdDev_n;   // Computed Parameter: RandomNumber3_StdDev_n
                                      //  Referenced by: '<S579>/Random Number3'

  real_T RandomNumber3_Seed_m;         // Expression: 0
                                          //  Referenced by: '<S579>/Random Number3'

  real_T RandomNumber5_Mean;           // Expression: 0
                                          //  Referenced by: '<S579>/Random Number5'

  real_T RandomNumber5_StdDev;       // Computed Parameter: RandomNumber5_StdDev
                                        //  Referenced by: '<S579>/Random Number5'

  real_T RandomNumber5_Seed;           // Expression: 0
                                          //  Referenced by: '<S579>/Random Number5'

  real_T Delay_InitialCondition_f;     // Expression: 0.0
                                          //  Referenced by: '<S26>/Delay'

  real_T Delay1_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S26>/Delay1'

  real_T Delay2_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S26>/Delay2'

  real_T Out1_Y0_m;                    // Computed Parameter: Out1_Y0_m
                                          //  Referenced by: '<S555>/Out1'

  real_T Memory_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<S555>/Memory'

  real_T Out1_Y0_ei;                   // Computed Parameter: Out1_Y0_ei
                                          //  Referenced by: '<S556>/Out1'

  real_T Out1_Y0_lf;                   // Computed Parameter: Out1_Y0_lf
                                          //  Referenced by: '<S557>/Out1'

  real_T Out1_Y0_f;                    // Computed Parameter: Out1_Y0_f
                                          //  Referenced by: '<S558>/Out1'

  real_T Out1_Y0_m3;                   // Computed Parameter: Out1_Y0_m3
                                          //  Referenced by: '<S559>/Out1'

  real_T Out1_Y0_m34;                  // Computed Parameter: Out1_Y0_m34
                                          //  Referenced by: '<S560>/Out1'

  real_T Out1_Y0_h;                    // Computed Parameter: Out1_Y0_h
                                          //  Referenced by: '<S561>/Out1'

  real_T Out1_Y0_o3;                   // Computed Parameter: Out1_Y0_o3
                                          //  Referenced by: '<S562>/Out1'

  real_T Out1_Y0_p;                    // Computed Parameter: Out1_Y0_p
                                          //  Referenced by: '<S563>/Out1'

  real_T Out1_Y0_hp;                   // Computed Parameter: Out1_Y0_hp
                                          //  Referenced by: '<S564>/Out1'

  real_T Out1_Y0_p0;                   // Computed Parameter: Out1_Y0_p0
                                          //  Referenced by: '<S565>/Out1'

  real_T Out1_Y0_iy;                   // Computed Parameter: Out1_Y0_iy
                                          //  Referenced by: '<S566>/Out1'

  real_T Out1_Y0_c;                    // Computed Parameter: Out1_Y0_c
                                          //  Referenced by: '<S567>/Out1'

  real_T Out1_Y0_d0;                   // Computed Parameter: Out1_Y0_d0
                                          //  Referenced by: '<S568>/Out1'

  real_T Out1_Y0_ck;                   // Computed Parameter: Out1_Y0_ck
                                          //  Referenced by: '<S569>/Out1'

  real_T Out1_Y0_ii;                   // Computed Parameter: Out1_Y0_ii
                                          //  Referenced by: '<S570>/Out1'

  real_T Out1_Y0_l2;                   // Computed Parameter: Out1_Y0_l2
                                          //  Referenced by: '<S571>/Out1'

  real_T Out1_Y0_nz;                   // Computed Parameter: Out1_Y0_nz
                                          //  Referenced by: '<S572>/Out1'

  real_T Out1_Y0_fr;                   // Computed Parameter: Out1_Y0_fr
                                          //  Referenced by: '<S573>/Out1'

  real_T Out1_Y0_e1;                   // Computed Parameter: Out1_Y0_e1
                                          //  Referenced by: '<S574>/Out1'

  real_T ConvertREDXfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S534>/Convert REDX from [mm] to [m]'

  real_T ConvertBLUXfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S534>/Convert BLUX from [mm] to [m]'

  real_T ConvertBLAXfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S534>/Convert BLAX from [mm] to [m]'

  real_T ConvertBLAYfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S534>/Convert BLAY from [mm] to [m]'

  real_T ConvertBLUYfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S534>/Convert BLUY from [mm] to [m]'

  real_T ConvertREDYfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S534>/Convert REDY from [mm] to [m]'

  real_T Constant_Value;               // Expression: 1
                                          //  Referenced by: '<S535>/Constant'

  real_T ControlDynamixelActuatorsineith;// Expression: 400
                                            //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_c;// Expression: 0
                                            //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_d;// Expression: 200
                                            //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_n;// Expression: 3072
                                            //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_g;// Expression: 1024
                                            //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsine_cw;// Expression: 0
                                            //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_e;// Expression: 850
                                            //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_k;// Expression: 400
                                            //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_j;// Expression: 100
                                            //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_l;// Expression: 50
                                            //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_o;// Expression: 0
                                            //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T Out1_Y0_nj;                   // Computed Parameter: Out1_Y0_nj
                                          //  Referenced by: '<S54>/Out1'

  real_T Out1_Y0_bq;                   // Computed Parameter: Out1_Y0_bq
                                          //  Referenced by: '<S56>/Out1'

  real_T Out1_Y0_c1;                   // Computed Parameter: Out1_Y0_c1
                                          //  Referenced by: '<S58>/Out1'

  real_T PuckState_Value;              // Expression: 1
                                          //  Referenced by: '<S34>/Puck State'

  real_T Out1_Y0_gf;                   // Computed Parameter: Out1_Y0_gf
                                          //  Referenced by: '<S41>/Out1'

  real_T Out1_Y0_nx;                   // Computed Parameter: Out1_Y0_nx
                                          //  Referenced by: '<S43>/Out1'

  real_T Out1_Y0_g4;                   // Computed Parameter: Out1_Y0_g4
                                          //  Referenced by: '<S45>/Out1'

  real_T PuckState_Value_o;            // Expression: 1
                                          //  Referenced by: '<S33>/Puck State'

  real_T Out1_Y0_hs;                   // Computed Parameter: Out1_Y0_hs
                                          //  Referenced by: '<S68>/Out1'

  real_T Out1_Y0_cr;                   // Computed Parameter: Out1_Y0_cr
                                          //  Referenced by: '<S70>/Out1'

  real_T Out1_Y0_dg;                   // Computed Parameter: Out1_Y0_dg
                                          //  Referenced by: '<S72>/Out1'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S35>/Constant2'

  real_T PuckState_Value_h;            // Expression: 1
                                          //  Referenced by: '<S35>/Puck State'

  real_T Out1_Y0_am;                   // Computed Parameter: Out1_Y0_am
                                          //  Referenced by: '<S153>/Out1'

  real_T Out1_Y0_bh;                   // Computed Parameter: Out1_Y0_bh
                                          //  Referenced by: '<S155>/Out1'

  real_T Out1_Y0_jy;                   // Computed Parameter: Out1_Y0_jy
                                          //  Referenced by: '<S157>/Out1'

  real_T StartPos_gainval;             // Computed Parameter: StartPos_gainval
                                          //  Referenced by: '<S149>/Start Pos'

  real_T EndTime_Y0;                   // Expression: 1
                                          //  Referenced by: '<S149>/End Time'

  real_T EndTime_YFinal;               // Expression: 0
                                          //  Referenced by: '<S149>/End Time'

  real_T Switch_Threshold;             // Expression: 0
                                          //  Referenced by: '<S149>/Switch'

  real_T StartPos_gainval_k;           // Computed Parameter: StartPos_gainval_k
                                          //  Referenced by: '<S150>/Start Pos'

  real_T EndTime_Y0_i;                 // Expression: 1
                                          //  Referenced by: '<S150>/End Time'

  real_T EndTime_YFinal_i;             // Expression: 0
                                          //  Referenced by: '<S150>/End Time'

  real_T Switch_Threshold_j;           // Expression: 0
                                          //  Referenced by: '<S150>/Switch'

  real_T StartPos_gainval_a;           // Computed Parameter: StartPos_gainval_a
                                          //  Referenced by: '<S151>/Start Pos'

  real_T EndTime_Y0_p;                 // Expression: 1
                                          //  Referenced by: '<S151>/End Time'

  real_T EndTime_YFinal_m;             // Expression: 0
                                          //  Referenced by: '<S151>/End Time'

  real_T Switch_Threshold_p;           // Expression: 0
                                          //  Referenced by: '<S151>/Switch'

  real_T PuckState_Value_c;            // Expression: 1
                                          //  Referenced by: '<S93>/Puck State'

  real_T Out1_Y0_ep;                   // Computed Parameter: Out1_Y0_ep
                                          //  Referenced by: '<S236>/Out1'

  real_T Out1_Y0_me;                   // Computed Parameter: Out1_Y0_me
                                          //  Referenced by: '<S238>/Out1'

  real_T Out1_Y0_bg;                   // Computed Parameter: Out1_Y0_bg
                                          //  Referenced by: '<S240>/Out1'

  real_T StartPos_gainval_b;           // Computed Parameter: StartPos_gainval_b
                                          //  Referenced by: '<S232>/Start Pos'

  real_T EndPos_Y0;                    // Expression: 1
                                          //  Referenced by: '<S232>/End Pos'

  real_T EndPos_YFinal;                // Expression: 0
                                          //  Referenced by: '<S232>/End Pos'

  real_T Switch_Threshold_n;           // Expression: 0
                                          //  Referenced by: '<S232>/Switch'

  real_T StartPos_gainval_i;           // Computed Parameter: StartPos_gainval_i
                                          //  Referenced by: '<S233>/Start Pos'

  real_T EndPos_Y0_i;                  // Expression: 1
                                          //  Referenced by: '<S233>/End Pos'

  real_T EndPos_YFinal_f;              // Expression: 0
                                          //  Referenced by: '<S233>/End Pos'

  real_T Switch_Threshold_n0;          // Expression: 0
                                          //  Referenced by: '<S233>/Switch'

  real_T StartPos_gainval_o;           // Computed Parameter: StartPos_gainval_o
                                          //  Referenced by: '<S234>/Start Pos'

  real_T EndPos_Y0_p;                  // Expression: 1
                                          //  Referenced by: '<S234>/End Pos'

  real_T EndPos_YFinal_n;              // Expression: 0
                                          //  Referenced by: '<S234>/End Pos'

  real_T Switch_Threshold_p5;          // Expression: 0
                                          //  Referenced by: '<S234>/Switch'

  real_T PuckState_Value_g;            // Expression: 1
                                          //  Referenced by: '<S164>/Puck State'

  real_T Out1_Y0_ig;                   // Computed Parameter: Out1_Y0_ig
                                          //  Referenced by: '<S324>/Out1'

  real_T Out1_Y0_fb;                   // Computed Parameter: Out1_Y0_fb
                                          //  Referenced by: '<S326>/Out1'

  real_T Out1_Y0_bj;                   // Computed Parameter: Out1_Y0_bj
                                          //  Referenced by: '<S328>/Out1'

  real_T Constant4_Value;              // Expression: 0
                                          //  Referenced by: '<S246>/Constant4'

  real_T DesiredRate_Value;            // Expression: 0.03490659
                                          //  Referenced by: '<S321>/Desired Rate '

  real_T Constant_Value_n;             // Expression: pi
                                          //  Referenced by: '<S321>/Constant'

  real_T PuckState_Value_gv;           // Expression: 1
                                          //  Referenced by: '<S246>/Puck State'

  real_T Out1_Y0_ll;                   // Computed Parameter: Out1_Y0_ll
                                          //  Referenced by: '<S364>/Out1'

  real_T DiscreteTimeIntegrator4_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator4_gainval
                             //  Referenced by: '<S370>/Discrete-Time Integrator4'

  real_T DiscreteTimeIntegrator5_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator5_gainval
                             //  Referenced by: '<S370>/Discrete-Time Integrator5'

  real_T DiscreteTimeIntegrator2_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator2_gainval
                             //  Referenced by: '<S370>/Discrete-Time Integrator2'

  real_T DiscreteTimeIntegrator3_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator3_gainval
                             //  Referenced by: '<S370>/Discrete-Time Integrator3'

  real_T DiscreteTimeIntegrator1_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainval
                             //  Referenced by: '<S370>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S370>/Discrete-Time Integrator'

  real_T Out1_Y0_bjy;                  // Computed Parameter: Out1_Y0_bjy
                                          //  Referenced by: '<S378>/Out1'

  real_T u_Y0;                         // Computed Parameter: u_Y0
                                          //  Referenced by: '<S378>/u'

  real_T Delay_InitialCondition_p[3];  // Expression: [0;0;0]
                                          //  Referenced by: '<S386>/Delay'

  real_T Delay1_InitialCondition_d[3]; // Expression: [0;0;0]
                                          //  Referenced by: '<S386>/Delay1'

  real_T Delay3_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S387>/Delay3'

  real_T Delay1_InitialCondition_p;    // Expression: 0.0
                                          //  Referenced by: '<S388>/Delay1'

  real_T Delay3_InitialCondition_p;    // Expression: 0.0
                                          //  Referenced by: '<S388>/Delay3'

  real_T Delay1_InitialCondition_o;    // Expression: 0.0
                                          //  Referenced by: '<S389>/Delay1'

  real_T Delay3_InitialCondition_e;    // Expression: 0.0
                                          //  Referenced by: '<S389>/Delay3'

  real_T Constant_Value_j[3];          // Expression: [0;0;0]
                                          //  Referenced by: '<S391>/Constant'

  real_T Delay_InitialCondition_n;     // Expression: 0.0
                                          //  Referenced by: '<S391>/Delay'

  real_T Delay_InitialCondition_l;     // Expression: 0.0
                                          //  Referenced by: '<S392>/Delay'

  real_T Delay3_InitialCondition_a;    // Expression: 0.0
                                          //  Referenced by: '<S393>/Delay3'

  real_T Constant1_Value[3];           // Expression: [0;0;0]
                                          //  Referenced by: '<S392>/Constant1'

  real_T Switch_Threshold_d;           // Expression: 0
                                          //  Referenced by: '<S378>/Switch'

  real_T DesiredStates_Y0;             // Computed Parameter: DesiredStates_Y0
                                          //  Referenced by: '<S381>/Desired States'

  real_T DiscreteTransferFcn1_NumCoef; // Expression: [0.004988]
                                          //  Referenced by: '<S381>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_DenCoef[2];// Expression: [1 -0.995]
                                            //  Referenced by: '<S381>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_InitialSta;// Expression: 0
                                            //  Referenced by: '<S381>/Discrete Transfer Fcn1'

  real_T DesiredStates_Y0_g;           // Computed Parameter: DesiredStates_Y0_g
                                          //  Referenced by: '<S380>/Desired States'

  real_T Gain_Gain;                    // Expression: -1
                                          //  Referenced by: '<S403>/Gain'

  real_T Constant4_Value_k;            // Expression: pi/2
                                          //  Referenced by: '<S352>/Constant4'

  real_T Constant5_Value;              // Expression: pi/3
                                          //  Referenced by: '<S352>/Constant5'

  real_T Constant6_Value;              // Expression: 0
                                          //  Referenced by: '<S352>/Constant6'

  real_T Constant7_Value;              // Expression: 1
                                          //  Referenced by: '<S352>/Constant7'

  real_T Delay_InitialCondition_li;    // Expression: 0.0
                                          //  Referenced by: '<S354>/Delay'

  real_T Constant_Value_o[3];          // Expression: [0;0;0]
                                          //  Referenced by: '<S355>/Constant'

  real_T Delay1_InitialCondition_dc;   // Expression: 0.0
                                          //  Referenced by: '<S355>/Delay1'

  real_T Delay_InitialCondition_b;     // Expression: 0.0
                                          //  Referenced by: '<S355>/Delay'

  real_T Delay3_InitialCondition_j;    // Expression: 0.0
                                          //  Referenced by: '<S355>/Delay3'

  real_T Delay2_InitialCondition_d;    // Expression: 0.0
                                          //  Referenced by: '<S355>/Delay2'

  real_T Delay_InitialCondition_c;     // Expression: 0.0
                                          //  Referenced by: '<S379>/Delay'

  real_T Delay_InitialCondition_m;     // Expression: 0.0
                                          //  Referenced by: '<S359>/Delay'

  real_T Constant_Value_g[3];          // Expression: [0;0;0]
                                          //  Referenced by: '<S360>/Constant'

  real_T Delay1_InitialCondition_df;   // Expression: 0.0
                                          //  Referenced by: '<S360>/Delay1'

  real_T Delay_InitialCondition_a;     // Expression: 0.0
                                          //  Referenced by: '<S360>/Delay'

  real_T Delay3_InitialCondition_o;    // Expression: 0.0
                                          //  Referenced by: '<S360>/Delay3'

  real_T Delay2_InitialCondition_h;    // Expression: 0.0
                                          //  Referenced by: '<S360>/Delay2'

  real_T Step_Time;                    // Expression: 90
                                          //  Referenced by: '<S360>/Step'

  real_T Step_Y0;                      // Expression: 0
                                          //  Referenced by: '<S360>/Step'

  real_T Step_YFinal;                  // Expression: 1
                                          //  Referenced by: '<S360>/Step'

  real_T Constant1_Value_j;            // Expression: 0
                                          //  Referenced by: '<S247>/Constant1'

  real_T PuckState_Value_a;            // Expression: 1
                                          //  Referenced by: '<S247>/Puck State'

  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<S530>/Constant3'

  real_T Constant4_Value_g;            // Expression: 0
                                          //  Referenced by: '<S530>/Constant4'

  real_T Constant5_Value_d;            // Expression: 0
                                          //  Referenced by: '<S530>/Constant5'

  real_T PuckState_Value_d;            // Expression: 0
                                          //  Referenced by: '<S530>/Puck State'

  real_T Constant_Value_b;             // Expression: 0
                                          //  Referenced by: '<S532>/Constant'

  real_T Constant1_Value_f;            // Expression: 0
                                          //  Referenced by: '<S532>/Constant1'

  real_T Constant2_Value_h;            // Expression: 0
                                          //  Referenced by: '<S532>/Constant2'

  real_T Constant3_Value_h;            // Expression: 0
                                          //  Referenced by: '<S532>/Constant3'

  real_T PuckState_Value_e;            // Expression: 0
                                          //  Referenced by: '<S532>/Puck State'

  real_T Gain_Gain_p;                  // Expression: -1
                                          //  Referenced by: '<S532>/Gain'

  real_T Saturation_UpperSat;          // Expression: 0.005
                                          //  Referenced by: '<S532>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -0.005
                                          //  Referenced by: '<S532>/Saturation'

  real_T BLACKPWM_Y0;                  // Computed Parameter: BLACKPWM_Y0
                                          //  Referenced by: '<S636>/BLACK PWM'

  real_T RemoveNegatives_UpperSat;     // Expression: 1000
                                          //  Referenced by: '<S639>/Remove Negatives'

  real_T RemoveNegatives_LowerSat;     // Expression: 0
                                          //  Referenced by: '<S639>/Remove Negatives'

  real_T BLUEPWM_Y0;                   // Computed Parameter: BLUEPWM_Y0
                                          //  Referenced by: '<S637>/BLUE PWM'

  real_T RemoveNegatives_UpperSat_m;   // Expression: 1000
                                          //  Referenced by: '<S651>/Remove Negatives'

  real_T RemoveNegatives_LowerSat_a;   // Expression: 0
                                          //  Referenced by: '<S651>/Remove Negatives'

  real_T REDPWM_Y0;                    // Computed Parameter: REDPWM_Y0
                                          //  Referenced by: '<S638>/RED PWM'

  real_T RemoveNegatives_UpperSat_k;   // Expression: 1000
                                          //  Referenced by: '<S663>/Remove Negatives'

  real_T RemoveNegatives_LowerSat_k;   // Expression: 0
                                          //  Referenced by: '<S663>/Remove Negatives'

  real_T DataStoreMemory_InitialValue; // Expression: 0
                                          //  Referenced by: '<Root>/Data Store Memory'

  real_T DataStoreMemory2_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Data Store Memory2'

  real_T SafetyNumber_Value;           // Expression: 568471
                                          //  Referenced by: '<S19>/Safety Number'

  real_T Gain_Gain_c;                  // Expression: 100
                                          //  Referenced by: '<S19>/Gain'

  real_T Gain1_Gain;                   // Expression: 100
                                          //  Referenced by: '<S19>/Gain1'

  real_T Gain2_Gain;                   // Expression: 100
                                          //  Referenced by: '<S19>/Gain2'

  real_T Gain3_Gain;                   // Expression: 100
                                          //  Referenced by: '<S19>/Gain3'

  real_T Gain4_Gain;                   // Expression: 100
                                          //  Referenced by: '<S19>/Gain4'

  real_T Gain5_Gain;                   // Expression: 100
                                          //  Referenced by: '<S19>/Gain5'

  real_T Gain6_Gain;                   // Expression: 100
                                          //  Referenced by: '<S19>/Gain6'

  real_T Gain7_Gain;                   // Expression: 100
                                          //  Referenced by: '<S19>/Gain7'

  real_T BLACK_Fx_InitialValue;        // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Fx'

  real_T BLACK_Fx1_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Fx1'

  real_T BLACK_Fx_Sat_InitialValue;    // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Fx_Sat'

  real_T BLACK_Fx_Sat2_InitialValue;   // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Fx_Sat2'

  real_T BLACK_Fy_InitialValue;        // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Fy'

  real_T BLACK_Fy1_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Fy1'

  real_T BLACK_Fy_Sat_InitialValue;    // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Fy_Sat'

  real_T BLACK_Fy_Sat2_InitialValue;   // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Fy_Sat2'

  real_T BLACK_Px_InitialValue;        // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Px'

  real_T BLACK_Px1_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Px1'

  real_T BLACK_Px2_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Px2'

  real_T BLACK_Px3_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Px3'

  real_T BLACK_Px4_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Px4'

  real_T BLACK_Px5_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Px5'

  real_T BLACK_Py_InitialValue;        // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Py'

  real_T BLACK_Py1_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Py1'

  real_T BLACK_Py2_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Py2'

  real_T BLACK_Py3_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Py3'

  real_T BLACK_Py4_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Py4'

  real_T BLACK_Py5_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Py5'

  real_T BLACK_Py6_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Py6'

  real_T BLACK_Py7_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Py7'

  real_T BLACK_Py8_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Py8'

  real_T BLACK_Py9_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Py9'

  real_T BLACK_Rz_InitialValue;        // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Rz'

  real_T BLACK_Rz1_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Rz1'

  real_T BLACK_Rz2_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Rz2'

  real_T BLACK_Rz3_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Rz3'

  real_T BLACK_Tz_InitialValue;        // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Tz'

  real_T BLACK_Tz1_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Tz1'

  real_T BLACK_Tz_Sat_InitialValue;    // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Tz_Sat'

  real_T BLACK_Tz_Sat2_InitialValue;   // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Tz_Sat2'

  real_T RED_Fx1_InitialValue;         // Expression: 0
                                          //  Referenced by: '<Root>/RED_Fx1'

  real_T RED_Fx_Sat_InitialValue;      // Expression: 0
                                          //  Referenced by: '<Root>/RED_Fx_Sat'

  real_T RED_Fy_InitialValue;          // Expression: 0
                                          //  Referenced by: '<Root>/RED_Fy'

  real_T RED_Fy_Sat_InitialValue;      // Expression: 0
                                          //  Referenced by: '<Root>/RED_Fy_Sat'

  real_T RED_Px_InitialValue;          // Expression: 0
                                          //  Referenced by: '<Root>/RED_Px'

  real_T RED_Py_InitialValue;          // Expression: 0
                                          //  Referenced by: '<Root>/RED_Py'

  real_T RED_Rz_InitialValue;          // Expression: 0
                                          //  Referenced by: '<Root>/RED_Rz'

  real_T RED_Tz_InitialValue;          // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz'

  real_T RED_Tz12_InitialValue;        // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz12'

  real_T RED_Tz13_InitialValue;        // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz13'

  real_T RED_Tz14_InitialValue;        // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz14'

  real_T RED_Tz15_InitialValue;        // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz15'

  real_T RED_Tz16_InitialValue;        // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz16'

  real_T RED_Tz17_InitialValue;        // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz17'

  real_T RED_Tz4_InitialValue;         // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz4'

  real_T RED_Tz5_InitialValue;         // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz5'

  real_T RED_Tz6_InitialValue;         // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz6'

  real_T RED_Tz7_InitialValue;         // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz7'

  real_T RED_Tz_RW_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz_RW'

  real_T RED_Tz_RWSat_InitialValue;    // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz_RW Sat'

  real_T RED_Tz_Sat_InitialValue;      // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz_Sat'

  real_T RED_dRz_RWSat_InitialValue;   // Expression: 0
                                          //  Referenced by: '<Root>/RED_dRz_RW Sat'

  real_T RED_dRz_RWSat1_InitialValue;  // Expression: 0
                                          //  Referenced by: '<Root>/RED_dRz_RW Sat1'

  real_T RED_dRz_RWSat10_InitialValue; // Expression: 0
                                          //  Referenced by: '<Root>/RED_dRz_RW Sat10'

  real_T RED_dRz_RWSat11_InitialValue; // Expression: 0
                                          //  Referenced by: '<Root>/RED_dRz_RW Sat11'

  real_T RED_dRz_RWSat12_InitialValue; // Expression: 0
                                          //  Referenced by: '<Root>/RED_dRz_RW Sat12'

  real_T RED_dRz_RWSat13_InitialValue; // Expression: 0
                                          //  Referenced by: '<Root>/RED_dRz_RW Sat13'

  real_T RED_dRz_RWSat14_InitialValue; // Expression: 0
                                          //  Referenced by: '<Root>/RED_dRz_RW Sat14'

  real_T RED_dRz_RWSat2_InitialValue;  // Expression: 0
                                          //  Referenced by: '<Root>/RED_dRz_RW Sat2'

  real_T RED_dRz_RWSat3_InitialValue;  // Expression: 0
                                          //  Referenced by: '<Root>/RED_dRz_RW Sat3'

  real_T RED_dRz_RWSat4_InitialValue;  // Expression: 0
                                          //  Referenced by: '<Root>/RED_dRz_RW Sat4'

  real_T RED_dRz_RWSat5_InitialValue;  // Expression: 0
                                          //  Referenced by: '<Root>/RED_dRz_RW Sat5'

  real_T RED_dRz_RWSat6_InitialValue;  // Expression: 0
                                          //  Referenced by: '<Root>/RED_dRz_RW Sat6'

  real_T RED_dRz_RWSat7_InitialValue;  // Expression: 0
                                          //  Referenced by: '<Root>/RED_dRz_RW Sat7'

  real_T RED_dRz_RWSat8_InitialValue;  // Expression: 0
                                          //  Referenced by: '<Root>/RED_dRz_RW Sat8'

  real_T RED_dRz_RWSat9_InitialValue;  // Expression: 0
                                          //  Referenced by: '<Root>/RED_dRz_RW Sat9'

  real_T Universal_Time_InitialValue;  // Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time'

  real_T Universal_Time1_InitialValue; // Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time1'

  real_T Universal_Time10_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time10'

  real_T Universal_Time11_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time11'

  real_T Universal_Time12_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time12'

  real_T Universal_Time13_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time13'

  real_T Universal_Time14_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time14'

  real_T Universal_Time15_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time15'

  real_T Universal_Time16_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time16'

  real_T Universal_Time17_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time17'

  real_T Universal_Time18_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time18'

  real_T Universal_Time19_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time19'

  real_T Universal_Time2_InitialValue; // Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time2'

  real_T Universal_Time20_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time20'

  real_T Universal_Time21_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time21'

  real_T Universal_Time22_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time22'

  real_T Universal_Time23_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time23'

  real_T Universal_Time24_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time24'

  real_T Universal_Time3_InitialValue; // Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time3'

  real_T Universal_Time4_InitialValue; // Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time4'

  real_T Universal_Time5_InitialValue; // Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time5'

  real_T Universal_Time6_InitialValue; // Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time6'

  real_T Universal_Time7_InitialValue; // Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time7'

  real_T Universal_Time8_InitialValue; // Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time8'

  real_T Universal_Time9_InitialValue; // Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time9'

  int32_T Constant1_Value_i;           // Computed Parameter: Constant1_Value_i
                                          //  Referenced by: '<S22>/Constant1'

  int32_T UDPSend_Port;                // Computed Parameter: UDPSend_Port
                                          //  Referenced by: '<S22>/UDP Send'

  int32_T UDPReceive1_Port;            // Computed Parameter: UDPReceive1_Port
                                          //  Referenced by: '<S534>/UDP Receive1'

  int32_T Delay_InitialCondition_g;
                                 // Computed Parameter: Delay_InitialCondition_g
                                    //  Referenced by: '<S534>/Delay'

  int32_T Delay1_InitialCondition_h;
                                // Computed Parameter: Delay1_InitialCondition_h
                                   //  Referenced by: '<S534>/Delay1'

  int32_T Delay2_InitialCondition_j;
                                // Computed Parameter: Delay2_InitialCondition_j
                                   //  Referenced by: '<S534>/Delay2'

  int32_T UDPReceive_Port;             // Computed Parameter: UDPReceive_Port
                                          //  Referenced by: '<S534>/UDP Receive'

  int32_T UDPReceive2_Port;            // Computed Parameter: UDPReceive2_Port
                                          //  Referenced by: '<S534>/UDP Receive2'

  int32_T UDPReceive3_Port;            // Computed Parameter: UDPReceive3_Port
                                          //  Referenced by: '<S534>/UDP Receive3'

  int32_T UDPSend_Port_d;              // Computed Parameter: UDPSend_Port_d
                                          //  Referenced by: '<S577>/UDP Send'

  int32_T UDPReceive1_Port_f;          // Computed Parameter: UDPReceive1_Port_f
                                          //  Referenced by: '<S2>/UDP Receive1'

  int32_T UDPSend_Port_d5;             // Computed Parameter: UDPSend_Port_d5
                                          //  Referenced by: '<S19>/UDP Send'

  P_ChangeBLUEBehavior_APF_CTL__T ChangeBLUEBehavior_l;// '<S12>/Change BLUE Behavior' 
  P_Phase4ReturnHome_APF_CTL_VI_T Phase5HoldHome;// '<Root>/Phase #5: Hold Home' 
  P_Phase4ReturnHome_APF_CTL_VI_T Phase4ReturnHome;// '<Root>/Phase #4: Return Home' 
  P_SimulatedPositionController_T SimulatedPositionController;
                                      // '<S352>/Simulated Position Controller'
  P_TargetTracker_APF_CTL_VIS_O_T TargetFinder;// '<S349>/Target Finder'
  P_TargetTracker_APF_CTL_VIS_O_T TargetTracker;// '<S349>/Target Tracker'
  P_REDARM_APF_CTL_VIS_Obs_2023_T REDARM_m;// '<S246>/RED+ARM'
  P_SubPhase1_APF_CTL_VIS_Obs_h_T SubPhase2_p;// '<S89>/Sub-Phase #2 '
  P_SubPhase1_APF_CTL_VIS_Obs_h_T SubPhase1_p;// '<S89>/Sub-Phase #1'
  P_SubPhase1_APF_CTL_VIS_Obs_a_T SubPhase3_e;// '<S88>/Sub-Phase #3 '
  P_SubPhase1_APF_CTL_VIS_Obs_a_T SubPhase2_c;// '<S88>/Sub-Phase #2 '
  P_SubPhase1_APF_CTL_VIS_Obs_a_T SubPhase1_g;// '<S88>/Sub-Phase #1'
  P_SubPhase1_APF_CTL_VIS_Obs_2_T SubPhase3;// '<S87>/Sub-Phase #3 '
  P_SubPhase1_APF_CTL_VIS_Obs_2_T SubPhase2;// '<S87>/Sub-Phase #2 '
  P_SubPhase1_APF_CTL_VIS_Obs_2_T SubPhase1;// '<S87>/Sub-Phase #1'
  P_REDARM_APF_CTL_VIS_Obs_2023_T REDARM_e;// '<S35>/RED+ARM'
  P_Phase0Synchronization_APF_C_T Phase1StartFloating;// '<Root>/Phase #1: Start Floating ' 
  P_Phase0Synchronization_APF_C_T Phase0Synchronization;// '<Root>/Phase #0: Synchronization' 
  P_ChangeBLACKBehavior_APF_CTL_T ChangeBLUEBehavior;// '<S1>/Change BLUE Behavior' 
  P_ChangeBLACKBehavior_APF_CTL_T ChangeBLACKBehavior;// '<S1>/Change BLACK Behavior' 
};

// Real-time Model Data Structure
struct tag_RTM_APF_CTL_VIS_Obs_2023a_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_APF_CTL_VIS_Obs_2023a_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_APF_CTL_VIS_Obs_2023a_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[6];
  real_T odeF[4][6];
  ODE4_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_APF_CTL_VIS_Obs_2023a_T APF_CTL_VIS_Obs_2023a_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_APF_CTL_VIS_Obs_2023a_T APF_CTL_VIS_Obs_2023a_B;

#ifdef __cplusplus

}

#endif

// Continuous states (default storage)
extern X_APF_CTL_VIS_Obs_2023a_T APF_CTL_VIS_Obs_2023a_X;

// Block states (default storage)
extern struct DW_APF_CTL_VIS_Obs_2023a_T APF_CTL_VIS_Obs_2023a_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void APF_CTL_VIS_Obs_2023a_initialize(void);
  extern void APF_CTL_VIS_Obs_2023a_step(void);
  extern void APF_CTL_VIS_Obs_2023a_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_APF_CTL_VIS_Obs_2023_T *const APF_CTL_VIS_Obs_2023a_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S3>/To Workspace' : Unused code path elimination
//  Block '<S349>/Scope1' : Unused code path elimination
//  Block '<S382>/Reshape' : Unused code path elimination
//  Block '<S382>/Reshape1' : Unused code path elimination
//  Block '<S382>/To Workspace' : Unused code path elimination
//  Block '<S382>/To Workspace1' : Unused code path elimination
//  Block '<S382>/To Workspace2' : Unused code path elimination
//  Block '<S382>/To Workspace3' : Unused code path elimination
//  Block '<S382>/To Workspace4' : Unused code path elimination
//  Block '<S379>/Scope1' : Unused code path elimination
//  Block '<S247>/To Workspace2' : Unused code path elimination
//  Block '<S355>/Reshape6' : Reshape block reduction
//  Block '<S360>/Reshape6' : Reshape block reduction
//  Block '<S534>/Reshape' : Reshape block reduction


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'APF_CTL_VIS_Obs_2023a'
//  '<S1>'   : 'APF_CTL_VIS_Obs_2023a/Check Connection'
//  '<S2>'   : 'APF_CTL_VIS_Obs_2023a/Collect  ZED Data'
//  '<S3>'   : 'APF_CTL_VIS_Obs_2023a/Data Logger Subsystem'
//  '<S4>'   : 'APF_CTL_VIS_Obs_2023a/Float Code'
//  '<S5>'   : 'APF_CTL_VIS_Obs_2023a/Manipulator Encoder Data'
//  '<S6>'   : 'APF_CTL_VIS_Obs_2023a/Phase #0: Synchronization'
//  '<S7>'   : 'APF_CTL_VIS_Obs_2023a/Phase #1: Start Floating '
//  '<S8>'   : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position'
//  '<S9>'   : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment'
//  '<S10>'  : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home'
//  '<S11>'  : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home'
//  '<S12>'  : 'APF_CTL_VIS_Obs_2023a/Phase #6: Clean Shutdown'
//  '<S13>'  : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code'
//  '<S14>'  : 'APF_CTL_VIS_Obs_2023a/Platform Identification'
//  '<S15>'  : 'APF_CTL_VIS_Obs_2023a/Robotic  Arm Code'
//  '<S16>'  : 'APF_CTL_VIS_Obs_2023a/Send Data to TX2'
//  '<S17>'  : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics'
//  '<S18>'  : 'APF_CTL_VIS_Obs_2023a/Simulation Status'
//  '<S19>'  : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code'
//  '<S20>'  : 'APF_CTL_VIS_Obs_2023a/Check Connection/Change BLACK Behavior'
//  '<S21>'  : 'APF_CTL_VIS_Obs_2023a/Check Connection/Change BLUE Behavior'
//  '<S22>'  : 'APF_CTL_VIS_Obs_2023a/Check Connection/Change RED Behavior'
//  '<S23>'  : 'APF_CTL_VIS_Obs_2023a/Data Logger Subsystem/Data Logger'
//  '<S24>'  : 'APF_CTL_VIS_Obs_2023a/Data Logger Subsystem/Data Logger/MATLAB Function'
//  '<S25>'  : 'APF_CTL_VIS_Obs_2023a/Float Code/Enable Pucks'
//  '<S26>'  : 'APF_CTL_VIS_Obs_2023a/Manipulator Encoder Data/Change RED Behavior'
//  '<S27>'  : 'APF_CTL_VIS_Obs_2023a/Phase #0: Synchronization/Change BLACK Behavior'
//  '<S28>'  : 'APF_CTL_VIS_Obs_2023a/Phase #0: Synchronization/Change BLUE Behavior'
//  '<S29>'  : 'APF_CTL_VIS_Obs_2023a/Phase #0: Synchronization/Change RED Behavior'
//  '<S30>'  : 'APF_CTL_VIS_Obs_2023a/Phase #1: Start Floating /Change BLACK Behavior'
//  '<S31>'  : 'APF_CTL_VIS_Obs_2023a/Phase #1: Start Floating /Change BLUE Behavior'
//  '<S32>'  : 'APF_CTL_VIS_Obs_2023a/Phase #1: Start Floating /Change RED Behavior'
//  '<S33>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLACK Behavior'
//  '<S34>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLUE Behavior'
//  '<S35>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior'
//  '<S36>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLACK Behavior/Custom Discrete PD (Attitude)'
//  '<S37>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLACK Behavior/Custom Discrete PD (X-Position)'
//  '<S38>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLACK Behavior/Custom Discrete PD (Y-Position)'
//  '<S39>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLACK Behavior/Hough Control'
//  '<S40>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLACK Behavior/Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S41>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLACK Behavior/Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S42>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLACK Behavior/Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S43>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLACK Behavior/Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S44>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLACK Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S45>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLACK Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S46>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLACK Behavior/Hough Control/MATLAB Function2'
//  '<S47>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLACK Behavior/Hough Control/MATLAB Function3'
//  '<S48>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLACK Behavior/Hough Control/MATLAB Function4'
//  '<S49>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLUE Behavior/Custom Discrete PD (Attitude)'
//  '<S50>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLUE Behavior/Custom Discrete PD (X-Position)'
//  '<S51>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLUE Behavior/Custom Discrete PD (Y-Position)'
//  '<S52>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLUE Behavior/Hough Control'
//  '<S53>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLUE Behavior/Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S54>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLUE Behavior/Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S55>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLUE Behavior/Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S56>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLUE Behavior/Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S57>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLUE Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S58>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLUE Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S59>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLUE Behavior/Hough Control/MATLAB Function2'
//  '<S60>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLUE Behavior/Hough Control/MATLAB Function3'
//  '<S61>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change BLUE Behavior/Hough Control/MATLAB Function4'
//  '<S62>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/Custom Discrete PD (Attitude)'
//  '<S63>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/Custom Discrete PD (X-Position)'
//  '<S64>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/Custom Discrete PD (Y-Position)'
//  '<S65>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/Hough Control'
//  '<S66>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/RED+ARM'
//  '<S67>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/Custom Discrete PD (Attitude)/x_dot -> x2'
//  '<S68>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/Custom Discrete PD (Attitude)/x_dot -> x2/Hold this value'
//  '<S69>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/Custom Discrete PD (X-Position)/x_dot -> x2'
//  '<S70>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/Custom Discrete PD (X-Position)/x_dot -> x2/Hold this value'
//  '<S71>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/Custom Discrete PD (Y-Position)/x_dot -> x2'
//  '<S72>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/Custom Discrete PD (Y-Position)/x_dot -> x2/Hold this value'
//  '<S73>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/Hough Control/MATLAB Function2'
//  '<S74>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/Hough Control/MATLAB Function3'
//  '<S75>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/Hough Control/MATLAB Function4'
//  '<S76>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Passthrough for Experiment'
//  '<S77>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Simulated Position Controller'
//  '<S78>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)'
//  '<S79>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)'
//  '<S80>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)'
//  '<S81>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2'
//  '<S82>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2/Hold this value'
//  '<S83>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2'
//  '<S84>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2/Hold this value'
//  '<S85>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2'
//  '<S86>'  : 'APF_CTL_VIS_Obs_2023a/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2/Hold this value'
//  '<S87>'  : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior'
//  '<S88>'  : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior'
//  '<S89>'  : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior'
//  '<S90>'  : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1'
//  '<S91>'  : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 '
//  '<S92>'  : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 '
//  '<S93>'  : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4'
//  '<S94>'  : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/BLACK_Rz Desired'
//  '<S95>'  : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Custom Discrete PD (Attitude)'
//  '<S96>'  : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Custom Discrete PD (X-Position)'
//  '<S97>'  : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Custom Discrete PD (Y-Position)'
//  '<S98>'  : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Hough Control'
//  '<S99>'  : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/BLACK_Rz Desired/Subsystem'
//  '<S100>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/BLACK_Rz Desired/Wrap1'
//  '<S101>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/BLACK_Rz Desired/Wrap1/MATLAB Function'
//  '<S102>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S103>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S104>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S105>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S106>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S107>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S108>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Hough Control/MATLAB Function2'
//  '<S109>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Hough Control/MATLAB Function3'
//  '<S110>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Hough Control/MATLAB Function4'
//  '<S111>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /BLACK_Rz Desired'
//  '<S112>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Custom Discrete PD (Attitude)'
//  '<S113>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Custom Discrete PD (X-Position)'
//  '<S114>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Custom Discrete PD (Y-Position)'
//  '<S115>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Hough Control'
//  '<S116>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /BLACK_Rz Desired/Subsystem'
//  '<S117>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /BLACK_Rz Desired/Wrap1'
//  '<S118>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /BLACK_Rz Desired/Wrap1/MATLAB Function'
//  '<S119>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S120>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S121>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S122>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S123>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S124>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S125>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Hough Control/MATLAB Function2'
//  '<S126>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Hough Control/MATLAB Function3'
//  '<S127>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Hough Control/MATLAB Function4'
//  '<S128>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /BLACK_Rz Desired'
//  '<S129>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Custom Discrete PD (Attitude)'
//  '<S130>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Custom Discrete PD (X-Position)'
//  '<S131>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Custom Discrete PD (Y-Position)'
//  '<S132>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Hough Control'
//  '<S133>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /BLACK_Rz Desired/Subsystem'
//  '<S134>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /BLACK_Rz Desired/Wrap1'
//  '<S135>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /BLACK_Rz Desired/Wrap1/MATLAB Function'
//  '<S136>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S137>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S138>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S139>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S140>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S141>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S142>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Hough Control/MATLAB Function2'
//  '<S143>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Hough Control/MATLAB Function3'
//  '<S144>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Hough Control/MATLAB Function4'
//  '<S145>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Custom Discrete PD (Attitude)'
//  '<S146>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Custom Discrete PD (X-Position)'
//  '<S147>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Custom Discrete PD (Y-Position)'
//  '<S148>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Hough Control'
//  '<S149>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Motion X1'
//  '<S150>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Motion Y1'
//  '<S151>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Motion Z1'
//  '<S152>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S153>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S154>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S155>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S156>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S157>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S158>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Hough Control/MATLAB Function2'
//  '<S159>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Hough Control/MATLAB Function3'
//  '<S160>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Hough Control/MATLAB Function4'
//  '<S161>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1'
//  '<S162>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 '
//  '<S163>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 '
//  '<S164>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #4'
//  '<S165>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/BLUE_Rz Desired'
//  '<S166>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Custom Discrete PD (Attitude)'
//  '<S167>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Custom Discrete PD (X-Position)'
//  '<S168>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Custom Discrete PD (Y-Position)'
//  '<S169>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Hough Control'
//  '<S170>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/MATLAB Function2'
//  '<S171>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/MATLAB Function3'
//  '<S172>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Subsystem2'
//  '<S173>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/BLUE_Rz Desired/Subsystem'
//  '<S174>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/BLUE_Rz Desired/Wrap'
//  '<S175>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/BLUE_Rz Desired/Wrap/MATLAB Function'
//  '<S176>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S177>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S178>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S179>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S180>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S181>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S182>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Hough Control/MATLAB Function2'
//  '<S183>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Hough Control/MATLAB Function3'
//  '<S184>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Hough Control/MATLAB Function4'
//  '<S185>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Subsystem2/Subsystem'
//  '<S186>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /BLUE_Rz Desired'
//  '<S187>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Custom Discrete PD (Attitude)'
//  '<S188>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Custom Discrete PD (X-Position)'
//  '<S189>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Custom Discrete PD (Y-Position)'
//  '<S190>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Hough Control'
//  '<S191>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /MATLAB Function2'
//  '<S192>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /MATLAB Function3'
//  '<S193>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Subsystem2'
//  '<S194>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /BLUE_Rz Desired/Subsystem'
//  '<S195>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /BLUE_Rz Desired/Wrap'
//  '<S196>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /BLUE_Rz Desired/Wrap/MATLAB Function'
//  '<S197>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S198>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S199>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S200>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S201>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S202>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S203>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Hough Control/MATLAB Function2'
//  '<S204>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Hough Control/MATLAB Function3'
//  '<S205>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Hough Control/MATLAB Function4'
//  '<S206>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Subsystem2/Subsystem'
//  '<S207>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /BLUE_Rz Desired'
//  '<S208>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Custom Discrete PD (Attitude)'
//  '<S209>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Custom Discrete PD (X-Position)'
//  '<S210>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Custom Discrete PD (Y-Position)'
//  '<S211>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Hough Control'
//  '<S212>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /MATLAB Function2'
//  '<S213>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /MATLAB Function3'
//  '<S214>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Subsystem2'
//  '<S215>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /BLUE_Rz Desired/Subsystem'
//  '<S216>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /BLUE_Rz Desired/Wrap'
//  '<S217>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /BLUE_Rz Desired/Wrap/MATLAB Function'
//  '<S218>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S219>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S220>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S221>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S222>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S223>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S224>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Hough Control/MATLAB Function2'
//  '<S225>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Hough Control/MATLAB Function3'
//  '<S226>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Hough Control/MATLAB Function4'
//  '<S227>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Subsystem2/Subsystem'
//  '<S228>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #4/Custom Discrete PD (Attitude)'
//  '<S229>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #4/Custom Discrete PD (X-Position)'
//  '<S230>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #4/Custom Discrete PD (Y-Position)'
//  '<S231>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #4/Hough Control'
//  '<S232>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #4/Motion X'
//  '<S233>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #4/Motion Y'
//  '<S234>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #4/Motion Z'
//  '<S235>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #4/Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S236>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #4/Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S237>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #4/Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S238>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #4/Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S239>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #4/Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S240>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #4/Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S241>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #4/Hough Control/MATLAB Function2'
//  '<S242>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #4/Hough Control/MATLAB Function3'
//  '<S243>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #4/Hough Control/MATLAB Function4'
//  '<S244>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1'
//  '<S245>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 '
//  '<S246>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 '
//  '<S247>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4'
//  '<S248>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Custom Discrete PD (Attitude)'
//  '<S249>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Custom Discrete PD (X-Position)'
//  '<S250>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Custom Discrete PD (Y-Position)'
//  '<S251>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Hough Control'
//  '<S252>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/MATLAB Function'
//  '<S253>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/MATLAB Function1'
//  '<S254>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM'
//  '<S255>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED_Rz Desired'
//  '<S256>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Subsystem1'
//  '<S257>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Custom Discrete PD (Attitude)/x_dot -> x2'
//  '<S258>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Custom Discrete PD (Attitude)/x_dot -> x2/Hold this value'
//  '<S259>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Custom Discrete PD (X-Position)/x_dot -> x2'
//  '<S260>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Custom Discrete PD (X-Position)/x_dot -> x2/Hold this value'
//  '<S261>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Custom Discrete PD (Y-Position)/x_dot -> x2'
//  '<S262>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Custom Discrete PD (Y-Position)/x_dot -> x2/Hold this value'
//  '<S263>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Hough Control/MATLAB Function2'
//  '<S264>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Hough Control/MATLAB Function3'
//  '<S265>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Hough Control/MATLAB Function4'
//  '<S266>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Passthrough for Experiment'
//  '<S267>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Simulated Position Controller'
//  '<S268>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)'
//  '<S269>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)'
//  '<S270>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)'
//  '<S271>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2'
//  '<S272>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2/Hold this value'
//  '<S273>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2'
//  '<S274>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2/Hold this value'
//  '<S275>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2'
//  '<S276>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2/Hold this value'
//  '<S277>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED_Rz Desired/Subsystem'
//  '<S278>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED_Rz Desired/Wrap'
//  '<S279>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED_Rz Desired/Wrap/MATLAB Function'
//  '<S280>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Subsystem1/Subsystem'
//  '<S281>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Custom Discrete PD (Attitude)'
//  '<S282>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Custom Discrete PD (X-Position)'
//  '<S283>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Custom Discrete PD (Y-Position)'
//  '<S284>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Hough Control'
//  '<S285>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /MATLAB Function'
//  '<S286>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /MATLAB Function1'
//  '<S287>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM'
//  '<S288>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED_Rz Desired'
//  '<S289>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Subsystem1'
//  '<S290>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Custom Discrete PD (Attitude)/x_dot -> x2'
//  '<S291>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Custom Discrete PD (Attitude)/x_dot -> x2/Hold this value'
//  '<S292>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Custom Discrete PD (X-Position)/x_dot -> x2'
//  '<S293>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Custom Discrete PD (X-Position)/x_dot -> x2/Hold this value'
//  '<S294>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Custom Discrete PD (Y-Position)/x_dot -> x2'
//  '<S295>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Custom Discrete PD (Y-Position)/x_dot -> x2/Hold this value'
//  '<S296>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Hough Control/MATLAB Function2'
//  '<S297>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Hough Control/MATLAB Function3'
//  '<S298>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Hough Control/MATLAB Function4'
//  '<S299>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Passthrough for Experiment'
//  '<S300>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Simulated Position Controller'
//  '<S301>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)'
//  '<S302>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)'
//  '<S303>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)'
//  '<S304>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2'
//  '<S305>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2/Hold this value'
//  '<S306>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2'
//  '<S307>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2/Hold this value'
//  '<S308>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2'
//  '<S309>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2/Hold this value'
//  '<S310>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED_Rz Desired/Subsystem'
//  '<S311>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED_Rz Desired/Wrap'
//  '<S312>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED_Rz Desired/Wrap/MATLAB Function'
//  '<S313>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Subsystem1/Subsystem'
//  '<S314>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Custom Discrete PD (Attitude)'
//  '<S315>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Custom Discrete PD (X-Position)'
//  '<S316>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Custom Discrete PD (Y-Position)'
//  '<S317>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Hough Control'
//  '<S318>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /MATLAB Function'
//  '<S319>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /MATLAB Function1'
//  '<S320>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM'
//  '<S321>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED_Rz Desired'
//  '<S322>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Subsystem1'
//  '<S323>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Custom Discrete PD (Attitude)/x_dot -> x2'
//  '<S324>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Custom Discrete PD (Attitude)/x_dot -> x2/Hold this value'
//  '<S325>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Custom Discrete PD (X-Position)/x_dot -> x2'
//  '<S326>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Custom Discrete PD (X-Position)/x_dot -> x2/Hold this value'
//  '<S327>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Custom Discrete PD (Y-Position)/x_dot -> x2'
//  '<S328>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Custom Discrete PD (Y-Position)/x_dot -> x2/Hold this value'
//  '<S329>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Hough Control/MATLAB Function2'
//  '<S330>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Hough Control/MATLAB Function3'
//  '<S331>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Hough Control/MATLAB Function4'
//  '<S332>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Passthrough for Experiment'
//  '<S333>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Simulated Position Controller'
//  '<S334>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)'
//  '<S335>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)'
//  '<S336>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)'
//  '<S337>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2'
//  '<S338>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2/Hold this value'
//  '<S339>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2'
//  '<S340>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2/Hold this value'
//  '<S341>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2'
//  '<S342>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2/Hold this value'
//  '<S343>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED_Rz Desired/Subsystem'
//  '<S344>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED_Rz Desired/Wrap'
//  '<S345>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED_Rz Desired/Wrap/MATLAB Function'
//  '<S346>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Subsystem1/Subsystem'
//  '<S347>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/BLACK'
//  '<S348>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/BLUE'
//  '<S349>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/CTL'
//  '<S350>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC'
//  '<S351>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED'
//  '<S352>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM'
//  '<S353>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/BLACK/Ryan's Transform'
//  '<S354>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/BLACK/Subsystem'
//  '<S355>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/BLACK/UKF_New'
//  '<S356>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/BLACK/Subsystem/MATLAB Function'
//  '<S357>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/BLACK/UKF_New/MATLAB Function2'
//  '<S358>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/BLUE/Ryan's Transform'
//  '<S359>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/BLUE/Subsystem'
//  '<S360>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/BLUE/UKF_New'
//  '<S361>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/BLUE/Subsystem/MATLAB Function'
//  '<S362>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/BLUE/UKF_New/MATLAB Function2'
//  '<S363>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/CTL/Hough Control'
//  '<S364>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/CTL/If Action Subsystem'
//  '<S365>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/CTL/Target Finder'
//  '<S366>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/CTL/Target Tracker'
//  '<S367>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/CTL/Hough Control/MATLAB Function2'
//  '<S368>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/CTL/Hough Control/MATLAB Function3'
//  '<S369>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/CTL/Hough Control/MATLAB Function4'
//  '<S370>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/CTL/If Action Subsystem/DAC Controller3'
//  '<S371>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/CTL/If Action Subsystem/DAC Controller3/Fx Gain Derivatives'
//  '<S372>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/CTL/If Action Subsystem/DAC Controller3/Fy Gain Derivatives'
//  '<S373>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/CTL/If Action Subsystem/DAC Controller3/Torque Gain Derivatives'
//  '<S374>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/CTL/Target Finder/LQR1'
//  '<S375>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/CTL/Target Finder/LQR1/MATLAB Function'
//  '<S376>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/CTL/Target Tracker/LQR1'
//  '<S377>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/CTL/Target Tracker/LQR1/MATLAB Function'
//  '<S378>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF'
//  '<S379>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Switch logic'
//  '<S380>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Target Finder'
//  '<S381>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Target Tracker'
//  '<S382>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF/GDC'
//  '<S383>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF/Looking Angle'
//  '<S384>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF/GDC/MATLAB Function'
//  '<S385>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF/GDC/Subsystem1'
//  '<S386>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF/GDC/Subsystem1/AdaDelta'
//  '<S387>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF/GDC/Subsystem1/AdaGrad'
//  '<S388>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF/GDC/Subsystem1/AdaMax'
//  '<S389>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF/GDC/Subsystem1/Adam'
//  '<S390>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF/GDC/Subsystem1/Gradient Descent'
//  '<S391>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF/GDC/Subsystem1/Momentum'
//  '<S392>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF/GDC/Subsystem1/Nesterov'
//  '<S393>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF/GDC/Subsystem1/RMSProp'
//  '<S394>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF/GDC/Subsystem1/AdaDelta/MATLAB Function1'
//  '<S395>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF/GDC/Subsystem1/AdaGrad/MATLAB Function1'
//  '<S396>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF/GDC/Subsystem1/AdaMax/MATLAB Function1'
//  '<S397>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF/GDC/Subsystem1/Adam/MATLAB Function1'
//  '<S398>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF/GDC/Subsystem1/Gradient Descent/Batch'
//  '<S399>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF/GDC/Subsystem1/Momentum/Momentum'
//  '<S400>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF/GDC/Subsystem1/Nesterov/MATLAB Function1'
//  '<S401>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/APF/GDC/Subsystem1/RMSProp/MATLAB Function1'
//  '<S402>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Switch logic/Switch logic'
//  '<S403>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Target Finder/Constant Angular Rate'
//  '<S404>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Target Finder/Hold Position'
//  '<S405>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Target Finder/Constant Angular Rate/Subsystem'
//  '<S406>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Target Finder/Constant Angular Rate/Wrap1'
//  '<S407>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Target Finder/Constant Angular Rate/Wrap1/MATLAB Function'
//  '<S408>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Target Tracker/Constant Angular Rate'
//  '<S409>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Target Tracker/Hold Position'
//  '<S410>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Target Tracker/Constant Angular Rate/Looking Angle'
//  '<S411>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Passthrough for Experiment'
//  '<S412>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Simulated Position Controller'
//  '<S413>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)'
//  '<S414>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)'
//  '<S415>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)'
//  '<S416>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2'
//  '<S417>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2/Hold this value'
//  '<S418>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2'
//  '<S419>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2/Hold this value'
//  '<S420>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2'
//  '<S421>' : 'APF_CTL_VIS_Obs_2023a/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2/Hold this value'
//  '<S422>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLACK Behavior'
//  '<S423>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLUE Behavior'
//  '<S424>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior'
//  '<S425>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLACK Behavior/Custom Discrete PD (Attitude)'
//  '<S426>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLACK Behavior/Custom Discrete PD (X-Position)'
//  '<S427>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLACK Behavior/Custom Discrete PD (Y-Position)'
//  '<S428>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLACK Behavior/Hough Control'
//  '<S429>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLACK Behavior/Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S430>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLACK Behavior/Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S431>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLACK Behavior/Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S432>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLACK Behavior/Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S433>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLACK Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S434>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLACK Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S435>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLACK Behavior/Hough Control/MATLAB Function2'
//  '<S436>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLACK Behavior/Hough Control/MATLAB Function3'
//  '<S437>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLACK Behavior/Hough Control/MATLAB Function4'
//  '<S438>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLUE Behavior/Custom Discrete PD (Attitude)'
//  '<S439>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLUE Behavior/Custom Discrete PD (X-Position)'
//  '<S440>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLUE Behavior/Custom Discrete PD (Y-Position)'
//  '<S441>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLUE Behavior/Hough Control'
//  '<S442>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLUE Behavior/Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S443>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLUE Behavior/Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S444>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLUE Behavior/Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S445>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLUE Behavior/Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S446>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLUE Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S447>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLUE Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S448>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLUE Behavior/Hough Control/MATLAB Function2'
//  '<S449>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLUE Behavior/Hough Control/MATLAB Function3'
//  '<S450>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change BLUE Behavior/Hough Control/MATLAB Function4'
//  '<S451>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/Custom Discrete PD (Attitude)'
//  '<S452>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/Custom Discrete PD (X-Position)'
//  '<S453>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/Custom Discrete PD (Y-Position)'
//  '<S454>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/Hough Control'
//  '<S455>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/RED+ARM'
//  '<S456>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/Custom Discrete PD (Attitude)/x_dot -> x2'
//  '<S457>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/Custom Discrete PD (Attitude)/x_dot -> x2/Hold this value'
//  '<S458>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/Custom Discrete PD (X-Position)/x_dot -> x2'
//  '<S459>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/Custom Discrete PD (X-Position)/x_dot -> x2/Hold this value'
//  '<S460>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/Custom Discrete PD (Y-Position)/x_dot -> x2'
//  '<S461>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/Custom Discrete PD (Y-Position)/x_dot -> x2/Hold this value'
//  '<S462>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/Hough Control/MATLAB Function2'
//  '<S463>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/Hough Control/MATLAB Function3'
//  '<S464>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/Hough Control/MATLAB Function4'
//  '<S465>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/RED+ARM/Passthrough for Experiment'
//  '<S466>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/RED+ARM/Simulated Position Controller'
//  '<S467>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)'
//  '<S468>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)'
//  '<S469>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)'
//  '<S470>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2'
//  '<S471>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2/Hold this value'
//  '<S472>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2'
//  '<S473>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2/Hold this value'
//  '<S474>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2'
//  '<S475>' : 'APF_CTL_VIS_Obs_2023a/Phase #4: Return Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2/Hold this value'
//  '<S476>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLACK Behavior'
//  '<S477>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLUE Behavior'
//  '<S478>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior'
//  '<S479>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLACK Behavior/Custom Discrete PD (Attitude)'
//  '<S480>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLACK Behavior/Custom Discrete PD (X-Position)'
//  '<S481>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLACK Behavior/Custom Discrete PD (Y-Position)'
//  '<S482>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLACK Behavior/Hough Control'
//  '<S483>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLACK Behavior/Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S484>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLACK Behavior/Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S485>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLACK Behavior/Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S486>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLACK Behavior/Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S487>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLACK Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S488>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLACK Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S489>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLACK Behavior/Hough Control/MATLAB Function2'
//  '<S490>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLACK Behavior/Hough Control/MATLAB Function3'
//  '<S491>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLACK Behavior/Hough Control/MATLAB Function4'
//  '<S492>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLUE Behavior/Custom Discrete PD (Attitude)'
//  '<S493>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLUE Behavior/Custom Discrete PD (X-Position)'
//  '<S494>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLUE Behavior/Custom Discrete PD (Y-Position)'
//  '<S495>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLUE Behavior/Hough Control'
//  '<S496>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLUE Behavior/Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S497>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLUE Behavior/Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S498>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLUE Behavior/Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S499>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLUE Behavior/Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S500>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLUE Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S501>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLUE Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S502>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLUE Behavior/Hough Control/MATLAB Function2'
//  '<S503>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLUE Behavior/Hough Control/MATLAB Function3'
//  '<S504>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change BLUE Behavior/Hough Control/MATLAB Function4'
//  '<S505>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/Custom Discrete PD (Attitude)'
//  '<S506>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/Custom Discrete PD (X-Position)'
//  '<S507>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/Custom Discrete PD (Y-Position)'
//  '<S508>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/Hough Control'
//  '<S509>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/RED+ARM'
//  '<S510>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/Custom Discrete PD (Attitude)/x_dot -> x2'
//  '<S511>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/Custom Discrete PD (Attitude)/x_dot -> x2/Hold this value'
//  '<S512>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/Custom Discrete PD (X-Position)/x_dot -> x2'
//  '<S513>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/Custom Discrete PD (X-Position)/x_dot -> x2/Hold this value'
//  '<S514>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/Custom Discrete PD (Y-Position)/x_dot -> x2'
//  '<S515>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/Custom Discrete PD (Y-Position)/x_dot -> x2/Hold this value'
//  '<S516>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/Hough Control/MATLAB Function2'
//  '<S517>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/Hough Control/MATLAB Function3'
//  '<S518>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/Hough Control/MATLAB Function4'
//  '<S519>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Passthrough for Experiment'
//  '<S520>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Simulated Position Controller'
//  '<S521>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)'
//  '<S522>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)'
//  '<S523>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)'
//  '<S524>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2'
//  '<S525>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2/Hold this value'
//  '<S526>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2'
//  '<S527>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2/Hold this value'
//  '<S528>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2'
//  '<S529>' : 'APF_CTL_VIS_Obs_2023a/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2/Hold this value'
//  '<S530>' : 'APF_CTL_VIS_Obs_2023a/Phase #6: Clean Shutdown/Change BLACK Behavior'
//  '<S531>' : 'APF_CTL_VIS_Obs_2023a/Phase #6: Clean Shutdown/Change BLUE Behavior'
//  '<S532>' : 'APF_CTL_VIS_Obs_2023a/Phase #6: Clean Shutdown/Change RED Behavior'
//  '<S533>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Initialize Universal Time (Simulation)'
//  '<S534>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States'
//  '<S535>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/Adjust Time'
//  '<S536>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/MATLAB Function'
//  '<S537>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x1'
//  '<S538>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x10'
//  '<S539>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x11'
//  '<S540>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x12'
//  '<S541>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x13'
//  '<S542>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x14'
//  '<S543>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x15'
//  '<S544>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x16'
//  '<S545>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x17'
//  '<S546>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x18'
//  '<S547>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x2'
//  '<S548>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x3'
//  '<S549>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x4'
//  '<S550>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x5'
//  '<S551>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x6'
//  '<S552>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x7'
//  '<S553>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x8'
//  '<S554>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x9'
//  '<S555>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/Adjust Time/Enabled Subsystem'
//  '<S556>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/Adjust Time/Enabled Subsystem1'
//  '<S557>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x1/Hold this value'
//  '<S558>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x10/Hold this value'
//  '<S559>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x11/Hold this value'
//  '<S560>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x12/Hold this value'
//  '<S561>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x13/Hold this value'
//  '<S562>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x14/Hold this value'
//  '<S563>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x15/Hold this value'
//  '<S564>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x16/Hold this value'
//  '<S565>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x17/Hold this value'
//  '<S566>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x18/Hold this value'
//  '<S567>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x2/Hold this value'
//  '<S568>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x3/Hold this value'
//  '<S569>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x4/Hold this value'
//  '<S570>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x5/Hold this value'
//  '<S571>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x6/Hold this value'
//  '<S572>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x7/Hold this value'
//  '<S573>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x8/Hold this value'
//  '<S574>' : 'APF_CTL_VIS_Obs_2023a/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x9/Hold this value'
//  '<S575>' : 'APF_CTL_VIS_Obs_2023a/Platform Identification/Subsystem'
//  '<S576>' : 'APF_CTL_VIS_Obs_2023a/Robotic  Arm Code/Change RED Behavior'
//  '<S577>' : 'APF_CTL_VIS_Obs_2023a/Send Data to TX2/Subsystem'
//  '<S578>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLACK Dynamics'
//  '<S579>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLUE Dynamics'
//  '<S580>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics'
//  '<S581>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLACK Dynamics/BLACK Dynamics Model'
//  '<S582>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x1'
//  '<S583>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x2'
//  '<S584>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x3'
//  '<S585>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x4'
//  '<S586>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x5'
//  '<S587>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x7'
//  '<S588>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLACK Dynamics/BLACK Dynamics Model/MATLAB Function'
//  '<S589>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x1/Hold this value'
//  '<S590>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x2/Hold this value'
//  '<S591>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x3/Hold this value'
//  '<S592>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x4/Hold this value'
//  '<S593>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x5/Hold this value'
//  '<S594>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x7/Hold this value'
//  '<S595>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLUE Dynamics/BLUE  Dynamics Model'
//  '<S596>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x1'
//  '<S597>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x2'
//  '<S598>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x3'
//  '<S599>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x4'
//  '<S600>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x5'
//  '<S601>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x7'
//  '<S602>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLUE Dynamics/BLUE  Dynamics Model/MATLAB Function'
//  '<S603>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x1/Hold this value'
//  '<S604>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x2/Hold this value'
//  '<S605>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x3/Hold this value'
//  '<S606>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x4/Hold this value'
//  '<S607>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x5/Hold this value'
//  '<S608>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x7/Hold this value'
//  '<S609>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM'
//  '<S610>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only'
//  '<S611>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM/RED + ARM Dynamics'
//  '<S612>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM/RED + ARM Dynamics/Coriolis Function1'
//  '<S613>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM/RED + ARM Dynamics/Dynamics Model'
//  '<S614>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM/RED + ARM Dynamics/Inertia Function 1'
//  '<S615>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM/RED + ARM Dynamics/x_dot -> x1'
//  '<S616>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM/RED + ARM Dynamics/x_dot -> x2'
//  '<S617>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM/RED + ARM Dynamics/x_dot -> x3'
//  '<S618>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM/RED + ARM Dynamics/x_dot -> x1/Hold this value'
//  '<S619>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM/RED + ARM Dynamics/x_dot -> x2/Hold this value'
//  '<S620>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM/RED + ARM Dynamics/x_dot -> x3/Hold this value'
//  '<S621>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics'
//  '<S622>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/RED Dynamics Model'
//  '<S623>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x1'
//  '<S624>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x2'
//  '<S625>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x3'
//  '<S626>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x4'
//  '<S627>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x5'
//  '<S628>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x6'
//  '<S629>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/RED Dynamics Model/MATLAB Function'
//  '<S630>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x1/Hold this value'
//  '<S631>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x2/Hold this value'
//  '<S632>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x3/Hold this value'
//  '<S633>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x4/Hold this value'
//  '<S634>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x5/Hold this value'
//  '<S635>' : 'APF_CTL_VIS_Obs_2023a/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x6/Hold this value'
//  '<S636>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLACK Behavior'
//  '<S637>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLUE Behavior'
//  '<S638>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior'
//  '<S639>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLACK Behavior/Calculate Thruster  ON//OFF'
//  '<S640>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLACK Behavior/Rotate Forces to Body'
//  '<S641>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLACK Behavior/Calculate Thruster  ON//OFF/MATLAB Function'
//  '<S642>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLACK Behavior/Calculate Thruster  ON//OFF/MATLAB Function1'
//  '<S643>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLACK Behavior/Calculate Thruster  ON//OFF/MATLAB Function10'
//  '<S644>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLACK Behavior/Calculate Thruster  ON//OFF/MATLAB Function11'
//  '<S645>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLACK Behavior/Calculate Thruster  ON//OFF/MATLAB Function3'
//  '<S646>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLACK Behavior/Calculate Thruster  ON//OFF/Rotate Forces to Inertial'
//  '<S647>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLACK Behavior/Calculate Thruster  ON//OFF/pseudo-inverse'
//  '<S648>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLACK Behavior/Calculate Thruster  ON//OFF/pseudo-inverse3'
//  '<S649>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLACK Behavior/Calculate Thruster  ON//OFF/Rotate Forces to Inertial/Create Rotation Matrix'
//  '<S650>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLACK Behavior/Rotate Forces to Body/Create Rotation Matrix'
//  '<S651>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLUE Behavior/Calculate Thruster  ON//OFF'
//  '<S652>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLUE Behavior/Rotate Forces to Body'
//  '<S653>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLUE Behavior/Calculate Thruster  ON//OFF/MATLAB Function'
//  '<S654>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLUE Behavior/Calculate Thruster  ON//OFF/MATLAB Function1'
//  '<S655>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLUE Behavior/Calculate Thruster  ON//OFF/MATLAB Function2'
//  '<S656>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLUE Behavior/Calculate Thruster  ON//OFF/MATLAB Function6'
//  '<S657>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLUE Behavior/Calculate Thruster  ON//OFF/MATLAB Function7'
//  '<S658>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLUE Behavior/Calculate Thruster  ON//OFF/Rotate Forces to Inertial'
//  '<S659>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLUE Behavior/Calculate Thruster  ON//OFF/pseudo-inverse'
//  '<S660>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLUE Behavior/Calculate Thruster  ON//OFF/pseudo-inverse2'
//  '<S661>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLUE Behavior/Calculate Thruster  ON//OFF/Rotate Forces to Inertial/Create Rotation Matrix'
//  '<S662>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change BLUE Behavior/Rotate Forces to Body/Create Rotation Matrix'
//  '<S663>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF'
//  '<S664>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Rotate Forces to Body'
//  '<S665>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/If Action Subsystem'
//  '<S666>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/If Action Subsystem1'
//  '<S667>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/If Action Subsystem2'
//  '<S668>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/If Action Subsystem3'
//  '<S669>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/If Action Subsystem4'
//  '<S670>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/If Action Subsystem5'
//  '<S671>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/MATLAB Function'
//  '<S672>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/MATLAB Function11'
//  '<S673>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/MATLAB Function2'
//  '<S674>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/MATLAB Function3'
//  '<S675>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/MATLAB Function4'
//  '<S676>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/MATLAB Function5'
//  '<S677>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/MATLAB Function6'
//  '<S678>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/MATLAB Function7'
//  '<S679>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/Rotate Forces to Inertial'
//  '<S680>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/pseudo-inverse'
//  '<S681>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/pseudo-inverse1'
//  '<S682>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/Rotate Forces to Inertial/Create Rotation Matrix'
//  '<S683>' : 'APF_CTL_VIS_Obs_2023a/Thruster Control Code/Change RED Behavior/Rotate Forces to Body/Create Rotation Matrix'

#endif                                 // RTW_HEADER_APF_CTL_VIS_Obs_2023a_h_

//
// File trailer for generated code.
//
// [EOF]
//
