#include <iostream>

int main () {

    /***********Pointers to constants*******************
     * The data pointed to by the pointers is constant and CANNOT be changed.
     * The pointer itself can change and point somewhere else.
     ***************************************************/

    int high_score1 {100};
    int low_score1 {65};
    const int *score_ptr1 {&high_score1};

    std::cout << high_score1 << std::endl;
    std::cout << low_score1 << std::endl;
    std::cout << "Pointer: " << *score_ptr1 << std::endl;

    // *score_ptr1 = 86;  // error
    score_ptr1 = &low_score1;  // ok

    std::cout << "Changed pointer: " << *score_ptr1 << std::endl;

    /***********Constant pointers************************
     * The data pointed to by the pointers is constant and can be changed.
     * The pointer itself CANNOT change and point somewhere else.
     ***************************************************/

    int high_score2 {100};
    int low_score2 {65};
    int *const score_ptr2 {&high_score2};

    std::cout << high_score2 << std::endl;
    std::cout << low_score2 << std::endl;
    std::cout << "Pointer: " << *score_ptr2 << std::endl;

    *score_ptr2 = 86;  // ok
    // score_ptr2 = &low_score2;  // error

    std::cout << "Changed pointer: " << *score_ptr2 << std::endl;

    /***********Constant pointers to pointers***********
     * The data pointed to by the pointers is constant and can be changed.
     * The pointer itself CANNOT change and point somewhere else.
     ***************************************************/

    int high_score3 {100};
    int low_score3 {65};
    const int *const score_ptr3 {&high_score3};

    std::cout << high_score3 << std::endl;
    std::cout << low_score3 << std::endl;
    std::cout << "Pointer: " << *score_ptr3 << std::endl;

    // *score_ptr3 = 86;  // error
    // score_ptr3 = &low_score3;  // error

    return 0;
}