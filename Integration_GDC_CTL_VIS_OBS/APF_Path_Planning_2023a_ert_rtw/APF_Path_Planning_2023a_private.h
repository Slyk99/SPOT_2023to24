//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: APF_Path_Planning_2023a_private.h
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
#ifndef RTW_HEADER_APF_Path_Planning_2023a_private_h_
#define RTW_HEADER_APF_Path_Planning_2023a_private_h_
#include "rtwtypes.h"
#include "APF_Path_Planning_2023a.h"
#include "APF_Path_Planning_2023a_types.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void APF_Pa_ChangeBLACKBehavior_Init(RT_MODEL_APF_Path_Planning_20_T *
  const APF_Path_Planning_2023a_M, DW_ChangeBLACKBehavior_APF_Pa_T *localDW,
  P_ChangeBLACKBehavior_APF_Pat_T *localP);
extern void APF_Path_Pl_ChangeBLACKBehavior(RT_MODEL_APF_Path_Planning_20_T *
  const APF_Path_Planning_2023a_M, DW_ChangeBLACKBehavior_APF_Pa_T *localDW,
  P_ChangeBLACKBehavior_APF_Pat_T *localP);
extern void APF_Path_Pla_ChangeBLUEBehavior(RT_MODEL_APF_Path_Planning_20_T *
  const APF_Path_Planning_2023a_M, real_T *rtd_BLUE_Fx, real_T *rtd_BLUE_Fy,
  real_T *rtd_BLUE_Tz, real_T *rtd_Float_State, P_ChangeBLUEBehavior_APF_Path_T *
  localP);
extern void APF__Phase0Synchronization_Init(DW_Phase0Synchronization_APF__T
  *localDW);
extern void APF_Path__Phase0Synchronization(RT_MODEL_APF_Path_Planning_20_T *
  const APF_Path_Planning_2023a_M, real_T *rtd_BLACK_Fx, real_T *rtd_BLACK_Fy,
  real_T *rtd_BLACK_Tz, real_T *rtd_BLUE_Fx, real_T *rtd_BLUE_Fy, real_T
  *rtd_BLUE_Tz, real_T *rtd_Float_State, real_T *rtd_RED_ARM_Control_Mode,
  real_T *rtd_RED_Fx, real_T *rtd_RED_Fy, real_T *rtd_RED_Tz, real_T
  *rtd_RED_Tz_RW, const real_T *rtd_WhoAmI, const real_T *rtd_isSim,
  DW_Phase0Synchronization_APF__T *localDW, P_Phase0Synchronization_APF_P_T
  *localP);
extern void APF_Path_Planni_MATLABFunction2(real_T rtu_z, real_T rty_Oy[2],
  real_T rty_Ox[2]);
extern void APF_Path_Planni_MATLABFunction3(real_T rtu_z, real_T rty_Ox[2]);
extern void APF_Path_Planni_MATLABFunction4(const real_T rtu_Oy[2], const real_T
  rtu_e_in[2], real_T *rty_e_out);
extern void SimulatedPositionControlle_Init(B_SimulatedPositionController_T
  *localB, DW_SimulatedPositionControlle_T *localDW,
  P_SimulatedPositionController_T *localP);
extern void APF_SimulatedPositionController(real_T rtu_q1_desired, real_T
  rtu_q2_desired, real_T rtu_q3_desired, real_T *rty_q1_command, real_T
  *rty_q2_command, real_T *rty_q3_command, const real_T *rtd_RED_Rz_Elbow, const
  real_T *rtd_RED_Rz_Shoulder, const real_T *rtd_RED_Rz_Wrist,
  B_SimulatedPositionController_T *localB, DW_SimulatedPositionControlle_T
  *localDW);
extern void APF_Pa_PassthroughforExperiment(real_T rtu_q1_desired, real_T
  rtu_q2_desired, real_T rtu_q3_desired, real_T *rty_q1_command, real_T
  *rty_q2_command, real_T *rty_q3_command);
extern void APF_Path_Planning_2_REDARM_Init(B_REDARM_APF_Path_Planning_20_T
  *localB, DW_REDARM_APF_Path_Planning_2_T *localDW,
  P_REDARM_APF_Path_Planning_20_T *localP);
