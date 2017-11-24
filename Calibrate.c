#include "Read_Encoder.h"
#include "Encoder.h"
#include "project.h"
#include "tm4c123gh6pm.h"	//Header file accesses registers in TMC123 microcontroller
#include "Speed_Control.h"
#include "Calibrate.h"
#include "myPWM.h"

#include <stdio.h>
#include <stdint.h>


#include "tm4c123gh6pm.h"	

	char ct;
	int i = 0;
	//int t = 1;
	int A = 1;
	double calspeed, tempspeed, voltage;
	double calspeed0, calspeed1,calspeed2,calspeed3,calspeed4,calspeed5,calspeed6,calspeed7,calspeed8,calspeed9,calspeed10,calspeed11,calspeed12,calspeed13,calspeed14,calspeed15, calspeed16;
	double calspeed17,calspeed18,calspeed19,calspeed20,calspeed21,calspeed22,calspeed23,calspeed24,calspeed25;
	double k, t, AvK;
	
	float aandw[36];
	
void initialize_aandw()
{
	int i;
	for (i = 0; i< 36;i++)
	{
		aandw[i] = i* 3.141719;
	}
}

void Calibrate (void)
{
	
	
	//PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, 0);
		stopmotor();
		
		
		printf("Press any key to calibrate\n motor will turn on "); //lets the user know to get ready
		ct = getc(stdin); //Gets a char from the terminal from the user.
		printf("You entered %c\n\n",ct); //Lets the user know what they have selected
		
	

		
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, 320);
	
	calspeed0 = ReadEncoder();
	tempspeed = calspeed0;
	
	while(tempspeed <= calspeed0){
	tempspeed = ReadEncoder();
	}
	calspeed1 = tempspeed;
	
	while(tempspeed <= calspeed1){
	tempspeed = ReadEncoder();
	}
	calspeed2 = tempspeed;
	
	while(tempspeed <= calspeed2){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999){
			break;
		}
	}
	i=0;	
	calspeed3 = tempspeed;
	
	while(tempspeed <= calspeed3){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999){
			break;
		}
	}
	i=0;	
	calspeed4 = tempspeed;
	
	while(tempspeed <= calspeed4){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999){
			break;
		}
	}	
	i=0;
	calspeed5 = tempspeed;
	
	while(tempspeed <= calspeed5){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999){
			break;
		}
	}
	i=0;	
	calspeed6 = tempspeed;
	
	while(tempspeed <= calspeed6){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999){
			break;
		}
	}
	i=0;	
	calspeed7 = tempspeed;
	
	while(tempspeed <= calspeed7){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999){
			break;
		}
	}	
	i=0;
	calspeed8 = tempspeed;
	
	while(tempspeed <= calspeed8){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999)
		{
			break;
		}
	}	
	i=0;
		calspeed9 = tempspeed;
	
	while(tempspeed <= calspeed9){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999){
			break;
		}
	}
	i=0;	
	calspeed10 = tempspeed;
	
	while(tempspeed <= calspeed10){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999){
			break;
		}
	}
	i=0;	
	calspeed11 = tempspeed;
	
	while(tempspeed <= calspeed11){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999){
			break;
		}
	}	
	i=0;
	calspeed12 = tempspeed;
	
	while(tempspeed <= calspeed12){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999){
			break;
		}
	}
	i=0;	
	calspeed13 = tempspeed;
	
	while(tempspeed <= calspeed13){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999){
			break;
		}
	}
	i=0;	
	calspeed14 = tempspeed;
	
	while(tempspeed <= calspeed14){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999){
			break;
		}
	}	
	i=0;
	calspeed15 = tempspeed;
	
	while(tempspeed <= calspeed15){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999)
		{
			break;
		}
	}	
	i=0;
	calspeed16 = tempspeed;
	
	while(tempspeed <= calspeed16){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999){
			break;
		}
	}
	i=0;	
	calspeed17 = tempspeed;
	
	while(tempspeed <= calspeed17){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999){
			break;
		}
	}
	i=0;	
	calspeed18 = tempspeed;
	
	while(tempspeed <= calspeed18){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999){
			break;
		}
	}	
	i=0;
	calspeed19 = tempspeed;
	
	while(tempspeed <= calspeed19){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999){
			break;
		}
	}
	i=0;	
	calspeed20 = tempspeed;
	
	while(tempspeed <= calspeed20){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999){
			break;
		}
	}
	i=0;	
	calspeed21 = tempspeed;
	
	while(tempspeed <= calspeed21){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999){
			break;
		}
	}	
	i=0;
	calspeed22 = tempspeed;
	
	while(tempspeed <= calspeed22){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999)
		{
			break;
		}
	}	
		i=0;
	calspeed23 = tempspeed;
	
	while(tempspeed <= calspeed23){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999)
		{
			break;
		}
	}	
		i=0;
	calspeed24 = tempspeed;
	
	while(tempspeed <= calspeed24){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999)
		{
			break;
		}
	}	
		i=0;
	calspeed25 = tempspeed;
	
	while(tempspeed <= calspeed25){
	tempspeed = ReadEncoder();
		i++;
		if (i > 9999)
		{
			break;
		}
	}	
	
	
	printf("Speed 0  = %.2f  ", calspeed0);		
	printf("Speed 1  = %.2f  ", calspeed1);
	printf("Speed 2  = %.2f  ", calspeed2);
	printf("Speed 3  = %.2f\n", calspeed3);
	printf("Speed 4  = %.2f ", calspeed4);
	printf("Speed 5  = %.2f ", calspeed5);
	printf("Speed 6  = %.2f ", calspeed6);
	printf("Speed 7  = %.2f\n", calspeed7);
	printf("Speed 8  = %.2f ", calspeed8);
	printf("Speed 9  = %.2f ", calspeed9);
	printf("Speed 10 = %.2f ", calspeed10);
	printf("Speed 11 = %.2f\n", calspeed11);
	printf("Speed 12 = %.2f ", calspeed12);
	printf("Speed 13 = %.2f ", calspeed13);
	printf("Speed 14 = %.2f ", calspeed14);
	printf("Speed 15 = %.2f\n", calspeed15);
	printf("Speed 16 = %.2f ", calspeed16);
	printf("Speed 17 = %.2f ", calspeed17);
	printf("Speed 18 = %.2f ", calspeed18);
	printf("Speed 19 = %.2f\n", calspeed19);
	printf("Speed 20 = %.2f ", calspeed20);
	printf("Speed 21 = %.2f ", calspeed21);
	printf("Speed 22 = %.2f ", calspeed22);
	printf("Speed 23 = %.2f\n", calspeed20);
	printf("Speed 24 = %.2f ", calspeed21);
	printf("Speed 25 = %.2f\n ", calspeed22);
	
	voltage = ADCReadChan();
	PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, 0);
	
			
k = calspeed25 / voltage;
AvK = calspeed17 * .6321;

if (AvK < calspeed2){
	t = .02;
}
else if (AvK < calspeed3){
	t = .03;
}
else if (AvK < calspeed4){
	t = .04;
}
else if (AvK < calspeed5){
	t = .05;
}
else if (AvK < calspeed6){
	t = .06;
}
else if (AvK < calspeed7){
	t = .07;
}
else if (AvK < calspeed8){
	t = .08;
}
else if (AvK < calspeed9){
	t = .09;
}
else if (AvK < calspeed10){
	t = .10;
}
else if (AvK < calspeed11){
	t = .11;
}
else if (AvK < calspeed12){
	t = .12;
}
else if (AvK < calspeed13){
	t = .13;
}
else if (AvK < calspeed14){
	t = .14;
}
else if (AvK < calspeed15){
	t = .15;
}
else if (AvK < calspeed16){
	t = .16;
}
else if (AvK < calspeed17){
	t = .17;
}
	printf("K = %.2f\n", k);
	printf("Avk = %.2f\n", AvK);
	printf("Time const = %.2f\n", t);
	printf("Voltage = %.2f\n", voltage);
	stopmotor();
}
	
