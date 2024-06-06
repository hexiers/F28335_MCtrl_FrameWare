/*
 * Park.c
 *
 *  Created on: 2023年8月1日
 *      Author: Hex
 */

// **************************************************************************
// the includes

#include "Park.h"

// **************************************************************************
// the functions

PARK_Handle PARK_init(void *pMemory, const size_t numBytes)
{
    PARK_Handle handle;

    if (numBytes < sizeof(PARK_Obj))
        return ((PARK_Handle)NULL);

    // assign the handle
    handle = (PARK_Handle)pMemory;

    return (handle);
} // end of PARK_init() function

// end of file
