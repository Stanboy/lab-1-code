/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    //PWM_Start();
    for(;;)
    {
        
       
        Pin_LED_Write(~Pin_LED_Read());  //toggl pin state
        CyDelay(1000); //system delay of 1 second
        //Pin_LED2_Write(~Pin_LED2_Read());  //toggl pin state
        //CyDelay(1000); //system delay of 1 second
        //Pin_LED3_Write(~Pin_LED3_Read());  //toggl pin state
        //CyDelay(1000); //system delay of 1 second
    }
}

/* [] END OF FILE */
