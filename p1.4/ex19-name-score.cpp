#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::cout << "Enter name and int pairs, end with 'NoName' and '0'.\n";
    std::vector<std::string> names;
    std::vector<int> scores;
    while (true) {
        std::string name;
        int score;
        std::cin >> name >> score;
        if (name == "NoName" && score == 0) {
            break;
        } else {
            for (std::string stored_name: names) {
                if (name == stored_name) {
                    std::cout << "Names must be unique, exiting\n";
                    return 1;
                }
            }
            names.push_back(name);
            scores.push_back(score);
        }
    }
    for (int i = 0; i < names.size(); ++i) {
        std::cout << "(" << names[i] << ", " << scores[i] << ")\n";
    }
    std::cout << "Enter a name to get their score, or a score to get names with that score.\n";
    int score;
    while (true) {
        if (std::cin >> score) {
            bool found_name {false};
            for (int i = 0; i < scores.size(); ++i) {
                if (scores[i] == score) {
                    std::cout << names[i] << '\n';
                    found_name = true;
                }
            }
            if (!found_name) {
                std::cout << "No name found with score " << score << '\n';
            }
        } else {
            std::cin.clear();
            std::string name;
            std::cin >> name;
            bool found_name {false};
            for (int i = 0; i < names.size(); ++i) {
                if (names[i] == name) {
                    std::cout << scores[i] << '\n';
                    found_name = true;
                    break;
                }
            }
            if (!found_name) {
                std::cout << "Name not found." << '\n';
            }
        }
    }
}