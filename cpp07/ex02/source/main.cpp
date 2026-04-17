/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 09:00:45 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/17 13:14:18 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <Array.hpp>
#include "ArrayException.hpp"

#define MAX_VAL 5

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    std::cout << "\n DEFINED ARRAY SIZE (MAX VAL): "<< MAX_VAL << "\n" << std::endl;
	
    std::cout << "\n-------> My array vs integer array <------" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
		std::cout << "[ "<< i << " ] Array val: " << numbers[i] << std::endl;
		std::cout << "[ "<< i << " ] INT   val: " << mirror[i] << std::endl;
	}
    //SCOPE
    {
    	std::cout << "\n-------> copying operator <------" << std::endl;

    	Array<int> tmp = numbers;   
		Array<int> test(tmp);
        for (int i = 0; i < tmp.size(); i++) {
            std::cout << "[ "<< i << " ] = operator: " << tmp[i] << std::endl;
            std::cout << "[ "<< i << " ] copy costr: " << test[i] << std::endl;
        }            
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "\n-------> Check out of bound values <------" << std::endl;
	
    try
    {
        numbers[-2] = 0;
    }
    catch(const ArrayException& e)
    {
        std::cerr << "ARRAY ERROR: " << e.what() 
					<< " trying to access id : "<< e.getValue() << std::endl;
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const ArrayException& e)
    {
        std::cerr << "ARRAY ERROR: " << e.what() 
					<< " trying to access id : "<< e.getValue() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
