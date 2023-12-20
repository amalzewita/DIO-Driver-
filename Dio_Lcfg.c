/*****************************************************************************/
/* Module: DIO - Configuration                                               */
/* File Name: DIO_cfg.c                                                      */
/* Description: DIO Configuration Source File                                */
/* Author: Amal Amr                                                          */
/*****************************************************************************/

//#include "TM4C123GH6PM.h" /* Include the TM4C123GH6PM microcontroller header file.                                                  */
#include "DIO_MemMap.h"     /* This file provides function declarations, macros, and definitions for digital input/output operations. */
#include "DIO.h"            /* Include the DIO (Digital Input/Output) header file.                                                    */

/* 
 * This struct array config is used for configuring the digital I/O pins.
 * Each element in the array represents the configuration for a specific channel.
 * The configuration includes the channel number and the port number.
 * The term "channel" generally refers to a specific pin on a microcontroller.
 * The term "port" refers to a group of pins on a microcontroller.
 *
 * The DIO_usedChannels is a predefined constant that specifies how many
 * channels are being used. It should be defined in the DIO_cfg.h
 *
 * Each {x_channelNum, x_portNum} pair corresponds to a specific hardware setup.
 * For example, SW1_channelNum and SW1_portNum define the channel and port number
 * for switch 1, similarly for SW2, LED1, LED2, and LED3.
 *
 * This array is typically used for initializing the pins with specific settings
 * (like input/output direction, pull-up/pull-down resistors, etc.) in the DIO module.
 */

DIO_configurationType config[DIO_usedChannels] = {
                                                    { SW1_channelNum,     SW1_portNum    }, /* Configuration for switch 1 */ 
                                                    { SW2_channelNum,     SW2_portNum    }, /* Configuration for switch 2 */ 
                                                    { LED1_channelNum,    LED1_portNum   }, /* Configuration for LED 1    */ 
                                                    { LED2_channelNum,    LED2_portNum   }, /* Configuration for LED 2    */ 
                                                    { LED3_channelNum,    LED3_portNum   }, /* Configuration for LED 3    */ 
};
