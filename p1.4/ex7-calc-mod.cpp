#include <iostream>
#include <vector>
#include <string>

int convert_input(std::string inp)
{
    std::vector<std::string> num_words{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    std::vector<std::string> num_ints{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
    for (int i = 0; i < num_ints.size(); ++i) {
        if (num_words[i] == inp) {
            return i;
        } else if (num_ints[i] == inp) {
            return i;
        }
    }
    std::cout << inp;
}

int main()
{
    std::string inp1, inp2;
    char operation;
    std::cout << "Enter two numbers and an operation to apply to them.\n";
    while (std::cin >> inp1 >> inp2 >> operation) {
        int num1 = convert_input(inp1);
        int num2 = convert_input(inp2);
        switch (operation) {
        case '+':
            std::cout << num1 << " + " << num2 << " = " << num1 + num2 << '\n';
            break;
        case '-':
            std::cout << num1 << " - " << num2 << " = " << num1 - num2 << '\n';
            break;
        case '*':
            std::cout << num1 << " * " << num2 << " = " << num1 * num2 << '\n';
            break;
        case '/':
            std::cout << num1 << " - " << num2 << " = " << num1 - num2 << '\n';
            break;
        default:
            std::cout << "That is not a valid operation, use '+', '-', '*', or '/'.\n";
            break;
        }
    }
    return 0;
}