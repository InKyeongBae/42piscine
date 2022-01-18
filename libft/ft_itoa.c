/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:08:54 by ibae              #+#    #+#             */
/*   Updated: 2022/01/18 17:08:57 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	isneg(int *n, int *sign, int *tmp)
{
	if (*n == -2147483648)
	{
		*n = *n + 1;
		*sign = -1;
		*tmp = 1;
		*n = *n * -1;
	}
	else if (*n < 0)
	{
		*sign = -1;
		*n = *n * -1;
		*tmp = 0;
	}
	else if (*n >= 0)
	{
		*sign = 1;
		*tmp = 0;
	}
}

int	itoa_len(int n)
{
	int	len;

	len = 0;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

void	itoa_write(char *str, int len, int n, int tmp)
{
	while (n > 9)
	{
		str[len--] = (n % 10) + '0' + tmp;
		n = n / 10;
		tmp = 0;
	}
	str[len] = n + '0';
}

char	*ft_itoa(int n)
{
	int		sign;
	int		tmp;
	int		len;
	char	*str;

	isneg(&n, &sign, &tmp);
	len = itoa_len(n);
	if (sign == -1)
	{
		str = malloc(sizeof(char) * (len + 2));
		if (str == NULL)
			return (0);
		len++;
		str[0] = '-';
	}
	else
	{
		str = malloc(sizeof(char) * (len + 1));
		if (str == NULL)
			return (0);
	}
	str[len--] = '\0';
	itoa_write(str, len, n, tmp);
	return (str);
}
