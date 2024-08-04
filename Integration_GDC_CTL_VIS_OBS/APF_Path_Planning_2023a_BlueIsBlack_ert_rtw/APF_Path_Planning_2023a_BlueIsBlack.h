//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: APF_Path_Planning_2023a_BlueIsBlack.h
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
#ifndef RTW_HEADER_APF_Path_Planning_2023a_BlueIsBlack_h_
#define RTW_HEADER_APF_Path_Planning_2023a_BlueIsBlack_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "DAHostLib_Network.h"
#include "custom_data_logger.h"
#include "gpio_control.h"
#include "dynamixel_functions.h"
#include "dynamixel_sdk.h"
#include "resource_headers.h"
#include "APF_Path_Planning_2023a_BlueIsBlack_types.h"

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

#define APF_Path_Planning_2023a_BlueIsBlack_M (APF_Path_Planning_2023a_Blue_M)

// Block states (default storage) for system '<S1>/Change BLACK Behavior'
struct DW_ChangeBLACKBehavior_APF_Pa_T {
  real_T UDPSend_NetworkLib[137];      // '<S20>/UDP Send'
};

// Block states (default storage) for system '<Root>/Phase #0: Synchronization'
struct DW_Phase0Synchronization_APF__T {
  int8_T ThisIFblockdetermineswhetherorn;
    // '<S6>/This IF block determines whether or not to run the BLACK sim//exp'
  int8_T ThisIFblockdetermineswhethero_d;
     // '<S6>/This IF block determines whether or not to run the BLUE sim//exp'
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
struct B_REDARM_APF_Path_Planning_20_T {
  B_SimulatedPositionController_T SimulatedPositionController;// '<S66>/Simulated Position Controller' 
};

// Block states (default storage) for system '<S35>/RED+ARM'
struct DW_REDARM_APF_Path_Planning_2_T {
  DW_SimulatedPositionControlle_T SimulatedPositionController;// '<S66>/Simulated Position Controller' 
};

// Block signals for system '<S87>/Sub-Phase #1'
struct B_SubPhase1_APF_Path_Planning_T {
  real_T rtb_Ox_fz_m[2];
  real_T rtb_Ox_a_c[2];
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
struct DW_SubPhase1_APF_Path_Plannin_T {
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
struct B_SubPhase1_APF_Path_Planni_n_T {
  real_T rtb_Ox_e_m[2];
  real_T rtb_Ox_kz_c[2];
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
struct DW_SubPhase1_APF_Path_Plann_o_T {
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
struct B_SubPhase1_APF_Path_Planni_i_T {
  real_T rtb_Ox_o_m[2];
  real_T rtb_Ox_gy_c[2];
  real_T Delay1;                       // '<S257>/Delay1'
  real_T Subtract;                     // '<S244>/Subtract'
  real_T Delay1_c;                     // '<S259>/Delay1'
  real_T Subtract2;                    // '<S244>/Subtract2'
  real_T Delay1_m;                     // '<S261>/Delay1'
  real_T e_out;                        // '<S251>/MATLAB Function4'
  real_T In1;                          // '<S262>/In1'
  real_T In1_g;                        // '<S260>/In1'
  real_T In1_g2;                       // '<S258>/In1'
  B_REDARM_APF_Path_Planning_20_T REDARM;// '<S244>/RED+ARM'
};

// Block states (default storage) for system '<S89>/Sub-Phase #1'
struct DW_SubPhase1_APF_Path_Plann_m_T {
  real_T Delay1_DSTATE;                // '<S257>/Delay1'
  real_T Delay1_DSTATE_e;              // '<S259>/Delay1'
  real_T Delay1_DSTATE_o;              // '<S261>/Delay1'
  int8_T ifwewentthroughastep_ActiveSubs;// '<S257>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_a;// '<S259>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_i;// '<S261>/if we went through a "step"' 
  boolean_T icLoad;                    // '<S257>/Delay1'
  boolean_T icLoad_g;                  // '<S259>/Delay1'
  boolean_T icLoad_h;                  // '<S261>/Delay1'
  DW_REDARM_APF_Path_Planning_2_T REDARM;// '<S244>/RED+ARM'
};

// Block signals for system '<Root>/Phase #4: Return Home'
struct B_Phase4ReturnHome_APF_Path_P_T {
  real_T rtb_Ox_d_m[2];
  real_T rtb_Ox_kr_c[2];
  real_T rtb_Oy_a_k[2];
  real_T Delay1;                       // '<S427>/Delay1'
  real_T Subtract;                     // '<S395>/Subtract'
  real_T Delay1_b;                     // '<S429>/Delay1'
  real_T Subtract1;                    // '<S395>/Subtract1'
  real_T Delay1_d;                     // '<S431>/Delay1'
  real_T In1;                          // '<S446>/In1'
  real_T In1_g;                        // '<S444>/In1'
  real_T In1_g2;                       // '<S442>/In1'
  real_T e_out;                        // '<S425>/MATLAB Function4'
  real_T In1_g20;                      // '<S432>/In1'
  real_T In1_g20a;                     // '<S430>/In1'
  real_T In1_g20as;                    // '<S428>/In1'
  real_T Subtract_k;                   // '<S394>/Subtract'
  real_T Delay1_k;                     // '<S415>/Delay1'
  real_T Subtract1_j;                  // '<S394>/Subtract1'
  real_T Delay1_g;                     // '<S417>/Delay1'
  real_T Delay1_p;                     // '<S413>/Delay1'
  real_T e_out_h;                      // '<S412>/MATLAB Function4'
  real_T In1_g20asd;                   // '<S418>/In1'
  real_T In1_g20asdt;                  // '<S416>/In1'
  real_T In1_g20asdtg;                 // '<S414>/In1'
  real_T Subtract_c;                   // '<S393>/Subtract'
  real_T Delay1_j;                     // '<S402>/Delay1'
  real_T Subtract1_k;                  // '<S393>/Subtract1'
  real_T Delay1_i;                     // '<S404>/Delay1'
  real_T Delay1_c;                     // '<S400>/Delay1'
  real_T e_out_hp;                     // '<S399>/MATLAB Function4'
  real_T In1_g20asdtgi;                // '<S405>/In1'
  real_T In1_g20asdtgi0;               // '<S403>/In1'
  real_T In1_g20asdtgi0c;              // '<S401>/In1'
};

// Block states (default storage) for system '<Root>/Phase #4: Return Home'
struct DW_Phase4ReturnHome_APF_Path__T {
  real_T Delay1_DSTATE;                // '<S427>/Delay1'
  real_T Delay1_DSTATE_d;              // '<S429>/Delay1'
  real_T Delay1_DSTATE_o;              // '<S431>/Delay1'
  real_T Delay1_DSTATE_j;              // '<S443>/Delay1'
  real_T Delay1_DSTATE_l;              // '<S441>/Delay1'
  real_T Delay1_DSTATE_h;              // '<S445>/Delay1'
  real_T Delay1_DSTATE_f;              // '<S415>/Delay1'
  real_T Delay1_DSTATE_i;              // '<S417>/Delay1'
  real_T Delay1_DSTATE_ol;             // '<S413>/Delay1'
  real_T Delay1_DSTATE_a;              // '<S402>/Delay1'
  real_T Delay1_DSTATE_jh;             // '<S404>/Delay1'
  real_T Delay1_DSTATE_h5;             // '<S400>/Delay1'
  int8_T ThisIFblockdetermineswhetherorn;
  // '<S10>/This IF block determines whether or not to run the BLACK sim//exp'
  int8_T ThisIFblockdetermineswhethero_j;
    // '<S10>/This IF block determines whether or not to run the BLUE sim//exp'
  int8_T ThisIFblockdetermineswhethero_a;
    // '<S10>/This IF block determines whether or not to run the RED sim//exp '
  int8_T ifwewentthroughastep_ActiveSubs;// '<S427>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_c;// '<S429>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_m;// '<S431>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_i;// '<S415>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_p;// '<S417>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_k;// '<S413>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_a;// '<S402>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_l;// '<S404>/if we went through a "step"' 
  int8_T ifwewentthroughastep_ActiveSu_d;// '<S400>/if we went through a "step"' 
  boolean_T icLoad;                    // '<S427>/Delay1'
  boolean_T icLoad_g;                  // '<S429>/Delay1'
  boolean_T icLoad_d;                  // '<S431>/Delay1'
  boolean_T icLoad_e;                  // '<S443>/Delay1'
  boolean_T icLoad_gp;                 // '<S441>/Delay1'
  boolean_T icLoad_k;                  // '<S445>/Delay1'
  boolean_T icLoad_c;                  // '<S415>/Delay1'
  boolean_T icLoad_p;                  // '<S417>/Delay1'
  boolean_T icLoad_j;                  // '<S413>/Delay1'
  boolean_T icLoad_f;                  // '<S402>/Delay1'
  boolean_T icLoad_jl;                 // '<S404>/Delay1'
  boolean_T icLoad_ca;                 // '<S400>/Delay1'
};

// Block signals for system '<S610>/MATLAB Function10'
struct B_MATLABFunction10_APF_Path_P_T {
  real_T PWMs[8];
  real_T positives_only[8];
};

// Block signals (default storage)
struct B_APF_Path_Planning_2023a_Blu_T {
  real_T w_m[169];
  real_T w_c[169];
  real_T X_Cal[78];
  real_T X_Cal_k1[78];
  real_T c_x[78];
  real_T c_x_m[78];
  real_T b_u1[65];
  real_T y[64];
  real_T y_c[64];
  real_T y_k[64];
  real_T y_cx[64];
  real_T Z_Cal[39];
  real_T d_x[39];
  real_T Z_Cal_b[39];
  real_T V[36];
  real_T U[36];
  real_T sigma[36];
  real_T IC[36];
  real_T b_A[36];
  real_T b_A_p[36];
  real_T b_A_c[36];
  real_T Vf[36];
  real_T Product2_m[24];               // '<S652>/Product2'
  real_T Product1_e[24];               // '<S619>/Product1'
  real_T Product1_it[24];              // '<S631>/Product1'
  real_T Merge1_d[24];                 // '<S634>/Merge1'
  real_T transpose[24];                // '<S652>/transpose'
  real_T b[24];
  real_T b_f[24];
  real_T Product2[24];                 // '<S631>/Product2'
  real_T Product2_n[24];               // '<S619>/Product2'
  real_T B[18];
  real_T X_Cal_g[18];
  real_T v_g[13];
  real_T b_v[13];
  creal_T unusedExpr[6];
  real_T TmpSignalConversionAtUDPSendInp[10];
  real_T rtb_Black_Measurments_table_r_m[9];
  real_T rtb_Product2_m_n[9];
  real_T Product2_b[9];                // '<S634>/Product2'
  real_T x[9];
  real_T ThrustPer_Final[8];           // '<S634>/MATLAB Function2'
  real_T ThrustPer_Final_e[8];         // '<S622>/MATLAB Function2'
  real_T ThrustPer_Final_d[8];         // '<S610>/MATLAB Function1'
  real_T rtb_Product_p[8];
  real_T fill[6];
  real_T state_red[6];
  real_T IC1[6];
  real_T a__3[6];
  real_T wi[6];
  real_T wr[6];
  real_T wi_l[6];
  real_T b_s[6];
  real_T e[6];
  real_T work[6];
  real_T work_j[6];
  real_T b_x_data[5];
  real_T e_d[5];
  real_T tau[5];
  real_T tau_g[5];
  real_T rtb_C_Ib_l[4];
  real_T Z_k[3];
  real_T r_co[3];
  real_T TmpSignalConversionAtSFunct[3];// '<S347>/Ryan's Transform'
  real_T x_ddot[3];                    // '<S593>/MATLAB Function'
  real_T path_m[3];                    // '<S364>/MATLAB Function1'
  real_T dv[3];
  real_T dv1[3];
  real_T state_red_d[3];
  real_T v_dy[3];
  real_T rtb_Oy_f_l[2];
  real_T rtb_Ox_g4_o[2];
  real_T rtb_Ox_p_b[2];
  real_T Sum;                          // '<S247>/Sum'
  real_T Sum1;                         // '<S247>/Sum1'
  real_T Sum3[3];                      // '<S368>/Sum3'
  real_T Sum_n[3];                     // '<S369>/Sum'
  real_T e_out;                        // '<S351>/MATLAB Function4'
  real_T Eg[3];                        // '<S370>/MATLAB Function1'
  real_T m[3];                         // '<S366>/MATLAB Function1'
  real_T v[3];                         // '<S366>/MATLAB Function1'
  real_T m_b[3];                       // '<S365>/MATLAB Function1'
  real_T v_d;                          // '<S365>/MATLAB Function1'
  real_T Gt[3];                        // '<S364>/MATLAB Function1'
  real_T Eg_n[3];                      // '<S363>/MATLAB Function1'
  real_T Etheta[3];                    // '<S363>/MATLAB Function1'
  real_T k1_dot;                       // '<S349>/Torque Gain Derivatives'
  real_T k2_dot;                       // '<S349>/Torque Gain Derivatives'
  real_T k2_dot_a;                     // '<S349>/Fy Gain Derivatives'
  real_T k1_dot_j;                     // '<S349>/Fy Gain Derivatives'
  real_T k2_dot_d;                     // '<S349>/Fx Gain Derivatives'
  real_T k1_dot_e;                     // '<S349>/Fx Gain Derivatives'
  real_T States[6];                    // '<S356>/MATLAB Function'
  real_T P_K[36];                      // '<S356>/MATLAB Function'
  real_T Subtract;                     // '<S246>/Subtract'
  real_T Subtract2;                    // '<S246>/Subtract2'
  real_T e_out_p;                      // '<S317>/MATLAB Function4'
  real_T In1;                          // '<S328>/In1'
  real_T In1_g;                        // '<S326>/In1'
  real_T In1_g2;                       // '<S324>/In1'
  real_T Subtract_c;                   // '<S162>/Subtract'
  real_T Subtract1;                    // '<S162>/Subtract1'
  real_T e_out_i;                      // '<S189>/MATLAB Function4'
  real_T In1_g20;                      // '<S198>/In1'
  real_T In1_g20a;                     // '<S196>/In1'
  real_T In1_g20as;                    // '<S194>/In1'
  real_T Subtract_k;                   // '<S93>/Subtract'
  real_T Subtract1_l;                  // '<S93>/Subtract1'
  real_T e_out_b;                      // '<S148>/MATLAB Function4'
  real_T In1_g20asd;                   // '<S157>/In1'
  real_T In1_g20asdt;                  // '<S155>/In1'
  real_T In1_g20asdtg;                 // '<S153>/In1'
  real_T Subtract_j;                   // '<S35>/Subtract'
  real_T Subtract1_n;                  // '<S35>/Subtract1'
  real_T e_out_k;                      // '<S65>/MATLAB Function4'
  real_T In1_g20asdtgi;                // '<S72>/In1'
  real_T In1_g20asdtgi0;               // '<S70>/In1'
  real_T In1_g20asdtgi0c;              // '<S68>/In1'
  real_T Subtract_d;                   // '<S33>/Subtract'
  real_T Subtract1_g;                  // '<S33>/Subtract1'
  real_T e_out_m;                      // '<S39>/MATLAB Function4'
  real_T In1_g20asdtgi0cd;             // '<S45>/In1'
  real_T In1_g20asdtgi0cdy;            // '<S43>/In1'
  real_T In1_g20asdtgi0cdyi;           // '<S41>/In1'
  real_T Subtract_n;                   // '<S34>/Subtract'
  real_T Subtract1_ld;                 // '<S34>/Subtract1'
  real_T e_out_md;                     // '<S52>/MATLAB Function4'
  real_T In1_g20asdtgi0cdyix;          // '<S58>/In1'
  real_T In1_e;                        // '<S56>/In1'
  real_T In1_o;                        // '<S54>/In1'
  real_T TmpSignalConversionAtUDPSendI_o[19];
  real_T UDPReceive1_o1[10];           // '<S505>/UDP Receive1'
  real_T ConvertREDXfrommmtom;        // '<S505>/Convert REDX from [mm] to [m]'
  real_T ConvertBLUXfrommmtom;        // '<S505>/Convert BLUX from [mm] to [m]'
  real_T dividebydeltaT;               // '<S515>/divide by delta T'
  real_T ConvertBLAXfrommmtom;        // '<S505>/Convert BLAX from [mm] to [m]'
  real_T dividebydeltaT_f;             // '<S520>/divide by delta T'
  real_T ConvertBLAYfrommmtom;        // '<S505>/Convert BLAY from [mm] to [m]'
  real_T dividebydeltaT_l;             // '<S521>/divide by delta T'
  real_T Unwrap1;                      // '<S505>/Unwrap1'
  real_T dividebydeltaT_e;             // '<S522>/divide by delta T'
  real_T ConvertBLUYfrommmtom;        // '<S505>/Convert BLUY from [mm] to [m]'
  real_T dividebydeltaT_c;             // '<S516>/divide by delta T'
  real_T Unwrap2;                      // '<S505>/Unwrap2'
  real_T dividebydeltaT_cy;            // '<S517>/divide by delta T'
  real_T dividebydeltaT_n;             // '<S508>/divide by delta T'
  real_T ConvertREDYfrommmtom;        // '<S505>/Convert REDY from [mm] to [m]'
  real_T dividebydeltaT_n1;            // '<S518>/divide by delta T'
  real_T Unwrap;                       // '<S505>/Unwrap'
  real_T dividebydeltaT_m;             // '<S519>/divide by delta T'
  real_T In1_e0;                       // '<S545>/In1'
  real_T In1_l;                        // '<S544>/In1'
  real_T In1_f;                        // '<S543>/In1'
  real_T In1_eg;                       // '<S542>/In1'
  real_T In1_b;                        // '<S541>/In1'
  real_T In1_m;                        // '<S540>/In1'
  real_T In1_en;                       // '<S539>/In1'
  real_T In1_em;                       // '<S538>/In1'
  real_T In1_gd;                       // '<S537>/In1'
  real_T In1_fy;                       // '<S536>/In1'
  real_T In1_lk;                       // '<S535>/In1'
  real_T In1_a;                        // '<S531>/In1'
  real_T In1_c;                        // '<S530>/In1'
  real_T In1_p;                        // '<S529>/In1'
  real_T In1_gt;                       // '<S528>/In1'
  real_T Subtract_l;                   // '<S527>/Subtract'
  real_T Memory;                       // '<S526>/Memory'
  real_T In1_aw;                       // '<S606>/In1'
  real_T In1_g0;                       // '<S605>/In1'
  real_T In1_fv;                       // '<S604>/In1'
  real_T In1_h;                        // '<S603>/In1'
  real_T In1_ff;                       // '<S602>/In1'
  real_T In1_n;                        // '<S601>/In1'
  real_T In1_hq;                       // '<S591>/In1'
  real_T In1_pj;                       // '<S590>/In1'
  real_T In1_a4;                       // '<S589>/In1'
  real_T In1_ir;                       // '<S579>/In1'
  real_T In1_cz;                       // '<S575>/In1'
  real_T In1_ex;                       // '<S574>/In1'
  real_T In1_j;                        // '<S565>/In1'
  real_T In1_ib;                       // '<S564>/In1'
  real_T In1_pg;                       // '<S563>/In1'
  real_T In1_d;                        // '<S562>/In1'
  real_T In1_c5;                       // '<S561>/In1'
  real_T In1_pk;                       // '<S560>/In1'
  real_T link1_com_x;
  real_T link1_com_y;
  real_T sampleTime;
  real_T sampleTime_n;
  real_T sampleTime_b;
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
  real_T t34;
  real_T t35;
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
  real_T q;
  real_T alpha_pol;
  real_T varargin_1_data;
  real_T absxk;
  real_T t;
  real_T Sum6_a;                       // '<S154>/Sum6'
  real_T Derivative2;                  // '<S349>/Derivative2'
  real_T Switch;                       // '<S247>/Switch'
  real_T isSim;
  real_T RED_Tz_RW;
  real_T rtb_path_o_idx_1;
  real_T absx_tmp;
  real_T t112_tmp;
  real_T t12_tmp;
  real_T t99_tmp;
  real_T t99_tmp_l;
  real_T t51_tmp;
  real_T t99_tmp_h;
  real_T t99_tmp_b;
  real_T t99_tmp_d;
  real_T t81_tmp;
  real_T t113_tmp;
  real_T t114_tmp;
  real_T t115_tmp;
  real_T t99_tmp_e;
  real_T t114_tmp_tmp;
  real_T t113_tmp_tmp;
  real_T t63_tmp;
  real_T rtb_path_m_tmp;
  real_T rtb_path_idx_1;
  real_T rtb_Sum6_a_tmp;
  real_T anrm;
  real_T absx;
  real_T temp1;
  real_T temp2;
  real_T tau_tmp;
  real_T anrm_b;
  real_T absxk_j;
  real_T c;
  real_T r;
  real_T g;
  real_T s;
  real_T scale;
  real_T b_absxk;
  real_T t_f;
  real_T y_a;
  real_T y_j;
  real_T smlnum;
  real_T tst;
  real_T aa;
  real_T s_j;
  real_T h11;
  real_T h12;
  real_T tr;
  real_T h21s;
  real_T sum;
  real_T s_tmp;
  real_T temp;
  real_T p;
  real_T bcmax;
  real_T bcmis;
  real_T scale_o;
  real_T z;
  real_T a;
  real_T b_n;
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
  real_T scale_oy;
  real_T ads;
  real_T bds;
  real_T alpha1;
  real_T temp_n;
  real_T tau_m;
  real_T xnorm;
  real_T a_c;
  real_T scale_m;
  real_T absxk_m;
  real_T t_j;
  real_T anorm;
  real_T p_h;
  real_T rte;
  real_T r_c;
  real_T c_c;
  real_T s_p;
  real_T b_gamma;
  real_T oldc;
  real_T b_anorm;
  real_T cfromc;
  real_T ctoc;
  real_T cfrom1;
  real_T cto1;
  real_T mul;
  real_T absx11;
  real_T absx21;
  real_T absx31;
  real_T cfromc_p;
  real_T ctoc_a;
  real_T cfrom1_e;
  real_T cto1_a;
  real_T mul_a;
  real_T cfromc_i;
  real_T ctoc_l;
  real_T cfrom1_o;
  real_T cto1_o;
  real_T mul_i;
  real_T sm;
  real_T adf;
  real_T ab;
  real_T acmx;
  real_T acmn;
  real_T scale_f;
  real_T absxk_i;
  real_T t_ff;
  real_T scale_g;
  real_T absxk_c;
  real_T t_o;
  real_T temp_tmp;
  real_T temp_tmp_l;
  real_T sr;
  real_T si;
  real_T xc;
  real_T d;
  real_T scale_mv;
  real_T absxk_mj;
  real_T t_c;
  real_T temp_f;
  real_T d1;
  real_T d2;
  int32_T b_x_size[2];
  real32_T ByteUnpack_o1;              // '<S2>/Byte Unpack'
  real32_T ByteUnpack_o2;              // '<S2>/Byte Unpack'
  real32_T ByteUnpack_o3;              // '<S2>/Byte Unpack'
  int32_T UDPReceive_o1;               // '<S505>/UDP Receive'
  int32_T UDPReceive2_o1;              // '<S505>/UDP Receive2'
  int32_T UDPReceive3_o1;              // '<S505>/UDP Receive3'
  uint8_T UDPReceive1_o1_k[12];        // '<S2>/UDP Receive1'
  int32_T r_p;
  int32_T ar;
  int32_T b_j;
  int32_T d_e;
  int32_T xoffset;
  int32_T b_xoffset;
  int32_T yElIdx;
  int32_T uElOffset1;
  int32_T ntIdx1;
  int32_T ntIdx0;
  int32_T StartClock;                  // '<S505>/MATLAB Function'
  int32_T i;
  int32_T i_o;
  int32_T loop_ub;
  int32_T sigma_tmp;
  int32_T i_h;
  int32_T c_i;
  int32_T k;
  int32_T b_jj;
  int32_T ii;
  int32_T temp1_tmp;
  int32_T tau_tmp_l;
  int32_T tau_tmp_tmp;
  int32_T d_tmp;
  int32_T b_k;
  int32_T ica;
  int32_T ira;
  int32_T d_i;
  int32_T kend;
  int32_T f_k;
  int32_T d_iy;
  int32_T i_h2;
  int32_T c_temp_tmp;
  int32_T kdefl;
  int32_T l;
  int32_T k_m;
  int32_T b_m;
  int32_T nr;
  int32_T b_i;
  int32_T its;
  int32_T n;
  int32_T ix0;
  int32_T knt;
  int32_T s_tmp_m;
  int32_T h_tmp;
  int32_T count;
  int32_T i_h3;
  int32_T qp1;
  int32_T qq;
  int32_T qjj;
  int32_T qs;
  int32_T e_k;
  int32_T i_c;
  int32_T in;
  int32_T b_kl;
  int32_T lastv;
  int32_T lastc;
  int32_T b_lastv;
  int32_T ix;
  int32_T d_p;
  int32_T e_p;
  int32_T ia;
  int32_T rowleft;
  int32_T b_ia;
  int32_T b_tmp;
  int32_T knt_p;
  int32_T c_a;
  int32_T d_tmp_j;
  int32_T kend_e;
  int32_T k_o;
  int32_T jtot;
  int32_T l1;
  int32_T b_m_b;
  int32_T l_a;
  int32_T lsv;
  int32_T lend;
  int32_T iscale;
  int32_T lendsv_tmp;
  int32_T b_anorm_tmp;
  int32_T n_tmp;
  int32_T b_i_g;
  int32_T i1;
  int32_T p1;
  int32_T p2;
  int32_T p3;
  int32_T itmp;
  int32_T b_i_e;
  int32_T i2;
  int32_T i3;
  int32_T kend_f;
  int32_T k_h;
  int32_T kend_ei;
  int32_T k_c;
  int32_T k_a;
  int32_T temp_tmp_tmp;
  int32_T temp_tmp_tmp_d;
  int32_T idx;
  int32_T k_af;
  int32_T k_p;
  int32_T temp_tmp_m;
  int32_T i4;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T i5;
  int32_T loop_ub_o;
  int32_T k_n;
  int32_T i6;
  int32_T b_l;
  int32_T k_pe;
  int32_T k_pt;
  int32_T i7;
  int32_T k_f;
  int32_T i8;
  int32_T i9;
  int32_T i10;
  uint32_T lo;
  uint32_T hi;
  boolean_T rEQ0;
  boolean_T tmp_data;
  boolean_T Reject;
  boolean_T iscale_i;
  boolean_T scalea;
  boolean_T notdone;
  boolean_T skipThisColumn;
  boolean_T converged;
  boolean_T b_o;
  boolean_T b1;
  boolean_T apply_transform;
  boolean_T notdone_k;
  boolean_T notdone_i;
  boolean_T notdone_o;
  B_MATLABFunction10_APF_Path_P_T sf_MATLABFunction5;// '<S634>/MATLAB Function5' 
  B_MATLABFunction10_APF_Path_P_T sf_MATLABFunction6;// '<S622>/MATLAB Function6' 
  B_MATLABFunction10_APF_Path_P_T sf_MATLABFunction10;// '<S610>/MATLAB Function10' 
  B_Phase4ReturnHome_APF_Path_P_T Phase5HoldHome;// '<Root>/Phase #5: Hold Home' 
  B_Phase4ReturnHome_APF_Path_P_T Phase4ReturnHome;// '<Root>/Phase #4: Return Home' 
  B_SimulatedPositionController_T SimulatedPositionController;
                                      // '<S354>/Simulated Position Controller'
  B_REDARM_APF_Path_Planning_20_T REDARM_m;// '<S246>/RED+ARM'
  B_SubPhase1_APF_Path_Planni_i_T SubPhase2_p;// '<S89>/Sub-Phase #2 '
  B_SubPhase1_APF_Path_Planni_i_T SubPhase1_p;// '<S89>/Sub-Phase #1'
  B_SubPhase1_APF_Path_Planni_n_T SubPhase3_e;// '<S88>/Sub-Phase #3 '
  B_SubPhase1_APF_Path_Planni_n_T SubPhase2_c;// '<S88>/Sub-Phase #2 '
  B_SubPhase1_APF_Path_Planni_n_T SubPhase1_g;// '<S88>/Sub-Phase #1'
  B_SubPhase1_APF_Path_Planning_T SubPhase3;// '<S87>/Sub-Phase #3 '
  B_SubPhase1_APF_Path_Planning_T SubPhase2;// '<S87>/Sub-Phase #2 '
  B_SubPhase1_APF_Path_Planning_T SubPhase1;// '<S87>/Sub-Phase #1'
  B_REDARM_APF_Path_Planning_20_T REDARM_e;// '<S35>/RED+ARM'
};

// Block states (default storage) for system '<Root>'
struct DW_APF_Path_Planning_2023a_Bl_T {
  Dynamixel_Controller_APF_Path_T obj;
  // '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
  GPIO_Write_APF_Path_Planning__T obj_p;// '<S25>/Set Pin 428 (Pucks) to HIGH'
  ReadArm_Position_Rates_APF_Pa_T obj_d;
                      // '<S26>/Read Joint Positions using  Dynamixel Encoders'
  IdentifyPlatform_APF_Path_Pla_T obj_dk;// '<S546>/WhoAmI'
  CustomDataLogger_APF_Path_Pla_T obj_i;// '<S23>/MATLAB System'
  real_T Delay1_DSTATE[6];             // '<S356>/Delay1'
  real_T Delay_DSTATE[36];             // '<S356>/Delay'
  real_T Delay_DSTATE_c[3];            // '<S368>/Delay'
  real_T Delay_DSTATE_o[3];            // '<S369>/Delay'
  real_T Delay3_DSTATE[3];             // '<S364>/Delay3'
  real_T Delay_DSTATE_d[3];            // '<S363>/Delay'
  real_T Delay1_DSTATE_n[3];           // '<S363>/Delay1'
  real_T Delay3_DSTATE_d[3];           // '<S370>/Delay3'
  real_T Delay3_DSTATE_a[3];           // '<S366>/Delay3'
  real_T Delay1_DSTATE_d[3];           // '<S366>/Delay1'
  real_T Delay3_DSTATE_j[3];           // '<S365>/Delay3'
  real_T Delay1_DSTATE_l;              // '<S365>/Delay1'
  real_T DiscreteTimeIntegrator4_DSTATE;// '<S349>/Discrete-Time Integrator4'
  real_T DiscreteTimeIntegrator5_DSTATE;// '<S349>/Discrete-Time Integrator5'
  real_T DiscreteTimeIntegrator2_DSTATE;// '<S349>/Discrete-Time Integrator2'
  real_T DiscreteTimeIntegrator3_DSTATE;// '<S349>/Discrete-Time Integrator3'
  real_T DiscreteTimeIntegrator1_DSTATE;// '<S349>/Discrete-Time Integrator1'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S349>/Discrete-Time Integrator'
  real_T Delay1_DSTATE_da;             // '<S323>/Delay1'
  real_T Delay1_DSTATE_d3;             // '<S325>/Delay1'
  real_T Delay1_DSTATE_g;              // '<S327>/Delay1'
  real_T StartPos_DSTATE;              // '<S190>/Start Pos'
  real_T Delay1_DSTATE_a;              // '<S195>/Delay1'
  real_T StartPos_DSTATE_n;            // '<S191>/Start Pos'
  real_T Delay1_DSTATE_j;              // '<S197>/Delay1'
  real_T StartPos_DSTATE_f;            // '<S192>/Start Pos'
  real_T Delay1_DSTATE_e;              // '<S193>/Delay1'
  real_T StartPos_DSTATE_p;            // '<S149>/Start Pos'
  real_T Delay1_DSTATE_p;              // '<S154>/Delay1'
  real_T StartPos_DSTATE_b;            // '<S150>/Start Pos'
  real_T Delay1_DSTATE_na;             // '<S156>/Delay1'
  real_T StartPos_DSTATE_l;            // '<S151>/Start Pos'
  real_T Delay1_DSTATE_p2;             // '<S152>/Delay1'
  real_T Delay1_DSTATE_gi;             // '<S67>/Delay1'
  real_T Delay1_DSTATE_m;              // '<S69>/Delay1'
  real_T Delay1_DSTATE_ej;             // '<S71>/Delay1'
  real_T Delay1_DSTATE_i;              // '<S42>/Delay1'
  real_T Delay1_DSTATE_c;              // '<S44>/Delay1'
  real_T Delay1_DSTATE_c1;             // '<S40>/Delay1'
  real_T Delay1_DSTATE_mw;             // '<S55>/Delay1'
  real_T Delay1_DSTATE_et;             // '<S57>/Delay1'
  real_T Delay1_DSTATE_av;             // '<S53>/Delay1'
  real_T Delay1_DSTATE_eo;             // '<S515>/Delay1'
  real_T Delay1_DSTATE_gs;             // '<S512>/Delay1'
  real_T Delay1_DSTATE_b;              // '<S520>/Delay1'
  real_T Delay1_DSTATE_p4;             // '<S509>/Delay1'
  real_T Delay1_DSTATE_md;             // '<S521>/Delay1'
  real_T Delay1_DSTATE_ju;             // '<S510>/Delay1'
  real_T Delay1_DSTATE_p4s;            // '<S522>/Delay1'
  real_T Delay1_DSTATE_k;              // '<S511>/Delay1'
  real_T Delay1_DSTATE_mi;             // '<S516>/Delay1'
  real_T Delay1_DSTATE_pc;             // '<S513>/Delay1'
  real_T Delay1_DSTATE_cu;             // '<S517>/Delay1'
  real_T Delay1_DSTATE_a0;             // '<S514>/Delay1'
  real_T Delay1_DSTATE_h;              // '<S508>/Delay1'
  real_T Delay1_DSTATE_ah;             // '<S523>/Delay1'
  real_T Delay1_DSTATE_lx;             // '<S518>/Delay1'
  real_T Delay1_DSTATE_j3;             // '<S524>/Delay1'
  real_T Delay1_DSTATE_m2;             // '<S519>/Delay1'
  real_T Delay1_DSTATE_hi;             // '<S525>/Delay1'
  real_T Delay_DSTATE_a;               // '<S26>/Delay'
  real_T Delay1_DSTATE_pw;             // '<S26>/Delay1'
  real_T Delay2_DSTATE;                // '<S26>/Delay2'
  real_T AccelerationtoVelocity_DSTATE[3];// '<S552>/Acceleration  to Velocity'
  real_T VelocitytoPosition_DSTATE[3]; // '<S552>/Velocity to Position'
  real_T Delay1_DSTATE_f;              // '<S558>/Delay1'
  real_T Delay1_DSTATE_lg;             // '<S555>/Delay1'
  real_T Delay1_DSTATE_d3a;            // '<S553>/Delay1'
  real_T Delay1_DSTATE_ea;             // '<S556>/Delay1'
  real_T Delay1_DSTATE_cx;             // '<S554>/Delay1'
  real_T Delay1_DSTATE_ab;             // '<S557>/Delay1'
  real_T AccelerationtoVelocity_DSTATE_i[3];// '<S566>/Acceleration  to Velocity' 
  real_T VelocitytoPosition_DSTATE_a[3];// '<S566>/Velocity to Position'
  real_T Delay1_DSTATE_gv;             // '<S572>/Delay1'
  real_T Delay1_DSTATE_ds;             // '<S569>/Delay1'
  real_T Delay1_DSTATE_i5;             // '<S567>/Delay1'
  real_T Delay1_DSTATE_l0;             // '<S570>/Delay1'
  real_T Delay1_DSTATE_iq;             // '<S568>/Delay1'
  real_T Delay1_DSTATE_eq;             // '<S571>/Delay1'
  real_T AccelerationtoVelocity_DSTATE_b[3];// '<S593>/Acceleration  to Velocity' 
  real_T VelocitytoPosition_DSTATE_m[3];// '<S593>/Velocity to Position'
  real_T Delay1_DSTATE_n2;             // '<S595>/Delay1'
  real_T Delay1_DSTATE_pc3;            // '<S597>/Delay1'
  real_T Delay1_DSTATE_k4;             // '<S594>/Delay1'
  real_T Delay1_DSTATE_dh;             // '<S598>/Delay1'
  real_T Delay1_DSTATE_lh;             // '<S596>/Delay1'
  real_T Delay1_DSTATE_jb;             // '<S599>/Delay1'
  real_T Delay_DSTATE_of[12];          // '<S582>/Delay'
  real_T AccelerationtoVelocity_DSTATE_f[12];// '<S582>/Acceleration  to Velocity' 
  real_T Delay1_DSTATE_by;             // '<S587>/Delay1'
  real_T Delay1_DSTATE_ny;             // '<S586>/Delay1'
  real_T Delay1_DSTATE_nb;             // '<S588>/Delay1'
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
  real_T BLACK_Py;                     // '<Root>/BLACK_Py'
  real_T BLUE_Py;                      // '<Root>/BLACK_Py1'
  real_T BLACK_Py_Est;                 // '<Root>/BLACK_Py2'
  real_T BLACK_Py_preKalm;             // '<Root>/BLACK_Py3'
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
  real_T RED_Elbow_Command;            // '<Root>/Universal_Time21'
  real_T RED_Wrist_Command;            // '<Root>/Universal_Time22'
  real_T RED_RzD;                      // '<Root>/Universal_Time3'
  real_T BLACK_Vx;                     // '<Root>/Universal_Time4'
  real_T BLACK_Vy;                     // '<Root>/Universal_Time5'
  real_T BLACK_RzD;                    // '<Root>/Universal_Time6'
  real_T BLUE_Vx;                      // '<Root>/Universal_Time7'
  real_T BLUE_Vy;                      // '<Root>/Universal_Time8'
  real_T BLUE_RzD;                     // '<Root>/Universal_Time9'
  real_T Product1_DWORK4[9];           // '<S651>/Product1'
  real_T Product1_DWORK4_a[9];         // '<S652>/Product1'
  real_T Product1_DWORK4_av[9];        // '<S630>/Product1'
  real_T Product1_DWORK4_g[9];         // '<S631>/Product1'
  real_T Product1_DWORK4_m[9];         // '<S618>/Product1'
  real_T Product1_DWORK4_f[9];         // '<S619>/Product1'
  real_T TimeStampA;                   // '<S349>/Derivative2'
  real_T LastUAtTimeA;                 // '<S349>/Derivative2'
  real_T TimeStampB;                   // '<S349>/Derivative2'
  real_T LastUAtTimeB;                 // '<S349>/Derivative2'
  real_T TimeStampA_n;                 // '<S349>/Derivative1'
  real_T LastUAtTimeA_d;               // '<S349>/Derivative1'
  real_T TimeStampB_h;                 // '<S349>/Derivative1'
  real_T LastUAtTimeB_l;               // '<S349>/Derivative1'
  real_T TimeStampA_m;                 // '<S349>/Derivative3'
  real_T LastUAtTimeA_m;               // '<S349>/Derivative3'
  real_T TimeStampB_a;                 // '<S349>/Derivative3'
  real_T LastUAtTimeB_k;               // '<S349>/Derivative3'
  real_T UDPSend_NetworkLib_m[137];    // '<S548>/UDP Send'
  real_T UDPReceive1_NetworkLib_b[137];// '<S505>/UDP Receive1'
  real_T Unwrap1_Prev;                 // '<S505>/Unwrap1'
  real_T Unwrap1_Cumsum;               // '<S505>/Unwrap1'
  real_T Unwrap2_Prev;                 // '<S505>/Unwrap2'
  real_T Unwrap2_Cumsum;               // '<S505>/Unwrap2'
  real_T Unwrap_Prev;                  // '<S505>/Unwrap'
  real_T Unwrap_Cumsum;                // '<S505>/Unwrap'
  real_T UDPReceive_NetworkLib[137];   // '<S505>/UDP Receive'
  real_T UDPReceive2_NetworkLib[137];  // '<S505>/UDP Receive2'
  real_T UDPReceive3_NetworkLib[137];  // '<S505>/UDP Receive3'
  real_T Memory_PreviousInput;         // '<S526>/Memory'
  real_T NextOutput;                   // '<S552>/Random Number'
  real_T NextOutput_b;                 // '<S549>/Random Number1'
  real_T NextOutput_j;                 // '<S549>/Random Number'
  real_T NextOutput_g;                 // '<S549>/Random Number2'
  real_T NextOutput_a;                 // '<S566>/Random Number'
  real_T NextOutput_i;                 // '<S593>/Random Number'
  real_T NextOutput_n;                 // '<S592>/Random Number7'
  real_T NextOutput_ga;                // '<S592>/Random Number6'
  real_T NextOutput_l;                 // '<S592>/Random Number8'
  real_T NextOutput_f;                 // '<S582>/Random Number2'
  real_T NextOutput_h;                 // '<S582>/Random Number1'
  real_T NextOutput_go;                // '<S582>/Random Number3'
  real_T UDPSend_NetworkLib_l[137];    // '<S22>/UDP Send'
  int32_T Delay_DSTATE_l[5];           // '<S505>/Delay'
  int32_T Delay1_DSTATE_hu[5];         // '<S505>/Delay1'
  int32_T Delay2_DSTATE_k[5];          // '<S505>/Delay2'
  uint32_T RandSeed;                   // '<S552>/Random Number'
  uint32_T RandSeed_n;                 // '<S549>/Random Number1'
  uint32_T RandSeed_g;                 // '<S549>/Random Number'
  uint32_T RandSeed_m;                 // '<S549>/Random Number2'
  uint32_T RandSeed_o;                 // '<S566>/Random Number'
  uint32_T RandSeed_n0;                // '<S550>/Random Number4'
  uint32_T RandSeed_e;                 // '<S550>/Random Number3'
  uint32_T RandSeed_c;                 // '<S550>/Random Number5'
  uint32_T RandSeed_k;                 // '<S593>/Random Number'
  uint32_T RandSeed_a;                 // '<S592>/Random Number7'
  uint32_T RandSeed_f;                 // '<S592>/Random Number6'
  uint32_T RandSeed_h;                 // '<S592>/Random Number8'
  uint32_T RandSeed_av;                // '<S582>/Random Number2'
  uint32_T RandSeed_a4;                // '<S582>/Random Number1'
  uint32_T RandSeed_i;                 // '<S582>/Random Number3'
  int8_T SeparatePhases_ActiveSubsystem;// '<Root>/Separate Phases'
  int8_T Ifperforminganexperimentgrabthe;
  // '<S13>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 
  int8_T ThisIFblockdetermineswhethero_n;
    // '<S9>/This IF block determines whether or not to run the BLACK sim//exp'
  int8_T ThisIFblockdetermineswhethero_a;
     // '<S9>/This IF block determines whether or not to run the BLUE sim//exp'
  int8_T ThisIFblockdetermineswhether_fg;
     // '<S9>/This IF block determines whether or not to run the RED sim//exp '
  int8_T ExperimentSubPhases_ActiveSubsy;// '<S89>/Experiment Sub-Phases'
  int8_T ExperimentSubPhases_ActiveSub_c;// '<S88>/Experiment Sub-Phases'
  int8_T ExperimentSubPhases_ActiveSub_l;// '<S87>/Experiment Sub-Phases'
  int8_T ThisIFblockdetermineswhether_l2;
     // '<S8>/This IF block determines whether or not to run the BLUE sim//exp'
  int8_T ThisIFblockdetermineswhethero_h;
    // '<S8>/This IF block determines whether or not to run the BLACK sim//exp'
  int8_T ThisIFblockdetermineswhethero_g;
     // '<S8>/This IF block determines whether or not to run the RED sim//exp '
  boolean_T IC1_FirstOutputTime;       // '<S356>/IC1'
  boolean_T IC_FirstOutputTime;        // '<S356>/IC'
  boolean_T icLoad;                    // '<S323>/Delay1'
  boolean_T icLoad_f;                  // '<S325>/Delay1'
  boolean_T icLoad_i;                  // '<S327>/Delay1'
  boolean_T icLoad_e;                  // '<S195>/Delay1'
  boolean_T icLoad_fr;                 // '<S197>/Delay1'
  boolean_T icLoad_iy;                 // '<S193>/Delay1'
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
  boolean_T icLoad_l;                  // '<S515>/Delay1'
  boolean_T icLoad_ld;                 // '<S512>/Delay1'
  boolean_T icLoad_d;                  // '<S520>/Delay1'
  boolean_T icLoad_k;                  // '<S509>/Delay1'
  boolean_T icLoad_fv;                 // '<S521>/Delay1'
  boolean_T icLoad_na;                 // '<S510>/Delay1'
  boolean_T Unwrap1_FirstStep;         // '<S505>/Unwrap1'
  boolean_T icLoad_gx;                 // '<S522>/Delay1'
  boolean_T icLoad_m;                  // '<S511>/Delay1'
  boolean_T icLoad_eo;                 // '<S516>/Delay1'
  boolean_T icLoad_fpv;                // '<S513>/Delay1'
  boolean_T Unwrap2_FirstStep;         // '<S505>/Unwrap2'
  boolean_T icLoad_mt;                 // '<S517>/Delay1'
  boolean_T icLoad_nw;                 // '<S514>/Delay1'
  boolean_T icLoad_h;                  // '<S508>/Delay1'
  boolean_T icLoad_au;                 // '<S523>/Delay1'
  boolean_T icLoad_eob;                // '<S518>/Delay1'
  boolean_T icLoad_fh;                 // '<S524>/Delay1'
  boolean_T Unwrap_FirstStep;          // '<S505>/Unwrap'
  boolean_T icLoad_fow;                // '<S519>/Delay1'
  boolean_T icLoad_aq;                 // '<S525>/Delay1'
  boolean_T icLoad_ou;                 // '<S558>/Delay1'
  boolean_T icLoad_p4;                 // '<S555>/Delay1'
  boolean_T icLoad_jc;                 // '<S553>/Delay1'
  boolean_T icLoad_jk;                 // '<S556>/Delay1'
  boolean_T icLoad_jr;                 // '<S554>/Delay1'
  boolean_T icLoad_jko;                // '<S557>/Delay1'
  boolean_T icLoad_do;                 // '<S572>/Delay1'
  boolean_T icLoad_nk;                 // '<S569>/Delay1'
  boolean_T icLoad_ip;                 // '<S567>/Delay1'
  boolean_T icLoad_az;                 // '<S570>/Delay1'
  boolean_T icLoad_dh;                 // '<S568>/Delay1'
  boolean_T icLoad_ex;                 // '<S571>/Delay1'
  boolean_T icLoad_nn;                 // '<S595>/Delay1'
  boolean_T icLoad_kb;                 // '<S597>/Delay1'
  boolean_T icLoad_jf;                 // '<S594>/Delay1'
  boolean_T icLoad_dk;                 // '<S598>/Delay1'
  boolean_T icLoad_l1;                 // '<S596>/Delay1'
  boolean_T icLoad_kp;                 // '<S599>/Delay1'
  boolean_T icLoad_bs;                 // '<S587>/Delay1'
  boolean_T icLoad_n5;                 // '<S586>/Delay1'
  boolean_T icLoad_mj;                 // '<S588>/Delay1'
  DW_Phase4ReturnHome_APF_Path__T Phase5HoldHome;// '<Root>/Phase #5: Hold Home' 
  DW_Phase4ReturnHome_APF_Path__T Phase4ReturnHome;// '<Root>/Phase #4: Return Home' 
  DW_SimulatedPositionControlle_T SimulatedPositionController;
                                      // '<S354>/Simulated Position Controller'
  DW_REDARM_APF_Path_Planning_2_T REDARM_m;// '<S246>/RED+ARM'
  DW_SubPhase1_APF_Path_Plann_m_T SubPhase2_p;// '<S89>/Sub-Phase #2 '
  DW_SubPhase1_APF_Path_Plann_m_T SubPhase1_p;// '<S89>/Sub-Phase #1'
  DW_SubPhase1_APF_Path_Plann_o_T SubPhase3_e;// '<S88>/Sub-Phase #3 '
  DW_SubPhase1_APF_Path_Plann_o_T SubPhase2_c;// '<S88>/Sub-Phase #2 '
  DW_SubPhase1_APF_Path_Plann_o_T SubPhase1_g;// '<S88>/Sub-Phase #1'
  DW_SubPhase1_APF_Path_Plannin_T SubPhase3;// '<S87>/Sub-Phase #3 '
  DW_SubPhase1_APF_Path_Plannin_T SubPhase2;// '<S87>/Sub-Phase #2 '
  DW_SubPhase1_APF_Path_Plannin_T SubPhase1;// '<S87>/Sub-Phase #1'
  DW_REDARM_APF_Path_Planning_2_T REDARM_e;// '<S35>/RED+ARM'
  DW_Phase0Synchronization_APF__T Phase1StartFloating;// '<Root>/Phase #1: Start Floating ' 
  DW_Phase0Synchronization_APF__T Phase0Synchronization;// '<Root>/Phase #0: Synchronization' 
  DW_ChangeBLACKBehavior_APF_Pa_T ChangeBLUEBehavior;// '<S1>/Change BLUE Behavior' 
  DW_ChangeBLACKBehavior_APF_Pa_T ChangeBLACKBehavior;// '<S1>/Change BLACK Behavior' 
};

// Parameters for system: '<S1>/Change BLACK Behavior'
struct P_ChangeBLACKBehavior_APF_Pat_T_ {
  int32_T Constant1_Value;             // Computed Parameter: Constant1_Value
                                          //  Referenced by: '<S20>/Constant1'

