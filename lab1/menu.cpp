/*
 *Purpose:
 *  Displays a menu and takes an input for user to select
 * 
 * @author Amuldeep Dhillon
 * @version 1.0 2/3/2017
 * 
 * @param - none
 * @inputs - 1 2 3 4
 * @outputs - The menu, Error messages, and Good Bye
 * @return - none
*/
#include "lab.h"
using namespace std;
int choice;
void menu(){
do {
	cout << "Choose what you want to do:" << endl;
	cout << "   1 – Convert Second to Hours, Minutes and Seconds" << endl;
	cout << "   2 - Convert Fahrenheit to Celsius:" << endl;
	cout << "   3 - Convert Celsius to Fahrenheit:" << endl;
	cout << "   4 - Quit:" << endl;
	cin >> choice;
	
	while(cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error: Please Pick One Of The Options" << endl;
		cin >> choice;
	}
	
	if(choice == 1)
		{convertTime();}
	
	else if(choice == 2)
		{convertFtoC();}
	
	else if(choice == 3)
		{convertCtoF();}
		
	else if(choice == 4)
		{cout << "Good Bye \n";}
		
	else if(choice != 1 || 2 || 3 || 4)
		{cout << "Error: Please Pick One Of The Options" << endl;}
	
} while (choice != 4);
}

