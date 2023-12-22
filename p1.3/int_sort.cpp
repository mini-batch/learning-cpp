#include <iostream>
#include <array>

int main()
{
    std::cout << "Enter 3 integers:\n";
    std::array<int, 3> nums;
    std::cin >> nums[0] >> nums[1] >> nums[2];
    while (true) {
        bool ordered = true;
        for (int i = 0; i < 2; i++) {
            if (nums[i] > nums[i+1]) {
                ordered = false;
                int temp = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = temp;
            }
        }
        if (ordered) {
            break;
        }
    }
    std::cout << nums[0] << ", " << nums[1] << ", " << nums[2] << '\n';
    return 0;
}