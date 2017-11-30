/* Filename:				Assignment5A.c
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

int main(){
	
	int array[10];
	int NewRandVal = 0;
	int pos = 0;

	setbuf (stdout , 0);
	srand( time( NULL ) );

	while( pos < 10){
		NewRandVal = ( rand() % ( 20 - 1 + 1 )) + 1;
		array[pos] = NewRandVal;
		pos++;
	}

	pos = 0;
	while( pos < 10){
		printf("array[%d] - %d\n" , pos, array[pos]);
		pos++;
	}

	pos = 0;
	while( pos < 10){
		array[pos] = array[pos] * 100;
		pos++;
	}

	pos = 0;
	while( pos < 10){
		printf("\narray[%d] - %d" , pos, array[pos]);
		pos++;
	}

	printf("\n\n");

	pos = 9;
	
	while( pos >= 0){
		printf("array[%d] - %d\n" , pos, array[pos]);
		pos--;
	}

	return 0;
}
