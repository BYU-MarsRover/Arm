<<<<<<< HEAD
/*******************************************************************************
* File Name: Wrist_Tilt.c  
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
#include "Wrist_Tilt.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Wrist_Tilt_PC =   (Wrist_Tilt_PC & \
                                (uint32)(~(uint32)(Wrist_Tilt_DRIVE_MODE_IND_MASK << (Wrist_Tilt_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Wrist_Tilt_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Wrist_Tilt_Write
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
void Wrist_Tilt_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Wrist_Tilt_DR & (uint8)(~Wrist_Tilt_MASK));
    drVal = (drVal | ((uint8)(value << Wrist_Tilt_SHIFT) & Wrist_Tilt_MASK));
    Wrist_Tilt_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Wrist_Tilt_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Wrist_Tilt_DM_STRONG     Strong Drive 
*  Wrist_Tilt_DM_OD_HI      Open Drain, Drives High 
*  Wrist_Tilt_DM_OD_LO      Open Drain, Drives Low 
*  Wrist_Tilt_DM_RES_UP     Resistive Pull Up 
*  Wrist_Tilt_DM_RES_DWN    Resistive Pull Down 
*  Wrist_Tilt_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Wrist_Tilt_DM_DIG_HIZ    High Impedance Digital 
*  Wrist_Tilt_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Wrist_Tilt_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Wrist_Tilt__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Wrist_Tilt_Read
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
*  Macro Wrist_Tilt_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Wrist_Tilt_Read(void) 
{
    return (uint8)((Wrist_Tilt_PS & Wrist_Tilt_MASK) >> Wrist_Tilt_SHIFT);
}


/*******************************************************************************
* Function Name: Wrist_Tilt_ReadDataReg
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
uint8 Wrist_Tilt_ReadDataReg(void) 
{
    return (uint8)((Wrist_Tilt_DR & Wrist_Tilt_MASK) >> Wrist_Tilt_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Wrist_Tilt_INTSTAT) 

    /*******************************************************************************
    * Function Name: Wrist_Tilt_ClearInterrupt
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
    uint8 Wrist_Tilt_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Wrist_Tilt_INTSTAT & Wrist_Tilt_MASK);
		Wrist_Tilt_INTSTAT = maskedStatus;
        return maskedStatus >> Wrist_Tilt_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
=======
/*******************************************************************************
* File Name: Wrist_Tilt.c  
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
#include "Wrist_Tilt.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Wrist_Tilt_PC =   (Wrist_Tilt_PC & \
                                (uint32)(~(uint32)(Wrist_Tilt_DRIVE_MODE_IND_MASK << (Wrist_Tilt_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Wrist_Tilt_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Wrist_Tilt_Write
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
void Wrist_Tilt_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Wrist_Tilt_DR & (uint8)(~Wrist_Tilt_MASK));
    drVal = (drVal | ((uint8)(value << Wrist_Tilt_SHIFT) & Wrist_Tilt_MASK));
    Wrist_Tilt_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Wrist_Tilt_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Wrist_Tilt_DM_STRONG     Strong Drive 
*  Wrist_Tilt_DM_OD_HI      Open Drain, Drives High 
*  Wrist_Tilt_DM_OD_LO      Open Drain, Drives Low 
*  Wrist_Tilt_DM_RES_UP     Resistive Pull Up 
*  Wrist_Tilt_DM_RES_DWN    Resistive Pull Down 
*  Wrist_Tilt_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Wrist_Tilt_DM_DIG_HIZ    High Impedance Digital 
*  Wrist_Tilt_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Wrist_Tilt_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Wrist_Tilt__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Wrist_Tilt_Read
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
*  Macro Wrist_Tilt_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Wrist_Tilt_Read(void) 
{
    return (uint8)((Wrist_Tilt_PS & Wrist_Tilt_MASK) >> Wrist_Tilt_SHIFT);
}


/*******************************************************************************
* Function Name: Wrist_Tilt_ReadDataReg
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
uint8 Wrist_Tilt_ReadDataReg(void) 
{
    return (uint8)((Wrist_Tilt_DR & Wrist_Tilt_MASK) >> Wrist_Tilt_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Wrist_Tilt_INTSTAT) 

    /*******************************************************************************
    * Function Name: Wrist_Tilt_ClearInterrupt
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
    uint8 Wrist_Tilt_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Wrist_Tilt_INTSTAT & Wrist_Tilt_MASK);
		Wrist_Tilt_INTSTAT = maskedStatus;
        return maskedStatus >> Wrist_Tilt_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
>>>>>>> 0742168bb9b6d18216297ff5e7f48388d3571538
