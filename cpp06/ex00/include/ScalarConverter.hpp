/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:10:49 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/14 15:23:29 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include <cmath>
# include <string>
# include "scalarStruct.hpp"

# define LITTERALNUMBER 8

class ScalarConverter 
{
	public:

	static bool convert(const char* str, scalars *conv);
	
	
	private:
	
	// inputs   ---------------------->
	static std::string	_in_str;
	static inType		_in_type;
	static int 			_in_litteral;
	
	static std::string  _litteralNumbers[LITTERALNUMBER];
	
	// methods  ---------------------->
	// --- parse input
	static bool validateInput(const char* str);
	static bool isLitterals(std::string str);

	// --- conversion 
	static bool convertChar(scalars *conv);
	static bool convertInt(scalars *conv);
	static bool convertFloat(scalars *conv);
	static bool convertDouble(scalars *conv);
	static bool convertLitteral(scalars *conv, double num);
	static bool convertNone(scalars *conv);

	//helpers  ---------------------->
	static void setError(scalars *conv);
	static bool fitsInteger(long num);
	static bool fitsFloat(double num);
	static void intToChar(int num, scalars *conv) ;
	
	// blocked constructors ---------->
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& obj);
	~ScalarConverter(void);
	ScalarConverter& operator=(const ScalarConverter& obj);
		
};

#endif
