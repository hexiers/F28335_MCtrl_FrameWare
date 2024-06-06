
//! @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_Driver\Include\pwm.h
//! @Author: Hex
//! @Date: 2023-08-20 21:25:26
//! @LastEditTime: 2023-09-05 21:50:40
//! @Description: 


//! @FilePath: \DSP28xx_MotCtl_Frameware\MotCtl_Driver\Include\pwm.h
//! @Author: Hex
//! @Date: 2023-08-20 21:25:26
//! @LastEditTime: 2023-09-05 21:20:12
//! @Description:

#ifndef _PWM_H_
#define _PWM_H_

// **************************************************************************
// the includes

#include "../../MotCtl_Driver/Include/cpu.h"
#include "types.h"

// **************************************************************************
// the defines
// **************************************************************************

//! \brief 6个ePWM的基地址
//!
#define PWM_ePWM1_BASE_ADDR          (0x00006800)

#define PWM_ePWM2_BASE_ADDR          (0x00006840)

#define PWM_ePWM3_BASE_ADDR          (0x00006880)

#define PWM_ePWM4_BASE_ADDR          (0x000068C0)

#define PWM_ePWM5_BASE_ADDR          (0x000068C0)

#define PWM_ePWM6_BASE_ADDR          (0x000068C0)

// TBCTL (Time-Base Control)
//==========================
// CTRMODE bits
#define TB_COUNT_UP 0x0
#define TB_COUNT_DOWN 0x1
#define TB_COUNT_UPDOWN 0x2
#define TB_FREEZE 0x3
// PHSEN bit
#define TB_DISABLE 0x0
#define TB_ENABLE 0x1
// PRDLD bit
#define TB_SHADOW 0x0
#define TB_IMMEDIATE 0x1
// SYNCOSEL bits
#define TB_SYNC_IN 0x0
#define TB_CTR_ZERO 0x1
#define TB_CTR_CMPB 0x2
#define TB_SYNC_DISABLE 0x3
// HSPCLKDIV and CLKDIV bits
#define TB_DIV1 0x0
#define TB_DIV2 0x1
#define TB_DIV4 0x2
// PHSDIR bit
#define TB_DOWN 0x0
#define TB_UP 0x1

// CMPCTL (Compare Control)
//==========================
// LOADAMODE and LOADBMODE bits
#define CC_CTR_ZERO 0x0
#define CC_CTR_PRD 0x1
#define CC_CTR_ZERO_PRD 0x2
#define CC_LD_DISABLE 0x3
// SHDWAMODE and SHDWBMODE bits
#define CC_SHADOW 0x0
#define CC_IMMEDIATE 0x1

// AQCTLA and AQCTLB (Action Qualifier Control)
//=============================================
// ZRO, PRD, CAU, CAD, CBU, CBD bits
#define AQ_NO_ACTION 0x0
#define AQ_CLEAR 0x1
#define AQ_SET 0x2
#define AQ_TOGGLE 0x3

// DBCTL (Dead-Band Control)
//==========================
// OUT MODE bits
#define DB_DISABLE 0x0
#define DBA_ENABLE 0x1
#define DBB_ENABLE 0x2
#define DB_FULL_ENABLE 0x3
// POLSEL bits
#define DB_ACTV_HI 0x0
#define DB_ACTV_LOC 0x1
#define DB_ACTV_HIC 0x2
#define DB_ACTV_LO 0x3
// IN MODE
#define DBA_ALL 0x0
#define DBB_RED_DBA_FED 0x1
#define DBA_RED_DBB_FED 0x2
#define DBB_ALL 0x3

// CHPCTL (chopper control)
//==========================
// CHPEN bit
#define CHP_DISABLE 0x0
#define CHP_ENABLE 0x1
// CHPFREQ bits
#define CHP_DIV1 0x0
#define CHP_DIV2 0x1
#define CHP_DIV3 0x2
#define CHP_DIV4 0x3
#define CHP_DIV5 0x4
#define CHP_DIV6 0x5
#define CHP_DIV7 0x6
#define CHP_DIV8 0x7
// CHPDUTY bits
#define CHP1_8TH 0x0
#define CHP2_8TH 0x1
#define CHP3_8TH 0x2
#define CHP4_8TH 0x3
#define CHP5_8TH 0x4
#define CHP6_8TH 0x5
#define CHP7_8TH 0x6

// TZSEL (Trip Zone Select)
//==========================
// CBCn and OSHTn bits
#define TZ_DISABLE 0x0
#define TZ_ENABLE 0x1

// TZCTL (Trip Zone Control)
//==========================
// TZA and TZB bits
#define TZ_HIZ 0x0
#define TZ_FORCE_HI 0x1
#define TZ_FORCE_LO 0x2
#define TZ_NO_CHANGE 0x3

// ETSEL (Event Trigger Select)
//=============================
#define ET_CTR_ZERO 0x1
#define ET_CTR_PRD 0x2
#define ET_CTRU_CMPA 0x4
#define ET_CTRD_CMPA 0x5
#define ET_CTRU_CMPB 0x6
#define ET_CTRD_CMPB 0x7

// ETPS (Event Trigger Pre-scale)
//===============================
// INTPRD, SOCAPRD, SOCBPRD bits
#define ET_DISABLE 0x0
#define ET_1ST 0x1
#define ET_2ND 0x2
#define ET_3RD 0x3

//--------------------------------
// HRPWM (High Resolution PWM)
//================================
// HRCNFG
#define HR_Disable 0x0
#define HR_REP 0x1
#define HR_FEP 0x2
#define HR_BEP 0x3

#define HR_CMP 0x0
#define HR_PHS 0x1

#define HR_CTR_ZERO 0x0
#define HR_CTR_PRD 0x1

// **************************************************************************
// the typdefines
// **************************************************************************
//----------------------------------------------------
// Time base control register bit definitions */
struct TBCTL_BITS
{                         // bits   description
    Uint16 CTRMODE : 2;   // 1:0    Counter Mode
    Uint16 PHSEN : 1;     // 2      Phase load enable
    Uint16 PRDLD : 1;     // 3      Active period load
    Uint16 SYNCOSEL : 2;  // 5:4    Sync output select
    Uint16 SWFSYNC : 1;   // 6      Software force sync pulse
    Uint16 HSPCLKDIV : 3; // 9:7    High speed time pre-scale
    Uint16 CLKDIV : 3;    // 12:10  Timebase clock pre-scale
    Uint16 PHSDIR : 1;    // 13     Phase Direction
    Uint16 FREE_SOFT : 2; // 15:14  Emulation mode
};
union TBCTL_REG
{
    Uint16 all;
    struct TBCTL_BITS bit;
};

