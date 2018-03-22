//#include "i2c_slave.h"

//#include <stdint.h>
//#include <stdbool.h>
//#include "inc/hw_ints.h"
//#include "inc/hw_i2c.h"
//#include "inc/hw_memmap.h"
//#include "inc/hw_types.h"
//#include "inc/hw_gpio.h"
//#include "driverlib/interrupt.h"
//#include "driverlib/i2c.h"
//#include "driverlib/sysctl.h"
//#include "driverlib/gpio.h"
//#include "driverlib/pin_map.h"
//#include "driverlib/uart.h"
////#include "utils/uartstdio.h"
////#include "utils/uartstdio.c"

//#define SLAVE_ADDRESS 0x3C
//volatile uint32_t   result = 'V';

//void InitConsole(void)
//{
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

//    GPIOPinConfigure(GPIO_PA0_U0RX);
//    GPIOPinConfigure(GPIO_PA1_U0TX);

//    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
//    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);
//    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
//    UARTStdioConfig(0, 115200, 16000000);
//}


//void I2C1_Slave_Init(void)
//{
//    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
//    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));

//    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C1);
//    SysCtlPeripheralReset(SYSCTL_PERIPH_I2C1);

//    GPIOPinConfigure(GPIO_PA6_I2C1SCL);
//    GPIOPinConfigure(GPIO_PA7_I2C1SDA);

//    GPIOPinTypeI2CSCL(GPIO_PORTA_BASE, GPIO_PIN_6);
//    GPIOPinTypeI2C(GPIO_PORTA_BASE, GPIO_PIN_7);

//    I2CSlaveEnable(I2C1_BASE);
//    I2CSlaveInit(I2C1_BASE, SLAVE_ADDRESS);
//}

//void I2C1SlaveIntHandler(void)
//{
//    // Clear the I2C0 interrupt flag.
//    I2CSlaveIntClear(I2C1_BASE);
//    // Read the data from the slave.
//    result = I2CSlaveDataGet(I2C1_BASE);
//}

//int main(void)
//{
//    SysCtlClockSet(SYSCTL_SYSDIV_1| SYSCTL_USE_OSC| SYSCTL_OSC_MAIN| SYSCTL_XTAL_16MHZ);

//    InitConsole();
//    I2C1_Slave_Init();

//    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
//    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
//    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);

//    IntEnable(INT_I2C1);
//    I2CSlaveIntEnableEx(I2C1_BASE, I2C_SLAVE_INT_DATA);
//    IntMasterEnable();

//    while(1)
//    {
//        //I2CSlaveDataPut(I2C1_BASE, result);
//        UARTprintf(" Slave receive: '%c' \n", result);
//        SysCtlDelay(SysCtlClockGet()/12);

//        //while(!(I2CSlaveStatus(I2C1_BASE) & I2C_SLAVE_ACT_TREQ));

//        I2CSlaveDataPut(I2C1_BASE, result);
//    }
//}