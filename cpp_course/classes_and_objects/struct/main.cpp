#include <iostream>
#include <string>

// ✅ Define a simple struct
struct Player {
    std::string name;
    int health;
    int xp;
};

// ✅ Function that takes a struct by reference (efficient, avoids copy)
void display_player(const Player& p) {
    std::cout << "Player: " << p.name << ", Health: " << p.health << ", XP: " << p.xp << "\n";
}

int main() {
    // ✅ Declare and initialize a struct
    Player player1 {"Alice", 100, 10};  

    // ✅ Access struct members
    std::cout << "Player: " << player1.name << "\n";
    std::cout << "Health: " << player1.health << "\n";
    std::cout << "XP: " << player1.xp << "\n";

    display_player(player1);  // ✅ Pass by reference (no extra copy)


    return 0;
}
