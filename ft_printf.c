/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolf <ewolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 15:21:35 by ewolf             #+#    #+#             */
/*   Updated: 2026/10/30 15:22:18 by ewolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_p_b_u(unsigned long nb, char *base)
{
	unsigned long	i;
	int				ret;
	int				base_len;

	i = 0;
	ret = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nb / base_len != 0 && ret++ >= 0)
		ret += ft_p_b_u(nb / base_len, base);
	else
		ret++;
	while (nb % base_len != i)
		i++;
	write(1, &base[i], 1);
	return (ret);
}

int	ft_put_nbr(int nb, char *base)
{
	int	i;
	int	ret;
	int	base_len;

	i = 0;
	ret = 0;
	base_len = 10;
	if (nb < 0)
	{
		if (nb == -2147483648)
			return (write(1, "-2147483648", 11));
		nb *= -1;
		write(1, "-", 1);
		ret++;
	}
	if (nb / base_len != 0 && ret++ >= 0)
		ret += ft_put_nbr(nb / base_len, base);
	else
		ret++;
	while (nb % base_len != i)
		i++;
	write(1, &base[i], 1);
	return (ret);
}

int	ft_put_str_pointer(void *val, char c)
{
	int		i;
	char	*str;

	i = 0;
	if (c == 'p')
	{
		if (!val)
			return (write(1, "(nil)", 5));
		write (1, "0x", 2);
		return (2 + ft_p_b_u((unsigned long)val, "0123456789abcdef"));
	}
	if (!val)
		return (write(1, "(null)", 6));
	str = val;
	while ((char)str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_print_arg(char c, va_list args)
{
	char	ch;

	if (c == 'c')
	{
		ch = (char) va_arg(args, int);
		write(1, &ch, 1);
		return (1);
	}
	if (c == 's' || c == 'p')
		return (ft_put_str_pointer(va_arg(args, void *), c));
	if (c == 'd' || c == 'i')
		return (ft_put_nbr(va_arg(args, int), "0123456789"));
	if (c == 'u')
		return (ft_p_b_u(va_arg(args, unsigned int), "0123456789"));
	if (c == 'x')
		return (ft_p_b_u(va_arg(args, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_p_b_u(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	int		ret;
	va_list	args;

	i = 0;
	ret = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			if (input[i] == '\0')
				break ;
			ret += ft_print_arg(input[i], args);
		}
		else
		{
			write(1, &input[i], 1);
			ret++;
		}
		i++;
	}
	va_end(args);
	return (ret);
}