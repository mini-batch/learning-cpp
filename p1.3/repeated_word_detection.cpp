#include <iostream>
#include <string>

int main()
{
    std::string previous{" "};
    std::string current;
    while (std::cin >> current)
    {
        if (current == previous)
        {
            std::cout << "Repeated word: " << current << '\n';
        }
        previous = current;
    }
}