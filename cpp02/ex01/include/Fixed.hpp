/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:47:32 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/13 13:01:29 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>
# include <ostream>

class Fixed 
{
	public:

	Fixed(void);
	Fixed(const int nbr);
	Fixed(const float nbr);
	Fixed(const Fixed& obj);
	Fixed& operator=(const Fixed& obj);
	~Fixed(void);
	
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
