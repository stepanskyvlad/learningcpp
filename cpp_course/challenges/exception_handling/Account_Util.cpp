#include <iostream>
#include "Account_Util.h"

// Displays Account objects in a  vector of Account objects 
void display(const std::vector<std::shared_ptr<Account>> &accounts) {
    std::cout << "\n=== Displaying ===========================================" << std::endl;
    for (const auto &acc: accounts) 
        std::cout << *acc << std::endl;
}

// Deposits supplied amount to each Account object in the vector
void deposit(std::vector<std::shared_ptr<Account>> &accounts, double amount) {
    std::cout << "\n=== Depositing =================================" << std::endl;
    for (auto &acc: accounts) {
        try {
            if (acc->deposit(amount)) {
                std::cout << "Deposited " << amount << " to " << *acc << std::endl;
            }
        } catch (const NegativeDepositeException &ex) {
            std::cerr << ex.what() << " -> " << *acc << std::endl;
        }
    }
}

// Withdraw amount from each Account object in the vector
void withdraw(std::vector<std::shared_ptr<Account>> &accounts, double amount) {
    std::cout << "\n=== Withdrawing ==============================" <<std::endl;
    for (auto &acc: accounts)  {
        try {
            if (acc->withdraw(amount)) {
                std::cout << "Withdrew " << amount << " from " << *acc << std::endl;
            }
        } catch (const InsufficentFundsException &ex) {
            std::cerr << ex.what()  << " -> " << *acc << std::endl;
        } catch (const WithdrawalLimitException &ex) {
            std::cerr << ex.what()  << " -> " << *acc << std::endl;
        } catch (const AmountLimitException &ex) {
            std::cerr << ex.what()  << " -> " << *acc << std::endl;
        }
    }
}
