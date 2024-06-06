
//! @FilePath: \F28335_MotCtl_Frameware\DSP28xx_MotCtl_Frameware\MotCtl_Driver\Include\pwm.h
//! @Author: Hex
//! @Date: 2023-08-20 21:25:26
//! @LastEditTime: 2024-06-03 22:32:04
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

#define PWM_ePWM5_BASE_ADDR          (0x00006900)

#define PWM_ePWM6_BASE_ADDR          (0x00006940)



//! \brief PWM序号
typedef enum
{
    PWM_Number_1=0,
    PWM_Number_2,
    PWM_Number_3,
    PWM_Number_4,
    PWM_Number_5,
    PWM_Number_6,
} PWM_Number_e;

// TBCTL (Time-Base Control)
//==========================
// CTRMODE bits
#define	TB_COUNT_UP		0x0
#define	TB_COUNT_DOWN	0x1
#define	TB_COUNT_UPDOWN	0x2
#define	TB_FREEZE		0x3
// PHSEN bit
#define	TB_DISABLE		0x0
#define	TB_ENABLE		0x1
// PRDLD bit
#define	TB_SHADOW		0x0
#define	TB_IMMEDIATE	0x1
// SYNCOSEL bits
#define	TB_SYNC_IN		0x0
#define	TB_CTR_ZERO		0x1
#define	TB_CTR_CMPB		0x2
#define	TB_SYNC_DISABLE	0x3
// HSPCLKDIV and CLKDIV bits
#define	TB_DIV1			0x0
#define	TB_DIV2			0x1
#define	TB_DIV4			0x2
// PHSDIR bit
#define	TB_DOWN			0x0
#define	TB_UP			0x1

// CMPCTL (Compare Control)
//==========================
// LOADAMODE and LOADBMODE bits
#define	CC_CTR_ZERO		0x0
#define	CC_CTR_PRD		0x1
#define	CC_CTR_ZERO_PRD	0x2
#define	CC_LD_DISABLE	0x3
// SHDWAMODE and SHDWBMODE bits
#define	CC_SHADOW		0x0
#define	CC_IMMEDIATE	0x1

// AQCTLA and AQCTLB (Action Qualifier Control)
//=============================================
// ZRO, PRD, CAU, CAD, CBU, CBD bits
#define	AQ_NO_ACTION	0x0
#define	AQ_CLEAR		0x1
#define	AQ_SET			0x2
#define	AQ_TOGGLE		0x3

// DBCTL (Dead-Band Control)
//==========================
// OUT MODE bits
#define	DB_DISABLE		0x0
#define	DBA_ENABLE		0x1
#define	DBB_ENABLE		0x2
#define	DB_FULL_ENABLE	0x3
// POLSEL bits
#define	DB_ACTV_HI		0x0
#define	DB_ACTV_LOC		0x1
#define	DB_ACTV_HIC		0x2
#define	DB_ACTV_LO		0x3
// IN MODE
#define DBA_ALL         0x0
#define DBB_RED_DBA_FED 0x1
#define DBA_RED_DBB_FED 0x2
#define DBB_ALL         0x3

// CHPCTL (chopper control)
//==========================
// CHPEN bit
#define	CHP_DISABLE		0x0
#define	CHP_ENABLE		0x1
// CHPFREQ bits
#define	CHP_DIV1		0x0
#define	CHP_DIV2		0x1
#define	CHP_DIV3		0x2
#define	CHP_DIV4		0x3
#define	CHP_DIV5		0x4
#define	CHP_DIV6		0x5
#define	CHP_DIV7		0x6
#define	CHP_DIV8		0x7
// CHPDUTY bits
#define	CHP1_8TH		0x0
#define	CHP2_8TH		0x1
#define	CHP3_8TH		0x2
#define	CHP4_8TH		0x3
#define	CHP5_8TH		0x4
#define	CHP6_8TH		0x5
#define	CHP7_8TH		0x6

// TZSEL (Trip Zone Select)
//==========================
// CBCn and OSHTn bits
#define	TZ_DISABLE		0x0
#define	TZ_ENABLE		0x1

// TZCTL (Trip Zone Control)
//==========================
// TZA and TZB bits
#define	TZ_HIZ			0x0
#define	TZ_FORCE_HI		0x1
#define	TZ_FORCE_LO		0x2
#define	TZ_NO_CHANGE	0x3

// ETSEL (Event Trigger Select)
//=============================
#define	ET_CTR_ZERO		0x1
#define	ET_CTR_PRD		0x2
#define	ET_CTRU_CMPA	0x4
#define	ET_CTRD_CMPA	0x5
#define	ET_CTRU_CMPB	0x6
#define	ET_CTRD_CMPB	0x7

// ETPS (Event Trigger Pre-scale)
//===============================
// INTPRD, SOCAPRD, SOCBPRD bits
#define	ET_DISABLE		0x0
#define	ET_1ST			0x1
#define	ET_2ND			0x2
#define	ET_3RD			0x3


//--------------------------------
// HRPWM (High Resolution PWM)
//================================
// HRCNFG
#define	HR_Disable		0x0
#define	HR_REP			0x1
#define	HR_FEP			0x2
#define	HR_BEP			0x3

