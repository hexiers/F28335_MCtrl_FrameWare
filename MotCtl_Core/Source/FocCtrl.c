/*****************************************************************************
 * File name: 	FocCtrl.c
 *    Author: 	Hex
 *	  E-mail: 	hex@hust.edu.cn
 *    Date  : 	2024年6月9日
 *	  Description:
 *****************************************************************************/
#include "FocCtrl.h"

void FocCtrl_setParams(FOC_CTRL_Handle handle, USER_Params *pUserParams)
{
    FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

    _iq Kp, Ki;
    _iq outMin, outMax;
    _iq maxModulation;

    // 初始值赋0
    MATH_vec2 Iab_out_pu = {_IQ(0.0), _IQ(0.0)};
    MATH_vec2 Idq_out_pu = {_IQ(0.0), _IQ(0.0)};
    MATH_vec2 Idq_ref_pu = {_IQ(0.0), _IQ(0.0)};
    MATH_vec2 Vab_in_pu = {_IQ(0.0), _IQ(0.0)};
    MATH_vec2 Vab_out_pu = {_IQ(0.0), _IQ(0.0)};
    MATH_vec2 Vdq_out_pu = {_IQ(0.0), _IQ(0.0)};

    // 设置电机参数
    FocCtrl_setMotorParams(handle, pUserParams->MOTOR.type,
                           pUserParams->MOTOR.numPolePairs,
                           pUserParams->MOTOR.ratedFlux_VHz,
                           pUserParams->MOTOR.Ls_d_H,
                           pUserParams->MOTOR.Ls_q_H,
                           pUserParams->MOTOR.Rr_ohm,
                           pUserParams->MOTOR.Rs_ohm);

    // 设置控制时钟参数
    FocCtrl_setNumIsrTicksPerCtrlTick(handle, pUserParams->CTRL.numIsrTicksPerCtrlTick);
    FocCtrl_setNumCtrlTicksPerCurrentTick(handle, pUserParams->CTRL.numCtrlTicksPerCurrentTick);
    FocCtrl_setNumCtrlTicksPerSpeedTick(handle, pUserParams->CTRL.numCtrlTicksPerSpeedTick);
    FocCtrl_setNumCtrlTicksPerTrajTick(handle, pUserParams->CTRL.numCtrlTicksPerTrajTick);

    FocCtrl_setCtrlFreq_Hz(handle, pUserParams->CTRL.ctrlFreq_kHz);
    FocCtrl_setCtrlPeriod_sec(handle, pUserParams->CTRL.ctrlPeriod_sec);

    // CTRL_setMaxVsMag_pu(handle, _IQ(pUserParams->maxVsMag_pu));

    FocCtrl_setIab_in_pu(handle, &Iab_out_pu);
    FocCtrl_setIdq_in_pu(handle, &Idq_out_pu);
    FocCtrl_setIdq_ref_pu(handle, &Idq_ref_pu);

    FocCtrl_setVab_in_pu(handle, &Vab_in_pu);
    FocCtrl_setVab_out_pu(handle, &Vab_out_pu);
    FocCtrl_setVdq_out_pu(handle, &Vdq_out_pu);

    FocCtrl_setSpd_out_pu(handle, _IQ(0.0));

    // 重置各个环的计数器
    FocCtrl_resetCounter_current(handle);
    FocCtrl_resetCounter_isr(handle);
    FocCtrl_resetCounter_speed(handle);
    FocCtrl_resetCounter_state(handle);

    // 设置状态机等待时间
    FocCtrl_setWaitTimes(handle, &pUserParams->CTRL.ctrlWaitTime[0]);

    // 设置标志位
    FocCtrl_setFlag_enableCtrl(handle, false);
    FocCtrl_setFlag_enableOffset(handle, true);
    FocCtrl_setFlag_enableSpeedCtrl(handle, true);
    FocCtrl_setFlag_enableUserMotorParams(handle, false);
    FocCtrl_setFlag_enableDcBusComp(handle, true);

    // 使能电流环寄存器
    FocCtrl_setFlag_enableCurrentCtrl(handle, true);

    // 初始化故障寄存器
    FocCtrl_setErrorCode(handle, CTRL_ErrorCode_NoError);

    // 设置控制器初始状态
    FocCtrl_setState(handle, FOC_CTRL_State_Idle);

    // 设置电流传感器个数
    FocCtrl_setupClarke_I(handle, pUserParams->FBK.numCurrentSensors);

    // 设置电压传感器个数
    FocCtrl_setupClarke_V(handle, pUserParams->FBK.numVoltageSensors);

    // 设置默认的id PI控制参数
    Kp = _IQ(0.1);
    Ki = _IQ(pUserParams->CTRL.ctrlPeriod_sec / 0.004);
    outMin = _IQ(-0.95);
    outMax = _IQ(0.95);
    PI_setGains(obj->piHandle_Id, Kp, Ki);
    PI_setUi(obj->piHandle_Id, _IQ(0.0));
    PI_setMinMax(obj->piHandle_Id, outMin, outMax);

    // 设置默认的iq PI控制参数
    Kp = _IQ(0.1);
    Ki = _IQ(pUserParams->CTRL.ctrlPeriod_sec / 0.004);
    outMin = _IQ(-0.95);
    outMax = _IQ(0.95);
    PI_setGains(obj->piHandle_Iq, Kp, Ki);
    PI_setUi(obj->piHandle_Iq, _IQ(0.0));
    PI_setMinMax(obj->piHandle_Iq, outMin, outMax);

    // 设置默认的speed PI控制参数
    Kp = _IQ(0.02 * pUserParams->MOTOR.maxCurr_A * pUserParams->FBK.fullScaleFreq_Hz / pUserParams->FBK.fullScaleCurrent_A);
    Ki = _IQ(2.0 * pUserParams->MOTOR.maxCurr_A * pUserParams->FBK.fullScaleFreq_Hz * pUserParams->CTRL.ctrlPeriod_sec / pUserParams->FBK.fullScaleCurrent_A);
    outMin = _IQ(-1.0);
    outMax = _IQ(1.0);
    PI_setGains(obj->piHandle_spd, Kp, Ki);
    PI_setUi(obj->piHandle_spd, _IQ(0.0));
    PI_setMinMax(obj->piHandle_spd, outMin, outMax);

    // 设置速度参考值为0
    FocCtrl_setSpd_ref_pu(handle, _IQ(0.0));

    // 设置最大的调制比
    maxModulation = _IQ(MATH_TWO_OVER_THREE);
    SVGEN_setMaxModulation(obj->svgenHandle, maxModulation);

    return;
} // end of CTRL_setParams() function

