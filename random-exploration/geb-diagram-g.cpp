// Godel, Escher, Bach pages 135-137
#include <iostream>

int g(int n)
{
    if (n == 0) {
        return 0;
    } else {
        return n - g(g(n-1));
    } // add exception for n < 0
}


int q(int n)
{
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return q(n - q(n-1)) + q(n - q(n-2));
    }
}


int main()
{
    for (int i = 1; i < 100; ++i) {
        std::cout << q(i) << "\n";
    }
    return 0;
}