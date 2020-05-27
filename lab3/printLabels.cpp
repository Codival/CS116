#include "wine.h"

/*
 * Purpose:print the labels for all the wine lists
 * 
 * @author: Amuldeep Dhillon
 * @version: 1.0 3/7/2016
 * 
 * @param:none
 * 
 * 
 * @Outputs:The words name, type, vintage, rating, price, and city in
 * 			the same location as the list will appear in
 * 
 * @return:none
*/


void printLabels(){
	std::cout << "\n";
	std::cout << left << setw(30) << setfill(' ') << "Name" << setw(15) 
	<< setfill(' ') << "Type" << setw(15) << setfill(' ') << "Vintage" 
	<< setw(15) << setfill(' ') << "Rating" << setw(15) << setfill(' ') 
	<< "Price" << setw(15) << setfill(' ') << "City" <<std::endl;
}
