/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:10:49 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/14 13:31:23 by fpaglia          ###   ########.fr       */
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
 * the possiblitiy of being a litteral (inf/nan/etc)
 */
struct inData {
	std::string 	str;
	inType			type;
	int 			litteral; 
};

/* 
 */
struct scalars {
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
