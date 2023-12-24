#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> num_words{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
    std::vector<std::string> num_ints{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    for (std::string inp; std::cin >> inp; ) {
        for (int i = 0; i < 10; ++i) {
            if (num_words[i] == inp) {
                std::cout << i << '\n';
            } else if (num_ints[i] == inp) {
                std::cout << num_words[i] << '\n';
            }
        }
    }
    return 0;
}