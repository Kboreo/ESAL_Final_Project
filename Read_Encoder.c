#include "Read_Encoder.h"
#include "Encoder.h"
#include "project.h"
#include "tm4c123gh6pm.h"	//Header file accesses registers in TMC123 microcontroller

	uint32_t ticks;
	double Espeed;
	int x = 0;

	//double ReadEncoder(void)
	double ReadEncoder(void)
	{	
//	while (1)
	//{
	//for (int y = 0; y<400; y++)
	//	{
	//	for (int i = 0; i<100; i++)
	//{
	//	__nop();
	//}
//}	
	//for later use
	//int  posistion = QEIPositionGet(QEI0_BASE);
	//int direction = QEIDirectionGet(QEI0_BASE);
	
//Read encoder speed
	ticks = QEIVelocityGet(QEI0_BASE);
	
	//using a 2.5cm wheel, speed in rad/seco
	
Espeed = ticks * 12.56637 / 192;

//printf("Espeed = %.2f\n\n", Espeed);
	
//}
	
return Espeed;	

	}