#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cout	<< "Error\n"
					<< "conversion cannot be executed.\n\n"
					<< "Example usage:\n"
					<< av[0] << " c     # to convert a character\n"
					<< av[0] << " 42    # to convert an integer\n"
					<< av[0] << " 42.0f # to convert a float\n"
					<< av[0] << " 42.0  # to convert a double\n\n"
					<< "Please note that for character conversion only a single char is allowed.\n"
					<< std::endl;
		return 1;
	}

	const char	*str = av[1];
	char		*end = NULL; 
	double		nbrd = std::strtod(str,&end);
	if (str == end) 
		std::cout << *str << *end << "  only one value!" << std::endl;
	else
		std::cout  << *str << *end << "  there are leftovers!!" << std::endl;;
	float		nbrf = (float)nbrd;
	int			nbri = (int)nbrd;
	char		nbrc = (char)nbrd;
	// nbrd = -INFINITY; 
	// nbrf =  (float)nbrd;

	std::cout << std::fixed << std::setprecision(1)
			  << "char   : " << nbrc << "\n"   
			  << "int    : " << nbri << "\n"
			  << "float  : " << nbrf << "f\n" 
			  << "double : " << nbrd << "\n" << std::endl;
}