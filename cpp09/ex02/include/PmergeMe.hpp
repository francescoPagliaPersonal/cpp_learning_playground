/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:13:30 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/05 17:27:30 by fpaglia          ###   ########.fr       */
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


	
	struct numid_s {
		int					value;
		std::vector<size_t>	index; 

		numid_s(void) : value(-1) {} ;
		numid_s(int v) : value(v) {} ;
    	numid_s(int v, size_t idx) : value(v) { index.push_back(idx); } ;
	};
	
	typedef std::vector<numid_s>::size_type	vec_id;
	typedef std::vector<numid_s>::iterator	vec_it;

	// struct pair_s {
	// 	numid_s		winner;
	// 	numid_s		looser;
	// };

	
	private:
	
	std::vector<int>	_sourceItems;
	std::vector<int>	_vItems;
	std::deque<int>		_dItems;
	size_t				_vCounter;
	size_t				_dCounter;
	
	template<typename T>
	void	_printIterable(std::string title, T const & obj);
	void	_compare_pairs(std::vector<numid_s> & incoming, int level);
	void	print_pairs_info(std::vector<numid_s> const & looser, std::vector<numid_s> const & winner, int level);
	void	_insert_looser(std::vector<numid_s> & container, vec_it start, vec_it end, numid_s num);
	void 	_insert_array(std::vector<numid_s> & container, vec_id id_start, vec_id id_end, std::vector<numid_s> & winner, std::vector<numid_s> & looser );
	// std::vector<winner_s> & _merge(std::vector<winner_s> & winners);

};

#include "PmergeMe.tpp" 

#endif
