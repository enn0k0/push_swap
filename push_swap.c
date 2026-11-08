/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolf <ewolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 15:08:08 by fhuber            #+#    #+#             */
/*   Updated: 2026/11/03 15:40:16 by ewolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int	a[argc - 1];
	int	b[argc - 1];
	int len_stacks[2];
	int i;
	int	a_copy[argc - 1];

	
	i = 0;
	len_stacks[0] = argc - 1;
	len_stacks[1] = 0;
	ft_convert_to_arr(argc, argv, a);
	ft_convert_to_arr(argc, argv, a_copy);

	// ft_printf("A | B\n");
	// ft_printarr(a, b, argc);
	// ft_printf("\n");

	ft_printf("\n");
	// i = ft_simple_algorithm_wolf(a, b, len_stacks[0], len_stacks[1]);

	// ft_printarr(a, b, argc);
	// ft_printf("\n simple moves: %i\n\n\n", i);

	// i = ft_medium_algorithm(a_copy, b, len_stacks[0], len_stacks[1]);
	// ft_printarr(a_copy, b, argc);
	// ft_printf("\n medium moves: %i", i);

	i = ft_complex_algorithm(a_copy, b, len_stacks);
	// ft_printarr(a_copy, b, argc);
	ft_printf("\n complex moves: %i", i);

	
// 	ft_push(a, b, len_stacks[0], len_stacks[1]);
// 	ft_push(a, b, len_stacks[0], len_stacks[1]);
// 	ft_printf("\n\n");
// 	ft_printarr(a, b, argc);
// 	ft_printf("\na %i, b %i\n\n", len_a, len_b);
// 	ft_push(b, a, len_stacks[1], len_stacks[0]);
// 	ft_push(b, a, len_stacks[1], len_stacks[0]);
// 	ft_printarr(a, b, argc);
// 	printf("\na %i, b %i\n\n", len_a, len_b);
}