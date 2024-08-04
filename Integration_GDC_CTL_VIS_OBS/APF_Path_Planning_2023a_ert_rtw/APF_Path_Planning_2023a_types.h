//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: APF_Path_Planning_2023a_types.h
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
#ifndef RTW_HEADER_APF_Path_Planning_2023a_types_h_
#define RTW_HEADER_APF_Path_Planning_2023a_types_h_
#include "rtwtypes.h"
#ifndef struct_CustomDataLogger_APF_Path_Pla_T
#define struct_CustomDataLogger_APF_Path_Pla_T

struct CustomDataLogger_APF_Path_Pla_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_CustomDataLogger_APF_Path_Pla_T

#ifndef struct_GPIO_Write_APF_Path_Planning__T
#define struct_GPIO_Write_APF_Path_Planning__T

struct GPIO_Write_APF_Path_Planning__T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T gpioPin;
  real_T pinDirection;
};

#endif                                // struct_GPIO_Write_APF_Path_Planning__T

#ifndef struct_ReadArm_Position_Rates_APF_Pa_T
#define struct_ReadArm_Position_Rates_APF_Pa_T

struct ReadArm_Position_Rates_APF_Pa_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
};

#endif                                // struct_ReadArm_Position_Rates_APF_Pa_T

#ifndef struct_IdentifyPlatform_APF_Path_Pla_T
#define struct_IdentifyPlatform_APF_Path_Pla_T

struct IdentifyPlatform_APF_Path_Pla_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
};

#endif                                // struct_IdentifyPlatform_APF_Path_Pla_T

#ifndef struct_Dynamixel_Controller_APF_Path_T
#define struct_Dynamixel_Controller_APF_Path_T

struct Dynamixel_Controller_APF_Path_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  real_T POSITION_P_GAIN;
  real_T POSITION_I_GAIN;
  real_T POSITION_D_GAIN;
  real_T MAX_POSITION;
  real_T MIN_POSITION;
  real_T MOVE_TIME;
  real_T CURRENT_LIMIT;
  real_T SPEED_P_GAIN;
  real_T SPEED_I_GAIN;
  real_T VELOCITY_LIMIT;
  real_T ACCELERATION_TIME;
};

#endif                                // struct_Dynamixel_Controller_APF_Path_T

// Parameters for system: '<S1>/Change BLACK Behavior'
typedef struct P_ChangeBLACKBehavior_APF_Pat_T_ P_ChangeBLACKBehavior_APF_Pat_T;

// Parameters for system: '<S6>/Change BLUE Behavior'
typedef struct P_ChangeBLUEBehavior_APF_Path_T_ P_ChangeBLUEBehavior_APF_Path_T;

// Parameters for system: '<Root>/Phase #0: Synchronization'
typedef struct P_Phase0Synchronization_APF_P_T_ P_Phase0Synchronization_APF_P_T;

// Parameters for system: '<S66>/Simulated Position Controller'
typedef struct P_SimulatedPositionController_T_ P_SimulatedPositionController_T;

// Parameters for system: '<S35>/RED+ARM'
typedef struct P_REDARM_APF_Path_Planning_20_T_ P_REDARM_APF_Path_Planning_20_T;

// Parameters for system: '<S87>/Sub-Phase #1'
typedef struct P_SubPhase1_APF_Path_Planning_T_ P_SubPhase1_APF_Path_Planning_T;

// Parameters for system: '<S88>/Sub-Phase #1'
typedef struct P_SubPhase1_APF_Path_Planni_a_T_ P_SubPhase1_APF_Path_Planni_a_T;

// Parameters for system: '<S89>/Sub-Phase #1'
typedef struct P_SubPhase1_APF_Path_Planni_h_T_ P_SubPhase1_APF_Path_Planni_h_T;

// Parameters for system: '<S349>/Target Tracker'
typedef struct P_TargetTracker_APF_Path_Plan_T_ P_TargetTracker_APF_Path_Plan_T;

// Parameters for system: '<Root>/Phase #4: Return Home'
typedef struct P_Phase4ReturnHome_APF_Path_P_T_ P_Phase4ReturnHome_APF_Path_P_T;

// Parameters (default storage)
typedef struct P_APF_Path_Planning_2023a_T_ P_APF_Path_Planning_2023a_T;

// Forward declaration for rtModel
typedef struct tag_RTM_APF_Path_Planning_202_T RT_MODEL_APF_Path_Planning_20_T;

#endif                           // RTW_HEADER_APF_Path_Planning_2023a_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
