/*********************************************************************************************************************************
**
** Module Name:   Speed_Control
**
** Module Description: Controls the speed of the motor based on user input in Get_Speed.c 
**
**********************************************************************************************************************************
**
** Author(s):		Kodey Boreo, Phillip Tesolin 
**
**********************************************************************************************************************************/


#include "Read_Encoder.h"
#include "Encoder.h"
#include "project.h"
#include "tm4c123gh6pm.h"	//Header file accesses registers in TMC123 microcontroller
#include "Speed_Control.h"

	double Target_Speed;
	uint32_t Period;
	uint32_t Speed;
	double Error , speed2;
	double DutyC, vol;	

	
	
void Speed_Control(double Speed, double uSpeed)
	
{	
	int i = 1;
	int x; 
	int a = 0;
	
	while (i == 1)
	{				
		//adjusts speed 10 times before printing speed
		for (int i = 0; i<10;i++)
			{
			Speed= ReadEncoder();
			speed2 = Speed;		
		
			//waits here for speed to change 
			a=0;	
			while(Speed == speed2){
				Speed = ReadEncoder();
				a++;
				if (a >999){
				break;
				}
				}
				
				
				//speed corrections
				Error = uSpeed - Speed;
				vol = DutyC/640*10;
				vol = vol + .04 * Error; 
				DutyC = vol/10*640;	
	
				//sets limits for duty cycle
				if (DutyC < 4) {
					DutyC = 4;
					}
				if (DutyC > 640){
					DutyC = 640;
					}

				//Set new PWM 
				PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, DutyC);

			}
	
		Speed = ReadEncoder();
		printf("Speed is, IN CONTROL %.2f rps \n\n", Speed);
	
		//will exit GPIO when SW2 is pressed
		x = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0); // set x equal to the output of button SW2 		
			if ( x == 0){
					i = 0;
			}	

}
		//turns off motor before exiting 
		stopmotor();
	}
