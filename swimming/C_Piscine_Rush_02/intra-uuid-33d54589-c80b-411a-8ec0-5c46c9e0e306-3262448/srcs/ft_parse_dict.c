/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtrin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 13:14:40 by rtrin             #+#    #+#             */
/*   Updated: 2020/08/09 22:57:22 by rtrin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_parse_dict(void)
{
	int		pos;
	char	*file;

	if ((file = ft_read_dict()))
	{
		pos = 0;
		while (file[pos] && g_err == 0)
		{
			if (file[pos] == '\n')
				pos++;
			else
				ft_parse_line(file, &pos);
		}
		free(file);
	}
	else
		g_err = 2;
}

void	ft_parse_line(char *file, int *pos)
{
	int		i;
	int		num_len;
	char	*str;

	if ((num_len = ft_parse_num(file, *pos)))
	{
		i = *pos + num_len;
		if ((str = ft_parse_val(file, &i)))
		{
			if (num_len == 1)
				ft_set_unit(file, str, *pos);
			else if (num_len == 2)
				ft_set_tens_teens(file, str, *pos);
			else if (file[*pos] == '1')
				ft_set_thou(file, str, *pos, num_len);
			*pos = i;
		}
		else
			g_err = 2;
	}
	else
		g_err = 2;
}

int		ft_parse_num(char *file, int pos)
{
	int	len;

	len = 0;
	while (file[pos + len] && ft_is_dec(file[pos + len]))
		len++;
	return (len);
}

char	*ft_parse_val(char *file, int *pos)
{
	int len;

	len = 0;
	while (file[*pos] && file[*pos] == ' ')
		*pos += 1;
	if (file[*pos] == ':')
	{
		*pos += 1;
		while (file[*pos] && file[*pos] == ' ')
			*pos += 1;
		while (file[*pos] != '\n')
		{
			if (file[*pos] == '\0' || file[*pos] < 32 || file[*pos] > 126)
				return (NULL);
			len++;
			*pos += 1;
		}
		return (ft_strcut(file, *pos - len, len));
	}
	return (NULL);
}

char	*ft_strcut(char *file, int pos, int len)
{
	char	*str;
	int		i;

	if ((str = malloc((len + 1) * sizeof(char))))
	{
		i = 0;
		while (i < len)
		{
			str[i] = file[pos + i];
			i++;
		}
		str[i + 1] = '\0';
	}
	return (str);
}
