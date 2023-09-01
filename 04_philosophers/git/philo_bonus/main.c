/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 04:06:01 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/14 10:26:33 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Program name			philo_three
** Turn in files		philo_three/
** Makefile				Yes
** Arguments			number_of_philosophers
** 						time_to_die
** 						time_to_eat
** 						time_to_sleep
** 						[number_of_times_each_philosopher_must_eat]
** External functs.		memset, printf, malloc, free, write, fork, kill,
** 						exit, pthread_create, pthread_detach, pthread_join,
** 						usleep, gettimeofday, waitpid, sem_open, sem_close,
** 						sem_post, sem_wait, sem_unlink
** Libft authorized		No
** Description			philosopher with threads and semaphore
** In this version the non common rules will be:
** // В этой версии необщими правилами будут:
** 	All the forks are in the middle of the table.
** // Все вилки находятся посередине стола.
** 	They have no states in memory but the number of available forks is
** represented bya semaphore.
** // У них нет состояний в памяти, но количество доступных вилок
** // представлено семафором.
** 	Each philosopher should be a process and the main process should not
** be a philosopher.
** // Каждый философ должен быть процессом, и главный процесс не должен
** // быть философом.
*/

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		ret;

	memset(&vars, '\0', sizeof(vars));
	if (ft_get_args(argc, argv, &vars))
		return (ft_print("Bad args\n", -1));
	if (ft_create_semaphore(&vars))
		return (-1);
	ret = ft_create_forks(&vars);
	if (ret != 0)
		exit(ret);
	if (ft_wait_forks(&vars))
		return (-1);
	sem_close(vars.sema);
	sem_unlink(SEM_NAME_1);
	sem_close(vars.sema_p);
	sem_unlink(SEM_NAME_2);
	ft_exit(&vars, 0);
	return (0);
}
