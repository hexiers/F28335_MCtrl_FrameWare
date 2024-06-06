
//! @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_Driver\Include\adc.h
//! @Author: Hex
//! @Date: 2023-08-20 21:25:26
//! @LastEditTime: 2023-08-27 17:24:33
//! @Description: ADC函数，已做修改

#ifndef _ADC_H_
#define _ADC_H_

// **************************************************************************
// the includes

// drivers
#include "../../MotCtl_Driver/Include/cpu.h"
#include "types.h"

// **************************************************************************
// the defines

//! \brief Defines the base address of the analog-to-digital converter (ADC) registers
//!
#define ADC_BASE_ADDR (0x00007100)

//! \brief Defines the ADC delay for part of the ADC initialization
//!
#define ADC_DELAY_usec 10000L

//! \brief 定义ADC数位
//!
#define ADC_numBits 12

//! \brief 定义 1.65V 偏置值输入对应数位 (3.3V input, 12 bit ADC)
//!
#define ADC_dataBias (1 << (ADC_numBits - 1))

//!
#define ADC_ADCCTL1_SEQ_CASC _BITS(1 << 4)
#define ADC_ADCCTL1_SEQ_OVRD_BITS (1 << 5)
#define ADC_ADCCTL1_CONT_RUN_BITS (1 << 6)
#define ADC_ADCCTL1_CPS_BITS (1 << 7)
#define ADC_ADCCTL1_RESET_BITS (1 << 14)

// **************************************************************************
// the typedefs

typedef enum
{
  ADC_SeqMode_Cascade = 0,
  ADC_SeqMode_DualSeq
} ADC_SeqMode_e;



#define NOP asm(" RPT #1 || NOP");
#define NOP7 asm(" RPT #7 || NOP");
//---------------------------------------------------------------------------
// ADC Individual Register Bit Definitions:

struct ADCTRL1_BITS
{                      // bits  description
  uint16_t rsvd1 : 4;    // 3:0   reserved
  uint16_t SEQ_CASC : 1; // 4     Cascaded sequencer mode
  uint16_t SEQ_OVRD : 1; // 5     Sequencer override
  uint16_t CONT_RUN : 1; // 6     Continuous run
  uint16_t CPS : 1;      // 7     ADC core clock pre-scalar
  uint16_t ACQ_PS : 4;   // 11:8  Acquisition window size
  uint16_t SUSMOD : 2;   // 13:12 Emulation suspend mode
  uint16_t RESET : 1;    // 14    ADC reset
  uint16_t rsvd2 : 1;    // 15    reserved
};

union ADCTRL1_REG
{
  uint16_t all;
  struct ADCTRL1_BITS bit;
};

struct ADCTRL2_BITS
{                            // bits  description
  uint16_t EPWM_SOCB_SEQ2 : 1; // 0     EPWM compare B SOC mask for SEQ2
  uint16_t rsvd1 : 1;          // 1     reserved
  uint16_t INT_MOD_SEQ2 : 1;   // 2     SEQ2 Interrupt mode
  uint16_t INT_ENA_SEQ2 : 1;   // 3     SEQ2 Interrupt enable
  uint16_t rsvd2 : 1;          // 4     reserved
  uint16_t SOC_SEQ2 : 1;       // 5     Start of conversion for SEQ2
  uint16_t RST_SEQ2 : 1;       // 6     Reset SEQ2
  uint16_t EXT_SOC_SEQ1 : 1;   // 7     External start of conversion for SEQ1
  uint16_t EPWM_SOCA_SEQ1 : 1; // 8     EPWM compare B SOC mask for SEQ1
  uint16_t rsvd3 : 1;          // 9     reserved
  uint16_t INT_MOD_SEQ1 : 1;   // 10    SEQ1 Interrupt mode
  uint16_t INT_ENA_SEQ1 : 1;   // 11    SEQ1 Interrupt enable
  uint16_t rsvd4 : 1;          // 12    reserved
  uint16_t SOC_SEQ1 : 1;       // 13    Start of conversion trigger for SEQ1
  uint16_t RST_SEQ1 : 1;       // 14    Restart sequencer 1
  uint16_t EPWM_SOCB_SEQ : 1;  // 15    EPWM compare B SOC enable
};