#define	HR_CMP			0x0
#define	HR_PHS			0x1

#define	HR_CTR_ZERO		0x0
#define	HR_CTR_PRD		0x1


typedef enum
{
    PWM_CounterMode_Up=0,
    PWM_Countermode_Down,
    PWM_CounterMode_UpDown,
    PWM_CounterMode_Stop
} PWM_CounterMode_e;




// **************************************************************************
// the typdefines
// **************************************************************************
//----------------------------------------------------
// Time base control register bit definitions */                                 
struct TBCTL_BITS {          // bits   description
   uint16_t CTRMODE:2;         // 1:0    Counter Mode
   uint16_t PHSEN:1;           // 2      Phase load enable
   uint16_t PRDLD:1;           // 3      Active period load
   uint16_t SYNCOSEL:2;        // 5:4    Sync output select
   uint16_t SWFSYNC:1;         // 6      Software force sync pulse
   uint16_t HSPCLKDIV:3;       // 9:7    High speed time pre-scale
   uint16_t CLKDIV:3;          // 12:10  Timebase clock pre-scale
   uint16_t PHSDIR:1;          // 13     Phase Direction
   uint16_t FREE_SOFT:2;       // 15:14  Emulation mode 
};

union TBCTL_REG {
   uint16_t              all;
   struct TBCTL_BITS   bit;
};

//----------------------------------------------------
// Time base status register bit definitions */                                    
struct TBSTS_BITS {          // bits   description
   uint16_t CTRDIR:1;          // 0      Counter direction status
   uint16_t SYNCI:1;           // 1      External input sync status
   uint16_t CTRMAX:1;          // 2      Counter max latched status
   uint16_t rsvd1:13;          // 15:3   reserved
};

union TBSTS_REG {
   uint16_t              all;
   struct TBSTS_BITS   bit;
};

//----------------------------------------------------
// Compare control register bit definitions */                                    
struct CMPCTL_BITS {          // bits   description
   uint16_t LOADAMODE:2;        // 0:1    Active compare A
   uint16_t LOADBMODE:2;        // 3:2    Active compare B
   uint16_t SHDWAMODE:1;        // 4      Compare A block operating mode
   uint16_t rsvd1:1;            // 5      reserved
   uint16_t SHDWBMODE:1;        // 6      Compare B block operating mode
   uint16_t rsvd2:1;            // 7      reserved
   uint16_t SHDWAFULL:1;        // 8      Compare A Shadow registers full Status
   uint16_t SHDWBFULL:1;        // 9      Compare B Shadow registers full Status
   uint16_t rsvd3:6;            // 15:10  reserved
};

union CMPCTL_REG {
   uint16_t                all;
   struct CMPCTL_BITS    bit;
};

//----------------------------------------------------
// Action qualifier register bit definitions */                                    
struct AQCTL_BITS {           // bits   description
   uint16_t ZRO:2;              // 1:0    Action Counter = Zero
   uint16_t PRD:2;              // 3:2    Action Counter = Period
   uint16_t CAU:2;              // 5:4    Action Counter = Compare A up
   uint16_t CAD:2;              // 7:6    Action Counter = Compare A down
   uint16_t CBU:2;              // 9:8    Action Counter = Compare B up
   uint16_t CBD:2;              // 11:10  Action Counter = Compare B down
   uint16_t rsvd:4;             // 15:12  reserved
};
union AQCTL_REG {
   uint16_t                all;
   struct AQCTL_BITS     bit;
};

//----------------------------------------------------
// Action qualifier SW force register bit definitions */                                    
struct AQSFRC_BITS {           // bits   description
   uint16_t ACTSFA:2;            // 1:0    Action when One-time SW Force A invoked
   uint16_t OTSFA:1;             // 2      One-time SW Force A output
   uint16_t ACTSFB:2;            // 4:3    Action when One-time SW Force B invoked
   uint16_t OTSFB:1;             // 5      One-time SW Force A output
   uint16_t RLDCSF:2;            // 7:6    Reload from Shadow options
   uint16_t rsvd1:8;             // 15:8   reserved
};
union AQSFRC_REG {
   uint16_t                 all;
   struct AQSFRC_BITS     bit;
};

//----------------------------------------------------
// Action qualifier continuous SW force register bit definitions */                                    
struct AQCSFRC_BITS {          // bits   description
   uint16_t CSFA:2;              // 1:0    Continuous Software Force on output A
   uint16_t CSFB:2;              // 3:2    Continuous Software Force on output B
   uint16_t rsvd1:12;            // 15:4   reserved
};
union AQCSFRC_REG {
   uint16_t                  all;
   struct AQCSFRC_BITS     bit;
};


// As of version 1.1
// Changed the MODE bit-field to OUT_MODE
// Added the bit-field IN_MODE
// This corresponds to changes in silicon as of F2833x devices
// Rev A silicon.
//----------------------------------------------------
// Dead-band generator control register bit definitions                                    
struct DBCTL_BITS {          // bits   description
   uint16_t OUT_MODE:2;      	 // 1:0    Dead Band Output Mode Control 
   uint16_t POLSEL:2;          // 3:2    Polarity Select Control 
   uint16_t IN_MODE:2;         // 5:4    Dead Band Input Select Mode Control
   uint16_t rsvd1:10;          // 15:4   reserved
};

