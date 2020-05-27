#include "wine.h"

/*
 * Purpose:sets the wine's name, type, year, rating, and price manually
 * respective to each parameter
 * 
 * @author: Amuldeep Dhillon
 * @version: 1.0 3/7/2016
 * 
 * @param:wine's name
 * @param:wine's type
 * @param:wine's vintage
 * @param:wine's rating
 * @param:wine's price
 * 
 * @return:none
*/


void Wine::setInfo(string wine_name,string wine_type, int wine_year,
		int wine_rating, double wine_price){
			wineName = wine_name;
			wineType = wine_type;
			wineYear = wine_year;
			wineRating = wine_rating;
			winePrice = wine_price;
}
