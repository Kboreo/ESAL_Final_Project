/*********************************************************************************************************************************
**
** Module Name:   Float_Setup.c
**
** Module Description: Set up for floating point
**
**********************************************************************************************************************************
**
** Author(s):		Kodey Boreo, Phillip Tesolin 
**
**********************************************************************************************************************************/


#include "Float_Setup.h"
#include "Encoder.h"
#include "tm4c123gh6pm.h"


//Variables
uint32_t first_Test[13];
uint32_t test[13];
 
 //Function used to setup the use of floating point.
void FloatSetup()
{
	first_Test[12] = 1;
	test[2] = 2;
}
 