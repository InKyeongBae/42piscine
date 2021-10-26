/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:59:35 by ibae              #+#    #+#             */
/*   Updated: 2021/10/24 21:04:33 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include "struct.h"

int	count_line(char *str)
{
	int	nu;
	int	i;

	i = 0;
	nu = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			nu += 1;
		i += 1;
	}
	return (nu);
}

t_dict_element	*array_dict(char *dict, t_dict_element *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count_line(dict))
	{
		parse_line(p[i].value, (dict + j), 0);
		parse_line(p[i].str, (dict + j), 1);
		while (dict[j] != '\n')
			j += 1;
		j += 1;
		i += 1;
	}
	return (p);
}
