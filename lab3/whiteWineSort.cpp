#include "wine.h"

/*
 * Purpose:display all the White Wines sorted by Price
 * 
 * @author: Amuldeep Dhillon
 * @version: 1.0 3/7/2016
 * 
 * @param:the vector fptr that holds all the wine pointers
 * 
 * 
 * @Outputs:Notice that they are display just the white wines
 * 			display all the white wine's and their information
 * 			the lowest price
 * 			the highest price
 * 			the average price
 * 
 * @return:none
*/


void whiteWineSort(std::vector<Wine*>& test){
	vector<double> Whitewine;
	int count = 0;
	double priceSum = 0;
	double priceAverage = 0;
	sort(test.begin(), test.end());
	std::cout << "\n\nJust White Wine\n";
	printLabels();
	for (unsigned int i=0; i < test.size(); i++)
	{if(test[i]->getWineType() == "White"){
		test[i]->printInfo();
		priceSum = priceSum + test[i]->getPrice();
		Whitewine.push_back(test[i]->getPrice());
		count++;
	}
	}
	sort(Whitewine.begin(), Whitewine.end());
	string lP = std::to_string(Whitewine[0]);
	string hP = std::to_string(Whitewine[Whitewine.size()-1]);
	std::cout << "\nThe Lowest Price is: " << lP << std::endl;
	std::cout << "The Highest Price is: " << hP << std::endl;
	priceAverage = priceSum/count;
	string pA = std::to_string(priceAverage);
	std::cout << "The Average Price is: " << pA <<std::endl;
}

