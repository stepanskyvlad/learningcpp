#include <iostream>
#include <memory>
#include <vector>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

int main() {
    std::cout.precision(2);
    std::cout << std::fixed;
    
    // Savings 

    std::shared_ptr<Account> sav_acc1 = std::make_shared<Savings_Account>();
    std::shared_ptr<Account> sav_acc2 = std::make_shared<Savings_Account>("Superman");
    std::shared_ptr<Account> sav_acc3 = std::make_shared<Savings_Account>("Batman", 2000);
    std::shared_ptr<Account> sav_acc4 = std::make_shared<Savings_Account>("Wonderwoman", 5000, 5.0);
    std::vector<std::shared_ptr<Account>> sav_accounts {sav_acc1, sav_acc2, sav_acc3, sav_acc4};

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);
   
    // Checking

    std::shared_ptr<Account> check_acc1 = std::make_shared<Checking_Account>();
    std::shared_ptr<Account> check_acc2 = std::make_shared<Checking_Account>("Kirk");
    std::shared_ptr<Account> check_acc3 = std::make_shared<Checking_Account>("Spock", 2000);
    std::shared_ptr<Account> check_acc4 = std::make_shared<Checking_Account>("Bones", 5000);
    std::vector<std::shared_ptr<Account>> check_accounts {check_acc1, check_acc2, check_acc3, check_acc4};

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    // Trust

    std::shared_ptr<Account> trust_acc1 = std::make_shared<Trust_Account>();
    std::shared_ptr<Account> trust_acc2 = std::make_shared<Trust_Account>("Athos", 10000, 5.0);
    std::shared_ptr<Account> trust_acc3 = std::make_shared<Trust_Account>("Porthos", 20000, 4.0);
    std::shared_ptr<Account> trust_acc4 = std::make_shared<Trust_Account>("Aramis", 30000);
    std::vector<std::shared_ptr<Account>> trust_accounts {trust_acc1, trust_acc2, trust_acc3, trust_acc4};

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);
    
    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    for (int i=1; i<=5; i++)
        withdraw(trust_accounts, 1000);

    for (int i=1; i<=2; i++)
        deposit(check_accounts, -1000);

    try {
        std::shared_ptr<Account> sav_acc5 = std::make_shared<Savings_Account>("Batman", -2000);
    } catch (const IllegalBalanceException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    
    std::cout << "\n === Finish ==== " << std::endl;

    return 0;
}

