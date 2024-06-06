
//! @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_Paras\Include\errParams.h
//! @Author: Hex
//! @Date: 2023-08-23 20:01:05
//! @LastEditTime: 2023-08-23 20:03:09
//! @Description: 定义故障阈值参数结构体 


#ifndef MOTCTL_PARAS_INCLUDE_ERRPARAMS_H_
#define MOTCTL_PARAS_INCLUDE_ERRPARAMS_H_

// include files*************************************************************
#include "types.h"

// 宏定义 defines ***********************************************************


// typedef 类定义 ***********************************************************
typedef struct
{
	uint16_t	HPOvFaultPoint;/* 转换成BIT值，写入FPGA*/
	uint16_t	HPUvFaultPoint;/* 转换成BIT值，写入FPGA*/
	uint16_t	LPOvFaultPoint;
	uint16_t	LPUvFaultPoint;
	uint16_t	HPOcFaultPoint;
	uint16_t	PDDOvtFaultPoint;
	uint16_t	PhaseOcFaultPoint;
	uint16_t	OvSpdFaultPoint;
	uint16_t	SnsLessUnSpdFaultPoint;
	uint16_t	MotorOvtFaultPoint;

}stFaultPara;

extern   stFaultPara m1FaultPara;


//  函数方法 ****************************************************************





#endif /* MOTCTL_PARAS_INCLUDE_ERRPARAMS_H_ */
