#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your first name and age\n";
    std::string first_name{"?"};
    int age{-1};
    std::cin >> first_name >> age;
    std::cout << "Hello, " << first_name << ". You are: " << age * 12 << " months old\n";
}