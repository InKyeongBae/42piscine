/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhpar <chanhpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:15:46 by chanhpar          #+#    #+#             */
/*   Updated: 2021/10/24 16:18:23 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_digits(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		idx += 1;
	}
	return (idx);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
	int	src_len;

	i = 0;
	src_len = count_digits(src);
	while (i < src_len)
	{
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = '\0';
	return (dest);
}
