//************************************************************
// Desciption: PRCv12 Register File Header File
//      Generated by genRF 07/01/2015 16:16:42
//************************************************************

#ifndef PRCV12_RF_H
#define PRCV12_RF_H

// Register 0x00 [AMBA:0xA0000000]
typedef union prcv12_r00{
  struct{
    unsigned MBUS_R0		: 24;
  };
  uint32_t as_int;
} prcv12_r00_t;
#define PRCv12_R00_DEFAULT {{0x000000}}
_Static_assert(sizeof(prcv12_r00_t) == 4, "Punned Structure Size");

// Register 0x01 [AMBA:0xA0000004]
typedef union prcv12_r01{
  struct{
    unsigned MBUS_R1		: 24;
  };
  uint32_t as_int;
} prcv12_r01_t;
#define PRCv12_R01_DEFAULT {{0x000000}}
_Static_assert(sizeof(prcv12_r01_t) == 4, "Punned Structure Size");

// Register 0x02 [AMBA:0xA0000008]
typedef union prcv12_r02{
  struct{
    unsigned MBUS_R2		: 24;
  };
  uint32_t as_int;
} prcv12_r02_t;
#define PRCv12_R02_DEFAULT {{0x000000}}
_Static_assert(sizeof(prcv12_r02_t) == 4, "Punned Structure Size");

// Register 0x03 [AMBA:0xA000000C]
typedef union prcv12_r03{
  struct{
    unsigned MBUS_R3		: 24;
  };
  uint32_t as_int;
} prcv12_r03_t;
#define PRCv12_R03_DEFAULT {{0x000000}}
_Static_assert(sizeof(prcv12_r03_t) == 4, "Punned Structure Size");

// Register 0x04 [AMBA:0xA0000010]
typedef union prcv12_r04{
  struct{
    unsigned MBUS_R4		: 24;
  };
  uint32_t as_int;
} prcv12_r04_t;
#define PRCv12_R04_DEFAULT {{0x000000}}
_Static_assert(sizeof(prcv12_r04_t) == 4, "Punned Structure Size");

// Register 0x05 [AMBA:0xA0000014]
typedef union prcv12_r05{
  struct{
    unsigned MBUS_R5		: 24;
  };
  uint32_t as_int;
} prcv12_r05_t;
#define PRCv12_R05_DEFAULT {{0x000000}}
_Static_assert(sizeof(prcv12_r05_t) == 4, "Punned Structure Size");

// Register 0x06 [AMBA:0xA0000018]
typedef union prcv12_r06{
  struct{
    unsigned MBUS_R6		: 24;
  };
  uint32_t as_int;
} prcv12_r06_t;
#define PRCv12_R06_DEFAULT {{0x000000}}
_Static_assert(sizeof(prcv12_r06_t) == 4, "Punned Structure Size");

// Register 0x07 [AMBA:0xA000001C]
typedef union prcv12_r07{
  struct{
    unsigned MBUS_R7		: 24;
  };
  uint32_t as_int;
} prcv12_r07_t;
#define PRCv12_R07_DEFAULT {{0x000000}}
_Static_assert(sizeof(prcv12_r07_t) == 4, "Punned Structure Size");

// Register 0x08 [AMBA:0xA0000020]
typedef union prcv12_r08{
  struct{
    unsigned CHIP_ID		: 16;
  };
  uint32_t as_int;
} prcv12_r08_t;
#define PRCv12_R08_DEFAULT {{0x0000}}
_Static_assert(sizeof(prcv12_r08_t) == 4, "Punned Structure Size");

// Register 0x09 [AMBA:0xA0000024]
typedef union prcv12_r09{
  struct{
    unsigned MBUS_THRES		: 20;
  };
  uint32_t as_int;
} prcv12_r09_t;
#define PRCv12_R09_DEFAULT {{0x80008}}
_Static_assert(sizeof(prcv12_r09_t) == 4, "Punned Structure Size");

