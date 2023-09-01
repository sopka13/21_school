/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:22:03 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/12 21:04:48 by gdilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# define F_STR_SIZE 30000

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <libgen.h>
# include <fcntl.h>

extern char		**g_map;
extern char		g_empty;
extern char		g_obstacle;
extern char		g_full;
extern char     *g_buf;
extern int		**g_map_num;
extern int		g_line;
extern int		g_error;
extern int		g_min_square;
extern int		g_width;
long int		g_size_buf;

void			ft_free(void);
void			ft_put_error(void);

int			ft_finish_map(void);
void			ft_get_width(char *str_map);
void			ft_solution_output(char *str_map);
void			ft_strcpy_map(char *str, char *str_map, int line);
void			ft_output_map(void);
void			ft_put_str(char *str);
void			ft_put_char(char c);
char			*ft_write_in(void);
int            ft_second_map(void);
int				ft_map_arr(char *str_map);
int				ft_atoi(char *line, int a);
int				ft_open_map(char *name);
int				ft_valid_str_map(char *str_map);
int				ft_get_count_lines(char *str_map);
int				ft_check_letter2(char *str_map);
int				ft_valid_width(char *str_map);
int				ft_input(int a);
int				ft_check_letter(void);
int				ft_min(int a, int b, int c);
void				ft_build_max_square(int i, int j, int min);
long int		ft_size_buf(char *file);

#endif
