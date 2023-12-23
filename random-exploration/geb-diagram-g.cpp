// Godel, Escher, Bach pages 135-137
#include <iostream>
#include <vector>

int g(int n)
{
    if (n == 0) {
        return 0;
    } else {
        return n - g(g(n-1));
    } // add exception for n < 0
}


int q(int n, std::vector<int> store)
{
    if (store[n] != -1) {
        return store[n];
    } else if (n == 1 || n == 2) {
        return 1;
    } else {
        return q(n - q(n-1, store), store) + q(n - q(n-2, store), store);
    }
}


int main()
{
    std::vector<int> store(99, -1);
    for (int i = 1; i < store.size(); ++i) {
        store[i] = q(i, store);
    }
    for (int i = 1; i < store.size(); ++i) {
        std::cout << store[i] << "\n";
    }
    return 0;
}