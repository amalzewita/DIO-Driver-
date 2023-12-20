/*****************************************************************************/
/* Module: DIO - Registers                                                   */
/* File Name: DIO_MemMap.h                                                   */
/* Description: DIO Memory Registers Header File                             */
/* Author: Amal Amr                                                          */
/*****************************************************************************/

/* Start of the header guard for DIO_REGS_H.
 * Header guards prevent the contents of this file from being included multiple times in a single compilation,
 * which can lead to redefinition errors. This is a standard practice in C programming to ensure safe and 
 * correct compilation in multi-file projects. */
#ifndef DIO_REGS_H
#define DIO_REGS_H

/* Include the STD_TYPES.h header file.
 * This file likely contains standard type definitions used throughout your project. */
#include "STD_TYPES.h"

/* Definition of GPIO Port Data Registers.
 * These macros define the addresses of the data registers for GPIO ports (A to F).
 * The addresses are cast to pointers to volatile uint32_t, ensuring proper access to hardware registers.
 * The 'volatile' keyword is used to tell the compiler not to optimize these accesses, as the value can change unexpectedly.
 * These registers are used for direct manipulation of the GPIO ports. */
#define GPIO_PORTA_DATA_R       (*((volatile uint32_t *)0x400043FC)) /* Data register for GPIO Port A */
#define GPIO_PORTB_DATA_R       (*((volatile uint32_t *)0x400053FC)) /* Data register for GPIO Port B */
#define GPIO_PORTC_DATA_R       (*((volatile uint32_t *)0x400063FC)) /* Data register for GPIO Port C */
#define GPIO_PORTD_DATA_R       (*((volatile uint32_t *)0x400073FC)) /* Data register for GPIO Port D */
#define GPIO_PORTE_DATA_R       (*((volatile uint32_t *)0x400243FC)) /* Data register for GPIO Port E */
#define GPIO_PORTF_DATA_R       (*((volatile uint32_t *)0x400253FC)) /* Data register for GPIO Port F */

/* End of the header guard.
 * If DIO_REGS_H is already defined, everything between #ifndef and #endif is skipped,
 * preventing multiple inclusions of this header file. */
#endif /* DIO_REGS_H */
