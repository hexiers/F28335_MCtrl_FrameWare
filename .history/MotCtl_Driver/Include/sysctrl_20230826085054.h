
//! @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_Driver\Include\pll.h
//! @Author: Hex
//! @Date: 2023-08-20 21:25:26
//! @LastEditTime: 2023-08-26 08:27:05
//! @Description: 修改为28335版本

#ifndef _SYSCTRL_H_
#define _SYSCTRL_H_

// **************************************************************************
// the includes

#include "../../MotCtl_Driver/Include/cpu.h"
#include "types.h"

// **************************************************************************
// the defines

// 系统控制基地址
//! \brief Defines the base address of the phase lock loop (PLL) registers
//!
#define SYSCTRL_BASE_ADDR (0x00007011)

//=================   PLL 宏定义 ==========================================
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

//++++++++++++++++++  时钟宏定义 +++++++++++++++++++++++++++++++

//! PCLKCR0
//!
#define PCLKCR0_TBCLKSYNC_BITS (1 << 2)

#define PCLKCR0_ADCENCLK_BITS (1 << 3)

//!
#define PCLKCR0_I2CAENCLK_BITS (1 << 4)

//!
#define PCLKCR0_SCICENCLK_BITS (1 << 5)

//!
#define PCLKCR0_SPIAENCLK_BITS (1 << 8)

//!
#define PCLKCR0_SCIAENCLK_BITS (1 << 10)

#define PCLKCR0_SCIBENCLK_BITS (1 << 11)

#define PCLKCR0_MCBSPAENCLK_BITS (1 << 12)

#define PCLKCR0_MCBSPBENCLK_BITS (1 << 13)

//!
#define PCLKCR0_ECANAENCLK_BITS (1 << 14)

#define PCLKCR0_ECANBENCLK_BITS (1 << 15)

//! PCLKCR1
#define PCLKCR1_EPWM1ENCLK_BITS (1 << 0)

#define PCLKCR1_EPWM2ENCLK_BITS (1 << 1)

#define PCLKCR1_EPWM3ENCLK_BITS (1 << 2)

#define PCLKCR1_EPWM4ENCLK_BITS (1 << 3)

#define PCLKCR1_EPWM5ENCLK_BITS (1 << 4)

#define PCLKCR1_EPWM6ENCLK_BITS (1 << 5)

#define PCLKCR1_ECAP1ENCLK_BITS (1 << 8)

#define PCLKCR1_ECAP2ENCLK_BITS (1 << 9)

#define PCLKCR1_ECAP3ENCLK_BITS (1 << 10)

#define PCLKCR1_ECAP4ENCLK_BITS (1 << 11)

#define PCLKCR1_ECAP5ENCLK_BITS (1 << 12)

#define PCLKCR1_ECAP6ENCLK_BITS (1 << 13)

#define PCLKCR1_EQEP1ENCLK_BITS (1 << 14)

#define PCLKCR1_EQEP2ENCLK_BITS (1 << 15)

// PCLKCR3
#define PCLKCR3_CPUTIMER0ENCLK_BITS (1 << 8)

#define PCLKCR3_CPUTIMER1ENCLK_BITS (1 << 9)

#define PCLKCR3_CPUTIMER2ENCLK_BITS (1 << 10)

#define PCLKCR3_DMAENCLK_BITS (1 << 11)

#define PCLKCR3_XINTFENCLK_BITS (1 << 12)

#define PCLKCR3_GPIOINENCLK_BITS (1 << 13)




//! \briefines the location of the LSPNCLK bits in the LOSPCP register
//!
#define LOSPCP_LSPCLK_BITS (7 << 0)

//! \briefines the location of the XCLKOUTDIV bits in the XCLK register
//!
#define XCLK_XCLKOUTDIV_BITS (3 << 0)

//! \briefines the location of the XCLKINSEL bits in the XCLK register
//!
#define XCLK_XCLKINSEL_BITS (1 << 6)

//! \briefines the location of the OSCCLKSRCSEL bits in the CLKCTL register
//!
#define CLKCTL_OSCCLKSRCSEL_BITS (1 << 0)

//! \briefines the location of the OSCCLKSRC2SEL bits in the CLKCTL register
//!
#define CLKCTL_OSCCLKSRC2SEL_BITS (1 << 1)

