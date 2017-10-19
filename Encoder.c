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
#include "tm4c123gh6pm.h"	//Header file accesses registers in TMC123 microcontroller


#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400073FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40007400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40007420))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40007510))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4000751C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40007520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40007524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40007528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4000752C))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))

//Function that sets up the Encoder
void setupENCODER(void)
{
	

  volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000008;     // 1) General purpose I/O Peripheral Ready
  delay = SYSCTL_RCGC2_R;           // reading register adds a delay   
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0  
  GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0       
  GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog function
  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4,PF0 input, PF3,PF2,PF1 output   
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) no alternate function
  //GPIO_PORTF_PUR_R = 0x11;          // enable pullup resistors on PF4,PF0       
  GPIO_PORTF_DEN_R = 0x1F;          // 7) enable digital pins PF4-PF0  
	
	// Enable the peripherals used by this program.
  SysCtlPeripheralEnable(SYSCTL_PERIPH_QEI0);
	
	//GPIOPinTypeGPIOInput(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7); //SET PD6 & 7 as input
  //GPIOPadConfigSet(GPIO_PORTD_BASE,GPIO_PIN_6|GPIO_PIN_7,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);//set internal pullup R
	//Wait for the QEIO module to be ready.
	//
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_QEI0))
	{
		
	}
	
// Enable the quadrature encoder.
	QEIEnable(QEI0_BASE);
	
//Enables velocity capture
	QEIVelocityEnable(QEI0_BASE);

// Configure the quadrature encoder to capture edges on both signals and
// maintain an absolute position by resetting on index pulses. Using a
// 1000 line encoder at four edges per line, there are 1920 pulses per
// revolution; therefore set the maximum position to 1919 as the count
// is zero based.
	QEIConfigure(QEI0_BASE, (QEI_CONFIG_CAPTURE_A_B | QEI_CONFIG_NO_RESET | QEI_CONFIG_QUADRATURE | QEI_CONFIG_NO_SWAP), 1919);



	
	
	// Configures velocity capture
	QEIVelocityConfigure(QEI0_BASE, QEI_VELDIV_2, 5000);
	
	
	
	

//Configure PD6 as QEI model 0 phase A 
//and PD7 as QEI model 0 phase B
  GPIOPinConfigure(GPIO_PD6_PHA0);
	GPIOPinConfigure(GPIO_PD7_PHB0);
	GPIOPinTypeQEI(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7);
	
	
	for (int i = 0; i<1000; i++)
	{
		int noop;
	}
	
	//
// Read the encoder position.
	
	while(1)
	{
//
	QEIPositionGet(QEI0_BASE);
	QEIDirectionGet(QEI0_BASE);
	
	
//Read encoder speed
	double speed = QEIVelocityGet(QEI0_BASE);
	
	printf("Speed = %f\n\n", speed);
	
	}
	

	}


	