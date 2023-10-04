/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:54:47 by bsafi             #+#    #+#             */
/*   Updated: 2023/04/07 15:30:35 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*dest;

	dest = malloc(sizeof(t_list));
	if (!dest)
		return (0);
	dest->content = content;
	dest->next = 0;
	return (dest);
}
