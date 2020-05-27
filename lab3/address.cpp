
#include "wine.h"

/*
 * Purpose:set addresses city to blank
 * 
 * @author: Amuldeep Dhillon
 * @version: 1.0 3/7/2016
 * 
 * @param:none
 * 
 * @return:none
*/


Address::Address(){
	city = "";
}

/*
 * Purpose:set WineryName, street, city, state, zipcode respectively
 * to the parameters from the document
 * 
 * @author: Amuldeep Dhillon
 * @version: 1.0 3/7/2016
 * 
 * @param:name of the winery
 * @param:name of the winery street
 * @param:name of the winery city
 * @param:name of the winery state
 * @param:the winery's zipcode
 * 
 * 
 * @return:none
*/


Address::Address(string winery_name, string winery_street,
			string winery_city, string winery_state, int winery_zip){

	wineryName = winery_name;
	street = winery_street;
	city = winery_city;
	state = winery_state;
	zipCode = winery_zip;
}
