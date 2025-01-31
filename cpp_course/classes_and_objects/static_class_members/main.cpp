// Static class members
#include <iostream>
#include "Player.h"

using namespace std;

void display_active_players() {
    cout << "Active players: " << Player::get_num_players() << endl;
}

int main() {
    display_active_players();  // 0
    Player hero{"Hero"};
    display_active_players(); // 1
    
    {
        Player frank{"Frank"};
        display_active_players(); // 2
    }  // destructor was called
    display_active_players(); // 1
    
    Player *enemy = new Player("Enemy", 100, 100);
    display_active_players(); // 2
    delete enemy;  // destructor was called
    display_active_players(); // 1



    return 0;
}