  int32_T UDPSend_Port;                // Computed Parameter: UDPSend_Port
                                          //  Referenced by: '<S20>/UDP Send'

};

// Parameters for system: '<S6>/Change BLUE Behavior'
struct P_ChangeBLUEBehavior_APF_Path_T_ {
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
struct P_Phase0Synchronization_APF_P_T_ {
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

  P_ChangeBLUEBehavior_APF_Path_T ChangeBLUEBehavior;// '<S6>/Change BLUE Behavior' 
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
struct P_REDARM_APF_Path_Planning_20_T_ {
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
struct P_SubPhase1_APF_Path_Planning_T_ {
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
struct P_SubPhase1_APF_Path_Planni_a_T_ {
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
struct P_SubPhase1_APF_Path_Planni_h_T_ {
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

  P_REDARM_APF_Path_Planning_20_T REDARM;// '<S244>/RED+ARM'
};

// Parameters for system: '<Root>/Phase #4: Return Home'
struct P_Phase4ReturnHome_APF_Path_P_T_ {
  real_T Out1_Y0;                      // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S401>/Out1'

  real_T Out1_Y0_k;                    // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S403>/Out1'

  real_T Out1_Y0_d;                    // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S405>/Out1'

  real_T PuckState_Value;              // Expression: 1
                                          //  Referenced by: '<S393>/Puck State'

