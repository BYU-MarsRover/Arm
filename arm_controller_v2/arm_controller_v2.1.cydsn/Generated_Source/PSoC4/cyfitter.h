#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include <cydevice_trm.h>

/* led */
#define led__0__DM__MASK 0x1C0u
#define led__0__DM__SHIFT 6
#define led__0__DR CYREG_PRT1_DR
#define led__0__HSIOM CYREG_HSIOM_PORT_SEL1
#define led__0__HSIOM_MASK 0x00000F00u
#define led__0__HSIOM_SHIFT 8u
#define led__0__INTCFG CYREG_PRT1_INTCFG
#define led__0__INTSTAT CYREG_PRT1_INTSTAT
#define led__0__MASK 0x04u
#define led__0__OUT_SEL CYREG_UDB_PA1_CFG10
#define led__0__OUT_SEL_SHIFT 4u
#define led__0__OUT_SEL_VAL 2u
#define led__0__PA__CFG0 CYREG_UDB_PA1_CFG0
#define led__0__PA__CFG1 CYREG_UDB_PA1_CFG1
#define led__0__PA__CFG10 CYREG_UDB_PA1_CFG10
#define led__0__PA__CFG11 CYREG_UDB_PA1_CFG11
#define led__0__PA__CFG12 CYREG_UDB_PA1_CFG12
#define led__0__PA__CFG13 CYREG_UDB_PA1_CFG13
#define led__0__PA__CFG14 CYREG_UDB_PA1_CFG14
#define led__0__PA__CFG2 CYREG_UDB_PA1_CFG2
#define led__0__PA__CFG3 CYREG_UDB_PA1_CFG3
#define led__0__PA__CFG4 CYREG_UDB_PA1_CFG4
#define led__0__PA__CFG5 CYREG_UDB_PA1_CFG5
#define led__0__PA__CFG6 CYREG_UDB_PA1_CFG6
#define led__0__PA__CFG7 CYREG_UDB_PA1_CFG7
#define led__0__PA__CFG8 CYREG_UDB_PA1_CFG8
#define led__0__PA__CFG9 CYREG_UDB_PA1_CFG9
#define led__0__PC CYREG_PRT1_PC
#define led__0__PC2 CYREG_PRT1_PC2
#define led__0__PORT 1u
#define led__0__PS CYREG_PRT1_PS
#define led__0__SHIFT 2
#define led__DR CYREG_PRT1_DR
#define led__INTCFG CYREG_PRT1_INTCFG
#define led__INTSTAT CYREG_PRT1_INTSTAT
#define led__MASK 0x04u
#define led__PA__CFG0 CYREG_UDB_PA1_CFG0
#define led__PA__CFG1 CYREG_UDB_PA1_CFG1
#define led__PA__CFG10 CYREG_UDB_PA1_CFG10
#define led__PA__CFG11 CYREG_UDB_PA1_CFG11
#define led__PA__CFG12 CYREG_UDB_PA1_CFG12
#define led__PA__CFG13 CYREG_UDB_PA1_CFG13
#define led__PA__CFG14 CYREG_UDB_PA1_CFG14
#define led__PA__CFG2 CYREG_UDB_PA1_CFG2
#define led__PA__CFG3 CYREG_UDB_PA1_CFG3
#define led__PA__CFG4 CYREG_UDB_PA1_CFG4
#define led__PA__CFG5 CYREG_UDB_PA1_CFG5
#define led__PA__CFG6 CYREG_UDB_PA1_CFG6
#define led__PA__CFG7 CYREG_UDB_PA1_CFG7
#define led__PA__CFG8 CYREG_UDB_PA1_CFG8
#define led__PA__CFG9 CYREG_UDB_PA1_CFG9
#define led__PC CYREG_PRT1_PC
#define led__PC2 CYREG_PRT1_PC2
#define led__PORT 1u
#define led__PS CYREG_PRT1_PS
#define led__SHIFT 2

/* MISO */
#define MISO__0__DM__MASK 0x38000u
#define MISO__0__DM__SHIFT 15
#define MISO__0__DR CYREG_PRT0_DR
#define MISO__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define MISO__0__HSIOM_MASK 0x00F00000u
#define MISO__0__HSIOM_SHIFT 20u
#define MISO__0__INTCFG CYREG_PRT0_INTCFG
#define MISO__0__INTSTAT CYREG_PRT0_INTSTAT
#define MISO__0__MASK 0x20u
#define MISO__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define MISO__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define MISO__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define MISO__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define MISO__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define MISO__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define MISO__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define MISO__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define MISO__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define MISO__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define MISO__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define MISO__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define MISO__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define MISO__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define MISO__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define MISO__0__PC CYREG_PRT0_PC
#define MISO__0__PC2 CYREG_PRT0_PC2
#define MISO__0__PORT 0u
#define MISO__0__PS CYREG_PRT0_PS
#define MISO__0__SHIFT 5
#define MISO__DR CYREG_PRT0_DR
#define MISO__INTCFG CYREG_PRT0_INTCFG
#define MISO__INTSTAT CYREG_PRT0_INTSTAT
#define MISO__MASK 0x20u
#define MISO__PA__CFG0 CYREG_UDB_PA0_CFG0
#define MISO__PA__CFG1 CYREG_UDB_PA0_CFG1
#define MISO__PA__CFG10 CYREG_UDB_PA0_CFG10
#define MISO__PA__CFG11 CYREG_UDB_PA0_CFG11
#define MISO__PA__CFG12 CYREG_UDB_PA0_CFG12
#define MISO__PA__CFG13 CYREG_UDB_PA0_CFG13
#define MISO__PA__CFG14 CYREG_UDB_PA0_CFG14
#define MISO__PA__CFG2 CYREG_UDB_PA0_CFG2
#define MISO__PA__CFG3 CYREG_UDB_PA0_CFG3
#define MISO__PA__CFG4 CYREG_UDB_PA0_CFG4
#define MISO__PA__CFG5 CYREG_UDB_PA0_CFG5
#define MISO__PA__CFG6 CYREG_UDB_PA0_CFG6
#define MISO__PA__CFG7 CYREG_UDB_PA0_CFG7
#define MISO__PA__CFG8 CYREG_UDB_PA0_CFG8
#define MISO__PA__CFG9 CYREG_UDB_PA0_CFG9
#define MISO__PC CYREG_PRT0_PC
#define MISO__PC2 CYREG_PRT0_PC2
#define MISO__PORT 0u
#define MISO__PS CYREG_PRT0_PS
#define MISO__SHIFT 5

