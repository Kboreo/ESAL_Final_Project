/*********************************************************************************************************************************
**
** Module Name:   HAL_ADC.h
**
** Module Description: Sets up all of the hardware that is used in ADC
**
**********************************************************************************************************************************
**
** Author(s):		Kodey Boreo, Phillip Tesolin 
**
**********************************************************************************************************************************/

//Includes
#include "HAL_ADC.h"

//Variables
uint32_t ADC_Values[13];
double ADCVALUE;	

//Function Prototypes
void SetupADCPins(void);

//set up for 2 pots and accelerometer + 1 extra
void SetupADCPins()
{
		//Need to Unlock PD7
	HWREG(GPIO_PORTE_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
	HWREG(GPIO_PORTE_BASE + GPIO_O_CR) = 0xFF;
  HWREG(GPIO_PORTE_BASE + GPIO_O_LOCK) = 0;
	GPIOPinTypeADC(GPIO_PORTE_BASE,GPIO_PIN_3|GPIO_PIN_1|GPIO_PIN_2);
	//GPIOPinTypeADC(GPIO_PORTD_BASE,GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
	//GPIOPinTypeADC(GPIO_PORTE_BASE,GPIO_PIN_2);
	
}

//Function that sets the HW up for the ADC module
void SetupADC()
{	
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE))
	{
	}
	
	//
	// Enable the ADC0 module.
	//
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
	//
	// Wait for the ADC0 module to be ready.
	//
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0))
	{
	}
	
	ADCReferenceSet(ADC0_BASE, ADC_REF_EXT_3V);
	//
	// Enable the first sample sequencer to capture the value of channel 0 when
	// the processor trigger occurs.
	//
	ADCSequenceDisable(ADC0_BASE,0);
	ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0);
	ADCSequenceStepConfigure(ADC0_BASE, 0, 0, ADC_CTL_CH0 );
  ADCSequenceStepConfigure(ADC0_BASE, 0, 1, ADC_CTL_CH1 );	
  ADCSequenceStepConfigure(ADC0_BASE, 0, 2, ADC_CTL_CH2 );	
	ADCSequenceStepConfigure(ADC0_BASE, 0, 3, ADC_CTL_CH4 );	
	ADCSequenceStepConfigure(ADC0_BASE, 0, 4, ADC_CTL_CH5 );	
	ADCSequenceStepConfigure(ADC0_BASE, 0, 5, ADC_CTL_CH6 );	
	ADCSequenceStepConfigure(ADC0_BASE, 0, 6, ADC_CTL_CH7 | ADC_CTL_END);	
	ADCSequenceEnable(ADC0_BASE, 0);
	SetupADCPins(); //setup the GPIO		
}

//Function to read the ADC value from the Channel
double ADCReadChan()
{	
//	SysTickWait10msDN(10); //Delay Function
	//printf("\n");
	int32_t scratch;
	//
	// Trigger the sample sequence.
	//
	ADCProcessorTrigger(ADC0_BASE, 0);
	//
	// Wait until the sample sequence has completed.
	//
	while(ADCBusy(ADC0_BASE)){};
	//while(!ADCIntStatus(ADC0_BASE, 0, false))
	{
	}
	//
	// Read the value from the ADC.
	//	
	scratch = (ADCSequenceDataGet(ADC0_BASE, 0, ADC_Values));
	if (scratch < 13)
	{
		ADC_Values[12]=scratch;
	}
		 
	
	ADCVALUE = ADC_Values[0];		
	//x = x * .000807;  //Multiple the x value with the "offset" to get it to the correct value		voltage div k21.2 ohm and 79 kohm
	ADCVALUE = ADCVALUE * .0037415;  //Multiple the x value with the "offset" to get it to the correct value		voltage div k21.2 ohm and 79 kohm
	//printf("Voltage on PE3 is, %.2fV \n\n", x);  //Displays voltage to the End user	
	return ADCVALUE;
}