extern void APF_Path_Planning_2023a_REDARM(real_T *rtd_RED_ARM_Control_Mode,
  real_T *rtd_RED_Elbow_Command, const real_T *rtd_RED_Rz_Elbow, const real_T
  *rtd_RED_Rz_Shoulder, const real_T *rtd_RED_Rz_Wrist, real_T
  *rtd_RED_Shoulder_Command, real_T *rtd_RED_Wrist_Command, const real_T
  *rtd_isSim, B_REDARM_APF_Path_Planning_20_T *localB,
  DW_REDARM_APF_Path_Planning_2_T *localDW, P_REDARM_APF_Path_Planning_20_T
  *localP);
extern void APF_Path_Plannin_MATLABFunction(real_T rtu_u, real_T
  *rty_wrappedAngle);
extern void APF_Path_Plannin_SubPhase1_Init(B_SubPhase1_APF_Path_Planning_T
  *localB, DW_SubPhase1_APF_Path_Plannin_T *localDW,
  P_SubPhase1_APF_Path_Planning_T *localP);
extern void APF_Path_Plann_SubPhase1_Update(RT_MODEL_APF_Path_Planning_20_T *
  const APF_Path_Planning_2023a_M, B_SubPhase1_APF_Path_Planning_T *localB,
  DW_SubPhase1_APF_Path_Plannin_T *localDW);
extern void APF_Path_Planning_202_SubPhase1(RT_MODEL_APF_Path_Planning_20_T *
  const APF_Path_Planning_2023a_M, real_T *rtd_BLACK_Fx, real_T *rtd_BLACK_Fy,
  const real_T *rtd_BLACK_Px, const real_T *rtd_BLACK_Py, const real_T
  *rtd_BLACK_Rz, real_T *rtd_BLACK_Tz, real_T *rtd_Float_State, const real_T
  *rtd_Univ_Time, B_SubPhase1_APF_Path_Planning_T *localB,
  DW_SubPhase1_APF_Path_Plannin_T *localDW, P_SubPhase1_APF_Path_Planning_T
  *localP);
extern void APF_Path_Plann_SubPhase1_p_Init(B_SubPhase1_APF_Path_Planni_n_T
  *localB, DW_SubPhase1_APF_Path_Plann_o_T *localDW,
  P_SubPhase1_APF_Path_Planni_a_T *localP);
extern void APF_Path_Pla_SubPhase1_f_Update(RT_MODEL_APF_Path_Planning_20_T *
  const APF_Path_Planning_2023a_M, B_SubPhase1_APF_Path_Planni_n_T *localB,
  DW_SubPhase1_APF_Path_Plann_o_T *localDW);
extern void APF_Path_Planning_2_SubPhase1_g(RT_MODEL_APF_Path_Planning_20_T *
  const APF_Path_Planning_2023a_M, real_T *rtd_BLUE_Fx, real_T *rtd_BLUE_Fy,
  const real_T *rtd_BLUE_Px, const real_T *rtd_BLUE_Py, const real_T
  *rtd_BLUE_Rz, real_T *rtd_BLUE_Tz, real_T *rtd_Float_State, const real_T
  *rtd_Univ_Time, B_SubPhase1_APF_Path_Planni_n_T *localB,
  DW_SubPhase1_APF_Path_Plann_o_T *localDW, P_SubPhase1_APF_Path_Planni_a_T
  *localP);
extern void APF_Path_Plann_MATLABFunction_o(real_T rtu_t, real_T *rty_x);
extern void APF_Path_Planni_MATLABFunction1(real_T rtu_t, real_T *rty_y);
extern void APF_Path_Plann_SubPhase1_k_Init(B_SubPhase1_APF_Path_Planni_i_T
  *localB, DW_SubPhase1_APF_Path_Plann_m_T *localDW,
  P_SubPhase1_APF_Path_Planni_h_T *localP);
extern void APF_Path_Pla_SubPhase1_e_Update(RT_MODEL_APF_Path_Planning_20_T *
  const APF_Path_Planning_2023a_M, B_SubPhase1_APF_Path_Planni_i_T *localB,
  DW_SubPhase1_APF_Path_Plann_m_T *localDW);
