
//! @FilePath: \F28335_MotCtl_Frameware\DSP28xx_MotCtl_Frameware\MotCtl_Paras\Include\errParams.h
//! @Author: Hex
//! @Date: 2024-06-07 01:06:42
//! @LastEditTime: 2024-06-08 10:55:50
//! @Description: 

#ifndef MOTCTL_PARAS_INCLUDE_ERRPARAMS_H_
#define MOTCTL_PARAS_INCLUDE_ERRPARAMS_H_

// include files*************************************************************
#include "types.h"

// 宏定义 defines ***********************************************************


// typedef 类定义 ***********************************************************
typedef struct _ERR_Params_{

	float_t	HPOvFaultPoint;			           // 高压过压点
	float_t	HPUvFaultPoint;			           // 高压欠压点           	   					
	float_t	LPOvFaultPoint;                    // 低压过压点	   					
	float_t	LPUvFaultPoint;	   				   // 低压欠压点	
	float_t	HPOcFaultPoint;	 				   // 高压过流点 					
	float_t	PDDOvtFaultPoint;	   			   // 管温过温点			
	float_t	PhaseOcFaultPoint;	  			   // 相电流过流点					
	float_t	OvSpdFaultPoint;	   			   // 超速点	
	float_t	MotorOvtFaultPoint;	   			   // 电机超温点	

}ERR_Params;


//  函数方法 ****************************************************************





#endif /* MOTCTL_PARAS_INCLUDE_ERRPARAMS_H_ */
