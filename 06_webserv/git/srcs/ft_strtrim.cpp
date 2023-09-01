/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 08:31:52 by eyohn             #+#    #+#             */
/*   Updated: 2021/10/14 14:24:00 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"

/*
** This function truncates the passed characters at the beginning and end
** of the line
**	return (0) - Success
**	return (1) - String is empty
*/

static int		ft_equal(char a, std::string chars)
{
	/*
	** Search 'a' character in the chars
	** return (1) - Found
	** return (0) - Not found
	*/

	for (int i = 0; i < static_cast<int>(chars.length()); ++i)
		if (a == chars[i])
			return (1);
	return (0);
}

int		ft_strtrim(std::string &str, std::string chars)
{
	if (str.empty())
		return (1);

	std::string::iterator	start = str.begin();
	std::string::iterator	end = str.end();

	while (str.length() && ft_equal((*start), chars))
	{
		str.erase(start);
		start = str.begin();
	}

	end--;
	while (str.length() && ft_equal((*end), chars))
	{
		str.erase(end);
		end--;
	}
	return (0);
}
