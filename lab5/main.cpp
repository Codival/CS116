/*
 *Purpose:starts and calls all other functions
 * 
 * 
 * @author Amuldeep Dhillon
 * @version 1.0 5/6/2017
 * 
 * @param argc - unused
 * @param argv[] - unused
 * @return - none
*/

#include "lab.h"
#include "dbconnect.h"


using namespace std;




/*
 argv[1] - put sql command in argv[1], otherwise, just 
 use sql "show tables"
*/
int main(int argc, char* argv[])
{
	printMeFirst("Amuldeep Dhillon", "Lab 5 - CS116");
	int choice = 0;
	string sqlCommand,countCommand, avgCommand;
  MYSQL *conn;		// the connection
  MYSQL_RES *res;	// the results
  MYSQL_ROW row;	// the results row (line by line)
 
  struct connection_details mysqlD;
  mysqlD.server = (char *)"localhost";  // where the mysql database is
  mysqlD.user = (char *)"root";		// the root user of mysql	
  mysqlD.password = (char *)"password"; // the password of the root user in mysql
  mysqlD.database = (char *)"mysql";	// the databse to pick
 
  // connect to the mysql database
  conn = mysql_connection_setup(mysqlD);
 cout << "Welcome to the Wine Database \n";
 while(choice != 4){
	menu(choice);
	if(choice == 1){
		scoreComparison(sqlCommand,countCommand,avgCommand);
	}
	if(choice == 2){
		priceComparison(sqlCommand,countCommand,avgCommand);
	}
	if(choice == 3){
		vintageComparison(sqlCommand,countCommand,avgCommand);
	}
	if(choice == 4){
		cout << "Good Bye\n";
		break;
	}

  // assign the results return to the MYSQL_RES pointer
  /*
  if (argc < 2)
  {
     cout << "argv[0]: " << argv[0] << endl;
     printf("\nUsage: %s  \"SQL statement here\"\n", argv[0]);
     printf("if no argument given, default is:\n %s show tables\n", argv[0]);
     res = mysql_perform_query(conn, (char *)"show tables");
     printf("MySQL Tables in mysql database:\n");
  }
  * */
  //else
  //{
     // use wine database
     res = mysql_perform_query(conn, (char *)"use wine");
     //cout << "argv[0]: " << argv[0] << endl << endl;
     //cout << "argv[1]: " << argv[1] << endl << endl;
     res = mysql_perform_query(conn, ((char*)(sqlCommand.c_str())));
     /*
      * you need to print out the header.  Make sure it it 
      * nicely formated line up.  Modify the cout statement
      * below so the header is nicely line up.  Hint: use left and setw
      * 
      * WineName   Vitange  Rating  Price  Type
      * */
     cout << left << setw(30) << setfill(' ') << "Wine Name"
                       << setw(15) << setfill(' ') << "Vintage"
						<< setw(15) << setfill(' ') << "Rating"
						<< setw(15) << setfill(' ') << "Price" 
						<< setw(15) << setfill(' ') << "Type"
	 << endl << endl;
  //}
	int i=0;
	Wine w;
	List < Wine > wineList;
  while ((row = mysql_fetch_row(res)) !=NULL)
  { 
      //if (argc < 2) {
      //   printf("%s\n", row[0]);  // only print out 1st column
      //}
      //else
      //{
		  
		  
		 
		  w.setName(row[0]);
		  w.setVintage(stoi(row[1]));
		  w.setRating(stoi(row[2]));
		  w.setPrice(stod(row[3]));
		  w.setType(row[4]);
		  
		  wineList.insertAtBack(w,i);
		  
		  
		  /*
		  // print out each row of the data extracted from
		   // MySQL database
		   // Make sure the output is line up with the header
		   // Hint: use left and setw
		   //

	 cout << left << setw(30) << setfill(' ') << row[0]   // coulumn (field) #1 - Wine Name
	  << setw(15) << setfill(' ') << row[1] // field #2 - Vintage
	  << setw(15) << setfill(' ') << row[2] // field #3 - Rating
	 << setw(15) << setfill(' ') << row[3] // field #4 - Price
	  << setw(15) << setfill(' ') << row[4] // field #5 - Wine type
	  << endl; // field #7 - UPC
	  */
      //}
       
      
  }
  printNoteInfo(wineList);
  cout << "\nTotal Number of Wines is: ";
  res = mysql_perform_query(conn, ((char*)(countCommand.c_str())));
  row = mysql_fetch_row(res);
  cout << row[0] << endl;
  
  mysql_free_result(res);
  cout << "Average Price of Wines is: ";
  res = mysql_perform_query(conn, ((char*)(avgCommand.c_str())));
  row = mysql_fetch_row(res);
  cout << row[0] << endl << endl;
  
  mysql_free_result(res);
}

  /* clean up the database link */
  mysql_close(conn);

  return 0;
}
