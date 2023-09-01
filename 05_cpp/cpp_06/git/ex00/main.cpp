/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:15:03 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/01 10:18:37 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int		main(int argc, char** argv)
{
	t_vars	vars;

	ft_init_vars(&vars, argc, argv);
	if (ft_check_args(&vars))
		ft_exit(&vars);

	Scalar data(argv[1]);
	ft_write_result(data);
	return (0);
}