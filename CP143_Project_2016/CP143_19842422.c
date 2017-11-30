/* Filename:				CP143_19842422.c
 * Date:					28/09/2016
 * Name:					Senior J.J.
 * Student number:			19842422
 * ----------------------------------------------------------
 * By submitting this file electronically, I declare that it
 * is my own original work, and that I have not copied
 * any part of it from another source, unless instructed
 * to do so in the assignment.
 * ----------------------------------------------------------
 * This program recieves a consumption pattern, heating
 * pattern and properties file for an Electric Water Heater
 * (EWH). The consumption and heating files will be read from
 * CSV files. The properties will be read from a binary file.
 * This project will run a simulation to determine energy
 * and water consumption details. It will then return these
 * results in table format.
 * ----------------------------------------------------------
 */

#include <stdlib.h>						//Include standard libraries
#include <stdio.h>                  	//Include standard libraries
#include <math.h>                   	//Include standard libraries
#include <time.h>                   	//Include standard libraries
#include <string.h>						//Include standard libraries
#include "CP143_19842422.h"				//Include project library

int main()
{	
	EWHPropertiesReader();				//Read the EWH properties from the given binary file	
	
	heatingScheduleReader();			//Read the heating schedule from the given CSV file
	
	consumptionPatternReader();			//Read the consumption pattern from the given CSV file
	
	//printEWHProperties();				//Print the individual files for debugging purposes
	//printHeatingScheduleCSV();        //Print the individual files for debugging purposes
	//printConsumptionPatternCSV();     //Print the individual files for debugging purposes
	
	printDayStats();					//Run the simulation and print the results

	return 0;
}
