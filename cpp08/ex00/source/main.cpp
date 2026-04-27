/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:48:47 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/27 10:44:14 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <algorithm>
#include <deque>
#include <vector>
#include <list>
#include <cstddef>
#include <iostream>
#include <errno.h>

int main(void)
{
	const int	num[] = {0, 2, 4, 8, 16, 32, 64, 128 };
	
	{
		
		std::cout << "\n\n========== T0 std::find =============\n" << std::endl;

		
		std::list<int> contOfNum;
		std::list<int>::iterator it;

		for (std::size_t i = 0; i < sizeof(num)/sizeof(num[0]); ++i)
			contOfNum.push_back(num[i]);
	
		it = std::find(contOfNum.begin(), contOfNum.end(), 32);
		if (it  != contOfNum.end())
			std::cout << "std::find     :" << *it << std::endl;
		else
			std::cout << "no item found, error no: "<< errno << std::endl;	
	
		errno = 0;

		it = std::find(contOfNum.begin(), contOfNum.end(), 33);
		if (it  != contOfNum.end())
			std::cout << "std::find     :" << *it << std::endl;
		else
			std::cout << "no item found, error no: "<< errno << std::endl;	
	
		std::cout << "\n\n========== T1 LIST =============\n" << std::endl;
	
		it = ::easyfind(contOfNum, 32);
		if (it != contOfNum.end())
			std::cout << "easyfind      :" << *it << std::endl;
		else
			std::cout << "no item found, error no: "<< errno << std::endl;	
		
		
		it = ::easyfind(contOfNum, 33);
		if (it != contOfNum.end())
			std::cout << "easyfind      :" << *it << std::endl;
		else
			std::cout << "no item found, error no: "<< errno << std::endl;	
		
		errno = 0;
		std::cout << "\nerrno resetted: "<< errno << std::endl;
		
	}
	{
		std::cout << "\n\n========== T2 VECTOR =============\n" << std::endl;

		std::vector<int> contOfNum(sizeof(num)/sizeof(num[0]));
		std::vector<int>::iterator it;

		for (std::size_t i = 0; i < sizeof(num)/sizeof(num[0]); ++i)
			contOfNum[i] = num[i];
		
		
		it = ::easyfind(contOfNum, 32);
		if (it != contOfNum.end())
			std::cout << "easyfind      :" << *it << std::endl;
		else
			std::cout << "no item found, error no: "<< errno << std::endl;	

		errno = 0;
		
		it = ::easyfind(contOfNum, 33);
		if (it != contOfNum.end())
			std::cout << "easyfind      :" << *it << std::endl;
		else
			std::cout << "no item found, error no: "<< errno << std::endl;		
		
		errno = 0;
		std::cout << "\nerrno resetted: "<< errno << std::endl;
	}
	{
		std::cout << "\n\n========== T3 DEQUE =============\n" << std::endl;

		std::deque<int> contOfNum;
		std::deque<int>::iterator it;

		for (std::size_t i = 0; i < sizeof(num)/sizeof(num[0]); ++i)
			contOfNum.push_back(num[i]);
		
		
		it = ::easyfind(contOfNum, 32);
		if (it != contOfNum.end())
			std::cout << "easyfind      :" << *it << std::endl;
		else
			std::cout << "no item found, error no: "<< errno << std::endl;	

		errno = 0;

		it = ::easyfind(contOfNum, 33);
		if (it != contOfNum.end())
			std::cout << "easyfind      :" << *it << std::endl;
		else
			std::cout << "no item found, error no: "<< errno << std::endl;	
		
	}
}