/* MOSI */
#define MOSI__0__DM__MASK 0x7000u
#define MOSI__0__DM__SHIFT 12
#define MOSI__0__DR CYREG_PRT0_DR
#define MOSI__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define MOSI__0__HSIOM_MASK 0x000F0000u
#define MOSI__0__HSIOM_SHIFT 16u
#define MOSI__0__INTCFG CYREG_PRT0_INTCFG
#define MOSI__0__INTSTAT CYREG_PRT0_INTSTAT
#define MOSI__0__MASK 0x10u
#define MOSI__0__OUT_SEL CYREG_UDB_PA0_CFG10
#define MOSI__0__OUT_SEL_SHIFT 8u
#define MOSI__0__OUT_SEL_VAL 1u
#define MOSI__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define MOSI__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define MOSI__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define MOSI__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define MOSI__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define MOSI__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define MOSI__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define MOSI__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define MOSI__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define MOSI__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define MOSI__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define MOSI__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define MOSI__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define MOSI__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define MOSI__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define MOSI__0__PC CYREG_PRT0_PC
#define MOSI__0__PC2 CYREG_PRT0_PC2
#define MOSI__0__PORT 0u
#define MOSI__0__PS CYREG_PRT0_PS
#define MOSI__0__SHIFT 4
#define MOSI__DR CYREG_PRT0_DR
#define MOSI__INTCFG CYREG_PRT0_INTCFG
#define MOSI__INTSTAT CYREG_PRT0_INTSTAT
#define MOSI__MASK 0x10u
#define MOSI__PA__CFG0 CYREG_UDB_PA0_CFG0
#define MOSI__PA__CFG1 CYREG_UDB_PA0_CFG1
#define MOSI__PA__CFG10 CYREG_UDB_PA0_CFG10
#define MOSI__PA__CFG11 CYREG_UDB_PA0_CFG11
#define MOSI__PA__CFG12 CYREG_UDB_PA0_CFG12
#define MOSI__PA__CFG13 CYREG_UDB_PA0_CFG13
#define MOSI__PA__CFG14 CYREG_UDB_PA0_CFG14
#define MOSI__PA__CFG2 CYREG_UDB_PA0_CFG2
#define MOSI__PA__CFG3 CYREG_UDB_PA0_CFG3
#define MOSI__PA__CFG4 CYREG_UDB_PA0_CFG4
#define MOSI__PA__CFG5 CYREG_UDB_PA0_CFG5
#define MOSI__PA__CFG6 CYREG_UDB_PA0_CFG6
#define MOSI__PA__CFG7 CYREG_UDB_PA0_CFG7
#define MOSI__PA__CFG8 CYREG_UDB_PA0_CFG8
#define MOSI__PA__CFG9 CYREG_UDB_PA0_CFG9
#define MOSI__PC CYREG_PRT0_PC
#define MOSI__PC2 CYREG_PRT0_PC2
#define MOSI__PORT 0u
#define MOSI__PS CYREG_PRT0_PS
#define MOSI__SHIFT 4

/* SCLK */
#define SCLK__0__DM__MASK 0x1C0000u
#define SCLK__0__DM__SHIFT 18
#define SCLK__0__DR CYREG_PRT0_DR
#define SCLK__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define SCLK__0__HSIOM_MASK 0x0F000000u
#define SCLK__0__HSIOM_SHIFT 24u
#define SCLK__0__INTCFG CYREG_PRT0_INTCFG
#define SCLK__0__INTSTAT CYREG_PRT0_INTSTAT
#define SCLK__0__MASK 0x40u
#define SCLK__0__OUT_SEL CYREG_UDB_PA0_CFG10
#define SCLK__0__OUT_SEL_SHIFT 12u
#define SCLK__0__OUT_SEL_VAL 0u
#define SCLK__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define SCLK__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define SCLK__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define SCLK__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define SCLK__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define SCLK__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define SCLK__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define SCLK__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define SCLK__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define SCLK__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define SCLK__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define SCLK__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define SCLK__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define SCLK__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define SCLK__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define SCLK__0__PC CYREG_PRT0_PC
#define SCLK__0__PC2 CYREG_PRT0_PC2
#define SCLK__0__PORT 0u
#define SCLK__0__PS CYREG_PRT0_PS
#define SCLK__0__SHIFT 6
#define SCLK__DR CYREG_PRT0_DR
#define SCLK__INTCFG CYREG_PRT0_INTCFG
#define SCLK__INTSTAT CYREG_PRT0_INTSTAT
#define SCLK__MASK 0x40u
#define SCLK__PA__CFG0 CYREG_UDB_PA0_CFG0
#define SCLK__PA__CFG1 CYREG_UDB_PA0_CFG1
#define SCLK__PA__CFG10 CYREG_UDB_PA0_CFG10
#define SCLK__PA__CFG11 CYREG_UDB_PA0_CFG11
#define SCLK__PA__CFG12 CYREG_UDB_PA0_CFG12
#define SCLK__PA__CFG13 CYREG_UDB_PA0_CFG13
#define SCLK__PA__CFG14 CYREG_UDB_PA0_CFG14
#define SCLK__PA__CFG2 CYREG_UDB_PA0_CFG2
#define SCLK__PA__CFG3 CYREG_UDB_PA0_CFG3
#define SCLK__PA__CFG4 CYREG_UDB_PA0_CFG4
#define SCLK__PA__CFG5 CYREG_UDB_PA0_CFG5
#define SCLK__PA__CFG6 CYREG_UDB_PA0_CFG6
#define SCLK__PA__CFG7 CYREG_UDB_PA0_CFG7
#define SCLK__PA__CFG8 CYREG_UDB_PA0_CFG8
#define SCLK__PA__CFG9 CYREG_UDB_PA0_CFG9
#define SCLK__PC CYREG_PRT0_PC
#define SCLK__PC2 CYREG_PRT0_PC2
#define SCLK__PORT 0u
#define SCLK__PS CYREG_PRT0_PS
#define SCLK__SHIFT 6

