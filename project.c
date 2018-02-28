/*********************************************************************************************************************************
**
** Module Name:   project.c
**
** Module Description: Main Project C file 

**This program performs two main functions. The first is to calculate the first order transfer function of a motor based on a step
**input. When the Calibrate function is called and executed a step input sent to the motor with via a PWM signal with 100 percent 
**duty cycle. The voltage across the motor is reduced by a voltage divider then read into an ADC channel. The motor speed is read 
**every 10mS and stored in memory until the speed remains constant. Once the speed remains constant the time constant (t) for the 
**transfer function is calculated by finding the time the motor took to reach its steady state speed multiplied by (1-e^-1). The 
**gain (K) value is calculated by dividing its final speed by the input voltage. Once these values are known a first order transfer
**function can be derived in the form k/(ts+1).
**The second function asks the user for a desired speed then through PWM the microcontroller maintains that speed regardless of the 
**load placed on the motor. Every 10mS the encoder reads the motors current speed. The difference between the desired speed and the 
**actual speed is multiplied by a gain and adjusts the PWM signal to compensate for this load. In addition to compensating for the 
**error between current speed and desired speed the controller also adds compensation for small errors over long periods and 
**compensation for rate of change. 

**
**********************************************************************************************************************************
**
** Author(s):		Kodey Boreo, Phillip Tesolin 
**
**********************************************************************************************************************************/



#include "project.h"
#include <stdio.h>
#include <stdint.h>

bool TESTING = 1;  //bool used for debugging and testing features.

#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif

void mainMenu(char ctemp);

void SetupHardware()
{
	setup_IO(); //setup for pins
	UartSetup(); //setup for user input
	FloatSetup(); //setup to allow floating point print 
	setupENCODER();	 //setup to read motor encoder
	setupPWM();	//setup PWM output
	FPUEnable();	//inable floating point
	FPULazyStackingEnable(); //inable lazy stack for floating point
	//SetupADC(); //setup to read motor voltage 
	
}
//**************************************************
#define SLAVE_ADDRESS 0x3C
volatile uint32_t   result = 'V';

void InitConsole(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);

    //SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    //UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);
    //GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    //UARTStdioConfig(0, 115200, 16000000);
}


void I2C1_Slave_Init(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));

    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C1);
    SysCtlPeripheralReset(SYSCTL_PERIPH_I2C1);

    GPIOPinConfigure(GPIO_PA6_I2C1SCL);
    GPIOPinConfigure(GPIO_PA7_I2C1SDA);

    GPIOPinTypeI2CSCL(GPIO_PORTA_BASE, GPIO_PIN_6);
    GPIOPinTypeI2C(GPIO_PORTA_BASE, GPIO_PIN_7);

    I2CSlaveEnable(I2C1_BASE);
    I2CSlaveInit(I2C1_BASE, SLAVE_ADDRESS);
}

void I2C1SlaveIntHandler(void)
{
    // Clear the I2C0 interrupt flag.
    I2CSlaveIntClear(I2C1_BASE);
    // Read the data from the slave.
    result = I2CSlaveDataGet(I2C1_BASE);
}
//*****************************************************


double speed; 	//Speed read from encoder
double uSpeed;	//Requested speed from the user


int  main(void)
{	
	SetupHardware();  //Initializes all of the required HardWare for the project.	
	
	
	//************************************************************************
	
	InitConsole();
    I2C1_Slave_Init();

    //SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    //GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_3);
    //GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);

    IntEnable(INT_I2C1);
    I2CSlaveIntEnableEx(I2C1_BASE, I2C_SLAVE_INT_DATA);
    IntMasterEnable();

    while(1)
    {
        I2CSlaveDataPut(I2C1_BASE, result);
        printf(" Slave receive: '%c' \n", result);
        SysCtlDelay(SysCtlClockGet()/12);

        //while(!(I2CSlaveStatus(I2C1_BASE) & I2C_SLAVE_ACT_TREQ));

        I2CSlaveDataPut(I2C1_BASE, result);
    }

	//*********************************************************************
	
	{
//************************
//Write a function here to get the desired speed	
	
	uSpeed = GetUserSpeed();//set uSpeed equal to the speed you want me to travel

	Speed_Control(speed, uSpeed);
	
	speed = ReadEncoder(); // this will set speed equal to the current speed 
	
	//*************************
	//Write a function here to send "speed" to Levi
	}
}	
	



