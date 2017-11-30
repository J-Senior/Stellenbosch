/* Filename:				Assignment1B.c
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

int main()
{
	int num1=0;							//User input
	int ans=0;							//Value for evaluation

	setbuf(stdout, 0);

	printf("Enter an integer:");
	scanf("%d",&num1);						//Read first variable

	ans = num1 % 2;							//Use modulus to return -1 or 0 or 1
	if(ans == 0){
		printf("The integer is even.");		//Return evaluation to user
	}
	else {
		printf("The integer is odd.");		//Return evaluation to user
	}
	return 0;
}