union DBCTL_REG {
   uint16_t                  all;
   struct DBCTL_BITS       bit;
};


//----------------------------------------------------
// Trip zone select register bit definitions                                   
struct TZSEL_BITS {           // bits   description
   uint16_t  CBC1:1;            // 0      TZ1 CBC select
   uint16_t  CBC2:1;            // 1      TZ2 CBC select
   uint16_t  CBC3:1;            // 2      TZ3 CBC select
   uint16_t  CBC4:1;            // 3      TZ4 CBC select
   uint16_t  CBC5:1;            // 4      TZ5 CBC select
   uint16_t  CBC6:1;            // 5      TZ6 CBC select
   uint16_t  rsvd1:2;           // 7:6    reserved
   uint16_t  OSHT1:1;           // 8      One-shot TZ1 select             
   uint16_t  OSHT2:1;           // 9      One-shot TZ2 select             
   uint16_t  OSHT3:1;           // 10     One-shot TZ3 select             
   uint16_t  OSHT4:1;           // 11     One-shot TZ4 select             
   uint16_t  OSHT5:1;           // 12     One-shot TZ5 select             
   uint16_t  OSHT6:1;           // 13     One-shot TZ6 select             
   uint16_t  rsvd2:2;           // 15:14  reserved
};

union TZSEL_REG {
   uint16_t                  all;
   struct TZSEL_BITS       bit;
};


//----------------------------------------------------
// Trip zone control register bit definitions */                                    
struct TZCTL_BITS {         // bits   description
   uint16_t TZA:2;            // 1:0    TZ1 to TZ6 Trip Action On EPWMxA
   uint16_t TZB:2;            // 3:2    TZ1 to TZ6 Trip Action On EPWMxB
   uint16_t rsvd:12;          // 15:4   reserved
};

union TZCTL_REG {
   uint16_t                  all;
   struct TZCTL_BITS       bit;
};


//----------------------------------------------------
// Trip zone control register bit definitions */                                    
struct TZEINT_BITS {         // bits   description
   uint16_t  rsvd1:1;          // 0      reserved
   uint16_t  CBC:1;            // 1      Trip Zones Cycle By Cycle Int Enable
   uint16_t  OST:1;            // 2      Trip Zones One Shot Int Enable
   uint16_t  rsvd2:13;         // 15:3   reserved
};   


union TZEINT_REG {
   uint16_t                  all;
   struct TZEINT_BITS      bit;
};


//----------------------------------------------------
// Trip zone flag register bit definitions */                                    
struct TZFLG_BITS {         // bits   description
   uint16_t  INT:1;           // 0      Global status
   uint16_t  CBC:1;           // 1      Trip Zones Cycle By Cycle Int
   uint16_t  OST:1;           // 2      Trip Zones One Shot Int
   uint16_t  rsvd2:13;        // 15:3   reserved
};

union TZFLG_REG {
   uint16_t                  all;
   struct TZFLG_BITS       bit;
};

//----------------------------------------------------
// Trip zone flag clear register bit definitions */                                    
struct TZCLR_BITS {         // bits   description
   uint16_t  INT:1;           // 0      Global status
   uint16_t  CBC:1;           // 1      Trip Zones Cycle By Cycle Int
   uint16_t  OST:1;           // 2      Trip Zones One Shot Int
   uint16_t  rsvd2:13;        // 15:3   reserved
};

union TZCLR_REG {
   struct TZCLR_BITS       bit;
   uint16_t                  all;
};

//----------------------------------------------------
// Trip zone flag force register bit definitions */                                    
struct TZFRC_BITS {         // bits   description
   uint16_t  rsvd1:1;         // 0      reserved
   uint16_t  CBC:1;           // 1      Trip Zones Cycle By Cycle Int
   uint16_t  OST:1;           // 2      Trip Zones One Shot Int
   uint16_t  rsvd2:13;        // 15:3   reserved
};

union TZFRC_REG {
   uint16_t                  all;
   struct TZFRC_BITS       bit;
};

//----------------------------------------------------
// Event trigger select register bit definitions */                                    
struct ETSEL_BITS {         // bits   description
   uint16_t  INTSEL:3;        // 2:0    EPWMxINTn Select
   uint16_t  INTEN:1;         // 3      EPWMxINTn Enable
   uint16_t  rsvd1:4;         // 7:4    reserved
   uint16_t  SOCASEL:3;       // 10:8   Start of conversion A Select
   uint16_t  SOCAEN:1;        // 11     Start of conversion A Enable
   uint16_t  SOCBSEL:3;       // 14:12  Start of conversion B Select
   uint16_t  SOCBEN:1;        // 15     Start of conversion B Enable
};

union ETSEL_REG {
   uint16_t                  all;
   struct ETSEL_BITS       bit;
};


