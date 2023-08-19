/*
 * ClarkeTrans.h
 *
 *  Created on: 2023年7月31日
 *  Author: Hex
 */

#ifndef MOTCTL_CORE_INCLUDE_CLARKETRANS_H_
#define MOTCTL_CORE_INCLUDE_CLARKETRANS_H_


//! \file   modules/clarke/src/32b/clarke.h   
//! \brief  Contains the public interface to the 
//!         Clarke transform (CLARKE) module routines


// **************************************************************************
// the includes

// modules
#include "IQmathLib.h"
#include "ti_Lib/Include/math.h"
#include "types.h"


// **************************************************************************
// 类型定义
// **************************************************************************
// the typedefs

//! \brief  定义 CLARKE 对象
//!
typedef struct _CLARKE_Obj_
{
	_iq     alpha_sf;      					//!< alpha 分量系数
	_iq     beta_sf;      					//!< alpha 分量系数

	uint_least8_t  numSensors;   			//!< 传感器数量

} CLARKE_Obj;


//! \brief 	定义 CLARKE 句柄
//!
typedef struct _CLARKE_Obj_ *CLARKE_Handle;


// **************************************************************************
// 通用方法
// **************************************************************************
// 函数原型           


//! \brief     获取传感器数量
//! \param[in] handle 【Clarke句柄】
//! \return    传感器数量
static inline uint_least8_t CLARKE_getNumSensors(CLARKE_Handle handle)
{
  CLARKE_Obj *obj = (CLARKE_Obj *)handle;

  return(obj->numSensors);
} // 结束 CLARKE_getNumSensors()


//! \brief     初始化
//! \param[in] pMemory   指向 Clarke 对象指针
//! \param[in] numBytes  The number of bytes allocated for the Clarke object, bytes
//! \return The Clarke (CLARKE) object handle
extern CLARKE_Handle CLARKE_init(void *pMemory,const size_t numBytes);


//! \brief     执行三输入 Clarke 变换
//! \param[in] handle  	Clarke 句柄
//! \param[in] pInVec   指向输入矢量
//! \param[in] pOutVec  指向输出矢量
static inline void CLARKE_run(CLARKE_Handle handle,const MATH_vec3 *pInVec,MATH_vec2 *pOutVec)
{
  CLARKE_Obj *obj = (CLARKE_Obj *)handle;

  uint_least8_t numSensors = obj->numSensors;

  _iq alpha_sf = obj->alpha_sf;
  _iq beta_sf = obj->beta_sf;


  if(numSensors == 3)
    {
      pOutVec->value[0] = _IQmpy(lshft_1(pInVec->value[0]) - (pInVec->value[1] + pInVec->value[2]),alpha_sf);
      pOutVec->value[1] = _IQmpy(pInVec->value[1] - pInVec->value[2],beta_sf);
    }
  else if(numSensors == 2)
    {
      pOutVec->value[0] = _IQmpy(pInVec->value[0],alpha_sf);
      pOutVec->value[1] = _IQmpy(pInVec->value[0] + lshft_1(pInVec->value[1]),beta_sf);
    }

  return;
} // 结束 CLARKE_run() function


//! \brief     设定传感器数量                
//! \param[in] handle
//! \param[in] numSensors
static inline void CLARKE_setNumSensors(CLARKE_Handle handle,const uint_least8_t numSensors)
{
  CLARKE_Obj *obj = (CLARKE_Obj *)handle;

  obj->numSensors = numSensors;

  return;
} // 结束 CLARKE_setNumSensors()


//! \brief     设定变换系数
//! \param[in] handle
//! \param[in] alpha_sf      T
//! \param[in] beta_sf
static inline void CLARKE_setScaleFactors(CLARKE_Handle handle,const _iq alpha_sf,const _iq beta_sf)
{
  CLARKE_Obj *obj = (CLARKE_Obj *)handle;


  obj->alpha_sf = alpha_sf;
  obj->beta_sf = beta_sf;

  return;
} //结束 CLARKE_setScaleFactors()


#endif /* MOTCTL_CORE_INCLUDE_CLARKETRANS_H_ */
