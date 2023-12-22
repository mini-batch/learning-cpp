#include <iostream>

int main()
{
    std::cout << "Enter an integer:\n";
    int num;
    std::cin >> num;
    std::cout << "The number " << num << " is " << (num % 2 == 0 ? "even" : "odd") << ".\n";
    return 0;
}