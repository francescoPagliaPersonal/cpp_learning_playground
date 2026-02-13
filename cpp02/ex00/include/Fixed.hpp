/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:47:32 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/13 09:35:34 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed 
{
	public:

	Fixed(void);
	Fixed(const Fixed& obj);
	Fixed& operator=(const Fixed& obj);
	~Fixed(void);
	
	int					getRawBits( void ) const;
	void				setRawBits( int const raw );
	
	private:

	static const int	_fractbit;
	int					_rawbits;
	
};

#endif

