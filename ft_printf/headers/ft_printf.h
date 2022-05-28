/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 10:20:36 by ibae              #+#    #+#             */
/*   Updated: 2022/05/28 10:20:37 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_print
{
	va_list	args;
	int		counter;
}	t_print;

void	ischaracter(t_print *arg_count);
void	isstring(t_print *arg_count);
void	ispointer(t_print *arg_count);
void	ishex(t_print *arg_count, char character);
void	isint(t_print *arg_count);
void	isunsignedint(t_print *arg_count);
int		ft_printf(const char *string, ...);

#endif
