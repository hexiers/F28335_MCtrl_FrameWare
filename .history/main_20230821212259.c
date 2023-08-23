/*
 * @Author: Hexer
 * @Email: hex@hust.edu.cn
 * @Date: 2023-08-20 21:25:25
 * @LastEditors: Hexer
 * @LastEditTime: 2023-08-21 21:22:45
 * @FilePath: \DSP28xx_MotCtl_Frameware\main.c
 * @Description: 
 */
/*
 * @Author: Hex
 * @Date: 2023-07-31 21:32:36
 * @LastEditors: Hexer hex@hust.edu.cn
 * @LastEditTime: 2023-08-20 16:56:15
 * @FilePath: \DSP28xx_MotCtl_Frameware\main.c
 * @Description: 
 */

#include "DSP2833x_Project.h"
#include "GPIO_int.h"
#include "math.h"
#include "HAL.h" // 硬件抽象层头文件

void main(void)
{

	InitSysCtrl();		// 初始化 系统, 锁相环 , 看门狗等
	InitPieCtrl();		// 中断向量表控制
	InitPieVectTable(); // 中断向量表

	/*  CPU初始化*/
	MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);

	/*  按照120MHz时钟频率，初始化FLASH访问的等待周期数*/
	InitFlash();

	// initialize the hardware abstraction layer
	// halHandle = HAL_init(&hal, sizeof(hal));

	Init_Gpio_LED(); // LED灯GPIO初始化

	int i = 0;

	while (1)
	{
		i++;
		if (i == 1)

		{
			i = 0;
			DELAY_US(50000);
			GpioDataRegs.GPASET.bit.GPIO29 = 1;
		}
		DELAY_US(50000);
		GpioDataRegs.GPACLEAR.bit.GPIO29 = 1;
	}
}
