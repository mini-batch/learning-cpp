#include <iostream>
#include <string>

int main()
{
    char currency;
    std::cout << "Enter the currency to convert into GBP\n"
                << "y=yen, e=euros, d=dollars, k=koruna, u=yuan:\n";
    std::cin >> currency;
    double amount;
    std::cout << "Enter the amount:\n";
    std::cin >> amount;
    switch (currency) {
        case 'y':
            std::cout << amount << " yen is equivalent to £" << amount * 0.0053569128;
            break;
        case 'e':
            std::cout << "€" << amount << " is equivalent to £" << amount * 0.87188486;
            break;
        case 'd':
            std::cout << "$" << amount << " is equivalent to £" << amount * 0.80151519;
            break;
        case 'k':
            std::cout << amount << " koruna is equivalent to £" << amount * 0.035643494;
            break;
        case 'u':
            std::cout << amount << " yuan is equivalent to £" << amount * 0.11191551;
            break;
        default:
            std::cout << "This currency is not currently able to be converted.\n";
            break;
    }
    std::cout << '\n';
    return 0;
}