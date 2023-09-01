/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:12:51 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/01 10:18:54 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _SCALAR_HPP_
#define _SCALAR_HPP_

#define ERR_1 "Error: invalid number of arguments\n"

#include <iostream>
#include <limits.h>
#include <cmath>

class Scalar
{
	char		m_char;
	int			m_int;
	float		m_float;
	double		m_double;
	Scalar();
public:
	Scalar(std::string str);
	Scalar(const Scalar &other);
	~Scalar();

	const Scalar &	operator= (const Scalar &scalar);
	std::string		getChar();
	void			getInt();
	void			getFloat();
	void			getDouble();
};

typedef struct	s_vars
{
	int			argc;
	char		**argv;
	int			num_err;
}				t_vars;

int		ft_check_args(t_vars *vars);
void	ft_exit(t_vars *vars);
void	ft_init_vars(t_vars *vars, int argc, char** argv);
void	ft_bzero(void *arr, size_t size);
void	ft_write_result(Scalar &data);

#endif