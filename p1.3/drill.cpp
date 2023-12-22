#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter the name of the person you want to write to:\n";
    std::string first_name {" "};
    std::cin >> first_name;
    std::cout << "What is their age?\n";
    int age {0};
    std::cin >> age;
    std::cout << "Enter the name of another friend:\n";
    std::string friend_name {" "};
    std::cin >> friend_name;
    std::cout << "Is the friend male of female? (m/f):\n";
    char friend_sex {0};
    std::cin >> friend_sex;
    std::cout << "Dear " << first_name << ",\n"
                << "  How are you? What have you been up to?\n"
                << "I am currently working on my programming skills and knowledge.\n"
                << "I've got a job interview coming up in a couple of works, wish me luck!\n"
                << "Have you seen " << friend_name << " lately?\n";
    if (friend_sex == 'm') {
        std::cout << "If you see " << friend_name << " please ask him to call me.\n";
    } else if (friend_sex == 'f') {
        std::cout << "If you see " << friend_name << " please ask her to call me.\n";
    }
    if (age < 12) {
        std::cout << "Next year you will be " << age + 1 << ".\n";
    } else if (age == 17) {
        std::cout << "Next year you'll be able to vote.\n";
    } else if (age > 70) {
        std::cout << "I hope you are enjoying retirement.\n";
    }
    std::cout << "Yours sincerely,\n\nDave\n";
}