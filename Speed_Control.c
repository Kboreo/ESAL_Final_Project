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

	double Target_Speed;		//Double that is used for setting the target speed of the system. 
	uint32_t Period;	//Uint used for the period.
	uint32_t Speed;	//Uint used speed 
	double Error[4] = {0,0,0,0}, speed2;	//Initilization of a double array that is used for error calculations
	double DutyC, vol, Ki, Kd;	//Doubles used for Duty Cycle and other variables used for the control system

	
//Function used for the speed control.
//Inputs: Speed and user requested speed	
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
				
				//saves errors from the last 4 error calcs
				Error[4]=Error[3];
				Error[3]=Error[2];
				Error[2]=Error[1];
				Ki = Error[1] + Error[2] + Error[3];
				Kd = (Error[2]-Error[1]) / .01;
				
				//speed corrections
				
				//Calculates error in rad/s
				Error[1] = uSpeed - Speed;
				
				//sets vol equal to the current voltage
				vol = DutyC/640*10;
				
				//sets vol equal to the current vol + error in volts from two errors ago + current error in volts * 1.247
				vol = vol + (Error[2]/640*10) + 1.247 * Error[1]/640*10;
				
				//sets duty cycle 
				DutyC = vol/10*640;	
	
				//sets limits for duty cycle
				if (DutyC < 4){
					DutyC = 4;
					}
				if (DutyC > 640){
					DutyC = 640;
					}

				//Set new PWM 
				PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, DutyC);

			}
	
		Speed = ReadEncoder(); //Set varible equal to the read speed from the "ReadEncoder" function.
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
