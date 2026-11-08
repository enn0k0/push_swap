/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuber <fhuber@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 14:42:45 by fhuber            #+#    #+#             */
/*   Updated: 2026/11/03 15:06:26 by fhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_complex_algorithm(int *a, int *b, int *len_a, int *len_b)
{
	int	count;
	int	i;

	count = 0;
	if (!ft_rank_values(a, *len_a))
		return (0);
	i = *len_a;
	while (i > 0)
		{
			if (a[0] % 2 == 0)
				count += ft_det_move("rb", a, b, len_a, len_b);
			else
				count += ft_det_move("rb", a, b, len_a, len_b);
		}
		while (pos < 0)
		{
			count += ft_det_move("rrb", a, b, len_a, len_b);
			pos++;
		}
	 
	return (count);	
}
