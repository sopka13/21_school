#include "../includes/lem_in.h"

int check_connection(int dest) 
{
	if(dest == 0)
		return 0;
	else if (g_cur_rooms[dest] == ' ')
		return 1;
	else
		return 0;
}

void create_matrix(unsigned int number_of_rooms)
{
	g_sm_matrix = (char**)malloc(number_of_rooms * sizeof(char*));
	for (unsigned int i = 0; i<number_of_rooms; i++)
	{
		g_sm_matrix[i] = (char*)malloc(number_of_rooms * sizeof(char));
		for (unsigned int j = 0; j<number_of_rooms; j++)
		{
			g_sm_matrix[i][j] = ' ';
		}
	}
}

void g_cur_rooms_create(unsigned int number_of_rooms, int create)
{
	if (create)
		g_cur_rooms = (char*)malloc(number_of_rooms * sizeof(char));
	for (unsigned int j = 0; j < number_of_rooms; j++)
		g_cur_rooms[j] = ' ';
}

void full_matrix(int i, int j, char a, char b)
{
	g_sm_matrix[i][j] = a;
	g_sm_matrix[j][i] = b;
}

int find_ch(int room, int start, char c)
{
	for (unsigned int j = start; j < g_vars.number_of_rooms; j++)
	{
		if (g_sm_matrix[room][j] == c)
			return j;
	}
	return -1;
}

int finish_check(int prew, int room)
{
	(void)prew;
	for(unsigned int i = 0; i < g_vars.list_room[room]->number_of_conn; i++)
	{
		if (g_vars.list_room[room]->conn_pointers[i]->index == (int)g_vars.number_of_rooms - 1)
		{
			if (find_ch(room, 0, '+') != -1)
				return 0;
			else
				return 1;
		}
	}
	return 0;
}

void rollback(int prew, int room)
{
	if (g_cur_rooms[room] != '-')
	{
		if (g_sm_matrix[prew][room] == '+')
			full_matrix(prew, room, ' ', ' ');

		else if (g_sm_matrix[prew][room] == ' ')
			full_matrix(prew, room, '-', '+');

		g_cur_rooms[room] = '-';
	}
}

int room_check(int prew, int room)
{
	if (check_connection(room))
	{
		g_cur_rooms[room] = '+';
		if (g_sm_matrix[prew][room] == '-')
			full_matrix(prew, room, ' ', ' ');
		else if (g_sm_matrix[prew][room] == ' ')
			full_matrix(prew, room, '+', '-');
		return(full_current_step(prew, room));
	}
	return -3;
}

int find_minus(int prew, int room)
{
	int ch = 0;
	int a;
	
	while (ch != -1)
	{
		ch = find_ch(room, ch, '-');
		if (ch == -1)
			continue;
		a = room_check(room, ch);
		if (a == -1)
			return -1;
		else if (a == -2)
			rollback(room, ch);
		ch = find_ch(room, ch + 1, '-');
	}
	rollback(prew, room);
	return -2; 
}

int full_current_step(int prew, int room)
{
	int a;
	if (room == 0)
	{
		rollback(prew, room);
		return -2;
	}

	if (finish_check(prew, room) || room == (int)g_vars.number_of_rooms - 1)
	{
		if (room != (int)g_vars.number_of_rooms - 1)
		{   
			g_cur_rooms[g_vars.number_of_rooms - 1] = '+';
			full_matrix(room, g_vars.number_of_rooms - 1, '+', ' '); 
		}
		g_vars.number_of_ways++; 
		return -1; 
	}
	
	if (room != 0 && find_ch(room, 0,'+') != -1)
		return find_minus(prew, room);
	else
	{    
		for (unsigned int i = 0; i < g_vars.list_room[room]->number_of_conn; i++)
		{
			a = room_check(room, g_vars.list_room[room]->conn_pointers[i]->index);
			if (a == -2)
				continue;
			if (a == -1)
				return -1;
		}
	}
	rollback(prew, room);
	return -2;
}

void finish_ways()
{
	int room;

	room = find_ch(0, 0, '+');
	while (room != -1)
	{
		ft_lst_add_back_pn(&g_steps, ft_lstnew_pn(0,' ', 0));
		
		if (room != -1)
			g_sm_matrix[0][room] = ' ';
		while (room != -1)
		{
			ft_lst_add_back_pn(&g_steps, ft_lstnew_pn(room,' ', 0));
			room = find_ch(room, 0, '+');
		}
		ft_lst_add_back_one(&g_fin_ways, ft_lstnew_one(&g_steps));
		ft_lstclear_pn(&g_steps);
		room = find_ch(0, 0, '+');
	}
}

void clean_matrix()
{
	if(g_sm_matrix != NULL)
	{
		for (unsigned int i = 0; i < g_vars.number_of_rooms; i++)
		{
			free(g_sm_matrix[i]);
		}
		free(g_sm_matrix);
	}
	if (g_cur_rooms != NULL)
		free(g_cur_rooms);
}

void ft_alg()
{
	int a;
	g_vars.number_of_ways = 0;

	for(unsigned int i = 0; i < g_vars.number_of_rooms; i++)
		g_vars.list_room[i]->index = i;

	create_matrix(g_vars.number_of_rooms); 
	g_cur_rooms_create(g_vars.number_of_rooms, 1);
	for (unsigned int i = 0; i < g_vars.list_room[0]->number_of_conn; i++)
	{
		g_cur_rooms[0] = '+';
		g_cur_rooms[g_vars.list_room[0]->conn_pointers[i]->index] = '+';
		full_matrix(0, g_vars.list_room[0]->conn_pointers[i]->index, '+', ' ');
		a = full_current_step(0, g_vars.list_room[0]->conn_pointers[i]->index);
		if (a == -2)
			rollback(0, g_vars.list_room[0]->conn_pointers[i]->index);
		g_cur_rooms_create(g_vars.number_of_rooms, 0);
	}
	if (g_vars.visio)
		ft_print_matrix(g_sm_matrix);
	finish_ways();
	clean_matrix();
}