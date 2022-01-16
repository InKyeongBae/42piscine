/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:51:47 by ibae              #+#    #+#             */
/*   Updated: 2022/01/16 15:51:51 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	src_len = 0;
	while (*dst != '\0')
	{
		dst++;
		dst_len += 1;
	}
	while (*src != '\0' && (dst_len + src_len + 1 < dstsize))
	{
		*(dst++) = *(src++);
		src_len += 1;
	}
	while (*(src++) != '\0')
		src_len++;
	*dst = '\0';
	if (dstsize < dst_len)
		return (src_len + dstsize);
	else
		return (src_len + dst_len);
}
