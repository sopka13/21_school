/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:35:30 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/04 16:31:40 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_func(char *c);
int	ft_any(char **tab, int(*f)(char*));

int	main(void)
{
	char	tab[20] = "Hello World !1234567";
	int		a;
	char	*b;
	int		(*f)(char*);

	f = &ft_func;
	b = tab;
	a = ft_any(&b, f);
	printf("%d\n", a);
}
