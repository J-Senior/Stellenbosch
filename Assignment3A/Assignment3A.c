/* Filename:				Assignment3A.c
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

	char opnum=0;
	int int1=0;
	int int2=0;
	int ans=0;

	setbuf(stdout, 0);

	printf("Menu of Operations\n"
			"------------------\n"
			"1. +\n"
			"2. -\n"
			"3. *\n"
			"4. /\n"
			"5. %%\n"
			"Enter operation number to be executed: ");
	scanf("%c",&opnum);

	printf("Enter first integer: ");
	scanf("%d",&int1);

	printf("Enter second integer: ");
	scanf("%d",&int2);

	switch(opnum){
		case '1':
			ans=int1+int2;
			printf("%d + %d = %d",int1,int2,ans);
			break;

		case '2':
			ans=int1-int2;
			printf("%d - %d = %d",int1,int2,ans);
			break;

		case '3':
			ans=int1*int2;
			printf("%d x %d = %d",int1,int2,ans);
			break;

		case '4':
			ans=int1/int2;
			printf("%d / %d = %d",int1,int2,ans);
			break;

		case '5':
			ans=int1%int2;
			printf("%d %% %d = %d",int1,int2,ans);
			break;

		default:
			printf("Invalid choice\n");
	}

	return 0;
}
