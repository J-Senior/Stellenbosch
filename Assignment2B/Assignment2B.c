/* Filename:				Assignment2B.c
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

int main()
{
	int grid=0;
	int gridy=0;
	int gridx=0;

	setbuf(stdout, 0);

	printf("Enter the grid size: ");
	scanf("%d",&grid);

	for(gridy=1; gridy<=grid; gridy++){
		printf("\n");
		for(gridx=1; gridx<=grid; gridx++){
				printf("* ");
		}
	}

	return 0;
}
