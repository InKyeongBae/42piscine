/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:39:02 by ibae              #+#    #+#             */
/*   Updated: 2021/10/24 21:03:20 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>

# include "struct.h"

# include <fcntl.h>

# include <stdlib.h>

int				count_line(char *str);
t_dict			ft_set_input_dict(char *file, t_dict dict);
t_dict			ft_set_default_dict(t_dict dict);
t_dict_element	*array_dict(char *dict, t_dict_element *p);

char			*parse_line(char *dest, char *src, int r);

char			*read_dict(char *dictname);

char			*ft_strcpy(char *dest, char *src);

#endif