//----------------------------------------------------
// Event trigger pre-scale register bit definitions */                                    
struct ETPS_BITS {         // bits   description
   uint16_t  INTPRD:2;       // 1:0    EPWMxINTn Period Select
   uint16_t  INTCNT:2;       // 3:2    EPWMxINTn Counter Register
   uint16_t  rsvd1:4;        // 7:4    reserved
   uint16_t  SOCAPRD:2;      // 9:8    EPWMxSOCA Period Select
   uint16_t  SOCACNT:2;      // 11:10  EPWMxSOCA Counter Register
   uint16_t  SOCBPRD:2;      // 13:12  EPWMxSOCB Period Select
   uint16_t  SOCBCNT:2;      // 15:14  EPWMxSOCB Counter Register
};

union ETPS_REG {
   uint16_t                  all;
   struct ETPS_BITS        bit;
};

//----------------------------------------------------
// Event trigger Flag register bit definitions */                                    
struct ETFLG_BITS {         // bits   description
   uint16_t  INT:1;           // 0	EPWMxINTn Flag
   uint16_t  rsvd1:1;         // 1	reserved
   uint16_t  SOCA:1;          // 2	EPWMxSOCA Flag
   uint16_t  SOCB:1;          // 3	EPWMxSOCB Flag
   uint16_t  rsvd2:12;        // 15:4	reserved
};

union ETFLG_REG {
   uint16_t                   all;
   struct ETFLG_BITS        bit;
};


//----------------------------------------------------
// Event trigger Clear register bit definitions */                                    
struct ETCLR_BITS {         // bits   description
   uint16_t  INT:1;           // 0	EPWMxINTn Clear
   uint16_t  rsvd1:1;         // 1	reserved
   uint16_t  SOCA:1;          // 2	EPWMxSOCA Clear
   uint16_t  SOCB:1;          // 3	EPWMxSOCB Clear
   uint16_t  rsvd2:12;        // 15:4	reserved
};

union ETCLR_REG {
   uint16_t                   all;
   struct ETCLR_BITS        bit;
};

//----------------------------------------------------
// Event trigger Force register bit definitions */                                    
struct ETFRC_BITS {         // bits   description
   uint16_t  INT:1;           // 0	EPWMxINTn Force
   uint16_t  rsvd1:1;         // 1	reserved
   uint16_t  SOCA:1;          // 2	EPWMxSOCA Force
   uint16_t  SOCB:1;          // 3	EPWMxSOCB Force
   uint16_t  rsvd2:12;        // 15:4	reserved
};

union ETFRC_REG {
   uint16_t                  all;
   struct ETFRC_BITS        bit;
};
//----------------------------------------------------
// PWM chopper control register bit definitions */                                    
struct PCCTL_BITS {         // bits   description
   uint16_t  CHPEN:1;         // 0      PWM chopping enable
   uint16_t  OSHTWTH:4;       // 4:1    One-shot pulse width
   uint16_t  CHPFREQ:3;       // 7:5    Chopping clock frequency
   uint16_t  CHPDUTY:3;       // 10:8   Chopping clock Duty cycle
   uint16_t  rsvd1:5;         // 15:11  reserved
};


union PCCTL_REG {
   uint16_t                  all;
   struct PCCTL_BITS       bit;
};

struct HRCNFG_BITS {       	// bits   description
   uint16_t  EDGMODE:2;     	// 1:0    Edge Mode select Bits
   uint16_t  CTLMODE:1;     	// 2      Control mode Select Bit
   uint16_t  HRLOAD:1;      	// 3      Shadow mode Select Bit
   uint16_t  rsvd1:12;      	// 15:4   reserved
};

union HRCNFG_REG {
   uint16_t                  	all;
   struct HRCNFG_BITS       bit;
};


struct TBPHS_HRPWM_REG {   	// bits   description
   uint16_t  TBPHSHR;     	// 15:0   Extension register for HRPWM Phase (8 bits)
   uint16_t  TBPHS;           // 31:16  Phase offset register
};

union TBPHS_HRPWM_GROUP {
   uint32_t  all;
   struct TBPHS_HRPWM_REG  half;
};

struct CMPA_HRPWM_REG {   	// bits   description
   uint16_t  CMPAHR;     	    // 15:0   Extension register for HRPWM compare (8 bits)
   uint16_t  CMPA;            // 31:16  Compare A reg
};

union CMPA_HRPWM_GROUP {
   uint32_t  all;
   struct CMPA_HRPWM_REG  half;
};





