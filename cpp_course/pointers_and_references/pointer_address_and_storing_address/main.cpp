#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    
    int num{10};
    cout << "Value of num is: " << num << endl;		
    cout << "sizeof of num is: " << sizeof num << endl; 	
    cout << "Address of num is: " << &num << endl;	 	

    int *p;
    cout << "\nValue of p is: " << p << endl;   // garbage
    cout << "Address of p is: " << &p << endl;
    cout << "sizeof of p is: " << sizeof p<< endl;
    
    p = nullptr;
    cout << "\nValue of p is: " << p << endl;


    int *p1 {nullptr};
    double *p2 {nullptr};
    unsigned long long *p3 {nullptr};
    vector<string>  *p4{nullptr};
    string *p5 {nullptr};
    
    cout << "\nsizeof p1 is: " << sizeof p1 << endl;  // 8 (size of address)
    cout << "sizeof p2 is: " << sizeof p2 << endl;  // 8
    cout << "sizeof p3 is: " << sizeof p3 << endl;  // 8
    cout << "sizeof p4 is: " << sizeof p4 << endl;  // 8
    cout << "sizeof p5 is: " << sizeof p5 << endl;  // 8
    
    // double high_temp{100.7};
    int score{10};

    int *score_ptr {nullptr};
    score_ptr = &score;

    cout << "Value of score is: " << score << endl;  // score: 10
    cout << "Address of score is: " << &score << endl;  // address of score
    cout << "Value of score_ptr is: " << score_ptr << endl;  // value of pointer is the address of score (the same as &score)
    cout << "Address of pointer is: " << &score_ptr << endl;  // address of pointer - the address where the address of score saved 
    cout << "Value of the score which pointer points to: " << *score_ptr << endl;  // 10
                                                            // dereferencing: the variable which is saved on the address which pointer points to

    // score_ptr = &high_temp;     // Compiler error. Pointer except ints

    cout  << endl;
    return 0;
}