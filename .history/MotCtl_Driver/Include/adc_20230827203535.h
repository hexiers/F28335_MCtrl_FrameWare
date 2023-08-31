
//! @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_Driver\Include\adc.h
//! @Author: Hex
//! @Date: 2023-08-20 21:25:26
//! @LastEditTime: 2023-08-27 20:35:35
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

typedef enum
{
  ADC_SeqOvrd_disabled = 0,
  ADC_SeqOvrd_enabled = 1
} ADC_SeqOvrd_e;

typedef enum
{
  Power_Down= 0,
  Power_Up
} ADC_PwrMode_e;

#define NOP asm(" RPT #1 || NOP");
#define NOP7 asm(" RPT #7 || NOP");
//---------------------------------------------------------------------------
// ADC Individual Register Bit Definitions:

struct ADCTRL1_BITS
{                        // bits  description
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
{                              // bits  description
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
{                          // bits   description
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
{                         // bits  description
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
{                      // bits   description
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
{                      // bits   description
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
{                      // bits   description
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
{                      // bits   description
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
{                         // bits   description
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
{                            // bits   description
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
{                       // bits   description
  uint16_t rsvd1 : 14;  // 13:0   reserved
  uint16_t REF_SEL : 2; // 15:14  Reference select
};
union ADCREFSEL_REG
{
  uint16_t all;
  struct ADCREFSEL_BITS bit;
};

struct ADCOFFTRIM_BITS
{                           // bits   description
  uint16_t OFFSET_TRIM : 9; // 8:0    Offset Trim
  uint16_t rsvd1 : 7;       // 15:9   reserved
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
  union ADCTRL2_REG ADCTRL2; //!< ADC Control Register 2
  volatile uint16_t ADCMAXCONV;
  union ADCMAXCONV_REG ADCMAXCONV;     // Max conversions
  union ADCCHSELSEQ1_REG ADCCHSELSEQ1; // Channel select sequencing control 1
  union ADCCHSELSEQ2_REG ADCCHSELSEQ2; // Channel select sequencing control 2
  union ADCCHSELSEQ3_REG ADCCHSELSEQ3; // Channel select sequencing control 3
  union ADCCHSELSEQ4_REG ADCCHSELSEQ4; // Channel select sequencing control 4
  union ADCASEQSR_REG ADCASEQSR;
  volatile uint16_t ADCRESULT[16]; // 左对齐寄存器，映射的右对齐寄存器位于 (0x0B00-0x0B0F) 空间
  union ADCTRL3_REG ADCTRL3;
  union ADCST_REG  ADCST;
  volatile uint16_t rsvd1[2];
  union ADCREFSEL_REG    ADCREFSEL;     // Reference Select Register
  union ADCOFFTRIM_REG   ADCOFFTRIM;    // Offset Trim Register
} ADC_Obj;

//! \brief Defines the analog-to-digital converter (ADC) handle
//!
typedef struct _ADC_Obj_ *ADC_Handle;

// **************************************************************************
// the globals

// **************************************************************************
// the function prototypes


typedef enum
{
  ADC_StartStop_mode = 0,
  ADC_Continuous_mode
} ADC_RunMode_e;

typedef enum
{
  ADC_SOC_PulseClk_1 = 0,
  ADC_SOC_PulseClk_2,
  ADC_SOC_PulseClk_3,
  ADC_SOC_PulseClk_4,
  ADC_SOC_PulseClk_5,
  ADC_SOC_PulseClk_6
} ADC_ACQPS_e;

typedef enum
{
  ADC_HSPCLK_Div_1 = 0,
  ADC_HSPCLK_Div_2
} ADC_CpsMode_e;

typedef enum
{
  ADC_SUS_Ignored = 0,
  ADC_SUS_FinalresultLatched,
  ADC_SUS_ResultLatched,
  ADC_SUS_StopImmediately
} ADC_SusMode_e;

typedef enum
{
  ADC_SeqNumber_1 = 0,
  ADC_SeqNumber_2,
} ADC_SeqNumber_e;

typedef enum
{
  ADC_ClearSOC_Mode = 0,
  ADC_SOCA_SEQ1_EN,
  ADC_SOCB_SEQ2_EN,
  ADC_SOCB_SEQ_EN,   //仅级联有效
} ADC_SocMode_e;

typedef enum
{
  ADC_InnerRef = 0,
  ADC_ExtRef_2V,
  ADC_ExtRef_1_5V,
  ADC_ExtRef_1V
} ADC_RefSel_e;

typedef enum
{
  ADC_Disable = 0,
  ADC_Enable
} ADC_EN_e;

typedef enum
{
  ADC_IntPerSeq= 0,
  ADC_IntPerOtherSeq
} ADC_IntModSeq_e;

//! \brief   ADC 复位
extern void ADC_reset(ADC_Handle adcHandle);

//! \brief   ADC seq模式选择
extern void ADC_setSeqMode(ADC_Handle adcHandle, ADC_SeqMode_e seqmode);

//! \brief   ADC 运行模式选择
extern void ADC_setRunMode(ADC_Handle adcHandle, ADC_RunMode_e runmode);

//! \brief   ADC 内核时钟分频设置
extern void ADC_setClockPrescale(ADC_Handle adcHandle, ADC_CpsMode_e CpsMode);

//! \brief   ADC 采样窗长度设置
extern void ADC_setAcqWindowSize(ADC_Handle adcHandle, ADC_ACQPS_e ACQPSMode);

//! \brief   ADC 仿真挂起操作
extern void ADC_setSuspendMode(ADC_Handle adcHandle, ADC_SusMode_e SusMode);

//! \brief   ADC ePWM触发AD采样使能//TODO
extern void ADC_setSocMode(ADC_Handle adcHandle, ADC_SocMode_e SOCMode);

//! \brief   ADC 复位排序器
extern void ADC_resetSeq(ADC_Handle adcHandle, ADC_SeqNumber_e SeqNum);

//! \brief   ADC 参考源选择
extern void ADC_setRefSource(ADC_Handle adcHandle, ADC_RefSel_e RefSel);

//! \brief   ADC 中断选择
extern void ADC_setIntMode(ADC_Handle adcHandle, ADC_SeqNumber_e seqmode, ADC_EN_e EnableSeq, ADC_IntModSeq_e IntModSeq);


#endif // end of _ADC_H_ definition


