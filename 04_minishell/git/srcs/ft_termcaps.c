/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcaps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:38:53 by ssandman          #+#    #+#             */
/*   Updated: 2021/06/05 12:18:54 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		put_int(int c)
{
	write(1, &c, 1);
	return (0);
}

void	print_symbol(char *buff, t_tc *tmc)
{
	int ret;

	tmc->cmd[tmc->i] = *buff;
	tmc->cmd[tmc->i + 1] = '\0';
	if ((ret = isatty(0)) == 1)
	{
		if ((int)ft_strlen(STR) + tmc->i + 1 == tmc->co)
		{
			put_int(*buff);
			write(1, "\n", 2);
		}
		else
			put_int(*buff);
	}
	tmc->i++;
}

void	bibip(void)
{
	char	*beep;

	beep = tgetstr("bl", NULL);
	if (beep == NULL)
		return ;
	tputs(beep, 1, put_int);
}

void	clear_eol(void)
{
	char	*cl_toend;

	cl_toend = tgetstr("ce", NULL);
	if (cl_toend == NULL)
		return ;
	tputs(cl_toend, 1, put_int);
}

void	clear_down(void)
{
	char	*cl_down;

	cl_down = tgetstr("cd", NULL);
	if (cl_down == NULL)
		return ;
	tputs(cl_down, 1, put_int);
}
