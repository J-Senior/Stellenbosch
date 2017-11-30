/* Filename:				Assignment5B.c
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

void arrayGenerator( char array[], int sizeOfArray);
void arrayDisplay( char array[], int sizeOfArray);
void arrayOrganise( char array[], int sizeOfArray);

int main(){

	int sizeOfArray = 100;

	char array[sizeOfArray];

	arrayGenerator( array, sizeOfArray);
	arrayDisplay( array, sizeOfArray);
	arrayOrganise( array, sizeOfArray);
	arrayDisplay( array, sizeOfArray);

	return 0;
}

void arrayGenerator( char array[], int sizeOfArray){

	int pos = 0;
	int NewRandInt = 0;
	char NewRandChar = 0;

	srand( time( NULL ) );

	while( pos < sizeOfArray ){
		NewRandInt = ( rand() % ( 122 - 97 + 1 )) + 97;
		NewRandChar = (char)NewRandInt;
		array[pos] = NewRandChar;
		pos++;
	}
}

void arrayDisplay( char array[], int sizeOfArray){

	int pos = 0;

	printf("\n");

	while( pos < sizeOfArray){
		printf("array[%d] - %c\n" , pos, array[pos]);
		pos++;
	}

	printf("\n");

	return;
}

void arrayOrganise( char array[], int sizeOfArray){

	int counter = 0;
	int hold = 0;
	int pos = 0;

	for( counter = 1; counter < sizeOfArray; counter++ ){
		for( pos = 0; pos < sizeOfArray - 1; pos++ ){
			if( array[pos] > array[pos + 1]){
				hold = array[pos];
				array[pos] = array[pos + 1];
				array[pos + 1] = hold;
			}
		}
	}
}