/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:06:23 by ibae              #+#    #+#             */
/*   Updated: 2022/01/18 18:06:28 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			count;
	unsigned int	res;

	count = 0;
	res = 0;
	while ((count < n) && !res && (s1[count] != 0) && (s2[count] != 0))
	{
		res = (unsigned char)s1[count] - (unsigned char)s2[count];
		count++;
	}
	if (count < n && !res && (s1[count] == 0 || s2[count] == 0))
		res = (unsigned char)s1[count] - (unsigned char)s2[count];
	return (res);
}
