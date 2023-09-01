/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:43:30 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/04 17:46:35 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_func(char *c);
int	ft_count_if(char **tab, int(*f)(char*));

int	main(void)
{
	char	tab[20] = "ABABAB";
	int		a;
	char	*b;
	int		(*f)(char*);

	f = &ft_func;
	b = tab;
	a = ft_count_if(&b, f);
	printf("%d\n", a);
}
