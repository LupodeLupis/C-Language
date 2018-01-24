#include <stdio.h>

#define distRate1  0.69			// Rate per Kilometer from 0km to 100km (inclusive)
#define distRate2  0.49			// Rate per Kilometer above 100km 

// Structure Declaration for Vehicle Rentals
struct Rental
{
   int id;						// ID of the Rental Vehicle
   double baseDay;				// Daily Base Price 
   double earnings;			// Total earnings from this rental
};

/* prototype functions addPositive Here*/

double addPositive(double, double);



/* main program */
int main()
{
   const int noVehicles = 2;			// Number of Vehicles
   int option;							// Variable to store the option selected
   int flag;							// Flag to support vehicle ID find
   int tempID;							// To hold user input for vehicle ID
   int i = 0;
   int days, km;
   double basePrice;
   double rate;
   double charge;


   // Variable for "for-loop" counters

   // Initialize the struct Vehicle Rental
   struct Rental vRent[] = { { 123, 9.95, 0 },{ 124, 19.95, 0 } };

   /*Declare Your Variables Here*/




   printf("***** Rental Vehicle Management App *****\n\n");

   do
   {
      // Display the option list
      printf("1.) Rental Status\n");
      printf("2.) Apply Charges\n");
      printf("0.) Log out\n\n");
      printf("Please enter an option to continue: ");

      scanf("%d", &option);

      switch (option)
      {
      case 0: // Exit the program
         break;

      case 1: // Rental Vehicle Status

         printf("\n-- Rental Vehicle Status --\n\n");
         printf("ID#      Earnings\n");
         printf("-------- ----------\n");

		 for (i = 0; i < noVehicles; i++) {

				printf("%8d %10.2lf\n", vRent[i].id, vRent[i].earnings);

		 }

		 printf("\n");


         // Use "%8d %10.2lf" formatting to display ID and Earnings for each rental
         // using a loop construct

         break;

      case 2: // Calculate Rental Charges

         flag = -1;
         printf("\n-- Rental Charges --\n\n");
         printf("Enter vehicle ID: ");
         scanf("%d", &tempID);


         // Finding the correct vehicle index
         for (i = 0; i < noVehicles && flag == -1; i++) {
            if (tempID == vRent[i].id) {
               flag = i;
            }
         }

         if (flag != -1) { 

			 printf("Enter Rental Period (in Days): "); 
			 scanf("%d", &days);

			 basePrice = vRent[flag].baseDay * days; 

			 printf("Enter kilometers driven: ");
			 scanf("%d", &km);

			 if (km >=0 && km <= 100) {

				 rate = distRate1 * km;
			 }
			 else if (km > 100) {

				 rate = distRate1 * 100 + distRate2 * (km - 100);

			 }

			 charge = basePrice + rate ; 
										 

			 vRent[flag].earnings = addPositive(vRent[flag].earnings,charge); 


          
            printf("\nBase   kmCost Total\n");
            printf("====== ====== ======\n");

			printf("%6.2lf %6.2lf %6.2lf\n\n", basePrice, rate, basePrice + rate);

            // Use "%6.2lf %6.2lf %6.2lf" formatting inside a printf statement

         }
         else {
            printf("ERROR: Vehicle ID does not exist.\n\n");
         }

         break;


      default:
         printf("Error: Please enter a valid option to continue\n\n");
         break;
      }


   } while (option != 0);


   return 0;
}



/* Implement Function addPositive Here*/
double addPositive(double amount, double newAmount)
{
	
	if (newAmount > 0) {

		amount+=  newAmount;

	}
	return amount;
}




