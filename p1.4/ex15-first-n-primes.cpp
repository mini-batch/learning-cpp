#include <iostream>
#include <vector>

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
    std::cout << "How many primes would you like?\n";
    int num_primes;
    std::cin >> num_primes;
    std::cout << "Primes:\n";
    int prime_counter {0};
    for (int i = 1; prime_counter < num_primes; ++i) {
        if (is_prime(i)) {
            prime_counter += 1;
            std::cout << i << '\n';
        }
    }
}