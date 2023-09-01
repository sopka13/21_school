#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

void		ft_child(int *file_desc)
{
	char	*str_1 = "Hello World!";
	int		i;
	char	str_2[BUFSIZ];

	i = 0;
	bzero(str_2, sizeof(str_2));
	i = read(file_desc[0], str_2, BUFSIZ);
	printf("number of bytes read = %d, str = %s\n", i, str_2);
	i = write(file_desc[1], str_1, strlen(str_1));
	printf("number of bytes write = %d\n", i);
	exit (0);
}

void		ft_parent(int *file_desc)
{
	int		status;
	pid_t	pid;
	int		i;
	char	str_1[BUFSIZ];

	bzero(str_1, sizeof(str_1));
	pid = wait(&status);
	printf("Код завершения дочернего процесса %d: %d\n", pid, WEXITSTATUS(status));
	i = read(file_desc[0], str_1, BUFSIZ);
	printf("number of bytes read = %d, file_desc[0] = %s\n", i, str_1);
	i = read(file_desc[0], str_1, BUFSIZ);
	printf("number of bytes read = %d, file_desc[0] = %s\n", i, str_1);
	return ;
}

int			main(int argc, char **argv, char **envp)
{
	int		file_desc[2];
	int		i;
	char	str[BUFSIZ + 1];
	pid_t	pid;

	file_desc[0] = -1;
	file_desc[1] = -1;
	// i = pipe(file_desc);
	printf("pipe = %d\n", i);
	pid = fork();
	printf("pid = %d\n", pid);
	if (pid == 0)
		ft_child(file_desc);
	else if (pid > 0)
		ft_parent(file_desc);
	else
		printf("%s\n", strerror(errno));
	return (0);
}