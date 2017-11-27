/*********************************************************************************************************************************
**
** Module Name:   Read_Encoder.c
**
** Module Description: Reads the current speed 
**
**********************************************************************************************************************************
**
** Author(s):		Kodey Boreo, Phillip Tesolin 
**
**********************************************************************************************************************************/


#include "Read_Encoder.h"
#include "Encoder.h"
#include "project.h"
#include "tm4c123gh6pm.h"	//Header file accesses registers in TMC123 microcontroller

	uint32_t ticks;
	double Espeed;
	int x = 0;


	double ReadEncoder(void)
	{	


	
//Read encoder speed
	ticks = QEIVelocityGet(QEI0_BASE);
	
// speed in rad/seco
	
Espeed = ticks * 6.283185 / 19.2;
	
return Espeed;	

	}

	//for later use
	//int  posistion = QEIPositionGet(QEI0_BASE);
	//int direction = QEIDirectionGet(QEI0_BASE);