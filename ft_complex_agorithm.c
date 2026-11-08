/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_agorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolf <ewolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:00:53 by ewolf             #+#    #+#             */
/*   Updated: 2026/11/03 17:11:11 by ewolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_index(int *arr, int insert, int start, int size)
{
	int	i;
	int ret;

	i = start;
	ret = 0;
	// if (insert < arr[i])
	// 		ret = i;
	while (i < size)
	{
		if (insert < arr[i])
			ret = i;
		i++;
	}
	// if (insert > arr[i - 1])
	// 	ret = i;
	return (ret);
}

int ft_complex_algorithm(int *a, int *b, int *len_stacks)
{
	int count = 0;
	int group_size = 99;
	int	i = 0;
	
	while (len_stacks[0])
	{
		if (a[0] < a[1])
			count += ft_det_move("sa", a, b, len_stacks);
		count += ft_det_move("pb", a, b, len_stacks);
		count += ft_det_move("pb", a, b, len_stacks);
	}
	count += ft_det_move("pa", a, b, len_stacks);
	count += ft_det_move("pa", a, b, len_stacks);
	group_size = ft_find_index(a, b[1], 0, 2);
	// ft_printf("\nind %i\n", group_size);
	while (i < group_size)
	{
		count += ft_det_move("ra", a, b, len_stacks);
		i++;
	}
	count += ft_det_move("pa", a, b, len_stacks);
	i = 0;
	while (i < group_size)
	{
		count += ft_det_move("rra", a, b, len_stacks);
		i++;
	}
	ft_printf("\nind %i\n", group_size);
	return (count);
}



int main(void)
{
	int arr[] = {7, 1};
	int size = 2;
	int insert = 0;
	ft_printf("\n%i\n\n", ft_find_index(arr, insert, 0, size));
}