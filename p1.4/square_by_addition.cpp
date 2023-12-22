#include <iostream>

int square(int x)
{
    int square = 0;
    for (int i = 0; i < x; ++i) {
        square += x;
    }
    return square;
}

int main()
{
    std::cout << "Enter an integer to square:\n";
    int x;
    std::cin >> x;
    std::cout << "The square of " << x << " is " << square(x) << '\n';
    return 0;
}