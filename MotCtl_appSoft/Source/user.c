
//! @FilePath: \F28335_MotCtl_Frameware\DSP28xx_MotCtl_Frameware\MotCtl_appSoft\Source\user.c
//! @Author: Hex
//! @Date: 2023-08-23 20:36:24
//! @LastEditTime: 2024-06-06 22:56:13
//! @Description:

#include "user.h"
// TODO
void USER_checkForErrors(USER_Params *pUserParams)
{
}

// TODO
void USER_setParams(USER_Params *pUserParams)
{
}

USER_PARAMS_ErrorCode USER_getErrorCode(USER_Params *pUserParams)
{
    return (pUserParams->errorCode);
} // end of USER_getErrorCode() function

void USER_setErrorCode(USER_Params *pUserParams, const USER_PARAMS_ErrorCode errorCode)
{
    pUserParams->errorCode = errorCode;

    return;
} // end of USER_setErrorCode() function
