#include "project.h"
#include <stdio.h>
#include <stdint.h>

//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************

#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif


void SetupHardware()
{
	UartSetup();
//	UartSetup2();
}

void UnlockPins()
{
	//Need to Unlock PF4
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
	HWREG(GPIO_PORTF_BASE + GPIO_O_CR) = 0xFF;
	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0; 
	
}

int  main(void)
{
		
		uint8_t temp;
    volatile uint32_t ui32Loop;
	
	
	
    // Enable the GPIO port that is used for the on-board LED.
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    SetupHardware();

		
		// Check if the peripheral access is enabled.
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    
		}
		
		UnlockPins();
    
		// Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3); // set pin 3 as output
		GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0); // set pin 4 as input
		//these two switchs need an internal pull up on pins
		GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_0|GPIO_PIN_4,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);//set internal pullup R for pin 0 and 4
		
		int x;
		
		x = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0);
		
		while(x == 1)
		{
			x = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0);	
		}
			
		
    while(1)
    {
				UARTCharPut(UART0_BASE, temp);
			  temp++;
				//UARTCharPut(UART0_BASE, '\n');
				//UARTCharPut(UART0_BASE, '\r');
        // Turn on the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0xF);

        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
        {
        }

        // Turn off the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);

        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
        {
        }
    }
}


