/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_name_export_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:11:34 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 19:11:37 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		**ft_valid_name_export_1(char **name)
{
	if (!(name[0] = ft_strdup("")))
	{
		ft_print(strerror(errno), -2);
		return (NULL);
	}
	if (!(name[1] = ft_strdup("")))
	{
		ft_print(strerror(errno), -2);
		return (NULL);
	}
	return (name);
}
