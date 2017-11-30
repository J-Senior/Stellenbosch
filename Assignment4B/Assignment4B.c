/* Filename:				Assignment4A.c
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

#include <stdio.h>
#include <stdlib.h>

//function prototypes
void add(int x, int y); //one of the prototypes was written for you
void subtract(int x, int y);
void addSubtract(int x, int y, int z, int t);

int main(void){
	
	add(2,2);
	subtract(10,1);
	addSubtract(3,7,8,2);
	add(24,100);
	return 0;
}
//write the functions HERE!

void add(int x, int y){
	
	int ans;
	ans = x + y;
	printf("\nThe function called add() is starting.\n"
			"It adds the two integers that are sent to it: %d + %d = %d\n"
			"The function called add() is ending.\n" , x , y , ans );
}

void subtract(int x, int y){
	
	int ans;
	ans = x - y;
	printf("\nThe function called subtract() is starting.\n"
			"It subtracts the two integers that are sent to it: %d - %d = %d\n"
			"The function called add() is ending.\n" , x , y , ans );
}

void addSubtract(int x, int y, int z, int t){

	printf("\nThe function called addSubtract() is starting.\n"
			"It adds the first two and subtracts the last two of the four\n"
			"integers that are sent to it.\n"
			"It subcontracts its work ;)\n");

	add(x,y);

	subtract(z,t);

	printf("\nThe function called addSubtract() is ending.\n");
}
