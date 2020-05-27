/*
 *Purpose:
 *  Convert Seconds into Hours, Minutes, and Seconds
 * 
 * @author Amuldeep Dhillon
 * @version 1.0 2/3/2017
 * 
 * @param - none
 * @inputs - a positive integer
 * @outputs - Prompt for number of seconds, the conversions
 * 				and any error messages
 * @return - none
*/
#include "lab.h"
using namespace std;
void convertTime(){
	int time1;
	int time2;
	int hours;
	int minutes;
	int seconds;
	cout << "Please enter the amount of Time in Seconds:" << endl;
	cin >> time1;
	
	while(cin.fail() || time1 < 0){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error: Please Enter a Positive Integer" << endl;
		cin >> time1;
	}
	
	hours = time1/3600;
	time2 = time1 - (hours * 3600);
	minutes = time2/60;
	seconds = time2 - (minutes * 60);
	cout << time1 << " Seconds is " << hours << " Hours, " << minutes 
	<< " Minutes, and " << seconds << " Seconds!" << endl;
}
