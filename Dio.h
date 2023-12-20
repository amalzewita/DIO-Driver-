/*****************************************************************************/
/* Module: DIO                                                               */
/* File Name: DIO.h                                                          */
/* Description: DIO Header File                                              */
/* Author: Amal Amr                                                          */
/*****************************************************************************/

#ifndef __DIO__
#define __DIO__

#include "STD_TYPES.h"
#include "DIO_cfg.h"

/*****************************************************************************/
/*      DEFINITION TYPES                                                     */
/*****************************************************************************/

/*****************************************************************************/
/* Type Name: Dio_LevelType                                                  */
/* Type: uint8                                                               */
/* Range: STD_LOW - STD_HIGH                                                 */
/* Description: These are the possible levels a DIO channel can have         */
/* (input or output)                                                         */
/*****************************************************************************/
typedef uint8_t Dio_LevelType;

/*****************************************************************************/
/* Type Name: Dio_PortLevelType                                              */
/* Type: uint                                                                */
/* Range: 0 - xxx                                                            */
/* Description: If the ?C owns ports of                                      */
/* different port widths (e.g. 4, 8,16...Bit)                                */
/* Dio_PortLevelType inherits the size of the largest port.                  */
/*****************************************************************************/
typedef uint8_t Dio_PortLevelType;

/*****************************************************************************/
/* Type Name: Dio_ChannelType                                                */
/* Type: uint                                                                */
/* Range: 0 - 7                                                              */
/* Description: Numeric ID of a DIO channel.                                 */
/*****************************************************************************/
typedef uint8_t Dio_ChannelType;

/*****************************************************************************/
/* Type Name: Dio_PortType                                                   */
/* Type: uint                                                                */
/* Range: 0 - 5                                                              */
/* Description: Numeric ID of a DIO port.                                    */
/*****************************************************************************/
typedef uint8_t Dio_PortType;

/*****************************************************************************/
/* Struct Name: Dio_ConfigType                                               */
/* Type: Struct                                                              */                            
/* Description: Conf for pins                                                */
/*****************************************************************************/
typedef struct {
  Dio_ChannelType       chNum;
  Dio_PortType          portNum;
  
}DIO_configurationType;

/*****************************************************************************/
/*      EXTERNAL VARIABLES                                                   */
/*****************************************************************************/
extern DIO_configurationType config[DIO_usedChannels];

/*****************************************************************************/
/*      FUNCTION PROTOTYPES                                                  */
/*****************************************************************************/

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
Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId );

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
void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level );

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
Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId );

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
Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId );

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
void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level );

#endif