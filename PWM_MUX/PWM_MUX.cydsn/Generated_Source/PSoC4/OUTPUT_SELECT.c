<<<<<<< HEAD
/*******************************************************************************
* File Name: OUTPUT_SELECT.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "OUTPUT_SELECT.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        OUTPUT_SELECT_PC =   (OUTPUT_SELECT_PC & \
                                (uint32)(~(uint32)(OUTPUT_SELECT_DRIVE_MODE_IND_MASK << (OUTPUT_SELECT_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (OUTPUT_SELECT_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: OUTPUT_SELECT_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void OUTPUT_SELECT_Write(uint8 value) 
{
    uint8 drVal = (uint8)(OUTPUT_SELECT_DR & (uint8)(~OUTPUT_SELECT_MASK));
    drVal = (drVal | ((uint8)(value << OUTPUT_SELECT_SHIFT) & OUTPUT_SELECT_MASK));
    OUTPUT_SELECT_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: OUTPUT_SELECT_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  OUTPUT_SELECT_DM_STRONG     Strong Drive 
*  OUTPUT_SELECT_DM_OD_HI      Open Drain, Drives High 
*  OUTPUT_SELECT_DM_OD_LO      Open Drain, Drives Low 
*  OUTPUT_SELECT_DM_RES_UP     Resistive Pull Up 
*  OUTPUT_SELECT_DM_RES_DWN    Resistive Pull Down 
*  OUTPUT_SELECT_DM_RES_UPDWN  Resistive Pull Up/Down 
*  OUTPUT_SELECT_DM_DIG_HIZ    High Impedance Digital 
*  OUTPUT_SELECT_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void OUTPUT_SELECT_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(OUTPUT_SELECT__0__SHIFT, mode);
	SetP4PinDriveMode(OUTPUT_SELECT__1__SHIFT, mode);
	SetP4PinDriveMode(OUTPUT_SELECT__2__SHIFT, mode);
}


/*******************************************************************************
* Function Name: OUTPUT_SELECT_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro OUTPUT_SELECT_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 OUTPUT_SELECT_Read(void) 
{
    return (uint8)((OUTPUT_SELECT_PS & OUTPUT_SELECT_MASK) >> OUTPUT_SELECT_SHIFT);
}


/*******************************************************************************
* Function Name: OUTPUT_SELECT_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 OUTPUT_SELECT_ReadDataReg(void) 
{
    return (uint8)((OUTPUT_SELECT_DR & OUTPUT_SELECT_MASK) >> OUTPUT_SELECT_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(OUTPUT_SELECT_INTSTAT) 

    /*******************************************************************************
    * Function Name: OUTPUT_SELECT_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 OUTPUT_SELECT_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(OUTPUT_SELECT_INTSTAT & OUTPUT_SELECT_MASK);
		OUTPUT_SELECT_INTSTAT = maskedStatus;
        return maskedStatus >> OUTPUT_SELECT_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
=======
/*******************************************************************************
* File Name: OUTPUT_SELECT.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "OUTPUT_SELECT.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        OUTPUT_SELECT_PC =   (OUTPUT_SELECT_PC & \
                                (uint32)(~(uint32)(OUTPUT_SELECT_DRIVE_MODE_IND_MASK << (OUTPUT_SELECT_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (OUTPUT_SELECT_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: OUTPUT_SELECT_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void OUTPUT_SELECT_Write(uint8 value) 
{
    uint8 drVal = (uint8)(OUTPUT_SELECT_DR & (uint8)(~OUTPUT_SELECT_MASK));
    drVal = (drVal | ((uint8)(value << OUTPUT_SELECT_SHIFT) & OUTPUT_SELECT_MASK));
    OUTPUT_SELECT_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: OUTPUT_SELECT_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  OUTPUT_SELECT_DM_STRONG     Strong Drive 
*  OUTPUT_SELECT_DM_OD_HI      Open Drain, Drives High 
*  OUTPUT_SELECT_DM_OD_LO      Open Drain, Drives Low 
*  OUTPUT_SELECT_DM_RES_UP     Resistive Pull Up 
*  OUTPUT_SELECT_DM_RES_DWN    Resistive Pull Down 
*  OUTPUT_SELECT_DM_RES_UPDWN  Resistive Pull Up/Down 
*  OUTPUT_SELECT_DM_DIG_HIZ    High Impedance Digital 
*  OUTPUT_SELECT_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void OUTPUT_SELECT_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(OUTPUT_SELECT__0__SHIFT, mode);
	SetP4PinDriveMode(OUTPUT_SELECT__1__SHIFT, mode);
	SetP4PinDriveMode(OUTPUT_SELECT__2__SHIFT, mode);
}


/*******************************************************************************
* Function Name: OUTPUT_SELECT_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro OUTPUT_SELECT_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 OUTPUT_SELECT_Read(void) 
{
    return (uint8)((OUTPUT_SELECT_PS & OUTPUT_SELECT_MASK) >> OUTPUT_SELECT_SHIFT);
}


/*******************************************************************************
* Function Name: OUTPUT_SELECT_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 OUTPUT_SELECT_ReadDataReg(void) 
{
    return (uint8)((OUTPUT_SELECT_DR & OUTPUT_SELECT_MASK) >> OUTPUT_SELECT_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(OUTPUT_SELECT_INTSTAT) 

    /*******************************************************************************
    * Function Name: OUTPUT_SELECT_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 OUTPUT_SELECT_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(OUTPUT_SELECT_INTSTAT & OUTPUT_SELECT_MASK);
		OUTPUT_SELECT_INTSTAT = maskedStatus;
        return maskedStatus >> OUTPUT_SELECT_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
>>>>>>> 0742168bb9b6d18216297ff5e7f48388d3571538
