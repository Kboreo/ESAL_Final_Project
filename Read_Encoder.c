#include "Read_Encoder.h"
#include "Encoder.h"
#include "project.h"
#include "tm4c123gh6pm.h"	//Header file accesses registers in TMC123 microcontroller

	double i,ticks;
	double Espeed;
	int x = 0;

	//double ReadEncoder(void)
	double ReadEncoder(void)
	{	
	for (int y = 0; y<180; y++)
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
	Espeed = ticks / 19.2;
	
	printf("Speed is %.2f rps\n\n", Espeed);
///This is only a test
	
return Espeed;	
}
	}