#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cout << "Think of a number between 1 and 100, I'll try and guess it :)\n";
    int lower_lim {1};
    int upper_lim {100};
    int num_questions {0};
    char user_answer;
    while (true) {
        if (abs(lower_lim - upper_lim) == 1) {
            num_questions += 1;
            std::cout << num_questions << ". Is your number " << lower_lim << "?\n";
            std::cin >> user_answer;
            if (user_answer == 'y') {
                upper_lim = lower_lim;
            } else if (user_answer == 'n') {
                lower_lim = upper_lim;
            }
        } else {
            int current_guess;
            current_guess = lower_lim + (upper_lim - lower_lim) / 2.0 + 1;
            num_questions += 1;
            std::cout << num_questions << ". Is your number less than " << current_guess << "? (y/n)\n";
            std::cin >> user_answer;
            if (user_answer == 'y') {
            upper_lim = current_guess - 1;
            } else if (user_answer == 'n') {
                lower_lim = current_guess;
            }
        }
        if (lower_lim == upper_lim) {
            std::cout << "Your number is " << lower_lim << "!\n";
            break;
        }
        std::cout << "Lower: " << lower_lim << '\n';
        std::cout << "Upper: " << upper_lim << '\n';
    }
    return 0;
}