#include "get_next_line.h"
#include <stdio.h>

void		*ft_memset(void *s, int c, size_t n)
{
	while (n-- > 0)
		*((unsigned char *)s + n) = (unsigned char)c;
	return (s);
}

void		ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0x00, n);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strputend(char *a, char b)
{
	char	*c;
	int		i;

	i = 0;
	if (!a)
		return (NULL);
	if (!(c = (char*)malloc((int)ft_strlen(a) + 2)))
		return (NULL);
	while (a[i])
	{
		c[i] = a[i];
		i++;
	}
	c[i++] = b;
	c[i] = '\0';
	free(a);
	return (c);
}

int				get_next_line(int fd, char **line)
{
    static int  i = 0;
    static int  l = 0;
    static char *str;
    char        *out;
    int         m = 0;

    if (fd < 0 || !line || BUFFER_SIZE <= 0 || !(out = (char*)malloc(sizeof(char))))
        return (-1);
    out[0] = '\0';
    if (i == 0 && !(str = (char*)malloc(sizeof(char) * BUFFER_SIZE)))
        return (-1);

    while(1)                                        // цикл поиска конца строки
    {
        if (i == 0)                                 // читаем только если мы дошли до конца уже считанного буфера и при первом вызове функ-ии
        {
            ft_bzero(str, (int)ft_strlen(str));
            l = read(fd, str, BUFFER_SIZE);         // считываем по заданному размеру буфера
        }
        if (l == -1)                                // если при чтении файла вернулась ошибка
            return (-1);
        while (i < l && str[i] != '\n')             // разгребаем строку которую считали
            out = ft_strputend(out, str[i++]);
        if (str[i] == '\n')                         // если нашли конец строки то вернем 1
            m = 1;
        if (i == BUFFER_SIZE && l == BUFFER_SIZE)   // если мы считали весь буфер и не нашли конец строки то нужно вернуться и повторить чтение файла
        {
            i = 0;                                  // обнуляем для того, что бы читать со считанной строки с первого символа
            continue;
        }
        if (str[i] == '\n' && i != l)               // если мы нашли перенос строки то переставляем указатель на следующий символ
            i++;
        if (l < BUFFER_SIZE && i == l)              // Если объем чтения меньше буфера и мы посмотрели весь объем чтения значит файл закончился но в нем могут быть 2 переноса строк
            i = 0;
        out = ft_strputend(out, '\0');              // если нашли конец строки присваиваем адрес и завершаемся
        *line = out;
        if (m == 0 || i == 0)
            free(str);
        return (m);
    }
    return (0);
}
