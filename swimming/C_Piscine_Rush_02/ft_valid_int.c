
void	ft_valid_int(void)
{
	if (g_num_len != 0)
		ft_write1();
	if (g_num_len == 0)
		ft_write2();
}

void	ft_write1(void)
{
	int		i;
	char	a[39];
	int		k;

	i = 0;
	k = 0;
	while (g_num_str[i] == "0" && i <= g_num_len)
		i++;
	while (i <= g_num_len)
	{
		if (g_num_str[i] >= "0" && g_num_str[i] <= "9")
		{
			a[k] = g_num_str[i];
			i++;
			k++;
		}
		else
		{
			g_err = 1;
			break ;
		}
	}
	g_num_len = k;
	g_num_str = a;
}

void	ft_write2(void)
{
	int		i;
	char	a[39];
	int		k;

	i = 0;
	k = 0;
	while (g_num_str[i] == "0" && i <= g_num_len)
		i++;
	while (i <= g_num_len)
	{
		if (g_num_str[i] >= "0" && g_num_str[i] <= "9")
		{
			a[k] = g_num_str[i];
			i++;
			k++;
		}
		else
		{
			g_err = 1;
			break ;
		}
	}
	g_num_len = k;
	g_num_str = a;
}
