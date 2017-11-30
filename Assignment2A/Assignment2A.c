/* Filename:				Assignment2A.c
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

int main()
{
	int mop=0;
	float rad=0;
	float circ=0;
	float area=0;
	int hyp=0;
	int sida=0;
	int sidb=0;
	int hypc=0;

	setbuf(stdout, 0);

	while(mop!=3){

		printf("Menu Options:\n1. Circle Calculations\n2. Triangle Calculations\n3. Exit Program\n\nEnter your choice: ");
			scanf("%d",&mop);

		if(mop==1){
			printf("Please enter the radius of the circle: ");
			scanf("%f",&rad);

			circ=2*3.1416*rad;
			area=3.1416*pow(rad,2);

			printf("The circumference is %.4f and the area is %.4f.\n\n",circ, area);

		}

		if(mop==2){
			printf("Enter hypotenuse: ");
			scanf("%d",&hyp);

			printf("Enter side A: ");
			scanf("%d",&sida);

			printf("Enter side B: ");
			scanf("%d",&sidb);

			hypc=sqrt(pow(sida,2)+pow(sidb,2));

			if(hyp==hypc){
				printf("The first number is the hypotenuse of a right triangle.\n\n");
			}
			else{
				printf("The first number is NOT the hypotenuse of a right triangle.\n\n");
			}
		}

		if(mop>3){
			printf("An invalid menu option.\n\n");
		}

	}
	printf("Quitting...\n\n");
	return 0;
}
