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
	PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, 640);
	
	//Set PWM duty-50% (Period/2)
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, 10);
	
	// Enable the PWM generator
	PWMGenEnable(PWM1_BASE, PWM_GEN_3);
	
	// Turn on the Output pins
	PWMOutputState(PWM1_BASE, PWM_OUT_6_BIT, true);
}

void stopmotor(void)
{
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, 10);
}
	

//Simple delay function.
void delayMS(int ms) 
{
    SysCtlDelay((SysCtlClockGet()/(3*1000))*ms);
}

//void pwmTest(void)
//{	
//	//Fade
//  bool fadeUp = true;
//  unsigned long increment = 10; //Long increment
//  unsigned long pwmNow = 100;	//new PWM value
//	int i = 1; //Int used in while loop
//	int x;  //Int that contains the output of the button SW2
//	int y;  //Int that contains the output of the button SW1
//	volatile int flashTime = 10; //Long that controls the speed of the flashing
//	
//}
	