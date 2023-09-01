/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:49:28 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/29 12:20:36 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define LEIGTH 255

class user
{
public:
	int			size[5];
	std::string	field[5];
};

class contact_book
{
private:
	int			i;
	int			k;
	int			index;
	user		contact[8];
public:
	contact_book ()
	{
		index = 0;
		for (int i = 0; i < 8; ++i)
		{
			for (int k = 0; k < 5; ++k)
				contact[i].size[k] = 0;
		}
	}
	void ft_add (void)
	{
		if (index > 7)
			index = 0;
		std::cout << "Enter first name: ";
		getline(std::cin, contact[index].field[0]);
		contact[index].size[0] = contact[index].field[0].length();
		std::cout << "Enter last name: ";
		getline(std::cin, contact[index].field[1]);
		contact[index].size[1] = contact[index].field[1].length();
		std::cout << "Enter nickname: ";
		getline(std::cin, contact[index].field[2]);
		contact[index].size[2] = contact[index].field[2].length();
		std::cout << "Enter phone number: ";
		getline(std::cin, contact[index].field[3]);
		contact[index].size[3] = contact[index].field[3].length();
		std::cout << "Enter darkest secret: ";
		getline(std::cin, contact[index].field[4]);
		contact[index].size[4] = contact[index].field[4].length();
		std::cout << "Done" << std::endl;
		if (contact[index].size[0] + contact[index].size[1] + contact[index].size[2] + contact[index].size[3] + contact[index].size[4] != 0)
			index++;
	}
	void ft_search (void)
	{
		i = -1;
		while (++i < 8)
		{
			if (contact[i].size[0] + contact[i].size[1] + contact[i].size[2] + contact[i].size[3] + contact[i].size[4] == 0)
				continue ;
			k = -1;
			std::cout << i + 1;
			std::cout << '|';
			while (++k < 3)
			{
				if (contact[i].size[k] == 0)
				{
					int r = -1;
					while (++r < 10)
						std::cout << ' ';
					std::cout << '|';
					continue ;
				}
				if (contact[i].size[k] > 10)
				{
					std::cout << contact[i].field[k].substr(0, 9);
					std::cout << '.';
				}
				else
				{
					int p = 1;
					while ((p++ + contact[i].size[k]) <= 10)
						std::cout << ' ';
					std::cout << contact[i].field[k].substr(0, contact[i].size[k]);
				}
				std::cout << '|';
			}
			std::cout << '\n';
		}
		i = 0;
		std::cout << "Enter index of contact: ";
		std::cin >> i;
		--i;
		if (i < 0 || i > 8 ||
			contact[i].size[0] + contact[i].size[1] + contact[i].size[2] + contact[i].size[3] + contact[i].size[4] == 0)
		{
			std::cout << "Index does not exist" << std::endl;
			return ;
		}
		else
		{
			std::cout << "First name: ";
			std::cout << contact[i].field[0] << std::endl;
			std::cout << "Last name: ";
			std::cout << contact[i].field[1] << std::endl;
			std::cout << "Nickname: ";
			std::cout << contact[i].field[2] << std::endl;
			std::cout << "Phone number: ";
			std::cout << contact[i].field[3] << std::endl;
			std::cout << "Darkest secret: ";
			std::cout << contact[i].field[4] << std::endl;
			return ;
		}
	}
};

int				main(void)
{
	contact_book	book;
	std::string	get_str;

	while (1)
	{
		getline(std::cin, get_str);
		if (!(get_str.compare("ADD")))
			book.ft_add();
		else if (!(get_str.compare("SEARCH")))
			book.ft_search();
		else if (!(get_str.compare("EXIT")))
			exit (0);
	}
	return (0);
}