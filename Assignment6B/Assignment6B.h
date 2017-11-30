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


#ifndef ASSIGNMENT6B_H_
#define ASSIGNMENT6B_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define width 265
#define height 80
#define datapoints 500
#define gravity 9.81
#define absZero 0.0
#define half 0.5

void TrajectoryCalc(double speed, double angle, double data[][2]);
void ClearDisplay(char display[][height]);
void UpdateDisplay(char display[][height], double data[][2]);
void PrintDisplay(char display[][height]);

#endif /* ASSIGNMENT6B_H_ */
