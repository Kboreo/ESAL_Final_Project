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


extern double speed; 

int  main(void)
{		
		SetupHardware();
		printf("Hardware setup complete\n\n");
		
		printf("PWM setup complete \n\n");
		//pwmTest();

while(1)
{	
	 GetUserSpped();
	 ReadEncoder();
	 Speed_Control(); 
}
}


