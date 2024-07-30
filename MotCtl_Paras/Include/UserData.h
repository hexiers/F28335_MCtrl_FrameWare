
//! @FilePath: \F28335_MotCtl_Frameware\DSP28xx_MotCtl_Frameware\MotCtl_Paras\Include\UserData.h
//! @Author: Hex
//! @Date: 2023-08-23 19:51:35
//! @LastEditTime: 2024-06-08 15:38:36
//! @Description:  用户数据结构定义

#include "types.h"
#include "MotorParams.h"
#include "FbkParams.h"
#include "ErrParams.h"
#include "CtlParams.h"


typedef enum {
    USER_PARAMS_NoError = 0,
    USER_PARAMS_fullScaleCurrent_High,
    USER_PARAMS_fullScaleCurrent_Low,
    USER_PARAMS_fullScaleVoltage_High,
    USER_PARAMS_fullScaleVoltage_Low,
    USER_PARAMS_FullScaleFreq_High,
    USER_PARAMS_FullScaleFreq_Low,
}USER_PARAMS_ErrorCode;



//! \brief Defines a structure for the user parameters
typedef struct _USER_Params_
{
    // GROUP1 用户设置电机类参数
    MOTOR_Params MOTOR;

    // GROUP2 用户设置软件控制类参数
    CTRL_Params CTRL;

    // GROUP3 用户设置硬件反馈类参数
    FBK_Params FBK;

    // GROUP4 用户设置硬件故障类参数
    ERR_Params ERR;

    // GROUP3 用户配置参数错误自检码
    USER_PARAMS_ErrorCode errorCode;

} USER_Params;






