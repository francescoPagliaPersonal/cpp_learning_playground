/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:03:08 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/23 12:01:49 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define  MUTANTSTACK_H

#include <iterator>
#include <ratio>
#include <list>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	class iterator {
		public:
		T * begin(void) {return std::stack<T>::c.begin();}
		T * end(void) {return std::stack<T>::c.end();}
	};
};

#endif
