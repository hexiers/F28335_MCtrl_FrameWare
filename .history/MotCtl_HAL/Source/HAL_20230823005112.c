//! @Author: Hex
//! @Date: 2023-08-20 21:25:26
//! @LastEditTime: 2023-08-22 19:38:21
//! @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_HAL\Source\HAL.c
//! @Description: HAL操作函数，

/********************************** INCLUDE Files ***************************************************/
#include "HAL.h"
#include "hal_obj.h"

#ifdef FLASH
#pragma CODE_SECTION(HAL_setupFlash, "ramfuncs");
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

    FLASH_setNumPagedReadWaitStates(obj->flashHandle, FLASH_NumPagedWaitStates_2);

    FLASH_setNumRandomReadWaitStates(obj->flashHandle, FLASH_NumRandomWaitStates_2);

    FLASH_setOtpWaitStates(obj->flashHandle, FLASH_NumOtpWaitStates_3);

    FLASH_setStandbyWaitCount(obj->flashHandle, FLASH_STANDBY_WAIT_COUNT_DEFAULT);

    FLASH_setActiveWaitCount(obj->flashHandle, FLASH_ACTIVE_WAIT_COUNT_DEFAULT);

    return;
} // HAL_setupFlash() function

//! @brief:禁用看门狗函数
//! @param HAL_Handle handle
//! @return *
//! @details:
void HAL_disableWdog(HAL_Handle handle)
{
    HAL_Obj *obj = (HAL_Obj *)handle;

    WDOG_disable(obj->wdogHandle);
}

//! @brief: 禁用全局中断
//! @param HAL_Handle handle
//! @return *
//! @details:
void HAL_disableGlobalInts(HAL_Handle handle)
{
    HAL_Obj *obj = (HAL_Obj *)handle;

    CPU_disableGlobalInts(obj->cpuHandle);
}

void HAL_EnableAdcInts(HAL_Handle handle)
{
    HAL_Obj *obj = (HAL_Obj *)handle;

    PIE_enableAdcInt(obj->adcHandle, ADC_IntNumber_1); // 选择ADC1为中断源

    ADC_enableInt(obj->adcHandle, ADC_IntNumber_1); // 使能ADC中断

    CPU_enableInt(obj->cpuHandle, CPU_IntNumber_10); // 打开CPU中断

    return;
}

//! @brief: 设置 PIE
//! @param HAL_Handle handle
//! @return *
//! @details:

void HAL_setupPie(HAL_Handle handle)
{
    HAL_Obj *obj = (HAL_Obj *)handle;

    PIE_disable(obj->pieHandle);  //禁用Pie

    PIE_disableAllInts(obj->pieHandle);

    PIE_clearAllInts(obj->pieHandle);

    PIE_clearAllFlags(obj->pieHandle);

    PIE_setDefaultIntVectorTable(obj->pieHandle);

    PIE_enable(obj->pieHandle);

    return;
} // end of HAL_setupPie() function


void HAL_setParams(HAL_Handle handle)
{
    HAL_Obj *obj = (HAL_Obj *)handle;	
   
   // 关闭全局中断
  CPU_disableGlobalInts(obj->cpuHandle);

  // 清除CPU的中断标志位
  CPU_clearIntFlags(obj->cpuHandle);

  //TODO 设置 PLL 时钟 
  HAL_setupPll(handle,PLL_ClkFreq_60_MHz);

  // setup the PIE
  HAL_setupPie(handle);


    return ;
}


//! @brief: HAL层初始化，给HAL中的各种 handle 赋真实物理地址
//! @param void *pMem
//! @param size_t numBytes
//! @return *
//! @details: 

HAL_Handle HAL_init(void *pMem, const size_t numBytes) 
{
    HAL_Handle  handle;	 
    HAL_Obj     *obj;
    
    // 如果HAL对象实体空间不够返回空指针
    if(numBytes < sizeof(HAL_Obj))

        return((HAL_Handle)NULL);

    // 设置句柄
    handle = (HAL_Handle) pMem;

    // 设置HAL对象
    obj = (HAL_Obj *)handle;

    handle->adcHandle = ADC_init(ADC_BASE_ADDR,sizeof(ADC_Obj));


   
    return handle;
}

