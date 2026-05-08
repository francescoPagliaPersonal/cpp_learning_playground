/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.ingest.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:35:04 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/08 15:04:24 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <cerrno>
#include <climits>
#include <cstdlib>
#include <sstream>

void PmergeMe::ingest(const char **arr) {
	std::string				myint;
	std::string::size_type	pos;
	std::stringstream		error;
	
	for (int i = 0; arr[i] != NULL; ++i) {
		myint = arr[i];
		pos = myint.find_first_not_of("0123456789");
		if (pos != myint.npos) {
			error.clear();
			error << "item [" << i << "] is not a positive integer: " << myint;
			throw std::runtime_error(error.str());
		}
		char *end = NULL;
		errno = 0;
		long long num = std::strtol(myint.c_str(), &end, 10);
		if (errno != 0 || num > INT_MAX) {
			error.clear();
			error << "item [" << i << "] overflows: " << myint;
			throw std::runtime_error(error.str());
		}
		
		_sourceItems.push_back(node_s(num));		
	}	
}