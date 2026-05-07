#include "header.hpp"
#include <cmath>

int fordJohnsonBound(int n) {
    double total = 0;
    for (int k = 1; k <= n; ++k) {
        total += std::ceil(log2(0.75 * k));
    }
    return static_cast<int>(total);
}
