#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		get_next_line(int fd, char **line);
void    get_next_line_utils(void);
char		*ft_strputend(char *a, char b);
size_t	ft_strlen(const char *s);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *s, int c, size_t n);

#endif
