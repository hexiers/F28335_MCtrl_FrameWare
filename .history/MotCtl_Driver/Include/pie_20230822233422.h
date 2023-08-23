
//! @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_Driver\Include\pie.h
//! @Author: Hex
//! @Date: 2023-08-20 21:25:26
//! @LastEditTime: 2023-08-22 23:20:07
//! @Description: 原库28069中断向量和28335有冲突，做修改

#ifndef _PIE_H_
#define _PIE_H_

//! \file   drivers/pie/src/32b/f28x/f2806x/pie.h
//!
//! \brief  Contains public interface to various functions related
//!         to the peripheral interrupt expansion (PIE) object
//!
//! (C) Copyright 2015, Texas Instruments, Inc.

// **************************************************************************
// the includes

#include "../../MotCtl_Driver/Include/adc.h"
#include "../../MotCtl_Driver/Include/pwm.h"
#include "types.h"

//!
//!
//! \defgroup PIE PIE
//!
//@{

#ifdef __cplusplus
extern "C"
{
#endif

// **************************************************************************
// the defines

//! \brief Defines the base address of the peripheral interrupt expansion (PIE) registers
//!
#define PIE_BASE_ADDR (0x00000CE0)

//! \brief Defines the location of the INT1 bits in the DBGIER register
//!
#define PIE_DBGIER_INT1_BITS (1 << 0)

//! \brief Defines the location of the INT2 bits in the DBGIER register
//!
#define PIE_DBGIER_INT2_BITS (1 << 1)

//! \brief Defines the location of the INT3 bits in the DBGIER register
//!
#define PIE_DBGIER_INT3_BITS (1 << 2)

//! \brief Defines the location of the INT4 bits in the DBGIER register
//!
#define PIE_DBGIER_INT4_BITS (1 << 3)

//! \brief Defines the location of the INT5 bits in the DBGIER register
//!
#define PIE_DBGIER_INT5_BITS (1 << 4)

//! \brief Defines the location of the INT6 bits in the DBGIER register
//!
#define PIE_DBGIER_INT6_BITS (1 << 5)

//! \brief Defines the location of the INT7 bits in the DBGIER register
//!
#define PIE_DBGIER_INT7_BITS (1 << 6)

//! \brief Defines the location of the INT8 bits in the DBGIER register
//!
#define PIE_DBGIER_INT8_BITS (1 << 7)

//! \brief Defines the location of the INT9 bits in the DBGIER register
//!
#define PIE_DBGIER_INT9_BITS (1 << 8)

//! \brief Defines the location of the INT10 bits in the DBGIER register
//!
#define PIE_DBGIER_INT10_BITS (1 << 9)

//! \brief Defines the location of the INT11 bits in the DBGIER register
//!
#define PIE_DBGIER_INT11_BITS (1 << 10)

//! \brief Defines the location of the INT12 bits in the DBGIER register
//!
#define PIE_DBGIER_INT12_BITS (1 << 11)

//! \brief Defines the location of the INT13 bits in the DBGIER register
//!
#define PIE_DBGIER_INT13_BITS (1 << 12)

//! \brief Defines the location of the INT14 bits in the DBGIER register
//!
#define PIE_DBGIER_INT14_BITS (1 << 13)

//! \brief Defines the location of the DLOGINT bits in the DBGIER register
//!
#define PIE_DBGIER_DLOGINT_BITS (1 << 14)

//! \brief Defines the location of the RTOSINT bits in the DBGIER register
//!
#define PIE_DBGIER_RTOSINT_BITS (1 << 15)

//! \brief Defines the location of the INT1 bits in the IER register
//!
#define PIE_IER_INT1_BITS (1 << 0)

//! \brief Defines the location of the INT2 bits in the IER register
//!
#define PIE_IER_INT2_BITS (1 << 1)

//! \brief Defines the location of the INT3 bits in the IER register
//!
#define PIE_IER_INT3_BITS (1 << 2)

//! \brief Defines the location of the INT4 bits in the IER register
//!
#define PIE_IER_INT4_BITS (1 << 3)

//! \brief Defines the location of the INT5 bits in the IER register
//!
#define PIE_IER_INT5_BITS (1 << 4)

//! \brief Defines the location of the INT6 bits in the IER register
//!
#define PIE_IER_INT6_BITS (1 << 5)

//! \brief Defines the location of the INT7 bits in the IER register
//!
#define PIE_IER_INT7_BITS (1 << 6)

//! \brief Defines the location of the INT8 bits in the IER register
//!
#define PIE_IER_INT8_BITS (1 << 7)

//! \brief Defines the location of the INT9 bits in the IER register
//!
#define PIE_IER_INT9_BITS (1 << 8)

//! \brief Defines the location of the INT10 bits in the IER register
//!
#define PIE_IER_INT10_BITS (1 << 9)

//! \brief Defines the location of the INT11 bits in the IER register
//!
#define PIE_IER_INT11_BITS (1 << 10)

//! \brief Defines the location of the INT12 bits in the IER register
//!
#define PIE_IER_INT12_BITS (1 << 11)

//! \brief Defines the location of the INT13 bits in the IER register
//!
#define PIE_IER_INT13_BITS (1 << 12)

//! \brief Defines the location of the INT14 bits in the IER register
//!
#define PIE_IER_INT14_BITS (1 << 13)

//! \brief Defines the location of the DLOGINT bits in the IER register
//!
#define PIE_IER_DLOGINT_BITS (1 << 14)

//! \brief Defines the location of the RTOSINT bits in the IER register
//!
#define PIE_IER_RTOSINT_BITS (1 << 15)

//! \brief Defines the location of the INTx1 bits in the IERx register
//!
#define PIE_IERx_INTx1_BITS (1 << 0)

//! \brief Defines the location of the INTx2 bits in the IERx register
//!
#define PIE_IERx_INTx2_BITS (1 << 1)

//! \brief Defines the location of the INTx3 bits in the IERx register
//!
#define PIE_IERx_INTx3_BITS (1 << 2)

//! \brief Defines the location of the INTx4 bits in the IERx register
//!
#define PIE_IERx_INTx4_BITS (1 << 3)

//! \brief Defines the location of the INTx5 bits in the IERx register
//!
#define PIE_IERx_INTx5_BITS (1 << 4)

//! \brief Defines the location of the INTx6 bits in the IERx register
//!
#define PIE_IERx_INTx6_BITS (1 << 5)

//! \brief Defines the location of the INTx7 bits in the IERx register
//!
#define PIE_IERx_INTx7_BITS (1 << 6)

//! \brief Defines the location of the INTx8 bits in the IERx register
//!
#define PIE_IERx_INTx8_BITS (1 << 7)

//! \brief Defines the location of the INT1 bits in the IFR register
//!
#define PIE_IFR_INT1_BITS (1 << 0)

//! \brief Defines the location of the INT2 bits in the IFR register
//!
#define PIE_IFR_INT2_BITS (1 << 1)

//! \brief Defines the location of the INT3 bits in the IFR register
//!
#define PIE_IFR_INT3_BITS (1 << 2)

//! \brief Defines the location of the INT4 bits in the IFR register
//!
#define PIE_IFR_INT4_BITS (1 << 3)

//! \brief Defines the location of the INT5 bits in the IFR register
//!
#define PIE_IFR_INT5_BITS (1 << 4)

//! \brief Defines the location of the INT6 bits in the IFR register
//!
#define PIE_IFR_INT6_BITS (1 << 5)

//! \brief Defines the location of the INT7 bits in the IFR register
//!
#define PIE_IFR_INT7_BITS (1 << 6)

//! \brief Defines the location of the INT8 bits in the IFR register
//!
#define PIE_IFR_INT8_BITS (1 << 7)

//! \brief Defines the location of the INT9 bits in the IFR register
//!
#define PIE_IFR_INT9_BITS (1 << 8)

//! \brief Defines the location of the INT10 bits in the IFR register
//!
#define PIE_IFR_INT10_BITS (1 << 9)

//! \brief Defines the location of the INT11 bits in the IFR register
//!
#define PIE_IFR_INT11_BITS (1 << 10)

//! \brief Defines the location of the INT12 bits in the IFR register
//!
#define PIE_IFR_INT12_BITS (1 << 11)

//! \brief Defines the location of the INT13 bits in the IFR register
//!
#define PIE_IFR_INT13_BITS (1 << 12)

//! \brief Defines the location of the INT14 bits in the IFR register
//!
#define PIE_IFR_INT14_BITS (1 << 13)

//! \brief Defines the location of the DLOGINT bits in the IFR register
//!
#define PIE_IFR_DLOGINT_BITS (1 << 14)

//! \brief Defines the location of the RTOSINT bits in the IFR register
//!
#define PIE_IFR_RTOSINT_BITS (1 << 15)

//! \brief Defines the location of the INTx1 bits in the IFRx register
//!
#define PIE_IFRx_INTx1_BITS (1 << 0)

//! \brief Defines the location of the INTx2 bits in the IFRx register
//!
#define PIE_IFRx_INTx2_BITS (1 << 1)

//! \brief Defines the location of the INTx3 bits in the IFRx register
//!
#define PIE_IFRx_INTx3_BITS (1 << 2)

//! \brief Defines the location of the INTx4 bits in the IFRx register
//!
#define PIE_IFRx_INTx4_BITS (1 << 3)

//! \brief Defines the location of the INTx5 bits in the IFRx register
//!
#define PIE_IFRx_INTx5_BITS (1 << 4)

//! \brief Defines the location of the INTx6 bits in the IFRx register
//!
#define PIE_IFRx_INTx6_BITS (1 << 5)

//! \brief Defines the location of the INTx7 bits in the IFRx register
//!
#define PIE_IFRx_INTx7_BITS (1 << 6)

//! \brief Defines the location of the INTx8 bits in the IFRx register
//!
#define PIE_IFRx_INTx8_BITS (1 << 7)

//! \brief Defines the location of the ENPIE bits in the PIECTRL register
//!
#define PIE_PIECTRL_ENPIE_BITS (1 << 0)

//! \brief Defines the location of the PIEVECT bits in the PIECTRL register
//!
#define PIE_PIECTRL_PIEVECT_BITS (32767 << 1)

//! \brief Defines the location of the GROUP1 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP1_BITS (1 << 0)

//! \brief Defines the location of the GROUP2 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP2_BITS (1 << 1)

//! \brief Defines the location of the GROUP3 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP3_BITS (1 << 2)

//! \brief Defines the location of the GROUP4 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP4_BITS (1 << 3)

//! \brief Defines the location of the GROUP5 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP5_BITS (1 << 4)

//! \brief Defines the location of the GROUP6 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP6_BITS (1 << 5)

//! \brief Defines the location of the GROUP7 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP7_BITS (1 << 6)

//! \brief Defines the location of the GROUP8 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP8_BITS (1 << 7)

//! \brief Defines the location of the GROUP9 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP9_BITS (1 << 8)

//! \brief Defines the location of the GROUP10 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP10_BITS (1 << 9)

//! \brief Defines the location of the GROUP11 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP11_BITS (1 << 10)

//! \brief Defines the location of the GROUP12 bits in the PIEACK register
//!
#define PIE_PIEACK_GROUP12_BITS (1 << 11)

// TODO
#define PIE_XINTnCR_POLARITY_BITS (3 << 2)
#define PIE_XINTnCR_ENABLE_BITS (1 << 0)

    // **************************************************************************
    // the typedefs

    //! \brief Defines the type for an interrupt vector
    //!
    typedef interrupt void (*PIE_IntVec_t)(void);

    //! \brief 外部中断电平响应方式
    //!
    typedef enum
    {
        PIE_ExtIntPolarity_FallingEdge = (0 << 2),         //!< Denotes an interrupt is generated on the falling edge
        PIE_ExtIntPolarity_RisingEdge = (1 << 2),          //!< Denotes an interrupt is generated on the rising edge
        PIE_ExtIntPolarity_RisingAndFallingEdge = (3 << 2) //!< Denotes an interrupt is generated on the falling and rising edges
    } PIE_ExtIntPolarity_e;

    //! \brief  (PIE)组的编号，一共12组
    //!
    typedef enum
    {
        PIE_GroupNumber_1 = 0,   //!< Denotes PIE group number 1
        PIE_GroupNumber_2 = 1,   //!< Denotes PIE group number 2
        PIE_GroupNumber_3 = 2,   //!< Denotes PIE group number 3
        PIE_GroupNumber_4 = 3,   //!< Denotes PIE group number 4
        PIE_GroupNumber_5 = 4,   //!< Denotes PIE group number 5
        PIE_GroupNumber_6 = 5,   //!< Denotes PIE group number 6
        PIE_GroupNumber_7 = 6,   //!< Denotes PIE group number 7
        PIE_GroupNumber_8 = 7,   //!< Denotes PIE group number 8
        PIE_GroupNumber_9 = 8,   //!< Denotes PIE group number 9
        PIE_GroupNumber_10 = 9,  //!< Denotes PIE group number 10
        PIE_GroupNumber_11 = 10, //!< Denotes PIE group number 11
        PIE_GroupNumber_12 = 11  //!< Denotes PIE group number 12
    } PIE_GroupNumber_e;

    //! \brief  (PIE)int.x编号
    //!
    typedef enum
    {
        PIE_SubGroupNumber_1 = 0, //!< Denotes PIE group number 1
        PIE_SubGroupNumber_2 = 1, //!< Denotes PIE group number 2
        PIE_SubGroupNumber_3 = 2, //!< Denotes PIE group number 3
        PIE_SubGroupNumber_4 = 3, //!< Denotes PIE group number 4
        PIE_SubGroupNumber_5 = 4, //!< Denotes PIE group number 5
        PIE_SubGroupNumber_6 = 5, //!< Denotes PIE group number 6
        PIE_SubGroupNumber_7 = 6, //!< Denotes PIE group number 7
        PIE_SubGroupNumber_8 = 7  //!< Denotes PIE group number 8
    } PIE_SubGroupNumber_e;

    //! \brief 系统中断的枚举变量
    //!
    typedef enum
    {
        PIE_SystemInterrupts_Reset = 0, //!< Reset interrupt vector
        PIE_SystemInterrupts_INT1,      //!< INT1 interrupt vector
        PIE_SystemInterrupts_INT2,      //!< INT2 interrupt vector
        PIE_SystemInterrupts_INT3,      //!< INT3 interrupt vector
        PIE_SystemInterrupts_INT4,      //!< INT4 interrupt vector
        PIE_SystemInterrupts_INT5,      //!< INT5 interrupt vector
        PIE_SystemInterrupts_INT6,      //!< INT6 interrupt vector
        PIE_SystemInterrupts_INT7,      //!< INT7 interrupt vector
        PIE_SystemInterrupts_INT8,      //!< INT8 interrupt vector
        PIE_SystemInterrupts_INT9,      //!< INT9 interrupt vector
        PIE_SystemInterrupts_INT10,     //!< INT10 interrupt vector
        PIE_SystemInterrupts_INT11,     //!< INT11 interrupt vector
        PIE_SystemInterrupts_INT12,     //!< INT12 interrupt vector
        PIE_SystemInterrupts_TINT1,     //!< INT13 interrupt vector
        PIE_SystemInterrupts_TINT2,     //!< INT14 interrupt vector
        PIE_SystemInterrupts_DATALOG,   //!< DATALOG interrupt vector
        PIE_SystemInterrupts_RTOSINT,   //!< RTOSINT interrupt vector
        PIE_SystemInterrupts_EMUINT,    //!< EMUINT interrupt vector
        PIE_SystemInterrupts_NMI,       //!< NMI interrupt vector
        PIE_SystemInterrupts_ILLEGAL,   //!< ILLEGAL interrupt vector
        PIE_SystemInterrupts_USER1,     //!< USER1 interrupt vector
        PIE_SystemInterrupts_USER2,     //!< USER2 interrupt vector
        PIE_SystemInterrupts_USER3,     //!< USER3 interrupt vector
        PIE_SystemInterrupts_USER4,     //!< USER4 interrupt vector
        PIE_SystemInterrupts_USER5,     //!< USER5 interrupt vector
        PIE_SystemInterrupts_USER6,     //!< USER6 interrupt vector
        PIE_SystemInterrupts_USER7,     //!< USER7 interrupt vector
        PIE_SystemInterrupts_USER8,     //!< USER8 interrupt vector
        PIE_SystemInterrupts_USER9,     //!< USER9 interrupt vector
        PIE_SystemInterrupts_USER10,    //!< USER10 interrupt vector
        PIE_SystemInterrupts_USER11,    //!< USER11 interrupt vector
        PIE_SystemInterrupts_USER12     //!< USER12 interrupt vector
    } PIE_SystemInterrupts_e;

    //! \brief 枚举以定义外围中断扩展（PIE）的各个中断源（跟28335中断源对应）
    //!
    typedef enum
    {
        // Group 1 Interrupts
        PIE_InterruptSource_SEQ1INT = (1 << 0), //!< Group 1 ADC Interrupt 1
        PIE_InterruptSource_SEQ2INT = (1 << 1), //!< Group 1 ADC Interrupt 2
        PIE_InterruptSource_XINT_1 = (1 << 3),  //!< External Interrupt 1
        PIE_InterruptSource_XINT_2 = (1 << 4),  //!< External Interrupt 2
        PIE_InterruptSource_ADCINT = (1 << 5),  //!< ADC Interrupt 9
        PIE_InterruptSource_TIMER_0 = (1 << 6), //!< Timer Interrupt 0
        PIE_InterruptSource_WAKE = (1 << 7),    //!< Wake Up Interrupt

        // Group 2 Interrupts
        PIE_InterruptSource_TZ1 = (1 << 0), //!< EPWM TZ1 Interrupt
        PIE_InterruptSource_TZ2 = (1 << 1), //!< EPWM TZ2 Interrupt
        PIE_InterruptSource_TZ3 = (1 << 2), //!< EPWM TZ3 Interrupt
        PIE_InterruptSource_TZ4 = (1 << 3), //!< EPWM TZ4 Interrupt
        PIE_InterruptSource_TZ5 = (1 << 4), //!< EPWM TZ5 Interrupt
        PIE_InterruptSource_TZ6 = (1 << 5), //!< EPWM TZ6 Interrupt

        // Group 3 Interrupts
        PIE_InterruptSource_EPWM1 = (1 << 0), //!< EPWM 1 Interrupt
        PIE_InterruptSource_EPWM2 = (1 << 1), //!< EPWM 2 Interrupt
        PIE_InterruptSource_EPWM3 = (1 << 2), //!< EPWM 3 Interrupt
        PIE_InterruptSource_EPWM4 = (1 << 3), //!< EPWM 4 Interrupt
        PIE_InterruptSource_EPWM5 = (1 << 4), //!< EPWM 5 Interrupt
        PIE_InterruptSource_EPWM6 = (1 << 5), //!< EPWM 6 Interrupt

        // Group 4 Interrupts
        PIE_InterruptSource_ECAP1 = (1 << 0), //!< ECAP 1 Interrupt
        PIE_InterruptSource_ECAP2 = (1 << 1), //!< ECAP 2 Interrupt
        PIE_InterruptSource_ECAP3 = (1 << 2), //!< ECAP 3 Interrupt
        PIE_InterruptSource_ECAP4 = (1 << 3), //!< ECAP 1 Interrupt
        PIE_InterruptSource_ECAP5 = (1 << 4), //!< ECAP 2 Interrupt
        PIE_InterruptSource_ECAP6 = (1 << 5), //!< ECAP 3 Interrupt

        // Group 5 Interrupts
        PIE_InterruptSource_EQEP1 = (1 << 0), //!< EQEP 1 Interrupt
        PIE_InterruptSource_EQEP2 = (1 << 1), //!< EQEP 2 Interrupt

        // Group 6 Interrupts
        PIE_InterruptSource_SPIARX = (1 << 0),   //!< SPI A RX Interrupt
        PIE_InterruptSource_SPIATX = (1 << 1),   //!< SPI A TX Interrupt
        PIE_InterruptSource_McBSPBRX = (1 << 2), //!< SPI B RX Interrupt
        PIE_InterruptSource_McBSPBTX = (1 << 3), //!< SPI B TX Interrupt
        PIE_InterruptSource_McBSPARX = (1 << 4), //!< McBSP A RX Interrupt
        PIE_InterruptSource_McBSPATX = (1 << 5), //!< McBSP A TX Interrupt

        // Group 7 Interrupts
        PIE_InterruptSource_DMA_CH1 = (1 << 0), //!< DMA Channel 1
        PIE_InterruptSource_DMA_CH2 = (1 << 1), //!< DMA Channel 2
        PIE_InterruptSource_DMA_CH3 = (1 << 2), //!< DMA Channel 3
        PIE_InterruptSource_DMA_CH4 = (1 << 3), //!< DMA Channel 4
        PIE_InterruptSource_DMA_CH5 = (1 << 4), //!< DMA Channel 5
        PIE_InterruptSource_DMA_CH6 = (1 << 5), //!< DMA Channel 6

        // Group 8 Interrupts
        PIE_InterruptSource_I2CA1 = (1 << 0), //!< I2C A Interrupt 1
        PIE_InterruptSource_I2CA2 = (1 << 1), //!< I2C A Interrupt 2

        // Group 9 Interrupts
        PIE_InterruptSource_SCIARX = (1 << 0), //!< SCI A RX Interrupt
        PIE_InterruptSource_SCIATX = (1 << 1), //!< SCI A TX Interrupt
        PIE_InterruptSource_SCIBRX = (1 << 2), //!< SCI B RX Interrupt
        PIE_InterruptSource_SCIBTX = (1 << 3), //!< SCI B TX Interrupt
        PIE_InterruptSource_ECANA0 = (1 << 4), //!< eCAN A 0 Interrupt
        PIE_InterruptSource_ECANA1 = (1 << 5), //!< eCAN A 1 Interrupt
        PIE_InterruptSource_ECANB0 = (1 << 4), //!< eCAN B 0 Interrupt
        PIE_InterruptSource_ECANB1 = (1 << 5), //!< eCAN B 1 Interrupt

        // Group 10 Interrupts
        // Group 11 Interrupts

        // Group 12 Interrupts
        PIE_InterruptSource_XINT_3 = (1 << 0),     //!< External Interrupt 3
        PIE_InterruptSource_XINT_4 = (1 << 1),     //!< External Interrupt 3
        PIE_InterruptSource_XINT_5 = (1 << 2),     //!< External Interrupt 3
        PIE_InterruptSource_XINT_6 = (1 << 3),     //!< External Interrupt 3
        PIE_InterruptSource_XINT_7 = (1 << 4),     //!< External Interrupt 3
        PIE_InterruptSource_CLAINT_LVF = (1 << 6), //!< CLA Interrupt LVF
        PIE_InterruptSource_CLAINT_LUF = (1 << 7)  //!< CLA Interrupt LUF

    } PIE_InterruptSource_e;

    //! \brief Defines the PIE_IERIFR_t data type
    //!
    typedef struct _PIE_IERIFR_t
    {
        volatile uint16_t IER; //!< the Interrupt Enable Register (IER)
        volatile uint16_t IFR; //!< the Interrupt Flag Register (IFR)
    } PIE_IERIFR_t;

    //! \brief Defines the peripheral interrupt expansion (PIE) object
    //!
    typedef struct _PIE_Obj_
    {
        volatile uint16_t PIECTRL;               //!< PIE Control Register
        volatile uint16_t PIEACK;                //!< PIE Acknowledge Register
        volatile PIE_IERIFR_t PIEIER_PIEIFR[12]; //!< PIE Interrupt Enable Register and PIE Interrupt Flag Register
        volatile uint16_t rsvd_1[6];             //!< Reserved
        volatile PIE_IntVec_t Reset;             //!< Reset interrupt vector
        volatile PIE_IntVec_t INT1;              //!< INT1 interrupt vector
        volatile PIE_IntVec_t INT2;              //!< INT2 interrupt vector
        volatile PIE_IntVec_t INT3;              //!< INT3 interrupt vector
        volatile PIE_IntVec_t INT4;              //!< INT4 interrupt vector
        volatile PIE_IntVec_t INT5;              //!< INT5 interrupt vector
        volatile PIE_IntVec_t INT6;              //!< INT6 interrupt vector
        volatile PIE_IntVec_t INT7;              //!< INT7 interrupt vector
        volatile PIE_IntVec_t INT8;              //!< INT8 interrupt vector
        volatile PIE_IntVec_t INT9;              //!< INT9 interrupt vector
        volatile PIE_IntVec_t INT10;             //!< INT10 interrupt vector
        volatile PIE_IntVec_t INT11;             //!< INT11 interrupt vector
        volatile PIE_IntVec_t INT12;             //!< INT12 interrupt vector
        volatile PIE_IntVec_t TINT1;             //!< INT13 interrupt vector
        volatile PIE_IntVec_t TINT2;             //!< INT14 interrupt vector
        volatile PIE_IntVec_t DATALOG;           //!< DATALOG interrupt vector
        volatile PIE_IntVec_t RTOSINT;           //!< RTOSINT interrupt vector
        volatile PIE_IntVec_t EMUINT;            //!< EMUINT interrupt vector
        volatile PIE_IntVec_t NMI;               //!< NMI interrupt vector
        volatile PIE_IntVec_t ILLEGAL;           //!< ILLEGAL interrupt vector
        volatile PIE_IntVec_t USER1;             //!< USER1 interrupt vector
        volatile PIE_IntVec_t USER2;             //!< USER2 interrupt vector
        volatile PIE_IntVec_t USER3;             //!< USER3 interrupt vector
        volatile PIE_IntVec_t USER4;             //!< USER4 interrupt vector
        volatile PIE_IntVec_t USER5;             //!< USER5 interrupt vector
        volatile PIE_IntVec_t USER6;             //!< USER6 interrupt vector
        volatile PIE_IntVec_t USER7;             //!< USER7 interrupt vector
        volatile PIE_IntVec_t USER8;             //!< USER8 interrupt vector
        volatile PIE_IntVec_t USER9;             //!< USER9 interrupt vector
        volatile PIE_IntVec_t USER10;            //!< USER10 interrupt vector
        volatile PIE_IntVec_t USER11;            //!< USER11 interrupt vector
        volatile PIE_IntVec_t USER12;            //!< USER12 interrupt vector
        // Group 1 PIE interrupt
        volatile PIE_IntVec_t SEQ1INT; //!< 28335为ADC排序中断
        volatile PIE_IntVec_t SEQ2INT; //!< 28335为ADC排序中断
        volatile PIE_IntVec_t rsvd1_3; //!< Reserved
        volatile PIE_IntVec_t XINT1;   //!< XINT1 interrupt vector
        volatile PIE_IntVec_t XINT2;   //!< XINT2 interrupt vector
        volatile PIE_IntVec_t ADCINT;  //!<  ADC中断
        volatile PIE_IntVec_t TINT0;   //!< TINT0 interrupt vector
        volatile PIE_IntVec_t WAKEINT; //!< WAKEINT interrupt vector

        // Group 2 PIE interrupt
        volatile PIE_IntVec_t EPWM1_TZINT; //!< EPWM1_TZINT interrupt vector
        volatile PIE_IntVec_t EPWM2_TZINT; //!< EPWM2_TZINT interrupt vector
        volatile PIE_IntVec_t EPWM3_TZINT; //!< EPWM3_TZINT interrupt vector
        volatile PIE_IntVec_t EPWM4_TZINT; //!< EPWM4_TZINT interrupt vector
        volatile PIE_IntVec_t EPWM5_TZINT; //!< EPWM5_TZINT interrupt vector
        volatile PIE_IntVec_t EPWM6_TZINT; //!< EPWM6_TZINT interrupt vector
        volatile PIE_IntVec_t rsvd2_7;     //!< 28335为保留
        volatile PIE_IntVec_t rsvd2_8;     //!< 28335为保留

        // Group 3 PIE interrupt
        volatile PIE_IntVec_t EPWM1_INT; //!< EPWM1 interrupt vector
        volatile PIE_IntVec_t EPWM2_INT; //!< EPWM2 interrupt vector
        volatile PIE_IntVec_t EPWM3_INT; //!< EPWM3 interrupt vector
        volatile PIE_IntVec_t EPWM4_INT; //!< EPWM4 interrupt vector
        volatile PIE_IntVec_t EPWM5_INT; //!< EPWM5_INT interrupt vector
        volatile PIE_IntVec_t EPWM6_INT; //!< EPWM6_INT interrupt vector
        volatile PIE_IntVec_t rsvd3_7;   //!< 28335为保留
        volatile PIE_IntVec_t rsvd3_8;   //!< 28335为保留

        // Group 4 PIE interrupt
        volatile PIE_IntVec_t ECAP1_INT; //!< ECAP1_INT interrupt vector
        volatile PIE_IntVec_t ECAP2_INT; //!< ECAP2_INT interrupt vector
        volatile PIE_IntVec_t ECAP3_INT; //!< ECAP3_INT interrupt vector
        volatile PIE_IntVec_t ECAP4_INT; //!< 28335更改项
        volatile PIE_IntVec_t ECAP5_INT; //!< 28335更改项
        volatile PIE_IntVec_t ECAP6_INT; //!< 28335更改项
        volatile PIE_IntVec_t rsvd4_7;   //!< 28335更改项
        volatile PIE_IntVec_t rsvd4_8;   //!< 28335更改项

        // Group 5 PIE interrupt
        volatile PIE_IntVec_t EQEP1_INT; //!< EQEP1_INT interrupt vector
        volatile PIE_IntVec_t EQEP2_INT; //!< EQEP2_INT interrupt vector
        volatile PIE_IntVec_t rsvd5_3;   //!<  28335更改项
        volatile PIE_IntVec_t rsvd5_4;   //!<  28335更改项
        volatile PIE_IntVec_t rsvd5_5;   //!<  28335更改项
        volatile PIE_IntVec_t rsvd5_6;   //!<  28335更改项
        volatile PIE_IntVec_t rsvd5_7;   //!<  28335更改项
        volatile PIE_IntVec_t rsvd5_8;   //!<  28335更改项

        // Group 6 PIE interrupt
        volatile PIE_IntVec_t SPIRXINTA; //!< SPIRXINTA interrupt vector
        volatile PIE_IntVec_t SPITXINTA; //!< SPITXINTA interrupt vector
        volatile PIE_IntVec_t MRINTB;    //!< 28335更改项 McBSP-B
        volatile PIE_IntVec_t MXINTB;    //!< 28335更改项 McBSP-B
        volatile PIE_IntVec_t MRINTA;    //!< 28335更改项 McBSP-A
        volatile PIE_IntVec_t MXINTA;    //!< 28335更改项 McBSP-A
        volatile PIE_IntVec_t rsvd6_7;   //!< Reserved
        volatile PIE_IntVec_t rsvd6_8;   //!< Reserved

        // Group 7 Interrupts
        volatile PIE_IntVec_t DMACH1_INT; //!< DMA Channel 1
        volatile PIE_IntVec_t DMACH2_INT; //!< DMA Channel 2
        volatile PIE_IntVec_t DMACH3_INT; //!< DMA Channel 3
        volatile PIE_IntVec_t DMACH4_INT; //!< DMA Channel 4
        volatile PIE_IntVec_t DMACH5_INT; //!< DMA Channel 5
        volatile PIE_IntVec_t DMACH6_INT; //!< DMA Channel 6
        volatile PIE_IntVec_t rsvd7_7;    //!< Reserved
        volatile PIE_IntVec_t rsvd7_8;    //!< Reserved

        // Group 8 Interrupts
        volatile PIE_IntVec_t I2CINT1A;  //!< I2CINT1A interrupt vector
        volatile PIE_IntVec_t I2CINT2A;  //!< I2CINT2A interrupt vector
        volatile PIE_IntVec_t rsvd8_3;   //!< Reserved
        volatile PIE_IntVec_t rsvd8_4;   //!< Reserved
        volatile PIE_IntVec_t SCIRXINTC; //!< 28335更改项
        volatile PIE_IntVec_t SCITXINTC; //!< 28335更改项
        volatile PIE_IntVec_t rsvd8_7;   //!< Reserved
        volatile PIE_IntVec_t rsvd8_8;   //!< Reserved

        // Group 9 Interrupts
        volatile PIE_IntVec_t SCIRXINTA; //!< SCIRXINTA interrupt vector
        volatile PIE_IntVec_t SCITXINTA; //!< SCITXINTA interrupt vector
        volatile PIE_IntVec_t SCIRXINTB; //!< SPIRXINTB interrupt vector
        volatile PIE_IntVec_t SCITXINTB; //!< SPITXINTB interrupt vector
        volatile PIE_IntVec_t ECAN0INTA; //!< 28335更改项
        volatile PIE_IntVec_t ECAN1INTA; //!< 28335更改项
        volatile PIE_IntVec_t ECAN0INTB; //!< 28335更改项
        volatile PIE_IntVec_t ECAN0INTB; //!< 28335更改项

        // Group 10 Interrupts
        volatile PIE_IntVec_t rsvd10_1; //!< 28335 去除
        volatile PIE_IntVec_t rsvd10_2; //!< 28335 去除
        volatile PIE_IntVec_t rsvd10_3; //!< 28335 去除
        volatile PIE_IntVec_t rsvd10_4; //!< 28335 去除
        volatile PIE_IntVec_t rsvd10_5; //!< 28335 去除
        volatile PIE_IntVec_t rsvd10_6; //!< 28335 去除
        volatile PIE_IntVec_t rsvd10_7; //!< 28335 去除
        volatile PIE_IntVec_t rsvd10_8; //!< 28335 去除

        // Group 11 Interrupts
        volatile PIE_IntVec_t rsvd11_1; //!< 28335去除，不包含
        volatile PIE_IntVec_t rsvd11_2; //!< 28335去除，不包含
        volatile PIE_IntVec_t rsvd11_3; //!< 28335去除，不包含
        volatile PIE_IntVec_t rsvd11_4; //!< 28335去除，不包含
        volatile PIE_IntVec_t rsvd11_5; //!< 28335去除，不包含
        volatile PIE_IntVec_t rsvd11_6; //!< 28335去除，不包含
        volatile PIE_IntVec_t rsvd11_7; //!< 28335去除，不包含
        volatile PIE_IntVec_t rsvd11_8; //!< 28335去除，不包含

        // Group 12 Interrupts
        volatile PIE_IntVec_t XINT3;      //!< XINT3 interrupt vector
        volatile PIE_IntVec_t XINT4;      //!< 28335 更改项
        volatile PIE_IntVec_t XINT5;      //!< 28335 更改项
        volatile PIE_IntVec_t XINT6;      //!< 28335 更改项
        volatile PIE_IntVec_t XINT7;      //!< 28335 更改项
        volatile PIE_IntVec_t rsvd12_6;   //!< 28335 更改项
        volatile PIE_IntVec_t CLAINT_LVF; //!< CLA Interrupt LVF
        volatile PIE_IntVec_t CLAINT_LUF; //!< CLA Interrupt LUF

        volatile uint16_t rsvd13[25200]; //!< Reserved
        volatile uint16_t XINTnCR[7];    //!< 28335 更改项
        volatile uint16_t XNMICR;        //!< 28335 更改项
        volatile uint16_t XINTnCTR[2];   //!< 28335 更改项
        volatile uint16_t rsvd14[5];     //!< 28335 更改项
        volatile uint16_t XNMICTR;       //!< 28335 更改项
    } PIE_Obj;

    //! \brief Defines the peripheral interrupt expansion (PIE) handle
    //!
    typedef struct _PIE_Obj_ *PIE_Handle;

    // **************************************************************************
    // the globals

    // **************************************************************************
    // the function prototypes

    //! \brief    //TODO  Clears all the interrupts
    //! \param[in] pieHandle    The peripheral interrupt expansion (PIE) object handle
    extern void PIE_clearAllInts(PIE_Handle pieHandle);

    //! \brief     清除中断标志位
    //! \param[in] pieHandle    The peripheral interrupt expansion (PIE) object handle
    extern void PIE_clearAllFlags(PIE_Handle pieHandle);

    //! \brief     清除由 group number 定义的中断
    //! \param[in] pieHandle    The peripheral interrupt expansion (PIE) object handle
    //! \param[in] groupNumber  The group number
    static inline void PIE_clearInt(PIE_Handle pieHandle, const PIE_GroupNumber_e groupNumber)
    {
        PIE_Obj *pie = (PIE_Obj *)pieHandle;

        // set the group number
        pie->PIEACK = (1 << groupNumber);

        return;
    } // end of PIE_clearInt() function

    //! \brief     禁用外设中断
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
    extern void PIE_disable(PIE_Handle pieHandle);

    //! \brief     禁用所有中断 IER=0
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
    extern void PIE_disableAllInts(PIE_Handle pieHandle);

    //! \brief     禁用 capture 中断
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
    extern void PIE_disableCaptureInt(PIE_Handle pieHandle);

    //! \brief     禁用特定的 PIE 中断
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
    //! \param[in] group  The PIE group an interrupt belongs to
    //! \param[in] intSource  The specific interrupt source to disable
    extern void PIE_disableInt(PIE_Handle pieHandle, const PIE_GroupNumber_e group, const PIE_InterruptSource_e intSource);

    //! \brief     使能(PIE)
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
    extern void PIE_enable(PIE_Handle pieHandle);

    //! \brief    使能 ADC 中断
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
    //! \param[in] intNumber  The interrupt number
    extern void PIE_enableAdcInt(PIE_Handle pieHandle);

    //! @brief: 使能 ADC 排序器中断
    //! @param PIE_Handle pieHandle
    //! @param int intNumber
    //! @return *
    //! @details:
    extern void PIE_enableAdcSEQInt(PIE_Handle pieHandle, const int SEQNumber);

    //! \brief    使能 capture 中断
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
    extern void PIE_enableCaptureInt(PIE_Handle pieHandle);

    //! \brief     使能 特定的外部 中断
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) handle
    //! \param[in] intNumber  The interrupt number
    extern void PIE_enableExtInt(PIE_Handle pieHandle, const CPU_ExtIntNumber_e intNumber);

    //! \brief     使能特定的 PIE 中断
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
    //! \param[in] group  The PIE group an interrupt belongs to
    //! \param[in] intSource  The specific interrupt source to enable
    extern void PIE_enableInt(PIE_Handle pieHandle, const PIE_GroupNumber_e group, const PIE_InterruptSource_e intSource);

    //! \brief     使能 PWM 中断
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) handle
    //! \param[in] pwmNumber  The PWM number
    extern void PIE_enablePwmInt(PIE_Handle pieHandle, const PWM_Number_e pwmNumber);

    //! \brief     使能PWM Trip Zone 中断
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) handle
    //! \param[in] pwmNumber  The PWM number
    extern void PIE_enablePwmTzInt(PIE_Handle pieHandle, const PWM_Number_e pwmNumber);

    //! \brief     使能Cpu Timer 0 中断
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) handle
    extern void PIE_enableTimer0Int(PIE_Handle pieHandle);

    //! \brief     Gets the external interrupt count value
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) handle
    //! \param[in] intNumber  The external interrupt number
    //! \return    The count value
    extern uint16_t PIE_getExtIntCount(PIE_Handle pieHandle, const CPU_ExtIntNumber_e intNumber);

    //! \brief    获取 PIE 中断使能值
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
    //! \param[in] group  The PIE group the flags belong to
    extern uint16_t PIE_getIntEnables(PIE_Handle pieHandle, const PIE_GroupNumber_e group);

    //! \brief    获取 PIE 中断标志位的值
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
    //! \param[in] group  The PIE group the flags belong to
    extern uint16_t PIE_getIntFlags(PIE_Handle pieHandle, const PIE_GroupNumber_e group);

    //! \brief     强制使能 某个 PIE 中断
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
    //! \param[in] group  The PIE group an interrupt belongs to
    //! \param[in] intSource  The specific interrupt source to force
    extern void PIE_forceInt(PIE_Handle pieHandle, const PIE_GroupNumber_e group, const PIE_InterruptSource_e intSource);

    //! \brief     Defines an illegal interrupt service routine - if the program pointer references this function,
    //!            there is an incorrect mapping in the PIE interrupt table
    interrupt void PIE_illegalIsr(void);

    //! \brief    初始化(PIE) 对象
    //! \param[in] pMemory    A pointer to the memory for the PIE object
    //! \param[in] numBytes   The number of bytes allocated for the PIE object, bytes
    //! \return    The peripheral interrupt expansion (PIE) object handle
    extern PIE_Handle PIE_init(void *pMemory, const size_t numBytes);

    //! \brief     Registers a handler for a PIE interrupt
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
    //! \param[in] groupNumber  The PIE group an interrupt belongs to
    //! \param[in] subGroupNumber  The PIE subgroup an interrupt belongs to
    //! \param[in] vector  The specific interrupt handler
    extern void PIE_registerPieIntHandler(PIE_Handle pieHandle,
                                          const PIE_GroupNumber_e groupNumber,
                                          const PIE_SubGroupNumber_e subGroupNumber,
                                          const PIE_IntVec_t vector);

    //! \brief     Registers a handler for a PIE interrupt
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
    //! \param[in] systemInt  The system interrupt to register this handler to
    //! \param[in] vector  The specific interrupt handler
    extern void PIE_registerSystemIntHandler(PIE_Handle pieHandle,
                                             const PIE_SystemInterrupts_e systemInt,
                                             const PIE_IntVec_t vector);

    //! \brief     初始化中断向量表 用illegal ISR handlers
    //! \param[in]  pieHandle  The peripheral interrupt expansion (PIE) object handle
    extern void PIE_setDefaultIntVectorTable(PIE_Handle pieHandle);

    //! \brief     设置外部中断响应电平
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) handle
    //! \param[in] intNumber  The external interrupt number
    //! \param[in] polarity   The signal polarity
    extern void PIE_setExtIntPolarity(PIE_Handle pieHandle,
                                      const CPU_ExtIntNumber_e intNumber,
                                      const PIE_ExtIntPolarity_e polarity);

    //! \brief     注销 PIE 中断 handler
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
    //! \param[in] groupNumber  The PIE group an interrupt belongs to
    //! \param[in] subGroupNumber  The PIE subgroup an interrupt belongs to
    extern void PIE_unregisterPieIntHandler(PIE_Handle pieHandle,
                                            const PIE_GroupNumber_e groupNumber,
                                            const PIE_SubGroupNumber_e subGroupNumber);

    //! \brief     Unregisters a handler for a PIE interrupt
    //! \param[in] pieHandle  The peripheral interrupt expansion (PIE) object handle
    //! \param[in] systemInt  The system interrupt to unregister
    extern void PIE_unregisterSystemIntHandler(PIE_Handle pieHandle,
                                               const PIE_SystemInterrupts_e systemInt);

#ifdef __cplusplus
}
#endif // extern "C"

//@} // ingroup
#endif // end of _PIE_H_ definition
