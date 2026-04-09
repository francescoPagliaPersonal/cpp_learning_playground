/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:10:49 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/09 18:39:03 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

enum errCode {
	OK,
	NAN,
	NODISP,
	NOPOSS,
	ERRMAX
};

enum inType {
	CHAR,
	INTEGER,
	FLOAT,
	DOUBLE,
	MAXTYPE	
};

class ScalarConverter 
{
	public:

	static void convert(const char* str);
	
	
	private:
	
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& obj);
	~ScalarConverter(void);
	ScalarConverter& operator=(const ScalarConverter& obj);

	// inputs  ---------------------->

	unsigned long long  integer;
	unsigned long long  fraction;
	int					ilen;
	int					flen;
	int					sign;
	inType 				type;

	// returns ---------------------->
	char	rChr;
	int		rInt;
	double	rDou;
	float	rFlo;
		
};

#endif
