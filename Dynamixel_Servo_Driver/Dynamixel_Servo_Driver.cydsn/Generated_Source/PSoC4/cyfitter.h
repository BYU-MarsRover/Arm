#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include <cydevice_trm.h>

/* ISR */
#define ISR__INTC_CLR_EN_REG CYREG_CM0_ICER
#define ISR__INTC_CLR_PD_REG CYREG_CM0_ICPR
#define ISR__INTC_MASK 0x10000u
#define ISR__INTC_NUMBER 16u
#define ISR__INTC_PRIOR_MASK 0xC0u
#define ISR__INTC_PRIOR_NUM 3u
#define ISR__INTC_PRIOR_REG CYREG_CM0_IPR4
#define ISR__INTC_SET_EN_REG CYREG_CM0_ISER
#define ISR__INTC_SET_PD_REG CYREG_CM0_ISPR

/* ISR_1 */
#define ISR_1__INTC_CLR_EN_REG CYREG_CM0_ICER
#define ISR_1__INTC_CLR_PD_REG CYREG_CM0_ICPR
#define ISR_1__INTC_MASK 0x20000u
#define ISR_1__INTC_NUMBER 17u
#define ISR_1__INTC_PRIOR_MASK 0xC000u
#define ISR_1__INTC_PRIOR_NUM 3u
#define ISR_1__INTC_PRIOR_REG CYREG_CM0_IPR4
#define ISR_1__INTC_SET_EN_REG CYREG_CM0_ISER
#define ISR_1__INTC_SET_PD_REG CYREG_CM0_ISPR

/* LED */
#define LED__0__DM__MASK 0x1C0000u
#define LED__0__DM__SHIFT 18
#define LED__0__DR CYREG_PRT1_DR
#define LED__0__HSIOM CYREG_HSIOM_PORT_SEL1
#define LED__0__HSIOM_MASK 0x0F000000u
#define LED__0__HSIOM_SHIFT 24u
#define LED__0__INTCFG CYREG_PRT1_INTCFG
#define LED__0__INTSTAT CYREG_PRT1_INTSTAT
#define LED__0__MASK 0x40u
#define LED__0__PA__CFG0 CYREG_UDB_PA1_CFG0
#define LED__0__PA__CFG1 CYREG_UDB_PA1_CFG1
#define LED__0__PA__CFG10 CYREG_UDB_PA1_CFG10
#define LED__0__PA__CFG11 CYREG_UDB_PA1_CFG11
#define LED__0__PA__CFG12 CYREG_UDB_PA1_CFG12
#define LED__0__PA__CFG13 CYREG_UDB_PA1_CFG13
#define LED__0__PA__CFG14 CYREG_UDB_PA1_CFG14
#define LED__0__PA__CFG2 CYREG_UDB_PA1_CFG2
#define LED__0__PA__CFG3 CYREG_UDB_PA1_CFG3
#define LED__0__PA__CFG4 CYREG_UDB_PA1_CFG4
#define LED__0__PA__CFG5 CYREG_UDB_PA1_CFG5
#define LED__0__PA__CFG6 CYREG_UDB_PA1_CFG6
#define LED__0__PA__CFG7 CYREG_UDB_PA1_CFG7
#define LED__0__PA__CFG8 CYREG_UDB_PA1_CFG8
#define LED__0__PA__CFG9 CYREG_UDB_PA1_CFG9
#define LED__0__PC CYREG_PRT1_PC
#define LED__0__PC2 CYREG_PRT1_PC2
#define LED__0__PORT 1u
#define LED__0__PS CYREG_PRT1_PS
#define LED__0__SHIFT 6
#define LED__DR CYREG_PRT1_DR
#define LED__INTCFG CYREG_PRT1_INTCFG
#define LED__INTSTAT CYREG_PRT1_INTSTAT
#define LED__MASK 0x40u
#define LED__PA__CFG0 CYREG_UDB_PA1_CFG0
#define LED__PA__CFG1 CYREG_UDB_PA1_CFG1
#define LED__PA__CFG10 CYREG_UDB_PA1_CFG10
#define LED__PA__CFG11 CYREG_UDB_PA1_CFG11
#define LED__PA__CFG12 CYREG_UDB_PA1_CFG12
#define LED__PA__CFG13 CYREG_UDB_PA1_CFG13
#define LED__PA__CFG14 CYREG_UDB_PA1_CFG14
#define LED__PA__CFG2 CYREG_UDB_PA1_CFG2
#define LED__PA__CFG3 CYREG_UDB_PA1_CFG3
#define LED__PA__CFG4 CYREG_UDB_PA1_CFG4
#define LED__PA__CFG5 CYREG_UDB_PA1_CFG5
#define LED__PA__CFG6 CYREG_UDB_PA1_CFG6
#define LED__PA__CFG7 CYREG_UDB_PA1_CFG7
#define LED__PA__CFG8 CYREG_UDB_PA1_CFG8
#define LED__PA__CFG9 CYREG_UDB_PA1_CFG9
#define LED__PC CYREG_PRT1_PC
#define LED__PC2 CYREG_PRT1_PC2
#define LED__PORT 1u
#define LED__PS CYREG_PRT1_PS
#define LED__SHIFT 6

