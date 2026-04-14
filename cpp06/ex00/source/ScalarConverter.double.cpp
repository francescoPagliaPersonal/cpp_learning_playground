#include "ScalarConverter.hpp"
#include <errno.h>
#include <cstdlib>


bool ScalarConverter::convertDouble(scalars *conv) {
	const char *str = _input.str.c_str();
	char *end;
	errno = 0;
	double num = std::strtod(str, &end);
	if (errno != 0)	{
		setError(conv);
		return false;
	}

	if (_input.litteral) {
		convertLitteral(conv, num);
		return true;
	}
	
	conv->nbrd = num;
	conv->nbrd_status = OK;
	
	if (!fitsFloat(num)){
		conv->nbrf_status = NOPOSS;
	}
	else {
		conv->nbrf = static_cast<float>(num);
		conv->nbrd == static_cast<double>(conv->nbrf)
			? conv->nbrf_status = OK
		 	: conv->nbrf_status = NOPOSS;
	}
	if (!fitsInteger(static_cast<long>(std::ceil(conv->nbrd))))
		conv->nbri_status = NOPOSS;
	else {
		conv->nbri = static_cast<int>(std::ceil(conv->nbrd));
		num ==  static_cast<int>(conv->nbri) 
			? conv->nbri_status = OK 
			: conv->nbri_status = NOPOSS; 
	} 
	if (conv->nbri_status == OK )
		intToChar(conv->nbri, conv);
	else
		(conv->nbrc_status = NOPOSS);
	return true;
}