  real_T Out1_Y0_b;                    // Computed Parameter: Out1_Y0_b
                                          //  Referenced by: '<S414>/Out1'

  real_T Out1_Y0_dv;                   // Computed Parameter: Out1_Y0_dv
                                          //  Referenced by: '<S416>/Out1'

  real_T Out1_Y0_p;                    // Computed Parameter: Out1_Y0_p
                                          //  Referenced by: '<S418>/Out1'

  real_T PuckState_Value_d;            // Expression: 1
                                          //  Referenced by: '<S394>/Puck State'

  real_T Out1_Y0_b3;                   // Computed Parameter: Out1_Y0_b3
                                          //  Referenced by: '<S428>/Out1'

  real_T Out1_Y0_b1;                   // Computed Parameter: Out1_Y0_b1
                                          //  Referenced by: '<S430>/Out1'

  real_T Out1_Y0_ba;                   // Computed Parameter: Out1_Y0_ba
                                          //  Referenced by: '<S432>/Out1'

  real_T Out1_Y0_c;                    // Computed Parameter: Out1_Y0_c
                                          //  Referenced by: '<S442>/Out1'

  real_T Out1_Y0_o;                    // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S444>/Out1'

  real_T Out1_Y0_a;                    // Computed Parameter: Out1_Y0_a
                                          //  Referenced by: '<S446>/Out1'

  real_T Constant1_Value;              // Expression: pi/2
                                          //  Referenced by: '<S426>/Constant1'

  real_T Constant6_Value;              // Expression: 0
                                          //  Referenced by: '<S426>/Constant6'

  real_T Constant7_Value;              // Expression: 1
                                          //  Referenced by: '<S426>/Constant7'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S395>/Constant2'

  real_T PuckState_Value_c;            // Expression: 1
                                          //  Referenced by: '<S395>/Puck State'

};

// Parameters (default storage)
struct P_APF_Path_Planning_2023a_Blu_T_ {
  real_T Att_Mode;                     // Variable: Att_Mode
                                          //  Referenced by: '<S247>/Constant2'

  real_T BLACK_end[3];                 // Variable: BLACK_end
                                          //  Referenced by:
                                          //    '<S149>/End Pos'
                                          //    '<S150>/End Pos'
                                          //    '<S151>/End Pos'
                                          //    '<S190>/End Pos'
                                          //    '<S191>/End Pos'
                                          //    '<S192>/End Pos'

  real_T BLACK_ini[6];                 // Variable: BLACK_ini
                                          //  Referenced by:
                                          //    '<S149>/Velocity'
                                          //    '<S149>/Start Pos'
                                          //    '<S150>/Velocity'
                                          //    '<S150>/Start Pos'
                                          //    '<S151>/Velocity'
                                          //    '<S151>/Start Pos'
                                          //    '<S190>/Velocity'
                                          //    '<S190>/Start Pos'
                                          //    '<S191>/Velocity'
                                          //    '<S191>/Start Pos'
                                          //    '<S192>/Velocity'
                                          //    '<S192>/Start Pos'

  real_T Binv[9];                      // Variable: Binv
                                          //  Referenced by:
                                          //    '<S350>/MATLAB Function'
                                          //    '<S369>/MATLAB Function1'

  real_T F_Black_X_nominal;            // Variable: F_Black_X_nominal
                                          //  Referenced by:
                                          //    '<S610>/MATLAB Function11'
                                          //    '<S610>/MATLAB Function3'

  real_T F_Black_Y_nominal;            // Variable: F_Black_Y_nominal
                                          //  Referenced by:
                                          //    '<S610>/MATLAB Function11'
                                          //    '<S610>/MATLAB Function3'

  real_T F_Blue_X_nominal;             // Variable: F_Blue_X_nominal
                                          //  Referenced by:
                                          //    '<S622>/MATLAB Function1'
                                          //    '<S622>/MATLAB Function7'

  real_T F_Blue_Y_nominal;             // Variable: F_Blue_Y_nominal
                                          //  Referenced by:
                                          //    '<S622>/MATLAB Function1'
                                          //    '<S622>/MATLAB Function7'

  real_T F_red_X_nominal;              // Variable: F_red_X_nominal
                                          //  Referenced by:
                                          //    '<S634>/MATLAB Function11'
                                          //    '<S634>/MATLAB Function4'
                                          //    '<S634>/MATLAB Function6'
                                          //    '<S634>/MATLAB Function7'

  real_T F_red_Y_nominal;              // Variable: F_red_Y_nominal
                                          //  Referenced by:
                                          //    '<S634>/MATLAB Function11'
                                          //    '<S634>/MATLAB Function4'
                                          //    '<S634>/MATLAB Function6'
                                          //    '<S634>/MATLAB Function7'

  real_T F_thrusters_BLACK[8];         // Variable: F_thrusters_BLACK
                                          //  Referenced by: '<S610>/MATLAB Function'

  real_T F_thrusters_BLUE[8];          // Variable: F_thrusters_BLUE
                                          //  Referenced by: '<S622>/MATLAB Function'

  real_T F_thrusters_RED[8];           // Variable: F_thrusters_RED
                                          //  Referenced by:
                                          //    '<S634>/MATLAB Function'
                                          //    '<S634>/MATLAB Function3'

  real_T Gamma1_el;                    // Variable: Gamma1_el
                                          //  Referenced by: '<S582>/Dynamics Model'

  real_T Gamma1_sh;                    // Variable: Gamma1_sh
                                          //  Referenced by: '<S582>/Dynamics Model'

  real_T Gamma1_wr;                    // Variable: Gamma1_wr
                                          //  Referenced by: '<S582>/Dynamics Model'

  real_T Gamma2_el;                    // Variable: Gamma2_el
                                          //  Referenced by: '<S582>/Dynamics Model'

  real_T Gamma2_sh;                    // Variable: Gamma2_sh
                                          //  Referenced by: '<S582>/Dynamics Model'

  real_T Gamma2_wr;                    // Variable: Gamma2_wr
                                          //  Referenced by: '<S582>/Dynamics Model'

  real_T Gamma3_el;                    // Variable: Gamma3_el
                                          //  Referenced by: '<S582>/Dynamics Model'

  real_T Gamma3_sh;                    // Variable: Gamma3_sh
                                          //  Referenced by: '<S582>/Dynamics Model'

  real_T Gamma3_wr;                    // Variable: Gamma3_wr
                                          //  Referenced by: '<S582>/Dynamics Model'

  real_T Gamma4_el;                    // Variable: Gamma4_el
                                          //  Referenced by: '<S582>/Dynamics Model'

  real_T Gamma4_sh;                    // Variable: Gamma4_sh
                                          //  Referenced by: '<S582>/Dynamics Model'

  real_T Gamma4_wr;                    // Variable: Gamma4_wr
                                          //  Referenced by: '<S582>/Dynamics Model'

  real_T Gamma5_el;                    // Variable: Gamma5_el
                                          //  Referenced by: '<S582>/Dynamics Model'

  real_T Gamma5_sh;                    // Variable: Gamma5_sh
                                          //  Referenced by: '<S582>/Dynamics Model'

  real_T Gamma5_wr;                    // Variable: Gamma5_wr
                                          //  Referenced by: '<S582>/Dynamics Model'

  real_T Gamma6_el;                    // Variable: Gamma6_el
                                          //  Referenced by: '<S582>/Dynamics Model'

  real_T Gamma6_sh;                    // Variable: Gamma6_sh
                                          //  Referenced by: '<S582>/Dynamics Model'

  real_T Gamma6_wr;                    // Variable: Gamma6_wr
                                          //  Referenced by: '<S582>/Dynamics Model'

  real_T H[18];                        // Variable: H
                                          //  Referenced by: '<S356>/MATLAB Function'

  real_T IBLACK;                       // Variable: IBLACK
                                          //  Referenced by: '<S552>/MATLAB Function'

  real_T IBLUE;                        // Variable: IBLUE
                                          //  Referenced by: '<S566>/MATLAB Function'

  real_T IDIST;                        // Variable: IDIST
                                          //  Referenced by: '<S582>/Inertia Function 1'

  real_T IEE;                          // Variable: IEE
                                          //  Referenced by: '<S582>/Inertia Function 1'

  real_T IPROX;                        // Variable: IPROX
                                          //  Referenced by: '<S582>/Inertia Function 1'

  real_T IRED;                         // Variable: IRED
                                          //  Referenced by:
                                          //    '<S582>/Inertia Function 1'
                                          //    '<S593>/MATLAB Function'

  real_T J;                            // Variable: J
                                          //  Referenced by: '<S356>/MATLAB Function'

