#include "../includes/lem_in.h"

void ft_print_matrix(char **matrix)
{
    ft_putstr_fd("\t", 1);
    
    for (int i = 0; i < (int)g_vars.number_of_rooms; i++)
    {
        ft_putstr_fd("\033[33m",1);
        ft_putstr_fd(g_vars.list_room[i]->name,1);
        ft_putstr_fd("\033[0m",1);
        ft_putstr_fd("\t", 1);
    }
    ft_putstr_fd("\n",1);
    for (int i = 0; i < (int)g_vars.number_of_rooms; i++)
    {
        ft_putstr_fd("\033[33m",1);
        ft_putstr_fd(g_vars.list_room[i]->name,1);
        ft_putstr_fd("\033[0m",1);
        ft_putstr_fd("\t", 1);
        for (int j = 0; j < (int)g_vars.number_of_rooms; j++)
        {
            ft_putstr_fd("\033[1;32m",1);
            ft_putchar_fd(matrix[i][j],1);
            ft_putstr_fd("\033[0m",1);
            ft_putstr_fd("\t", 1);
        }
        ft_putstr_fd("\n",1);
    }
    ft_putstr_fd("\n",1);
}

void ft_print_ways(t_fin_ways **g_fin_ways)
{
	ft_putstr_fd("\033[1;34mnomber of ways:\033[0m",1);
    ft_putstr_fd("\033[1;35m",1);
    ft_putstr_fd(ft_itoa(g_vars.number_of_ways),1);
    ft_putstr_fd("\033[0m",1);
    ft_putstr_fd("\n",1); 
	t_fin_ways *ways = *g_fin_ways;
	while (ways)
	{
		// ft_putstr_fd("\n",1);
		for (int i = 0; i < ways->length_way; i++)
		{
            ft_putstr_fd(g_vars.list_room[ways->step_index[i]]->name,1);
            if (i != ways->length_way - 1)
                ft_putstr_fd("\033[0;31m=>\033[0m",1);
        }
		ft_putstr_fd("\n",1);
		ways = ways->next;
	}
    ft_putstr_fd("\n",1);
}
