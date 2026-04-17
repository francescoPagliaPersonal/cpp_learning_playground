/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 09:01:05 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/17 09:53:35 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

#include <exception>
template<typename T>
class Array 
{
	public:

	Array(void);
	Array(int n);
	~Array(void);
	
	Array(Array const & obj);
	Array&	operator=(Array const & obj);
	int		size(void) const;
	
	T&			operator[](int idx);
	const T&	operator[](int idx) const;
	
	bool		operator==(Array const & obj) const;
	bool		operator!=(Array const & obj) const;
	bool		operator>=(Array const & obj) const;
	bool		operator<=(Array const & obj) const;
	bool		operator>(Array const & obj) const;
	bool		operator<(Array const & obj) const;

	class ArrayExceptRange : public std::exception {};

	private:
	
	T	*_array;
};

#endif
