/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:13:44 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/05 12:01:21 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cerrno>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <sstream>
#include <stdexcept>

size_t				_vCounter = 0;
size_t				_dCounter = 0;

PmergeMe::PmergeMe(void) {};
PmergeMe::~PmergeMe(void) {};

PmergeMe::PmergeMe(const PmergeMe & obj) : 
	_sourceItems(obj._sourceItems), 
	_vItems(obj._vItems), 
	_dItems(obj._dItems) {};

PmergeMe& PmergeMe::operator=(const PmergeMe & obj) 
{
	if (this == &obj)
		return *this;
	
	_sourceItems = obj._sourceItems;
	_vItems = obj._vItems;
	_dItems = obj._dItems;
	return *this;
};

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
		_sourceItems.push_back(num);		
	}	
}

void PmergeMe::print(void)  {
	_printIterable("Input", _sourceItems);
}
