/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:23:10 by ssandman          #+#    #+#             */
/*   Updated: 2021/06/05 10:43:55 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		got_cmd(t_tc *tmc, t_vars *vars)
{
	int ret;

	if ((ret = isatty(0)) == 1)
		write(1, "\n", 2);
	if (ft_strcmp(tmc->hist->tail->cmd, tmc->cmd) != 0)
	{
		if ((ret = append_cmd(vars, tmc)) == -1 ||
		(ret = pushback(tmc->hist, tmc->cmd)) == -1)
			return (-1);
	}
	ft_bzero(tmc->cmd, tmc->i);
	if (vars->flags->squote == 0 && vars->flags->quote == 0 &&
	vars->flags->and == 0 && vars->flags->backslash == 0)
	{
		hist_wipe(tmc);
		return (1);
	}
	else
	{
		hist_wipe(tmc);
		vars->flags->status = 2;
		return (ft_print("Syntax error", 0));
	}
}

void	prep_cmd(t_tc *tmc, t_vars *vars)
{
	int i;

	i = -1;
	while (tmc->cmd[++i])
		vars->str[i] = tmc->cmd[i];
	vars->str[i] = '\0';
	i = -1;
	while (vars->str[++i])
		ft_event(vars, vars->str[i]);
}

int		enterkey(t_tc *tmc, t_vars *vars)
{
	int ret;

	if ((ret = isatty(0)) == 1)
		save_clear();
	if (!ft_only_space(tmc->cmd, -1))
	{
		write(1, "\n", 2);
		tputs(save_cursor, 1, put_int);
		return (0);
	}
	else
	{
		prep_cmd(tmc, vars);
		if ((ret = isatty(0)) == 1)
			tputs(save_cursor, 1, put_int);
		if (tmc->i != 0)
			tmc->cmd[tmc->i + 1] = '\0';
		if (tmc->i > 0)
			return (got_cmd(tmc, vars));
	}
	hist_wipe(tmc);
	return (0);
}

void	ctrld(t_tc *tmc, t_vars *vars, char *buff)
{
	if (tmc->i == 0 && *buff != '\t')
	{
		write(1, "\nexit\n", 7);
		ft_exit(vars);
	}
	else
		bibip();
}

int		ft_read_input(t_tc *tmc, t_vars *vars)
{
	int		rd;
	char	buff[BUF];
	int		ret;
	int		n;

	ret = isatty(0);
	n = (ret == 1) ? 10 : 1;
	while ((rd = read(0, &buff, n)) > 0)
	{
		if (*buff == 12 || !ft_strcmp(buff, LEFT) || !ft_strcmp(buff, RIGHT))
			bibip();
		else if (*buff == 4 || *buff == '\t')
			ctrld(tmc, vars, buff);
		else if (*buff == 10 || !ft_strcmp(buff, "\n") || *buff == '\0')
			return (enterkey(tmc, vars));
		else if (!ft_strcmp(buff, UP))
			upkey(tmc);
		else if (!ft_strcmp(buff, DOWN))
			downkey(tmc);
		else if (*buff == BACKSP)
			backspace(tmc);
		else
			print_symbol(buff, tmc);
	}
	return (rd <= 0 ? -1 : 0);
}
