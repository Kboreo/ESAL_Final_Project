/*********************************************************************************************************************************
**
** Module Name:   Encoder.c
**
** Module Description: C file for the code that handles all of the Encoder functionality
**
**********************************************************************************************************************************
**
** Author(s):		Kodey Boreo, Phillip Tesolin
**
**********************************************************************************************************************************/

//Includes
#include "Encoder.h"

//Function that sets up the Encoder
void setupENCODER(void)
{
	
	// Enable the peripherals used by this program.
  SysCtlPeripheralEnable(SYSCTL_PERIPH_QEI0);
  
	//Wait for the QEIO module to be ready.
	//
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_QEI0))
	{
		
	}
	
	//
// Configure the quadrature encoder to capture edges on both signals and
// maintain an absolute position by resetting on index pulses. Using a
// 1000 line encoder at four edges per line, there are 1920 pulses per
// revolution; therefore set the maximum position to 1919 as the count
// is zero based.
//
	QEIConfigure(QEI0_BASE, (QEI_CONFIG_CAPTURE_A_B | QEI_CONFIG_RESET_IDX | QEI_CONFIG_QUADRATURE | QEI_CONFIG_NO_SWAP), 1919);
//
// Enable the quadrature encoder.
//
	QEIEnable(QEI0_BASE);
	
	for (int i = 0; i<10; i++)
	{
		int noop;
	}
	
	//
// Read the encoder position.
//
	QEIPositionGet(QEI0_BASE);
	
	

	}
	