// Section 11
// Pass-by-reference

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pass_by_ref1(int &num);
void pass_by_ref2(string &s);
void pass_by_ref3(vector<string> &v);
void print_vector(const vector<string> &v);  // const

void pass_by_ref1(int &num) {
    num = 1000;
}

void pass_by_ref2(string &s) {
    s = "Changed";
}

void pass_by_ref3(vector<string> &v) {
    v.clear();  // delete all vector elements
}

void print_vector( const vector<string> &v)  {
    for (auto s: v) 
        cout << s << " ";
    cout << endl;
}

int main() {
    int num {10};
    int another_num {20};
    
    cout << "num before calling pass_by_ref1: " << num << endl;  // 10
    pass_by_ref1(num);
    cout << "num after calling pass_by_ref1: " << num << endl;  // 1000
    
    cout << "\nanother_num before calling pass_by_ref1: " << another_num << endl;  // 20
    pass_by_ref1(another_num);
    cout << "another_num after calling pass_by_ref1: " << another_num << endl;  // 1000

    string name {"Frank"};

    cout << "\nname before calling pass_by_ref2: " << name << endl;  // Frank 
    pass_by_ref2(name);
    cout << "name after calling pass_by_ref2: " << name << endl;  // Changed

    vector<string> stooges {"Larry", "Moe", "Curly"};

    cout << "\nstooges before calling pass_by_ref3: ";
    print_vector(stooges);  // Larry Moe Curly
    pass_by_ref3(stooges);  // Pass by reference and delete all content in vector
    cout << "stooges after calling pass_by_ref3: ";
    print_vector(stooges);  // Deleted all names in vector
    
    cout << endl;
    return 0;
}

