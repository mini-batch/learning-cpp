#include <iostream>
#include <vector>

std::vector<int> sieve_of_eratosthenes(int max_val) {
    std::vector<int> store (max_val, -1);
    for (int i = 2; i < store.size(); ++i) {
        if (store[i] != -1) {
            continue;
        }
        int index = i;
        while (index < store.size()) {
            index += i;
            store[index] = 1;
        }
    }
    return store;
}


bool is_prime(int x)
{
    if (x == 1) {
        return false;
    }
    if (x == 2) {
        return true;
    }
    for (int i = 2; i <= x / 2; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    std::cout << "Enter max value:\n";
    int max_val;
    std::cin >> max_val;
    // int count {0};
    // for (int i = 1; i <= max_val; ++i) {
    //     if (is_prime(i)) {
    //         count += 1;
    //         std::cout << i << '\n';
    //     }
    // }
    // std::cout << count;
    std::vector<int> output = sieve_of_eratosthenes(max_val);
    int count {0};
    std::cout << "Primes:\n";
    for (int i = 2; i < output.size(); ++i) {
        if (output[i] == -1) {
            count += 1;
            std::cout << i << '\n';
        }
    }
    std::cout << "Number of primes: " << count << '\n';
}