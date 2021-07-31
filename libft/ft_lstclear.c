/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:25:13 by melaena           #+#    #+#             */
/*   Updated: 2020/11/02 17:39:59 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*temp;

	if (!lst)
		return ;
	if (!*lst)
		return ;
	elem = *lst;
	while (elem)
	{
		del(elem->content);
		temp = elem;
		elem = elem->next;
		free(temp);
	}
	*lst = 0;
	return ;
}
