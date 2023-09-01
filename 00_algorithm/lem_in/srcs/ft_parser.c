#include "../includes/lem_in.h"

static enum str_type	ft_get_type(char *str){
	enum str_type	return_type;
	char			*temp;
	
	print_debug("ft_get_type start\n");

	if (g_vars.ant_number_flag) {						// Get ant number
		return return_type = ANTS_NUMBER;
	} else if (!ft_strcmp(str, "##start") ||			// Get start str
		g_vars.start_flag == 1) {
		return return_type = ROOM_START;
	} else if (!ft_strcmp(str, "##end") ||				// Get end str
				g_vars.end_flag == 1) {
		return return_type = ROOM_END;
	} else if (str[0] == '#') {							// Comment
		return return_type = COMMENT;
	} else if (g_vars.end_rooms_flag == 0) {			// Get rooms
		return return_type = ROOM_ADD;
	} else if (g_vars.end_rooms_flag) {					// Get connections
		return return_type = ROOM_CONN;
	}

	if(!g_vars.ret_value){
		temp = ft_strdup("Bad map: ");
		g_vars.err_msg = ft_strjoin(temp, str);
		g_vars.ret_value = -1;
		free(temp);
	}

	print_debug("ft_get_type finish with ERROR\n");
	g_vars.ret_value = -1;
	return return_type = STR_ERROR;						// Bad str
}

static int				ft_put_room_to_list(t_room *next_room){
	print_debug("ft_put_room_to_list start. number_of_rooms = %d\n", g_vars.number_of_rooms);
	t_room			**temp;
	unsigned int	i;
	
	if (g_vars.number_of_rooms == 0) {
		g_vars.list_room = (t_room **)malloc(sizeof(t_room *));
		if (!g_vars.list_room)
			goto error;
		g_vars.list_room[0] = next_room;
		g_vars.number_of_rooms += 1;
		print_debug("ft_put_room_to_list finish success. number_of_rooms = %d\n", g_vars.number_of_rooms);
		return SUCCESS;
	} else {
		temp = (t_room **)malloc(sizeof(t_room *)
				* (g_vars.number_of_rooms + 1));
		if (!temp)
			goto error;
	}

	if(next_room == g_vars.start_room){
		temp[0] = next_room;
		for(i = 1; i <= g_vars.number_of_rooms; i++)
			temp[i] = g_vars.list_room[i - 1];
	} else {
		for(i = 0; i < g_vars.number_of_rooms; i++)
			temp[i] = g_vars.list_room[i];
		temp[i] = next_room;
	}

	free(g_vars.list_room);
	g_vars.number_of_rooms += 1;
	g_vars.list_room = temp;

	print_debug("ft_put_room_to_list finish success. number_of_rooms = %d\n", g_vars.number_of_rooms);
	return SUCCESS;
error:
	print_debug("ft_put_room_to_list finish with ERROR\n");
	if(!g_vars.ret_value){
		g_vars.err_msg = ft_strdup("malloc error");
		g_vars.ret_value = -1;
	}

	return ERROR;
}

static int				ft_preatoi_checker(char *str){
	print_debug("ft_preatoi_checker start. str: %s\n", str);
	size_t	size = ft_strlen(str);

	if(ft_strlen(str) > 9)
		goto error;

	for(unsigned long i = 0; i < size; i++)
		if(!ft_isdigit(str[i]))
			goto error;

	print_debug("ft_preatoi_checker finish success\n");
	return SUCCESS;
error:
	print_debug("ft_preatoi_checker finish with error\n");
	if(!g_vars.ret_value){
		g_vars.err_msg = ft_strdup("Count of ants too high.");
		g_vars.ret_value = -1;
	}
	return ERROR;
}

static int				ft_check_double_room(t_room *room){
	print_debug("ft_check_double_room start\n");
	// Check start and end
	if(g_vars.number_of_rooms == 0 && g_vars.end_room == NULL){ // This is first room
		print_debug("ft_check_double_room finish success\n");
		return SUCCESS;
	}
	if(g_vars.end_room != NULL &&							// Check end room
		(!ft_strcmp(g_vars.end_room->name, room->name)
		   || (g_vars.end_room->x == room->x
			   && g_vars.end_room->y == room->y))){
		print_debug("ft_check_double_room finish with ERROR\n");
		return ERROR;
   }
	for(unsigned int i = 0; i < g_vars.number_of_rooms; i++){
		if(!ft_strcmp(g_vars.list_room[i]->name, room->name)
		   || (g_vars.list_room[i]->x == room->x
			   && g_vars.list_room[i]->y == room->y)){
			print_debug("ft_check_double_room finish with ERROR\n");
			return ERROR;
		}
	}
	print_debug("ft_check_double_room finish success\n");
	return SUCCESS;
}

