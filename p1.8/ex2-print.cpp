#include <iostream>
#include <string>
#include <vector>


void fibonacci(int x, int y, std::vector<int>& v, int n)
{
    v.push_back(x);
    v.push_back(y);
    int temp;
    for (int i = 0; i < n; ++i) {
        temp = x + y;
        v.push_back(temp);
        x = y;
        y = temp;
    }
}


void print(const std::string& s, const std::vector<int>& v)
{
    std::cout << s << ": ";
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i != v.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << '\n';
}


int main()
{
    const int FIRST_NUM = 1;
    const int SECOND_NUM = 2;
    const int NUM_TERMS = 100;
    std::string label{"Numbers"};
    std::vector<int> v;
    fibonacci(FIRST_NUM,SECOND_NUM,v,NUM_TERMS);
    print(label, v);
}

/*
Exercise 4:
Using NUM_TERMS = 100, the largest int we get before negative numbers appear is 1836311903.
1134903170 + 1836311903 leads to integer overflow. 
So largest int is somewhere in the range (1836311903, 1134903170 + 1836311903).
*/