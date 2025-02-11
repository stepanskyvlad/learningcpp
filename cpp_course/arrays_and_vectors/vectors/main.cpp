#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main() {
    // vector <char> vowels; // empty
    // vector <char> vowels (5);  // 5 initialized to zero
    vector <char> vowels {'a', 'e', 'i', 'o', 'u'};
    // bool isEmpty = vowels.empty(); // check is vector empty

    cout << vowels[0] << endl;
    cout << vowels[4] << endl;

    vector <int> test_scores_all_zeros (3); // 3 elements all initialized to zero
    vector <int> test_scores_all_hundreds (3, 100); // 3 elements all initialized to 100
    vector <uint16_t> test_scores {100, 99, 98};

    cout << "\nTest scores using vector syntax. Bound will be checked" << endl;
    cout << test_scores.at(0) << endl;

    // Change the element in the vector
    test_scores.at(1) = 77;

    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    // To see how many elements there are in the vector
    cout << "There are " << test_scores.size() << " scores in the vector.\n" << endl;

    // Add some elements
    uint16_t fourth_score = 65;
    uint16_t fifth_score = 75;

    test_scores.push_back(fourth_score);
    test_scores.push_back(fifth_score);
    cout << test_scores.at(3) << endl;
    cout << test_scores.at(4) << endl;
    cout << "There are " << test_scores.size() << " scores in the vector.\n" << endl;

    // Example of a 2D-vector

    vector <vector<uint16_t>> movie_ratings
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    cout << "Here are the movie rating for reviewer #1 using array syntax: " << endl;
    cout << movie_ratings[0][0] << endl;
    cout << movie_ratings[0][1] << endl;
    cout << movie_ratings[0][2] << endl;
    cout << movie_ratings[0][3] << endl;

    cout << "Here are the movie rating for reviewer #2 using vector syntax: " << endl;
    cout << movie_ratings.at(1).at(0) << endl;
    cout << movie_ratings.at(1).at(1) << endl;
    cout << movie_ratings.at(1).at(2) << endl;
    cout << movie_ratings.at(1).at(3) << endl;

    return 0;
}