//----------------------------------------------------
// Time base status register bit definitions */
struct TBSTS_BITS
{                      // bits   description
    Uint16 CTRDIR : 1; // 0      Counter direction status
    Uint16 SYNCI : 1;  // 1      External input sync status
    Uint16 CTRMAX : 1; // 2      Counter max latched status
    Uint16 rsvd1 : 13; // 15:3   reserved
};
union TBSTS_REG
{
    Uint16 all;
    struct TBSTS_BITS bit;
};

//----------------------------------------------------
// Compare control register bit definitions */
struct CMPCTL_BITS
{                         // bits   description
    Uint16 LOADAMODE : 2; // 0:1    Active compare A
    Uint16 LOADBMODE : 2; // 3:2    Active compare B
    Uint16 SHDWAMODE : 1; // 4      Compare A block operating mode
    Uint16 rsvd1 : 1;     // 5      reserved
    Uint16 SHDWBMODE : 1; // 6      Compare B block operating mode
    Uint16 rsvd2 : 1;     // 7      reserved
    Uint16 SHDWAFULL : 1; // 8      Compare A Shadow registers full Status
    Uint16 SHDWBFULL : 1; // 9      Compare B Shadow registers full Status
    Uint16 rsvd3 : 6;     // 15:10  reserved
};

union CMPCTL_REG
{
    Uint16 all;
    struct CMPCTL_BITS bit;
};

//----------------------------------------------------
// Action qualifier register bit definitions */
struct AQCTL_BITS
{                    // bits   description
    Uint16 ZRO : 2;  // 1:0    Action Counter = Zero
    Uint16 PRD : 2;  // 3:2    Action Counter = Period
    Uint16 CAU : 2;  // 5:4    Action Counter = Compare A up
    Uint16 CAD : 2;  // 7:6    Action Counter = Compare A down
    Uint16 CBU : 2;  // 9:8    Action Counter = Compare B up
    Uint16 CBD : 2;  // 11:10  Action Counter = Compare B down
    Uint16 rsvd : 4; // 15:12  reserved
};

union AQCTL_REG
{
    Uint16 all;
    struct AQCTL_BITS bit;
};

//----------------------------------------------------
// Action qualifier SW force register bit definitions */
struct AQSFRC_BITS
{                      // bits   description
    Uint16 ACTSFA : 2; // 1:0    Action when One-time SW Force A invoked
    Uint16 OTSFA : 1;  // 2      One-time SW Force A output
    Uint16 ACTSFB : 2; // 4:3    Action when One-time SW Force B invoked
    Uint16 OTSFB : 1;  // 5      One-time SW Force A output
    Uint16 RLDCSF : 2; // 7:6    Reload from Shadow options
    Uint16 rsvd1 : 8;  // 15:8   reserved
};

union AQSFRC_REG
{
    Uint16 all;
    struct AQSFRC_BITS bit;
};

//----------------------------------------------------
// Action qualifier continuous SW force register bit definitions */
struct AQCSFRC_BITS
{                      // bits   description
    Uint16 CSFA : 2;   // 1:0    Continuous Software Force on output A
    Uint16 CSFB : 2;   // 3:2    Continuous Software Force on output B
    Uint16 rsvd1 : 12; // 15:4   reserved
};

union AQCSFRC_REG
{
    Uint16 all;
    struct AQCSFRC_BITS bit;
};

// As of version 1.1
// Changed the MODE bit-field to OUT_MODE
// Added the bit-field IN_MODE
// This corresponds to changes in silicon as of F2833x devices
// Rev A silicon.
//----------------------------------------------------
// Dead-band generator control register bit definitions
struct DBCTL_BITS
{                        // bits   description
    Uint16 OUT_MODE : 2; // 1:0    Dead Band Output Mode Control
    Uint16 POLSEL : 2;   // 3:2    Polarity Select Control
    Uint16 IN_MODE : 2;  // 5:4    Dead Band Input Select Mode Control
    Uint16 rsvd1 : 10;   // 15:4   reserved
};

union DBCTL_REG
{
    Uint16 all;
    struct DBCTL_BITS bit;
};

//----------------------------------------------------
// Trip zone select register bit definitions
struct TZSEL_BITS
{                     // bits   description
    Uint16 CBC1 : 1;  // 0      TZ1 CBC select
    Uint16 CBC2 : 1;  // 1      TZ2 CBC select
    Uint16 CBC3 : 1;  // 2      TZ3 CBC select
    Uint16 CBC4 : 1;  // 3      TZ4 CBC select
    Uint16 CBC5 : 1;  // 4      TZ5 CBC select
    Uint16 CBC6 : 1;  // 5      TZ6 CBC select
    Uint16 rsvd1 : 2; // 7:6    reserved
    Uint16 OSHT1 : 1; // 8      One-shot TZ1 select
    Uint16 OSHT2 : 1; // 9      One-shot TZ2 select
    Uint16 OSHT3 : 1; // 10     One-shot TZ3 select
    Uint16 OSHT4 : 1; // 11     One-shot TZ4 select
    Uint16 OSHT5 : 1; // 12     One-shot TZ5 select
    Uint16 OSHT6 : 1; // 13     One-shot TZ6 select
    Uint16 rsvd2 : 2; // 15:14  reserved
};

union TZSEL_REG
{
    Uint16 all;
    struct TZSEL_BITS bit;
};

//----------------------------------------------------
// Trip zone control register bit definitions */
struct TZCTL_BITS
{                     // bits   description
    Uint16 TZA : 2;   // 1:0    TZ1 to TZ6 Trip Action On EPWMxA
    Uint16 TZB : 2;   // 3:2    TZ1 to TZ6 Trip Action On EPWMxB
    Uint16 rsvd : 12; // 15:4   reserved
};

union TZCTL_REG
{
    Uint16 all;
    struct TZCTL_BITS bit;
};

//----------------------------------------------------
// Trip zone control register bit definitions */
struct TZEINT_BITS
{                      // bits   description
    Uint16 rsvd1 : 1;  // 0      reserved
    Uint16 CBC : 1;    // 1      Trip Zones Cycle By Cycle Int Enable
    Uint16 OST : 1;    // 2      Trip Zones One Shot Int Enable
    Uint16 rsvd2 : 13; // 15:3   reserved
};

