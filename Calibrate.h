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



#include "gpio.h"
#include "uart.h"
#include "../inc/tm4c123gh6pm.h"
#include "pin_map.h"

void initialize_aandw(void);