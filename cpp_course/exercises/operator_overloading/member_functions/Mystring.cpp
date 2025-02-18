#include <iostream>
#include <cstring>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
        // std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
        // std::cout << "Move constructor used" << std::endl;
}

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

//-----------------------------------------------------
// My operator overloading
//-----------------------------------------------------
bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

bool Mystring::operator!=(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) != 0);
}

bool Mystring::operator>(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) > 0);
}

bool Mystring::operator<(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) < 0);
}

bool Mystring::operator>=(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) >= 0);
}

bool Mystring::operator<=(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) <= 0);
}

Mystring Mystring::operator-() const {
    size_t new_size = std::strlen(str) + 1;
    char *buff = new char[new_size];
    std::strcpy(buff, str);
    for (size_t i=0; i<new_size; i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

Mystring Mystring::operator+() const {
    size_t new_size = std::strlen(str) + 1;
    char *buff = new char[new_size];
    std::strcpy(buff, str);
    for (size_t i=0; i < new_size; i++) {
        buff[i] = std::toupper(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// Pre-increment
Mystring &Mystring::operator++()   {
    for (size_t i=0; i < std::strlen(str); i++) {
        str[i] = std::toupper(str[i]);
    }
    return *this;
}
 
// Post-increment: Note that post-increment returns a Mystring by value not by reference
Mystring Mystring::operator++(int) {
    Mystring temp (*this);             // make a copy
    operator++();                      // call pre-increment - make sure you call pre-increment!
    return temp;                       // return the old value
}

// Pre-decrement
Mystring &Mystring::operator--() {
    for (size_t i=0; i< std::strlen(str); i++) {
        str[i] = std::tolower(str[i]);
    }
    return *this;
}

// Post-decrement
Mystring Mystring::operator--(int) {
    Mystring temp {*this};
    operator--();
    return temp;
}

Mystring Mystring::operator+(const Mystring &rhs) const {
    size_t new_size = std::strlen(str) + std::strlen(rhs.str) + 1;
    char *buff = new char[new_size];
    std::strcpy(buff, str);  // Initialize new_str
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

Mystring &Mystring::operator+=(const Mystring &rhs) {
    // *this = *this + rhs;
    // return *this;

    size_t new_size = std::strlen(str) + std::strlen(rhs.str) + 1;
    char *new_str = new char[new_size];
    std::strcpy(new_str, str);  // Initialize new_str
    std::strcat(new_str, rhs.str);
    delete [] str;  // Free old memory
    str = new_str;  // Simply reassign the pointer. Now str and new_str point to the same memory location
    new_str = nullptr;  // Properly nullify source pointer. Now Only `str` points to new
    return *this;

    // -------------------------------------------------------------
    // We don't need allocate memory for `str` and make copy
    //--------------------------------------------------------------
    // size_t new_size = std::strlen(str) + std::strlen(rhs.str) + 1;
    // char *buff = new char[new_size];
    // std::strcpy(buff, str);
    // std::strcat(buff, rhs.str);
    // delete [] str;
    // -------------------------------------------------------------
    // str = new char[std::strlen(buff) + 1]; // ❌ Unnecessary reallocation
    // std::strcpy(str, buff);
    // delete [] buff;
    // -------------------------------------------------------------
    // return *this;

}

Mystring Mystring::operator*(const unsigned int num) const {
    // Mystring temp;
    // for (int i=1; i<=num; i++) {
    //     temp = temp + *this;
    // }
    // return temp;

    size_t new_size = std::strlen(str) * num + 1;
    char *buff = new char[new_size];  // ❌ Memory is uninitialized. There is garbage data
    *buff = '\0';  // Initialize buff. Assigning '\0' ensures `buff` is an empty C-string.
    // strcpy(buff, ""); // or initialize it this way. The whole buff will empty string.
    for (size_t i=0; i < num; i++) {
        std::strcat(buff, str);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

Mystring &Mystring::operator*=(const unsigned int num) {
    // *this = *this * num;
    // return *this;

    size_t new_size = std::strlen(str) * num + 1;
    char *buff = new char[new_size];
    *buff = '\0';  // Initialize buff.
    for (size_t i=0; i < num; i++) {
        std::strcat(buff, str);
    }
    delete [] str;
    str = buff;
    buff = nullptr;
    return *this;
}
