/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 09:00:45 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/20 12:56:05 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <exception>
#include <iostream>
#include <Array.hpp>
#include <sstream>

#define MAX_VAL 5

int main(int, char**)
{
	srand(time(NULL));
	{
		std::cout << "\n\n========== T1 INT NEGATIVE ARRAY =============\n" << std::endl;
		try
		{
			std::cout << "setting up an array with size '-5'" << std::endl;
			Array<int> num(-5);
		}
		catch (std::exception& e )
		{
			std::cout << "ERROR: " << e.what() << std::endl;
			
		}
	}
	{
		
		std::cout << "\n\n========== T2 RETRIEVE OUT OF BOUND ITEMS =============\n" << std::endl;
	
		Array<int> numbers(MAX_VAL);
		try
		{
			
			std::cout << "TRYING number[-2]: " << std::endl;
			numbers[-2] = 0;
		}
		catch(const ArrayException& e)
		{
			std::cerr << "ARRAY ERROR: " << e.what() 
						<< " trying to access non existing id : "<< e.getValue() << std::endl;
		}
		try
		{
			std::cout << "TRYING number[MAX_VAL]: " << std::endl;

			numbers[MAX_VAL] = 0;
		}
		catch(const ArrayException& e)
		{
			std::cerr << "ARRAY ERROR: " << e.what() 
						<< " trying to access non existing id : "<< e.getValue() << std::endl;
		}
	}
	{
		std::cout << "\n\n========== T3 ARRAY CLASS VS ARRAY INT (INT*) =============\n" << std::endl;
		
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		
		std::cout << "\n-------> fill arrays with rand values <------\n" << std::endl;
		int i = 0;
		for (; i < MAX_VAL; i++)
		{
			const int value = (rand() % 256);
			numbers[i] = value;
			mirror[i] = value;
			std::cout << "["<< i << "] Array val: " << numbers[i] << std::endl;
			std::cout << "["<< i << "] INT   val: " << mirror[i] << std::endl;
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				break;
			}
		}
		if (i == MAX_VAL)
			std::cout << "\nNumbers array correctly built and tested against a standard INT ARR" << std::endl;
	    delete [] mirror;
	}
	{
		std::cout << "\n\n========== T4 ARRAY CLASS DEEP COPY =============\n" << std::endl;

		Array<int> numbers(MAX_VAL);
		for (int i = 0; i < MAX_VAL; i++)
			numbers[i] = (rand() % 256);

		std::cout << "\n-------> copying process <------" << std::endl;

		Array<int> tmp = numbers;   
		Array<int> test(tmp);
		for (int i = 0; i < tmp.size(); i++) {
			std::cout << "["<< i << "] numbers   : " << numbers[i] << std::endl;
			std::cout << "["<< i << "] = operator: " << tmp[i] << std::endl;
			std::cout << "["<< i << "] copy costr: " << test[i] << "\n" << std::endl;
		}            
		
		std::cout << "\n-------> editing values <------" << std::endl;
		
		for (int i = 0; i < MAX_VAL; i++){
			tmp[i] /= 2;
			test[i] *= 2; 
			std::cout << "["<< i << "] numbers   : " << numbers[i] << std::endl;
			std::cout << "["<< i << "] = operator: " << tmp[i] << std::endl;
			std::cout << "["<< i << "] copy costr: " << test[i] << "\n" << std::endl;
		}   
	}
	{
		std::cout << "\n\n========== T5 ARRAY CLASS STRINGS =============\n" << std::endl;
		
		Array<std::string>	letters(MAX_VAL);
		Array<std::string>	l_copy = letters;
		for (int i = 0; i < MAX_VAL; i++){
			letters[i].assign("Ciao core!");
			std::cout << "["<< i << "] letters   : " << letters[i] << std::endl;
		}
		for (int i = 0; i < MAX_VAL; i++){
			letters[i].replace(letters[i].begin() + i, letters[i].begin() + i + 4, " STOP " );
			std::cout << "["<< i << "] letters   : " << letters[i] ;
			if (letters[i] == l_copy[i]) {
				std::cout << " ERROR! letters should be modified!" << std::endl;
				break ;
			}
			else 
				std::cout << " ===> Successful edit!" << std::endl;
		}
	}
    return 0;
}
