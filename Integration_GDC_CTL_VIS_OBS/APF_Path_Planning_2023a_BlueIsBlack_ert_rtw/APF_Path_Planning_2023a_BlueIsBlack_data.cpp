//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: APF_Path_Planning_2023a_BlueIsBlack_data.cpp
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

// Block parameters (default storage)
P_APF_Path_Planning_2023a_Blu_T APF_Path_Planning_2023a_BlueI_P = {
  // Variable: Att_Mode
  //  Referenced by: '<S247>/Constant2'

  0.0,

  // Variable: BLACK_end
  //  Referenced by:
  //    '<S149>/End Pos'
  //    '<S150>/End Pos'
  //    '<S151>/End Pos'
  //    '<S190>/End Pos'
  //    '<S191>/End Pos'
  //    '<S192>/End Pos'

  { 2.0, 1.4, 6.4228116473391328 },

  // Variable: BLACK_ini
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

  { 1.3, 1.25, 4.71238898038469, 0.0, 0.0, -0.026179938779914945 },

  // Variable: Binv
  //  Referenced by:
  //    '<S350>/MATLAB Function'
  //    '<S369>/MATLAB Function1'

  { 12.0, 0.0, 0.0, 0.0, 12.0, 0.0, 0.0, 0.0, 0.19816 },

  // Variable: F_Black_X_nominal
  //  Referenced by:
  //    '<S610>/MATLAB Function11'
  //    '<S610>/MATLAB Function3'

  0.2196,

  // Variable: F_Black_Y_nominal
  //  Referenced by:
  //    '<S610>/MATLAB Function11'
  //    '<S610>/MATLAB Function3'

  0.2825,

  // Variable: F_Blue_X_nominal
  //  Referenced by:
  //    '<S622>/MATLAB Function1'
  //    '<S622>/MATLAB Function7'

  0.2196,

  // Variable: F_Blue_Y_nominal
  //  Referenced by:
  //    '<S622>/MATLAB Function1'
  //    '<S622>/MATLAB Function7'

  0.2825,

  // Variable: F_red_X_nominal
  //  Referenced by:
  //    '<S634>/MATLAB Function11'
  //    '<S634>/MATLAB Function4'
  //    '<S634>/MATLAB Function6'
  //    '<S634>/MATLAB Function7'

  0.2196,

  // Variable: F_red_Y_nominal
  //  Referenced by:
  //    '<S634>/MATLAB Function11'
  //    '<S634>/MATLAB Function4'
  //    '<S634>/MATLAB Function6'
  //    '<S634>/MATLAB Function7'

  0.2825,

  // Variable: F_thrusters_BLACK
  //  Referenced by: '<S610>/MATLAB Function'

  { 0.2196, 0.2196, 0.2825, 0.2825, 0.2196, 0.2196, 0.2825, 0.2825 },

  // Variable: F_thrusters_BLUE
  //  Referenced by: '<S622>/MATLAB Function'

  { 0.2196, 0.2196, 0.2825, 0.2825, 0.2196, 0.2196, 0.2825, 0.2825 },

  // Variable: F_thrusters_RED
  //  Referenced by:
  //    '<S634>/MATLAB Function'
  //    '<S634>/MATLAB Function3'

  { 0.2196, 0.2196, 0.2825, 0.2825, 0.2196, 0.2196, 0.2825, 0.2825 },

  // Variable: Gamma1_el
  //  Referenced by: '<S582>/Dynamics Model'

  0.12,

  // Variable: Gamma1_sh
  //  Referenced by: '<S582>/Dynamics Model'

  0.005,

  // Variable: Gamma1_wr
  //  Referenced by: '<S582>/Dynamics Model'

  0.025,

  // Variable: Gamma2_el
  //  Referenced by: '<S582>/Dynamics Model'

  5.0,

  // Variable: Gamma2_sh
  //  Referenced by: '<S582>/Dynamics Model'

  5.0,

  // Variable: Gamma2_wr
  //  Referenced by: '<S582>/Dynamics Model'

  5.0,

  // Variable: Gamma3_el
  //  Referenced by: '<S582>/Dynamics Model'

  10.0,

  // Variable: Gamma3_sh
  //  Referenced by: '<S582>/Dynamics Model'

  40.0,

  // Variable: Gamma3_wr
  //  Referenced by: '<S582>/Dynamics Model'

  40.0,

  // Variable: Gamma4_el
  //  Referenced by: '<S582>/Dynamics Model'

  0.039,

  // Variable: Gamma4_sh
  //  Referenced by: '<S582>/Dynamics Model'

  0.015,

  // Variable: Gamma4_wr
  //  Referenced by: '<S582>/Dynamics Model'

  0.029,

  // Variable: Gamma5_el
  //  Referenced by: '<S582>/Dynamics Model'

  800.0,

  // Variable: Gamma5_sh
  //  Referenced by: '<S582>/Dynamics Model'

  800.0,

  // Variable: Gamma5_wr
  //  Referenced by: '<S582>/Dynamics Model'

  800.0,

  // Variable: Gamma6_el
  //  Referenced by: '<S582>/Dynamics Model'

  1.0E-6,

  // Variable: Gamma6_sh
  //  Referenced by: '<S582>/Dynamics Model'

  0.005,

  // Variable: Gamma6_wr
  //  Referenced by: '<S582>/Dynamics Model'

  0.02,

  // Variable: H
  //  Referenced by: '<S356>/MATLAB Function'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 },

  // Variable: IBLACK
  //  Referenced by: '<S552>/MATLAB Function'

  0.19956537087503129,

  // Variable: IBLUE
  //  Referenced by: '<S566>/MATLAB Function'

  0.19609228544737417,

  // Variable: IDIST
  //  Referenced by: '<S582>/Inertia Function 1'

  0.003506,

  // Variable: IEE
  //  Referenced by: '<S582>/Inertia Function 1'

  0.000106,

  // Variable: IPROX
  //  Referenced by: '<S582>/Inertia Function 1'

  0.003704,

  // Variable: IRED
  //  Referenced by:
  //    '<S582>/Inertia Function 1'
  //    '<S593>/MATLAB Function'

  0.19816136536704418,

  // Variable: J
  //  Referenced by: '<S356>/MATLAB Function'

  0.19816136536704418,

  // Variable: K_a
  //  Referenced by:
  //    '<S350>/MATLAB Function'
  //    '<S369>/MATLAB Function1'

  { 2.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 3.5 },

  // Variable: Kd_elarm
  //  Referenced by:
  //    '<S78>/kd_elarm'
  //    '<S438>/kd_elarm'
  //    '<S492>/kd_elarm'
  //    '<S268>/kd_elarm'
  //    '<S301>/kd_elarm'
  //    '<S334>/kd_elarm'
  //    '<S384>/kd_elarm'

  0.8,

  // Variable: Kd_sharm
  //  Referenced by:
  //    '<S79>/kd_sharm'
  //    '<S439>/kd_sharm'
  //    '<S493>/kd_sharm'
  //    '<S269>/kd_sharm'
  //    '<S302>/kd_sharm'
  //    '<S335>/kd_sharm'
  //    '<S385>/kd_sharm'

  1.0,

  // Variable: Kd_tb
  //  Referenced by:
  //    '<S36>/kd_tb'
  //    '<S396>/kd_tb'
  //    '<S450>/kd_tb'
  //    '<S95>/kd_tb'
  //    '<S112>/kd_tb'
  //    '<S129>/kd_tb'
  //    '<S145>/kd_tb'
  //    '<S186>/kd_tb'

  1.2,

  // Variable: Kd_tblue
  //  Referenced by:
  //    '<S49>/kd_tb'
  //    '<S409>/kd_tb'
  //    '<S463>/kd_tb'
  //    '<S166>/kd_tb'
  //    '<S203>/kd_tb'
  //    '<S224>/kd_tb'

  1.2,

  // Variable: Kd_tr
  //  Referenced by:
  //    '<S62>/kd_tr'
  //    '<S422>/kd_tr'
  //    '<S476>/kd_tr'
  //    '<S248>/kd_tr'
  //    '<S281>/kd_tr'
  //    '<S314>/kd_tr'

  1.2,

  // Variable: Kd_wrarm
  //  Referenced by:
  //    '<S80>/kd_wrarm'
  //    '<S440>/kd_wrarm'
  //    '<S494>/kd_wrarm'
  //    '<S270>/kd_wrarm'
  //    '<S303>/kd_wrarm'
  //    '<S336>/kd_wrarm'
  //    '<S386>/kd_wrarm'

  0.6,

  // Variable: Kd_xb
  //  Referenced by:
  //    '<S37>/kd_xb'
  //    '<S397>/kd_xb'
  //    '<S451>/kd_xb'
  //    '<S96>/kd_xb'
  //    '<S113>/kd_xb'
  //    '<S130>/kd_xb'
  //    '<S146>/kd_xb'
  //    '<S187>/kd_xb'

  2.6,

  // Variable: Kd_xblue
  //  Referenced by:
  //    '<S50>/kd_xb'
  //    '<S410>/kd_xb'
  //    '<S464>/kd_xb'
  //    '<S167>/kd_xb'
  //    '<S204>/kd_xb'
  //    '<S225>/kd_xb'

  2.6,

  // Variable: Kd_xr
  //  Referenced by:
  //    '<S63>/kd_xr'
  //    '<S423>/kd_xr'
  //    '<S477>/kd_xr'
  //    '<S249>/kd_xr'
  //    '<S282>/kd_xr'
  //    '<S315>/kd_xr'

  2.6,

  // Variable: Kd_yb
  //  Referenced by:
  //    '<S38>/kd_yb'
  //    '<S398>/kd_yb'
  //    '<S452>/kd_yb'
  //    '<S97>/kd_yb'
  //    '<S114>/kd_yb'
  //    '<S131>/kd_yb'
  //    '<S147>/kd_yb'
  //    '<S188>/kd_yb'

  2.6,

  // Variable: Kd_yblue
  //  Referenced by:
  //    '<S51>/kd_yb'
  //    '<S411>/kd_yb'
  //    '<S465>/kd_yb'
  //    '<S168>/kd_yb'
  //    '<S205>/kd_yb'
  //    '<S226>/kd_yb'

  2.6,

  // Variable: Kd_yr
  //  Referenced by:
  //    '<S64>/kd_yr'
  //    '<S424>/kd_yr'
  //    '<S478>/kd_yr'
  //    '<S250>/kd_yr'
  //    '<S283>/kd_yr'
  //    '<S316>/kd_yr'

  2.6,

  // Variable: Kp_elarm
  //  Referenced by:
  //    '<S78>/kp_elarm'
  //    '<S438>/kp_elarm'
  //    '<S492>/kp_elarm'
  //    '<S268>/kp_elarm'
  //    '<S301>/kp_elarm'
  //    '<S334>/kp_elarm'
  //    '<S384>/kp_elarm'

  1.2,

  // Variable: Kp_sharm
  //  Referenced by:
  //    '<S79>/kp_sharm'
  //    '<S439>/kp_sharm'
  //    '<S493>/kp_sharm'
  //    '<S269>/kp_sharm'
  //    '<S302>/kp_sharm'
  //    '<S335>/kp_sharm'
  //    '<S385>/kp_sharm'

  1.5,

  // Variable: Kp_tb
  //  Referenced by:
  //    '<S36>/kp_tb'
  //    '<S396>/kp_tb'
  //    '<S450>/kp_tb'
  //    '<S95>/kp_tb'
  //    '<S112>/kp_tb'
  //    '<S129>/kp_tb'
  //    '<S145>/kp_tb'
  //    '<S186>/kp_tb'

  0.5,

  // Variable: Kp_tblue
  //  Referenced by:
  //    '<S49>/kp_tb'
  //    '<S409>/kp_tb'
  //    '<S463>/kp_tb'
  //    '<S166>/kp_tb'
  //    '<S203>/kp_tb'
  //    '<S224>/kp_tb'

  0.5,

  // Variable: Kp_tr
  //  Referenced by:
  //    '<S62>/kp_tr'
  //    '<S422>/kp_tr'
  //    '<S476>/kp_tr'
  //    '<S248>/kp_tr'
  //    '<S281>/kp_tr'
  //    '<S314>/kp_tr'

  0.5,

  // Variable: Kp_wrarm
  //  Referenced by:
  //    '<S80>/kp_wrarm'
  //    '<S440>/kp_wrarm'
  //    '<S494>/kp_wrarm'
  //    '<S270>/kp_wrarm'
  //    '<S303>/kp_wrarm'
  //    '<S336>/kp_wrarm'
  //    '<S386>/kp_wrarm'

  2.0,

  // Variable: Kp_xb
  //  Referenced by:
  //    '<S37>/kp_xb'
  //    '<S397>/kp_xb'
  //    '<S451>/kp_xb'
  //    '<S96>/kp_xb'
  //    '<S113>/kp_xb'
  //    '<S130>/kp_xb'
  //    '<S146>/kp_xb'
  //    '<S187>/kp_xb'

  1.0,

  // Variable: Kp_xblue
  //  Referenced by:
  //    '<S50>/kp_xb'
  //    '<S410>/kp_xb'
  //    '<S464>/kp_xb'
  //    '<S167>/kp_xb'
  //    '<S204>/kp_xb'
  //    '<S225>/kp_xb'

  1.0,

  // Variable: Kp_xr
  //  Referenced by:
  //    '<S63>/kp_xr'
  //    '<S423>/kp_xr'
  //    '<S477>/kp_xr'
  //    '<S249>/kp_xr'
  //    '<S282>/kp_xr'
  //    '<S315>/kp_xr'

  1.0,

  // Variable: Kp_yb
  //  Referenced by:
  //    '<S38>/kp_yb'
  //    '<S398>/kp_yb'
  //    '<S452>/kp_yb'
  //    '<S97>/kp_yb'
  //    '<S114>/kp_yb'
  //    '<S131>/kp_yb'
  //    '<S147>/kp_yb'
  //    '<S188>/kp_yb'

  1.0,

  // Variable: Kp_yblue
  //  Referenced by:
  //    '<S51>/kp_yb'
  //    '<S411>/kp_yb'
  //    '<S465>/kp_yb'
  //    '<S168>/kp_yb'
  //    '<S205>/kp_yb'
  //    '<S226>/kp_yb'

  1.0,

  // Variable: Kp_yr
  //  Referenced by:
  //    '<S64>/kp_yr'
  //    '<S424>/kp_yr'
  //    '<S478>/kp_yr'
  //    '<S250>/kp_yr'
  //    '<S283>/kp_yr'
  //    '<S316>/kp_yr'

  1.0,

  // Variable: Method
  //  Referenced by: '<S362>/Constant3'

  7.0,

  // Variable: Nmat
  //  Referenced by:
  //    '<S350>/MATLAB Function'
  //    '<S369>/MATLAB Function1'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  // Variable: PWMFreq
  //  Referenced by:
  //    '<S19>/PWM Frequency'
  //    '<S610>/MATLAB Function1'
  //    '<S622>/MATLAB Function2'
  //    '<S634>/MATLAB Function2'

  5.0,

  // Variable: P_IC
  //  Referenced by:
  //    '<S356>/IC'
  //    '<S356>/Delay'

  { 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.2 },

  // Variable: P_b
  //  Referenced by:
  //    '<S350>/MATLAB Function'
  //    '<S369>/MATLAB Function1'

  { 45.0, 0.0, 0.0, 0.0, 45.0, 0.0, 0.0, 0.0, 0.0 },

  // Variable: Phase0_End
  //  Referenced by: '<Root>/Constant4'

  10.0,

  // Variable: Phase1_End
  //  Referenced by: '<Root>/Constant'

  15.0,

  // Variable: Phase2_End
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

  25.0,

  // Variable: Phase3_End
  //  Referenced by: '<Root>/Constant2'

  145.0,

  // Variable: Phase3_SubPhase1_End
  //  Referenced by:
  //    '<S87>/Constant4'
  //    '<S88>/Constant4'
  //    '<S89>/Constant4'

  25.0,

  // Variable: Phase3_SubPhase2_End
  //  Referenced by:
  //    '<S87>/Constant1'
  //    '<S88>/Constant1'
  //    '<S89>/Constant1'

  25.0,

  // Variable: Phase3_SubPhase3_End
  //  Referenced by:
  //    '<S87>/Constant2'
  //    '<S88>/Constant2'
  //    '<S89>/Constant2'

  25.0,

  // Variable: Phase3_SubPhase4_End
  //  Referenced by:
  //    '<S87>/Constant3'
  //    '<S88>/Constant3'
  //    '<S89>/Constant3'

  145.0,

  // Variable: Phase4_End
  //  Referenced by: '<Root>/Constant3'

  145.0,

  // Variable: Phase5_End
  //  Referenced by: '<Root>/Constant6'

  145.0,

  // Variable: Phi
  //  Referenced by:
  //    '<S634>/MATLAB Function'
  //    '<S634>/MATLAB Function4'
  //    '<S634>/MATLAB Function6'
  //    '<S582>/Coriolis Function1'
  //    '<S582>/Inertia Function 1'

  1.2788882640695929,

  // Variable: Q
  //  Referenced by: '<S356>/MATLAB Function'

  { 1.00034654284122E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.00034654284122E-6, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    3.63628392455557E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.63628392455557E-6, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.00184501303471272 },

  // Variable: Q_a
  //  Referenced by:
  //    '<S350>/MATLAB Function'
  //    '<S369>/MATLAB Function1'

  { 5.0, 0.0, 0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0 },

  // Variable: Q_b
  //  Referenced by:
  //    '<S350>/MATLAB Function'
  //    '<S369>/MATLAB Function1'

  { 0.0125, 0.0, 0.0, 0.0, 0.0125, 0.0, 0.0, 0.0, 0.05 },

  // Variable: R
  //  Referenced by: '<S356>/MATLAB Function'

  { 5.27091972607854E-5, 0.0, 0.0, 0.0, 5.27091972607854E-5, 0.0, 0.0, 0.0,
    0.000199668122223857 },

  // Variable: RMSprop_epsilon
  //  Referenced by: '<S370>/MATLAB Function1'

  1.0E-8,

  // Variable: RMSprop_eta
  //  Referenced by: '<S370>/MATLAB Function1'

  0.025,

  // Variable: RMSprop_gamma
  //  Referenced by: '<S370>/MATLAB Function1'

  0.9,

  // Variable: Tz_lim_elarm
  //  Referenced by:
  //    '<S77>/Saturation1'
  //    '<S437>/Saturation1'
  //    '<S491>/Saturation1'
  //    '<S267>/Saturation1'
  //    '<S300>/Saturation1'
  //    '<S333>/Saturation1'
  //    '<S383>/Saturation1'

  0.1,

  // Variable: Tz_lim_sharm
  //  Referenced by:
  //    '<S77>/Saturation'
  //    '<S437>/Saturation'
  //    '<S491>/Saturation'
  //    '<S267>/Saturation'
  //    '<S300>/Saturation'
  //    '<S333>/Saturation'
  //    '<S383>/Saturation'

  0.1,

  // Variable: Tz_lim_wrarm
  //  Referenced by:
  //    '<S77>/Saturation3'
  //    '<S437>/Saturation3'
  //    '<S491>/Saturation3'
  //    '<S267>/Saturation3'
  //    '<S300>/Saturation3'
  //    '<S333>/Saturation3'
  //    '<S383>/Saturation3'

  0.1,

  // Variable: a1
  //  Referenced by:
  //    '<S634>/MATLAB Function'
  //    '<S634>/MATLAB Function4'
  //    '<S634>/MATLAB Function6'
  //    '<S582>/Coriolis Function1'
  //    '<S582>/Inertia Function 1'

  0.3,

  // Variable: a2
  //  Referenced by:
  //    '<S634>/MATLAB Function'
  //    '<S634>/MATLAB Function4'
  //    '<S634>/MATLAB Function6'
  //    '<S582>/Coriolis Function1'
  //    '<S582>/Inertia Function 1'

  0.3,

  // Variable: a3
  //  Referenced by:
  //    '<S634>/MATLAB Function'
  //    '<S634>/MATLAB Function4'
  //    '<S634>/MATLAB Function6'
  //    '<S582>/Coriolis Function1'
  //    '<S582>/Inertia Function 1'

  0.4,

  // Variable: adadelta_epsilon
  //  Referenced by: '<S363>/MATLAB Function1'

  1.0E-5,

  // Variable: adadelta_gamma
  //  Referenced by: '<S363>/MATLAB Function1'

  0.37,

  // Variable: adagrad_epsilon
  //  Referenced by: '<S364>/MATLAB Function1'

  1.0E-8,

  // Variable: adagrad_eta
  //  Referenced by: '<S364>/MATLAB Function1'

  0.18,

  // Variable: adam_beta_1
  //  Referenced by: '<S366>/MATLAB Function1'

  0.99,

  // Variable: adam_beta_2
  //  Referenced by: '<S366>/MATLAB Function1'

  0.999,

  // Variable: adam_epsilon
  //  Referenced by: '<S366>/MATLAB Function1'

  0.01,

  // Variable: adam_eta
  //  Referenced by: '<S366>/MATLAB Function1'

  0.0163,

  // Variable: adamax_beta_1
  //  Referenced by: '<S365>/MATLAB Function1'

  0.1,

  // Variable: adamax_beta_2
  //  Referenced by: '<S365>/MATLAB Function1'

  0.1,

  // Variable: adamax_eta
  //  Referenced by: '<S365>/MATLAB Function1'

  0.025,

  // Variable: alpha
  //  Referenced by: '<S356>/MATLAB Function'

  1.0E-6,

  // Variable: b0
  //  Referenced by:
  //    '<S634>/MATLAB Function'
  //    '<S634>/MATLAB Function4'
  //    '<S634>/MATLAB Function6'
  //    '<S582>/Coriolis Function1'
  //    '<S582>/Inertia Function 1'

  0.25,

  // Variable: b1
  //  Referenced by:
  //    '<S634>/MATLAB Function'
  //    '<S634>/MATLAB Function4'
  //    '<S634>/MATLAB Function6'
  //    '<S582>/Coriolis Function1'
  //    '<S582>/Inertia Function 1'

  0.175,

  // Variable: b2
  //  Referenced by:
  //    '<S634>/MATLAB Function'
  //    '<S634>/MATLAB Function4'
  //    '<S634>/MATLAB Function6'
  //    '<S582>/Coriolis Function1'
  //    '<S582>/Inertia Function 1'

  0.175,

  // Variable: b3
  //  Referenced by:
  //    '<S634>/MATLAB Function'
  //    '<S634>/MATLAB Function4'
  //    '<S634>/MATLAB Function6'
  //    '<S582>/Inertia Function 1'

  0.025153,

  // Variable: baseRate
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

  0.01,

  // Variable: batch_eta
  //  Referenced by: '<S367>/Batch'

  0.25,

  // Variable: beta
  //  Referenced by: '<S356>/MATLAB Function'

  0.162242557505519,

  // Variable: delta
  //  Referenced by: '<S347>/Ryan's Transform'

  2.0,

  // Variable: drop_states_BLACK
  //  Referenced by: '<S552>/Velocity to Position'

  { 1.3, 1.25, 4.71238898038469 },

  // Variable: drop_states_BLUE
  //  Referenced by: '<S566>/Velocity to Position'

  { 2.0, 1.4, 3.2812189937493397 },

  // Variable: drop_states_RED
  //  Referenced by: '<S593>/Velocity to Position'

  { 2.7, 0.4, 8.639379797371932 },

  // Variable: dt
  //  Referenced by: '<S356>/MATLAB Function'

  0.01,

  // Variable: end_time_black
  //  Referenced by:
  //    '<S149>/End Time'
  //    '<S150>/End Time'
  //    '<S151>/End Time'
  //    '<S190>/End Time'
  //    '<S191>/End Time'
  //    '<S192>/End Time'

  205.0,

  // Variable: home_states_BLACK
  //  Referenced by:
  //    '<S393>/Desired Attitude (BLACK)'
  //    '<S393>/Desired Px (BLACK)'
  //    '<S393>/Desired Py (BLACK)'
  //    '<S447>/Desired Attitude (BLACK)'
  //    '<S447>/Desired Px (BLACK)'
  //    '<S447>/Desired Py (BLACK)'

  { 1.3, 1.25, 4.71238898038469 },

  // Variable: home_states_BLUE
  //  Referenced by:
  //    '<S394>/Desired Attitude (BLUE)'
  //    '<S394>/Desired Px (BLUE)'
  //    '<S394>/Desired Py (BLUE)'
  //    '<S448>/Desired Attitude (BLUE)'
  //    '<S448>/Desired Px (BLUE)'
  //    '<S448>/Desired Py (BLUE)'

  { 2.0, 1.4, 3.2812189937493397 },

  // Variable: home_states_RED
  //  Referenced by:
  //    '<S395>/Desired Px (RED)'
  //    '<S395>/Desired Py (RED)'
  //    '<S395>/Desired Rz (RED)'
  //    '<S449>/Desired Px (RED)'
  //    '<S449>/Desired Py (RED)'
  //    '<S449>/Desired Rz (RED)'

  { 2.7, 0.4, 8.639379797371932 },

  // Variable: init_states_BLACK
  //  Referenced by:
  //    '<S33>/Desired Attitude (BLACK)'
  //    '<S33>/Desired Px (BLACK)'
  //    '<S33>/Desired Py (BLACK)'

  { 1.3, 1.25, 4.71238898038469 },

  // Variable: init_states_BLUE
  //  Referenced by:
  //    '<S34>/Desired Attitude (BLUE)'
  //    '<S34>/Desired Px (BLUE)'
  //    '<S34>/Desired Py (BLUE)'

  { 2.0, 1.4, 3.2812189937493397 },

  // Variable: init_states_RED
  //  Referenced by:
  //    '<S35>/Constant'
  //    '<S35>/Constant1'
  //    '<S35>/Constant3'

  { 2.7, 0.4, 8.639379797371932 },

  // Variable: k_1_0
  //  Referenced by:
  //    '<S349>/Discrete-Time Integrator3'
  //    '<S349>/Discrete-Time Integrator5'

  3.5,

  // Variable: k_1_t_0
  //  Referenced by: '<S349>/Discrete-Time Integrator1'

  1.0,

  // Variable: k_2_0
  //  Referenced by:
  //    '<S349>/Discrete-Time Integrator2'
  //    '<S349>/Discrete-Time Integrator4'

  28.0,

  // Variable: k_2_t_0
  //  Referenced by: '<S349>/Discrete-Time Integrator'

  1.0,

  // Variable: ka
  //  Referenced by:
  //    '<S350>/MATLAB Function'
  //    '<S369>/MATLAB Function1'

  1.0,

  // Variable: kr
  //  Referenced by:
  //    '<S350>/MATLAB Function'
  //    '<S369>/MATLAB Function1'

  2.0,

  // Variable: lambda1
  //  Referenced by:
  //    '<S349>/Fx Gain Derivatives'
  //    '<S349>/Fy Gain Derivatives'

  0.4,

  // Variable: lambda12
  //  Referenced by:
  //    '<S349>/Fx Gain Derivatives'
  //    '<S349>/Fy Gain Derivatives'

  0.4,

  // Variable: lambda12_t
  //  Referenced by: '<S349>/Torque Gain Derivatives'

  0.05,

  // Variable: lambda1_t
  //  Referenced by: '<S349>/Torque Gain Derivatives'

  0.05,

  // Variable: lambda2
  //  Referenced by:
  //    '<S349>/Fx Gain Derivatives'
  //    '<S349>/Fy Gain Derivatives'

  0.4,

  // Variable: lambda2_t
  //  Referenced by: '<S349>/Torque Gain Derivatives'

  0.05,

  // Variable: lamda
  //  Referenced by: '<S356>/MATLAB Function'

  -5.9999999999938662,

  // Variable: m
  //  Referenced by: '<S356>/MATLAB Function'

  11.296999999999999,

  // Variable: mBLACK
  //  Referenced by: '<S552>/MATLAB Function'

  11.362,

  // Variable: mBLUE
  //  Referenced by: '<S566>/MATLAB Function'

  10.826,

  // Variable: mDIST
  //  Referenced by:
  //    '<S634>/MATLAB Function'
  //    '<S634>/MATLAB Function4'
  //    '<S634>/MATLAB Function6'
  //    '<S582>/Coriolis Function1'
  //    '<S582>/Inertia Function 1'

  0.335,

  // Variable: mEE
  //  Referenced by:
  //    '<S634>/MATLAB Function'
  //    '<S634>/MATLAB Function4'
  //    '<S634>/MATLAB Function6'
  //    '<S582>/Coriolis Function1'
  //    '<S582>/Inertia Function 1'

  0.111,

  // Variable: mPROX
  //  Referenced by:
  //    '<S634>/MATLAB Function'
  //    '<S634>/MATLAB Function4'
  //    '<S634>/MATLAB Function6'
  //    '<S582>/Coriolis Function1'
  //    '<S582>/Inertia Function 1'

  0.345,

  // Variable: mRED
  //  Referenced by:
  //    '<S634>/MATLAB Function'
  //    '<S634>/MATLAB Function4'
  //    '<S634>/MATLAB Function6'
  //    '<S582>/Inertia Function 1'
  //    '<S593>/MATLAB Function'

  11.296999999999999,

  // Variable: momentum_eta
  //  Referenced by: '<S368>/Momentum'

  0.7,

  // Variable: momentum_gamma
  //  Referenced by: '<S368>/Momentum'

  0.7,

  // Variable: nesterov_eta
  //  Referenced by: '<S369>/MATLAB Function1'

  0.6,

  // Variable: nesterov_gamma
  //  Referenced by: '<S369>/MATLAB Function1'

  0.3,

  // Variable: noise_variance_BLACK
  //  Referenced by: '<S552>/Random Number'

  0.0,

  // Variable: noise_variance_BLUE
  //  Referenced by: '<S566>/Random Number'

  0.0,

  // Variable: noise_variance_RED
  //  Referenced by: '<S593>/Random Number'

  0.0,

  // Variable: p
  //  Referenced by:
  //    '<S349>/Fx Gain Derivatives'
  //    '<S349>/Fy Gain Derivatives'

  0.4,

  // Variable: p_t
  //  Referenced by: '<S349>/Torque Gain Derivatives'

  0.05,

  // Variable: platformSelection
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

  7.0,

  // Variable: psi
  //  Referenced by:
  //    '<S350>/MATLAB Function'
  //    '<S369>/MATLAB Function1'

  0.0,

  // Variable: r_hold
  //  Referenced by:
  //    '<S350>/MATLAB Function'
  //    '<S369>/MATLAB Function1'

  0.427,

  // Variable: r_off
  //  Referenced by:
  //    '<S247>/Looking Angle'
  //    '<S350>/MATLAB Function'
  //    '<S369>/MATLAB Function1'

  0.165,

  // Variable: shape
  //  Referenced by:
  //    '<S350>/MATLAB Function'
  //    '<S369>/MATLAB Function1'

  { 0.3, 0.3, 0.4, 0.175, 0.175 },

  // Variable: sigma
  //  Referenced by:
  //    '<S350>/MATLAB Function'
  //    '<S369>/MATLAB Function1'

  0.15,

  // Variable: simMode
  //  Referenced by: '<S18>/Constant'

  0.0,

  // Variable: thresh
  //  Referenced by: '<S356>/MATLAB Function'

  9.0,

  // Variable: thruster_count_threshold
  //  Referenced by:
  //    '<S610>/MATLAB Function10'
  //    '<S622>/MATLAB Function6'
  //    '<S634>/MATLAB Function5'

  0.0,

  // Variable: thruster_dist2CG_BLACK
  //  Referenced by:
  //    '<S610>/MATLAB Function'
  //    '<S610>/MATLAB Function11'
  //    '<S610>/MATLAB Function3'

  { 87.2054215807076, -50.794578419292378, 67.834888223904244,
    -73.665111776095742, 50.794578419292378, -79.6054215807076,
    68.165111776095742, -60.834888223904244 },

  // Variable: thruster_dist2CG_BLUE
  //  Referenced by:
  //    '<S622>/MATLAB Function'
  //    '<S622>/MATLAB Function1'
  //    '<S622>/MATLAB Function7'

  { 84.3010033444816, -53.698996655518386, 79.980637211758491,
    -61.519362788241494, 53.698996655518386, -76.7010033444816,
    56.019362788241487, -72.9806372117585 },

  // Variable: thruster_dist2CG_RED
  //  Referenced by:
  //    '<S634>/MATLAB Function'
  //    '<S634>/MATLAB Function11'
  //    '<S634>/MATLAB Function3'
  //    '<S634>/MATLAB Function4'
  //    '<S634>/MATLAB Function6'
  //    '<S634>/MATLAB Function7'

  { 86.629636186598191, -39.370363813401788, 66.664291404797723,
    -64.835708595202249, 43.870363813401781, -85.629636186598219,
    62.335708595202249, -68.664291404797723 },

  // Variable: xLength
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

  3.51155,

  // Variable: x_in
  //  Referenced by:
  //    '<S356>/IC1'
  //    '<S356>/Delay1'

  { 1.3, 1.25, 4.71238898038469, 0.0, 0.0, -0.026179938779914945 },

  // Variable: yLength
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

  2.41935,

  // Expression: 428
  //  Referenced by: '<S25>/Set Pin 428 (Pucks) to HIGH'

  428.0,

  // Expression: 1
  //  Referenced by: '<S25>/Set Pin 428 (Pucks) to HIGH'

  1.0,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S560>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_a
  //  Referenced by: '<S561>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_g
  //  Referenced by: '<S562>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_gc
  //  Referenced by: '<S563>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_e
  //  Referenced by: '<S564>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_n
  //  Referenced by: '<S565>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_o
  //  Referenced by: '<S574>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_ow
  //  Referenced by: '<S575>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_as
  //  Referenced by: '<S576>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_ox
  //  Referenced by: '<S577>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_e3
  //  Referenced by: '<S578>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_i
  //  Referenced by: '<S579>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_b
  //  Referenced by: '<S589>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_asw
  //  Referenced by: '<S590>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_ea
  //  Referenced by: '<S591>/Out1'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S582>/Delay'

  0.0,

  // Computed Parameter: AccelerationtoVelocity_gainval
  //  Referenced by: '<S582>/Acceleration  to Velocity'

  0.01,

  // Expression: [drop_states_RED,drop_states_ARM,0,0,0,0,0,0]
  //  Referenced by: '<S582>/Acceleration  to Velocity'

  { 2.7, 0.4, 8.639379797371932, 1.5707963267948966, 1.5707963267948966, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S582>/Random Number2'

  0.0,

  // Computed Parameter: RandomNumber2_StdDev
  //  Referenced by: '<S582>/Random Number2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S582>/Random Number2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S582>/Random Number1'

  0.0,

  // Computed Parameter: RandomNumber1_StdDev
  //  Referenced by: '<S582>/Random Number1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S582>/Random Number1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S582>/Random Number3'

  0.0,

  // Computed Parameter: RandomNumber3_StdDev
  //  Referenced by: '<S582>/Random Number3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S582>/Random Number3'

  0.0,

  // Computed Parameter: Out1_Y0_j
  //  Referenced by: '<S601>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_l
  //  Referenced by: '<S602>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S603>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_bf
  //  Referenced by: '<S604>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_gt
  //  Referenced by: '<S605>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_em
  //  Referenced by: '<S606>/Out1'

  0.0,

  // Computed Parameter: AccelerationtoVelocity_gainva_g
  //  Referenced by: '<S593>/Acceleration  to Velocity'

  0.01,

  // Expression: 0
  //  Referenced by: '<S593>/Acceleration  to Velocity'

  0.0,

  // Computed Parameter: VelocitytoPosition_gainval
  //  Referenced by: '<S593>/Velocity to Position'

  0.01,

  // Expression: 0
  //  Referenced by: '<S593>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S593>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S592>/Random Number7'

  0.0,

  // Computed Parameter: RandomNumber7_StdDev
  //  Referenced by: '<S592>/Random Number7'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S592>/Random Number7'

  0.0,

  // Expression: 0
  //  Referenced by: '<S592>/Random Number6'

  0.0,

  // Computed Parameter: RandomNumber6_StdDev
  //  Referenced by: '<S592>/Random Number6'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S592>/Random Number6'

  0.0,

  // Expression: 0
  //  Referenced by: '<S592>/Random Number8'

  0.0,

  // Computed Parameter: RandomNumber8_StdDev
  //  Referenced by: '<S592>/Random Number8'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S592>/Random Number8'

  0.0,

  // Computed Parameter: AccelerationtoVelocity_gainva_j
  //  Referenced by: '<S552>/Acceleration  to Velocity'

  0.01,

  // Expression: 0
  //  Referenced by: '<S552>/Acceleration  to Velocity'

  0.0,

  // Computed Parameter: VelocitytoPosition_gainval_n
  //  Referenced by: '<S552>/Velocity to Position'

  0.01,

  // Expression: 0
  //  Referenced by: '<S552>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S552>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S549>/Random Number1'

  0.0,

  // Computed Parameter: RandomNumber1_StdDev_e
  //  Referenced by: '<S549>/Random Number1'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S549>/Random Number1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S549>/Random Number'

  0.0,

  // Computed Parameter: RandomNumber_StdDev
  //  Referenced by: '<S549>/Random Number'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S549>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S549>/Random Number2'

  0.0,

  // Computed Parameter: RandomNumber2_StdDev_c
  //  Referenced by: '<S549>/Random Number2'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S549>/Random Number2'

  0.0,

  // Computed Parameter: AccelerationtoVelocity_gainva_p
  //  Referenced by: '<S566>/Acceleration  to Velocity'

  0.01,

  // Expression: 0
  //  Referenced by: '<S566>/Acceleration  to Velocity'

  0.0,

  // Computed Parameter: VelocitytoPosition_gainval_e
  //  Referenced by: '<S566>/Velocity to Position'

  0.01,

  // Expression: 0
  //  Referenced by: '<S566>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S566>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S550>/Random Number4'

  0.0,

  // Computed Parameter: RandomNumber4_StdDev
  //  Referenced by: '<S550>/Random Number4'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S550>/Random Number4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S550>/Random Number3'

  0.0,

  // Computed Parameter: RandomNumber3_StdDev_n
  //  Referenced by: '<S550>/Random Number3'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S550>/Random Number3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S550>/Random Number5'

  0.0,

  // Computed Parameter: RandomNumber5_StdDev
  //  Referenced by: '<S550>/Random Number5'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S550>/Random Number5'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S26>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S26>/Delay1'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S26>/Delay2'

  0.0,

  // Computed Parameter: Out1_Y0_m
  //  Referenced by: '<S526>/Out1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S526>/Memory'

  0.0,

  // Computed Parameter: Out1_Y0_ei
  //  Referenced by: '<S527>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_lf
  //  Referenced by: '<S528>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_f
  //  Referenced by: '<S529>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_m3
  //  Referenced by: '<S530>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_m34
  //  Referenced by: '<S531>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_h
  //  Referenced by: '<S532>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_o3
  //  Referenced by: '<S533>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S534>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_hp
  //  Referenced by: '<S535>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_p0
  //  Referenced by: '<S536>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_iy
  //  Referenced by: '<S537>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_c
  //  Referenced by: '<S538>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_d0
  //  Referenced by: '<S539>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_ck
  //  Referenced by: '<S540>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_ii
  //  Referenced by: '<S541>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_l2
  //  Referenced by: '<S542>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_nz
  //  Referenced by: '<S543>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_fr
  //  Referenced by: '<S544>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_e1
  //  Referenced by: '<S545>/Out1'

  0.0,

  // Expression: 1/1000
  //  Referenced by: '<S505>/Convert REDX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S505>/Convert BLUX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S505>/Convert BLAX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S505>/Convert BLAY from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S505>/Convert BLUY from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S505>/Convert REDY from [mm] to [m]'

  0.001,

  // Expression: 1
  //  Referenced by: '<S506>/Constant'

  1.0,

  // Expression: 400
  //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  400.0,

  // Expression: 0
  //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  0.0,

  // Expression: 200
  //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  200.0,

  // Expression: 3072
  //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  3072.0,

  // Expression: 1024
  //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  1024.0,

  // Expression: 0
  //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  0.0,

  // Expression: 850
  //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  850.0,

  // Expression: 400
  //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  400.0,

  // Expression: 100
  //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  100.0,

  // Expression: 50
  //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  50.0,

  // Expression: 0
  //  Referenced by: '<S547>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  0.0,

  // Computed Parameter: Out1_Y0_nj
  //  Referenced by: '<S54>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_bq
  //  Referenced by: '<S56>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_c1
  //  Referenced by: '<S58>/Out1'

  0.0,

  // Expression: 1
  //  Referenced by: '<S34>/Puck State'

  1.0,

  // Computed Parameter: Out1_Y0_gf
  //  Referenced by: '<S41>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_nx
  //  Referenced by: '<S43>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_g4
  //  Referenced by: '<S45>/Out1'

  0.0,

  // Expression: 1
  //  Referenced by: '<S33>/Puck State'

  1.0,

  // Computed Parameter: Out1_Y0_hs
  //  Referenced by: '<S68>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_cr
  //  Referenced by: '<S70>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_dg
  //  Referenced by: '<S72>/Out1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S35>/Constant2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S35>/Puck State'

  1.0,

  // Computed Parameter: Out1_Y0_am
  //  Referenced by: '<S153>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_bh
  //  Referenced by: '<S155>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_jy
  //  Referenced by: '<S157>/Out1'

  0.0,

  // Computed Parameter: StartPos_gainval
  //  Referenced by: '<S149>/Start Pos'

  0.01,

  // Expression: 1
  //  Referenced by: '<S149>/End Time'

  1.0,

  // Expression: 0
  //  Referenced by: '<S149>/End Time'

  0.0,

  // Expression: 0
  //  Referenced by: '<S149>/Switch'

  0.0,

  // Computed Parameter: StartPos_gainval_k
  //  Referenced by: '<S150>/Start Pos'

  0.01,

  // Expression: 1
  //  Referenced by: '<S150>/End Time'

  1.0,

  // Expression: 0
  //  Referenced by: '<S150>/End Time'

  0.0,

  // Expression: 0
  //  Referenced by: '<S150>/Switch'

  0.0,

  // Computed Parameter: StartPos_gainval_l
  //  Referenced by: '<S151>/Start Pos'

  0.01,

  // Expression: 1
  //  Referenced by: '<S151>/End Time'

  1.0,

  // Expression: 0
  //  Referenced by: '<S151>/End Time'

  0.0,

  // Expression: 0
  //  Referenced by: '<S151>/Switch'

  0.0,

  // Expression: 1
  //  Referenced by: '<S93>/Puck State'

  1.0,

  // Computed Parameter: Out1_Y0_dc
  //  Referenced by: '<S194>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_ap
  //  Referenced by: '<S196>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_jf
  //  Referenced by: '<S198>/Out1'

  0.0,

  // Computed Parameter: StartPos_gainval_a
  //  Referenced by: '<S190>/Start Pos'

  0.01,

  // Expression: 1
  //  Referenced by: '<S190>/End Time'

  1.0,

  // Expression: 0
  //  Referenced by: '<S190>/End Time'

  0.0,

  // Expression: 0
  //  Referenced by: '<S190>/Switch'

  0.0,

  // Computed Parameter: StartPos_gainval_al
  //  Referenced by: '<S191>/Start Pos'

  0.01,

  // Expression: 1
  //  Referenced by: '<S191>/End Time'

  1.0,

  // Expression: 0
  //  Referenced by: '<S191>/End Time'

  0.0,

  // Expression: 0
  //  Referenced by: '<S191>/Switch'

  0.0,

  // Computed Parameter: StartPos_gainval_j
  //  Referenced by: '<S192>/Start Pos'

  0.01,

  // Expression: 1
  //  Referenced by: '<S192>/End Time'

  1.0,

  // Expression: 0
  //  Referenced by: '<S192>/End Time'

  0.0,

  // Expression: 0
  //  Referenced by: '<S192>/Switch'

  0.0,

  // Expression: 1
  //  Referenced by: '<S162>/Puck State'

  1.0,

  // Computed Parameter: Out1_Y0_ig
  //  Referenced by: '<S324>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_fb
  //  Referenced by: '<S326>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_bj
  //  Referenced by: '<S328>/Out1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S246>/Constant4'

  0.0,

  // Expression: 0.03490659
  //  Referenced by: '<S321>/Desired Rate '

  0.03490659,

  // Expression: pi
  //  Referenced by: '<S321>/Constant'

  3.1415926535897931,

  // Expression: 1
  //  Referenced by: '<S246>/Puck State'

  1.0,

  // Expression: pi/2
  //  Referenced by: '<S354>/Constant4'

  1.5707963267948966,

  // Expression: pi/3
  //  Referenced by: '<S354>/Constant5'

  1.0471975511965976,

  // Expression: 0
  //  Referenced by: '<S354>/Constant6'

  0.0,

  // Expression: 1
  //  Referenced by: '<S354>/Constant7'

  1.0,

  // Expression: [0,0,0]
  //  Referenced by: '<S356>/Force'

  { 0.0, 0.0, 0.0 },

  // Expression: 0.0
  //  Referenced by: '<S368>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S369>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S364>/Delay3'

  0.0,

  // Expression: [0;0;0]
  //  Referenced by: '<S363>/Delay'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<S363>/Delay1'

  { 0.0, 0.0, 0.0 },

  // Expression: 0.0
  //  Referenced by: '<S370>/Delay3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S366>/Delay3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S366>/Delay1'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S365>/Delay3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S365>/Delay1'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator4_gainval
  //  Referenced by: '<S349>/Discrete-Time Integrator4'

  0.01,

  // Computed Parameter: DiscreteTimeIntegrator5_gainval
  //  Referenced by: '<S349>/Discrete-Time Integrator5'

  0.01,

  // Computed Parameter: DiscreteTimeIntegrator2_gainval
  //  Referenced by: '<S349>/Discrete-Time Integrator2'

  0.01,

  // Computed Parameter: DiscreteTimeIntegrator3_gainval
  //  Referenced by: '<S349>/Discrete-Time Integrator3'

  0.01,

  // Expression: 0
  //  Referenced by: '<S247>/Switch'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator1_gainval
  //  Referenced by: '<S349>/Discrete-Time Integrator1'

  0.01,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S349>/Discrete-Time Integrator'

  0.01,

  // Expression: [0;0;0]
  //  Referenced by: '<S368>/Constant'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<S369>/Constant1'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S247>/Constant1'

  0.0,

  // Expression: 1
  //  Referenced by: '<S247>/Puck State'

  1.0,

  // Expression: 0
  //  Referenced by: '<S501>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S501>/Constant4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S501>/Constant5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S501>/Puck State'

  0.0,

  // Expression: 0
  //  Referenced by: '<S503>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S503>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S503>/Constant2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S503>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S503>/Puck State'

  0.0,

  // Expression: -1
  //  Referenced by: '<S503>/Gain'

  -1.0,

  // Expression: 0.005
  //  Referenced by: '<S503>/Saturation'

  0.005,

  // Expression: -0.005
  //  Referenced by: '<S503>/Saturation'

  -0.005,

  // Computed Parameter: BLACKPWM_Y0
  //  Referenced by: '<S607>/BLACK PWM'

  0.0,

  // Expression: 1000
  //  Referenced by: '<S610>/Remove Negatives'

  1000.0,

  // Expression: 0
  //  Referenced by: '<S610>/Remove Negatives'

  0.0,

  // Computed Parameter: BLUEPWM_Y0
  //  Referenced by: '<S608>/BLUE PWM'

  0.0,

  // Expression: 1000
  //  Referenced by: '<S622>/Remove Negatives'

  1000.0,

  // Expression: 0
  //  Referenced by: '<S622>/Remove Negatives'

  0.0,

  // Computed Parameter: REDPWM_Y0
  //  Referenced by: '<S609>/RED PWM'

  0.0,

  // Expression: 1000
  //  Referenced by: '<S634>/Remove Negatives'

  1000.0,

  // Expression: 0
  //  Referenced by: '<S634>/Remove Negatives'

  0.0,

  // Expression: 568471
  //  Referenced by: '<S19>/Safety Number'

  568471.0,

  // Expression: 100
  //  Referenced by: '<S19>/Gain'

  100.0,

  // Expression: 100
  //  Referenced by: '<S19>/Gain1'

  100.0,

  // Expression: 100
  //  Referenced by: '<S19>/Gain2'

  100.0,

  // Expression: 100
  //  Referenced by: '<S19>/Gain3'

  100.0,

  // Expression: 100
  //  Referenced by: '<S19>/Gain4'

  100.0,

  // Expression: 100
  //  Referenced by: '<S19>/Gain5'

  100.0,

  // Expression: 100
  //  Referenced by: '<S19>/Gain6'

  100.0,

  // Expression: 100
  //  Referenced by: '<S19>/Gain7'

  100.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Fx'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Fx1'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Fx_Sat'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Fx_Sat2'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Fy'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Fy1'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Fy_Sat'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Fy_Sat2'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Px'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Px1'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Px2'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Px3'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Py'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Py1'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Py2'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Py3'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Rz'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Rz1'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Rz2'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Rz3'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Tz'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Tz1'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Tz_Sat'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Tz_Sat2'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Fx1'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Fx_Sat'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Fy'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Fy_Sat'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Px'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Py'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Rz'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz12'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz13'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz14'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz15'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz16'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz17'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz4'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz5'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz6'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz7'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz_RW'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz_RW Sat'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz_Sat'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_dRz_RW Sat'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_dRz_RW Sat1'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_dRz_RW Sat10'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_dRz_RW Sat11'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_dRz_RW Sat12'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_dRz_RW Sat2'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_dRz_RW Sat3'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_dRz_RW Sat4'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_dRz_RW Sat5'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_dRz_RW Sat6'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_dRz_RW Sat7'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_dRz_RW Sat8'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_dRz_RW Sat9'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time1'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time10'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time11'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time12'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time13'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time14'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time15'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time16'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time17'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time18'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time19'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time2'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time20'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time21'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time22'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time23'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time24'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time3'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time4'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time5'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time6'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time7'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time8'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time9'

  0.0,

  // Computed Parameter: Constant1_Value_i
  //  Referenced by: '<S22>/Constant1'

  1,

  // Computed Parameter: UDPSend_Port
  //  Referenced by: '<S22>/UDP Send'

  33001,

  // Computed Parameter: UDPReceive1_Port
  //  Referenced by: '<S505>/UDP Receive1'

  31534,

  // Computed Parameter: Delay_InitialCondition_g
  //  Referenced by: '<S505>/Delay'

  0,

  // Computed Parameter: Delay1_InitialCondition_h
  //  Referenced by: '<S505>/Delay1'

  0,

  // Computed Parameter: Delay2_InitialCondition_j
  //  Referenced by: '<S505>/Delay2'

  0,

  // Computed Parameter: UDPReceive_Port
  //  Referenced by: '<S505>/UDP Receive'

  33001,

  // Computed Parameter: UDPReceive2_Port
  //  Referenced by: '<S505>/UDP Receive2'

  33002,

  // Computed Parameter: UDPReceive3_Port
  //  Referenced by: '<S505>/UDP Receive3'

  33003,

  // Computed Parameter: UDPSend_Port_d
  //  Referenced by: '<S548>/UDP Send'

  46875,

  // Computed Parameter: UDPReceive1_Port_f
  //  Referenced by: '<S2>/UDP Receive1'

  30172,

  // Computed Parameter: UDPSend_Port_d5
  //  Referenced by: '<S19>/UDP Send'

  48291,

  // Start of '<S12>/Change BLUE Behavior'
  {
    // Expression: 0
    //  Referenced by: '<S502>/Constant3'

    0.0,

    // Expression: 0
    //  Referenced by: '<S502>/Constant4'

    0.0,

    // Expression: 0
    //  Referenced by: '<S502>/Constant5'

    0.0,

    // Expression: 0
    //  Referenced by: '<S502>/Puck State'

    0.0
  }
  ,

  // End of '<S12>/Change BLUE Behavior'

  // Start of '<Root>/Phase #5: Hold Home'
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S455>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_k
    //  Referenced by: '<S457>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_d
    //  Referenced by: '<S459>/Out1'

    0.0,

    // Expression: 1
    //  Referenced by: '<S447>/Puck State'

    1.0,

    // Computed Parameter: Out1_Y0_b
    //  Referenced by: '<S468>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_dv
    //  Referenced by: '<S470>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_p
    //  Referenced by: '<S472>/Out1'

    0.0,

    // Expression: 1
    //  Referenced by: '<S448>/Puck State'

    1.0,

    // Computed Parameter: Out1_Y0_b3
    //  Referenced by: '<S482>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_b1
    //  Referenced by: '<S484>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_ba
    //  Referenced by: '<S486>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_c
    //  Referenced by: '<S496>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_o
    //  Referenced by: '<S498>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_a
    //  Referenced by: '<S500>/Out1'

    0.0,

    // Expression: pi/2
    //  Referenced by: '<S480>/Constant1'

    1.5707963267948966,

    // Expression: 0
    //  Referenced by: '<S480>/Constant6'

    0.0,

    // Expression: 1
    //  Referenced by: '<S480>/Constant7'

    1.0,

    // Expression: 0
    //  Referenced by: '<S449>/Constant2'

    0.0,

    // Expression: 1
    //  Referenced by: '<S449>/Puck State'

    1.0
  }
  ,

  // End of '<Root>/Phase #5: Hold Home'

  // Start of '<Root>/Phase #4: Return Home'
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S401>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_k
    //  Referenced by: '<S403>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_d
    //  Referenced by: '<S405>/Out1'

    0.0,

    // Expression: 1
    //  Referenced by: '<S393>/Puck State'

    1.0,

    // Computed Parameter: Out1_Y0_b
    //  Referenced by: '<S414>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_dv
    //  Referenced by: '<S416>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_p
    //  Referenced by: '<S418>/Out1'

    0.0,

    // Expression: 1
    //  Referenced by: '<S394>/Puck State'

    1.0,

    // Computed Parameter: Out1_Y0_b3
    //  Referenced by: '<S428>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_b1
    //  Referenced by: '<S430>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_ba
    //  Referenced by: '<S432>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_c
    //  Referenced by: '<S442>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_o
    //  Referenced by: '<S444>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_a
    //  Referenced by: '<S446>/Out1'

    0.0,

    // Expression: pi/2
    //  Referenced by: '<S426>/Constant1'

    1.5707963267948966,

    // Expression: 0
    //  Referenced by: '<S426>/Constant6'

    0.0,

    // Expression: 1
    //  Referenced by: '<S426>/Constant7'

    1.0,

    // Expression: 0
    //  Referenced by: '<S395>/Constant2'

    0.0,

    // Expression: 1
    //  Referenced by: '<S395>/Puck State'

    1.0
  }
  ,

  // End of '<Root>/Phase #4: Return Home'

  // Start of '<S354>/Simulated Position Controller'
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S388>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_h
    //  Referenced by: '<S390>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_k
    //  Referenced by: '<S392>/Out1'

    0.0
  }
  ,

  // End of '<S354>/Simulated Position Controller'

  // Start of '<S246>/RED+ARM'
  {
    // Expression: pi/2
    //  Referenced by: '<S320>/Constant4'

    1.5707963267948966,

    // Expression: pi/2
    //  Referenced by: '<S320>/Constant5'

    1.5707963267948966,

    // Expression: 0
    //  Referenced by: '<S320>/Constant6'

    0.0,

    // Expression: 1
    //  Referenced by: '<S320>/Constant7'

    1.0,

    // Start of '<S66>/Simulated Position Controller'
    {
      // Computed Parameter: Out1_Y0
      //  Referenced by: '<S338>/Out1'

      0.0,

      // Computed Parameter: Out1_Y0_h
      //  Referenced by: '<S340>/Out1'

      0.0,

      // Computed Parameter: Out1_Y0_k
      //  Referenced by: '<S342>/Out1'

      0.0
    }
    // End of '<S66>/Simulated Position Controller'
  }
  ,

  // End of '<S246>/RED+ARM'

  // Start of '<S89>/Sub-Phase #2 '
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S291>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_c
    //  Referenced by: '<S293>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_j
    //  Referenced by: '<S295>/Out1'

    0.0,

    // Expression: 0
    //  Referenced by: '<S245>/Constant1'

    0.0,

    // Expression: 0.03490659
    //  Referenced by: '<S288>/Desired Rate '

    0.03490659,

    // Expression: pi
    //  Referenced by: '<S288>/Constant'

    3.1415926535897931,

    // Expression: 1
    //  Referenced by: '<S245>/Puck State'

    1.0,

    // Start of '<S244>/RED+ARM'
    {
      // Expression: pi/2
      //  Referenced by: '<S287>/Constant4'

      1.5707963267948966,

      // Expression: pi/2
      //  Referenced by: '<S287>/Constant5'

      1.5707963267948966,

      // Expression: 0
      //  Referenced by: '<S287>/Constant6'

      0.0,

      // Expression: 1
      //  Referenced by: '<S287>/Constant7'

      1.0,

      // Start of '<S66>/Simulated Position Controller'
      {
        // Computed Parameter: Out1_Y0
        //  Referenced by: '<S305>/Out1'

        0.0,

        // Computed Parameter: Out1_Y0_h
        //  Referenced by: '<S307>/Out1'

        0.0,

        // Computed Parameter: Out1_Y0_k
        //  Referenced by: '<S309>/Out1'

        0.0
      }
      // End of '<S66>/Simulated Position Controller'
    }
    // End of '<S244>/RED+ARM'
  }
  ,

  // End of '<S89>/Sub-Phase #2 '

  // Start of '<S89>/Sub-Phase #1'
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S258>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_c
    //  Referenced by: '<S260>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_j
    //  Referenced by: '<S262>/Out1'

    0.0,

    // Expression: 0
    //  Referenced by: '<S244>/Constant1'

    0.0,

    // Expression: 0.03490659
    //  Referenced by: '<S255>/Desired Rate '

    0.03490659,

    // Expression: pi
    //  Referenced by: '<S255>/Constant'

    3.1415926535897931,

    // Expression: 1
    //  Referenced by: '<S244>/Puck State'

    1.0,

    // Start of '<S244>/RED+ARM'
    {
      // Expression: pi/2
      //  Referenced by: '<S254>/Constant4'

      1.5707963267948966,

      // Expression: pi/2
      //  Referenced by: '<S254>/Constant5'

      1.5707963267948966,

      // Expression: 0
      //  Referenced by: '<S254>/Constant6'

      0.0,

      // Expression: 1
      //  Referenced by: '<S254>/Constant7'

      1.0,

      // Start of '<S66>/Simulated Position Controller'
      {
        // Computed Parameter: Out1_Y0
        //  Referenced by: '<S272>/Out1'

        0.0,

        // Computed Parameter: Out1_Y0_h
        //  Referenced by: '<S274>/Out1'

        0.0,

        // Computed Parameter: Out1_Y0_k
        //  Referenced by: '<S276>/Out1'

        0.0
      }
      // End of '<S66>/Simulated Position Controller'
    }
    // End of '<S244>/RED+ARM'
  }
  ,

  // End of '<S89>/Sub-Phase #1'

  // Start of '<S88>/Sub-Phase #3 '
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S235>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_p
    //  Referenced by: '<S237>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_j
    //  Referenced by: '<S239>/Out1'

    0.0,

    // Expression: 0.03490659
    //  Referenced by: '<S223>/Desired Rate '

    0.03490659,

    // Expression: 1
    //  Referenced by: '<S164>/Puck State'

    1.0
  }
  ,

  // End of '<S88>/Sub-Phase #3 '

  // Start of '<S88>/Sub-Phase #2 '
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S214>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_p
    //  Referenced by: '<S216>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_j
    //  Referenced by: '<S218>/Out1'

    0.0,

    // Expression: 0.03490659
    //  Referenced by: '<S202>/Desired Rate '

    0.03490659,

    // Expression: 1
    //  Referenced by: '<S163>/Puck State'

    1.0
  }
  ,

  // End of '<S88>/Sub-Phase #2 '

  // Start of '<S88>/Sub-Phase #1'
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S177>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_p
    //  Referenced by: '<S179>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_j
    //  Referenced by: '<S181>/Out1'

    0.0,

    // Expression: 0.03490659
    //  Referenced by: '<S165>/Desired Rate '

    0.03490659,

    // Expression: 1
    //  Referenced by: '<S161>/Puck State'

    1.0
  }
  ,

  // End of '<S88>/Sub-Phase #1'

  // Start of '<S87>/Sub-Phase #3 '
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S137>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_a
    //  Referenced by: '<S139>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_o
    //  Referenced by: '<S141>/Out1'

    0.0,

    // Expression: 0.03490659
    //  Referenced by: '<S128>/Desired Rate (BLACK)'

    0.03490659,

    // Expression: 1
    //  Referenced by: '<S92>/Puck State'

    1.0
  }
  ,

  // End of '<S87>/Sub-Phase #3 '

  // Start of '<S87>/Sub-Phase #2 '
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S120>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_a
    //  Referenced by: '<S122>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_o
    //  Referenced by: '<S124>/Out1'

    0.0,

    // Expression: 0.03490659
    //  Referenced by: '<S111>/Desired Rate (BLACK)'

    0.03490659,

    // Expression: 1
    //  Referenced by: '<S91>/Puck State'

    1.0
  }
  ,

  // End of '<S87>/Sub-Phase #2 '

  // Start of '<S87>/Sub-Phase #1'
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S103>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_a
    //  Referenced by: '<S105>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_o
    //  Referenced by: '<S107>/Out1'

    0.0,

    // Expression: 0.03490659
    //  Referenced by: '<S94>/Desired Rate (BLACK)'

    0.03490659,

    // Expression: 1
    //  Referenced by: '<S90>/Puck State'

    1.0
  }
  ,

  // End of '<S87>/Sub-Phase #1'

  // Start of '<S35>/RED+ARM'
  {
    // Expression: pi/2
    //  Referenced by: '<S66>/Constant4'

    1.5707963267948966,

    // Expression: pi/2
    //  Referenced by: '<S66>/Constant5'

    1.5707963267948966,

    // Expression: 0
    //  Referenced by: '<S66>/Constant6'

    0.0,

    // Expression: 1
    //  Referenced by: '<S66>/Constant7'

    1.0,

    // Start of '<S66>/Simulated Position Controller'
    {
      // Computed Parameter: Out1_Y0
      //  Referenced by: '<S82>/Out1'

      0.0,

      // Computed Parameter: Out1_Y0_h
      //  Referenced by: '<S84>/Out1'

      0.0,

      // Computed Parameter: Out1_Y0_k
      //  Referenced by: '<S86>/Out1'

      0.0
    }
    // End of '<S66>/Simulated Position Controller'
  }
  ,

  // End of '<S35>/RED+ARM'

  // Start of '<Root>/Phase #1: Start Floating '
  {
    // Expression: 0
    //  Referenced by: '<S30>/Constant3'

    0.0,

    // Expression: 0
    //  Referenced by: '<S30>/Constant4'

    0.0,

    // Expression: 0
    //  Referenced by: '<S30>/Constant5'

    0.0,

    // Expression: 1
    //  Referenced by: '<S30>/Puck State'

    1.0,

    // Expression: 0
    //  Referenced by: '<S32>/Constant'

    0.0,

    // Expression: 0
    //  Referenced by: '<S32>/Constant1'

    0.0,

    // Expression: 0
    //  Referenced by: '<S32>/Constant2'

    0.0,

    // Expression: 0
    //  Referenced by: '<S32>/Constant3'

    0.0,

    // Expression: 0
    //  Referenced by: '<S32>/Constant4'

    0.0,

    // Expression: 1
    //  Referenced by: '<S32>/Puck State'

    1.0,

    // Start of '<S6>/Change BLUE Behavior'
    {
      // Expression: 0
      //  Referenced by: '<S31>/Constant3'

      0.0,

      // Expression: 0
      //  Referenced by: '<S31>/Constant4'

      0.0,

      // Expression: 0
      //  Referenced by: '<S31>/Constant5'

      0.0,

      // Expression: 1
      //  Referenced by: '<S31>/Puck State'

      1.0
    }
    // End of '<S6>/Change BLUE Behavior'
  }
  ,

  // End of '<Root>/Phase #1: Start Floating '

  // Start of '<Root>/Phase #0: Synchronization'
  {
    // Expression: 0
    //  Referenced by: '<S27>/Constant3'

    0.0,

    // Expression: 0
    //  Referenced by: '<S27>/Constant4'

    0.0,

    // Expression: 0
    //  Referenced by: '<S27>/Constant5'

    0.0,

    // Expression: 0
    //  Referenced by: '<S27>/Puck State'

    0.0,

    // Expression: 0
    //  Referenced by: '<S29>/Constant'

    0.0,

    // Expression: 0
    //  Referenced by: '<S29>/Constant1'

    0.0,

    // Expression: 0
    //  Referenced by: '<S29>/Constant2'

    0.0,

    // Expression: 0
    //  Referenced by: '<S29>/Constant3'

    0.0,

    // Expression: 0
    //  Referenced by: '<S29>/Constant4'

    0.0,

    // Expression: 0
    //  Referenced by: '<S29>/Puck State'

    0.0,

    // Start of '<S6>/Change BLUE Behavior'
    {
      // Expression: 0
      //  Referenced by: '<S28>/Constant3'

      0.0,

      // Expression: 0
      //  Referenced by: '<S28>/Constant4'

      0.0,

      // Expression: 0
      //  Referenced by: '<S28>/Constant5'

      0.0,

      // Expression: 0
      //  Referenced by: '<S28>/Puck State'

      0.0
    }
    // End of '<S6>/Change BLUE Behavior'
  }
  ,

  // End of '<Root>/Phase #0: Synchronization'

  // Start of '<S1>/Change BLUE Behavior'
  {
    // Computed Parameter: Constant1_Value
    //  Referenced by: '<S21>/Constant1'

    1,

    // Computed Parameter: UDPSend_Port
    //  Referenced by: '<S21>/UDP Send'

    33003
  }
  ,

  // End of '<S1>/Change BLUE Behavior'

  // Start of '<S1>/Change BLACK Behavior'
  {
    // Computed Parameter: Constant1_Value
    //  Referenced by: '<S20>/Constant1'

    1,

    // Computed Parameter: UDPSend_Port
    //  Referenced by: '<S20>/UDP Send'

    33002
  }
  // End of '<S1>/Change BLACK Behavior'
};

//
// File trailer for generated code.
//
// [EOF]
//