union ADCTRL2_REG
{
  uint16_t all;
  struct ADCTRL2_BITS bit;
};

struct ADCASEQSR_BITS
{                        // bits   description
  uint16_t SEQ1_STATE : 4; // 3:0    SEQ1 state
  uint16_t SEQ2_STATE : 3; // 6:4    SEQ2 state
  uint16_t rsvd1 : 1;      // 7      reserved
  uint16_t SEQ_CNTR : 4;   // 11:8   Sequencing counter status
  uint16_t rsvd2 : 4;      // 15:12  reserved
};

union ADCASEQSR_REG
{
  uint16_t all;
  struct ADCASEQSR_BITS bit;
};

struct ADCMAXCONV_BITS
{                       // bits  description
  uint16_t MAX_CONV1 : 4; // 3:0   Max number of conversions
  uint16_t MAX_CONV2 : 3; // 6:4   Max number of conversions
  uint16_t rsvd1 : 9;     // 15:7  reserved
};

union ADCMAXCONV_REG
{
  uint16_t all;
  struct ADCMAXCONV_BITS bit;
};

struct ADCCHSELSEQ1_BITS
{                    // bits   description
  uint16_t CONV00 : 4; // 3:0    Conversion selection 00
  uint16_t CONV01 : 4; // 7:4    Conversion selection 01
  uint16_t CONV02 : 4; // 11:8   Conversion selection 02
  uint16_t CONV03 : 4; // 15:12  Conversion selection 03
};

union ADCCHSELSEQ1_REG
{
  uint16_t all;
  struct ADCCHSELSEQ1_BITS bit;
};

struct ADCCHSELSEQ2_BITS
{                    // bits   description
  uint16_t CONV04 : 4; // 3:0    Conversion selection 04
  uint16_t CONV05 : 4; // 7:4    Conversion selection 05
  uint16_t CONV06 : 4; // 11:8   Conversion selection 06
  uint16_t CONV07 : 4; // 15:12  Conversion selection 07
};

union ADCCHSELSEQ2_REG
{
  uint16_t all;
  struct ADCCHSELSEQ2_BITS bit;
};

struct ADCCHSELSEQ3_BITS
{                    // bits   description
  uint16_t CONV08 : 4; // 3:0    Conversion selection 08
  uint16_t CONV09 : 4; // 7:4    Conversion selection 09
  uint16_t CONV10 : 4; // 11:8   Conversion selection 10
  uint16_t CONV11 : 4; // 15:12  Conversion selection 11
};

union ADCCHSELSEQ3_REG
{
  uint16_t all;
  struct ADCCHSELSEQ3_BITS bit;
};

struct ADCCHSELSEQ4_BITS
{                    // bits   description
  uint16_t CONV12 : 4; // 3:0    Conversion selection 12
  uint16_t CONV13 : 4; // 7:4    Conversion selection 13
  uint16_t CONV14 : 4; // 11:8   Conversion selection 14
  uint16_t CONV15 : 4; // 15:12  Conversion selection 15
};

union ADCCHSELSEQ4_REG
{
  uint16_t all;
  struct ADCCHSELSEQ4_BITS bit;
};

struct ADCTRL3_BITS
{                       // bits   description
  uint16_t SMODE_SEL : 1; // 0      Sampling mode select
  uint16_t ADCCLKPS : 4;  // 4:1    ADC core clock divider
  uint16_t ADCPWDN : 1;   // 5      ADC powerdown
  uint16_t ADCBGRFDN : 2; // 7:6    ADC bandgap/ref power down
  uint16_t rsvd1 : 8;     // 15:8   reserved
};

union ADCTRL3_REG
{
  uint16_t all;
  struct ADCTRL3_BITS bit;
};

