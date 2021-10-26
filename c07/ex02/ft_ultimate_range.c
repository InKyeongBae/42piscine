/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 00:35:37 by ibae              #+#    #+#             */
/*   Updated: 2021/10/23 13:40:41 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*temp;
	int	i;

	size = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	temp = (int *)malloc(sizeof(int) * size);
	if (temp == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		temp[i] = min + i;
		i++;
	}
	*range = temp;
	return (size);
}
