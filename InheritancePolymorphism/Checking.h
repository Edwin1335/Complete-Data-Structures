#include "Bank.h"

class Checkings : Bank
{
public:
    Checkings();
    virtual void withdrawl(double with);
    virtual void monthlyProc();
};

Checkings::Checkings() : Bank::Bank()
{
}

void Checkings::withdrawl(double with)
{
    double remainingBalance = this->balance - with;
    if (remainingBalance > 0)
    {
        Bank::withdrawl(with);
    }
    else if (remainingBalance <= 0)
    {
        monthServiceCharge + 15.00;
    }
}

void Checkings::monthlyProc()
{
    double monthlyFee = 5.00 + (.10 * this->numOfWithdrawl);
    Bank::monthlyProc();
}