typedef struct _PWM_Obj_
{
   union  TBCTL_REG           TBCTL;   // 
   union  TBSTS_REG           TBSTS;   // 
   union  TBPHS_HRPWM_GROUP   TBPHS;   // Union of TBPHS:TBPHSHR
   uint16_t                     TBCTR;   // Counter
   uint16_t                     TBPRD;   // Period register set 
   uint16_t                     rsvd1;   // 
   union  CMPCTL_REG          CMPCTL;  // Compare control
   union  CMPA_HRPWM_GROUP    CMPA;    // Union of CMPA:CMPAHR
   uint16_t                     CMPB;    // Compare B reg
   union  AQCTL_REG           AQCTLA;  // Action qual output A
   union  AQCTL_REG           AQCTLB;  // Action qual output B
   union  AQSFRC_REG          AQSFRC;  // Action qual SW force
   union  AQCSFRC_REG         AQCSFRC; // Action qualifier continuous SW force 
   union  DBCTL_REG           DBCTL;   // Dead-band control
   uint16_t                     DBRED;   // Dead-band rising edge delay
   uint16_t                     DBFED;   // Dead-band falling edge delay
   union  TZSEL_REG           TZSEL;   // Trip zone select
   uint16_t                     rsvd2;   
   union  TZCTL_REG           TZCTL;   // Trip zone control
   union  TZEINT_REG          TZEINT;  // Trip zone interrupt enable
   union  TZFLG_REG           TZFLG;   // Trip zone interrupt flags
   union  TZCLR_REG           TZCLR;   // Trip zone clear   
   union  TZFRC_REG    	      TZFRC;   // Trip zone force interrupt
   union  ETSEL_REG           ETSEL;   // Event trigger selection
   union  ETPS_REG            ETPS;    // Event trigger pre-scaler
   union  ETFLG_REG           ETFLG;   // Event trigger flags
   union  ETCLR_REG           ETCLR;   // Event trigger clear   
   union  ETFRC_REG           ETFRC;   // Event trigger force
   union  PCCTL_REG           PCCTL;   // PWM chopper control
   uint16_t                     rsvd3;   // 
   union  HRCNFG_REG          HRCNFG;  // HRPWM Config Reg
} PWM_Obj;

//! \brief pwm操作句柄
//!
typedef struct _PWM_Obj_ *PWM_Handle;


// **************************************************************************
// the globals

typedef enum
{
   PWM_ClkDiv_by_1 =0,
   PWM_ClkDiv_by_2  ,
   PWM_ClkDiv_by_4  ,
   PWM_ClkDiv_by_6  ,
   PWM_ClkDiv_by_8 ,
   PWM_ClkDiv_by_10 ,
   PWM_ClkDiv_by_12 ,
   PWM_ClkDiv_by_14
} PWM_ClkDiv_e;

typedef enum
{
   PWM_HspClkDiv_by_1= 0 ,
   PWM_HspClkDiv_by_2= 1 ,
   PWM_HspClkDiv_by_4= 2 ,
   PWM_HspClkDiv_by_8= 3 ,
   PWM_HspClkDiv_by_16= 4 ,
   PWM_HspClkDiv_by_32=5,
   PWM_HspClkDiv_by_64=6,
   PWM_HspClkDiv_by_128=7
} PWM_HspClkDiv_e;

typedef enum
{
   Disabled = 0,
   Enabled
} PWM_Enable_e;

typedef enum
{
   PWM_Count_down = 0,
   PWM_Count_up
} PWM_PhaseDir_e;

typedef enum
{
   PWM_RunMode_SoftStopAfterNextCount = 0x00,
   PWM_RunMode_SoftStopAfterCycle = 0x01,
   PWM_RunMode_FreeRun =  0x03
} PWM_RunMode_e;



typedef enum
{
   PWM_PRDLD_ShadowMode = 0,
   PWM_PRLDD_Immediately
} PWM_PeriodLoad_e;


typedef enum
{
   PWM_SyncMode_EPWMxSYNC = 0,
   PWM_CTR_ZERO,
   PWM_CTR_CMPB,
   PWM_DISABLED
} PWM_SyncMode_e;

typedef enum
{
    PWM_LoadMode_Zero=0,
    PWM_LoadMode_Period,
    PWM_LoadMode_Either,
    PWM_LoadMode_Freeze
} PWM_LoadMode_e;

typedef enum
{
    PWM_ShadowMode_Shadow=0,
    PWM_ShadowMode_Immediate
} PWM_ShadowMode_e;


typedef enum
{
    PWM_ActionQual_Disabled=0,
    PWM_ActionQual_Clear,
    PWM_ActionQual_Set,
    PWM_ActionQual_Toggle
}PWM_ActionQual_e;

typedef enum
{
    PWM_DeadBandOutputMode_Bypass=0,
    PWM_DeadBandOutputMode_EPWMxA_Disable_EPWMxB_Falling,
    PWM_DeadBandOutputMode_EPWMxA_Rising_EPWMxB_Disable,
    PWM_DeadBandOutputMode_EPWMxA_Rising_EPWMxB_Falling
}PWM_DeadBandOutputMode_e;

typedef enum
{
    PWM_DeadBandPolarity_EPWMxA_EPWMxB=0,
    PWM_DeadBandPolarity_EPWMxA_Inverted,
    PWM_DeadBandPolarity_EPWMxB_Inverted,
    PWM_DeadBandPolarity_EPWMxA_Inverted_EPWMxB_Inverted
} PWM_DeadBandPolarity_e;

typedef enum
{
    PWM_SocPulseSrc_DcEvt=0,
    PWM_SocPulseSrc_CounterEqualZero,
    PWM_SocPulseSrc_CounterEqualPeriod,
    PWM_SocPulseSrc_CounterEqualZeroOrPeriod,
    PWM_SocPulseSrc_CounterEqualCmpAIncr,
    PWM_SocPulseSrc_CounterEqualCmpADecr,
    PWM_SocPulseSrc_CounterEqualCmpBIncr,
    PWM_SocPulseSrc_CounterEqualCmpBDecr
} PWM_SocPulseSrc_e;

typedef enum
{
    PWM_IntPeriod_Disable=0,
    PWM_IntPeriod_FirstEvent,
    PWM_IntPeriod_SecondEvent,
    PWM_IntPeriod_ThirdEvent
} PWM_IntPeriod_e;

