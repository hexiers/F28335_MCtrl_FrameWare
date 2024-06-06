//! @Author: Hex
//! @Date: 2023-08-20 21:25:26
//! @LastEditTime: 2023-08-22 19:38:21
//! @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_HAL\Source\HAL.c
//! @Description: HAL操作函数，

/********************************** INCLUDE Files ***************************************************/
#include "HAL.h"
#include "hal_obj.h"
#include "DSP2833x_Examples.h"

#ifdef FLASH
#pragma CODE_SECTION(HAL_setupFlash, "ramfuncs");
#endif

/********************************** 函数方法  function ************************************************/

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

  //ADC_enableInt(obj->adcHandle, ADC_IntNumber_1); // 使能ADC中断

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

  obj->sciBHandle = SCI_init((void *)SCIB_BASE_ADDR, sizeof(SCI_Obj));

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

  //Sys_enableClkIn(obj->sysctrlHandle);

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
  SCI_enableRx(obj->sciBHandle);
  SCI_enableTx(obj->sciBHandle);
  SCI_disableSleep(obj->sciBHandle);
  SCI_disableRxErrorInt(obj->sciBHandle);

  // 禁用发送接收中断
  SCI_disableRxInt(obj->sciBHandle);
  SCI_disableTxInt(obj->sciBHandle);

  // 数据格式设置
  SCI_setCharLength(obj->sciBHandle, SCI_CharLength_8_Bits);
  SCI_disableLoopBack(obj->sciBHandle);
  SCI_disableParity(obj->sciBHandle);
  SCI_setMode(obj->sciBHandle, SCI_Mode_IdleLine);
  SCI_setNumStopBits(obj->sciBHandle, SCI_NumStopBits_One);

  // 波特率设置
  SCI_setBaudRate(obj->sciBHandle, SCI_BaudRate_115_2_kBaud);

  // fifo设置
  SCI_disableTxFifoEnh(obj->sciBHandle);
  SCI_disableTxFifoInt(obj->sciBHandle);
  SCI_clearTxFifoInt(obj->sciBHandle);

  SCI_enableRxFifoInt(obj->sciBHandle);
  SCI_setRxFifoIntLevel(obj->sciBHandle, SCI_FifoLevel_12_Words);
  SCI_clearRxFifoInt(obj->sciBHandle);
  SCI_clearRxFifoOvf(obj->sciBHandle);

  // 设置完毕，复位所有寄存器
  SCI_reset(obj->sciBHandle);
  SCI_resetRxFifo(obj->sciBHandle);

  return;
}

void HAL_setupAdc(HAL_Handle handle)
{
  ADC_Obj* adcHandle = (ADC_Obj *)handle->adcHandle;

  uint16_t i = 0;
  
  ENABLE_PROTECTED_REGISTER_WRITE_MODE;

  ADC_reset(adcHandle);

  for(i = 0;i<100;i++)	NOP;	

  ADC_setSuspendMode(adcHandle,ADC_SUS_StopImmediately);

  ADC_setAcqWindowSize(adcHandle,ADC_SOC_PulseClk_5);

	ADC_setClockPrescale(adcHandle,ADC_HSPCLK_Div_1 ,ADC_CLKPS_Div_10);

  ADC_setRunMode(adcHandle,ADC_Continuous_mode);

	ADC_setSeqMode(adcHandle,ADC_SeqMode_DualSeq,ADC_SeqOvrd_disabled);

  ADC_setRefSource(adcHandle,ADC_InnerRef);

	for(i=0;i<100;i++)	NOP;

	ADC_setADCBGRFDN(adcHandle,ADC_BGRF_Powerup);

	for(i=0;i<10000;i++)	NOP;

  ADC_setPower(adcHandle,ADC_Power_Up);
	
  for(i=0;i<5000;i++)	NOP;
	
  DELAY_US(50000);

	ADC_setSMODSel(adcHandle,ADC_Sequential_Sampling);
	//================================================================================
	//MAX_CONV		
	adcHandle->ADCMAXCONV.bit.MAX_CONV1=7;
	adcHandle->ADCCHSELSEQ1.bit.CONV00=0;
	adcHandle->ADCCHSELSEQ1.bit.CONV01=1;
	adcHandle->ADCCHSELSEQ1.bit.CONV02=2;
	adcHandle->ADCCHSELSEQ1.bit.CONV03=3;
	adcHandle->ADCCHSELSEQ2.bit.CONV04=4;
	adcHandle->ADCCHSELSEQ2.bit.CONV05=5;
	adcHandle->ADCCHSELSEQ2.bit.CONV06=6;
	adcHandle->ADCCHSELSEQ2.bit.CONV07=7;
  adcHandle->ADCMAXCONV.bit.MAX_CONV1=1;
	//================================================================================
	//ADC_ST_FLAG
	adcHandle->ADCST.bit.INT_SEQ1_CLR=1;
	adcHandle->ADCST.bit.INT_SEQ2_CLR=1;
	//================================================================================
	//ADCTRL2
	adcHandle->ADCTRL2.bit.EPWM_SOCA_SEQ1=0;	
	adcHandle->ADCTRL2.bit.EXT_SOC_SEQ1=0; 
	adcHandle->ADCTRL2.bit.EPWM_SOCB_SEQ=0; 
	adcHandle->ADCTRL2.bit.EPWM_SOCB_SEQ2=0;
	
	adcHandle->ADCTRL2.bit.SOC_SEQ1=0;
  ADC_resetSeq(adcHandle,ADC_SeqNumber_1);

	adcHandle->ADCTRL2.bit.SOC_SEQ2=0;
  ADC_resetSeq(adcHandle,ADC_SeqNumber_2);

	adcHandle->ADCTRL2.bit.INT_ENA_SEQ2=0;
	adcHandle->ADCTRL2.bit.INT_MOD_SEQ2=0;
	ADC_cal();

 DISABLE_PROTECTED_REGISTER_WRITE_MODE;
}


