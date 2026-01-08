#pragma once

class IllegalBalanceException: public std::runtime_error
{
public:
    IllegalBalanceException(double balance)
        : std::runtime_error("You we provided a negative balance: " + std::to_string(balance)) {}
    ~IllegalBalanceException() = default;
};


class NegativeDepositeException: public std::runtime_error
{
public:
    NegativeDepositeException(double amount)
        : std::runtime_error("You we provided a negative deposite: " + std::to_string(amount)) {}
    ~NegativeDepositeException() = default;
};


class InsufficentFundsException: public std::runtime_error
{
public:
    InsufficentFundsException(double amount)
        : std::runtime_error("You'll have a negative balance after withdrawing this amount: " + std::to_string(amount)) {}
    ~InsufficentFundsException() = default;
};


class WithdrawalLimitException: public std::runtime_error
{
public:
    WithdrawalLimitException(int max_withdrawals)
        : std::runtime_error("You've reached withdrawal limit: " + std::to_string(max_withdrawals)) {}
    ~WithdrawalLimitException() = default;
};


class AmountLimitException: public std::runtime_error
{
public:
    AmountLimitException(double amount) 
        : std::runtime_error("The amount is more than 20 percent of the account's balance: " + std::to_string(amount)) {}
    ~AmountLimitException() = default;
};