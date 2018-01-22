/*
Name:ALBERTO LAURENZI
Student number:150954162
Email:alaurenzi@myseneca.ca
Workshop:W7_Home
Section:
Date:07/07/2017
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 3

int isValid(const long long phone);

void decompose(long long phone, int *AAA, int *PPP, int *LLLL) {


	*AAA = phone / 10000000;
	*PPP = (phone / 10000) % 1000;
	*LLLL = phone % 10000;

	return;
}


/* main program */
int main(void) {

	int i = 0;
	int index = 0;
	int Area = 0;
	int Prefix = 0;
	int Line = 0;
	int option;
	long long phoneNew;
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

				scanf("%lld", &phoneNew);
				
				if (isValid(phoneNew)) {
					phoneNumber[index] = phoneNew;
					index++;
					printf("\n");
				} 
				else {
					printf("ERROR!!! Phone Number is not Valid\n");
					printf("\n");
				}
			}
			else
			{
				printf("ERROR!!!Phone Number List is Full\n");
				printf("\n");
			}

			break;;
		default:
			printf("ERROR!!!: Incorrect Option: Try Again\n");
			printf("\n");
			break;;
		}

	} while (option != 0);

	return 0;
}


// implement Function isValid //

int isValid(const long long phone) {

	int areaCode[3] = { 416,647,905 };
	int area, prefix;
	int true = 1;
	int false = 0;
	int i;
	area = phone / 10000000;
	prefix = (phone / 10000) % 1000;

	for (i = 0; i < SIZE; i++) {
		if (areaCode[i] == area && prefix >= 100 && prefix <= 999) {
			return true;
		}
	}
	return false;
}
	