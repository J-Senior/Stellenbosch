/* Filename:				CP143_19842422.h
 * Date:					28/09/2016
 * Name:					Senior J.J.
 * Student number:			19842422
 * ----------------------------------------------------------
 * By submitting this file electronically, I declare that it
 * is my own original work, and that I have not copied
 * any part of it from another source, unless instructed
 * to do so in the assignment.
 * ----------------------------------------------------------
 */

#ifndef CP143_19842422_H_
#define CP143_19842422_H_

#include <stdlib.h>			//Include standard libraries
#include <stdio.h>			//Include standard libraries
#include <math.h>			//Include standard libraries
#include <time.h>			//Include standard libraries
#include <string.h>			//Include standard libraries

#define c 1.16263889		//specific heat of water in Wh / (kg * degC)
#define inletT 18			//EWH inlet temperature in °C
#define ambientT 20			//EWH ambient temperature in °C

struct geyserType{						//Definition of the geyserType structure
	double thermalConductance;			//G in W/(K.m^2)
	double internalTemperature;			//in degC, initial value (updated by simulator)
	double setTemp;						//Thermostat set temp in degC
	int volume;							//in litres (meter can only measure whole litres)
	int elementRating;					//in Watts
	double length;						//length of EWH in metersx
	double radius;						//radius of EWH in metres
	double surfaceArea;					//Area exposed to the environment in m^2
};

struct geyserType geyser;				//Declare struct geyser of type geyserType

void TimeConversion(int minOfDay);                                                                     										//Prototype for converting 'minute of the day' to hh:mm format
void runSimulationStep(struct geyserType*geyser, double stepPeriod, double inletTemp, double ambientTemp, double consumption, int heating);	//Prototype to run a single simulation step of the EWH
void heatingScheduleReader();																												//Prototype to read heating schedule CSV file
void printHeatingScheduleCSV();																												//Prototype to print heating schedule
void consumptionPatternReader();                                                                                                            //Prototype to read consumption pattern CSV file
void printConsumptionPatternCSV();                                                                                                          //Prototype to print consumption pattern
void EWHPropertiesReader();                                                                                                                 //Prototype to read EWH properties binary file
void printEWHProperties();                                                                                                                  //Prototype to print EWH properties
void printDayStats();                                                                                                                       //Prototype to print daily usage details

#endif /* CP143_19842422_H_ */
