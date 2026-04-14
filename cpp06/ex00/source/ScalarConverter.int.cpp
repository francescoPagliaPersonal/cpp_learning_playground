#include "ScalarConverter.hpp"
#include <errno.h>
#include <cstdlib>


bool ScalarConverter::convertInt(scalars *conv) {
	const char *str = _input.str.c_str();
	char *end;
	errno = 0;
	long num = std::strtol(str, &end, 10);
	if (errno != 0)	{
		setError(conv);
		return false;
	}
	
	if (!fitsInteger(num)){
		setError(conv);
		return false;
	}
	
	conv->nbri = num;
	conv->nbri_status = OK;
	intToChar(num, conv);
	conv->nbrf = static_cast<float>(num);
	if (num == static_cast<int>(conv->nbrf))
		conv->nbrf_status = OK;
	else
	 	conv->nbrf_status = NOPOSS;
	conv->nbrd = static_cast<double>(num);
	if (num == static_cast<int>(conv->nbrd))
		conv->nbrd_status = OK;
	else
	 	conv->nbrd_status = NOPOSS;
	return true;		
}
