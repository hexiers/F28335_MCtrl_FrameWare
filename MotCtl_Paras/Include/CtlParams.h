/*****************************************************************************
 * File name: 	CtlParams.h
 *    Author: 	Hex
 *	  E-mail: 	hex@hust.edu.cn
 *    Date  : 	2024年6月8日
 *	  Description:
 *****************************************************************************/
#ifndef MOTCTL_PARAS_INCLUDE_CTLPARAMS_H_
#define MOTCTL_PARAS_INCLUDE_CTLPARAMS_H_

// include files*************************************************************
#include "types.h"

// 宏定义 defines ***********************************************************
//! \brief 控制状态机的
//!
typedef enum {
  FOC_CTRL_State_Error=0,           //!< 控制器故障状态
  FOC_CTRL_State_Idle,              //!< 控制器空闲状态
  FOC_CTRL_State_OffLine,           //!< 控制器离线状态
  FOC_CTRL_State_OnLine,            //!< 控制器在线状态
  FOC_CTRL_numStates                //!< 控制状态种类数
} FOC_CTRL_State_e;


// typedef 类定义 ***************************************s********************
//! \brief 定义控制参数
typedef struct _CTRL_Params_
{

    uint_least16_t systemFreq_MHz; // 定义系统时钟频率，MHz

    uint_least16_t pwmFreq_kHz; // PWM控制频率, kHz
    float_t pwmPeriod_usec;     // 定义PWM的周期，us

    uint_least32_t isrFreq_kHz; // ISR 产生中断频率

    uint_least32_t ctrlFreq_kHz; // 控制频率, Hz
    float_t ctrlPeriod_sec;      // 控制器执行时间, sec

    uint_least16_t numPwmTicksPerIsrTick;      // 定义每个Isr周期的PWM周期次数
    uint_least16_t numIsrTicksPerCtrlTick;     // 定义每个控制周期的ISR中断次数
    uint_least16_t numCtrlTicksPerCurrentTick; // 定义每次执行电流环的控制时钟数
    uint_least16_t numCtrlTicksPerEstTick;     // 定义每次执行观测器的控制时钟数
    uint_least16_t numCtrlTicksPerSpeedTick;   // 定义每次执行速度环的控制时钟数
    uint_least16_t numCtrlTicksPerTrajTick;    // 定义每次执行位置环的控制时钟数

    uint_least32_t currCtrlFreq_Hz; // 定义电流环控制频率
    uint_least32_t estFreq_Hz;      // 定义观测器执行频率
    uint_least32_t spdCtrlFreq_Hz;  // 定义速度话执行频率
    uint_least32_t trajFreq_Hz;     // 定义位置控制频率

    uint_least32_t ctrlWaitTime[FOC_CTRL_numStates];

    float_t maxAccel_Hzps; // 定义最大加速度, Hz/s

    float_t IdRated_A; // 定义额定的d轴电流

} CTRL_Params;

//  函数方法 ****************************************************************

#endif /* MOTCTL_PARAS_INCLUDE_CTLPARAMS_H_ */
