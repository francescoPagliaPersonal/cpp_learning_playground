/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 00:03:54 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/15 00:03:57 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Data.hpp"
# include "Serializer.hpp"
# include <iostream>
int main()
{
	Data *ptr = new Data;
	// Data *ptr = NULL;
	uintptr_t num = Serializer::serialize(ptr);
	Data *revptr = Serializer::deserialize(num);
	if (ptr != NULL) {
		std::cout << "original ptr : " << ptr << "  " << *ptr << "\n"
				  << "casted prt   : " << reinterpret_cast<void *>(num)  
				  << "  " << *revptr << std::endl;
	}
	else {
		std::cout << "original ptr : " << ptr << "  " << "NULL pointer\n"
				  << "casted prt   : " << reinterpret_cast<void *>(num)  
				  << "  " <<  "NULL pointer" << std::endl;
	}
	if (ptr == revptr)
		std::cout << "original and deserialized pointer match" << std::endl;
	delete ptr;
}
