
//! @Author: Hex
//! @Date: 2023-08-20 21:25:26
//! @LastEditTime: 2023-08-22 19:38:21
//! @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_HAL\Source\HAL.c
//! @Description: 


/********************************** INCLUDE Files ***************************************************/
#include "HAL.h"
#include "hal_obj.h"

#ifdef FLASH
#pragma CODE_SECTION(HAL_setupFlash,"ramfuncs");
#endif

/********************************** 函数方法  function ************************************************/

//! @brief: 设置FLash
//! @param HAL_Handle handle
//! @return *
//! @details: 

void HAL_setupFlash(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;

  FLASH_enablePipelineMode(obj->flashHandle);

  FLASH_setNumPagedReadWaitStates(obj->flashHandle,FLASH_NumPagedWaitStates_2);

  FLASH_setNumRandomReadWaitStates(obj->flashHandle,FLASH_NumRandomWaitStates_2);

  FLASH_setOtpWaitStates(obj->flashHandle,FLASH_NumOtpWaitStates_3);

  FLASH_setStandbyWaitCount(obj->flashHandle,FLASH_STANDBY_WAIT_COUNT_DEFAULT);

  FLASH_setActiveWaitCount(obj->flashHandle,FLASH_ACTIVE_WAIT_COUNT_DEFAULT);

  return;
} // HAL_setupFlash() function
