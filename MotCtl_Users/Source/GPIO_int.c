//############################################################
// FILE:  GPIO_int.c
// Created on: 2016年8月8日
// Author: XQ
// summary:GPIO_int
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//版权所有，盗版必究
//DSP/STM32电机控制开发板
//硕历电子
//网址: https://shuolidianzi.taobao.com
//Author-QQ: 616264123
//电机控制QQ群：314306105
//############################################################

/**
 * 
 */
#include "GPIO_int.h"

 void Init_Gpio_LED(void)
 {
	 EALLOW;

	 // GPIO0     CPU运行灯     //  1 S闪烁一次
    GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 0;  									// GPIO11 = GPIO
    GpioCtrlRegs.GPADIR.bit.GPIO29 = 1;      // GPIO11 = output
    //  GPIO1     系统故障灯
    GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 0;  									// GPIO11 = GPIO
    GpioCtrlRegs.GPADIR.bit.GPIO30 = 1;      // GPIO11 = output

    EDIS;
  }

void Init_3MotorGpio(void)
{
   EALLOW;
   GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;
   GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;
   GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;
   GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;
   GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;
   GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;

   GpioCtrlRegs.GPAMUX1.bit.GPIO12 =1;	// 0=GPIO,  1=TZ1,  2=SCITX-A,  3=SPISIMO-B
   GpioCtrlRegs.GPADIR.bit.GPIO12 = 0;	// 1=OUTput,  0=INput    DB9

   EDIS;
}

void Init_DACEPWMGpio(void)
{
   EALLOW;
   GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1;
   GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 1;
   EDIS;
}

void Init_ECanbGpio(void)
{
   EALLOW;
   GpioCtrlRegs.GPAPUD.bit.GPIO20 = 0;   // Enable pull-up for GPIO20 (CANTXB)
   GpioCtrlRegs.GPAPUD.bit.GPIO21 = 0;   // Enable pull-up for GPIO21 (CANRXB)
   GpioCtrlRegs.GPAQSEL2.bit.GPIO21 = 3; // Asynch qual for GPIO21 (CANRXB)
   GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 3;  // Configure GPIO20 for CANTXB operation
   GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 3;  // Configure GPIO21 for CANRXB operation
   EDIS;
}

void Init_FMQ_voice(void)
{
	    EALLOW;
		//   蜂鸣器  语音报警控制
	    GpioCtrlRegs.GPCPUD.bit.GPIO70 = 0;   									// Enable pullup on GPIO11
	    GpioDataRegs.GPCCLEAR.bit.GPIO70 = 1;
	    GpioCtrlRegs.GPCMUX1.bit.GPIO70 = 0;  									// GPIO11 = GPIO
	    GpioCtrlRegs.GPCDIR.bit.GPIO70 = 1;   									// GPIO11 = OUTputIO
	    EDIS;
}

void InitScirs232bGpio(void)
{
   EALLOW;

   GpioCtrlRegs.GPAPUD.bit.GPIO22 = 0;    // Enable pull-up for GPIO22 (SCITXDB)
   GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 3;   // Configure GPIO22 for SCITXDB operation

   GpioCtrlRegs.GPAPUD.bit.GPIO23 = 0;    // Enable pull-up for GPIO23 (SCIRXDB)
   GpioCtrlRegs.GPAQSEL2.bit.GPIO23 = 3;  // Asynch input GPIO23 (SCIRXDB)
   GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 3;   // Configure GPIO23 for SCIRXDB operation

    EDIS;
}

