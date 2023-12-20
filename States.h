/* Start of the header guard for the STATES header file.
 * The header guard prevents the contents of this file from being included multiple times in a single compilation,
 * which can lead to redefinition errors. This is a standard practice in C programming to ensure safe and 
 * correct compilation in multi-file projects. */
#ifndef _STATES_
#define _STATES_

/* Definition of the LED_STATES enumeration.
 * This enum defines various states for LEDs, each associated with a specific hexadecimal value.
 * These values could represent specific configurations for LED lights or be used for controlling
 * the state/color of LEDs in an embedded system or microcontroller-based application.
 *
 * The assigned hexadecimal values (0x0E, 0x02, 0x08, 0x04) likely correspond to specific settings
 * or configurations for the LEDs, which are represented by the enumerators WHITE, RED, GREEN, and BLUE. */
typedef enum {
    WHITE = 0x0E, // Represents the white state for an LED, with a specific setting value.
    RED = 0x02,   // Represents the red state for an LED, with a specific setting value.
    GREEN = 0x08, // Represents the green state for an LED, with a specific setting value.
    BLUE = 0x04   // Represents the blue state for an LED, with a specific setting value.
} LED_STATES;

/* End of the header guard. If _STATES_ is already defined, everything between 
 * #ifndef and #endif is skipped, preventing multiple inclusions of this header file. */
#endif
