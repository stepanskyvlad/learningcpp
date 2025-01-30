#include <iostream>
#include <string>

using namespace std;

class Player {
private:
   std::string name;
   int health;
   int xp;
public:
    Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);
};

Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {
    std::cout << "Three-args constructor" << std::endl;
}

int main() {
    Player empty;              // Calls Player("None", 0, 0)
    Player frank {"Frank"};    // Calls Player("Frank", 0, 0)
    Player hero {"Hero", 100}; // Calls Player("Hero", 100, 0)
    Player villain {"Villain", 100, 55}; // Calls Player("Villain", 100, 55)
    
    return 0;
}
