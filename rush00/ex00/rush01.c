/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwanlee <hwanlee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:56:06 by hwanlee           #+#    #+#             */
/*   Updated: 2021/10/10 18:09:55 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
char	g_error_msg[36] = "Set positive integers as parameter";

void	ft_putchar(char c);

void	ft_setchar(int col, int row, int j, int i)
{
	if (i == 1 && j == 1)
		ft_putchar('/');
	else if (i == 1 && j == col)
		ft_putchar('\\');
	else if (i == row && j == 1)
		ft_putchar('\\');
	else if (i == row && j == col)
		ft_putchar('/');
	else if (i == 1 || i == row)
		ft_putchar('*');
	else if (j == 1 || j == col)
		ft_putchar('*');
	else
		ft_putchar(' ');
	if (j == col)
		ft_putchar('\n');
}
// need to type '\\' because a single backslash denotes the escape character

void	rush(int col, int row)
{
	int	i;
	int	j;

	if (col <= 0 || row <= 0)
	{
		write(1, g_error_msg, 36);
		ft_putchar('\n');
	}
	i = 1;
	while (i <= row)
	{
		j = 1;
		while (j <= col)
		{
			ft_setchar(col, row, j, i);
			j++;
		}
		i++;
	}
}
