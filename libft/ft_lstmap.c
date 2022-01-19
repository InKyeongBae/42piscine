/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibae <ibae@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:02:51 by ibae              #+#    #+#             */
/*   Updated: 2022/01/19 11:02:53 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*sub;
	t_list	*temp;

	if (!lst || !f)
		return (0);
	result = ft_lstnew(f(lst->content));
	if (result == NULL)
		return (0);
	sub = result;
	lst = lst->next;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (temp == NULL)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		sub->next = temp;
		sub = temp;
		lst = lst->next;
	}
	return (result);
}
