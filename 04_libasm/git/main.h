#ifndef MAIN_H
# define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ssize_t			ft_read(int fd, void *buf, size_t count);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *str);
ssize_t			ft_write(int fd, const void *buf, size_t count);

#endif