
#include "PmergeMe.hpp"
#include <cmath>

int	PmergeMe::_fordJohnsonBound(int n) const {
	double total = 0;
	const double logTwo = std::log(2.0); 
	for (int k = 1; k <= n; ++k) {
		total += std::ceil(std::log(0.75 * k) / logTwo);
	}
	return static_cast<int>(total);
}
