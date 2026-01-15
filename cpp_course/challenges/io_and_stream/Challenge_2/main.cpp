// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <numeric>

int calc_score(std::string correct_answers, std::string student_answers) {
    int score {0};
    for (size_t i = 0; i < correct_answers.size(); i++) {
        if (correct_answers.at(i) == student_answers.at(i)) {
            score += 1;
        }
    }
    return score;
}

int main() {
    std::ifstream file;
    std::string correct_score;
    std::string student_score;
    std::string student_name;
    std::vector<int> scores {};

    file.open("responses.txt");
    if (!file) {
        std::cerr << "Problem with reading files." << std::endl;
        return 1;
    }
    file >> correct_score;
    std::cout << "Name" << std::setw(36) << "Score" << std::right << std::endl;
    std::cout << std::setfill('-') << std::setw(40) << "" << std::endl;
    std::cout << std::setfill(' ');
    while (file >> student_name >> student_score) {
        scores.push_back(calc_score(correct_score, student_score));
        std::cout << student_name << std::setw(40 - student_name.size()) << calc_score(correct_score, student_score) << std::right << std::endl;
    }
    std::cout << std::setfill('-') << std::setw(40) << "" << std::endl;
    std::cout << std::setfill(' ');
    float average = std::accumulate(scores.begin(), scores.end(), 0.0f) / scores.size();
    std::cout << "Average score" << std::setw(27) << average << std::right << std::endl;


    return 0;
}

