/*
 *Purpose:
 * Execute the entire program
 * 
 * @author Amuldeep Dhillon
 * @version 1.0 2/17/2017
 * 
 * @param none
 * @Inputs - Classes Bank and Account
 * @Outputs- the outputs of each respective program
 * @return - 0
*/
#include "lab.h"
using namespace std;

int main(){
	   
   printMeFirst("Amuldeep Dhillon", "Lab 4 CS-116-02 - 2017 Spring");  // you must call this function 1st
  
   Bank myBank;
   cout << "\nInital bank balances: \n";
   myBank.printBalances();   /* set up empty accounts */

   cout << "\nAdding some money to accounts: \n";
  
   cout << "\nAdding $1000 to saving \n";
   cout << "Adding $2000 to checking \n";
   myBank.deposit(1000, "S");  /* deposit $1000 to savings */
   myBank.deposit(2000, "C");  /* deposit $2000 to checking */
   myBank.printBalances();
 
   cout << "\nTaking out $1500 from checking,and moving $200 from";
   cout << " savings to checking.\n";

   myBank.withdraw(1500, "C"); /* withdraw $1500 from checking */
   myBank.transfer(200, "S");  /* transfer $200 from savings */
   myBank.printBalances();


   cout << "\nTrying to withdraw $900 from Savings.\n";
   myBank.withdraw(900,"S");
   myBank.printBalances();
  
   cout << "\nTrying to withdraw $400 from Checking.\n";
   myBank.withdraw(400,"C");
   myBank.printBalances();
  
  
   return 0;
}
