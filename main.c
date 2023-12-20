#include "TM4C123GH6PM.h" /* Include the TM4C123GH6PM microcontroller header file.                                                  */
#include "DIO.h"          /* Include the DIO (Digital Input/Output) header file.                                                    */
#include "States.h"       /* Include the States header file, possibly defining various states used in the program.                  */
#include "PORT.h"

int main()
{
  /*    Initialize the previous state of SW1 to BLUE.                    */
  LED_STATES PrevSW1State = BLUE;
  
  /*    Call the PORT initialization function.                           */
  PORT_init();
  
  /*    Check if switch SW1 is pressed.                                  */
  while(1)
  {
    if( !(Dio_ReadChannel(SW1_channelID) ) )
    {
      /*    Toggle between BLUE and GREEN states when SW1 is pressed.    */
      if( PrevSW1State == BLUE )
      {
        PrevSW1State = GREEN;                        /*    Update the state to GREEN.                                                */
        Dio_WritePort(PORTF,BLUE);                   /*    Turn on the BLUE LED.                                                     */
        while( !(Dio_ReadChannel(SW1_channelID) ) ); /*    Wait until SW1 is released.                                               */ 
      }
      else
      {
        PrevSW1State = BLUE;                         /* Update the state to BLUE.                                                    */
        Dio_WritePort(PORTF,GREEN);                  /* Turn on the GREEN LED.                                                       */
        while( !(Dio_ReadChannel(SW1_channelID) ) ); /*  Wait until SW1 is released.                                                 */
      }
    }
    /* Check if switch SW2 is pressed. */
    else if( !(Dio_ReadChannel(SW2_channelID) ) )
    {
      Dio_WritePort(PORTF,WHITE);                    /* Turn on the WHITE LED.                                                       */
      while( !(Dio_ReadChannel(SW2_channelID) ) );   /* Wait until SW2 is released.                                                  */
    }
    /*    If no switch is pressed, turn on the RED LED.                  */
    else
    {
      Dio_WritePort(PORTF,RED);                    /* Turn on the RED LED.                                                         */
    }
  }
}
