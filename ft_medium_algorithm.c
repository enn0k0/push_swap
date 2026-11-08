/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolf <ewolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:43:10 by fhuber            #+#    #+#             */
/*   Updated: 2026/11/03 16:12:47 by ewolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_rank(int *a, int len, int i)
{
	int	j;
	int	rank;

	j = 0;
	rank = 0;
	while (j < len)
	{
		if (a[j] < a[i])
			rank++;
		j++;
	}
	return (rank);
}

int	ft_rank_values(int *a, int len)
{
	int	i;
	int	*save_rank;

	save_rank = malloc(sizeof(*save_rank) * len);
	if (!save_rank)
		return (0);
	i = 0;
	while (i < len)
	{
		save_rank[i] = ft_get_rank(a, len, i);
		i++;
	}
	i = 0;
	while (i < len)
	{
		a[i] = save_rank[i];
		i++;
	}
	free(save_rank);
	return (1);
}

static int	ft_get_chunk(int *a, int *b, int *len_stacks, int count)
{
	int	chunk_min;
	int	chunk_max;
	int	chunk_size;
	int	i;

	chunk_min = 0;
	chunk_size = 1;
	while (chunk_size * chunk_size < (len_stacks[0] + len_stacks[1]))
		chunk_size++;
	while (chunk_min < (len_stacks[0] + len_stacks[1]))
	{
		chunk_max = chunk_min + chunk_size - 1;
		i = len_stacks[0];
		while (i > 0)
		{
			if (a[0] >= chunk_min && a[0] <= chunk_max)
				count += ft_det_move("pb", a, b, len_stacks);
			else
				count += ft_det_move("ra", a, b, len_stacks);
			i--;
		}
		chunk_min += chunk_size;
	}
	return (count);
}

static int	ft_set_target(int *a, int *b, int *len_stacks, int count)
{
	int	target;
	int	pos;

	target = len_stacks[0] + len_stacks[1] - 1;
	while (len_stacks[1] > 0)
	{
		pos = 0;
		while (pos < len_stacks[1] && b[pos] != target)
			pos++;
		if (pos > len_stacks[1] / 2)
			pos -= len_stacks[1];
		while (pos > 0)
		{
			count += ft_det_move("rb", a, b, len_stacks);
			pos--;
		}
		while (pos < 0)
		{
			count += ft_det_move("rrb", a, b, len_stacks);
			pos++;
		}
		count += ft_det_move("pa", a, b, len_stacks);
		target--;
	}
	return (count);
}

int	ft_medium_algorithm(int *a, int *b, int *len_stacks)
{
	int	count;

	count = 0;
	if (!ft_rank_values(a, len_stacks[0]))
		return (0);
	count = ft_get_chunk(a, b, len_stacks, count);
	count = ft_set_target(a, b, len_stacks, count);
	return (count);
}
