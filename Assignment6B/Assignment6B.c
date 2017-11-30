/* Filename:				Assignment6B.c
 * Date:					2016/07/27
 * Name:					Senior J.J.
 * Student number:			19842422
 * ----------------------------------------------------------
 * By submitting this file electronically, I declare that it
 * is my own original work, and that I have not copied
 * any part of it from another source, unless instructed
 * to do so in the assignment.
 * ----------------------------------------------------------
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "Assignment6B.h"

void TrajectoryCalc(double speed, double angle, double data[][2]){
	
	int counter = 0;
	double rad = 0;
	double temp = 0;
	double speedY = 0;
	double speedX = 0;

	for (counter = 0; counter < datapoints; counter++){
		data[counter][0] = data[counter][1] = -1.0;
	}
	rad = angle * M_PI / 180.0;
	speedX = speed * cos(rad);
	speedY = speed * sin(rad);
	speedX = fmax(speedX, 0.1);

	counter = 0;
	
	do {
		data[counter][0] = counter;
		temp = counter * (speedY - half * gravity * counter / speedX) / speedX;
		data[counter][1] = temp;
		counter++;
	} while (temp >= absZero);
}

void ClearDisplay(char display[][height]){
	
	int counterX, counterY;
	
	for(counterX = 0; counterX < width; counterX++){
		for(counterY = 0; counterY < height; counterY++){
			display[counterX][counterY] = ' ';
		}
	}
	
	for (counterX = 1; counterX < (width - 1); counterX++){
		display[counterX][0] = '-';
		display[counterX][height - 1] = '-';
	}
	
	for (counterY = 0; counterY < (height); counterY++){
		display[0][counterY] = '|';
		display[width - 1][counterY] = '|';
	}	
}

void UpdateDisplay(char display[][height], double data[][2]){
	
	int counter = 0;
	int x = 0;
	int y = 0;	
	
	for (counter = 0; counter < datapoints; counter++){
		y = (int) floor(data[counter][1]);
		if(y >= 0){
			x = (int) floor(data[counter][0]);
			if ((x < width) && (y < height)){
				display[x][height - 1 - y] = '*';
			}		
		}	
	}
}	

void PrintDisplay(char display[][height]){
	
	int counterX, counterY;
	
	for(counterY = 0; counterY < height; counterY++){
		for(counterX = 0; counterX < width; counterX++){
			putchar(display[counterX][counterY]);
		}
		putchar('\n');
	}
	
}
