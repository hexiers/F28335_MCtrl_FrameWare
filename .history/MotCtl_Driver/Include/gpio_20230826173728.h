
//! @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_Driver\Include\gpio.h
//! @Author: Hex
//! @Date: 2023-08-20 21:25:26
//! @LastEditTime: 2023-08-26 17:25:18
//! @Description: api函数已做修改


#ifndef _GPIO_H_
#define _GPIO_H_

//! \file   drivers/gpio/src/32b/f28x/f2806x/gpio.h
//! \brief  Contains public interface to general purpose I/O (GPIO) methods
//!
//! (C) Copyright 2015, Texas Instruments, Inc.

// **************************************************************************
// the includes

#include "../../MotCtl_Driver/Include/cpu.h"
#include "types.h"

//!
//!
//! \defgroup GPIO GPIO
//!
//@{

#ifdef __cplusplus
extern "C"
{
#endif

// **************************************************************************
// the defines

//! \brief Defines the base address of the general purpose I/O (GPIO) registers
//!
#define GPIO_BASE_ADDR (0x00006F80)

//! \brief Defines the location of the CONFIG bits in the GPMUX register
//!
#define GPIO_GPMUX_CONFIG_BITS (3 << 0)
//! \brief Defines number of GPIOs covered by each GPxMUX register
//!
#define GPIO_GPMUX_NUMGPIOS_PER_REG 16

//! \brief Defines the location of the GPIOx bits in the GPxQSELy register
//!
#define GPIO_GPxQSELy_GPIOx_BITS 3

//! \brief Defines number of GPIOs covered by each GPxQSELy register
//!
#define GPIO_GPxQSELx_NUMGPIOS_PER_REG 16

//! \brief Defines the location of the GPIOx bits in the GPxQSELy register
//!
#define GPIO_GPxCTRL_QUALPRDx_BITS 0xFF

//! \brief Defines number of bits per QUALPRDx field per GPxCTRL register
//!
#define GPIO_GPxCTRL_QUALPRDx_NUMBITS_PER_REG 8

  // **************************************************************************
  // the typedefs

  //! \brief Enumeration to define the general purpose I/O (GPIO) modes for each pin
  //!
  typedef enum
  {
    GPIO_Mode_GeneralPurpose = 0, //!< Denotes a general purpose function
    GPIO_Mode_Prep_Func1 = 1,     //!< GPIO第1项功能
    GPIO_Mode_Prep_Func2 = 2,     //!< GPIO第2项功能
    GPIO_Mode_Prep_Func3 = 3      //!< GPIO第3项功能
  } GPIO_Mode_e;

  //! \brief Enumeration to define the general purpose I/O (GPIO) directions
  //!
  typedef enum
  {
    GPIO_Direction_Input = 0, //!< Denotes an input direction
    GPIO_Direction_Output     //!< Denotes an output direction
  } GPIO_Direction_e;

  //! \brief Enumeration to define the general purpose I/O (GPIO) pullups
  //!
  typedef enum
  {
    GPIO_Pullup_Enable = 0, //!< Denotes a pullup enabled
    GPIO_Pullup_Disable     //!< Denotes a pullup disabled
  } GPIO_Pullup_e;

  //! \brief Enumeration to define the general purpose I/O (GPIO) qualification
  //!
  typedef enum
  {
    GPIO_Qual_Sync = 0, //!< Denotes input will be synchronized to SYSCLK
    GPIO_Qual_Sample_3, //!< Denotes input is qualified with 3 samples
    GPIO_Qual_Sample_6, //!< Denotes input is qualified with 6 samples
    GPIO_Qual_ASync     //!< Denotes input is asynchronous
  } GPIO_Qual_e;

  //! \brief Enumeration to define the general purpose I/O (GPIO) ports
  //!
  typedef enum
  {
    GPIO_Port_A = 0, //!< GPIO Port A
    GPIO_Port_B      //!< GPIO Port B
  } GPIO_Port_e;

  //! \brief Enumeration to define the general purpose I/O (GPIO) numbers
  //!
  typedef enum
  {
    GPIO_Number_0 = 0,   //!< Denotes GPIO number 0
    GPIO_Number_1,       //!< Denotes GPIO number 1
    GPIO_Number_2,       //!< Denotes GPIO number 2
    GPIO_Number_3,       //!< Denotes GPIO number 3
    GPIO_Number_4,       //!< Denotes GPIO number 4
    GPIO_Number_5,       //!< Denotes GPIO number 5
    GPIO_Number_6,       //!< Denotes GPIO number 6
    GPIO_Number_7,       //!< Denotes GPIO number 7
    GPIO_Number_8,       //!< Denotes GPIO number 8
    GPIO_Number_9,       //!< Denotes GPIO number 9
    GPIO_Number_10,      //!< Denotes GPIO number 10
    GPIO_Number_11,      //!< Denotes GPIO number 11
    GPIO_Number_12,      //!< Denotes GPIO number 12
    GPIO_Number_13,      //!< Denotes GPIO number 13
    GPIO_Number_14,      //!< Denotes GPIO number 14
    GPIO_Number_15,      //!< Denotes GPIO number 15
    GPIO_Number_16,      //!< Denotes GPIO number 16
    GPIO_Number_17,      //!< Denotes GPIO number 17
    GPIO_Number_18,      //!< Denotes GPIO number 18
    GPIO_Number_19,      //!< Denotes GPIO number 19
    GPIO_Number_20,      //!< Denotes GPIO number 20
    GPIO_Number_21,      //!< Denotes GPIO number 21
    GPIO_Number_22,      //!< Denotes GPIO number 22
    GPIO_Number_23,      //!< Denotes GPIO number 23
    GPIO_Number_24,      //!< Denotes GPIO number 24
    GPIO_Number_25,      //!< Denotes GPIO number 25
    GPIO_Number_26,      //!< Denotes GPIO number 26
    GPIO_Number_27,      //!< Denotes GPIO number 27
    GPIO_Number_28,      //!< Denotes GPIO number 28
    GPIO_Number_29,      //!< Denotes GPIO number 29
    GPIO_Number_30,      //!< Denotes GPIO number 30
    GPIO_Number_31,      //!< Denotes GPIO number 31
    GPIO_Number_32,      //!< Denotes GPIO number 32
    GPIO_Number_33,      //!< Denotes GPIO number 33
    GPIO_Number_34,      //!< Denotes GPIO number 34
    GPIO_Number_35,      //!< Denotes GPIO number 35
    GPIO_Number_36,      //!< Denotes GPIO number 36
    GPIO_Number_37,      //!< Denotes GPIO number 37
    GPIO_Number_38,      //!< Denotes GPIO number 38
    GPIO_Number_39,      //!< Denotes GPIO number 39
    GPIO_Number_40,      //!< Denotes GPIO number 40
    GPIO_Number_41,      //!< Denotes GPIO number 41
    GPIO_Number_42,      //!< Denotes GPIO number 42
    GPIO_Number_43,      //!< Denotes GPIO number 43
    GPIO_Number_44,      //!< Denotes GPIO number 44
    GPIO_Number_50 = 50, //!< Denotes GPIO number 50
    GPIO_Number_51,      //!< Denotes GPIO number 51
    GPIO_Number_52,      //!< Denotes GPIO number 52
    GPIO_Number_53,      //!< Denotes GPIO number 53
    GPIO_Number_54,      //!< Denotes GPIO number 54
    GPIO_Number_55,      //!< Denotes GPIO number 55
    GPIO_Number_56,      //!< Denotes GPIO number 56
    GPIO_Number_57,      //!< Denotes GPIO number 57
    GPIO_Number_58,      //!< Denotes GPIO number 58
    GPIO_Number_59,      //!< Denotes GPIO number 59
    GPIO_Number_60,      //!< Denotes GPIO number 60
    GPIO_Number_61,      //!< Denotes GPIO number 61
    GPIO_Number_62,      //!< Denotes GPIO number 62
    GPIO_Number_63,      //!< Denotes GPIO number 63
    GPIO_Number_64,      //!< Denotes GPIO number 64
    GPIO_Number_65,      //!< Denotes GPIO number 65
    GPIO_Number_66,      //!< Denotes GPIO number 66
    GPIO_Number_67,      //!< Denotes GPIO number 67
    GPIO_Number_68,      //!< Denotes GPIO number 68
    GPIO_Number_69,      //!< Denotes GPIO number 69
    GPIO_Number_70,      //!< Denotes GPIO number 70
    GPIO_Number_71,      //!< Denotes GPIO number 71
    GPIO_Number_72,      //!< Denotes GPIO number 72
    GPIO_Number_73,      //!< Denotes GPIO number 73
    GPIO_Number_74,      //!< Denotes GPIO number 74
    GPIO_Number_75,      //!< Denotes GPIO number 75
    GPIO_Number_76,      //!< Denotes GPIO number 76
    GPIO_Number_77,      //!< Denotes GPIO number 77
    GPIO_Number_78,      //!< Denotes GPIO number 78
    GPIO_Number_79,      //!< Denotes GPIO number 79
    GPIO_Number_80,      //!< Denotes GPIO number 80
    GPIO_Number_81,      //!< Denotes GPIO number 81
    GPIO_Number_82,      //!< Denotes GPIO number 82
    GPIO_Number_83,      //!< Denotes GPIO number 83
    GPIO_Number_84,      //!< Denotes GPIO number 84
    GPIO_Number_85,      //!< Denotes GPIO number 85
    GPIO_Number_86,      //!< Denotes GPIO number 86
    GPIO_Number_87,      //!< Denotes GPIO number 87
    GPIO_numGpios
  } GPIO_Number_e;

  //! \brief Defines the General Purpose I/O (GPIO) object
  //!
  typedef struct _GPIO_Obj_
  {
    // OX006F80
    volatile uint32_t GPACTRL;   //!< GPIO A Control Register
    volatile uint32_t GPAQSEL1;  //!< GPIO A Qualifier Select 1 Register
    volatile uint32_t GPAQSEL2;  //!< GPIO A Qualifier Select 2 Register
    volatile uint32_t GPAMUX1;   //!< GPIO A MUX 1 Register
    volatile uint32_t GPAMUX2;   //!< GPIO A MUX 2 Register
    volatile uint32_t GPADIR;    //!< GPIO A Direction Register
    volatile uint32_t GPAPUD;    //!< GPIO A Pull Up Disable Register
    volatile uint16_t rsvd_1[2]; //!< Reserved
    // OX006F90
    volatile uint32_t GPBCTRL;   //!< GPIO B Control Register
    volatile uint32_t GPBQSEL1;  //!< GPIO B Qualifier Select 1 Register
    volatile uint32_t GPBQSEL2;  //!< GPIO B Qualifier Select 2 Register
    volatile uint32_t GPBMUX1;   //!< GPIO B MUX 1 Register
    volatile uint32_t GPBMUX2;   //!< GPIO B MUX 2 Register
    volatile uint32_t GPBDIR;    //!< GPIO B Direction Register
    volatile uint32_t GPBPUD;    //!< GPIO B Pull Up Disable Register
    volatile uint16_t rsvd_2[8]; //!< Reserved
    // OX006FA6
    volatile uint32_t GPCMUX1;    //!< GPIO C MUX 1 Register
    volatile uint32_t GPCMUX2;    //!< GPIO C MUX 2 Register
    volatile uint32_t GPCDIR;     //!< GPIO C Direction Register
    volatile uint32_t GPCPUD;     //!< GPIO C Pull Up Disable Register 0x6FAC
    volatile uint16_t rsvd_3[18]; //!< Reserved
    // OX006FC0
    volatile uint32_t GPADAT;    //!< GPIO A Data Register
    volatile uint32_t GPASET;    //!< GPIO A Set Register
    volatile uint32_t GPACLEAR;  //!< GPIO A Clear Register
    volatile uint32_t GPATOGGLE; //!< GPIO A Toggle Register
    volatile uint32_t GPBDAT;    //!< GPIO B Data Register
    volatile uint32_t GPBSET;    //!< GPIO B Set Register
    volatile uint32_t GPBCLEAR;  //!< GPIO B Clear Register
    volatile uint32_t GPBTOGGLE; //!< GPIO B Toggle Register
    volatile uint32_t GPCDAT;    //!< GPIO c Data Register
    volatile uint32_t GPCSET;    //!< GPIO c Set Register
    volatile uint32_t GPCCLEAR;  //!< GPIO c Clear Register
    volatile uint32_t GPCTOGGLE; //!< GPIO c Toggle Register
    volatile uint16_t rsvd_4[8]; //!< Reserved

    volatile uint16_t GPIOXINTnSEL[8]; //!< XINT1-8 Source Select Registers
    volatile uint16_t GPIOLPMSEL;      //!

  } GPIO_Obj;

  //! \brief Defines the general purpose I/O (GPIO) handle
  //!
  typedef struct _GPIO_Obj_ *GPIO_Handle;

  // **************************************************************************
  // the globals

  // **************************************************************************
  // the function prototypes

  //! \brief     Returns the data value present on a pin (either input or output)
  //! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
  //! \param[in] gpioNumber  The GPIO number
  //! \return    The boolean state of a pin (high/low)
  extern bool GPIO_getData(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber);

  //! \brief     Returns the data value present on a GPIO port
  //! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
  //! \param[in] gpioPort  The GPIO port
  //! \return    The data values for the specified port
  extern uint32_t GPIO_getPortData(GPIO_Handle gpioHandle, const GPIO_Port_e gpioPort);

  //! \brief     Initializes the general purpose I/O (GPIO) object handle
  //! \param[in] pMemory     A pointer to the base address of the GPIO registers
  //! \param[in] numBytes    The number of bytes allocated for the GPIO object, bytes
  //! \return    The general purpose I/O (GPIO) object handle
  extern GPIO_Handle GPIO_init(void *pMemory, const size_t numBytes);

  //! \brief     Sets the general purpose I/O (GPIO) signal direction
  //! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
  //! \param[in] gpioNumber  The GPIO number
  //! \param[in] direction   The signal direction
  extern void GPIO_setDirection(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const GPIO_Direction_e direction);

  //! \brief     Sets the general purpose I/O (GPIO) pullup disable
  //! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
  //! \param[in] gpioNumber  The GPIO number
  //! \param[in] pullup   The pullup enable or disable signal
  extern void GPIO_setPullup(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const GPIO_Pullup_e pullup);

  //! \brief     Sets the general purpose I/O (GPIO) external interrupt number
  //! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
  //! \param[in] gpioNumber  The GPIO number
  //! \param[in] intNumber   The interrupt number
  extern void GPIO_setExtInt(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const CPU_ExtIntNumber_e intNumber);

  //! \brief     Sets the specified general purpose I/O (GPIO) signal low
  //! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
  //! \param[in] gpioNumber  The GPIO number
  extern void GPIO_setLow(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber);

  //! \brief     Sets the mode for the specified general purpose I/O (GPIO) signal
  //! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
  //! \param[in] gpioNumber  The GPIO number
  //! \param[in] mode        The mode
  extern void GPIO_setMode(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const GPIO_Mode_e mode);

  //! \brief     Reads the specified general purpose I/O (GPIO)
  //! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
  //! \param[in] gpioNumber  The GPIO number
  //! \return    The general purpose I/O (GPIO) state, HIGH or LOW
  extern bool GPIO_read(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber);

  //! \brief     Sets the specified general purpose I/O (GPIO) signal high
  //! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
  //! \param[in] gpioNumber  The GPIO number
  extern void GPIO_setHigh(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber);

  //! \brief     Sets data output on a given GPIO port
  //! \param[in] gpioHandle   The general purpose I/O (GPIO) object handle
  //! \param[in] gpioPort     The GPIO number
  //! \param[in] data         The data to write to the port
  extern void GPIO_setPortData(GPIO_Handle gpioHandle, const GPIO_Port_e gpioPort, const uint32_t data);

  //! \brief     Sets the qualification for the specified general purpose I/O (GPIO)
  //! \param[in] gpioHandle    The general purpose I/O (GPIO) object handle
  //! \param[in] gpioNumber    The GPIO number
  //! \param[in] qualification The desired input qualification
  extern void GPIO_setQualification(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const GPIO_Qual_e qualification);

  //! \brief     Sets the qualification period for the specified general purpose I/O block (8 I/O's per block)
  //! \param[in] gpioHandle   The general purpose I/O (GPIO) object handle
  //! \param[in] gpioNumber   The GPIO number
  //! \param[in] period       The desired input qualification period
  extern void GPIO_setQualificationPeriod(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber, const uint_least8_t period);

  //! \brief     Toggles the specified general purpose I/O (GPIO) signal
  //! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
  //! \param[in] gpioNumber  The GPIO number
  extern void GPIO_toggle(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber);

  //! \brief     Selects a gpio pin to wake up device from STANDBY and HALT LPM
  //! \param[in] gpioHandle  The general purpose I/O (GPIO) object handle
  //! \param[in] gpioNumber  The GPIO number
  extern void GPIO_lpmSelect(GPIO_Handle gpioHandle, const GPIO_Number_e gpioNumber);

#ifdef __cplusplus
}
#endif // extern "C"

//@} // ingroup
#endif // end of _GPIO_H_ definition
