/*****************************************************************************
 * File name: 	offset.c
 *    Author: 	Hex
 *	  E-mail: 	hex@hust.edu.cn
 *    Date  : 	2023Äê8ÔÂ20ÈÕ
 *	  Description: 
 *****************************************************************************/

#include "../../../MotCtl_Driver/Include/offset.h"


_iq OFFSET_getBeta(OFFSET_Handle handle)
{
  OFFSET_Obj *obj = (OFFSET_Obj *)handle;
  _iq b0;
  _iq b1;

  FILTER_FO_getNumCoeffs(obj->filterHandle,&b0,&b1);

  return(b0);
} // end of OFFSET_getBeta() function


OFFSET_Handle OFFSET_init(void *pMemory,const size_t numBytes)
{
  OFFSET_Handle handle;
  OFFSET_Obj *obj;

  if(numBytes < sizeof(OFFSET_Obj))
    return((OFFSET_Handle)NULL);

  // assign the handle
  handle = (OFFSET_Handle)pMemory;
  obj = (OFFSET_Obj *)handle;

  obj->filterHandle = FILTER_FO_init(&(obj->filter),sizeof(obj->filter));

  return(handle);
} // end of OFFSET_init() function


void OFFSET_setBeta(OFFSET_Handle handle,const _iq beta)
{
  OFFSET_Obj *obj = (OFFSET_Obj *)handle;
  _iq a1 = (beta - _IQ(1.0));
  _iq b0 = beta;
  _iq b1 = 0;

  FILTER_FO_setDenCoeffs(obj->filterHandle,a1);
  FILTER_FO_setNumCoeffs(obj->filterHandle,b0,b1);

  return;
} // end of OFFSET_setBeta() function


void OFFSET_setInitCond(OFFSET_Handle handle,const _iq initCond)
{
  OFFSET_Obj *obj = (OFFSET_Obj *)handle;

  FILTER_FO_setInitialConditions(obj->filterHandle,initCond,initCond);
  obj->value = initCond;

  return;
} // end of OFFSET_setInitCond() function


void OFFSET_setOffset(OFFSET_Handle handle, _iq offsetValue)
{
  OFFSET_Obj *obj = (OFFSET_Obj *)handle;

  obj->value = offsetValue;

  return;
} // end of OFFSET_setOffset() function