  real_T K_a[9];                       // Variable: K_a
                                          //  Referenced by:
                                          //    '<S350>/MATLAB Function'
                                          //    '<S369>/MATLAB Function1'

  real_T Kd_elarm;                     // Variable: Kd_elarm
                                          //  Referenced by:
                                          //    '<S78>/kd_elarm'
                                          //    '<S438>/kd_elarm'
                                          //    '<S492>/kd_elarm'
                                          //    '<S268>/kd_elarm'
                                          //    '<S301>/kd_elarm'
                                          //    '<S334>/kd_elarm'
                                          //    '<S384>/kd_elarm'

  real_T Kd_sharm;                     // Variable: Kd_sharm
                                          //  Referenced by:
                                          //    '<S79>/kd_sharm'
                                          //    '<S439>/kd_sharm'
                                          //    '<S493>/kd_sharm'
                                          //    '<S269>/kd_sharm'
                                          //    '<S302>/kd_sharm'
                                          //    '<S335>/kd_sharm'
                                          //    '<S385>/kd_sharm'

  real_T Kd_tb;                        // Variable: Kd_tb
                                          //  Referenced by:
                                          //    '<S36>/kd_tb'
                                          //    '<S396>/kd_tb'
                                          //    '<S450>/kd_tb'
                                          //    '<S95>/kd_tb'
                                          //    '<S112>/kd_tb'
                                          //    '<S129>/kd_tb'
                                          //    '<S145>/kd_tb'
                                          //    '<S186>/kd_tb'

  real_T Kd_tblue;                     // Variable: Kd_tblue
                                          //  Referenced by:
                                          //    '<S49>/kd_tb'
                                          //    '<S409>/kd_tb'
                                          //    '<S463>/kd_tb'
                                          //    '<S166>/kd_tb'
                                          //    '<S203>/kd_tb'
                                          //    '<S224>/kd_tb'

  real_T Kd_tr;                        // Variable: Kd_tr
                                          //  Referenced by:
                                          //    '<S62>/kd_tr'
                                          //    '<S422>/kd_tr'
                                          //    '<S476>/kd_tr'
                                          //    '<S248>/kd_tr'
                                          //    '<S281>/kd_tr'
                                          //    '<S314>/kd_tr'

  real_T Kd_wrarm;                     // Variable: Kd_wrarm
                                          //  Referenced by:
                                          //    '<S80>/kd_wrarm'
                                          //    '<S440>/kd_wrarm'
                                          //    '<S494>/kd_wrarm'
                                          //    '<S270>/kd_wrarm'
                                          //    '<S303>/kd_wrarm'
                                          //    '<S336>/kd_wrarm'
                                          //    '<S386>/kd_wrarm'

  real_T Kd_xb;                        // Variable: Kd_xb
                                          //  Referenced by:
                                          //    '<S37>/kd_xb'
                                          //    '<S397>/kd_xb'
                                          //    '<S451>/kd_xb'
                                          //    '<S96>/kd_xb'
                                          //    '<S113>/kd_xb'
                                          //    '<S130>/kd_xb'
                                          //    '<S146>/kd_xb'
                                          //    '<S187>/kd_xb'

  real_T Kd_xblue;                     // Variable: Kd_xblue
                                          //  Referenced by:
                                          //    '<S50>/kd_xb'
                                          //    '<S410>/kd_xb'
                                          //    '<S464>/kd_xb'
                                          //    '<S167>/kd_xb'
                                          //    '<S204>/kd_xb'
                                          //    '<S225>/kd_xb'

  real_T Kd_xr;                        // Variable: Kd_xr
                                          //  Referenced by:
                                          //    '<S63>/kd_xr'
                                          //    '<S423>/kd_xr'
                                          //    '<S477>/kd_xr'
                                          //    '<S249>/kd_xr'
                                          //    '<S282>/kd_xr'
                                          //    '<S315>/kd_xr'

  real_T Kd_yb;                        // Variable: Kd_yb
                                          //  Referenced by:
                                          //    '<S38>/kd_yb'
                                          //    '<S398>/kd_yb'
                                          //    '<S452>/kd_yb'
                                          //    '<S97>/kd_yb'
                                          //    '<S114>/kd_yb'
                                          //    '<S131>/kd_yb'
                                          //    '<S147>/kd_yb'
                                          //    '<S188>/kd_yb'

  real_T Kd_yblue;                     // Variable: Kd_yblue
                                          //  Referenced by:
                                          //    '<S51>/kd_yb'
                                          //    '<S411>/kd_yb'
                                          //    '<S465>/kd_yb'
                                          //    '<S168>/kd_yb'
                                          //    '<S205>/kd_yb'
                                          //    '<S226>/kd_yb'

  real_T Kd_yr;                        // Variable: Kd_yr
                                          //  Referenced by:
                                          //    '<S64>/kd_yr'
                                          //    '<S424>/kd_yr'
                                          //    '<S478>/kd_yr'
                                          //    '<S250>/kd_yr'
                                          //    '<S283>/kd_yr'
                                          //    '<S316>/kd_yr'

  real_T Kp_elarm;                     // Variable: Kp_elarm
                                          //  Referenced by:
                                          //    '<S78>/kp_elarm'
                                          //    '<S438>/kp_elarm'
                                          //    '<S492>/kp_elarm'
                                          //    '<S268>/kp_elarm'
                                          //    '<S301>/kp_elarm'
                                          //    '<S334>/kp_elarm'
                                          //    '<S384>/kp_elarm'

  real_T Kp_sharm;                     // Variable: Kp_sharm
                                          //  Referenced by:
                                          //    '<S79>/kp_sharm'
                                          //    '<S439>/kp_sharm'
                                          //    '<S493>/kp_sharm'
                                          //    '<S269>/kp_sharm'
                                          //    '<S302>/kp_sharm'
                                          //    '<S335>/kp_sharm'
                                          //    '<S385>/kp_sharm'

  real_T Kp_tb;                        // Variable: Kp_tb
                                          //  Referenced by:
                                          //    '<S36>/kp_tb'
                                          //    '<S396>/kp_tb'
                                          //    '<S450>/kp_tb'
                                          //    '<S95>/kp_tb'
                                          //    '<S112>/kp_tb'
                                          //    '<S129>/kp_tb'
                                          //    '<S145>/kp_tb'
                                          //    '<S186>/kp_tb'

  real_T Kp_tblue;                     // Variable: Kp_tblue
                                          //  Referenced by:
                                          //    '<S49>/kp_tb'
                                          //    '<S409>/kp_tb'
                                          //    '<S463>/kp_tb'
                                          //    '<S166>/kp_tb'
                                          //    '<S203>/kp_tb'
                                          //    '<S224>/kp_tb'

  real_T Kp_tr;                        // Variable: Kp_tr
                                          //  Referenced by:
                                          //    '<S62>/kp_tr'
                                          //    '<S422>/kp_tr'
                                          //    '<S476>/kp_tr'
                                          //    '<S248>/kp_tr'
                                          //    '<S281>/kp_tr'
                                          //    '<S314>/kp_tr'

  real_T Kp_wrarm;                     // Variable: Kp_wrarm
                                          //  Referenced by:
                                          //    '<S80>/kp_wrarm'
                                          //    '<S440>/kp_wrarm'
                                          //    '<S494>/kp_wrarm'
                                          //    '<S270>/kp_wrarm'
                                          //    '<S303>/kp_wrarm'
                                          //    '<S336>/kp_wrarm'
                                          //    '<S386>/kp_wrarm'

  real_T Kp_xb;                        // Variable: Kp_xb
                                          //  Referenced by:
                                          //    '<S37>/kp_xb'
                                          //    '<S397>/kp_xb'
                                          //    '<S451>/kp_xb'
                                          //    '<S96>/kp_xb'
                                          //    '<S113>/kp_xb'
                                          //    '<S130>/kp_xb'
                                          //    '<S146>/kp_xb'
                                          //    '<S187>/kp_xb'

  real_T Kp_xblue;                     // Variable: Kp_xblue
                                          //  Referenced by:
                                          //    '<S50>/kp_xb'
                                          //    '<S410>/kp_xb'
                                          //    '<S464>/kp_xb'
                                          //    '<S167>/kp_xb'
                                          //    '<S204>/kp_xb'
                                          //    '<S225>/kp_xb'

  real_T Kp_xr;                        // Variable: Kp_xr
                                          //  Referenced by:
                                          //    '<S63>/kp_xr'
                                          //    '<S423>/kp_xr'
                                          //    '<S477>/kp_xr'
                                          //    '<S249>/kp_xr'
                                          //    '<S282>/kp_xr'
                                          //    '<S315>/kp_xr'

  real_T Kp_yb;                        // Variable: Kp_yb
                                          //  Referenced by:
                                          //    '<S38>/kp_yb'
                                          //    '<S398>/kp_yb'
                                          //    '<S452>/kp_yb'
                                          //    '<S97>/kp_yb'
                                          //    '<S114>/kp_yb'
                                          //    '<S131>/kp_yb'
                                          //    '<S147>/kp_yb'
                                          //    '<S188>/kp_yb'

  real_T Kp_yblue;                     // Variable: Kp_yblue
                                          //  Referenced by:
                                          //    '<S51>/kp_yb'
                                          //    '<S411>/kp_yb'
                                          //    '<S465>/kp_yb'
                                          //    '<S168>/kp_yb'
                                          //    '<S205>/kp_yb'
                                          //    '<S226>/kp_yb'

  real_T Kp_yr;                        // Variable: Kp_yr
                                          //  Referenced by:
                                          //    '<S64>/kp_yr'
                                          //    '<S424>/kp_yr'
                                          //    '<S478>/kp_yr'
                                          //    '<S250>/kp_yr'
                                          //    '<S283>/kp_yr'
                                          //    '<S316>/kp_yr'

  real_T Method;                       // Variable: Method
                                          //  Referenced by: '<S362>/Constant3'

  real_T Nmat[9];                      // Variable: Nmat
                                          //  Referenced by:
                                          //    '<S350>/MATLAB Function'
                                          //    '<S369>/MATLAB Function1'

  real_T PWMFreq;                      // Variable: PWMFreq
                                          //  Referenced by:
                                          //    '<S19>/PWM Frequency'
                                          //    '<S610>/MATLAB Function1'
                                          //    '<S622>/MATLAB Function2'
                                          //    '<S634>/MATLAB Function2'

  real_T P_IC[36];                     // Variable: P_IC
                                          //  Referenced by:
                                          //    '<S356>/IC'
                                          //    '<S356>/Delay'

  real_T P_b[9];                       // Variable: P_b
                                          //  Referenced by:
                                          //    '<S350>/MATLAB Function'
                                          //    '<S369>/MATLAB Function1'

  real_T Phase0_End;                   // Variable: Phase0_End
                                          //  Referenced by: '<Root>/Constant4'

  real_T Phase1_End;                   // Variable: Phase1_End
                                          //  Referenced by: '<Root>/Constant'

  real_T Phase2_End;                   // Variable: Phase2_End
                                          //  Referenced by:
                                          //    '<Root>/Constant1'
                                          //    '<S172>/Constant2'
                                          //    '<S209>/Constant2'
                                          //    '<S230>/Constant2'
                                          //    '<S256>/Constant2'
                                          //    '<S289>/Constant2'
                                          //    '<S322>/Constant2'
                                          //    '<S99>/Constant1'
                                          //    '<S116>/Constant1'
                                          //    '<S133>/Constant1'
                                          //    '<S173>/Constant1'
                                          //    '<S210>/Constant1'
                                          //    '<S231>/Constant1'
                                          //    '<S277>/Constant1'
                                          //    '<S310>/Constant1'
                                          //    '<S343>/Constant1'
                                          //    '<S365>/Constant'

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
                                          //    '<S634>/MATLAB Function'
                                          //    '<S634>/MATLAB Function4'
                                          //    '<S634>/MATLAB Function6'
                                          //    '<S582>/Coriolis Function1'
                                          //    '<S582>/Inertia Function 1'

  real_T Q[36];                        // Variable: Q
                                          //  Referenced by: '<S356>/MATLAB Function'

  real_T Q_a[9];                       // Variable: Q_a
                                          //  Referenced by:
                                          //    '<S350>/MATLAB Function'
                                          //    '<S369>/MATLAB Function1'

  real_T Q_b[9];                       // Variable: Q_b
                                          //  Referenced by:
                                          //    '<S350>/MATLAB Function'
                                          //    '<S369>/MATLAB Function1'

  real_T R[9];                         // Variable: R
                                          //  Referenced by: '<S356>/MATLAB Function'

  real_T RMSprop_epsilon;              // Variable: RMSprop_epsilon
                                          //  Referenced by: '<S370>/MATLAB Function1'

  real_T RMSprop_eta;                  // Variable: RMSprop_eta
                                          //  Referenced by: '<S370>/MATLAB Function1'

  real_T RMSprop_gamma;                // Variable: RMSprop_gamma
                                          //  Referenced by: '<S370>/MATLAB Function1'

  real_T Tz_lim_elarm;                 // Variable: Tz_lim_elarm
                                          //  Referenced by:
                                          //    '<S77>/Saturation1'
                                          //    '<S437>/Saturation1'
                                          //    '<S491>/Saturation1'
                                          //    '<S267>/Saturation1'
                                          //    '<S300>/Saturation1'
                                          //    '<S333>/Saturation1'
                                          //    '<S383>/Saturation1'

  real_T Tz_lim_sharm;                 // Variable: Tz_lim_sharm
                                          //  Referenced by:
                                          //    '<S77>/Saturation'
                                          //    '<S437>/Saturation'
                                          //    '<S491>/Saturation'
                                          //    '<S267>/Saturation'
                                          //    '<S300>/Saturation'
                                          //    '<S333>/Saturation'
                                          //    '<S383>/Saturation'

  real_T Tz_lim_wrarm;                 // Variable: Tz_lim_wrarm
                                          //  Referenced by:
                                          //    '<S77>/Saturation3'
                                          //    '<S437>/Saturation3'
                                          //    '<S491>/Saturation3'
                                          //    '<S267>/Saturation3'
                                          //    '<S300>/Saturation3'
                                          //    '<S333>/Saturation3'
                                          //    '<S383>/Saturation3'

  real_T a1;                           // Variable: a1
                                          //  Referenced by:
                                          //    '<S634>/MATLAB Function'
                                          //    '<S634>/MATLAB Function4'
                                          //    '<S634>/MATLAB Function6'
                                          //    '<S582>/Coriolis Function1'
                                          //    '<S582>/Inertia Function 1'

  real_T a2;                           // Variable: a2
                                          //  Referenced by:
                                          //    '<S634>/MATLAB Function'
                                          //    '<S634>/MATLAB Function4'
                                          //    '<S634>/MATLAB Function6'
                                          //    '<S582>/Coriolis Function1'
                                          //    '<S582>/Inertia Function 1'

  real_T a3;                           // Variable: a3
                                          //  Referenced by:
                                          //    '<S634>/MATLAB Function'
                                          //    '<S634>/MATLAB Function4'
                                          //    '<S634>/MATLAB Function6'
                                          //    '<S582>/Coriolis Function1'
                                          //    '<S582>/Inertia Function 1'

  real_T adadelta_epsilon;             // Variable: adadelta_epsilon
                                          //  Referenced by: '<S363>/MATLAB Function1'

  real_T adadelta_gamma;               // Variable: adadelta_gamma
                                          //  Referenced by: '<S363>/MATLAB Function1'

  real_T adagrad_epsilon;              // Variable: adagrad_epsilon
                                          //  Referenced by: '<S364>/MATLAB Function1'

  real_T adagrad_eta;                  // Variable: adagrad_eta
                                          //  Referenced by: '<S364>/MATLAB Function1'

  real_T adam_beta_1;                  // Variable: adam_beta_1
                                          //  Referenced by: '<S366>/MATLAB Function1'

  real_T adam_beta_2;                  // Variable: adam_beta_2
                                          //  Referenced by: '<S366>/MATLAB Function1'

  real_T adam_epsilon;                 // Variable: adam_epsilon
                                          //  Referenced by: '<S366>/MATLAB Function1'

  real_T adam_eta;                     // Variable: adam_eta
                                          //  Referenced by: '<S366>/MATLAB Function1'

  real_T adamax_beta_1;                // Variable: adamax_beta_1
                                          //  Referenced by: '<S365>/MATLAB Function1'

  real_T adamax_beta_2;                // Variable: adamax_beta_2
                                          //  Referenced by: '<S365>/MATLAB Function1'

  real_T adamax_eta;                   // Variable: adamax_eta
                                          //  Referenced by: '<S365>/MATLAB Function1'

  real_T alpha;                        // Variable: alpha
                                          //  Referenced by: '<S356>/MATLAB Function'

  real_T b0;                           // Variable: b0
                                          //  Referenced by:
                                          //    '<S634>/MATLAB Function'
                                          //    '<S634>/MATLAB Function4'
                                          //    '<S634>/MATLAB Function6'
                                          //    '<S582>/Coriolis Function1'
                                          //    '<S582>/Inertia Function 1'

  real_T b1;                           // Variable: b1
                                          //  Referenced by:
                                          //    '<S634>/MATLAB Function'
                                          //    '<S634>/MATLAB Function4'
                                          //    '<S634>/MATLAB Function6'
                                          //    '<S582>/Coriolis Function1'
                                          //    '<S582>/Inertia Function 1'

  real_T b2;                           // Variable: b2
                                          //  Referenced by:
                                          //    '<S634>/MATLAB Function'
                                          //    '<S634>/MATLAB Function4'
                                          //    '<S634>/MATLAB Function6'
                                          //    '<S582>/Coriolis Function1'
                                          //    '<S582>/Inertia Function 1'

  real_T b3;                           // Variable: b3
                                          //  Referenced by:
                                          //    '<S634>/MATLAB Function'
                                          //    '<S634>/MATLAB Function4'
                                          //    '<S634>/MATLAB Function6'
                                          //    '<S582>/Inertia Function 1'