// Register 0x0A [AMBA:0xA0000028]
typedef union prcv12_r0A{
  struct{
    unsigned RF_WR_IRQ_MASK		: 8;
    unsigned MEM_WR_IRQ_MASK		: 1;
    unsigned MBUS_RX_IRQ_MASK		: 1;
    unsigned MBUS_TX_IRQ_MASK		: 1;
    unsigned MBUS_FWD_IRQ_MASK		: 1;
    unsigned CONFIG_HALT_CPU		: 4;
    unsigned OLD_MSG_REG_MASK		: 1;
  };
  uint32_t as_int;
} prcv12_r0A_t;
#define PRCv12_R0A_DEFAULT {{0xF0, 0x0, 0x0, 0x0, 0x0, 0xA, 0x1}}
_Static_assert(sizeof(prcv12_r0A_t) == 4, "Punned Structure Size");

// Register 0x0B [AMBA:0xA000002C]
typedef union prcv12_r0B{
  struct{
    unsigned GOC_SEL		: 4;
    unsigned GOC_SEL_DLY		: 2;
    unsigned GOC_ONECLK_MODE		: 1;
    unsigned GOC_CLK_GEN_SEL_FREQ		: 3;
    unsigned GOC_CLK_GEN_SEL_DIV		: 2;
    unsigned DSLP_CLK_GEN_FAST_MODE		: 1;
    unsigned CLK_GEN_RING		: 2;
    unsigned CLK_GEN_DIV_MBC		: 2;
    unsigned CLK_GEN_DIV_CORE		: 2;
    unsigned CLK_GEN_HIGH_FREQ		: 1;
  };
  uint32_t as_int;
} prcv12_r0B_t;
#define PRCv12_R0B_DEFAULT {{0x3, 0x0, 0x0, 0x1, 0x1, 0x0, 0x0, 0x3, 0x0, 0x0}}
_Static_assert(sizeof(prcv12_r0B_t) == 4, "Punned Structure Size");

// Register 0x0C [AMBA:0xA0000030]
typedef union prcv12_r0C{
  struct{
    unsigned SRAM_USE_INVERTER_SA		: 1;
    unsigned SRAM_TUNE_DECODER_DLY		: 4;
    unsigned SRAM_TUNE_WL_WIDTH		: 4;
    unsigned SRAM_TUNE_ASO_DLY		: 5;
    unsigned SRAM_USE_VREF_0P6		: 1;
    unsigned SRAM_USE_V0P6_NWELL		: 1;
  };
  uint32_t as_int;
} prcv12_r0C_t;
#define PRCv12_R0C_DEFAULT {{0x0, 0x2, 0x2, 0x00, 0x0, 0x0}}
_Static_assert(sizeof(prcv12_r0C_t) == 4, "Punned Structure Size");

// Register 0x0D [AMBA:0xA0000034]
typedef union prcv12_r0D{
  struct{
    unsigned WUP_TSTAMP_SAT		: 15;
    unsigned WUP_IRQ_EN		: 1;
    unsigned WUP_IRQ_IN_SLEEP_ONLY		: 1;
  };
  uint32_t as_int;
} prcv12_r0D_t;
#define PRCv12_R0D_DEFAULT {{0x0000, 0x0, 0x1}}
_Static_assert(sizeof(prcv12_r0D_t) == 4, "Punned Structure Size");

// Register 0x0E [AMBA:0xA0000038]
// -- READ-ONLY --

// Register 0x0F [AMBA:0xA000003C]
typedef union prcv12_r0F{
  struct{
    unsigned GOCEP_PASS		: 1;
    unsigned GOCEP_PASS_AND_RUN		: 1;
    unsigned GOCEP_FAIL		: 1;
    unsigned GOCEP_FAIL_CHIP_ID		: 1;
    unsigned GOCEP_FAIL_HEADER_PARITY		: 1;
    unsigned GOCEP_FAIL_MEM_PARITY		: 1;
    unsigned GOCEP_FAIL_TIMEOUT		: 1;
    unsigned GOCEP_CPU_WAS_RUNNING		: 1;
  };
  uint32_t as_int;
} prcv12_r0F_t;
#define PRCv12_R0F_DEFAULT {{0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}}
_Static_assert(sizeof(prcv12_r0F_t) == 4, "Punned Structure Size");

