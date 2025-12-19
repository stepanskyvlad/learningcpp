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
    if (amount < (balance * (withdrawal_percent_checker/100)) && (Savings_Account::withdraw(amount))) {
        withdrawal_counter += 1;
        return true;
    } else {
        return false;
    }
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}