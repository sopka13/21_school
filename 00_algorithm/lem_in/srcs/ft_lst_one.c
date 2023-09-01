#include "../includes/lem_in.h"

void	ft_lstclear_one(t_fin_ways **lst)
{
	t_fin_ways	*buf;

	while (*lst)
	{
		buf = *lst;
		*lst = (*lst)->next;
		free(buf->step_index);
		free(buf);
	}
}

void	ft_lst_add_back_one(t_fin_ways **lst, t_fin_ways *new)
{
	t_fin_ways	*back;

	if (*lst != NULL)
	{
		back = ft_lstlast_one(*lst);
		back->next = new;
	}
	else
		*lst = new;
}

int	ft_lstsize_one(t_fin_ways *lst)
{
	t_fin_ways	*move;
	int		size;

	size = 1;
	move = lst;
	if (!lst)
		return (0);
	while (move->next != NULL)
	{
		size++;
		move = move->next;
	}
	return (size);
}

int* full_arr_int(t_step *lst, int size)
{
    int *arr = (int*)ft_malloc(size * sizeof(int));
    int ch = 0;
	if (!lst)
		return NULL;
	while (lst->next != NULL)
	{
        arr[ch] = lst->room;
		lst = lst->next;
        ch++;
	}
    arr[ch] = lst->room;
    return arr;
}

t_fin_ways	*ft_lstlast_one(t_fin_ways *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	else
		return (0);
	return (lst);
}

t_fin_ways	*ft_lstnew_one(t_step	**steps)
{
	t_fin_ways	*new;

	new = (t_fin_ways *)ft_malloc(sizeof(t_fin_ways));
    new->length_way = ft_lstsize_pn(*steps);
    new->step_index = full_arr_int(*steps, new->length_way);
	new->next = NULL;
	return (new);
}
