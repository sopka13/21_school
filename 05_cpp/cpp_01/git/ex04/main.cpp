/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:28:16 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/01 22:23:51 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

int		main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << ERR_ARGS << std::endl;
		return (1);
	}

	std::string		name_file = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	std::string		name_out_file = name_file + OUTPUT_FORMAT;
	size_t			length_s1 = s1.length();

	std::ofstream	file_out(name_out_file, std::ios_base::out | std::ios_base::trunc);					//create object for output dile
	if (!file_out.is_open())
	{
		std::cout << ERR_CREATE << std::endl;
		return (1);
	}
	std::ifstream	file_in(name_file);
	if (!file_out.is_open())
	{
		std::cout << ERR_OPEN << std::endl;
		return (1);
	}

	int		i(0);
	int		k;
	char	ch;
	while ((ch = file_in.get()) && ch != EOF)
	{
		k = 0;
		if (ch == s1[k])
		{
			std::string	temp_str;
			temp_str.push_back(ch);
			while (ch != EOF && k < ((int)length_s1 - 1) && ch == s1[k])
			{
				ch = file_in.get();
				temp_str.push_back(ch);
				k++;
			}
			if (k == (int)length_s1 - 1)
				file_out << s2;
			else
				file_out << temp_str;
		}
		else
			file_out << ch;
		i++;
	}

	file_out.close();											//close file
	file_in.close();											//close file
	return (0);
}