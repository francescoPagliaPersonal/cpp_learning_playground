/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Looser.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 23:03:40 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/10 12:16:59 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Looser.hpp"

Looser::Looser(std::string file, std::string s1, std::string s2)
	: _filename(file), _s1(s1), _s2(s2) {
		this->_fileout.assign("");
	};

Looser::Looser(std::string file, std::string s1, std::string s2, std::string fileout)
	: _filename(file), _s1(s1), _s2(s2), _fileout(fileout) {};

Looser::~Looser(void) {};

std::string	Looser::get_output_filename(void) const 
{
	return _fileout;
}

const std::string	_build_filename(const std::string& str)
{
	std::string::size_type dot = str.find_last_of(".");
	if (dot == str.npos)
		return (str + ".replace");
	else
	{
		std::string	name = str.substr(0, dot);
		std::string	ext = str.substr(dot, str.npos);
		return (name + ".replace" + ext);
	}	
}

bool	Looser::replace(void)
{
	std::string outname;
	if (_fileout.length() == 0)
		outname = _build_filename(_filename);
	else
		outname = _fileout;
	
	std::ifstream	infs(this->_filename.c_str());
	std::ofstream	outfs(outname.c_str());

	if (!infs.is_open() && !outfs.is_open())
		return (false);
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
				infs.unget();
			} else {
				outfs << ch;
			}
		}
	}
	infs.close();
	outfs.close();
	_fileout = outname;
	return (true);
}
