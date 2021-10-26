/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:28:38 by ibae              #+#    #+#             */
/*   Updated: 2021/10/17 16:32:31 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_error(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] <= 32 || str[i] == 127 || str[i] == '+' || str[i] == '-')
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
	int	n;

	n = 0;
	while (base[n] != '\0')
	{
		if (str == base[n])
			return (n);
		n++;
	}
	return (-1);
}

int	ft_white_spaces(char *str, int *ptr_i)
{
	int	count;
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	count = 1;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			count *= -1;
		i++;
	}
	*ptr_i = i;
	return (count);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		negative;
	int		num;
	int		num2;
	int		len;

	num = 0;
	i = 0;
	len = ft_check_error(base);
	if (len >= 2)
	{
		negative = ft_white_spaces(str, &i);
		num2 = nb_base(str[i], base);
		while (num2 != -1)
		{
			num = (num * len) + num2;
			i++;
			num2 = nb_base(str[i], base);
		}
		return (num *= negative);
	}
	return (0);
}
