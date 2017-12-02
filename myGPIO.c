/*********************************************************************************************************************************
**
** Module Name:   myGPIO.c
**
** Module Description: Handles the GPIO Module for the project
**
**********************************************************************************************************************************
**
** Author(s):		Kodey Boreo, Phillip Tesolin 
**
**********************************************************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include "myGPIO.h"

#include "tm4c123gh6pm.h"	//Header file accesses registers in TMC123 microcontroller

//define easy to read names for registers
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))

//Global Variables
unsigned long SW1, SW2;  	//input from PF0 and PF4

//   Function Prototypes
void PortF_Init(void);		
void Delay(void);

void setup_IO()
{
	//Enable the GPIO port that is used for the on-board LED.
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	//Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
  //enable the GPIO pin for digital function.
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_1); // set pin 3,2, and 1 as output
	GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0); // set pin 4 and 0 as input
	//these two switches need an internal pull up on pins
	GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_0|GPIO_PIN_4,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);//set internal pullup R for pin 0 and 4
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
  {
    
	}	
	//Need to Unlock PF4
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
	HWREG(GPIO_PORTF_BASE + GPIO_O_CR) = 0xFF;
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;
	//3. Subroutines Section
   
  PortF_Init();		//Call initialization of port PF0-PF4    

}

// Subroutine to initialize port F pins for input and output
// PF4 and PF0 are input SW1 and SW2 respectively
// PF3,PF2,PF1 are outputs to the LED
void PortF_Init(void)
	{ 
  volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000020;     // 1) F clock
  delay = SYSCTL_RCGC2_R;           // reading register adds a delay   
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0  
  GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0       
  GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4,PF0 input, PF3,PF2,PF1 output   
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) no alternate function
  GPIO_PORTF_PUR_R = 0x11;          // enable pullup resistors on PF4,PF0       
  GPIO_PORTF_DEN_R = 0x1F;          // 7) enable digital pins PF4-PF0        
}

void pinReadAndWrite(uint32_t ui32Loop,uint8_t temp)
{
	int i = 1;
	printf("Press SW1 to turn on Blue LED\nPress SW2 to turn on Red LED\n"); 
	printf("Press both SW1 and SW2 to exit GPIO\n\n");
	
	
	while (i == 1)
	{
		int x;  //Int that contains the output of the button SW2
		int y;  //Int that contains the output of the button SW1

		x = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0); // set x equal to the output of button SW2 
		y = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4); // set y equal to the output of button SW1		
			
			if (y == 0) //if loop that checks if SW1 is pressed, if it is pressed, blue LED will light.
			{
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0xF);  // Turn on blue LED
				
        //Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
        {
        }

        //Turn off the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);

        //Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
        {
        }			
			}
			else if (x == 0) //if loop that checks if SW2 is pressed, if  pressed, red LED will light.
			{
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xF);  // Turn on blue LED
				
        //Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
        {
        }

        //Turn off the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);

        //Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
        {
        }				
			}
			//will exit GPIO when both SW1 and SW2 are pressed
			if ( x == 0)
		 {
			 if (y == 0)
			 {
					i = 0;
			 }
		 }				
    }		
}
	