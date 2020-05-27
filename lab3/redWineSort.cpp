#include "wine.h"

/*
 * Purpose:display all the Red Wines sorted by Price
 * 
 * @author: Amuldeep Dhillon
 * @version: 1.0 3/7/2016
 * 
 * @param:the vector fptr that holds all the wine pointers
 * 
 * 
 * @Outputs:Notice that they are display just the red wines
 * 			display all the red wine's and their information
 * 			the lowest price
 * 			the highest price
 * 			the average price
 * 
 * @return:none
*/


void redWineSort(std::vector<Wine*>& test){
	vector<double> Redwine;
	int count = 0;
	double priceSum = 0;
	double priceAverage = 0;
	sort(test.begin(), test.end(), ComparePrice());
	std::cout << "\n\nJust Red Wine\n";
	printLabels();
	for (unsigned int i=0; i < test.size(); i++)
	{if(test[i]->getWineType() == "Red"){
		test[i]->printInfo();
		priceSum = priceSum + test[i]->getPrice();
		Redwine.push_back(test[i]->getPrice());
		count++;
	}
	}
	string lP = std::to_string(Redwine[0]);
	string hP = std::to_string(Redwine[Redwine.size()-1]);
	std::cout << "\nThe Lowest Price is: " << lP << std::endl;
	std::cout << "The Highest Price is: " << hP << std::endl;
	priceAverage = priceSum/count;
	string pA = std::to_string(priceAverage);
	std::cout << "The Average Price is: " << pA <<std::endl;
}
