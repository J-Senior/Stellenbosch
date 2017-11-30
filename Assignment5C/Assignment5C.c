/* Filename:				Assignment5c.c
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

void printCounter(int counter);
int GCD(int x, int y);

static int x = 1;

int main(){

	printCounter(11);
	printf("\n\nGCD(%d,%d) = %d", 10, 20, GCD(10,20));
	printf("\n");
	return 0;
}

void printCounter(int counter){
	
	printf("\n%d", x);
	x++;
	
	if( x < counter){
		printCounter(counter);
	}
}

int GCD(int x, int y){

	if( y == 0){
		return x;
	}
	
	else{
		return GCD(y, x % y);
	}
}
