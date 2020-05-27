#ifndef ACCOUNT_H
#define ACCOUNT_H
class Account
{
public:
   Account();
   Account(double bal);
   void deposit(double amount);
   void withdraw(double amount);
   double getBalance() const;
private:
   double balance;
};

#endif
