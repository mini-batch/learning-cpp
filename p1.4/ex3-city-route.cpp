#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<double> distances;
    for (double distance; std::cin >> distance; ) {
        distances.push_back(distance);
    }
    double total_distance {0};
    for (double distance: distances) {
        total_distance += distance;
    }
    std::sort(distances.begin(), distances.end());
    const double smallest_distance {distances[0]};
    const double mean_distance {total_distance / distances.size()};
    std::cout << "Total distance: " << total_distance << '\n';
    std::cout << "Smallest distance: " << smallest_distance << '\n';
    std::cout << "Mean distance: " << mean_distance << '\n';
}