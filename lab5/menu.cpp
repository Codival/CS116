/*
 *Purpose:Display a menu for the Wine Database
 * 
 * 
 * @author Amuldeep Dhillon
 * @version 1.0 5/6/2017
 * 
 * @param input - The input that the user inputs
 * @return - none
*/
#include "lab.h"

void menu(int &input){
	cout << "Please select how you would like to sort your wines\n";
	cout << "1 - By Rating\n";
	cout << "2 - By Price\n";
	cout << "3 - By Vintage\n";
	cout << "4 - Exit\n";
	cout << "Enter your Choice: ";
	while(!(cin >> input) || input > 4 || input < 1){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error: Please enter a valid Input: ";
	}

}
