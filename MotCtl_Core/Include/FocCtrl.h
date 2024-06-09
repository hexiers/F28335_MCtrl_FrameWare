/*****************************************************************************
 * File name: 	FocCtrl.h
 *    Author: 	Hex
 *	  E-mail: 	hex@hust.edu.cn
 *    Date  : 	2024年6月9日
 *	  Description: 控制状态机
 *****************************************************************************/
#ifndef MOTCTL_CORE_INCLUDE_FOCCTRL_H_
#define MOTCTL_CORE_INCLUDE_FOCCTRL_H_

// include files*************************************************************
#include "types.h"
#include "Clarke.h"
#include "IIR_Filter_Fo.h"
#include "iPark.h"
#include "math.h"
#include "Park.h"
#include "PI_Ctrler.h"
#include "SVM.h"
#include "MotorParams.h"
#include "UserData.h"

// 宏定义 defines ***********************************************************
//!
#define CTRL_NUM_CONTROLLERS (2)

// typedef 类定义 ***********************************************************

typedef enum
{
  CTRL_ErrorCode_NoError = 0, //!< no error error code
  CTRL_ErrorCode_IdClip,      //!< Id clip error code
  CTRL_ErrorCode_EstError,    //!< estimator error code
  CTRL_numErrorCodes          //!< the number of controller error codes
} CTRL_ErrorCode_e;

//! \brief Enumeration for the target processors
//!
typedef enum
{
  CTRL_TargetProc_2806x = 0, //!< 2806x processor
  CTRL_TargetProc_2805x,     //!< 2805x processor
  CTRL_TargetProc_2803x,     //!< 2803x processor
  CTRL_TargetProc_2802x,     //!< 2802x processor
  CTRL_TargetProc_Unknown    //!< Unknown processor
} CTRL_TargetProc_e;

//! \brief Enumeration for the controller (CTRL) types
//!
typedef enum
{
  CTRL_Type_PID_spd = 0, //!< PID Speed controller
  CTRL_Type_PID_Id,      //!< PID Id controller
  CTRL_Type_PID_Iq       //!< PID Iq controller
} CTRL_Type_e;

//! \brief Defines the controller (CTRL) version number
//!
typedef struct _CTRL_Version_
{
  uint16_t rsvd;                //!< reserved value
  CTRL_TargetProc_e targetProc; //!< the target processor
  uint16_t major;               //!< the major release number
  uint16_t minor;               //!< the minor release number
} CTRL_Version;

