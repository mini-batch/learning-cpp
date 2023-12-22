#include <iostream>

int main()
{
    int one, two, five, ten, twenty, fifty, hundred;
    std::cout << "How many 1p's do you have?\n";
    std::cin >> one;
    std::cout << "How many 2p's do you have?\n";
    std::cin >> two;
    std::cout << "How many 5p's do you have?\n";
    std::cin >> five;
    std::cout << "How many 10p's do you have?\n";
    std::cin >> ten;
    std::cout << "How many 20p's do you have?\n";
    std::cin >> twenty;
    std::cout << "How many 50p's do you have?\n";
    std::cin >> fifty;
    std::cout << "How many £1's do you have?\n";
    std::cin >> hundred;

    std::cout << "You have " << one << " 1p " << (one > 1 ? "coins" : "coin") << '\n';
    std::cout << "You have " << two << " 2p " << (two > 1 ? "coins" : "coin") << '\n';
    std::cout << "You have " << five << " 5p " << (five > 1 ? "coins" : "coin") << '\n';
    std::cout << "You have " << ten << " 10p " << (ten > 1 ? "coins" : "coin") << '\n';
    std::cout << "You have " << twenty << " 20p " << (twenty > 1 ? "coins" : "coin") << '\n';
    std::cout << "You have " << fifty << " 50p " << (fifty > 1 ? "coins" : "coin") << '\n';
    std::cout << "You have " << hundred << " £1 " << (hundred > 1 ? "coins" : "coin") << '\n';
    std::cout << "You have £" << (static_cast<double>(one) + two * 2 + five * 5 + ten * 10 + twenty * 20 + fifty * 50 + hundred * 100) / 100 << ".\n";

    return 0;
}