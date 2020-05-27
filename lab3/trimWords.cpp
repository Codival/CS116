/*
 * Purpose: Remove the empyt white spaces between data elements
 * 
 * @author: Amuldeep Dhillon
 * @version: 1.0 3/7/2016
 * 
 * @param: string of data from the document
 * 
 * 
 * @return:the data element put in without space "string"
*/


#include "wine.h"

using namespace std;

string trimWords(const string & sentence) {
  stringstream ss;
  string s;
  string out;
    
  ss << sentence;
  while (ss >> s) 
  {
    out += (s + ' ');
  }
  return out.substr(0, out.length() - 1);
}