//! \brief      Defines the controller (CTRL) object
//! \details    The controller object implements all of the FOC algorithms and the estimator
//!             functions.
//!
typedef struct _FOC_CTRL_Obj_
{
  CTRL_Version version; //!< the controller version

  FOC_CTRL_State_e state; //!< the current state of the controller

  FOC_CTRL_State_e prevState; //!< the previous state of the controller

  CTRL_ErrorCode_e errorCode; //!< the error code for the controller

  CLARKE_Handle clarkeHandle_I; //!< the handle for the current Clarke transform
  CLARKE_Obj clarke_I;          //!< the current Clarke transform object

  CLARKE_Handle clarkeHandle_V; //!< the handle for the voltage Clarke transform
  CLARKE_Obj clarke_V;          //!< the voltage Clarke transform object

  // EST_Handle         estHandle;                    //!< the handle for the parameter estimator

  PARK_Handle parkHandle; //!< the handle for the Park object
  PARK_Obj park;          //!< the Park transform object

  PI_Handle piHandle_Id; //!< the handle for the Id PID controller
  PI_Obj pi_Id;          //!< the Id PID controller object

  PI_Handle piHandle_Iq; //!< the handle for the Iq PID controller
  PI_Obj pi_Iq;          //!< the Iq PID controller object

  PI_Handle piHandle_spd; //!< the handle for the speed PID controller
  PI_Obj pi_spd;          //!< the speed PID controller object

  IPARK_Handle iparkHandle; //!< the handle for the inverse Park transform
  IPARK_Obj ipark;          //!< the inverse Park transform object

  SVGEN_Handle svgenHandle; //!< the handle for the space vector generator
  SVGEN_Obj svgen;          //!< the space vector generator object

  MOTOR_Params motorParams; //!< the motor parameters

  uint_least32_t waitTimes[FOC_CTRL_numStates]; //!< an array of wait times for each state, estimator clock counts

  uint_least32_t counter_state; //!< the state counter

  uint_least16_t numIsrTicksPerCtrlTick; //!< Defines the number of isr clock ticks per controller clock tick

  uint_least16_t numCtrlTicksPerCurrentTick; //!< Defines the number of controller clock ticks per current controller clock tick

  uint_least16_t numCtrlTicksPerSpeedTick; //!< Defines the number of controller clock ticks per speed controller clock tick

  uint_least16_t numCtrlTicksPerTrajTick; //!< Defines the number of controller clock ticks per trajectory clock tick

  uint_least32_t ctrlFreq_Hz; //!< Defines the controller frequency, Hz

  uint_least32_t trajFreq_Hz; //!< Defines the trajectory frequency, Hz

  _iq trajPeriod_sec; //!< Defines the trajectory period, sec

  float_t ctrlPeriod_sec; //!< Defines the controller period, sec

  _iq maxVsMag_pu; //!< the maximum voltage vector that is allowed, pu

  MATH_vec2 Iab_in; //!< the Iab input values

  MATH_vec2 Iab_filt; //!< the Iab filtered values

  MATH_vec2 Idq_in; //!< the Idq input values

  MATH_vec2 Vab_in; //!< the Vab input values

  _iq spd_out; //!< the speed output value

  MATH_vec2 Vab_out; //!< the Vab output values

  MATH_vec2 Vdq_out; //!< the Vdq output values

  _iq Kp_Id;  //!< the desired Kp_Id value
  _iq Kp_Iq;  //!< the desired Kp_Iq value
  _iq Kp_spd; //!< the desired Kp_spd value

  _iq Ki_Id;  //!< the desired Ki_Id value
  _iq Ki_Iq;  //!< the desired Ki_Iq value
  _iq Ki_spd; //!< the desired Ki_spd value

  _iq Kd_Id;  //!< the desired Kd_Id value
  _iq Kd_Iq;  //!< the desired Kd_Iq value
  _iq Kd_spd; //!< the desired Kd_spd value

  _iq Ui_Id;  //!< the desired Ui_Id value
  _iq Ui_Iq;  //!< the desired Ui_Iq value
  _iq Ui_spd; //!< the desired Ui_spd value

  MATH_vec2 Idq_ref; //!< the Idq reference values, pu

  _iq IdRated; //!< the Id rated current, pu

  _iq spd_ref; //!< the speed reference, pu

  _iq spd_max; //!< the maximum speed, pu

  uint_least16_t counter_current; //!< the isr counter

  uint_least16_t counter_isr; //!< the isr counter

  uint_least16_t counter_speed; //!< the speed counter

  bool flag_enableCtrl;            //!< a flag to enable the controller
  bool flag_enableDcBusComp;       //!< a flag to enable the DC bus compensation in the controller
  bool flag_enableOffset;          //!< a flag to enable offset estimation after idle state
  bool flag_enableSpeedCtrl;       //!< a flag to enable the speed controller
  bool flag_enableUserMotorParams; //!< a flag to use known motor parameters from user.h file

  // NOTE:  APPENDING ONLY WORKS BECAUSE WE HAVE ALLOCATED TWO CONTROLLERS IN PROTECTED RAM AND WE ARE ONLY USING THE FIRST ONE
  MATH_vec2 Idq_offset_pu;     //!< the Idq offset values, pu
  MATH_vec2 Vdq_offset_pu;     //!< the Vdq offset values, pu
  _iq angle_pu;                //!< the angle value, pu
  _iq speed_ref_pu;            //!< the speed reference, pu
  _iq speed_fb_pu;             //!< the feedback speed value, pu
  _iq speed_outMax_pu;         //!< the maximum output of the speed PI control, pu
  bool flag_enableCurrentCtrl; //!< a flag to enable the current controllers
} FOC_CTRL_Obj;

//! \brief 定义FOC控制的句柄
typedef struct _FOC_CTRL_Obj_ *FOC_CTRL_Handle;

//  函数方法 ****************************************************************

//! @brief: 设置电机参数
inline void FocCtrl_setMotorParams(FOC_CTRL_Handle handle,
                                   const MOTOR_Type_e motorType,
                                   const uint_least16_t numPolePairs,
                                   const float_t ratedFlux,
                                   const float_t Ls_d,
                                   const float_t Ls_q,
                                   const float_t Rr,
                                   const float_t Rs)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->motorParams.type = motorType;
  obj->motorParams.numPolePairs = numPolePairs;
  obj->motorParams.ratedFlux_VHz = ratedFlux;
  obj->motorParams.Ls_d_H = Ls_d;
  obj->motorParams.Ls_q_H = Ls_q;
  obj->motorParams.Rr_ohm = Rr;
  obj->motorParams.Rs_ohm = Rs;
  return;
}

//! \brief     设置电流环分频值
inline void FocCtrl_setNumCtrlTicksPerCurrentTick(FOC_CTRL_Handle handle,
                                                  const uint_least16_t numCtrlTicksPerCurrentTick)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->numCtrlTicksPerCurrentTick = numCtrlTicksPerCurrentTick;

  return;
} // end of CTRL_setNumCtrlTicksPerCurrentTick() function