union TZEINT_REG
{
    Uint16 all;
    struct TZEINT_BITS bit;
};

//----------------------------------------------------
// Trip zone flag register bit definitions */
struct TZFLG_BITS
{                      // bits   description
    Uint16 INT : 1;    // 0      Global status
    Uint16 CBC : 1;    // 1      Trip Zones Cycle By Cycle Int
    Uint16 OST : 1;    // 2      Trip Zones One Shot Int
    Uint16 rsvd2 : 13; // 15:3   reserved
};

union TZFLG_REG
{
    Uint16 all;
    struct TZFLG_BITS bit;
};

//----------------------------------------------------
// Trip zone flag clear register bit definitions */
struct TZCLR_BITS
{                      // bits   description
    Uint16 INT : 1;    // 0      Global status
    Uint16 CBC : 1;    // 1      Trip Zones Cycle By Cycle Int
    Uint16 OST : 1;    // 2      Trip Zones One Shot Int
    Uint16 rsvd2 : 13; // 15:3   reserved
};

union TZCLR_REG
{
    Uint16 all;
    struct TZCLR_BITS bit;
};

//----------------------------------------------------
// Trip zone flag force register bit definitions */
struct TZFRC_BITS
{                      // bits   description
    Uint16 rsvd1 : 1;  // 0      reserved
    Uint16 CBC : 1;    // 1      Trip Zones Cycle By Cycle Int
    Uint16 OST : 1;    // 2      Trip Zones One Shot Int
    Uint16 rsvd2 : 13; // 15:3   reserved
};

union TZFRC_REG
{
    Uint16 all;
    struct TZFRC_BITS bit;
};

//----------------------------------------------------
// Event trigger select register bit definitions */
struct ETSEL_BITS
{                       // bits   description
    Uint16 INTSEL : 3;  // 2:0    EPWMxINTn Select
    Uint16 INTEN : 1;   // 3      EPWMxINTn Enable
    Uint16 rsvd1 : 4;   // 7:4    reserved
    Uint16 SOCASEL : 3; // 10:8   Start of conversion A Select
    Uint16 SOCAEN : 1;  // 11     Start of conversion A Enable
    Uint16 SOCBSEL : 3; // 14:12  Start of conversion B Select
    Uint16 SOCBEN : 1;  // 15     Start of conversion B Enable
};

union ETSEL_REG
{
    Uint16 all;
    struct ETSEL_BITS bit;
};

//----------------------------------------------------
// Event trigger pre-scale register bit definitions */
struct ETPS_BITS
{                       // bits   description
    Uint16 INTPRD : 2;  // 1:0    EPWMxINTn Period Select
    Uint16 INTCNT : 2;  // 3:2    EPWMxINTn Counter Register
    Uint16 rsvd1 : 4;   // 7:4    reserved
    Uint16 SOCAPRD : 2; // 9:8    EPWMxSOCA Period Select
    Uint16 SOCACNT : 2; // 11:10  EPWMxSOCA Counter Register
    Uint16 SOCBPRD : 2; // 13:12  EPWMxSOCB Period Select
    Uint16 SOCBCNT : 2; // 15:14  EPWMxSOCB Counter Register
};

union ETPS_REG
{
    Uint16 all;
    struct ETPS_BITS bit;
};

//----------------------------------------------------
// Event trigger Flag register bit definitions */
struct ETFLG_BITS
{                      // bits   description
    Uint16 INT : 1;    // 0	EPWMxINTn Flag
    Uint16 rsvd1 : 1;  // 1	reserved
    Uint16 SOCA : 1;   // 2	EPWMxSOCA Flag
    Uint16 SOCB : 1;   // 3	EPWMxSOCB Flag
    Uint16 rsvd2 : 12; // 15:4	reserved
};

union ETFLG_REG
{
    Uint16 all;
    struct ETFLG_BITS bit;
};

//----------------------------------------------------
// Event trigger Clear register bit definitions */
struct ETCLR_BITS
{                      // bits   description
    Uint16 INT : 1;    // 0	EPWMxINTn Clear
    Uint16 rsvd1 : 1;  // 1	reserved
    Uint16 SOCA : 1;   // 2	EPWMxSOCA Clear
    Uint16 SOCB : 1;   // 3	EPWMxSOCB Clear
    Uint16 rsvd2 : 12; // 15:4	reserved
};

union ETCLR_REG
{
    Uint16 all;
    struct ETCLR_BITS bit;
};

//----------------------------------------------------
// Event trigger Force register bit definitions */
struct ETFRC_BITS
{                      // bits   description
    Uint16 INT : 1;    // 0	EPWMxINTn Force
    Uint16 rsvd1 : 1;  // 1	reserved
    Uint16 SOCA : 1;   // 2	EPWMxSOCA Force
    Uint16 SOCB : 1;   // 3	EPWMxSOCB Force
    Uint16 rsvd2 : 12; // 15:4	reserved
};

union ETFRC_REG
{
    Uint16 all;
    struct ETFRC_BITS bit;
};
//----------------------------------------------------
// PWM chopper control register bit definitions */
struct PCCTL_BITS
{                       // bits   description
    Uint16 CHPEN : 1;   // 0      PWM chopping enable
    Uint16 OSHTWTH : 4; // 4:1    One-shot pulse width
    Uint16 CHPFREQ : 3; // 7:5    Chopping clock frequency
    Uint16 CHPDUTY : 3; // 10:8   Chopping clock Duty cycle
    Uint16 rsvd1 : 5;   // 15:11  reserved
};

union PCCTL_REG
{
    Uint16 all;
    struct PCCTL_BITS bit;
};

struct HRCNFG_BITS
{                       // bits   description
    Uint16 EDGMODE : 2; // 1:0    Edge Mode select Bits
    Uint16 CTLMODE : 1; // 2      Control mode Select Bit
    Uint16 HRLOAD : 1;  // 3      Shadow mode Select Bit
    Uint16 rsvd1 : 12;  // 15:4   reserved
};

union HRCNFG_REG
{
    Uint16 all;
    struct HRCNFG_BITS bit;
};

struct TBPHS_HRPWM_REG
{                   // bits   description
    Uint16 TBPHSHR; // 15:0   Extension register for HRPWM Phase (8 bits)
    Uint16 TBPHS;   // 31:16  Phase offset register
};

