/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 19:19:44 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/16 09:24:59 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

template<typename T>
void	swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T	min(T& a, T& b) {
	return a < b ? a : b;
}

template<typename T>
T	max(T& a, T& b) {
	return a > b ? a : b;
}
#endif 
