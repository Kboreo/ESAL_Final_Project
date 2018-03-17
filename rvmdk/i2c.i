#line 1 "i2c.c"
#line 1 "i2c.h"
#line 2 "i2c.c"

#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"
 
 
 





 










#line 27 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"








 

 
 
#line 57 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"
    typedef struct __va_list { void *__ap; } va_list;

   






 


   










 


   















 




   

 


   




 



   





 







#line 138 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"



#line 147 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"

 

#line 4 "i2c.c"
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdbool.h"
 






 





#line 25 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdbool.h"



#line 5 "i2c.c"
#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
 
 





 









     
#line 27 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
     











#line 46 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"





 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     




typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;


     
typedef   signed     long long intmax_t;
typedef unsigned     long long uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     






     






     






     

     


     


     


     

     
#line 216 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     



     






     
    
 



#line 241 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

     







     










     











#line 305 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"






 
#line 6 "i2c.c"
#line 1 "inc/hw_i2c.h"















































#line 55 "inc/hw_i2c.h"
                                            



                                            
#line 70 "inc/hw_i2c.h"
                                            
#line 79 "inc/hw_i2c.h"















#line 111 "inc/hw_i2c.h"







                                            







#line 138 "inc/hw_i2c.h"








                                            

                                            

                                            
#line 159 "inc/hw_i2c.h"







                                            

                                            

                                            

                                            

                                            

                                            

                                            

                                            

                                            


                                            









                                            

                                            
#line 206 "inc/hw_i2c.h"
                                            








                                            

                                            

                                            

                                            




                                            




















































#line 288 "inc/hw_i2c.h"














#line 313 "inc/hw_i2c.h"
















                                            

                                            

                                            












                                            

                                            

                                            

                                            

                                            


                                            

                                            









                                            

                                            

                                            

                                            

                                            

                                            

                                            









                                            
#line 399 "inc/hw_i2c.h"































#line 440 "inc/hw_i2c.h"







#line 455 "inc/hw_i2c.h"















#line 7 "i2c.c"
#line 1 "inc/hw_memmap.h"
















































#line 116 "inc/hw_memmap.h"
                                            

                                            

                                            
#line 141 "inc/hw_memmap.h"
                                            

                                            
#line 150 "inc/hw_memmap.h"

#line 8 "i2c.c"
#line 1 "inc/hw_types.h"















































#line 63 "inc/hw_types.h"




















































































#line 9 "i2c.c"
#line 1 "inc/hw_gpio.h"















































#line 79 "inc/hw_gpio.h"







                                            









                                            









                                            



















                                            

                                            
















                                            
                                            
                                            
                                            
                                            



































#line 194 "inc/hw_gpio.h"
                                            
                                            
                                            

                                            

                                            
                                            
                                            
                                            
                                            
#line 212 "inc/hw_gpio.h"

#line 10 "i2c.c"
#line 1 "driverlib/i2c.h"








































































#line 119 "driverlib/i2c.h"






#line 141 "driverlib/i2c.h"

















#line 165 "driverlib/i2c.h"













#line 197 "driverlib/i2c.h"






#line 218 "driverlib/i2c.h"
















#line 264 "driverlib/i2c.h"






#line 278 "driverlib/i2c.h"






extern void I2CIntRegister(uint32_t ui32Base, void(*pfnHandler)(void));
extern void I2CIntUnregister(uint32_t ui32Base);
extern void I2CTxFIFOConfigSet(uint32_t ui32Base, uint32_t ui32Config);
extern void I2CTxFIFOFlush(uint32_t ui32Base);
extern void I2CRxFIFOConfigSet(uint32_t ui32Base, uint32_t ui32Config);
extern void I2CRxFIFOFlush(uint32_t ui32Base);
extern uint32_t I2CFIFOStatus(uint32_t ui32Base);
extern void I2CFIFODataPut(uint32_t ui32Base, uint8_t ui8Data);
extern uint32_t I2CFIFODataPutNonBlocking(uint32_t ui32Base,
                                          uint8_t ui8Data);
extern uint32_t I2CFIFODataGet(uint32_t ui32Base);
extern uint32_t I2CFIFODataGetNonBlocking(uint32_t ui32Base,
                                          uint8_t *pui8Data);
