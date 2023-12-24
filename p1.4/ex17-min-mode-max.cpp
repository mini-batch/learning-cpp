#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::cout << "Enter some strings (end with ctrl + d):\n";
    std::vector<std::string> input_strings;
    for (std::string inp; std::cin >> inp; ) {
        input_strings.push_back(inp);
    }
    std::sort(input_strings.begin(), input_strings.end());
    std::string mode_num;
    int mode_count {0};
    int running_count {1};
    for (int i = 0; i < input_strings.size(); ++i) {
        if (input_strings[i] == input_strings[i+1]) {
            running_count += 1;
            if (running_count > mode_count) {
                mode_num = input_strings[i];
                mode_count = running_count;
            }
        } else {
            running_count = 1;
        }
    }
    std::cout << "Min: " << input_strings[0] << '\n';
    std::cout << "Max: " << input_strings.back() << '\n';
    std::cout << "Mode: " << mode_num << ", Count: " << mode_count << '\n';
}