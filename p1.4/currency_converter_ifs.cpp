#include <iostream>
#include <string>

int main()
{
    std::string currency;
    std::cout << "Enter the currency to convert into GBP (yen, euros, or dollars):\n";
    std::cin >> currency;
    double amount;
    std::cout << "Enter the amount:\n";
    std::cin >> amount;
    if (currency == "yen") {
        std::cout << amount << " yen is equivalent to £" << amount * 0.0053569128;
    } else if (currency == "euros") {
        std::cout << "€" << amount << " is equivalent to £" << amount * 0.87188486;
    } else if (currency == "dollars") {
        std::cout << "$" << amount << " is equivalent to £" << amount * 0.80151519;
    } else {
        std::cout << "This currency conversion is not currently available.";
    }
    std::cout << '\n';
    return 0;
}