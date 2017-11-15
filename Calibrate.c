#include "Read_Encoder.h"
#include "Encoder.h"
#include "project.h"
#include "tm4c123gh6pm.h"	//Header file accesses registers in TMC123 microcontroller
#include "Speed_Control.h"
#include "Calibrate.h"

#include <stdio.h>
#include <stdint.h>


#include "tm4c123gh6pm.h"	




void Calibrate (void)
{
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, 0);
	int i = 0;
	int t = 1;
	int A = 1;
	double calspeed;
	
PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, 320);
	
 calspeed = ReadEncoder();

	printf("cal speed = %.2f\n\n", calspeed);
	
	
	
	

}
	
