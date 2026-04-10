/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:10:49 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/10 18:23:33 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include <cmath>
# include <string>

enum nbrStatus {
	OK,
	NODISP,
	NOPOSS,
	ERRMAX
};

enum inType {
	CHAR,
	INTEGER,
	DOUBLE,
	FLOAT,
	MAXTYPE	
};

struct inData {
	std::string 	str;
	inType			type;
	nbrStatus		status;
};

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

	static bool convert(const char* str);
	
	
	private:
	
	// inputs   ---------------------->
	static inData		input;
	static outData		convertions;
	
	// methods  ---------------------->
	static bool validateInput(const char* str);
	static bool	strToData(inData input);
	static bool checkLitterals(const std::string& str);
	static void setOutput();
	static void setOutput(char c);
	static void setOutput(int nbri);
	static void setOutput(float nbrf);
	static void setOutput(double nbrd);
	
	// blocked constructors ---------->
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& obj);
	~ScalarConverter(void);
	ScalarConverter& operator=(const ScalarConverter& obj);

	
	
		
};

#endif