/* SPIM_BSPIM */
#define SPIM_BSPIM_BitCounter__16BIT_CONTROL_AUX_CTL_REG CYREG_UDB_W16_ACTL_00
#define SPIM_BSPIM_BitCounter__16BIT_CONTROL_CONTROL_REG CYREG_UDB_W16_CTL_00
#define SPIM_BSPIM_BitCounter__16BIT_CONTROL_COUNT_REG CYREG_UDB_W16_CTL_00
#define SPIM_BSPIM_BitCounter__16BIT_COUNT_CONTROL_REG CYREG_UDB_W16_CTL_00
#define SPIM_BSPIM_BitCounter__16BIT_COUNT_COUNT_REG CYREG_UDB_W16_CTL_00
#define SPIM_BSPIM_BitCounter__16BIT_MASK_MASK_REG CYREG_UDB_W16_MSK_00
#define SPIM_BSPIM_BitCounter__16BIT_MASK_PERIOD_REG CYREG_UDB_W16_MSK_00
#define SPIM_BSPIM_BitCounter__16BIT_PERIOD_MASK_REG CYREG_UDB_W16_MSK_00
#define SPIM_BSPIM_BitCounter__16BIT_PERIOD_PERIOD_REG CYREG_UDB_W16_MSK_00
#define SPIM_BSPIM_BitCounter__32BIT_CONTROL_AUX_CTL_REG CYREG_UDB_W32_ACTL_00
#define SPIM_BSPIM_BitCounter__32BIT_CONTROL_REG CYREG_UDB_W32_CTL_00
#define SPIM_BSPIM_BitCounter__32BIT_COUNT_REG CYREG_UDB_W32_CTL_00
#define SPIM_BSPIM_BitCounter__32BIT_PERIOD_REG CYREG_UDB_W32_MSK_00
#define SPIM_BSPIM_BitCounter__CONTROL_AUX_CTL_REG CYREG_UDB_W8_ACTL_00
#define SPIM_BSPIM_BitCounter__CONTROL_REG CYREG_UDB_W8_CTL_00
#define SPIM_BSPIM_BitCounter__CONTROL_ST_REG CYREG_UDB_CAT16_CTL_ST_00
#define SPIM_BSPIM_BitCounter__COUNT_REG CYREG_UDB_W8_CTL_00
#define SPIM_BSPIM_BitCounter__COUNT_ST_REG CYREG_UDB_CAT16_CTL_ST_00
#define SPIM_BSPIM_BitCounter__MASK_CTL_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_00
#define SPIM_BSPIM_BitCounter__PER_CTL_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_00
#define SPIM_BSPIM_BitCounter__PERIOD_REG CYREG_UDB_W8_MSK_00
#define SPIM_BSPIM_BitCounter_ST__16BIT_STATUS_AUX_CTL_REG CYREG_UDB_W16_ACTL_00
#define SPIM_BSPIM_BitCounter_ST__16BIT_STATUS_REG CYREG_UDB_W16_ST_00
#define SPIM_BSPIM_BitCounter_ST__32BIT_MASK_REG CYREG_UDB_W32_MSK_00
#define SPIM_BSPIM_BitCounter_ST__32BIT_STATUS_AUX_CTL_REG CYREG_UDB_W32_ACTL_00
#define SPIM_BSPIM_BitCounter_ST__32BIT_STATUS_REG CYREG_UDB_W32_ST_00
#define SPIM_BSPIM_BitCounter_ST__MASK_REG CYREG_UDB_W8_MSK_00
#define SPIM_BSPIM_BitCounter_ST__MASK_ST_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_00
#define SPIM_BSPIM_BitCounter_ST__PER_ST_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_00
#define SPIM_BSPIM_BitCounter_ST__STATUS_AUX_CTL_REG CYREG_UDB_W8_ACTL_00
#define SPIM_BSPIM_BitCounter_ST__STATUS_CNT_REG CYREG_UDB_CAT16_CTL_ST_00
#define SPIM_BSPIM_BitCounter_ST__STATUS_CONTROL_REG CYREG_UDB_CAT16_CTL_ST_00
#define SPIM_BSPIM_BitCounter_ST__STATUS_REG CYREG_UDB_W8_ST_00
#define SPIM_BSPIM_RxStsReg__4__MASK 0x10u
#define SPIM_BSPIM_RxStsReg__4__POS 4
#define SPIM_BSPIM_RxStsReg__5__MASK 0x20u
#define SPIM_BSPIM_RxStsReg__5__POS 5
#define SPIM_BSPIM_RxStsReg__6__MASK 0x40u
#define SPIM_BSPIM_RxStsReg__6__POS 6
#define SPIM_BSPIM_RxStsReg__MASK 0x70u
#define SPIM_BSPIM_RxStsReg__MASK_REG CYREG_UDB_W8_MSK_03
#define SPIM_BSPIM_RxStsReg__STATUS_AUX_CTL_REG CYREG_UDB_W8_ACTL_03
#define SPIM_BSPIM_RxStsReg__STATUS_REG CYREG_UDB_W8_ST_03
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_A0_REG CYREG_UDB_W16_A0_00
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_A1_REG CYREG_UDB_W16_A1_00
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_D0_REG CYREG_UDB_W16_D0_00
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_D1_REG CYREG_UDB_W16_D1_00
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_DP_AUX_CTL_REG CYREG_UDB_W16_ACTL_00
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_F0_REG CYREG_UDB_W16_F0_00
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_F1_REG CYREG_UDB_W16_F1_00
#define SPIM_BSPIM_sR8_Dp_u0__32BIT_A0_REG CYREG_UDB_W32_A0_00
#define SPIM_BSPIM_sR8_Dp_u0__32BIT_A1_REG CYREG_UDB_W32_A1_00
#define SPIM_BSPIM_sR8_Dp_u0__32BIT_D0_REG CYREG_UDB_W32_D0_00
#define SPIM_BSPIM_sR8_Dp_u0__32BIT_D1_REG CYREG_UDB_W32_D1_00
#define SPIM_BSPIM_sR8_Dp_u0__32BIT_DP_AUX_CTL_REG CYREG_UDB_W32_ACTL_00
#define SPIM_BSPIM_sR8_Dp_u0__32BIT_F0_REG CYREG_UDB_W32_F0_00
#define SPIM_BSPIM_sR8_Dp_u0__32BIT_F1_REG CYREG_UDB_W32_F1_00
#define SPIM_BSPIM_sR8_Dp_u0__A0_A1_REG CYREG_UDB_CAT16_A_00
#define SPIM_BSPIM_sR8_Dp_u0__A0_REG CYREG_UDB_W8_A0_00
#define SPIM_BSPIM_sR8_Dp_u0__A1_REG CYREG_UDB_W8_A1_00
#define SPIM_BSPIM_sR8_Dp_u0__D0_D1_REG CYREG_UDB_CAT16_D_00
#define SPIM_BSPIM_sR8_Dp_u0__D0_REG CYREG_UDB_W8_D0_00
#define SPIM_BSPIM_sR8_Dp_u0__D1_REG CYREG_UDB_W8_D1_00
#define SPIM_BSPIM_sR8_Dp_u0__DP_AUX_CTL_REG CYREG_UDB_W8_ACTL_00
#define SPIM_BSPIM_sR8_Dp_u0__F0_F1_REG CYREG_UDB_CAT16_F_00
#define SPIM_BSPIM_sR8_Dp_u0__F0_REG CYREG_UDB_W8_F0_00
#define SPIM_BSPIM_sR8_Dp_u0__F1_REG CYREG_UDB_W8_F1_00
#define SPIM_BSPIM_sR8_Dp_u0__MSK_DP_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_00
#define SPIM_BSPIM_sR8_Dp_u0__PER_DP_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_00
#define SPIM_BSPIM_TxStsReg__0__MASK 0x01u
#define SPIM_BSPIM_TxStsReg__0__POS 0
#define SPIM_BSPIM_TxStsReg__1__MASK 0x02u
#define SPIM_BSPIM_TxStsReg__1__POS 1
#define SPIM_BSPIM_TxStsReg__16BIT_STATUS_AUX_CTL_REG CYREG_UDB_W16_ACTL_01
#define SPIM_BSPIM_TxStsReg__16BIT_STATUS_REG CYREG_UDB_W16_ST_01
#define SPIM_BSPIM_TxStsReg__2__MASK 0x04u
#define SPIM_BSPIM_TxStsReg__2__POS 2
#define SPIM_BSPIM_TxStsReg__3__MASK 0x08u
#define SPIM_BSPIM_TxStsReg__3__POS 3
#define SPIM_BSPIM_TxStsReg__4__MASK 0x10u
#define SPIM_BSPIM_TxStsReg__4__POS 4
#define SPIM_BSPIM_TxStsReg__MASK 0x1Fu
#define SPIM_BSPIM_TxStsReg__MASK_REG CYREG_UDB_W8_MSK_01
#define SPIM_BSPIM_TxStsReg__STATUS_AUX_CTL_REG CYREG_UDB_W8_ACTL_01
#define SPIM_BSPIM_TxStsReg__STATUS_REG CYREG_UDB_W8_ST_01

