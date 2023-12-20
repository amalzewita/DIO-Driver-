/* Macro: SET_BIT
 * This macro sets a specific bit in a register.
 * It achieves this by performing a bitwise OR operation between the register (REG) and 1 shifted left by the bit position (BIT).
 * Setting a bit is often used to activate or enable a specific function or feature in hardware programming.
 */
#define SET_BIT(REG,BIT) ((REG) |= (1<<(BIT)))

/* Macro: CLEAR_BIT
 * This macro clears (resets) a specific bit in a register.
 * It does this by AND-ing the register (REG) with the bitwise NOT of 1 shifted left by the bit position (BIT).
 * Clearing a bit is often used to deactivate or disable a specific function or feature in hardware programming.
 */
#define CLEAR_BIT(REG,BIT) ((REG) &= (~(1<<(BIT))))

/* Macro: TOGGLE_BIT
 * This macro toggles (flips) a specific bit in a register.
 * It uses XOR operation on the register (REG) with 1 shifted left by the bit position (BIT).
 * Toggling is useful for switching the state of a bit between 0 and 1 repeatedly.
 */
#define TOGGLE_BIT(REG,BIT) ((REG) ^= (1<<(BIT)))

/* Macro: GET_BIT
 * This macro retrieves the state (0 or 1) of a specific bit in a register.
 * It isolates the desired bit by AND-ing the register (REG) with 1 shifted left by BIT, then shifts right by BIT.
 * This moves the desired bit to the least significant bit position for easy evaluation.
 */
#define GET_BIT(REG,BIT) (((REG)&(1<<(BIT)))>>(BIT))
