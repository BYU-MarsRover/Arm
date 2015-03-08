/*******************************************************************************
* FILENAME: cyfitter_cfg.c
* PSoC Creator  3.1 SP1
*
* Description:
* This file is automatically generated by PSoC Creator with device 
* initialization code.  Except for the user defined sections in
* CyClockStartupError(), this file should not be modified.
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include <string.h>
#include <cytypes.h>
#include <cydevice_trm.h>
#include <cyfitter.h>
#include <CyLib.h>
#include <cyfitter_cfg.h>


#if defined(__GNUC__) || defined(__ARMCC_VERSION)
    #define CYPACKED 
    #define CYPACKED_ATTR __attribute__ ((packed))
    #define CYALIGNED __attribute__ ((aligned))
    #define CY_CFG_UNUSED __attribute__ ((unused))
    #define CY_CFG_SECTION __attribute__ ((section(".psocinit")))
    
    #if defined(__ARMCC_VERSION)
        #define CY_CFG_MEMORY_BARRIER() __memory_changed()
    #else
        #define CY_CFG_MEMORY_BARRIER() __sync_synchronize()
    #endif
    
#elif defined(__ICCARM__)
    #include <intrinsics.h>

    #define CYPACKED __packed
    #define CYPACKED_ATTR 
    #define CYALIGNED _Pragma("data_alignment=4")
    #define CY_CFG_UNUSED _Pragma("diag_suppress=Pe177")
    #define CY_CFG_SECTION _Pragma("location=\".psocinit\"")
    
    #define CY_CFG_MEMORY_BARRIER() __DMB()
    
#else
    #error Unsupported toolchain
#endif


CY_CFG_UNUSED
static void CYMEMZERO(void *s, size_t n);
CY_CFG_UNUSED
static void CYMEMZERO(void *s, size_t n)
{
	(void)memset(s, 0, n);
}
CY_CFG_UNUSED
static void CYCONFIGCPY(void *dest, const void *src, size_t n);
CY_CFG_UNUSED
static void CYCONFIGCPY(void *dest, const void *src, size_t n)
{
	(void)memcpy(dest, src, n);
}
CY_CFG_UNUSED
static void CYCONFIGCPYCODE(void *dest, const void *src, size_t n);
CY_CFG_UNUSED
static void CYCONFIGCPYCODE(void *dest, const void *src, size_t n)
{
	(void)memcpy(dest, src, n);
}



/* Clock startup error codes                                                   */
#define CYCLOCKSTART_NO_ERROR    0u
#define CYCLOCKSTART_XTAL_ERROR  1u
#define CYCLOCKSTART_32KHZ_ERROR 2u
#define CYCLOCKSTART_PLL_ERROR   3u

#ifdef CY_NEED_CYCLOCKSTARTUPERROR
/*******************************************************************************
* Function Name: CyClockStartupError
********************************************************************************
* Summary:
*  If an error is encountered during clock configuration (crystal startup error,
*  PLL lock error, etc.), the system will end up here.  Unless reimplemented by
*  the customer, this function will stop in an infinite loop.
*
* Parameters:
*   void
*
* Return:
*   void
*
*******************************************************************************/
CY_CFG_UNUSED
static void CyClockStartupError(uint8 errorCode);
CY_CFG_UNUSED
static void CyClockStartupError(uint8 errorCode)
{
    /* To remove the compiler warning if errorCode not used.                */
    errorCode = errorCode;

    /* `#START CyClockStartupError` */

    /* If we have a clock startup error (bad MHz crystal, PLL lock, etc.),  */
    /* we will end up here to allow the customer to implement something to  */
    /* deal with the clock condition.                                       */

    /* `#END` */

    /* If nothing else, stop here since the clocks have not started         */
    /* correctly.                                                           */
    while(1) {}
}
#endif

#define CY_CFG_BASE_ADDR_COUNT 8u
CYPACKED typedef struct
{
	uint8 offset;
	uint8 value;
} CYPACKED_ATTR cy_cfg_addrvalue_t;



