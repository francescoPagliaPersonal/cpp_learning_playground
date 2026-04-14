#include "ScalarConverter.hpp"


bool ScalarConverter::convertChar(scalars *conv) {
	conv->nbrc = _input.str.c_str()[0];
	conv->nbrc_status = OK;
	conv->nbri = static_cast<int>(conv->nbrc);
	conv->nbri_status = OK;
	conv->nbrd = static_cast<double>(conv->nbri);
	conv->nbrd_status = OK;
	conv->nbrf = static_cast<float>(conv->nbrd);
	conv->nbrf_status = OK;
	return true;
}