/*****************************************************************************
 * File name: 	IIR_Filter_Fo.c
 *    Author: 	Hex
 *	  E-mail: 	hex@hust.edu.cn
 *    Date  : 	2023Äê8ÔÂ20ÈÕ
 *	  Description: 
 *****************************************************************************/


// ************************   includes   ********************************************
#include "IIR_Filter_Fo.h"



FILTER_FO_Handle FILTER_FO_init(void *pMemory, const size_t numBytes)
{
    FILTER_FO_Handle handle;

    if (numBytes < sizeof(FILTER_FO_Obj))
        return ((FILTER_FO_Handle)NULL);

    // assign the handle
    handle = (FILTER_FO_Handle)pMemory;

    return (handle);
} // end of FILTER_FO_init() function