/*******************************************************************************
* File Name: pot_shoulder.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_pot_shoulder_H) /* Pins pot_shoulder_H */
#define CY_PINS_pot_shoulder_H

#include "cytypes.h"
#include "cyfitter.h"
#include "pot_shoulder_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    pot_shoulder_Write(uint8 value) ;
void    pot_shoulder_SetDriveMode(uint8 mode) ;
uint8   pot_shoulder_ReadDataReg(void) ;
uint8   pot_shoulder_Read(void) ;
uint8   pot_shoulder_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define pot_shoulder_DRIVE_MODE_BITS        (3)
#define pot_shoulder_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - pot_shoulder_DRIVE_MODE_BITS))

#define pot_shoulder_DM_ALG_HIZ         (0x00u)
#define pot_shoulder_DM_DIG_HIZ         (0x01u)
#define pot_shoulder_DM_RES_UP          (0x02u)
#define pot_shoulder_DM_RES_DWN         (0x03u)
#define pot_shoulder_DM_OD_LO           (0x04u)
#define pot_shoulder_DM_OD_HI           (0x05u)
#define pot_shoulder_DM_STRONG          (0x06u)
#define pot_shoulder_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define pot_shoulder_MASK               pot_shoulder__MASK
#define pot_shoulder_SHIFT              pot_shoulder__SHIFT
#define pot_shoulder_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pot_shoulder_PS                     (* (reg32 *) pot_shoulder__PS)
/* Port Configuration */
#define pot_shoulder_PC                     (* (reg32 *) pot_shoulder__PC)
/* Data Register */
#define pot_shoulder_DR                     (* (reg32 *) pot_shoulder__DR)
/* Input Buffer Disable Override */
#define pot_shoulder_INP_DIS                (* (reg32 *) pot_shoulder__PC2)


#if defined(pot_shoulder__INTSTAT)  /* Interrupt Registers */

    #define pot_shoulder_INTSTAT                (* (reg32 *) pot_shoulder__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define pot_shoulder_DRIVE_MODE_SHIFT       (0x00u)
#define pot_shoulder_DRIVE_MODE_MASK        (0x07u << pot_shoulder_DRIVE_MODE_SHIFT)


#endif /* End Pins pot_shoulder_H */


/* [] END OF FILE */