/* SPIM_IntClock */
#define SPIM_IntClock__DIVIDER_MASK 0x0000FFFFu
#define SPIM_IntClock__ENABLE CYREG_CLK_DIVIDER_A00
#define SPIM_IntClock__ENABLE_MASK 0x80000000u
#define SPIM_IntClock__MASK 0x80000000u
#define SPIM_IntClock__REGISTER CYREG_CLK_DIVIDER_A00

/* PWM_1_PWMUDB */
#define PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG CYREG_UDB_W16_ACTL_02
#define PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG CYREG_UDB_W16_CTL_02
#define PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG CYREG_UDB_W16_CTL_02
#define PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG CYREG_UDB_W16_CTL_02
#define PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG CYREG_UDB_W16_CTL_02
#define PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG CYREG_UDB_W16_MSK_02
#define PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG CYREG_UDB_W16_MSK_02
#define PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG CYREG_UDB_W16_MSK_02
#define PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG CYREG_UDB_W16_MSK_02
#define PWM_1_PWMUDB_genblk1_ctrlreg__7__MASK 0x80u
#define PWM_1_PWMUDB_genblk1_ctrlreg__7__POS 7
#define PWM_1_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG CYREG_UDB_W8_ACTL_02
#define PWM_1_PWMUDB_genblk1_ctrlreg__CONTROL_REG CYREG_UDB_W8_CTL_02
#define PWM_1_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG CYREG_UDB_CAT16_CTL_ST_02
#define PWM_1_PWMUDB_genblk1_ctrlreg__COUNT_REG CYREG_UDB_W8_CTL_02
#define PWM_1_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG CYREG_UDB_CAT16_CTL_ST_02
#define PWM_1_PWMUDB_genblk1_ctrlreg__MASK 0x80u
#define PWM_1_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_02
#define PWM_1_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_02
#define PWM_1_PWMUDB_genblk1_ctrlreg__PERIOD_REG CYREG_UDB_W8_MSK_02
#define PWM_1_PWMUDB_genblk8_stsreg__0__MASK 0x01u
#define PWM_1_PWMUDB_genblk8_stsreg__0__POS 0
#define PWM_1_PWMUDB_genblk8_stsreg__1__MASK 0x02u
#define PWM_1_PWMUDB_genblk8_stsreg__1__POS 1
#define PWM_1_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG CYREG_UDB_W16_ACTL_02
#define PWM_1_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG CYREG_UDB_W16_ST_02
#define PWM_1_PWMUDB_genblk8_stsreg__2__MASK 0x04u
#define PWM_1_PWMUDB_genblk8_stsreg__2__POS 2
#define PWM_1_PWMUDB_genblk8_stsreg__3__MASK 0x08u
#define PWM_1_PWMUDB_genblk8_stsreg__3__POS 3
#define PWM_1_PWMUDB_genblk8_stsreg__MASK 0x0Fu
#define PWM_1_PWMUDB_genblk8_stsreg__MASK_REG CYREG_UDB_W8_MSK_02
#define PWM_1_PWMUDB_genblk8_stsreg__MASK_ST_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_02
#define PWM_1_PWMUDB_genblk8_stsreg__PER_ST_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_02
#define PWM_1_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG CYREG_UDB_W8_ACTL_02
#define PWM_1_PWMUDB_genblk8_stsreg__STATUS_CNT_REG CYREG_UDB_CAT16_CTL_ST_02
#define PWM_1_PWMUDB_genblk8_stsreg__STATUS_CONTROL_REG CYREG_UDB_CAT16_CTL_ST_02
#define PWM_1_PWMUDB_genblk8_stsreg__STATUS_REG CYREG_UDB_W8_ST_02
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG CYREG_UDB_W16_A0_02
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG CYREG_UDB_W16_A1_02
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG CYREG_UDB_W16_D0_02
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG CYREG_UDB_W16_D1_02
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_DP_AUX_CTL_REG CYREG_UDB_W16_ACTL_02
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG CYREG_UDB_W16_F0_02
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG CYREG_UDB_W16_F1_02
#define PWM_1_PWMUDB_sP16_pwmdp_u0__A0_A1_REG CYREG_UDB_CAT16_A_02
#define PWM_1_PWMUDB_sP16_pwmdp_u0__A0_REG CYREG_UDB_W8_A0_02
#define PWM_1_PWMUDB_sP16_pwmdp_u0__A1_REG CYREG_UDB_W8_A1_02
#define PWM_1_PWMUDB_sP16_pwmdp_u0__D0_D1_REG CYREG_UDB_CAT16_D_02
#define PWM_1_PWMUDB_sP16_pwmdp_u0__D0_REG CYREG_UDB_W8_D0_02
#define PWM_1_PWMUDB_sP16_pwmdp_u0__D1_REG CYREG_UDB_W8_D1_02
#define PWM_1_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG CYREG_UDB_W8_ACTL_02
#define PWM_1_PWMUDB_sP16_pwmdp_u0__F0_F1_REG CYREG_UDB_CAT16_F_02
#define PWM_1_PWMUDB_sP16_pwmdp_u0__F0_REG CYREG_UDB_W8_F0_02
#define PWM_1_PWMUDB_sP16_pwmdp_u0__F1_REG CYREG_UDB_W8_F1_02
#define PWM_1_PWMUDB_sP16_pwmdp_u0__MSK_DP_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_02
#define PWM_1_PWMUDB_sP16_pwmdp_u0__PER_DP_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_02
#define PWM_1_PWMUDB_sP16_pwmdp_u1__A0_A1_REG CYREG_UDB_CAT16_A_03
#define PWM_1_PWMUDB_sP16_pwmdp_u1__A0_REG CYREG_UDB_W8_A0_03
#define PWM_1_PWMUDB_sP16_pwmdp_u1__A1_REG CYREG_UDB_W8_A1_03
#define PWM_1_PWMUDB_sP16_pwmdp_u1__D0_D1_REG CYREG_UDB_CAT16_D_03
#define PWM_1_PWMUDB_sP16_pwmdp_u1__D0_REG CYREG_UDB_W8_D0_03
#define PWM_1_PWMUDB_sP16_pwmdp_u1__D1_REG CYREG_UDB_W8_D1_03
#define PWM_1_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG CYREG_UDB_W8_ACTL_03
#define PWM_1_PWMUDB_sP16_pwmdp_u1__F0_F1_REG CYREG_UDB_CAT16_F_03
#define PWM_1_PWMUDB_sP16_pwmdp_u1__F0_REG CYREG_UDB_W8_F0_03
#define PWM_1_PWMUDB_sP16_pwmdp_u1__F1_REG CYREG_UDB_W8_F1_03

