/*
 *Purpose:
 *  Convert Fahrenheit to Celsius
 * 
 * @author Amuldeep Dhillon
 * @version 1.0 2/3/2017
 * 
 * @param - none
 * @inptus - A Real Number
 * @outputs - Prompt for Fahrenheit, The conversion, and any Error 
 * 				messages
 * @return - 0
*/
#include "lab.h"
using namespace std;
void convertFtoC(){
	double f;
	double c;
	int rounder;
	cout << "Enter a Value in Fahrenheit:" << endl;
	cin >> f;
	
	while(cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error: Please Enter an Integer" << endl;
		cin >> f;
	}
	
	rounder = ((f - 32) * (5.0/9.0))*100;
	c = rounder / 100.0;
	cout << fixed << setprecision(1) << f << " degrees Fahrenheit " <<
	"is " << c << " degrees Celsius" << endl;
	
	
}

