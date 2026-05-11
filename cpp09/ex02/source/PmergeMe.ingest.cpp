/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.ingest.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:35:04 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/11 12:32:13 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <cerrno>
#include <climits>
#include <cstdlib>
#include <sstream>

static bool checkDuplicates(std::vector<int> & arr, int value) 
{
	typedef  std::vector<int>::size_type T_id;
	
	if (arr.empty()) {
		arr.push_back(value);
		return false;
	}
		
	T_id low = 0;
	T_id high = arr.size(); 
	T_id mid = -1;
	while (low < high) {
		mid = low + (high - low) / 2;
		if 
			(arr[mid] < value) low = mid + 1;
		else 
			high = mid;
	}
	if (arr[low] != value && arr[low + 1] != value )
	{
		arr.insert(arr.begin() + low, value);
		return false;
	}
	return true;
}


void PmergeMe::ingest(const char **arr) {
	std::string				myint;
	std::string::size_type	pos;
	std::stringstream		error;
	std::vector<int>		duplicates;
	
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
		if (checkDuplicates(duplicates, num)) {
			error.clear();
			error << "item [" << i << "] is a duplicate: " << myint;
			throw std::runtime_error(error.str());
		}
		_sourceItems.push_back(node_s(num));		
	}	
}