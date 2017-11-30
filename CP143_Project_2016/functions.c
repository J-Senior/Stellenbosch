/* Filename:				functions.c
 * Date:					28/09/2016
 * Name:					Senior J.J.
 * Student number:			19842422
 * ----------------------------------------------------------
 * By submitting this file electronically, I declare that it
 * is my own original work, and that I have not copied
 * any part of it from another source, unless instructed
 * to do so in the assignment.
 * ----------------------------------------------------------
 * This file contains the functions required by the CP143
 * project
 * ----------------------------------------------------------
 */

#include <stdlib.h>								//Include standard libraries
#include <stdio.h>                  			//Include standard libraries
#include <math.h>                   			//Include standard libraries
#include <time.h>                   			//Include standard libraries
#include <string.h>                 			//Include standard libraries
#include "CP143_19842422.h"						//Include project library

int minOfDay = 0;								//Declare global variables
int hourOfDay = 0;                              //Declare global variables
int minOfHour = 0;                              //Declare global variables
double totalEnergyIn = 0;						//Declare global variables

int hourofDay[1440] = {0};						//Declare global variables
int minofHour[1440] = {0};                      //Declare global variables
int onOff[1440] = {0};                          //Declare global variables
int volume[1440] = {0};                         //Declare global variables
double consumption[1440] = {0};                 //Declare global variables

void TimeConversion(int minOfDay)																											//Function to convert 'minute of the day' to hh:mm format
{
	hourOfDay = minOfDay / 60;						//Determines hour of day
	minOfHour = minOfDay % 60;						//Determines minute of hour
	
	printf("%02d:%02d", hourOfDay, minOfHour);		//Print minute of day in hh:mm format
}

void runSimulationStep(struct geyserType*geyser, double stepPeriod, double inletTemp, double ambientTemp, double consumption, int heating)	//Function to run a single simulation step of the EWH
{
	double Ein = 0;																															//Declare variables
	double doubleVolume = geyser->volume;                                                                                                   //Convert EWH member int volume to double
	double doubleRating = geyser->elementRating;                                                                                            //Convert EWH member int elementRating to double
	
	double alpha = (stepPeriod / 60) * ((-1 * geyser->surfaceArea * geyser->thermalConductance)/(c * doubleVolume));						//Calculate alpha
	
	if((geyser->internalTemperature < geyser->setTemp) && (heating != 0))																	//Determine whether or not the heating element is receiving electricity
	{
		Ein = doubleRating * (stepPeriod / 60);                                                                                             //If the element is receiving electricity calculate system energy input
	}
	else
	{
		Ein = 0;                                                                                                                            //If the element is not recieving electricity there is no system energy input
	}

	double Euse = c * consumption * (geyser->internalTemperature - inletTemp);                                                              //Calculate energy usage

	double Eloss = c * doubleVolume * (geyser->internalTemperature - ambientTemp) * (1 - exp(alpha));                                       //Calculate energy standing losses

	double Tchange = (Ein - Euse - Eloss) / (c * doubleVolume);                                                                             //Calculate temperature change

	//double Etotal = c * geyser->volume * Tchange;                                                                                         //Calculate total energy of the system

	totalEnergyIn = totalEnergyIn + Ein;                                                                                                    //Calculate total energy input for the current session

	geyser->internalTemperature = geyser->internalTemperature + Tchange;                                                                    //Update the EWH internal temperature
}

void heatingScheduleReader()																												//Function to read a given heating schedule in CSV format
{
	int counter = 0;                                                                                            //Declare variables
	char fileName[64];                                                                                          //Declare array for string reading
	FILE *hsPtr = NULL;                                                                                         //Declare file pointer
	//hsPtr = fopen("HeatingSchedule00.csv", "r");                                                              //Open heating schedule. Used during debugging
	
	setbuf(stdout, 0);                                                                                          //scanf fix
	
	printf("\nEnter heating schedule name:");                                                                   //Print user instructions
	scanf("%s", fileName);                                                                                      //Scan user given filename
	hsPtr = fopen(fileName, "r");                                                                               //Assign pointer to file and open the file for reading

	if ( hsPtr == NULL )                                                                                        //Determine whether the pointer was successfully assigned
	{
		printf("ERROR - Heating schedule file could not be opened!\n");                                         //If the file could not be found, print error notification
		exit(0);                                                                                                //Exit the program
	}

	else                                                                                                        //If the pointer was successfully assigned
	{
		for(counter = 0; counter < 1440 + 1; counter++)                                                         //Increment total possible entries
		{
			if(counter == 0)                                                                                    //Discard first line of file
			{																									//		||
				fscanf(hsPtr, "%*[^\n]\n", NULL);                                                               //		||
			}
			else
			{
				fscanf(hsPtr, "%d:%d,%d", &hourofDay[counter-1], &minofHour[counter-1], &onOff[counter-1]);		//Scan the hour, minute and on/off state into appropriate array
			}
		}
		fclose(hsPtr);                                                                                          //Close the file
	}
	
}

