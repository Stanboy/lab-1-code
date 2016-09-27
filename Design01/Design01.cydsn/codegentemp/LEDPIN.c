/*******************************************************************************
* File Name: LEDPIN.c  
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
#include "LEDPIN.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        LEDPIN_PC =   (LEDPIN_PC & \
                                (uint32)(~(uint32)(LEDPIN_DRIVE_MODE_IND_MASK << (LEDPIN_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (LEDPIN_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: LEDPIN_Write
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
void LEDPIN_Write(uint8 value) 
{
    uint8 drVal = (uint8)(LEDPIN_DR & (uint8)(~LEDPIN_MASK));
    drVal = (drVal | ((uint8)(value << LEDPIN_SHIFT) & LEDPIN_MASK));
    LEDPIN_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: LEDPIN_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  LEDPIN_DM_STRONG     Strong Drive 
*  LEDPIN_DM_OD_HI      Open Drain, Drives High 
*  LEDPIN_DM_OD_LO      Open Drain, Drives Low 
*  LEDPIN_DM_RES_UP     Resistive Pull Up 
*  LEDPIN_DM_RES_DWN    Resistive Pull Down 
*  LEDPIN_DM_RES_UPDWN  Resistive Pull Up/Down 
*  LEDPIN_DM_DIG_HIZ    High Impedance Digital 
*  LEDPIN_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void LEDPIN_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(LEDPIN__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: LEDPIN_Read
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
*  Macro LEDPIN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LEDPIN_Read(void) 
{
    return (uint8)((LEDPIN_PS & LEDPIN_MASK) >> LEDPIN_SHIFT);
}


/*******************************************************************************
* Function Name: LEDPIN_ReadDataReg
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
uint8 LEDPIN_ReadDataReg(void) 
{
    return (uint8)((LEDPIN_DR & LEDPIN_MASK) >> LEDPIN_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LEDPIN_INTSTAT) 

    /*******************************************************************************
    * Function Name: LEDPIN_ClearInterrupt
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
    uint8 LEDPIN_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(LEDPIN_INTSTAT & LEDPIN_MASK);
		LEDPIN_INTSTAT = maskedStatus;
        return maskedStatus >> LEDPIN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
