#include "Bank.h"

class Savings : public Bank
{
private:
    bool status;

public:
    Savings();
    Savings(bool stat);
    virtual void deposit(double depo);
    virtual void withdrawl(double with);
    virtual void monthlyProc();
};

Savings::Savings() : Bank::Bank()
{
    status = true;
}

Savings::Savings(bool stat) : Bank::Bank()
{
    status = stat;
}

void Savings::withdrawl(double with)
{
    if (status)
    {
        Bank::withdrawl(with);
    }
    else
    {
        std::cout << "Account is inactive" << std::endl;
    }
}

void Savings::deposit(double depo)
{
    Bank::deposit(depo);

    if (balance >= 25.00)
    {
        status = true;
    }
}

void Savings::monthlyProc()
{
    int withdAbove;
    double totalCharge;

    if(this->numOfWithdrawl > 4)
    {
        withdAbove = this->numOfWithdrawl - 4;
        totalCharge = 1.00 * withdAbove;
        this->monthServiceCharge += totalCharge;
    }

    if(this->balance <= 25.00)
    {
        status = false;
    }
}