//! \brief     设置速度环分频值
inline void FocCtrl_setNumCtrlTicksPerSpeedTick(FOC_CTRL_Handle handle,
                                                const uint_least16_t numCtrlTicksPerSpeedTick)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->numCtrlTicksPerSpeedTick = numCtrlTicksPerSpeedTick;

  return;
} // end of CTRL_setNumCtrlTicksPerSpeedTick() function

//! \brief     设置位置环分频值
inline void FocCtrl_setNumCtrlTicksPerTrajTick(FOC_CTRL_Handle handle,
                                               const uint_least16_t numCtrlTicksPerTrajTick)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->numCtrlTicksPerTrajTick = numCtrlTicksPerTrajTick;

  return;
} // end of CTRL_setNumCtrlTicksPerTrajTick() function

//! \brief     设置中断响应分频值
inline void FocCtrl_setNumIsrTicksPerCtrlTick(FOC_CTRL_Handle handle,
                                              const uint_least16_t numIsrTicksPerCtrlTick)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->numIsrTicksPerCtrlTick = numIsrTicksPerCtrlTick;

  return;
} // end of CTRL_setNumIsrTicksPerCtrlTick() function

//! \brief   设置控制频率
inline void FocCtrl_setCtrlFreq_Hz(FOC_CTRL_Handle handle, const uint_least32_t ctrlFreq_Hz)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->ctrlFreq_Hz = ctrlFreq_Hz;

  return;
} // end of FocCtrl_setCtrlFreq_Hz() function

//! \brief   设置控制周期秒数
inline void FocCtrl_setCtrlPeriod_sec(FOC_CTRL_Handle handle, const float_t ctrlPeriod_sec)
{

  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->ctrlPeriod_sec = ctrlPeriod_sec;

  return;
}

//! \brief   设置ALpha和beta下的电流
inline void FocCtrl_setIab_in_pu(FOC_CTRL_Handle handle, const MATH_vec2 *pIab_in_pu)
{

  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->Iab_in.value[0] = pIab_in_pu->value[0];
  obj->Iab_in.value[1] = pIab_in_pu->value[1];

  return;
} // end of FocCtrl_setIab_in_pu() function

//! \brief      设置dq轴下的电流值
inline void FocCtrl_setIdq_in_pu(FOC_CTRL_Handle handle, const MATH_vec2 *pIdq_in_pu)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->Idq_in.value[0] = pIdq_in_pu->value[0];
  obj->Idq_in.value[1] = pIdq_in_pu->value[1];

  return;
} // end of FocCtrl_setIdq_in_pu() function

//! \brief     设置dq轴下的电流偏置
static inline void FocCtrl_setIdq_offset_pu(FOC_CTRL_Handle handle, const MATH_vec2 *pIdq_offset_pu)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->Idq_offset_pu.value[0] = pIdq_offset_pu->value[0];
  obj->Idq_offset_pu.value[1] = pIdq_offset_pu->value[1];

  return;
} // end of CTRL_setIdq_offset_pu() function

//! \brief      设置dq轴下的电流指令值
inline void FocCtrl_setIdq_ref_pu(FOC_CTRL_Handle handle, const MATH_vec2 *pIdq_ref_pu)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->Idq_ref.value[0] = pIdq_ref_pu->value[0];
  obj->Idq_ref.value[1] = pIdq_ref_pu->value[1];

  return;
} // end of FocCtrl_setIdq_ref_pu() function

//! \brief      设置d轴下的额定电流
inline void FocCtrl_setIdRated_pu(FOC_CTRL_Handle handle, const _iq IdRated_pu)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->IdRated = IdRated_pu;

  return;
} // end of FocCtrl_setIdRated_pu() function

//! \brief   设置 alpha/beta 电压输入量
inline void FocCtrl_setVab_in_pu(FOC_CTRL_Handle handle, const MATH_vec2 *pVab_in_pu)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->Vab_in.value[0] = pVab_in_pu->value[0];
  obj->Vab_in.value[1] = pVab_in_pu->value[1];

  return;
} // end of FocCtrl_setVab_in_pu() function

//! \brief  设置 alpha/beta 电压输输出量
inline void FocCtrl_setVab_out_pu(FOC_CTRL_Handle handle, const MATH_vec2 *pVab_out_pu)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->Vab_out.value[0] = pVab_out_pu->value[0];
  obj->Vab_out.value[1] = pVab_out_pu->value[1];

  return;
} // end of CTRL_setVab_out_pu() function

//! \brief  设置 d/q轴下的电压偏置量
static inline void FocCtrl_setVdq_offset_pu(FOC_CTRL_Handle handle, const MATH_vec2 *pVdq_offset_pu)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->Vdq_offset_pu.value[0] = pVdq_offset_pu->value[0];
  obj->Vdq_offset_pu.value[1] = pVdq_offset_pu->value[1];

  return;
} // end of FocCtrl_setVdq_offset_pu() function

