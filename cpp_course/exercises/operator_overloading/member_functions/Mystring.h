#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
    Mystring( Mystring &&source);                         // Move constructor
    ~Mystring();                                                     // Destructor
    
    Mystring &operator=(const Mystring &rhs);     // Copy assignment
    Mystring &operator=(Mystring &&rhs);           // Move assignment

    bool operator==(const Mystring &rhs) const;
    bool operator!=(const Mystring &rhs) const;
    bool operator>(const Mystring &rhs) const;
    bool operator<(const Mystring &rhs) const;
    bool operator>=(const Mystring &rhs) const;
    bool operator<=(const Mystring &rhs) const;

    Mystring operator-() const;
    Mystring operator+() const;

    Mystring &operator++();  // pre-increment
    Mystring operator++(int);  // post-increment
    Mystring &operator--();  // pre-decrement
    Mystring operator--(int); // post-decrement

    Mystring operator+(const Mystring &rhs) const;
    Mystring &operator+=(const Mystring &rhs);
    Mystring operator*(const unsigned int num) const;
    Mystring &operator*=(const unsigned int num);

    void display() const;
    // getters
    int get_length() const;                                      
    const char *get_str() const;
};

#endif // _MYSTRING_H_