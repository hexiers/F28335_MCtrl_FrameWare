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

  WDOG_disable(obj->sysctrlHandle);
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

  PIE_enableAdcInt(obj->pieHandle); // 选择ADC1为中断源

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

  PIE_disable(obj->pieHandle); // 禁用Pie

  PIE_disableAllInts(obj->pieHandle);

  PIE_clearAllInts(obj->pieHandle);

  PIE_clearAllFlags(obj->pieHandle);

  PIE_setDefaultIntVectorTable(obj->pieHandle);

  PIE_enable(obj->pieHandle);

  return;
} // end of HAL_setupPie() function

//! @brief: HAL层初始化，给HAL中的各种 handle 赋真实物理地址
//! @param void *pMem
//! @param size_t numBytes
//! @return *
//! @details:

HAL_Handle HAL_init(void *pMemory, const size_t numBytes)
{
  HAL_Handle handle;
  HAL_Obj *obj;

  // 如果HAL对象实体空间不够返回空指针
  if (numBytes < sizeof(HAL_Obj))

    return ((HAL_Handle)NULL);

  // 设置句柄
  handle = (HAL_Handle)pMemory;

  // 设置HAL对象
  obj = (HAL_Obj *)handle;

  // adc初始化
  obj->adcHandle = ADC_init((void *)ADC_BASE_ADDR, sizeof(ADC_Obj));

  // initialize the CPU handle
  obj->cpuHandle = CPU_init(&cpu, sizeof(cpu));

  // initialize the FLASH handle
  obj->flashHandle = FLASH_init((void *)FLASH_BASE_ADDR, sizeof(FLASH_Obj));

  obj->gpioHandle = GPIO_init((void *)GPIO_BASE_ADDR, sizeof(GPIO_Obj));

  obj->pieHandle = PIE_init((void *)PIE_BASE_ADDR, sizeof(PIE_Obj));

  obj->sysctrlHandle = SYSCTRL_init((void *)SYSCTRL_BASE_ADDR, sizeof(SYSCTRL_Obj));
  HAL_disableWdog(handle);

  obj->pwmHandle[0] = PWM_init((void *)PWM_ePWM1_BASE_ADDR, sizeof(PWM_Obj));
  obj->pwmHandle[1] = PWM_init((void *)PWM_ePWM2_BASE_ADDR, sizeof(PWM_Obj));
  obj->pwmHandle[2] = PWM_init((void *)PWM_ePWM3_BASE_ADDR, sizeof(PWM_Obj));

  obj->sciAHandle = SCI_init((void *)SCIA_BASE_ADDR, sizeof(SCI_Obj));

  obj->timerHandle[0] = TIMER_init((void *)TIMER0_BASE_ADDR, sizeof(TIMER_Obj));
  obj->timerHandle[1] = TIMER_init((void *)TIMER0_BASE_ADDR, sizeof(TIMER_Obj));
  obj->timerHandle[2] = TIMER_init((void *)TIMER0_BASE_ADDR, sizeof(TIMER_Obj));

  obj->pwrHandle = PWR_init((void *)PWR_BASE_ADDR, sizeof(PWR_Obj));

  obj->spiAHandle = SPI_init((void *)SPIA_BASE_ADDR, sizeof(SPI_Obj));

  obj->qepHandle = QEP_init((void *)QEP1_BASE_ADDR, sizeof(QEP1_BASE_ADDR));
  obj->qepHandle = QEP_init((void *)QEP1_BASE_ADDR, sizeof(QEP2_BASE_ADDR));

  obj->offsetHandle_V[0] = OFFSET_init((void *)&obj->offsetHandle_V[0], sizeof(OFFSET_Obj));
  obj->offsetHandle_V[1] = OFFSET_init((void *)&obj->offsetHandle_V[1], sizeof(OFFSET_Obj));
  obj->offsetHandle_V[2] = OFFSET_init((void *)&obj->offsetHandle_V[2], sizeof(OFFSET_Obj));

  obj->offsetHandle_I[0] = OFFSET_init((void *)&obj->offsetHandle_I[0], sizeof(OFFSET_Obj));
  obj->offsetHandle_I[1] = OFFSET_init((void *)&obj->offsetHandle_I[1], sizeof(OFFSET_Obj));
  obj->offsetHandle_I[2] = OFFSET_init((void *)&obj->offsetHandle_I[2], sizeof(OFFSET_Obj));

  return handle;
}