/* isr_1 */
#define isr_1__INTC_CLR_EN_REG CYREG_CM0_ICER
#define isr_1__INTC_CLR_PD_REG CYREG_CM0_ICPR
#define isr_1__INTC_MASK 0x10000u
#define isr_1__INTC_NUMBER 16u
#define isr_1__INTC_PRIOR_MASK 0xC0u
#define isr_1__INTC_PRIOR_NUM 3u
#define isr_1__INTC_PRIOR_REG CYREG_CM0_IPR4
#define isr_1__INTC_SET_EN_REG CYREG_CM0_ISER
#define isr_1__INTC_SET_PD_REG CYREG_CM0_ISPR

/* servo */
#define servo__0__DM__MASK 0x07u
#define servo__0__DM__SHIFT 0
#define servo__0__DR CYREG_PRT1_DR
#define servo__0__HSIOM CYREG_HSIOM_PORT_SEL1
#define servo__0__HSIOM_MASK 0x0000000Fu
#define servo__0__HSIOM_SHIFT 0u
#define servo__0__INTCFG CYREG_PRT1_INTCFG
#define servo__0__INTSTAT CYREG_PRT1_INTSTAT
#define servo__0__MASK 0x01u
#define servo__0__OUT_SEL CYREG_UDB_PA1_CFG10
#define servo__0__OUT_SEL_SHIFT 0u
#define servo__0__OUT_SEL_VAL 0u
#define servo__0__PA__CFG0 CYREG_UDB_PA1_CFG0
#define servo__0__PA__CFG1 CYREG_UDB_PA1_CFG1
#define servo__0__PA__CFG10 CYREG_UDB_PA1_CFG10
#define servo__0__PA__CFG11 CYREG_UDB_PA1_CFG11
#define servo__0__PA__CFG12 CYREG_UDB_PA1_CFG12
#define servo__0__PA__CFG13 CYREG_UDB_PA1_CFG13
#define servo__0__PA__CFG14 CYREG_UDB_PA1_CFG14
#define servo__0__PA__CFG2 CYREG_UDB_PA1_CFG2
#define servo__0__PA__CFG3 CYREG_UDB_PA1_CFG3
#define servo__0__PA__CFG4 CYREG_UDB_PA1_CFG4
#define servo__0__PA__CFG5 CYREG_UDB_PA1_CFG5
#define servo__0__PA__CFG6 CYREG_UDB_PA1_CFG6
#define servo__0__PA__CFG7 CYREG_UDB_PA1_CFG7
#define servo__0__PA__CFG8 CYREG_UDB_PA1_CFG8
#define servo__0__PA__CFG9 CYREG_UDB_PA1_CFG9
#define servo__0__PC CYREG_PRT1_PC
#define servo__0__PC2 CYREG_PRT1_PC2
#define servo__0__PORT 1u
#define servo__0__PS CYREG_PRT1_PS
#define servo__0__SHIFT 0
#define servo__DR CYREG_PRT1_DR
#define servo__INTCFG CYREG_PRT1_INTCFG
#define servo__INTSTAT CYREG_PRT1_INTSTAT
#define servo__MASK 0x01u
#define servo__PA__CFG0 CYREG_UDB_PA1_CFG0
#define servo__PA__CFG1 CYREG_UDB_PA1_CFG1
#define servo__PA__CFG10 CYREG_UDB_PA1_CFG10
#define servo__PA__CFG11 CYREG_UDB_PA1_CFG11
#define servo__PA__CFG12 CYREG_UDB_PA1_CFG12
#define servo__PA__CFG13 CYREG_UDB_PA1_CFG13
#define servo__PA__CFG14 CYREG_UDB_PA1_CFG14
#define servo__PA__CFG2 CYREG_UDB_PA1_CFG2
#define servo__PA__CFG3 CYREG_UDB_PA1_CFG3
#define servo__PA__CFG4 CYREG_UDB_PA1_CFG4
#define servo__PA__CFG5 CYREG_UDB_PA1_CFG5
#define servo__PA__CFG6 CYREG_UDB_PA1_CFG6
#define servo__PA__CFG7 CYREG_UDB_PA1_CFG7
#define servo__PA__CFG8 CYREG_UDB_PA1_CFG8
#define servo__PA__CFG9 CYREG_UDB_PA1_CFG9
#define servo__PC CYREG_PRT1_PC
#define servo__PC2 CYREG_PRT1_PC2
#define servo__PORT 1u
#define servo__PS CYREG_PRT1_PS
#define servo__SHIFT 0

