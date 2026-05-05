/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:13:30 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/05 13:04:36 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

#include <cstddef>
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
	

	protected:
	
	struct winner_s {
		int					value;
		std::vector<size_t>	index; 
	};
	
	struct pair_s {
		int		winner;
		int		looser;
	};

	
	private:
	
	std::vector<int>	_sourceItems;
	std::vector<int>	_vItems;
	std::deque<int>		_dItems;
	size_t				_vCounter;
	size_t				_dCounter;
	
	template<typename T>
	void _printIterable(std::string title, T const & obj);

	std::vector<winner_s> & _merge(std::vector<winner_s> & winners);

};

#include "PmergeMe.tpp" 

#endif
