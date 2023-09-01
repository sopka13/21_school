#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <errno.h>
#include <syscall.h>

ssize_t			ft_read(int fd, void *buf, size_t count);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *str);
ssize_t			ft_write(int fd, const void *buf, size_t count);

static void	ft_test_read(void)
{
	char	buff[10];
	int		ret;
	int		fd;
	int		size;

	ret = 0;
	write(1, "++++++++++Test ft_read start++++++++++++\n", 42);

	bzero(buff, sizeof(buff));
	size = 10;
	fd = 0;
	printf("---Test 1: size = %d fd = %d\n", size, fd);
	printf("ft_read:\n");
	ret = ft_read(fd, buff, size);
	printf("result = %s", buff);
	printf("$\n ret = %d error = %s\n", ret, strerror(errno));
	bzero(buff, sizeof(buff));
	printf("read:\n");
	ret = read(fd, buff, size);
	printf("result = %s", buff);
	printf("$\n ret = %d error = %s\n\n", ret, strerror(errno));

	bzero(buff, sizeof(buff));
	size = 10;
	fd = 1;
	printf("---Test 2: size = %d fd = %d\n", size, fd);
	printf("ft_read:\n");
	ret = ft_read(fd, buff, size);
	printf("result = %s", buff);
	printf("$\n ret = %d error = %s\n", ret, strerror(errno));
	bzero(buff, sizeof(buff));
	printf("read:\n");
	ret = read(fd, buff, size);
	printf("result = %s", buff);
	printf("$\n ret = %d error = %s\n\n", ret, strerror(errno));

	bzero(buff, sizeof(buff));
	size = 10;
	fd = 2;
	printf("---Test 3: size = %d fd = %d\n", size, fd);
	printf("ft_read:\n");
	ret = ft_read(fd, buff, size);
	printf("result = %s", buff);
	printf("$\n ret = %d error = %s\n", ret, strerror(errno));
	bzero(buff, sizeof(buff));
	printf("read:\n");
	ret = read(fd, buff, size);
	printf("result = %s", buff);
	printf("$\n ret = %d error = %s\n\n", ret, strerror(errno));

	bzero(buff, sizeof(buff));
	size = 10;
	fd = 3;
	printf("---Test 4: size = %d fd = %d\n", size, fd);
	printf("ft_read:\n");
	ret = ft_read(fd, buff, size);
	printf("result = %s", buff);
	printf("$\n ret = %d error = %s\n", ret, strerror(errno));
	bzero(buff, sizeof(buff));
	printf("read:\n");
	ret = read(fd, buff, size);
	printf("result = %s", buff);
	printf("$\n ret = %d error = %s\n\n", ret, strerror(errno));

	bzero(buff, sizeof(buff));
	unsigned long siz = 18446744073709551615;
	fd = 1;
	unsigned long ret1 = 0;
	printf("---Test 5: size = %lu fd = %d\n", siz, fd);
	printf("ft_read:\n");
	ret = ft_read(fd, buff, siz);
	printf("result = %s", buff);
	printf("$\n ret = %lu error = %s\n", ret1, strerror(errno));
	bzero(buff, sizeof(buff));
	printf("read:\n");
	ret = read(fd, buff, siz);
	printf("result = %s", buff);
	printf("$\n ret = %lu error = %s\n\n", ret1, strerror(errno));

	bzero(buff, sizeof(buff));
	size = 0;
	fd = 0;
	printf("---Test 6: size = %d fd = %d\n", size, fd);
	printf("ft_read:\n");
	ret = ft_read(fd, buff, size);
	printf("result = %s", buff);
	printf("$\n ret = %d error = %s\n", ret, strerror(errno));
	bzero(buff, sizeof(buff));
	printf("read:\n");
	ret = read(fd, buff, size);
	printf("result = %s", buff);
	printf("$\n ret = %d error = %s\n\n", ret, strerror(errno));

	bzero(buff, sizeof(buff));
	size = -10;
	fd = 0;
	printf("---Test 7: size = %d fd = %d\n", size, fd);
	printf("ft_read:\n");
	ret = ft_read(fd, buff, size);
	printf("result = %s", buff);
	printf("$\n ret = %d error = %s\n", ret, strerror(errno));
	bzero(buff, sizeof(buff));
	printf("read:\n");
	ret = read(fd, buff, size);
	printf("result = %s", buff);
	printf("$\n ret = %d error = %s\n\n", ret, strerror(errno));

	write(1, "++++++++++Test ft_read end++++++++++++++\n\n", 42);
}

