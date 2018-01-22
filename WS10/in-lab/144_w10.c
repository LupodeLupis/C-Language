/*----------------------------------------
Name :ALBERTO LAURENZI
ID   :150954162
Email:alaurenzi@myseneca.ca
-----------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define FILE_TXT "jedi_master.txt"
#define FILE_CSV "starwars_directory.csv"

// FUNCTION PROTOTYPE //
int isJediMaster(const char name[]);
void formatJediPhoneRecord(char formattedRecord[], const char fullName[], const char npa[], const char co[], const char number[]);


int isJediMaster(const char name[]) {
	int isJedi = 0;
	char jedi_Name[31];

	FILE* fp;
	// open the file "jedi_master.txt"//
	fp = fopen(FILE_TXT, "r");
	// check if the file is open correctly//
	if (fp != NULL) {
		//read the names one by one until the end of file//
		while (fscanf(fp, "%30[^\n]%*c", jedi_Name) != EOF) {
			//compare the string and if the are equal, the value of return is = 0//
			if (strcmp(name, jedi_Name) == 0) {

				isJedi = 1;
			}
		}
	}
	//close the file "jedi_master.txt"//
	fclose(fp);

	return isJedi;
}

void formatJediPhoneRecord(char formattedRecord[], const char fullName[], const char npa[], const char co[], const char number[]) {


	int i;
	// Check if the lenght of the string fullName is > than 16//
	if (strlen(fullName) > 16) {

		strcpy(formattedRecord, fullName);
		formattedRecord[14] = '.';
		formattedRecord[15] ='.';
		formattedRecord[16] = '\0';
		
	}

	else {
		// copy the content of the string fullName into formattedRecord //
		strcpy(formattedRecord, fullName);

		//iterate n-times until 16th char is reached //
		for (i = 0; i < (16 - strlen(fullName)); i++) {
			strcat(formattedRecord, " ");
		}
	}
	
	// concatenate formattedRecord with ()- and area code number, prefix, line number//
	strcat(formattedRecord, " (");
	strcat(formattedRecord, npa);
	strcat(formattedRecord, ") ");
	strcat(formattedRecord, co);
	strcat(formattedRecord, "-");
	strcat(formattedRecord, number);
	
	// check if the name and concatenate  "Jedi Master" if belog to him //
	if (isJediMaster(fullName) == 1) {
		strcat(formattedRecord, " Jedi Master");
	}
}



/* Example formatted strings:
Padme Amidala    (418) 555-0105
Mace Windu       (438) 555-0155 Jedi Master.
Emperor Palpat.. (450) 555-0143
*/