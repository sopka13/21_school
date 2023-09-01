#include  <stdio.h>
#include <stdlib.h>
int ft_parse_num(char *file, int pos);
int	ft_is_dec(int c);
char	*ft_parse_val(char *file, int *pos);
char	*ft_strcut(char *file, int pos, int len);
int main(void)
{
    char str[] = "15:    jshf^%^%$^$j5465hgejsf    \n";
    int num_len = ft_parse_num(str, 0);
    printf("%s\n%d", ft_parse_val(str, &num_len), num_len);
    return 0;
}
int		ft_parse_num(char *file, int pos)
{
	int	len;
	len = 0;
	while (file[pos + len] && ft_is_dec(file[pos + len]))
	{
		if (len >= 2 &&	(file[pos] != '1' || file[pos + 1] != '0' || file[pos + len] != '0'))
					return (0);
		len++;
	}
	if (len == 2 &&
			(file[pos] == '0' || (file[pos] != '1' && file[pos + 1] != '0')))
				return (0);
	return (len);
}
int	ft_is_dec(int c)
{
	return (c >= '0' && c <= '9');
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
