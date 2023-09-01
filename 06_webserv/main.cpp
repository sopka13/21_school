/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 08:05:16 by eyohn             #+#    #+#             */
/*   Updated: 2021/10/17 13:18:34 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include <dirent.h>

int		main(void)
{
	char*			path = "./git/sites_avaliable/test/YoupiBanane/";
	DIR*			dirp;
	struct dirent*	dp;

	// step 2: Construct html
	if ((dirp = opendir(path)))
	{
		while ((dp = readdir(dirp)) != NULL)
		{
			std::cout << "###############" << std::endl;
			std::cout << "d_ino: " << dp->d_ino << std::endl;
			std::cout << "d_name: " << dp->d_name << std::endl;
			std::cout << "d_off: " << dp->d_off << std::endl;
			std::cout << "d_reclen: " << dp->d_reclen << std::endl;
			std::cout << "d_type: " << dp->d_type << std::endl;
		}
	}
	else
		std::cout << "Open error" << std::endl;
	return (0);
}