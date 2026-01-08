#include "Checking_Account.h"


Checking_Account::Checking_Account(std::string name, double balance)
    : Account {name, balance} {
    }

bool Checking_Account::withdraw(double amount) {
    amount += withdrawal_fee;
    return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking Account: " << account.name << ": " << account.balance << "]";
    return os;
}

bool Checking_Account::operator-=(double amount) {
    return Checking_Account::withdraw(amount);
}

bool Checking_Account::operator+=(double amount) {
    return Checking_Account::deposit(amount);
}