//! \briefines the location of the WDCLKSRCSEL bits in the CLKCTL register
//!
#define CLKCTL_WDCLKSRCSEL_BITS (1 << 2)

//! \briefines the location of the TMR2CLKSRCSEL bits in the CLKCTL register
//!
#define CLKCTL_TMR2CLKSRCSEL_BITS (3 << 3)

//! \briefines the location of the TMR2CLKPRESCALE bits in the CLKCTL register
//!
#define CLKCTL_TMR2CLKPRESCALE_BITS (7 << 5)

//! \briefines the location of the INTOSC1OFF bits in the CLKCTL register
//!
#define CLKCTL_INTOSC1OFF_BITS (1 << 8)

//! \briefines the location of the INTOSC1HALTI bits in the CLKCTL register
//!
#define CLKCTL_INTOSC1HALTI_BITS (1 << 9)

//! \briefines the location of the INTOSC2OFF bits in the CLKCTL register
//!
#define CLKCTL_INTOSC2OFF_BITS (1 << 10)

//! \briefines the location of the INTOSC2HALTI bits in the CLKCTL register
//!
#define CLKCTL_INTOSC2HALTI_BITS (1 << 11)

//! \briefines the location of the WDHALTI bits in the CLKCTL register
//!
#define CLKCTL_WDHALTI_BITS (1 << 12)

//! \briefines the location of the XCLKINOFF bits in the CLKCTL register
//!
#define CLKCTL_XCLKINOFF_BITS (1 << 13)

//! \briefines the location of the XTALOSCOFF bits in the CLKCTL register
//!
#define CLKCTL_XTALOSCOFF_BITS (1 << 14)

//! \briefines the location of the NMIRESETSEL bits in the CLKCTL register
//!
#define CLKCTL_NMIRESETSEL_BITS (1 << 15)

// **************************************************************************
// the typedefs

//! \brief Enumeration to define the external clock output frequency
//!
typedef enum
{
    CLK_ClkOutPreScaler_SysClkOut_by_4 = (0 << 0), //!< Denotes XCLKOUT = SYSCLKOUT/4
    CLK_ClkOutPreScaler_SysClkOut_by_2 = (1 << 0), //!< Denotes XCLKOUT = SYSCLKOUT/2
    CLK_ClkOutPreScaler_SysClkOut_by_1 = (2 << 0), //!< Denotes XCLKOUT = SYSCLKOUT/1
    CLK_ClkOutPreScaler_Off                        //!< Denotes XCLKOUT = Off
} CLK_ClkOutPreScaler_e;

//! \brief Enumeration to define the comparator numbers
//!
typedef enum
{
    CLK_CompNumber_1 = (1 << 0), //!< Denotes comparator number 1
    CLK_CompNumber_2 = (1 << 1), //!< Denotes comparator number 2
    CLK_CompNumber_3 = (1 << 2)  //!< Denotes comparator number 3
} CLK_CompNumber_e;

//! \brief Enumeration to define the CPU timer numbers
//!
typedef enum
{
    CLK_CpuTimerNumber_0 = (1 << 8), //!< Denotes CPU timer number 0
    CLK_CpuTimerNumber_1 = (1 << 9), //!< Denotes CPU timer number 1
    CLK_CpuTimerNumber_2 = (1 << 10) //!< Denotes CPU timer number 2
} CLK_CpuTimerNumber_e;

//! \brief Enumeration to define the low speed clock prescaler, which sets the clock frequency
//!
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

//! \brief Enumeration to define the clock in source
//!
typedef enum
{
    CLK_XClkInSrc_Gpio38 = (0 << 6),
    CLK_XClkInSrc_Gpio19 = (1 << 6)
} CLK_XClkInSrc_e;

//! \brief Enumeration to define the clock oscillator source
//!
typedef enum
{
    CLK_OscSrc_Internal = (0 << 0), //!< Denotes an internal oscillator source
    CLK_OscSrc_External = (1 << 0)  //!< Denotes an external oscillator source
} CLK_OscSrc_e;

//! \brief Enumeration to define the clock oscillator 2 source
//!
typedef enum
{
    CLK_Osc2Src_Internal = (1 << 1), //!< Denotes an internal oscillator 2 source
    CLK_Osc2Src_External = (0 << 1)  //!< Denotes an external oscillator 2 source
} CLK_Osc2Src_e;

