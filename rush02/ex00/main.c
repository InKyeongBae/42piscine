/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:46:39 by ibae              #+#    #+#             */
/*   Updated: 2021/10/24 21:04:05 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include "struct.h"

int	main(int argc, char *argv[])
{
	t_dict			dict;
	char			*nb;
	int				len;
	char			*buff;

	if (argc == 2)
		dict.file_path = "numbers.dict";
	else if (argc == 3)
		dict.file_path = argv[1];
	else
		return (0);
	nb = argv[argc - 1];
	buff = read_dict(dict.file_path);
	len = count_line(buff);
	dict.size = len;
	dict.element = (t_dict_element *)malloc(sizeof(t_dict_element) * (len + 1));
	if (dict.element == NULL)
		return (0);
	array_dict(buff, dict.element);
	free(buff);
	free(dict.element);
	return (0);
}