/*******************************************************************************
* Function Name: cfg_write_bytes32
********************************************************************************
* Summary:
*  This function is used for setting up the chip configuration areas that
*  contain relatively sparse data.
*
* Parameters:
*   void
*
* Return:
*   void
*
*******************************************************************************/
static void cfg_write_bytes32(const uint32 addr_table[], const cy_cfg_addrvalue_t data_table[]);
static void cfg_write_bytes32(const uint32 addr_table[], const cy_cfg_addrvalue_t data_table[])
{
	/* For 32-bit little-endian architectures */
	uint32 i, j = 0u;
	for (i = 0u; i < CY_CFG_BASE_ADDR_COUNT; i++)
	{
		uint32 baseAddr = addr_table[i];
		uint8 count = (uint8)baseAddr;
		baseAddr &= 0xFFFFFF00u;
		while (count != 0u)
		{
			CY_SET_XTND_REG8((void CYFAR *)(baseAddr + data_table[j].offset), data_table[j].value);
			j++;
			count--;
		}
	}
}

/*******************************************************************************
* Function Name: SetIMOBGTrims
********************************************************************************
*
* Summary:
*   Performs the configuration of the bandgap trim for the IMO based on the given
*   expected frequency of the IMO. 
*
* Parameters:
*   imoFreq: Frequency for operation of the IMO.
*
* Return:
*   void
*
*******************************************************************************/
static void SetIMOBGTrims(uint8 imoFreq);
CY_CFG_SECTION
static void SetIMOBGTrims(uint8 imoFreq)
{
	CYPACKED typedef struct {
		uint8 freq;
		uint8 absolute;
		uint8 tmpco;
	} CYPACKED_ATTR imo_trim_entry_t;

	CYPACKED typedef struct {
		imo_trim_entry_t entries[4];
	} CYPACKED_ATTR imo_trim_table_t;

	static const imo_trim_table_t *imo_trim_table = (const imo_trim_table_t *)CYREG_SFLASH_IMO_MAXF0;
	static const uint32 IMO_TRIM_FREQ_TABLE_ENTRIES = sizeof(imo_trim_table->entries)/sizeof(imo_trim_table->entries[0]);

	int32 imoTrimIndex;
	uint8 setAbs;
	uint8 setTmpCo;

	/* Traverse the SFLASH IMO frequency-dependent bandgap trim table to
	 * locate the appropriate value to trim the IMO bandgap based on freq. */
	setAbs = CY_GET_REG8((const void *)CYREG_SFLASH_IMO_ABS4);
	setTmpCo = CY_GET_REG8((const void *)CYREG_SFLASH_IMO_TMPCO4);
	for (imoTrimIndex = ((int32)IMO_TRIM_FREQ_TABLE_ENTRIES)-1;
	     (imoTrimIndex >= 0) && (imoFreq <= imo_trim_table->entries[imoTrimIndex].freq);
	     imoTrimIndex--)
	{
		setAbs = imo_trim_table->entries[imoTrimIndex].absolute;
		setTmpCo = imo_trim_table->entries[imoTrimIndex].tmpco;
	}

	CY_SET_REG32((void *)CYREG_PWR_BG_TRIM4, setAbs);
	CY_SET_REG32((void *)CYREG_PWR_BG_TRIM5, setTmpCo);
}



