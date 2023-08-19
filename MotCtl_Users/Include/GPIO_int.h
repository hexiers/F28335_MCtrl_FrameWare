// FILE:  GPIO_int.h
// Created on: 2016年8月5日
// Author: XQ
// summary: Header file  and definition
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//版权所有，盗版必究
//DSP/STM32电机控制开发板
//硕历电子
//网址: https://shuolidianzi.taobao.com
//Author-QQ: 616264123
//电机控制QQ群：314306105
//############################################################

#include "DSP2833x_Project.h"

#ifndef GPIO_int_H
#define GPIO_int_H
#define LED1_CLR  GpioDataRegs.GPACLEAR.bit.GPIO29=1
#define LED1_SET  GpioDataRegs.GPASET.bit.GPIO29=1
#define LED1_REV  GpioDataRegs.GPATOGGLE.bit.GPIO29=1
#define LED2_CLR  GpioDataRegs.GPACLEAR.bit.GPIO30=1
#define LED2_SET  GpioDataRegs.GPASET.bit.GPIO30=1
#define LED2_REV  GpioDataRegs.GPATOGGLE.bit.GPIO30=1


void Init_Gpio_LED(void);
void Init_3MotorGpio(void);
void Init_DACEPWMGpio(void);
void Init_FMQ_voice(void);
void InitScirs232bGpio(void);
void Init_KEY_switch(void);
void Init_LCD12864_Gpio(void);
void Init_ECanbGpio(void);

#endif  // end of GPIO_int_H definition

//===========================================================================
// End of file.
//===========================================================================
