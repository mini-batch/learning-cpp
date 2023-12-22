#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter a spelled-out number (e.g. 'one'):\n";
    std::string spelled_out;
    std::cin >> spelled_out;
    if (spelled_out == "zero") {
        std::cout << "The number is 0.\n";
    } else if (spelled_out == "one") {
        std::cout << "The number is 1.\n";
    } else if (spelled_out == "two") {
        std::cout << "The number is 2.\n";
    } else if (spelled_out == "three") {
        std::cout << "The number is 3.\n";
    } else if (spelled_out == "four") {
        std::cout << "The number is 4.\n";
    } else {
        std::cout << "I don't know that number :(\n";
    }
    return 0;
}