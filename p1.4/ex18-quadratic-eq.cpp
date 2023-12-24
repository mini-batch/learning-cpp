#include <iostream>
#include <cmath>

int main()
{
    std::cout << "Enter values for a, b, and c, to solve the quadratic ax^2+bx+c=0\n";
    double a, b, c;
    std::cin >> a >> b >> c;
    double x1 = (-b + std::sqrt(b*b - 4 * a * c)) / (2 * a);
    double x2 = (-b - std::sqrt(b*b - 4 * a * c)) / (2 * a);
    std::cout << x1 << ", " << x2 << '\n';
    return 0;
}