typedef enum
{
    PWM_SocPeriod_Disable=0,
    PWM_SocPeriod_FirstEvent,
    PWM_SocPeriod_SecondEvent,
    PWM_SocPeriod_ThirdEvent
} PWM_SocPeriod_e;


// **************************************************************************
// the function prototypes

//! @brief: PWM初始化
//! @param void *pMemory
//! @param size_t numBytes
//! @return *
extern PWM_Handle PWM_init(void *pMemory, const size_t numBytes);

//! \brief  设置周期计数器最大值
extern void PWM_set_TB_Period(PWM_Handle pwmHandle, const uint16_t period);

//! \brief  设置计数器相位值
extern void PWM_set_TB_Phase(PWM_Handle pwmHandle, const uint16_t phase);

//! \brief  设置PWM时钟 TBCLK = SYSCLKOUT / (HSPCLKDIV × CLKDIV)
extern void PWM_set_TB_ClkDiv(PWM_Handle pwmHandle, const PWM_ClkDiv_e clkDiv);

//! \brief  设置PWM时钟 TBCLK = SYSCLKOUT / (HSPCLKDIV × CLKDIV)
extern void PWM_set_TB_HighSpeedClkDiv(PWM_Handle pwmHandle, const PWM_HspClkDiv_e clkDiv);

//! \brief  是否使能PWM相位寄存器
extern void PWM_set_TB_PHSEN(PWM_Handle pwmHandle, const PWM_Enable_e Val);

//! \brief  设置PWM相位寄存器方向：载入相位后计数方向
extern void PWM_set_TB_PhaseDir(PWM_Handle pwmHandle, const PWM_PhaseDir_e phaseDir);

//! \brief  设置PWM仿真模式:选择仿真事件期间ePWM时基计数器的行为。
extern void PWM_set_TB_RunMode(PWM_Handle pwmHandle, const PWM_RunMode_e runMode);

//! \brief  设置PWM计数器模式
extern void PWM_set_TB_CounterMode(PWM_Handle pwmHandle, const PWM_CounterMode_e counterMode);

//! \brief  设置PWM影子寄存器
extern void PWM_set_TB_PeriodLoad(PWM_Handle pwmHandle, const PWM_PeriodLoad_e periodLoad);

//! \brief  计数器是否最大值
extern bool PWM_isCTR_reachMax(PWM_Handle pwmHandle);

//! \brief  同步信号是否到来
extern bool PWM_isSYN_occured(PWM_Handle pwmHandle);

//! \brief  当前计数器是否向上计数
extern bool PWM_isCount_UP (PWM_Handle pwmHandle);

//! \brief  设置PWM当前计数值
static inline  void PWM_set_TB_Count(PWM_Handle pwmHandle, const uint16_t count)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    // set the bits
    pwm->TBCTR = count;

    return;
} // end of PWM_setCount() function

//! \brief  设置同步模式
extern void PWM_set_TB_SyncMode(PWM_Handle pwmHandle, const PWM_SyncMode_e syncMode);

//! \brief  设置同步模式
extern void PWM_set_TB_CounterMode(PWM_Handle pwmHandle, const PWM_CounterMode_e counterMode);

//! \brief  清除PWM中断标志位
static inline void PWM_clearIntFlag(PWM_Handle pwmHandle)
{
   PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
   // set the bits
   pwm->ETCLR.bit.INT = 1;

   return;
} // end of PWM_clearIntFlag() function

//! \brief  清除OST标志位
static inline void PWM_clearOneShotTrip(PWM_Handle pwmHandle)
{
   PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

   ENABLE_PROTECTED_REGISTER_WRITE_MODE;
   // set the bits
   pwm->TZCLR.bit.OST = 1;

   DISABLE_PROTECTED_REGISTER_WRITE_MODE;

   return;
} // end of PWM_clearOneShotTrip() function

//! \brief  清除脉宽调制 (PWM) 转换开始SOCA 标志
static inline void PWM_clearSocAFlag(PWM_Handle pwmHandle)
{
   PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

   // set the bits
   pwm->ETCLR.bit.SOCA = 1;

   return;
} // end of PWM_clearSocAFlag() function

//! \brief  清除脉宽调制 (PWM) 转换开始 SOCB标志
static inline void PWM_clearSocBFlag(PWM_Handle pwmHandle)
{
   PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

   // set the bits
   pwm->ETCLR.bit.SOCB = 1;

   return;
} // end of PWM_clearSocBFlag() function

////TODO ! \brief     清除指定的故障保护区 (TZ) 标志
////! \param[in] pwmHandle  The pulse width modulation (PWM) object handle
////! \param[in] tripZoneFlag  The trip zone flag to clear
//extern void PWM_clearTripZone(PWM_Handle pwmHandle, const PWM_TripZoneFlag_e tripZoneFlag);

//! \brief  将脉宽调制 (PWM) 数据值写入计数器比较器A硬件
static inline void PWM_setCmpA(PWM_Handle pwmHandle, const uint16_t pwmData)
{
   PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

   pwm->CMPA.half.CMPA = pwmData;

   return;
} // end of PWM_setCmpA() function

