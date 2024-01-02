#include <iostream>
#include <string>
#include <stdexcept>

void error(std::string s)
{
    throw std::runtime_error(s);
}

double ctok(double c)  // converts Celsius to Kelvin
{
    if (c < -273.15) {
        error("Value must greater than or equal to -273.15 degrees Celsius");
    }
    double k = c + 273.15;
    return k;
}

double ktoc(double k)
{
    if (k < 0) {
        error("Value must be greater than or equal to 0 degrees Kelvin");
    }
    double c = k - 273.15;
    return c;
}

int main()
{
    try {
        double value;
        char unit;
        double converted_value;
        while (true) {
            std::cout << "Enter a value followed by 'c' or 'k' to convert.\n";
            std::cin >> value >> unit;
            switch (unit) {
            case 'c':
                converted_value = ctok(value);
                std::cout << value << "C = " << converted_value << "K\n";
                break;
            case 'k':
                converted_value = ktoc(value);
                std::cout << value << "K = " << converted_value << "C\n";
                break;
            default:
                std::cerr << "Unit must be 'c' or 'k'\n";
                break;
            }
        }
        return 0;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "Unknown exception\n";
        return 2;
    }
}