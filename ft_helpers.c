/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolf <ewolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:54:26 by ewolf             #+#    #+#             */
/*   Updated: 2026/11/03 13:40:54 by ewolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_det_double_move(char *move, int *a, int *b, int *len_a, int *len_b)
{
	if (ft_strcmp(move, "ss") == 0)
	{
		ft_swap(a);
		ft_swap(b);
	}
	else if (ft_strcmp(move, "rr") == 0)
	{
		ft_rotate(a, *len_a);
		ft_rotate(b, *len_b);
	}
	else if (ft_strcmp(move, "rrr") == 0)
	{
		ft_reverse_rotate(a, *len_a);
		ft_reverse_rotate(b, *len_b);
	}
}


int ft_det_move(char *move, int *a, int *b, int *len_a, int *len_b)
{
	if (ft_strcmp(move, "sa") == 0)
		ft_swap(a);
	else if (ft_strcmp(move, "sb") == 0)
		ft_swap(b);
	else if (ft_strcmp(move, "pa") == 0)
		ft_push(b, a, len_b, len_a);
	else if (ft_strcmp(move, "pb") == 0)
		ft_push(a, b, len_a, len_b);
	else if (ft_strcmp(move, "ra") == 0)
		ft_rotate(a, *len_a);
	else if (ft_strcmp(move, "rb") == 0)
		ft_rotate(b, *len_b);
	else if (ft_strcmp(move, "rra") == 0)
		ft_reverse_rotate(a, *len_a);
	else if (ft_strcmp(move, "rrb") == 0)
		ft_reverse_rotate(b, *len_b);
	else
		ft_det_double_move(move, a, b, len_a, len_b);
	ft_printf("%s\n", move);
	return (1);
}
