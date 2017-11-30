/* Filename:				Assignment7A.c
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

void passPointer(double *arrayPtr);
int counter;

int main(){

	double array[5] = {1.00, 2.20, 3.50, 6.50, 7.80};
	double *arrayPtr = NULL;

	printf("REFERRING TO MEMORY BLOCK USING ARRAY NAME:\n");
	for(counter = 0; counter < 5; counter++){
		printf("At index %d: Value = %.2lf, address = %d\n", counter, array[counter], &array[counter]);
	}

	arrayPtr = &array[0];
	
	printf("\nREFERRING TO MEMORY BLOCK BY USING POINTER WITH [ ] NOTATION:\n");
	for(counter = 0; counter < 5; counter++){
		printf("At index %d: Value = %.2lf, address = %d\n", counter, arrayPtr[counter], &arrayPtr[counter]);
	}
	
	printf("\nREFERRING TO MEMORY BLOCK BY USING POINTER WITH * NOTATION:\n");
	for(counter = 0; counter < 5; counter++){
		printf("At index %d: Value = %.2lf, address = %d\n", counter, *(arrayPtr + counter), (arrayPtr + counter));
	}

	printf("\nREFERRING TO MEMORY BLOCK BY USING THE POINTER PASSED TO FUNCTION:\n");
	passPointer(arrayPtr);
	
	return 0;
}

void passPointer(double *arrayPtr){
		for(counter = 0; counter < 5; counter++){
		printf("At index %d: Value = %.2lf, address = %d\n", counter, *(arrayPtr + counter), (arrayPtr + counter));
	}
}