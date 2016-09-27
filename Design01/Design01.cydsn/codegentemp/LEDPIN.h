/*******************************************************************************
* File Name: LEDPIN.h  
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

#if !defined(CY_PINS_LEDPIN_H) /* Pins LEDPIN_H */
#define CY_PINS_LEDPIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LEDPIN_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LEDPIN_Write(uint8 value) ;
void    LEDPIN_SetDriveMode(uint8 mode) ;
uint8   LEDPIN_ReadDataReg(void) ;
uint8   LEDPIN_Read(void) ;
uint8   LEDPIN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LEDPIN_DRIVE_MODE_BITS        (3)
#define LEDPIN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LEDPIN_DRIVE_MODE_BITS))

#define LEDPIN_DM_ALG_HIZ         (0x00u)
#define LEDPIN_DM_DIG_HIZ         (0x01u)
#define LEDPIN_DM_RES_UP          (0x02u)
#define LEDPIN_DM_RES_DWN         (0x03u)
#define LEDPIN_DM_OD_LO           (0x04u)
#define LEDPIN_DM_OD_HI           (0x05u)
#define LEDPIN_DM_STRONG          (0x06u)
#define LEDPIN_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define LEDPIN_MASK               LEDPIN__MASK
#define LEDPIN_SHIFT              LEDPIN__SHIFT
#define LEDPIN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LEDPIN_PS                     (* (reg32 *) LEDPIN__PS)
/* Port Configuration */
#define LEDPIN_PC                     (* (reg32 *) LEDPIN__PC)
/* Data Register */
#define LEDPIN_DR                     (* (reg32 *) LEDPIN__DR)
/* Input Buffer Disable Override */
#define LEDPIN_INP_DIS                (* (reg32 *) LEDPIN__PC2)


#if defined(LEDPIN__INTSTAT)  /* Interrupt Registers */

    #define LEDPIN_INTSTAT                (* (reg32 *) LEDPIN__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define LEDPIN_DRIVE_MODE_SHIFT       (0x00u)
#define LEDPIN_DRIVE_MODE_MASK        (0x07u << LEDPIN_DRIVE_MODE_SHIFT)


#endif /* End Pins LEDPIN_H */


/* [] END OF FILE */
