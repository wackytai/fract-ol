/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:38:25 by tlemos-m          #+#    #+#             */
/*   Updated: 2022/11/10 11:09:07 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new;

	new = 0;
	while (lst != NULL)
	{
		tmp = ft_lstnew((f)(lst->content));
		if (!tmp)
			ft_lstclear(&tmp, del);
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
