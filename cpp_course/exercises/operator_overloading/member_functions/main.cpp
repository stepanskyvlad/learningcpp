// Section 14
// Challenge: member functions
#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    
    cout << boolalpha << endl;
    Mystring a {"frank"};
    Mystring b {"frank"};

    cout << (a==b) << endl; // true
    cout << (a!=b) << endl; // false
    cout << (a>=b) << endl; // true
    cout << (a<=b) << endl; // true
    
    b = "george";
    cout << (a==b) << endl; // false
    cout << (a!=b) << endl; // true
    cout << (a<b) << endl;  // true
    cout << (a<=b) << endl; // true
    cout << (a>b) << endl;  //false
    cout << (a>b) << endl;           // false

    cout << "----------------------" << endl;

    Mystring s1 {"FRANK"};
    s1 = -s1;       
    cout << s1 << endl;               // frank      
    
    s1 = +s1;
    cout << s1 << endl;  // FRANK

    cout << "----------------------" << endl;

    s1 = s1 + "*****";
    cout << s1 << endl;       // frank*****       
    
    s1 += "-----";            // frank*****-----
    cout << s1 << endl;

    Mystring s12 {"Bob"};
    Mystring s13 = s1 + s12;

    cout << s13 << endl;      // FRANK*****-----Bob
    
    Mystring s2{"12345"};
    s1 = s2 * 3;
    cout << s1 << endl;       // 123451234512345
    
    Mystring s3{"abcdef"};  
    s3 *= 5;
    cout << s3 << endl;       // abcdefabcdefabcdefabcdefabcdef

    cout << "----------------------" << endl;
    
    Mystring s = "Frank";
    ++s;
    cout << s << endl;       // FRANK
    
    --s; 
    cout << s << endl;       // frank
    
    Mystring result;
    result = ++s;                           
    cout << s << endl;       // FRANK
    cout << result << endl;  // FRANK
    
    s = "Frank";
    s++;
    cout << s << endl;       // FRANK
    s--;
    cout << s << endl;       //frank
    

    result = s++;
    cout << s << endl;       // FRANK
    cout << result << endl;  // frank

    result = s--;
    cout << s << endl;       // frank
    cout << result << endl;  // FRANK
    
    return 0;
}
