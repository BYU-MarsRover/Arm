/*******************************************************************************
* File Name: Channel_1.c  
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
#include "Channel_1.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Channel_1_PC =   (Channel_1_PC & \
                                (uint32)(~(uint32)(Channel_1_DRIVE_MODE_IND_MASK << (Channel_1_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Channel_1_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Channel_1_Write
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
void Channel_1_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Channel_1_DR & (uint8)(~Channel_1_MASK));
    drVal = (drVal | ((uint8)(value << Channel_1_SHIFT) & Channel_1_MASK));
    Channel_1_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Channel_1_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Channel_1_DM_STRONG     Strong Drive 
*  Channel_1_DM_OD_HI      Open Drain, Drives High 
*  Channel_1_DM_OD_LO      Open Drain, Drives Low 
*  Channel_1_DM_RES_UP     Resistive Pull Up 
*  Channel_1_DM_RES_DWN    Resistive Pull Down 
*  Channel_1_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Channel_1_DM_DIG_HIZ    High Impedance Digital 
*  Channel_1_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Channel_1_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Channel_1__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Channel_1_Read
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
*  Macro Channel_1_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Channel_1_Read(void) 
{
    return (uint8)((Channel_1_PS & Channel_1_MASK) >> Channel_1_SHIFT);
}


/*******************************************************************************
* Function Name: Channel_1_ReadDataReg
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
uint8 Channel_1_ReadDataReg(void) 
{
    return (uint8)((Channel_1_DR & Channel_1_MASK) >> Channel_1_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Channel_1_INTSTAT) 

    /*******************************************************************************
    * Function Name: Channel_1_ClearInterrupt
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
    uint8 Channel_1_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Channel_1_INTSTAT & Channel_1_MASK);
		Channel_1_INTSTAT = maskedStatus;
        return maskedStatus >> Channel_1_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
