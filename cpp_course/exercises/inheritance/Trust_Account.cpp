#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account{name, balance, int_rate} {
}

bool Trust_Account::deposit(double amount) {
    if (amount >= big_deposit) {
        amount += bonus;
    }
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
    if (amount > (balance * (withdrawal_percent_checker/100)) || withdrawal_counter >= max_withdrawal_number) {
        return false;
    } else {
        withdrawal_counter += 1;
        return Savings_Account::withdraw(amount);
    }
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}

bool Trust_Account::operator+=(double amount) {
    return Trust_Account::deposit(amount);
}

bool Trust_Account::operator-=(double amount) {
    return Trust_Account::withdraw(amount);
}