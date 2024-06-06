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
 *    Date  : 	2023��8��20��
 *	  Description: ����HAL���󣬰���������ʹ�õĺ���������
 *****************************************************************************/
#ifndef MOTCTL_HAL_INCLUDE_HAL_OBJ_H_
#define MOTCTL_HAL_INCLUDE_HAL_OBJ_H_

// *************************include files*************************************************************
// driver��ͷ�ļ�
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


// Ӧ�ò�ͷ�ļ�
#include "../../MotCtl_appSoft/Include/user.h"

// ************************* �궨�� defines ***********************************************************

// ************************* typedef �ඨ�� ***********************************************************

//! \brief      ����ADC�ɼ�������
//! \details    ADC�ɼ������ݰ�������������͵�ѹ��ֱ��ĸ�ߵ�ѹ���ⲿת������
typedef struct _HAL_AdcData_t_
{
    MATH_vec3 I; // �������

    MATH_vec3 V; // �����ѹ

    _iq dcBus; // ֱ��ĸ�ߵ���

    _iq POT; // �ⲿת������

} HAL_AdcData_t;


//! \brief      ����DAC���������
//! \details    4·DAC������
//!
typedef struct _HAL_DacData_t_
{
    uint16_t PeriodMax; //! ���ռ�ձ�

    int32_t *ptrData[4]; //! ���룺4��ָ��

    _iq value[4]; //! DAC����

    _iq offset[4]; //! DACƫ������

    _iq gain[4]; //! DAC����
} HAL_DacData_t;


//! \brief      ������PWM����Tabcʱ�������
//! \details    ����������PWM��ѹֵ�����͸�HAL_writePwmData()�ĺ������Ա�д��PWM���衣
//!
typedef struct _HAL_PwmData_t_
{
    MATH_vec3 Tabc;

} HAL_PwmData_t;


//! \brief      ������Ӳ������㣨HAL������ʵ��
//! \details    HAL�����������������ľ����ʹ��HAL������HAL�������������
//!

typedef struct _HAL_Obj_
{
    ADC_Handle adcHandle;

    CLK_Handle clkHandle;

    CPU_Handle cpuHandle;

    FLASH_Handle flashHandle;

    GPIO_Handle gpioHandle;

    OFFSET_Handle offsetHandle_I[3]; // ����ƫ�ù��������
    OFFSET_Obj offset_I[3];

    OFFSET_Handle offsetHandle_V[3]; // ��ѹƫ�ù��������
    OFFSET_Obj offset_V[3];

    OSC_Handle oscHandle;

    PIE_Handle pieHandle;

    PLL_Handle pllHandle;

    PWM_Handle pwmHandle[3];

    //PWMDAC_Handle pwmDacHandle[3];

    PWR_Handle pwrHandle;

    TIMER_Handle timerHandle[3]; // 3�����趨ʱ�����

    WDOG_Handle wdogHandle; // ���Ź����

    HAL_AdcData_t adcBias; // adcƫ��

    _iq current_sf; // ��������ϵ��, amps_pu/cnt

    _iq voltage_sf; // ��ѹ����ϵ��, volts_pu/cnt

    uint_least8_t numCurrentSensors; // ��������������
    
    uint_least8_t numVoltageSensors; // ��ѹ����������

    SPI_Handle spiAHandle; // SPIA�������
    SPI_Obj spiA;          //SPIA����

    SCI_Handle sciAHandle; // SCIA�������
    SCI_Obj sciA;          //SCIA����

} HAL_Obj;


//! \brief      ����HAL���
//! \details    HAL�����ָ��HALʵ���ָ��. ���к���ͨ��HAL������ݣ���ȷ������������
//!
typedef struct _HAL_Obj_ *HAL_Handle;

//! \brief      ����HAL����
//!
extern HAL_Obj hal;

//  *************************�������� ****************************************************************
//! \brief      ����ƫ�ù���
//! \details    ��������ѹadcƫ������У��
//! \param[in]  handle    HAL���
//! \param[in]  pAdcData  ADC����ָ��


inline void HAL_runOffsetEst(HAL_Handle handle, const HAL_AdcData_t *pAdcData)
{
    uint_least8_t cnt;
    HAL_Obj *obj = (HAL_Obj *)handle;

    // ����ƫ�ù���
    for (cnt = 0; cnt < obj->numCurrentSensors; cnt++)
    {
        OFFSET_run(obj->offsetHandle_I[cnt], pAdcData->I.value[cnt]);
    }

    // ��ѹƫ�ù���
    for (cnt = 0; cnt < obj->numVoltageSensors; cnt++)
    {
        OFFSET_run(obj->offsetHandle_V[cnt], pAdcData->V.value[cnt]);
    }

    return;
} // end of HAL_runOffsetEst()

#endif /* MOTCTL_HAL_INCLUDE_HAL_OBJ_H_ */
