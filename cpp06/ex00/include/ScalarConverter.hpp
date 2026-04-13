/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:10:49 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/13 16:03:23 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include <cmath>
# include <string>

# define LITTERALNUMBER 8

enum nbrStatus {
	OK,
	NODISP,
	NOPOSS,
	MAXERR
};

enum inType {
	CHAR,
	INTEGER,
	FLOAT,
	DOUBLE,
	NOTATYPE,
	MAXTYPE	
};

/* Input data stores: 
 * the validated std::string 
 * the datatype evaluated
 * the sign :
 *		-1 = negative
 *		0  = no sign
 *		+1 = positive
 */
struct inData {
	std::string 	str;
	inType			type;
	int 			sign; 
};

/* 
 */
struct outData {
	char			nbrc;
	nbrStatus		nbrc_status;
	int 			nbri;
	nbrStatus		nbri_status;
	float 			nbrf;
	nbrStatus		nbrf_status;
	double 			nbrd;
	nbrStatus		nbrd_status;	
};


class ScalarConverter 
{
	public:

	static bool convert(const char* str, outData *conv);
	
	
	private:
	
	// inputs   ---------------------->
	static inData		_input;
	static std::string  _littNum[LITTERALNUMBER];
	
	// methods  ---------------------->
	static bool validateInput(const char* str);
	static bool checkLitterals(std::string str);

	static bool convertChar(outData *conv);
	static bool convertInt(outData *conv);
	static bool convertFloat(outData *conv);
	static bool convertDouble(outData *conv);
	static bool convertNone(outData *conv);
	
	// blocked constructors ---------->
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& obj);
	~ScalarConverter(void);
	ScalarConverter& operator=(const ScalarConverter& obj);
		
};

#endif
