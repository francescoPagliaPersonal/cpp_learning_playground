/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Looser.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:03:40 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/09 23:03:43 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Looser.class.hpp"

Looser::Looser(std::string file, std::string s1, std::string s2)
	: _filename(file), _s1(s1), _s2(s2) {};

Looser::~Looser(void) {};

bool	Looser::replace(void)
{
	std::string		outname = _filename + ".replace";
	std::ifstream	infs(this->_filename);
	std::ofstream	outfs(outname);

	if (infs.is_open())
	{
		std::string tmp("");
		size_t i = 0;
		char ch;
		while (infs.get(ch))
		{
			if (ch == _s1[i]) {
				tmp += ch;
				i++;
				if (i == _s1.length()) {
					outfs << _s2;
					tmp.clear();
					i = 0;
				}
			}
			else {
				if (i > 0) {
					outfs << tmp[0];
					tmp.erase(0, 1);
					i = tmp.length();
					infs.unget(); // retry current char
				} else {
					outfs << ch;
				}
			}
		}
		infs.close();
		outfs.close();
		return (1);
	}
	return (0);
}
