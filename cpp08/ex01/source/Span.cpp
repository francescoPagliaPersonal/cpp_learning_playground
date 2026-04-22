/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:44:08 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/22 14:42:40 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <sstream>
#include <vector>

Span::Span(std::size_t items) : _maxItems(items) {};
Span::Span(Span const & obj) : _maxItems(obj._maxItems) {
	_array.assign(obj._array.begin(), obj._array.end());
}
Span::~Span(void) {};

Span& Span::operator=(Span const & obj) {
	_maxItems = obj._maxItems;
	_array.clear();
	_array.assign(obj._array.begin(), obj._array.end());
	return *this;
}

void	Span::addNumber(int num) {
	if (_array.size() >= _maxItems)
		throw ArrayExceptRange("Max capacity reached storage cannot grow any further.");
	_array.push_back(num);
}

int		Span::shortestSpan(void) const {
	if (_array.size() < 2)
		throw ArrayExceptRange("Not enough items to perform shortestSpan operation.");
	
	std::vector<int>tmp;
	tmp.assign(_array.begin(), _array.end());
	std::sort(tmp.begin(), tmp.end());
	
	int span = *(tmp.end() -1) - *tmp.begin();
	for (std::size_t i = 1; i < tmp.size(); ++i) {
		int diff = tmp[i] - tmp[i - 1];
		if (diff < span)
			span = diff;
		if (span == 0)
			break;
	}
	return span;
}

int		Span::longestSpan(void) const {
	if (_array.size() < 2)
		throw ArrayExceptRange("Not enough items to perform shortestSpan operation.");
	int maxVal = *std::max_element(_array.begin(), _array.end());
	int minVal = *std::min_element(_array.begin(), _array.end());
	return maxVal - minVal;
}

const std::string Span::printArray(void) const {
	std::ostringstream tostr;
	std::vector<int>::const_iterator it;
	for ( it = _array.begin(); it != _array.end(); ++it) 
		tostr << *it << ", " ;
	return tostr.str();
}

std::ostream& operator<<(std::ostream& stream, Span& obj) {
	stream << obj.printArray() ;
	return stream;
}