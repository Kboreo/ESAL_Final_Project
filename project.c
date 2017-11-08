#include "project.h"
#include <stdio.h>
#include <stdint.h>

bool TESTING = 1;  //bool used for debugging and testing features.

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


double speed; 	//Speed read from encoder
double uSpeed;	//Requested speed from the user


int  main(void)
{	
	SetupHardware();  //Initializes all of the required HardWare for the project.			
	printf("Hardware setup complete\n\n");		
	printf("PWM setup complete \n\n");
	
	while(1)
	{	
		uSpeed = GetUserSpeed();
		//printf("User input, IN MAIN %.3f\n\n",uSpeed);
		//speed = ReadEncoder();
		//printf("Speed is, IN MAIN %.2f rps \n\n", speed);
		Speed_Control(speed, uSpeed); 
	}
}


