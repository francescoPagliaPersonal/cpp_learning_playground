/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:56:15 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/27 10:50:51 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

#include <errno.h>

template<typename T>
typename T::const_iterator	easyfind(T const & container, int value) 
{
	typename T::const_iterator it;
	for (it = container.begin(); it != container.end(); ++it)
		if (*it == value)
			return it;
	errno = 1;
	return container.end();
}


template<typename T>
typename T::iterator		easyfind(T & container, int value) 
{
	typename T::iterator it;
	for (it = container.begin(); it != container.end(); ++it)
		if (*it == value)
			return it;
	errno = 1;
	return container.end();
}

#endif