static void	ft_test_strcmp(void)
{
	char	*str1;
	char	*str2;
	int		ret;

	write(1, "++++++++++Test ft_strcmp start++++++++++\n", 42);
	
	str1 = "String number 1";
	str2 = "String number 2";
	printf("---Test 1: \n str1 = %s \n str2 = %s\n", str1, str2);
	ret = ft_strcmp(str1, str2);
	printf("ft_strcmp result = %d error = %s\n", ret, strerror(errno));
	ret = strcmp(str1, str2);
	printf("   strcmp result = %d error = %s\n\n", ret, strerror(errno));

	str1 = "String number 1";
	str2 = "String number 1";
	printf("---Test 2: \n str1 = %s \n str2 = %s\n", str1, str2);
	ret = ft_strcmp(str1, str2);
	printf("ft_strcmp result = %d error = %s\n", ret, strerror(errno));
	ret = strcmp(str1, str2);
	printf("   strcmp result = %d error = %s\n\n", ret, strerror(errno));

	str1 = "String number 2";
	str2 = "String number 1";
	printf("---Test 3: \n str1 = %s \n str2 = %s\n", str1, str2);
	ret = ft_strcmp(str1, str2);
	printf("ft_strcmp result = %d error = %s\n", ret, strerror(errno));
	ret = strcmp(str1, str2);
	printf("   strcmp result = %d error = %s\n\n", ret, strerror(errno));

	str1 = "String";
	str2 = "String number 2";
	printf("---Test 4: \n str1 = %s \n str2 = %s\n", str1, str2);
	ret = ft_strcmp(str1, str2);
	printf("ft_strcmp result = %d error = %s\n", ret, strerror(errno));
	ret = strcmp(str1, str2);
	printf("   strcmp result = %d error = %s\n\n", ret, strerror(errno));

	str1 = "String number 1";
	str2 = "String";
	printf("---Test 5: \n str1 = %s \n str2 = %s\n", str1, str2);
	ret = ft_strcmp(str1, str2);
	printf("ft_strcmp result = %d error = %s\n", ret, strerror(errno));
	ret = strcmp(str1, str2);
	printf("   strcmp result = %d error = %s\n\n", ret, strerror(errno));

	str1 = "";
	str2 = "String number 2";
	printf("---Test 6: \n str1 = %s \n str2 = %s\n", str1, str2);
	ret = ft_strcmp(str1, str2);
	printf("ft_strcmp result = %d error = %s\n", ret, strerror(errno));
	ret = strcmp(str1, str2);
	printf("   strcmp result = %d error = %s\n\n", ret, strerror(errno));

	str1 = "String number 1";
	str2 = "";
	printf("---Test 7: \n str1 = %s \n str2 = %s\n", str1, str2);
	ret = ft_strcmp(str1, str2);
	printf("ft_strcmp result = %d error = %s\n", ret, strerror(errno));
	ret = strcmp(str1, str2);
	printf("   strcmp result = %d error = %s\n\n", ret, strerror(errno));

	// str1 = NULL;
	// str2 = "String number 2";
	// printf("---Test 8: \n str1 = %s \n str2 = %s\n", str1, str2);
	// ret = ft_strcmp(str1, str2);
	// printf("ft_strcmp result = %d error = %s\n", ret, strerror(errno));
	// ret = strcmp(str1, str2);
	// printf("   strcmp result = %d error = %s\n\n", ret, strerror(errno));

	// str1 = "String number 1";
	// str2 = NULL;
	// printf("---Test 9: \n str1 = %s \n str2 = %s\n", str1, str2);
	// ret = ft_strcmp(str1, str2);
	// printf("ft_strcmp result = %d error = %s\n", ret, strerror(errno));
	// ret = strcmp(str1, str2);
	// printf("   strcmp result = %d error = %s\n\n", ret, strerror(errno));

	// str1 = NULL;
	// str2 = NULL;
	// printf("---Test 10: \n str1 = %s \n str2 = %s\n", str1, str2);
	// ret = ft_strcmp(str1, str2);
	// printf("ft_strcmp result = %d error = %s\n", ret, strerror(errno));
	// ret = strcmp(str1, str2);
	// printf("   strcmp result = %d error = %s\n\n", ret, strerror(errno));

	str1 = "";
	str2 = "";
	printf("---Test 11: \n str1 = %s \n str2 = %s\n", str1, str2);
	ret = ft_strcmp(str1, str2);
	printf("ft_strcmp result = %d error = %s\n", ret, strerror(errno));
	ret = strcmp(str1, str2);
	printf("   strcmp result = %d error = %s\n\n", ret, strerror(errno));

	write(1, "++++++++++Test ft_strcmp end++++++++++++\n\n", 42);
}

