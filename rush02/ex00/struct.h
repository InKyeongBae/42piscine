/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:35:31 by ibae              #+#    #+#             */
/*   Updated: 2021/10/24 17:17:33 by chanhpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_dict_element
{
	char	*value;
	char	*str;
	int		valid;
}	t_dict_element;

typedef struct s_dict
{
	char			*file_path;
	t_dict_element	*element;
	int				size;
	int				valid;
}	t_dict;

#endif
