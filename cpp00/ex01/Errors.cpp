#include "Errors.h"

std::string		error_messages[E_MAX] = {
	"",
	"EOF sent, message interrupted.",
	"Non ascii character added, operation aborted.",
	"Not a valid phone number please use only:  \"0123456789.+\"",
	"ID not found"
};