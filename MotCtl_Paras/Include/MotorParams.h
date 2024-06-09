
//! @FilePath: \F28335_MotCtl_Frameware\DSP28xx_MotCtl_Frameware\MotCtl_Paras\Include\MotorParams.h
//! @Author: Hex
//! @Date: 2023-08-23 19:53:04
//! @LastEditTime: 2024-06-08 16:15:13
//! @Description:

#ifndef _MOTOR_H_
#define _MOTOR_H_

// **************************************************************************
// the includes

#include "types.h"


typedef enum
{
    MOTOR_Type_Induction = 0,  //!< induction
    MOTOR_Type_Pm,             //!< permanent magnet
    MOTOR_Type_BLDC,
    MOTOR_Type_DC
} MOTOR_Type_e;

//! \brief 定义电机参数结构体
typedef struct _MOTOR_Params_{
    // GROUP2 电机参数
    MOTOR_Type_e type;                             // 电机类型
    uint_least16_t numPolePairs;                   // 电机极对数
    float_t ratedFlux_VHz;                         // 额定磁链, V/Hz
    float_t Rr_ohm;                                // 转子电阻, ohm
    float_t Rs_ohm;                                // 定子电阻, ohm
    float_t Ls_d_H;                               // d电感, H
    float_t Ls_q_H;                               // q电感, H
    float_t maxCurr_A;                             // 电机最大电流值, A
    float_t Inertia;                             // 电机最大电流值, A
} MOTOR_Params;

#endif // end of _MOTOR_H_ definition
