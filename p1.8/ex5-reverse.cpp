#include <vector>
#include <iostream>


std::vector<int> reverse_copy(std::vector<int>& v)
{
    std::vector<int> reversed_v(v.size());
    for (int i = 0; i < v.size(); ++i) {
        reversed_v[i] = v[v.size() - i - 1];
    }
    return reversed_v;
}


void reverse_in_place(std::vector<int>& v)
{
    for (int i = 0; i < v.size() / 2; ++i) {
        std::swap(v[i], v[v.size() - i - 1]);
    }
}


int main()
{
    // Copy reverse
    std::cout << "Copy reverse\n";
    std::vector<int> v{1,3,5,7,9};
    std::cout << "v: ";
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::vector<int> reverse_v{reverse_copy(v)};
    std::cout << "\nreverse_v: ";
    for (int i = 0; i < reverse_v.size(); ++i) {
        std::cout << reverse_v[i] << " ";
    } 
    std::cout << '\n';

    // In place reverse
    std::cout << "In place reverse\n";
    std::cout << "v: ";
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << '\n';
    reverse_in_place(v);
    std::cout << "v: ";
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << '\n';
}