/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:55:44 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/22 14:11:43 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_T
# define SPAN_T

#include <cstddef>
#include <exception>
#include <iterator>
#include <typeinfo>

template<typename Iterator>
void Span::addRange(const Iterator first, const Iterator last)
{
	if (!(typeid(typename std::iterator_traits<Iterator>::value_type) == typeid(int)))
		throw ArrayExceptType("Incoming datatype doesn't match internal int datatype.");
	
	typename std::iterator_traits<Iterator>::difference_type dist;
	dist = std::distance(first, last);

	if (dist < 0)
		throw ArrayExceptRange("The provided iterator range is not valid.");
	
	if (_maxItems - _array.size() < static_cast<std::size_t>(dist) )
		throw ArrayExceptRange("Range to insert is larger that the class capacity.");

	Iterator it;
	for (it = first; it != last; ++it)
		_array.push_back(*it);
}

#endif
