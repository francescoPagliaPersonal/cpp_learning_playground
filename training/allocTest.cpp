
#include <iostream>

int main()
{
	int *a = new int(5);
	int  b = 5;
	std::cout << a << " " << *a << std::endl;
	std::cout << &a << " " << *a << std::endl;
	std::cout << &b << " " << b << std::endl;
}