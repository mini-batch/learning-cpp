#include <iostream>
#include <vector>
#include <string>

class Name_value {
public:
    std::string name;
    int value;
    Name_value(std::string name, int value)
        :name{name}, value{value} { }
};

int main()
{
    std::cout << "Enter name and int pairs, end with 'NoName' and '0'.\n";
    std::vector<Name_value> pairs;
    while (true) {
        std::string name;
        int score;
        std::cin >> name >> score;
        if (name == "NoName" && score == 0) {
            break;
        } else {
            for (Name_value stored_pair: pairs) {
                if (stored_pair.name == name) {
                    std::cout << "Names must be unique\n";
                    return 1;
                }
            }
            pairs.push_back(Name_value(name, score));
        }
    }
    for (int i = 0; i < pairs.size(); ++i) {
        std::cout << "(" << pairs[i].name << ", " << pairs[i].value << ")\n";
    }
    std::cout << "Enter a name to get their score, or a score to get names with that score.\n";
    int score;
    while (true) {
        if (std::cin >> score) {
            bool found_name {false};
            for (int i = 0; i < pairs.size(); ++i) {
                if (pairs[i].value == score) {
                    std::cout << pairs[i].name << '\n';
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
            for (int i = 0; i < pairs.size(); ++i) {
                if (pairs[i].name == name) {
                    std::cout << pairs[i].value << '\n';
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