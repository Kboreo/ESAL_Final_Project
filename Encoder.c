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
	//SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ); //40MHz
	 //habilita perfierico QEI
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_QEI0);


	//Unlock GPIOD7 - Like PF0 its used for NMI - Without this step it doesn't work
	HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY; //In Tiva include this is the same as "_DD" in older versions (0x4C4F434B)
	HWREG(GPIO_PORTD_BASE + GPIO_O_CR) |= 0x80;
	HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = 0;


	//Set Pins to be PHA0 and PHB0
	GPIOPinConfigure(GPIO_PD6_PHA0);
	GPIOPinConfigure(GPIO_PD7_PHB0);

	//Set GPIO pins for QEI. PhA0 -> PD6, PhB0 ->PD7.
	GPIOPinTypeQEI(GPIO_PORTD_BASE, GPIO_PIN_6 |  GPIO_PIN_7);
	GPIOPadConfigSet(GPIO_PORTD_BASE, GPIO_PIN_6 |  GPIO_PIN_7, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD); // change push pull gpio

	//Disable peripheral and int before configuration
	//QEIDisable(QEI0_BASE);
	QEIIntDisable(QEI0_BASE,QEI_INTERROR | QEI_INTDIR | QEI_INTTIMER | QEI_INTINDEX); //desabilita todas las interrupciones

	// Configure quadrature encoder, use an arbitrary top limit of 1000
	// 4 pulsos por linea
	// encoder de 2048 PPR max 7500 RPM
	QEIConfigure(QEI0_BASE, (QEI_CONFIG_CAPTURE_A_B  | QEI_CONFIG_NO_RESET 	| QEI_CONFIG_QUADRATURE | QEI_CONFIG_NO_SWAP), 1919);  //maxima posicion


	
	// Enable the quadrature encoder.
	QEIEnable(QEI0_BASE);
	QEIVelocityEnable(QEI0_BASE);
	QEIVelocityConfigure(QEI0_BASE, QEI_VELDIV_2, 0xffffff);
  QEIFilterConfigure(QEI0_BASE, 3);

//Set position to a middle value so we can see if things are working
QEIPositionSet(QEI0_BASE, 0);

	while(1)
	{	
	for (int i = 0; i<999; i++)
	{
		for (int i = 0; i<999; i++)
	{
		

	}	

	}
	
	//
// Read the encoder position.
	

//
	QEIPositionGet(QEI0_BASE);
	QEIDirectionGet(QEI0_BASE);
	
	
//Read encoder speed
	double speed = QEIVelocityGet(QEI0_BASE);
	
	printf("Speed = %d\n\n", speed);
	//printf("float = %f\n\n", speed);
		
	int ticks = QEIVelocityGet(QEI0_BASE);
		
		printf("ticks = %d\n\n", ticks);
	
	}
	
	
//	
//	//Enable the GPIO port that is used for the Encoder
//	
////	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
////	  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD))
// // {
//    
//	//}
////QEI on PDS PD6 PD7	
// volatile unsigned long delay;
//	SYSCTL_RCGCGPIO_R |= 0X01; 				//QEI run mode clock gating control
//  SYSCTL_RCGC2_R |= 0x00000008;     // 1) General purpose I/O Peripheral Ready
//  delay = SYSCTL_RCGC2_R;           // reading register adds a delay   
//  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0  
//  GPIO_PORTF_CR_R = 0xFF;           // allow changes to PD      
//  GPIO_PORTF_AMSEL_R &= 0x00;        // 3) disable analog function
//  GPIO_PORTF_AFSEL_R = 0xC0;        // 6) alternate function selected 
//	GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0x00FF0FFF)+0x66006000;    // 4) select peripheral for encoder 
//  GPIO_PORTF_DIR_R &=  ~0xC0;          // 5) sets port D as input  
//  
//  //GPIO_PORTF_PUR_R = 0x11;          // enable pullup resistors on PF4,PF0       
//  GPIO_PORTF_DEN_R = 0xFF;          // 7) enable digital pins PF4-PF0  
//	
//	// Enable the peripherals used by this program.
// SysCtlPeripheralEnable(SYSCTL_PERIPH_QEI0);
//	
//	//GPIOPinTypeGPIOInput(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7); //SET PD6 & 7 as input
//  //GPIOPadConfigSet(GPIO_PORTD_BASE,GPIO_PIN_6|GPIO_PIN_7,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);//set internal pullup R
//	//Wait for the QEIO module to be ready.
//	//
//	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_QEI0))
//	{
//		
//	}
//	
//// Enable the quadrature encoder.
//	QEIEnable(QEI0_BASE);
//	
////Enables velocity capture
//	QEIVelocityEnable(QEI0_BASE);

//// Configure the quadrature encoder to capture edges on both signals and
//// maintain an absolute position by resetting on index pulses. Using a
//// 1000 line encoder at four edges per line, there are 1920 pulses per
//// revolution; therefore set the maximum position to 1919 as the count
//// is zero based.
//	QEIConfigure(QEI0_BASE, (QEI_CONFIG_CAPTURE_A_B | QEI_CONFIG_NO_RESET | QEI_CONFIG_QUADRATURE | QEI_CONFIG_NO_SWAP), 1919);



//	
//	
//	// Configures velocity capture
//	QEIVelocityConfigure(QEI0_BASE, QEI_VELDIV_2, 500);
//	
//	
//	
//	

////Configure PD6 as QEI model 0 phase A 
////and PD7 as QEI model 0 phase B
//  GPIOPinConfigure(GPIO_PD6_PHA0);
//	GPIOPinConfigure(GPIO_PD7_PHB0);
//	GPIOPinTypeQEI(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7);
//	
//	while(1)
//	{	
//	for (int i = 0; i<999; i++)
//	{
//		for (int t = 0; t<999; t++)
//		{
//			int g = g + 1; 
//		}
//	}
//	
//	//
//// Read the encoder position.
//	

////
//	QEIPositionGet(QEI0_BASE);
//	QEIDirectionGet(QEI0_BASE);
//	
//	
////Read encoder speed
//	double speed = QEIVelocityGet(QEI0_BASE);
//	
//	printf("Speed = %d\n\n", speed);
//		
//	int ticks = QEIVelocityGet(QEI0_BASE);
//		
//		printf("Speed = %d\n\n", ticks);
//	
//	}
//	

	}


	