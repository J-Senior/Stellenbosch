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
 
int main(){
	
	char display[width][height];
	double data[datapoints][2];
	double speed = 0.0;
	double angle = 0.0;
	int exit = 1;
	
	setbuf(stdout, 0);
	
	do{
		printf("Trajectory Display:\n");
		printf("Launch Speed (m/s):");
		scanf("%lf", &speed);
		printf("Launch Angle (deg):");
		scanf("%lf", &angle);

		ClearDisplay(display);
		PrintDisplay(display);
		TrajectoryCalc(speed, angle, data);
		UpdateDisplay(display, data);
		
		printf("\n\nTrajectory Display for launch velocity %4.1f m/s at %4.1f deg:\n\n", speed, angle);
		
		PrintDisplay(display);
		
		printf("Type 0 to exit.");
		scanf("%d", &exit);
	}while (exit != 0);
	
	return 0;
}