//! \brief Enumeration to define the timer 2 prescaler, which sets the timer 2 frequency
//!
typedef enum
{
    CLK_Timer2PreScaler_by_1 = (0 << 5), //!< Denotes a CPU timer 2 clock pre-scaler value of divide by 1
    CLK_Timer2PreScaler_by_2 = (1 << 5), //!< Denotes a CPU timer 2 clock pre-scaler value of divide by 2
    CLK_Timer2PreScaler_by_4 = (2 << 5), //!< Denotes a CPU timer 2 clock pre-scaler value of divide by 4
    CLK_Timer2PreScaler_by_8 = (3 << 5), //!< Denotes a CPU timer 2 clock pre-scaler value of divide by 8
    CLK_Timer2PreScaler_by_16 = (4 << 5) //!< Denotes a CPU timer 2 clock pre-scaler value of divide by 16
} CLK_Timer2PreScaler_e;

//! \brief Enumeration to define the timer 2 source
//!
typedef enum
{
    CLK_Timer2Src_SysClk = (0 << 3),  //!< Denotes the CPU timer 2 clock source is SYSCLKOUT
    CLK_Timer2Src_ExtOsc = (1 << 3),  //!< Denotes the CPU timer 2 clock source is external oscillator
    CLK_Timer2Src_IntOsc1 = (2 << 3), //!< Denotes the CPU timer 2 clock source is internal oscillator 1
    CLK_Timer2Src_IntOsc2 = (3 << 3)  //!< Denotes the CPU timer 2 clock source is internal oscillator 2
} CLK_Timer2Src_e;

//! \brief Enumeration to define the watchdog clock source
//!
typedef enum
{
    CLK_WdClkSrc_IntOsc1 = (0 << 2),        //!< Denotes the watchdog clock source is internal oscillator 1
    CLK_WdClkSrc_ExtOscOrIntOsc2 = (1 << 2) //!< Denotes the watchdog clock source is external oscillator or internal oscillator 2
} CLK_WdClkSrc_e;


//  ************************************** PLL 定义  *********************************
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

//! \brief Defines the phase lock loop (PLL) object
//!
typedef struct _SYSCTRL_Obj_
{
    volatile uint16_t PLLSTS;   //!< PLL 状态寄存器
    volatile uint16_t rsvd1[8]; //!< Reserved
    volatile uint16_t HISPCP;
    volatile uint16_t LOSPCP;
    volatile uint16_t PCLKCR0;
    volatile uint16_t PCLKCR1;
    volatile uint16_t LPMCR0;
    volatile uint16_t rsvd2;
    volatile uint16_t PCLKCR3;
    volatile uint16_t PLLCR;
    // 看门狗寄存器
    volatile uint16_t SCSR;
    volatile uint16_t WDCNTR;
    volatile uint16_t rsvd3;
    volatile uint16_t WDKEY;
    volatile uint16_t rsvd4[3];
    volatile uint16_t WDCR;
    volatile uint16_t rsvd5[4];
    volatile uint16_t MAPCNF; // 30: Dual-mapping configuration register
} SYSCTRL_Obj;

//! \brief Defines the phase lock loop (PLL) handle
//!
typedef struct _SYSCTRL_Obj_ *SYSCTRL_Handle;

// **************************************************************************
// the globals




// **************************************************************************
// the function prototypes

//! \brief     Disables the phase lock loop (PLL)
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
extern void PLL_disable(SYSCTRL_Handle sysCtrl_Handle);

//! \brief     Disables the clock detect logic
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
extern void PLL_disableClkDetect(SYSCTRL_Handle sysCtrl_Handle);

//! \brief     Disables the oscillator
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
extern void PLL_disableOsc(SYSCTRL_Handle sysCtrl_Handle);

//! \brief     Enables the phase lock loop (PLL)
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
extern void PLL_enable(SYSCTRL_Handle sysCtrl_Handle);

//! \brief     Enables the clock detect logic
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
extern void PLL_enableClkDetect(SYSCTRL_Handle sysCtrl_Handle);

//! \brief     Enables the NORMRDY signal
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
extern void PLL_enableNormRdy(SYSCTRL_Handle sysCtrl_Handle);