static void	ft_test_strcpy(void)
{
	char	str10[10];
	char	*str20;
	char	*str30;

	write(1, "++++++++++Test ft_strcpy start++++++++++\n", 42);

	bzero(str10, sizeof(str10));
	str20 = "String";
	str30 = NULL;
	printf("\n---Test 1:        str1 = %s; str2 = %s; str3 = %s; sizeof(str1) = %ld; sizeof(str2) = %ld; sizeof(str3) = %ld; error = %s;\n", str10, str20, str30,  sizeof(str10), sizeof(str20), sizeof(str30), strerror(errno));
	str30 = ft_strcpy(str10, str20);
	printf("ft_strcmp result: str1 = %s; str2 = %s; str3 = %s; sizeof(str1) = %ld; sizeof(str2) = %ld; sizeof(str3) = %ld; error = %s;\n", str10, str20, str30,  sizeof(str10), sizeof(str20), sizeof(str30), strerror(errno));
	str30 = strcpy(str10, str20);
	printf("   strcmp result: str1 = %s; str2 = %s; str3 = %s; sizeof(str1) = %ld; sizeof(str2) = %ld; sizeof(str3) = %ld; error = %s;\n", str10, str20, str30,  sizeof(str10), sizeof(str20), sizeof(str30), strerror(errno));

	bzero(str10, sizeof(str10));
	str20 = "String 2";
	str30 = NULL;
	printf("\n---Test 2:        str1 = %s; str2 = %s; str3 = %s; sizeof(str1) = %ld; sizeof(str2) = %ld; sizeof(str3) = %ld; error = %s;\n", str10, str20, str30,  sizeof(str10), sizeof(str20), sizeof(str30), strerror(errno));
	str30 = ft_strcpy(str10, str20);
	printf("ft_strcmp result: str1 = %s; str2 = %s; str3 = %s; sizeof(str1) = %ld; sizeof(str2) = %ld; sizeof(str3) = %ld; error = %s;\n", str10, str20, str30,  sizeof(str10), sizeof(str20), sizeof(str30), strerror(errno));
	str30 = strcpy(str10, str20);
	printf("   strcmp result: str1 = %s; str2 = %s; str3 = %s; sizeof(str1) = %ld; sizeof(str2) = %ld; sizeof(str3) = %ld; error = %s;\n", str10, str20, str30,  sizeof(str10), sizeof(str20), sizeof(str30), strerror(errno));

	// bzero(str10, sizeof(str10));
	str20 = "";
	str30 = NULL;
	printf("\n---Test 3:        str1 = %s; str2 = %s; str3 = %s; sizeof(str1) = %ld; sizeof(str2) = %ld; sizeof(str3) = %ld; error = %s;\n", str10, str20, str30,  sizeof(str10), sizeof(str20), sizeof(str30), strerror(errno));
	str30 = ft_strcpy(str10, str20);
	printf("ft_strcmp result: str1 = %s; str2 = %s; str3 = %s; sizeof(str1) = %ld; sizeof(str2) = %ld; sizeof(str3) = %ld; error = %s;\n", str10, str20, str30,  sizeof(str10), sizeof(str20), sizeof(str30), strerror(errno));
	str30 = strcpy(str10, str20);
	printf("   strcmp result: str1 = %s; str2 = %s; str3 = %s; sizeof(str1) = %ld; sizeof(str2) = %ld; sizeof(str3) = %ld; error = %s;\n", str10, str20, str30,  sizeof(str10), sizeof(str20), sizeof(str30), strerror(errno));

	bzero(str10, sizeof(str10));
	str20 = "String 2";
	str30 = "String 3";
	printf("\n---Test 4:        str1 = %s; str2 = %s; str3 = %s; sizeof(str1) = %ld; sizeof(str2) = %ld; sizeof(str3) = %ld; error = %s;\n", str10, str20, str30,  sizeof(str10), sizeof(str20), sizeof(str30), strerror(errno));
	str30 = ft_strcpy(str10, str20);
	printf("ft_strcmp result: str1 = %s; str2 = %s; str3 = %s; sizeof(str1) = %ld; sizeof(str2) = %ld; sizeof(str3) = %ld; error = %s;\n", str10, str20, str30,  sizeof(str10), sizeof(str20), sizeof(str30), strerror(errno));
	str30 = strcpy(str10, str20);
	printf("   strcmp result: str1 = %s; str2 = %s; str3 = %s; sizeof(str1) = %ld; sizeof(str2) = %ld; sizeof(str3) = %ld; error = %s;\n", str10, str20, str30,  sizeof(str10), sizeof(str20), sizeof(str30), strerror(errno));

	// bzero(str10, sizeof(str10));
	// str20 = NULL;
	// str30 = NULL;
	// printf("\n---Test 5:        str1 = %s; str2 = %s; str3 = %s; sizeof(str1) = %ld; sizeof(str2) = %ld; sizeof(str3) = %ld; error = %s;\n", str10, str20, str30,  sizeof(str10), sizeof(str20), sizeof(str30), strerror(errno));
	// str30 = ft_strcpy(str10, str20);
	// printf("ft_strcmp result: str1 = %s; str2 = %s; str3 = %s; sizeof(str1) = %ld; sizeof(str2) = %ld; sizeof(str3) = %ld; error = %s;\n", str10, str20, str30,  sizeof(str10), sizeof(str20), sizeof(str30), strerror(errno));
	// str30 = strcpy(str10, str20);
	// printf("   strcmp result: str1 = %s; str2 = %s; str3 = %s; sizeof(str1) = %ld; sizeof(str2) = %ld; sizeof(str3) = %ld; error = %s;\n", str10, str20, str30,  sizeof(str10), sizeof(str20), sizeof(str30), strerror(errno));

	write(1, "++++++++++Test ft_strcpy end++++++++++++\n\n", 42);
}

