#include "ScalarConverter.hpp"


/* Given a string validate if the input is properly formatted.
 * Check if it is a litteral non numerical value
 * Starts with a +/- sign (optional)
 * Has an interrupted series of numbers.
 * Has at most one dot "." (optional)
 * Ends with "f" (optional)
 *
 * Returns
 * Fill up the "input" inData structure 
 */
bool ScalarConverter::validateInput(const char* str) {
	
	_input.litteral = 0;
	_input.type = NOTATYPE;
	_input.str.assign(str);
	
	std::string& tmp = _input.str;
	std::string::iterator it = tmp.begin();
	
	if (!std::isdigit(static_cast<unsigned char>(*it))
		&& (std::isprint(static_cast<unsigned char>(*it)) 
		&& (it + 1 == tmp.end()))) {
		_input.type = CHAR;
		return true;
	}

	if (isLitterals(tmp))
		return true;
	
	if (*it == '+' || *it == '-'){
		// *it == '+' ? _input.sign =	1 : _input.sign = -1;
		++it;
	}
	
	int dot = 0;
	int char_f = 0;
	while (it != tmp.end())
	{
		if (!std::isdigit(static_cast<unsigned char>(*it)))
			break;
		++it;
	}
	if (it != tmp.end()) {
		if (*it == '.')
			dot = 1;
		else if (static_cast<unsigned char>(std::tolower(*it)) == 'f')
			char_f = 1;
		else 
			return false;
		++it;
	}
	if (dot == 1) {
		if (!std::isdigit(static_cast<unsigned char>(*it)))
			return false;
		else {
			while (it != tmp.end())
			{
				if (!std::isdigit(static_cast<unsigned char>(*it)))
					break;
				++it;
			}
		}
		if (*it == 'f') {
			char_f = 1;
			++it;	
		}
	}
	if (it != tmp.end())
		return false;
	
	dot == 1 ? _input.type = DOUBLE : _input.type = INTEGER;
	char_f == 1 ? _input.type = FLOAT : _input.type = _input.type;
	return true;
}