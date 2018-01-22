/*
Name:ALBERTO LAURENZI
Student number:150954162
Email:alaurenzi@myseneca.ca
Workshop:W7_LAB
Section:
Date:
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 3

 void decompose(long long phone, int *AAA, int *PPP, int *LLLL) {

	*AAA = phone / 10000000;
	*PPP = phone / 10000 % 1000;
	*LLLL = phone % 10000;

	return ;
}

int isValid(long long unVar);

/* main program */
int main(void) {

	int i = 0;
	int index = 0;
	int Area = 0;
	int Prefix = 0;
	int Line = 0;
	int option;
	long long phoneNumber[SIZE] = { 0LL };

	printf("---=== Phone Numbers ===---\n\n");

	do {
		// Display the Option List
		printf("1. Display Phone List\n");
		printf("2. Add a Number\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program

			printf("Exiting Phone Number App. Good Bye!!!\n");
			break;;

		case 1: // Display the Phone List
				// @IN-LAB
			printf("Phone Numbers\n");
			printf("==============\n");
			// Display each number in decomposed form

			for (i = 0; i < SIZE; i++) {
				decompose(phoneNumber[i], &Area, &Prefix, &Line);

				if (phoneNumber[i] != 0) {
					printf("(%3d)-%3d-%4d\n", Area, Prefix, Line);
				}
			}
			printf("\n");
			break;;

		case 2:	// Add a Phone Number
				// @IN-LAB
			printf("Add a Number\n");
			printf("============\n");

			if (phoneNumber[index] == 0) {

				scanf("\n%lld", &phoneNumber[index]);
				index++;
				printf("\n");
			}
			else
			{
				printf("ERROR!!!Phone Number List is Full\n");
				printf("\n");
			}

			break;;

		default:
			break;;
		}

	} while (option != 0);

	return 0;
}


// implement Function isValid //
