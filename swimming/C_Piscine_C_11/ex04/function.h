/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 19:10:21 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/04 20:17:21 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define SIZE_TAB 51

int ft_func(int a, int b);
int ft_is_sort(int *tab, int length, int (*f)(int, int));

#endif