extern void I2CMasterBurstLengthSet(uint32_t ui32Base,
                                    uint8_t ui8Length);
extern uint32_t I2CMasterBurstCountGet(uint32_t ui32Base);
extern void I2CMasterGlitchFilterConfigSet(uint32_t ui32Base,
                                           uint32_t ui32Config);
extern void I2CSlaveFIFOEnable(uint32_t ui32Base, uint32_t ui32Config);
extern void I2CSlaveFIFODisable(uint32_t ui32Base);
extern _Bool I2CMasterBusBusy(uint32_t ui32Base);
extern _Bool I2CMasterBusy(uint32_t ui32Base);
extern void I2CMasterControl(uint32_t ui32Base, uint32_t ui32Cmd);
extern uint32_t I2CMasterDataGet(uint32_t ui32Base);
extern void I2CMasterDataPut(uint32_t ui32Base, uint8_t ui8Data);
extern void I2CMasterDisable(uint32_t ui32Base);
extern void I2CMasterEnable(uint32_t ui32Base);
extern uint32_t I2CMasterErr(uint32_t ui32Base);
extern void I2CMasterInitExpClk(uint32_t ui32Base, uint32_t ui32I2CClk,
                                _Bool bFast);
extern void I2CMasterIntClear(uint32_t ui32Base);
extern void I2CMasterIntDisable(uint32_t ui32Base);
extern void I2CMasterIntEnable(uint32_t ui32Base);
extern _Bool I2CMasterIntStatus(uint32_t ui32Base, _Bool bMasked);
extern void I2CMasterIntEnableEx(uint32_t ui32Base,
                                 uint32_t ui32IntFlags);
extern void I2CMasterIntDisableEx(uint32_t ui32Base,
                                  uint32_t ui32IntFlags);
extern uint32_t I2CMasterIntStatusEx(uint32_t ui32Base,
                                       _Bool bMasked);
extern void I2CMasterIntClearEx(uint32_t ui32Base,
                                uint32_t ui32IntFlags);
extern void I2CMasterTimeoutSet(uint32_t ui32Base, uint32_t ui32Value);
extern void I2CSlaveACKOverride(uint32_t ui32Base, _Bool bEnable);
extern void I2CSlaveACKValueSet(uint32_t ui32Base, _Bool bACK);
extern uint32_t I2CMasterLineStateGet(uint32_t ui32Base);
extern void I2CMasterSlaveAddrSet(uint32_t ui32Base,
                                  uint8_t ui8SlaveAddr,
                                  _Bool bReceive);
extern uint32_t I2CSlaveDataGet(uint32_t ui32Base);
extern void I2CSlaveDataPut(uint32_t ui32Base, uint8_t ui8Data);
extern void I2CSlaveDisable(uint32_t ui32Base);
extern void I2CSlaveEnable(uint32_t ui32Base);
extern void I2CSlaveInit(uint32_t ui32Base, uint8_t ui8SlaveAddr);
extern void I2CSlaveAddressSet(uint32_t ui32Base, uint8_t ui8AddrNum,
                                 uint8_t ui8SlaveAddr);
extern void I2CSlaveIntClear(uint32_t ui32Base);
extern void I2CSlaveIntDisable(uint32_t ui32Base);
extern void I2CSlaveIntEnable(uint32_t ui32Base);
extern void I2CSlaveIntClearEx(uint32_t ui32Base, uint32_t ui32IntFlags);
extern void I2CSlaveIntDisableEx(uint32_t ui32Base,
                                 uint32_t ui32IntFlags);
extern void I2CSlaveIntEnableEx(uint32_t ui32Base, uint32_t ui32IntFlags);
extern _Bool I2CSlaveIntStatus(uint32_t ui32Base, _Bool bMasked);
extern uint32_t I2CSlaveIntStatusEx(uint32_t ui32Base,
                                      _Bool bMasked);
extern uint32_t I2CSlaveStatus(uint32_t ui32Base);
extern void I2CLoopbackEnable(uint32_t ui32Base);










#line 11 "i2c.c"
#line 1 "driverlib/sysctl.h"






























































#line 140 "driverlib/sysctl.h"








