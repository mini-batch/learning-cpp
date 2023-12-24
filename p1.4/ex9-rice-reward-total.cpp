#include <iostream>

int main()
{
    double total_grains {0};
    double current_square_grains {1};
    std::cout << sizeof total_grains;
    for (int i = 1; i <= 64; ++i) {
        total_grains += current_square_grains;
        std::cout << "Square: " << i << ", Current: " << current_square_grains << ", Total: " << total_grains << '\n';
        current_square_grains *= 2;
    }
    return 0;
}