/* WIZ_SS */
#define WIZ_SS__0__DM__MASK 0xE00u
#define WIZ_SS__0__DM__SHIFT 9
#define WIZ_SS__0__DR CYREG_PRT0_DR
#define WIZ_SS__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define WIZ_SS__0__HSIOM_MASK 0x0000F000u
#define WIZ_SS__0__HSIOM_SHIFT 12u
#define WIZ_SS__0__INTCFG CYREG_PRT0_INTCFG
#define WIZ_SS__0__INTSTAT CYREG_PRT0_INTSTAT
#define WIZ_SS__0__MASK 0x08u
#define WIZ_SS__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define WIZ_SS__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define WIZ_SS__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define WIZ_SS__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define WIZ_SS__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define WIZ_SS__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define WIZ_SS__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define WIZ_SS__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define WIZ_SS__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define WIZ_SS__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define WIZ_SS__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define WIZ_SS__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define WIZ_SS__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define WIZ_SS__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define WIZ_SS__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define WIZ_SS__0__PC CYREG_PRT0_PC
#define WIZ_SS__0__PC2 CYREG_PRT0_PC2
#define WIZ_SS__0__PORT 0u
#define WIZ_SS__0__PS CYREG_PRT0_PS
#define WIZ_SS__0__SHIFT 3
#define WIZ_SS__DR CYREG_PRT0_DR
#define WIZ_SS__INTCFG CYREG_PRT0_INTCFG
#define WIZ_SS__INTSTAT CYREG_PRT0_INTSTAT
#define WIZ_SS__MASK 0x08u
#define WIZ_SS__PA__CFG0 CYREG_UDB_PA0_CFG0
#define WIZ_SS__PA__CFG1 CYREG_UDB_PA0_CFG1
#define WIZ_SS__PA__CFG10 CYREG_UDB_PA0_CFG10
#define WIZ_SS__PA__CFG11 CYREG_UDB_PA0_CFG11
#define WIZ_SS__PA__CFG12 CYREG_UDB_PA0_CFG12
#define WIZ_SS__PA__CFG13 CYREG_UDB_PA0_CFG13
#define WIZ_SS__PA__CFG14 CYREG_UDB_PA0_CFG14
#define WIZ_SS__PA__CFG2 CYREG_UDB_PA0_CFG2
#define WIZ_SS__PA__CFG3 CYREG_UDB_PA0_CFG3
#define WIZ_SS__PA__CFG4 CYREG_UDB_PA0_CFG4
#define WIZ_SS__PA__CFG5 CYREG_UDB_PA0_CFG5
#define WIZ_SS__PA__CFG6 CYREG_UDB_PA0_CFG6
#define WIZ_SS__PA__CFG7 CYREG_UDB_PA0_CFG7
#define WIZ_SS__PA__CFG8 CYREG_UDB_PA0_CFG8
#define WIZ_SS__PA__CFG9 CYREG_UDB_PA0_CFG9
#define WIZ_SS__PC CYREG_PRT0_PC
#define WIZ_SS__PC2 CYREG_PRT0_PC2
#define WIZ_SS__PORT 0u
#define WIZ_SS__PS CYREG_PRT0_PS
#define WIZ_SS__SHIFT 3

/* Timer_1_cy_m0s8_tcpwm_1 */
#define Timer_1_cy_m0s8_tcpwm_1__CC CYREG_TCPWM_CNT0_CC
#define Timer_1_cy_m0s8_tcpwm_1__CC_BUFF CYREG_TCPWM_CNT0_CC_BUFF
#define Timer_1_cy_m0s8_tcpwm_1__COUNTER CYREG_TCPWM_CNT0_COUNTER
#define Timer_1_cy_m0s8_tcpwm_1__CTRL CYREG_TCPWM_CNT0_CTRL
#define Timer_1_cy_m0s8_tcpwm_1__INTR CYREG_TCPWM_CNT0_INTR
#define Timer_1_cy_m0s8_tcpwm_1__INTR_MASK CYREG_TCPWM_CNT0_INTR_MASK
#define Timer_1_cy_m0s8_tcpwm_1__INTR_MASKED CYREG_TCPWM_CNT0_INTR_MASKED
#define Timer_1_cy_m0s8_tcpwm_1__INTR_SET CYREG_TCPWM_CNT0_INTR_SET
#define Timer_1_cy_m0s8_tcpwm_1__PERIOD CYREG_TCPWM_CNT0_PERIOD
#define Timer_1_cy_m0s8_tcpwm_1__PERIOD_BUFF CYREG_TCPWM_CNT0_PERIOD_BUFF
#define Timer_1_cy_m0s8_tcpwm_1__STATUS CYREG_TCPWM_CNT0_STATUS
#define Timer_1_cy_m0s8_tcpwm_1__TCPWM_CMD CYREG_TCPWM_CMD
#define Timer_1_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK 0x01u
#define Timer_1_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT 0
#define Timer_1_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK 0x100u
#define Timer_1_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT 8
#define Timer_1_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK 0x1000000u
#define Timer_1_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT 24
#define Timer_1_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK 0x10000u
#define Timer_1_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT 16
#define Timer_1_cy_m0s8_tcpwm_1__TCPWM_CTRL CYREG_TCPWM_CTRL
#define Timer_1_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK 0x01u
#define Timer_1_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT 0
#define Timer_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE CYREG_TCPWM_INTR_CAUSE
#define Timer_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK 0x01u
#define Timer_1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT 0
#define Timer_1_cy_m0s8_tcpwm_1__TCPWM_NUMBER 0u
#define Timer_1_cy_m0s8_tcpwm_1__TR_CTRL0 CYREG_TCPWM_CNT0_TR_CTRL0
#define Timer_1_cy_m0s8_tcpwm_1__TR_CTRL1 CYREG_TCPWM_CNT0_TR_CTRL1
#define Timer_1_cy_m0s8_tcpwm_1__TR_CTRL2 CYREG_TCPWM_CNT0_TR_CTRL2

