/*****************************************************************************
 * File name: 	FbkParams.h
 *    Author: 	Hex
 *	  E-mail: 	hex@hust.edu.cn
 *    Date  : 	2024年6月8日
 *	  Description:
 *****************************************************************************/
#ifndef MOTCTL_PARAS_INCLUDE_FBKPARAMS_H_
#define MOTCTL_PARAS_INCLUDE_FBKPARAMS_H_

// include files*************************************************************
#include "types.h"

// typedef 类定义 ***********************************************************

//! \brief 定义电机参数结构体
typedef struct _FBK_Params_
{
    // GROUP1 反馈类参数
    float_t fullScaleCurrent_A; // 基值对应的电流值, A
    float_t fullScaleVoltage_V; // 基值对应的电压值, V
    float_t fullScaleFreq_Hz;   // 基值对应的频率值, Hz

    float_t offsetPole_Hz;           // 电流、电压滞后补偿极点, Hz
    uint_least8_t numCurrentSensors; // 电流传感器数量
    uint_least8_t numVoltageSensors; // 电压传感器数量

    uint_least8_t currSensorDirection; // 电流传感器测量方向

    float_t dcBusPole_Hz;         // 直流母线电压滤波器极点, Hz
    float_t speedPole_Hz;         // 速度控制滤波器极点, Hz
    float_t voltage_sf;           // 电压转换系数
    float_t current_sf;           // 电流转换系数
    float_t voltageFilterPole_Hz; // 电压滤波器极点,Hz

} FBK_Params;

//  函数方法 ****************************************************************

#endif /* MOTCTL_PARAS_INCLUDE_FBKPARAMS_H_ */
