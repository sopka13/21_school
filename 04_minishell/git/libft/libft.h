/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 19:15:51 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 20:28:18 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 64

typedef struct	s_split
{
	int			i;
	int			l;
	int			m;
	int			n;
}				t_split;

void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_calloc(size_t n, size_t size);
char			**ft_split(const char *s, char c);
char			*ft_strtrim(char *s1, const char *set);
char			*ft_strdup(const char *src);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
void			*ft_realloc(char *ptr, size_t new_size);
char			*ft_strputend(char *a, char b);
char			*ft_itoa(int n);
char			*ft_itoa_llu(unsigned long long int n);
int				ft_isdigit(int c);
int				ft_atoi(char *a);
int				ft_isalpha(int c);
char			*ft_strchr(const char *s, int c);
int				get_next_line(int fd, char **line);
char			*ft_strcpy(char *dest, char *src);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				ft_strcmp(const char *s1, const char *s2);

#endif