//! \brief  将脉宽调制 (PWM) 数据值写入计数器比较器A硬件
static inline void PWM_setCmpAHr(PWM_Handle pwmHandle, const uint16_t pwmData)
{
   PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

   pwm->CMPA.half.CMPAHR = pwmData;

   return;
} // end of PWM_setCmpAHr() function

//! \brief  将脉宽调制 (PWM) 数据值写入计数器比较器B
static inline void PWM_setCmpB(PWM_Handle pwmHandle, const uint16_t pwmData)
{
   PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

   pwm->CMPB = pwmData;

   return;
} // end of PWM_setCmpB() function

//! \brief  获取A比较器的值
static inline uint16_t PWM_get_CmpA(PWM_Handle pwmHandle)
{
   PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

   return pwm->CMPA.half.CMPA;
} // end of PWM_get_CmpA() function

//! \brief  获取B比较器的值
static inline uint16_t PWM_get_CmpB(PWM_Handle pwmHandle)
{
   PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

   return pwm->CMPB;
} // end of PWM_get_CmpB() function


//! \brief  获取PWM周期值
static inline uint16_t PWM_getPeriod(PWM_Handle pwmHandle)
{
   PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

   return (pwm->TBPRD);
} // end of PWM_getPeriod() function

//! \brief  强制触发一次OST
static inline void PWM_setOneShotTrip(PWM_Handle pwmHandle)
{
   PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

   ENABLE_PROTECTED_REGISTER_WRITE_MODE;

   // set the bits
   pwm->TZFRC.bit.OST = 1;

   DISABLE_PROTECTED_REGISTER_WRITE_MODE;

   return;
} // end of PWM_setOneShotTrip() function

//! \brief  强制同步
static inline void PWM_forceSync(PWM_Handle pwmHandle)
{
   PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

   pwm->TBCTL.bit.SWFSYNC = 1;

   return;
} // end of PWM_forceSync() function

//! \brief  使能相位寄存器
static inline void PWM_enable_TB_Phase(PWM_Handle pwmHandle, bool value)
{
   PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

   pwm->TBCTL.bit.PHSEN = value;

   return;
}

//! \brief  设置同步输出源：选择 EPWMxSYNCO 信号源
static inline void PWM_set_TB_syncMode(PWM_Handle pwmHandle, const PWM_SyncMode_e syncMode){
   
   PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

   pwm->TBCTL.bit.SYNCOSEL = syncMode;

   return;

}

//! \brief  设置CMPA的比较模式
static inline void PWM_set_CC_LoadMode_CmpA(PWM_Handle pwmHandle, const PWM_LoadMode_e loadMode)
{
   PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

   pwm->CMPCTL.bit.LOADAMODE = loadMode;

   return;
}

//! \brief  设置CMPB的比较模式
static inline void PWM_set_CC_LoadMode_CmpB(PWM_Handle pwmHandle, const PWM_LoadMode_e loadMode){
   
   PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

   pwm->CMPCTL.bit.LOADBMODE = loadMode;

   return;
}

//! \brief  设置CMPA的影子比较模式
static inline void PWM_set_CC_LShadowMode_CmpA(PWM_Handle pwmHandle,const PWM_ShadowMode_e shadowMode){
   
   PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

   pwm->CMPCTL.bit.SHDWAMODE = shadowMode;

   return;
}

//! \brief  设置CMPB的影子比较模式
static inline void PWM_set_CC_LShadowMode_CmpB(PWM_Handle pwmHandle,const PWM_ShadowMode_e shadowMode){
   
   PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

   pwm->CMPCTL.bit.SHDWBMODE = shadowMode;

   return;
}


static inline void PWM_set_AQ_CntUp_CmpA_PwmA(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual){

    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->AQCTLA.bit.CAU = actionQual;

    return;
}

static inline void PWM_set_AQ_CntUp_CmpA_PwmB(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual){

    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->AQCTLB.bit.CAU = actionQual;

    return;
}

static inline void PWM_set_AQ_CntDown_CmpA_PwmA(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual){

    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->AQCTLA.bit.CAD = actionQual;

    return;
}

static inline void PWM_set_AQ_CntDown_CmpA_PwmB(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual){

    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->AQCTLB.bit.CAD = actionQual;

    return;
}

static inline void PWM_set_AQ_Cnt_PRD_PwmA(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual){

    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->AQCTLA.bit.PRD = actionQual;

    return;
}

static inline void PWM_set_AQ_Cnt_PRD_PwmB(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual){

    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->AQCTLB.bit.PRD = actionQual;

    return;
}

static inline void PWM_set_AQ_Cnt_Zero_PwmA(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual){

    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->AQCTLA.bit.ZRO = actionQual;

    return;
}

static inline void PWM_AQ_Cnt_Zero_PwmB(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual){

    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->AQCTLB.bit.ZRO = actionQual;

    return;
}



//! \brief  设置当计数器等于 CMPA 且计数器递增时，PWMA对象动作   
extern void PWM_setActionQual_CntUp_CmpA_PwmA(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual);

//! \brief  设置当计数器等于 CMPA 且计数器递增时，PWMB对象动作   
extern void PWM_setActionQual_CntUp_CmpA_PwmB(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual);

