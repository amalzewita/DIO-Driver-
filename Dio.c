/*****************************************************************************/
/* Module: DIO                                                               */
/* File Name: DIO.c                                                          */
/* Description: DIO Source File                                              */
/* Author: Amal Amr                                                          */
/*****************************************************************************/

// #include "TM4C123GH6PM.h"
#include "DIO_MemMap.h"
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "DIO.h"

/*****************************************************************************/
/* Service Name: Dio_ReadChannel                                             */
/* Service ID: 0x00                                                          */
/* Sync/Async: Synchronous                                                   */
/* Reentrancy: Reentrant                                                     */
/* Parameters (in): ChannelId                                                */
/* Parameters (in/out): None                                                 */
/* Parameters (out): None                                                    */
/* Return Value: Dio_LevelType                                               */
/* Description: Returns the value of the specified DIO channel.              */
/*****************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    /* Initialize the output variable to a default value of STD_LOW. */
    Dio_LevelType output = STD_LOW;

    /* Switch statement to determine the appropriate action based on the port number.
     * The port number is obtained from the configuration array using the provided ChannelId. */
    switch(config[ChannelId].portNum) 
    {
        case 0:
            /* Read the value of the specified channel from GPIO Port A.
             * GET_BIT macro is used to extract the specific bit (channel) value. */
            output = GET_BIT(GPIO_PORTA_DATA_R, config[ChannelId].chNum);
            break;
        case 1:
            /* Read the value from GPIO Port B. */
            output = GET_BIT(GPIO_PORTB_DATA_R, config[ChannelId].chNum);
            break;
        case 2:
            /* Read the value from GPIO Port C. */
            output = GET_BIT(GPIO_PORTC_DATA_R, config[ChannelId].chNum);
            break;
        case 3:
            /* Read the value from GPIO Port D. */
            output = GET_BIT(GPIO_PORTD_DATA_R, config[ChannelId].chNum);
            break;
        case 4:
            /* Read the value from GPIO Port E. */
            output = GET_BIT(GPIO_PORTE_DATA_R, config[ChannelId].chNum);
            break;
        case 5:
            /* Read the value from GPIO Port F. */
            output = GET_BIT(GPIO_PORTF_DATA_R, config[ChannelId].chNum);
            break;
        default:
            /* If the port number is not recognized, no action is taken. */
            break;
    }

    /* Return the read value. */
    return output; 
}

/*****************************************************************************/
/* Service Name: Dio_ReadPort                                                */
/* Service ID: 0x02                                                          */
/* Sync/Async: Synchronous                                                   */
/* Reentrancy: Reentrant                                                     */
/* Parameters (in): PortId                                                   */
/* Parameters (in/out): None                                                 */
/* Parameters (out): None                                                    */
/* Return Value: Dio_PortLevelType                                           */
/* Description: Returns the level of all channels of that port.              */
/*****************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{ 
    /* Initialize the output variable to a default value of STD_LOW. */
    Dio_PortLevelType output = STD_LOW; /* Initialize with zero. */

    /* Switch statement to determine the appropriate action based on the PortId. */
    switch(PortId)
    {
        case 0:
            /* Read the current value of GPIO Port A. */
            output = GPIO_PORTA_DATA_R;
            break;
        case 1:
            /* Read the current value of GPIO Port B. */
            output = GPIO_PORTB_DATA_R;
            break;
        case 2:
            /* Read the current value of GPIO Port C. */
            output = GPIO_PORTC_DATA_R;
            break;
        case 3:
            /* Read the current value of GPIO Port D. */
            output = GPIO_PORTD_DATA_R;
            break;
        case 4:
            /* Read the current value of GPIO Port E. */
            output = GPIO_PORTE_DATA_R;
            break;
        case 5:
            /* Read the current value of GPIO Port F. */
            output = GPIO_PORTF_DATA_R;
            break;
        default:
            /* No action taken if the port identifier is not recognized. */
            break;
    }

    /* Return the read value. */
    return output;
}


/*****************************************************************************/
/* Service Name: Dio_WriteChannel                                            */
/* Service ID: 0x01                                                          */
/* Sync/Async: Synchronous                                                   */
/* Reentrancy: Reentrant                                                     */
/* Parameters (in): - ChannelId                                              */
/*                  - Level                                                  */
/* Parameters (in/out): None                                                 */
/* Parameters (out): None                                                    */
/* Return Value: void                                                        */
/* Description: Service to set a level of a channel.                         */
/*****************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level) 
{
    /* Switch statement to determine the appropriate action based on the port number.
     * The port number is obtained from the configuration array using the provided ChannelId. */
    switch(config[ChannelId].portNum)
    {
        case 0:
            /* Write to GPIO Port A. */
            if(Level == STD_LOW)
            {
                /* Clear the specified channel bit if Level is STD_LOW (set to low). */
                CLEAR_BIT(GPIO_PORTA_DATA_R, config[ChannelId].chNum);
            }
            else
            {
                /* Set the specified channel bit if Level is high. */
                SET_BIT(GPIO_PORTA_DATA_R, config[ChannelId].chNum);
            }
            break;
        case 1:
            /* Write to GPIO Port B. */
            if(Level == STD_LOW)
            {
                CLEAR_BIT(GPIO_PORTB_DATA_R, config[ChannelId].chNum);
            }
            else
            {
                SET_BIT(GPIO_PORTB_DATA_R, config[ChannelId].chNum);
            }
            break;
        case 2:
            /* Write to GPIO Port C. */
            if(Level == STD_LOW)
            {
                CLEAR_BIT(GPIO_PORTC_DATA_R, config[ChannelId].chNum);
            }
            else
            {
                SET_BIT(GPIO_PORTC_DATA_R, config[ChannelId].chNum);
            }
            break;
        case 3:
            /* Write to GPIO Port D. */
            if(Level == STD_LOW)
            {
                CLEAR_BIT(GPIO_PORTD_DATA_R, config[ChannelId].chNum);
            }
            else
            {
                SET_BIT(GPIO_PORTD_DATA_R, config[ChannelId].chNum);
            }
            break;
        case 4:
            /* Write to GPIO Port E. */
            if(Level == STD_LOW)
            {
                CLEAR_BIT(GPIO_PORTE_DATA_R, config[ChannelId].chNum);
            }
            else
            {
                SET_BIT(GPIO_PORTE_DATA_R, config[ChannelId].chNum);
            }
            break;
        case 5:
            /* Write to GPIO Port F. */
            if(Level == STD_LOW)
            {
                CLEAR_BIT(GPIO_PORTF_DATA_R, config[ChannelId].chNum);
            }
            else
            {
                SET_BIT(GPIO_PORTF_DATA_R, config[ChannelId].chNum);
            }
            break;
        default:
            /* No action taken if the port number is not recognized. */
            break;  
    }
}

