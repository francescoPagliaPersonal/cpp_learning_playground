/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:47:32 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/17 12:30:32 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>
# include <ostream>
# include <climits>

class Fixed 
{
	public:

	Fixed(void);
	Fixed(const int nbr);
	Fixed(const float nbr);
	Fixed(const Fixed& obj);
	Fixed& operator=(const Fixed& obj);
	~Fixed(void);
	
	bool	operator>(const Fixed& obj) const;
	bool	operator<(const Fixed& obj) const;
	bool	operator>=(const Fixed& obj) const;
	bool	operator<=(const Fixed& obj) const;
	bool	operator==(const Fixed& obj) const;
	bool	operator!=(const Fixed& obj) const;

	Fixed	operator+(const Fixed& obj) const;
	Fixed	operator-(const Fixed& obj) const;
	Fixed	operator*(const Fixed& obj) const;
	Fixed	operator/(const Fixed& obj) const;

	Fixed&	operator++(void);
	Fixed&	operator--(void);
	Fixed	operator++(int);
	Fixed	operator--(int);
	
	static Fixed&		max(Fixed& obj1, Fixed& obj2);
	static const Fixed&	max(const Fixed& obj1, const Fixed& obj2);
	static Fixed&		min(Fixed& obj1, Fixed& obj2);
	static const Fixed&	min(const Fixed& obj1, const Fixed& obj2);
	
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;
	
	private:

	static const int	_fractbit;
	int					_rawbits;
	int					_toRawBits(const int nbr);
	int					_toRawBits(const float nbr);
	
};

std::ostream& 			operator<<(std::ostream& ostream, Fixed const &obj);

#endif