//! \brief     Enables the oscillator
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
extern void PLL_enableOsc(SYSCTRL_Handle sysCtrl_Handle);

//! \brief     Gets the phase lock loop (PLL) clock frequency
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
//! \return    The clock frequency
extern PLL_ClkFreq_e PLL_getClkFreq(SYSCTRL_Handle sysCtrl_Handle);

//! \brief     Gets the phase lock loop (PLL) clock status
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
//! \return    The clock status
extern PLL_ClkStatus_e PLL_getClkStatus(SYSCTRL_Handle sysCtrl_Handle);

//! \brief     Gets the phase lock loop (PLL) divide select value
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
//! \return    The divide select value
extern PLL_DivideSelect_e PLL_getDivideSelect(SYSCTRL_Handle sysCtrl_Handle);

//! \brief     Gets the phase lock loop (PLL) lock status
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
//! \return    The lock status
extern PLL_LockStatus_e PLL_getLockStatus(SYSCTRL_Handle sysCtrl_Handle);

//! \brief     Initializes the phase lock loop (PLL) object handle
//! \param[in] pMemory     A pointer to the base address of the PLL registers
//! \param[in] numBytes    The number of bytes allocated for the PLL object, bytes
//! \return    The phase lock loop (PLL) object handle
extern SYSCTRL_Handle PLL_init(void *pMemory, const size_t numBytes);

//! \brief     Resets the phase lock loop (PLL) clock detect logic
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
extern void PLL_resetClkDetect(SYSCTRL_Handle sysCtrl_Handle);

//! \brief     Sets the phase lock loop (PLL) clock frequency
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
//! \param[in] freq       The clock frequency
extern void PLL_setClkFreq(SYSCTRL_Handle sysCtrl_Handle, const PLL_ClkFreq_e freq);

//! \brief     Sets the phase lock loop (PLL) divide select value
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
//! \param[in] divSelect  The divide select value
extern void PLL_setDivideSelect(SYSCTRL_Handle sysCtrl_Handle, const PLL_DivideSelect_e divSelect);

//! \brief     Sets the phase lock loop (PLL) lock time
//! \param[in] pllHandle  The phase lock loop (PLL) object handle
//! \param[in] lockPeriod The lock period, cycles
extern void PLL_setLockPeriod(SYSCTRL_Handle sysCtrl_Handle, const uint16_t lockPeriod);


//! \brief     Disables the ADC clock
//! \param[in] clkHandle  The clock (CLK) object handle
extern void Sys_disableAdcClock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  Sysisables the CPU timer clock
//! \param[in] clkHandle       The clock (CLK) object handle
//! \param[in] cpuTimerNumber  The CPU timer number
extern void Sys_disableCpuTimerClock(SYSCTRL_Handle sysCtrl_Handle,
                                 const CLK_CpuTimerNumber_e cpuTimerNumber);

