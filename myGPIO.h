#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "hw_memmap.h"
#include "hw_gpio.h"
#include "hw_types.h"
#include "../inc/tm4c123gh6pm.h"
#include "pin_map.h"
#include "gpio.h"
#include "sysctl.h"
#include "driverlib/uart.h"

void setup_IO();
void pinReadAndWrite(uint32_t ui32Loop,uint8_t temp);