void FocCtrl_setupClarke_I(FOC_CTRL_Handle handle, uint_least8_t numCurrentSensors)
{
    FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

    _iq alpha_sf, beta_sf;

    // initialize the Clarke transform module for current
    if (numCurrentSensors == 3)
    {
        alpha_sf = _IQ(MATH_ONE_OVER_THREE);
        beta_sf = _IQ(MATH_ONE_OVER_SQRT_THREE);
    }
    else if (numCurrentSensors == 2)
    {
        alpha_sf = _IQ(1.0);
        beta_sf = _IQ(MATH_ONE_OVER_SQRT_THREE);
    }
    else
    {
        alpha_sf = _IQ(0.0);
        beta_sf = _IQ(0.0);
    }

    // set the parameters
    CLARKE_setScaleFactors(obj->clarkeHandle_I, alpha_sf, beta_sf);
    CLARKE_setNumSensors(obj->clarkeHandle_I, numCurrentSensors);

    return;
} // end of FocCtrl_setupClarke_I() function

void FocCtrl_setupClarke_V(FOC_CTRL_Handle handle, uint_least8_t numVoltageSensors)
{
    FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;
    _iq alpha_sf, beta_sf;

    // initialize the Clarke transform module for current
    if (numVoltageSensors == 3)
    {
        alpha_sf = _IQ(MATH_ONE_OVER_THREE);
        beta_sf = _IQ(MATH_ONE_OVER_SQRT_THREE);
    }
    else
    {
        alpha_sf = _IQ(0.0);
        beta_sf = _IQ(0.0);
    }

    // set the parameters
    CLARKE_setScaleFactors(obj->clarkeHandle_V, alpha_sf, beta_sf);
    CLARKE_setNumSensors(obj->clarkeHandle_V, numVoltageSensors);

    return;
} // end of CTRL_setupClarke_V() function

void FocCtrl_setWaitTimes(FOC_CTRL_Handle handle, const uint_least32_t *pWaitTimes)
{
    FOC_CTRL_Obj *obj = (FOC_CTRL_Obj *)handle;

    uint_least16_t stateCnt;

    for (stateCnt = 0; stateCnt < FOC_CTRL_numStates; stateCnt++)
    {
        obj->waitTimes[stateCnt] = pWaitTimes[stateCnt];
    }

    return;
} // end of CTRL_setWaitTimes() function
