/*
 * @Author: Hex
 * @Date: 2023-08-20 16:20:56
 * @LastEditors: Hexer hex@hust.edu.cn
 * @LastEditTime: 2023-08-20 16:23:22
 * @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_HAL\Include\offset.h
 * @Description:
 */
#ifndef MOTCTL_HAL_INCLUDE_OFFSET_H_
#define MOTCTL_HAL_INCLUDE_OFFSET_H_

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
//! \brief Defines the OFFSET handle
//!
typedef struct _OFFSET_Obj_ *OFFSET_Handle;

//  ***********************  函数方法 ****************************************************************
//! \brief     Gets the beta offset filter coefficient
//! \param[in] handle  The offset handle
//! \return The filter coefficient beta
extern _iq OFFSET_getBeta(OFFSET_Handle handle);

//! \brief     Gets the offset value
//! \param[in] handle  The offset handle
//! \return    The offset value
static inline _iq OFFSET_getOffset(OFFSET_Handle handle)
{
    OFFSET_Obj *obj = (OFFSET_Obj *)handle;

    return (obj->value);
} // end of OFFSET_getOffset() function

//! \brief     Initializes the offset
//! \param[in] pMemory   A pointer to the memory for the offset object
//! \param[in] numBytes  The number of bytes allocated for the offset object, bytes
//! \return The offset (OFFSET) object handle
extern OFFSET_Handle OFFSET_init(void *pMemory, const size_t numBytes);

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

//! \brief     Sets the beta offset filter coefficient
//! \param[in] handle  The offset handle
//! \param[in] beta          The offset filter coefficient beta
extern void OFFSET_setBeta(OFFSET_Handle handle, const _iq beta);

//! \brief     Set the initial condition of the integrator or the value of y[n-1]
//! \param[in] handle  The offset handle
//! \param[in] initCond      The mean value that the filter will approximate to
extern void OFFSET_setInitCond(OFFSET_Handle handle, const _iq initCond);

//! \brief     Sets the offset value
//! \param[in] handle  The offset handle
//! \param[in] offsetValue   The offset value
extern void OFFSET_setOffset(OFFSET_Handle handle, _iq offsetValue);

#endif /* MOTCTL_HAL_INCLUDE_OFFSET_H_ */
