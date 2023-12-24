#include <iostream>
#include <vector>

char generate_choice()
{
    std::vector<char> choices{'r','p','s'};
    return choices[rand() % 3];
}

void print_result(char user_choice, char computer_choice)
{
}

int main()
{
    while (true) {
        std::cout << "Do you choose 'r' (rock), 'p' (paper), or 's' (scissors)?\n";
        char user_choice;
        std::cin >> user_choice;
        char computer_choice {generate_choice()};
        std::cout << "I choose " << computer_choice << ".\n";
        switch (user_choice) {
        case 'r':
            if (computer_choice == 'r') {
                std::cout << "It's a draw\n";
            } else if (computer_choice == 'p') {
                std::cout << "I win.\n";
            } else {
                std::cout << "You win.\n";
            }
            break;
        case 'p':
            if (computer_choice == 'r') {
                std::cout << "You win\n";
            } else if (computer_choice == 'p') {
                std::cout << "It's a draw.\n";
            } else {
                std::cout << "I win.\n";
            }
            break;
        case 's':
            if (computer_choice == 'r') {
                std::cout << "I win\n";
            } else if (computer_choice == 'p') {
                std::cout << "You win.\n";
            } else {
                std::cout << "It's a draw.\n";
            }
            break;
        default:
            std::cout << "Enter 'r' (rock), 'p' (paper), or 's' (scissors)\n";
            break;
        }
    }

}