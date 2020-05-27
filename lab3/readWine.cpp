#include "wine.h"


using namespace std;

const char SPLIT_CHAR = ';';

/*
 * Purpose: Sort the Document info into a newly
 * made vector, sort and print wines in order of both price and rating
 *  and execute other functions
 * 
 * @author: Amuldeep Dhillon
 * @version: 1.0 3/7/2016
 * 
 * @param:Wine Document
 * 
 * @Outputs: Labels to tell user when each program is beginning
 * 
 * @return:0
*/

int main(int argc, char* argv[])
{
	printMeFirst("Amuldeep Dhillon", "Lab 3: CS 116-02 Thursdays");
    string str1, str;
    vector < string > tokens;
	string wineName, type, wineryName, address, city, state;
	int vintage, rating, zipcode;
	double price;
	string fileName;
	
	vector<Wine*> fptr;
	
	Wine *f1;
	
	Address addressDetails;
	
  // use filename if provided in the parameter list
    if (argc < 2)
	{
		cout <<"Usage: " << argv[0] << " input_file\n";
		cout <<"Using default file winelist.txt instead\n";
		fileName = "winelist.txt";

	}
	else 
		fileName = argv[1];
			
                               
  ifstream myfile (fileName.c_str()); // open the file
 

  if (myfile.is_open()) {
    while (myfile) {
      if (!getline(myfile, str))
        break; //end of file

      istringstream split(str);
      //  for (string each; getline(split, each, split_char); tokens.push_back(each));
      // OR USE THE WHILE LOOP BELOW
      vector <string> tokens;
      while (split) // parse the line
      {
        string s;
        if (!getline(split, s, SPLIT_CHAR))
          break; // end of line
        else 
        {
          str1 = trimWords(s);
          tokens.push_back(str1);
        }
      }
      // now use `tokens`

      for (unsigned int i = 0; i < tokens.size(); i++)
      {
		switch (i)
		{
			case 0: 
				wineName = tokens[0];
				break;
			case 1: 
				type= tokens[1];
				break;			
			case 2: 
				vintage = stoi(tokens[2]);
				break;	
			case 3: 
				rating = stoi(tokens[3]); 
				break;					 
			case 4: 
				price= stod(tokens[4]);
				break;				
			case 5: 
				wineryName = tokens[5];
				break;				
			case 6: 
				address = tokens[6];
				break;			
			case 7: 
				city = tokens[7];
				break;			
			case 8: 
				state = tokens[8];
				break;			
			case 9: 
				zipcode = stoi(tokens[i]);
				break;			
		}
      }

		f1 = new Wine(wineName,type,vintage,rating,price);
		addressDetails.setCity(city);
		f1->setAddress(addressDetails);
		fptr.push_back(f1);

    }
	scoreSort(fptr);
	priceSort(fptr);
	std::cout << "\nRanking Based On Price\n" << std::endl;
	printLabels();
	sort(fptr.begin(), fptr.end(), ComparePrice());
	for (unsigned int i=0; i < fptr.size(); i++)
	{
		fptr[i]->printInfo();
	}
	std::cout << "\nRanking Based On Rating\n" << std::endl;
	printLabels();
	sort(fptr.begin(), fptr.end(), CompareScore());
	for (unsigned int i=0; i < fptr.size(); i++)
	{
		fptr[i]->printInfo();
	}
	redWineSort(fptr);
	whiteWineSort(fptr);
    myfile.close();
  } 
  else 
    cout << "Unable to open file";
    
  

  return 0;
}
