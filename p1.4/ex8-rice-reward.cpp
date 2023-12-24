#include <iostream>

int main()
{
    int square {0};
    int total_grains {1};
    int current_square_grains {1};
    bool reached1thou {false};
    bool reached1mil {false};
    bool reached1bil {false};
    for (int i = 1; i < 64; ++i) {
        square += 1;
        current_square_grains *= 2;
        total_grains += current_square_grains;
        if (total_grains > 1000 && !reached1thou) {
            std::cout << square << " squares to reach 1,000 grains.\n";
            reached1thou = true;
        }
        if (total_grains > 1000000 && !reached1mil) {
            std::cout << square << " squares to reach 1,000,000 grains.\n";
            reached1mil = true;
        }
        if (total_grains > 1000000000 && !reached1bil) {
            std::cout << square << " squares to reach 1,000,000,000 grains.\n";
            reached1bil = true;
            break;
        }
    }
    return 0;
}