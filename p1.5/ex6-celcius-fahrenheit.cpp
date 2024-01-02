#include <iostream>
#include <string>
#include <stdexcept>

void error(std::string s)
{
    throw std::runtime_error(s);
}

double ctof(double c)
{
    if (c < -273.15) {
        error("Value must greater than or equal to -273.15 degrees Celsius");
    }
    double f = (c * 9.0/5.0) + 32;
    return f;
}

double ftoc(double f)
{
    if (f < -459.67) {
        error("Value must be greater than or equal to -459.67 degrees Fahrenheit");
    }
    double c = (f - 32) * 5.0/9.0;
    return c;
}

int main()
{
    try {
        double value;
        char unit;
        double converted_value;
        while (true) {
            std::cout << "Enter a value followed by 'c' or 'f' to convert.\n";
            std::cin >> value >> unit;
            switch (unit) {
            case 'c':
                converted_value = ctof(value);
                std::cout << value << "C = " << converted_value << "F\n";
                break;
            case 'f':
                converted_value = ftoc(value);
                std::cout << value << "F = " << converted_value << "C\n";
                break;
            default:
                std::cerr << "Unit must be 'c' or 'f'\n";
                break;
            }
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