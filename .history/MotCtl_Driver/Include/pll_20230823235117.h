
//! @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_Driver\Include\pll.h
//! @Author: Hex
//! @Date: 2023-08-20 21:25:26
//! @LastEditTime: 2023-08-23 21:42:04
//! @Description: 修改为28335版本

#ifndef _PLL_H_
#define _PLL_H_

// **************************************************************************
// the includes

#include "../../MotCtl_Driver/Include/cpu.h"
#include "types.h"

// **************************************************************************
// the defines

//=================   PLL 宏定义 ==========================================
//! \brief Defines the base address of the phase lock loop (PLL) registers
//!
#define PLL_BASE_ADDR (0x00007011)

//! \brief Defines the location of the DIV bits in the PLLCR register
//!
#define PLL_PLLCR_DIV_BITS (15 << 0)

//! \brief Defines the location of the PLLLOCKS bits in the PLLSTS register
//!
#define PLL_PLLSTS_PLLLOCKS_BITS (1 << 0)

//! \brief Defines the location of the PLLOFF bits in the PLLSTS register
//!
#define PLL_PLLSTS_PLLOFF_BITS (1 << 2)

//! \brief Defines the location of the MCLKSTS bits in the PLLSTS register
//!
#define PLL_PLLSTS_MCLKSTS_BITS (1 << 3)

//! \brief Defines the location of the MCLKCLR bits in the PLLSTS register
//!
#define PLL_PLLSTS_MCLKCLR_BITS (1 << 4)

//! \brief Defines the location of the OSCOFF bits in the PLLSTS register
//!
#define PLL_PLLSTS_OSCOFF_BITS (1 << 5)

//! \brief Defines the location of the MCLKOFF bits in the PLLSTS register
//!
#define PLL_PLLSTS_MCLKOFF_BITS (1 << 6)

//! \brief Defines the location of the DIVSEL bits in the PLLSTS register
//!
#define PLL_PLLSTS_DIVSEL_BITS (3 << 7)


// **************************************************************************
// the typedefs
// 外设时钟管理寄存器
struct PCLKCR0_BITS  {   // bits  description
   uint16_t  rsvd1:2;       // 1:0   reserved
   uint16_t TBCLKSYNC:1;   // 2     EWPM Module TBCLK enable/sync
   uint16_t ADCENCLK:1;    // 3     Enable high speed clk to ADC
   uint16_t I2CAENCLK:1;   // 4     Enable SYSCLKOUT to I2C-A
   uint16_t SCICENCLK:1;   // 5     Enalbe low speed clk to SCI-C
   uint16_t rsvd2:2;       // 7:6   reserved
   uint16_t SPIAENCLK:1;   // 8     Enable low speed clk to SPI-A
   uint16_t rsvd3:1;       // 9     reserved
   uint16_t SCIAENCLK:1;   // 10    Enable low speed clk to SCI-A
   uint16_t SCIBENCLK:1;   // 11    Enable low speed clk to SCI-B
   uint16_t MCBSPAENCLK:1; // 12    Enable low speed clk to McBSP-A
   uint16_t MCBSPBENCLK:1; // 13    Enable low speed clk to McBSP-B
   uint16_t ECANAENCLK:1;  // 14    Enable system clk to eCAN-A
   uint16_t ECANBENCLK:1;  // 15    Enable system clk to eCAN-B
};
union PCLKCR0_REG {
   uint16_t   all;
   struct PCLKCR0_BITS bit;
};

// 外设时钟管理寄存器
struct PCLKCR1_BITS  {    // bits  description
   uint16_t EPWM1ENCLK:1;   // 0     Enable SYSCLKOUT to EPWM1
   uint16_t EPWM2ENCLK:1;   // 1     Enable SYSCLKOUT to EPWM2
   uint16_t EPWM3ENCLK:1;   // 2     Enable SYSCLKOUT to EPWM3
   uint16_t EPWM4ENCLK:1;   // 3     Enable SYSCLKOUT to EPWM4
   uint16_t EPWM5ENCLK:1;   // 4     Enable SYSCLKOUT to EPWM5
   uint16_t EPWM6ENCLK:1;   // 5     Enable SYSCLKOUT to EPWM6
   uint16_t rsvd1:2;        // 7:6   reserved
   uint16_t ECAP1ENCLK:1;   // 8     Enable SYSCLKOUT to ECAP1
   uint16_t ECAP2ENCLK:1;   // 9     Enable SYSCLKOUT to ECAP2
   uint16_t ECAP3ENCLK:1;   // 10    Enable SYSCLKOUT to ECAP3
   uint16_t ECAP4ENCLK:1;   // 11    Enable SYSCLKOUT to ECAP4
   uint16_t ECAP5ENCLK:1;   // 12    Enable SYSCLKOUT to ECAP5
   uint16_t ECAP6ENCLK:1;   // 13    Enable SYSCLKOUT to ECAP6
   uint16_t EQEP1ENCLK:1;   // 14    Enable SYSCLKOUT to EQEP1
   uint16_t EQEP2ENCLK:1;   // 15    Enable SYSCLKOUT to EQEP2
};
union PCLKCR1_REG {
   uint16_t              all;
   struct PCLKCR1_BITS bit;
};