union TBPHS_HRPWM_GROUP
{
    Uint32 all;
    struct TBPHS_HRPWM_REG half;
};

struct CMPA_HRPWM_REG
{                  // bits   description
    Uint16 CMPAHR; // 15:0   Extension register for HRPWM compare (8 bits)
    Uint16 CMPA;   // 31:16  Compare A reg
};

union CMPA_HRPWM_GROUP
{
    Uint32 all;
    struct CMPA_HRPWM_REG half;
};

typedef struct _PWM_Obj_
{
    union TBCTL_REG TBCTL;         //
    union TBSTS_REG TBSTS;         //
    union TBPHS_HRPWM_GROUP TBPHS; // Union of TBPHS:TBPHSHR
    Uint16 TBCTR;                  // Counter
    Uint16 TBPRD;                  // Period register set
    Uint16 rsvd1;                  //
    union CMPCTL_REG CMPCTL;       // Compare control
    union CMPA_HRPWM_GROUP CMPA;   // Union of CMPA:CMPAHR
    Uint16 CMPB;                   // Compare B reg
    union AQCTL_REG AQCTLA;        // Action qual output A
    union AQCTL_REG AQCTLB;        // Action qual output B
    union AQSFRC_REG AQSFRC;       // Action qual SW force
    union AQCSFRC_REG AQCSFRC;     // Action qualifier continuous SW force
    union DBCTL_REG DBCTL;         // Dead-band control
    Uint16 DBRED;                  // Dead-band rising edge delay
    Uint16 DBFED;                  // Dead-band falling edge delay
    union TZSEL_REG TZSEL;         // Trip zone select
    Uint16 rsvd2;
    union TZCTL_REG TZCTL;   // Trip zone control
    union TZEINT_REG TZEINT; // Trip zone interrupt enable
    union TZFLG_REG TZFLG;   // Trip zone interrupt flags
    union TZCLR_REG TZCLR;   // Trip zone clear
    union TZFRC_REG TZFRC;   // Trip zone force interrupt
    union ETSEL_REG ETSEL;   // Event trigger selection
    union ETPS_REG ETPS;     // Event trigger pre-scaler
    union ETFLG_REG ETFLG;   // Event trigger flags
    union ETCLR_REG ETCLR;   // Event trigger clear
    union ETFRC_REG ETFRC;   // Event trigger force
    union PCCTL_REG PCCTL;   // PWM chopper control
    Uint16 rsvd3;            //
    union HRCNFG_REG HRCNFG; // HRPWM Config Reg
} PWM_Obj;

//! \brief pwm操作句柄
//!
typedef struct _PWM_Obj_ *PWM_Handle;


// **************************************************************************
// the globals

// **************************************************************************
// the function prototypes


extern PWM_Handle PWM_init(void *pMemory, const size_t numBytes);

//! \brief     Clears the pulse width modulation (PWM) interrupt flag
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
static inline void PWM_clearIntFlag(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    // set the bits
    pwm->ETCLR = PWM_ETCLR_INT_BITS;

    return;
} // end of PWM_clearIntFlag() function

//! \brief     Clears the pulse width modulation (PWM) one shot trip
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
static inline void PWM_clearOneShotTrip(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pwm->TZCLR = PWM_TZCLR_OST_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_clearOneShotTrip() function

//! \brief     Clears the pulse width modulation (PWM) start of conversion (SOC) A flag
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
static inline void PWM_clearSocAFlag(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    // set the bits
    pwm->ETCLR = PWM_ETCLR_SOCA_BITS;

    return;
} // end of PWM_clearSocAFlag() function

//! \brief     Clears the pulse width modulation (PWM) start of conversion (SOC) B flag
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
static inline void PWM_clearSocBFlag(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    // set the bits
    pwm->ETCLR = PWM_ETCLR_SOCB_BITS;

    return;
} // end of PWM_clearSocBFlag() function

//! \brief     Clears the trip zone (TZ) flag specified
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] tripZoneFlag  The trip zone flag to clear
extern void PWM_clearTripZone(PWM_Handle pwmHandle, const PWM_TripZoneFlag_e tripZoneFlag);

//! \brief     Decrement the dead band falling edge delay
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_decrementDeadBandFallingEdgeDelay(PWM_Handle pwmHandle);

//! \brief     Decrement the dead band rising edge delay
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_decrementDeadBandRisingEdgeDelay(PWM_Handle pwmHandle);

//! \brief     Disables auto conversion of delay line value
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_disableAutoConvert(PWM_Handle pwmHandle);

//! \brief     Disables the pulse width modulation (PWM) chopping
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_disableChopping(PWM_Handle pwmHandle);

//! \brief     Disables the pulse width modulation (PWM) counter loading from the phase register
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_disableCounterLoad(PWM_Handle pwmHandle);

//! \brief     Disables the pulse width modulation (PWM) deadband
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_disableDeadBand(PWM_Handle pwmHandle);

//! \brief     Disables the pulse width modulation (PWM) deadband half cycle clocking
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_disableDeadBandHalfCycle(PWM_Handle pwmHandle);

//! \brief     Disables the pulse width modulation (PWM) digital compare blanking window
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_disableDigitalCompareBlankingWindow(PWM_Handle pwmHandle);

//! \brief     Disables the pulse width modulation (PWM) digital compare blanking window inversion
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_disableDigitalCompareBlankingWindowInversion(PWM_Handle pwmHandle);

//! \brief     Disables high resolution period control
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_disableHrPeriod(PWM_Handle pwmHandle);

//! \brief     Disables high resolution phase synchronization
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_disableHrPhaseSync(PWM_Handle pwmHandle);

//! \brief     Disables the pulse width modulation (PWM) interrupt
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_disableInt(PWM_Handle pwmHandle);

//! \brief     Disables the pulse width modulation (PWM) start of conversion (SOC) B pulse generation
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_disableSocAPulse(PWM_Handle pwmHandle);

//! \brief     Disables the pulse width modulation (PWM) start of conversion (SOC) B pulse generation
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_disableSocBPulse(PWM_Handle pwmHandle);

//! \brief     Disables the pulse width modulation (PWM) trip zones
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_disableTripZones(PWM_Handle pwmHandle);

//! \brief     Disables the pulse width modulation (PWM) trip zones interrupts
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] interrupt  The interrupt source to disable
extern void PWM_disableTripZoneInt(PWM_Handle pwmHandle, const PWM_TripZoneFlag_e interruptSource);

