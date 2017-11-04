#include <stdio.h>
#include <stdint.h>
#include "Get_Speed.h"

double GetUserSpeed(void)
{
	volatile double userSpeed;	//variable for the user requested speed
	
	printf("Please type the speed you would like: \n"); //Ask to enter the speed they would like.
	//scanf("%la", &userSpeed);	//scans the whole line (alternative way)
	scanf("%lf", &userSpeed);	//scans the whole line
	printf("You entered %.3f\n\n",userSpeed); //Lets the user know what they have selected, using a precision of three places after the decimal. 
	return userSpeed;		//Returns "userSpeed"
}