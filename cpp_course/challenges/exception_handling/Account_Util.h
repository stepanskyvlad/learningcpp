#pragma once
#include <vector>
#include <memory>
#include "Account.h"

// Utility helper functions for Account class

void display(const std::vector<std::shared_ptr<Account>> &accounts);
void deposit(std::vector<std::shared_ptr<Account>> &accounts, double amount);
void withdraw(std::vector<std::shared_ptr<Account>> &accounts, double amount);