//! \brief     Disable the pulse width modulation (PWM) trip zone source
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] src        The pulse width modulation (PWM) trip zone source
extern void PWM_disableTripZoneSrc(PWM_Handle pwmHandle, const PWM_TripZoneSrc_e src);

//! \brief     Enables auto conversion of delay line value
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_enableAutoConvert(PWM_Handle pwmHandle);

//! \brief     Enables the pulse width modulation (PWM) chopping
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_enableChopping(PWM_Handle pwmHandle);

//! \brief     Enables the pulse width modulation (PWM) counter loading from the phase register
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_enableCounterLoad(PWM_Handle pwmHandle);

//! \brief     Enables the pulse width modulation (PWM) deadband half cycle clocking
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_enableDeadBandHalfCycle(PWM_Handle pwmHandle);

//! \brief     Enables the pulse width modulation (PWM) digital compare blanking window
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_enableDigitalCompareBlankingWindow(PWM_Handle pwmHandle);

//! \brief     Enables the pulse width modulation (PWM) digital compare blanking window inversion
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_enableDigitalCompareBlankingWindowInversion(PWM_Handle pwmHandle);

//! \brief     Enables high resolution period control
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_enableHrPeriod(PWM_Handle pwmHandle);

//! \brief     Enables high resolution phase synchronization
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_enableHrPhaseSync(PWM_Handle pwmHandle);

//! \brief     Enables the pulse width modulation (PWM) interrupt
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_enableInt(PWM_Handle pwmHandle);

//! \brief     Enables the pulse width modulation (PWM) start of conversion (SOC) A pulse generation
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_enableSocAPulse(PWM_Handle pwmHandle);

//! \brief     Enables the pulse width modulation (PWM) start of conversion (SOC) B pulse generation
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_enableSocBPulse(PWM_Handle pwmHandle);

//! \brief     Enables the pulse width modulation (PWM) trip zones interrupts
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] interrupt  The interrupt source to enable
extern void PWM_enableTripZoneInt(PWM_Handle pwmHandle, const PWM_TripZoneFlag_e interruptSource);

//! \brief     Enable the pulse width modulation (PWM) trip zone source
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] src        The pulse width modulation (PWM) trip zone source
extern void PWM_enableTripZoneSrc(PWM_Handle pwmHandle, const PWM_TripZoneSrc_e src);

//! \brief     Gets the value of the Counter Compare A hardware
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \return    The CMPA value
static inline uint16_t PWM_get_CmpA(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    return pwm->CMPA;
} // end of PWM_get_CmpA() function

//! \brief     Gets the value of the Counter Compare A Mirror Register
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \return    The CMPAM value
static inline uint16_t PWM_get_CmpAM(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    return pwm->CMPAM;
} // end of PWM_get_CmpAM() function

//! \brief     Gets the value of the Counter Compare B hardware
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \return    The CMPB value
static inline uint16_t PWM_get_CmpB(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    return pwm->CMPB;
} // end of PWM_get_CmpB() function

//! \brief     Force Synchronization
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
static inline void PWM_forceSync(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->TBCTL |= PWM_TBCTL_SWFSYNC_BITS;

    return;
} // end of PWM_forceSync() function

//! \brief     Gets the pulse width modulation (PWM) deadband falling edge delay
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \return    The delay
extern uint16_t PWM_getDeadBandFallingEdgeDelay(PWM_Handle pwmHandle);

//! \brief     Gets the pulse width modulation (PWM) deadband rising edge delay
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \return    The delay
extern uint16_t PWM_getDeadBandRisingEdgeDelay(PWM_Handle pwmHandle);

//! \brief     Gets the pulse width modulation (PWM) interrupt event count
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \return    The interrupt event count
extern uint16_t PWM_getIntCount(PWM_Handle pwmHandle);

//! \brief     Gets the pulse width modulation (PWM) period value
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \return    The pwm period value
static inline uint16_t PWM_getPeriod(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    return (pwm->TBPRD);
} // end of PWM_getPeriod() function

//! \brief     Gets the pulse width modulation (PWM) data value from the Counter Compare A hardware
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \return    The PWM compare data value
static inline uint16_t PWM_getCmpA(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    return (pwm->CMPA);
} // end of PWM_getCmpA() function

//! \brief     Gets the pulse width modulation (PWM) data value from the Counter Compare A  Hr hardware
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \return    The PWM compare high resolution data value
static inline uint16_t PWM_getCmpAHr(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    return (pwm->CMPAHR);
} // end of PWM_getCmpAHr() function

//! \brief     Gets the pulse width modulation (PWM) data value from the Counter Compare B hardware
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \return    The PWM compare data value
static inline uint16_t PWM_getCmpB(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    return (pwm->CMPB);
} // end of PWM_getCmpB() function

//! \brief     Gets the pulse width modulation (PWM) start of conversion (SOC) A count
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \return    The SOC A count
extern uint16_t PWM_getSocACount(PWM_Handle pwmHandle);

//! \brief     Gets the pulse width modulation (PWM) start of conversion (SOC) B count
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \return    The SOC B count
extern uint16_t PWM_getSocBCount(PWM_Handle pwmHandle);

//! \brief     Set the High Resolution Control Mode
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] edgeMode   The control mode HRPWM should use
extern void PWM_setHrControlMode(PWM_Handle pwmHandle, const PWM_HrControlMode_e controlMode);

//! \brief     Set the High Resolution Edge Mode
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] edgeMode   The edge mode HRPWM should use
extern void PWM_setHrEdgeMode(PWM_Handle pwmHandle, const PWM_HrEdgeMode_e edgeMode);

//! \brief     Set the High Resolution Shadow Load Mode
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] edgeMode   The shadow load mode HRPWM should use
extern void PWM_setHrShadowMode(PWM_Handle pwmHandle, const PWM_HrShadowMode_e shadowMode);

//! \brief     Increment the dead band falling edge delay
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_incrementDeadBandFallingEdgeDelay(PWM_Handle pwmHandle);

//! \brief     Increment the dead band rising edge delay
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
extern void PWM_incrementDeadBandRisingEdgeDelay(PWM_Handle pwmHandle);



//! \brief     Sets the pulse width modulation (PWM) object action for PWM A when the counter equals CMPA and the counter is decrementing
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
extern void PWM_setActionQual_CntDown_CmpA_PwmA(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual);