static t_room			*ft_create_room(char **args){
	print_debug("ft_create_room start.\n");
	t_room	*room;

	if(ft_preatoi_checker(args[1]) || ft_preatoi_checker(args[2]))
		goto error;

	if(!(room = (t_room *)malloc(sizeof(t_room)))){
		g_vars.err_msg = ft_strdup("malloc error");
		g_vars.ret_value = -1;
		goto error;
	}

	room->name = args[0];
	room->x = ft_atoi(args[1]);
	room->y = ft_atoi(args[2]);
	room->connections = NULL;
	room->conn_pointers = NULL;
	room->number_of_conn = 0;
	room->ants_inside = 0;
	room->ant_name = 0;
	if(ft_check_double_room(room)){
		free(room);
		goto error;
	}
	free(args[1]);
	free(args[2]);
	free(args);

	print_debug("ft_create_room finish success\n");
	return room;

error:
	free(args[0]);
	free(args[1]);
	free(args[2]);
	free(args);
	g_vars.ret_value = -1;

	print_debug("ft_create_room finish with ERROR\n");
	return NULL;
}

static int				ft_get_str_number(char **list){
	// Counts the number of rows in the list "str"
	print_debug("ft_get_str_number start.\n");
	int	ret = 0;

	if(!list)
		return 0;

	while(list[ret])
		ret++;
	
	print_debug("ft_get_str_number end. ret = %d\n",
				ret);
	return ret;
}

static void				ft_free_list(char **list){
	int i;

	if(list == NULL)
		return ;

	for(i = 0; list[i] != NULL; i++)
		free(list[i]);
	free(list);
	return ;
}

static int				ft_get_start_room(char *str){
	print_debug("ft_get_start_room start. str: %s; start_flag = %d\n",
				str, g_vars.start_flag);
	char	**list;

	if (g_vars.start_flag == 2 ||							// If double start lable in map
		g_vars.end_flag == 1)								// If get end label after start label
		goto error;

	if (!g_vars.start_flag) {
		g_vars.start_flag = 1;
		print_debug("ft_get_start_room finish success. start_flag = %d\n",
					g_vars.start_flag);
		return SUCCESS;
	}

	list = ft_split(str, ' ');
	if(ft_get_str_number(list) != 3){
		ft_free_list(list);
		goto error;
	}
	if (!(g_vars.start_room = ft_create_room(list)))
		goto error;
	g_vars.start_room->ants_inside = g_vars.ant_number;

	if(ft_put_room_to_list(g_vars.start_room))
		goto error;

	g_vars.start_flag = 2;

	print_debug("ft_get_start_room finish success\n");
	return SUCCESS;

error: {
	if(!g_vars.ret_value){
		char *temp = ft_strdup("Bad map: ");
		g_vars.err_msg = ft_strjoin(temp, str);
		g_vars.ret_value = -1;
		// free(str);
		free(temp);
	}

	print_debug("ft_get_start_room finish with ERROR\n");
	return ERROR;										// Bad str
	}
}

static int				ft_get_end_room(char *str){
	print_debug("ft_get_end_room start. str: %s; end_rooms_flag = %d\n",
				str, g_vars.end_rooms_flag);
	char	**list;

	if (g_vars.end_flag == 2 ||								// If double end lable in map
		g_vars.start_flag == 1)								// If get start label after end label
		goto error;

	if (g_vars.end_flag == 0) {								// For scip end lable
		g_vars.end_flag = 1;
		return SUCCESS;
	}

	list = ft_split(str, ' ');
	if(ft_get_str_number(list) != 3){
		ft_free_list(list);
		goto error;
	}
	if (!(g_vars.end_room = ft_create_room(list)))
		goto error;

	g_vars.end_flag = 2;

	print_debug("ft_get_end_room finish success\n");
	return SUCCESS;

error: {
	if(!g_vars.ret_value){
		char *temp = ft_strdup("Bad map: ");
		g_vars.err_msg = ft_strjoin(temp, str);
		g_vars.ret_value = -1;
		// free(str);
		free(temp);
	}

	print_debug("ft_get_end_room finish with ERROR\n");
	return ERROR;		
	}								// Bad str
}

static int				ft_get_ant_number(char *str){
	print_debug("ft_get_ant_number start. str: %s\n", str);
	g_vars.ant_number_flag = 0;

	if(ft_preatoi_checker(str))
		goto error;

	g_vars.ant_number = ft_atoi(str);

	if(g_vars.ant_number == 0)
		goto error;

	print_debug("ft_get_ant_number finish success\n");
	return SUCCESS;
error:
	print_debug("ft_get_ant_number finish with error\n");
	return ERROR;
}