// Register 0x10 [AMBA:0xA0000040]
typedef union prcv12_r10{
  struct{
    unsigned RUN_CPU		: 1;
  };
  uint32_t as_int;
} prcv12_r10_t;
#define PRCv12_R10_DEFAULT {{0x0}}
_Static_assert(sizeof(prcv12_r10_t) == 4, "Punned Structure Size");

// Register 0x11 [AMBA:0xA0000044]
typedef union prcv12_r11{
  struct{
    unsigned MBUS_FLAG_TX_SUCC		: 1;
    unsigned MBUS_FLAG_TX_FAIL		: 1;
    // ** NOT-DEFINED ** //
    unsigned MBUS_FLAG_RX_OVERFLOW		: 1;
    unsigned MBUS_FLAG_RX_BROADCAST		: 1;
  };
  uint32_t as_int;
} prcv12_r11_t;
#define PRCv12_R11_DEFAULT {{0x0, 0x0 /* NOT-DEFINED */ , 0x0, 0x0}}
_Static_assert(sizeof(prcv12_r11_t) == 4, "Punned Structure Size");

// Register 0x12 [AMBA:0xA0000048]
typedef union prcv12_r12{
  struct{
    unsigned STR_WR_CH3_WR_BUF_LOWER		: 16;
    unsigned STR_WR_CH3_ALT_ADDR		: 8;
  };
  uint32_t as_int;
} prcv12_r12_t;
#define PRCv12_R12_DEFAULT {{0x0000, 0x00}}
_Static_assert(sizeof(prcv12_r12_t) == 4, "Punned Structure Size");

// Register 0x13 [AMBA:0xA000004C]
typedef union prcv12_r13{
  struct{
    unsigned STR_WR_CH3_WR_BUF_UPPER		: 16;
    unsigned STR_WR_CH3_ALT_REG_WR		: 8;
  };
  uint32_t as_int;
} prcv12_r13_t;
#define PRCv12_R13_DEFAULT {{0x0000, 0x00}}
_Static_assert(sizeof(prcv12_r13_t) == 4, "Punned Structure Size");

// Register 0x14 [AMBA:0xA0000050]
typedef union prcv12_r14{
  struct{
    unsigned STR_WR_CH3_BUF_LEN		: 20;
    // ** NOT-DEFINED ** //
    unsigned STR_WR_CH3_DBLB		: 1;
    unsigned STR_WR_CH3_WRP		: 1;
    unsigned STR_WR_CH3_EN		: 1;
  };
  uint32_t as_int;
} prcv12_r14_t;
#define PRCv12_R14_DEFAULT {{0x007FF /* NOT-DEFINED */ , 0x0, 0x0, 0x1}}
_Static_assert(sizeof(prcv12_r14_t) == 4, "Punned Structure Size");

// Register 0x15 [AMBA:0xA0000054]
typedef union prcv12_r15{
  struct{
    unsigned STR_WR_CH3_BUF_OFF		: 20;
  };
  uint32_t as_int;
} prcv12_r15_t;
#define PRCv12_R15_DEFAULT {{0x00000}}
_Static_assert(sizeof(prcv12_r15_t) == 4, "Punned Structure Size");

// Register 0x16 [AMBA:0xA0000058]
typedef union prcv12_r16{
  struct{
    unsigned STR_WR_CH2_WR_BUF_LOWER		: 16;
    unsigned STR_WR_CH2_ALT_ADDR		: 8;
  };
  uint32_t as_int;
} prcv12_r16_t;
#define PRCv12_R16_DEFAULT {{0x0000, 0x00}}
_Static_assert(sizeof(prcv12_r16_t) == 4, "Punned Structure Size");

