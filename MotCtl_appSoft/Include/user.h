
//! @FilePath: \F28335_MotCtl_Frameware\DSP28xx_MotCtl_Frameware\MotCtl_appSoft\Include\user.h
//! @Author: Hex
//! @Date: 2023-08-20 21:25:26
//! @LastEditTime: 2024-06-08 09:49:20
//! @Description: 用户层借口，定义更改的数据

#ifndef MOTCTL_APPSOFT_INCLUDE_USER_H_
#define MOTCTL_APPSOFT_INCLUDE_USER_H_

// ************************************** include files  ************************************************************
#include "UserData.h"

// ！============   反馈类参数设置  =======================

//! \brief 电流基值
#define USER_FULL_SCALE_CURRENT_A (10.0)

//! \brief 频率基值
#define USER_FULL_SCALE_FREQ_Hz (300)

//! \brief 电压基值
#define USER_FULL_SCALE_VOLTAGE_V (36)

//! \brief ADC电压采集最大时（3/3.3V）对应的电流值
#define USER_ADC_FULL_SCALE_CURRENT_A (20)

//! \brief ADC相电压采集最大时（3/3.3V）对应的电压值
#define USER_ADC_FULL_SCALE_PH_VOLTAGE_V (44.30)

//! \brief ADC直流电压采集最大时（3/3.3V）对应的电压值
#define USER_ADC_FULL_SCALE_DC_VOLTAGE_V (44.30)

//! \brief 相电压滤波器极点
#define USER_VOLTAGE_FILTER_POLE_Hz (344.6)

//! \brief 偏置滤波器极点，rad/s
#define USER_OFFSET_POLE_Hz (5)

//! \brief 相电流传感器数量
#define USER_NUM_CURRENT_SENSORS (3)

//! \brief 相电压传感器数量
#define USER_NUM_VOLTAGE_SENSORS (3)

//! \brief 速度控制极点，Hz
#define USER_SPEED_POLE_Hz (100)

//! \brief 母线电压采集极点，Hz
#define USER_DCBUS_POLE_Hz (100)

//! \brief 母电流传感器方向,默认为1，电流方向为流向电机为正
#define USER_CURR_SENSOR_DIRECTION (1)

// ！===================================  控制类参数设置  =============================================
//! \brief 系统时钟
#define USER_SYSTEM_FREQ_MHz (150)

//! \brief pwm时钟
#define USER_PWM_Freq_kHz (10)

#define USER_numPwmTicksPerIsrTicks (3)

#define USER_numIsrTicksPerCtrlTick (1)

#define USER_numCtrlTicksPerCurrentTick (1)

#define USER_numCtrlTicksPerEstTick (1)

#define USER_numCtrlTicksPerSpeedTick (5)

#define USER_numCtrlTicksPerTrajTick (5)

//! \brief 最大加速度
#define USER_MAX_ACCEL_Hzps (20)


//! \brief 参数辨识时最大加速度
#define USER_MAX_ACCEL_EST_Hzps (5.0)


// ！===================================   电机类参数设置  ==============================================
#define USER_MOTOR_TYPE MOTOR_Type_Pm
#define USER_MOTOR_NUM_POLE_PAIRS (4)
#define USER_MOTOR_Rr (NULL)
#define USER_MOTOR_Rs (1.52442157)
#define USER_MOTOR_Ls_d (0.00209840364)
#define USER_MOTOR_Ls_q (0.00209840364)
#define USER_MOTOR_RATED_FLUX (0.0509840436)
#define USER_MOTOR_MAX_CURRENT (1)

// **************************************  typedef 类定义 ***********************************************************

//***********************************    函数方法 function ***********************************************************

extern void USER_checkForErrors(USER_Params *pUserParams);

extern void USER_setParams(USER_Params *pUserParams);

extern USER_PARAMS_ErrorCode USER_getErrorCode(USER_Params *pUserParams);

extern void USER_setErrorCode(USER_Params *pUserParams, const USER_PARAMS_ErrorCode errorCode);

#endif /* MOTCTL_APPSOFT_INCLUDE_USER_H_ */
