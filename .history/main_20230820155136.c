/*
 * main.c
 */

#include "DSP2833x_Project.h"
#include "GPIO_int.h"
#include "math.h"
#include "HAL.h"                // DSP2833x Examples Include File



void main(void) {


    InitSysCtrl();   // ��ʼ�� ϵͳ, ���໷ , ���Ź���
    InitPieCtrl();   //�ж�����������
    InitPieVectTable(); //�ж�������

	/*  CPU��ʼ��*/
	MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);

	/*  ����120MHzʱ��Ƶ�ʣ���ʼ��FLASH���ʵĵȴ�������*/
	InitFlash();

	// initialize the hardware abstraction layer
    halHandle = HAL_init(&hal,sizeof(hal));


	Init_Gpio_LED(); // LED��GPIO��ʼ��

	int i =0;

	while(1)
	{
		i++;
		if(i == 1)

		{
			i=0;
			DELAY_US(50000);
			GpioDataRegs.GPASET.bit.GPIO29 =1;

		}
		DELAY_US(50000);
		GpioDataRegs.GPACLEAR.bit.GPIO29 =1;
	}

}