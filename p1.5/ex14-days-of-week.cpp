#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>


void error(std::string s)
{
    throw std::runtime_error(s);
}


int main()
{
    try {
        std::cout << "Enter day and int pairs, e.g. monday 10 fri 2.\n";
        std::vector<std::string> day_names { "mon", "tue", "wed", "thu", "fri", "sat", "sun" };
        std::vector<std::vector<int> > days(7);
        int rejection_count {0};
        std::string day;
        int val;
        while(std::cin >> day) {
            if (std::cin >> val) {
                if (day == "monday" || day == "mon") days[0].push_back(val);
                else if (day == "tuesday" || day == "tue") days[1].push_back(val);
                else if (day == "wednesday" || day == "wed") days[2].push_back(val);
                else if (day == "thursday" || day == "thu") days[3].push_back(val);
                else if (day == "friday" || day == "fri") days[4].push_back(val);
                else if (day == "saturday" || day == "sat") days[5].push_back(val);
                else if (day == "sunday" || day == "sun") days[6].push_back(val);
                else (++rejection_count);
            } else {
                error("Input type was not valid");
            }
        }
        for (int i = 0; i < day_names.size(); ++i) {
            std::cout << day_names[i] << " counts:\n";
            int day_sum {0};
            for (int j = 0; j < days[i].size(); ++j) {
                std::cout << days[i][j] << " ";
                day_sum += days[i][j];
            }
            std::cout << "sum: " << day_sum << '\n';
        }
        if (rejection_count == 1) std::cout << "1 input was rejected.\n";
        else std::cout << rejection_count << " inputs were rejected.\n";
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