/* WIZ_INT */
#define WIZ_INT__0__DM__MASK 0x07u
#define WIZ_INT__0__DM__SHIFT 0
#define WIZ_INT__0__DR CYREG_PRT0_DR
#define WIZ_INT__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define WIZ_INT__0__HSIOM_MASK 0x0000000Fu
#define WIZ_INT__0__HSIOM_SHIFT 0u
#define WIZ_INT__0__INTCFG CYREG_PRT0_INTCFG
#define WIZ_INT__0__INTSTAT CYREG_PRT0_INTSTAT
#define WIZ_INT__0__MASK 0x01u
#define WIZ_INT__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define WIZ_INT__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define WIZ_INT__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define WIZ_INT__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define WIZ_INT__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define WIZ_INT__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define WIZ_INT__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define WIZ_INT__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define WIZ_INT__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define WIZ_INT__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define WIZ_INT__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define WIZ_INT__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define WIZ_INT__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define WIZ_INT__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define WIZ_INT__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define WIZ_INT__0__PC CYREG_PRT0_PC
#define WIZ_INT__0__PC2 CYREG_PRT0_PC2
#define WIZ_INT__0__PORT 0u
#define WIZ_INT__0__PS CYREG_PRT0_PS
#define WIZ_INT__0__SHIFT 0
#define WIZ_INT__DR CYREG_PRT0_DR
#define WIZ_INT__INTCFG CYREG_PRT0_INTCFG
#define WIZ_INT__INTSTAT CYREG_PRT0_INTSTAT
#define WIZ_INT__MASK 0x01u
#define WIZ_INT__PA__CFG0 CYREG_UDB_PA0_CFG0
#define WIZ_INT__PA__CFG1 CYREG_UDB_PA0_CFG1
#define WIZ_INT__PA__CFG10 CYREG_UDB_PA0_CFG10
#define WIZ_INT__PA__CFG11 CYREG_UDB_PA0_CFG11
#define WIZ_INT__PA__CFG12 CYREG_UDB_PA0_CFG12
#define WIZ_INT__PA__CFG13 CYREG_UDB_PA0_CFG13
#define WIZ_INT__PA__CFG14 CYREG_UDB_PA0_CFG14
#define WIZ_INT__PA__CFG2 CYREG_UDB_PA0_CFG2
#define WIZ_INT__PA__CFG3 CYREG_UDB_PA0_CFG3
#define WIZ_INT__PA__CFG4 CYREG_UDB_PA0_CFG4
#define WIZ_INT__PA__CFG5 CYREG_UDB_PA0_CFG5
#define WIZ_INT__PA__CFG6 CYREG_UDB_PA0_CFG6
#define WIZ_INT__PA__CFG7 CYREG_UDB_PA0_CFG7
#define WIZ_INT__PA__CFG8 CYREG_UDB_PA0_CFG8
#define WIZ_INT__PA__CFG9 CYREG_UDB_PA0_CFG9
#define WIZ_INT__PC CYREG_PRT0_PC
#define WIZ_INT__PC2 CYREG_PRT0_PC2
#define WIZ_INT__PORT 0u
#define WIZ_INT__PS CYREG_PRT0_PS
#define WIZ_INT__SHIFT 0

/* WIZ_RDY */
#define WIZ_RDY__0__DM__MASK 0x38u
#define WIZ_RDY__0__DM__SHIFT 3
#define WIZ_RDY__0__DR CYREG_PRT0_DR
#define WIZ_RDY__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define WIZ_RDY__0__HSIOM_MASK 0x000000F0u
#define WIZ_RDY__0__HSIOM_SHIFT 4u
#define WIZ_RDY__0__INTCFG CYREG_PRT0_INTCFG
#define WIZ_RDY__0__INTSTAT CYREG_PRT0_INTSTAT
#define WIZ_RDY__0__MASK 0x02u
#define WIZ_RDY__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define WIZ_RDY__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define WIZ_RDY__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define WIZ_RDY__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define WIZ_RDY__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define WIZ_RDY__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define WIZ_RDY__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define WIZ_RDY__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define WIZ_RDY__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define WIZ_RDY__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define WIZ_RDY__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define WIZ_RDY__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define WIZ_RDY__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define WIZ_RDY__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define WIZ_RDY__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define WIZ_RDY__0__PC CYREG_PRT0_PC
#define WIZ_RDY__0__PC2 CYREG_PRT0_PC2
#define WIZ_RDY__0__PORT 0u
#define WIZ_RDY__0__PS CYREG_PRT0_PS
#define WIZ_RDY__0__SHIFT 1
#define WIZ_RDY__DR CYREG_PRT0_DR
#define WIZ_RDY__INTCFG CYREG_PRT0_INTCFG
#define WIZ_RDY__INTSTAT CYREG_PRT0_INTSTAT
#define WIZ_RDY__MASK 0x02u
#define WIZ_RDY__PA__CFG0 CYREG_UDB_PA0_CFG0
#define WIZ_RDY__PA__CFG1 CYREG_UDB_PA0_CFG1
#define WIZ_RDY__PA__CFG10 CYREG_UDB_PA0_CFG10
#define WIZ_RDY__PA__CFG11 CYREG_UDB_PA0_CFG11
#define WIZ_RDY__PA__CFG12 CYREG_UDB_PA0_CFG12
#define WIZ_RDY__PA__CFG13 CYREG_UDB_PA0_CFG13
#define WIZ_RDY__PA__CFG14 CYREG_UDB_PA0_CFG14
#define WIZ_RDY__PA__CFG2 CYREG_UDB_PA0_CFG2
#define WIZ_RDY__PA__CFG3 CYREG_UDB_PA0_CFG3
#define WIZ_RDY__PA__CFG4 CYREG_UDB_PA0_CFG4
#define WIZ_RDY__PA__CFG5 CYREG_UDB_PA0_CFG5
#define WIZ_RDY__PA__CFG6 CYREG_UDB_PA0_CFG6
#define WIZ_RDY__PA__CFG7 CYREG_UDB_PA0_CFG7
#define WIZ_RDY__PA__CFG8 CYREG_UDB_PA0_CFG8
#define WIZ_RDY__PA__CFG9 CYREG_UDB_PA0_CFG9
#define WIZ_RDY__PC CYREG_PRT0_PC
#define WIZ_RDY__PC2 CYREG_PRT0_PC2
#define WIZ_RDY__PORT 0u
#define WIZ_RDY__PS CYREG_PRT0_PS
#define WIZ_RDY__SHIFT 1

