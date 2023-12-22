#include <iostream>

int main()
{
    std::cout << "Enter a distance in miles:\n";
    double miles;
    std::cin >> miles;
    std::cout << miles << " miles is equivalent to " << miles * 1.609 << " kilometres.\n";
    return 0;
}