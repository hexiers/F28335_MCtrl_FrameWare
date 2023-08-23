/*
 * @Author: Hex
 * @Date: 2023-08-20 14:55:11
 * @LastEditors: Hexer hex@hust.edu.cn
 * @LastEditTime: 2023-08-20 20:54:06
 * @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_HAL\Include\HAL_Obj.h
 * @Description: 
 */
/*****************************************************************************
 * File name: 	HAL_Obj.h
 *    Author: 	Hex
 *	  E-mail: 	hex@hust.edu.cn
 *    Date  : 	2023年8月20日
 *	  Description: 定义HAL对象，包含驱动层使用的函数和数据
 *****************************************************************************/
#ifndef MOTCTL_HAL_INCLUDE_HAL_OBJ_H_
#define MOTCTL_HAL_INCLUDE_HAL_OBJ_H_

// *************************include files*************************************************************
// driver层头文件
#include "../../MotCtl_Driver/Include/adc.h"
#include "../../MotCtl_Driver/Include/clk.h"
#include "../../MotCtl_Driver/Include/cpu.h"
#include "../../MotCtl_Driver/Include/flash.h"
#include "../../MotCtl_Driver/Include/gpio.h"
#include "../../MotCtl_Driver/Include/osc.h"
#include "../../MotCtl_Driver/Include/pie.h"
#include "../../MotCtl_Driver/Include/pll.h"
#include "../../MotCtl_Driver/Include/pwm.h"
#include "../../MotCtl_Driver/Include/pwr.h"
#include "../../MotCtl_Driver/Include/qep.h"
#include "../../MotCtl_Driver/Include/sci.h"
#include "../../MotCtl_Driver/Include/spi.h"
#include "../../MotCtl_Driver/Include/timer.h"
#include "../../MotCtl_Driver/Include/wdog.h"
#include "../../MotCtl_Driver/Include/offset.h"


// 应用层头文件
#include "../../MotCtl_appSoft/Include/user.h"

// ************************* 宏定义 defines ***********************************************************

// ************************* typedef 类定义 ***********************************************************

//! \brief      定义ADC采集的数据
//! \details    ADC采集的数据包括：三相电流和电压、直流母线电压、外部转速输入
typedef struct _HAL_AdcData_t_
{
    MATH_vec3 I; // 三相电流

    MATH_vec3 V; // 三相电压

    _iq dcBus; // 直流母线电流

    _iq POT; // 外部转速输入

} HAL_AdcData_t;


//! \brief      定义DAC输出的数据
//! \details    4路DAC输出输出
//!
typedef struct _HAL_DacData_t_
{
    uint16_t PeriodMax; //! 最大占空比

    int32_t *ptrData[4]; //! 输入：4个指针

    _iq value[4]; //! DAC数据

    _iq offset[4]; //! DAC偏置数据

    _iq gain[4]; //! DAC增益
} HAL_DacData_t;


//! \brief      定义了PWM发波Tabc时间的数据
//! \details    包含了三相PWM电压值。发送给HAL_writePwmData()的函数，以便写入PWM外设。
//!
typedef struct _HAL_PwmData_t_
{
    MATH_vec3 Tabc;

} HAL_PwmData_t;


//! \brief      定义了硬件抽象层（HAL）对象实体
//! \details    HAL对象包含了所有外设的句柄，使用HAL函数和HAL句柄来访问外设
//!

typedef struct _HAL_Obj_
{
    ADC_Handle adcHandle;

    CLK_Handle clkHandle;

    CPU_Handle cpuHandle;

    FLASH_Handle flashHandle;

    GPIO_Handle gpioHandle;

    OFFSET_Handle offsetHandle_I[3]; // 电流偏置估计器句柄
    OFFSET_Obj offset_I[3];

    OFFSET_Handle offsetHandle_V[3]; // 电压偏置估计器句柄
    OFFSET_Obj offset_V[3];

    OSC_Handle oscHandle;

    PIE_Handle pieHandle;

    PLL_Handle pllHandle;

    PWM_Handle pwmHandle[3];

    //PWMDAC_Handle pwmDacHandle[3];

    PWR_Handle pwrHandle;

    TIMER_Handle timerHandle[3]; // 3个外设定时器句柄

    WDOG_Handle wdogHandle; // 看门狗句柄

    HAL_AdcData_t adcBias; // adc偏置

    _iq current_sf; // 电流缩放系数, amps_pu/cnt

    _iq voltage_sf; // 电压缩放系数, volts_pu/cnt

    uint_least8_t numCurrentSensors; // 电流传感器数量
    
    uint_least8_t numVoltageSensors; // 电压传感器数量

    SPI_Handle spiAHandle; // SPIA操作句柄
    SPI_Obj spiA;          //SPIA对象

    SCI_Handle sciAHandle; // SCIA操作句柄
    SCI_Obj sciA;          //SCIA对象

} HAL_Obj;


//! \brief      定义HAL句柄
//! \details    HAL句柄是指向HAL实体的指针. 所有函数通过HAL句柄传递，明确操作何种外设
//!
typedef struct _HAL_Obj_ *HAL_Handle;

//! \brief      定义HAL对象
//!
extern HAL_Obj hal;

//  *************************函数方法 ****************************************************************
//! \brief      运行偏置估计
//! \details    电流、电压adc偏置数据校正
//! \param[in]  handle    HAL句柄
//! \param[in]  pAdcData  ADC数据指针


inline void HAL_runOffsetEst(HAL_Handle handle, const HAL_AdcData_t *pAdcData)
{
    uint_least8_t cnt;
    HAL_Obj *obj = (HAL_Obj *)handle;

    // 电流偏置估计
    for (cnt = 0; cnt < obj->numCurrentSensors; cnt++)
    {
        OFFSET_run(obj->offsetHandle_I[cnt], pAdcData->I.value[cnt]);
    }

    // 电压偏置估计
    for (cnt = 0; cnt < obj->numVoltageSensors; cnt++)
    {
        OFFSET_run(obj->offsetHandle_V[cnt], pAdcData->V.value[cnt]);
    }

    return;
} // end of HAL_runOffsetEst()

#endif /* MOTCTL_HAL_INCLUDE_HAL_OBJ_H_ */