// 外设时钟管理寄存器
struct PCLKCR3_BITS  {        // bits  description
   uint16_t rsvd1:8;            // 7:0   reserved
   uint16_t CPUTIMER0ENCLK:1;   // 8     Enable SYSCLKOUT to CPU-Timer 0
   uint16_t CPUTIMER1ENCLK:1;   // 9     Enable SYSCLKOUT to CPU-Timer 1
   uint16_t CPUTIMER2ENCLK:1;   // 10    Enable SYSCLKOUT to CPU-Timer 2
   uint16_t DMAENCLK:1;         // 11    Enable the DMA clock
   uint16_t XINTFENCLK:1;       // 12    Enable SYSCLKOUT to XINTF
   uint16_t GPIOINENCLK:1;      //     Enable GPIO input clock
   uint16_t rsvd2:2;            // 15:14 reserved
};
union PCLKCR3_REG {
   uint16_t             all;
   struct PCLKCR3_BITS bit;
};

// Dual-mapping configuration register bit definitions:
struct MAPCNF_BITS {     // bits  description
    uint16_t MAPEPWM:1;    // 0     EPWM dual-map enable
    uint16_t rsvd1:15;     // 15:1  reserved
};

union MAPCNF_REG {
	uint16_t           all;
	struct MAPCNF_BITS bit;
};


//! \brief 定义在外部输入30MHz情况下的分频数
//!
typedef enum
{
    PLL_ClkFreq_15_MHz = (1 << 0),   //!< Denotes a clock frequency of 5 MHz
    PLL_ClkFreq_30_MHz = (2 << 0),   //!< Denotes a clock frequency of 10 MHz
    PLL_ClkFreq_45_MHz = (3 << 0),   //!< Denotes a clock frequency of 15 MHz
    PLL_ClkFreq_60_MHz = (4 << 0),   //!< Denotes a clock frequency of 20 MHz
    PLL_ClkFreq_75_MHz = (5 << 0),   //!< Denotes a clock frequency of 25 MHz
    PLL_ClkFreq_90_MHz = (6 << 0),   //!< Denotes a clock frequency of 30 MHz
    PLL_ClkFreq_105_MHz = (7 << 0),  //!< Denotes a clock frequency of 35 MHz
    PLL_ClkFreq_120_MHz = (8 << 0),  //!< Denotes a clock frequency of 40 MHz
    PLL_ClkFreq_135_MHz = (9 << 0),  //!< Denotes a clock frequency of 45 MHz
    PLL_ClkFreq_150_MHz = (10 << 0), //!< Denotes a clock frequency of 50 MHz
} PLL_ClkFreq_e;

//! \brief Enumeration to define the phase lock loop (PLL) divide select
//!
typedef enum
{
    PLL_DivideSelect_ClkIn_by_4 = (0 << 7), //!< Denotes a divide select of CLKIN/4
    PLL_DivideSelect_ClkIn_by_2 = (2 << 7), //!< Denotes a divide select of CLKIN/2
    PLL_DivideSelect_ClkIn_by_1 = (3 << 7)  //!< Denotes a divide select of CLKIN/1
} PLL_DivideSelect_e;

//! \brief Enumeration to define the phase lock loop (PLL) clock status
//!
typedef enum
{
    PLL_ClkStatus_Normal = (0 << 3), //!< Denotes a normal clock
    PLL_ClkStatus_Missing = (1 << 3) //!< Denotes a missing clock
} PLL_ClkStatus_e;

//! \brief Enumeration to define the phase lock loop (PLL) clock lock status
//!
typedef enum
{
    PLL_LockStatus_Locking = (0 << 0), //!< Denotes that the system is locking to the clock
    PLL_LockStatus_Done = (1 << 0)     //!< Denotes that the system is locked to the clock
} PLL_LockStatus_e;

typedef enum
{
    CLK_LowSpdPreScaler_SysClkOut_by_1 = (0 << 0),  //!< Denotes Low Speed Clock = SYSCLKOUT/1
    CLK_LowSpdPreScaler_SysClkOut_by_2 = (1 << 0),  //!< Denotes Low Speed Clock = SYSCLKOUT/2
    CLK_LowSpdPreScaler_SysClkOut_by_4 = (2 << 0),  //!< Denotes Low Speed Clock = SYSCLKOUT/4
    CLK_LowSpdPreScaler_SysClkOut_by_6 = (3 << 0),  //!< Denotes Low Speed Clock = SYSCLKOUT/6
    CLK_LowSpdPreScaler_SysClkOut_by_8 = (4 << 0),  //!< Denotes Low Speed Clock = SYSCLKOUT/8
    CLK_LowSpdPreScaler_SysClkOut_by_10 = (5 << 0), //!< Denotes Low Speed Clock = SYSCLKOUT/10
    CLK_LowSpdPreScaler_SysClkOut_by_12 = (6 << 0), //!< Denotes Low Speed Clock = SYSCLKOUT/12
    CLK_LowSpdPreScaler_SysClkOut_by_14 = (7 << 0)  //!< Denotes Low Speed Clock = SYSCLKOUT/14
} CLK_LowSpdPreScaler_e;

