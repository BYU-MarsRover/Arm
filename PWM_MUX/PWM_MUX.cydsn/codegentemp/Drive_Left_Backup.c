<<<<<<< HEAD
/*******************************************************************************
* File Name: Drive_Left_Backup.c  
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
#include "Drive_Left_Backup.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Drive_Left_Backup_PC =   (Drive_Left_Backup_PC & \
                                (uint32)(~(uint32)(Drive_Left_Backup_DRIVE_MODE_IND_MASK << (Drive_Left_Backup_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Drive_Left_Backup_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Drive_Left_Backup_Write
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
void Drive_Left_Backup_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Drive_Left_Backup_DR & (uint8)(~Drive_Left_Backup_MASK));
    drVal = (drVal | ((uint8)(value << Drive_Left_Backup_SHIFT) & Drive_Left_Backup_MASK));
    Drive_Left_Backup_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Drive_Left_Backup_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Drive_Left_Backup_DM_STRONG     Strong Drive 
*  Drive_Left_Backup_DM_OD_HI      Open Drain, Drives High 
*  Drive_Left_Backup_DM_OD_LO      Open Drain, Drives Low 
*  Drive_Left_Backup_DM_RES_UP     Resistive Pull Up 
*  Drive_Left_Backup_DM_RES_DWN    Resistive Pull Down 
*  Drive_Left_Backup_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Drive_Left_Backup_DM_DIG_HIZ    High Impedance Digital 
*  Drive_Left_Backup_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Drive_Left_Backup_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Drive_Left_Backup__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Drive_Left_Backup_Read
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
*  Macro Drive_Left_Backup_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Drive_Left_Backup_Read(void) 
{
    return (uint8)((Drive_Left_Backup_PS & Drive_Left_Backup_MASK) >> Drive_Left_Backup_SHIFT);
}


/*******************************************************************************
* Function Name: Drive_Left_Backup_ReadDataReg
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
uint8 Drive_Left_Backup_ReadDataReg(void) 
{
    return (uint8)((Drive_Left_Backup_DR & Drive_Left_Backup_MASK) >> Drive_Left_Backup_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Drive_Left_Backup_INTSTAT) 

    /*******************************************************************************
    * Function Name: Drive_Left_Backup_ClearInterrupt
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
    uint8 Drive_Left_Backup_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Drive_Left_Backup_INTSTAT & Drive_Left_Backup_MASK);
		Drive_Left_Backup_INTSTAT = maskedStatus;
        return maskedStatus >> Drive_Left_Backup_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
=======
/*******************************************************************************
* File Name: Drive_Left_Backup.c  
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
#include "Drive_Left_Backup.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Drive_Left_Backup_PC =   (Drive_Left_Backup_PC & \
                                (uint32)(~(uint32)(Drive_Left_Backup_DRIVE_MODE_IND_MASK << (Drive_Left_Backup_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Drive_Left_Backup_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Drive_Left_Backup_Write
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
void Drive_Left_Backup_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Drive_Left_Backup_DR & (uint8)(~Drive_Left_Backup_MASK));
    drVal = (drVal | ((uint8)(value << Drive_Left_Backup_SHIFT) & Drive_Left_Backup_MASK));
    Drive_Left_Backup_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Drive_Left_Backup_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Drive_Left_Backup_DM_STRONG     Strong Drive 
*  Drive_Left_Backup_DM_OD_HI      Open Drain, Drives High 
*  Drive_Left_Backup_DM_OD_LO      Open Drain, Drives Low 
*  Drive_Left_Backup_DM_RES_UP     Resistive Pull Up 
*  Drive_Left_Backup_DM_RES_DWN    Resistive Pull Down 
*  Drive_Left_Backup_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Drive_Left_Backup_DM_DIG_HIZ    High Impedance Digital 
*  Drive_Left_Backup_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Drive_Left_Backup_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Drive_Left_Backup__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Drive_Left_Backup_Read
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
*  Macro Drive_Left_Backup_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Drive_Left_Backup_Read(void) 
{
    return (uint8)((Drive_Left_Backup_PS & Drive_Left_Backup_MASK) >> Drive_Left_Backup_SHIFT);
}


/*******************************************************************************
* Function Name: Drive_Left_Backup_ReadDataReg
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
uint8 Drive_Left_Backup_ReadDataReg(void) 
{
    return (uint8)((Drive_Left_Backup_DR & Drive_Left_Backup_MASK) >> Drive_Left_Backup_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Drive_Left_Backup_INTSTAT) 

    /*******************************************************************************
    * Function Name: Drive_Left_Backup_ClearInterrupt
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
    uint8 Drive_Left_Backup_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Drive_Left_Backup_INTSTAT & Drive_Left_Backup_MASK);
		Drive_Left_Backup_INTSTAT = maskedStatus;
        return maskedStatus >> Drive_Left_Backup_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
>>>>>>> 0742168bb9b6d18216297ff5e7f48388d3571538
