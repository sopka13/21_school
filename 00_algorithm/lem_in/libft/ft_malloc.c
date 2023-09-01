/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <heula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 20:19:03 by heula             #+#    #+#             */
/*   Updated: 2021/07/14 23:37:45 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (mem == NULL)
	{
		write(1, "Cannot allocate memory\n", 23);
		exit(12);
	}
	return (mem);
}
