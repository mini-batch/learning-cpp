#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>

void error(std::string s)
{
    throw std::runtime_error(s);
}


void sum_first_n(int n, std::vector<double> num_store)
{
    if (n <= 0) error("n must be positive\n");
    if (n > num_store.size()) error("n must be less than or equal to the number of elements in the series\n");    
    std::cout << "The sum of the first " << n << " elements is:\n";
    double total {0};
    bool integer_overflow {false};
    for (int i = 0; i < n; ++i) {
        std::cout << num_store[i];
        if (i < n-1) std::cout << " + ";
        else std::cout << " = ";
        total += num_store[i];
    }
    std::cout << total << "\n";
}


std::vector<double> get_differences(int n, std::vector<double> num_store)
{
    if (n < 2) error("n must be greater than 2 to get differences\n");
    if (n > num_store.size()) error("n must be less than or equal to the number of elements in the series\n");
    std::vector<double> diffs (n-1);
    for (int i = 0; i < n-1; ++i) {
        diffs[i] = num_store[i+1] - num_store[i];
    }
    return diffs;
}


int main()
{
    try {
        int n {0};
        std::cout << "How many numbers do you wish to sum?\n";
        std::cin >> n;
        std::cout << "Enter integers in series:\n";
        std::vector<double> num_store;
        for (double i; std::cin >> i; ) {
            num_store.push_back(i);
        }
        sum_first_n(n, num_store);
        std::cout << "Differences between the first n-1 adjacent elements\n";
        for (double x: get_differences(n, num_store)) {
            std::cout << x << " ";
        }
        std::cout << '\n';
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