/*
 * @Author: Hex
 * @Date: 2023-08-20 16:20:56
 * @LastEditors: Hexer hex@hust.edu.cn
 * @LastEditTime: 2023-08-20 16:23:22
 * @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_HAL\Include\offset.h
 * @Description:
 */
#ifndef MOTCTL_DRIVER_INCLUDE_OFFSET_H_
#define MOTCTL_DRIVER_INCLUDE_OFFSET_H_

// *********************** include files *************************************************************
#include "types.h"
#include "IQmathLib.h"
#include "IIR_Filter_Fo.h"

// ***********************  宏定义 defines ***********************************************************

// ***********************  typedef 类定义 ***********************************************************
typedef struct _OFFSET_
{
    _iq value;                     // offset值
    _iq bias;                      // bias偏置值
    FILTER_FO_Obj filter;          // 定义一阶滤波器对象
    FILTER_FO_Handle filterHandle; // 定义一阶滤波器句柄
} OFFSET_Obj;

typedef struct _OFFSET_Obj_ *OFFSET_Handle;

//  ***********************  函数方法 ****************************************************************

extern _iq OFFSET_getBeta(OFFSET_Handle handle);

extern OFFSET_Handle OFFSET_init(void *pMemory, const size_t numBytes);

extern void OFFSET_setBeta(OFFSET_Handle handle, const _iq beta);

extern void OFFSET_setInitCond(OFFSET_Handle handle, const _iq initCond);

extern void OFFSET_setOffset(OFFSET_Handle handle, _iq offsetValue);

//! \brief     获取 offset 值
//! \param[in] handle  offset handle
//! \return    offset值
static inline _iq OFFSET_getOffset(OFFSET_Handle handle)
{
    OFFSET_Obj *obj = (OFFSET_Obj *)handle;

    return (obj->value);
} // end of OFFSET_getOffset()

//! \brief     Runs an offset filter of the form
//!            y[n] = beta*(x[n]+bias) + (1 - beta)*y[n-1]
//!            y -> The DC offset
//!            x -> The ADC measurement
//!
//! \param[in] handle  The offset handle
//! \param[in] inputValue    The input value to offset filter
static inline void OFFSET_run(OFFSET_Handle handle, const _iq inputValue)
{
    OFFSET_Obj *obj = (OFFSET_Obj *)handle;

    obj->value = FILTER_FO_run(obj->filterHandle, inputValue);

    return;
} // end of OFFSET_run() function

#endif /* MOTCTL_DRIVER_INCLUDE_OFFSET_H_ */
