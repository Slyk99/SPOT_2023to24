//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: APF_Path_Planning_2023a_data.cpp
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

// Block parameters (default storage)
P_APF_Path_Planning_2023a_T APF_Path_Planning_2023a_P = {
  // Variable: Att_Mode
  //  Referenced by: '<S368>/Constant2'

  0.0,

  // Variable: BLACK_end
  //  Referenced by:
  //    '<S149>/End Pos'
  //    '<S150>/End Pos'
  //    '<S151>/End Pos'

  { 1.75, 0.5, 6.4228116473391328 },

  // Variable: BLACK_ini
  //  Referenced by:
  //    '<S149>/Velocity'
  //    '<S149>/Start Pos'
  //    '<S150>/Velocity'
  //    '<S150>/Start Pos'
  //    '<S151>/Velocity'
  //    '<S151>/Start Pos'

  { 1.75, 0.5, 3.2812189937493397, 0.0, 0.0, 0.026179938779914945 },

  // Variable: BLUE_end
  //  Referenced by:
  //    '<S232>/End Time'
  //    '<S233>/End Time'
  //    '<S234>/End Time'

  { 1.3, 1.25, 5.497787143782138 },

  // Variable: BLUE_ini
  //  Referenced by:
  //    '<S232>/Velocity'
  //    '<S232>/Start Pos'
  //    '<S233>/Velocity'
  //    '<S233>/Start Pos'
  //    '<S234>/Velocity'
  //    '<S234>/Start Pos'

  { 1.3, 1.25, 2.3561944901923448, 0.0, 0.0, -0.026179938779914945 },

  // Variable: Binv
  //  Referenced by:
  //    '<S372>/MATLAB Function'
  //    '<S382>/MATLAB Function1'

  { 12.0, 0.0, 0.0, 0.0, 12.0, 0.0, 0.0, 0.0, 0.19816 },

  // Variable: F_Black_X_nominal
  //  Referenced by:
  //    '<S629>/MATLAB Function11'
  //    '<S629>/MATLAB Function3'

  0.2196,

  // Variable: F_Black_Y_nominal
  //  Referenced by:
  //    '<S629>/MATLAB Function11'
  //    '<S629>/MATLAB Function3'

  0.2825,

  // Variable: F_Blue_X_nominal
  //  Referenced by:
  //    '<S641>/MATLAB Function1'
  //    '<S641>/MATLAB Function7'

  0.2196,

  // Variable: F_Blue_Y_nominal
  //  Referenced by:
  //    '<S641>/MATLAB Function1'
  //    '<S641>/MATLAB Function7'

  0.2825,

  // Variable: F_red_X_nominal
  //  Referenced by:
  //    '<S653>/MATLAB Function11'
  //    '<S653>/MATLAB Function4'
  //    '<S653>/MATLAB Function6'
  //    '<S653>/MATLAB Function7'

  0.2196,

  // Variable: F_red_Y_nominal
  //  Referenced by:
  //    '<S653>/MATLAB Function11'
  //    '<S653>/MATLAB Function4'
  //    '<S653>/MATLAB Function6'
  //    '<S653>/MATLAB Function7'

  0.2825,

  // Variable: F_thrusters_BLACK
  //  Referenced by: '<S629>/MATLAB Function'

  { 0.2196, 0.2196, 0.2825, 0.2825, 0.2196, 0.2196, 0.2825, 0.2825 },

  // Variable: F_thrusters_BLUE
  //  Referenced by: '<S641>/MATLAB Function'

  { 0.2196, 0.2196, 0.2825, 0.2825, 0.2196, 0.2196, 0.2825, 0.2825 },

  // Variable: F_thrusters_RED
  //  Referenced by:
  //    '<S653>/MATLAB Function'
  //    '<S653>/MATLAB Function3'

  { 0.2196, 0.2196, 0.2825, 0.2825, 0.2196, 0.2196, 0.2825, 0.2825 },

  // Variable: Gamma1_el
  //  Referenced by: '<S601>/Dynamics Model'

  0.12,

  // Variable: Gamma1_sh
  //  Referenced by: '<S601>/Dynamics Model'

  0.005,

  // Variable: Gamma1_wr
  //  Referenced by: '<S601>/Dynamics Model'

  0.025,

  // Variable: Gamma2_el
  //  Referenced by: '<S601>/Dynamics Model'

  5.0,

  // Variable: Gamma2_sh
  //  Referenced by: '<S601>/Dynamics Model'

  5.0,

  // Variable: Gamma2_wr
  //  Referenced by: '<S601>/Dynamics Model'

  5.0,

  // Variable: Gamma3_el
  //  Referenced by: '<S601>/Dynamics Model'

  10.0,

  // Variable: Gamma3_sh
  //  Referenced by: '<S601>/Dynamics Model'

  40.0,

  // Variable: Gamma3_wr
  //  Referenced by: '<S601>/Dynamics Model'

  40.0,

  // Variable: Gamma4_el
  //  Referenced by: '<S601>/Dynamics Model'

  0.039,

  // Variable: Gamma4_sh
  //  Referenced by: '<S601>/Dynamics Model'

  0.015,

  // Variable: Gamma4_wr
  //  Referenced by: '<S601>/Dynamics Model'

  0.029,

  // Variable: Gamma5_el
  //  Referenced by: '<S601>/Dynamics Model'

  800.0,

  // Variable: Gamma5_sh
  //  Referenced by: '<S601>/Dynamics Model'

  800.0,

  // Variable: Gamma5_wr
  //  Referenced by: '<S601>/Dynamics Model'

  800.0,

  // Variable: Gamma6_el
  //  Referenced by: '<S601>/Dynamics Model'

  1.0E-6,

  // Variable: Gamma6_sh
  //  Referenced by: '<S601>/Dynamics Model'

  0.005,

  // Variable: Gamma6_wr
  //  Referenced by: '<S601>/Dynamics Model'

  0.02,

  // Variable: Hz
  //  Referenced by: '<S369>/Switch logic'

  0.01,

  // Variable: IBLACK
  //  Referenced by: '<S571>/MATLAB Function'

  0.19956537087503129,

  // Variable: IBLUE
  //  Referenced by: '<S585>/MATLAB Function'

  0.19609228544737417,

  // Variable: IDIST
  //  Referenced by: '<S601>/Inertia Function 1'

  0.003506,

  // Variable: IEE
  //  Referenced by: '<S601>/Inertia Function 1'

  0.000106,

  // Variable: IPROX
  //  Referenced by: '<S601>/Inertia Function 1'

  0.003704,

  // Variable: IRED
  //  Referenced by:
  //    '<S601>/Inertia Function 1'
  //    '<S612>/MATLAB Function'

  0.19816136536704418,

  // Variable: K_a
  //  Referenced by:
  //    '<S372>/MATLAB Function'
  //    '<S382>/MATLAB Function1'

  { 2.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 3.5 },

  // Variable: Kd_elarm
  //  Referenced by:
  //    '<S78>/kd_elarm'
  //    '<S457>/kd_elarm'
  //    '<S511>/kd_elarm'
  //    '<S268>/kd_elarm'
  //    '<S301>/kd_elarm'
  //    '<S334>/kd_elarm'
  //    '<S403>/kd_elarm'

  0.8,

  // Variable: Kd_sharm
  //  Referenced by:
  //    '<S79>/kd_sharm'
  //    '<S458>/kd_sharm'
  //    '<S512>/kd_sharm'
  //    '<S269>/kd_sharm'
  //    '<S302>/kd_sharm'
  //    '<S335>/kd_sharm'
  //    '<S404>/kd_sharm'

  1.0,

  // Variable: Kd_tb
  //  Referenced by:
  //    '<S36>/kd_tb'
  //    '<S415>/kd_tb'
  //    '<S469>/kd_tb'
  //    '<S95>/kd_tb'
  //    '<S112>/kd_tb'
  //    '<S129>/kd_tb'

  1.2,

  // Variable: Kd_tblue
  //  Referenced by:
  //    '<S49>/kd_tb'
  //    '<S428>/kd_tb'
  //    '<S482>/kd_tb'
  //    '<S166>/kd_tb'
  //    '<S187>/kd_tb'
  //    '<S208>/kd_tb'
  //    '<S228>/kd_tb'

  1.2,

  // Variable: Kd_tr
  //  Referenced by:
  //    '<S62>/kd_tr'
  //    '<S441>/kd_tr'
  //    '<S495>/kd_tr'
  //    '<S248>/kd_tr'
  //    '<S281>/kd_tr'
  //    '<S314>/kd_tr'

  1.2,

  // Variable: Kd_wrarm
  //  Referenced by:
  //    '<S80>/kd_wrarm'
  //    '<S459>/kd_wrarm'
  //    '<S513>/kd_wrarm'
  //    '<S270>/kd_wrarm'
  //    '<S303>/kd_wrarm'
  //    '<S336>/kd_wrarm'
  //    '<S405>/kd_wrarm'

  0.6,

  // Variable: Kd_xb
  //  Referenced by:
  //    '<S37>/kd_xb'
  //    '<S416>/kd_xb'
  //    '<S470>/kd_xb'
  //    '<S96>/kd_xb'
  //    '<S113>/kd_xb'
  //    '<S130>/kd_xb'

  2.6,

  // Variable: Kd_xblue
  //  Referenced by:
  //    '<S50>/kd_xb'
  //    '<S429>/kd_xb'
  //    '<S483>/kd_xb'
  //    '<S167>/kd_xb'
  //    '<S188>/kd_xb'
  //    '<S209>/kd_xb'
  //    '<S229>/kd_xb'

  2.6,

  // Variable: Kd_xr
  //  Referenced by:
  //    '<S63>/kd_xr'
  //    '<S442>/kd_xr'
  //    '<S496>/kd_xr'
  //    '<S249>/kd_xr'
  //    '<S282>/kd_xr'
  //    '<S315>/kd_xr'

  2.6,

  // Variable: Kd_yb
  //  Referenced by:
  //    '<S38>/kd_yb'
  //    '<S417>/kd_yb'
  //    '<S471>/kd_yb'
  //    '<S97>/kd_yb'
  //    '<S114>/kd_yb'
  //    '<S131>/kd_yb'

  2.6,

  // Variable: Kd_yblue
  //  Referenced by:
  //    '<S51>/kd_yb'
  //    '<S430>/kd_yb'
  //    '<S484>/kd_yb'
  //    '<S168>/kd_yb'
  //    '<S189>/kd_yb'
  //    '<S210>/kd_yb'
  //    '<S230>/kd_yb'

  2.6,

  // Variable: Kd_yr
  //  Referenced by:
  //    '<S64>/kd_yr'
  //    '<S443>/kd_yr'
  //    '<S497>/kd_yr'
  //    '<S250>/kd_yr'
  //    '<S283>/kd_yr'
  //    '<S316>/kd_yr'

  2.6,

  // Variable: Kp_elarm
  //  Referenced by:
  //    '<S78>/kp_elarm'
  //    '<S457>/kp_elarm'
  //    '<S511>/kp_elarm'
  //    '<S268>/kp_elarm'
  //    '<S301>/kp_elarm'
  //    '<S334>/kp_elarm'
  //    '<S403>/kp_elarm'

  1.2,

  // Variable: Kp_sharm
  //  Referenced by:
  //    '<S79>/kp_sharm'
  //    '<S458>/kp_sharm'
  //    '<S512>/kp_sharm'
  //    '<S269>/kp_sharm'
  //    '<S302>/kp_sharm'
  //    '<S335>/kp_sharm'
  //    '<S404>/kp_sharm'

  1.5,

  // Variable: Kp_tb
  //  Referenced by:
  //    '<S36>/kp_tb'
  //    '<S415>/kp_tb'
  //    '<S469>/kp_tb'
  //    '<S95>/kp_tb'
  //    '<S112>/kp_tb'
  //    '<S129>/kp_tb'

  0.5,

  // Variable: Kp_tblue
  //  Referenced by:
  //    '<S49>/kp_tb'
  //    '<S428>/kp_tb'
  //    '<S482>/kp_tb'
  //    '<S166>/kp_tb'
  //    '<S187>/kp_tb'
  //    '<S208>/kp_tb'
  //    '<S228>/kp_tb'

  0.5,

  // Variable: Kp_tr
  //  Referenced by:
  //    '<S62>/kp_tr'
  //    '<S441>/kp_tr'
  //    '<S495>/kp_tr'
  //    '<S248>/kp_tr'
  //    '<S281>/kp_tr'
  //    '<S314>/kp_tr'

  0.5,

  // Variable: Kp_wrarm
  //  Referenced by:
  //    '<S80>/kp_wrarm'
  //    '<S459>/kp_wrarm'
  //    '<S513>/kp_wrarm'
  //    '<S270>/kp_wrarm'
  //    '<S303>/kp_wrarm'
  //    '<S336>/kp_wrarm'
  //    '<S405>/kp_wrarm'

  2.0,

  // Variable: Kp_xb
  //  Referenced by:
  //    '<S37>/kp_xb'
  //    '<S416>/kp_xb'
  //    '<S470>/kp_xb'
  //    '<S96>/kp_xb'
  //    '<S113>/kp_xb'
  //    '<S130>/kp_xb'

  1.0,

  // Variable: Kp_xblue
  //  Referenced by:
  //    '<S50>/kp_xb'
  //    '<S429>/kp_xb'
  //    '<S483>/kp_xb'
  //    '<S167>/kp_xb'
  //    '<S188>/kp_xb'
  //    '<S209>/kp_xb'
  //    '<S229>/kp_xb'

  1.0,

  // Variable: Kp_xr
  //  Referenced by:
  //    '<S63>/kp_xr'
  //    '<S442>/kp_xr'
  //    '<S496>/kp_xr'
  //    '<S249>/kp_xr'
  //    '<S282>/kp_xr'
  //    '<S315>/kp_xr'

  1.0,

  // Variable: Kp_yb
  //  Referenced by:
  //    '<S38>/kp_yb'
  //    '<S417>/kp_yb'
  //    '<S471>/kp_yb'
  //    '<S97>/kp_yb'
  //    '<S114>/kp_yb'
  //    '<S131>/kp_yb'

  1.0,

  // Variable: Kp_yblue
  //  Referenced by:
  //    '<S51>/kp_yb'
  //    '<S430>/kp_yb'
  //    '<S484>/kp_yb'
  //    '<S168>/kp_yb'
  //    '<S189>/kp_yb'
  //    '<S210>/kp_yb'
  //    '<S230>/kp_yb'

  1.0,

  // Variable: Kp_yr
  //  Referenced by:
  //    '<S64>/kp_yr'
  //    '<S443>/kp_yr'
  //    '<S497>/kp_yr'
  //    '<S250>/kp_yr'
  //    '<S283>/kp_yr'
  //    '<S316>/kp_yr'

  1.0,

  // Variable: Method
  //  Referenced by: '<S375>/Constant3'

  8.0,

  // Variable: Nmat
  //  Referenced by:
  //    '<S372>/MATLAB Function'
  //    '<S382>/MATLAB Function1'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  // Variable: PWMFreq
  //  Referenced by:
  //    '<S19>/PWM Frequency'
  //    '<S629>/MATLAB Function1'
  //    '<S641>/MATLAB Function2'
  //    '<S653>/MATLAB Function2'

  5.0,

  // Variable: P_b
  //  Referenced by:
  //    '<S372>/MATLAB Function'
  //    '<S382>/MATLAB Function1'

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
  //    '<S378>/Constant'

  45.0,

  // Variable: Phase3_End
  //  Referenced by: '<Root>/Constant2'

  355.0,

  // Variable: Phase3_SubPhase1_End
  //  Referenced by:
  //    '<S87>/Constant4'
  //    '<S88>/Constant4'
  //    '<S89>/Constant4'

  45.0,

  // Variable: Phase3_SubPhase2_End
  //  Referenced by:
  //    '<S87>/Constant1'
  //    '<S88>/Constant1'
  //    '<S89>/Constant1'

  45.0,

  // Variable: Phase3_SubPhase3_End
  //  Referenced by:
  //    '<S87>/Constant2'
  //    '<S88>/Constant2'
  //    '<S89>/Constant2'
  //    '<S395>/Constant1'

  75.0,

  // Variable: Phase3_SubPhase4_End
  //  Referenced by:
  //    '<S87>/Constant3'
  //    '<S88>/Constant3'
  //    '<S89>/Constant3'

  355.0,

  // Variable: Phase4_End
  //  Referenced by: '<Root>/Constant3'

  385.0,

  // Variable: Phase5_End
  //  Referenced by: '<Root>/Constant6'

  405.0,

  // Variable: Phi
  //  Referenced by:
  //    '<S653>/MATLAB Function'
  //    '<S653>/MATLAB Function4'
  //    '<S653>/MATLAB Function6'
  //    '<S601>/Coriolis Function1'
  //    '<S601>/Inertia Function 1'

  1.2788882640695929,

  // Variable: Q_a
  //  Referenced by:
  //    '<S372>/MATLAB Function'
  //    '<S382>/MATLAB Function1'

  { 5.0, 0.0, 0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0 },

  // Variable: Q_b
  //  Referenced by:
  //    '<S372>/MATLAB Function'
  //    '<S382>/MATLAB Function1'

  { 0.0125, 0.0, 0.0, 0.0, 0.0125, 0.0, 0.0, 0.0, 0.05 },

  // Variable: RMSprop_epsilon
  //  Referenced by: '<S383>/MATLAB Function1'

  1.0E-8,

  // Variable: RMSprop_eta
  //  Referenced by: '<S383>/MATLAB Function1'

  0.025,

  // Variable: RMSprop_gamma
  //  Referenced by: '<S383>/MATLAB Function1'

  0.9,

  // Variable: Red_Rate
  //  Referenced by: '<S393>/Desired Rate (RED)'

  0.025,

  // Variable: Time_Look
  //  Referenced by: '<S369>/Switch logic'

  25.0,

  // Variable: Tz_lim_elarm
  //  Referenced by:
  //    '<S77>/Saturation1'
  //    '<S456>/Saturation1'
  //    '<S510>/Saturation1'
  //    '<S267>/Saturation1'
  //    '<S300>/Saturation1'
  //    '<S333>/Saturation1'
  //    '<S402>/Saturation1'

  0.1,

  // Variable: Tz_lim_sharm
  //  Referenced by:
  //    '<S77>/Saturation'
  //    '<S456>/Saturation'
  //    '<S510>/Saturation'
  //    '<S267>/Saturation'
  //    '<S300>/Saturation'
  //    '<S333>/Saturation'
  //    '<S402>/Saturation'

  0.1,

  // Variable: Tz_lim_wrarm
  //  Referenced by:
  //    '<S77>/Saturation3'
  //    '<S456>/Saturation3'
  //    '<S510>/Saturation3'
  //    '<S267>/Saturation3'
  //    '<S300>/Saturation3'
  //    '<S333>/Saturation3'
  //    '<S402>/Saturation3'

  0.1,

  // Variable: a1
  //  Referenced by:
  //    '<S653>/MATLAB Function'
  //    '<S653>/MATLAB Function4'
  //    '<S653>/MATLAB Function6'
  //    '<S601>/Coriolis Function1'
  //    '<S601>/Inertia Function 1'

  0.3,

  // Variable: a2
  //  Referenced by:
  //    '<S653>/MATLAB Function'
  //    '<S653>/MATLAB Function4'
  //    '<S653>/MATLAB Function6'
  //    '<S601>/Coriolis Function1'
  //    '<S601>/Inertia Function 1'

  0.3,

  // Variable: a3
  //  Referenced by:
  //    '<S653>/MATLAB Function'
  //    '<S653>/MATLAB Function4'
  //    '<S653>/MATLAB Function6'
  //    '<S601>/Coriolis Function1'
  //    '<S601>/Inertia Function 1'

  0.4,

  // Variable: adadelta_epsilon
  //  Referenced by: '<S376>/MATLAB Function1'

  1.0E-5,

  // Variable: adadelta_gamma
  //  Referenced by: '<S376>/MATLAB Function1'

  0.37,

  // Variable: adagrad_epsilon
  //  Referenced by: '<S377>/MATLAB Function1'

  1.0E-8,

  // Variable: adagrad_eta
  //  Referenced by: '<S377>/MATLAB Function1'

  0.18,

  // Variable: adam_beta_1
  //  Referenced by: '<S379>/MATLAB Function1'

  0.99,

  // Variable: adam_beta_2
  //  Referenced by: '<S379>/MATLAB Function1'

  0.999,

  // Variable: adam_epsilon
  //  Referenced by: '<S379>/MATLAB Function1'

  0.01,

  // Variable: adam_eta
  //  Referenced by: '<S379>/MATLAB Function1'

  0.0163,

  // Variable: adamax_beta_1
  //  Referenced by: '<S378>/MATLAB Function1'

  0.5,

  // Variable: adamax_beta_2
  //  Referenced by: '<S378>/MATLAB Function1'

  0.999,

  // Variable: adamax_eta
  //  Referenced by: '<S378>/MATLAB Function1'

  0.014,

  // Variable: b0
  //  Referenced by:
  //    '<S653>/MATLAB Function'
  //    '<S653>/MATLAB Function4'
  //    '<S653>/MATLAB Function6'
  //    '<S601>/Coriolis Function1'
  //    '<S601>/Inertia Function 1'

  0.25,

  // Variable: b1
  //  Referenced by:
  //    '<S653>/MATLAB Function'
  //    '<S653>/MATLAB Function4'
  //    '<S653>/MATLAB Function6'
  //    '<S601>/Coriolis Function1'
  //    '<S601>/Inertia Function 1'

  0.175,

  // Variable: b2
  //  Referenced by:
  //    '<S653>/MATLAB Function'
  //    '<S653>/MATLAB Function4'
  //    '<S653>/MATLAB Function6'
  //    '<S601>/Coriolis Function1'
  //    '<S601>/Inertia Function 1'

  0.175,

  // Variable: b3
  //  Referenced by:
  //    '<S653>/MATLAB Function'
  //    '<S653>/MATLAB Function4'
  //    '<S653>/MATLAB Function6'
  //    '<S601>/Inertia Function 1'

  0.025153,

  // Variable: baseRate
  //  Referenced by:
  //    '<S26>/Read Joint Positions using  Dynamixel Encoders'
  //    '<S565>/WhoAmI'
  //    '<S566>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'
  //    '<S527>/divide by delta T'
  //    '<S528>/divide by delta T'
  //    '<S529>/divide by delta T'
  //    '<S530>/divide by delta T'
  //    '<S531>/divide by delta T'
  //    '<S532>/divide by delta T'
  //    '<S533>/divide by delta T'
  //    '<S534>/divide by delta T'
  //    '<S535>/divide by delta T'
  //    '<S536>/divide by delta T'
  //    '<S537>/divide by delta T'
  //    '<S538>/divide by delta T'
  //    '<S539>/divide by delta T'
  //    '<S540>/divide by delta T'
  //    '<S541>/divide by delta T'
  //    '<S542>/divide by delta T'
  //    '<S543>/divide by delta T'
  //    '<S544>/divide by delta T'
  //    '<S572>/divide by delta T'
  //    '<S573>/divide by delta T'
  //    '<S574>/divide by delta T'
  //    '<S575>/divide by delta T'
  //    '<S576>/divide by delta T'
  //    '<S577>/divide by delta T'
  //    '<S586>/divide by delta T'
  //    '<S587>/divide by delta T'
  //    '<S588>/divide by delta T'
  //    '<S589>/divide by delta T'
  //    '<S590>/divide by delta T'
  //    '<S591>/divide by delta T'
  //    '<S40>/divide by delta T'
  //    '<S42>/divide by delta T'
  //    '<S44>/divide by delta T'
  //    '<S53>/divide by delta T'
  //    '<S55>/divide by delta T'
  //    '<S57>/divide by delta T'
  //    '<S67>/divide by delta T'
  //    '<S69>/divide by delta T'
  //    '<S71>/divide by delta T'
  //    '<S419>/divide by delta T'
  //    '<S421>/divide by delta T'
  //    '<S423>/divide by delta T'
  //    '<S432>/divide by delta T'
  //    '<S434>/divide by delta T'
  //    '<S436>/divide by delta T'
  //    '<S446>/divide by delta T'
  //    '<S448>/divide by delta T'
  //    '<S450>/divide by delta T'
  //    '<S473>/divide by delta T'
  //    '<S475>/divide by delta T'
  //    '<S477>/divide by delta T'
  //    '<S486>/divide by delta T'
  //    '<S488>/divide by delta T'
  //    '<S490>/divide by delta T'
  //    '<S500>/divide by delta T'
  //    '<S502>/divide by delta T'
  //    '<S504>/divide by delta T'
  //    '<S102>/divide by delta T'
  //    '<S104>/divide by delta T'
  //    '<S106>/divide by delta T'
  //    '<S119>/divide by delta T'
  //    '<S121>/divide by delta T'
  //    '<S123>/divide by delta T'
  //    '<S136>/divide by delta T'
  //    '<S138>/divide by delta T'
  //    '<S140>/divide by delta T'
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
  //    '<S605>/divide by delta T'
  //    '<S606>/divide by delta T'
  //    '<S607>/divide by delta T'
  //    '<S613>/divide by delta T'
  //    '<S614>/divide by delta T'
  //    '<S615>/divide by delta T'
  //    '<S616>/divide by delta T'
  //    '<S617>/divide by delta T'
  //    '<S618>/divide by delta T'
  //    '<S81>/divide by delta T'
  //    '<S83>/divide by delta T'
  //    '<S85>/divide by delta T'
  //    '<S460>/divide by delta T'
  //    '<S462>/divide by delta T'
  //    '<S464>/divide by delta T'
  //    '<S514>/divide by delta T'
  //    '<S516>/divide by delta T'
  //    '<S518>/divide by delta T'
  //    '<S271>/divide by delta T'
  //    '<S273>/divide by delta T'
  //    '<S275>/divide by delta T'
  //    '<S304>/divide by delta T'
  //    '<S306>/divide by delta T'
  //    '<S308>/divide by delta T'
  //    '<S337>/divide by delta T'
  //    '<S339>/divide by delta T'
  //    '<S341>/divide by delta T'
  //    '<S406>/divide by delta T'
  //    '<S408>/divide by delta T'
  //    '<S410>/divide by delta T'

  0.01,

  // Variable: batch_eta
  //  Referenced by: '<S380>/Batch'

  0.25,

  // Variable: drop_states_BLACK
  //  Referenced by: '<S571>/Velocity to Position'

  { 1.75, 0.5, 3.2812189937493397 },

  // Variable: drop_states_BLUE
  //  Referenced by: '<S585>/Velocity to Position'

  { 1.3, 1.25, 2.3561944901923448 },

  // Variable: drop_states_RED
  //  Referenced by: '<S612>/Velocity to Position'

  { 2.7, 0.4, -3.1415926535897931 },

  // Variable: end_time_black
  //  Referenced by:
  //    '<S149>/End Time'
  //    '<S150>/End Time'
  //    '<S151>/End Time'

  300.0,

  // Variable: end_time_blue
  //  Referenced by:
  //    '<S232>/End Pos'
  //    '<S233>/End Pos'
  //    '<S234>/End Pos'

  300.0,

  // Variable: home_states_BLACK
  //  Referenced by:
  //    '<S412>/Desired Attitude (BLACK)'
  //    '<S412>/Desired Px (BLACK)'
  //    '<S412>/Desired Py (BLACK)'
  //    '<S466>/Desired Attitude (BLACK)'
  //    '<S466>/Desired Px (BLACK)'
  //    '<S466>/Desired Py (BLACK)'

  { 1.75, 0.5, 3.2812189937493397 },

  // Variable: home_states_BLUE
  //  Referenced by:
  //    '<S413>/Desired Attitude (BLUE)'
  //    '<S413>/Desired Px (BLUE)'
  //    '<S413>/Desired Py (BLUE)'
  //    '<S467>/Desired Attitude (BLUE)'
  //    '<S467>/Desired Px (BLUE)'
  //    '<S467>/Desired Py (BLUE)'

  { 1.3, 1.25, 2.3561944901923448 },

  // Variable: home_states_RED
  //  Referenced by:
  //    '<S414>/Desired Px (RED)'
  //    '<S414>/Desired Py (RED)'
  //    '<S414>/Desired Rz (RED)'
  //    '<S468>/Desired Px (RED)'
  //    '<S468>/Desired Py (RED)'
  //    '<S468>/Desired Rz (RED)'

  { 2.7, 0.4, -3.1415926535897931 },

  // Variable: init_states_BLACK
  //  Referenced by:
  //    '<S33>/Desired Attitude (BLACK)'
  //    '<S33>/Desired Px (BLACK)'
  //    '<S33>/Desired Py (BLACK)'

  { 1.75, 0.5, 3.2812189937493397 },

  // Variable: init_states_BLUE
  //  Referenced by:
  //    '<S34>/Desired Attitude (BLUE)'
  //    '<S34>/Desired Px (BLUE)'
  //    '<S34>/Desired Py (BLUE)'

  { 1.3, 1.25, 2.3561944901923448 },

  // Variable: init_states_RED
  //  Referenced by:
  //    '<S35>/Constant'
  //    '<S35>/Constant1'
  //    '<S35>/Constant3'
  //    '<S393>/Constant'
  //    '<S394>/Constant1'
  //    '<S394>/Constant2'
  //    '<S399>/Constant1'
  //    '<S399>/Constant2'

  { 2.7, 0.4, -3.1415926535897931 },

  // Variable: k
  //  Referenced by:
  //    '<S364>/Constant'
  //    '<S366>/Constant'

  { 3.8729833462074241, 7.3274719625260332E-15, 1.4031034209200205E-15,
    7.8891613745256441E-15, 3.8729833462074232, -1.1145622395159269E-17,
    -4.5079872316022321E-16, 5.0966384815908735E-16, 1.0000000000000036,
    82.689214446166972, -2.0781987242202149E-15, 1.9958640187946502E-15,
    2.3467763609000223E-14, 82.6892144461671, 1.0683955481494294E-14,
    -2.2423151955265392E-15, 2.7961454301515212E-15, 4.5162288173579288 },

  // Variable: k_1_0
  //  Referenced by:
  //    '<S360>/Discrete-Time Integrator3'
  //    '<S360>/Discrete-Time Integrator5'

  3.8729833462074241,

  // Variable: k_1_t_0
  //  Referenced by: '<S360>/Discrete-Time Integrator1'

  1.0000000000000036,

  // Variable: k_2_0
  //  Referenced by:
  //    '<S360>/Discrete-Time Integrator2'
  //    '<S360>/Discrete-Time Integrator4'

  82.689214446166972,

  // Variable: k_2_t_0
  //  Referenced by: '<S360>/Discrete-Time Integrator'

  4.5162288173579288,

  // Variable: ka
  //  Referenced by:
  //    '<S372>/MATLAB Function'
  //    '<S382>/MATLAB Function1'

  1.0,

  // Variable: kr
  //  Referenced by:
  //    '<S372>/MATLAB Function'
  //    '<S382>/MATLAB Function1'

  2.0,

  // Variable: lambda1
  //  Referenced by:
  //    '<S360>/Fx Gain Derivatives'
  //    '<S360>/Fy Gain Derivatives'

  0.4,

  // Variable: lambda12
  //  Referenced by:
  //    '<S360>/Fx Gain Derivatives'
  //    '<S360>/Fy Gain Derivatives'

  0.4,

  // Variable: lambda12_t
  //  Referenced by: '<S360>/Torque Gain Derivatives'

  0.05,

  // Variable: lambda1_t
  //  Referenced by: '<S360>/Torque Gain Derivatives'

  0.05,

  // Variable: lambda2
  //  Referenced by:
  //    '<S360>/Fx Gain Derivatives'
  //    '<S360>/Fy Gain Derivatives'

  0.4,

  // Variable: lambda2_t
  //  Referenced by: '<S360>/Torque Gain Derivatives'

  0.05,

  // Variable: mBLACK
  //  Referenced by: '<S571>/MATLAB Function'

  11.362,

  // Variable: mBLUE
  //  Referenced by: '<S585>/MATLAB Function'

  10.826,

  // Variable: mDIST
  //  Referenced by:
  //    '<S653>/MATLAB Function'
  //    '<S653>/MATLAB Function4'
  //    '<S653>/MATLAB Function6'
  //    '<S601>/Coriolis Function1'
  //    '<S601>/Inertia Function 1'

  0.335,

  // Variable: mEE
  //  Referenced by:
  //    '<S653>/MATLAB Function'
  //    '<S653>/MATLAB Function4'
  //    '<S653>/MATLAB Function6'
  //    '<S601>/Coriolis Function1'
  //    '<S601>/Inertia Function 1'

  0.111,

  // Variable: mPROX
  //  Referenced by:
  //    '<S653>/MATLAB Function'
  //    '<S653>/MATLAB Function4'
  //    '<S653>/MATLAB Function6'
  //    '<S601>/Coriolis Function1'
  //    '<S601>/Inertia Function 1'

  0.345,

  // Variable: mRED
  //  Referenced by:
  //    '<S653>/MATLAB Function'
  //    '<S653>/MATLAB Function4'
  //    '<S653>/MATLAB Function6'
  //    '<S601>/Inertia Function 1'
  //    '<S612>/MATLAB Function'

  11.296999999999999,

  // Variable: momentum_eta
  //  Referenced by: '<S381>/Momentum'

  0.7,

  // Variable: momentum_gamma
  //  Referenced by: '<S381>/Momentum'

  0.7,

  // Variable: nesterov_eta
  //  Referenced by: '<S382>/MATLAB Function1'

  0.6,

  // Variable: nesterov_gamma
  //  Referenced by: '<S382>/MATLAB Function1'

  0.3,

  // Variable: noise_variance_BLACK
  //  Referenced by: '<S571>/Random Number'

  0.0,

  // Variable: noise_variance_BLUE
  //  Referenced by: '<S585>/Random Number'

  0.0,

  // Variable: noise_variance_RED
  //  Referenced by: '<S612>/Random Number'

  0.0,

  // Variable: p
  //  Referenced by:
  //    '<S360>/Fx Gain Derivatives'
  //    '<S360>/Fy Gain Derivatives'

  0.4,

  // Variable: p_t
  //  Referenced by: '<S360>/Torque Gain Derivatives'

  0.05,

  // Variable: platformSelection
  //  Referenced by:
  //    '<S35>/Constant4'
  //    '<S414>/Constant4'
  //    '<S468>/Constant4'
  //    '<S524>/MATLAB Function'
  //    '<S570>/Constant'
  //    '<S244>/Constant4'
  //    '<S245>/Constant4'
  //    '<S246>/Constant1'
  //    '<S247>/Constant3'
  //    '<S653>/Constant'
  //    '<S653>/Constant1'
  //    '<S653>/Constant2'

  8.0,

  // Variable: psi
  //  Referenced by:
  //    '<S372>/MATLAB Function'
  //    '<S382>/MATLAB Function1'

  1.0,

  // Variable: r_hold
  //  Referenced by:
  //    '<S372>/MATLAB Function'
  //    '<S382>/MATLAB Function1'

  0.427,

  // Variable: r_off
  //  Referenced by:
  //    '<S368>/Looking Angle'
  //    '<S372>/MATLAB Function'
  //    '<S398>/Looking Angle'
  //    '<S382>/MATLAB Function1'

  0.165,

  // Variable: shape
  //  Referenced by:
  //    '<S372>/MATLAB Function'
  //    '<S382>/MATLAB Function1'

  { 0.3, 0.3, 0.4, 0.175, 0.175 },

  // Variable: sigma
  //  Referenced by:
  //    '<S372>/MATLAB Function'
  //    '<S382>/MATLAB Function1'

  0.1,

  // Variable: simMode
  //  Referenced by: '<S18>/Constant'

  0.0,

  // Variable: thruster_count_threshold
  //  Referenced by:
  //    '<S629>/MATLAB Function10'
  //    '<S641>/MATLAB Function6'
  //    '<S653>/MATLAB Function5'

  0.0,

  // Variable: thruster_dist2CG_BLACK
  //  Referenced by:
  //    '<S629>/MATLAB Function'
  //    '<S629>/MATLAB Function11'
  //    '<S629>/MATLAB Function3'

  { 87.2054215807076, -50.794578419292378, 67.834888223904244,
    -73.665111776095742, 50.794578419292378, -79.6054215807076,
    68.165111776095742, -60.834888223904244 },

  // Variable: thruster_dist2CG_BLUE
  //  Referenced by:
  //    '<S641>/MATLAB Function'
  //    '<S641>/MATLAB Function1'
  //    '<S641>/MATLAB Function7'

  { 84.3010033444816, -53.698996655518386, 79.980637211758491,
    -61.519362788241494, 53.698996655518386, -76.7010033444816,
    56.019362788241487, -72.9806372117585 },

  // Variable: thruster_dist2CG_RED
  //  Referenced by:
  //    '<S653>/MATLAB Function'
  //    '<S653>/MATLAB Function11'
  //    '<S653>/MATLAB Function3'
  //    '<S653>/MATLAB Function4'
  //    '<S653>/MATLAB Function6'
  //    '<S653>/MATLAB Function7'

  { 86.629636186598191, -39.370363813401788, 66.664291404797723,
    -64.835708595202249, 43.870363813401781, -85.629636186598219,
    62.335708595202249, -68.664291404797723 },

  // Variable: xLength
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

  3.51155,

  // Variable: yLength
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

  2.41935,

  // Expression: 428
  //  Referenced by: '<S25>/Set Pin 428 (Pucks) to HIGH'

  428.0,

  // Expression: 1
  //  Referenced by: '<S25>/Set Pin 428 (Pucks) to HIGH'

  1.0,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S579>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_a
  //  Referenced by: '<S580>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_g
  //  Referenced by: '<S581>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_gc
  //  Referenced by: '<S582>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_e
  //  Referenced by: '<S583>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_n
  //  Referenced by: '<S584>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_o
  //  Referenced by: '<S593>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_ow
  //  Referenced by: '<S594>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_as
  //  Referenced by: '<S595>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_ox
  //  Referenced by: '<S596>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_e3
  //  Referenced by: '<S597>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_i
  //  Referenced by: '<S598>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_b
  //  Referenced by: '<S608>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_asw
  //  Referenced by: '<S609>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_ea
  //  Referenced by: '<S610>/Out1'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S601>/Delay'

  0.0,

  // Computed Parameter: AccelerationtoVelocity_gainval
  //  Referenced by: '<S601>/Acceleration  to Velocity'

  0.01,

  // Expression: [drop_states_RED,drop_states_ARM,0,0,0,0,0,0]
  //  Referenced by: '<S601>/Acceleration  to Velocity'

  { 2.7, 0.4, -3.1415926535897931, 1.5707963267948966, 1.5707963267948966, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S601>/Random Number2'

  0.0,

  // Computed Parameter: RandomNumber2_StdDev
  //  Referenced by: '<S601>/Random Number2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S601>/Random Number2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S601>/Random Number1'

  0.0,

  // Computed Parameter: RandomNumber1_StdDev
  //  Referenced by: '<S601>/Random Number1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S601>/Random Number1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S601>/Random Number3'

  0.0,

  // Computed Parameter: RandomNumber3_StdDev
  //  Referenced by: '<S601>/Random Number3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S601>/Random Number3'

  0.0,

  // Computed Parameter: Out1_Y0_j
  //  Referenced by: '<S620>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_l
  //  Referenced by: '<S621>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S622>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_bf
  //  Referenced by: '<S623>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_gt
  //  Referenced by: '<S624>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_em
  //  Referenced by: '<S625>/Out1'

  0.0,

  // Computed Parameter: AccelerationtoVelocity_gainva_g
  //  Referenced by: '<S612>/Acceleration  to Velocity'

  0.01,

  // Expression: 0
  //  Referenced by: '<S612>/Acceleration  to Velocity'

  0.0,

  // Computed Parameter: VelocitytoPosition_gainval
  //  Referenced by: '<S612>/Velocity to Position'

  0.01,

  // Expression: 0
  //  Referenced by: '<S612>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S612>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S611>/Random Number7'

  0.0,

  // Computed Parameter: RandomNumber7_StdDev
  //  Referenced by: '<S611>/Random Number7'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S611>/Random Number7'

  0.0,

  // Expression: 0
  //  Referenced by: '<S611>/Random Number6'

  0.0,

  // Computed Parameter: RandomNumber6_StdDev
  //  Referenced by: '<S611>/Random Number6'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S611>/Random Number6'

  0.0,

  // Expression: 0
  //  Referenced by: '<S611>/Random Number8'

  0.0,

  // Computed Parameter: RandomNumber8_StdDev
  //  Referenced by: '<S611>/Random Number8'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S611>/Random Number8'

  0.0,

  // Computed Parameter: AccelerationtoVelocity_gainva_j
  //  Referenced by: '<S571>/Acceleration  to Velocity'

  0.01,

  // Expression: 0
  //  Referenced by: '<S571>/Acceleration  to Velocity'

  0.0,

  // Computed Parameter: VelocitytoPosition_gainval_n
  //  Referenced by: '<S571>/Velocity to Position'

  0.01,

  // Expression: 0
  //  Referenced by: '<S571>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S571>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S568>/Random Number1'

  0.0,

  // Computed Parameter: RandomNumber1_StdDev_e
  //  Referenced by: '<S568>/Random Number1'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S568>/Random Number1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S568>/Random Number'

  0.0,

  // Computed Parameter: RandomNumber_StdDev
  //  Referenced by: '<S568>/Random Number'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S568>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S568>/Random Number2'

  0.0,

  // Computed Parameter: RandomNumber2_StdDev_c
  //  Referenced by: '<S568>/Random Number2'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S568>/Random Number2'

  0.0,

  // Computed Parameter: AccelerationtoVelocity_gainva_p
  //  Referenced by: '<S585>/Acceleration  to Velocity'

  0.01,

  // Expression: 0
  //  Referenced by: '<S585>/Acceleration  to Velocity'

  0.0,

  // Computed Parameter: VelocitytoPosition_gainval_e
  //  Referenced by: '<S585>/Velocity to Position'

  0.01,

  // Expression: 0
  //  Referenced by: '<S585>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S585>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S569>/Random Number4'

  0.0,

  // Computed Parameter: RandomNumber4_StdDev
  //  Referenced by: '<S569>/Random Number4'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S569>/Random Number4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S569>/Random Number3'

  0.0,

  // Computed Parameter: RandomNumber3_StdDev_n
  //  Referenced by: '<S569>/Random Number3'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S569>/Random Number3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S569>/Random Number5'

  0.0,

  // Computed Parameter: RandomNumber5_StdDev
  //  Referenced by: '<S569>/Random Number5'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S569>/Random Number5'

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
  //  Referenced by: '<S545>/Out1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S545>/Memory'

  0.0,

  // Computed Parameter: Out1_Y0_ei
  //  Referenced by: '<S546>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_lf
  //  Referenced by: '<S547>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_f
  //  Referenced by: '<S548>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_m3
  //  Referenced by: '<S549>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_m34
  //  Referenced by: '<S550>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_h
  //  Referenced by: '<S551>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_o3
  //  Referenced by: '<S552>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S553>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_hp
  //  Referenced by: '<S554>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_p0
  //  Referenced by: '<S555>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_iy
  //  Referenced by: '<S556>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_c
  //  Referenced by: '<S557>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_d0
  //  Referenced by: '<S558>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_ck
  //  Referenced by: '<S559>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_ii
  //  Referenced by: '<S560>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_l2
  //  Referenced by: '<S561>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_nz
  //  Referenced by: '<S562>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_fr
  //  Referenced by: '<S563>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_e1
  //  Referenced by: '<S564>/Out1'

  0.0,

  // Expression: 1/1000
  //  Referenced by: '<S524>/Convert REDX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S524>/Convert BLUX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S524>/Convert BLAX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S524>/Convert BLAY from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S524>/Convert BLUY from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S524>/Convert REDY from [mm] to [m]'

  0.001,

  // Expression: 1
  //  Referenced by: '<S525>/Constant'

  1.0,

  // Expression: 400
  //  Referenced by: '<S566>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  400.0,

  // Expression: 0
  //  Referenced by: '<S566>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  0.0,

  // Expression: 200
  //  Referenced by: '<S566>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  200.0,

  // Expression: 3072
  //  Referenced by: '<S566>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  3072.0,

  // Expression: 1024
  //  Referenced by: '<S566>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  1024.0,

  // Expression: 0
  //  Referenced by: '<S566>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  0.0,

  // Expression: 850
  //  Referenced by: '<S566>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  850.0,

  // Expression: 400
  //  Referenced by: '<S566>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  400.0,

  // Expression: 100
  //  Referenced by: '<S566>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  100.0,

  // Expression: 50
  //  Referenced by: '<S566>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  50.0,

  // Expression: 0
  //  Referenced by: '<S566>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  0.0,

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

  // Expression: 0
  //  Referenced by: '<S93>/Constant'

  0.0,

  // Expression: 1
  //  Referenced by: '<S93>/Puck State'

  1.0,

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

  // Computed Parameter: Out1_Y0_ep
  //  Referenced by: '<S236>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_me
  //  Referenced by: '<S238>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_bg
  //  Referenced by: '<S240>/Out1'

  0.0,

  // Computed Parameter: StartPos_gainval_i
  //  Referenced by: '<S232>/Start Pos'

  0.01,

  // Expression: 1
  //  Referenced by: '<S232>/End Pos'

  1.0,

  // Expression: 0
  //  Referenced by: '<S232>/End Pos'

  0.0,

  // Expression: 0
  //  Referenced by: '<S232>/Switch'

  0.0,

  // Computed Parameter: StartPos_gainval_j
  //  Referenced by: '<S233>/Start Pos'

  0.01,

  // Expression: 1
  //  Referenced by: '<S233>/End Pos'

  1.0,

  // Expression: 0
  //  Referenced by: '<S233>/End Pos'

  0.0,

  // Expression: 0
  //  Referenced by: '<S233>/Switch'

  0.0,

  // Computed Parameter: StartPos_gainval_a
  //  Referenced by: '<S234>/Start Pos'

  0.01,

  // Expression: 1
  //  Referenced by: '<S234>/End Pos'

  1.0,

  // Expression: 0
  //  Referenced by: '<S234>/End Pos'

  0.0,

  // Expression: 0
  //  Referenced by: '<S234>/Switch'

  0.0,

  // Expression: 1
  //  Referenced by: '<S164>/Puck State'

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

  // Computed Parameter: Out1_Y0_ll
  //  Referenced by: '<S354>/Out1'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator4_gainval
  //  Referenced by: '<S360>/Discrete-Time Integrator4'

  0.01,

  // Computed Parameter: DiscreteTimeIntegrator5_gainval
  //  Referenced by: '<S360>/Discrete-Time Integrator5'

  0.01,

  // Computed Parameter: DiscreteTimeIntegrator2_gainval
  //  Referenced by: '<S360>/Discrete-Time Integrator2'

  0.01,

  // Computed Parameter: DiscreteTimeIntegrator3_gainval
  //  Referenced by: '<S360>/Discrete-Time Integrator3'

  0.01,

  // Computed Parameter: DiscreteTimeIntegrator1_gainval
  //  Referenced by: '<S360>/Discrete-Time Integrator1'

  0.01,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S360>/Discrete-Time Integrator'

  0.01,

  // Computed Parameter: Out1_Y0_bjy
  //  Referenced by: '<S368>/Out1'

  0.0,

  // Computed Parameter: u_Y0
  //  Referenced by: '<S368>/u'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S381>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S382>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S377>/Delay3'

  0.0,

  // Expression: [0;0;0]
  //  Referenced by: '<S376>/Delay'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<S376>/Delay1'

  { 0.0, 0.0, 0.0 },

  // Expression: 0.0
  //  Referenced by: '<S383>/Delay3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S379>/Delay3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S379>/Delay1'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S378>/Delay3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S378>/Delay1'

  0.0,

  // Expression: [0;0;0]
  //  Referenced by: '<S381>/Constant'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<S382>/Constant1'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S368>/Switch'

  0.0,

  // Computed Parameter: DesiredStates_Y0
  //  Referenced by: '<S371>/Desired States'

  0.0,

  // Expression: [0.004988]
  //  Referenced by: '<S371>/Discrete Transfer Fcn1'

  0.004988,

  // Expression: [1 -0.995]
  //  Referenced by: '<S371>/Discrete Transfer Fcn1'

  { 1.0, -0.995 },

  // Expression: 0
  //  Referenced by: '<S371>/Discrete Transfer Fcn1'

  0.0,

  // Computed Parameter: DesiredStates_Y0_g
  //  Referenced by: '<S370>/Desired States'

  0.0,

  // Expression: pi/2
  //  Referenced by: '<S352>/Constant4'

  1.5707963267948966,

  // Expression: pi/3
  //  Referenced by: '<S352>/Constant5'

  1.0471975511965976,

  // Expression: 0
  //  Referenced by: '<S352>/Constant6'

  0.0,

  // Expression: 1
  //  Referenced by: '<S352>/Constant7'

  1.0,

  // Expression: 3
  //  Referenced by: '<S369>/Constant'

  3.0,

  // Expression: 25
  //  Referenced by: '<S347>/Step'

  25.0,

  // Expression: 0
  //  Referenced by: '<S347>/Step'

  0.0,

  // Expression: 1
  //  Referenced by: '<S347>/Step'

  1.0,

  // Expression: 40
  //  Referenced by: '<S347>/Step1'

  40.0,

  // Expression: 0
  //  Referenced by: '<S347>/Step1'

  0.0,

  // Expression: 1
  //  Referenced by: '<S347>/Step1'

  1.0,

  // Expression: 60
  //  Referenced by: '<S347>/Step2'

  60.0,

  // Expression: 0
  //  Referenced by: '<S347>/Step2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S347>/Step2'

  1.0,

  // Expression: 0
  //  Referenced by: '<S247>/Constant1'

  0.0,

  // Expression: 1
  //  Referenced by: '<S247>/Puck State'

  1.0,

  // Expression: 0.0
  //  Referenced by: '<S369>/Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S520>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S520>/Constant4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S520>/Constant5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S520>/Puck State'

  0.0,

  // Expression: 0
  //  Referenced by: '<S522>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S522>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S522>/Constant2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S522>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S522>/Puck State'

  0.0,

  // Expression: -1
  //  Referenced by: '<S522>/Gain'

  -1.0,

  // Expression: 0.005
  //  Referenced by: '<S522>/Saturation'

  0.005,

  // Expression: -0.005
  //  Referenced by: '<S522>/Saturation'

  -0.005,

  // Computed Parameter: BLACKPWM_Y0
  //  Referenced by: '<S626>/BLACK PWM'

  0.0,

  // Expression: 1000
  //  Referenced by: '<S629>/Remove Negatives'

  1000.0,

  // Expression: 0
  //  Referenced by: '<S629>/Remove Negatives'

  0.0,

  // Computed Parameter: BLUEPWM_Y0
  //  Referenced by: '<S627>/BLUE PWM'

  0.0,

  // Expression: 1000
  //  Referenced by: '<S641>/Remove Negatives'

  1000.0,

  // Expression: 0
  //  Referenced by: '<S641>/Remove Negatives'

  0.0,

  // Computed Parameter: REDPWM_Y0
  //  Referenced by: '<S628>/RED PWM'

  0.0,

  // Expression: 1000
  //  Referenced by: '<S653>/Remove Negatives'

  1000.0,

  // Expression: 0
  //  Referenced by: '<S653>/Remove Negatives'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory2'

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
  //  Referenced by: '<S524>/UDP Receive1'

  31534,

  // Computed Parameter: Delay_InitialCondition_g
  //  Referenced by: '<S524>/Delay'

  0,

  // Computed Parameter: Delay1_InitialCondition_h
  //  Referenced by: '<S524>/Delay1'

  0,

  // Computed Parameter: Delay2_InitialCondition_j
  //  Referenced by: '<S524>/Delay2'

  0,

  // Computed Parameter: UDPReceive_Port
  //  Referenced by: '<S524>/UDP Receive'

  33001,

  // Computed Parameter: UDPReceive2_Port
  //  Referenced by: '<S524>/UDP Receive2'

  33002,

  // Computed Parameter: UDPReceive3_Port
  //  Referenced by: '<S524>/UDP Receive3'

  33003,

  // Computed Parameter: UDPSend_Port_d
  //  Referenced by: '<S567>/UDP Send'

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
    //  Referenced by: '<S521>/Constant3'

    0.0,

    // Expression: 0
    //  Referenced by: '<S521>/Constant4'

    0.0,

    // Expression: 0
    //  Referenced by: '<S521>/Constant5'

    0.0,

    // Expression: 0
    //  Referenced by: '<S521>/Puck State'

    0.0
  }
  ,

  // End of '<S12>/Change BLUE Behavior'

  // Start of '<Root>/Phase #5: Hold Home'
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S474>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_k
    //  Referenced by: '<S476>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_d
    //  Referenced by: '<S478>/Out1'

    0.0,

    // Expression: 1
    //  Referenced by: '<S466>/Puck State'

    1.0,

    // Computed Parameter: Out1_Y0_b
    //  Referenced by: '<S487>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_dv
    //  Referenced by: '<S489>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_p
    //  Referenced by: '<S491>/Out1'

    0.0,

    // Expression: 1
    //  Referenced by: '<S467>/Puck State'

    1.0,

    // Computed Parameter: Out1_Y0_b3
    //  Referenced by: '<S501>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_b1
    //  Referenced by: '<S503>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_ba
    //  Referenced by: '<S505>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_c
    //  Referenced by: '<S515>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_o
    //  Referenced by: '<S517>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_a
    //  Referenced by: '<S519>/Out1'

    0.0,

    // Expression: pi/2
    //  Referenced by: '<S499>/Constant1'

    1.5707963267948966,

    // Expression: 0
    //  Referenced by: '<S499>/Constant6'

    0.0,

    // Expression: 1
    //  Referenced by: '<S499>/Constant7'

    1.0,

    // Expression: 0
    //  Referenced by: '<S468>/Constant2'

    0.0,

    // Expression: 1
    //  Referenced by: '<S468>/Puck State'

    1.0
  }
  ,

  // End of '<Root>/Phase #5: Hold Home'

  // Start of '<Root>/Phase #4: Return Home'
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S420>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_k
    //  Referenced by: '<S422>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_d
    //  Referenced by: '<S424>/Out1'

    0.0,

    // Expression: 1
    //  Referenced by: '<S412>/Puck State'

    1.0,

    // Computed Parameter: Out1_Y0_b
    //  Referenced by: '<S433>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_dv
    //  Referenced by: '<S435>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_p
    //  Referenced by: '<S437>/Out1'

    0.0,

    // Expression: 1
    //  Referenced by: '<S413>/Puck State'

    1.0,

    // Computed Parameter: Out1_Y0_b3
    //  Referenced by: '<S447>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_b1
    //  Referenced by: '<S449>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_ba
    //  Referenced by: '<S451>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_c
    //  Referenced by: '<S461>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_o
    //  Referenced by: '<S463>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_a
    //  Referenced by: '<S465>/Out1'

    0.0,

    // Expression: pi/2
    //  Referenced by: '<S445>/Constant1'

    1.5707963267948966,

    // Expression: 0
    //  Referenced by: '<S445>/Constant6'

    0.0,

    // Expression: 1
    //  Referenced by: '<S445>/Constant7'

    1.0,

    // Expression: 0
    //  Referenced by: '<S414>/Constant2'

    0.0,

    // Expression: 1
    //  Referenced by: '<S414>/Puck State'

    1.0
  }
  ,

  // End of '<Root>/Phase #4: Return Home'

  // Start of '<S352>/Simulated Position Controller'
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S407>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_h
    //  Referenced by: '<S409>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_k
    //  Referenced by: '<S411>/Out1'

    0.0
  }
  ,

  // End of '<S352>/Simulated Position Controller'

  // Start of '<S349>/Target Finder'
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S355>/Out1'

    0.0,

    // Computed Parameter: PseudoDerivative_A
    //  Referenced by: '<S364>/Pseudo Derivative'

    -25.028,

    // Computed Parameter: PseudoDerivative_C
    //  Referenced by: '<S364>/Pseudo Derivative'

    -626.40078399999993,

    // Computed Parameter: PseudoDerivative_D
    //  Referenced by: '<S364>/Pseudo Derivative'

    25.028,

    // Computed Parameter: PseudoDerivative1_A
    //  Referenced by: '<S364>/Pseudo Derivative1'

    -25.028,

    // Computed Parameter: PseudoDerivative1_C
    //  Referenced by: '<S364>/Pseudo Derivative1'

    -626.40078399999993,

    // Computed Parameter: PseudoDerivative1_D
    //  Referenced by: '<S364>/Pseudo Derivative1'

    25.028,

    // Computed Parameter: PseudoDerivative2_A
    //  Referenced by: '<S364>/Pseudo Derivative2'

    -25.028,

    // Computed Parameter: PseudoDerivative2_C
    //  Referenced by: '<S364>/Pseudo Derivative2'

    -626.40078399999993,

    // Computed Parameter: PseudoDerivative2_D
    //  Referenced by: '<S364>/Pseudo Derivative2'

    25.028
  }
  ,

  // End of '<S349>/Target Finder'

  // Start of '<S349>/Target Tracker'
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S356>/Out1'

    0.0,

    // Computed Parameter: PseudoDerivative_A
    //  Referenced by: '<S366>/Pseudo Derivative'

    -25.028,

    // Computed Parameter: PseudoDerivative_C
    //  Referenced by: '<S366>/Pseudo Derivative'

    -626.40078399999993,

    // Computed Parameter: PseudoDerivative_D
    //  Referenced by: '<S366>/Pseudo Derivative'

    25.028,

    // Computed Parameter: PseudoDerivative1_A
    //  Referenced by: '<S366>/Pseudo Derivative1'

    -25.028,

    // Computed Parameter: PseudoDerivative1_C
    //  Referenced by: '<S366>/Pseudo Derivative1'

    -626.40078399999993,

    // Computed Parameter: PseudoDerivative1_D
    //  Referenced by: '<S366>/Pseudo Derivative1'

    25.028,

    // Computed Parameter: PseudoDerivative2_A
    //  Referenced by: '<S366>/Pseudo Derivative2'

    -25.028,

    // Computed Parameter: PseudoDerivative2_C
    //  Referenced by: '<S366>/Pseudo Derivative2'

    -626.40078399999993,

    // Computed Parameter: PseudoDerivative2_D
    //  Referenced by: '<S366>/Pseudo Derivative2'

    25.028
  }
  ,

  // End of '<S349>/Target Tracker'

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
    //  Referenced by: '<S219>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_p
    //  Referenced by: '<S221>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_j
    //  Referenced by: '<S223>/Out1'

    0.0,

    // Expression: 0.03490659
    //  Referenced by: '<S207>/Desired Rate '

    0.03490659,

    // Expression: 1
    //  Referenced by: '<S163>/Puck State'

    1.0
  }
  ,

  // End of '<S88>/Sub-Phase #3 '

  // Start of '<S88>/Sub-Phase #2 '
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S198>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_p
    //  Referenced by: '<S200>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_j
    //  Referenced by: '<S202>/Out1'

    0.0,

    // Expression: 0.03490659
    //  Referenced by: '<S186>/Desired Rate '

    0.03490659,

    // Expression: 1
    //  Referenced by: '<S162>/Puck State'

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
