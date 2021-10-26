/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhpar <chanhpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:31:00 by chanhpar          #+#    #+#             */
/*   Updated: 2021/10/23 16:00:42 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*parse_line1(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != ' ' && src[i] != ':')
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}

char	*parse_line2(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (src[i] != ' ' && src[i] != ':')
		i += 1;
	while (src[i] == ':' || src[i] == ' ')
		i += 1;
	j = 0;
	while (src[i + j] != '\n')
	{
		dest[j] = src[i + j];
		j += 1;
	}
	dest[j] = '\0';
	return (dest);
}

char	*parse_line(char *dest, char *src, int r)
{
	if (r == 0)
		return (parse_line1(dest, src));
	else
		return (parse_line2(dest, src));
}
