#include "wine.h"

/*
 * Purpose:display all the wine's within an enter rating range
 * 
 * @author: Amuldeep Dhillon
 * @version: 1.0 3/7/2016
 * 
 * @param:the vector fptr, that holds all the wine pointers, from main
 * 
 * @Inputs: Bottom rating, Top rating
 * @Outputs:
 * 			Notice that score sorting has begun
 * 			ask user for score range lowest then highest
 * 			Error message if they do not insert a positive number
 * 			Notice that they have inserted the numbers back ward and
 * 				flip them
 * 			All the wine in the range
 * 			Number of options
 * 			Average price of the wine
 * 
 * @return:none
*/


void scoreSort(std::vector<Wine*>& test){
	int input1;
	int input2;
	int count = 0;
	double priceSum = 0;
	double priceAverage = 0;
	std::cout << "Beginning the Score Sorting \n";
	sort(test.begin(), test.end(), CompareScore());
	std::cout << "Enter a Bottom Score: ";
	std::cin >> input1;
	while(cin.fail() || input1 < 0){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error: Please Enter A Positive Number" << endl;
		cin >> input1;
	}
	std::cout << "Enter a Top Score: ";
	std::cin >> input2;
	while(cin.fail() || input2 < 0){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error: Please Enter A Positive Number" << endl;
		cin >> input2;
	}
	if(input1 > input2){
		std::cout << "You have entered the numbers backwards, We are "
		<< "switching the inputs";
		int temp = input2;
		input2 = input1;
		input1 = temp;
	}
	printLabels();
	for (unsigned int i=0; i < test.size(); i++)
	{
		if(test[i]->getRating() >= input1 && test[i]->getRating() <= input2)
			{test[i]->printInfo(); 
			priceSum = priceSum + test[i]->getPrice();
			count++;}
	}
	priceAverage = (priceSum/count);
	string c = std::to_string(count);
	string pA = std::to_string(priceAverage);
	std::cout << fixed << setprecision(2) << "\nThere are " << c << " options" << std::endl;
	std::cout <<  "The Average price is " << pA << std::endl;
}
