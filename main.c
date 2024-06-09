/*
 * @Author: Hex
 * @Email: hex@hust.edu.cn
 * @Date: 2023-08-20 21:25:25
 * @LastEditTime: 2023-08-21 21:47:37
 * @FilePath: \DSP28xx_MotCtl_Frameware\main.c
 * @Description:
 */

#include "DSP2833x_Project.h"
#include "GPIO_int.h"
#include "math.h"
#include "HAL.h" // 硬件抽象层头文件

USER_Params UserParams;
HAL_Handle halHandle;
HAL_Obj hal;
uint16_t result[16] = { 0,0,0,0,
						0,0,0,0,
						0,0,0,0,
						0,0,0,0};

void main(void)
{

	/*  CPU初始化*/
	MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);

	// 初始化HAL层,分配句柄映射
	halHandle = HAL_init((void *)&hal, sizeof(hal));

	// 用户参数检查
	USER_checkForErrors(&UserParams);

	// 初始化用户参数
	USER_setParams(&UserParams);

	// 配置底层驱动参数
	HAL_setParams(halHandle);

	int i = 0;

	while (1)
	{
		i++;
		DELAY_US(100);
		if (i == 10000)
		{
			i = 0;
			// 呼吸灯闪
			GPIO_toggle(halHandle->gpioHandle, GPIO_Number_29);
			// 故障灯无动作
			GPIO_setHigh(halHandle->gpioHandle, GPIO_Number_30);

			ADC_softRunSoc(halHandle->adcHandle, ADC_SeqNumber_1);

			ADC_softRunSoc(halHandle->adcHandle, ADC_SeqNumber_2);

			ADC_Read(halHandle->adcHandle, result);
		}
	}
}
