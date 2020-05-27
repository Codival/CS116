/*
 *Purpose:Print the data in the Wine class objects
 * 
 * 
 * @author Amuldeep Dhillon
 * @version 1.0 5/6/2017
 * 
 * @param - none
 * @return - none
*/
#include "lab.h"


void Wine::printInfo(){

	cout << left << setw(30) << setfill(' ') << wineName << setw(15) << setfill(' ')
		<< wineYear << setw(15) << setfill(' ') << wineRating << setw(15) << setfill(' ')
		<< winePrice << setw(15) << setfill(' ') << wineType <<endl;
}