struct ADCST_BITS
{                          // bits   description
  uint16_t INT_SEQ1 : 1;     // 0      SEQ1 Interrupt flag
  uint16_t INT_SEQ2 : 1;     // 1      SEQ2 Interrupt flag
  uint16_t SEQ1_BSY : 1;     // 2      SEQ1 busy status
  uint16_t SEQ2_BSY : 1;     // 3      SEQ2 busy status
  uint16_t INT_SEQ1_CLR : 1; // 4      SEQ1 Interrupt clear
  uint16_t INT_SEQ2_CLR : 1; // 5      SEQ2 Interrupt clear
  uint16_t EOS_BUF1 : 1;     // 6      End of sequence buffer1
  uint16_t EOS_BUF2 : 1;     // 7      End of sequence buffer2
  uint16_t rsvd1 : 8;        // 15:8   reserved
};

union ADCST_REG
{
  uint16_t all;
  struct ADCST_BITS bit;
};

struct ADCREFSEL_BITS
{                     // bits   description
  uint16_t rsvd1 : 14;  // 13:0   reserved
  uint16_t REF_SEL : 2; // 15:14  Reference select
};
union ADCREFSEL_REG
{
  uint16_t all;
  struct ADCREFSEL_BITS bit;
};

struct ADCOFFTRIM_BITS
{                        // bits   description
  int16 OFFSET_TRIM : 9; // 8:0    Offset Trim
  uint16_t rsvd1 : 7;      // 15:9   reserved
};

union ADCOFFTRIM_REG
{
  uint16_t all;
  struct ADCOFFTRIM_BITS bit;
};

//! \brief Defines the analog-to-digital converter (ADC) object
//!
typedef struct _ADC_Obj_
{
  union ADCTRL1_REG ADCTRL1; //!< ADC Control Register 1
  volatile uint16_t_t ADCTRL2; //!< ADC Control Register 2
  volatile uint16_t_t ADCMAXCONV;
  volatile uint16_t_t ADCCHSELSEQ1;
  volatile uint16_t_t ADCCHSELSEQ2;
  volatile uint16_t_t ADCCHSELSEQ3;
  volatile uint16_t_t ADCCHSELSEQ4;
  volatile uint16_t_t ADCASEQSR;
  volatile uint16_t_t ADCRESULT[16]; // 左对齐寄存器，映射的右对齐寄存器位于 (0x0B00-0x0B0F) 空间
  volatile uint16_t_t ADCTRL3;
  volatile uint16_t_t ADCST;
  volatile uint16_t_t ADCREFSEL;
  volatile uint16_t_t ADCOFFTRIM;
} ADC_Obj;

//! \brief Defines the analog-to-digital converter (ADC) handle
//!
typedef struct _ADC_Obj_ *ADC_Handle;

// **************************************************************************
// the globals

// **************************************************************************
// the function prototypes

//! \brief     Clears the analog-to-digital converter (ADC) interrupt flag
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] intNumber  The ADC interrupt number
static inline void ADC_clearIntFlag(ADC_Handle adcHandle, const ADC_IntNumber_e intNumber)
{
  ADC_Obj *adc = (ADC_Obj *)adcHandle;

  // clear the bit
  adc->ADCINTFLGCLR = 1 << intNumber;

  return;
} // end of ADC_clearIntFlag() function

//! \brief     Gets the analog-to-digital converter (ADC) interrupt flag
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] intNumber  The ADC interrupt number
//! \return    The ADC interrupt flag status
static inline bool ADC_getIntFlag(ADC_Handle adcHandle, const ADC_IntNumber_e intNumber)
{
  ADC_Obj *adc = (ADC_Obj *)adcHandle;
  bool status;

  // check the status of the bit
  status = (bool)(adc->ADCINTFLG & (1 << intNumber) >> intNumber);

  return (status);
} // end of ADC_getIntFlag() function

//! \brief   ADC复位
extern void ADC_reset(ADC_Handle adcHandle);

//! \brief   ADC seq模式选择
extern void ADC_setSeqMode(ADC_Handle adcHandle, ADC_SeqMode_e seqmode);

