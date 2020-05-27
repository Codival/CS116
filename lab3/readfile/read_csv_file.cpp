// reading a text file
#include <iostream>
#include <sstream>
#include <vector>
#include <string> 
#include <fstream>
#include <algorithm>  // used for vector sort
#include <iomanip>  // output format setw


using namespace std;


const char SPLIT_CHAR = ';';



string trim_words(const string & sentence) {
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


int main(int argc, char* argv[])
{
    string str1, str;
    vector < string > tokens;
	string fname, lname, gender, state;
	int month, day, year;
	string fileName;
	
	
  // use filename if provided in the parameter list
    if (argc < 2)
	{
		cout <<"Usage: " << argv[0] << " input_file\n";
		cout <<"Using default file president_csv.txt instead\n";
		fileName = "person_csv.txt";

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
          str1 = trim_words(s);
          tokens.push_back(str1);
        }
      }
      // now use `tokens`

      for (unsigned int i = 0; i < tokens.size(); i++)
      {
		switch (i)
		{
			case 0: // field #1 from the line
				fname = tokens[0];
				break;
			case 1: // field #2 from the line
				lname = tokens[1];
				break;			
			case 2: 
				gender = tokens[2];
				break;	
			case 3: 
				month = stoi(tokens[3]); // convert field #4  
				break;					 // string month to int	month		
			case 4: 
				day = stoi(tokens[4]);
				break;				
			case 5: 
				year = stoi(tokens[5]);
				break;				
			case 6: 
				state = tokens[i];
				break;			
		}
      }
      cout << endl; 		  
	
      cout << fname << "  " << lname 
          << " " << gender << "   "
          << month << "/" << day << "/" << year
          << " ; State: " << state << endl;
    }
    myfile.close();
  } 
  else 
    cout << "Unable to open file";
    
  

  return 0;
}
