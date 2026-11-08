/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolf <ewolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 12:29:37 by ewolf             #+#    #+#             */
/*   Updated: 2026/11/03 16:08:31 by ewolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_simple_algorithm_wolf(int *a, int *b, int *len_stacks)
{
	int	i;
	int	smalest;
	int cur_run;
	int pos;
	int run_for;
	int count = 0;

	cur_run = 0;
	run_for = len_stacks[0];
	while (cur_run < run_for)
	{
		pos = 0;
		smalest = a[0];
		i = 0;
		while (++i < len_stacks[0])
		{
			if (a[i] < smalest)
			{
				smalest = a[i];
				pos = i;
			}
		}
		i = 0;
		while (i++ < pos)
			count += ft_det_move("ra", a, b, len_stacks);
		count += ft_det_move("pb", a, b, len_stacks);
		cur_run++;
	}
	while (len_stacks[1])
		count += ft_det_move("pa", a, b, len_stacks);
	return (count);
}


int	ft_simple_algorithm_huber(int *a, int *b, int *len_stacks)
{
    int	i;
    int	min_index;
    int	rotations;
	int count = 0;

    while (len_stacks[0] > 0)
    {
        min_index = 0;
        i = 1;
        while (i < len_stacks[0])
        {
            if (a[i] < a[min_index])
                min_index = i;
            i++;
        }
        if (min_index <= len_stacks[0] / 2)
            rotations = min_index;
        else
            rotations = len_stacks[0] - min_index;
        i = 0;
        while (i < rotations)
        {
            if (min_index <= len_stacks[0] / 2)
                count += ft_det_move("ra", a, b, len_stacks);
            else
                count += ft_det_move("rra", a, b, len_stacks);
            i++;
        }
        count += ft_det_move("pb", a, b, len_stacks);;
    }
    while (len_stacks[1] > 0)
        count += ft_det_move("pa", a, b, len_stacks);;
	return (count);
}
