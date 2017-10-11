/*********************************************************************************************************************************
**
** Module Name:   myPWM.c
**
** Module Description: C file for the code that handles all of the PWM functionality
**
**********************************************************************************************************************************
**
** Author(s):		Kodey Boreo
**
**********************************************************************************************************************************/

//Includes
#include "myPWM.h"

//Function that sets up the PWM
void setupPWM(void)
{
	//Set the clock to 16MHZ
  SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |   SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
	
	//Configure PWM Clock to match system
  SysCtlPWMClockSet(SYSCTL_PWMDIV_1);
	
	// Enable the peripherals used by this program.
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);  //The Tiva Launchpad has two modules (0 and 1). Module 1 covers the LED pins
	
	//Wait for the PWM1 module to be ready.
	//
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_PWM1))
	{
		
	}
	
	//Configure PF2 Pin as PWM
  GPIOPinConfigure(GPIO_PF2_M1PWM6);
	GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_2);
	
	//Configure PWM Options
	//PWM_GEN_3 Covers M1PWM6
	PWMGenConfigure(PWM1_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
	
	//Set the Period (expressed in clock ticks)
	PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, 320);
	
	//Set PWM duty-50% (Period/2)
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6,100);
	
	// Enable the PWM generator
	PWMGenEnable(PWM1_BASE, PWM_GEN_3);
	
	// Turn on the Output pins
	PWMOutputState(PWM1_BASE, PWM_OUT_6_BIT, true);
}

//Simple delay function.
void delayMS(int ms) 
{
    SysCtlDelay((SysCtlClockGet()/(3*1000))*ms);
}

void pwmTest(void)
{	
	//Fade
  bool fadeUp = true;
  unsigned long increment = 10; //Long increment
  unsigned long pwmNow = 100;	//new PWM value
	int i = 1; //Int used in while loop
	int x;  //Int that contains the output of the button SW2
	int y;  //Int that contains the output of the button SW1
	volatile int flashTime = 10; //Long that controls the speed of the flashing
	
	printf("Press SW1 to speed up flashing of LED\nPress SW2 to slow down flashing of LED\n"); 
	printf("Press both SW1 and SW2 to exit PWM\n\n");
	
  while(i == 1)
  {	
		x = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0); // set x equal to the output of button SW2 
		y = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4); // set y equal to the output of button SW1
		
		//if loop that checks if SW1 is pressed, if it is pressed, increment will be incremented, which speeds up flashing.
		if(y == 0) 
		{
			if(flashTime < 320) //If loop that checks if flash time is bigger than the period.
			flashTime++;	
		}
		
		//if loop that checks if SW2 is pressed, if it is pressed, increment will be decremented, which slows down flashing.
		else if(x == 0)
		{
			if(flashTime > 10) //If loop that checks if flash time is smaller than 10, weird crap happens after flashtime < 10.
			flashTime--;
		}
		
		//will exit PWM when both SW1 and SW2 are pressed
			if ( x == 0)
		 {
			 if (y == 0)
			 {
					i = 0;
				 PWMOutputState(PWM1_BASE, PWM_OUT_6_BIT, false); //Disable ports for PWM so ports can be used for other modules.
				 GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2); // Re-enable pin 2 on portf for GPIO usage on other modules.
			 }
		 }
		
		delayMS(20); //delay
		 
    if (fadeUp) //check if fadeUp is true
		{
			pwmNow += increment; //add the value of increment to pwmNow
      if (pwmNow >= 320) 
			{ 
				fadeUp = false; 
			}
    }
    else 
		{
			pwmNow -= increment; //subtract the value of increment to pwmNow
      if (pwmNow <= flashTime) 
			{ 
				fadeUp = true;
			}
    }        
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6,pwmNow);  //Set the pulse width to the new value, pwmNow.      
    }	
}