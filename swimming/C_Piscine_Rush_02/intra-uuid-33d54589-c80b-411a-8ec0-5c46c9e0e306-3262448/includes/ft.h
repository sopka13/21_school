/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtrin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 11:40:54 by rtrin             #+#    #+#             */
/*   Updated: 2020/08/09 23:10:26 by rtrin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

extern int		g_err;
extern int		g_num_len;
extern char		*g_num_str;
extern char		*g_dict_name;
extern char		*g_units[10];
extern char		*g_teens[9];
extern char		*g_tens[9];
extern char		*g_thou[23];

int			ft_is_dec(char c);
int			ft_strlen(char *str);
int			ft_atoi(char *str);
int			ft_parse_num(char *file, int pos);
char		*ft_strcut(char *file, int pos, int len);
char		*ft_read_dict(void);
char		*ft_parse_val(char *file, int *pos);
void		ft_validate_number(void);
void		ft_parse_dict(void);
void		ft_parse_line(char *file, int *pos);
void		ft_print_err(void);
void		ft_read_input(void);
void		ft_set_unit(char *file, char *str, int pos);
void		ft_set_tens_teens(char *file, char *str, int pos);
void		ft_set_thou(char *file, char *str, int pos, int num_len);
void		ft_print_teens_tens(unsigned long h,
		unsigned long t, unsigned long u);
void		ft_print_thous(unsigned long p);
void		ft_print_seps(unsigned long v, unsigned long h, int p);
void		ft_wordify(unsigned long v, int p);
void		ft_putstr(char *str);
void		ft_clear_buf(char *str, int size);
void		ft_num_convert(int len, int p);

#endif
