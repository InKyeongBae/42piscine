/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:10:43 by ibae              #+#    #+#             */
/*   Updated: 2021/10/24 11:47:29 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	lenght_nbr(int nbr, char *base, int len)
{
	int	base_len;
	int	nb;

	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		nb = nbr * -1;
		len++;
	}
	else
		nb = nbr;
	while (nb >= base_len)
	{
		nb /= base_len;
		len++;
	}
	len++;
	return (len);
}

void	ft_putnbr_base_v2(int nbr, char *base, char *result)
{
	int		len_base;
	long	nb;
	int		i;
	int		len_result;

	len_base = ft_strlen(base);
	len_result = lenght_nbr(nbr, base, 0);
	nb = nbr;
	i = 0;
	if (nb < 0)
	{
		result[0] = '-';
		nb *= -1;
		i = 1;
	}
	len_result--;
	while (nb >= len_base)
	{
		result[len_result] = base[nb % len_base];
		nb /= len_base;
		len_result--;
	}
	if (nb < len_base)
		result[i] = base[nb];
}
