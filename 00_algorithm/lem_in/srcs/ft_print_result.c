#include "../includes/lem_in.h"

static void	ft_write_step(char *name, char *room_name){
	write(1, " L", 2);
	write(1, name, ft_strlen(name));
	write(1, "-", 1);
	write(1, room_name, ft_strlen(room_name));
}

static void	ft_reverse_iteration(t_fin_ways *way){
	print_debug("ft_reverse_iteration start. length_way = %d\n",
				way->length_way);
	register unsigned	curent_pos = way->length_way - 1;
	char			*temp = NULL;
	
	while(curent_pos){
		print_debug("ft_reverse_iteration %d iteration; curent_pos = %d\n", 
					way->length_way , curent_pos);
		if(g_vars.list_room[way->step_index[curent_pos]] == g_vars.end_room &&					// if curent_pos == end
			g_vars.list_room[way->step_index[curent_pos - 1]]->ants_inside > 0){
				// print_debug("1\n");
				temp = g_vars.list_room[way->step_index[curent_pos - 1]] == g_vars.start_room
					? ft_itoa(g_vars.ant_number
						- g_vars.list_room[way->step_index[curent_pos - 1]]->ants_inside
						+ 1)
					: ft_itoa(g_vars.list_room[way->step_index[curent_pos - 1]]->ant_name);
				ft_write_step(temp,
								g_vars.list_room[way->step_index[curent_pos]]->name);
				free(temp);
				g_vars.list_room[way->step_index[curent_pos]]->ants_inside += 1;
				g_vars.list_room[way->step_index[curent_pos - 1]]->ants_inside -= 1;
				(g_vars.list_room[way->step_index[curent_pos - 1]] == g_vars.start_room)
					? (g_vars.start_room->ant_name -= 1)
					: (g_vars.list_room[way->step_index[curent_pos - 1]]->ant_name = 0);
				curent_pos -= 1;
		} else if (g_vars.list_room[way->step_index[curent_pos - 1]] == g_vars.start_room &&	// if curent_pos == start + 1
					g_vars.list_room[way->step_index[curent_pos]]->ants_inside == 0 &&
					g_vars.list_room[way->step_index[curent_pos - 1]]->ants_inside > 0) {
				// print_debug("2\n");
				g_vars.list_room[way->step_index[curent_pos]]->ant_name
				= (g_vars.ant_number
					- g_vars.list_room[way->step_index[curent_pos - 1]]->ants_inside
					+ 1);
				temp = ft_itoa(g_vars.ant_number
						- g_vars.list_room[way->step_index[curent_pos - 1]]->ants_inside
						+ 1);
				ft_write_step(temp,
								g_vars.list_room[way->step_index[curent_pos]]->name);
				free(temp);
				g_vars.list_room[way->step_index[curent_pos]]->ants_inside += 1;
				g_vars.list_room[way->step_index[curent_pos - 1]]->ants_inside -= 1;
				curent_pos -= 1;
		} else if(g_vars.list_room[way->step_index[curent_pos - 1]]->ants_inside > 0 &&			// if other rooms
					g_vars.list_room[way->step_index[curent_pos]]->ants_inside == 0) {
				// print_debug("3\n");
				g_vars.list_room[way->step_index[curent_pos]]->ants_inside += 1;
				g_vars.list_room[way->step_index[curent_pos - 1]]->ants_inside -= 1;
				g_vars.list_room[way->step_index[curent_pos]]->ant_name
				= g_vars.list_room[way->step_index[curent_pos - 1]]->ant_name;
				temp = ft_itoa(g_vars.list_room[way->step_index[curent_pos - 1]]->ant_name);
				ft_write_step(temp,
								g_vars.list_room[way->step_index[curent_pos]]->name);
				free(temp);
				g_vars.list_room[way->step_index[curent_pos - 1]]->ant_name = 0;
				curent_pos -= 1;
		} else if (g_vars.list_room[way->step_index[curent_pos - 1]]->ants_inside == 0){
			// print_debug("4\n");
			curent_pos -= 1;
			continue;
		} else {																				// if traffic stop
			// print_debug("5\n");
			ft_write_step(ft_itoa(g_vars.list_room[way->step_index[curent_pos - 1]]->ant_name),
								"wait");


			exit(1);
			curent_pos -= 1;
		}
	}

	print_debug("ft_reverse_iteration finish success\n");
	return ;
// error:
// 	print_debug("ft_reverse_iteration finish with ERROR\n");
// 	return ;
}

int		ft_print_result(void){
	print_debug("ft_print_result start. ant_num = %d; number_of_ways = %d\n",
				g_vars.ant_number, g_vars.number_of_ways);
	unsigned int	ant_end = 0;

	if(g_vars.number_of_ways == 0)
		goto error;

	while(ant_end != g_vars.ant_number){
		t_fin_ways *temp = g_fin_ways;
		while (temp){
			ft_reverse_iteration(temp);
			temp = temp->next;
		}
		write(1, "\n", 1);
		print_debug("ats in end_room = %d\n", ant_end);
		ant_end = g_vars.end_room->ants_inside;
	}

	print_debug("ft_print_result finish success\n");
	return SUCCESS;
error:
	print_debug("ft_print_result finish with error\n");
	return ERROR;
}