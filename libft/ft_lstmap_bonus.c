/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:37:55 by alshakhp          #+#    #+#             */
/*   Updated: 2024/10/04 10:37:57 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current;
	t_list	*new_lst_cur;

	new_list = NULL;
	if (!lst || !f)
		return (NULL);
	current = lst;
	while (current)
	{
		new_lst_cur = ft_lstnew(f(current->content));
		if (!new_lst_cur)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_lst_cur);
		current = current->next;
	}
	return (new_list);
}