/* UART_2_SCB */
#define UART_2_SCB__BIST_CONTROL CYREG_SCB0_BIST_CONTROL
#define UART_2_SCB__BIST_DATA CYREG_SCB0_BIST_DATA
#define UART_2_SCB__CTRL CYREG_SCB0_CTRL
#define UART_2_SCB__EZ_DATA00 CYREG_SCB0_EZ_DATA00
#define UART_2_SCB__EZ_DATA01 CYREG_SCB0_EZ_DATA01
#define UART_2_SCB__EZ_DATA02 CYREG_SCB0_EZ_DATA02
#define UART_2_SCB__EZ_DATA03 CYREG_SCB0_EZ_DATA03
#define UART_2_SCB__EZ_DATA04 CYREG_SCB0_EZ_DATA04
#define UART_2_SCB__EZ_DATA05 CYREG_SCB0_EZ_DATA05
#define UART_2_SCB__EZ_DATA06 CYREG_SCB0_EZ_DATA06
#define UART_2_SCB__EZ_DATA07 CYREG_SCB0_EZ_DATA07
#define UART_2_SCB__EZ_DATA08 CYREG_SCB0_EZ_DATA08
#define UART_2_SCB__EZ_DATA09 CYREG_SCB0_EZ_DATA09
#define UART_2_SCB__EZ_DATA10 CYREG_SCB0_EZ_DATA10
#define UART_2_SCB__EZ_DATA11 CYREG_SCB0_EZ_DATA11
#define UART_2_SCB__EZ_DATA12 CYREG_SCB0_EZ_DATA12
#define UART_2_SCB__EZ_DATA13 CYREG_SCB0_EZ_DATA13
#define UART_2_SCB__EZ_DATA14 CYREG_SCB0_EZ_DATA14
#define UART_2_SCB__EZ_DATA15 CYREG_SCB0_EZ_DATA15
#define UART_2_SCB__EZ_DATA16 CYREG_SCB0_EZ_DATA16
#define UART_2_SCB__EZ_DATA17 CYREG_SCB0_EZ_DATA17
#define UART_2_SCB__EZ_DATA18 CYREG_SCB0_EZ_DATA18
#define UART_2_SCB__EZ_DATA19 CYREG_SCB0_EZ_DATA19
#define UART_2_SCB__EZ_DATA20 CYREG_SCB0_EZ_DATA20
#define UART_2_SCB__EZ_DATA21 CYREG_SCB0_EZ_DATA21
#define UART_2_SCB__EZ_DATA22 CYREG_SCB0_EZ_DATA22
#define UART_2_SCB__EZ_DATA23 CYREG_SCB0_EZ_DATA23
#define UART_2_SCB__EZ_DATA24 CYREG_SCB0_EZ_DATA24
#define UART_2_SCB__EZ_DATA25 CYREG_SCB0_EZ_DATA25
#define UART_2_SCB__EZ_DATA26 CYREG_SCB0_EZ_DATA26
#define UART_2_SCB__EZ_DATA27 CYREG_SCB0_EZ_DATA27
#define UART_2_SCB__EZ_DATA28 CYREG_SCB0_EZ_DATA28
#define UART_2_SCB__EZ_DATA29 CYREG_SCB0_EZ_DATA29
#define UART_2_SCB__EZ_DATA30 CYREG_SCB0_EZ_DATA30
#define UART_2_SCB__EZ_DATA31 CYREG_SCB0_EZ_DATA31
#define UART_2_SCB__I2C_CFG CYREG_SCB0_I2C_CFG
#define UART_2_SCB__I2C_CTRL CYREG_SCB0_I2C_CTRL
#define UART_2_SCB__I2C_M_CMD CYREG_SCB0_I2C_M_CMD
#define UART_2_SCB__I2C_S_CMD CYREG_SCB0_I2C_S_CMD
#define UART_2_SCB__I2C_STATUS CYREG_SCB0_I2C_STATUS
#define UART_2_SCB__INTR_CAUSE CYREG_SCB0_INTR_CAUSE
#define UART_2_SCB__INTR_I2C_EC CYREG_SCB0_INTR_I2C_EC
#define UART_2_SCB__INTR_I2C_EC_MASK CYREG_SCB0_INTR_I2C_EC_MASK
#define UART_2_SCB__INTR_I2C_EC_MASKED CYREG_SCB0_INTR_I2C_EC_MASKED
#define UART_2_SCB__INTR_M CYREG_SCB0_INTR_M
#define UART_2_SCB__INTR_M_MASK CYREG_SCB0_INTR_M_MASK
#define UART_2_SCB__INTR_M_MASKED CYREG_SCB0_INTR_M_MASKED
#define UART_2_SCB__INTR_M_SET CYREG_SCB0_INTR_M_SET
#define UART_2_SCB__INTR_RX CYREG_SCB0_INTR_RX
#define UART_2_SCB__INTR_RX_MASK CYREG_SCB0_INTR_RX_MASK
#define UART_2_SCB__INTR_RX_MASKED CYREG_SCB0_INTR_RX_MASKED
#define UART_2_SCB__INTR_RX_SET CYREG_SCB0_INTR_RX_SET
#define UART_2_SCB__INTR_S CYREG_SCB0_INTR_S
#define UART_2_SCB__INTR_S_MASK CYREG_SCB0_INTR_S_MASK
#define UART_2_SCB__INTR_S_MASKED CYREG_SCB0_INTR_S_MASKED
#define UART_2_SCB__INTR_S_SET CYREG_SCB0_INTR_S_SET
#define UART_2_SCB__INTR_SPI_EC CYREG_SCB0_INTR_SPI_EC
#define UART_2_SCB__INTR_SPI_EC_MASK CYREG_SCB0_INTR_SPI_EC_MASK
#define UART_2_SCB__INTR_SPI_EC_MASKED CYREG_SCB0_INTR_SPI_EC_MASKED
#define UART_2_SCB__INTR_TX CYREG_SCB0_INTR_TX
#define UART_2_SCB__INTR_TX_MASK CYREG_SCB0_INTR_TX_MASK
#define UART_2_SCB__INTR_TX_MASKED CYREG_SCB0_INTR_TX_MASKED
#define UART_2_SCB__INTR_TX_SET CYREG_SCB0_INTR_TX_SET
#define UART_2_SCB__RX_CTRL CYREG_SCB0_RX_CTRL
#define UART_2_SCB__RX_FIFO_CTRL CYREG_SCB0_RX_FIFO_CTRL
#define UART_2_SCB__RX_FIFO_RD CYREG_SCB0_RX_FIFO_RD
#define UART_2_SCB__RX_FIFO_RD_SILENT CYREG_SCB0_RX_FIFO_RD_SILENT
#define UART_2_SCB__RX_FIFO_STATUS CYREG_SCB0_RX_FIFO_STATUS
#define UART_2_SCB__RX_MATCH CYREG_SCB0_RX_MATCH
#define UART_2_SCB__SPI_CTRL CYREG_SCB0_SPI_CTRL
#define UART_2_SCB__SPI_STATUS CYREG_SCB0_SPI_STATUS
#define UART_2_SCB__SS0_POSISTION 0u
#define UART_2_SCB__SS1_POSISTION 1u
#define UART_2_SCB__SS2_POSISTION 2u
#define UART_2_SCB__SS3_POSISTION 3u
#define UART_2_SCB__STATUS CYREG_SCB0_STATUS
#define UART_2_SCB__TX_CTRL CYREG_SCB0_TX_CTRL
#define UART_2_SCB__TX_FIFO_CTRL CYREG_SCB0_TX_FIFO_CTRL
#define UART_2_SCB__TX_FIFO_STATUS CYREG_SCB0_TX_FIFO_STATUS
#define UART_2_SCB__TX_FIFO_WR CYREG_SCB0_TX_FIFO_WR
#define UART_2_SCB__UART_CTRL CYREG_SCB0_UART_CTRL
#define UART_2_SCB__UART_RX_CTRL CYREG_SCB0_UART_RX_CTRL
#define UART_2_SCB__UART_RX_STATUS CYREG_SCB0_UART_RX_STATUS
#define UART_2_SCB__UART_TX_CTRL CYREG_SCB0_UART_TX_CTRL

