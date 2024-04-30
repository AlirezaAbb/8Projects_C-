//*****************************************************************************
//             Workshop - #8 (P1)
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

#define NUM_GRAMS 64
#define MAX_PRODUCT 3

// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo {
	int sku;
	double price;
	int calories;
	double weight;
};
// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* num);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* num);

// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int num_product);

// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo(const int sequence_num);

// 5. Display the formatted table header

void displayCatFoodHeader();

// 6. Display a formatted record of cat food data

void displayCatFoodData(const int sku, const double* price, const int calories, const double* weight);

// 7. Logic entry point

void start();