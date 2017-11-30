/* Filename:				Assignment1A.c
 * Date:					2016/07/27
 * Name:					Senior J.J.
 * Student number:			19842422
 * ----------------------------------------------------------
 * By submitting this file electronically, I declare that it
 * is my own original work, and that I have not copied
 * any part of it from another source, unless instructed
 * to do so in the assignment.
 * ----------------------------------------------------------
 * Calculation Programming exercise
 * ----------------------------------------------------------
 */
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int num1=0;							//User input 1
	int num2=0;							//User input 2
	int ans=0;							//Answer returned to user

	setbuf(stdout, 0);

	printf("Please enter the first integer:\n");
	scanf("%d",&num1);										//Read first variable

	printf("Please enter the second integer:\n");
	scanf("%d",&num2);										//Read second variable

	ans = num1 + num2;										//Calculate sum
	printf("\n%d + %d = %d", num1, num2, ans);				//Return sum

	if (num2 != 0) {
		ans = num1 / num2;									//Calculate division
		printf("\n%d / %d = %d", num1, num2, ans);			//Return devision
	}
	else {
		printf("\n%d / %d is not allowed", num1, num2);		//Declare division invalid due to zero error
	}

	if (num2 != 0) {
		ans = num1 % num2;									//Calculate modulus
		printf("\n%d %% %d = %d", num1, num2, ans);			//Return modulus
	}
	else {
		printf("\n%d %% %d is not allowed", num1, num2);	//Declare modulus invalid due to zero error
	}

	ans = (num1 + num2) / 2;											//Calculate average
	printf("\nThe average of %d and %d is %d", num1, num2, ans);		//Return average

	return 0;
}


