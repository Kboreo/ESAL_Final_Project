#include <stdio.h>
#include <stdint.h>
#include "Get_Speed.h"





double GetUserSpeed(void)
{
	double userSpeed;
	uint8_t ctemp;
	
	printf("Please type the speed you would like: \n");
	ctemp = getc(stdin); //Gets a char from the terminal from the user.
	printf("You entered %c\n\n",ctemp); //Lets the user know what they have selected
	//scanf("%lf", &userSpeed);
	//printf("You entered %f\n\n",userSpeed); //Lets the user know what they have selected
	
	
	//return userSpeed;
	return ctemp; 
}