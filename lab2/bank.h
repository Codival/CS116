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
   Account checking;
   Account savings;
};

#endif
