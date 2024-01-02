#include <vector>
#include <iostream>
#include <stdexcept>

int main()
{
    try {
        std::vector<int> v(5,1);
        int x = v.at(5);
        std::cout << x << '\n';
    } catch (std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << '\n';
    }
    
    return 0;
}