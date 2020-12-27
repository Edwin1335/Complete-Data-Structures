#include <iostream>
#include <iomanip>
#include <string>

class Bank
{
protected:
    double balance;
    int numOfDeposMonth;
    int numOfWithdrawl;
    double annInterestrate;
    double monthServiceCharge;

public:
    Bank();
    Bank(double, double);
    virtual void deposit(double depo);
    virtual void withdrawl(double with);
    virtual void calcInt();
    virtual void monthlyProc();
};

Bank::Bank()
{
    this->balance = 0;
    this->annInterestrate = 0;
    this->numOfDeposMonth = 0;
    this->numOfWithdrawl = 0;
}

Bank::Bank(double ba, double anInt)
{
    this->balance = ba;
    this->annInterestrate = anInt;
    this->numOfDeposMonth = 0;
    this->numOfWithdrawl = 0;
}

void Bank::deposit(double dep)
{
    this->balance = this->balance + dep;
    numOfDeposMonth++;
}

void Bank::withdrawl(double with)
{
    this->balance = this->balance - with;
    numOfWithdrawl++;
}

void Bank::calcInt()
{
    double monthlyInterestRate, monthlyInterest;

    monthlyInterestRate = (annInterestrate / 12);
    monthlyInterest = this->balance * monthlyInterestRate;
    this->balance = balance + monthlyInterest;
}

void Bank::monthlyProc()
{
    this->balance = balance - monthServiceCharge;
    this->calcInt();
    numOfWithdrawl = 0;
    numOfDeposMonth = 0;
    monthServiceCharge = 0;
}