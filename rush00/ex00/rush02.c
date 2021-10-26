/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:06:41 by ibae              #+#    #+#             */
/*   Updated: 2021/10/10 18:23:00 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_row_print(int len, char start_char, char mid_char, char end_char)
{
	int	count;

	count = 1;
	while (count <= len)
	{
		if (count == 1)
			ft_putchar(start_char);
		else if (count == len)
			ft_putchar(end_char);
		else
			ft_putchar(mid_char);
		count++;
	}
	ft_putchar('\n');
}

void	rush(int row, int col)
{
	int	line;

	line = 1;
	if (row >= 1 && col >= 1)
	{
		while (line <= col)
		{
			if (line == 1)
				ft_row_print(row, 'A', 'B', 'A');
			else if (line == col)
				ft_row_print(row, 'C', 'B', 'C');
			else
				ft_row_print(row, 'B', ' ', 'B');
			line++;
		}
	}
	else
		write(1, "Set positive integers as parameters\n", 36);
}
