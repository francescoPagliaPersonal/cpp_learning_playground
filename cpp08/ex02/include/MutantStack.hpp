/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:03:08 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/23 15:05:56 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define  MUTANTSTACK_H

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	
	public:
	MutantStack<T>(void) : std::stack<T>() {};
	MutantStack<T>(const MutantStack<T>& obj) : std::stack<T>(obj) {};
	~MutantStack<T>(void) {}; 
	MutantStack<T>& operator=(const MutantStack<T>& obj) {
		std::stack<T>::operator=(obj);
		return *this;
	}
	
	typedef typename std::stack<T>::container_type::iterator 		iterator;
    typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
	typedef typename std::stack<T>::container_type::value_type		value_type;

	iterator begin(void)	{return this->c.begin();}
	iterator end(void)		{return this->c.end();}

	iterator begin(void)	const	{return this->c.begin();}
	iterator end(void)		const 	{return this->c.end();}
};

#endif