#line 155 "driverlib/sysctl.h"








#line 171 "driverlib/sysctl.h"







#line 185 "driverlib/sysctl.h"
                                            





















#line 214 "driverlib/sysctl.h"







#line 385 "driverlib/sysctl.h"







#line 462 "driverlib/sysctl.h"

















#line 486 "driverlib/sysctl.h"








                                            

                                            











#line 516 "driverlib/sysctl.h"






#line 535 "driverlib/sysctl.h"















#line 556 "driverlib/sysctl.h"


























extern uint32_t SysCtlSRAMSizeGet(void);
extern uint32_t SysCtlFlashSizeGet(void);
extern uint32_t SysCtlFlashSectorSizeGet(void);
extern _Bool SysCtlPeripheralPresent(uint32_t ui32Peripheral);
extern _Bool SysCtlPeripheralReady(uint32_t ui32Peripheral);
extern void SysCtlPeripheralPowerOn(uint32_t ui32Peripheral);
extern void SysCtlPeripheralPowerOff(uint32_t ui32Peripheral);
extern void SysCtlPeripheralReset(uint32_t ui32Peripheral);
extern void SysCtlPeripheralEnable(uint32_t ui32Peripheral);
extern void SysCtlPeripheralDisable(uint32_t ui32Peripheral);
extern void SysCtlPeripheralSleepEnable(uint32_t ui32Peripheral);
extern void SysCtlPeripheralSleepDisable(uint32_t ui32Peripheral);
extern void SysCtlPeripheralDeepSleepEnable(uint32_t ui32Peripheral);
extern void SysCtlPeripheralDeepSleepDisable(uint32_t ui32Peripheral);
extern void SysCtlPeripheralClockGating(_Bool bEnable);
extern void SysCtlIntRegister(void (*pfnHandler)(void));
extern void SysCtlIntUnregister(void);
extern void SysCtlIntEnable(uint32_t ui32Ints);
extern void SysCtlIntDisable(uint32_t ui32Ints);
extern void SysCtlIntClear(uint32_t ui32Ints);
extern uint32_t SysCtlIntStatus(_Bool bMasked);
extern void SysCtlLDOSleepSet(uint32_t ui32Voltage);
extern uint32_t SysCtlLDOSleepGet(void);
extern void SysCtlLDODeepSleepSet(uint32_t ui32Voltage);
extern uint32_t SysCtlLDODeepSleepGet(void);
extern void SysCtlSleepPowerSet(uint32_t ui32Config);
extern void SysCtlDeepSleepPowerSet(uint32_t ui32Config);
extern void SysCtlReset(void);
extern void SysCtlSleep(void);
extern void SysCtlDeepSleep(void);
extern uint32_t SysCtlResetCauseGet(void);
extern void SysCtlResetCauseClear(uint32_t ui32Causes);
extern void SysCtlBrownOutConfigSet(uint32_t ui32Config,
                                    uint32_t ui32Delay);
extern void SysCtlDelay(uint32_t ui32Count);
extern void SysCtlMOSCConfigSet(uint32_t ui32Config);
extern uint32_t SysCtlPIOSCCalibrate(uint32_t ui32Type);
extern void SysCtlClockSet(uint32_t ui32Config);
extern uint32_t SysCtlClockGet(void);
extern void SysCtlDeepSleepClockSet(uint32_t ui32Config);
extern void SysCtlDeepSleepClockConfigSet(uint32_t ui32Div,
                                          uint32_t ui32Config);
extern void SysCtlPWMClockSet(uint32_t ui32Config);
extern uint32_t SysCtlPWMClockGet(void);
extern void SysCtlIOSCVerificationSet(_Bool bEnable);
extern void SysCtlMOSCVerificationSet(_Bool bEnable);
extern void SysCtlPLLVerificationSet(_Bool bEnable);
extern void SysCtlClkVerificationClear(void);
extern void SysCtlGPIOAHBEnable(uint32_t ui32GPIOPeripheral);
extern void SysCtlGPIOAHBDisable(uint32_t ui32GPIOPeripheral);
extern void SysCtlUSBPLLEnable(void);
extern void SysCtlUSBPLLDisable(void);
extern uint32_t SysCtlClockFreqSet(uint32_t ui32Config,
                                   uint32_t ui32SysClock);
