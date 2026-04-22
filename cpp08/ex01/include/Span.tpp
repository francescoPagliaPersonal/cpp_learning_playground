/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:55:44 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/22 12:53:30 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_T
# define SPAN_T

#include <exception>
#include <typeinfo>

template<typename T>
void Span::addRange(T const & container, 
						typename T::iterator start,
						const typename T::iterator end)
{
	typename T::value_type tmp = 0; 
	int test = tmp; // do not compile if assignment is not possible;
	(void)test;
	(void)container;
	
	if (std::distance(start, end) + _array.size() >= _maxItems)
		throw ArrayExceptRange("inserting such range will cause to insert more than Max Item count.");

	
	while (start != end) {
		_array.push_back(*start);
		++start;
	}
}

#endif
