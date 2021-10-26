/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:07:39 by ibae              #+#    #+#             */
/*   Updated: 2021/10/18 15:35:52 by ibae             ###   ########.fr       */
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
	if (i * i == (unsigned int)nb)
		return (i);
	else
		return (0);
}
