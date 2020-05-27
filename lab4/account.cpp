#include "lab.h"
#include "account.h"
using namespace std;

/*
 *Purpose:
 * set account balance to zero
 * 
 * @author Amuldeep Dhillon
 * @version 1.0 2/17/2017
 * 
 * @param none
 * @Inputs - none
 * @Outputs - none
 * @return - none
*/
Account::Account(){
	balance = 0;
}

/*
 *Purpose:
 * set account balance to specified amount
 * 
 * @author Amuldeep Dhillon
 * @version 1.0 2/17/2017
 * 
 * @param the amount that balance is set to
 * @Inputs - none
 * @Outputs - none
 * @return - none
*/
Account::Account(double bal){
	balance = bal;
}

/*
 *Purpose:
 * set balance to zero
 * 
 * @author Amuldeep Dhillon
 * @version 1.0 2/17/2017
 * 
 * @param none
 * @Inputs - none
 * @Outputs - none
 * @return - none
*/
void Account::setBalance(){
	balance = 0;
}

/*
 *Purpose:set balance to specified amount
 * 
 * 
 * @author Amuldeep Dhillon
 * @version 1.0 2/17/2017
 * 
 * @param the amount the balance should be
 * @Inputs - none
 * @Outputs - none
 * @return - none
*/
void Account::setBalance(double bal){
	balance = bal;
}

/*
 *Purpose:
 * add a specified value to balance
 * 
 * @author Amuldeep Dhillon
 * @version 1.0 2/17/2017
 * 
 * @param the amount added to balance
 * @Inputs - none
 * @Outputs - none
 * @return - none
*/
void Account::deposit(double amount){
	balance = balance + amount;
}

/*
 *Purpose:
 * remove specified amount from balance
 * 
 * @author Amuldeep Dhillon
 * @version 1.0 2/17/2017
 * 
 * @param the amount to be removed from balance
 * @Inputs - none
 * @Outputs - none
 * @return - none
*/
void Account::withdraw(double amount){
	balance = balance - amount;
}

/*
 *Purpose:
 * return the value of balance
 * 
 * @author Amuldeep Dhillon
 * @version 1.0 2/17/2017
 * 
 * @param none
 * @Inputs - none
 * @Outputs - none
 * @return - the double balance
*/
double Account::getBalance() const{
	return balance;
}