//! \brief  SysDisables the crystal oscillator
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_disableCrystalOsc(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysDisables the ECANA clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_disableEcanaClock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysDisables the ECAP1 clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_disableEcap1Clock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysDisables the EQEP1 clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_disableEqep1Clock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysDisables the EQEP2 clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_disableEqep2Clock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysDisables the GPIO input clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_disableGpioInputClock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysDisables the HRPWM clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_disableHrPwmClock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysDisables the I2C clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_disableI2cClock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysDisables the LIN-A clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_disableLinAClock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysDisables the pwm clock
//! \param[in] clkHandle   The clock (CLK) object handle
//! \param[in] pwmNumber   The PWM number
extern void Sys_disablePwmClock(SYSCTRL_Handle sysCtrl_Handle, const PWM_Number_e pwmNumber);

//! \brief  SysDisables the SCI-A clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_disableSciaClock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysDisables the SCI-B clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_disableScibClock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysDisables the SPI-A clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_disableSpiaClock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysDisables the SPI-B clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_disableSpibClock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysDisables the ePWM module time base clock sync signal
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_disableTbClockSync(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysDisables the watchdog halt mode ignore
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_disableWatchDogHaltMode(SYSCTRL_Handle sysCtrl_Handle);



//! \brief  SysEnables the ADC clock
//! \param[in] clkHandle  The clock (CLK) object handle
extern void Sys_enableAdcClock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysEnables the XCLKIN oscillator input
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_enableClkIn(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysEnables the CPU timer clock
//! \param[in] clkHandle       The clock (CLK) object handle
//! \param[in] cpuTimerNumber  The CPU timer number
extern void Sys_enableCpuTimerClock(SYSCTRL_Handle sysCtrl_Handle,
                                const CLK_CpuTimerNumber_e cpuTimerNumber);
                                
//! \brief  SysEnables the crystal oscillator
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_enableCrystalOsc(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysEnables the ECANA clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_enableEcanaClock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysEnables the ECAP1 clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_enableEcap1Clock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysEnables the EQEP1 clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_enableEqep1Clock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysEnables the EQEP2 clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_enableEqep2Clock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysEnables the GPIO input clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_enableGpioInputClock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysEnables the pwm clock
//! \param[in] clkHandle   The clock (CLK) object handle
//! \param[in] pwmNumber   The PWM number
extern void Sys_enablePwmClock(SYSCTRL_Handle sysCtrl_Handle, const PWM_Number_e pwmNumber);

//! \brief  SysEnables the SCI-A clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_enableSciaClock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysEnables the SCI-B clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_enableScibClock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysEnables the SPI-A clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_enableSpiaClock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysEnables the SPI-B clock
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_enableSpibClock(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysEnables the ePWM module time base clock sync signal
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_enableTbClockSync(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysEnables the watchdog halt mode ignore
//! \param[in] clkHandle   The clock (CLK) object handle
extern void Sys_enableWatchDogHaltMode(SYSCTRL_Handle sysCtrl_Handle);

//! \brief  SysSets the external clock out prescaler
//! \param[in] clkHandle  The clock (CLK) object handle
//! \param[in] preScaler  The prescaler value
extern void Sys_setClkOutPreScaler(SYSCTRL_Handle sysCtrl_Handle,
                               const CLK_ClkOutPreScaler_e preScaler);

//! \brief  SysSets the low speed peripheral clock prescaler
//! \param[in] clkHandle  The clock (CLK) object handle
//! \param[in] preScaler  The prescaler value
extern void Sys_setLowSpdPreScaler(SYSCTRL_Handle sysCtrl_Handle,
                                const CLK_LowSpdPreScaler_e preScaler);

//! \brief  SysSets the oscillator clock source
//! \param[in] clkHandle  The clock (CLK) object handle
//! \param[in] src        The oscillator clock source
extern void Sys_setOscSrc(SYSCTRL_Handle sysCtrl_Handle, const CLK_OscSrc_e src);

//! \brief  SysSets the oscillator 2 clock source
//! \param[in] clkHandle  The clock (CLK) object handle
//! \param[in] src        The oscillator 2 clock source
extern void Sys_setOsc2Src(SYSCTRL_Handle sysCtrl_Handle, const CLK_Osc2Src_e src);

//! \brief SSys the XCLKIN Clock Source
//! \param[in] clkHandle  The clock (CLK) object handle
//! \paran[in] src        The XCLKIN clock source
extern void Sys_setXClkInSrc(SYSCTRL_Handle sysCtrl_Handle, const CLK_XClkInSrc_e src);

//! \brief  SysSets the timer 2 clock prescaler
//! \param[in] clkHandle  The clock (CLK) object handle
//! \param[in] preScaler  The prescaler value
extern void Sys_setTimer2PreScaler(SYSCTRL_Handle sysCtrl_Handle,
                               const CLK_Timer2PreScaler_e preScaler);

//! \brief  SysSets the timer 2 clock source
//! \param[in] clkHandle  The clock (CLK) object handle
//! \param[in] src        The timer 2 clock source
extern void Sys_setTimer2Src(SYSCTRL_Handle sysCtrl_Handle, const CLK_Timer2Src_e src);

//! \brief  SysSets the watchdog clock source
//! \param[in] clkHandle  The clock (CLK) object handle
//! \param[in] src        The watchdog clock source
extern void Sys_setWatchDogSrc(SYSCTRL_Handle sysCtrl_Handle, const CLK_WdClkSrc_e src);





#ifdef __cplusplus
}
#endif // extern "C"

//@} // ingroup
#endif // end of _sysCtrl_H_ definition
