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
			addBook(filename,&mybook);
			printf("The book is successfully added to the inventory.\n\n");
			break;
		case 3:
			//checkPrice(filename,&mybook);
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
 //Not implemented!
}

void checkPrice(const char filename[], const int isbn2find) {


}


void clear(void)
{
	//Not implemented!
}

int searchInventory(FILE *fp, const int isbn2find)
{
 //Not implemented! 

	return 0;
}


float calculateCapital(const char filename[])
{
    //Define an object of struct Book

	struct Book capital;
    
    //Define and initialize total_capital
    
	float total_capital = 0;
    
    //Open the file, and check for null pointer
    
	FILE *fp = fopen(filename, "r");
	if ( fp != NULL)
	{
		
		while (readRecord(fp, &capital) == 5) {
			total_capital += capital._price * capital._qty;
		}
	}
    
        
	fclose(fp);
        
	return total_capital;
    
}

