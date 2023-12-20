#include "tm4c123gh6pm.h"
#include "types.h"
#include "SPI0.h"
#define GET_BIT(REG,BIT) (((REG)&(1<<(BIT)))>>(BIT))
#define CLOCK_FREQ 16000000 // Assuming a system clock of 16MHz
#define DESIRED_SPI_CLK_SPEED 1000000 // Desired SPI clock speed (1MHz in this case)


void init_SPI0() {
  
      // Enable the SSI0 module clock
    SYSCTL_RCGCSSI_R |= SYSCTL_RCGCSSI_R0;
    
    // Enable the GPIO port that is used for the SSI0 function (e.g., Port A)
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0; // Replace 0 with the appropriate value for the GPIO port

    // Configure the appropriate pins for the SSI0 function
    GPIO_PORTA_AFSEL_R |= ((1<<2) | (1<<3) | (1<<4) | (1<<5)); // Replace X with the GPIO port letter and define the pins for CLK, FSS, RX, TX
    GPIO_PORTA_PCTL_R =  0x00222200; // Replace X with the GPIO port letter and configure the pins for SSI function
    GPIO_PORTA_DEN_R |= ((1<<2) | (1<<3) | (1<<4) | (1<<5)); // Replace X with the GPIO port letter and enable the pins for digital I/O
    GPIO_PORTA_DIR_R |= (1<<5); // Replace X with the GPIO port letter and set the TX pin as output (if needed)



    // Disable SSI0 module before configuring it
    SSI0_CR1_R = 0X00;

    // Configure SSI0 operation mode, clock frequency, and data frame format
    SSI0_CC_R = 0x0; // Use system clock
    SSI0_CPSR_R =  0x10  ; //(CLOCK_FREQ / (2 * DESIRED_SPI_CLK_SPEED)) - 1; // Set clock prescaler
    SSI0_CR0_R = 0x07; //((CLOCK_FREQ / DESIRED_SPI_CLK_SPEED) << 8); // Set clock rate
    //SSI0_CR0_R |= 0X0F; // DSS
    // Enable SSI0 module and interrupts
    //SSI0_IM_R |= SSI_IM_RXIM; // Enable receive FIFO interrupt
    //NVIC_EN0_R |= (1 << 7); // Enable SSI0 interrupt in NVIC
    
    SSI0_CR1_R |= 0X02;
    
    
    
}
void SSI0_Handler() {

}
uint16_t SPI0_receive(uint16_t DATA){
    // Wait until receive FIFO is not empty
    /*while (!(GET_BIT(SSI0_SR_R,1)))
    {
      
        // You can add a timeout mechanism here to prevent infinite waiting
    }*/
  while (!(GET_BIT(SSI0_SR_R,1)));
    SSI0_DR_R=DATA;
    // Read received data from the data register
    return (uint16_t)(SSI0_DR_R & 0xFF);
}