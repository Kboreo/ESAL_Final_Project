#include "Read_Encoder.h"
#include "Encoder.h"
#include "project.h"
#include "tm4c123gh6pm.h"	//Header file accesses registers in TMC123 microcontroller
#include "Speed_Control.h"

	double Target_Speed;
	uint32_t Period;
	uint32_t Speed;
	double Error;
	uint32_t DutyC;
void Speed_Control(double Speed, double uSpeed)
{	

		
		DutyC = ROM_PWMPulseWidthGet(PWM1_BASE, PWM_OUT_6);
	
	for (int i = 0; i<100;i++)
	{
		Speed = ReadEncoder();
		Error = uSpeed - Speed;
		DutyC = DutyC + (9 * Error); 
		if (DutyC < 16) DutyC = 16;
		if (DutyC > 310) DutyC = 100;
		

		//Set new PWM 
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, DutyC);
	
	}
	Speed = ReadEncoder();
	printf("User input, IN CONTROL %.3f\n\n",uSpeed);		
	printf("Speed is, IN CONTROL %.2f rps \n\n", Speed);
	//printf ("PWM duty cycle is %i\n\n", DutyC);
}
