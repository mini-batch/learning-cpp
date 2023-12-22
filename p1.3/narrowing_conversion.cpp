#include <iostream>

int main()
{
    // int a = 20000;
    // char c = a;
    // int b = c;
    // if (a != b) {
    //     std::cout << "Error: " << a << "!=" << b << '\n';
    // }
    // else {
    //     std::cout << "No error! We have large characters";
    // }

    double d = 0;
    while (std::cin >> d) {
        int i = d;
        char c = i;
        int i2 = c;
        std::cout << "d==" << d
                    << "i==" << i
                    << "i2==" << i2
                    << "char(" << c << ")\n";
    }
    return 0;
}