/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 00:35:59 by ibae              #+#    #+#             */
/*   Updated: 2021/10/24 11:48:00 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
void	ft_putnbr_base_v2(int nbr, char *base, char *result);
int		lenght_nbr(int nbr, char *base, int len);

int	ft_checkerror(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32
			|| str[i] == 43 || str[i] == 45)
			return (0);
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	nb_base(char str, char *base)
{
	int	nb;

	nb = 0;
	while (base[nb] != '\0')
	{
		if (str == base[nb])
			return (nb);
		nb++;
	}
	return (-1);
}

int	ft_whs(char *str, int *p)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while ((str[i] != '\0') && (str[i] == 43 || str[i] == 45))
	{
		if (str[i] == 45)
			count *= -1;
		i++;
	}
	*p = i;
	return (count);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	count;
	int	nb;
	int	nb2;
	int	base_lenght;

	nb = 0;
	i = 0;
	base_lenght = ft_checkerror(base);
	if (base_lenght >= 2)
	{
		count = ft_whs(str, &i);
		nb2 = nb_base(str[i], base);
		while (nb2 != -1)
		{
			nb = (nb * base_lenght) + nb2;
			i++;
			nb2 = nb_base(str[i], base);
		}
		return (nb *= count);
	}
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		convert;
	int		len_result;

	if (ft_checkerror(base_to) == 0 || ft_checkerror(base_from) == 0)
		return (0);
	convert = ft_atoi_base(nbr, base_from);
	len_result = lenght_nbr(convert, base_to, 0);
	result = (char *)malloc(sizeof(char) * (len_result + 1));
	if (result == NULL)
		return (0);
	ft_putnbr_base_v2(convert, base_to, result);
	result[len_result] = '\0';
	return (result);
}
