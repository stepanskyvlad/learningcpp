// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std; 

int main() {
    cout.precision(2);
    cout << fixed;
   
    // Accounts
    // vector<Account> accounts;
    // accounts.push_back(Account {});
    // accounts.push_back(Account {"Larry"});
    // accounts.push_back(Account {"Moe", 2000} );
    // accounts.push_back(Account {"Curly", 5000} );
    
    // display(accounts);
    // deposit(accounts, 1000);
    // withdraw(accounts,2000);
    
    // Savings 

    Account *sav_acc1 = new Savings_Account {};
    Account *sav_acc2 = new Savings_Account {"Superman"};
    Account *sav_acc3 = new Savings_Account {"Batman", 2000};
    Account *sav_acc4 = new Savings_Account {"Wonderwoman", 5000, 5.0};
    vector<Account *> sav_accounts {sav_acc1, sav_acc2, sav_acc3, sav_acc4};

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts,2000);
   
    // Checking


    Account *check_acc1 = new Checking_Account {};
    Account *check_acc2 = new Checking_Account {"Kirk"};
    Account *check_acc3 = new Checking_Account {"Spock", 2000};
    Account *check_acc4 = new Checking_Account {"Bones", 5000};
    vector<Account *> check_accounts {check_acc1, check_acc2, check_acc3, check_acc4};

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    // Trust
  
    Account *trust_acc1 = new Trust_Account {};
    Account *trust_acc2 = new Trust_Account {"Athos", 10000, 5.0};
    Account *trust_acc3 = new Trust_Account {"Porthos", 20000, 4.0};
    Account *trust_acc4 = new Trust_Account {"Aramis", 30000};
    vector<Account *> trust_accounts {trust_acc1, trust_acc2, trust_acc3, trust_acc4};

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);
    
    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    for (int i=1; i<=5; i++)
        withdraw(trust_accounts, 1000);
    
    std::cout << "\n === Clean up ==== " << std::endl;
    delete sav_acc1;
    delete sav_acc2;
    delete sav_acc3;
    delete sav_acc4;

    delete check_acc1;
    delete check_acc2;
    delete check_acc3;
    delete check_acc4;

    delete trust_acc1;
    delete trust_acc2;
    delete trust_acc3;
    delete trust_acc4;

    return 0;
}

