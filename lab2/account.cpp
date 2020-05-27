/*
 *Purpose:
 * Set Account balances to zero or specified amount
 * Subtract withdrawals
 * Add deposits
 * 
 * @author Amuldeep Dhillon
 * @version 1.0 2/17/2017
 * 
 * @param none
 * @Inputs - balances, withdrawls, deposits
 * @Outputs - balances
 * @return - Balances
*/
#include "lab.h"
#include "account.h"
using namespace std;

Account::Account(){
	balance = 0;
}

Account::Account(double bal){
	balance = bal;
}

void Account::deposit(double amount){
	balance = balance + amount;
}

void Account::withdraw(double amount){
	balance = balance - amount;
}

double Account::getBalance() const{
	return balance;
}
