#include <iostream>

int main()
{
    std::cout << "Enter 2 integers:\n";
    int num1;
    int num2;
    std::cin >> num1 >> num2;
    std::cout << "Smallest: " << (num1 < num2 ? num1 : num2) << '\n'
                << "Largest: " << (num1 < num2 ? num2 : num1) << '\n'
                << "Sum: " << num1 + num2 << '\n'
                << "Difference: " << num1 - num2 << '\n'
                << "Product: " << num1 * num2 << '\n'
                << "Ratio: " << static_cast<double>(num1) / num2 << '\n';
}