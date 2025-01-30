// Constructor Initialization Lists
// Delegating Constructors
#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
   std::string name;
   int health;
   int xp;
public:
// Overloaded Constructors
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};


Player::Player() 
// Delegating Constructor
    : Player{"None", 0, 0} {
        std::cout << "No-args constructor" << std::endl;
}

Player::Player(std::string name_val) 
// Delegating Constructors
   : Player{name_val, 0, 0} {
        std::cout << "One-arg constructor" << std::endl;

}

// Constructor Initialization Lists
Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {
        std::cout << "Three-args constructor" << std::endl;
}

int main() {
    
    Player empty;
    Player frank {"Frank"};
    Player villain {"Villain", 100, 55};
    
    return 0;
}
