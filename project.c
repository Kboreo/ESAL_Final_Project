#include "project.h"
#include <stdio.h>
#include <stdint.h>


#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif


void SetupHardware()
{
	UartSetup();
	FloatSetup();
	setupENCODER();	
	setupPWM();
	FPUEnable();
	FPULazyStackingEnable();
}


double speed; 
double uSpeed;


int  main(void)
{		
		SetupHardware();
		printf("Hardware setup complete\n\n");
		
		printf("PWM setup complete \n\n");
		//pwmTest();

while(1)
{	
		//uSpeed = GetUserSpeed();
		speed = ReadEncoder();
		Speed_Control(speed, uSpeed); 
}
}


