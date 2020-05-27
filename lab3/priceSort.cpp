#include "wine.h"

/*
 * Purpose:sort Wine's that fall within the user entered price range
 * 
 * @author: Amuldeep Dhillon
 * @version: 1.0 3/7/2016
 * 
 * @param: the vector fptr that holds all the wine pointers
 * 
 * @Inputs:Lowest price, Highest price
 * @Outputs:Notice that the price sorting is beginning
 * 			Ask user for price range
 * 			Error message if they do not insert a positive number
 * 			Notice the user if they inserted the range backwards
 * 				and are switching the inputs
 * 			All the wines that fall in the price range with their info
 * 			Number of options
 * 			Average price of all the ranged wine
 * 
 * @return:none
*/


void priceSort(std::vector<Wine*>& test){
	int input1;
	int input2;
	int count = 0;
	double priceSum = 0;
	double priceAverage = 0;
	std::cout << "\n\nBeginning the Price Sorting \n";
	sort(test.begin(), test.end(), ComparePrice());
	std::cout << "Enter a Bottom Price: ";
	std::cin >> input1;
	while(cin.fail() || input1 < 0){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error: Please Enter A Positive Number" << endl;
		cin >> input1;
	}
	std::cout << "Enter a Top Price: ";
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
		if(test[i]->getPrice() >= input1 && test[i]->getPrice() <= input2)
			{test[i]->printInfo(); 
			priceSum = priceSum + test[i]->getPrice();
			count++;}
	}
	priceAverage = (priceSum/count);
	string c = std::to_string(count);
	string pA = std::to_string(priceAverage);
	std::cout << "\nThere are " << c << " options" << std::endl;
	std::cout <<  "The Average price is " << pA << std::endl;
}

