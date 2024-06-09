//! @FilePath: \F28335_MotCtl_Frameware\DSP28xx_MotCtl_Frameware\MotCtl_appSoft\Source\user.c
//! @Author: Hex
//! @Date: 2023-08-23 20:36:24
//! @LastEditTime: 2024-06-08 15:59:33
//! @Description:

#include "user.h"
// TODO
void USER_checkForErrors(USER_Params *pUserParams)
{
    USER_setErrorCode(pUserParams, USER_PARAMS_NoError);
}

// 设置控制参数
void USER_setParams(USER_Params *pUserParams)
{
    // CTRL类参数赋值
    pUserParams->CTRL.systemFreq_MHz = USER_SYSTEM_FREQ_MHz;

    pUserParams->CTRL.pwmFreq_kHz = USER_PWM_Freq_kHz;
    pUserParams->CTRL.pwmPeriod_usec = (1000.0 / USER_PWM_Freq_kHz);

    pUserParams->CTRL.isrFreq_kHz = pUserParams->CTRL.pwmFreq_kHz * USER_numPwmTicksPerIsrTicks;

    pUserParams->CTRL.ctrlFreq_kHz = pUserParams->CTRL.isrFreq_kHz * USER_numIsrTicksPerCtrlTick;
    pUserParams->CTRL.ctrlPeriod_sec = 1.0 / pUserParams->CTRL.ctrlFreq_kHz;

    pUserParams->CTRL.currCtrlFreq_Hz = pUserParams->CTRL.ctrlFreq_kHz * USER_numCtrlTicksPerCurrentTick * 1000.0;
    pUserParams->CTRL.spdCtrlFreq_Hz = pUserParams->CTRL.ctrlFreq_kHz * USER_numCtrlTicksPerSpeedTick * 1000.0;
    pUserParams->CTRL.trajFreq_Hz = pUserParams->CTRL.ctrlFreq_kHz * USER_numCtrlTicksPerTrajTick * 1000.0;
    pUserParams->CTRL.estFreq_Hz = pUserParams->CTRL.ctrlFreq_kHz * USER_numCtrlTicksPerEstTick * 1000.0;

    pUserParams->CTRL.numCtrlTicksPerCurrentTick = USER_numCtrlTicksPerCurrentTick;
    pUserParams->CTRL.numPwmTicksPerIsrTick = USER_numIsrTicksPerCtrlTick;
    pUserParams->CTRL.numCtrlTicksPerEstTick = USER_numCtrlTicksPerEstTick;
    pUserParams->CTRL.numCtrlTicksPerSpeedTick = USER_numCtrlTicksPerSpeedTick;
    pUserParams->CTRL.numCtrlTicksPerTrajTick - USER_numCtrlTicksPerTrajTick;

    pUserParams->CTRL.maxAccel_Hzps = USER_MAX_ACCEL_Hzps;

    pUserParams->CTRL.ctrlWaitTime[FOC_CTRL_State_Error] = 0;
    pUserParams->CTRL.ctrlWaitTime[FOC_CTRL_State_Idle] = 0;
    pUserParams->CTRL.ctrlWaitTime[FOC_CTRL_State_OffLine] = (uint_least32_t)(5.0 * pUserParams->CTRL.ctrlFreq_kHz * 1000);
    pUserParams->CTRL.ctrlWaitTime[FOC_CTRL_State_OnLine] = 0;

    // MOTOR类参数赋值
    pUserParams->MOTOR.type = USER_MOTOR_TYPE;
    pUserParams->MOTOR.Ls_d_H = USER_MOTOR_Ls_d * 1000;
    pUserParams->MOTOR.Ls_q_H = USER_MOTOR_Ls_q * 1000;
    pUserParams->MOTOR.Rs_ohm = USER_MOTOR_Rs;
    pUserParams->MOTOR.Rr_ohm = USER_MOTOR_Rs;
    pUserParams->MOTOR.ratedFlux_VHz = USER_MOTOR_RATED_FLUX;
    pUserParams->MOTOR.numPolePairs = USER_MOTOR_NUM_POLE_PAIRS;

    // FBK类参数赋值
    pUserParams->FBK.fullScaleCurrent_A = USER_FULL_SCALE_CURRENT_A;
    pUserParams->FBK.fullScaleVoltage_V = USER_FULL_SCALE_VOLTAGE_V;
    pUserParams->FBK.fullScaleFreq_Hz = USER_FULL_SCALE_FREQ_Hz;
    pUserParams->FBK.current_sf = (float_t)((USER_ADC_FULL_SCALE_CURRENT_A) / (USER_FULL_SCALE_CURRENT_A));
    pUserParams->FBK.voltage_sf = ((float_t)((USER_ADC_FULL_SCALE_PH_VOLTAGE_V) / (USER_FULL_SCALE_VOLTAGE_V)));
    pUserParams->FBK.voltageFilterPole_Hz = USER_VOLTAGE_FILTER_POLE_Hz;
    pUserParams->FBK.numCurrentSensors = USER_NUM_CURRENT_SENSORS;
    pUserParams->FBK.numVoltageSensors = USER_NUM_VOLTAGE_SENSORS;
    pUserParams->FBK.offsetPole_Hz = USER_OFFSET_POLE_Hz;
    pUserParams->FBK.speedPole_Hz = USER_SPEED_POLE_Hz;
    pUserParams->FBK.dcBusPole_Hz = USER_DCBUS_POLE_Hz;
    pUserParams->FBK.currSensorDirection = USER_CURR_SENSOR_DIRECTION;
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
