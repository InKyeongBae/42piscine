/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:26:38 by ibae              #+#    #+#             */
/*   Updated: 2022/01/16 16:26:40 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_str(const char *haystack, const char *needle, int n)
{
	haystack += n;
	while (*needle)
	{
		if (*haystack != *needle)
			return (0);
		needle++;
		haystack++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (0);
	if (*haystack == '\0')
		return (0);
	while ((haystack[i] != 0) && (i <= (len - ft_strlen(needle))))
	{
		if (find_str(haystack, needle, i) == 1)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
