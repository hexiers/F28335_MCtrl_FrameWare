
//! @FilePath: \F28335_MotCtl_Frameware\DSP28xx_MotCtl_Frameware\MotCtl_Driver\Source\adc.c
//! @Author: Hex
//! @Date: 2023-08-20 21:25:26
//! @LastEditTime: 2024-06-04 23:39:08
//! @Description: 


// **************************************************************************
// the includes
#include "../Include/adc.h"

// assembly file
extern void usDelay(uint32_t Count);

// **************************************************************************
// the defines

// **************************************************************************
// the globals

// **************************************************************************
// the functions

//! @brief: ADC曆梟場宎趙
ADC_Handle ADC_init(void *pMemory, const size_t numBytes)
{
  ADC_Handle adcHandle;

  if (numBytes < sizeof(ADC_Obj))
    return ((ADC_Handle)NULL);

  // assign the handle
  adcHandle = (ADC_Handle)pMemory;

  return (adcHandle);
} // end of ADC_init() function

//! @brief: ADC囀瞄萇埭奻萇
void ADC_setPower(ADC_Handle adcHandle, ADC_PwrMode_e pwrmode)
{
  ADC_Obj *adc = (ADC_Obj *)adcHandle;

  // clear the bits
  adc->ADCTRL3.bit.ADCPWDN = pwrmode;

  return;
} // end of ADC_setPower() function

void ADC_reset(ADC_Handle adcHandle)
{
  ADC_Obj *adc = (ADC_Obj *)adcHandle;

  ENABLE_PROTECTED_REGISTER_WRITE_MODE;
  // set the bits
  adc->ADCTRL1.bit.RESET = 1;

  DISABLE_PROTECTED_REGISTER_WRITE_MODE;

  return;
} // end of ADC_reset() function

void ADC_setSeqMode(ADC_Handle adcHandle, ADC_SeqMode_e seqmode, ADC_SeqOvrd_e SeqOvrd)
{
  ADC_Obj *adc = (ADC_Obj *)adcHandle;

  adc->ADCTRL1.bit.SEQ_CASC = seqmode;

  adc->ADCTRL1.bit.SEQ_OVRD = SeqOvrd;

  return;
}

void ADC_setRunMode(ADC_Handle adcHandle, ADC_RunMode_e runmode)
{
  ADC_Obj *adc = (ADC_Obj *)adcHandle;

  adc->ADCTRL1.bit.CONT_RUN = runmode;

  return;
}

void ADC_setClockPrescale(ADC_Handle adcHandle, ADC_CpsMode_e Cps, ADC_CLKPS_e ClkPS)
{
  ADC_Obj *adc = (ADC_Obj *)adcHandle;

  adc->ADCTRL1.bit.CPS = Cps;

  adc->ADCTRL3.bit.ADCCLKPS= ClkPS;

  return;
}

void ADC_setAcqWindowSize(ADC_Handle adcHandle, ADC_ACQPS_e ACQPSMode)
{
  ADC_Obj *adc = (ADC_Obj *)adcHandle;

  adc->ADCTRL1.bit.ACQ_PS = ACQPSMode;

  return;
}

void ADC_setSuspendMode(ADC_Handle adcHandle, ADC_SusMode_e SusMode)
{
  ADC_Obj *adc = (ADC_Obj *)adcHandle;

  adc->ADCTRL1.bit.SUSMOD = SusMode;

  return;
}

void ADC_resetSeq(ADC_Handle adcHandle, ADC_SeqNumber_e SeqNum)
{
  ADC_Obj *adc = (ADC_Obj *)adcHandle;

  if (SeqNum == ADC_SeqNumber_1)
  {
    adc->ADCTRL2.bit.RST_SEQ1 = 1;
  }
  else if (SeqNum == ADC_SeqNumber_2)
  {
    adc->ADCTRL2.bit.RST_SEQ2 = 1;
  }

  return;
}

void ADC_setRefSource(ADC_Handle adcHandle, ADC_RefSel_e RefSel)
{
  ADC_Obj *adc = (ADC_Obj *)adcHandle;

  adc->ADCREFSEL.bit.REF_SEL = RefSel;

  return;
}

void ADC_setIntMode(ADC_Handle adcHandle, ADC_SeqNumber_e seqmode, ADC_EN_e EnableSeq, ADC_IntModSeq_e IntModSeq)
{
  ADC_Obj *adc = (ADC_Obj *)adcHandle;

  if (seqmode == ADC_SeqNumber_1)
  {
    adc->ADCTRL2.bit.INT_ENA_SEQ1 = EnableSeq;

    adc->ADCTRL2.bit.INT_MOD_SEQ1 = IntModSeq;
  }
  else if (seqmode == ADC_SeqNumber_2)
  {
    adc->ADCTRL2.bit.INT_ENA_SEQ2 = EnableSeq;

    adc->ADCTRL2.bit.INT_MOD_SEQ2 = IntModSeq;
  }

  return;
}

void ADC_setSocMode(ADC_Handle adcHandle, ADC_SocMode_e SOCMode, ADC_EN_e EnableSOCMode)
{
  ADC_Obj *adc = (ADC_Obj *)adcHandle;

  if (SOCMode == ADC_SOCA_SEQ1_EN)
  {
    adc->ADCTRL2.bit.EPWM_SOCA_SEQ1 = 1;

    adc->ADCTRL2.bit.EPWM_SOCB_SEQ2 = 0;

    adc->ADCTRL2.bit.EPWM_SOCB_SEQ = 0;

    adc->ADCTRL2.bit.EXT_SOC_SEQ1 = 0;
  }

  return;
}

void ADC_softRunSoc(ADC_Handle adcHandle, ADC_SeqNumber_e seqmode)
{
  ADC_Obj *adc = (ADC_Obj *)adcHandle;

  if (seqmode == ADC_SeqNumber_1)

    adc->ADCTRL2.bit.SOC_SEQ1 = 1;

  else if (seqmode == ADC_SeqNumber_2)

    adc->ADCTRL2.bit.SOC_SEQ2 = 1;

  return;
}

void ADC_setSMODSel(ADC_Handle adcHandle, ADC_sMod_e smode)
{
  ADC_Obj *adc = (ADC_Obj *)adcHandle;

  adc->ADCTRL3.bit.SMODE_SEL = smode;

  return;

}

void ADC_setADCBGRFDN(ADC_Handle adcHandle, ADC_BGRF_e BGRF)
{
  ADC_Obj *adc = (ADC_Obj *)adcHandle;

  adc->ADCTRL3.bit.ADCBGRFDN = BGRF;

  return;
}


void ADC_Read(ADC_Handle adcHandle, uint16_t *result)
{
  ADC_Obj *adc = (ADC_Obj *)adcHandle;

  uint16_t i = 0;
  for( i = 0;i<16; i++)
  {
	  *result = (adc->ADCRESULT[i] >> 4);
  	   result++;
  }


  return;
}

// end of file