extern void SysCtlResetBehaviorSet(uint32_t ui32Behavior);
extern uint32_t SysCtlResetBehaviorGet(void);
extern void SysCtlClockOutConfig(uint32_t ui32Config, uint32_t ui32Div);
extern void SysCtlAltClkConfig(uint32_t ui32Config);
extern uint32_t SysCtlNMIStatus(void);
extern void SysCtlNMIClear(uint32_t ui32Status);
extern void SysCtlVoltageEventConfig(uint32_t ui32Config);
extern uint32_t SysCtlVoltageEventStatus(void);
extern void SysCtlVoltageEventClear(uint32_t ui32Status);
extern _Bool SysCtlVCOGet(uint32_t ui32Crystal, uint32_t *pui32VCOFrequency);










#line 12 "i2c.c"
#line 1 "driverlib/gpio.h"



























































#line 68 "driverlib/gpio.h"

















#line 91 "driverlib/gpio.h"







#line 105 "driverlib/gpio.h"







#line 119 "driverlib/gpio.h"







#line 135 "driverlib/gpio.h"






extern void GPIODirModeSet(uint32_t ui32Port, uint8_t ui8Pins,
                           uint32_t ui32PinIO);
extern uint32_t GPIODirModeGet(uint32_t ui32Port, uint8_t ui8Pin);
extern void GPIOIntTypeSet(uint32_t ui32Port, uint8_t ui8Pins,
                           uint32_t ui32IntType);
extern uint32_t GPIOIntTypeGet(uint32_t ui32Port, uint8_t ui8Pin);
extern void GPIOPadConfigSet(uint32_t ui32Port, uint8_t ui8Pins,
                             uint32_t ui32Strength, uint32_t ui32PadType);
extern void GPIOPadConfigGet(uint32_t ui32Port, uint8_t ui8Pin,
                             uint32_t *pui32Strength, uint32_t *pui32PadType);
extern void GPIOIntEnable(uint32_t ui32Port, uint32_t ui32IntFlags);
extern void GPIOIntDisable(uint32_t ui32Port, uint32_t ui32IntFlags);
extern uint32_t GPIOIntStatus(uint32_t ui32Port, _Bool bMasked);
extern void GPIOIntClear(uint32_t ui32Port, uint32_t ui32IntFlags);
extern void GPIOIntRegister(uint32_t ui32Port, void (*pfnIntHandler)(void));
extern void GPIOIntUnregister(uint32_t ui32Port);
extern void GPIOIntRegisterPin(uint32_t ui32Port, uint32_t ui32Pin,
                               void (*pfnIntHandler)(void));
