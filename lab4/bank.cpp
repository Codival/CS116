
#include "lab.h"
#include "bank.h"
using namespace std;

/*
 *Purpose:
 * set Bank Account balances to zero
 *  
 * @author Amuldeep Dhillon
 * @version 2.0 4/6/2017
 * 
 * @param - none
 * @Inputs - none
 * @Outputs - none
 * @return - none
*/
Bank::Bank(){
	checking.setBalance();
	savings.setBalance();
}


/*
 *Purpose:
 * set Bank Account balances to a specified amounts
 *  
 * @author Amuldeep Dhillon
 * @version 2.0 4/6/2017
 * 
 * @param - checkingAmount, savingAmount
 * @Inputs - none
 * @Outputs - none
 * @return - none
*/
Bank::Bank (double checkingAmount,double savingAmount){
	checking.setBalance(checkingAmount);
	savings.setBalance(savingAmount);
}


/*
 *Purpose:
 * shows the bank account balances
 *  
 * @author Amuldeep Dhillon
 * @version 2.0 4/6/2017
 * 
 * @param - none
 * @Inputs - none
 * @Outputs - The amount in both accounts
 * @return - none
*/
void Bank::printBalances() const{
	cout << "Savings Account Balance: $" << fixed << setprecision(2) << savings.getBalance() << endl;
	cout << "Checking Account Balance: $" << fixed << setprecision(2) << checking.getBalance() << endl;
}

/*
 *Purpose:
 * Adds money to either checking or saving accounts
 *  
 * @author Amuldeep Dhillon
 * @version 2.0 4/6/2017
 * 
 * @param - the amount to deposit, which account
 * @Inputs - none
 * @Outputs - none
 * @return - none
*/
void Bank::deposit(double amount,string account){
	if(account == "C"){
		checking.deposit(amount);}
	else{
		savings.deposit(amount);
	}
}

/*
 *Purpose:
 * removes the specified amount from a specified account
 * checks to see if user actaully has the money to withdraw
 * charges 5 dollars if they don't
 *  
 * @author Amuldeep Dhillon
 * @version 2.0 4/6/2017
 * 
 * @param - amount to withdraw and from which account
 * @Inputs - none
 * @Outputs - Message telling user they don't own that amount
 * and that they have been charged a penalty.
 * @return - none
*/
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

/*
 *Purpose:
 * sends money from one account to another
 *  
 * @author Amuldeep Dhillon
 * @version 2.0 4/6/2017
 * 
 * @param - amount to transfer and from which account to remove
 * @Inputs - none
 * @Outputs - message telling user they do not own that amount
 * and that they have been charged a penalty
 * @return - none
*/
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
		

