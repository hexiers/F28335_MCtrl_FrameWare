/*
 * @Author: Hex
 * @Date: 2023-08-20 08:44:27
 * @LastEditors: Hexer hex@hust.edu.cn
 * @LastEditTime: 2023-08-20 10:00:35
 * @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_Core\Include\iPark.h
 * @Description: 
 */

#ifndef MOTCTL_CORE_INCLUDE_IPARK_H_
#define MOTCTL_CORE_INCLUDE_IPARK_H_

// include files*************************************************************
#include "IQmathLib.h"
#include "math.h"
#include "types.h"


// defines 宏定义*************************************************************


// typedef 类定义*************************************************************
//! \brief 定义ipark对象
typedef struct _IPARK_Obj_
{

  _iq  sinTh;      
  _iq  cosTh;      

} IPARK_Obj;

//! \brief 定义ipark句柄
typedef struct _IPARK_Obj_* IPARK_Handle;

// 函数方法*******************************************************************
//! \brief     Gets the cosine of the angle between the d,q and the alpha,beta coordinate systems
//! \param[in] handle  The inverse Park transform handle
//! \return    The cosine of the angle
static inline _iq IPARK_getCosTh(IPARK_Handle handle)
{
  IPARK_Obj *obj = (IPARK_Obj *)handle;

  return(obj->cosTh);
} // end of IPARK_getCosTh() function


//! \brief     Gets the cosine/sine phasor for the inverse Park transform
//! \param[in] handle  The inverse Park transform handle
//! \param[in] pPhasor      The pointer to the cosine/sine phasor
static inline void IPARK_getPhasor(IPARK_Handle handle,MATH_vec2 *pPhasor)
{
  IPARK_Obj *obj = (IPARK_Obj *)handle;

  pPhasor->value[0] = obj->cosTh;
  pPhasor->value[1] = obj->sinTh;

  return;
} // end of IPARK_getPhasor() function


//! \brief     Gets the sine of the angle between the d,q and the alpha,beta coordinate systems
//! \param[in] handle  The inverse Park transform handle
//! return     The sine of the angle
static inline _iq IPARK_getSinTh(IPARK_Handle handle)
{
  IPARK_Obj *obj = (IPARK_Obj *)handle;

  return(obj->sinTh);
} // end of IPARK_getSinTh() function


//! \brief     Initializes the inverse Park transform module
//! \param[in] pMemory      A pointer to the memory for the inverse Park object
//! \param[in] numBytes     The number of bytes allocated for the inverse Park object, bytes
//! \return The inverse Park (IPARK) object handle
extern IPARK_Handle IPARK_init(void *pMemory,const size_t numBytes);


//! \brief     Runs the inverse Park transform module
//! \param[in] handle  The inverse Park transform handle
//! \param[in] pInVec       The pointer to the input vector
//! \param[in] pOutVec      The pointer to the output vector
static inline void IPARK_run(IPARK_Handle handle,const MATH_vec2 *pInVec,MATH_vec2 *pOutVec)
{
  IPARK_Obj *obj = (IPARK_Obj *)handle;

  _iq sinTh = obj->sinTh;
  _iq cosTh = obj->cosTh;

  _iq value_0 = pInVec->value[0];
  _iq value_1 = pInVec->value[1];

  pOutVec->value[0] = _IQmpy(value_0,cosTh) - _IQmpy(value_1,sinTh);
  pOutVec->value[1] = _IQmpy(value_1,cosTh) + _IQmpy(value_0,sinTh);

  return;
} // end of IPARK_run() function


//! \brief     Sets the cosine of the angle between the d,q and the alpha,beta coordinate systems
//! \param[in] handle  The inverse Park transform handle
//! \param[in] cosTh   The cosine of the angle
static inline void IPARK_setCosTh(IPARK_Handle handle,const _iq cosTh)
{
  IPARK_Obj *obj = (IPARK_Obj *)handle;

  obj->cosTh = cosTh;

  return;
} // end of IPARK_setCosTh() function


//! \brief     Sets the cosine/sine phasor for the inverse Park transform
//! \param[in] handle   The inverse Park transform handle
//! \param[in] pPhasor  The pointer to the cosine/sine phasor, pu
static inline void IPARK_setPhasor(IPARK_Handle handle,const MATH_vec2 *pPhasor)
{
  IPARK_Obj *obj = (IPARK_Obj *)handle;

  obj->cosTh = pPhasor->value[0];
  obj->sinTh = pPhasor->value[1];

  return;
} // end of IPARK_setPhasor() function


//! \brief     Sets the sine of the angle between the d,q and the alpha,beta coordinate systems
//! \param[in] handle  The inverse Park transform handle
//! \param[in] sinTh   The sine of the angle
static inline void IPARK_setSinTh(IPARK_Handle handle,const _iq sinTh)
{
  IPARK_Obj *obj = (IPARK_Obj *)handle;

  obj->sinTh = sinTh;

  return;
} // end of IPARK_setSinTh() function


//! \brief     Sets up the inverse Park transform module
//! \param[in] handle  The inverse Park transform handle
//! \param[in] Th_pu   The angle between the d,q and the alpha,beta coordinate systems, pu
static inline void IPARK_setup(IPARK_Handle handle,const _iq Th_pu)
{
  IPARK_Obj *obj = (IPARK_Obj *)handle;

  obj->sinTh = _IQsinPU(Th_pu);
  obj->cosTh = _IQcosPU(Th_pu);

  return;
} // end of IPARK_setup() function



#endif  // END OF MOTCTL_CORE_INCLUDE_IPARK_H_