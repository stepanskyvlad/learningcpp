// Declare Classes and Objects
#include <iostream>
#include <string>
#include <vector>

class Player {
    // attributes
    std::string name {"Player"};
    int health {100};
    int xp {3};

    // methods
    void talk(std::string);
    bool is_dead();
};

class Account {
    // attributes
    std::string name {"Account"};
    double balance {0.0};

    // methods
    void deposit(double);
    void withdraw(double);
};

int main() {
    Account frank_account;
    Account jim_account;

    Player frank;
    Player hero;

    Player players[] {frank, hero};

    std::vector<Player> player_vec {frank};
    player_vec.push_back(hero);

    Player *enemy {nullptr};
    enemy = new Player;

    delete enemy;

    return 0;
}