/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 19:19:44 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/16 10:31:12 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

template<typename T>
inline void	swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
inline const T&	min(const T& a, const T& b) {
	return a < b ? a : b;
}

template<typename T>
inline const T&	max(const T& a, const T& b) {
	return a > b ? a : b;
}

#endif 
