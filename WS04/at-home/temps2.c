

#include <stdio.h>

int main() {
	
	
	int days , field;
	int highDay = 0;
	int lowDay = 0;
	int max = -100;
	int min =  100;
	int highTemp[10];
	int lowTemp[10];
	int i;
	float totalAv= 0;

	printf("---=== IPC Temperature Analyzer V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &days);

		while (days < 3 || days > 10) {
				printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
					scanf("%d", &days);
	}

	printf("\n");

			for (i = 0; i < days; i++) {
				printf("Day %d - High: ", i + 1);
					scanf("%d", &highTemp[i]);
						printf("Day %d - Low: ", i + 1);
							scanf("%d", &lowTemp[i]);


				if (highTemp[i] > max) {
					max = highTemp[i];
					highDay = i;
	}

						if (lowTemp[i] < min) {
							min = lowTemp[i];
							lowDay = i;
	}

	}


		printf("\nDay  Hi  Low\n");


			for (i = 0; i < days; i++) {
				printf("%-2d   %-3d %-3d\n", i + 1, highTemp[i], lowTemp[i]);
	}

		printf("\nThe highest temperature was %d, on day %d\n", max, highDay +1);
		printf("The lowest temperature was %d, on day %d\n", min, lowDay +1);
	
	
			do {
				printf("\nEnter a number between 1 and 4 to see the average temperature for the entered number of days, enter a negative number to exit: ");
				scanf("%d", &field);
			
					while (field == 0 || field > 4){
							printf("\nInvalid entry, please enter a number between 1 and 4, inclusive: ");
							scanf("%d", &field);
	}

							if (field < 0)

							printf("\nGoodbye!\n");

							else {
							totalAv = 0;

									for (i = 0; i < field; i++) {
									totalAv += (float)(highTemp[i] + lowTemp[i]) / 2;
	}

		totalAv = totalAv / field;
		printf("\nThe average temperature up to day %d is: %.2f\n", field, totalAv);

	}

	}while (field > 0);
	
		
	return 0;
}


