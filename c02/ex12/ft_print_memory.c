/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:20:26 by ibae              #+#    #+#             */
/*   Updated: 2021/10/21 14:22:13 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_set_base16(unsigned char c)
{
	char	*base;

	base = "0123456789abcdef";
	ft_putchar(base[c / 16]);
	ft_putchar(base[c % 16]);
}

void	ft_print_data(char *s, unsigned int size)
{
	unsigned int	i;

	i = -1;
	while (++i < size)
	{
		if (!(i % 2))
			ft_putchar(' ');
		ft_set_base16(s[i]);
	}
	while (i < 16)
	{
		if (i++ % 2 == 1)
			write(1, "  ", 2);
		else
			write(1, "   ", 3);
	}
	ft_putchar(' ');
	i = -1;
	while (++i < size)
	{
		if (s[i] < 32 || s[i] == 127)
			ft_putchar('.');
		else
			ft_putchar(s[i]);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				j;

	i = 0;
	while (i < size)
	{
		j = 56;
		while (j >= 0)
		{
			ft_set_base16((unsigned long int)(addr + i) >> j & 0xff);
			j -= 8;
		}
		ft_putchar(':');
		if ((size - i) < 16)
			ft_print_data(addr + i, size - i);
		else
			ft_print_data(addr + i, 16);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}