/*******************************************************************************
* Function Name: ClockSetup
********************************************************************************
*
* Summary:
*   Performs the initialization of all of the clocks in the device based on the
*   settings in the Clock tab of the DWR.  This includes enabling the requested
*   clocks and setting the necessary dividers to produce the desired frequency. 
*
* Parameters:
*   void
*
* Return:
*   void
*
*******************************************************************************/
static void ClockSetup(void);
CY_CFG_SECTION
static void ClockSetup(void)
{
	/* Enable HALF_EN before trimming for the flash accelerator. */
	CY_SET_REG32((void CYXDATA *)(CYREG_CLK_SELECT), (CY_GET_REG32((void *)CYREG_CLK_SELECT) | 0x00040000u));

	/* Trim IMO BG based on desired frequency. */
	SetIMOBGTrims(24u);

	/* Going less than or equal to 24MHz, so update the clock speed then adjust trim value. */
	CY_SET_REG32((void CYXDATA *)(CYREG_CLK_IMO_TRIM2), (25u));
	CyDelayCycles(5u);
	CY_SET_REG32((void CYXDATA *)(CYREG_CLK_IMO_TRIM1), (CY_GET_REG8((void *)CYREG_SFLASH_IMO_TRIM21)));
	CyDelayUs(5u);

	/* Disable HALF_EN since it is not required at this IMO frequency. */
	CY_SET_REG32((void CYXDATA *)(CYREG_CLK_SELECT), (CY_GET_REG32((void *)CYREG_CLK_SELECT) & 0xFFFBFFFFu));
	/* CYDEV_CLK_ILO_CONFIG Starting address: CYDEV_CLK_ILO_CONFIG */
	CY_SET_XTND_REG32((void CYFAR *)(CYREG_CLK_ILO_CONFIG), 0x80000006u);


	/* CYDEV_CLK_SELECT00 Starting address: CYDEV_CLK_SELECT00 */
	CY_SET_XTND_REG32((void CYFAR *)(CYREG_CLK_SELECT08), 0x00000010u);

	/* CYDEV_CLK_IMO_CONFIG Starting address: CYDEV_CLK_IMO_CONFIG */
	CY_SET_XTND_REG32((void CYFAR *)(CYREG_CLK_IMO_CONFIG), 0x80000000u);

	/* CYDEV_CLK_DIVIDER_A00 Starting address: CYDEV_CLK_DIVIDER_A00 */
	CY_SET_XTND_REG32((void CYFAR *)(CYREG_CLK_DIVIDER_A00), 0x80000017u);

}


/* Analog API Functions */


