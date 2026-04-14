/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:10:49 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/14 14:59:48 by fpaglia          ###   ########.fr       */
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
	static inData		_input;
	static std::string  _litteralNumbers[LITTERALNUMBER];
	
	// methods  ---------------------->
	static bool validateInput(const char* str);
	static bool isLitterals(std::string str);

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
