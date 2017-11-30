/* Filename:				Assignment3B.c
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

int main(){
	int num=0;
	int flag=0;
	int divisor=2;
	int modulo=0;

	setbuf(stdout, 0);

	printf("Enter an integer. I will determine if it is prime: ");
	scanf("%d",&num);

	if(num <= 1){
		printf("Invalid input");
	}

	else{
		while(divisor <= sqrt(num) && flag == 0 ){
			modulo = num % divisor;
			printf("%d mod %d = %d\n", num, divisor, modulo);

			if(modulo == 0){
				flag = 1;
			}

			else{
				flag = 0;
			}

			divisor = divisor + 1;
		}

		if(flag == 0){
			printf("\n%d is a prime number", num);
		}

		else{
			printf("\n%d is not a prime number", num);
		}

	}

	return 0;
}

