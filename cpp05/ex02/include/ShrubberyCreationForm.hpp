#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# define REGRAD_SIGN 145
# define REGRAD_EXEC 137

#include "AForm.hpp"


class ShrubberyCreationForm : public AForm 
{
	public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& obj);
	~ShrubberyCreationForm(void);

	virtual bool 	execute(Bureaucrat const & executor) const;
	std::string 	getTarget() const;
 
	// TODO: setup the exception to throw in the the Forms 

	private:
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& obj);
	ShrubberyCreationForm(void);

	std::string		_target;
};

#endif
 