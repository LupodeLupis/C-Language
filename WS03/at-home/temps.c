// Name:ALBERTO LAURENZI
// Student Number:150954162
// Email:alaurenzi@myseneca.ca
// Section:SKK
// Workshop:W3_home

#include <stdio.h>

#define NUMS 4

int main() {

	int  tempHigh, tempLow, i;
	float average;

	int lowDay = 0;
	int highDay = 0;

	int totalHigh = 0;
	int totalLow = 0;

	int max = -41;
	int min = 41;

	

	printf("---=== IPC Temperature Analyzer ===---");

	for (i = 0; i < NUMS; i++) {										
		printf("\nEnter the high value for day %d: ", i + 1);
		scanf("%d", &tempHigh);
			

		printf("\nEnter the low value for day %d: ", i + 1);
		scanf("%d", &tempLow);
			

		while (tempHigh > 40 || tempHigh < -40 || tempLow > 40 || tempLow < -40 || tempHigh < tempLow) {

			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");

			printf("\nEnter the high value for day %d: ", i + 1);
			scanf("%d", &tempHigh);

			printf("\nEnter the low value for day %d: ", i + 1);
			scanf("%d", &tempLow); 



		}

		if (tempHigh > max) {
				max = tempHigh;
				highDay = i;

			}

			if (tempLow < min) {
				min = tempLow;
				lowDay = i;
			}


		totalHigh = totalHigh + tempHigh;

		totalLow = totalLow + tempLow;

		
		
	}
	
		average = (float)(totalHigh + totalLow) / 8;

		printf("\nThe average (mean) temperature was: %.2f", average);

		printf("\nThe highest temperature was %d, on day %d ", max, highDay + 1);

		printf("\nThe lowest temperature was %d, on day %d ", min, lowDay + 1);
		

		return 0;

	}


