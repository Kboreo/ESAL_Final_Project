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
		setupPWM();
		pwmTest();
}


