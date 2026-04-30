/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 09:31:43 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/30 09:35:44 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
void PmergeMe::_printIterable(std::string title, T const & obj) {
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
