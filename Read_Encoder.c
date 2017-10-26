#include "Read_Encoder.h"
#include "Encoder.h"
#include "project.h"
#include "tm4c123gh6pm.h"	//Header file accesses registers in TMC123 microcontroller

	uint32_t i,ticks;
	double speed;

	double ReadEncoder(void)
	{	
	for (int i = 0; i<2000; i++)
	{
		__nop();
	}
	//for later use
	//int  posistion = QEIPositionGet(QEI0_BASE);
	//int direction = QEIDirectionGet(QEI0_BASE);
	
//Read encoder speed
	ticks = QEIVelocityGet(QEI0_BASE);
	
	//using a 2.5cm wheel, speed in cm per second
	speed = ticks * 3.141* 2.5 / 192;
	
	printf("Speed = %.2f cm/s \n\n", speed);

return speed;	

	}