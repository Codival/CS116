#include "wine.h"

/*
 * Purpose:sets the wine name, type, year, rating, price, and address
 * pointer respective to the parameters from the document
 * 
 * @author: Amuldeep Dhillon
 * @version: 1.0 3/7/2016
 * 
 * @param:name of the wine
 * @param:the wine type
 * @param:the vintage of the wine
 * @param:the wine's rating
 * @param:the wine's price
 * 
 * @return:none
*/


Wine::Wine(string wine_name,string wine_type, int wine_year,
		int wine_rating, double wine_price){
			wineName = wine_name;
			wineType = wine_type;
			wineYear = wine_year;
			wineRating = wine_rating;
			winePrice = wine_price;
			paddress= new Address;
}
