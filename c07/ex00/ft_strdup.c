/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 00:35:12 by ibae              #+#    #+#             */
/*   Updated: 2021/10/23 13:22:19 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_strdup(char *src)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (s == NULL)
		return (0);
	while (i < ft_strlen(src))
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
