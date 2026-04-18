/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:08:02 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/16 13:16:34 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H


typedef unsigned long size_t;


template<typename T>
void iter(T *arr, const size_t len, void (*f)(T const &))
{
	for (size_t i = 0; i < len; ++i)
		f(arr[i]);				
}

template<typename T>
void iter(T *arr, const size_t len, void (*f)(T &))
{
	for (size_t i = 0; i < len; ++i)
		f(arr[i]);				
}

template<typename T, typename A>
void iter(T *arr, const size_t len, A f)
{
	for (size_t i = 0; i < len; ++i)
		f(arr[i]);				
}

#endif

