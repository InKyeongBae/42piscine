/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 00:35:48 by ibae              #+#    #+#             */
/*   Updated: 2021/10/23 23:50:44 by ibae             ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_join_arr(int size, char **strs, char *sep, char *result)
{
	int	i;

	i = 0;
	result[0] = '\0';
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i != size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*result;
	int		res_size;

	if (size == 0)
	{
		result = (char *)malloc(sizeof(char) * 1);
		if (result == NULL)
			return (0);
		result[0] = '\0';
		return (result);
	}
	i = 0;
	res_size = ft_strlen(sep) * (size - 1);
	while (i < size)
	{
		res_size += ft_strlen(strs[i]);
		i++;
	}
	result = (char *)malloc(sizeof(char) * (res_size + 1));
	if (result == NULL)
		return (0);
	result = ft_join_arr(size, strs, sep, result);
	return (result);
}