  real_T baseRate;                     // Variable: baseRate
                                          //  Referenced by:
                                          //    '<S26>/Read Joint Positions using  Dynamixel Encoders'
                                          //    '<S546>/WhoAmI'
                                          //    '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'
                                          //    '<S508>/divide by delta T'
                                          //    '<S509>/divide by delta T'
                                          //    '<S510>/divide by delta T'
                                          //    '<S511>/divide by delta T'
                                          //    '<S512>/divide by delta T'
                                          //    '<S513>/divide by delta T'
                                          //    '<S514>/divide by delta T'
                                          //    '<S515>/divide by delta T'
                                          //    '<S516>/divide by delta T'
                                          //    '<S517>/divide by delta T'
                                          //    '<S518>/divide by delta T'
                                          //    '<S519>/divide by delta T'
                                          //    '<S520>/divide by delta T'
                                          //    '<S521>/divide by delta T'
                                          //    '<S522>/divide by delta T'
                                          //    '<S523>/divide by delta T'
                                          //    '<S524>/divide by delta T'
                                          //    '<S525>/divide by delta T'
                                          //    '<S553>/divide by delta T'
                                          //    '<S554>/divide by delta T'
                                          //    '<S555>/divide by delta T'
                                          //    '<S556>/divide by delta T'
                                          //    '<S557>/divide by delta T'
                                          //    '<S558>/divide by delta T'
                                          //    '<S567>/divide by delta T'
                                          //    '<S568>/divide by delta T'
                                          //    '<S569>/divide by delta T'
                                          //    '<S570>/divide by delta T'
                                          //    '<S571>/divide by delta T'
                                          //    '<S572>/divide by delta T'
                                          //    '<S40>/divide by delta T'
                                          //    '<S42>/divide by delta T'
                                          //    '<S44>/divide by delta T'
                                          //    '<S53>/divide by delta T'
                                          //    '<S55>/divide by delta T'
                                          //    '<S57>/divide by delta T'
                                          //    '<S67>/divide by delta T'
                                          //    '<S69>/divide by delta T'
                                          //    '<S71>/divide by delta T'
                                          //    '<S400>/divide by delta T'
                                          //    '<S402>/divide by delta T'
                                          //    '<S404>/divide by delta T'
                                          //    '<S413>/divide by delta T'
                                          //    '<S415>/divide by delta T'
                                          //    '<S417>/divide by delta T'
                                          //    '<S427>/divide by delta T'
                                          //    '<S429>/divide by delta T'
                                          //    '<S431>/divide by delta T'
                                          //    '<S454>/divide by delta T'
                                          //    '<S456>/divide by delta T'
                                          //    '<S458>/divide by delta T'
                                          //    '<S467>/divide by delta T'
                                          //    '<S469>/divide by delta T'
                                          //    '<S471>/divide by delta T'
                                          //    '<S481>/divide by delta T'
                                          //    '<S483>/divide by delta T'
                                          //    '<S485>/divide by delta T'
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
                                          //    '<S193>/divide by delta T'
                                          //    '<S195>/divide by delta T'
                                          //    '<S197>/divide by delta T'
                                          //    '<S213>/divide by delta T'
                                          //    '<S215>/divide by delta T'
                                          //    '<S217>/divide by delta T'
                                          //    '<S234>/divide by delta T'
                                          //    '<S236>/divide by delta T'
                                          //    '<S238>/divide by delta T'
                                          //    '<S257>/divide by delta T'
                                          //    '<S259>/divide by delta T'
                                          //    '<S261>/divide by delta T'
                                          //    '<S290>/divide by delta T'
                                          //    '<S292>/divide by delta T'
                                          //    '<S294>/divide by delta T'
                                          //    '<S323>/divide by delta T'
                                          //    '<S325>/divide by delta T'
                                          //    '<S327>/divide by delta T'
                                          //    '<S586>/divide by delta T'
                                          //    '<S587>/divide by delta T'
                                          //    '<S588>/divide by delta T'
                                          //    '<S594>/divide by delta T'
                                          //    '<S595>/divide by delta T'
                                          //    '<S596>/divide by delta T'
                                          //    '<S597>/divide by delta T'
                                          //    '<S598>/divide by delta T'
                                          //    '<S599>/divide by delta T'
                                          //    '<S81>/divide by delta T'
                                          //    '<S83>/divide by delta T'
                                          //    '<S85>/divide by delta T'
                                          //    '<S441>/divide by delta T'
                                          //    '<S443>/divide by delta T'
                                          //    '<S445>/divide by delta T'
                                          //    '<S495>/divide by delta T'
                                          //    '<S497>/divide by delta T'
                                          //    '<S499>/divide by delta T'
                                          //    '<S271>/divide by delta T'
                                          //    '<S273>/divide by delta T'
                                          //    '<S275>/divide by delta T'
                                          //    '<S304>/divide by delta T'
                                          //    '<S306>/divide by delta T'
                                          //    '<S308>/divide by delta T'
                                          //    '<S337>/divide by delta T'
                                          //    '<S339>/divide by delta T'
                                          //    '<S341>/divide by delta T'
                                          //    '<S387>/divide by delta T'
                                          //    '<S389>/divide by delta T'
                                          //    '<S391>/divide by delta T'

  real_T batch_eta;                    // Variable: batch_eta
                                          //  Referenced by: '<S367>/Batch'

  real_T beta;                         // Variable: beta
                                          //  Referenced by: '<S356>/MATLAB Function'

  real_T delta;                        // Variable: delta
                                          //  Referenced by: '<S347>/Ryan's Transform'

  real_T drop_states_BLACK[3];         // Variable: drop_states_BLACK
                                          //  Referenced by: '<S552>/Velocity to Position'

  real_T drop_states_BLUE[3];          // Variable: drop_states_BLUE
                                          //  Referenced by: '<S566>/Velocity to Position'

  real_T drop_states_RED[3];           // Variable: drop_states_RED
                                          //  Referenced by: '<S593>/Velocity to Position'

  real_T dt;                           // Variable: dt
                                          //  Referenced by: '<S356>/MATLAB Function'

  real_T end_time_black;               // Variable: end_time_black
                                          //  Referenced by:
                                          //    '<S149>/End Time'
                                          //    '<S150>/End Time'
                                          //    '<S151>/End Time'
                                          //    '<S190>/End Time'
                                          //    '<S191>/End Time'
                                          //    '<S192>/End Time'

  real_T home_states_BLACK[3];         // Variable: home_states_BLACK
                                          //  Referenced by:
                                          //    '<S393>/Desired Attitude (BLACK)'
                                          //    '<S393>/Desired Px (BLACK)'
                                          //    '<S393>/Desired Py (BLACK)'
                                          //    '<S447>/Desired Attitude (BLACK)'
                                          //    '<S447>/Desired Px (BLACK)'
                                          //    '<S447>/Desired Py (BLACK)'

  real_T home_states_BLUE[3];          // Variable: home_states_BLUE
                                          //  Referenced by:
                                          //    '<S394>/Desired Attitude (BLUE)'
                                          //    '<S394>/Desired Px (BLUE)'
                                          //    '<S394>/Desired Py (BLUE)'
                                          //    '<S448>/Desired Attitude (BLUE)'
                                          //    '<S448>/Desired Px (BLUE)'
                                          //    '<S448>/Desired Py (BLUE)'

  real_T home_states_RED[3];           // Variable: home_states_RED
                                          //  Referenced by:
                                          //    '<S395>/Desired Px (RED)'
                                          //    '<S395>/Desired Py (RED)'
                                          //    '<S395>/Desired Rz (RED)'
                                          //    '<S449>/Desired Px (RED)'
                                          //    '<S449>/Desired Py (RED)'
                                          //    '<S449>/Desired Rz (RED)'

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

  real_T k_1_0;                        // Variable: k_1_0
                                          //  Referenced by:
                                          //    '<S349>/Discrete-Time Integrator3'
                                          //    '<S349>/Discrete-Time Integrator5'

  real_T k_1_t_0;                      // Variable: k_1_t_0
                                          //  Referenced by: '<S349>/Discrete-Time Integrator1'

  real_T k_2_0;                        // Variable: k_2_0
                                          //  Referenced by:
                                          //    '<S349>/Discrete-Time Integrator2'
                                          //    '<S349>/Discrete-Time Integrator4'

  real_T k_2_t_0;                      // Variable: k_2_t_0
                                          //  Referenced by: '<S349>/Discrete-Time Integrator'

  real_T ka;                           // Variable: ka
                                          //  Referenced by:
                                          //    '<S350>/MATLAB Function'
                                          //    '<S369>/MATLAB Function1'

  real_T kr;                           // Variable: kr
                                          //  Referenced by:
                                          //    '<S350>/MATLAB Function'
                                          //    '<S369>/MATLAB Function1'

  real_T lambda1;                      // Variable: lambda1
                                          //  Referenced by:
                                          //    '<S349>/Fx Gain Derivatives'
                                          //    '<S349>/Fy Gain Derivatives'

  real_T lambda12;                     // Variable: lambda12
                                          //  Referenced by:
                                          //    '<S349>/Fx Gain Derivatives'
                                          //    '<S349>/Fy Gain Derivatives'

  real_T lambda12_t;                   // Variable: lambda12_t
                                          //  Referenced by: '<S349>/Torque Gain Derivatives'

  real_T lambda1_t;                    // Variable: lambda1_t
                                          //  Referenced by: '<S349>/Torque Gain Derivatives'

  real_T lambda2;                      // Variable: lambda2
                                          //  Referenced by:
                                          //    '<S349>/Fx Gain Derivatives'
                                          //    '<S349>/Fy Gain Derivatives'

  real_T lambda2_t;                    // Variable: lambda2_t
                                          //  Referenced by: '<S349>/Torque Gain Derivatives'

  real_T lamda;                        // Variable: lamda
                                          //  Referenced by: '<S356>/MATLAB Function'

  real_T m;                            // Variable: m
                                          //  Referenced by: '<S356>/MATLAB Function'

  real_T mBLACK;                       // Variable: mBLACK
                                          //  Referenced by: '<S552>/MATLAB Function'

  real_T mBLUE;                        // Variable: mBLUE
                                          //  Referenced by: '<S566>/MATLAB Function'

  real_T mDIST;                        // Variable: mDIST
                                          //  Referenced by:
                                          //    '<S634>/MATLAB Function'
                                          //    '<S634>/MATLAB Function4'
                                          //    '<S634>/MATLAB Function6'
                                          //    '<S582>/Coriolis Function1'
                                          //    '<S582>/Inertia Function 1'

  real_T mEE;                          // Variable: mEE
                                          //  Referenced by:
                                          //    '<S634>/MATLAB Function'
                                          //    '<S634>/MATLAB Function4'
                                          //    '<S634>/MATLAB Function6'
                                          //    '<S582>/Coriolis Function1'
                                          //    '<S582>/Inertia Function 1'

  real_T mPROX;                        // Variable: mPROX
                                          //  Referenced by:
                                          //    '<S634>/MATLAB Function'
                                          //    '<S634>/MATLAB Function4'
                                          //    '<S634>/MATLAB Function6'
                                          //    '<S582>/Coriolis Function1'
                                          //    '<S582>/Inertia Function 1'

  real_T mRED;                         // Variable: mRED
                                          //  Referenced by:
                                          //    '<S634>/MATLAB Function'
                                          //    '<S634>/MATLAB Function4'
                                          //    '<S634>/MATLAB Function6'
                                          //    '<S582>/Inertia Function 1'
                                          //    '<S593>/MATLAB Function'

  real_T momentum_eta;                 // Variable: momentum_eta
                                          //  Referenced by: '<S368>/Momentum'

  real_T momentum_gamma;               // Variable: momentum_gamma
                                          //  Referenced by: '<S368>/Momentum'

  real_T nesterov_eta;                 // Variable: nesterov_eta
                                          //  Referenced by: '<S369>/MATLAB Function1'

  real_T nesterov_gamma;               // Variable: nesterov_gamma
                                          //  Referenced by: '<S369>/MATLAB Function1'

  real_T noise_variance_BLACK;         // Variable: noise_variance_BLACK
                                          //  Referenced by: '<S552>/Random Number'

  real_T noise_variance_BLUE;          // Variable: noise_variance_BLUE
                                          //  Referenced by: '<S566>/Random Number'

  real_T noise_variance_RED;           // Variable: noise_variance_RED
                                          //  Referenced by: '<S593>/Random Number'

  real_T p;                            // Variable: p
                                          //  Referenced by:
                                          //    '<S349>/Fx Gain Derivatives'
                                          //    '<S349>/Fy Gain Derivatives'

  real_T p_t;                          // Variable: p_t
                                          //  Referenced by: '<S349>/Torque Gain Derivatives'

  real_T platformSelection;            // Variable: platformSelection
                                          //  Referenced by:
                                          //    '<S35>/Constant4'
                                          //    '<S395>/Constant4'
                                          //    '<S449>/Constant4'
                                          //    '<S505>/MATLAB Function'
                                          //    '<S551>/Constant'
                                          //    '<S244>/Constant4'
                                          //    '<S245>/Constant4'
                                          //    '<S246>/Constant1'
                                          //    '<S247>/Constant3'
                                          //    '<S634>/Constant'
                                          //    '<S634>/Constant1'
                                          //    '<S634>/Constant2'

  real_T psi;                          // Variable: psi
                                          //  Referenced by:
                                          //    '<S350>/MATLAB Function'
                                          //    '<S369>/MATLAB Function1'

  real_T r_hold;                       // Variable: r_hold
                                          //  Referenced by:
                                          //    '<S350>/MATLAB Function'
                                          //    '<S369>/MATLAB Function1'

  real_T r_off;                        // Variable: r_off
                                          //  Referenced by:
                                          //    '<S247>/Looking Angle'
                                          //    '<S350>/MATLAB Function'
                                          //    '<S369>/MATLAB Function1'

  real_T shape[5];                     // Variable: shape
                                          //  Referenced by:
                                          //    '<S350>/MATLAB Function'
                                          //    '<S369>/MATLAB Function1'

  real_T sigma;                        // Variable: sigma
                                          //  Referenced by:
                                          //    '<S350>/MATLAB Function'
                                          //    '<S369>/MATLAB Function1'

  real_T simMode;                      // Variable: simMode
                                          //  Referenced by: '<S18>/Constant'

  real_T thresh;                       // Variable: thresh
                                          //  Referenced by: '<S356>/MATLAB Function'

  real_T thruster_count_threshold;     // Variable: thruster_count_threshold
                                          //  Referenced by:
                                          //    '<S610>/MATLAB Function10'
                                          //    '<S622>/MATLAB Function6'
                                          //    '<S634>/MATLAB Function5'

  real_T thruster_dist2CG_BLACK[8];    // Variable: thruster_dist2CG_BLACK
                                          //  Referenced by:
                                          //    '<S610>/MATLAB Function'
                                          //    '<S610>/MATLAB Function11'
                                          //    '<S610>/MATLAB Function3'

  real_T thruster_dist2CG_BLUE[8];     // Variable: thruster_dist2CG_BLUE
                                          //  Referenced by:
                                          //    '<S622>/MATLAB Function'
                                          //    '<S622>/MATLAB Function1'
                                          //    '<S622>/MATLAB Function7'

  real_T thruster_dist2CG_RED[8];      // Variable: thruster_dist2CG_RED
                                          //  Referenced by:
                                          //    '<S634>/MATLAB Function'
                                          //    '<S634>/MATLAB Function11'
                                          //    '<S634>/MATLAB Function3'
                                          //    '<S634>/MATLAB Function4'
                                          //    '<S634>/MATLAB Function6'
                                          //    '<S634>/MATLAB Function7'

  real_T xLength;                      // Variable: xLength
                                          //  Referenced by:
                                          //    '<S90>/Desired X-Position (BLACK)'
                                          //    '<S91>/Desired X-Position (BLACK)'
                                          //    '<S92>/Desired X-Position (BLACK)'
                                          //    '<S161>/MATLAB Function2'
                                          //    '<S163>/MATLAB Function2'
                                          //    '<S164>/MATLAB Function2'
                                          //    '<S244>/MATLAB Function'
                                          //    '<S245>/MATLAB Function'
                                          //    '<S246>/MATLAB Function'

  real_T x_in[6];                      // Variable: x_in
                                          //  Referenced by:
                                          //    '<S356>/IC1'
                                          //    '<S356>/Delay1'

  real_T yLength;                      // Variable: yLength
                                          //  Referenced by:
                                          //    '<S90>/Desired Y-Position (BLACK)'
                                          //    '<S91>/Desired Y-Position (BLACK)'
                                          //    '<S92>/Desired Y-Position (BLACK)'
                                          //    '<S161>/MATLAB Function3'
                                          //    '<S163>/MATLAB Function3'
                                          //    '<S164>/MATLAB Function3'
                                          //    '<S244>/MATLAB Function1'
                                          //    '<S245>/MATLAB Function1'
                                          //    '<S246>/MATLAB Function1'

  real_T SetPin428PuckstoHIGH_gpioPin; // Expression: 428
                                          //  Referenced by: '<S25>/Set Pin 428 (Pucks) to HIGH'

  real_T SetPin428PuckstoHIGH_pinDirecti;// Expression: 1
                                            //  Referenced by: '<S25>/Set Pin 428 (Pucks) to HIGH'

  real_T Out1_Y0;                      // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S560>/Out1'

  real_T Out1_Y0_a;                    // Computed Parameter: Out1_Y0_a
                                          //  Referenced by: '<S561>/Out1'

  real_T Out1_Y0_g;                    // Computed Parameter: Out1_Y0_g
                                          //  Referenced by: '<S562>/Out1'

  real_T Out1_Y0_gc;                   // Computed Parameter: Out1_Y0_gc
                                          //  Referenced by: '<S563>/Out1'

  real_T Out1_Y0_e;                    // Computed Parameter: Out1_Y0_e
                                          //  Referenced by: '<S564>/Out1'

  real_T Out1_Y0_n;                    // Computed Parameter: Out1_Y0_n
                                          //  Referenced by: '<S565>/Out1'

  real_T Out1_Y0_o;                    // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S574>/Out1'

  real_T Out1_Y0_ow;                   // Computed Parameter: Out1_Y0_ow
                                          //  Referenced by: '<S575>/Out1'

  real_T Out1_Y0_as;                   // Computed Parameter: Out1_Y0_as
                                          //  Referenced by: '<S576>/Out1'

  real_T Out1_Y0_ox;                   // Computed Parameter: Out1_Y0_ox
                                          //  Referenced by: '<S577>/Out1'

  real_T Out1_Y0_e3;                   // Computed Parameter: Out1_Y0_e3
                                          //  Referenced by: '<S578>/Out1'

  real_T Out1_Y0_i;                    // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S579>/Out1'

  real_T Out1_Y0_b;                    // Computed Parameter: Out1_Y0_b
                                          //  Referenced by: '<S589>/Out1'

  real_T Out1_Y0_asw;                  // Computed Parameter: Out1_Y0_asw
                                          //  Referenced by: '<S590>/Out1'

  real_T Out1_Y0_ea;                   // Computed Parameter: Out1_Y0_ea
                                          //  Referenced by: '<S591>/Out1'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S582>/Delay'

  real_T AccelerationtoVelocity_gainval;
                           // Computed Parameter: AccelerationtoVelocity_gainval
                              //  Referenced by: '<S582>/Acceleration  to Velocity'

  real_T AccelerationtoVelocity_IC[12];
                    // Expression: [drop_states_RED,drop_states_ARM,0,0,0,0,0,0]
                       //  Referenced by: '<S582>/Acceleration  to Velocity'

  real_T RandomNumber2_Mean;           // Expression: 0
                                          //  Referenced by: '<S582>/Random Number2'

  real_T RandomNumber2_StdDev;       // Computed Parameter: RandomNumber2_StdDev
                                        //  Referenced by: '<S582>/Random Number2'

  real_T RandomNumber2_Seed;           // Expression: 0
                                          //  Referenced by: '<S582>/Random Number2'

  real_T RandomNumber1_Mean;           // Expression: 0
                                          //  Referenced by: '<S582>/Random Number1'

  real_T RandomNumber1_StdDev;       // Computed Parameter: RandomNumber1_StdDev
                                        //  Referenced by: '<S582>/Random Number1'

  real_T RandomNumber1_Seed;           // Expression: 0
                                          //  Referenced by: '<S582>/Random Number1'

  real_T RandomNumber3_Mean;           // Expression: 0
                                          //  Referenced by: '<S582>/Random Number3'

  real_T RandomNumber3_StdDev;       // Computed Parameter: RandomNumber3_StdDev
                                        //  Referenced by: '<S582>/Random Number3'

  real_T RandomNumber3_Seed;           // Expression: 0
                                          //  Referenced by: '<S582>/Random Number3'

  real_T Out1_Y0_j;                    // Computed Parameter: Out1_Y0_j
                                          //  Referenced by: '<S601>/Out1'

  real_T Out1_Y0_l;                    // Computed Parameter: Out1_Y0_l
                                          //  Referenced by: '<S602>/Out1'

  real_T Out1_Y0_d;                    // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S603>/Out1'

  real_T Out1_Y0_bf;                   // Computed Parameter: Out1_Y0_bf
                                          //  Referenced by: '<S604>/Out1'

  real_T Out1_Y0_gt;                   // Computed Parameter: Out1_Y0_gt
                                          //  Referenced by: '<S605>/Out1'

  real_T Out1_Y0_em;                   // Computed Parameter: Out1_Y0_em
                                          //  Referenced by: '<S606>/Out1'

  real_T AccelerationtoVelocity_gainva_g;
                          // Computed Parameter: AccelerationtoVelocity_gainva_g
                             //  Referenced by: '<S593>/Acceleration  to Velocity'

