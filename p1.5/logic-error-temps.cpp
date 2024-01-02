#include <iostream>
#include <vector>
#include <limits>

int main()
{
    constexpr int min_temp {std::numeric_limits<int>::min()};
    constexpr int max_temp {std::numeric_limits<int>::max()};
    std::vector<double> temps;
    int num_of_temps {0};
    double sum {0};
    double high_temp {min_temp};
    double low_temp {max_temp};
    for (double temp; std::cin >> temp; ) {
        ++num_of_temps;
        sum += temp;
        if (temp > high_temp) high_temp = temp;
        if (temp < low_temp) low_temp = temp;
    }
    std::cout << "High temp: " << high_temp << '\n';
    std::cout << "Low temp: " << low_temp << '\n';
    std::cout << "Average temp: " << sum/num_of_temps << '\n';
    return 0;
}