/*
 *Purpose:Takes a lower and upper bound for scores and creates the MySQL command
 * 		  to retrieve data, the number of data pieces, and average price
 * 
 * 
 * @author Amuldeep Dhillon
 * @version 1.0 5/6/2017
 * 
 * @param command - the string for the SQL command to find the data
 * @param count - the string for the SQL command to count the data
 * @param average - the string for the SQL command to average the prices
 * @return - none
*/
#include "lab.h"

void scoreComparison(string & command,string & count,string & average){
	int bottom, top, temp;
	cout << "Please enter a Bottom Rating Value: " << endl;
	while(!(cin >> bottom) || bottom < 0 || bottom > 100){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error: Please enter a valid Input: ";
	}
	cout << "Please enter a Top Rating Value: " << endl;
	while(!(cin>>top) || top < 0 || top > 100){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error: Please enter a valid Input: ";
	}
	if(bottom > top){
		cout << "Bottom is greater than Top, switching values\n";
		temp = top;
		top = bottom;
		bottom = temp;
	}
	
	string part1 = "select name, vintage, score, price, type from wineInfo where score >= ";
	string part2 = " and score <= ";
	string part3 = " order by score,price";
	stringstream convert;
	convert << part1 << bottom << part2 << top << part3;
	command = convert.str();
	
	string part4 = "select count(name) from wineInfo where score >= ";
	string part5 = " and score <= ";
	stringstream counter;
	counter << part4 << bottom << part5 << top;
	count = counter.str();
	
	string part6 = "select round(avg(price),2) from wineInfo where score >= ";
	string part7 = " and score <= ";
	stringstream averager;
	averager << part6 << bottom << part7 << top;
	average = averager.str();
}
