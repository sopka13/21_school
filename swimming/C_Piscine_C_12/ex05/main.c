/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 13:10:00 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/06 18:05:33 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int main(void)
{
	t_list *test;
    char    **f = NULL;
    char    strs[5] = "HELLO";

    *f = strs;
    printf("hi");
    test = ft_list_push_strs(5, f);
//	printf("%s\n", test -> data);
//	printf("%s\n", test -> next -> data);
//	printf("%s\n", test -> next -> next -> data);
//	printf("%s\n", test -> next -> next -> next -> data);
	return (0);
}
