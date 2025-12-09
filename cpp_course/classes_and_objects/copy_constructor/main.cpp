/***************************************************************************************************
If you do NOT define:
 * Copy Constructor
 * Copy Assignment Operator
 * Destructor
 * Move Constructor
 * Move Assignment Operator
 * 
I do NOT need to provide a copy constructor and destructor -> C++ will generate them automatically.
****************************************************************************************************/

// Always provide copy constructor when your class has raw pointers members and const reference parameters
// or avoid using raw pointer members if possible (use smart pointers)
#include <iostream>
#include <string>

using namespace std;

class Player {
private:
   std::string name;
   int health;
   int xp;
public:
    std::string get_name() {return name;}
    int get_health() {return health;}
    int get_xp() {return xp;}
    // Constructor
    Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);
    // Copy constructor
    Player(const Player &source);
    // Destructor
    ~Player() {cout << "Destructor called for: " << name << endl;}
};

Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {
    std::cout << "Three-args constructor" << std::endl;
}

Player::Player(const Player &source)
    // : name(source.name), health(source.health), xp(source.xp) {
    // delegation copy (we delegate copying process to our constructor)
    : Player {source.name, source.health, source.xp} {
        cout << "Copy constructor - made copy for " + name << endl;
    }

void display_player(Player p) {
    // Player p is a copy of passed Player object to this function
    cout << "Name: " << p.get_name() << endl;
    cout << "Health: " << p.get_health() << endl;
    cout << "XP: " << p.get_xp() << endl;
}

int main() {
    Player empty;              // Calls Player("None", 0, 0)

    display_player(empty);  // copying inside the function

    Player copy_empty {empty};  // copying Player object

    Player frank {"Frank"};    // Calls Player("Frank", 0, 0)
    Player hero {"Hero", 100}; // Calls Player("Hero", 100, 0)
    Player villain {"Villain", 100, 55}; // Calls Player("Villain", 100, 55)
    
    return 0;
}
