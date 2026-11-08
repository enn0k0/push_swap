/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_agorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolf <ewolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:00:53 by ewolf             #+#    #+#             */
/*   Updated: 2026/11/09 00:02:50 by ewolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_index(int *arr, int insert, char lowest, int size)
{
	int	i;

	i = 0;
	if (lowest == 't')
	{
		while (i < size)
		{
			if (insert < arr[i])
				return (i);
			i++;
		}
		return (i);
	}
	if (lowest == 'b')
	{
		while (i < size)
		{
			if (insert > arr[i])
				return (i);
			i++;
		}
		return (size);
	}
	return (100);
}


int ft_sort_a(int *a, int *b, int *len_stacks, int group_size)
{
	int i = 0;
	int count = 0;
	int cur = 0;
	int pos = 0;
	
	while (cur < group_size)
	{
		i = 0;
		pos = ft_find_index(a, b[0], 't', group_size + cur);
		while (i < pos && pos != group_size + cur)
		{
			count += ft_det_move("ra", a, b, len_stacks);
			i++;
		}
		i = 0;
		count += ft_det_move("pa", a, b, len_stacks);
		if (pos == group_size + cur)
			count += ft_det_move("ra", a, b, len_stacks);
		while (i < pos && pos != group_size + cur)
		{
			count += ft_det_move("rra", a, b, len_stacks);
			i++;
		}
		cur++;
	}
	return (count);
}

int ft_sort_b(int *a, int *b, int *len_stacks, int group_size)
{
	int i = 0;
	int count = 0;
	int cur = 0;
	int pos = 0;
	
	while (cur < group_size)
	{
		i = 0;
		pos = ft_find_index(b, a[0], 'b', group_size + cur);
		
		while (i < pos && pos != group_size + cur)
		{
			count += ft_det_move("rb", a, b, len_stacks);
			i++;
		}
		i = 0;
		count += ft_det_move("pb", a, b, len_stacks);
		if (pos == group_size + cur)
			count += ft_det_move("rb", a, b, len_stacks);
		while (i < pos && pos != group_size + cur)
		{
			count += ft_det_move("rrb", a, b, len_stacks);
			i++;
		}
		cur++;
	}
	return (count);
}

int ft_complex_algorithm(int *a, int *b, int *len_stacks)
{
	int count = 0;
	int group_size;
	group_size = 2;
	
	while (len_stacks[0])
	{
		if (a[0] > a[1])
			count += ft_det_move("sa", a, b, len_stacks);
		count += ft_det_move("pb", a, b, len_stacks);
		count += ft_det_move("pb", a, b, len_stacks);
	}
	count += ft_det_move("pa", a, b, len_stacks);
	count += ft_det_move("pa", a, b, len_stacks);
	count += ft_sort_a(a, b, len_stacks, group_size);
	
	count += ft_det_move("pa", a, b, len_stacks);
	count += ft_det_move("pa", a, b, len_stacks);
	count += ft_sort_b(a, b, len_stacks, group_size);
	group_size = 4;
	count += ft_sort_a(a, b, len_stacks, group_size);
	
	// count += ft_det_move("pa", a, b, len_stacks);
	// count += ft_det_move("pa", a, b, len_stacks);
	// group_size = 2;
	// count += ft_sort_a(a, b, len_stacks, group_size);

	// count += ft_det_move("pa", a, b, len_stacks);
	// count += ft_det_move("pa", a, b, len_stacks);
	// count += ft_sort_b(a, b, len_stacks, group_size);
	
	// group_size = 4;
	// count += ft_sort_b(a, b, len_stacks, group_size);

	// group_size = 8;
	// count += ft_sort_a(a, b, len_stacks, group_size);
	
	
	return (count);
}



// int main(void)
// {
// 	int arr[] = {1, 9};
// 	int size = 2;
// 	int insert = 10;
// 	ft_printf("\n%i\n\n", ft_find_index(arr, insert, 't', size));
// }