static int				ft_add_room(char *str){
	print_debug("ft_add_room start. str: %s\n",
				str);
	char	**list;
	t_room	*temp;

	list = ft_split(str, ' ');

	if (ft_get_str_number(list) != 3) {					// Str with rooms end
		for(int i = 0; list[i]; i++)
			free(list[i]);
		free(list);
		// if(g_vars.number_of_rooms)
		g_vars.end_rooms_flag = 1;
		ft_parser(str);
		goto success;
	}

	if (!(temp = ft_create_room(list)) ||
		ft_put_room_to_list(temp))
		goto error;

success:
	print_debug("ft_add_room finish success\n");
	return SUCCESS;

error: {
	if(!g_vars.ret_value){
		char *tmp = ft_strdup("Bad map: ");
		g_vars.err_msg = ft_strjoin(tmp, str);
		g_vars.ret_value = -1;
		free(tmp);
	}

	print_debug("ft_add_room finish with ERROR\n");
	return ERROR;										// Bad str
	}
}

static t_room			*ft_get_room(char *name){
	print_debug("ft_get_room start. str: %s\n", name);
	t_room	*ret = NULL;

	// if(!ft_strcmp(g_vars.start_room->name, name)){
	// 	return g_vars.start_room;
	// } else if (!ft_strcmp(g_vars.end_room->name, name)){
	// 	return g_vars.end_room;
	// } else {
		for(unsigned int i = 0; i < g_vars.number_of_rooms; i++){
			if (!ft_strcmp(g_vars.list_room[i]->name, name)){
				ret = g_vars.list_room[i];
				break;
			}
		}
	// }

	print_debug("ft_get_room finish success. ret - %p\n", ret);
	return ret;
}

static int				ft_check_to_have_this_connection(t_room *curent_room, t_room *room_connect){
	for(unsigned int i = 0; i < curent_room->number_of_conn; i++){
		if(curent_room->conn_pointers[i] == room_connect)
			return 1;
	}

	return 0;
}

static int				ft_add_one_connection(t_room *curent_room,
											t_room *room_connect,
											char *room_name){
	print_debug("ft_add_one_connection start. name: %s, connection_number = %d, room_name = %s\n",
			room_name, curent_room->number_of_conn, curent_room->name);
	char			**conn_list = NULL;
	t_room			**conn_pointer = NULL;
	unsigned int	i = 0;

	if(curent_room->number_of_conn == 0){
		if(!(curent_room->connections = (char**)malloc(sizeof(char*))) ||
			!(curent_room->conn_pointers = (t_room**)malloc(sizeof(t_room*))))
			goto error;
		curent_room->connections[0] = room_name;
		curent_room->conn_pointers[0] = room_connect;
		curent_room->number_of_conn += 1;
	} else {
		if(ft_check_to_have_this_connection(curent_room, room_connect)){
			free(room_name);
			goto success;
		}
		if(!(conn_list = (char**)malloc(sizeof(char*)
			* (curent_room->number_of_conn + 1))) ||
			!(conn_pointer = (t_room**)malloc(sizeof(t_room*)
			* (curent_room->number_of_conn + 1))))
			goto error;
		while(i < curent_room->number_of_conn){
			conn_list[i] = curent_room->connections[i];
			conn_pointer[i] = curent_room->conn_pointers[i];
			i++;
		}
		conn_list[i] = room_name;
		conn_pointer[i] = room_connect;
		free(curent_room->connections);
		free(curent_room->conn_pointers);
		curent_room->connections = conn_list;
		curent_room->conn_pointers = conn_pointer;
		curent_room->number_of_conn += 1;
	}
	goto success;

success:
	print_debug("ft_add_one_connection end success. connection_number = %d, room_name = %s\n",
			curent_room->number_of_conn, curent_room->name);
	return SUCCESS;
error:
	free(room_name);
	print_debug("ft_add_one_connection end with ERROR\n");
	if(!g_vars.ret_value){
		g_vars.err_msg = ft_strdup("malloc error");
		g_vars.ret_value = -1;
	}
	return ERROR;
}

static int				ft_remove_room_from_list(unsigned int room_index){
	print_debug("ft_remove_room_from_list start\n");
	t_room		**tmp_list;
	int			m = 0;

	if(!(tmp_list = (t_room**)malloc(sizeof(t_room*) * (g_vars.number_of_rooms - 1))))
		goto error;

	for(unsigned int i = 0; i < g_vars.number_of_rooms; i++){
		if(i == room_index)
			continue;
		tmp_list[m] = g_vars.list_room[i];
		m++;
	}
	free(g_vars.list_room[room_index]->name);
	free(g_vars.list_room[room_index]);
	free(g_vars.list_room);
	g_vars.list_room = tmp_list;
	g_vars.number_of_rooms -= 1;

	print_debug("ft_remove_room_from_list finish success\n");
	return SUCCESS;
error:
	print_debug("ft_remove_room_from_list finish with error\n");
	return ERROR;
}

