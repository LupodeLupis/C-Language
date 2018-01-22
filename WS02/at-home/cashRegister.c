//ALBERTO LAURENZI 150954162//

#include <stdio.h>

int main() {

	double gst, paid, balance;

	int amount, amount1, amount2, amount3, amount4, loonie, quarter, dimes, pennies, nickles;



	printf("Please enter the amount to be paid: $");

	scanf("%lf", &paid);

	gst = paid * 0.13 + 0.005;

	printf("GST: %.2lf\n", gst);

	balance = paid + gst;

	printf("Balance owing: $%.2lf\n", balance);


	loonie = balance;

	amount = (balance - loonie) * 100;
	
	printf("Loonies required: %d, balance owing $%.2lf\n", loonie, (double)amount / 100);


	quarter = amount / 25;

	amount1 = amount % 25;

	printf("Quarters required: %d, balance owing $%.2lf\n", quarter, (double)amount1 / 100);


	dimes = amount1 / 10;

	amount2 = amount1 % 10;

	printf("Dimes required: %d, balance owing $%.2lf\n", dimes, (double)amount2 / 100);


	nickles = amount2 / 5;

	amount3 = amount2 % 5;

	printf("Nickels required: %d, balance owing $%.2lf\n", nickles, (double)amount3 / 100);

	pennies = amount3 / 1;

	amount4 = amount3 % 1;

	printf("Pennies required: %d, balance owing $%.2lf\n", pennies, (double)amount4 / 100);



	return 0;

}
