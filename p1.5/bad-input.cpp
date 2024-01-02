#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

void error(std::string s)
{
    throw std::runtime_error(s);
}

int main()
{
    try {
        double d {0};
        std::cin >> d;
        if (std::cin) {
            std::cout << "Success.\n";
        } else {
            std::cout << "Failure. Throwing runtime error.\n";
            error("Input was not a double.\n");
        }
        std::vector<int> v(5);
        int x = v.at(5);
        return 0;
    } 
    catch (std::runtime_error& e) {
        std::cerr << "runtime error: " << e.what() << '\n';
        return 1;
    }
    catch (std::out_of_range& e) {
        std::cerr << "out_of_range error: " << e.what() << '\n';
        return 2;
    }
    catch (...) {
        std::cerr << "Unknown exception.\n";
        return 3;
    }
    
}