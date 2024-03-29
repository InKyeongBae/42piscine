/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:37:33 by ibae              #+#    #+#             */
/*   Updated: 2021/10/24 13:47:07 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	if (dest == NULL)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int argc, char **argv)
{
	int					i;
	struct s_stock_str	*arr;

	arr = malloc((argc + 1) * sizeof(struct s_stock_str));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		arr[i].size = ft_strlen(argv[i]);
		arr[i].str = argv[i];
		arr[i].copy = ft_strdup(argv[i]);
		i++;
	}
	arr[i].str = 0;
	arr[i].copy = 0;
	return (arr);
}
