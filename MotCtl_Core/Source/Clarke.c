/*
 * Clarke.c
 *
 *  Created on: 2023??8??1??
 *      Author: Hex
 */

// **************************************************************************
// the includes

#include "ClarkeTrans.h"


// **************************************************************************
//

CLARKE_Handle CLARKE_init(void *pMemory,const size_t numBytes)
{
  CLARKE_Handle handle;

  if(numBytes < sizeof(CLARKE_Obj))
    return((CLARKE_Handle)NULL);

  // assign the handle
  handle = (CLARKE_Handle)pMemory;

  return(handle);
} // end of CLARKE_init() function