//! \brief     Disables the analog-to-digital converter (ADC) band gap circuit
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
extern void ADC_disableBandGap(ADC_Handle adcHandle);

//! \brief     Disables the analog-to-digital converter (ADC) interrupt
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] intNumber  The interrupt number
extern void ADC_disableInt(ADC_Handle adcHandle, const ADC_IntNumber_e intNumber);

//! \brief     Disables the analog-to-digital converter (ADC) reference buffers circuit
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
extern void ADC_disableRefBuffers(ADC_Handle adcHandle);

//! \brief     Enables the analog-to-digital converter (ADC) band gap circuit
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
extern void ADC_enableBandGap(ADC_Handle adcHandle);

//! \brief     Enables the analog-to-digital converter (ADC) interrupt
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] intNumber  The interrupt number
extern void ADC_enableInt(ADC_Handle adcHandle, const ADC_IntNumber_e intNumber);

//! \brief     Enables the analog-to-digital converter (ADC) reference buffers circuit
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
extern void ADC_enableRefBuffers(ADC_Handle adcHandle);

//! \brief     Gets the analog-to-digital converter (ADC) divide select value
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \return    The divide select value
extern ADC_DivideSelect_e ADC_getDivideSelect(ADC_Handle adcHandle);

//! \brief     Gets the analog-to-digital converter (ADC) start-of-conversion (SOC) sample delay value
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] socNumber  The SOC number
//! \return    The ADC sample delay value
static inline ADC_SocSampleDelay_e ADC_getSocSampleDelay(ADC_Handle adcHandle, const ADC_SocNumber_e socNumber)
{
  ADC_Obj *adc = (ADC_Obj *)adcHandle;
  ADC_SocSampleDelay_e sampleDelay;

  // get the bits
  sampleDelay = (ADC_SocSampleDelay_e)(adc->ADCSOCxCTL[socNumber] & ADC_ADCSOCxCTL_ACQPS_BITS);

  return (sampleDelay);
} // end of ADC_getSocSampleDelay() function

//! \brief     Initializes the analog-to-digital converter (ADC) object handle
//! \param[in] pMemory   A pointer to the base address of the ADC registers
//! \param[in] numBytes  The number of bytes allocated for the ADC object, bytes
//! \return    The analog-to-digital converter (ADC) object handle
extern ADC_Handle ADC_init(void *pMemory, const size_t numBytes);

//! \brief     Powers down the analog-to-digital converter (ADC)
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
extern void ADC_powerDown(ADC_Handle adcHandle);

//! \brief     Powers up the analog-to-digital converter (ADC)
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
extern void ADC_powerUp(ADC_Handle adcHandle);

//! \brief     Reads the specified ADC result (i.e. value)
//! \param[in] adcHandle     The ADC handle
//! \param[in] resultNumber  The result number for the ADCRESULT registers
//! \return    The ADC result
static inline uint_least16_t ADC_readResult(ADC_Handle adcHandle, const ADC_ResultNumber_e resultNumber)
{
  ADC_Obj *adc = (ADC_Obj *)adcHandle;

  return (adc->ADCRESULT[resultNumber]);
} // end of ADC_read() function

//! \brief     Sets the analog-to-digital converter (ADC) divide select value
//! \param[in] adcHandle    The analog-to-digital converter (ADC) object handle
//! \param[in] divSelect    The scale reference source
extern void ADC_setDivideSelect(ADC_Handle adcHandle, const ADC_DivideSelect_e divSelect);

//! \brief     Sets the interrupt mode
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] intNumber  The interrupt number
//! \param[in] intMode    The interrupt mode
extern void ADC_setIntMode(ADC_Handle adcHandle, const ADC_IntNumber_e intNumber, const ADC_IntMode_e intMode);

//! \brief     Sets the interrupt pulse generation mode
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] pulseMode  The pulse generation mode
extern void ADC_setIntPulseGenMode(ADC_Handle adcHandle, const ADC_IntPulseGenMode_e pulseMode);

