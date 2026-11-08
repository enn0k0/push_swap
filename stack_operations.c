/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolf <ewolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:24:53 by ewolf             #+#    #+#             */
/*   Updated: 2026/11/03 16:09:25 by ewolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_convert_to_arr(int argc, char **argv, int *arr)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

int	ft_swap(int *arr)
{
	int	c;

	c = arr[0];
	arr[0] = arr[1];
	arr[1] = c;
	return (1);
}

int	ft_rotate(int *arr, int len)
{
	int	i;
	int	first_numb;

	i = 0;
	first_numb = arr[0];
	i = 0;
	while (i < len) 
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[i - 1] = first_numb;
	return (1);
}

int ft_reverse_rotate(int *arr, int len)
{
	int	last_numb;

	last_numb = arr[len - 1];
	while (len >= 0) 
	{
		arr[len] = arr[len - 1];
		len--;
	}
	arr[0] = last_numb;
	return (1);
}

int ft_push(int *src, int *dst, int *len_src, int *len_dst)
{
	int	swap_int;
	int	i;

	swap_int = src[0];
	i = 0;
	while (i < *len_src - 1)
	{
		src[i] = src[i + 1];
		i++;
	}
	(*len_src)--;
	i = *len_dst + 1;
	while (i >= 0)
	{
		dst[i] = dst[i - 1];
		i--;
	}
	dst[0] = swap_int;
	(*len_dst)++;
	return (1);
}


//----------------------------REMOVE----------------------------
void ft_printarr(int *a, int *b, int argc)
{
	int i = 0; 
	while (i < argc - 1)
	{
		ft_printf("%i | %i\n", a[i], b[i]);
		i++;
	}
	
}
//----------------------------REMOVE----------------------------
