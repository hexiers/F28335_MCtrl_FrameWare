
//! @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_Paras\Include\UserData.h
//! @Author: Hex
//! @Date: 2023-08-23 19:51:35
//! @LastEditTime: 2023-08-23 20:34:36
//! @Description:  用户数据结构定义

#include "types.h"
#include "MotorParams.h"

enum USER_PARAMS_ErrorCode
{
    USER_PARAMS_NoError = 0,
    USER_PARAMS_fullScaleCurrent_High = 1,
    USER_PARAMS_fullScaleCurrent_Low = 2,
    USER_PARAMS_fullScaleVoltage_High = 3,
    USER_PARAMS_fullScaleVoltage_Low = 4,
    USER_PARAMS_FullScaleFreq_High = 5,
    USER_PARAMS_FullScaleFreq_Low = 6

}

//! \brief Defines a structure for the user parameters
//!
typedef struct _USER_Params_
{
    // GROUP1 反馈类参数
    float_t fullScaleCurrent_A;      // iq=1对应的电流值, A
    float_t fullScaleVoltage_V;      // iq=1对应的电压值, V
    float_t FullScaleFreq_Hz;        // iq=1对应的频率值, Hz
    float_t offsetPole_rps;          // 电流、电压滞后补偿极点, rad/s
    uint_least8_t numCurrentSensors; // 电流传感器数量
    uint_least8_t numVoltageSensors; // 电压传感器数量
    float_t dcBusPole_rps;           // 直流母线电压滤波器极点, rad/s
    float_t speedPole_rps;           // 速度控制滤波器极点, rad/s
    float_t voltage_sf;              // 电压转换系数
    float_t current_sf;              // 电流转换系数
    float_t voltageFilterPole_rps;   // 电压滤波器极点
    uint_least32_t ctrlFreq_Hz;      // 控制频率, Hz
    float_t ctrlPeriod_sec;          // 控制器执行时间, sec

    // GROUP2 软件控制参数
    uint_least16_t systemFreq_MHz;             // 系统时钟, MHz
    uint_least16_t numIsrTicksPerCtrlTick;     // 控制环分频值
    uint_least16_t numCtrlTicksPerCurrentTick; // 电流控制环分频值
    uint_least16_t numCtrlTicksPerSpeedTick;   // 速度环分频值
    float_t maxAccel_Hzps;                     // 最大加速度, Hz/s
    float_t pwmPeriod_usec;                    // PWM周期, usec

    // GROUP2 电机参数
    MOTOR_Type_e motor_type;           // 电机参数
    uint_least16_t motor_numPolePairs; // 电机极对数
    float_t motor_ratedFlux;           // 额定磁链, V/Hz
    float_t motor_Rr;                  // 转子电阻, ohm
    float_t motor_Rs;                  // 定子电阻, ohm
    float_t motor_Ls_d;                // d电感, H
    float_t motor_Ls_q;                // q电感, H
    float_t maxCurrent;                //! 电流限幅值, A

    // GROUP3 用户配置故障类参数
    USER_PARAMS_ErrorCode errorCode;
} USER_Params;