/*********************************************************************************************************************************
**
** Module Name:   project.c
**
** Module Description: Main Project C file 

**This program performs two main functions. The first is to calculate the first order transfer function of a motor based on a step
**input. When the Calibrate function is called and executed a step input sent to the motor with via a PWM signal with 100 percent 
**duty cycle. The voltage across the motor is reduced by a voltage divider then read into an ADC channel. The motor speed is read 
**every 10mS and stored in memory until the speed remains constant. Once the speed remains constant the time constant (t) for the 
**transfer function is calculated by finding the time the motor took to reach its steady state speed multiplied by (1-e^-1). The 
**gain (K) value is calculated by dividing its final speed by the input voltage. Once these values are known a first order transfer
**function can be derived in the form k/(ts+1).
**The second function asks the user for a desired speed then through PWM the microcontroller maintains that speed regardless of the 
**load placed on the motor. Every 10mS the encoder reads the motors current speed. The difference between the desired speed and the 
**actual speed is multiplied by a gain and adjusts the PWM signal to compensate for this load. In addition to compensating for the 
**error between current speed and desired speed the controller also adds compensation for small errors over long periods and 
**compensation for rate of change. 

**
**********************************************************************************************************************************
**
** Author(s):		Kodey Boreo, Phillip Tesolin 
**
**********************************************************************************************************************************/



#include "project.h"
#include <stdio.h>
#include <stdint.h>

bool TESTING = 1;  //bool used for debugging and testing features.

#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif

void mainMenu(char ctemp);

void SetupHardware()
{
	UartSetup();
	FloatSetup();
	setupENCODER();	
	setupPWM();
	FPUEnable();
	FPULazyStackingEnable();
	SetupADC();
}


double speed; 	//Speed read from encoder
double uSpeed;	//Requested speed from the user


int  main(void)
{	
	char ctemp; //Temp char used for UART
	SetupHardware();  //Initializes all of the required HardWare for the project.			
	printf("Hardware setup complete\n\n");		
	printf("PWM setup complete \n\n");
	
	//initialize_aandw();
	
	
	
		mainMenu(ctemp);
}	
	
//Main menu that displays to the UART terminal for a HMI	
void mainMenu(char ctemp)
{	
	//While loop for main user menu	

	while (1)
{
		printf("What function would you like to test?\n 1.Calibrate\n 2.Speed Control\n"); //Askes user what function they would like to use.
		ctemp = getc(stdin); //Gets a char from the terminal from the user.
		printf("You entered %c\n\n",ctemp); //Lets the user know what they have selected
		
		switch (ctemp)		//Switch statement that selects which function depending on the user input.
		{
			//GPIO
			case '1':						
			Calibrate(); 
				break;	
			
			
		

			case '2':		
			uSpeed = GetUserSpeed();
		//printf("User input, IN MAIN %.3f\n\n",uSpeed);
		//speed = ReadEncoder();
		//printf("Speed is, IN MAIN %.2f rps \n\n", speed);
			Speed_Control(speed, uSpeed); 		
				break;
			
						

			
			//Default case if user types anything other than the given options
			default:				
				printf("Ya done messed up, try again!\n\n");
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);  // Turn off LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);  // Turn off LED
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);  // Turn off LED
				break;		
		}
	}	
}


