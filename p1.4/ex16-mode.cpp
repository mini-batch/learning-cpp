#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::cout << "Enter some integers:\n";
    std::vector<int> input_nums;
    for (int num; std::cin >> num; ) {
        input_nums.push_back(num);
    }
    std::sort(input_nums.begin(), input_nums.end());
    int mode_num;
    int mode_count {0};
    int running_count {1};
    for (int i = 0; i < input_nums.size(); ++i) {
        if (input_nums[i] == input_nums[i+1]) {
            running_count += 1;
            if (running_count > mode_count) {
                mode_num = input_nums[i];
                mode_count = running_count;
            }
        } else {
            running_count = 1;
        }
    }
    std::cout << "Mode: " << mode_num << ", Count: " << mode_count << '\n';
}