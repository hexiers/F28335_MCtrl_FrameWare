/*
 * PI.c
 *
 *  Created on: 2023年8月1日
 *      Author: Hex
 */


// **************************************************************************
// the includes

#include "PI.h"


// **************************************************************************
// the functions


PI_Handle PI_init(void *pMemory,const size_t numBytes)
{
	PI_Handle handle;

	if(numBytes < sizeof(PI_Obj))

	  return((PI_Handle)NULL);

	// 设置句柄
	handle = (PI_Handle)pMemory;

	// 设置默认值
	PI_setUi(handle,_IQ(0.0));
	PI_setRefValue(handle,_IQ(0.0));
	PI_setFbackValue(handle,_IQ(0.0));

	return(handle);
} // end of PI_init()

// end of file

