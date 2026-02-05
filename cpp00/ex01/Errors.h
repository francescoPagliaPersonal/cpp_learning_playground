#ifndef ERRORS_H
# define ERRORS_H

# include <string>
typedef enum e_return {
	OK,
	E_EOF,
	E_ASCII,
	E_PHONE,
	E_INDEX,
	E_MAX
} t_ret;

extern std::string		error_messages[];
# endif
