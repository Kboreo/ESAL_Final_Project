#include "i2c_master.h"

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_i2c.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/i2c.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/uart.h"
//#include "utils/uartstdio.h"
//#include "utils/uartstdio.c"

#define SLAVE_ADDRESS 0x3C
volatile uint32_t   read;
volatile uint32_t receive;

double dspeed;

void I2C0MasterIntHandler(void)
{
    // Clear the I2C0 interrupt flag.
    I2CMasterIntClear(I2C0_BASE);
    // Read the data from the slave.
    receive = I2CMasterDataGet(I2C0_BASE);
}

void InitConsole(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
  //  UARTStdioConfig(0, 115200, 16000000);
}

void I2C0_Master_Init(void)
{
    //enable GPIO peripheral that contains I2C 0
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB));

    //enable I2C module 0
    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);
    //reset module
    SysCtlPeripheralReset(SYSCTL_PERIPH_I2C0);

    // Configure the pin muxing for I2C0 functions on port B2 and B3.
    GPIOPinConfigure(GPIO_PB2_I2C0SCL);
    GPIOPinConfigure(GPIO_PB3_I2C0SDA);

    // Select the I2C function for these pins.
    GPIOPinTypeI2CSCL(GPIO_PORTB_BASE, GPIO_PIN_2);
    GPIOPinTypeI2C(GPIO_PORTB_BASE, GPIO_PIN_3);

    // Enable and initialize the I2C0 master module.  Use the system clock for
    // the I2C0 module.  The last parameter sets the I2C data transfer rate.
    // If false the data rate is set to 100kbps and if true the data rate will
    // be set to 400kbps.
    I2CMasterInitExpClk(I2C0_BASE, SysCtlClockGet(), false);

    //clear I2C FIFOs
    // HWREG(I2C0_BASE + I2C_O_FIFOCTL) = 80008000;

}

int i2c_send(void)
{
    //SysCtlClockSet(SYSCTL_SYSDIV_1| SYSCTL_USE_OSC| SYSCTL_OSC_MAIN| SYSCTL_XTAL_16MHZ);

			InitConsole();
			I2C0_Master_Init();
	

//    IntEnable(INT_I2C0);
//    I2CMasterIntEnableEx(I2C0_BASE, I2C_MASTER_INT_DATA);
//    IntMasterEnable();

   // printf("Master --> Slave \n");

//    while(1)
//    {
			//***************************
			//
// Enable the I2C0 peripheral
//
SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);
//
// Wait for the I2C0 module to be ready.
//
while(!SysCtlPeripheralReady(SYSCTL_PERIPH_I2C0))
{
}
//
// Initialize Master and Slave
//
I2CMasterInitExpClk(I2C0_BASE, SysCtlClockGet(), true);
//
// Specify slave address
//
I2CMasterSlaveAddrSet(I2C0_BASE, 0x3c, false);
//
// Place the character to be sent in the data register
//
I2CMasterDataPut(I2C0_BASE, 81);
//
// Initiate send of character from Master to Slave
//
I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_SINGLE_SEND);
//
// Delay until transmission completes
//
while(I2CMasterBusBusy(I2C0_BASE))
{
}
			//**********************
//        I2CMasterSlaveAddrSet(I2C0_BASE, SLAVE_ADDRESS, true);
//        I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_SINGLE_RECEIVE);
//        while(I2CMasterBusy(I2C0_BASE));

//        printf("Received: %d \n", receive);
//        printf("received: '%c' \n", receive);

//        SysCtlDelay(SysCtlClockGet()/6);
return 0;
    }
//}
		
		
		//read specified register on slave device
int I2CReceive(void)
{
	
	InitConsole();
	I2C0_Master_Init();

	
	I2C0MasterIntHandler();

   //specify that we want to communicate to device address with an intended write to bus
   I2CMasterSlaveAddrSet(I2C0_BASE, 0x3c, true);

   //the register to be read
   I2CMasterDataPut(I2C0_BASE, 0xfb);

   //send control byte and register address byte to slave device
   I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_SINGLE_SEND);

   //wait for MCU to complete send transaction
   while(I2CMasterBusy(I2C0_BASE));

   //read from the specified slave device
   I2CMasterSlaveAddrSet(I2C0_BASE, 0x3c, true);

   //send control byte and read from the register from the MCU
   I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_SINGLE_RECEIVE);

   //wait while checking for MCU to complete the transaction
   while(I2CMasterBusy(I2C0_BASE));

   //Get the data from the MCU register and return to caller
   return( I2CMasterDataGet(I2C0_BASE));
	 
	 double dspeed 
	 
 }

		
		

		