  real_T AccelerationtoVelocity_IC_n;  // Expression: 0
                                          //  Referenced by: '<S593>/Acceleration  to Velocity'

  real_T VelocitytoPosition_gainval;
                               // Computed Parameter: VelocitytoPosition_gainval
                                  //  Referenced by: '<S593>/Velocity to Position'

  real_T RandomNumber_Mean;            // Expression: 0
                                          //  Referenced by: '<S593>/Random Number'

  real_T RandomNumber_Seed;            // Expression: 0
                                          //  Referenced by: '<S593>/Random Number'

  real_T RandomNumber7_Mean;           // Expression: 0
                                          //  Referenced by: '<S592>/Random Number7'

  real_T RandomNumber7_StdDev;       // Computed Parameter: RandomNumber7_StdDev
                                        //  Referenced by: '<S592>/Random Number7'

  real_T RandomNumber7_Seed;           // Expression: 0
                                          //  Referenced by: '<S592>/Random Number7'

  real_T RandomNumber6_Mean;           // Expression: 0
                                          //  Referenced by: '<S592>/Random Number6'

  real_T RandomNumber6_StdDev;       // Computed Parameter: RandomNumber6_StdDev
                                        //  Referenced by: '<S592>/Random Number6'

  real_T RandomNumber6_Seed;           // Expression: 0
                                          //  Referenced by: '<S592>/Random Number6'

  real_T RandomNumber8_Mean;           // Expression: 0
                                          //  Referenced by: '<S592>/Random Number8'

  real_T RandomNumber8_StdDev;       // Computed Parameter: RandomNumber8_StdDev
                                        //  Referenced by: '<S592>/Random Number8'

  real_T RandomNumber8_Seed;           // Expression: 0
                                          //  Referenced by: '<S592>/Random Number8'

  real_T AccelerationtoVelocity_gainva_j;
                          // Computed Parameter: AccelerationtoVelocity_gainva_j
                             //  Referenced by: '<S552>/Acceleration  to Velocity'

  real_T AccelerationtoVelocity_IC_p;  // Expression: 0
                                          //  Referenced by: '<S552>/Acceleration  to Velocity'

  real_T VelocitytoPosition_gainval_n;
                             // Computed Parameter: VelocitytoPosition_gainval_n
                                //  Referenced by: '<S552>/Velocity to Position'

  real_T RandomNumber_Mean_d;          // Expression: 0
                                          //  Referenced by: '<S552>/Random Number'

  real_T RandomNumber_Seed_g;          // Expression: 0
                                          //  Referenced by: '<S552>/Random Number'

  real_T RandomNumber1_Mean_j;         // Expression: 0
                                          //  Referenced by: '<S549>/Random Number1'

  real_T RandomNumber1_StdDev_e;   // Computed Parameter: RandomNumber1_StdDev_e
                                      //  Referenced by: '<S549>/Random Number1'

  real_T RandomNumber1_Seed_j;         // Expression: 0
                                          //  Referenced by: '<S549>/Random Number1'

  real_T RandomNumber_Mean_g;          // Expression: 0
                                          //  Referenced by: '<S549>/Random Number'

  real_T RandomNumber_StdDev;         // Computed Parameter: RandomNumber_StdDev
                                         //  Referenced by: '<S549>/Random Number'

  real_T RandomNumber_Seed_d;          // Expression: 0
                                          //  Referenced by: '<S549>/Random Number'

  real_T RandomNumber2_Mean_b;         // Expression: 0
                                          //  Referenced by: '<S549>/Random Number2'

  real_T RandomNumber2_StdDev_c;   // Computed Parameter: RandomNumber2_StdDev_c
                                      //  Referenced by: '<S549>/Random Number2'

  real_T RandomNumber2_Seed_g;         // Expression: 0
                                          //  Referenced by: '<S549>/Random Number2'

  real_T AccelerationtoVelocity_gainva_p;
                          // Computed Parameter: AccelerationtoVelocity_gainva_p
                             //  Referenced by: '<S566>/Acceleration  to Velocity'

  real_T AccelerationtoVelocity_IC_e;  // Expression: 0
                                          //  Referenced by: '<S566>/Acceleration  to Velocity'

  real_T VelocitytoPosition_gainval_e;
                             // Computed Parameter: VelocitytoPosition_gainval_e
                                //  Referenced by: '<S566>/Velocity to Position'

  real_T RandomNumber_Mean_dq;         // Expression: 0
                                          //  Referenced by: '<S566>/Random Number'

  real_T RandomNumber_Seed_p;          // Expression: 0
                                          //  Referenced by: '<S566>/Random Number'

  real_T RandomNumber4_Mean;           // Expression: 0
                                          //  Referenced by: '<S550>/Random Number4'

  real_T RandomNumber4_StdDev;       // Computed Parameter: RandomNumber4_StdDev
                                        //  Referenced by: '<S550>/Random Number4'

  real_T RandomNumber4_Seed;           // Expression: 0
                                          //  Referenced by: '<S550>/Random Number4'

  real_T RandomNumber3_Mean_i;         // Expression: 0
                                          //  Referenced by: '<S550>/Random Number3'

  real_T RandomNumber3_StdDev_n;   // Computed Parameter: RandomNumber3_StdDev_n
                                      //  Referenced by: '<S550>/Random Number3'

  real_T RandomNumber3_Seed_m;         // Expression: 0
                                          //  Referenced by: '<S550>/Random Number3'

  real_T RandomNumber5_Mean;           // Expression: 0
                                          //  Referenced by: '<S550>/Random Number5'

  real_T RandomNumber5_StdDev;       // Computed Parameter: RandomNumber5_StdDev
                                        //  Referenced by: '<S550>/Random Number5'

  real_T RandomNumber5_Seed;           // Expression: 0
                                          //  Referenced by: '<S550>/Random Number5'

  real_T Delay_InitialCondition_f;     // Expression: 0.0
                                          //  Referenced by: '<S26>/Delay'

  real_T Delay1_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S26>/Delay1'

  real_T Delay2_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S26>/Delay2'

  real_T Out1_Y0_m;                    // Computed Parameter: Out1_Y0_m
                                          //  Referenced by: '<S526>/Out1'

  real_T Memory_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<S526>/Memory'

  real_T Out1_Y0_ei;                   // Computed Parameter: Out1_Y0_ei
                                          //  Referenced by: '<S527>/Out1'

  real_T Out1_Y0_lf;                   // Computed Parameter: Out1_Y0_lf
                                          //  Referenced by: '<S528>/Out1'

  real_T Out1_Y0_f;                    // Computed Parameter: Out1_Y0_f
                                          //  Referenced by: '<S529>/Out1'

  real_T Out1_Y0_m3;                   // Computed Parameter: Out1_Y0_m3
                                          //  Referenced by: '<S530>/Out1'

  real_T Out1_Y0_m34;                  // Computed Parameter: Out1_Y0_m34
                                          //  Referenced by: '<S531>/Out1'

  real_T Out1_Y0_h;                    // Computed Parameter: Out1_Y0_h
                                          //  Referenced by: '<S532>/Out1'

  real_T Out1_Y0_o3;                   // Computed Parameter: Out1_Y0_o3
                                          //  Referenced by: '<S533>/Out1'

  real_T Out1_Y0_p;                    // Computed Parameter: Out1_Y0_p
                                          //  Referenced by: '<S534>/Out1'

  real_T Out1_Y0_hp;                   // Computed Parameter: Out1_Y0_hp
                                          //  Referenced by: '<S535>/Out1'

  real_T Out1_Y0_p0;                   // Computed Parameter: Out1_Y0_p0
                                          //  Referenced by: '<S536>/Out1'

  real_T Out1_Y0_iy;                   // Computed Parameter: Out1_Y0_iy
                                          //  Referenced by: '<S537>/Out1'

  real_T Out1_Y0_c;                    // Computed Parameter: Out1_Y0_c
                                          //  Referenced by: '<S538>/Out1'

  real_T Out1_Y0_d0;                   // Computed Parameter: Out1_Y0_d0
                                          //  Referenced by: '<S539>/Out1'

  real_T Out1_Y0_ck;                   // Computed Parameter: Out1_Y0_ck
                                          //  Referenced by: '<S540>/Out1'

  real_T Out1_Y0_ii;                   // Computed Parameter: Out1_Y0_ii
                                          //  Referenced by: '<S541>/Out1'

  real_T Out1_Y0_l2;                   // Computed Parameter: Out1_Y0_l2
                                          //  Referenced by: '<S542>/Out1'

  real_T Out1_Y0_nz;                   // Computed Parameter: Out1_Y0_nz
                                          //  Referenced by: '<S543>/Out1'

  real_T Out1_Y0_fr;                   // Computed Parameter: Out1_Y0_fr
                                          //  Referenced by: '<S544>/Out1'

  real_T Out1_Y0_e1;                   // Computed Parameter: Out1_Y0_e1
                                          //  Referenced by: '<S545>/Out1'

  real_T ConvertREDXfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S505>/Convert REDX from [mm] to [m]'

  real_T ConvertBLUXfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S505>/Convert BLUX from [mm] to [m]'

  real_T ConvertBLAXfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S505>/Convert BLAX from [mm] to [m]'

  real_T ConvertBLAYfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S505>/Convert BLAY from [mm] to [m]'

  real_T ConvertBLUYfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S505>/Convert BLUY from [mm] to [m]'

  real_T ConvertREDYfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S505>/Convert REDY from [mm] to [m]'

  real_T Constant_Value;               // Expression: 1
                                          //  Referenced by: '<S506>/Constant'

  real_T ControlDynamixelActuatorsineith;// Expression: 400
                                            //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_c;// Expression: 0
                                            //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_d;// Expression: 200
                                            //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_n;// Expression: 3072
                                            //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_g;// Expression: 1024
                                            //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsine_cw;// Expression: 0
                                            //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_e;// Expression: 850
                                            //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_k;// Expression: 400
                                            //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_j;// Expression: 100
                                            //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_l;// Expression: 50
                                            //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_o;// Expression: 0
                                            //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

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

  real_T EndTime_Y0_f;                 // Expression: 1
                                          //  Referenced by: '<S150>/End Time'

  real_T EndTime_YFinal_h;             // Expression: 0
                                          //  Referenced by: '<S150>/End Time'

  real_T Switch_Threshold_g;           // Expression: 0
                                          //  Referenced by: '<S150>/Switch'

  real_T StartPos_gainval_l;           // Computed Parameter: StartPos_gainval_l
                                          //  Referenced by: '<S151>/Start Pos'

  real_T EndTime_Y0_c;                 // Expression: 1
                                          //  Referenced by: '<S151>/End Time'

  real_T EndTime_YFinal_c;             // Expression: 0
                                          //  Referenced by: '<S151>/End Time'

  real_T Switch_Threshold_o;           // Expression: 0
                                          //  Referenced by: '<S151>/Switch'

  real_T PuckState_Value_c;            // Expression: 1
                                          //  Referenced by: '<S93>/Puck State'

  real_T Out1_Y0_dc;                   // Computed Parameter: Out1_Y0_dc
                                          //  Referenced by: '<S194>/Out1'

  real_T Out1_Y0_ap;                   // Computed Parameter: Out1_Y0_ap
                                          //  Referenced by: '<S196>/Out1'

  real_T Out1_Y0_jf;                   // Computed Parameter: Out1_Y0_jf
                                          //  Referenced by: '<S198>/Out1'

  real_T StartPos_gainval_a;           // Computed Parameter: StartPos_gainval_a
                                          //  Referenced by: '<S190>/Start Pos'

  real_T EndTime_Y0_k;                 // Expression: 1
                                          //  Referenced by: '<S190>/End Time'

  real_T EndTime_YFinal_e;             // Expression: 0
                                          //  Referenced by: '<S190>/End Time'

  real_T Switch_Threshold_j;           // Expression: 0
                                          //  Referenced by: '<S190>/Switch'

  real_T StartPos_gainval_al;         // Computed Parameter: StartPos_gainval_al
                                         //  Referenced by: '<S191>/Start Pos'

  real_T EndTime_Y0_e;                 // Expression: 1
                                          //  Referenced by: '<S191>/End Time'

  real_T EndTime_YFinal_j;             // Expression: 0
                                          //  Referenced by: '<S191>/End Time'

  real_T Switch_Threshold_jo;          // Expression: 0
                                          //  Referenced by: '<S191>/Switch'

  real_T StartPos_gainval_j;           // Computed Parameter: StartPos_gainval_j
                                          //  Referenced by: '<S192>/Start Pos'

  real_T EndTime_Y0_g;                 // Expression: 1
                                          //  Referenced by: '<S192>/End Time'

  real_T EndTime_YFinal_cq;            // Expression: 0
                                          //  Referenced by: '<S192>/End Time'

  real_T Switch_Threshold_i;           // Expression: 0
                                          //  Referenced by: '<S192>/Switch'

  real_T PuckState_Value_p;            // Expression: 1
                                          //  Referenced by: '<S162>/Puck State'

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

  real_T PuckState_Value_g;            // Expression: 1
                                          //  Referenced by: '<S246>/Puck State'

  real_T Constant4_Value_k;            // Expression: pi/2
                                          //  Referenced by: '<S354>/Constant4'

  real_T Constant5_Value;              // Expression: pi/3
                                          //  Referenced by: '<S354>/Constant5'

  real_T Constant6_Value;              // Expression: 0
                                          //  Referenced by: '<S354>/Constant6'

  real_T Constant7_Value;              // Expression: 1
                                          //  Referenced by: '<S354>/Constant7'

  real_T Force_Value[3];               // Expression: [0,0,0]
                                          //  Referenced by: '<S356>/Force'

  real_T Delay_InitialCondition_n;     // Expression: 0.0
                                          //  Referenced by: '<S368>/Delay'

  real_T Delay_InitialCondition_l;     // Expression: 0.0
                                          //  Referenced by: '<S369>/Delay'

  real_T Delay3_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S364>/Delay3'

  real_T Delay_InitialCondition_p[3];  // Expression: [0;0;0]
                                          //  Referenced by: '<S363>/Delay'

  real_T Delay1_InitialCondition_d[3]; // Expression: [0;0;0]
                                          //  Referenced by: '<S363>/Delay1'

  real_T Delay3_InitialCondition_a;    // Expression: 0.0
                                          //  Referenced by: '<S370>/Delay3'

  real_T Delay3_InitialCondition_e;    // Expression: 0.0
                                          //  Referenced by: '<S366>/Delay3'

  real_T Delay1_InitialCondition_o;    // Expression: 0.0
                                          //  Referenced by: '<S366>/Delay1'

  real_T Delay3_InitialCondition_p;    // Expression: 0.0
                                          //  Referenced by: '<S365>/Delay3'

  real_T Delay1_InitialCondition_p;    // Expression: 0.0
                                          //  Referenced by: '<S365>/Delay1'

  real_T DiscreteTimeIntegrator4_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator4_gainval
                             //  Referenced by: '<S349>/Discrete-Time Integrator4'

  real_T DiscreteTimeIntegrator5_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator5_gainval
                             //  Referenced by: '<S349>/Discrete-Time Integrator5'

  real_T DiscreteTimeIntegrator2_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator2_gainval
                             //  Referenced by: '<S349>/Discrete-Time Integrator2'

  real_T DiscreteTimeIntegrator3_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator3_gainval
                             //  Referenced by: '<S349>/Discrete-Time Integrator3'

  real_T Switch_Threshold_d;           // Expression: 0
                                          //  Referenced by: '<S247>/Switch'

  real_T DiscreteTimeIntegrator1_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainval
                             //  Referenced by: '<S349>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S349>/Discrete-Time Integrator'

  real_T Constant_Value_j[3];          // Expression: [0;0;0]
                                          //  Referenced by: '<S368>/Constant'

  real_T Constant1_Value[3];           // Expression: [0;0;0]
                                          //  Referenced by: '<S369>/Constant1'

  real_T Constant1_Value_j;            // Expression: 0
                                          //  Referenced by: '<S247>/Constant1'

  real_T PuckState_Value_a;            // Expression: 1
                                          //  Referenced by: '<S247>/Puck State'

  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<S501>/Constant3'

  real_T Constant4_Value_g;            // Expression: 0
                                          //  Referenced by: '<S501>/Constant4'

  real_T Constant5_Value_d;            // Expression: 0
                                          //  Referenced by: '<S501>/Constant5'

  real_T PuckState_Value_d;            // Expression: 0
                                          //  Referenced by: '<S501>/Puck State'

  real_T Constant_Value_b;             // Expression: 0
                                          //  Referenced by: '<S503>/Constant'

  real_T Constant1_Value_f;            // Expression: 0
                                          //  Referenced by: '<S503>/Constant1'

  real_T Constant2_Value_h;            // Expression: 0
                                          //  Referenced by: '<S503>/Constant2'

  real_T Constant3_Value_h;            // Expression: 0
                                          //  Referenced by: '<S503>/Constant3'

  real_T PuckState_Value_e;            // Expression: 0
                                          //  Referenced by: '<S503>/Puck State'

  real_T Gain_Gain;                    // Expression: -1
                                          //  Referenced by: '<S503>/Gain'

  real_T Saturation_UpperSat;          // Expression: 0.005
                                          //  Referenced by: '<S503>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -0.005
                                          //  Referenced by: '<S503>/Saturation'

  real_T BLACKPWM_Y0;                  // Computed Parameter: BLACKPWM_Y0
                                          //  Referenced by: '<S607>/BLACK PWM'

  real_T RemoveNegatives_UpperSat;     // Expression: 1000
                                          //  Referenced by: '<S610>/Remove Negatives'

  real_T RemoveNegatives_LowerSat;     // Expression: 0
                                          //  Referenced by: '<S610>/Remove Negatives'

  real_T BLUEPWM_Y0;                   // Computed Parameter: BLUEPWM_Y0
                                          //  Referenced by: '<S608>/BLUE PWM'

  real_T RemoveNegatives_UpperSat_m;   // Expression: 1000
                                          //  Referenced by: '<S622>/Remove Negatives'

  real_T RemoveNegatives_LowerSat_a;   // Expression: 0
                                          //  Referenced by: '<S622>/Remove Negatives'

  real_T REDPWM_Y0;                    // Computed Parameter: REDPWM_Y0
                                          //  Referenced by: '<S609>/RED PWM'

  real_T RemoveNegatives_UpperSat_k;   // Expression: 1000
                                          //  Referenced by: '<S634>/Remove Negatives'

  real_T RemoveNegatives_LowerSat_k;   // Expression: 0
                                          //  Referenced by: '<S634>/Remove Negatives'

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

  real_T BLACK_Py_InitialValue;        // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Py'

  real_T BLACK_Py1_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Py1'

  real_T BLACK_Py2_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Py2'

  real_T BLACK_Py3_InitialValue;       // Expression: 0
                                          //  Referenced by: '<Root>/BLACK_Py3'

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
                                          //  Referenced by: '<S505>/UDP Receive1'

  int32_T Delay_InitialCondition_g;
                                 // Computed Parameter: Delay_InitialCondition_g
                                    //  Referenced by: '<S505>/Delay'

  int32_T Delay1_InitialCondition_h;
                                // Computed Parameter: Delay1_InitialCondition_h
                                   //  Referenced by: '<S505>/Delay1'

  int32_T Delay2_InitialCondition_j;
                                // Computed Parameter: Delay2_InitialCondition_j
                                   //  Referenced by: '<S505>/Delay2'

  int32_T UDPReceive_Port;             // Computed Parameter: UDPReceive_Port
                                          //  Referenced by: '<S505>/UDP Receive'

  int32_T UDPReceive2_Port;            // Computed Parameter: UDPReceive2_Port
                                          //  Referenced by: '<S505>/UDP Receive2'

  int32_T UDPReceive3_Port;            // Computed Parameter: UDPReceive3_Port
                                          //  Referenced by: '<S505>/UDP Receive3'

