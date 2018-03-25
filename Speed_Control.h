/*********************************************************************************************************************************
**
** Module Name:   Speed_Control.h
**
** Module Description: Controls the speed of the motor based on user input in Get_Speed.c 
**
**********************************************************************************************************************************
**
** Author(s):		Kodey Boreo, Phillip Tesolin 
**
**********************************************************************************************************************************/


#include "driverlib/pin_map.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/pwm.h"
#include "driverlib/uart.h"
#include "driverlib/qei.h"
#include <stdint.h>
#include <stdbool.h>
#include "driverlib/fpu.h"
#include "sysctl.h"
#include "hw_memmap.h"
#include "tm4c123gh6pm.h"
#include "hw_types.h"
#include "Uart_helper.h"
#include "Read_Encoder.h"

void Speed_Control(double Speed, int uSpeed);