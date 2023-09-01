char ft_read(int a)
{
	char in[39];
	int i;

	i = 39;
	while (i > 0)
	{
		read(0, in, sizeof(in));
		i--;
		a++;
	}
	printf("%s\n", in);
	return (in);
}
