#include "Uart_helper.h"

//Writing this code involved 3 things 
//1 - Looking at the TIVA driver library documentaion
//2 - Looking at the source code for the uart.c in the driver folder
//3 - Doing some google to debug errors
void UartSetup()
{
		//
		// Enable the UART0 module.
		//
		SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
		//
		// Wait for the UART0 module to be ready.
		//
		while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0))
		{
		}
		
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA); // activate port A
		
		// enable alt funct on PA1-0 and enable digital I/O on PA1-0
		GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_2|GPIO_PIN_1);
		
		// Initialize the UART. Set the baud rate, number of data bits, turn off
		// parity, number of stop bits, and stick mode. The UART is enabled by the
		//
		UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 38400,(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |UART_CONFIG_PAR_NONE));
		//
		// Check for characters. Spin here until a character is placed
}