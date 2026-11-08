/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolf <ewolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 12:29:37 by ewolf             #+#    #+#             */
/*   Updated: 2026/11/02 17:31:31 by ewolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_simple_algorithm_wolf(int *a, int *b, int *len_a, int *len_b)
{
	int	i;
	int	smalest;
	int cur_run;
	int pos;
	int run_for;
	int count = 0;

	cur_run = 0;
	run_for = *len_a;
	while (cur_run < run_for)
	{
		pos = 0;
		smalest = a[0];
		i = 0;
		while (++i < *len_a)
		{
			if (a[i] < smalest)
			{
				smalest = a[i];
				pos = i;
			}
		}
		i = 0;
		while (i++ < pos)
			count += ft_det_move("ra", a, b, len_a, len_b);
		count += ft_det_move("pb", a, b, len_a, len_b);
		cur_run++;
	}
	while (*len_b)
		count += ft_det_move("pa", a, b, len_a, len_b);
	return (count);
}


int	ft_simple_algorithm_huber(int *a, int *b, int *len_a, int *len_b)
{
    int	i;
    int	min_index;
    int	rotations;
	int count = 0;

    while (*len_a > 0)
    {
        min_index = 0;
        i = 1;
        while (i < *len_a)
        {
            if (a[i] < a[min_index])
                min_index = i;
            i++;
        }
        if (min_index <= *len_a / 2)
            rotations = min_index;
        else
            rotations = *len_a - min_index;
        i = 0;
        while (i < rotations)
        {
            if (min_index <= *len_a / 2)
                count += ft_det_move("ra", a, b, len_a, len_b);
            else
                count += ft_det_move("rra", a, b, len_a, len_b);
            i++;
        }
        count += ft_det_move("pb", a, b, len_a, len_b);;
    }
    while (*len_b > 0)
        count += ft_det_move("pa", a, b, len_a, len_b);;
	return (count);
}
