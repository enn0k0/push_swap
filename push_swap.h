/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolf <ewolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 15:22:04 by ewolf             #+#    #+#             */
/*   Updated: 2026/11/03 16:07:30 by ewolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *input, ...);
int		ft_atoi(const char *nptr);
int		ft_rotate(int *arr, int len);
int		ft_swap(int *arr);
int		ft_push(int *src, int *dst, int *len_src, int *len_dst);
int		ft_reverse_rotate(int *arr, int len);
int		ft_simple_algorithm_wolf(int *a, int *b, int *len_stacks);
//------------------------------------------------
void ft_printarr(int *a, int *b, int argc);
int	ft_simple_algorithm_huber(int *src, int *dst, int *len_stacks);
//------------------------------------------------
void	ft_convert_to_arr(int argc, char **argv, int *arr);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_det_move(char *move, int *a, int *b, int *len_stacks);
int		ft_medium_algorithm(int *a, int *b, int *len_stacks);
int		ft_complex_algorithm(int *a, int *b, int *len_stacks);



#endif