//! \brief     Sets the pulse width modulation (PWM) object action for PWM B when the counter equals CMPA and the counter is decrementing
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
extern void PWM_setActionQual_CntDown_CmpA_PwmB(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual);

//! \brief     Sets the pulse width modulation (PWM) object action for PWM A when the counter equals CMPB and the counter is decrementing
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
extern void PWM_setActionQual_CntDown_CmpB_PwmA(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual);

//! \brief     Sets the pulse width modulation (PWM) object action for PWM B when the counter equals CMPB and the counter is decrementing
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
extern void PWM_setActionQual_CntDown_CmpB_PwmB(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual);

//! \brief     Sets the pulse width modulation (PWM) object action for PWM A when the counter equals CMPA and the counter is incrementing
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
extern void PWM_setActionQual_CntUp_CmpA_PwmA(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual);

//! \brief     Sets the pulse width modulation (PWM) object action for PWM B when the counter equals CMPA and the counter is incrementing
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
extern void PWM_setActionQual_CntUp_CmpA_PwmB(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual);

//! \brief     Sets the pulse width modulation (PWM) object action for PWM A when the counter equals CMPB and the counter is incrementing
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
extern void PWM_setActionQual_CntUp_CmpB_PwmA(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual);

//! \brief     Sets the pulse width modulation (PWM) object action for PWM B when the counter equals CMPB and the counter is incrementing
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
extern void PWM_setActionQual_CntUp_CmpB_PwmB(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual);

//! \brief     Sets the pulse width modulation (PWM) object Continuous Software Force action for PWM A
//! \param[in] pwmHandle              The pulse width modulation (PWM) object handle
//! \param[in] actionQualContSWForce  The action qualifier continuous software force
extern void PWM_setActionQualContSWForce_PwmA(PWM_Handle pwmHandle,
                                              const PWM_ActionQualContSWForce_e actionQualContSWForce);

//! \brief     Sets the pulse width modulation (PWM) object Continuous Software Force action for PWM B
//! \param[in] pwmHandle              The pulse width modulation (PWM) object handle
//! \param[in] actionQualContSWForce  The action qualifier continuous software force
extern void PWM_setActionQualContSWForce_PwmB(PWM_Handle pwmHandle,
                                              const PWM_ActionQualContSWForce_e actionQualContSWForce);

//! \brief     Sets the pulse width modulation (PWM) object action for PWM A when the counter equals the period
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
extern void PWM_setActionQual_Period_PwmA(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual);

//! \brief     Sets the pulse width modulation (PWM) object action for PWM B when the counter equals the period
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
extern void PWM_setActionQual_Period_PwmB(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual);

//! \brief     Sets the pulse width modulation (PWM) object action for PWM A when the counter equals the zero
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
extern void PWM_setActionQual_Zero_PwmA(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual);

//! \brief     Sets the pulse width modulation (PWM) object action for PWM B when the counter equals the zero
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] actionQual  The action qualifier
extern void PWM_setActionQual_Zero_PwmB(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual);

//! \brief     Sets the pulse width modulation (PWM) chopping clock frequency
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] clkFreq    The clock frequency
extern void PWM_setChoppingClkFreq(PWM_Handle pwmHandle, const PWM_ChoppingClkFreq_e clkFreq);

//! \brief     Sets the pulse width modulation (PWM) chopping clock duty cycle
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] dutyCycle  The duty cycle
extern void PWM_setChoppingDutyCycle(PWM_Handle pwmHandle, const PWM_ChoppingDutyCycle_e dutyCycle);

//! \brief     Sets the pulse width modulation (PWM) chopping clock pulse width
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] pulseWidth  The pulse width
extern void PWM_setChoppingPulseWidth(PWM_Handle pwmHandle, const PWM_ChoppingPulseWidth_e pulseWidth);

//! \brief     Sets the pulse width modulation (PWM) clock divisor
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] clkDiv     The clock divisor
extern void PWM_setClkDiv(PWM_Handle pwmHandle, const PWM_ClkDiv_e clkDiv);

//! \brief     Sets the pulse width modulation (PWM) count
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] count      The count
extern void PWM_setCount(PWM_Handle pwmHandle, const uint16_t count);

//! \brief     Sets the pulse width modulation (PWM) counter mode
//! \param[in] pwmHandle    The pulse width modulation (PWM) object handle
//! \param[in] counterMode  The count mode
extern void PWM_setCounterMode(PWM_Handle pwmHandle, const PWM_CounterMode_e counterMode);

//! \brief     Sets the pulse width modulation (PWM) deadband falling edge delay
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] delay      The delay
extern void PWM_setDeadBandFallingEdgeDelay(PWM_Handle pwmHandle, const uint16_t delay);

//! \brief     Sets the pulse width modulation (PWM) deadband input mode
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] inputMode  The input mode
extern void PWM_setDeadBandInputMode(PWM_Handle pwmHandle, const PWM_DeadBandInputMode_e inputMode);

//! \brief     Sets the pulse width modulation (PWM) deadband output mode
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] outputMode  The output mode
extern void PWM_setDeadBandOutputMode(PWM_Handle pwmHandle, const PWM_DeadBandOutputMode_e outputMode);

//! \brief     Sets the pulse width modulation (PWM) deadband polarity
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] polarity   The polarity
extern void PWM_setDeadBandPolarity(PWM_Handle pwmHandle, const PWM_DeadBandPolarity_e polarity);

//! \brief     Sets the pulse width modulation (PWM) deadband rising edge delay
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] delay      The delay
extern void PWM_setDeadBandRisingEdgeDelay(PWM_Handle pwmHandle, const uint16_t delay);

//! \brief     Sets the pulse width modulation (PWM) digital compare filter source
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] input      The filter's source
extern void PWM_setDigitalCompareFilterSource(PWM_Handle pwmHandle,
                                              const PWM_DigitalCompare_FilterSrc_e input);

//! \brief     Sets the pulse width modulation (PWM) digital compare blanking pulse
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] input      The pulse selection
extern void PWM_setDigitalCompareBlankingPulse(PWM_Handle pwmHandle,
                                               const PWM_DigitalCompare_PulseSel_e pulseSelect);

//! \brief     Sets the pulse width modulation (PWM) digital compare filter offset
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] offset     The offset
extern void PWM_setDigitalCompareFilterOffset(PWM_Handle pwmHandle,
                                              const uint16_t offset);

