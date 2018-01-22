/*
Name:ALBERTO LAURENZI
Student number:150954162
Email:alaurenzi@myseneca.ca
Workshop:W8_Home
Section:
Date:07.18.2017
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
int searchInventory(const struct Book book[], const int isbn, const int size);
void addBook(struct Book book[], int *size);
void checkPrice(const struct Book book[], const int size);
void clear(void);


int main(void) {

	struct Book book[MAX_BOOKS]; 
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
			displayInventory(book, size);
			break;
		case 2:
			addBook(book, &size);
			//printf("The book is successfully added to the inventory.\n\n");
			break;
		case 3:
			checkPrice(book, size);
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
			
				printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book[i]._isbn, book[i]._title, book[i]._year, book[i]._price, book[i]._qty);
			
		}
	}
	else {

		printf("The inventory is empty!\n");
	}
	printf("===================================================\n\n");

}
// add Item and check the index//
void addBook(struct Book book[], int *size) {
	
	int quantity, number;
	
	printf("ISBN:");
	scanf("%d", &number);
	printf("Quantity:");
	scanf("%d", &quantity);
	
	int result = searchInventory (book, number, *size);

	if (result != -1) {
		book[result]._qty += quantity;
		printf("The book exists in the repository, quantity is updated.\n\n");
	}
	else if (*size == MAX_BOOKS) {
			printf("The inventory is full!\n");
		}
	 else
 {
		
	 book[*size]._isbn = number;
	 book[*size]._qty = quantity;
	 printf("Title:");
	 clear();
	 scanf("%20[^\n]", book[*size]._title);
	 clear();
	 printf("Year:");
	 scanf("%d", &book[*size]._year);
	 printf("Price:");
	 scanf("%f", &book[*size]._price);
	 printf("The book is successfully added to the inventory.\n\n");
	 *size += 1;
 }
	
}

// clear the Input Buffer//
void clear(void)
{
	while (getchar() != '\n')
		;
}


// Check Price of the book // 
void checkPrice(const struct Book book[], const int size) {

	int book_code;
	
	printf("Please input the ISBN number of the book:\n\n");
	scanf("%d", &book_code);

	int index = searchInventory(book, book_code, size);

	if (index == -1) {

		printf("Book does not exist in the bookstore! Please try again.\n\n");
	}
	else {	
		printf("Book %d costs $%.2f\n\n",book[index]._isbn, book[index]._price);
	}
}
 
// Linear research over the inventory //
int searchInventory(const struct Book book[], const int isbn, const int size) {

	int i;

	for (i = 0;i < size; i++) {
		
			if (book[i]._isbn == isbn) {

			return i;
		}
	}	
	return -1;
}

