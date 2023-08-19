/*
 * PI.h
 *
 *  Created on: 2023年8月1日
 *  Author: Hex
 */

#ifndef MOTCTL_CORE_INCLUDE_PI_H_
#define MOTCTL_CORE_INCLUDE_PI_H_

#include "IQmathLib.h"
#include "types.h"


// **************************************************************************
// the defines



// **************************************************************************
// the typedefs

//! \brief   定义PI控制器对象
//!
typedef struct _PI_Obj_
{
  _iq Kp;                     //!<  参数：Kp
  _iq Ki;                     //!< 	参数：Ki

  _iq Ui;                     //!< 积分累计值

  _iq refValue;               //!< 参考输入
  _iq fbackValue;             //!< 反馈量

  _iq outMin;                 //!< 限幅最小输出量
  _iq outMax;                 //!< 限幅最大输出量

} PI_Obj;


//! \brief  定义PI句柄
//!
typedef struct _PI_Obj_ *PI_Handle;


// **************************************************************************
// 函数原型

//! \brief     获取反馈值
//! \param[in]
//! \return
static inline _iq PI_getFbackValue(PI_Handle handle)
{
  PI_Obj *obj = (PI_Obj *)handle;

  return(obj->fbackValue);
} // end of PI_getFbackValue()


//! \brief      获取Pi增益
static inline void PI_getGains(PI_Handle handle,_iq *pKp,_iq *pKi)
{
  PI_Obj *obj = (PI_Obj *)handle;

  *pKp = obj->Kp;
  *pKi = obj->Ki;

  return;
} // end of PI_getGains() function


//! \brief  获取Pi积分增益
//
static inline _iq PI_getKi(PI_Handle handle)
{
  PI_Obj *obj = (PI_Obj *)handle;

  return(obj->Ki);
} // end of PI_getKi()


//! \brief  获取Pi比例增益
//
static inline _iq PI_getKp(PI_Handle handle)
{
  PI_Obj *obj = (PI_Obj *)handle;

  return(obj->Kp);
} // end of PI_getKp()

//TO DO
//! \brief  获取Pi最大最小输出
//
static inline void PI_getMinMax(PI_Handle handle,_iq *pOutMin,_iq *pOutMax)
{
  PI_Obj *obj = (PI_Obj *)handle;

  *pOutMin = obj->outMin;
  *pOutMax = obj->outMax;

  return;
} // end of PI_getMinMax() function


//! \brief      获取Pi最大输出
//!
static inline _iq PI_getOutMax(PI_Handle handle)
{
  PI_Obj *obj = (PI_Obj *)handle;

  return(obj->outMax);
} // end of PID_getOutMax()


//! \brief      获取Pi最小输出
//!
static inline _iq PI_getOutMin(PI_Handle handle)
{
  PI_Obj *obj = (PI_Obj *)handle;

  return(obj->outMin);
} // end of PID_getOutMax()


//! \brief     获取PI的参考值
//!
static inline _iq PI_getRefValue(PI_Handle handle)
{
  PI_Obj *obj = (PI_Obj *)handle;

  return(obj->refValue);
} // end of PI_getRefValue()


//! \brief    获取积分累计值
//!
static inline _iq PI_getUi(PI_Handle handle)
{
  PI_Obj *obj = (PI_Obj *)handle;

  return(obj->Ui);
} // end of PID_getUi()


//! \brief    PI控制器初始化
extern PI_Handle PI_init(void *pMemory,const size_t numBytes);


//! \brief     PI运行方法（串联型）
//! \param[in] handle      PI句柄
//! \param[in] refValue    参考输入
//! \param[in] fbackValue  控制器反馈值
//! \param[in] pOutValue   控制输出指针
static inline void PI_run(PI_Handle handle,const _iq refValue,const _iq fbackValue,_iq *pOutValue)
{
  PI_Obj *obj = (PI_Obj *)handle;

  _iq Error;
  _iq Up,Ui;


  Error = refValue - fbackValue;

  Ui = obj->Ui;                                                  // 载入上一时刻的积分值
  Up = _IQmpy(obj->Kp,Error);                                    // 计算比例输出
  Ui = _IQsat(Ui + _IQmpy(obj->Ki,Up),obj->outMax,obj->outMin);  // 计算积分输出

  obj->Ui = Ui;                                                  // 存储积分累计值
  obj->refValue = refValue;
  obj->fbackValue = fbackValue;

  *pOutValue = _IQsat(Up + Ui,obj->outMax,obj->outMin);          // 限幅

  return;
} // end of PI_run()


//! \brief  设置PI的反馈输入
//!
static inline void PI_setFbackValue(PI_Handle handle,const _iq fbackValue)
{
  PI_Obj *obj = (PI_Obj *)handle;

  obj->fbackValue = fbackValue;

  return;
} // end of PI_setFbackValue()


//! \brief  设置PI的参数
static inline void PI_setGains(PI_Handle handle,const _iq Kp,const _iq Ki)
{
  PI_Obj *obj = (PI_Obj *)handle;

  obj->Kp = Kp;
  obj->Ki = Ki;

  return;
} // end of PI_setGains()


//! \brief   设置PI的Ki

static inline void PI_setKi(PI_Handle handle,const _iq Ki)
{
  PI_Obj *obj = (PI_Obj *)handle;

  obj->Ki = Ki;

  return;
} // end of PI_setKi()


//! \brief  设置PI的Kp
//!
static inline void PI_setKp(PI_Handle handle,const _iq Kp)
{
  PI_Obj *obj = (PI_Obj *)handle;

  obj->Kp = Kp;

  return;
} // end of PI_setKp()


//! \brief  设置PI的最大最小值
//!
static inline void PI_setMinMax(PI_Handle handle,const _iq outMin,const _iq outMax)
{
  PI_Obj *obj = (PI_Obj *)handle;

  obj->outMin = outMin;
  obj->outMax = outMax;

  return;
} // end of PI_setMinMax() function


//! \brief  设置PI的最大值
//!
static inline void PI_setOutMax(PI_Handle handle,const _iq outMax)
{
  PI_Obj *obj = (PI_Obj *)handle;

  obj->outMax = outMax;

  return;
} // end of PI_setOutMax()


//! \brief  设置PI的最小值
//!
static inline void PI_setOutMin(PI_Handle handle,const _iq outMin)
{
  PI_Obj *obj = (PI_Obj *)handle;

  obj->outMin = outMin;

  return;
} // end of PI_setOutMin()


//! \brief  设置PI的参考值
//!
static inline void PI_setRefValue(PI_Handle handle,const _iq refValue)
{
  PI_Obj *obj = (PI_Obj *)handle;

  obj->refValue = refValue;

  return;
} // end of PI_setRefValue()


//! \brief   设置PI的积分累计值
static inline void PI_setUi(PI_Handle handle,const _iq Ui)
{
  PI_Obj *obj = (PI_Obj *)handle;

  obj->Ui = Ui;

  return;
} // end of PI_setUi()


#endif /* MOTCTL_CORE_INCLUDE_PI_H_ */
