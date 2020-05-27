#include "wine.h"

/*
 * Purpose:sets the wine's address ponter
 * 
 * @author: Amuldeep Dhillon
 * @version: 1.0 3/7/2016
 * 
 * @param:The address of the wine
 *
 * 
 * @return:none
*/


void Wine::setAddress(Address a){
	*paddress = a;
}