//! \brief  设置当计数器等于 CMPA 且计数器递减时，PWMA对象动作   
extern void PWM_setActionQual_CntDown_CmpA_PwmA(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual);

//! \brief  设置当计数器等于 CMPA 且计数器递减时，PWMB对象动作   
extern void PWM_setActionQual_CntDown_CmpA_PwmB(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual);


//! \brief  设置当计数器等于 PRD PWMA对象动作   
extern void PWM_setActionQual_Cnt_PRD_PwmA(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual);

//! \brief  设置当计数器等于 PRD PWMB对象动作   
extern void PWM_setActionQual_Cnt_PRD_PwmB(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual);

//! \brief  设置当计数器等于 0 PWMA对象动作   
extern void PWM_setActionQual_Cnt_Zero_PwmA(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual);

//! \brief  设置当计数器等于 0 PWMB对象动作   
extern void PWM_setActionQual_Cnt_Zero_PwmB(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual);

//! \brief  设置当死区输出模式  
static inline void PWM_set_DB_OutputMode(PWM_Handle pwmHandle, const PWM_DeadBandOutputMode_e outputMode)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->DBCTL.bit.OUT_MODE = outputMode;

    return;
} // end of PWM_setDeadBandOutputMode() function

//! \brief  设置死区的极性
static inline void PWM_set_DB_Polarity(PWM_Handle pwmHandle, const PWM_DeadBandPolarity_e polarity)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

   pwm->DBCTL.bit.POLSEL = polarity;

    return;
} // end of PWM_setDeadBandPolarity() function

//! \brief  设置死区的上升的延时时间
static inline void PWM_set_DB_RisingEdgeDelay(PWM_Handle pwmHandle,const uint16_t delay)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->DBRED = delay;

    return;
} // end of PWM_setDeadBandRisingEdgeDelay() function

//! \brief  设置死区下降的延时时间
static inline void PWM_set_DB_FallingEdgeDelay(PWM_Handle pwmHandle,const uint16_t delay)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->DBFED = delay;

    return;
} // end of PWM_setDeadBandFallingEdgeDelay() function

//! \brief  禁止采用PWM斩波模式
static inline void PWM_disableChopping(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->PCCTL.bit.CHPEN = false;

    return;
} // end of PWM_disableChopping() function

//! \brief  禁止采用TZ
static inline void PWM_disableTripZones(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    // clear the bits
    pwm->TZSEL.all = 0;

    return;
} // end of PWM_disableTripZones() function


//! \brief  禁止采用PWM中断
static inline void PWM_ET_disableInt(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    // clear the bits
    pwm->ETSEL.bit.INTEN = 0;

    return;
} // end of PWM_disableInt() function


//! \brief  设置PWM的SOCA启动源
static inline void PWM_set_ET_SocAPulseSrc(PWM_Handle pwmHandle, const PWM_SocPulseSrc_e pulseSrc)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->ETSEL.bit.SOCASEL = pulseSrc;

    return;
} // end of PWM_setSocAPulseSrc() function

//! \brief  设置PWM的SOCB启动源
static inline void PWM_set_ET_SocBPulseSrc(PWM_Handle pwmHandle, const PWM_SocPulseSrc_e pulseSrc)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->ETSEL.bit.SOCBSEL = pulseSrc;

    return;
} // end of PWM_setSocBPulseSrc() function

//! \brief  使能PWM的SOCA启动源
static inline
void PWM_ET_enableSocAPulse(PWM_Handle pwmHandle, bool value)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    // set the bits
    pwm->ETSEL.bit.SOCAEN = value;

    return;
} // end of PWM_enableSocAPulse() function

//! \brief  使能PWM的SOCB启动源
static inline void PWM_ET_enableSocBPulse(PWM_Handle pwmHandle, bool value)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    // set the bits
    pwm->ETSEL.bit.SOCBEN = value;

    return;
} // end of PWM_enableSocBPulse() function

//! \brief  设置多少个事件触发中断
static inline void PWM_setIntPeriod(PWM_Handle pwmHandle, const PWM_IntPeriod_e intPeriod)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    // set the bits
    pwm->ETPS.bit.INTPRD = intPeriod;

    return;
} // end of PWM_setIntPeriod() function

//! \brief  设置多少个事件触发SOCA
static inline void PWM_setSocAPeriod(PWM_Handle pwmHandle, const PWM_SocPeriod_e intPeriod)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    // set the bits
    pwm->ETPS.bit.SOCAPRD = intPeriod ;

    return;
} // end of PWM_setSocAPeriod() function

//! \brief  设置多少个事件触发SOCB
static inline void PWM_setSocBPeriod(PWM_Handle pwmHandle, const PWM_SocPeriod_e intPeriod)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    // set the bits
    pwm->ETPS.bit.SOCBPRD = intPeriod ;

    return;
} // end of PWM_setSocAPeriod() function

//! \brief  设置PWM周期计数值
static inline void PWM_setPeriod(PWM_Handle pwmHandle, const uint16_t period)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    pwm->TBPRD = period;

    return;
} // end of PWM_setPeriod() function



//@} // ingroup
#endif // end of _PWM_H_ definition
