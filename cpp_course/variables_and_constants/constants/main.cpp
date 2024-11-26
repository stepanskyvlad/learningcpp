#include <iostream>
#include <cstdint>

using std::cin;
using std::cout;
using std::endl;


int main() {

    const uint16_t price_small_room {25};
    const uint16_t price_large_room {35};
    const float tax_percent {0.06};
    const uint16_t days {30};

    cout << "Welcome to the cleaning service!" << endl;
    cout << "================================" << endl;

    cout << "Enter the number of small rooms: ";
    uint16_t small_room_count {0};
    cin >> small_room_count;

    cout << "Enter the number of large rooms: ";
    uint16_t large_room_count {0};
    cin >> large_room_count;

    cout << "Price per small room: $" << price_small_room << endl;
    cout << "Price per large room: $" << price_large_room << endl;

    uint16_t cost = price_small_room * small_room_count + price_large_room * large_room_count;
    cout << "Cost: $" << cost << endl;

    float tax = tax_percent * cost;
    cout << "Tax: $" << tax << endl;

    cout << "================================" << endl;
    float total_cost = cost + tax;
    cout << "Total cost: $" << total_cost << endl;
    cout << "This estimate is valid for " << days << " days\n";
 
    return 0;
}