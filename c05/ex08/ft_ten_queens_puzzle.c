/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:23:30 by ibae              #+#    #+#             */
/*   Updated: 2021/10/19 19:40:40 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_count;
int	g_row[10];

void	ft_write_answer(int	*arr)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = '0' + arr[i++];
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

int	ft_is_possible(int col)
{
	int	i;
	int	abs;

	i = 0;
	while (i < col)
	{
		if (g_row[i] - g_row[col] < 0)
			abs = g_row[col] - g_row[i];
		else
			abs = g_row[i] - g_row[col];
		if (abs == 0 || abs == col - i)
			return (0);
		i++;
	}
	return (1);
}

void	dfs(int col)
{
	int	i;

	if (col == 10)
	{
		g_count += 1;
		ft_write_answer(g_row);
		return ;
	}
	i = 0;
	while (i < 10)
	{
		g_row[col] = i;
		if (ft_is_possible(col))
			dfs(col + 1);
		i++;
	}
	return ;
}

int	ft_ten_queens_puzzle(void)
{
	dfs(0);
	return (g_count);
}
