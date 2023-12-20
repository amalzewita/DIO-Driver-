/*****************************************************************************/
/* Module: PORT                                                              */
/* File Name: PORT.c                                                         */
/* Description: PORT Source File                                             */
/* Author: Amal Amr                                                          */
/*****************************************************************************/

#include "TM4C123GH6PM.h"
#include "STD_TYPES.h"
#include "PORT.h"

/*    Function to initialize the GPIO ports.                             */
void PORT_init() 
{
    /*    Enable clock for GPIOF (LEDs and switches are on Port F)       */ 
    SYSCTL_RCGCGPIO_R |= 0x20;        /* Set the 5th bit of RCGCGPIO register to enable clock for Port F.                          */
    GPIO_PORTF_LOCK_R = 0x4C4F434B;   /* Unlock GPIO Port F. The value 0x4C4F434B ('LOCK') unlocks the GPIOCR register.            */
      
    /*    Configure Port F pins 1, 2, and 3 as outputs.                  */
    GPIO_PORTF_DIR_R |= 0x0E; /* Set the 1st, 2nd, and 3rd bits of DIR register to configure PF1, PF2, PF3 as output.              */
    GPIO_PORTF_DEN_R |= 0x0E; /* Set the 1st, 2nd, and 3rd bits of DEN register to enable digital functionality for PF1, PF2, PF3. */
    
    /*    Set button pins (PF0 and PF4) as inputs with pull-ups.         */ 
    GPIO_PORTF_DIR_R &= ~(0x11);
    
    GPIO_PORTF_CR_R = 0x11;   /* Set the 0th and 4th bits of CR register to commit any changes to PF0 and PF4.                     */
    GPIO_PORTF_PUR_R |= 0x11; /* Set the 0th and 4th bits of PUR register to enable internal pull-up resistors on PF0 and PF4.     */
    GPIO_PORTF_DEN_R |= 0x11; /* Set the 0th and 4th bits of DEN register to enable digital functionality for PF0 and PF4.         */
    
}