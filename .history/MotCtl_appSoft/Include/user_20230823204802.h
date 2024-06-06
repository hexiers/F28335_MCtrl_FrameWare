
//! @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_appSoft\Include\user.h
//! @Author: Hex
//! @Date: 2023-08-20 21:25:26
//! @LastEditTime: 2023-08-23 20:36:59
//! @Description: 用户层借口，定义更改的数据


#ifndef MOTCTL_APPSOFT_INCLUDE_USER_H_
#define MOTCTL_APPSOFT_INCLUDE_USER_H_

// ************************************** include files  ************************************************************
#include "UserData.h"

// ****************************************  宏定义 defines *********************************************************


// **************************************  typedef 类定义 ***********************************************************


//***********************************    函数方法 function ***********************************************************





extern void USER_checkForErrors(USER_Params *pUserParams);

extern void USER_setParams(USER_Params *pUserParams);

extern void USER_PARAMS_ErrorCode USER_getErrorCode(USER_Params *pUserParams);

extern void USER_setParams(USER_Params *pUserParams);

#endif /* MOTCTL_APPSOFT_INCLUDE_USER_H_ */