/*****************************************************************************/
/* Service Name: Dio_WritePort                                               */
/* Service ID: 0x03                                                          */
/* Sync/Async: Synchronous                                                   */
/* Reentrancy: Reentrant                                                     */
/* Parameters (in): - PortId                                                 */
/*                  - Level                                                  */
/* Parameters (in/out): None                                                 */
/* Parameters (out): None                                                    */
/* Return Value: void                                                        */
/* Description: Service to set a value of a channel.                         */
/*****************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    /* Switch statement to determine the appropriate port based on the PortId. */
    switch(PortId)
    {
        case 0:
            /* Write the specified Level to GPIO Port A. */
            GPIO_PORTA_DATA_R = Level;
            break;
        case 1:
            /* Write the specified Level to GPIO Port B. */
            GPIO_PORTB_DATA_R = Level;
            break;
        case 2:
            /* Write the specified Level to GPIO Port C. */
            GPIO_PORTC_DATA_R = Level;
            break;
        case 3:
            /* Write the specified Level to GPIO Port D. */
            GPIO_PORTD_DATA_R = Level;
            break;
        case 4:
            /* Write the specified Level to GPIO Port E. */
            GPIO_PORTE_DATA_R = Level;
            break;
        case 5:
            /* Write the specified Level to GPIO Port F. */
            GPIO_PORTF_DATA_R = Level;
            break;
        default:
            /* No action taken if the port identifier is not recognized. */
            break;    
    }
}

/*****************************************************************************/
/* Service Name: Dio_FlipChannel                                             */
/* Service ID: 0x11                                                          */
/* Sync/Async: Synchronous                                                   */
/* Reentrancy: Reentrant                                                     */
/* Parameters (in): - ChannelId                                              */
/* Parameters (in/out): None                                                 */
/* Parameters (out): None                                                    */
/* Return Value: Dio_LevelType                                               */
/* Description: Service to flip (change from 1 to 0 or from 0 to 1) the      */
/* level of a channel and return the level of the channel after flip.        */                         
/*****************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    /* Local variable to store the output state of the channel. */
    Dio_LevelType output = STD_LOW;

    /* Switch statement to determine the appropriate action based on the port number.
     * The port number is obtained from the configuration array using the provided ChannelId. */
    switch(config[ChannelId].portNum)
    {
        case 0:
            /* Toggle and then get the new state of the specified channel in GPIO Port A. */
            TOGGLE_BIT(GPIO_PORTA_DATA_R, config[ChannelId].chNum);
            output = GET_BIT(GPIO_PORTA_DATA_R, config[ChannelId].chNum);
            break;
        case 1:
            /* Toggle and get the state for GPIO Port B. */
            TOGGLE_BIT(GPIO_PORTB_DATA_R, config[ChannelId].chNum);
            output = GET_BIT(GPIO_PORTB_DATA_R, config[ChannelId].chNum);
            break;
        case 2:
            /* Toggle and get the state for GPIO Port C. */
            TOGGLE_BIT(GPIO_PORTC_DATA_R, config[ChannelId].chNum);
            output = GET_BIT(GPIO_PORTC_DATA_R, config[ChannelId].chNum);
            break;
        case 3:
            /* Toggle and get the state for GPIO Port D. */
            TOGGLE_BIT(GPIO_PORTD_DATA_R, config[ChannelId].chNum);
            output = GET_BIT(GPIO_PORTD_DATA_R, config[ChannelId].chNum);
            break;
        case 4:
            /* Toggle and get the state for GPIO Port E. */
            TOGGLE_BIT(GPIO_PORTE_DATA_R, config[ChannelId].chNum);
            output = GET_BIT(GPIO_PORTE_DATA_R, config[ChannelId].chNum);
            break;
        case 5:
            /* Toggle and get the state for GPIO Port F. */
            TOGGLE_BIT(GPIO_PORTF_DATA_R, config[ChannelId].chNum);
            output = GET_BIT(GPIO_PORTF_DATA_R, config[ChannelId].chNum);
            break;
        default:
            /* No action is taken if the port number is not recognized. */
            break;
    }

    /* Return the new state of the channel. */
    return output;
}
