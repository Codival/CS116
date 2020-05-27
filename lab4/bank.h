/*
 *Contains the class Bank
 * @author Amuldeep Dhillon
 * @version 1.0 4/6/2017
 * 
*/
#ifndef BANK_H
#define BANK_H
class Bank
{
public:
   Bank();
   Bank(double checkingAmount, double savingsAmount);
   void printBalances() const;
   void deposit(double amount, std::string account);
   void withdraw(double amount, std::string account);
   void transfer(double amount, std::string account);
   
private:
   Checking checking;
   Saving savings;
};

#endif
