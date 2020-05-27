#include "wine.h"

/*
 * Purpose:displays all the info on a wine
 * 
 * @author: Amuldeep Dhillon
 * @version: 1.0 3/7/2016
 * 
 * @param:none
 * 
 * @Outputs:The wine's name, type, year, rating, price, and city of 
 * 			origin with organized spaces
 * 
 * @return:none
*/


void Wine::printInfo(){
	string city;
	if (paddress != NULL)
		city=paddress->getCity();
	else
		city = "None";

	cout << left << setw(30) << setfill(' ') << wineName << setw(15) << setfill(' ')
		<< wineType << setw(15) << setfill(' ') << wineYear << setw(15) << setfill(' ')
		<< wineRating << setw(15) << setfill(' ') << winePrice << setw(15) << setfill(' ') << city <<endl;
}
