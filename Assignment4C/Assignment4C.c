/* Filename:				Assignment4A.c
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
#include <time.h>

void wattHr2joule(void);
void joule2wattHr(void);
void inch2cm(void);
void cm2inch(void);
void hp2kW(void);
void kW2hp(void);
void sec2HrMinSec(void);
double ans = 0;

int main(void){
	
	char menuop = 0;

	setbuf(stdout,0);

	while(menuop != 'x'){
		
		printf("\n***Conversion Menu***\n"
				"a.		Wh2Joule\n"
				"b.		Joule2Wh\n"
				"c. 		Inch2Cm\n"
				"d.		Cm2Inch\n"
				"e.		Hp2kW\n"
				"f.		kW2Hp\n"
				"g.		sec2HrMinSec\n"
				"x.		Exit\n"
				"Select a valid option:\n");
		scanf(" %c" , &menuop);

		switch(menuop){
			
			case 'a':
				wattHr2joule();
				break;

			case 'b':
				joule2wattHr();
				break;

			case 'c':
				inch2cm();
				break;

			case 'd':
				cm2inch();
				break;

			case 'e':
				hp2kW();
				break;

			case 'f':
				kW2hp();
				break;

			case 'g':
				sec2HrMinSec();
				break;
				
			case 'x':
				printf("Goodbye!\n");
				break;

			default :
				printf("\nInvalid option\n");
		}
	}

	return 0;
}

void wattHr2joule(){

	double Wh;

	setbuf(stdout,0);

	printf("Enter the value (Wh):\n");
	scanf("%lf" , &Wh);
	ans = Wh * 3.6 * pow(10 , 3);
	printf("Your answer is (J):\n"
			"%f J\n" , ans);
}

void joule2wattHr(){

	double J;

	setbuf(stdout,0);

	printf("Enter the value (J):\n");
	scanf("%lf" , &J);
	ans = J * 2.778 * pow(10 , -4);
	printf("Your answer is (Wh):\n"
			" %f Wh\n" , ans);
}

void inch2cm(){
	
	double in;

	setbuf(stdout,0);

	printf("Enter the value (inch):\n");
	scanf("%lf" , &in);
	ans = in * 2.54;
	printf("Your answer is (cm):\n"
			"%f cm\n" , ans);
}

void cm2inch(){
	
	double cm;

	setbuf(stdout,0);

	printf("Enter the value (cm):\n");
	scanf("%lf" , &cm);
	ans = cm / 2.54;
	printf("Your answer is (inch):\n"
			"%f inch\n" , ans);
}

void hp2kW(){
	
	double Hp;

	setbuf(stdout,0);

	printf("Enter the value (Hp):\n");
	scanf("%lf" , &Hp);
	ans = Hp / 0.746;
	printf("Your answer is (kW):\n"
			"%f kW\n" , ans);
}

void kW2hp(){
	
	double kW;

	setbuf(stdout,0);

	printf("Enter the value (kW):\n");
	scanf("%lf" , &kW);
	ans = kW * 0.746;
	printf("Your answer is (Hp):\n"
			"%f Hp\n" , ans);
}

void sec2HrMinSec(){
	
	int x = 0;
	int sa = 0;
	int ma = 0;
	int ha = 0;

	setbuf(stdout,0);

	printf("Enter the value (seconds):\n");
	scanf("%d" , &sa);


	x = sa / 60;
	ha = x / 60;
	ma = x % 60;
	sa = sa % 60;

	printf("Your answer is (hh:mm:ss):\n"
			"%d:%d:%d\n" , ha , ma , sa);
}