//! @brief: GPIO初始化
void HAL_setupGpio(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;
  // PWM配置
  GPIO_setMode(obj->gpioHandle, GPIO_Number_0, GPIO_Mode_Prep_Func1);
  GPIO_setMode(obj->gpioHandle, GPIO_Number_1, GPIO_Mode_Prep_Func1);
  GPIO_setMode(obj->gpioHandle, GPIO_Number_2, GPIO_Mode_Prep_Func1);
  GPIO_setMode(obj->gpioHandle, GPIO_Number_3, GPIO_Mode_Prep_Func1);
  GPIO_setMode(obj->gpioHandle, GPIO_Number_4, GPIO_Mode_Prep_Func1);
  GPIO_setMode(obj->gpioHandle, GPIO_Number_5, GPIO_Mode_Prep_Func1);

  // CPU呼吸灯
  GPIO_setMode(obj->gpioHandle, GPIO_Number_29, GPIO_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_29, GPIO_Direction_Output);

  // CPU故障灯
  GPIO_setMode(obj->gpioHandle, GPIO_Number_30, GPIO_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_30, GPIO_Direction_Output);

  // 硬件过流保护，TZ功能
  GPIO_setMode(obj->gpioHandle, GPIO_Number_12, GPIO_Mode_Prep_Func1);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_12, GPIO_Direction_Output);

  // DAC口，PWM功能
  GPIO_setMode(obj->gpioHandle, GPIO_Number_10, GPIO_Mode_Prep_Func1);
  GPIO_setMode(obj->gpioHandle, GPIO_Number_11, GPIO_Mode_Prep_Func1);

  // CAN口，CANB
  GPIO_setPullup(obj->gpioHandle, GPIO_Number_20, GPIO_Pullup_Enable);
  GPIO_setPullup(obj->gpioHandle, GPIO_Number_21, GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle, GPIO_Number_20, GPIO_Mode_Prep_Func3);
  GPIO_setMode(obj->gpioHandle, GPIO_Number_21, GPIO_Mode_Prep_Func3);
  GPIO_setQualification(obj->gpioHandle, GPIO_Number_21, GPIO_Qual_ASync);

  // 蜂鸣器
  GPIO_setPullup(obj->gpioHandle, GPIO_Number_70, GPIO_Pullup_Enable);
  GPIO_setLow(obj->gpioHandle, GPIO_Number_70);
  GPIO_setMode(obj->gpioHandle, GPIO_Number_70, GPIO_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_70, GPIO_Direction_Output);

  // 422串口 SCIB
  GPIO_setPullup(obj->gpioHandle, GPIO_Number_22, GPIO_Pullup_Enable);
  GPIO_setPullup(obj->gpioHandle, GPIO_Number_23, GPIO_Pullup_Enable);
  GPIO_setMode(obj->gpioHandle, GPIO_Number_22, GPIO_Mode_Prep_Func3);
  GPIO_setMode(obj->gpioHandle, GPIO_Number_23, GPIO_Mode_Prep_Func3);
  GPIO_setQualification(obj->gpioHandle, GPIO_Number_23, GPIO_Qual_ASync);

  // 按键1
  GPIO_setMode(obj->gpioHandle, GPIO_Number_81, GPIO_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_81, GPIO_Direction_Input);
  // 按键2
  GPIO_setMode(obj->gpioHandle, GPIO_Number_45, GPIO_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_45, GPIO_Direction_Input);
  // 按键3
  GPIO_setMode(obj->gpioHandle, GPIO_Number_80, GPIO_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_80, GPIO_Direction_Input);
  // 按键4
  GPIO_setMode(obj->gpioHandle, GPIO_Number_46, GPIO_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_46, GPIO_Direction_Input);
  // 按键5
  GPIO_setMode(obj->gpioHandle, GPIO_Number_47, GPIO_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_47, GPIO_Direction_Input);

  // lcd显示屏
  // LCD_RS
  GPIO_setMode(obj->gpioHandle, GPIO_Number_66, GPIO_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_66, GPIO_Direction_Output);
  GPIO_setPullup(obj->gpioHandle, GPIO_Number_66, GPIO_Pullup_Enable);
  GPIO_setLow(obj->gpioHandle, GPIO_Number_66);
  // LCD_Rw
  GPIO_setMode(obj->gpioHandle, GPIO_Number_65, GPIO_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_65, GPIO_Direction_Output);
  GPIO_setPullup(obj->gpioHandle, GPIO_Number_65, GPIO_Pullup_Enable);
  GPIO_setLow(obj->gpioHandle, GPIO_Number_65);
  // LCD_en
  GPIO_setMode(obj->gpioHandle, GPIO_Number_64, GPIO_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_64, GPIO_Direction_Output);
  GPIO_setPullup(obj->gpioHandle, GPIO_Number_64, GPIO_Pullup_Enable);
  GPIO_setLow(obj->gpioHandle, GPIO_Number_64);
  // LCD_D0
  GPIO_setMode(obj->gpioHandle, GPIO_Number_61, GPIO_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_61, GPIO_Direction_Output);
  GPIO_setPullup(obj->gpioHandle, GPIO_Number_61, GPIO_Pullup_Enable);
  GPIO_setLow(obj->gpioHandle, GPIO_Number_61);
  // LCD_D1
  GPIO_setMode(obj->gpioHandle, GPIO_Number_60, GPIO_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_60, GPIO_Direction_Output);
  GPIO_setPullup(obj->gpioHandle, GPIO_Number_60, GPIO_Pullup_Enable);
  GPIO_setLow(obj->gpioHandle, GPIO_Number_60);
  // LCD_D2
  GPIO_setMode(obj->gpioHandle, GPIO_Number_59, GPIO_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_59, GPIO_Direction_Output);
  GPIO_setPullup(obj->gpioHandle, GPIO_Number_59, GPIO_Pullup_Enable);
  GPIO_setLow(obj->gpioHandle, GPIO_Number_59);
  // LCD_D3
  GPIO_setMode(obj->gpioHandle, GPIO_Number_58, GPIO_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_58, GPIO_Direction_Output);
  GPIO_setPullup(obj->gpioHandle, GPIO_Number_58, GPIO_Pullup_Enable);
  GPIO_setLow(obj->gpioHandle, GPIO_Number_58);
  // LCD_D4
  GPIO_setMode(obj->gpioHandle, GPIO_Number_57, GPIO_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_57, GPIO_Direction_Output);
  GPIO_setPullup(obj->gpioHandle, GPIO_Number_57, GPIO_Pullup_Enable);
  GPIO_setLow(obj->gpioHandle, GPIO_Number_57);
  // LCD_D5
  GPIO_setMode(obj->gpioHandle, GPIO_Number_56, GPIO_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_56, GPIO_Direction_Output);
  GPIO_setPullup(obj->gpioHandle, GPIO_Number_56, GPIO_Pullup_Enable);
  GPIO_setLow(obj->gpioHandle, GPIO_Number_56);
  // LCD_D6
  GPIO_setMode(obj->gpioHandle, GPIO_Number_55, GPIO_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_55, GPIO_Direction_Output);
  GPIO_setPullup(obj->gpioHandle, GPIO_Number_55, GPIO_Pullup_Enable);
  GPIO_setLow(obj->gpioHandle, GPIO_Number_55);
  // LCD_D7
  GPIO_setMode(obj->gpioHandle, GPIO_Number_54, GPIO_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_54, GPIO_Direction_Output);
  GPIO_setPullup(obj->gpioHandle, GPIO_Number_54, GPIO_Pullup_Enable);
  GPIO_setLow(obj->gpioHandle, GPIO_Number_54);
  // LCD_RST
  GPIO_setMode(obj->gpioHandle, GPIO_Number_52, GPIO_Mode_GeneralPurpose);
  GPIO_setDirection(obj->gpioHandle, GPIO_Number_52, GPIO_Direction_Output);
  GPIO_setPullup(obj->gpioHandle, GPIO_Number_52, GPIO_Pullup_Enable);
  GPIO_setLow(obj->gpioHandle, GPIO_Number_52);

  return;
}

void HAL_setParams(HAL_Handle handle)
{
  HAL_Obj *obj = (HAL_Obj *)handle;

  // 关闭全局中断
  CPU_disableGlobalInts(obj->cpuHandle);

  // 清除CPU的中断标志位
  CPU_clearIntFlags(obj->cpuHandle);

  // 设置 PLL 时钟
  HAL_setupPLL(handle, PLL_ClkFreq_150_MHz);

  // 打开外设时钟
  HAL_setupPeripheralClocks(handle);

  // setup the PIE
  HAL_setupPie(handle);

  HAL_setupFlash(handle);

  HAL_setupSci(handle);

  HAL_setupGpio(handle);

  HAL_setupAdc(handle);

  return;
}
