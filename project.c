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
}


int  main(void)
{		
		SetupHardware();
		printf("Hardware setup complete\n\n");
		setupPWM();
		printf("PWM setup complete \n\n");
		//pwmTest();
		setupENCODER();
}


