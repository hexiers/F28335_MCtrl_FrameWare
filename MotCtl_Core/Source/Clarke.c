/*
 * @Author: Hex
 * @Date: 2023-08-01 10:59:51
 * @LastEditors: Hexer hex@hust.edu.cn
 * @LastEditTime: 2023-08-20 09:39:00
 * @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_Core\Source\Clarke.c
 * @Description: 
 */

// **************************************************************************
// the includes

#include "Clarke.h"


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


