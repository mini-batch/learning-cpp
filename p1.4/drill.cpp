#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    double smallest {0};
    double largest {0};
    double num {0};
    double sum {0};
    int count {0};
    std::string unit;
    std::vector<double> log;
    while (std::cin >> num >> unit) {
        std::cout << num << '\n';
        double value;
        if (unit == "m") {
            value = num;
        } else if (unit == "in") {
            value = num * 2.54 / 100;
        } else if (unit == "ft") {
            value = num * 12 * 2.54 / 100;
        } else if (unit == "cm") {
            value = num / 100;
        } else {
            std::cout << "That is not a recognised unit\n";
        }
        sum += value;
        log.push_back(value);
        if (value < smallest) {
            smallest = num;
            std::cout << "Smallest so far.\n";
        }
        if (value > largest) {
            largest = num;
            std::cout << "Largest so far.\n";
        }
        ++count;
        std::cout << "Sum: " << sum << '\n';
        std::cout << "Count: " << count << '\n';
    }
    std::cout << "Values entered:\n";
    std::sort(log.begin(), log.end());
    for (double x: log) {
        std::cout << x << '\n';
    }
    return 0;
}