/***************************************按键IO初始化************************************************/
void Init_KEY_switch(void)
{
        EALLOW;
        //    按键1
        GpioCtrlRegs.GPCMUX2.bit.GPIO81 = 0;                                    // GPIO11 = GPIO
        GpioCtrlRegs.GPCDIR.bit.GPIO81 = 0;  // GPIO11 = inputIO
        //    按键2
        GpioCtrlRegs.GPBMUX1.bit.GPIO45 = 0;                                    // GPIO11 = GPIO
        GpioCtrlRegs.GPBDIR.bit.GPIO45 = 0;                                     // GPIO11 = inputIO
        //    按键3
        GpioCtrlRegs.GPCMUX2.bit.GPIO80= 0;                                     // GPIO11 = GPIO
        GpioCtrlRegs.GPCDIR.bit.GPIO80= 0;
        //    按键4
        GpioCtrlRegs.GPBMUX1.bit.GPIO46= 0;                                     // GPIO11 = GPIO
        GpioCtrlRegs.GPBDIR.bit.GPIO46= 0;
        //    按键5
        GpioCtrlRegs.GPBMUX1.bit.GPIO47= 0;                                     // GPIO11 = GPIO
        GpioCtrlRegs.GPBDIR.bit.GPIO47= 0;

        EDIS;
}
/***************************************12864液晶IO初始化************************************************/
void Init_LCD12864_Gpio(void)
{
	 EALLOW;
	 /***************LCD_RS*********************/
	 GpioCtrlRegs.GPCMUX1.bit.GPIO66 = 0;  									// GPIO11 = GPIO
	 GpioCtrlRegs.GPCDIR.bit.GPIO66 = 1;
	 GpioCtrlRegs.GPCPUD.bit.GPIO66=0;
	 GpioDataRegs.GPCCLEAR.bit.GPIO66=1;
	 /***************LCD_RW*********************/
	 GpioCtrlRegs.GPCMUX1.bit.GPIO65 = 0;  									// GPIO11 = GPIO
	 GpioCtrlRegs.GPCDIR.bit.GPIO65 = 1;
	 GpioCtrlRegs.GPCPUD.bit.GPIO65=0;
	 GpioDataRegs.GPCCLEAR.bit.GPIO65=1;
	 /***************LCD_EN*********************/
	 GpioCtrlRegs.GPCMUX1.bit.GPIO64 = 0;  									// GPIO11 = GPIO
	 GpioCtrlRegs.GPCDIR.bit.GPIO64 = 1;
	 GpioCtrlRegs.GPCPUD.bit.GPIO64=0;
	 GpioDataRegs.GPCCLEAR.bit.GPIO64=1;
	 /***************LCD_D0*********************/
	 GpioCtrlRegs.GPBMUX2.bit.GPIO61 = 0;  									// GPIO11 = GPIO
	 GpioCtrlRegs.GPBDIR.bit.GPIO61 = 1;
	 GpioCtrlRegs.GPBPUD.bit.GPIO61=0;
	 GpioDataRegs.GPBCLEAR.bit.GPIO61=1;
	 /***************LCD_D1*********************/
	 GpioCtrlRegs.GPBMUX2.bit.GPIO60 = 0;  									// GPIO11 = GPIO
	 GpioCtrlRegs.GPBDIR.bit.GPIO60 = 1;
	 GpioCtrlRegs.GPBPUD.bit.GPIO60=0;
	 GpioDataRegs.GPBCLEAR.bit.GPIO60=1;
	 /***************LCD_D2*********************/
	 GpioCtrlRegs.GPBMUX2.bit.GPIO59 = 0;  									// GPIO11 = GPIO
	 GpioCtrlRegs.GPBDIR.bit.GPIO59 = 1;
	 GpioCtrlRegs.GPBPUD.bit.GPIO59=0;
	 GpioDataRegs.GPBCLEAR.bit.GPIO59=1;
	 /***************LCD_D3*********************/
	 GpioCtrlRegs.GPBMUX2.bit.GPIO58 = 0;  									// GPIO11 = GPIO
	 GpioCtrlRegs.GPBDIR.bit.GPIO58 = 1;
	 GpioCtrlRegs.GPBPUD.bit.GPIO58=0;
	 GpioDataRegs.GPBCLEAR.bit.GPIO58=1;
	 /***************LCD_D4*********************/
	 GpioCtrlRegs.GPBMUX2.bit.GPIO57 = 0;  									// GPIO11 = GPIO
	 GpioCtrlRegs.GPBDIR.bit.GPIO57 = 1;
	 GpioCtrlRegs.GPBPUD.bit.GPIO57=0;
	 GpioDataRegs.GPBCLEAR.bit.GPIO57=1;
	 /***************LCD_D5*********************/
	 GpioCtrlRegs.GPBMUX2.bit.GPIO56 = 0;  									// GPIO11 = GPIO
	 GpioCtrlRegs.GPBDIR.bit.GPIO56 = 1;
	 GpioCtrlRegs.GPBPUD.bit.GPIO56=0;
	 GpioDataRegs.GPBCLEAR.bit.GPIO56=1;
	 /***************LCD_D6*********************/
	 GpioCtrlRegs.GPBMUX2.bit.GPIO55 = 0;  									// GPIO11 = GPIO
	 GpioCtrlRegs.GPBDIR.bit.GPIO55 = 1;
	 GpioCtrlRegs.GPBPUD.bit.GPIO55=0;
	 GpioDataRegs.GPBCLEAR.bit.GPIO55=1;
	 /***************LCD_D7*********************/
	 GpioCtrlRegs.GPBMUX2.bit.GPIO54 = 0;  									// GPIO11 = GPIO
	 GpioCtrlRegs.GPBDIR.bit.GPIO54 = 1;
	 GpioCtrlRegs.GPBPUD.bit.GPIO54=0;
	 GpioDataRegs.GPBCLEAR.bit.GPIO54=1;
	 /***************LCD_REST*********************/
	 GpioCtrlRegs.GPBMUX2.bit.GPIO52 = 0;  									// GPIO11 = GPIO
	 GpioCtrlRegs.GPBDIR.bit.GPIO52 = 1;
	 GpioCtrlRegs.GPBPUD.bit.GPIO52=0;
	 GpioDataRegs.GPBCLEAR.bit.GPIO52=1;
	 EDIS;
}

//===========================================================================
// No more.
//===========================================================================
