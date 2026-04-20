/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:56:15 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/20 16:05:29 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

template<typename T>
const T& easyfind(T const & container, int value) const {
	for (it = iterator.begin(); it < iterator.end(); ++it)
		if (container[i] == value)
			return container[i];
	errno = 1;
	return iterator.end();
}

#endif
