/*
Name:ALBERTO LAURENZI
Student number:150954162
Email:alaurenzi@myseeca.com
Workshop:Lab8
Section:
Date:7.14.2017
*/



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_BOOKS 10
#define MAX_TITLE_SIZE 20

struct Book {
	int _isbn;
	float _price;
	int _year;
	char _title[MAX_TITLE_SIZE];
	int _qty;
};

// Function Prototype//
void menu();
void displayInventory(const struct Book book[], const int size);
void searchInventory(const struct Book book[], const int isbn, const int size);
void addBook(struct Book book[], int *size);
void checkPrice(const struct Book book[], const int size);
void clear(void);


int main(void) {

	struct Book book[MAX_BOOKS]; //= { { 0 } };
	int size = 0;
	int option = 0;

	printf("Welcome to the Book Store\n");
	printf("=========================\n");

	do {
		menu();
		printf("Select: ");
		scanf("%d", &option);

		switch (option)
		{
		case 0:
			printf("Goodbye!\n");
			break;
		case 1:
			displayInventory(book,size);
			break;
		case 2:
			addBook(book, &size);
			printf("The book is successfully added to the inventory.\n\n");
			break;
		case 3:
			checkPrice(book,size);
			break;

		default:
			printf("Invalid input, try again:\n");
			break;
		}
	} while (option != 0);

	return 0;
}
// Display the Menu Option//
void menu() {
	
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("0) Exit.\n\n");

}
//Dispaly the Format//
void displayInventory(const struct Book book[], const int size) {
	
	int i;
	
	if (size > 0) {

		printf("\n\nInventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");

		for (i = 0; i < size; i++) {
			// Struct book = {{0}} + The If loop were used for let the User add all 10 books and display them //
			if (book[i]._isbn != 0) {
				printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book[i]._isbn, book[i]._title, book[i]._year, book[i]._price, book[i]._qty);
			}
		}
	}
	else {

		printf("The inventory is empty!\n");
	}
	printf("===================================================\n\n");
	
}
// add Item and check the index//
void addBook(struct Book book[], int *size) {

	int a = *size;

	if (*size >= MAX_BOOKS) {
		printf("the inventory is full\n");	
	}
	else {
		
		printf("ISBN:");
		scanf("%d", &book[a]._isbn);
		printf("Title:");
		clear();
		scanf("%20[^\n]", book[a]._title);
		clear();
		printf("Year:");
		scanf("%d", &book[a]._year);
		printf("Price:");
		scanf("%f", &book[a]._price);
		printf("Quantity:");
		scanf("%d", &book[a]._qty);
	}
	a++;
	*size = a;
}

// clear the Input Buffer//
void clear(void)
{
	while (getchar() != '\n')
		;
}


// >Function to be implemented in Home_Portion< //
void checkPrice(const struct Book book[], const int size) {}

void searchInventory(const struct Book book[], const int isbn, const int size){}

