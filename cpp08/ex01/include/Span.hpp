/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:28:53 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/22 13:57:32 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

#include <cstddef>
#include <ostream>
#include <vector>
#include "ArrayException.hpp"

class Span 
{
	public:
	
	Span(std::size_t items);
	Span(Span const & obj);
	~Span(void);
	Span& operator=(Span const & obj);

	void	addNumber(int num);

	template<typename Iterator>
	void	addRange(const Iterator first, const Iterator last);
	int		shortestSpan(void)	const;
	int		longestSpan(void)	const;

	const std::string	printArray(void)	const;
	
	class ArrayExceptRange : public ArrayException {
		public:
		ArrayExceptRange(std::string reason) 
			: ArrayException(reason) {};
	};

	class ArrayExceptType : public ArrayException {
		public:
		ArrayExceptType(std::string reason) 
			: ArrayException(reason) {};
	};
	
	private:
	
	Span(void);

	std::vector<int>	_array;
	std::size_t			_maxItems;
	
};

#include "Span.tpp" 

std::ostream& operator<<(std::ostream& stream, Span& obj) ; 

#endif
