/*
 *Purpose:
 *  Convert Celsius to Fahrenheit
 * 
 * @author Amuldeep Dhillon
 * @version 1.0 2/3/2017
 * 
 * @param - none
 * @inptus - A Real Number
 * @outputs - Prompt for Celsius, The conversion, and any Error 
 * 				messages
 * @return - 0
*/
#include "lab.h"
using namespace std;
void convertCtoF(){
	double f;
	double c;
	int rounder;
	cout << "Enter a Value in Celsius:" << endl;
	cin >> c;
	
	while(cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error: Please Enter an Integer" << endl;
		cin >> c;
	}
	
	rounder = ((c * (9.0/5.0)) + 32)*100;
	f = rounder / 100.0;
	cout << fixed << setprecision(1) << c << " degrees Celsius " <<
	"is " << f << " degrees Fahrenheit" << endl;
}
