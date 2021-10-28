/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:24:13 by ibae              #+#    #+#             */
/*   Updated: 2021/10/27 22:49:48 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	up;
	int	down;

	i = 0;
	up = 0;
	down = 0;
	length -= 1;
	while (i < length)
	{
		if (f(tab[i], tab[i + 1]) <= 0)
			up++;
		if (f(tab[i], tab[i + 1]) >= 0)
			down++;
		i++;
	}
	if (up == i || down == i)
		return (1);
	return (0);
}
