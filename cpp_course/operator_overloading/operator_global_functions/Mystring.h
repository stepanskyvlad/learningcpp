#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    // non-member (global) friend functions
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);      // compare
    friend Mystring operator-(const Mystring&obj);                         // unary operator (my_string-): make lowercase
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);   // binary operator (str1 + str2): concatenate
private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                               // No-args constructor
    Mystring(const char *s);                  // Overloaded constructor              
    Mystring(const Mystring &source);         // Copy constructor
    Mystring(Mystring &&source);              // Move constructor
    ~Mystring();                              // Destructor

    Mystring &operator=(const Mystring &rhs); // Copy assignment
    Mystring &operator=(Mystring &&rhs);      // Move assignment

    void display() const;
    // getters
    int get_length() const;
    const char *get_str() const;
  
};

#endif // _MYSTRING_H_