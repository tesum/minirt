/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demilan <demilan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:14:01 by demilan           #+#    #+#             */
/*   Updated: 2021/06/03 02:06:43 by demilan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*elem;

	if (lst == NULL && (f == NULL || *del == NULL))
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	if (new_list == NULL)
		ft_lstdelone(new_list, del);
	lst = lst->next;
	while (lst != NULL)
	{
		elem = ft_lstnew(f(lst->content));
		if (elem == NULL)
			ft_lstclear(&new_list, del);
		ft_lstadd_back(&new_list, elem);
		lst = lst->next;
	}
	return (new_list);
}
