
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
	u	HPOvFaultPoint;/* 转换成BIT值，写入FPGA*/
	Uint16	HPUvFaultPoint;/* 转换成BIT值，写入FPGA*/
	Uint16	LPOvFaultPoint;
	Uint16	LPUvFaultPoint;
	Uint16	HPOcFaultPoint;
	Uint16	PDDOvtFaultPoint;
	Uint16	PhaseOcFaultPoint;
	Uint16	OvSpdFaultPoint;
	Uint16	SnsLessUnSpdFaultPoint;
	Uint16	MotorOvtFaultPoint;

}stFaultPara;

extern   stFaultPara m1FaultPara;


//  函数方法 ****************************************************************





#endif /* MOTCTL_PARAS_INCLUDE_ERRPARAMS_H_ */
