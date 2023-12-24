#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<double> nums;
    for (double x; std::cin>>x; ) {
        nums.push_back(x);
    }
    std::sort(nums.begin(), nums.end());
    bool is_odd_length = nums.size() % 2;
    double median {0};
    if (is_odd_length) {
        median = nums[(nums.size()-1)/2];
    } else {
        median = 0.5 * (nums[(nums.size()/2)-1] + nums[(nums.size()/2)]);
    }
    std::cout << "Median num: " << median << '\n';
    return 0;
}