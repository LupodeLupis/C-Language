#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_TITLE_SIZE 20


//Type the struct here

struct Book {
	int _isbn;
	float _price;
	int _year;
	char _title[MAX_TITLE_SIZE];
	int _qty;
};

//Type the function prototypes here

void menu();
int readRecord(FILE *fp, struct Book *b2read);
void displayInventory(const char filename[]);
int searchInventory(FILE *fp, const int isbn2find);
float calculateCapital(const char filename[]);
void addBook(const char filename[], struct Book *b2Add);
void checkPrice(const char filename[], const int isbn2find);
void clear(void);

int main()
{
	//Type your code here:

	struct Book mybook;
		
	char filename[] = "144_w9_inventory.txt";
	int option;

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
			displayInventory(filename);
			break;
		case 2:
			printf("ISBN:");
			scanf("%d", &mybook._isbn);
			printf("Title:");
			clear();
			scanf("%20[^\n]",mybook._title);
			clear();
			printf("Year:");
			scanf("%d", &mybook._year);
			printf("Price:");
			scanf("%f", &mybook._price);
			printf("Quantity:");
			scanf("%d", &mybook._qty);
			addBook(filename, &mybook);
			break;
		case 3:
			printf("Please input the ISBN number of the book:\n\n");
			scanf("%d", &mybook._isbn);
			checkPrice(filename, mybook._isbn);
			break;
		case 4:
			printf("The total capital is: $%.2f.\n", calculateCapital(filename));
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
	printf("4) Calculate total capital of the store.\n");
	printf("0) Exit.\n\n");
}


int readRecord(FILE *fp, struct Book *b2read) {
	return fscanf(fp, "%d;%f;%d;%d;%[^\n]", &b2read->_isbn, &b2read->_price, &b2read->_year, &b2read->_qty, b2read->_title);
}

void displayInventory(const char filename[])
{
	//Define an object of struct Book
	struct Book newBook;

	//Open the file, and check for null pointer
	FILE *fp = fopen(filename, "r");
	if (fp != NULL) {

		//If the file is properly opened, display headers, similar to workshop 8
		printf("\n\nInventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");



		//Use a while loop to call readRecord and display the records.
		while (readRecord(fp, &newBook) == 5) {

			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", newBook._isbn, newBook._title, newBook._year, newBook._price, newBook._qty);
		}

		printf("===================================================\n\n");
	}
	fclose(fp);
}

void addBook(const char filename[], struct Book *b2Add)
{	
	FILE *fp = NULL;
	fp = fopen(filename, "a+");

	if (searchInventory(fp, b2Add->_isbn) == 1) {

		printf("The book exists in the repository!\n\n");
	}
	else {
		fp = fopen(filename, "a+");
		fprintf(fp,"%d;%.2f;%d;%d;%s\n", b2Add->_isbn, b2Add->_price, b2Add->_year, b2Add->_qty, b2Add->_title);
		printf("The book is successfully added to the inventory.\n\n");
	}
	fclose(fp);
}

int searchInventory(FILE *fp, const int isbn2find)
{
	struct Book invBook = { 0 }	;

	while (readRecord(fp, &invBook) == 5) {
		if (invBook._isbn == isbn2find)

			return 1;
	}
	return -1;
}

void checkPrice(const char filename[], const int isbn2find)
{
	struct Book bookRead;
	FILE* fp;

	fp = fopen(filename, "r");

	while (readRecord(fp, &bookRead) == 5) {

		if (bookRead._isbn == isbn2find) {

			printf("Book %d costs $%.2f\n\n", bookRead._isbn, bookRead._price);

			return;
		}		
	}

	printf("The Book was not found\n\n");
}

void clear(void)
{
	while (getchar() != '\n')
		;
}

float calculateCapital(const char filename[])
{
	//Define an object of struct Book

	struct Book capital;

	//Define and initialize total_capital

	float total_capital = 0;

	//Open the file, and check for null pointer

	FILE *fp = fopen(filename, "r");
	if (fp != NULL)
	{

		while (readRecord(fp, &capital) == 5) {
			total_capital += capital._price * capital._qty;
		}
	}

	fclose(fp);

	return total_capital;

}