/* UART_2_SCB_IRQ */
#define UART_2_SCB_IRQ__INTC_CLR_EN_REG CYREG_CM0_ICER
#define UART_2_SCB_IRQ__INTC_CLR_PD_REG CYREG_CM0_ICPR
#define UART_2_SCB_IRQ__INTC_MASK 0x400u
#define UART_2_SCB_IRQ__INTC_NUMBER 10u
#define UART_2_SCB_IRQ__INTC_PRIOR_MASK 0xC00000u
#define UART_2_SCB_IRQ__INTC_PRIOR_NUM 3u
#define UART_2_SCB_IRQ__INTC_PRIOR_REG CYREG_CM0_IPR2
#define UART_2_SCB_IRQ__INTC_SET_EN_REG CYREG_CM0_ISER
#define UART_2_SCB_IRQ__INTC_SET_PD_REG CYREG_CM0_ISPR

/* UART_2_SCBCLK */
#define UART_2_SCBCLK__DIVIDER_MASK 0x0000FFFFu
#define UART_2_SCBCLK__ENABLE CYREG_CLK_DIVIDER_C00
#define UART_2_SCBCLK__ENABLE_MASK 0x80000000u
#define UART_2_SCBCLK__MASK 0x80000000u
#define UART_2_SCBCLK__REGISTER CYREG_CLK_DIVIDER_C00

