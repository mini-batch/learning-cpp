#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>

void error(std::string s)
{
    throw std::runtime_error(s);
}


void sum_first_n(int n, std::vector<int> num_store)
{
    if (n <= 0) error("n must be positive\n");
    if (n > num_store.size()) error("n must be less than or equal to the number of elements in the series\n");    
    std::cout << "The sum of the first " << n << " elements is:\n";
    int total {0};
    bool integer_overflow {false};
    for (int i = 0; i < n; ++i) {
        std::cout << num_store[i];
        if (i < n-1) std::cout << " + ";
        else std::cout << " = ";
        if ((num_store[i] < 0) && (total < std::numeric_limits<int>::min() - num_store[i])) integer_overflow = true;
        else if ((num_store[i] > 0) && (total > std::numeric_limits<int>::max() - num_store[i])) integer_overflow = true;
        if (integer_overflow) {
            error("Sum is too large for an int\n");
        }
        total += num_store[i];
    }
    std::cout << total << "\n";
}


int main()
{
    try {
        int n {0};
        std::cout << "How many numbers do you wish to sum?\n";
        std::cin >> n;
        std::cout << "Enter integers in series:\n";
        std::vector<int> num_store;
        for (int i; std::cin >> i; ) {
            num_store.push_back(i);
        }
        sum_first_n(n, num_store);
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