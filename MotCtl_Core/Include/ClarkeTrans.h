/*
 * ClarkeTrans.h
 *
 *  Created on: 2023��7��31��
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
// ���Ͷ���
// **************************************************************************
// the typedefs

//! \brief  ���� CLARKE ����
//!
typedef struct _CLARKE_Obj_
{
	_iq     alpha_sf;      					//!< alpha ����ϵ��
	_iq     beta_sf;      					//!< alpha ����ϵ��

	uint_least8_t  numSensors;   			//!< ����������

} CLARKE_Obj;


//! \brief 	���� CLARKE ���
//!
typedef struct _CLARKE_Obj_ *CLARKE_Handle;


// **************************************************************************
// ͨ�÷���
// **************************************************************************
// ����ԭ��           


//! \brief     ��ȡ����������
//! \param[in] handle ��Clarke�����
//! \return    ����������
static inline uint_least8_t CLARKE_getNumSensors(CLARKE_Handle handle)
{
  CLARKE_Obj *obj = (CLARKE_Obj *)handle;

  return(obj->numSensors);
} // ���� CLARKE_getNumSensors()


//! \brief     ��ʼ��
//! \param[in] pMemory   ָ�� Clarke ����ָ��
//! \param[in] numBytes  The number of bytes allocated for the Clarke object, bytes
//! \return The Clarke (CLARKE) object handle
extern CLARKE_Handle CLARKE_init(void *pMemory,const size_t numBytes);


//! \brief     ִ�������� Clarke �任
//! \param[in] handle  	Clarke ���
//! \param[in] pInVec   ָ������ʸ��
//! \param[in] pOutVec  ָ�����ʸ��
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
} // ���� CLARKE_run() function


//! \brief     �趨����������                
//! \param[in] handle
//! \param[in] numSensors
static inline void CLARKE_setNumSensors(CLARKE_Handle handle,const uint_least8_t numSensors)
{
  CLARKE_Obj *obj = (CLARKE_Obj *)handle;

  obj->numSensors = numSensors;

  return;
} // ���� CLARKE_setNumSensors()


//! \brief     �趨�任ϵ��
//! \param[in] handle
//! \param[in] alpha_sf      T
//! \param[in] beta_sf
static inline void CLARKE_setScaleFactors(CLARKE_Handle handle,const _iq alpha_sf,const _iq beta_sf)
{
  CLARKE_Obj *obj = (CLARKE_Obj *)handle;


  obj->alpha_sf = alpha_sf;
  obj->beta_sf = beta_sf;

  return;
} //���� CLARKE_setScaleFactors()


#endif /* MOTCTL_CORE_INCLUDE_CLARKETRANS_H_ */