/*******************************************************************************
* Function Name: AnalogSetDefault
********************************************************************************
*
* Summary:
*  Sets up the analog portions of the chip to default values based on chip
*  configuration options from the project.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
static void AnalogSetDefault(void);
static void AnalogSetDefault(void)
{
}

#define CY_AMUX_UNUSED CYREG_CM0_ROM_DWT


/*******************************************************************************
* Function Name: cyfitter_cfg
********************************************************************************
* Summary:
*  This function is called by the start-up code for the selected device. It
*  performs all of the necessary device configuration based on the design
*  settings.  This includes settings from the Design Wide Resources (DWR) such
*  as Clocks and Pins as well as any component configuration that is necessary.
*
* Parameters:  
*   void
*
* Return:
*   void
*
*******************************************************************************/
CY_CFG_SECTION
void cyfitter_cfg(void)
{
	/* Disable interrupts by default. Let user enable if/when they want. */
	CyGlobalIntDisable;

	{
		static const uint32 CYCODE cy_cfg_addr_table[] = {
			0x400F3105u, /* Base address: 0x400F3100 Count: 5 */
			0x400F3211u, /* Base address: 0x400F3200 Count: 17 */
			0x400F3320u, /* Base address: 0x400F3300 Count: 32 */
			0x400F400Eu, /* Base address: 0x400F4000 Count: 14 */
			0x400F4118u, /* Base address: 0x400F4100 Count: 24 */
			0x400F4202u, /* Base address: 0x400F4200 Count: 2 */
			0x400F4303u, /* Base address: 0x400F4300 Count: 3 */
			0x400F6002u, /* Base address: 0x400F6000 Count: 2 */
		};

		static const cy_cfg_addrvalue_t CYCODE cy_cfg_data_table[] = {
			{0x81u, 0x40u},
			{0x88u, 0x08u},
			{0x89u, 0x08u},
			{0xE0u, 0x80u},
			{0xE4u, 0x20u},
			{0x02u, 0x80u},
			{0x06u, 0x10u},
			{0x08u, 0x55u},
			{0x0Au, 0xAAu},
			{0x0Eu, 0x01u},
			{0x16u, 0x08u},
			{0x1Au, 0x40u},
			{0x1Eu, 0x04u},
			{0x26u, 0x02u},
			{0x2Eu, 0x20u},
			{0x30u, 0x0Cu},
			{0x32u, 0xC0u},
			{0x34u, 0x03u},
			{0x36u, 0x30u},
			{0x3Eu, 0x55u},
			{0x58u, 0x04u},
			{0x5Fu, 0x01u},
			{0x04u, 0x02u},
			{0x05u, 0x08u},
			{0x06u, 0x08u},
			{0x07u, 0x02u},
			{0x0Cu, 0x08u},
			{0x0Eu, 0x05u},
			{0x15u, 0x80u},
			{0x17u, 0x08u},
			{0x1Du, 0x80u},
			{0x1Eu, 0x10u},
			{0x1Fu, 0x21u},
			{0x80u, 0x01u},
			{0x82u, 0x08u},
			{0x83u, 0x08u},
			{0x86u, 0x04u},
			{0x87u, 0x02u},
			{0x8Bu, 0x20u},
			{0x8Du, 0x80u},
			{0x8Eu, 0x10u},
			{0x91u, 0x80u},
			{0x92u, 0x01u},
			{0x97u, 0x02u},
			{0x99u, 0x08u},
			{0xA0u, 0x08u},
			{0xAEu, 0x01u},
			{0xB7u, 0x01u},
			{0xC0u, 0xF0u},
			{0xC2u, 0xE0u},
			{0xC4u, 0xA0u},
			{0xE2u, 0x90u},
			{0xE6u, 0x10u},
			{0xEAu, 0x40u},
			{0x06u, 0x04u},
			{0x08u, 0x08u},
			{0x09u, 0x40u},
			{0x0Cu, 0x80u},
			{0x5Au, 0x80u},
			{0x63u, 0x08u},
			{0x82u, 0x04u},
			{0x88u, 0x08u},
			{0x89u, 0x40u},
			{0xC0u, 0x80u},
			{0xC2u, 0xD0u},
			{0xD4u, 0x80u},
			{0xD8u, 0x40u},
			{0xE0u, 0x80u},
			{0x03u, 0x08u},
			{0x07u, 0x10u},
			{0x08u, 0x08u},
			{0x0Du, 0x08u},
			{0x0Eu, 0x02u},
			{0x53u, 0x04u},
			{0x5Bu, 0x20u},
			{0x80u, 0x08u},
			{0x82u, 0x01u},
			{0x83u, 0x10u},
			{0x85u, 0x08u},
			{0x87u, 0x08u},
			{0x8Bu, 0x04u},
			{0x8Eu, 0x40u},
			{0x8Fu, 0x20u},
			{0x96u, 0x80u},
			{0xACu, 0x80u},
			{0xB7u, 0x04u},
			{0xC0u, 0x60u},
			{0xC2u, 0xB0u},
			{0xD4u, 0xA0u},
			{0xE0u, 0x60u},
			{0xE4u, 0xE0u},
			{0xE8u, 0x10u},
			{0x00u, 0x01u},
			{0xC0u, 0x08u},
			{0x7Cu, 0x01u},
			{0x90u, 0x01u},
			{0xDEu, 0x01u},
			{0x02u, 0x01u},
			{0x11u, 0x01u},
		};



		CYPACKED typedef struct {
			void CYFAR *address;
			uint16 size;
		} CYPACKED_ATTR cfg_memset_t;

		static const cfg_memset_t CYCODE cfg_memset_list [] = {
			/* address, size */
			{(void CYFAR *)(CYDEV_UDB_P0_U0_BASE), 1024u},
			{(void CYFAR *)(CYDEV_UDB_DSI0_BASE), 1024u},
		};

		uint8 CYDATA i;

		/* Zero out critical memory blocks before beginning configuration */
		for (i = 0u; i < (sizeof(cfg_memset_list)/sizeof(cfg_memset_list[0])); i++)
		{
			const cfg_memset_t CYCODE * CYDATA ms = &cfg_memset_list[i];
			CYMEMZERO(ms->address, (size_t)(uint32)(ms->size));
		}

		cfg_write_bytes32(cy_cfg_addr_table, cy_cfg_data_table);

		/* HSIOM Starting address: CYDEV_HSIOM_BASE */
		CY_SET_XTND_REG32((void CYFAR *)(CYDEV_HSIOM_BASE), 0x00300300u);
		CY_SET_XTND_REG32((void CYFAR *)(CYREG_HSIOM_PORT_SEL1), 0x00003003u);
		CY_SET_XTND_REG32((void CYFAR *)(CYREG_HSIOM_PORT_SEL3), 0x0000EE00u);

		/* IOPINS0_0 Starting address: CYDEV_PRT0_DR */
		CY_SET_XTND_REG32((void CYFAR *)(CYREG_PRT0_DR), 0x00000024u);
		CY_SET_XTND_REG32((void CYFAR *)(CYREG_PRT0_PC), 0x00271380u);

		/* IOPINS0_1 Starting address: CYDEV_PRT1_DR */
		CY_SET_XTND_REG32((void CYFAR *)(CYREG_PRT1_DR), 0x00000009u);
		CY_SET_XTND_REG32((void CYFAR *)(CYREG_PRT1_PC), 0x00D89C4Eu);

		/* IOPINS0_2 Starting address: CYDEV_PRT2_DR */
		CY_SET_XTND_REG32((void CYFAR *)(CYREG_PRT2_PC), 0x00000001u);

		/* IOPINS0_3 Starting address: CYDEV_PRT3_DR */
		CY_SET_XTND_REG32((void CYFAR *)(CYREG_PRT3_PC), 0x00000D80u);

		/* UDB_PA_0 Starting address: CYDEV_UDB_PA0_BASE */
		CY_SET_XTND_REG32((void CYFAR *)(CYDEV_UDB_PA0_BASE), 0x00990004u);
		CY_SET_XTND_REG32((void CYFAR *)(CYREG_UDB_PA0_CFG4), 0xA2800000u);
		CY_SET_XTND_REG32((void CYFAR *)(CYREG_UDB_PA0_CFG8), 0x08200000u);

		/* UDB_PA_1 Starting address: CYDEV_UDB_PA1_BASE */
		CY_SET_XTND_REG32((void CYFAR *)(CYDEV_UDB_PA1_BASE), 0x00990004u);
		CY_SET_XTND_REG32((void CYFAR *)(CYREG_UDB_PA1_CFG4), 0x8A280000u);
		CY_SET_XTND_REG32((void CYFAR *)(CYREG_UDB_PA1_CFG8), 0x00800000u);

		/* UDB_PA_2 Starting address: CYDEV_UDB_PA2_BASE */
		CY_SET_XTND_REG32((void CYFAR *)(CYDEV_UDB_PA2_BASE), 0x00990004u);
		CY_SET_XTND_REG32((void CYFAR *)(CYREG_UDB_PA2_CFG4), 0x00020000u);

		/* UDB_PA_3 Starting address: CYDEV_UDB_PA3_BASE */
		CY_SET_XTND_REG32((void CYFAR *)(CYDEV_UDB_PA3_BASE), 0x00990000u);

		/* TCPWM_CNT0 Starting address: CYDEV_TCPWM_CNT0_TR_CTRL0 */
		CY_SET_XTND_REG32((void CYFAR *)(CYREG_TCPWM_CNT0_TR_CTRL0), 0x00099919u);

		/* Enable digital routing */
		CY_SET_XTND_REG8((void *)CYREG_UDB_UDBIF_BANK_CTL, CY_GET_XTND_REG8((void *)CYREG_UDB_UDBIF_BANK_CTL) | 0x02u);

		/* Enable UDB array */
		CY_SET_XTND_REG8((void *)CYREG_UDB_UDBIF_WAIT_CFG, (uint8)((CY_GET_XTND_REG8((void *)CYREG_UDB_UDBIF_WAIT_CFG) & 0xC3u) | 0x14u));
		CY_SET_XTND_REG8((void *)CYREG_UDB_UDBIF_BANK_CTL, (uint8)(CY_GET_XTND_REG8((void *)CYREG_UDB_UDBIF_BANK_CTL) | 0x16u));
	}

	/* Setup clocks based on selections from Clock DWR */
	ClockSetup();

	/* Perform basic analog initialization to defaults */
	AnalogSetDefault();

}