extern void GPIOIntUnregisterPin(uint32_t ui32Port, uint32_t ui32Pin);
extern int32_t GPIOPinRead(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinWrite(uint32_t ui32Port, uint8_t ui8Pins, uint8_t ui8Val);
extern void GPIOPinConfigure(uint32_t ui32PinConfig);
extern void GPIOPinTypeADC(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeCAN(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeComparator(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeComparatorOutput(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeDIVSCLK(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeEPI(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeEthernetLED(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeEthernetMII(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeGPIOInput(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeGPIOOutput(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeGPIOOutputOD(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeHibernateRTCCLK(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeI2C(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeI2CSCL(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeLCD(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeOneWire(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypePWM(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeQEI(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeSSI(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeTimer(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeTrace(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeUART(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeUSBAnalog(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeUSBDigital(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeWakeHigh(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOPinTypeWakeLow(uint32_t ui32Port, uint8_t ui8Pins);
extern uint32_t GPIOPinWakeStatus(uint32_t ui32Port);
extern void GPIODMATriggerEnable(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIODMATriggerDisable(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOADCTriggerEnable(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIOADCTriggerDisable(uint32_t ui32Port, uint8_t ui8Pins);










#line 13 "i2c.c"
#line 1 "driverlib/pin_map.h"















































#line 213 "driverlib/pin_map.h"






#line 384 "driverlib/pin_map.h"






#line 555 "driverlib/pin_map.h"






#line 726 "driverlib/pin_map.h"






#line 875 "driverlib/pin_map.h"






#line 1024 "driverlib/pin_map.h"






#line 1250 "driverlib/pin_map.h"






#line 1399 "driverlib/pin_map.h"






#line 1625 "driverlib/pin_map.h"






#line 1774 "driverlib/pin_map.h"






#line 2000 "driverlib/pin_map.h"






#line 2171 "driverlib/pin_map.h"






#line 2342 "driverlib/pin_map.h"






#line 2513 "driverlib/pin_map.h"






#line 2684 "driverlib/pin_map.h"






#line 2833 "driverlib/pin_map.h"






#line 2982 "driverlib/pin_map.h"






#line 3208 "driverlib/pin_map.h"






#line 3357 "driverlib/pin_map.h"






#line 3583 "driverlib/pin_map.h"






#line 3732 "driverlib/pin_map.h"






#line 3958 "driverlib/pin_map.h"






#line 4136 "driverlib/pin_map.h"






#line 4314 "driverlib/pin_map.h"






#line 4492 "driverlib/pin_map.h"






#line 4646 "driverlib/pin_map.h"






#line 4880 "driverlib/pin_map.h"






#line 5034 "driverlib/pin_map.h"






#line 5268 "driverlib/pin_map.h"






#line 5422 "driverlib/pin_map.h"






#line 5656 "driverlib/pin_map.h"






#line 5880 "driverlib/pin_map.h"






#line 6104 "driverlib/pin_map.h"






#line 6288 "driverlib/pin_map.h"






#line 6593 "driverlib/pin_map.h"






#line 6777 "driverlib/pin_map.h"






#line 7082 "driverlib/pin_map.h"






#line 7313 "driverlib/pin_map.h"






#line 7544 "driverlib/pin_map.h"






#line 7733 "driverlib/pin_map.h"






#line 8046 "driverlib/pin_map.h"









































































#line 8125 "driverlib/pin_map.h"

#line 8132 "driverlib/pin_map.h"










#line 8148 "driverlib/pin_map.h"

#line 8155 "driverlib/pin_map.h"













































#line 8208 "driverlib/pin_map.h"

#line 8216 "driverlib/pin_map.h"

























#line 8548 "driverlib/pin_map.h"






#line 8857 "driverlib/pin_map.h"






#line 9166 "driverlib/pin_map.h"






#line 9483 "driverlib/pin_map.h"






#line 9886 "driverlib/pin_map.h"






#line 10338 "driverlib/pin_map.h"






#line 10749 "driverlib/pin_map.h"






#line 11209 "driverlib/pin_map.h"






#line 11669 "driverlib/pin_map.h"






#line 12041 "driverlib/pin_map.h"






#line 12536 "driverlib/pin_map.h"






#line 12930 "driverlib/pin_map.h"






#line 13455 "driverlib/pin_map.h"






#line 13811 "driverlib/pin_map.h"






#line 14167 "driverlib/pin_map.h"






#line 14671 "driverlib/pin_map.h"






#line 15197 "driverlib/pin_map.h"






#line 15732 "driverlib/pin_map.h"






#line 16267 "driverlib/pin_map.h"






#line 16639 "driverlib/pin_map.h"






#line 17134 "driverlib/pin_map.h"






#line 17528 "driverlib/pin_map.h"






#line 18053 "driverlib/pin_map.h"






#line 18409 "driverlib/pin_map.h"






#line 18765 "driverlib/pin_map.h"






#line 19269 "driverlib/pin_map.h"






#line 19804 "driverlib/pin_map.h"






#line 20378 "driverlib/pin_map.h"






#line 20952 "driverlib/pin_map.h"

#line 14 "i2c.c"



void InitI2C0(void)
{
	
SysCtlPeripheralEnable(0xf0002002);

SysCtlPeripheralEnable(0xf0000804);


SysCtlDelay(2);


GPIOPinConfigure(0x00041003);

GPIOPinConfigure(0x00041403);


SysCtlDelay(2);


GPIOPinTypeI2CSCL(0x40024000, 0x00000010);


GPIOPinTypeI2C(0x40024000, 0x00000020);


I2CMasterInitExpClk(0x40022000, SysCtlClockGet(), 0);
}






















































































































