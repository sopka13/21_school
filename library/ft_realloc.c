#include "libft.h"

void        *ft_realloc(char *ptr, size_t new_size)
{
    char    *new;
    size_t  lenght;
    int     i;

    if (!ptr || new_size == 0)
        return (NULL);
    i = -1;
    if(!(new = (char*)ft_calloc(1, new_size + 1)))
        return (NULL);
    lenght = ft_strlen(ptr);
    if (lenght >= new_size)
    {
        while (++i < new_size && ptr[i])
        {
            if (i < lenght)
                new[i] = ptr[i];
            else
                new[i] = '\0';
        }
        // new[i] = '\0';
    }
    else
    {
        while (++i < new_size && ptr[i])
            new[i] = ptr[i];
        new[i] = '\0';
    }
    free(ptr);
    return (new);
}