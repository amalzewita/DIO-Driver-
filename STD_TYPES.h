#ifndef _STD_TYPES_
#define _STD_TYPES_ 

/* Definition of standard high and low states. */
#define STD_HIGH        (1U) /* Define standard high state as 1. */
#define STD_LOW         (0U) /* Define standard low state as 0. */

// Type definitions for standard integer sizes

// 8-bit signed integer
typedef signed char              int8_t;

// 8-bit unsigned integer
typedef unsigned char            uint8_t;

// 16-bit signed integer
typedef signed short             int16_t;

// 16-bit unsigned integer
typedef unsigned short           uint16_t;

// 32-bit signed integer
typedef signed long              int32_t;

// 32-bit unsigned integer
typedef unsigned long            uint32_t;

// 64-bit signed integer
typedef signed long long         int64_t;

// 64-bit unsigned integer
typedef unsigned long long       uint64_t;

// Type definitions for standard floating-point sizes

// 32-bit floating point
typedef float                    float32_t;

// 64-bit floating point
typedef double                   float64_t;

// Extended precision floating point (typically 80-bit, but platform dependent)
typedef long double              float80_t;

// Character type definition
typedef char                     char_t;


#endif