// Register 0x17 [AMBA:0xA000005C]
typedef union prcv12_r17{
  struct{
    unsigned STR_WR_CH2_WR_BUF_UPPER		: 16;
    unsigned STR_WR_CH2_ALT_REG_WR		: 8;
  };
  uint32_t as_int;
} prcv12_r17_t;
#define PRCv12_R17_DEFAULT {{0x0000, 0x00}}
_Static_assert(sizeof(prcv12_r17_t) == 4, "Punned Structure Size");

// Register 0x18 [AMBA:0xA0000060]
typedef union prcv12_r18{
  struct{
    unsigned STR_WR_CH2_BUF_LEN		: 20;
    // ** NOT-DEFINED ** //
    unsigned STR_WR_CH2_DBLB		: 1;
    unsigned STR_WR_CH2_WRP		: 1;
    unsigned STR_WR_CH2_EN		: 1;
  };
  uint32_t as_int;
} prcv12_r18_t;
#define PRCv12_R18_DEFAULT {{0x007FF /* NOT-DEFINED */ , 0x0, 0x0, 0x1}}
_Static_assert(sizeof(prcv12_r18_t) == 4, "Punned Structure Size");

// Register 0x19 [AMBA:0xA0000064]
typedef union prcv12_r19{
  struct{
    unsigned STR_WR_CH2_BUF_OFF		: 20;
  };
  uint32_t as_int;
} prcv12_r19_t;
#define PRCv12_R19_DEFAULT {{0x00000}}
_Static_assert(sizeof(prcv12_r19_t) == 4, "Punned Structure Size");

// Register 0x1A [AMBA:0xA0000068]
typedef union prcv12_r1A{
  struct{
    unsigned STR_WR_CH1_WR_BUF_LOWER		: 16;
    unsigned STR_WR_CH1_ALT_ADDR		: 8;
  };
  uint32_t as_int;
} prcv12_r1A_t;
#define PRCv12_R1A_DEFAULT {{0x0000, 0x00}}
_Static_assert(sizeof(prcv12_r1A_t) == 4, "Punned Structure Size");

// Register 0x1B [AMBA:0xA000006C]
typedef union prcv12_r1B{
  struct{
    unsigned STR_WR_CH1_WR_BUF_UPPER		: 16;
    unsigned STR_WR_CH1_ALT_REG_WR		: 8;
  };
  uint32_t as_int;
} prcv12_r1B_t;
#define PRCv12_R1B_DEFAULT {{0x0000, 0x00}}
_Static_assert(sizeof(prcv12_r1B_t) == 4, "Punned Structure Size");

// Register 0x1C [AMBA:0xA0000070]
typedef union prcv12_r1C{
  struct{
    unsigned STR_WR_CH1_BUF_LEN		: 20;
    // ** NOT-DEFINED ** //
    unsigned STR_WR_CH1_DBLB		: 1;
    unsigned STR_WR_CH1_WRP		: 1;
    unsigned STR_WR_CH1_EN		: 1;
  };
  uint32_t as_int;
} prcv12_r1C_t;
#define PRCv12_R1C_DEFAULT {{0x007FF /* NOT-DEFINED */ , 0x0, 0x0, 0x1}}
_Static_assert(sizeof(prcv12_r1C_t) == 4, "Punned Structure Size");

// Register 0x1D [AMBA:0xA0000074]
typedef union prcv12_r1D{
  struct{
    unsigned STR_WR_CH1_BUF_OFF		: 20;
  };
  uint32_t as_int;
} prcv12_r1D_t;
#define PRCv12_R1D_DEFAULT {{0x00000}}
_Static_assert(sizeof(prcv12_r1D_t) == 4, "Punned Structure Size");

// Register 0x1E [AMBA:0xA0000078]
typedef union prcv12_r1E{
  struct{
    unsigned STR_WR_CH0_WR_BUF_LOWER		: 16;
    unsigned STR_WR_CH0_ALT_ADDR		: 8;
  };
  uint32_t as_int;
} prcv12_r1E_t;
#define PRCv12_R1E_DEFAULT {{0x0000, 0x00}}
_Static_assert(sizeof(prcv12_r1E_t) == 4, "Punned Structure Size");