//! \brief     设置dq轴下的电压输出量
inline void FocCtrl_setVdq_out_pu(FOC_CTRL_Handle handle, const MATH_vec2 *pVdq_out_pu)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->Vdq_out.value[0] = pVdq_out_pu->value[0];
  obj->Vdq_out.value[1] = pVdq_out_pu->value[1];

  return;
} // end of FocCtrl_setVdq_out_pu() function

//! \brief     设置速度环输出量
inline void FocCtrl_setSpd_out_pu(FOC_CTRL_Handle handle, const _iq spd_out_pu)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->spd_out = spd_out_pu;

  return;
} // end of FocCtrl_setSpd_out_pu() function

//! \brief     重置电流环计数器
inline void FocCtrl_resetCounter_current(FOC_CTRL_Handle handle)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->counter_current = 0;

  return;
} // end of FocCtrl_resetCounter_current() function

//! \brief   重置中断事件计数器
inline void FocCtrl_resetCounter_isr(FOC_CTRL_Handle handle)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->counter_isr = 1;

  return;
} // end of FocCtrl_resetCounter_isr() function

//! \brief   重置速度环计数器
inline void FocCtrl_resetCounter_speed(FOC_CTRL_Handle handle)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->counter_speed = 0;

  return;
} // end of FocCtrl_resetCounter_speed() function

//! \brief    重置状态计数器
inline void FocCtrl_resetCounter_state(FOC_CTRL_Handle handle)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->counter_state = 0;

  return;
} // end of FocCtrl_resetCounter_state() function

//! \brief    在使能观测器控制
inline void FocCtrl_setFlag_enableCtrl(FOC_CTRL_Handle handle, const bool state)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->flag_enableCtrl = state;

  return;
} // end of FocCtrl_setFlag_enableCtrl() function

//! \brief   使能电流环控制
static inline void FocCtrl_setFlag_enableCurrentCtrl(FOC_CTRL_Handle handle, const bool state)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->flag_enableCurrentCtrl = state;

  return;
} // end of CTRL_setFlag_enableCurrentCtrl() function

//! \brief    设置DC母线电压修正使能
inline void FocCtrl_setFlag_enableDcBusComp(FOC_CTRL_Handle handle, const bool state)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->flag_enableDcBusComp = state;

  return;
} // end of FocCtrl_setFlag_enableDcBusComp() function

//! \brief     使能偏置值
inline void FocCtrl_setFlag_enableOffset(FOC_CTRL_Handle handle, const bool state)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->flag_enableOffset = state;

  return;
} // end of FocCtrl_setFlag_enableOffset() function

//! \brief     使能无位置控制下的速度控制
inline void FocCtrl_setFlag_enableSpeedCtrl(FOC_CTRL_Handle handle, const bool state)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->flag_enableSpeedCtrl = state;

  return;
} // end of FocCtrl_setFlag_enableSpeedCtrl() function

//! \brief      使能观测器采用user.h的电机参数
inline void FocCtrl_setFlag_enableUserMotorParams(FOC_CTRL_Handle handle, const bool state)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->flag_enableUserMotorParams = state;

  return;
} // end of FocCtrl_setFlag_enableUserMotorParams() function

//! \brief    设置控制错误代码
inline void FocCtrl_setErrorCode(FOC_CTRL_Handle handle, const CTRL_ErrorCode_e errorCode)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->errorCode = errorCode;

  return;
} // end of FocCtrl_setErrorCode() function

//! \brief    设置控制状态
inline void FocCtrl_setState(FOC_CTRL_Handle handle, const FOC_CTRL_State_e state)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->prevState = obj->state;
  obj->state = state;

  return;
} // end of FocCtrl_setState() function


//! \brief    设置控制状态
inline void FocCtrl_setSpd_ref_pu(FOC_CTRL_Handle handle,const _iq spd_ref_pu)
{
  FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

  obj->spd_ref = spd_ref_pu;

  return;
} // end of CTRL_setSpd_ref_pu() function



//! \brief    根据电流传感器数目设置CLARKE变换系数
extern void FocCtrl_setupClarke_I(FOC_CTRL_Handle handle, uint_least8_t numCurrentSensors);

//! \brief    根据电压传感器数目设置CLARKE变换系数
extern void FocCtrl_setupClarke_V(FOC_CTRL_Handle handle, uint_least8_t numVoltageSensors);

//! \brief    根据电压传感器数目设置CLARKE变换系数
extern void FocCtrl_setParams(FOC_CTRL_Handle handle, USER_Params *pUserParams);

//! \brief    设置控制状态等待时间
extern void FocCtrl_setWaitTimes(FOC_CTRL_Handle handle, const uint_least32_t *pWaitTimes);

#endif /* MOTCTL_CORE_INCLUDE_FOCCTRL_H_ */