//! \brief     Sets the interrupt source
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] intNumber  The interrupt number
//! \param[in] intSrc     The interrupt source
extern void ADC_setIntSrc(ADC_Handle adcHandle, const ADC_IntNumber_e intNumber, const ADC_IntSrc_e intSrc);

//! \brief     Sets the sample mode
//! \param[in] adcHandle   The analog-to-digital converter (ADC) object handle
//! \param[in] sampleMode  The sample mode
extern void ADC_setSampleMode(ADC_Handle adcHandle, const ADC_SampleMode_e sampleMode);

//! \brief     Sets the start-of-conversion (SOC) channel number
//! \param[in] adcHandle   The analog-to-digital converter (ADC) object handle
//! \param[in] socNumber   The SOC number
//! \param[in] chanNumber  The channel number
extern void ADC_setSocChanNumber(ADC_Handle adcHandle, const ADC_SocNumber_e socNumber, const ADC_SocChanNumber_e chanNumber);

//! \brief     Sets the start-of-conversion (SOC) sample delay
//! \param[in] adcHandle    The analog-to-digital converter (ADC) object handle
//! \param[in] socNumber    The SOC number
//! \param[in] sampleDelay  The sample delay
extern void ADC_setSocSampleDelay(ADC_Handle adcHandle, const ADC_SocNumber_e socNumber, const ADC_SocSampleDelay_e sampleDelay);

//! \brief     Sets the start-of-conversion (SOC) trigger source
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] socNumber  The SOC number
//! \param[in] trigSrc    The trigger delay
extern void ADC_setSocTrigSrc(ADC_Handle adcHandle, const ADC_SocNumber_e socNumber, const ADC_SocTrigSrc_e trigSrc);

//! \brief     Sets the start-of-conversion (SOC) force register
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] socFrc     The SOC to be forced a conversion
extern void ADC_setSocFrc(ADC_Handle adcHandle, const ADC_SocFrc_e socFrc);

//! \brief     Sets the temperature sensor source
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] sensorSrc  The temperature sensor source
extern void ADC_setTempSensorSrc(ADC_Handle adcHandle, const ADC_TempSensorSrc_e sensorSrc);

//! \brief     Sets the voltage reference source
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] voltRef    The voltage reference source
extern void ADC_setVoltRefSrc(ADC_Handle adcHandle, const ADC_VoltageRefSrc_e voltRef);

//! \brief     Sets the offset trim register
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
//! \param[in] offtrim    The offset trim value
extern void ADC_setOffTrim(ADC_Handle adcHandle, const uint16_t_t offtrim);

//! \brief     Enables conversion of the voltage reference low signal for calibration
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
extern void ADC_enableVoltRefLoConv(ADC_Handle adcHandle);

//! \brief     Disables conversion of the voltage reference low signal for calibration
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
extern void ADC_disableVoltRefLoConv(ADC_Handle adcHandle);

//! \brief     Sets the start of conversion (SOC) trigger source
//! \param[in] adcHandle    The analog-to-digital converter (ADC) object handle
//! \param[in] socNumber    The start of conversion (SOC) number
//! \param[in] intTrigSrc   The interrupt trigger source
extern void ADC_setupSocTrigSrc(ADC_Handle adcHandle, const ADC_SocNumber_e socNumber, const ADC_IntTriggerSOC_e intTrigSrc);

//! \brief     Sets the entire start of conversion (SOC) force register
//! \param[in] adcHandle    The analog-to-digital converter (ADC) object handle
//! \param[in] socFrc       The desired start of conversion force value
extern void ADC_setSocFrcWord(ADC_Handle adcHandle, const uint16_t_t socFrc);

//! \brief     Enables no overlap mode
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
extern void ADC_enableNoOverlapMode(ADC_Handle adcHandle);

//! \brief     Disables no overlap mode
//! \param[in] adcHandle  The analog-to-digital converter (ADC) object handle
extern void ADC_disableNoOverlapMode(ADC_Handle adcHandle);

#ifdef __cplusplus
}
#endif // extern "C"

//@} // ingroup
#endif // end of _ADC_H_ definition