// Register 0x1F [AMBA:0xA000007C]
typedef union prcv12_r1F{
  struct{
    unsigned STR_WR_CH0_WR_BUF_UPPER		: 16;
    unsigned STR_WR_CH0_ALT_REG_WR		: 8;
  };
  uint32_t as_int;
} prcv12_r1F_t;
#define PRCv12_R1F_DEFAULT {{0x0000, 0x00}}
_Static_assert(sizeof(prcv12_r1F_t) == 4, "Punned Structure Size");

// Register 0x20 [AMBA:0xA0000080]
typedef union prcv12_r20{
  struct{
    unsigned STR_WR_CH0_BUF_LEN		: 20;
    // ** NOT-DEFINED ** //
    unsigned STR_WR_CH0_DBLB		: 1;
    unsigned STR_WR_CH0_WRP		: 1;
    unsigned STR_WR_CH0_EN		: 1;
  };
  uint32_t as_int;
} prcv12_r20_t;
#define PRCv12_R20_DEFAULT {{0x007FF /* NOT-DEFINED */ , 0x0, 0x0, 0x1}}
_Static_assert(sizeof(prcv12_r20_t) == 4, "Punned Structure Size");

// Register 0x21 [AMBA:0xA0000084]
typedef union prcv12_r21{
  struct{
    unsigned STR_WR_CH0_BUF_OFF		: 20;
  };
  uint32_t as_int;
} prcv12_r21_t;
#define PRCv12_R21_DEFAULT {{0x00000}}
_Static_assert(sizeof(prcv12_r21_t) == 4, "Punned Structure Size");

// Register 0x22 [AMBA:0xA0000088]
// -- EMPTY --

// Register 0x23 [AMBA:0xA000008C]
// -- EMPTY --

// Register 0x24 [AMBA:0xA0000090]
typedef union prcv12_r24{
  struct{
    unsigned BLK_WR_LENGTH_LIMIT		: 20;
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    unsigned BLK_WR_CACT		: 1;
    unsigned BLK_WR_EN		: 1;
  };
  uint32_t as_int;
} prcv12_r24_t;
#define PRCv12_R24_DEFAULT {{0x00000 /* NOT-DEFINED */  /* NOT-DEFINED */ , 0x0, 0x1}}
_Static_assert(sizeof(prcv12_r24_t) == 4, "Punned Structure Size");

// Register 0x25 [AMBA:0xA0000094]
// -- EMPTY --

// Register 0x26 [AMBA:0xA0000098]
// -- EMPTY --

// Register 0x27 [AMBA:0xA000009C]
// -- EMPTY --

// Register 0x28 [AMBA:0xA00000A0]
// -- EMPTY --

// Register 0x29 [AMBA:0xA00000A4]
// -- EMPTY --

// Register 0x2A [AMBA:0xA00000A8]
// -- EMPTY --

// Register 0x2B [AMBA:0xA00000AC]
// -- EMPTY --

// Register 0x2C [AMBA:0xA00000B0]
// -- EMPTY --

// Register 0x2D [AMBA:0xA00000B4]
// -- EMPTY --

// Register 0x2E [AMBA:0xA00000B8]
// -- EMPTY --

// Register 0x2F [AMBA:0xA00000BC]
// -- EMPTY --

// Register 0x30 [AMBA:0xA00000C0]
// -- EMPTY --

// Register 0x31 [AMBA:0xA00000C4]
typedef union prcv12_r31{
  struct{
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    // ** NOT-DEFINED ** //
    unsigned ACT_RST		: 1;
  };
  uint32_t as_int;
} prcv12_r31_t;
#define PRCv12_R31_DEFAULT {{ /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */  /* NOT-DEFINED */ 0x0}}
_Static_assert(sizeof(prcv12_r31_t) == 4, "Punned Structure Size");

#endif // PRCV12_RF_H