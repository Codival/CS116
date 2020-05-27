#ifndef WINE_H
#define WINE_H

/*
 * 
 * Function documentations are located at the function definition
 * not their headings
 * 
*/

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  
#include <iomanip>  
#include <ctime>

void printMeFirst(std::string name, std::string courseInfo);

std::string trimWords(const std::string & sentence);

using namespace std;

/*
 * 
 *Class Structure for Address 
 * 
*/

class Address

{
public:

	Address(); 

	Address(string winery_name, string winery_street,

		string winery_city, string winery_state, int winery_zip) ; 

	void setInfo(string winery_name, string winery_street,

		string winery_city, string winery_state,  int winery_zip) ;     

	void setWineryName (string winery_name);

	void setCity (string c); 

	string getCity(); 

private:

	string wineryName, street, city, state;

	int zipCode;

}; 

/*
 * 
 *Class Structure for Wine 
 * 
*/

class Wine

{
public:

/*
 * Purpose: Sets paddress pointer to a new Address
 * 
 * @author: Amuldeep Dhillon
 * @version: 1.0 3/7/2016
 * 
 * @param:none
 * 
 * @return:none
*/
	Wine() {  paddress=new Address();  }

	Wine(string wine_name,string wine_type, int wine_year,

		int wine_rating, double wine_price);

	void setInfo(string wine_name,string wine_type, int wine_year,

		int wine_rating, double wine_price);

/*
 * Purpose: Delete the new Address we originally created
 * 
 * @author: Amuldeep Dhillon
 * @version: 1.0 3/7/2016
 * 
 * @param:none
 * 
 * @return:none
*/

	~Wine() { if (paddress != NULL)

		{delete paddress; paddress = NULL;}  }

		void setAddress(Address a) ; 

		int getRating(); 

		double getPrice();

		string getWineName();

		string getWineType();

		int getYear();

		void printInfo();

/*
 * Purpose:
 * 
 * @author: Amuldeep Dhillon
 * @version: 1.0 3/7/2016
 * 
 * @param:Wine type by reference
 * 
 * @return:
 * true if first wine year is lower than the second's
 * false if first wine year is higher than the second's
*/

		bool operator< (const Wine& p2) const
		  { return this->wineYear < p2.wineYear; }


	private:

		string wineName, wineType;

		int wineYear, wineRating;

		double winePrice;

		Address *paddress;

};

/*
 * Class structure of CompareScore
*/

class CompareScore{
	public:
	
/*
 * Purpose: Compares 
 * 
 * @author: Amuldeep Dhillon
 * @version: 1.0 3/7/2016
 * 
 * @param:Wine pointer
 * @param:Another Wine pointer
 * 
 * @return: 
 * true if the first wine pointer's rating is lower than the second's
 * false if the first wine pointer's rating is higher than the second's
 * 
*/

		bool operator() (Wine *a, Wine *b)
		{
			return a->getRating() < b->getRating();
		}
};

/*
 *Class structure for Compare price 
*/

class ComparePrice{
	public:
/*
 * Purpose:
 * 
 * @author: Amuldeep Dhillon
 * @version: 1.0 3/7/2016
 * 
 * @param:Wine pointer
 * @param:Another wine pointer
 * 
 * @return:
 * true if first wine pointer's price is lower than the second's
 * false if first wine pointer's price is higher than the second's
*/

		bool operator() (Wine *a, Wine *b)
		{
			return a->getPrice() < b->getPrice();
		}
};



void scoreSort(std::vector<Wine*>& test);
void priceSort(std::vector<Wine*>& test);
void redWineSort(std::vector<Wine*>& test);
void whiteWineSort(std::vector<Wine*>& test);
void printLabels();

#endif
