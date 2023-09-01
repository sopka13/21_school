/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termprep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:50:57 by ssandman          #+#    #+#             */
/*   Updated: 2021/06/01 17:01:24 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			tmc_set(t_tc *tmc)
{
	int ret;

	tmc->new = tmc->old;
	tmc->new.c_lflag &= ~(ICANON);
	tmc->new.c_lflag &= ~(ECHO);
	ret = tputs(save_cursor, 1, put_int);
	tmc->li = tgetnum("li");
	tmc->co = tgetnum("co");
	if (ret == -1 || tmc->li == -1 || tmc->co == -1)
		return (ft_print("can not get termcap data", -1));
	return (0);
}

int			tmc_get(t_tc *tmc)
{
	int ret;

	tmc->name = getenv("TERM");
	if (!tmc->name)
		return (ft_print("terminal type not specified in ur env", -1));
	ret = tgetent(NULL, tmc->name);
	if (ret < 0)
		return (ft_print("cant access termcap db", -1));
	if (ret == 0)
		return (ft_print("termtype is missing in termcap db", -1));
	ft_bzero(&tmc->new, sizeof(struct termios));
	return (0);
}

int			tmc_prep(t_tc *tmc)
{
	int		ret;

	if ((ret = isatty(0)) == 1)
	{
		if (tmc_get(tmc) == -1)
			return (-1);
	}
	if ((ret = isatty(0)) == 1)
		if ((ret = tcgetattr(STDIN_FILENO, &tmc->old)) == -1)
			return (ft_print(strerror(errno), -1));
	if ((ret = isatty(0)) == 1)
	{
		if (tmc_set(tmc) == -1)
			return (-1);
	}
	hist_wipe(tmc);
	if (!(tmc->cmd = malloc(sizeof(char) * BUF)))
		return (ft_print(strerror(errno), -1));
	tmc->i = 0;
	if ((ret = isatty(0)) == 1)
		if (!(tmc->cmd) ||
		(ret = tcsetattr(STDIN_FILENO, TCSANOW, &tmc->new)) == -1)
			return (ft_print("malloc error\n", -1));
	return (0);
}
