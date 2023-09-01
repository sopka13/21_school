#include <unistd.h>
#include <stdio.h>

char *ft_read(void);

int main(int argc, char **argv)
{
	printf("%c\n", (*ft_read()));
	return (0);
}
