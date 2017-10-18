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
	
	//GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0
	
		//Need to Unlock PD7
	HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
	HWREG(GPIO_PORTD_BASE + GPIO_O_CR) = 0xFF;
	HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = 0;
	
		//Configure PD6 as QEI model 0 phase A 
		//and PD7 as QEI model 0 phase B
  GPIOPinConfigure(GPIO_PD6_PHA0);
	GPIOPinConfigure(GPIO_PD7_PHB0);
	GPIOPinTypeQEI(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7);



// Configure the quadrature encoder to capture edges on both signals and
// maintain an absolute position by resetting on index pulses. Using a
// 1000 line encoder at four edges per line, there are 1920 pulses per
// revolution; therefore set the maximum position to 1919 as the count
// is zero based.
	QEIConfigure(QEI0_BASE, (QEI_CONFIG_CAPTURE_A_B | QEI_CONFIG_RESET_IDX | QEI_CONFIG_QUADRATURE | QEI_CONFIG_NO_SWAP), 1919);

// Enable the quadrature encoder.

	QEIEnable(QEI0_BASE);

//Enables velocity capture
	QEIVelocityEnable(QEI0_BASE);	
	
	// Configures velocity capture
	QEIVelocityConfigure(QEI0_BASE, QEI_VELDIV_1, 4);
	

	
	
	for (int i = 0; i<10; i++)
	{
		int noop;
	}
	
	//
// Read the encoder position.
//
	QEIPositionGet(QEI0_BASE);
	
	
//Read encoder speed
	QEIVelocityGet(QEI0_BASE);
	
	
	

	}
	