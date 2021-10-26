/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:20:34 by ibae              #+#    #+#             */
/*   Updated: 2021/10/21 00:17:19 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	i;

	if (nb < 0)
		return (0);
	if (nb < 2)
		return (nb);
	i = 0;
	while ((i * i) <= (unsigned int)nb)
		i++;
	i -= 1;
	return (i);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	sqrt;

	if (nb <= 1)
		return (0);
	else if (nb <= 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 2;
	sqrt = ft_sqrt(nb);
	while ((i <= sqrt) && (nb % i != 0))
		i++;
	return (i > sqrt);
}