void printHeatingScheduleCSV()																												//Function to print heating schedule during debugging
{
	int loopCounter = 0;                                                                                                        //Declare variables

	printf("\nPrinting heating schedule\n");                                                                                    //Print schedule name

	for(loopCounter = 0; loopCounter < 1440; loopCounter++)                                                                     //Increment total possible entries
	{
		if(((onOff[loopCounter] == 1) && (onOff[loopCounter - 1]) == 0) || ((loopCounter == 0) && (onOff[loopCounter] == 1)))	//If the current schedule value is on and the previous is off or if the day's first value is on
		{
			printf("On from %02d:%02d to ", hourofDay[loopCounter], minofHour[loopCounter]);                                    //Print starting time
		}
		if((onOff[loopCounter] == 0) && (onOff[loopCounter - 1] == 1))                                                          //If the current schedule value is off and the previous is on
		{
			printf("%02d:%02d\n", hourofDay[loopCounter], minofHour[loopCounter - 1]);                                          //Print end time
		}
	}
}

void consumptionPatternReader()																												//Function to read given consumption schedule in CSV format
{
	int counter = 0;																								//Declare variables
	int i = 0;																										//Declare variables
	char fileName[64];                                                                                  			//Declare array for string reading
	FILE *cpPtr = NULL;                                                                                 			//Declare file pointer
	//cpPtr = fopen("ConsumptionPattern00.csv", "r");                                                   			//Open consumption schedule. Used during debugging

	setbuf(stdout, 0);                                                                                  			//scanf fix

	printf("\nEnter consumption schedule name:");                                                       			//Print user instructions
	scanf("%s", fileName);                                                                              			//Scan user given filename
	cpPtr = fopen(fileName, "r");                                                                       			//Assign pointer to file and open the file for reading

	if ( cpPtr == NULL )                                                                                			//Determine whether the pointer was successfully assigned
	{                                                                                                   			
		printf("ERROR - Consumption pattern file could not be opened!\n");                              			//If the file could not be found, print error notification
		exit(0);                                                                                        			//Exit the program
	}

	else                                                                                                            //If the pointer was successfully assigned
	{
		for(counter = 0; counter < 1440 + 1; counter++)                                                             //Increment total possible entries
		{
			if(counter == 0)                                                                                        //Discard first line of file
			{                                                                                                       //		||
				fscanf(cpPtr, "%*[^\n]\n", NULL);                                                                   //		||
			}
			else
			{
				fscanf(cpPtr, "%d:%d,%d", &hourofDay[counter-1], &minofHour[counter-1], &volume[counter-1]);        //Scan the hour, minute and on/off state into appropriate array
			}
		}
		fclose(cpPtr);                                                                                              //Close file
	}

	for(counter = 0; counter < 1440; counter++)                                                                     //Increment total minutes of the day
	{
		if(counter == ((hourofDay[i] * 60) + minofHour[i]))                                                         //If the counter/ minute of day is equal to the current read time
		{
			consumption[counter] = volume[i];                                                                       //Assign current volume value to min of day consumption array
			i++;                                                                                                    //Increment current read value counter
		}
	}
}

void printConsumptionPatternCSV()																											//Function to print consumption pattern used during debugging
{
	int loopCounter = 0;                                                                                                                            //Declare variables
	double volumeSession = 0;                                                                                                                       //Declare variables
	double volumeTotal = 0;                                                                                                                         //Declare variables
	int i = 0;                                                                                                                                      //Declare variables

	printf("\nPrinting consumption schedule\n");                                                                                                    //Print schedule name

	for(loopCounter = 0; loopCounter < 1440; loopCounter++)                                                                                         //Increment through total possible entries
	{
		if(((consumption[loopCounter] != 0) && (consumption[loopCounter - 1]) == 0) || ((loopCounter == 0) && (consumption[loopCounter] != 0)))		//If there is current consumption
		{
			printf("On from ");                                                                                                                     //Print on time
			TimeConversion(loopCounter);                                                                                                            //		||
			printf(" to ");                                                                                                                         //		||
			i = 1;                                                                                                                                  //Set gate to open
		}
		if((consumption[loopCounter] == 0) && (consumption[loopCounter - 1]) != 0)                                                                  //If there is no longer consumption
		{
			TimeConversion(loopCounter - 1);                                                                                                        //Print off time
			volumeSession = volumeSession + consumption[loopCounter];                                                                               //Calculate session volume
			volumeTotal = volumeTotal + consumption[loopCounter];                                                                                   //Update total volume
			printf(", volume = %.0f litres\n", volumeSession);                                                                                      //Print session volume
			i = 0;                                                                                                                                  //Set gate to closed
			volumeSession = 0;                                                                                                                      //Reset session volume
		}

		if(i == 1)                                                                                                                                  //If gate is open
		{
			volumeSession = volumeSession + consumption[loopCounter];                                                                               //Update session volume
			volumeTotal = volumeTotal + consumption[loopCounter];                                                                                   //Update total volume
		}
	}
	printf("Total volume consumed for the day = %.0f litres\n", volumeTotal);                                                                       //Print day total volume
}

