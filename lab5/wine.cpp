/*
 * Purpose:sets the wine's name, type, year, rating, and price manually
 * respective to each parameter at the constructor level
 * 
 * @author: Amuldeep Dhillon
 * @version: 1.0 3/7/2016
 * 
 * @param wine's name: The name you want the wine to have
 * @param wine's type: The type you want the wine to have
 * @param wine's vintage: The vintage you want the wine to have
 * @param wine's rating: The rating you want the wine to have
 * @param wine's price: The price you want the wine to have
 * 
 * @return:none
*/
#include "lab.h"

Wine::Wine(string wine_name,string wine_type, int wine_year,
		int wine_rating, double wine_price){
			wineName = wine_name;
			wineType = wine_type;
			wineYear = wine_year;
			wineRating = wine_rating;
			winePrice = wine_price;
}
