//#include "i2c_doc.h"
//#include <stdarg.h>
//#include <stdbool.h>
//#include <stdint.h>
//#include "inc/hw_i2c.h"
//#include "inc/hw_memmap.h"
//#include "inc/hw_types.h"
//#include "inc/hw_gpio.h"
//#include "driverlib/i2c.h"
//#include "driverlib/sysctl.h"
//#include "driverlib/gpio.h"
//#include "driverlib/pin_map.h"
////
////Enable GPIO for Configuring the I2C Interface Pins
//SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOL);
//SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOK);
////
//// Wait for the Peripheral to be ready for programming
////
//while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOL)
//|| !SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOK));
////
//// Configure Pins for I2C2 Master Interface
////
//GPIOPinConfigure(GPIO_PL1_I2C2SCL);
//GPIOPinConfigure(GPIO_PL0_I2C2SDA);
//GPIOPinTypeI2C(GPIO_PORTL_BASE, GPIO_PIN_0);
//GPIOPinTypeI2CSCL(GPIO_PORTL_BASE, GPIO_PIN_1);
////
//// Configure Pins for I2C3 Slave Interface
////
//GPIOPinConfigure(GPIO_PK4_I2C3SCL);
//GPIOPinConfigure(GPIO_PK5_I2C3SDA);
//GPIOPinTypeI2C(GPIO_PORTK_BASE, GPIO_PIN_5);
//GPIOPinTypeI2CSCL(GPIO_PORTL_BASE, GPIO_PIN_4);