//! \brief Defines the phase lock loop (PLL) object
//!
typedef struct _PLL_Obj_
{
    volatile uint16_t PLLSTS;  //!< PLL 状态寄存器
    volatile uint16_t rsvd1[8]; //!< Reserved
    volatile uint16_t HISPCP;
    volatile uint16_t LOSPCP;
    union PCLKCR0_REG PCLKCR0;
    union PCLKCR1_REG PCLKCR1;
    volatile uint16_t LPMCR0;
    volatile uint16_t rsvd2;
    union PCLKCR3_REG PCLKCR3;
    volatile uint16_t PLLCR;
    // 看门狗寄存器
    volatile uint16_t SCSR;
    volatile uint16_t WDCNTR;
    volatile uint16_t rsvd3;
    volatile uint16_t WDKEY;
    volatile uint16_t rsvd4[3];
    volatile uint16_t WDCR;
    volatile uint16_t rsvd5[4];
    union   MAPCNF_REG  MAPCNF;    // 30: Dual-mapping configuration register
} PLL_Obj;

//! \brief Defines the phase lock loop (PLL) handle
//!
typedef struct _PLL_Obj_ *PLL_Handle;

// **************************************************************************
// the globals

// **************************************************************************
// the function prototypes

//! \brief     Disables the phase lock loop (PLL)
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
extern void PLL_disable(PLL_Handle pllHandle);

//! \brief     Disables the clock detect logic
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
extern void PLL_disableClkDetect(PLL_Handle pllHandle);

//! \brief     Disables the oscillator
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
extern void PLL_disableOsc(PLL_Handle pllHandle);

//! \brief     Enables the phase lock loop (PLL)
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
extern void PLL_enable(PLL_Handle pllHandle);

//! \brief     Enables the clock detect logic
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
extern void PLL_enableClkDetect(PLL_Handle pllHandle);

//! \brief     Enables the NORMRDY signal
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
extern void PLL_enableNormRdy(PLL_Handle pllHandle);

//! \brief     Enables the oscillator
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
extern void PLL_enableOsc(PLL_Handle pllHandle);

//! \brief     Gets the phase lock loop (PLL) clock frequency
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
//! \return    The clock frequency
extern PLL_ClkFreq_e PLL_getClkFreq(PLL_Handle pllHandle);

//! \brief     Gets the phase lock loop (PLL) clock status
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
//! \return    The clock status
extern PLL_ClkStatus_e PLL_getClkStatus(PLL_Handle pllHandle);

//! \brief     Gets the phase lock loop (PLL) divide select value
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
//! \return    The divide select value
extern PLL_DivideSelect_e PLL_getDivideSelect(PLL_Handle pllHandle);

//! \brief     Gets the phase lock loop (PLL) lock status
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
//! \return    The lock status
extern PLL_LockStatus_e PLL_getLockStatus(PLL_Handle pllHandle);

//! \brief     Initializes the phase lock loop (PLL) object handle
//! \param[in] pMemory     A pointer to the base address of the PLL registers
//! \param[in] numBytes    The number of bytes allocated for the PLL object, bytes
//! \return    The phase lock loop (PLL) object handle
extern PLL_Handle PLL_init(void *pMemory, const size_t numBytes);

//! \brief     Resets the phase lock loop (PLL) clock detect logic
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
extern void PLL_resetClkDetect(PLL_Handle pllHandle);

//! \brief     Sets the phase lock loop (PLL) clock frequency
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
//! \param[in] freq       The clock frequency
extern void PLL_setClkFreq(PLL_Handle pllHandle, const PLL_ClkFreq_e freq);

//! \brief     Sets the phase lock loop (PLL) divide select value
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
//! \param[in] divSelect  The divide select value
extern void PLL_setDivideSelect(PLL_Handle pllHandle, const PLL_DivideSelect_e divSelect);

//! \brief     Sets the phase lock loop (PLL) lock time
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
//! \param[in] lockPeriod The lock period, cycles
extern void PLL_setLockPeriod(PLL_Handle pllHandle, const uint16_t lockPeriod);

#ifdef __cplusplus
}
#endif // extern "C"

//@} // ingroup
#endif // end of _PLL_H_ definition