extern void APF_Path_Planning_2_SubPhase1_p(RT_MODEL_APF_Path_Planning_20_T *
  const APF_Path_Planning_2023a_M, real_T *rtd_Float_State, real_T
  *rtd_RED_ARM_Control_Mode, real_T *rtd_RED_Elbow_Command, real_T *rtd_RED_Fx,
  real_T *rtd_RED_Fy, const real_T *rtd_RED_Px, const real_T *rtd_RED_Py, const
  real_T *rtd_RED_Rz, const real_T *rtd_RED_Rz_Elbow, const real_T
  *rtd_RED_Rz_Shoulder, const real_T *rtd_RED_Rz_Wrist, real_T
  *rtd_RED_Shoulder_Command, real_T *rtd_RED_Tz, real_T *rtd_RED_Tz_RW, real_T
  *rtd_RED_Wrist_Command, const real_T *rtd_Univ_Time, const real_T *rtd_isSim,
  B_SubPhase1_APF_Path_Planni_i_T *localB, DW_SubPhase1_APF_Path_Plann_m_T
  *localDW, P_SubPhase1_APF_Path_Planni_h_T *localP);
extern void APF_Path_Pla_TargetTracker_Init(real_T rty_Out1[3],
  P_TargetTracker_APF_Path_Plan_T *localP, X_TargetTracker_APF_Path_Plan_T
  *localX);
extern void APF_Path_Pl_TargetTracker_Deriv(real_T rtu_e_x, real_T rtu_e_y,
  real_T rtu_e_t, P_TargetTracker_APF_Path_Plan_T *localP,
  X_TargetTracker_APF_Path_Plan_T *localX, XDot_TargetTracker_APF_Path_P_T
  *localXdot);
extern void APF_Path_Planning_TargetTracker(real_T rtu_e_x, real_T rtu_e_y,
  real_T rtu_e_t, real_T rty_Out1[3], P_TargetTracker_APF_Path_Plan_T *localP,
  X_TargetTracker_APF_Path_Plan_T *localX);
extern void APF_Path__Phase4ReturnHome_Init(B_Phase4ReturnHome_APF_Path_P_T
  *localB, DW_Phase4ReturnHome_APF_Path__T *localDW,
  P_Phase4ReturnHome_APF_Path_P_T *localP);
extern void APF_Pat_Phase4ReturnHome_Update(RT_MODEL_APF_Path_Planning_20_T *
  const APF_Path_Planning_2023a_M, B_Phase4ReturnHome_APF_Path_P_T *localB,
  DW_Phase4ReturnHome_APF_Path__T *localDW);
extern void APF_Path_Plann_Phase4ReturnHome(RT_MODEL_APF_Path_Planning_20_T *
  const APF_Path_Planning_2023a_M, real_T *rtd_BLACK_Fx, real_T *rtd_BLACK_Fy,
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
  *localDW, P_Phase4ReturnHome_APF_Path_P_T *localP);
extern void APF_Path_Plan_MATLABFunction1_l(const real_T rtu_ThrustPer[8],
  real_T rty_ThrustPer_Final[8]);
extern void APF_Path_Plann_MATLABFunction10(const real_T rtu_PWMs[8], real_T
  *rty_thrust_decay_factor, real_T *rty_count, B_MATLABFunction10_APF_Path_P_T
  *localB);
extern void APF_Path_P_CreateRotationMatrix(real_T rtu_Rz, real_T rty_C_Ib[4]);
extern void APF_Path_CreateRotationMatrix_g(real_T rtu_Rz, real_T rty_C_bI[4]);
extern void APF_Pa_ChangeBLACKBehavior_Term(RT_MODEL_APF_Path_Planning_20_T *
  const APF_Path_Planning_2023a_M, DW_ChangeBLACKBehavior_APF_Pa_T *localDW);

// private model entry point functions
extern void APF_Path_Planning_2023a_derivatives(void);

#endif                         // RTW_HEADER_APF_Path_Planning_2023a_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
