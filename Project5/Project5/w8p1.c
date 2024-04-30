//*****************************************************************************
//             Workshop - #8 (Part-1)
//Full Name  : Alireza Abbasi
//Student ID#: 153388210
//Email		 : aabbasi35@myseneca.ca
//Section	 : ZDD
//
//Authenticity Declaration:
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider. This submitted
//piece of work is entirely of my own creation.
//*****************************************************************************


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* num) {
	int val;
	do
	{
		scanf("%d", &val);
		if (val <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (val <= 0);
	if (num != NULL)
		*num = val;
	return val;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* num) {
	double val;
	do
	{
		scanf("%lf", &val);
		if (val <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (val <= 0);
	if (num != NULL)
		*num = val;
	return val;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_product) {
	printf("Cat Food Cost Analysis");
	printf("\n======================");
	printf("\n\nEnter the details for %d dry food bags of product data for analysis.", num_product);
	printf("\nNOTE: A 'serving' is %dg\n", NUM_GRAMS);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence_num) {
	struct CatFoodInfo food = { 0 };
	printf("\nCat Food Product #%d\n", sequence_num);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&food.sku);
	printf("PRICE         : $");
	//food.price = getDoublePositive(NULL);
	getDoublePositive(&food.price);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&food.weight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&food.calories);

	return food;

}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const int calories, const double* weight) {
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}

// 7. Logic entry point
void start() {
	struct CatFoodInfo cats[MAX_PRODUCT] = { {0} };
	openingMessage(MAX_PRODUCT);
	int i;
	for (i = 0; i < MAX_PRODUCT; i++)
	{
		cats[i] = getCatFoodInfo(i + 1);
	}
	printf("\n");
	displayCatFoodHeader();
	for (i = 0; i < MAX_PRODUCT; i++)
	{
		displayCatFoodData(cats[i].sku, &cats[i].price, cats[i].calories, &cats[i].weight);
	}
}	