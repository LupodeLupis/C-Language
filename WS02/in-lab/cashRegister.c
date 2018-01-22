// ALBERTO LAURENZI 150954162 //

#include <stdio.h>

int main() {

	double paid, balance , balance1;
	int loonie;
	int numQuarter;


	printf("Please enter the amount to be paid: $");
	scanf("%lf", &paid);

	loonie = paid;
	balance = paid - loonie;

	//balance = (int)(paid * 100) % (loonie * 100); // linux truncates the value by 0.01
	//balance = balance / 100; // linux truncates the value by 0.01

	printf("Loonies required: %d, balance owing $%.2lf\n", loonie , balance);

	numQuarter = balance / 0.25;
	
	balance1 = balance - (numQuarter * 0.25);


	printf("Quarters required: %d, balance owing $%.2lf\n", numQuarter , balance1);



	return 0;
}





