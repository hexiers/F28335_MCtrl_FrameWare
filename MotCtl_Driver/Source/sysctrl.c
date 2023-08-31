/* --COPYRIGHT--,BSD
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
//! \file   drivers/pll/src/32b/f28x/f2806x/pll.c
//!
//! \brief  Contains the various functions related to the phase-locked loop
//!         (PLL) object
//!
//! (C) Copyright 2015, Texas Instruments, Inc.

// **************************************************************************
// the includes

#include "../Include/sysctrl.h"

// **************************************************************************
// the defines

// **************************************************************************
// the globals

// **************************************************************************
// the functions

//! @brief: 系统控制器初始化
SYSCTRL_Handle SYSCTRL_init(void *pMemory, const size_t numBytes)
{
    SYSCTRL_Handle sysctrlHandle;

    if (numBytes < sizeof(SYSCTRL_Obj))
        return ((SYSCTRL_Handle)NULL);

    // assign the handle
    sysctrlHandle = (SYSCTRL_Handle)pMemory;

    return (sysctrlHandle);
} // end of PLL_init() function

//! @brief: 关闭PLL
void PLL_disable(SYSCTRL_Handle sysctrlHandle)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysctrlHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    obj->PLLSTS |= PLL_PLLSTS_PLLOFF_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_disable() function

//! @brief: 关闭CLK检测
void PLL_disableClkDetect(SYSCTRL_Handle sysctrlHandle)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysctrlHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    obj->PLLSTS |= PLL_PLLSTS_MCLKOFF_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_disableClkDetect() function

//! @brief: 关闭外部时钟输入
void PLL_disableOsc(SYSCTRL_Handle sysctrlHandle)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysctrlHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    obj->PLLSTS |= PLL_PLLSTS_OSCOFF_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_disableOsc() function

//! @brief: 使能PLL
void PLL_enable(SYSCTRL_Handle sysctrlHandle)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysctrlHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    obj->PLLSTS &= (~PLL_PLLSTS_PLLOFF_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_enable() function

//! @brief: 使能CLK检测
void PLL_enableClkDetect(SYSCTRL_Handle sysctrlHandle)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysctrlHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    obj->PLLSTS &= (~PLL_PLLSTS_MCLKOFF_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_enableClkDetect() function

//! @brief: 使能XCLKIN时钟
//! @param SYSCTRL_Handle sysctrlHandle
//! @return *
//! @details:
void PLL_enableOsc(SYSCTRL_Handle sysctrlHandle)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysctrlHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    obj->PLLSTS &= (~PLL_PLLSTS_OSCOFF_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_enableOsc() function

//! @brief: 获取PLL时钟频率
PLL_ClkFreq_e PLL_getClkFreq(SYSCTRL_Handle sysctrlHandle)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysctrlHandle;

    // get the clock rate
    PLL_ClkFreq_e clkFreq = (PLL_ClkFreq_e)(obj->PLLCR & PLL_PLLCR_DIV_BITS);

    return (clkFreq);
} // end of PLL_getClkFreq() function

//! @brief: 获取时钟状态
PLL_ClkStatus_e PLL_getClkStatus(SYSCTRL_Handle sysctrlHandle)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysctrlHandle;

    // mask the bits
    PLL_ClkStatus_e status = (PLL_ClkStatus_e)(obj->PLLSTS & PLL_PLLSTS_MCLKSTS_BITS);

    return (status);
} // end of PLL_getClkStatus() function

//! @brief: 获取除数
PLL_DivideSelect_e PLL_getDivideSelect(SYSCTRL_Handle sysctrlHandle)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysctrlHandle;

    // mask the bits
    PLL_DivideSelect_e divSelect = (PLL_DivideSelect_e)(obj->PLLSTS & PLL_PLLSTS_DIVSEL_BITS);

    return (divSelect);
} // end of PLL_getDivideSelect() function

//! @brief: 获取PLL锁定状态
PLL_LockStatus_e PLL_getLockStatus(SYSCTRL_Handle sysctrlHandle)
{
    volatile SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysctrlHandle;

    // mask the bits
    PLL_LockStatus_e status = (PLL_LockStatus_e)(obj->PLLSTS & PLL_PLLSTS_PLLLOCKS_BITS);

    return (status);
} // end of PLL_getLockStatus() function

//! @brief: 时钟检测复位
void PLL_resetClkDetect(SYSCTRL_Handle sysctrlHandle)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysctrlHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    obj->PLLSTS |= PLL_PLLSTS_MCLKCLR_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_resetClkDetect() function

//! @brief: 设置时钟频率
void PLL_setClkFreq(SYSCTRL_Handle sysctrlHandle, const PLL_ClkFreq_e clkFreq)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysctrlHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    obj->PLLCR = clkFreq;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_setClkFreq() function

//! @brief: 设置除数
void PLL_setDivideSelect(SYSCTRL_Handle sysctrlHandle, const PLL_DivideSelect_e divSelect)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysctrlHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    obj->PLLSTS &= (~PLL_PLLSTS_DIVSEL_BITS);

    // set the bits
    obj->PLLSTS |= divSelect;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PLL_setDivideSelect() function

void Sys_enableAdcClock(SYSCTRL_Handle sysctrlHandle)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysctrlHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    obj->PCLKCR0 |= PCLKCR0_ADCENCLK_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of CLK_enableAdcClock() function
// end of file

void WDOG_clearCounter(SYSCTRL_Handle sysCtrl_Handle)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysCtrl_Handle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // write first sequence
    obj->WDKEY = 0x55;

    // write second sequence
    obj->WDKEY = 0xAA;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of WDOG_clearCounter() function

void WDOG_disable(SYSCTRL_Handle sysCtrl_Handle)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysCtrl_Handle;
    uint16_t regValue = obj->WDCR;
    // set the bits
    regValue |= WDOG_WDCR_WDDIS_BITS;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // store the result
    obj->WDCR = regValue | WDOG_WDCR_WRITE_ENABLE;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of WDOG_disable() function

void WDOG_disableInt(SYSCTRL_Handle sysCtrl_Handle)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysCtrl_Handle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    obj->SCSR &= (~WDOG_SCSR_WDENINT_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of WDOG_disableInt() function

void WDOG_disableOverRide(SYSCTRL_Handle sysCtrl_Handle)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysCtrl_Handle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    obj->SCSR &= (~WDOG_SCSR_WDOVERRIDE_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of WDOG_disableOverRide() function

void WDOG_enable(SYSCTRL_Handle sysCtrl_Handle)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysCtrl_Handle;
    uint16_t regValue = obj->WDCR;

    // clear the bits
    regValue &= (~WDOG_WDCR_WDDIS_BITS);

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // store the result
    obj->WDCR = regValue | WDOG_WDCR_WRITE_ENABLE;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of WDOG_enable() function

void WDOG_enableInt(SYSCTRL_Handle sysCtrl_Handle)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysCtrl_Handle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    obj->SCSR |= WDOG_SCSR_WDENINT_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of WDOG_enableInt() function

void WDOG_enableOverRide(SYSCTRL_Handle sysCtrl_Handle)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysCtrl_Handle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    obj->SCSR |= WDOG_SCSR_WDOVERRIDE_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of WDOG_enableOverRide() function

WDOG_IntStatus_e WDOG_getIntStatus(SYSCTRL_Handle sysCtrl_Handle)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysCtrl_Handle;

    // mask the bits
    WDOG_IntStatus_e status =
        (WDOG_IntStatus_e)(obj->SCSR & WDOG_SCSR_WDINTS_BITS);

    return (status);
} // end of WDOG_getIntStatus() function

void WDOG_setCount(SYSCTRL_Handle sysCtrl_Handle, const uint_least8_t count)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysCtrl_Handle;

    // set the bits
    obj->WDCNTR = count;

    return;
} // end of WDOG_setCount() function

void WDOG_setPreScaler(SYSCTRL_Handle sysCtrl_Handle, const WDOG_PreScaler_e preScaler)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysCtrl_Handle;
    uint16_t regValue = obj->WDCR;

    // clear the bits
    regValue &= (~WDOG_WDCR_WDPS_BITS);

    // set the bits
    regValue |= preScaler;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // store the result
    obj->WDCR = regValue | WDOG_WDCR_WRITE_ENABLE;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of WDOG_setPreScaler() function

//******************  外设时钟使能 **************************

void Sys_enableScibClock(SYSCTRL_Handle sysCtrl_Handle)
{
    SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysCtrl_Handle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;
    // set the bits
    obj->PCLKCR0 |= PCLKCR0_SCIBENCLK_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
}

void Sys_enablePwmClock(SYSCTRL_Handle sysCtrl_Handle,const PWM_Number_e pwmNumber)
{
     SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysCtrl_Handle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;
    // set the bits
    obj->PCLKCR1 |= 1 << pwmNumber;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
}

void Sys_enableTbClockSync(SYSCTRL_Handle sysCtrl_Handle)
{
     SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysCtrl_Handle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;
    // set the bits
    obj->PCLKCR0 |= PCLKCR0_TBCLKSYNC_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
}

void Sys_enableEqep1Clock(SYSCTRL_Handle sysCtrl_Handle)
{
     SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysCtrl_Handle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;
    // set the bits
    obj->PCLKCR1 |= PCLKCR1_EQEP1ENCLK_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
}

void Sys_enableCpuTimerClock(SYSCTRL_Handle sysCtrl_Handle,CLK_CpuTimerNumber_e cpuTimerNumber)
{
     SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysCtrl_Handle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;
    // set the bits
    obj->PCLKCR3 |= cpuTimerNumber;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
}

void Sys_enableGpioInputClock(SYSCTRL_Handle sysCtrl_Handle)
{
     SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysCtrl_Handle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;
    // set the bits
    obj->PCLKCR3 |= PCLKCR3_GPIOINENCLK_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
}

void Sys_disableTbClockSync(SYSCTRL_Handle sysCtrl_Handle)
{
     SYSCTRL_Obj *obj = (SYSCTRL_Obj *)sysCtrl_Handle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;
    // set the bits
    obj->PCLKCR0 &= (~PCLKCR0_TBCLKSYNC_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
}