/* UART_2_tx */
#define UART_2_tx__0__DM__MASK 0x38u
#define UART_2_tx__0__DM__SHIFT 3
#define UART_2_tx__0__DR CYREG_PRT4_DR
#define UART_2_tx__0__HSIOM CYREG_HSIOM_PORT_SEL4
#define UART_2_tx__0__HSIOM_MASK 0x000000F0u
#define UART_2_tx__0__HSIOM_SHIFT 4u
#define UART_2_tx__0__INTCFG CYREG_PRT4_INTCFG
#define UART_2_tx__0__INTSTAT CYREG_PRT4_INTSTAT
#define UART_2_tx__0__MASK 0x02u
#define UART_2_tx__0__PC CYREG_PRT4_PC
#define UART_2_tx__0__PC2 CYREG_PRT4_PC2
#define UART_2_tx__0__PORT 4u
#define UART_2_tx__0__PS CYREG_PRT4_PS
#define UART_2_tx__0__SHIFT 1
#define UART_2_tx__DR CYREG_PRT4_DR
#define UART_2_tx__INTCFG CYREG_PRT4_INTCFG
#define UART_2_tx__INTSTAT CYREG_PRT4_INTSTAT
#define UART_2_tx__MASK 0x02u
#define UART_2_tx__PC CYREG_PRT4_PC
#define UART_2_tx__PC2 CYREG_PRT4_PC2
#define UART_2_tx__PORT 4u
#define UART_2_tx__PS CYREG_PRT4_PS
#define UART_2_tx__SHIFT 1

