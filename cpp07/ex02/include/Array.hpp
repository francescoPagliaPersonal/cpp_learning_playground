/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 09:01:05 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/17 13:13:51 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

#include "ArrayException.hpp"
#include <stdexcept>

template<typename T>
class Array
{
	public:

	Array(void)		: _array(NULL), _size(0) {};
	Array(int n)	: _array(new T[_isPositive(n)]), _size(n) {};
	~Array(void)	{ delete [] _array; };
	Array(Array const & obj)
					: _array(new T[obj._size]), _size(obj._size)
					{ for (int i = 0; i < obj._size; ++i)
						_array[i] = obj[i];
					};
	Array&	operator=(Array const & obj) 
			{
				if (this == &obj)
					return *this;
				
				T* tmp = new T[obj._size];

				for (int i = 0; i < obj._size; i++)
					tmp[i] = obj._array[i];

				delete[] _array;
				_array = tmp;
				_size = obj._size;
				return *this;		
			};
	
	int		size(void) const {return _size;};
	
	class ArrayExceptRange : public ArrayException {
		public:
		ArrayExceptRange(std::string reason) 
			: ArrayException(reason) {};
		ArrayExceptRange(std::string reason, int value)
			: ArrayException(reason, value) {};
	};
	
	T&			operator[](int idx) 
				{  
					if (!(idx >= 0 && idx < _size)) 
						throw ArrayExceptRange("Value out of range.", idx) ;
					return _array[idx];
				};
	const T&	operator[](int idx) const 
				{  
					if (!(idx >= 0 && idx < _size)) 
						throw ArrayExceptRange("Value out of range.", idx) ;
					return _array[idx];
				};
	
	bool	operator==(Array const & obj) const {
													if (_size != obj._size)
														return false;
													for (int i = 0; i < _size; ++i)
													{
														if (_array[i] != obj._array[i])
															return false;
														return true;
													}
												};
	bool	operator!=(Array const & obj) const {return !(this == obj);};
	

	private:
	
	T			*_array;
	int			_size;
	int		_isPositive(int n) 
			{
				if (n < 0)
					throw ArrayExceptRange("Negative Value not allowed.", n);
				return n;
			};	
};

#endif
