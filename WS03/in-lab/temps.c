

#include <stdio.h>

#define NUMS 3

int main() {

	int tempHigh, tempLow, i;
	float average;
	
	int totalHigh = 0;
	int totalLow = 0;


	printf("---=== IPC Temperature Analyzer ===---");

	for (i = 0; i < NUMS; i++) {
		printf("\nEnter the high value for day %d: " , i + 1);
		scanf("%d", &tempHigh);

		printf("\nEnter the low value for day %d: " , i + 1);
		scanf("%d", &tempLow);

		while (tempHigh > 40 || tempHigh < -40 || tempLow > 40 || tempLow < -40 || tempHigh < tempLow) {

			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");

			printf("\nEnter the high value for day %d: ", i + 1);
			scanf("%d", &tempHigh);

			printf("\nEnter the low value for day %d: ", i + 1);
			scanf("%d", &tempLow);

		}
		 
			totalHigh = totalHigh + tempHigh;
				
		    totalLow = totalLow + tempLow;
			
	}

	average = (float)(totalHigh + totalLow) / 6;
	printf("\nThe average (mean) temperature was: %.2f\n", average);



	return 0;

}

