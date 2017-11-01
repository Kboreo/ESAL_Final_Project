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
#define SYSCTL_RCGCGPIO_R				(*((volatile unsigned long *)0x400FE644))




//Function that sets up the Encoder
void setupENCODER(void)
{
//	uint32_t i,ticks;
//	double w,speed;
	//enables peripheral QEI
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
  SysCtlPeripheralEnable(SYSCTL_PERIPH_QEI0);

	//Unlock GPIOD7 
	HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY; //(0x4C4F434B)
	HWREG(GPIO_PORTD_BASE + GPIO_O_CR) |= 0x80;
	HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = 0;

	//Set Pins to be PHA0 and PHB0
	GPIOPinConfigure(GPIO_PD6_PHA0);
	GPIOPinConfigure(GPIO_PD7_PHB0);

	//Set GPIO pins for QEI. PhA0 -> PD6, PhB0 ->PD7.
	GPIOPinTypeQEI(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7);
	GPIOPadConfigSet(GPIO_PORTD_BASE, GPIO_PIN_6 |  GPIO_PIN_7, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD); // change push pull gpio

	//Disable peripheral and int before configuration
	QEIIntDisable(QEI0_BASE,QEI_INTERROR | QEI_INTDIR | QEI_INTTIMER | QEI_INTINDEX); 

	// Configure quadrature encoder
	QEIConfigure(QEI0_BASE, (QEI_CONFIG_CAPTURE_A_B  | QEI_CONFIG_NO_RESET 	| QEI_CONFIG_QUADRATURE | QEI_CONFIG_NO_SWAP), 1919);  //maxima posicion


	
	// Enable the quadrature encoder, filter and velocity capture
	// clock tick = .625x10^-9 seconds.. 
	QEIEnable(QEI0_BASE);
	QEIFilterEnable(QEI0_BASE);
	QEIVelocityEnable(QEI0_BASE);
	QEIVelocityConfigure(QEI0_BASE, QEI_VELDIV_2, 160000);//capture velocity after .01 seconds
  QEIFilterConfigure(QEI0_BASE, QEI_FILTCNT_2);


}


	