void EWHPropertiesReader()																													//Function to read EWH properties from binary file
{
	char fileName[64];                                      //Declare array for string reading
	FILE *propPtr = NULL;                                   //Declare file pointer
	//propPtr = fopen("Physical00.bin", "r");               //Open heating schedule. Used during debugging
	
	setbuf(stdout, 0);                                      //Scanf fix
	
	printf("\nEnter EWH properties file name:");            //Print user instructions
	scanf("%s", fileName);                                  //Scan user given filename
	propPtr = fopen(fileName, "r");                         //Assign pointer to file and open the file for reading

	if ( propPtr == NULL )                                  //Determine whether the pointer was successfully assigned
	{
		printf("ERROR - File could not be opened!\n");      //If the file could not be found, print error notification
		exit(0);                                            //Exit the program
	}

	else                                                    //If the pointer was successfully assigned
	{
		fread(&geyser, 56, 1, propPtr);                     //Read the EWH structure properties to geyser
		fclose(propPtr);                                    //Cose the file
	}
}

void printEWHProperties()																													//Function to print EWH properties used during debugging
{
	printf("\nPrinting EWH physical properties:\n");								//Print table heading
	printf("Thermal conductance: %02f W/(K.m^2)\n", geyser.thermalConductance);     //Print properties
	printf("Volume: %02d l\n", geyser.volume);                                      //		||
	printf("Element rating: %02d Watts\n", geyser.elementRating);                   //		||
	printf("Internal temperature: %02f degC\n", geyser.internalTemperature);        //		||
	printf("Set temperature: %02f degC\n", geyser.setTemp);                         //		||
	printf("Length: %02f m\n", geyser.length);                                      //		||
	printf("Radius: %02f m\n", geyser.radius);                                      //		||
	printf("Surface area: %02f m^2\n", geyser.surfaceArea);                         //		||
}

void printDayStats()																														//Function to print table of day usage details
{
	int loopCounter = 0, sessionDuration = 0, sessionVolume = 0, totalVolume = 0;                                                                           //Declare variables
	double sessionEnergy = 0, sessionAveTemp = 0, totalEnergyUse = 0, sessionTemp = 0, stepTemp = 0;                                                        //Declare variables

	printf("\n%5s%10s%10s%10s%10s%10s", "Start", "Duration", "Volume", "Energy", "Cost", "Ave Temp");                                                       //Print table headings
	printf("\n%5s%10s%10s%10s%10s%10s", "time", "min", "litres", "kWh", "Rand", "degC");                                                                    //		||
	printf("\n%55s", "=======================================================");                                                                            //		||

	for(loopCounter = 0; loopCounter < 1440; loopCounter++)                                                                                                 //Increment total possible entries
	{
		stepTemp = (double)geyser.internalTemperature;                                                                                                      //Assign the geyser internal temperature to a temporary value
		runSimulationStep(&geyser, 1, inletT, ambientT, consumption[loopCounter], onOff[loopCounter]);                                                      //Run a single simulation step

		if(consumption[loopCounter] != 0)                                                                                                                   //If there is current consumption
		{
			sessionDuration++;                                                                                                                              //Increment session duration counter
			sessionVolume = sessionVolume + consumption[loopCounter];                                                                                       //Update session volume
			sessionEnergy = sessionEnergy + (c * consumption[loopCounter] * (stepTemp - inletT)); 															//Update session energy
			sessionTemp = sessionTemp + stepTemp;                                                                                                           //Update session temperature

			if(consumption[loopCounter + 1] == 0)                                                                                                           //If there is no longer consumption
			{
				sessionAveTemp = (sessionTemp / (double)sessionDuration);                                                                                   //Calculate session average temperature

				printf("\n");
				TimeConversion(loopCounter - sessionDuration + 1);                                                                                          //Print session start time in hh:mm format
				printf("%10d%10d%10.3f%10.2f%10.1f", sessionDuration, sessionVolume, sessionEnergy / 1000, (sessionEnergy / 1000) * 1.50, sessionAveTemp);  //Print session details

				totalVolume = totalVolume + sessionVolume;                                                                                                  //Update total volume
				totalEnergyUse = totalEnergyUse + sessionEnergy;                                                                                            //Update total energy use

				sessionDuration = 0;                                                                                                                        //Reset variable
				sessionVolume = 0;                                                                                                                          //Reset variable
				sessionEnergy = 0;                                                                                                                          //Reset variable
				sessionTemp = 0;                                                                                                                            //Reset variable
			}
		}
	}
	printf("\nTotal energy input\t= %.3f kWh (R %.2f),", totalEnergyIn / 1000, (totalEnergyIn / 1000) * 1.50);                                              //Print day's total energy input and cost
	printf("\nTotal energy extracted\t= %.3f kWh (R %.2f),", totalEnergyUse / 1000, (totalEnergyUse / 1000)* 1.50);                                         //Print day's total energy usage and cost
	printf("\nTotal volume used\t= %d litres", totalVolume);                                                                                                //Print day's total water consumption
}

