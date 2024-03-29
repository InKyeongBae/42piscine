/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 10:19:33 by ibae              #+#    #+#             */
/*   Updated: 2022/05/28 10:19:35 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_print	*start(void)
{
	t_print	*arg_count;

	arg_count = (t_print *)malloc(sizeof(t_print));
	if (arg_count == NULL)
		return (NULL);
	arg_count->counter = 0;
	return (arg_count);
}

void	printcheck(const char character, t_print *arg_count)
{
	if (character == 'c')
		ischaracter(arg_count);
	else if (character == 's')
		isstring(arg_count);
	else if (character == 'p')
		ispointer(arg_count);
	else if (character == 'i' || character == 'd')
		isint(arg_count);
	else if (character == 'u')
		isunsignedint(arg_count);
	else if (character == 'x' || character == 'X')
		ishex(arg_count, character);
	else if (character == '%')
	{
		ft_putchar_fd('%', 1);
		arg_count->counter++;
	}
	else if (character != '\0')
	{
		write(1, &character, 1);
		arg_count->counter++;
	}
}

int	ft_printf(const char *string, ...)
{
	t_print	*arg_count;
	int		printcomplete;
	int		i;

	i = 0;
	arg_count = start();
	printcomplete = 0;
	va_start(arg_count->args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
			printcheck(string[++i], arg_count);
		else
		{
			ft_putchar_fd(string[i], 1);
			arg_count->counter++;
		}
		if (string[i] != '\0')
			i++;
	}
	printcomplete = arg_count->counter;
	va_end(arg_count->args);
	free(arg_count);
	return (printcomplete);
}
