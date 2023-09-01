/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:57:45 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/14 10:04:19 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Program name			philo_one
** Turn in files		philo_one/
** Makefile				Yes
** Arguments			number_of_philosophers
** 						time_to_die
** 						time_to_eat
** 						time_to_sleep
** 						[number_of_times_each_philosopher_must_eat]
** External functs.		memset, printf, malloc, free, write,
** 						usleep, gettimeofday, pthread_create,
** 						pthread_detach, pthread_join, pthread_mutex_init,
** 						pthread_mutex_destroy, pthread_mutex_lock,
** 						pthread_mutex_unlock
** Libft authorized		No
** Description			philosopher with threads and mutex
** In this version the non common rules will be:
** // В этой версии необщими правилами будут:
** 	One fork between each philosopher, therefore there will be a fork
** at the right andat the left of each philosopher.
** // Одна вилка между каждым философом, следовательно, будет вилка
** // справа и слева от каждого философа.
** 	To avoid philosophers duplicating forks, you should protect the forks
** state with amutex for each of them.
** // Чтобы философы не дублировали вилки, вы должны защитить состояние
** // вилок мьютексом для каждой из них.
** 	Each philosopher should be a thread.
** // У каждого философа должна быть нить.
*/

#include "philo.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	memset(&vars, '\0', sizeof(vars));
	if (ft_get_args(argc, argv, &vars))
		return (ft_print("Bad args\n", -1));
	if (ft_create_mutex(&vars))
		return (-1);
	if (ft_create_pthread(&vars))
		return (-1);
	if (ft_wait_pthread(&vars))
		return (-1);
	ft_free(&vars);
	return (0);
}
