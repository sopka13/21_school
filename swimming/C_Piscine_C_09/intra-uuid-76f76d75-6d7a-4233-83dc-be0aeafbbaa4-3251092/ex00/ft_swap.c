/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 21:08:14 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/02 21:08:31 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void  ft_swap(int * a, int * b)
{
	int tmp_a;

	tmp_a = * a;
	* a = * b;
	* b = tmp_a;
}