  int32_T UDPSend_Port_d;              // Computed Parameter: UDPSend_Port_d
                                          //  Referenced by: '<S548>/UDP Send'

  int32_T UDPReceive1_Port_f;          // Computed Parameter: UDPReceive1_Port_f
                                          //  Referenced by: '<S2>/UDP Receive1'

  int32_T UDPSend_Port_d5;             // Computed Parameter: UDPSend_Port_d5
                                          //  Referenced by: '<S19>/UDP Send'

  P_ChangeBLUEBehavior_APF_Path_T ChangeBLUEBehavior_l;// '<S12>/Change BLUE Behavior' 
  P_Phase4ReturnHome_APF_Path_P_T Phase5HoldHome;// '<Root>/Phase #5: Hold Home' 
  P_Phase4ReturnHome_APF_Path_P_T Phase4ReturnHome;// '<Root>/Phase #4: Return Home' 
  P_SimulatedPositionController_T SimulatedPositionController;
                                      // '<S354>/Simulated Position Controller'
  P_REDARM_APF_Path_Planning_20_T REDARM_m;// '<S246>/RED+ARM'
  P_SubPhase1_APF_Path_Planni_h_T SubPhase2_p;// '<S89>/Sub-Phase #2 '
  P_SubPhase1_APF_Path_Planni_h_T SubPhase1_p;// '<S89>/Sub-Phase #1'
  P_SubPhase1_APF_Path_Planni_a_T SubPhase3_e;// '<S88>/Sub-Phase #3 '
  P_SubPhase1_APF_Path_Planni_a_T SubPhase2_c;// '<S88>/Sub-Phase #2 '
  P_SubPhase1_APF_Path_Planni_a_T SubPhase1_g;// '<S88>/Sub-Phase #1'
  P_SubPhase1_APF_Path_Planning_T SubPhase3;// '<S87>/Sub-Phase #3 '
  P_SubPhase1_APF_Path_Planning_T SubPhase2;// '<S87>/Sub-Phase #2 '
  P_SubPhase1_APF_Path_Planning_T SubPhase1;// '<S87>/Sub-Phase #1'
  P_REDARM_APF_Path_Planning_20_T REDARM_e;// '<S35>/RED+ARM'
  P_Phase0Synchronization_APF_P_T Phase1StartFloating;// '<Root>/Phase #1: Start Floating ' 
  P_Phase0Synchronization_APF_P_T Phase0Synchronization;// '<Root>/Phase #0: Synchronization' 
  P_ChangeBLACKBehavior_APF_Pat_T ChangeBLUEBehavior;// '<S1>/Change BLUE Behavior' 
  P_ChangeBLACKBehavior_APF_Pat_T ChangeBLACKBehavior;// '<S1>/Change BLACK Behavior' 
};

// Real-time Model Data Structure
struct tag_RTM_APF_Path_Planning_202_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

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