static void	ft_test_strdup(void)
{
	char	*str1;
	char	*str2;

	write(1, "++++++++++Test ft_strdup start++++++++++\n", 42);

	str1 = "String number 1";
	str2 = NULL;
	printf("\n---Test 1:        str1 = %s; str2 = %s; sizeof(str1) = %ld; sizeof(str2) = %ld; error = %s;\n", str1, str2, sizeof(str1), sizeof(str2), strerror(errno));
	str2 = ft_strdup(str1);
	printf("ft_strcmp result: str1 = %s; str2 = %s; sizeof(str1) = %ld; sizeof(str2) = %ld; error = %s;\n", str1, str2, sizeof(str1), sizeof(str2), strerror(errno));
	free(str2);
	str2 = strdup(str1);
	printf("   strcmp result: str1 = %s; str2 = %s; sizeof(str1) = %ld; sizeof(str2) = %ld; error = %s;\n", str1, str2, sizeof(str1), sizeof(str2), strerror(errno));
	free(str2);
	str2 = ft_strdup(str1);
	free(str2);
	printf("ft_strcmp result(after free): str1 = %s; str2 = %s; sizeof(str1) = %ld; sizeof(str2) = %ld; error = %s;\n", str1, str2, sizeof(str1), sizeof(str2), strerror(errno));
	str2 = strdup(str1);
	free(str2);
	printf("   strcmp result(after free): str1 = %s; str2 = %s; sizeof(str1) = %ld; sizeof(str2) = %ld; error = %s;\n", str1, str2, sizeof(str1), sizeof(str2), strerror(errno));

	write(1, "\n++++++++++Test ft_strdup end++++++++++++\n\n", 44);
}

