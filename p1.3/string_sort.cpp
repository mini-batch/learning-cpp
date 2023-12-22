#include <iostream>
#include <array>
#include <string>

int main()
{
    std::cout << "Enter 3 integers:\n";
    std::array<std::string, 3> words;
    std::cin >> words[0] >> words[1] >> words[2];
    while (true) {
        bool ordered = true;
        for (int i = 0; i < 2; i++) {
            if (words[i] > words[i+1]) {
                ordered = false;
                std::string temp = words[i];
                words[i] = words[i+1];
                words[i+1] = temp;
            }
        }
        if (ordered) {
            break;
        }
    }
    std::cout << words[0] << ", " << words[1] << ", " << words[2] << '\n';
    return 0;
}