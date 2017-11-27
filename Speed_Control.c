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
	double Error, speed2;
	double DutyC;
void Speed_Control(double Speed, double uSpeed)
{	

	
	//sets duty cycle to predicted value needed to achieve speed
	DutyC = uSpeed * 19;
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, DutyC);

	//Delay to allow motor to achieve speed preset
	for (int i = 0; i<1600000;i++)
	{
		__nop;
	}	
	while(1)
	{
	
	for (int i = 0; i<100;i++)
	{
	Speed= ReadEncoder();
	speed2 = Speed;
		
		i=0;
	while(Speed == speed2){
		Speed = ReadEncoder();
		i++;
		if (i >999){
		break;
		}
	}
		Error = uSpeed - Speed;
		DutyC =(10 * Error)+DutyC; 
		if (DutyC < 1) {
			DutyC = 1;
		}
		if (DutyC > 310){
			DutyC = 320;
		}

		//Set new PWM 
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, DutyC);
//		for (int i = 0; i<16000000;i++)
//	{
//		__nop;
//	}	
	
	
//		for (int i = 0; i<1600000;i++)
//	{
//		__nop;
//	}	
}
	Speed = ReadEncoder();
	//printf("User input, IN CONTROL %.3f\n\n",uSpeed);		
	printf("Speed is, IN CONTROL %.2f rps \n\n", Speed);
	//printf ("PWM duty cycle is %.2f\n\n", DutyC);

}
	}
