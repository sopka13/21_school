/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:27:47 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/12 18:13:11 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*str;
	int			num;

	if (!(str = ft_strdup(format)))
		return (0);
	va_start(ap, format);
	num = ft_format(str, ap);
	va_end(ap);
	free((char*)str);
	return (num);
}
