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
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
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
bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

bool operator!=(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) != 0);
}

bool operator>(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) > 0);
}

bool operator<(const Mystring &lhs, const Mystring &rhs)  {
    return (std::strcmp(lhs.str, rhs.str) < 0);
}

bool operator>=(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) >= 0);
}

bool operator<=(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) <= 0);
}

Mystring operator-(const Mystring &obj) {
    size_t new_size = std::strlen(obj.str) + 1;
    char *buff = new char[new_size];
    std::strcpy(buff, obj.str);
    for (size_t i=0; i<new_size; i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

Mystring operator+(const Mystring &obj) {
    size_t new_size = std::strlen(obj.str) + 1;
    char *buff = new char[new_size];
    std::strcpy(buff, obj.str);
    for (size_t i=0; i < new_size; i++) {
        buff[i] = std::toupper(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// Pre-increment
Mystring &operator++(Mystring &obj)   {
    for (size_t i=0; i < std::strlen(obj.str); i++) {
        obj.str[i] = std::toupper(obj.str[i]);
    }
    return obj;
}
 
// Post-increment: Note that post-increment returns a Mystring by value not by reference
Mystring operator++(Mystring &obj, int) {
    Mystring temp (obj);             
    operator++(obj);                     
    return temp;                       
}

// Pre-decrement
Mystring &operator--(Mystring &obj) {
    for (size_t i=0; i< std::strlen(obj.str); i++) {
        obj.str[i] = std::tolower(obj.str[i]);
    }
    return obj;
}

// Post-decrement
Mystring operator--(Mystring &obj, int) {
    Mystring temp {obj};
    operator--(obj);
    return temp;
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs){
    size_t new_size = std::strlen(lhs.str) + std::strlen(rhs.str) + 1;
    char *buff = new char[new_size];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

Mystring &operator+=(Mystring &lhs, const Mystring &rhs) {
    // lhs = lhs + rhs;
    // return lhs;

    // OR

    size_t new_size = std::strlen(lhs.str) + std::strlen(rhs.str) + 1;
    char *new_str = new char[new_size];
    std::strcpy(new_str, lhs.str);
    std::strcat(new_str, rhs.str);
    delete [] lhs.str;
    lhs.str = new_str;
    // new_str = nullptr; // new_str goes out of scope after the function returns, so nullifying it has no effect.
    return lhs;
}

Mystring operator*(const Mystring &lhs, const unsigned int num) {
    // Mystring temp;
    // for (int i=1; i<=num; i++) {
    //     temp = temp + lhs;
    // }
    // return temp;

    // OR

    size_t new_size = std::strlen(lhs.str) * num + 1;
    char *buff = new char[new_size];
    *buff = '\0';
    // strcpy(buff, ""); 
    for (size_t i=0; i < num; i++) {
        std::strcat(buff, lhs.str);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

Mystring &operator*=(Mystring &lhs, const unsigned int num) {
    // lhs = lhs * num;
    // return lhs;

    // OR

    size_t new_size = std::strlen(lhs.str) * num + 1;
    char *buff = new char[new_size];
    *buff = '\0';  // Initialize buff.
    for (size_t i=0; i < num; i++) {
        std::strcat(buff, lhs.str);
    }
    delete [] lhs.str;
    lhs.str = buff;
    buff = nullptr;
    return lhs;
}
