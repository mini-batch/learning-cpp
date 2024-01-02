#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>

void error(std::string s)
{
    throw std::runtime_error(s);
}


void print_fibonacci(int n)
{
    if (n < 0) error("Number of terms must be non-negative");
    int x1 {1};
    int x2 {1};
    if (n > 1) std::cout << x1 << " ";
    if (n > 2) std::cout << x2 << " ";
    for (int i = 2; i < n; ++i) {
        int temp {x2};
        if (x1 > std::numeric_limits<int>::max() - x2) error("Integer overflow");
        x2 += x1;
        x1 = temp;
        std::cout << x2 << " ";
    }
    std::cout << '\n';
}


int main()
{
    try {
        int n {0};
        std::cout << "How many terms of the Fibonacci series do you want?\n";
        std::cin >> n;
        print_fibonacci(n);
        return 0;
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "Unknown exception\n";
        return 2;
    }
    
}