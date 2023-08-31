
//! @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_Paras\Include\MotorParams.h
//! @Author: Hex
//! @Date: 2023-08-23 19:53:04
//! @LastEditTime: 2023-08-23 19:53:15
//! @Description:

#ifndef _MOTOR_H_
#define _MOTOR_H_

// **************************************************************************
// the includes

#include "types.h"

typedef enum
{
    MOTOR_Type_Induction = 0, //!< induction
    MOTOR_Type_Pm             //!< permanent magnet
} MOTOR_Type_e;

//! \brief 定义电机参数
//!
typedef struct _MOTOR_Params_
{
    MOTOR_Type_e type; //!< Defines the motor type

    uint_least16_t numPolePairs; //!< Defines the number of pole pairs

    float_t Lr_H; //!< Defines the rotor inductance, H

    float_t Ls_d_H; //!< Defines the direct stator inductance, H
    float_t Ls_q_H; //!< Defines the quadrature stator inductance, H

    float_t Rr_Ohm; //!< Defines the rotor resistance, Ohm

    float_t Rs_Ohm; //!< Defines the stator resistance, Ohm

    float_t ratedFlux_VpHz; //!< Defines the rated flux, V/Hz
} MOTOR_Params;

#endif // end of _MOTOR_H_ definition