  extern P_APF_Path_Planning_2023a_Blu_T APF_Path_Planning_2023a_BlueI_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_APF_Path_Planning_2023a_Blu_T APF_Path_Planning_2023a_BlueI_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_APF_Path_Planning_2023a_Bl_T APF_Path_Planning_2023a_Blue_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void APF_Path_Planning_2023a_BlueIsBlack_initialize(void);
  extern void APF_Path_Planning_2023a_BlueIsBlack_step(void);
  extern void APF_Path_Planning_2023a_BlueIsBlack_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_APF_Path_Planning_20_T *const APF_Path_Planning_2023a_Blue_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S3>/To Workspace' : Unused code path elimination
//  Block '<S350>/Reshape' : Unused code path elimination
//  Block '<S350>/Reshape1' : Unused code path elimination
//  Block '<S350>/To Workspace' : Unused code path elimination
//  Block '<S350>/To Workspace1' : Unused code path elimination
//  Block '<S350>/To Workspace2' : Unused code path elimination
//  Block '<S350>/To Workspace3' : Unused code path elimination
//  Block '<S350>/To Workspace4' : Unused code path elimination
//  Block '<S247>/To Workspace2' : Unused code path elimination
//  Block '<S247>/actual' : Unused code path elimination
//  Block '<S247>/command' : Unused code path elimination
//  Block '<S356>/Reshape1' : Reshape block reduction
//  Block '<S505>/Reshape' : Reshape block reduction


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
//  '<Root>' : 'APF_Path_Planning_2023a_BlueIsBlack'
//  '<S1>'   : 'APF_Path_Planning_2023a_BlueIsBlack/Check Connection'
//  '<S2>'   : 'APF_Path_Planning_2023a_BlueIsBlack/Collect  ZED Data'
//  '<S3>'   : 'APF_Path_Planning_2023a_BlueIsBlack/Data Logger Subsystem'
//  '<S4>'   : 'APF_Path_Planning_2023a_BlueIsBlack/Float Code'
//  '<S5>'   : 'APF_Path_Planning_2023a_BlueIsBlack/Manipulator Encoder Data'
//  '<S6>'   : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #0: Synchronization'
//  '<S7>'   : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #1: Start Floating '
//  '<S8>'   : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position'
//  '<S9>'   : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment'
//  '<S10>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home'
//  '<S11>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home'
//  '<S12>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #6: Clean Shutdown'
//  '<S13>'  : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code'
//  '<S14>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Platform Identification'
//  '<S15>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Robotic  Arm Code'
//  '<S16>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Send Data to TX2'
//  '<S17>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics'
//  '<S18>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Simulation Status'
//  '<S19>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code'
//  '<S20>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Check Connection/Change BLACK Behavior'
//  '<S21>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Check Connection/Change BLUE Behavior'
//  '<S22>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Check Connection/Change RED Behavior'
//  '<S23>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Data Logger Subsystem/Data Logger'
//  '<S24>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Data Logger Subsystem/Data Logger/MATLAB Function'
//  '<S25>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Float Code/Enable Pucks'
//  '<S26>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Manipulator Encoder Data/Change RED Behavior'
//  '<S27>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #0: Synchronization/Change BLACK Behavior'
//  '<S28>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #0: Synchronization/Change BLUE Behavior'
//  '<S29>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #0: Synchronization/Change RED Behavior'
//  '<S30>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #1: Start Floating /Change BLACK Behavior'
//  '<S31>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #1: Start Floating /Change BLUE Behavior'
//  '<S32>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #1: Start Floating /Change RED Behavior'
//  '<S33>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLACK Behavior'
//  '<S34>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLUE Behavior'
//  '<S35>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior'
//  '<S36>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLACK Behavior/Custom Discrete PD (Attitude)'
//  '<S37>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLACK Behavior/Custom Discrete PD (X-Position)'
//  '<S38>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLACK Behavior/Custom Discrete PD (Y-Position)'
//  '<S39>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLACK Behavior/Hough Control'
//  '<S40>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLACK Behavior/Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S41>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLACK Behavior/Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S42>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLACK Behavior/Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S43>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLACK Behavior/Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S44>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLACK Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S45>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLACK Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S46>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLACK Behavior/Hough Control/MATLAB Function2'
//  '<S47>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLACK Behavior/Hough Control/MATLAB Function3'
//  '<S48>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLACK Behavior/Hough Control/MATLAB Function4'
//  '<S49>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLUE Behavior/Custom Discrete PD (Attitude)'
//  '<S50>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLUE Behavior/Custom Discrete PD (X-Position)'
//  '<S51>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLUE Behavior/Custom Discrete PD (Y-Position)'
//  '<S52>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLUE Behavior/Hough Control'
//  '<S53>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLUE Behavior/Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S54>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLUE Behavior/Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S55>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLUE Behavior/Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S56>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLUE Behavior/Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S57>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLUE Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S58>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLUE Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S59>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLUE Behavior/Hough Control/MATLAB Function2'
//  '<S60>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLUE Behavior/Hough Control/MATLAB Function3'
//  '<S61>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change BLUE Behavior/Hough Control/MATLAB Function4'
//  '<S62>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/Custom Discrete PD (Attitude)'
//  '<S63>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/Custom Discrete PD (X-Position)'
//  '<S64>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/Custom Discrete PD (Y-Position)'
//  '<S65>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/Hough Control'
//  '<S66>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/RED+ARM'
//  '<S67>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/Custom Discrete PD (Attitude)/x_dot -> x2'
//  '<S68>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/Custom Discrete PD (Attitude)/x_dot -> x2/Hold this value'
//  '<S69>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/Custom Discrete PD (X-Position)/x_dot -> x2'
//  '<S70>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/Custom Discrete PD (X-Position)/x_dot -> x2/Hold this value'
//  '<S71>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/Custom Discrete PD (Y-Position)/x_dot -> x2'
//  '<S72>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/Custom Discrete PD (Y-Position)/x_dot -> x2/Hold this value'
//  '<S73>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/Hough Control/MATLAB Function2'
//  '<S74>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/Hough Control/MATLAB Function3'
//  '<S75>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/Hough Control/MATLAB Function4'
//  '<S76>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Passthrough for Experiment'
//  '<S77>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Simulated Position Controller'
//  '<S78>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)'
//  '<S79>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)'
//  '<S80>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)'
//  '<S81>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2'
//  '<S82>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2/Hold this value'
//  '<S83>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2'
//  '<S84>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2/Hold this value'
//  '<S85>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2'
//  '<S86>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #2: Initial Position/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2/Hold this value'
//  '<S87>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior'
//  '<S88>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior'
//  '<S89>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior'
//  '<S90>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1'
//  '<S91>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 '
//  '<S92>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 '
//  '<S93>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4'
//  '<S94>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/BLACK_Rz Desired'
//  '<S95>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Custom Discrete PD (Attitude)'
//  '<S96>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Custom Discrete PD (X-Position)'
//  '<S97>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Custom Discrete PD (Y-Position)'
//  '<S98>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Hough Control'
//  '<S99>'  : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/BLACK_Rz Desired/Subsystem'
//  '<S100>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/BLACK_Rz Desired/Wrap1'
//  '<S101>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/BLACK_Rz Desired/Wrap1/MATLAB Function'
//  '<S102>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S103>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S104>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S105>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S106>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S107>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S108>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Hough Control/MATLAB Function2'
//  '<S109>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Hough Control/MATLAB Function3'
//  '<S110>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #1/Hough Control/MATLAB Function4'
//  '<S111>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /BLACK_Rz Desired'
//  '<S112>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Custom Discrete PD (Attitude)'
//  '<S113>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Custom Discrete PD (X-Position)'
//  '<S114>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Custom Discrete PD (Y-Position)'
//  '<S115>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Hough Control'
//  '<S116>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /BLACK_Rz Desired/Subsystem'
//  '<S117>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /BLACK_Rz Desired/Wrap1'
//  '<S118>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /BLACK_Rz Desired/Wrap1/MATLAB Function'
//  '<S119>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S120>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S121>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S122>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S123>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S124>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S125>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Hough Control/MATLAB Function2'
//  '<S126>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Hough Control/MATLAB Function3'
//  '<S127>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #2 /Hough Control/MATLAB Function4'
//  '<S128>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /BLACK_Rz Desired'
//  '<S129>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Custom Discrete PD (Attitude)'
//  '<S130>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Custom Discrete PD (X-Position)'
//  '<S131>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Custom Discrete PD (Y-Position)'
//  '<S132>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Hough Control'
//  '<S133>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /BLACK_Rz Desired/Subsystem'
//  '<S134>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /BLACK_Rz Desired/Wrap1'
//  '<S135>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /BLACK_Rz Desired/Wrap1/MATLAB Function'
//  '<S136>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S137>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S138>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S139>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S140>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S141>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S142>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Hough Control/MATLAB Function2'
//  '<S143>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Hough Control/MATLAB Function3'
//  '<S144>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #3 /Hough Control/MATLAB Function4'
//  '<S145>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Custom Discrete PD (Attitude)'
//  '<S146>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Custom Discrete PD (X-Position)'
//  '<S147>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Custom Discrete PD (Y-Position)'
//  '<S148>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Hough Control'
//  '<S149>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Motion X'
//  '<S150>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Motion Y'
//  '<S151>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Motion Z'
//  '<S152>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S153>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S154>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S155>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S156>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S157>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S158>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Hough Control/MATLAB Function2'
//  '<S159>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Hough Control/MATLAB Function3'
//  '<S160>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLACK Behavior/Sub-Phase #4/Hough Control/MATLAB Function4'
//  '<S161>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1'
//  '<S162>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2'
//  '<S163>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 '
//  '<S164>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 '
//  '<S165>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/BLUE_Rz Desired'
//  '<S166>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Custom Discrete PD (Attitude)'
//  '<S167>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Custom Discrete PD (X-Position)'
//  '<S168>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Custom Discrete PD (Y-Position)'
//  '<S169>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Hough Control'
//  '<S170>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/MATLAB Function2'
//  '<S171>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/MATLAB Function3'
//  '<S172>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Subsystem2'
//  '<S173>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/BLUE_Rz Desired/Subsystem'
//  '<S174>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/BLUE_Rz Desired/Wrap'
//  '<S175>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/BLUE_Rz Desired/Wrap/MATLAB Function'
//  '<S176>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S177>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S178>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S179>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S180>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S181>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S182>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Hough Control/MATLAB Function2'
//  '<S183>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Hough Control/MATLAB Function3'
//  '<S184>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Hough Control/MATLAB Function4'
//  '<S185>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #1/Subsystem2/Subsystem'
//  '<S186>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2/Custom Discrete PD (Attitude)'
//  '<S187>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2/Custom Discrete PD (X-Position)'
//  '<S188>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2/Custom Discrete PD (Y-Position)'
//  '<S189>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2/Hough Control'
//  '<S190>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2/Motion X'
//  '<S191>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2/Motion Y'
//  '<S192>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2/Motion Z'
//  '<S193>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2/Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S194>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2/Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S195>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2/Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S196>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2/Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S197>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2/Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S198>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2/Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S199>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2/Hough Control/MATLAB Function2'
//  '<S200>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2/Hough Control/MATLAB Function3'
//  '<S201>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2/Hough Control/MATLAB Function4'
//  '<S202>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /BLUE_Rz Desired'
//  '<S203>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Custom Discrete PD (Attitude)'
//  '<S204>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Custom Discrete PD (X-Position)'
//  '<S205>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Custom Discrete PD (Y-Position)'
//  '<S206>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Hough Control'
//  '<S207>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /MATLAB Function2'
//  '<S208>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /MATLAB Function3'
//  '<S209>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Subsystem2'
//  '<S210>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /BLUE_Rz Desired/Subsystem'
//  '<S211>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /BLUE_Rz Desired/Wrap'
//  '<S212>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /BLUE_Rz Desired/Wrap/MATLAB Function'
//  '<S213>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S214>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S215>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S216>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S217>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S218>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S219>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Hough Control/MATLAB Function2'
//  '<S220>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Hough Control/MATLAB Function3'
//  '<S221>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Hough Control/MATLAB Function4'
//  '<S222>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #2 /Subsystem2/Subsystem'
//  '<S223>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /BLUE_Rz Desired'
//  '<S224>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Custom Discrete PD (Attitude)'
//  '<S225>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Custom Discrete PD (X-Position)'
//  '<S226>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Custom Discrete PD (Y-Position)'
//  '<S227>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Hough Control'
//  '<S228>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /MATLAB Function2'
//  '<S229>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /MATLAB Function3'
//  '<S230>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Subsystem2'
//  '<S231>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /BLUE_Rz Desired/Subsystem'
//  '<S232>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /BLUE_Rz Desired/Wrap'
//  '<S233>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /BLUE_Rz Desired/Wrap/MATLAB Function'
//  '<S234>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S235>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S236>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S237>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S238>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S239>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S240>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Hough Control/MATLAB Function2'
//  '<S241>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Hough Control/MATLAB Function3'
//  '<S242>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Hough Control/MATLAB Function4'
//  '<S243>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change BLUE Behavior/Sub-Phase #3 /Subsystem2/Subsystem'
//  '<S244>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1'
//  '<S245>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 '
//  '<S246>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 '
//  '<S247>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4'
//  '<S248>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Custom Discrete PD (Attitude)'
//  '<S249>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Custom Discrete PD (X-Position)'
//  '<S250>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Custom Discrete PD (Y-Position)'
//  '<S251>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Hough Control'
//  '<S252>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/MATLAB Function'
//  '<S253>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/MATLAB Function1'
//  '<S254>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM'
//  '<S255>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED_Rz Desired'
//  '<S256>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Subsystem1'
//  '<S257>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Custom Discrete PD (Attitude)/x_dot -> x2'
//  '<S258>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Custom Discrete PD (Attitude)/x_dot -> x2/Hold this value'
//  '<S259>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Custom Discrete PD (X-Position)/x_dot -> x2'
//  '<S260>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Custom Discrete PD (X-Position)/x_dot -> x2/Hold this value'
//  '<S261>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Custom Discrete PD (Y-Position)/x_dot -> x2'
//  '<S262>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Custom Discrete PD (Y-Position)/x_dot -> x2/Hold this value'
//  '<S263>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Hough Control/MATLAB Function2'
//  '<S264>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Hough Control/MATLAB Function3'
//  '<S265>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Hough Control/MATLAB Function4'
//  '<S266>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Passthrough for Experiment'
//  '<S267>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Simulated Position Controller'
//  '<S268>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)'
//  '<S269>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)'
//  '<S270>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)'
//  '<S271>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2'
//  '<S272>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2/Hold this value'
//  '<S273>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2'
//  '<S274>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2/Hold this value'
//  '<S275>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2'
//  '<S276>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2/Hold this value'
//  '<S277>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED_Rz Desired/Subsystem'
//  '<S278>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED_Rz Desired/Wrap'
//  '<S279>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/RED_Rz Desired/Wrap/MATLAB Function'
//  '<S280>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #1/Subsystem1/Subsystem'
//  '<S281>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Custom Discrete PD (Attitude)'
//  '<S282>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Custom Discrete PD (X-Position)'
//  '<S283>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Custom Discrete PD (Y-Position)'
//  '<S284>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Hough Control'
//  '<S285>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /MATLAB Function'
//  '<S286>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /MATLAB Function1'
//  '<S287>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM'
//  '<S288>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED_Rz Desired'
//  '<S289>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Subsystem1'
//  '<S290>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Custom Discrete PD (Attitude)/x_dot -> x2'
//  '<S291>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Custom Discrete PD (Attitude)/x_dot -> x2/Hold this value'
//  '<S292>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Custom Discrete PD (X-Position)/x_dot -> x2'
//  '<S293>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Custom Discrete PD (X-Position)/x_dot -> x2/Hold this value'
//  '<S294>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Custom Discrete PD (Y-Position)/x_dot -> x2'
//  '<S295>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Custom Discrete PD (Y-Position)/x_dot -> x2/Hold this value'
//  '<S296>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Hough Control/MATLAB Function2'
//  '<S297>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Hough Control/MATLAB Function3'
//  '<S298>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Hough Control/MATLAB Function4'
//  '<S299>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Passthrough for Experiment'
//  '<S300>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Simulated Position Controller'
//  '<S301>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)'
//  '<S302>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)'
//  '<S303>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)'
//  '<S304>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2'
//  '<S305>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2/Hold this value'
//  '<S306>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2'
//  '<S307>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2/Hold this value'
//  '<S308>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2'
//  '<S309>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2/Hold this value'
//  '<S310>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED_Rz Desired/Subsystem'
//  '<S311>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED_Rz Desired/Wrap'
//  '<S312>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /RED_Rz Desired/Wrap/MATLAB Function'
//  '<S313>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #2 /Subsystem1/Subsystem'
//  '<S314>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Custom Discrete PD (Attitude)'
//  '<S315>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Custom Discrete PD (X-Position)'
//  '<S316>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Custom Discrete PD (Y-Position)'
//  '<S317>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Hough Control'
//  '<S318>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /MATLAB Function'
//  '<S319>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /MATLAB Function1'
//  '<S320>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM'
//  '<S321>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED_Rz Desired'
//  '<S322>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Subsystem1'
//  '<S323>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Custom Discrete PD (Attitude)/x_dot -> x2'
//  '<S324>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Custom Discrete PD (Attitude)/x_dot -> x2/Hold this value'
//  '<S325>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Custom Discrete PD (X-Position)/x_dot -> x2'
//  '<S326>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Custom Discrete PD (X-Position)/x_dot -> x2/Hold this value'
//  '<S327>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Custom Discrete PD (Y-Position)/x_dot -> x2'
//  '<S328>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Custom Discrete PD (Y-Position)/x_dot -> x2/Hold this value'
//  '<S329>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Hough Control/MATLAB Function2'
//  '<S330>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Hough Control/MATLAB Function3'
//  '<S331>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Hough Control/MATLAB Function4'
//  '<S332>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Passthrough for Experiment'
//  '<S333>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Simulated Position Controller'
//  '<S334>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)'
//  '<S335>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)'
//  '<S336>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)'
//  '<S337>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2'
//  '<S338>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2/Hold this value'
//  '<S339>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2'
//  '<S340>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2/Hold this value'
//  '<S341>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2'
//  '<S342>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2/Hold this value'
//  '<S343>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED_Rz Desired/Subsystem'
//  '<S344>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED_Rz Desired/Wrap'
//  '<S345>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /RED_Rz Desired/Wrap/MATLAB Function'
//  '<S346>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #3 /Subsystem1/Subsystem'
//  '<S347>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/BLACK'
//  '<S348>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/BLUE'
//  '<S349>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/DAC Controller1'
//  '<S350>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC'
//  '<S351>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/Hough Control'
//  '<S352>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/Looking Angle'
//  '<S353>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED'
//  '<S354>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM'
//  '<S355>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/BLACK/Ryan's Transform'
//  '<S356>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/BLACK/UKF2'
//  '<S357>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/BLACK/UKF2/MATLAB Function'
//  '<S358>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/DAC Controller1/Fx Gain Derivatives'
//  '<S359>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/DAC Controller1/Fy Gain Derivatives'
//  '<S360>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/DAC Controller1/Torque Gain Derivatives'
//  '<S361>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/MATLAB Function'
//  '<S362>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Subsystem1'
//  '<S363>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Subsystem1/AdaDelta'
//  '<S364>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Subsystem1/AdaGrad'
//  '<S365>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Subsystem1/AdaMax'
//  '<S366>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Subsystem1/Adam'
//  '<S367>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Subsystem1/Gradient Descent'
//  '<S368>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Subsystem1/Momentum'
//  '<S369>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Subsystem1/Nesterov'
//  '<S370>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Subsystem1/RMSProp'
//  '<S371>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Subsystem1/AdaDelta/MATLAB Function1'
//  '<S372>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Subsystem1/AdaGrad/MATLAB Function1'
//  '<S373>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Subsystem1/AdaMax/MATLAB Function1'
//  '<S374>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Subsystem1/Adam/MATLAB Function1'
//  '<S375>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Subsystem1/Gradient Descent/Batch'
//  '<S376>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Subsystem1/Momentum/Momentum'
//  '<S377>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Subsystem1/Nesterov/MATLAB Function1'
//  '<S378>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/GDC/Subsystem1/RMSProp/MATLAB Function1'
//  '<S379>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/Hough Control/MATLAB Function2'
//  '<S380>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/Hough Control/MATLAB Function3'
//  '<S381>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/Hough Control/MATLAB Function4'
//  '<S382>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Passthrough for Experiment'
//  '<S383>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Simulated Position Controller'
//  '<S384>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)'
//  '<S385>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)'
//  '<S386>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)'
//  '<S387>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2'
//  '<S388>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2/Hold this value'
//  '<S389>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2'
//  '<S390>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2/Hold this value'
//  '<S391>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2'
//  '<S392>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #3: Experiment/Change RED Behavior/Sub-Phase #4/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2/Hold this value'
//  '<S393>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLACK Behavior'
//  '<S394>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLUE Behavior'
//  '<S395>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior'
//  '<S396>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLACK Behavior/Custom Discrete PD (Attitude)'
//  '<S397>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLACK Behavior/Custom Discrete PD (X-Position)'
//  '<S398>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLACK Behavior/Custom Discrete PD (Y-Position)'
//  '<S399>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLACK Behavior/Hough Control'
//  '<S400>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLACK Behavior/Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S401>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLACK Behavior/Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S402>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLACK Behavior/Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S403>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLACK Behavior/Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S404>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLACK Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S405>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLACK Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S406>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLACK Behavior/Hough Control/MATLAB Function2'
//  '<S407>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLACK Behavior/Hough Control/MATLAB Function3'
//  '<S408>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLACK Behavior/Hough Control/MATLAB Function4'
//  '<S409>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLUE Behavior/Custom Discrete PD (Attitude)'
//  '<S410>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLUE Behavior/Custom Discrete PD (X-Position)'
//  '<S411>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLUE Behavior/Custom Discrete PD (Y-Position)'
//  '<S412>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLUE Behavior/Hough Control'
//  '<S413>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLUE Behavior/Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S414>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLUE Behavior/Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S415>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLUE Behavior/Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S416>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLUE Behavior/Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S417>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLUE Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S418>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLUE Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S419>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLUE Behavior/Hough Control/MATLAB Function2'
//  '<S420>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLUE Behavior/Hough Control/MATLAB Function3'
//  '<S421>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change BLUE Behavior/Hough Control/MATLAB Function4'
//  '<S422>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/Custom Discrete PD (Attitude)'
//  '<S423>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/Custom Discrete PD (X-Position)'
//  '<S424>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/Custom Discrete PD (Y-Position)'
//  '<S425>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/Hough Control'
//  '<S426>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/RED+ARM'
//  '<S427>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/Custom Discrete PD (Attitude)/x_dot -> x2'
//  '<S428>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/Custom Discrete PD (Attitude)/x_dot -> x2/Hold this value'
//  '<S429>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/Custom Discrete PD (X-Position)/x_dot -> x2'
//  '<S430>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/Custom Discrete PD (X-Position)/x_dot -> x2/Hold this value'
//  '<S431>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/Custom Discrete PD (Y-Position)/x_dot -> x2'
//  '<S432>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/Custom Discrete PD (Y-Position)/x_dot -> x2/Hold this value'
//  '<S433>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/Hough Control/MATLAB Function2'
//  '<S434>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/Hough Control/MATLAB Function3'
//  '<S435>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/Hough Control/MATLAB Function4'
//  '<S436>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/RED+ARM/Passthrough for Experiment'
//  '<S437>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/RED+ARM/Simulated Position Controller'
//  '<S438>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)'
//  '<S439>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)'
//  '<S440>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)'
//  '<S441>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2'
//  '<S442>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2/Hold this value'
//  '<S443>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2'
//  '<S444>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2/Hold this value'
//  '<S445>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2'
//  '<S446>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #4: Return Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2/Hold this value'
//  '<S447>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLACK Behavior'
//  '<S448>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLUE Behavior'
//  '<S449>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior'
//  '<S450>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLACK Behavior/Custom Discrete PD (Attitude)'
//  '<S451>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLACK Behavior/Custom Discrete PD (X-Position)'
//  '<S452>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLACK Behavior/Custom Discrete PD (Y-Position)'
//  '<S453>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLACK Behavior/Hough Control'
//  '<S454>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLACK Behavior/Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S455>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLACK Behavior/Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S456>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLACK Behavior/Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S457>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLACK Behavior/Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S458>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLACK Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S459>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLACK Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S460>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLACK Behavior/Hough Control/MATLAB Function2'
//  '<S461>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLACK Behavior/Hough Control/MATLAB Function3'
//  '<S462>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLACK Behavior/Hough Control/MATLAB Function4'
//  '<S463>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLUE Behavior/Custom Discrete PD (Attitude)'
//  '<S464>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLUE Behavior/Custom Discrete PD (X-Position)'
//  '<S465>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLUE Behavior/Custom Discrete PD (Y-Position)'
//  '<S466>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLUE Behavior/Hough Control'
//  '<S467>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLUE Behavior/Custom Discrete PD (Attitude)/x_dot -> x1'
//  '<S468>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLUE Behavior/Custom Discrete PD (Attitude)/x_dot -> x1/Hold this value'
//  '<S469>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLUE Behavior/Custom Discrete PD (X-Position)/x_dot -> x1'
//  '<S470>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLUE Behavior/Custom Discrete PD (X-Position)/x_dot -> x1/Hold this value'
//  '<S471>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLUE Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1'
//  '<S472>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLUE Behavior/Custom Discrete PD (Y-Position)/x_dot -> x1/Hold this value'
//  '<S473>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLUE Behavior/Hough Control/MATLAB Function2'
//  '<S474>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLUE Behavior/Hough Control/MATLAB Function3'
//  '<S475>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change BLUE Behavior/Hough Control/MATLAB Function4'
//  '<S476>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/Custom Discrete PD (Attitude)'
//  '<S477>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/Custom Discrete PD (X-Position)'
//  '<S478>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/Custom Discrete PD (Y-Position)'
//  '<S479>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/Hough Control'
//  '<S480>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/RED+ARM'
//  '<S481>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/Custom Discrete PD (Attitude)/x_dot -> x2'
//  '<S482>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/Custom Discrete PD (Attitude)/x_dot -> x2/Hold this value'
//  '<S483>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/Custom Discrete PD (X-Position)/x_dot -> x2'
//  '<S484>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/Custom Discrete PD (X-Position)/x_dot -> x2/Hold this value'
//  '<S485>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/Custom Discrete PD (Y-Position)/x_dot -> x2'
//  '<S486>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/Custom Discrete PD (Y-Position)/x_dot -> x2/Hold this value'
//  '<S487>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/Hough Control/MATLAB Function2'
//  '<S488>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/Hough Control/MATLAB Function3'
//  '<S489>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/Hough Control/MATLAB Function4'
//  '<S490>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Passthrough for Experiment'
//  '<S491>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Simulated Position Controller'
//  '<S492>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)'
//  '<S493>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)'
//  '<S494>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)'
//  '<S495>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2'
//  '<S496>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Elbow)/x_dot -> x2/Hold this value'
//  '<S497>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2'
//  '<S498>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Shoulder)/x_dot -> x2/Hold this value'
//  '<S499>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2'
//  '<S500>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #5: Hold Home/Change RED Behavior/RED+ARM/Simulated Position Controller/Custom Discrete PD (Wrist)/x_dot -> x2/Hold this value'
//  '<S501>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #6: Clean Shutdown/Change BLACK Behavior'
//  '<S502>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #6: Clean Shutdown/Change BLUE Behavior'
//  '<S503>' : 'APF_Path_Planning_2023a_BlueIsBlack/Phase #6: Clean Shutdown/Change RED Behavior'
//  '<S504>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Initialize Universal Time (Simulation)'
//  '<S505>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States'
//  '<S506>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/Adjust Time'
//  '<S507>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/MATLAB Function'
//  '<S508>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x1'
//  '<S509>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x10'
//  '<S510>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x11'
//  '<S511>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x12'
//  '<S512>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x13'
//  '<S513>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x14'
//  '<S514>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x15'
//  '<S515>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x16'
//  '<S516>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x17'
//  '<S517>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x18'
//  '<S518>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x2'
//  '<S519>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x3'
//  '<S520>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x4'
//  '<S521>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x5'
//  '<S522>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x6'
//  '<S523>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x7'
//  '<S524>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x8'
//  '<S525>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x9'
//  '<S526>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/Adjust Time/Enabled Subsystem'
//  '<S527>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/Adjust Time/Enabled Subsystem1'
//  '<S528>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x1/Hold this value'
//  '<S529>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x10/Hold this value'
//  '<S530>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x11/Hold this value'
//  '<S531>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x12/Hold this value'
//  '<S532>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x13/Hold this value'
//  '<S533>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x14/Hold this value'
//  '<S534>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x15/Hold this value'
//  '<S535>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x16/Hold this value'
//  '<S536>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x17/Hold this value'
//  '<S537>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x18/Hold this value'
//  '<S538>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x2/Hold this value'
//  '<S539>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x3/Hold this value'
//  '<S540>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x4/Hold this value'
//  '<S541>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x5/Hold this value'
//  '<S542>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x6/Hold this value'
//  '<S543>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x7/Hold this value'
//  '<S544>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x8/Hold this value'
//  '<S545>' : 'APF_Path_Planning_2023a_BlueIsBlack/PhaseSpace Camera Code/Use Hardware to Obtain States/x_dot -> x9/Hold this value'
//  '<S546>' : 'APF_Path_Planning_2023a_BlueIsBlack/Platform Identification/Subsystem'
//  '<S547>' : 'APF_Path_Planning_2023a_BlueIsBlack/Robotic  Arm Code/Change RED Behavior'
//  '<S548>' : 'APF_Path_Planning_2023a_BlueIsBlack/Send Data to TX2/Subsystem'
//  '<S549>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLACK Dynamics'
//  '<S550>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLUE Dynamics'
//  '<S551>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics'
//  '<S552>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLACK Dynamics/BLACK Dynamics Model'
//  '<S553>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x1'
//  '<S554>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x2'
//  '<S555>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x3'
//  '<S556>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x4'
//  '<S557>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x5'
//  '<S558>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x7'
//  '<S559>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLACK Dynamics/BLACK Dynamics Model/MATLAB Function'
//  '<S560>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x1/Hold this value'
//  '<S561>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x2/Hold this value'
//  '<S562>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x3/Hold this value'
//  '<S563>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x4/Hold this value'
//  '<S564>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x5/Hold this value'
//  '<S565>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLACK Dynamics/x_dot -> x7/Hold this value'
//  '<S566>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLUE Dynamics/BLUE  Dynamics Model'
//  '<S567>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x1'
//  '<S568>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x2'
//  '<S569>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x3'
//  '<S570>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x4'
//  '<S571>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x5'
//  '<S572>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x7'
//  '<S573>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLUE Dynamics/BLUE  Dynamics Model/MATLAB Function'
//  '<S574>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x1/Hold this value'
//  '<S575>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x2/Hold this value'
//  '<S576>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x3/Hold this value'
//  '<S577>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x4/Hold this value'
//  '<S578>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x5/Hold this value'
//  '<S579>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/BLUE Dynamics/x_dot -> x7/Hold this value'
//  '<S580>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM'
//  '<S581>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only'
//  '<S582>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM/RED + ARM Dynamics'
//  '<S583>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM/RED + ARM Dynamics/Coriolis Function1'
//  '<S584>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM/RED + ARM Dynamics/Dynamics Model'
//  '<S585>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM/RED + ARM Dynamics/Inertia Function 1'
//  '<S586>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM/RED + ARM Dynamics/x_dot -> x1'
//  '<S587>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM/RED + ARM Dynamics/x_dot -> x2'
//  '<S588>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM/RED + ARM Dynamics/x_dot -> x3'
//  '<S589>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM/RED + ARM Dynamics/x_dot -> x1/Hold this value'
//  '<S590>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM/RED + ARM Dynamics/x_dot -> x2/Hold this value'
//  '<S591>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED + ARM/RED + ARM Dynamics/x_dot -> x3/Hold this value'
//  '<S592>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics'
//  '<S593>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/RED Dynamics Model'
//  '<S594>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x1'
//  '<S595>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x2'
//  '<S596>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x3'
//  '<S597>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x4'
//  '<S598>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x5'
//  '<S599>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x6'
//  '<S600>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/RED Dynamics Model/MATLAB Function'
//  '<S601>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x1/Hold this value'
//  '<S602>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x2/Hold this value'
//  '<S603>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x3/Hold this value'
//  '<S604>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x4/Hold this value'
//  '<S605>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x5/Hold this value'
//  '<S606>' : 'APF_Path_Planning_2023a_BlueIsBlack/Simulate Plant Dynamics/RED and ARM Dynamics/RED Only/RED Dynamics/x_dot -> x6/Hold this value'
//  '<S607>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLACK Behavior'
//  '<S608>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLUE Behavior'
//  '<S609>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior'
//  '<S610>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLACK Behavior/Calculate Thruster  ON//OFF'
//  '<S611>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLACK Behavior/Rotate Forces to Body'
//  '<S612>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLACK Behavior/Calculate Thruster  ON//OFF/MATLAB Function'
//  '<S613>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLACK Behavior/Calculate Thruster  ON//OFF/MATLAB Function1'
//  '<S614>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLACK Behavior/Calculate Thruster  ON//OFF/MATLAB Function10'
//  '<S615>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLACK Behavior/Calculate Thruster  ON//OFF/MATLAB Function11'
//  '<S616>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLACK Behavior/Calculate Thruster  ON//OFF/MATLAB Function3'
//  '<S617>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLACK Behavior/Calculate Thruster  ON//OFF/Rotate Forces to Inertial'
//  '<S618>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLACK Behavior/Calculate Thruster  ON//OFF/pseudo-inverse'
//  '<S619>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLACK Behavior/Calculate Thruster  ON//OFF/pseudo-inverse3'
//  '<S620>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLACK Behavior/Calculate Thruster  ON//OFF/Rotate Forces to Inertial/Create Rotation Matrix'
//  '<S621>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLACK Behavior/Rotate Forces to Body/Create Rotation Matrix'
//  '<S622>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLUE Behavior/Calculate Thruster  ON//OFF'
//  '<S623>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLUE Behavior/Rotate Forces to Body'
//  '<S624>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLUE Behavior/Calculate Thruster  ON//OFF/MATLAB Function'
//  '<S625>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLUE Behavior/Calculate Thruster  ON//OFF/MATLAB Function1'
//  '<S626>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLUE Behavior/Calculate Thruster  ON//OFF/MATLAB Function2'
//  '<S627>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLUE Behavior/Calculate Thruster  ON//OFF/MATLAB Function6'
//  '<S628>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLUE Behavior/Calculate Thruster  ON//OFF/MATLAB Function7'
//  '<S629>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLUE Behavior/Calculate Thruster  ON//OFF/Rotate Forces to Inertial'
//  '<S630>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLUE Behavior/Calculate Thruster  ON//OFF/pseudo-inverse'
//  '<S631>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLUE Behavior/Calculate Thruster  ON//OFF/pseudo-inverse2'
//  '<S632>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLUE Behavior/Calculate Thruster  ON//OFF/Rotate Forces to Inertial/Create Rotation Matrix'
//  '<S633>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change BLUE Behavior/Rotate Forces to Body/Create Rotation Matrix'
//  '<S634>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF'
//  '<S635>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Rotate Forces to Body'
//  '<S636>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/If Action Subsystem'
//  '<S637>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/If Action Subsystem1'
//  '<S638>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/If Action Subsystem2'
//  '<S639>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/If Action Subsystem3'
//  '<S640>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/If Action Subsystem4'
//  '<S641>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/If Action Subsystem5'
//  '<S642>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/MATLAB Function'
//  '<S643>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/MATLAB Function11'
//  '<S644>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/MATLAB Function2'
//  '<S645>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/MATLAB Function3'
//  '<S646>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/MATLAB Function4'
//  '<S647>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/MATLAB Function5'
//  '<S648>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/MATLAB Function6'
//  '<S649>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/MATLAB Function7'
//  '<S650>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/Rotate Forces to Inertial'
//  '<S651>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/pseudo-inverse'
//  '<S652>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/pseudo-inverse1'
//  '<S653>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Calculate Thruster  ON//OFF/Rotate Forces to Inertial/Create Rotation Matrix'
//  '<S654>' : 'APF_Path_Planning_2023a_BlueIsBlack/Thruster Control Code/Change RED Behavior/Rotate Forces to Body/Create Rotation Matrix'

#endif                     // RTW_HEADER_APF_Path_Planning_2023a_BlueIsBlack_h_

//
// File trailer for generated code.
//
// [EOF]
//
