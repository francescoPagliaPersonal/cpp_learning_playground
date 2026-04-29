/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:13:30 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/29 15:36:05 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

#include <deque>
#include <vector>
#include <string>
#include <iostream>

class PmergeMe 
{
	public: 
	
	PmergeMe(void);
	PmergeMe(const PmergeMe & obj);
	~PmergeMe(void);
	PmergeMe& operator=(const PmergeMe & obj);
	
	void 	ingest(const char **arr);
	int		mergeSort(std::vector<int> & db);
	int		mergeSort(std::deque<int> & db);
	void	print(void);
	
	private:
	std::vector<int>	_sourceItems;
	std::vector<int>	_vItems;
	std::deque<int>		_dItems;
	
	template<typename T>
	void _printIterable(std::string title, T const & obj) {
		std::cout << "\nPRINTING "<< title << ": "<< std::endl;
		typename T::const_iterator it = obj.begin();
		typename T::const_iterator ite = obj.end();
		if (it == ite)
			return;
		--ite;
		while (it != ite )
		{
			std::cout << *it << ", ";
			++it;
		}
		std::cout << *it << "." << std::endl;
	}
};

#endif