int						ft_delete_empty_rooms(void){
	print_debug("ft_delete_empty_rooms start\n");
	unsigned int	i = 0;


	if(g_vars.start_room != NULL &&
		(g_vars.start_room->number_of_conn == 0 ||
		g_vars.end_room->conn_pointers == 0)){
		if(!g_vars.ret_value){
			g_vars.err_msg = ft_strdup("start or end room don't have connectoins!");
			g_vars.ret_value = -1;
		}
		goto error;
	}

	while(i < g_vars.number_of_rooms){
		if(g_vars.list_room[i]->number_of_conn == 0){
			if(ft_remove_room_from_list(i))
				goto error;
			continue;
		}
		i++;
	}

	if(g_vars.number_of_rooms == 0){
		if(!g_vars.ret_value){
			g_vars.err_msg = ft_strdup("No rooms or no connections\n");
			g_vars.ret_value = -1;
		}
		goto error;
	}

	print_debug("ft_parser finish success\n");
	return SUCCESS;
error:
	print_debug("ft_parser finish with error\n");
	return ERROR;
}

static int				ft_add_connection(char *str){
	print_debug("ft_add_connection start. str: %s\n",
			str);
	char	**list;
	t_room	*room_1;
	t_room	*room_2;
	char	*tmp_1;
	char	*tmp_2;

	if(!g_vars.end_room || !g_vars.start_room ||				// No end or start room
		(g_vars.list_room[g_vars.number_of_rooms - 1] !=
		g_vars.end_room &&
		ft_put_room_to_list(g_vars.end_room)))					// Add end_room to end list_room
		goto error;
	
	list = ft_split(str, '-');
	if(ft_get_str_number(list) != 2){
		for(int i = 0; list[i]; i++)
			free(list[i]);
		free(list);
		goto error;
	} else {
		tmp_1 = ft_strtrim(list[0], " \t");
		tmp_2 = ft_strtrim(list[1], " \t");
		if (!ft_strlen(tmp_1) || !ft_strlen(tmp_2)){
			for(int i = 0; list[i]; i++)
				free(list[i]);
			free(list);
			goto error;
		}
		room_1 = ft_get_room(tmp_1);
		room_2 = ft_get_room(tmp_2);
		if (!room_1 || !room_2){
			for(int i = 0; list[i]; i++)
				free(list[i]);
			free(list);
			free(tmp_1);
			free(tmp_2);
			goto error;
		} else {
			if (ft_add_one_connection(room_1, room_2, tmp_2) ||
				ft_add_one_connection(room_2, room_1, tmp_1))
				goto error;
		}
	}
	for(int i = 0; list[i]; i++)
		free(list[i]);
	free(list);

	print_debug("ft_add_connection finish success\n");
	return SUCCESS;

error:
	if(!g_vars.ret_value){
		char *tmp = ft_strdup("Bad map: ");
		g_vars.err_msg = ft_strjoin(tmp, str);
		g_vars.ret_value = -1;
		free(tmp);
	}

	print_debug("ft_add_room finish with ERROR\n");
	return ERROR;										// Bad str
}

int						ft_parser(char *str){
	// Parser for strings in map
	enum str_type	type;
	int				ret;
	char			*temp;

	print_debug("ft_parser start. str = %s\n", str);

	temp = ft_strtrim(str, " \t\n");

	if(ft_strlen(temp) == 0){
		free(temp);
		print_debug("ft_parser finish success\n");
		return SUCCESS;
	}

	type = ft_get_type(temp);							// Get type
	switch (type) {
	case ANTS_NUMBER:
		ret = ft_get_ant_number(temp);					// Get ant number
		break;
	case ROOM_START:
		ret = ft_get_start_room(temp);					// Create start room
		break;
	case ROOM_END:
		ret = ft_get_end_room(temp);					// Create end room
		break;
	case ROOM_ADD:
		ret = ft_add_room(temp);						// Create end room
		break;
	case ROOM_CONN:
		ret = ft_add_connection(temp);					// Create end room
		break;
	case COMMENT:
		ret = 0;										// Comment
		break;
	default:
		ret = 1;										// Return error
	};
	free(temp);

	if (ret)
		goto error;

	print_debug("ft_parser finish success\n");
	return SUCCESS;

error:
	if(!g_vars.ret_value){
		char *tmp = ft_strdup("Bad map: ");
		g_vars.err_msg = ft_strjoin(tmp, str);
		g_vars.ret_value = -1;
		free(tmp);
	}

	print_debug("ft_parser finish with ERROR\n");
	return ERROR;										// Bad str
}