//! \brief     Sets the pulse width modulation (PWM) digital compare filter offset
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] window     The window
extern void PWM_setDigitalCompareFilterWindow(PWM_Handle pwmHandle,
                                              const uint16_t window);

//! \brief     Sets the pulse width modulation (PWM) digital compare input
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] input      Comparator input to change
//! \param[in] inputSel   Input selection for designated input
extern void PWM_setDigitalCompareInput(PWM_Handle pwmHandle,
                                       const PWM_DigitalCompare_Input_e input,
                                       const PWM_DigitalCompare_InputSel_e inputSel);

//! \brief     Sets the pulse width modulation (PWM) digital compare A event 1 source parameters
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] selectFilter   Select filter output if true
//! \param[in] disableSync    Asynchronous if true
//! \param[in] enableSoc      Enable SOC generation if true
//! \param[in] generateSync   Generate SYNC if true
extern void PWM_setDigitalCompareAEvent1(PWM_Handle pwmHandle,
                                         const bool selectFilter,
                                         const bool disableSync,
                                         const bool enableSoc,
                                         const bool generateSync);

//! \brief     Sets the pulse width modulation (PWM) digital compare A event 2 source parameters
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] selectFilter   Select filter output if true
//! \param[in] disableSync    Asynchronous if true
extern void PWM_setDigitalCompareAEvent2(PWM_Handle pwmHandle,
                                         const bool selectFilter,
                                         const bool disableSync);

//! \brief     Sets the pulse width modulation (PWM) digital compare B event 1 source parameters
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] selectFilter   Select filter output if true
//! \param[in] disableSync    Asynchronous if true
//! \param[in] enableSoc      Enable SOC generation if true
//! \param[in] generateSync   Generate SYNC if true
extern void PWM_setDigitalCompareBEvent1(PWM_Handle pwmHandle,
                                         const bool selectFilter,
                                         const bool disableSync,
                                         const bool enableSoc,
                                         const bool generateSync);

//! \brief     Sets the pulse width modulation (PWM) digital compare B event 2 source parameters
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] selectFilter   Select filter output if true
//! \param[in] disableSync    Asynchronous if true
extern void PWM_setDigitalCompareBEvent2(PWM_Handle pwmHandle,
                                         const bool selectFilter,
                                         const bool disableSync);

//! \brief     Sets the pulse width modulation (PWM) high speed clock divisor
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] clkDiv     The clock divisor
extern void PWM_setHighSpeedClkDiv(PWM_Handle pwmHandle, const PWM_HspClkDiv_e clkDiv);

//! \brief     Sets the pulse width modulation (PWM) interrupt mode
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] intMode    The interrupt mode
extern void PWM_setIntMode(PWM_Handle pwmHandle, const PWM_IntMode_e intMode);

//! \brief     Sets the pulse width modulation (PWM) interrupt period
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] intPeriod  The interrupt period
extern void PWM_setIntPeriod(PWM_Handle pwmHandle, const PWM_IntPeriod_e intPeriod);

//! \brief     Sets the pulse width modulation (PWM) load mode for CMPA
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] loadMode   The load mode
extern void PWM_setLoadMode_CmpA(PWM_Handle pwmHandle, const PWM_LoadMode_e loadMode);

//! \brief     Sets the pulse width modulation (PWM) load mode for CMPB
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] loadMode   The load mode
extern void PWM_setLoadMode_CmpB(PWM_Handle pwmHandle, const PWM_LoadMode_e loadMode);

//! \brief     Sets the pulse width modulation (PWM) period load mode
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] periodLoad  The period load mode
extern void PWM_setPeriodLoad(PWM_Handle pwmHandle, const PWM_PeriodLoad_e periodLoad);

//! \brief     Sets the pulse width modulation (PWM) one shot trip
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
static inline void PWM_setOneShotTrip(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pwm->TZFRC |= PWM_TZFRC_OST_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_setOneShotTrip() function

//! \brief     Sets the pulse width modulation (PWM) period
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] period     The period
extern void PWM_setPeriod(PWM_Handle pwmHandle, const uint16_t period);

//! \brief     Sets the pulse width modulation (PWM) high resolution period
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] period     The period
extern void PWM_setPeriodHr(PWM_Handle pwmHandle, const uint16_t period);

//! \brief     Sets the pulse width modulation (PWM) phase
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] phase      The phase
extern void PWM_setPhase(PWM_Handle pwmHandle, const uint16_t phase);

//! \brief     Sets the pulse width modulation (PWM) phase direction
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] phaseDir   The phase direction
extern void PWM_setPhaseDir(PWM_Handle pwmHandle, const PWM_PhaseDir_e phaseDir);

//! \brief     Sets the pulse width modulation (PWM) run mode
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] runMode    The run mode
extern void PWM_setRunMode(PWM_Handle pwmHandle, const PWM_RunMode_e runMode);

//! \brief     Sets the pulse width modulation (PWM) start of conversion (SOC) A interrupt period
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] intPeriod  The interrupt period
extern void PWM_setSocAPeriod(PWM_Handle pwmHandle, const PWM_SocPeriod_e intPeriod);

//! \brief     Sets the pulse width modulation (PWM) start of conversion (SOC) A interrupt pulse source
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] pulseSrc   The interrupt pulse source
extern void PWM_setSocAPulseSrc(PWM_Handle pwmHandle, const PWM_SocPulseSrc_e pulseSrc);

//! \brief     Sets the pulse width modulation (PWM) start of conversion (SOC) B interrupt period
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] intPeriod  The interrupt period
extern void PWM_setSocBPeriod(PWM_Handle pwmHandle, const PWM_SocPeriod_e intPeriod);

//! \brief     Sets the pulse width modulation (PWM) start of conversion (SOC) B interrupt pulse source
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] pulseSrc   The interrupt pulse source
extern void PWM_setSocBPulseSrc(PWM_Handle pwmHandle, const PWM_SocPulseSrc_e pulseSrc);

//! \brief     Sets the pulse width modulation (PWM) shadow mode for CMPA
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] shadowMode  The shadow mode
extern void PWM_setShadowMode_CmpA(PWM_Handle pwmHandle, const PWM_ShadowMode_e shadowMode);

//! \brief     Sets the pulse width modulation (PWM) shadow mode for CMPB
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
//! \param[in] shadowMode  The shadow mode
extern void PWM_setShadowMode_CmpB(PWM_Handle pwmHandle, const PWM_ShadowMode_e shadowMode);