void HAL_setupPLL(HAL_Handle handle, PLL_ClkFreq_e ClkFreq)
{

  HAL_Obj *obj = (HAL_Obj *)handle;

  // 确认PLL状态正常
  if (PLL_getClkStatus(obj->sysctrlHandle) != PLL_ClkStatus_Normal)
  {
    PLL_resetClkDetect(obj->sysctrlHandle);

    asm("        ESTOP0");
  }

  // Divide Select must be ClkIn/4 before the clock rate can be changed
  if (PLL_getDivideSelect(obj->sysctrlHandle) != PLL_DivideSelect_ClkIn_by_4)
  {
    PLL_setDivideSelect(obj->sysctrlHandle, PLL_DivideSelect_ClkIn_by_4);
  }

  if (PLL_getClkFreq(obj->sysctrlHandle) != ClkFreq)
  {
    // disable the clock detect
    PLL_disableClkDetect(obj->sysctrlHandle);

    // set the clock rate
    PLL_setClkFreq(obj->sysctrlHandle, ClkFreq);
  }

  // wait until locked
  while (PLL_getLockStatus(obj->sysctrlHandle) != PLL_LockStatus_Done)
  {
  }

  // enable the clock detect
  PLL_enableClkDetect(obj->sysctrlHandle);

  // set divide select to ClkIn/2 to get desired clock rate
  // NOTE: clock must be locked before setting this register
  PLL_setDivideSelect(obj->sysctrlHandle, PLL_DivideSelect_ClkIn_by_2);
}

void HAL_setupPeripheralClocks(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;

  Sys_enableAdcClock(obj->sysctrlHandle);

  ADC_cal(); // 执行ADC校正代码

  Sys_enableScibClock(obj->sysctrlHandle);

  Sys_disableTbClockSync(obj->sysctrlHandle); // 关闭Tb时钟
  Sys_enablePwmClock(obj->sysctrlHandle, PWM_Number_1);
  Sys_enablePwmClock(obj->sysctrlHandle, PWM_Number_2);
  Sys_enablePwmClock(obj->sysctrlHandle, PWM_Number_3);
  Sys_enableTbClockSync(obj->sysctrlHandle);

  Sys_enableEqep1Clock(obj->sysctrlHandle);

  Sys_enableCpuTimerClock(obj->sysctrlHandle, CLK_CpuTimerNumber_0);

  Sys_enableGpioInputClock(obj->sysctrlHandle);

  Sys_enableClkIn(obj->sysctrlHandle);

  return;
} // end of HAL_setupPeripheralClocks function

//! @brief: FLASH初始化
void HAL_setupFlash(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;

  FLASH_enablePipelineMode(obj->flashHandle);

  // 150MHz
  FLASH_setNumPagedReadWaitStates(obj->flashHandle, FLASH_NumPagedWaitStates_5);

  FLASH_setNumRandomReadWaitStates(obj->flashHandle, FLASH_NumRandomWaitStates_5);

  FLASH_setOtpWaitStates(obj->flashHandle, FLASH_NumOtpWaitStates_8);

  FLASH_setStandbyWaitCount(obj->flashHandle, FLASH_ACTIVE_WAIT_COUNT_DEFAULT);

  FLASH_setActiveWaitCount(obj->flashHandle, FLASH_STANDBY_WAIT_COUNT_DEFAULT);

  asm(" RPT #7 || NOP");

  return;
}

void HAL_setupSci(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;

  // 打开接受、发送，关闭睡眠模式
  SCI_enableRx(obj->sciAHandle);
  SCI_enableTx(obj->sciAHandle);
  SCI_disableSleep(obj->sciAHandle);
  SCI_disableRxErrorInt(obj->sciAHandle);

  // 禁用发送接收中断
  SCI_disableRxInt(obj->sciAHandle);
  SCI_disableTxInt(obj->sciAHandle);

  // 数据格式设置
  SCI_setCharLength(obj->sciAHandle, SCI_CharLength_8_Bits);
  SCI_disableLoopBack(obj->sciAHandle);
  SCI_disableParity(obj->sciAHandle);
  SCI_setMode(obj->sciAHandle, SCI_Mode_IdleLine);
  SCI_setNumStopBits(obj->sciAHandle, SCI_NumStopBits_One);

  // 波特率设置
  SCI_setBaudRate(obj->sciAHandle, SCI_BaudRate_115_2_kBaud);

  // fifo设置
  SCI_disableTxFifoEnh(obj->sciAHandle);
  SCI_disableTxFifoInt(obj->sciAHandle);
  SCI_clearTxFifoInt(obj->sciAHandle);

  SCI_enableRxFifoInt(obj->sciAHandle);
  SCI_setRxFifoIntLevel(obj->sciAHandle, SCI_FifoLevel_12_Words);
  SCI_clearRxFifoInt(obj->sciAHandle);
  SCI_clearRxFifoOvf(obj->sciAHandle);

  // 设置完毕，复位所有寄存器
  SCI_reset(obj->sciAHandle);
  SCI_resetRxFifo(obj->sciAHandle);

  return;
}

void HAL_setParams(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;

  // 关闭全局中断
  CPU_disableGlobalInts(obj->cpuHandle);

  // 清除CPU的中断标志位
  CPU_clearIntFlags(obj->cpuHandle);

  // // 打开外设时钟
  // HAL_setupClks(handle);

  // 设置 PLL 时钟
  HAL_setupPLL(handle, PLL_ClkFreq_150_MHz);

  // 打开外设时钟
  HAL_setupPeripheralClocks(handle);

  // setup the PIE
  HAL_setupPie(handle);

  HAL_setupFlash(handle);

  HAL_setupSci(handle);

  return;
}