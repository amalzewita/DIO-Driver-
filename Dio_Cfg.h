/*****************************************************************************/
/* Module: DIO - Configuration                                               */
/* File Name: DIO_cfg.h                                                      */
/* Description: DIO Configuration Header File                                */
/* Author: Amal Amr                                                          */
/*****************************************************************************/

/* Start of the header guard for DIO_CFG_H.
 * The header guard is a preprocessor technique used to prevent the contents
 * of a header file from being included multiple times, which can lead to problems
 * such as redefinition errors. The header guard is typically the name of the file,
 * in uppercase, with underscores and a leading double underscore.
 */
#ifndef __DIO_CFG__
#define __DIO_CFG__

/* This section defines the number of channels that will be used in the DIO (Digital Input/Output) configuration.
 * The 'DIO_usedChannels' macro is set to 5, indicating that there are five different channels (like LEDs, switches)
 * that will be configured and used in the application.
 */
#define DIO_usedChannels 5

/* LED1 Definitions:
 * These macros define the port number, channel number, and channel ID for LED1.
 * - LED1_portNum: The port number where LED1 is connected (typecast to Dio_PortType for type safety).
 * - LED1_channelNum: The specific channel number on the port for LED1 (typecast to Dio_ChannelType).
 * - LED1_channelID: A unique identifier (ID) for LED1, defined as an 8-bit unsigned integer.
 */
#define LED1_portNum      (Dio_PortType)5
#define LED1_channelNum   (Dio_ChannelType)1
#define LED1_channelID    (Dio_ChannelType)0x02

/* LED2 Definitions:
 * These macros define the port number, channel number, and channel ID for LED2.
 * - LED2_portNum: The port number where LED1 is connected (typecast to Dio_PortType for type safety).
 * - LED2_channelNum: The specific channel number on the port for LED2 (typecast to Dio_ChannelType).
 * - LED2_channelID: A unique identifier (ID) for LED2, defined as an 8-bit unsigned integer.
 */
#define LED2_portNum      (Dio_PortType)5
#define LED2_channelNum   (Dio_ChannelType)2
#define LED2_channelID    (Dio_ChannelType)0x03

/* LED3 Definitions:
 * These macros define the port number, channel number, and channel ID for LED3.
 * - LED3_portNum: The port number where LED1 is connected (typecast to Dio_PortType for type safety).
 * - LED3_channelNum: The specific channel number on the port for LED3 (typecast to Dio_ChannelType).
 * - LED3_channelID: A unique identifier (ID) for LED3, defined as an 8-bit unsigned integer.
 */
#define LED3_portNum      (Dio_PortType)5
#define LED3_channelNum   (Dio_ChannelType)3
#define LED3_channelID    (Dio_ChannelType)0x04

/* SW1 (Switch 1) Definitions:
 * These macros define the port and channel number for a switch (SW1),
 * as well as a unique identifier for it.
 */
#define SW1_portNum      (Dio_PortType)5
#define SW1_channelNum   (Dio_ChannelType)0
#define SW1_channelID    (Dio_ChannelType)0x00

/* SW2 (Switch 2) Definitions:
 * These macros define the port and channel number for a switch (SW2),
 * as well as a unique identifier for it.
 */
#define SW2_portNum      (Dio_PortType)5
#define SW2_channelNum   (Dio_ChannelType)4
#define SW2_channelID    (Dio_ChannelType)0x01

/* End of the header guard.
 * If __DIO_CFG__ is already defined, everything between #ifndef and #endif is skipped,
 * preventing multiple inclusions of this header file.
 */
#endif
