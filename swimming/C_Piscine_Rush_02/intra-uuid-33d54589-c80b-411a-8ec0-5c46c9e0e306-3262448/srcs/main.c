/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtrin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 11:52:22 by rtrin             #+#    #+#             */
/*   Updated: 2020/08/09 23:14:04 by rtrin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		g_err = 0;
int		g_num_len = 0;
char	*g_dict_name = "numbers.dict";
char	*g_num_str = NULL;

int	main(int argc, char *argv[])
{
	if (argc >= 1 && argc <= 3)
	{
		if (argc == 1)
			ft_read_input();
		else if (argc == 2)
			g_num_str = argv[1];
		else
		{
			g_dict_name = argv[1];
			g_num_str = argv[2];
		}
		ft_validate_number();
		if (g_err == 0)
			ft_parse_dict();
	}
	else
		g_err = 1;
	if (g_err == 0)
	{
		ft_num_convert(g_num_len, 0);
		write(1, "\n", 1);
	}
	else
		ft_print_err();
	return (g_err);
}
