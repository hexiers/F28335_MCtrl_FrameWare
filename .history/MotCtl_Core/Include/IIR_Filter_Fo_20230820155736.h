/*****************************************************************************
 * File name: 	IIR_Filter_Fo.h
 *    Author: 	Hex
 *	  E-mail: 	hex@hust.edu.cn
 *    Date  : 	2023年8月20日
 *	  Description: 创建IIR型的一阶滤波器对象，用于数据滤波处理
 *                  
 *****************************************************************************/
#ifndef MOTCTL_CORE_INCLUDE_IIR_FILTER_FO_H_
#define MOTCTL_CORE_INCLUDE_IIR_FILTER_FO_H_

// **********************include files*************************************************************
#include "types.h"
#include "IQmathLib.h"

// 宏定义 defines ***********************************************************

// typedef 类定义 ***********************************************************
//! \brief 定义IIR型的一阶滤波器对象
//!
typedef struct _FILTER_FO_
{    
  _iq     a1;          //!< the denominator filter coefficient value for z^(-1)

  _iq     b0;          //!< the numerator filter coefficient value for z^0
  _iq     b1;          //!< the numerator filter coefficient value for z^(-1)

  _iq     x1;          //!< the input value at time sample n=-1

  _iq     y1;          //!< the output value at time sample n=-1
} FILTER_FO_Obj;


//! \brief Defines the first-order filter (FILTER_FO) handle
//!
typedef struct _FILTER_FO_Obj_ *FILTER_FO_Handle; 

//  函数方法 ****************************************************************
static inline _iq FILTER_FO_run(FILTER_FO_Handle handle,const _iq inputValue)
{
  FILTER_FO_Obj *obj = (FILTER_FO_Obj *)handle;

  _iq a1 = obj->a1;
  _iq b0 = obj->b0;
  _iq b1 = obj->b1;
  _iq x1 = obj->x1;
  _iq y1 = obj->y1;


  // compute the output
  _iq y0 = _IQmpy(b0,inputValue) + _IQmpy(b1,x1) 
    - _IQmpy(a1,y1);


  // store values for next time
  obj->x1 = inputValue;
  obj->y1 = y0;

  return(y0);
} // end of FILTER_FO_run() function




#endif /* MOTCTL_CORE_INCLUDE_IIR_FILTER_FO_H_ */
