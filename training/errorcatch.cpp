# include <stdexcept>
# include <iostream>


double divide(int a, int b)
{
	if (b == 0)
		throw std::invalid_argument("impossible to divide by 0!");
	return ((double)a / b);
}

double divide(const char *a, const char *b)
{
	int num_a;
	int num_b;
	try {
		num_a = std::stoi(a);
		num_b = std::stoi(b);
	}
	catch (std::exception& err){
		throw err.what();
	}
	if (num_b == 0)
		throw std::invalid_argument("impossible to divide by 0!");
	return ((double)num_a / num_b);
}

int main(int ac, char **av)
{
	if (ac != 3)
		return ( std::cout << av[0] << " {divisor} {dividend}" << std::endl, 1);
	try {
		std::cout << divide(av[1], av[2]) << std::endl;
	}
	catch (std::exception& err) {
		std::cout << err.what() << std::endl;
	}

}
