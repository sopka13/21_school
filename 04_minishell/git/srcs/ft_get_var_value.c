/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_var_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <900prod@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 18:38:21 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 18:26:17 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function get env vars value
** 	return (*str) - Success
** 	return (NULL) - Error
*/

#include "../minishell.h"

char		*ft_get_var_value(char *env_var)
{
	int		k;
	char	*env_value;

	if (!(env_value = ft_strdup("")))
	{
		ft_print(strerror(errno), -2);
		return (NULL);
	}
	k = -1;
	while (env_var[++k] && env_var[k] != '=')
	{
		if (env_var[k] == '=')
			break ;
	}
	while (env_var[k++])
	{
		if (!(env_value = ft_strputend(env_value, env_var[k])))
		{
			ft_print(strerror(errno), -2);
			return (NULL);
		}
	}
	return (env_value);
}
