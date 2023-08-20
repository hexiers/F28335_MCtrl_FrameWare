/*****************************************************************************
 * File name: 	IIR_Filter_Fo.h
 *    Author: 	Hex
 *	  E-mail: 	hex@hust.edu.cn
 *    Date  : 	2023��8��20��
 *	  Description: ����IIR�͵�һ���˲����������������˲�����
 *                 IIR ���˲�����ʽ��ʾΪ��y[n] = a * x[n] + (1 - a) * y[n-1]
 *****************************************************************************/
#ifndef MOTCTL_CORE_INCLUDE_IIR_FILTER_FO_H_
#define MOTCTL_CORE_INCLUDE_IIR_FILTER_FO_H_

// **********************include files*************************************************************
#include "types.h"
#include "IQmathLib.h"

// �궨�� defines ***********************************************************

// **********************  typedef �ඨ�� ***********************************************************
//! \brief ����IIR�͵�һ���˲�������FO,First oder��
//!
typedef struct _FILTER_FO_
{
    _iq a1; // ��һ�����y[n-1]��ϵ��

    _iq b0; // ��ǰ����x[n]��ϵ��
    _iq b1; // ��һ������x[n-1]��ϵ��

    _iq x1; // ��һ������x[n-1]��ֵ

    _iq y1; // ��һ�����y[n-1]��ֵ
} FILTER_FO_Obj;

//! \brief ���� (FILTER_FO) ���
//!
typedef struct _FILTER_FO_Obj_ *FILTER_FO_Handle;

//  **********************************  �������� **************************************************

//! \brief     ����IIRһ���˲���
//!            y[n] = b0*x[n] + b1*x[n-1] - a1*y[n-1]
//!
//! \param[in] handle
//! \param[in] inputValue  �˲�������ֵ
//! \return �˲������ֵ
static inline _iq FILTER_FO_run(FILTER_FO_Handle handle, const _iq inputValue)
{
    FILTER_FO_Obj *obj = (FILTER_FO_Obj *)handle;

    _iq a1 = obj->a1;
    _iq b0 = obj->b0;
    _iq b1 = obj->b1;
    _iq x1 = obj->x1;
    _iq y1 = obj->y1;

    // �������ֵ
    _iq y0 = _IQmpy(b0, inputValue) + _IQmpy(b1, x1) - _IQmpy(a1, y1);

    // �洢��һ������ֵ
    obj->x1 = inputValue;
    obj->y1 = y0;

    return (y0);
} // end of FILTER_FO_run()

static inline void FILTER_FO_getInitialConditions(FILTER_FO_Handle handle, _iq *px1, _iq *py1)
{
    FILTER_FO_Obj *obj = (FILTER_FO_Obj *)handle;

    *px1 = obj->x1;

    *py1 = obj->y1;

    return;
} // end of FILTER_FO_getInitialConditions() function

static inline void FILTER_FO_setDenCoeffs(FILTER_FO_Handle handle, const _iq a1)
{
    FILTER_FO_Obj *obj = (FILTER_FO_Obj *)handle;

    obj->a1 = a1;

    return;
} // end of FILTER_FO_setDenCoeffs() function

static inline void FILTER_FO_setInitialConditions(FILTER_FO_Handle handle, const _iq x1, const _iq y1)
{
    FILTER_FO_Obj *obj = (FILTER_FO_Obj *)handle;

    obj->x1 = x1;

    obj->y1 = y1;

    return;
} // end of FILTER_FO_setInitialConditions() function

static inline void FILTER_FO_setNumCoeffs(FILTER_FO_Handle handle, const _iq b0, const _iq b1)
{
    FILTER_FO_Obj *obj = (FILTER_FO_Obj *)handle;

    obj->b0 = b0;
    obj->b1 = b1;

    return;
} // end of FILTER_FO_setNumCoeffs() function

#endif /* MOTCTL_CORE_INCLUDE_IIR_FILTER_FO_H_ */
