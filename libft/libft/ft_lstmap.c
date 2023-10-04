/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:46:24 by bsafi             #+#    #+#             */
/*   Updated: 2023/04/07 15:42:32 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nvlst;
	t_list	*tmp;

	if (!lst)
		return (0);
	nvlst = 0;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&tmp, (*del));
			return (0);
		}
		ft_lstadd_back(&nvlst, tmp);
		lst = lst->next;
	}
	return (nvlst);
}
