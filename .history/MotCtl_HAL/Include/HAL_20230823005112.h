/*
 * @Author: Hex
 * @Date: 2023-08-20 14:48:30
 * @LastEditors: Hexer hex@hust.edu.cn
 * @LastEditTime: 2023-08-20 16:44:40
 * @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_HAL\Include\HAL.h
 * @Description: 硬件抽象层定义
 */
#ifndef MOTCTL_HAL_INCLUDE_HAL_H_
#define MOTCTL_HAL_INCLUDE_HAL_H_

//**********************************  include files*************************************************************
#include "HAL_Obj.h"
#include "user.h"

// ********************************** 宏定义 defines ***********************************************************


//**********************************  typedef 类定义 ***********************************************************


//**********************************   函数方法 ****************************************************************
extern HAL_Handle HAL_init(void *pMem, const size_t numBytes);




#endif /* MOTCTL_HAL_INCLUDE_HAL_H_ */
