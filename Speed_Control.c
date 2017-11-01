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
	
	
	Error = uSpeed - Speed;
	DutyC = DutyC + (.238 * Error) / 64; 
	
	

		//Set new PWM 
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, DutyC);
	
	
}
