/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:40:56 by ssandman          #+#    #+#             */
/*   Updated: 2021/06/05 12:18:55 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_histdb	*create_histdb(void)
{
	t_histdb *tmp;

	if (!(tmp = (t_histdb*)malloc(sizeof(t_histdb))))
	{
		ft_print(strerror(errno), 0);
		return (NULL);
	}
	tmp->size = 0;
	tmp->head = NULL;
	tmp->tail = NULL;
	return (tmp);
}

int			get_hist(t_vars *vars, t_tc *tmc)
{
	int		i;
	char	*str;
	char	*name;

	if (vars->home == 0 &&
		(!(vars->home = ft_get_envp(vars, "HOME=")) ||
		!(vars->home = ft_strtrim(vars->home, "HOME=\"")) ||
		!(name = ft_strjoin(vars->home, FNAME_HIST))))
		return (ft_print(strerror(errno), 1));
	if ((tmc->hist_fd = open(name, O_CREAT | O_RDWR | O_APPEND, 0666)) == -1)
		return (ft_print(strerror(errno), 1));
	if (!(tmc->hist = create_histdb()))
		return (1);
	while ((i = get_next_line(tmc->hist_fd, &str)) > 0)
	{
		pushback(tmc->hist, str);
		free(str);
	}
	free(str);
	close(tmc->hist_fd);
	tmc->hist_fd = 0;
	free(name);
	return (0);
}

int			append_cmd(t_vars *vars, t_tc *tmc)
{
	char	*name;

	if (!(name = ft_strjoin(vars->home, FNAME_HIST)))
		return (ft_print(strerror(errno), 1));
	if ((tmc->tmp_fd = open(name, O_CREAT | O_RDWR | O_APPEND, 0666)) == -1)
		return (ft_print(strerror(errno), -1));
	if (write(tmc->tmp_fd, tmc->cmd, ft_strlen(tmc->cmd)) !=
	(int)ft_strlen(tmc->cmd))
		return (ft_print(strerror(errno), -1));
	write(tmc->tmp_fd, "\n", 1);
	close(tmc->tmp_fd);
	tmc->tmp_fd = 0;
	free(name);
	return (0);
}

int			pushback(t_histdb *list, char *cmd)
{
	t_node *tmp;

	if ((tmp = (t_node*)malloc(sizeof(t_node))) == NULL ||
		(tmp->cmd = malloc(sizeof(char) * ft_strlen(cmd) + 1)) == NULL)
		return (-1);
	ft_strcpy(tmp->cmd, cmd);
	tmp->next = NULL;
	tmp->prev = list->tail;
	if (list->tail)
		list->tail->next = tmp;
	list->tail = tmp;
	if (list->head == NULL)
		list->head = tmp;
	list->size++;
	return (0);
}