/* WIZ_RST */
#define WIZ_RST__0__DM__MASK 0x1C0u
#define WIZ_RST__0__DM__SHIFT 6
#define WIZ_RST__0__DR CYREG_PRT0_DR
#define WIZ_RST__0__HSIOM CYREG_HSIOM_PORT_SEL0
#define WIZ_RST__0__HSIOM_MASK 0x00000F00u
#define WIZ_RST__0__HSIOM_SHIFT 8u
#define WIZ_RST__0__INTCFG CYREG_PRT0_INTCFG
#define WIZ_RST__0__INTSTAT CYREG_PRT0_INTSTAT
#define WIZ_RST__0__MASK 0x04u
#define WIZ_RST__0__PA__CFG0 CYREG_UDB_PA0_CFG0
#define WIZ_RST__0__PA__CFG1 CYREG_UDB_PA0_CFG1
#define WIZ_RST__0__PA__CFG10 CYREG_UDB_PA0_CFG10
#define WIZ_RST__0__PA__CFG11 CYREG_UDB_PA0_CFG11
#define WIZ_RST__0__PA__CFG12 CYREG_UDB_PA0_CFG12
#define WIZ_RST__0__PA__CFG13 CYREG_UDB_PA0_CFG13
#define WIZ_RST__0__PA__CFG14 CYREG_UDB_PA0_CFG14
#define WIZ_RST__0__PA__CFG2 CYREG_UDB_PA0_CFG2
#define WIZ_RST__0__PA__CFG3 CYREG_UDB_PA0_CFG3
#define WIZ_RST__0__PA__CFG4 CYREG_UDB_PA0_CFG4
#define WIZ_RST__0__PA__CFG5 CYREG_UDB_PA0_CFG5
#define WIZ_RST__0__PA__CFG6 CYREG_UDB_PA0_CFG6
#define WIZ_RST__0__PA__CFG7 CYREG_UDB_PA0_CFG7
#define WIZ_RST__0__PA__CFG8 CYREG_UDB_PA0_CFG8
#define WIZ_RST__0__PA__CFG9 CYREG_UDB_PA0_CFG9
#define WIZ_RST__0__PC CYREG_PRT0_PC
#define WIZ_RST__0__PC2 CYREG_PRT0_PC2
#define WIZ_RST__0__PORT 0u
#define WIZ_RST__0__PS CYREG_PRT0_PS
#define WIZ_RST__0__SHIFT 2
#define WIZ_RST__DR CYREG_PRT0_DR
#define WIZ_RST__INTCFG CYREG_PRT0_INTCFG
#define WIZ_RST__INTSTAT CYREG_PRT0_INTSTAT
#define WIZ_RST__MASK 0x04u
#define WIZ_RST__PA__CFG0 CYREG_UDB_PA0_CFG0
#define WIZ_RST__PA__CFG1 CYREG_UDB_PA0_CFG1
#define WIZ_RST__PA__CFG10 CYREG_UDB_PA0_CFG10
#define WIZ_RST__PA__CFG11 CYREG_UDB_PA0_CFG11
#define WIZ_RST__PA__CFG12 CYREG_UDB_PA0_CFG12
#define WIZ_RST__PA__CFG13 CYREG_UDB_PA0_CFG13
#define WIZ_RST__PA__CFG14 CYREG_UDB_PA0_CFG14
#define WIZ_RST__PA__CFG2 CYREG_UDB_PA0_CFG2
#define WIZ_RST__PA__CFG3 CYREG_UDB_PA0_CFG3
#define WIZ_RST__PA__CFG4 CYREG_UDB_PA0_CFG4
#define WIZ_RST__PA__CFG5 CYREG_UDB_PA0_CFG5
#define WIZ_RST__PA__CFG6 CYREG_UDB_PA0_CFG6
#define WIZ_RST__PA__CFG7 CYREG_UDB_PA0_CFG7
#define WIZ_RST__PA__CFG8 CYREG_UDB_PA0_CFG8
#define WIZ_RST__PA__CFG9 CYREG_UDB_PA0_CFG9
#define WIZ_RST__PC CYREG_PRT0_PC
#define WIZ_RST__PC2 CYREG_PRT0_PC2
#define WIZ_RST__PORT 0u
#define WIZ_RST__PS CYREG_PRT0_PS
#define WIZ_RST__SHIFT 2

/* Clock_pwm */
#define Clock_pwm__DIVIDER_MASK 0x0000FFFFu
#define Clock_pwm__ENABLE CYREG_CLK_DIVIDER_C00
#define Clock_pwm__ENABLE_MASK 0x80000000u
#define Clock_pwm__MASK 0x80000000u
#define Clock_pwm__REGISTER CYREG_CLK_DIVIDER_C00

/* Clock_counter */
#define Clock_counter__DIVIDER_MASK 0x0000FFFFu
#define Clock_counter__ENABLE CYREG_CLK_DIVIDER_B00
#define Clock_counter__ENABLE_MASK 0x80000000u
#define Clock_counter__MASK 0x80000000u
#define Clock_counter__REGISTER CYREG_CLK_DIVIDER_B00

/* Miscellaneous */
#define CY_VERSION "PSoC Creator  3.1"
#define CYDEV_BCLK__HFCLK__HZ 24000000U
#define CYDEV_BCLK__HFCLK__KHZ 24000U
#define CYDEV_BCLK__HFCLK__MHZ 24U
#define CYDEV_BCLK__SYSCLK__HZ 24000000U
#define CYDEV_BCLK__SYSCLK__KHZ 24000U
#define CYDEV_BCLK__SYSCLK__MHZ 24U
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PANTHER 6u
#define CYDEV_CHIP_DIE_PSOC4A 3u
#define CYDEV_CHIP_DIE_PSOC5LP 5u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC4
#define CYDEV_CHIP_JTAG_ID 0x04C81193u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 3u
#define CYDEV_CHIP_MEMBER_4D 2u
#define CYDEV_CHIP_MEMBER_4F 4u
#define CYDEV_CHIP_MEMBER_5A 6u
#define CYDEV_CHIP_MEMBER_5B 5u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_4A
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PANTHER_ES0 0u
#define CYDEV_CHIP_REV_PANTHER_ES1 1u
#define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_4A_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_READ_ACCELERATOR 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_PROTECT_KILL 4
#define CYDEV_DEBUG_PROTECT_OPEN 1
#define CYDEV_DEBUG_PROTECT CYDEV_DEBUG_PROTECT_OPEN
#define CYDEV_DEBUG_PROTECT_PROTECTED 2
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_PROJ_TYPE 2
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_STACK_SIZE 0x0400
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 1
#define CYDEV_VDDA 3.3
#define CYDEV_VDDA_MV 3300
#define CYDEV_VDDD 3.3
#define CYDEV_VDDD_MV 3300
#define CYIPBLOCK_M0S8_CTBM_VERSION 0
#define CYIPBLOCK_m0s8cpuss_VERSION 0
#define CYIPBLOCK_m0s8csd_VERSION 0
#define CYIPBLOCK_m0s8gpio2_VERSION 0
#define CYIPBLOCK_m0s8hsiom4a_VERSION 0
#define CYIPBLOCK_m0s8lcd_VERSION 0
#define CYIPBLOCK_m0s8lpcomp_VERSION 0
#define CYIPBLOCK_m0s8pclk_VERSION 0
#define CYIPBLOCK_m0s8sar_VERSION 0
#define CYIPBLOCK_m0s8scb_VERSION 0
#define CYIPBLOCK_m0s8srssv2_VERSION 1
#define CYIPBLOCK_m0s8tcpwm_VERSION 0
#define CYIPBLOCK_m0s8udbif_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 2
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
