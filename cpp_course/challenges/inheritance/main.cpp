// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Trust_Account.h"
#include "Checking_Account.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
   
    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000} );
    accounts.push_back(Account {"Curly", 5000} );
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts,2000);
    
    // Savings 
    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account {} );
    sav_accounts.push_back(Savings_Account {"Superman"} );
    sav_accounts.push_back(Savings_Account {"Batman", 2000} );
    sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);

    // Checking Accounts
    vector<Checking_Account> check_accounts;
    check_accounts.push_back(Checking_Account {});
    check_accounts.push_back(Checking_Account {"Trust Larry"});
    check_accounts.push_back(Checking_Account {"Trust Moe", 2000} );
    check_accounts.push_back(Checking_Account {"Trust Curly", 5000} );
    
    display(check_accounts);
    deposit(check_accounts, 1000);
    for (int i=0; i < 5; i++) {
        withdraw(check_accounts, 500);
    }

    // Trust
    vector<Trust_Account> trust_accounts;
    trust_accounts.push_back(Trust_Account {} );
    trust_accounts.push_back(Trust_Account {"Superman"} );
    trust_accounts.push_back(Trust_Account {"Batman", 2000} );
    trust_accounts.push_back(Trust_Account {"Wonderwoman", 5000, 5.0} );

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    deposit(trust_accounts, 5000);
    deposit(trust_accounts, 6000);
    for (int i=0; i < 5; i++ ) {
        withdraw(trust_accounts, 2000);
    }

    display(check_accounts);
    deposit_operator(check_accounts, 1000);
    withdraw_operator(check_accounts, 500);

    return 0;
}

