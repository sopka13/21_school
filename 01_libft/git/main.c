#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "./libft/libft.h"
#include <bsd/string.h>
//#include <linux/string.h>
//#include <bsd/bitstring.h>
//#include <bsd/stdlib.h>
//#include <bsd/bsd.h>
//#include <gnu/lib-names.h>
//#include <linux/libc-compat.h>

// Проверка на предельные значения
// Проверка при отправке отрицательных значений
// Проверка при отправке нулевого указателя (неправильных значений)

int main(void)
{
	int		i = 0;
	int     n = 101;
	int		a[n];
	int		a1[n];
	int		a2[n];
	char	b[n];
	char	b1[n];
	char	b2[n];
//
	while(i++ < n){
		a[i] = i;
		a1[i] = i + 1;
		a2[i] = i + 2;
		b[i] = 'A';
        b1[i] = 'B';
		b2[i] = 'C';
	}
	i = 0;
//
	printf("Тестирование функции memset:\n");{
	ft_memset(&a, '1', n*sizeof(int));
	memset(&a1, '1', n*sizeof(int));

//	for(int z=0; z<n; ++z){
//        printf("%d ", a[z]);
//	}
//	printf("\n");
//    for(int z=0; z<n; ++z){
//        printf("%d ", a1[z]);
//	}
//	printf("\n");

	ft_memset(&b, '0', n*sizeof(char));
	memset(&b1, '0', n*sizeof(char));

//	for(int z=0; z<n; ++z){
//        printf("%c ", b[z]);
//	}
//	printf("\n");
//    for(int z=0; z<n; ++z){
//        printf("%c ", b1[z]);
//	}
//	printf("\n");

	while(i++ < n-1){
		if(a[i] != a1[i]){
				printf("test 1 fall\n");
				break;
		}
		else if(b[i] != b1[i]){
				printf("test 2 fall\n");
				break;
		}
		else if(i == (n - 1)){
				printf("test 1 ok\n");
				printf("test 2 ok\n");
		}
		else
				continue;
	}
//
	while(i++ < n){
		a[i] = i;
		a1[i] = i + 1;
		a2[i] = i + 2;
		b[i] = 'A';
		b1[i] = 'B';
		b2[i] = 'C';
	}
	i = 0;
	}
//
	printf("Тестирование функции bzero:\n");{
	ft_bzero(&a, n*sizeof(int));
	bzero(&a1, n*sizeof(int));
	ft_bzero(&b, n*sizeof(char));
	bzero(&b1, n*sizeof(char));
	while(i++ < n-1){
		if(a[i] != a1[i]){
				printf("test 1 fall\n");
				break;
		}
		else if(b[i] != b1[i]){
				printf("test 2 fall\n");
				break;
		}
		else if(i == n-1){
				printf("test 1 ok\n");
				printf("test 2 ok\n");
		}
		else
				continue;
	}
//
	while(i++ < n){
		a[i] = i;
		a1[i] = i + 1;
		a2[i] = i + 2;
		b[i] = 'A';
		b1[i] = 'B';
		b2[i] = 'C';
	}
	i = 0;
	}
//
	printf("Тестирование функции memcpy:\n");{
	ft_memcpy(&a1, &a, n*sizeof(int));
	memcpy(&a2, &a, n*sizeof(int));
	ft_memcpy(&b1, &b, n*sizeof(char));
	memcpy(&b2, &b, n*sizeof(char));
	while(i++ < n-1){
		if(a2[i] != a1[i]){
				printf("test 1 fall\n");
				break;
		}
		else if(b2[i] != b1[i]){
				printf("test 2 fall\n");
				break;
		}
		else if(i == n-1){
				printf("test 1 ok\n");
				printf("test 2 ok\n");
		}
		else
				continue;
	}
	}
//
	printf("Тестирование функции memccpy:\n");{
        printf("Массивы int: ");
	    int     c[20] = {1, 1, 1, 1, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	    int     c1[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	    int     c2[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	    void *z = ft_memccpy(c1, c, 7, 14*(sizeof(int)));
        void *z1 = memccpy(c2, c, 7, 14*(sizeof(int)));
        for(i=0; i<20; ++i){
            if((c1[i] != c2[i]) || (*(int*)z != *(int*)z1)){
                printf("test fall\n");
                break;
            }
            if(i == 19 && *(int*)z == *(int*)z1)
                printf("test ok\n");
            else
                continue;
        }
//        for(i=0; i<20; ++i){printf("%d ", c1[i]);}
//        printf("\n");
//        for(i=0; i<20; ++i){printf("%d ", c2[i]);}
//        printf("\n");
//        printf("%d\n", *(int*)z);
//        printf("%d\n", *(int*)z1);

	    printf("Массивы char: ");
	    char    c3[20] = "00009000000000000000";
	    char    c4[20] = "12345678901234567890";
	    char    c5[20] = "12345678901234567890";
	    char *p = ft_memccpy(c4, c3, '9', 11);
        char *p1 = memccpy(c5, c3, '9', 11);
        for(i=0; i<20; ++i){
            if((c4[i] != c5[i]) || (*p != *p1)){
                printf("test fall\n");
                break;
            }
            if(i == 19 && *p == *p1)
                printf("test ok\n");
            else
                continue;
        }
//        printf("%s\n", c4);
//        printf("%s\n", c5);
//        printf("%c\n", *p);
//        printf("%c\n", *p1);
	}
//
//	printf("Тестирование функции memmove:");
//	void	*ft_memmove(void *dest, const void *src, size_t n);
//	memmove(void *dest, const void *src, size_t n)
//
	printf("Тестирование функции memchr:\n");{
	    printf("Массивы int: \n");
	    int     c1[20] = {1, 2, 3, 4, 5, 6, 7, 100, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	    int     c2[20] = {1, 2, 3, 4, 5, 6, 7, 100, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	    void *z = ft_memchr(c1, 100, 15*(sizeof(int)));
        void *z1 = memchr(c2, 100, 15*(sizeof(int)));
        for(i=0; i<20; ++i){
            if((c1[i] != c2[i]) || (*(int*)z != *(int*)z1)){
                printf("test fall\n");
                break;
            }
            if(i == 19 && *(int*)z == *(int*)z1)
                printf("test ok\n");
            else
                continue;
        }
//        for(i=0; i<20; ++i){printf("%d ", c1[i]);}
//        printf("\n");
//        for(i=0; i<20; ++i){printf("%d ", c2[i]);}
//        printf("\n");
//        printf("%d\n", *(int*)z);
//        printf("%d\n", *(int*)z1);
	}
//
//	printf("Тестирование функции memcmp:");
//	int	 ft_memcmp(const void *s1, const void *s2, size_t n);
//	memcmp(const void *s1, const void *s2, size_t n)
//
//	printf("Тестирование функции strlen:");
//	size_t  ft_strlen(const char *s);
//	strlen(const char *s)
//
	printf("Тестирование функции strlcpy:\n");{
	    char p[] = "HELLO";
	    char p1[20] = "";
	    char p2[20] = "";
        printf("%ld\n", ft_strlcpy(p1, p, 0));
        printf("%ld\n", strlcpy(p2, p, 0));
        printf("%s\n", p1);
        printf("%s\n", p2);
        printf("%ld\n", strlen(p));
	}
//
	printf("Тестирование функции strlcat:\n");{

	    printf("Массивы char: \n");
	    char    c3[] = "00000";
	    char    c4[] = "123456789";
	    char    c5[] = "123456789";
	    int p = strlcat(c4, c3, 10);
		int p1 = ft_strlcat(c5, c3, 10);
//        char *p1 = memccpy(c5, c3, '9', 11);
//        for(i=0; i<20; ++i){
//            if((c4[i] != c5[i]) || (*p != *p1)){
//                printf("test fall\n");
//                break;
//            }
//            if(i == 19 && *p == *p1)
//                printf("test ok\n");
//            else
//                continue;
//        }
        printf("lcat = %s - %d\n", c4, p);
		printf("ftlcat = %s - %d\n", c5, p1);
//        printf("%s\n", c5);
//        printf("%c\n", *p);
//        printf("%c\n", *p1);
	}
//	size_t  ft_strlcat(char *dst, const char *src, size_t size);
//	strlcat(char *dst, const char *src, size_t size)
//
//	printf("Тестирование функции strchr:");
//	char	*ft_strchr(const char *s, int c);
//	strchr(const char *s, int c)
//
//	printf("Тестирование функции strrchr:");
//	char	*ft_strrchr(const char *s, int c);
//	strrchr(const char *s, int c)
//
//	printf("Тестирование функции strnstr:");
//	char	*ft_strnstr(const char *big, const char *little, size_t len);
//	strnstr(const char *big, const char *little, size_t len)
//
//	printf("Тестирование функции strncmp:");
//	int	 ft_strncmp(const char *s1, const char *s2, size_t n);
//	strncmp(const char *s1, const char *s2, size_t n)

	printf("Тестирование функции atoi:\n");{
//Функция делает из строки символов число, т.е. из последовательности char делает int
//1. Проверить максимальные значения для int - '-2 147 483 648' до '2 147 483 647';
//2. Проверить что делает когда в конце строки нет никакого знака;
//3. Проверить когда в конце строки текст;
//4. Проверить что делает функция при передаче ей других типов данных;
	    printf("max/min int: ");{
	    const char    c[20] = "----2147483648";
	    const char    c1[20] = "-21474836489";
	    const char    c2[20] = "2147483647";
	    const char    c3[20] = "2147483648";
	    int num = ft_atoi(c);
        int num1 = atoi(c);
        int num2 = ft_atoi(c1);
        int num3 = atoi(c1);
        int num4 = ft_atoi(c2);
        int num5 = atoi(c2);
        int num6 = ft_atoi(c3);
        int num7 = atoi(c3);
        printf("atoi = %d ft_atoi = %d", num1, num);
        if(num == num1 && num2 == num3 && num4 == num5 && num6 == num7)
            printf("test ok\n");
        else
            printf("test fall\n");
	    }
	    printf("end str: ");{
        const char  c[20] = "a123A";
	    const char  c1[20] = "123--123";
	    const char  c2[20] = "+23\n";
	    const char  c3[20] = "          23\0";
	    int num = ft_atoi(c);
        int num1 = atoi(c);
        int num2 = ft_atoi(c1);
        int num3 = atoi(c1);
        int num4 = ft_atoi(c2);
        int num5 = atoi(c2);
        int num6 = ft_atoi(c3);
        int num7 = atoi(c3);
        if(num == num1 && num2 == num3 && num4 == num5 && num6 == num7)
            printf("test ok\n");
        else
            printf("test fall\n");
	    }
	}
//
	printf("Тестирование функции isalpha:\n");{
	    char    c = 'q';
	    char    c1 = '1';
	    char    c2 = '_';
        int m = ft_isalpha(c);
        int m1 = isalpha(c);
        printf("%d %d\n", m, m1);
	}
//
	printf("Тестирование функции isdigit:\n");{
	    char    c = '2';
	    char    c1 = '1';
	    char    c2 = '_';
        int m = ft_isdigit(c);
        int m1 = isdigit(c);
        printf("%d %d\n", m, m1);
	}
//
	printf("Тестирование функции isalnum:\n");{
	    int    c = -1;
	    char    c1 = '1';
	    char    c2 = '_';
        int m = ft_isalnum(c);
        int m1 = isalnum(c);
        printf("%d %d\n", m, m1);
	}
//
	printf("Тестирование функции isascii:\n");{
	    char    c = '~';
	    char    c1 = '1';
	    char    c2 = '_';
        int m = ft_isascii(c);
        int m1 = isascii(c);
        printf("%d %d\n", m, m1);
	}
//
	printf("Тестирование функции isprint:\n");{
	    char    c = 'a';
	    char    c1 = '1';
	    char    c2 = '_';
        int m = ft_isprint(c);
        int m1 = isprint(c);
        printf("%d %d\n", m, m1);
	}
//
//	printf("Тестирование функции toupper:");
//	int	 ft_toupper(int c);
//	toupper(int c)
//
//	printf("Тестирование функции tolower:");
//	int	 ft_tolower(int c);
//	tolower(int c)
//
	printf("Тестирование функции itoa: \n");{
		char *p = ft_itoa(-2147483648);
		printf("%s \n", p);
	}

	printf("Тестирование функции caloc: \n");{
		int a = sizeof(ft_calloc(55, 0));
		int b = sizeof(calloc(55, 0));
		printf("ft_calloc = %d \n", a);
		printf("calloc = %d \n", b);
	}
//	printf("Все функцтии протестированы:\n");
	return (0);
}
