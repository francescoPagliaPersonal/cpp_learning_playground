#include "ScalarConverter.hpp"

bool ScalarConverter::convertLitteral(scalars *conv, double num) {
	
	conv->nbrc_status = NOPOSS;
	conv->nbri_status = NOPOSS;
	
	conv->nbrf = static_cast<float>(num);
	conv->nbrf_status = OK;

	conv->nbrd = num;
	conv->nbrd_status = OK;
	
	return true;
}
