/************************************
 * public: accessible everywhere
 * private: accessible only by members of friends of the class
 * protected: used with inheritance
 ***********************************/
// Declare Classes and Objects
#include <iostream>
#include <string>

class Player {
private:
    // attributes
    std::string name {"Player"};
    int health;
    int xp;

public:
    // methods
    void talk(std::string text_to_say) {
        std::cout << name << " says " << text_to_say << std::endl;
    }
    bool is_dead();
};


int main() {
    Player frank;
    // frank.name = "Frank";  // Compiler error - private
    // std::cout << frank.health << std::endl;  // Compiler error - private

    frank.talk("Hello there");

    return 0;
}