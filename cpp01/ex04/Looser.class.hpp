/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Looser.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:49:28 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/09 14:54:37 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOSER_CLASS_H
# define LOOSER_CLASS_H

#include <fstream>
#include <string>
#include <iostream>

class Looser 
{
	public:

	Looser(std::string file, std::string s1, std::string s2);
	~Looser(void);
	bool	replace(void);
	// bool	replace(std::string fileout);

	private:

	std::string		_filename;
	std::string 	_s1;
	std::string 	_s2;
};

#endif
