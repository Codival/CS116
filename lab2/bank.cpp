/*
 *Purpose:
 * set Bank Account balances to zero or specified amounts
 * Print the balances
 * Add money into accounts
 * Remove money from the accounts
 * Transfer money from one account to another
 *  
 * @author Amuldeep Dhillon
 * @version 1.0 2/17/2017
 * 
 * @param - checkingAmount, savingAmount, amount, account
 * @Inputs - Money amount, account types
 * @Outputs - Balances
 * @return - Balances
*/
#include "lab.h"
#include "bank.h"
using namespace std;

Bank::Bank(){
	checking = Account();
	savings = Account();
}

Bank::Bank (double checkingAmount,double savingAmount){
	checking = Account(checkingAmount);
	savings = Account(savingAmount);
}

void Bank::printBalances() const{
	cout << "Savings Account Balance: $" << fixed << setprecision(2) << savings.getBalance() << endl;
	cout << "Checking Account Balance: $" << fixed << setprecision(2) << checking.getBalance() << endl;
}

void Bank::deposit(double amount,string account){
	if(account == "C"){
		checking.deposit(amount);}
	else{
		savings.deposit(amount);
	}
}

void Bank::withdraw(double amount, string account){
	if(account == "C"){
		if(amount > checking.getBalance()){
			cout << "Only $" << checking.getBalance() << " are available. "
			<< "But tring to withdraw $" << amount << ". Deduct $5 from account";
			checking.withdraw(penalty);}
		else{
			checking.withdraw(amount);} 
		}
	else{
		if(amount > savings.getBalance()){
			cout << "Only $" << checking.getBalance() << " are available, "
			<< "but tring to withdraw $" << amount << ". Deduct $5 from account\n";
			savings.withdraw(penalty);}
		else{
			savings.withdraw(amount);}
	}
}
		
void Bank::transfer(double amount, string account){
	if(account == "C"){
		if(checking.getBalance() >= amount){
			checking.withdraw(amount);
			savings.deposit(amount);
		}
		else{
			checking.withdraw(penalty);}
		}
		if(savings.getBalance() >= amount){
			savings.withdraw(amount);
			checking.deposit(amount);
		}
		else{
			savings.withdraw(penalty);}
}	
		

