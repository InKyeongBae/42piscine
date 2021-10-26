/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:57:19 by jaewchoi          #+#    #+#             */
/*   Updated: 2021/10/10 17:29:55 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_setchar(int col, int row, int j, int i)
{
	if ((i == 1 && j == 1) || (i == 1 && j == col))
		ft_putchar('o');
	else if ((i == row && j == 1) || (j == col && i == row))
		ft_putchar('o');
	else if (i == 1 || i == row)
		ft_putchar('-');
	else if (j == 1 || j == col)
		ft_putchar('|');
	else
		ft_putchar(' ');
	if (j == col)
		ft_putchar('\n');
}

void	rush(int col, int row)
{
	int		i;
	int		j;
	char	*err;

	if (col <= 0 || row <= 0)
	{
		err = "Set positive integers as parameters";
		while (*err != '\0')
		{
			ft_putchar(*err);
			err++;
		}
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
