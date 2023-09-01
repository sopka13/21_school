/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:35:46 by ssandman          #+#    #+#             */
/*   Updated: 2021/06/05 12:12:05 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	upkey(t_tc *tmc)
{
	tmc->inhist = 1;
	if (tmc->acthist == 1)
	{
		tputs(save_cursor, 1, put_int);
		tmc->hist->current = tmc->hist->tail;
		ft_bzero(tmc->cmd, BUF);
		ft_strcpy(tmc->cmd, tmc->hist->current->cmd);
		write(1, tmc->cmd, ft_strlen(tmc->hist->current->cmd));
		clear_down();
		tmc->acthist = 2;
	}
	else if (tmc->acthist == 2)
	{
		if (tmc->hist->current->prev == NULL)
			return ;
		tmc->hist->current = tmc->hist->current->prev;
		tputs(restore_cursor, 1, put_int);
		clear_down();
		ft_bzero(tmc->cmd, BUF);
		ft_strcpy(tmc->cmd, tmc->hist->current->cmd);
		write(1, tmc->cmd, ft_strlen(tmc->hist->current->cmd));
	}
	tmc->i = ft_strlen(tmc->cmd);
}

void	downkey(t_tc *tmc)
{
	if (tmc->inhist == 0)
	{
		bibip();
		return ;
	}
	if (tmc->hist->current->next == NULL)
	{
		tputs(restore_cursor, 1, put_int);
		clear_down();
		tmc->inhist = 0;
		tmc->acthist = 1;
		ft_bzero(tmc->cmd, BUF);
		tmc->i = 0;
		return ;
	}
	else
	{
		tmc->hist->current = tmc->hist->current->next;
		tputs(restore_cursor, 1, put_int);
		clear_down();
		ft_strcpy(tmc->cmd, tmc->hist->current->cmd);
		write(1, tmc->cmd, sizeof(char) * ft_strlen(tmc->hist->current->cmd));
	}
	tmc->i = ft_strlen(tmc->cmd);
}

void	backspace(t_tc *tmc)
{
	int	off;

	off = tmc->co;
	if (tmc->i > 0)
	{
		if ((tmc->i + (int)ft_strlen(STR) == tmc->co)
		|| (ft_strlen(STR) + tmc->i) % tmc->co == 0)
		{
			tputs(tgetstr("up", 0), 1, put_int);
			while (off != 0)
			{
				tputs(tgetstr("nd", 0), 1, put_int);
				off--;
			}
			tputs(delete_character, 1, put_int);
			tmc->i--;
		}
		else
		{
			tputs(cursor_left, 1, put_int);
			tputs(delete_character, 1, put_int);
			tmc->cmd[tmc->i - 1] = '\0';
			tmc->i == 0 ? tmc->i : tmc->i--;
		}
	}
}

void	hist_wipe(t_tc *tmc)
{
	tmc->inhist = 0;
	tmc->acthist = 1;
	tmc->i = 0;
}

void	save_clear(void)
{
	tputs(save_cursor, 1, put_int);
	clear_down();
}