static void	ft_test_strlen(void)
{
	int		ret;
	char	*str;

	write(1, "++++++++++Test ft_strlen start++++++++++\n", 42);

	str = "String number 1";
	printf("---Test 1: str = |%s| strerror = %s\n", str, strerror(errno));
	printf("ft_strlen:\n");
	ret = ft_strlen(str);
	printf(" ret = %d error = %s\n", ret, strerror(errno));
	printf("strlen:\n");
	ret = strlen(str);
	printf(" ret = %d error = %s\n\n", ret, strerror(errno));

	// str = NULL;
	// printf("---Test 2: str = |%s| strerror = %s\n", str, strerror(errno));
	// printf("ft_strlen:\n");
	// ret = ft_strlen(str);
	// printf(" ret = %d error = %s\n", ret, strerror(errno));
	// printf("strlen:\n");
	// ret = strlen(str);
	// printf(" ret = %d error = %s\n\n", ret, strerror(errno));

	str = "\0";
	printf("---Test 3: str = |%s| strerror = %s\n", str, strerror(errno));
	printf("ft_strlen:\n");
	ret = ft_strlen(str);
	printf(" ret = %d error = %s\n", ret, strerror(errno));
	printf("strlen:\n");
	ret = strlen(str);
	printf(" ret = %d error = %s\n\n", ret, strerror(errno));

	str = "     ";
	printf("---Test 4: str = |%s| strerror = %s\n", str, strerror(errno));
	printf("ft_strlen:\n");
	ret = ft_strlen(str);
	printf(" ret = %d error = %s\n", ret, strerror(errno));
	printf("strlen:\n");
	ret = strlen(str);
	printf(" ret = %d error = %s\n\n", ret, strerror(errno));

	str = "			";
	printf("---Test 5: str = |%s| strerror = %s\n", str, strerror(errno));
	printf("ft_strlen:\n");
	ret = ft_strlen(str);
	printf(" ret = %d error = %s\n", ret, strerror(errno));
	printf("strlen:\n");
	ret = strlen(str);
	printf(" ret = %d error = %s\n\n", ret, strerror(errno));

	write(1, "++++++++++Test ft_strlen end+++++++++++\n\n", 42);
}

static void	ft_test_write(void)
{
	int		ret;
	char	*str;
	int		fd;

	write(1, "++++++++++Test ft_write start++++++++++\n", 41);
	
	str = "Hello world";
	fd = 1;
	printf("---Test 1: str = %s; fd = %d; strerror = %s\n", str, fd, strerror(errno));
	printf("ft_write:\n");
	ret = ft_write(fd, str, strlen(str));
	printf("$\n ret = %d error = %s\n", ret, strerror(errno));
	printf("write:\n");
	ret = write(fd, str, strlen(str));
	printf("$\n ret = %d error = %s\n\n", ret, strerror(errno));
	
	str = "Hello world";
	fd = 2;
	printf("---Test 2: str = %s; fd = %d; strerror = %s\n", str, fd, strerror(errno));
	printf("ft_write:\n");
	ret = ft_write(fd, str, strlen(str));
	printf("$\n ret = %d error = %s\n", ret, strerror(errno));
	printf("write:\n");
	ret = write(fd, str, strlen(str));
	printf("$\n ret = %d error = %s\n\n", ret, strerror(errno));

	str = "Hello world";
	fd = 3;
	printf("---Test 3: str = %s; fd = %d; strerror = %s\n", str, fd, strerror(errno));
	printf("ft_write:\n");
	ret = ft_write(fd, str, strlen(str));
	printf("$\n ret = %d error = %s\n", ret, strerror(errno));
	printf("write:\n");
	ret = write(fd, str, strlen(str));
	printf("$\n ret = %d error = %s\n\n", ret, strerror(errno));

	str = "Hello world";
	fd = -1;
	printf("---Test 4: str = %s; fd = %d; strerror = %s\n", str, fd, strerror(errno));
	printf("ft_write:\n");
	ret = ft_write(fd, str, strlen(str));
	printf("$\n ret = %d error = %s\n", ret, strerror(errno));
	printf("write:\n");
	ret = write(fd, str, strlen(str));
	printf("$\n ret = %d error = %s\n\n", ret, strerror(errno));

	str = "Hello world";
	fd = 122;
	printf("---Test 5: str = %s; fd = %d; strerror = %s\n", str, fd, strerror(errno));
	printf("ft_write:\n");
	ret = ft_write(fd, str, strlen(str));
	printf("$\n ret = %d error = %s\n", ret, strerror(errno));
	printf("write:\n");
	ret = write(fd, str, strlen(str));
	printf("$\n ret = %d error = %s\n\n", ret, strerror(errno));

	str = "";
	fd = 1;
	printf("---Test 6: str = %s; fd = %d; strerror = %s\n", str, fd, strerror(errno));
	printf("ft_write:\n");
	ret = ft_write(fd, str, strlen(str));
	printf("$\n ret = %d error = %s\n", ret, strerror(errno));
	printf("write:\n");
	ret = write(fd, str, strlen(str));
	printf("$\n ret = %d error = %s\n\n", ret, strerror(errno));

	write(1, "++++++++++Test ft_write end++++++++++\n\n", 40);
}

int		main(void)
{
	ft_test_read();
	ft_test_strcmp();
	ft_test_strcpy();
	ft_test_strdup();
	ft_test_strlen();
	ft_test_write();
	return (0);
}