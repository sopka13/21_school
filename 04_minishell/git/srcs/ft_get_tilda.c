/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tilda.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:57:30 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/03 22:57:30 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		*ft_get_tilda(t_vars *vars, char *line_out)
{
	char	*str_temp;
	char	*str_temp_2;

	if (!(str_temp = ft_get_var_value(ft_get_envp(vars, "HOME="))))
		return (NULL);
	if (!(str_temp_2 = ft_strjoin(line_out, str_temp)))
		return (NULL);
	free(line_out);
	free(str_temp);
	return (str_temp_2);
}
