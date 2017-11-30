/* Filename:				Assignment6A.c
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
	
	int int1 = 0;
	int *ptr1 = NULL;
	
	int1 = 42;
	
	printf("The value stored in the memory location labelled int1 is %d.\n", int1);
	printf("Address of memory location labelled int1 is %p.\n\n", &int1);
	
	printf("REFERRING TO int1 THROUGH INDIRECT MEANS:\n");
	
	ptr1 = &int1;
	
	printf("The value stored in the memory location labelled int1 is %d.\n", *ptr1);
	printf("Address of memory location labelled int1 is %p.\n\n", ptr1);
	
	printf("CHANGING int1 THROUGH INDIRECT MEANS:\n");
	
	*ptr1 = 169;
	
	printf("Value in memory labelled int1 has changed to %d (accessed with label).\n", int1);
	printf("Value in memory labelled int1 has changed to %d (accessed with pointer).\n\n", *ptr1);
	
	printf("CALCULATIONS WITH int1 THROUGH INDIRECT MEANS:\n");
	
	int1 = (*ptr1) * 10;
	
	printf("Value in memory labelled int1 has been multiplied by 10 to give %d (accessed with label).\n", int1);
	printf("Value in memory labelled int1 has been multiplied by 10 to give %d (accessed with pointer).\n", *ptr1);
	
	return 0;
}