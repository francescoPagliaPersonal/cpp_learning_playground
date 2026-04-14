#include "ScalarConverter.hpp"

std::string ScalarConverter::_litteralNumbers[LITTERALNUMBER] = {
	"inff",
	"+inff",
	"-inff",
	"nanf",
	"inf",
	"+inf",
	"-inf",
	"nan"
};

bool ScalarConverter::isLitterals(std::string str) {
	
	for (std::string::iterator it = str.begin(); it != str.end(); ++it ) 
		*it = std::tolower(static_cast<unsigned char>(*it));
	
	int i = 0;
	while (i < LITTERALNUMBER)
	{
		if (_litteralNumbers[i] == str)
			break ;
		++i;
	}
	if (i < LITTERALNUMBER / 2)
		_input.type = FLOAT;
	else if (i < LITTERALNUMBER)
		_input.type = DOUBLE;
	_input.litteral = i < LITTERALNUMBER;
	return (_input.litteral);
}
