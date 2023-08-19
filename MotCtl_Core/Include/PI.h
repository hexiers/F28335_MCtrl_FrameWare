/*
 * PI.h
 *
 *  Created on: 2023��8��1��
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

//! \brief   ����PI����������
//!
typedef struct _PI_Obj_
{
  _iq Kp;                     //!<  ������Kp
  _iq Ki;                     //!< 	������Ki

  _iq Ui;                     //!< �����ۼ�ֵ

  _iq refValue;               //!< �ο�����
  _iq fbackValue;             //!< ������

  _iq outMin;                 //!< �޷���С�����
  _iq outMax;                 //!< �޷���������

} PI_Obj;


//! \brief  ����PI���
//!
typedef struct _PI_Obj_ *PI_Handle;


// **************************************************************************
// ����ԭ��

//! \brief     ��ȡ����ֵ
//! \param[in]
//! \return
static inline _iq PI_getFbackValue(PI_Handle handle)
{
  PI_Obj *obj = (PI_Obj *)handle;

  return(obj->fbackValue);
} // end of PI_getFbackValue()


//! \brief      ��ȡPi����
static inline void PI_getGains(PI_Handle handle,_iq *pKp,_iq *pKi)
{
  PI_Obj *obj = (PI_Obj *)handle;

  *pKp = obj->Kp;
  *pKi = obj->Ki;

  return;
} // end of PI_getGains() function


//! \brief  ��ȡPi��������
//
static inline _iq PI_getKi(PI_Handle handle)
{
  PI_Obj *obj = (PI_Obj *)handle;

  return(obj->Ki);
} // end of PI_getKi()


//! \brief  ��ȡPi��������
//
static inline _iq PI_getKp(PI_Handle handle)
{
  PI_Obj *obj = (PI_Obj *)handle;

  return(obj->Kp);
} // end of PI_getKp()

//TO DO
//! \brief  ��ȡPi�����С���
//
static inline void PI_getMinMax(PI_Handle handle,_iq *pOutMin,_iq *pOutMax)
{
  PI_Obj *obj = (PI_Obj *)handle;

  *pOutMin = obj->outMin;
  *pOutMax = obj->outMax;

  return;
} // end of PI_getMinMax() function


//! \brief      ��ȡPi������
//!
static inline _iq PI_getOutMax(PI_Handle handle)
{
  PI_Obj *obj = (PI_Obj *)handle;

  return(obj->outMax);
} // end of PID_getOutMax()


//! \brief      ��ȡPi��С���
//!
static inline _iq PI_getOutMin(PI_Handle handle)
{
  PI_Obj *obj = (PI_Obj *)handle;

  return(obj->outMin);
} // end of PID_getOutMax()


//! \brief     ��ȡPI�Ĳο�ֵ
//!
static inline _iq PI_getRefValue(PI_Handle handle)
{
  PI_Obj *obj = (PI_Obj *)handle;

  return(obj->refValue);
} // end of PI_getRefValue()


//! \brief    ��ȡ�����ۼ�ֵ
//!
static inline _iq PI_getUi(PI_Handle handle)
{
  PI_Obj *obj = (PI_Obj *)handle;

  return(obj->Ui);
} // end of PID_getUi()


//! \brief    PI��������ʼ��
extern PI_Handle PI_init(void *pMemory,const size_t numBytes);


//! \brief     PI���з����������ͣ�
//! \param[in] handle      PI���
//! \param[in] refValue    �ο�����
//! \param[in] fbackValue  ����������ֵ
//! \param[in] pOutValue   �������ָ��
static inline void PI_run(PI_Handle handle,const _iq refValue,const _iq fbackValue,_iq *pOutValue)
{
  PI_Obj *obj = (PI_Obj *)handle;

  _iq Error;
  _iq Up,Ui;


  Error = refValue - fbackValue;

  Ui = obj->Ui;                                                  // ������һʱ�̵Ļ���ֵ
  Up = _IQmpy(obj->Kp,Error);                                    // ����������
  Ui = _IQsat(Ui + _IQmpy(obj->Ki,Up),obj->outMax,obj->outMin);  // ����������

  obj->Ui = Ui;                                                  // �洢�����ۼ�ֵ
  obj->refValue = refValue;
  obj->fbackValue = fbackValue;

  *pOutValue = _IQsat(Up + Ui,obj->outMax,obj->outMin);          // �޷�

  return;
} // end of PI_run()


//! \brief  ����PI�ķ�������
//!
static inline void PI_setFbackValue(PI_Handle handle,const _iq fbackValue)
{
  PI_Obj *obj = (PI_Obj *)handle;

  obj->fbackValue = fbackValue;

  return;
} // end of PI_setFbackValue()


//! \brief  ����PI�Ĳ���
static inline void PI_setGains(PI_Handle handle,const _iq Kp,const _iq Ki)
{
  PI_Obj *obj = (PI_Obj *)handle;

  obj->Kp = Kp;
  obj->Ki = Ki;

  return;
} // end of PI_setGains()


//! \brief   ����PI��Ki

static inline void PI_setKi(PI_Handle handle,const _iq Ki)
{
  PI_Obj *obj = (PI_Obj *)handle;

  obj->Ki = Ki;

  return;
} // end of PI_setKi()


//! \brief  ����PI��Kp
//!
static inline void PI_setKp(PI_Handle handle,const _iq Kp)
{
  PI_Obj *obj = (PI_Obj *)handle;

  obj->Kp = Kp;

  return;
} // end of PI_setKp()


//! \brief  ����PI�������Сֵ
//!
static inline void PI_setMinMax(PI_Handle handle,const _iq outMin,const _iq outMax)
{
  PI_Obj *obj = (PI_Obj *)handle;

  obj->outMin = outMin;
  obj->outMax = outMax;

  return;
} // end of PI_setMinMax() function


//! \brief  ����PI�����ֵ
//!
static inline void PI_setOutMax(PI_Handle handle,const _iq outMax)
{
  PI_Obj *obj = (PI_Obj *)handle;

  obj->outMax = outMax;

  return;
} // end of PI_setOutMax()


//! \brief  ����PI����Сֵ
//!
static inline void PI_setOutMin(PI_Handle handle,const _iq outMin)
{
  PI_Obj *obj = (PI_Obj *)handle;

  obj->outMin = outMin;

  return;
} // end of PI_setOutMin()


//! \brief  ����PI�Ĳο�ֵ
//!
static inline void PI_setRefValue(PI_Handle handle,const _iq refValue)
{
  PI_Obj *obj = (PI_Obj *)handle;

  obj->refValue = refValue;

  return;
} // end of PI_setRefValue()


//! \brief   ����PI�Ļ����ۼ�ֵ
static inline void PI_setUi(PI_Handle handle,const _iq Ui)
{
  PI_Obj *obj = (PI_Obj *)handle;

  obj->Ui = Ui;

  return;
} // end of PI_setUi()


#endif /* MOTCTL_CORE_INCLUDE_PI_H_ */
