/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_glob.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtrin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:39:55 by rtrin             #+#    #+#             */
/*   Updated: 2020/08/09 22:58:55 by rtrin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*g_units[10] = { NULL };
char	*g_teens[9] = { NULL };
char	*g_tens[9] = { NULL };
char	*g_thou[23] = { NULL };

void	ft_set_unit(char *file, char *str, int pos)
{
	if (g_units[file[pos] - '0'])
		free(g_units[file[pos] - '0']);
	g_units[file[pos] - '0'] = str;
}

void	ft_set_tens_teens(char *file, char *str, int pos)
{
	if (file[pos] != '0' && file[pos + 1] == '0')
	{
		if (g_tens[file[pos] - '0' - 1])
			free(g_tens[file[pos] - '0' - 1]);
		g_tens[file[pos] - '0' - 1] = str;
	}
	else if (file[pos] == '1' && file[pos + 1] != '0')
	{
		if (g_teens[file[pos + 1] - '0' - 1])
			free(g_teens[file[pos + 1] - '0' - 1]);
		g_teens[file[pos + 1] - '0' - 1] = str;
	}
}

void	ft_set_thou(char *file, char *str, int pos, int num_len)
{
	int k;

	k = 1;
	while (k < num_len && file[pos + k] == '0')
		k++;
	if (k + 1 == num_len)
	{
		if (g_thou[num_len - 3])
			free(g_thou[num_len - 3]);
		g_thou[num_len - 3] = str;
	}
}
