#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

void error(std::string s)
{
    throw std::runtime_error(s);
}

void check_root(
    double x, 
    double a,
    double b,
    double c,
    double epsilon=1e-9
    )
{
    double output = a*x*x + b*x + c;
    if (abs(output) > epsilon) std::cout << "Root off by " << output << '\n';
}

void solve_quadratic(double a, double b, double c)
{
    if (b*b - 4*a*c < 0) {
        error("This equation has no real roots, exiting\n");
    }
    double x1 = (-b + std::sqrt(b*b -4*a*c)) / (2*a);
    double x2 = (-b - std::sqrt(b*b -4*a*c)) / (2*a);
    check_root(x1, a, b, c);
    check_root(x2, a, b, c);
    std::cout << "x1 = " << x1 << ", x2 = " << x2 << '\n';
}

int main()
{
    try {
        double a, b, c;
        std::cout << "Enter values for the coefficients to solve ax^2+bx+c=0\n";
        while (std::cin >> a >> b >> c) {
            solve_quadratic(a,b,c);
        }
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