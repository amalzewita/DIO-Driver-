/*****************************************************************************/
/* Module: PORT                                                              */
/* File Name: PORT.h                                                         */
/* Description: PORT Header File                                             */
/* Author: Amal Amr                                                          */
/*****************************************************************************/

/* Start of the header guard for the PORT module. 
 * The header guard prevents the contents of this file from being included multiple times, 
 * which can lead to redefinition errors. This is a common practice in C programming 
 * to avoid such issues in multi-file projects. */
#ifndef __PORT__
#define __PORT__

/* Declaration of the PORT_init function. 
 * This function is likely responsible for initializing certain hardware ports, 
 * possibly setting up GPIO (General Purpose Input/Output) configurations 
 * or other hardware-related settings. The function is declared here but 
 * should be defined in a corresponding .c file where the actual implementation details are provided. */
void PORT_init();

#define PORTA   0  /* Represents port A. */
#define PORTB   1  /* Represents port B. */
#define PORTC   2  /* Represents port C. */
#define PORTD   3  /* Represents port D. */
#define PORTE   4  /* Represents port E. */
#define PORTF   5  /* Represents port F. */

/* End of the header guard. If __PORT__ is already defined, everything between 
 * #ifndef and #endif is skipped, preventing multiple inclusions of this header file. */
#endif
