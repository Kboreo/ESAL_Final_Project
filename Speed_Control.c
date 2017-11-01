#include "Read_Encoder.h"
#include "Encoder.h"
#include "project.h"
#include "tm4c123gh6pm.h"	//Header file accesses registers in TMC123 microcontroller
#include "Speed_Control.h"

	double Target_Speed;
	uint32_t Period;
	uint32_t Speed;
	uint32_t Error;
	uint32_t DutyC;
void Speed_Control(double Speed, double uSpeed)
{	
	
	DutyC = ROM_PWMPulseWidthGet(PWM1_BASE, PWM_OUT_6);
	printf ("PWM duty cycle is %i\n\n", DutyC);
	
	Error = uSpeed - Speed;
	DutyC = DutyC + (.238 * Error); 
	if (DutyC < 16) DutyC = 16;
	if (DutyC > 310) DutyC = 100;
	
	//DutyC = 310; 
	
	

		//Set new PWM 
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, DutyC);
	
	
}
