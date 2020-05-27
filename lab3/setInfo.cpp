#include "wine.h"

/*
 * Purpose:set wineryName, street, city, state, and zipcode manually
 * by each respective parameter
 * 
 * @author: Amuldeep Dhillon
 * @version: 1.0 3/7/2016
 * 
 * @param:name of the Winery
 * @param:name of the Winery street
 * @param:name of the Winery city
 * @param:name of the Winery state
 * @param:Winery zipcode
 * 
 * 
 * @return:none
*/


void Address::setInfo(string winery_name, string winery_street,
			string winery_city, string winery_state,  int winery_zip){

	wineryName = winery_name;
	street = winery_street;
	city = winery_city;
	state = winery_state;
	zipCode = winery_zip;
}
