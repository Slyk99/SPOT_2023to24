//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: APF_CTL_VIS_Obs_2023a_data.cpp
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
#include "APF_CTL_VIS_Obs_2023a.h"

// Block parameters (default storage)
P_APF_CTL_VIS_Obs_2023a_T APF_CTL_VIS_Obs_2023a_P = {
  // Variable: Att_Mode
  //  Referenced by: '<S378>/Constant2'

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

  { 1.3, 1.25, 4.9741883681838388 },

  // Variable: BLUE_ini
  //  Referenced by:
  //    '<S232>/Velocity'
  //    '<S232>/Start Pos'
  //    '<S233>/Velocity'
  //    '<S233>/Start Pos'
  //    '<S234>/Velocity'
  //    '<S234>/Start Pos'

  { 1.3, 1.25, 1.8325957145940461, 0.0, 0.0, -0.026179938779914945 },

  // Variable: Binv
  //  Referenced by:
  //    '<S382>/MATLAB Function'
  //    '<S392>/MATLAB Function1'

  { 12.0, 0.0, 0.0, 0.0, 12.0, 0.0, 0.0, 0.0, 0.19816 },

  // Variable: F_Black_X_nominal
  //  Referenced by:
  //    '<S639>/MATLAB Function11'
  //    '<S639>/MATLAB Function3'

  0.2196,

  // Variable: F_Black_Y_nominal
  //  Referenced by:
  //    '<S639>/MATLAB Function11'
  //    '<S639>/MATLAB Function3'

  0.2825,

  // Variable: F_Blue_X_nominal
  //  Referenced by:
  //    '<S651>/MATLAB Function1'
  //    '<S651>/MATLAB Function7'

  0.2196,

  // Variable: F_Blue_Y_nominal
  //  Referenced by:
  //    '<S651>/MATLAB Function1'
  //    '<S651>/MATLAB Function7'

  0.2825,

  // Variable: F_red_X_nominal
  //  Referenced by:
  //    '<S663>/MATLAB Function11'
  //    '<S663>/MATLAB Function4'
  //    '<S663>/MATLAB Function6'
  //    '<S663>/MATLAB Function7'

  0.2196,

  // Variable: F_red_Y_nominal
  //  Referenced by:
  //    '<S663>/MATLAB Function11'
  //    '<S663>/MATLAB Function4'
  //    '<S663>/MATLAB Function6'
  //    '<S663>/MATLAB Function7'

  0.2825,

  // Variable: F_thrusters_BLACK
  //  Referenced by: '<S639>/MATLAB Function'

  { 0.2196, 0.2196, 0.2825, 0.2825, 0.2196, 0.2196, 0.2825, 0.2825 },

  // Variable: F_thrusters_BLUE
  //  Referenced by: '<S651>/MATLAB Function'

  { 0.2196, 0.2196, 0.2825, 0.2825, 0.2196, 0.2196, 0.2825, 0.2825 },

  // Variable: F_thrusters_RED
  //  Referenced by:
  //    '<S663>/MATLAB Function'
  //    '<S663>/MATLAB Function3'

  { 0.2196, 0.2196, 0.2825, 0.2825, 0.2196, 0.2196, 0.2825, 0.2825 },

  // Variable: Gamma1_el
  //  Referenced by: '<S611>/Dynamics Model'

  0.12,

  // Variable: Gamma1_sh
  //  Referenced by: '<S611>/Dynamics Model'

  0.005,

  // Variable: Gamma1_wr
  //  Referenced by: '<S611>/Dynamics Model'

  0.025,

  // Variable: Gamma2_el
  //  Referenced by: '<S611>/Dynamics Model'

  5.0,

  // Variable: Gamma2_sh
  //  Referenced by: '<S611>/Dynamics Model'

  5.0,

  // Variable: Gamma2_wr
  //  Referenced by: '<S611>/Dynamics Model'

  5.0,

  // Variable: Gamma3_el
  //  Referenced by: '<S611>/Dynamics Model'

  10.0,

  // Variable: Gamma3_sh
  //  Referenced by: '<S611>/Dynamics Model'

  40.0,

  // Variable: Gamma3_wr
  //  Referenced by: '<S611>/Dynamics Model'

  40.0,

  // Variable: Gamma4_el
  //  Referenced by: '<S611>/Dynamics Model'

  0.039,

  // Variable: Gamma4_sh
  //  Referenced by: '<S611>/Dynamics Model'

  0.015,

  // Variable: Gamma4_wr
  //  Referenced by: '<S611>/Dynamics Model'

  0.029,

  // Variable: Gamma5_el
  //  Referenced by: '<S611>/Dynamics Model'

  800.0,

  // Variable: Gamma5_sh
  //  Referenced by: '<S611>/Dynamics Model'

  800.0,

  // Variable: Gamma5_wr
  //  Referenced by: '<S611>/Dynamics Model'

  800.0,

  // Variable: Gamma6_el
  //  Referenced by: '<S611>/Dynamics Model'

  1.0E-6,

  // Variable: Gamma6_sh
  //  Referenced by: '<S611>/Dynamics Model'

  0.005,

  // Variable: Gamma6_wr
  //  Referenced by: '<S611>/Dynamics Model'

  0.02,

  // Variable: H
  //  Referenced by:
  //    '<S355>/MATLAB Function2'
  //    '<S360>/MATLAB Function2'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 },

  // Variable: Hz
  //  Referenced by: '<S379>/Switch logic'

  0.01,

  // Variable: IBLACK
  //  Referenced by: '<S581>/MATLAB Function'

  0.19956537087503129,

  // Variable: IBLUE
  //  Referenced by: '<S595>/MATLAB Function'

  0.19609228544737417,

  // Variable: IDIST
  //  Referenced by: '<S611>/Inertia Function 1'

  0.003506,

  // Variable: IEE
  //  Referenced by: '<S611>/Inertia Function 1'

  0.000106,

  // Variable: IPROX
  //  Referenced by: '<S611>/Inertia Function 1'

  0.003704,

  // Variable: IRED
  //  Referenced by:
  //    '<S611>/Inertia Function 1'
  //    '<S622>/MATLAB Function'

  0.19816136536704418,

  // Variable: J
  //  Referenced by:
  //    '<S355>/MATLAB Function2'
  //    '<S360>/MATLAB Function2'

  0.20184,

  // Variable: K_a
  //  Referenced by:
  //    '<S382>/MATLAB Function'
  //    '<S392>/MATLAB Function1'

  { 2.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 3.5 },

  // Variable: Kd_elarm
  //  Referenced by:
  //    '<S78>/kd_elarm'
  //    '<S467>/kd_elarm'
  //    '<S521>/kd_elarm'
  //    '<S268>/kd_elarm'
  //    '<S301>/kd_elarm'
  //    '<S334>/kd_elarm'
  //    '<S413>/kd_elarm'

  0.8,

  // Variable: Kd_sharm
  //  Referenced by:
  //    '<S79>/kd_sharm'
  //    '<S468>/kd_sharm'
  //    '<S522>/kd_sharm'
  //    '<S269>/kd_sharm'
  //    '<S302>/kd_sharm'
  //    '<S335>/kd_sharm'
  //    '<S414>/kd_sharm'

  1.0,

  // Variable: Kd_tb
  //  Referenced by:
  //    '<S36>/kd_tb'
  //    '<S425>/kd_tb'
  //    '<S479>/kd_tb'
  //    '<S95>/kd_tb'
  //    '<S112>/kd_tb'
  //    '<S129>/kd_tb'
  //    '<S145>/kd_tb'

  1.2,

  // Variable: Kd_tblue
  //  Referenced by:
  //    '<S49>/kd_tb'
  //    '<S438>/kd_tb'
  //    '<S492>/kd_tb'
  //    '<S166>/kd_tb'
  //    '<S187>/kd_tb'
  //    '<S208>/kd_tb'
  //    '<S228>/kd_tb'

  1.2,

  // Variable: Kd_tr
  //  Referenced by:
  //    '<S62>/kd_tr'
  //    '<S451>/kd_tr'
  //    '<S505>/kd_tr'
  //    '<S248>/kd_tr'
  //    '<S281>/kd_tr'
  //    '<S314>/kd_tr'

  1.2,

  // Variable: Kd_wrarm
  //  Referenced by:
  //    '<S80>/kd_wrarm'
  //    '<S469>/kd_wrarm'
  //    '<S523>/kd_wrarm'
  //    '<S270>/kd_wrarm'
  //    '<S303>/kd_wrarm'
  //    '<S336>/kd_wrarm'
  //    '<S415>/kd_wrarm'

  0.6,

  // Variable: Kd_xb
  //  Referenced by:
  //    '<S37>/kd_xb'
  //    '<S426>/kd_xb'
  //    '<S480>/kd_xb'
  //    '<S96>/kd_xb'
  //    '<S113>/kd_xb'
  //    '<S130>/kd_xb'
  //    '<S146>/kd_xb'

  2.6,

  // Variable: Kd_xblue
  //  Referenced by:
  //    '<S50>/kd_xb'
  //    '<S439>/kd_xb'
  //    '<S493>/kd_xb'
  //    '<S167>/kd_xb'
  //    '<S188>/kd_xb'
  //    '<S209>/kd_xb'
  //    '<S229>/kd_xb'

  2.6,

  // Variable: Kd_xr
  //  Referenced by:
  //    '<S63>/kd_xr'
  //    '<S452>/kd_xr'
  //    '<S506>/kd_xr'
  //    '<S249>/kd_xr'
  //    '<S282>/kd_xr'
  //    '<S315>/kd_xr'

  2.6,

  // Variable: Kd_yb
  //  Referenced by:
  //    '<S38>/kd_yb'
  //    '<S427>/kd_yb'
  //    '<S481>/kd_yb'
  //    '<S97>/kd_yb'
  //    '<S114>/kd_yb'
  //    '<S131>/kd_yb'
  //    '<S147>/kd_yb'

  2.6,

  // Variable: Kd_yblue
  //  Referenced by:
  //    '<S51>/kd_yb'
  //    '<S440>/kd_yb'
  //    '<S494>/kd_yb'
  //    '<S168>/kd_yb'
  //    '<S189>/kd_yb'
  //    '<S210>/kd_yb'
  //    '<S230>/kd_yb'

  2.6,

  // Variable: Kd_yr
  //  Referenced by:
  //    '<S64>/kd_yr'
  //    '<S453>/kd_yr'
  //    '<S507>/kd_yr'
  //    '<S250>/kd_yr'
  //    '<S283>/kd_yr'
  //    '<S316>/kd_yr'

  2.6,

  // Variable: Kp_elarm
  //  Referenced by:
  //    '<S78>/kp_elarm'
  //    '<S467>/kp_elarm'
  //    '<S521>/kp_elarm'
  //    '<S268>/kp_elarm'
  //    '<S301>/kp_elarm'
  //    '<S334>/kp_elarm'
  //    '<S413>/kp_elarm'

  1.2,

  // Variable: Kp_sharm
  //  Referenced by:
  //    '<S79>/kp_sharm'
  //    '<S468>/kp_sharm'
  //    '<S522>/kp_sharm'
  //    '<S269>/kp_sharm'
  //    '<S302>/kp_sharm'
  //    '<S335>/kp_sharm'
  //    '<S414>/kp_sharm'

  1.5,

  // Variable: Kp_tb
  //  Referenced by:
  //    '<S36>/kp_tb'
  //    '<S425>/kp_tb'
  //    '<S479>/kp_tb'
  //    '<S95>/kp_tb'
  //    '<S112>/kp_tb'
  //    '<S129>/kp_tb'
  //    '<S145>/kp_tb'

  0.5,

  // Variable: Kp_tblue
  //  Referenced by:
  //    '<S49>/kp_tb'
  //    '<S438>/kp_tb'
  //    '<S492>/kp_tb'
  //    '<S166>/kp_tb'
  //    '<S187>/kp_tb'
  //    '<S208>/kp_tb'
  //    '<S228>/kp_tb'

  0.5,

  // Variable: Kp_tr
  //  Referenced by:
  //    '<S62>/kp_tr'
  //    '<S451>/kp_tr'
  //    '<S505>/kp_tr'
  //    '<S248>/kp_tr'
  //    '<S281>/kp_tr'
  //    '<S314>/kp_tr'

  0.5,

  // Variable: Kp_wrarm
  //  Referenced by:
  //    '<S80>/kp_wrarm'
  //    '<S469>/kp_wrarm'
  //    '<S523>/kp_wrarm'
  //    '<S270>/kp_wrarm'
  //    '<S303>/kp_wrarm'
  //    '<S336>/kp_wrarm'
  //    '<S415>/kp_wrarm'

  2.0,

  // Variable: Kp_xb
  //  Referenced by:
  //    '<S37>/kp_xb'
  //    '<S426>/kp_xb'
  //    '<S480>/kp_xb'
  //    '<S96>/kp_xb'
  //    '<S113>/kp_xb'
  //    '<S130>/kp_xb'
  //    '<S146>/kp_xb'

  1.0,

  // Variable: Kp_xblue
  //  Referenced by:
  //    '<S50>/kp_xb'
  //    '<S439>/kp_xb'
  //    '<S493>/kp_xb'
  //    '<S167>/kp_xb'
  //    '<S188>/kp_xb'
  //    '<S209>/kp_xb'
  //    '<S229>/kp_xb'

  1.0,

  // Variable: Kp_xr
  //  Referenced by:
  //    '<S63>/kp_xr'
  //    '<S452>/kp_xr'
  //    '<S506>/kp_xr'
  //    '<S249>/kp_xr'
  //    '<S282>/kp_xr'
  //    '<S315>/kp_xr'

  1.0,

  // Variable: Kp_yb
  //  Referenced by:
  //    '<S38>/kp_yb'
  //    '<S427>/kp_yb'
  //    '<S481>/kp_yb'
  //    '<S97>/kp_yb'
  //    '<S114>/kp_yb'
  //    '<S131>/kp_yb'
  //    '<S147>/kp_yb'

  1.0,

  // Variable: Kp_yblue
  //  Referenced by:
  //    '<S51>/kp_yb'
  //    '<S440>/kp_yb'
  //    '<S494>/kp_yb'
  //    '<S168>/kp_yb'
  //    '<S189>/kp_yb'
  //    '<S210>/kp_yb'
  //    '<S230>/kp_yb'

  1.0,

  // Variable: Kp_yr
  //  Referenced by:
  //    '<S64>/kp_yr'
  //    '<S453>/kp_yr'
  //    '<S507>/kp_yr'
  //    '<S250>/kp_yr'
  //    '<S283>/kp_yr'
  //    '<S316>/kp_yr'

  1.0,

  // Variable: Method
  //  Referenced by: '<S385>/Constant3'

  8.0,

  // Variable: Nmat
  //  Referenced by:
  //    '<S382>/MATLAB Function'
  //    '<S392>/MATLAB Function1'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  // Variable: PWMFreq
  //  Referenced by:
  //    '<S19>/PWM Frequency'
  //    '<S639>/MATLAB Function1'
  //    '<S651>/MATLAB Function2'
  //    '<S663>/MATLAB Function2'

  5.0,

  // Variable: P_IC_Black
  //  Referenced by: '<S355>/IC'

  { 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.2 },

  // Variable: P_IC_Blue
  //  Referenced by: '<S360>/IC'

  { 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.2 },

  // Variable: P_b
  //  Referenced by:
  //    '<S382>/MATLAB Function'
  //    '<S392>/MATLAB Function1'

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
  //    '<S388>/Constant'

  25.0,

  // Variable: Phase3_End
  //  Referenced by: '<Root>/Constant2'

  305.0,

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
  //    '<S405>/Constant1'

  25.0,

  // Variable: Phase3_SubPhase4_End
  //  Referenced by:
  //    '<S87>/Constant3'
  //    '<S88>/Constant3'
  //    '<S89>/Constant3'

  305.0,

  // Variable: Phase4_End
  //  Referenced by: '<Root>/Constant3'

  305.0,

  // Variable: Phase5_End
  //  Referenced by: '<Root>/Constant6'

  305.0,

  // Variable: Phi
  //  Referenced by:
  //    '<S663>/MATLAB Function'
  //    '<S663>/MATLAB Function4'
  //    '<S663>/MATLAB Function6'
  //    '<S611>/Coriolis Function1'
  //    '<S611>/Inertia Function 1'

  1.2788882640695929,

  // Variable: Q_Black
  //  Referenced by: '<S355>/MATLAB Function2'

  { 5.0E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5.0E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    5.0E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5.0E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    5.0E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5.0E-5 },

  // Variable: Q_Blue
  //  Referenced by: '<S360>/MATLAB Function2'

  { 7.5E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 7.5E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    5.0E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5.0E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    5.0E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5.0E-5 },

  // Variable: Q_a
  //  Referenced by:
  //    '<S382>/MATLAB Function'
  //    '<S392>/MATLAB Function1'

  { 5.0, 0.0, 0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0 },

  // Variable: Q_b
  //  Referenced by:
  //    '<S382>/MATLAB Function'
  //    '<S392>/MATLAB Function1'

  { 0.0125, 0.0, 0.0, 0.0, 0.0125, 0.0, 0.0, 0.0, 0.05 },

  // Variable: RED_ini
  //  Referenced by:
  //    '<S403>/Constant'
  //    '<S404>/Constant1'
  //    '<S404>/Constant2'
  //    '<S409>/Constant1'
  //    '<S409>/Constant2'

  { 2.7, 0.4, -3.1415926535897931, 0.0, 0.0, 0.0 },

  // Variable: RMSprop_epsilon
  //  Referenced by: '<S393>/MATLAB Function1'

  1.0E-8,

  // Variable: RMSprop_eta
  //  Referenced by: '<S393>/MATLAB Function1'

  0.025,

  // Variable: RMSprop_gamma
  //  Referenced by: '<S393>/MATLAB Function1'

  0.9,

  // Variable: R_Black
  //  Referenced by: '<S355>/MATLAB Function2'

  { 0.99, 0.0, 0.0, 0.0, 0.99, 0.0, 0.0, 0.0, 0.99 },

  // Variable: R_Blue
  //  Referenced by: '<S360>/MATLAB Function2'

  { 0.01, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 0.01 },

  // Variable: Red_Rate
  //  Referenced by: '<S403>/Desired Rate (RED)'

  0.025,

  // Variable: Time_Look
  //  Referenced by: '<S379>/Switch logic'

  25.0,

  // Variable: Tz_lim_elarm
  //  Referenced by:
  //    '<S77>/Saturation1'
  //    '<S466>/Saturation1'
  //    '<S520>/Saturation1'
  //    '<S267>/Saturation1'
  //    '<S300>/Saturation1'
  //    '<S333>/Saturation1'
  //    '<S412>/Saturation1'

  0.1,

  // Variable: Tz_lim_sharm
  //  Referenced by:
  //    '<S77>/Saturation'
  //    '<S466>/Saturation'
  //    '<S520>/Saturation'
  //    '<S267>/Saturation'
  //    '<S300>/Saturation'
  //    '<S333>/Saturation'
  //    '<S412>/Saturation'

  0.1,

  // Variable: Tz_lim_wrarm
  //  Referenced by:
  //    '<S77>/Saturation3'
  //    '<S466>/Saturation3'
  //    '<S520>/Saturation3'
  //    '<S267>/Saturation3'
  //    '<S300>/Saturation3'
  //    '<S333>/Saturation3'
  //    '<S412>/Saturation3'

  0.1,

  // Variable: a1
  //  Referenced by:
  //    '<S663>/MATLAB Function'
  //    '<S663>/MATLAB Function4'
  //    '<S663>/MATLAB Function6'
  //    '<S611>/Coriolis Function1'
  //    '<S611>/Inertia Function 1'

  0.3,

  // Variable: a2
  //  Referenced by:
  //    '<S663>/MATLAB Function'
  //    '<S663>/MATLAB Function4'
  //    '<S663>/MATLAB Function6'
  //    '<S611>/Coriolis Function1'
  //    '<S611>/Inertia Function 1'

  0.3,

  // Variable: a3
  //  Referenced by:
  //    '<S663>/MATLAB Function'
  //    '<S663>/MATLAB Function4'
  //    '<S663>/MATLAB Function6'
  //    '<S611>/Coriolis Function1'
  //    '<S611>/Inertia Function 1'

  0.4,

  // Variable: adadelta_epsilon
  //  Referenced by: '<S386>/MATLAB Function1'

  1.0E-5,

  // Variable: adadelta_gamma
  //  Referenced by: '<S386>/MATLAB Function1'

  0.37,

  // Variable: adagrad_epsilon
  //  Referenced by: '<S387>/MATLAB Function1'

  1.0E-8,

  // Variable: adagrad_eta
  //  Referenced by: '<S387>/MATLAB Function1'

  0.18,

  // Variable: adam_beta_1
  //  Referenced by: '<S389>/MATLAB Function1'

  0.99,

  // Variable: adam_beta_2
  //  Referenced by: '<S389>/MATLAB Function1'

  0.999,

  // Variable: adam_epsilon
  //  Referenced by: '<S389>/MATLAB Function1'

  0.01,

  // Variable: adam_eta
  //  Referenced by: '<S389>/MATLAB Function1'

  0.0163,

  // Variable: adamax_beta_1
  //  Referenced by: '<S388>/MATLAB Function1'

  0.5,

  // Variable: adamax_beta_2
  //  Referenced by: '<S388>/MATLAB Function1'

  0.999,

  // Variable: adamax_eta
  //  Referenced by: '<S388>/MATLAB Function1'

  0.014,

  // Variable: alpha_Black
  //  Referenced by: '<S355>/MATLAB Function2'

  0.9,

  // Variable: alpha_Blue
  //  Referenced by: '<S360>/MATLAB Function2'

  0.9,

  // Variable: b0
  //  Referenced by:
  //    '<S663>/MATLAB Function'
  //    '<S663>/MATLAB Function4'
  //    '<S663>/MATLAB Function6'
  //    '<S611>/Coriolis Function1'
  //    '<S611>/Inertia Function 1'

  0.25,

  // Variable: b1
  //  Referenced by:
  //    '<S663>/MATLAB Function'
  //    '<S663>/MATLAB Function4'
  //    '<S663>/MATLAB Function6'
  //    '<S611>/Coriolis Function1'
  //    '<S611>/Inertia Function 1'

  0.175,

  // Variable: b2
  //  Referenced by:
  //    '<S663>/MATLAB Function'
  //    '<S663>/MATLAB Function4'
  //    '<S663>/MATLAB Function6'
  //    '<S611>/Coriolis Function1'
  //    '<S611>/Inertia Function 1'

  0.175,

  // Variable: b3
  //  Referenced by:
  //    '<S663>/MATLAB Function'
  //    '<S663>/MATLAB Function4'
  //    '<S663>/MATLAB Function6'
  //    '<S611>/Inertia Function 1'

  0.025153,

  // Variable: baseRate
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

  0.01,

  // Variable: batch_eta
  //  Referenced by: '<S390>/Batch'

  0.25,

  // Variable: beta_Black
  //  Referenced by: '<S355>/MATLAB Function2'

  2.0,

  // Variable: beta_Blue
  //  Referenced by: '<S360>/MATLAB Function2'

  20.0,

  // Variable: delta
  //  Referenced by:
  //    '<S347>/Ryan's Transform'
  //    '<S348>/Ryan's Transform'

  2.0,

  // Variable: drop_states_BLACK
  //  Referenced by: '<S581>/Velocity to Position'

  { 1.75, 0.5, 3.2812189937493397 },

  // Variable: drop_states_BLUE
  //  Referenced by: '<S595>/Velocity to Position'

  { 1.3, 1.25, 1.8325957145940461 },

  // Variable: drop_states_RED
  //  Referenced by: '<S622>/Velocity to Position'

  { 2.7, 0.4, -3.1415926535897931 },

  // Variable: dt
  //  Referenced by:
  //    '<S355>/MATLAB Function2'
  //    '<S360>/MATLAB Function2'

  0.01,

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
  //    '<S422>/Desired Attitude (BLACK)'
  //    '<S422>/Desired Px (BLACK)'
  //    '<S422>/Desired Py (BLACK)'
  //    '<S476>/Desired Attitude (BLACK)'
  //    '<S476>/Desired Px (BLACK)'
  //    '<S476>/Desired Py (BLACK)'

  { 1.75, 0.5, 3.2812189937493397 },

  // Variable: home_states_BLUE
  //  Referenced by:
  //    '<S423>/Desired Attitude (BLUE)'
  //    '<S423>/Desired Px (BLUE)'
  //    '<S423>/Desired Py (BLUE)'
  //    '<S477>/Desired Attitude (BLUE)'
  //    '<S477>/Desired Px (BLUE)'
  //    '<S477>/Desired Py (BLUE)'

  { 1.3, 1.25, 1.8325957145940461 },

  // Variable: home_states_RED
  //  Referenced by:
  //    '<S424>/Desired Px (RED)'
  //    '<S424>/Desired Py (RED)'
  //    '<S424>/Desired Rz (RED)'
  //    '<S478>/Desired Px (RED)'
  //    '<S478>/Desired Py (RED)'
  //    '<S478>/Desired Rz (RED)'

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

  { 1.3, 1.25, 1.8325957145940461 },

  // Variable: init_states_RED
  //  Referenced by:
  //    '<S35>/Constant'
  //    '<S35>/Constant1'
  //    '<S35>/Constant3'

  { 2.7, 0.4, -3.1415926535897931 },

  // Variable: k
  //  Referenced by:
  //    '<S374>/Constant'
  //    '<S376>/Constant'

  { 3.8729833462074241, 7.3274719625260332E-15, 1.4031034209200205E-15,
    7.8891613745256441E-15, 3.8729833462074232, -1.1145622395159269E-17,
    -4.5079872316022321E-16, 5.0966384815908735E-16, 1.0000000000000036,
    82.689214446166972, -2.0781987242202149E-15, 1.9958640187946502E-15,
    2.3467763609000223E-14, 82.6892144461671, 1.0683955481494294E-14,
    -2.2423151955265392E-15, 2.7961454301515212E-15, 4.5162288173579288 },

  // Variable: k_1_0
  //  Referenced by:
  //    '<S370>/Discrete-Time Integrator3'
  //    '<S370>/Discrete-Time Integrator5'

  3.8729833462074241,

  // Variable: k_1_t_0
  //  Referenced by: '<S370>/Discrete-Time Integrator1'

  1.0000000000000036,

  // Variable: k_2_0
  //  Referenced by:
  //    '<S370>/Discrete-Time Integrator2'
  //    '<S370>/Discrete-Time Integrator4'

  82.689214446166972,

  // Variable: k_2_t_0
  //  Referenced by: '<S370>/Discrete-Time Integrator'

  4.5162288173579288,

  // Variable: ka
  //  Referenced by:
  //    '<S382>/MATLAB Function'
  //    '<S392>/MATLAB Function1'

  1.0,

  // Variable: kr
  //  Referenced by:
  //    '<S382>/MATLAB Function'
  //    '<S392>/MATLAB Function1'

  2.0,

  // Variable: lambda1
  //  Referenced by:
  //    '<S370>/Fx Gain Derivatives'
  //    '<S370>/Fy Gain Derivatives'

  0.4,

  // Variable: lambda12
  //  Referenced by:
  //    '<S370>/Fx Gain Derivatives'
  //    '<S370>/Fy Gain Derivatives'

  0.4,

  // Variable: lambda12_t
  //  Referenced by: '<S370>/Torque Gain Derivatives'

  0.05,

  // Variable: lambda1_t
  //  Referenced by: '<S370>/Torque Gain Derivatives'

  0.05,

  // Variable: lambda2
  //  Referenced by:
  //    '<S370>/Fx Gain Derivatives'
  //    '<S370>/Fy Gain Derivatives'

  0.4,

  // Variable: lambda2_t
  //  Referenced by: '<S370>/Torque Gain Derivatives'

  0.05,

  // Variable: lamda_Black
  //  Referenced by: '<S355>/MATLAB Function2'

  15.060000000000002,

  // Variable: lamda_Blue
  //  Referenced by: '<S360>/MATLAB Function2'

  6.9600000000000009,

  // Variable: m
  //  Referenced by:
  //    '<S355>/MATLAB Function2'
  //    '<S360>/MATLAB Function2'

  11.21,

  // Variable: mBLACK
  //  Referenced by: '<S581>/MATLAB Function'

  11.362,

  // Variable: mBLUE
  //  Referenced by: '<S595>/MATLAB Function'

  10.826,

  // Variable: mDIST
  //  Referenced by:
  //    '<S663>/MATLAB Function'
  //    '<S663>/MATLAB Function4'
  //    '<S663>/MATLAB Function6'
  //    '<S611>/Coriolis Function1'
  //    '<S611>/Inertia Function 1'

  0.335,

  // Variable: mEE
  //  Referenced by:
  //    '<S663>/MATLAB Function'
  //    '<S663>/MATLAB Function4'
  //    '<S663>/MATLAB Function6'
  //    '<S611>/Coriolis Function1'
  //    '<S611>/Inertia Function 1'

  0.111,

  // Variable: mPROX
  //  Referenced by:
  //    '<S663>/MATLAB Function'
  //    '<S663>/MATLAB Function4'
  //    '<S663>/MATLAB Function6'
  //    '<S611>/Coriolis Function1'
  //    '<S611>/Inertia Function 1'

  0.345,

  // Variable: mRED
  //  Referenced by:
  //    '<S663>/MATLAB Function'
  //    '<S663>/MATLAB Function4'
  //    '<S663>/MATLAB Function6'
  //    '<S611>/Inertia Function 1'
  //    '<S622>/MATLAB Function'

  11.296999999999999,

  // Variable: method
  //  Referenced by:
  //    '<S355>/MATLAB Function2'
  //    '<S360>/MATLAB Function2'

  1.0,

  // Variable: momentum_eta
  //  Referenced by: '<S391>/Momentum'

  0.7,

  // Variable: momentum_gamma
  //  Referenced by: '<S391>/Momentum'

  0.7,

  // Variable: nesterov_eta
  //  Referenced by: '<S392>/MATLAB Function1'

  0.6,

  // Variable: nesterov_gamma
  //  Referenced by: '<S392>/MATLAB Function1'

  0.3,

  // Variable: noise_variance_BLACK
  //  Referenced by: '<S581>/Random Number'

  0.0,

  // Variable: noise_variance_BLUE
  //  Referenced by: '<S595>/Random Number'

  0.0,

  // Variable: noise_variance_RED
  //  Referenced by: '<S622>/Random Number'

  0.0,

  // Variable: p
  //  Referenced by:
  //    '<S370>/Fx Gain Derivatives'
  //    '<S370>/Fy Gain Derivatives'

  0.4,

  // Variable: p_t
  //  Referenced by: '<S370>/Torque Gain Derivatives'

  0.05,

  // Variable: platformSelection
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

  8.0,

  // Variable: psi
  //  Referenced by:
  //    '<S382>/MATLAB Function'
  //    '<S392>/MATLAB Function1'

  1.0,

  // Variable: r_hold
  //  Referenced by:
  //    '<S382>/MATLAB Function'
  //    '<S392>/MATLAB Function1'

  0.427,

  // Variable: r_off
  //  Referenced by:
  //    '<S378>/Looking Angle'
  //    '<S382>/MATLAB Function'
  //    '<S408>/Looking Angle'
  //    '<S392>/MATLAB Function1'

  0.165,

  // Variable: shape
  //  Referenced by:
  //    '<S382>/MATLAB Function'
  //    '<S392>/MATLAB Function1'

  { 0.3, 0.3, 0.4, 0.175, 0.175 },

  // Variable: sigma
  //  Referenced by:
  //    '<S382>/MATLAB Function'
  //    '<S392>/MATLAB Function1'

  0.1,

  // Variable: simMode
  //  Referenced by: '<S18>/Constant'

  0.0,

  // Variable: thresh_Black
  //  Referenced by: '<S355>/MATLAB Function2'

  7.815,

  // Variable: thresh_Blue
  //  Referenced by: '<S360>/MATLAB Function2'

  2.0,

  // Variable: thresh_Factor_Black
  //  Referenced by: '<S355>/MATLAB Function2'

  0.1,

  // Variable: thresh_Factor_Blue
  //  Referenced by: '<S360>/MATLAB Function2'

  0.5,

  // Variable: thruster_count_threshold
  //  Referenced by:
  //    '<S639>/MATLAB Function10'
  //    '<S651>/MATLAB Function6'
  //    '<S663>/MATLAB Function5'

  0.0,

  // Variable: thruster_dist2CG_BLACK
  //  Referenced by:
  //    '<S639>/MATLAB Function'
  //    '<S639>/MATLAB Function11'
  //    '<S639>/MATLAB Function3'

  { 87.2054215807076, -50.794578419292378, 67.834888223904244,
    -73.665111776095742, 50.794578419292378, -79.6054215807076,
    68.165111776095742, -60.834888223904244 },

  // Variable: thruster_dist2CG_BLUE
  //  Referenced by:
  //    '<S651>/MATLAB Function'
  //    '<S651>/MATLAB Function1'
  //    '<S651>/MATLAB Function7'

  { 84.3010033444816, -53.698996655518386, 79.980637211758491,
    -61.519362788241494, 53.698996655518386, -76.7010033444816,
    56.019362788241487, -72.9806372117585 },

  // Variable: thruster_dist2CG_RED
  //  Referenced by:
  //    '<S663>/MATLAB Function'
  //    '<S663>/MATLAB Function11'
  //    '<S663>/MATLAB Function3'
  //    '<S663>/MATLAB Function4'
  //    '<S663>/MATLAB Function6'
  //    '<S663>/MATLAB Function7'

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
  //  Referenced by: '<S589>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_a
  //  Referenced by: '<S590>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_g
  //  Referenced by: '<S591>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_gc
  //  Referenced by: '<S592>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_e
  //  Referenced by: '<S593>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_n
  //  Referenced by: '<S594>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_o
  //  Referenced by: '<S603>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_ow
  //  Referenced by: '<S604>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_as
  //  Referenced by: '<S605>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_ox
  //  Referenced by: '<S606>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_e3
  //  Referenced by: '<S607>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_i
  //  Referenced by: '<S608>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_b
  //  Referenced by: '<S618>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_asw
  //  Referenced by: '<S619>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_ea
  //  Referenced by: '<S620>/Out1'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S611>/Delay'

  0.0,

  // Computed Parameter: AccelerationtoVelocity_gainval
  //  Referenced by: '<S611>/Acceleration  to Velocity'

  0.01,

  // Expression: [drop_states_RED,drop_states_ARM,0,0,0,0,0,0]
  //  Referenced by: '<S611>/Acceleration  to Velocity'

  { 2.7, 0.4, -3.1415926535897931, 1.5707963267948966, 1.5707963267948966, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S611>/Random Number2'

  0.0,

  // Computed Parameter: RandomNumber2_StdDev
  //  Referenced by: '<S611>/Random Number2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S611>/Random Number2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S611>/Random Number1'

  0.0,

  // Computed Parameter: RandomNumber1_StdDev
  //  Referenced by: '<S611>/Random Number1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S611>/Random Number1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S611>/Random Number3'

  0.0,

  // Computed Parameter: RandomNumber3_StdDev
  //  Referenced by: '<S611>/Random Number3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S611>/Random Number3'

  0.0,

  // Computed Parameter: Out1_Y0_j
  //  Referenced by: '<S630>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_l
  //  Referenced by: '<S631>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S632>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_bf
  //  Referenced by: '<S633>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_gt
  //  Referenced by: '<S634>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_em
  //  Referenced by: '<S635>/Out1'

  0.0,

  // Computed Parameter: AccelerationtoVelocity_gainva_g
  //  Referenced by: '<S622>/Acceleration  to Velocity'

  0.01,

  // Expression: 0
  //  Referenced by: '<S622>/Acceleration  to Velocity'

  0.0,

  // Computed Parameter: VelocitytoPosition_gainval
  //  Referenced by: '<S622>/Velocity to Position'

  0.01,

  // Expression: 0
  //  Referenced by: '<S622>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S622>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S621>/Random Number7'

  0.0,

  // Computed Parameter: RandomNumber7_StdDev
  //  Referenced by: '<S621>/Random Number7'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S621>/Random Number7'

  0.0,

  // Expression: 0
  //  Referenced by: '<S621>/Random Number6'

  0.0,

  // Computed Parameter: RandomNumber6_StdDev
  //  Referenced by: '<S621>/Random Number6'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S621>/Random Number6'

  0.0,

  // Expression: 0
  //  Referenced by: '<S621>/Random Number8'

  0.0,

  // Computed Parameter: RandomNumber8_StdDev
  //  Referenced by: '<S621>/Random Number8'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S621>/Random Number8'

  0.0,

  // Computed Parameter: AccelerationtoVelocity_gainva_j
  //  Referenced by: '<S581>/Acceleration  to Velocity'

  0.01,

  // Expression: 0
  //  Referenced by: '<S581>/Acceleration  to Velocity'

  0.0,

  // Computed Parameter: VelocitytoPosition_gainval_n
  //  Referenced by: '<S581>/Velocity to Position'

  0.01,

  // Expression: 0
  //  Referenced by: '<S581>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S581>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S578>/Random Number1'

  0.0,

  // Computed Parameter: RandomNumber1_StdDev_e
  //  Referenced by: '<S578>/Random Number1'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S578>/Random Number1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S578>/Random Number'

  0.0,

  // Computed Parameter: RandomNumber_StdDev
  //  Referenced by: '<S578>/Random Number'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S578>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S578>/Random Number2'

  0.0,

  // Computed Parameter: RandomNumber2_StdDev_c
  //  Referenced by: '<S578>/Random Number2'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S578>/Random Number2'

  0.0,

  // Computed Parameter: AccelerationtoVelocity_gainva_p
  //  Referenced by: '<S595>/Acceleration  to Velocity'

  0.01,

  // Expression: 0
  //  Referenced by: '<S595>/Acceleration  to Velocity'

  0.0,

  // Computed Parameter: VelocitytoPosition_gainval_e
  //  Referenced by: '<S595>/Velocity to Position'

  0.01,

  // Expression: 0
  //  Referenced by: '<S595>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S595>/Random Number'

  0.0,

  // Expression: 0
  //  Referenced by: '<S579>/Random Number4'

  0.0,

  // Computed Parameter: RandomNumber4_StdDev
  //  Referenced by: '<S579>/Random Number4'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S579>/Random Number4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S579>/Random Number3'

  0.0,

  // Computed Parameter: RandomNumber3_StdDev_n
  //  Referenced by: '<S579>/Random Number3'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S579>/Random Number3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S579>/Random Number5'

  0.0,

  // Computed Parameter: RandomNumber5_StdDev
  //  Referenced by: '<S579>/Random Number5'

  0.0012247448713915891,

  // Expression: 0
  //  Referenced by: '<S579>/Random Number5'

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
  //  Referenced by: '<S555>/Out1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S555>/Memory'

  0.0,

  // Computed Parameter: Out1_Y0_ei
  //  Referenced by: '<S556>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_lf
  //  Referenced by: '<S557>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_f
  //  Referenced by: '<S558>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_m3
  //  Referenced by: '<S559>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_m34
  //  Referenced by: '<S560>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_h
  //  Referenced by: '<S561>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_o3
  //  Referenced by: '<S562>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S563>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_hp
  //  Referenced by: '<S564>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_p0
  //  Referenced by: '<S565>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_iy
  //  Referenced by: '<S566>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_c
  //  Referenced by: '<S567>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_d0
  //  Referenced by: '<S568>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_ck
  //  Referenced by: '<S569>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_ii
  //  Referenced by: '<S570>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_l2
  //  Referenced by: '<S571>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_nz
  //  Referenced by: '<S572>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_fr
  //  Referenced by: '<S573>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_e1
  //  Referenced by: '<S574>/Out1'

  0.0,

  // Expression: 1/1000
  //  Referenced by: '<S534>/Convert REDX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S534>/Convert BLUX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S534>/Convert BLAX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S534>/Convert BLAY from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S534>/Convert BLUY from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S534>/Convert REDY from [mm] to [m]'

  0.001,

  // Expression: 1
  //  Referenced by: '<S535>/Constant'

  1.0,

  // Expression: 400
  //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  400.0,

  // Expression: 0
  //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  0.0,

  // Expression: 200
  //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  200.0,

  // Expression: 3072
  //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  3072.0,

  // Expression: 1024
  //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  1024.0,

  // Expression: 0
  //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  0.0,

  // Expression: 850
  //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  850.0,

  // Expression: 400
  //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  400.0,

  // Expression: 100
  //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  100.0,

  // Expression: 50
  //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  50.0,

  // Expression: 0
  //  Referenced by: '<S576>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

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

  // Computed Parameter: StartPos_gainval_a
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

  // Computed Parameter: Out1_Y0_ep
  //  Referenced by: '<S236>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_me
  //  Referenced by: '<S238>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_bg
  //  Referenced by: '<S240>/Out1'

  0.0,

  // Computed Parameter: StartPos_gainval_b
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

  // Computed Parameter: StartPos_gainval_i
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

  // Computed Parameter: StartPos_gainval_o
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
  //  Referenced by: '<S364>/Out1'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator4_gainval
  //  Referenced by: '<S370>/Discrete-Time Integrator4'

  0.01,

  // Computed Parameter: DiscreteTimeIntegrator5_gainval
  //  Referenced by: '<S370>/Discrete-Time Integrator5'

  0.01,

  // Computed Parameter: DiscreteTimeIntegrator2_gainval
  //  Referenced by: '<S370>/Discrete-Time Integrator2'

  0.01,

  // Computed Parameter: DiscreteTimeIntegrator3_gainval
  //  Referenced by: '<S370>/Discrete-Time Integrator3'

  0.01,

  // Computed Parameter: DiscreteTimeIntegrator1_gainval
  //  Referenced by: '<S370>/Discrete-Time Integrator1'

  0.01,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S370>/Discrete-Time Integrator'

  0.01,

  // Computed Parameter: Out1_Y0_bjy
  //  Referenced by: '<S378>/Out1'

  0.0,

  // Computed Parameter: u_Y0
  //  Referenced by: '<S378>/u'

  0.0,

  // Expression: [0;0;0]
  //  Referenced by: '<S386>/Delay'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<S386>/Delay1'

  { 0.0, 0.0, 0.0 },

  // Expression: 0.0
  //  Referenced by: '<S387>/Delay3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S388>/Delay1'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S388>/Delay3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S389>/Delay1'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S389>/Delay3'

  0.0,

  // Expression: [0;0;0]
  //  Referenced by: '<S391>/Constant'

  { 0.0, 0.0, 0.0 },

  // Expression: 0.0
  //  Referenced by: '<S391>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S392>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S393>/Delay3'

  0.0,

  // Expression: [0;0;0]
  //  Referenced by: '<S392>/Constant1'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S378>/Switch'

  0.0,

  // Computed Parameter: DesiredStates_Y0
  //  Referenced by: '<S381>/Desired States'

  0.0,

  // Expression: [0.004988]
  //  Referenced by: '<S381>/Discrete Transfer Fcn1'

  0.004988,

  // Expression: [1 -0.995]
  //  Referenced by: '<S381>/Discrete Transfer Fcn1'

  { 1.0, -0.995 },

  // Expression: 0
  //  Referenced by: '<S381>/Discrete Transfer Fcn1'

  0.0,

  // Computed Parameter: DesiredStates_Y0_g
  //  Referenced by: '<S380>/Desired States'

  0.0,

  // Expression: -1
  //  Referenced by: '<S403>/Gain'

  -1.0,

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

  // Expression: 0.0
  //  Referenced by: '<S354>/Delay'

  0.0,

  // Expression: [0;0;0]
  //  Referenced by: '<S355>/Constant'

  { 0.0, 0.0, 0.0 },

  // Expression: 0.0
  //  Referenced by: '<S355>/Delay1'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S355>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S355>/Delay3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S355>/Delay2'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S379>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S359>/Delay'

  0.0,

  // Expression: [0;0;0]
  //  Referenced by: '<S360>/Constant'

  { 0.0, 0.0, 0.0 },

  // Expression: 0.0
  //  Referenced by: '<S360>/Delay1'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S360>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S360>/Delay3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S360>/Delay2'

  0.0,

  // Expression: 90
  //  Referenced by: '<S360>/Step'

  90.0,

  // Expression: 0
  //  Referenced by: '<S360>/Step'

  0.0,

  // Expression: 1
  //  Referenced by: '<S360>/Step'

  1.0,

  // Expression: 0
  //  Referenced by: '<S247>/Constant1'

  0.0,

  // Expression: 1
  //  Referenced by: '<S247>/Puck State'

  1.0,

  // Expression: 0
  //  Referenced by: '<S530>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S530>/Constant4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S530>/Constant5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S530>/Puck State'

  0.0,

  // Expression: 0
  //  Referenced by: '<S532>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S532>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S532>/Constant2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S532>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S532>/Puck State'

  0.0,

  // Expression: -1
  //  Referenced by: '<S532>/Gain'

  -1.0,

  // Expression: 0.005
  //  Referenced by: '<S532>/Saturation'

  0.005,

  // Expression: -0.005
  //  Referenced by: '<S532>/Saturation'

  -0.005,

  // Computed Parameter: BLACKPWM_Y0
  //  Referenced by: '<S636>/BLACK PWM'

  0.0,

  // Expression: 1000
  //  Referenced by: '<S639>/Remove Negatives'

  1000.0,

  // Expression: 0
  //  Referenced by: '<S639>/Remove Negatives'

  0.0,

  // Computed Parameter: BLUEPWM_Y0
  //  Referenced by: '<S637>/BLUE PWM'

  0.0,

  // Expression: 1000
  //  Referenced by: '<S651>/Remove Negatives'

  1000.0,

  // Expression: 0
  //  Referenced by: '<S651>/Remove Negatives'

  0.0,

  // Computed Parameter: REDPWM_Y0
  //  Referenced by: '<S638>/RED PWM'

  0.0,

  // Expression: 1000
  //  Referenced by: '<S663>/Remove Negatives'

  1000.0,

  // Expression: 0
  //  Referenced by: '<S663>/Remove Negatives'

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
  //  Referenced by: '<Root>/BLACK_Px4'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Px5'

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
  //  Referenced by: '<Root>/BLACK_Py4'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Py5'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Py6'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Py7'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Py8'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/BLACK_Py9'

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
  //  Referenced by: '<Root>/RED_dRz_RW Sat13'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_dRz_RW Sat14'

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
  //  Referenced by: '<S534>/UDP Receive1'

  31534,

  // Computed Parameter: Delay_InitialCondition_g
  //  Referenced by: '<S534>/Delay'

  0,

  // Computed Parameter: Delay1_InitialCondition_h
  //  Referenced by: '<S534>/Delay1'

  0,

  // Computed Parameter: Delay2_InitialCondition_j
  //  Referenced by: '<S534>/Delay2'

  0,

  // Computed Parameter: UDPReceive_Port
  //  Referenced by: '<S534>/UDP Receive'

  33001,

  // Computed Parameter: UDPReceive2_Port
  //  Referenced by: '<S534>/UDP Receive2'

  33002,

  // Computed Parameter: UDPReceive3_Port
  //  Referenced by: '<S534>/UDP Receive3'

  33003,

  // Computed Parameter: UDPSend_Port_d
  //  Referenced by: '<S577>/UDP Send'

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
    //  Referenced by: '<S531>/Constant3'

    0.0,

    // Expression: 0
    //  Referenced by: '<S531>/Constant4'

    0.0,

    // Expression: 0
    //  Referenced by: '<S531>/Constant5'

    0.0,

    // Expression: 0
    //  Referenced by: '<S531>/Puck State'

    0.0
  }
  ,

  // End of '<S12>/Change BLUE Behavior'

  // Start of '<Root>/Phase #5: Hold Home'
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S497>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_d
    //  Referenced by: '<S499>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_p
    //  Referenced by: '<S501>/Out1'

    0.0,

    // Expression: 1
    //  Referenced by: '<S477>/Puck State'

    1.0,

    // Computed Parameter: Out1_Y0_o
    //  Referenced by: '<S484>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_k
    //  Referenced by: '<S486>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_dj
    //  Referenced by: '<S488>/Out1'

    0.0,

    // Expression: 1
    //  Referenced by: '<S476>/Puck State'

    1.0,

    // Computed Parameter: Out1_Y0_b
    //  Referenced by: '<S511>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_b1
    //  Referenced by: '<S513>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_ba
    //  Referenced by: '<S515>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_c
    //  Referenced by: '<S525>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_o0
    //  Referenced by: '<S527>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_a
    //  Referenced by: '<S529>/Out1'

    0.0,

    // Expression: pi/2
    //  Referenced by: '<S509>/Constant1'

    1.5707963267948966,

    // Expression: 0
    //  Referenced by: '<S509>/Constant6'

    0.0,

    // Expression: 1
    //  Referenced by: '<S509>/Constant7'

    1.0,

    // Expression: 0
    //  Referenced by: '<S478>/Constant2'

    0.0,

    // Expression: 1
    //  Referenced by: '<S478>/Puck State'

    1.0
  }
  ,

  // End of '<Root>/Phase #5: Hold Home'

  // Start of '<Root>/Phase #4: Return Home'
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S443>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_d
    //  Referenced by: '<S445>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_p
    //  Referenced by: '<S447>/Out1'

    0.0,

    // Expression: 1
    //  Referenced by: '<S423>/Puck State'

    1.0,

    // Computed Parameter: Out1_Y0_o
    //  Referenced by: '<S430>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_k
    //  Referenced by: '<S432>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_dj
    //  Referenced by: '<S434>/Out1'

    0.0,

    // Expression: 1
    //  Referenced by: '<S422>/Puck State'

    1.0,

    // Computed Parameter: Out1_Y0_b
    //  Referenced by: '<S457>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_b1
    //  Referenced by: '<S459>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_ba
    //  Referenced by: '<S461>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_c
    //  Referenced by: '<S471>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_o0
    //  Referenced by: '<S473>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_a
    //  Referenced by: '<S475>/Out1'

    0.0,

    // Expression: pi/2
    //  Referenced by: '<S455>/Constant1'

    1.5707963267948966,

    // Expression: 0
    //  Referenced by: '<S455>/Constant6'

    0.0,

    // Expression: 1
    //  Referenced by: '<S455>/Constant7'

    1.0,

    // Expression: 0
    //  Referenced by: '<S424>/Constant2'

    0.0,

    // Expression: 1
    //  Referenced by: '<S424>/Puck State'

    1.0
  }
  ,

  // End of '<Root>/Phase #4: Return Home'

  // Start of '<S352>/Simulated Position Controller'
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S417>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_h
    //  Referenced by: '<S419>/Out1'

    0.0,

    // Computed Parameter: Out1_Y0_k
    //  Referenced by: '<S421>/Out1'

    0.0
  }
  ,

  // End of '<S352>/Simulated Position Controller'

  // Start of '<S349>/Target Finder'
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S365>/Out1'

    0.0,

    // Computed Parameter: PseudoDerivative_A
    //  Referenced by: '<S374>/Pseudo Derivative'

    -25.028,

    // Computed Parameter: PseudoDerivative_C
    //  Referenced by: '<S374>/Pseudo Derivative'

    -626.40078399999993,

    // Computed Parameter: PseudoDerivative_D
    //  Referenced by: '<S374>/Pseudo Derivative'

    25.028,

    // Computed Parameter: PseudoDerivative1_A
    //  Referenced by: '<S374>/Pseudo Derivative1'

    -25.028,

    // Computed Parameter: PseudoDerivative1_C
    //  Referenced by: '<S374>/Pseudo Derivative1'

    -626.40078399999993,

    // Computed Parameter: PseudoDerivative1_D
    //  Referenced by: '<S374>/Pseudo Derivative1'

    25.028,

    // Computed Parameter: PseudoDerivative2_A
    //  Referenced by: '<S374>/Pseudo Derivative2'

    -25.028,

    // Computed Parameter: PseudoDerivative2_C
    //  Referenced by: '<S374>/Pseudo Derivative2'

    -626.40078399999993,

    // Computed Parameter: PseudoDerivative2_D
    //  Referenced by: '<S374>/Pseudo Derivative2'

    25.028
  }
  ,

  // End of '<S349>/Target Finder'

  // Start of '<S349>/Target Tracker'
  {
    // Computed Parameter: Out1_Y0
    //  Referenced by: '<S366>/Out1'

    0.0,

    // Computed Parameter: PseudoDerivative_A
    //  Referenced by: '<S376>/Pseudo Derivative'

    -25.028,

    // Computed Parameter: PseudoDerivative_C
    //  Referenced by: '<S376>/Pseudo Derivative'

    -626.40078399999993,

    // Computed Parameter: PseudoDerivative_D
    //  Referenced by: '<S376>/Pseudo Derivative'

    25.028,

    // Computed Parameter: PseudoDerivative1_A
    //  Referenced by: '<S376>/Pseudo Derivative1'

    -25.028,

    // Computed Parameter: PseudoDerivative1_C
    //  Referenced by: '<S376>/Pseudo Derivative1'

    -626.40078399999993,

    // Computed Parameter: PseudoDerivative1_D
    //  Referenced by: '<S376>/Pseudo Derivative1'

    25.028,

    // Computed Parameter: PseudoDerivative2_A
    //  Referenced by: '<S376>/Pseudo Derivative2'

    -25.028,

    // Computed Parameter: PseudoDerivative2_C
    //  Referenced by: '<S376>/Pseudo Derivative2'

    -626.40078399999993,

    // Computed Parameter: PseudoDerivative2_D
    //  Referenced by: '<S376>/Pseudo Derivative2'

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
