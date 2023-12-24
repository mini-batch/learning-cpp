#include <iostream>

int main()
{
    double num1, num2;
    char operation;
    std::cout << "Enter two numbers and an operation to apply to them.\n";
    while (std::cin >> num1 >> num2 >> operation) {
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