/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_in_log_file.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 22:12:46 by eyohn             #+#    #+#             */
/*   Updated: 2021/10/14 14:24:15 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function write get str in log file
*/

#include "../includes/headers.hpp"

void		ft_write_in_log_file(t_vars *vars, const char *str)
{
	time_t	now = time(0);
	std::string		date(ctime(&now));
	date.erase(date.end() - 1);

	// vars->print_in_log.lock();
	*(vars->log_file) << date << ": " << str << std::endl;
	// vars->print_in_log.unlock();
	return ;
}