/* Clock_4 */
#define Clock_4__DIVIDER_MASK 0x0000FFFFu
#define Clock_4__ENABLE CYREG_CLK_DIVIDER_A00
#define Clock_4__ENABLE_MASK 0x80000000u
#define Clock_4__MASK 0x80000000u
#define Clock_4__REGISTER CYREG_CLK_DIVIDER_A00

/* Clock_5 */
#define Clock_5__DIVIDER_MASK 0x0000FFFFu
#define Clock_5__ENABLE CYREG_CLK_DIVIDER_B00
#define Clock_5__ENABLE_MASK 0x80000000u
#define Clock_5__MASK 0x80000000u
#define Clock_5__REGISTER CYREG_CLK_DIVIDER_B00

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

/* Timer_2_cy_m0s8_tcpwm_1 */
#define Timer_2_cy_m0s8_tcpwm_1__CC CYREG_TCPWM_CNT1_CC
#define Timer_2_cy_m0s8_tcpwm_1__CC_BUFF CYREG_TCPWM_CNT1_CC_BUFF
#define Timer_2_cy_m0s8_tcpwm_1__COUNTER CYREG_TCPWM_CNT1_COUNTER
#define Timer_2_cy_m0s8_tcpwm_1__CTRL CYREG_TCPWM_CNT1_CTRL
#define Timer_2_cy_m0s8_tcpwm_1__INTR CYREG_TCPWM_CNT1_INTR
#define Timer_2_cy_m0s8_tcpwm_1__INTR_MASK CYREG_TCPWM_CNT1_INTR_MASK
#define Timer_2_cy_m0s8_tcpwm_1__INTR_MASKED CYREG_TCPWM_CNT1_INTR_MASKED
#define Timer_2_cy_m0s8_tcpwm_1__INTR_SET CYREG_TCPWM_CNT1_INTR_SET
#define Timer_2_cy_m0s8_tcpwm_1__PERIOD CYREG_TCPWM_CNT1_PERIOD
#define Timer_2_cy_m0s8_tcpwm_1__PERIOD_BUFF CYREG_TCPWM_CNT1_PERIOD_BUFF
#define Timer_2_cy_m0s8_tcpwm_1__STATUS CYREG_TCPWM_CNT1_STATUS
#define Timer_2_cy_m0s8_tcpwm_1__TCPWM_CMD CYREG_TCPWM_CMD
#define Timer_2_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK 0x02u
#define Timer_2_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT 1
#define Timer_2_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK 0x200u
#define Timer_2_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT 9
#define Timer_2_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK 0x2000000u
#define Timer_2_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT 25
#define Timer_2_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK 0x20000u
#define Timer_2_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT 17
#define Timer_2_cy_m0s8_tcpwm_1__TCPWM_CTRL CYREG_TCPWM_CTRL
#define Timer_2_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK 0x02u
#define Timer_2_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT 1
#define Timer_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE CYREG_TCPWM_INTR_CAUSE
#define Timer_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK 0x02u
#define Timer_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT 1
#define Timer_2_cy_m0s8_tcpwm_1__TCPWM_NUMBER 1u
#define Timer_2_cy_m0s8_tcpwm_1__TR_CTRL0 CYREG_TCPWM_CNT1_TR_CTRL0
#define Timer_2_cy_m0s8_tcpwm_1__TR_CTRL1 CYREG_TCPWM_CNT1_TR_CTRL1
#define Timer_2_cy_m0s8_tcpwm_1__TR_CTRL2 CYREG_TCPWM_CNT1_TR_CTRL2

