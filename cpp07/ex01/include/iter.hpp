/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:08:02 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/20 11:54:41 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

#include <cstddef>

/* DISCLOSURE NOTE OVER THE NOT PROTECTION OF THE NULL ARRAY.
 *
 * this being a template doesn't have knowledge about the caller
 * any early termination creates a discrimant of the potential caller.
 * what if I want to have null values in my array? 
 * Imagine a vector of object that might need to be destroyed and replaced with a 
 * valid NULL value as an example.
 */
template<typename T>
void iter(T *arr, const std::size_t len, void (*f)(T const &))
{
	for (std::size_t i = 0; i < len; ++i)
		f(arr[i]);				
}

template<typename T>
void iter(T *arr, const std::size_t len, void (*f)(T &))
{
	for (std::size_t i = 0; i < len; ++i)
		f(arr[i]);				
}

/* This version could substitute completely the previous two 
 * which I leave in here because of my understanding of the exercise requirements.
 * It is interesting to see because in future c++(11+) the second Type 
 * allows the usage of labda operator that otherwise wouldn't be possible. 
 */
template<typename T, typename A>
void iter(T *arr, const std::size_t len, A f)
{
	for (std::size_t i = 0; i < len; ++i)
		f(arr[i]);				
}

#endif

