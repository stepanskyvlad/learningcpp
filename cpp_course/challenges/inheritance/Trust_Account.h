#pragma once
#include "Savings_Account.h"

// 2. Add a Trust account class to the Account hierarchy
//     A Trust account has a name, a balance, and an interest rate
//     The Trust account deposit works just like a savings account deposit.
//     However, any deposits of $5000.00 or more will receive a $50.00 bonus deposited to the account.
    
//     The Trust account withdrawal should only allow 3 withdrawals per year and each of these must be less than 20% of the account balance.
//     You don't have to keep track of calendar time for this application, just make sure the 4th withdrawal fails :)

class Trust_Account: public Savings_Account {
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double big_deposit = 5000.0;
    double bonus = 50.0;
    int withdrawal_counter = 0;
    int max_withdrawal_number = 3;
    double withdrawal_percent_checker = 20;
public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    bool deposit(double amount);
    bool withdraw(double amount);
    bool operator+=(double amount);
    bool operator-=(double amount);
};