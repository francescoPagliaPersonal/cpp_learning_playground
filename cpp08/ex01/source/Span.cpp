/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:44:08 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/22 12:44:29 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <sstream>

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
		throw ArrayExceptRange("max capacity reached can grow it any further");
	_array.push_back(num);
}

int		Span::shortestSpan(void) const {
	return 1;
}

int		Span::longestSpan(void) const {
	return 1;
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