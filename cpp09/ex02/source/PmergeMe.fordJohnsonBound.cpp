/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.fordJohnsonBound.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:06:15 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/12 12:06:19 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
