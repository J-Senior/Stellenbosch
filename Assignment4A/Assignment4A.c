/* Filename:				Assignment4A.c
 * Date:						2016/07/27
 * Name:					Senior J.J.
 * Student number:		19842422
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

int main(){
	float R1 = 0;
	float R2 = 0;
	float Rt = 0;
	float V = 0;
	float I = 0;

	setbuf(stdout, 0);

	printf("One resistor may be zero; neither may be negative;\n"
			"voltage must be greater than zero.\n"
			"Value for Resistor 1 (units: Ohm): ");
	scanf("%f" , &R1);

	printf("Value for Resistor 2 (units: Ohm): ");
	scanf("%f" , &R2);

	if(R1 == 0 && R2 == 0 || R1 < 0 || R2 < 0){
		printf("Invalid input. Only one resistor may be zero and neither may be negative.");
	}

	else{
		printf("Value for Voltage Source (units: V): ");
		scanf("%f" , &V);

		if(V == 0){
			printf("Invalid input. Voltage must be greater than zero.");
		}

		else{
			Rt = R1 + R2;
			I = V / Rt;

			if(I <= 0.1){
				printf("For a series circuit the current is %3.0f (units: mA)\n" , I*1000 );
			}

			else{
				printf("For a series circuit the current is %.3f (units: A)\n" , I );
			}
		}
	}
	
	return 0;
}