/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:48:39 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/12 17:42:29 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include "./libft/libft.h"

typedef struct	s_modify
{
	int			mns;
	int			pls;
	int			zero;
	int			num1;
	int			dot;
	int			num2;
	int			res;
	int			starprev;
	int			starpost;
	int			space;
	int			percent;
	int			null;
	int			mns2;
}				t_modify;

int				ft_printf(const char *format, ...);
int				ft_format(char *str, va_list ap);
void			ft_printf_1(char *str, int *num, t_modify *modify, va_list ap);
int				ft_relative(char c, t_modify *modify, int *num);
int				ft_digit(char c, t_modify *modify, int *num);
int				ft_flag_space(t_modify *modify, int *num);
int				ft_flag_mns(t_modify *modify, int *num);
int				ft_flag_pls(t_modify *modify, int *num);
int				ft_flag_res(t_modify *modify, int *num);
int				ft_flag_dot(t_modify *modify, int *num);
int				ft_flag_percent(t_modify *modify, int *num);
int				ft_di(int *num, t_modify *modify, va_list ap);
char			*ft_di2(char *a, t_modify *modify);
int				ft_u(int *num, t_modify *modify, va_list ap);
char			*ft_spaceuns(unsigned int x, char *a, t_modify *modify);
void			ft_s(int *num, t_modify *modify, va_list ap);
void			ft_p(int *num, t_modify *modify, va_list ap);
void			ft_x(char *str, int *num, t_modify *modify, va_list ap);
void			ft_c(int *num, t_modify *modify, va_list ap);
int				ft_percent(int *num, t_modify *modify);

#endif
