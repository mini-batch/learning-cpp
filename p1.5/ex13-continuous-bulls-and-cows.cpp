#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>


void error(std::string s)
{
    throw std::runtime_error(s);
}


std::vector<int> evaluate_guess(std::vector<int> guess, std::vector<int> nums)
{
    int bull_count {0};
    int cow_count {0};
    for (int i = 0; i < guess.size(); ++i) {
        if (guess[i] == nums[i]) bull_count += 1;
        else {
            for (int j = 0; j < nums.size(); ++j) {
                if (guess[i] == nums[j]) {
                    cow_count += 1;
                    break;
                }
            }
        }
    }
    return std::vector<int> {bull_count, cow_count};
}


int main()
{
    try {
        constexpr int NUM_SIZE {4};
        std::vector<int> nums (NUM_SIZE);
        std::vector<int> guess(NUM_SIZE);
        while(true) {
            std::cout << "Enter an int to set rng seed:\n";
            int seed;
            std::cin >> seed;
            if (std::cin.fail()) error("Seed must be an integer value");
            srand(seed);
            for (int i = 0; i < NUM_SIZE; ++i) {
                nums[i] = rand() % 10;
            }
            for (int i: nums) std::cout << i << ", ";
            std::cout << "Guess the " << NUM_SIZE << " numbers I'm thinking of:\n";
            while (true) {
                for (int i = 0; i < NUM_SIZE; ++i) {
                    std::cin >> guess[i];
                    if (guess[i] < 0 || guess[i] > 9) error("Only enter integers between 0 and 9.\n");
                    if (std::cin.fail()) error("Only enter integer values");
                }
                std::vector<int> result = evaluate_guess(guess, nums);
                if (result[0] == NUM_SIZE) {
                    std::cout << "That is correct!\n";
                    break;
                } else {
                    std::cout << result[0] << " bull and " << result[1] << " cow\n";
                }
            }
        }
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