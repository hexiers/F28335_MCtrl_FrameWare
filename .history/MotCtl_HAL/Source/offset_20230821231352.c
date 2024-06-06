
//! @Author: Hex
//! @Date: 2023-08-20 21:25:26
//! @LastEditTime: 2023-08-21 23:13:45
//! @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_HAL\Source\offset.c
//! @Description: 


//! @Author: Hex
//! @Date: 2023-08-20 21:25:26
//! @LastEditTime: 2023-08-21 23:13:07
//! @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_HAL\Source\offset.c
//! @Description: 

/*****************************************************************************
 * File name: 	offset.c
 *    Author: 	Hex
 *	  E-mail: 	hex@hust.edu.cn
 *    Date  : 	2023年8月20日
 *	  Description:
 *****************************************************************************/

#include "../../MotCtl_Driver/Include/offset.h"

//! \brief     Gets the beta offset filter coefficient
//! \param[in] handle  The offset handle
//! \return The filter coefficient beta
_iq OFFSET_getBeta(OFFSET_Handle handle)
{
    OFFSET_Obj *obj = (OFFSET_Obj *)handle;
    _iq b0;
    _iq b1;

    FILTER_FO_getNumCoeffs(obj->filterHandle, &b0, &b1);

    return (b0);
} // end of OFFSET_getBeta() function

//! \brief     Initializes the offset
//! \param[in] pMemory   A pointer to the memory for the offset object
//! \param[in] numBytes  The number of bytes allocated for the offset object, bytes
//! \return The offset (OFFSET) object handle
OFFSET_Handle OFFSET_init(void *pMemory, const size_t numBytes)
{
    OFFSET_Handle handle;
    OFFSET_Obj *obj;

    if (numBytes < sizeof(OFFSET_Obj))
        return ((OFFSET_Handle)NULL);

    // assign the handle
    handle = (OFFSET_Handle)pMemory;
    obj = (OFFSET_Obj *)handle;

    obj->filterHandle = FILTER_FO_init(&(obj->filter), sizeof(obj->filter));

    return (handle);
} // end of OFFSET_init() function

//! \brief     Sets the beta offset filter coefficient
//! \param[in] handle  The offset handle
//! \param[in] beta          The offset filter coefficient beta
void OFFSET_setBeta(OFFSET_Handle handle, const _iq beta)
{
    OFFSET_Obj *obj = (OFFSET_Obj *)handle;
    _iq a1 = (beta - _IQ(1.0));
    _iq b0 = beta;
    _iq b1 = 0;

    FILTER_FO_setDenCoeffs(obj->filterHandle, a1);
    FILTER_FO_setNumCoeffs(obj->filterHandle, b0, b1);

    return;
} // end of OFFSET_setBeta() function

//! \brief     Set the initial condition of the integrator or the value of y[n-1]
//! \param[in] handle  The offset handle
//! \param[in] initCond      The mean value that the filter will approximate to
void OFFSET_setInitCond(OFFSET_Handle handle, const _iq initCond)
{
    OFFSET_Obj *obj = (OFFSET_Obj *)handle;

    FILTER_FO_setInitialConditions(obj->filterHandle, initCond, initCond);
    obj->value = initCond;

    return;
} // end of OFFSET_setInitCond() function

//! \brief     Sets the offset value
//! \param[in] handle  The offset handle
//! \param[in] offsetValue   The offset value
void OFFSET_setOffset(OFFSET_Handle handle, _iq offsetValue)
{
    OFFSET_Obj *obj = (OFFSET_Obj *)handle;

    obj->value = offsetValue;

    return;
} // end of OFFSET_setOffset() function
