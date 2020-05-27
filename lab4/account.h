/*
 *Contains the class Account (the base class for Checking and Saving
 * @author Amuldeep Dhillon
 * @version 2.0 4/6/2017
 * 
*/
#ifndef ACCOUNT_H
#define ACCOUNT_H
class Account
{
public:
   Account();
   Account(double bal);
   void setBalance();
   void setBalance(double bal);
   void deposit(double amount);
   void withdraw(double amount);
   double getBalance() const;
private:
   double balance;
};

#endif