/* Channel_1 */
#define Channel_1__0__DM__MASK 0x07u
#define Channel_1__0__DM__SHIFT 0
#define Channel_1__0__DR CYREG_PRT3_DR
#define Channel_1__0__HSIOM CYREG_HSIOM_PORT_SEL3
#define Channel_1__0__HSIOM_MASK 0x0000000Fu
#define Channel_1__0__HSIOM_SHIFT 0u
#define Channel_1__0__INTCFG CYREG_PRT3_INTCFG
#define Channel_1__0__INTSTAT CYREG_PRT3_INTSTAT
#define Channel_1__0__MASK 0x01u
#define Channel_1__0__PA__CFG0 CYREG_UDB_PA3_CFG0
#define Channel_1__0__PA__CFG1 CYREG_UDB_PA3_CFG1
#define Channel_1__0__PA__CFG10 CYREG_UDB_PA3_CFG10
#define Channel_1__0__PA__CFG11 CYREG_UDB_PA3_CFG11
#define Channel_1__0__PA__CFG12 CYREG_UDB_PA3_CFG12
#define Channel_1__0__PA__CFG13 CYREG_UDB_PA3_CFG13
#define Channel_1__0__PA__CFG14 CYREG_UDB_PA3_CFG14
#define Channel_1__0__PA__CFG2 CYREG_UDB_PA3_CFG2
#define Channel_1__0__PA__CFG3 CYREG_UDB_PA3_CFG3
#define Channel_1__0__PA__CFG4 CYREG_UDB_PA3_CFG4
#define Channel_1__0__PA__CFG5 CYREG_UDB_PA3_CFG5
#define Channel_1__0__PA__CFG6 CYREG_UDB_PA3_CFG6
#define Channel_1__0__PA__CFG7 CYREG_UDB_PA3_CFG7
#define Channel_1__0__PA__CFG8 CYREG_UDB_PA3_CFG8
#define Channel_1__0__PA__CFG9 CYREG_UDB_PA3_CFG9
#define Channel_1__0__PC CYREG_PRT3_PC
#define Channel_1__0__PC2 CYREG_PRT3_PC2
#define Channel_1__0__PORT 3u
#define Channel_1__0__PS CYREG_PRT3_PS
#define Channel_1__0__SHIFT 0
#define Channel_1__DR CYREG_PRT3_DR
#define Channel_1__INTCFG CYREG_PRT3_INTCFG
#define Channel_1__INTSTAT CYREG_PRT3_INTSTAT
#define Channel_1__MASK 0x01u
#define Channel_1__PA__CFG0 CYREG_UDB_PA3_CFG0
#define Channel_1__PA__CFG1 CYREG_UDB_PA3_CFG1
#define Channel_1__PA__CFG10 CYREG_UDB_PA3_CFG10
#define Channel_1__PA__CFG11 CYREG_UDB_PA3_CFG11
#define Channel_1__PA__CFG12 CYREG_UDB_PA3_CFG12
#define Channel_1__PA__CFG13 CYREG_UDB_PA3_CFG13
#define Channel_1__PA__CFG14 CYREG_UDB_PA3_CFG14
#define Channel_1__PA__CFG2 CYREG_UDB_PA3_CFG2
#define Channel_1__PA__CFG3 CYREG_UDB_PA3_CFG3
#define Channel_1__PA__CFG4 CYREG_UDB_PA3_CFG4
#define Channel_1__PA__CFG5 CYREG_UDB_PA3_CFG5
#define Channel_1__PA__CFG6 CYREG_UDB_PA3_CFG6
#define Channel_1__PA__CFG7 CYREG_UDB_PA3_CFG7
#define Channel_1__PA__CFG8 CYREG_UDB_PA3_CFG8
#define Channel_1__PA__CFG9 CYREG_UDB_PA3_CFG9
#define Channel_1__PC CYREG_PRT3_PC
#define Channel_1__PC2 CYREG_PRT3_PC2
#define Channel_1__PORT 3u
#define Channel_1__PS CYREG_PRT3_PS
#define Channel_1__SHIFT 0