//! \brief     Sets the pulse width modulation (PWM) software sync
//! \param[in] pwmHandle   The pulse width modulation (PWM) object handle
extern void PWM_setSwSync(PWM_Handle pwmHandle);

//! \brief     Sets the pulse width modulation (PWM) sync mode
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] syncMode   The sync mode
extern void PWM_setSyncMode(PWM_Handle pwmHandle, const PWM_SyncMode_e syncMode);

//! \brief     Sets the pulse width modulation (PWM) trip zone digital compare event select for Digital Compare Output A Event 1 (DCAEVT1)
//! \param[in] pwmHandle      The pulse width modulation (PWM) object handle
//! \param[in] tripZoneEvent  The trip zone digital compare event
extern void PWM_setTripZoneDCEventSelect_DCAEVT1(PWM_Handle pwmHandle, const PWM_TripZoneDCEventSel_e tripZoneEvent);

//! \brief     Sets the pulse width modulation (PWM) trip zone digital compare event select for Digital Compare Output A Event 2 (DCAEVT2)
//! \param[in] pwmHandle      The pulse width modulation (PWM) object handle
//! \param[in] tripZoneEvent  The trip zone digital compare event
extern void PWM_setTripZoneDCEventSelect_DCAEVT2(PWM_Handle pwmHandle, const PWM_TripZoneDCEventSel_e tripZoneEvent);

//! \brief     Sets the pulse width modulation (PWM) trip zone digital compare event select for Digital Compare Output B Event 1 (DCBEVT1)
//! \param[in] pwmHandle      The pulse width modulation (PWM) object handle
//! \param[in] tripZoneEvent  The trip zone digital compare event
extern void PWM_setTripZoneDCEventSelect_DCBEVT1(PWM_Handle pwmHandle, const PWM_TripZoneDCEventSel_e tripZoneEvent);

//! \brief     Sets the pulse width modulation (PWM) trip zone digital compare event select for Digital Compare Output B Event 2 (DCBEVT2)
//! \param[in] pwmHandle      The pulse width modulation (PWM) object handle
//! \param[in] tripZoneEvent  The trip zone digital compare event
extern void PWM_setTripZoneDCEventSelect_DCBEVT2(PWM_Handle pwmHandle, const PWM_TripZoneDCEventSel_e tripZoneEvent);

//! \brief     Sets the pulse width modulation (PWM) trip zone state for Digital Compare Output A Event 1 (DCAEVT1)
//! \param[in] pwmHandle      The pulse width modulation (PWM) object handle
//! \param[in] tripZoneState  The trip zone state
extern void PWM_setTripZoneState_DCAEVT1(PWM_Handle pwmHandle, const PWM_TripZoneState_e tripZoneState);

//! \brief     Sets the pulse width modulation (PWM) trip zone state for Digital Compare Output A Event 2 (DCAEVT1)
//! \param[in] pwmHandle      The pulse width modulation (PWM) object handle
//! \param[in] tripZoneState  The trip zone state
extern void PWM_setTripZoneState_DCAEVT2(PWM_Handle pwmHandle, const PWM_TripZoneState_e tripZoneState);

//! \brief     Sets the pulse width modulation (PWM) trip zone state for Digital Compare Output B Event 1 (DCBEVT1)
//! \param[in] pwmHandle      The pulse width modulation (PWM) object handle
//! \param[in] tripZoneState  The trip zone state
extern void PWM_setTripZoneState_DCBEVT1(PWM_Handle pwmHandle, const PWM_TripZoneState_e tripZoneState);

//! \brief     Sets the pulse width modulation (PWM) trip zone state for Digital Compare Output B Event 2 (DCBEVT1)
//! \param[in] pwmHandle      The pulse width modulation (PWM) object handle
//! \param[in] tripZoneState  The trip zone state
extern void PWM_setTripZoneState_DCBEVT2(PWM_Handle pwmHandle, const PWM_TripZoneState_e tripZoneState);

//! \brief     Sets the pulse width modulation (PWM) trip zone state for Output A (TZA)
//! \param[in] pwmHandle      The pulse width modulation (PWM) object handle
//! \param[in] tripZoneState  The trip zone state
extern void PWM_setTripZoneState_TZA(PWM_Handle pwmHandle, const PWM_TripZoneState_e tripZoneState);

//! \brief     Sets the pulse width modulation (PWM) trip zone state for Output B (TZB)
//! \param[in] pwmHandle      The pulse width modulation (PWM) object handle
//! \param[in] tripZoneState  The trip zone state
extern void PWM_setTripZoneState_TZB(PWM_Handle pwmHandle, const PWM_TripZoneState_e tripZoneState);

//! \brief     Writes the pulse width modulation (PWM) data value to the Counter Compare A hardware
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] pwmData    The PWM data value
static inline void PWM_write_CmpA(PWM_Handle pwmHandle, const uint16_t pwmData)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->CMPA = pwmData;

    return;
} // end of PWM_write_CmpA() function

//! \brief     Writes the pulse width modulation (PWM) data value to the Counter Compare A hardware
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] pwmData    The PWM data value
static inline void PWM_setCmpA(PWM_Handle pwmHandle, const uint16_t pwmData)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->CMPA = pwmData;

    return;
} // end of PWM_setCmpA() function

//! \brief     Writes the pulse width modulation (PWM) data value to the Counter Compare A Hr hardware
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] pwmData    The PWM high resolution data value
static inline void PWM_setCmpAHr(PWM_Handle pwmHandle, const uint16_t pwmData)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->CMPAHR = pwmData;

    return;
} // end of PWM_setCmpAHr() function

//! \brief     Writes the pulse width modulation (PWM) data value to the Counter Compare B hardware
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] pwmData    The PWM data value
static inline void PWM_write_CmpB(PWM_Handle pwmHandle, const uint16_t pwmData)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->CMPB = pwmData;

    return;
} // end of PWM_write_CmpB() function

//! \brief     Writes the pulse width modulation (PWM) data value to the Counter Compare B hardware
//! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
//! \param[in] pwmData    The PWM data value
static inline void PWM_setCmpB(PWM_Handle pwmHandle, const uint16_t pwmData)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->CMPB = pwmData;

    return;
} // end of PWM_setCmpB() function

#ifdef __cplusplus
}
#endif // extern "C"

//@} // ingroup
#endif // end of _PWM_H_ definition
