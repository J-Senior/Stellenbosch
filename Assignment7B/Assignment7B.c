/* Filename:				Assignment7B.c
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

void getPositionForce(float matrix[][3]);
void calcTorque(float posForce[][3], float torqueArr[]);
void displayTorque(float torque[]);

void PrintDisplay(float matrix[2][3]);

float i, j, k;

int main(){
	
	setbuf(stdout, 0);
	
	float matrix[2][3];
	float torqueArr[3];
	
	getPositionForce(matrix);
	calcTorque(matrix, torqueArr);
	displayTorque(torqueArr);
	
	return 0;
}

void getPositionForce(float matrix[][3]){
	
	printf("Please enter position vector in {i, j, k}m format:");
	scanf("%f, %f, %f", &matrix[0][0], &matrix[0][1], &matrix[0][2]);
	
	printf("Please enter force vector in {i, j, k}N format:");
	scanf("%f, %f, %f", &matrix[1][0], &matrix[1][1], &matrix[1][2]);
}

void calcTorque(float matrix[][3], float torqueArr[]){
	
	torqueArr[0] = ((matrix[0][1] * matrix[1][2]) - (matrix[0][2] * matrix[1][1]));
	torqueArr[1] = -((matrix[0][0] * matrix[1][2]) - (matrix[0][2] * matrix[1][0]));
	torqueArr[2] = ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
}

void displayTorque(float torqueArr[]){
	
	int counter;
	
	printf("Torque produced:\n");
	printf("{%.3f i, %.3f j, %.3f k}N/m\n", torqueArr[0], torqueArr[1], torqueArr[2]);
}

void PrintDisplay(float matrix[2][3]){
	
	int counterX, counterY;
	
	for(counterX = 0; counterX < 2; counterX++){
		for(counterY = 0; counterY < 3; counterY++){
			printf("%.2f ", matrix[counterX][counterY]);
		}
		putchar('\n');
	}
}