/* Channel_2 */
#define Channel_2__0__DM__MASK 0x7000u
#define Channel_2__0__DM__SHIFT 12
#define Channel_2__0__DR CYREG_PRT3_DR
#define Channel_2__0__HSIOM CYREG_HSIOM_PORT_SEL3
#define Channel_2__0__HSIOM_MASK 0x000F0000u
#define Channel_2__0__HSIOM_SHIFT 16u
#define Channel_2__0__INTCFG CYREG_PRT3_INTCFG
#define Channel_2__0__INTSTAT CYREG_PRT3_INTSTAT
#define Channel_2__0__MASK 0x10u
#define Channel_2__0__PA__CFG0 CYREG_UDB_PA3_CFG0
#define Channel_2__0__PA__CFG1 CYREG_UDB_PA3_CFG1
#define Channel_2__0__PA__CFG10 CYREG_UDB_PA3_CFG10
#define Channel_2__0__PA__CFG11 CYREG_UDB_PA3_CFG11
#define Channel_2__0__PA__CFG12 CYREG_UDB_PA3_CFG12
#define Channel_2__0__PA__CFG13 CYREG_UDB_PA3_CFG13
#define Channel_2__0__PA__CFG14 CYREG_UDB_PA3_CFG14
#define Channel_2__0__PA__CFG2 CYREG_UDB_PA3_CFG2
#define Channel_2__0__PA__CFG3 CYREG_UDB_PA3_CFG3
#define Channel_2__0__PA__CFG4 CYREG_UDB_PA3_CFG4
#define Channel_2__0__PA__CFG5 CYREG_UDB_PA3_CFG5
#define Channel_2__0__PA__CFG6 CYREG_UDB_PA3_CFG6
#define Channel_2__0__PA__CFG7 CYREG_UDB_PA3_CFG7
#define Channel_2__0__PA__CFG8 CYREG_UDB_PA3_CFG8
#define Channel_2__0__PA__CFG9 CYREG_UDB_PA3_CFG9
#define Channel_2__0__PC CYREG_PRT3_PC
#define Channel_2__0__PC2 CYREG_PRT3_PC2
#define Channel_2__0__PORT 3u
#define Channel_2__0__PS CYREG_PRT3_PS
#define Channel_2__0__SHIFT 4
#define Channel_2__DR CYREG_PRT3_DR
#define Channel_2__INTCFG CYREG_PRT3_INTCFG
#define Channel_2__INTSTAT CYREG_PRT3_INTSTAT
#define Channel_2__MASK 0x10u
#define Channel_2__PA__CFG0 CYREG_UDB_PA3_CFG0
#define Channel_2__PA__CFG1 CYREG_UDB_PA3_CFG1
#define Channel_2__PA__CFG10 CYREG_UDB_PA3_CFG10
#define Channel_2__PA__CFG11 CYREG_UDB_PA3_CFG11
#define Channel_2__PA__CFG12 CYREG_UDB_PA3_CFG12
#define Channel_2__PA__CFG13 CYREG_UDB_PA3_CFG13
#define Channel_2__PA__CFG14 CYREG_UDB_PA3_CFG14
#define Channel_2__PA__CFG2 CYREG_UDB_PA3_CFG2
#define Channel_2__PA__CFG3 CYREG_UDB_PA3_CFG3
#define Channel_2__PA__CFG4 CYREG_UDB_PA3_CFG4
#define Channel_2__PA__CFG5 CYREG_UDB_PA3_CFG5
#define Channel_2__PA__CFG6 CYREG_UDB_PA3_CFG6
#define Channel_2__PA__CFG7 CYREG_UDB_PA3_CFG7
#define Channel_2__PA__CFG8 CYREG_UDB_PA3_CFG8
#define Channel_2__PA__CFG9 CYREG_UDB_PA3_CFG9
#define Channel_2__PC CYREG_PRT3_PC
#define Channel_2__PC2 CYREG_PRT3_PC2
#define Channel_2__PORT 3u
#define Channel_2__PS CYREG_PRT3_PS
#define Channel_2__SHIFT 4

/* Miscellaneous */
#define CY_VERSION "PSoC Creator  3.1 SP1"
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
#define CYDEV_HEAP_SIZE 0x0100
#define CYDEV_PROJ_TYPE 0
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
