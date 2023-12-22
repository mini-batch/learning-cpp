#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> disliked {"coriander", "celery", "stuff"};
    for (std::string word; std::cin >> word; ) {
        bool bleep = false;
        for (std::string x: disliked) {
            if (word == x) {
                bleep = true;
                break;
            }
        }
        if (bleep) {
            std::cout << "BLEEP\n";
        } else {
            std::cout << word << '\n';
        }
    }
    return 0;
}