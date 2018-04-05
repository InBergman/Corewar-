/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfreematch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdurand <rdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:11:06 by rdurand           #+#    #+#             */
/*   Updated: 2016/11/03 16:32:24 by rdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*lstremove(t_list_head *head, t_list *to_remove)
{
	if (!(head && to_remove))
		return (NULL);
	if (to_remove == head->first)
		head->first = to_remove->next;
	if (to_remove == head->last)
		head->last = to_remove->prev;
	if (to_remove->prev)
		to_remove->prev->next = to_remove->next;
	if (to_remove->next)
		to_remove->next->prev = to_remove->prev;
	to_remove->next = NULL;
	to_remove->prev = NULL;
	head->len--;
	return (to_remove);
}

static void		lstdelelem(t_list **elem, void (*del)(void*))
{
	if (elem && *elem)
	{
		del((*elem)->content);
		(*elem)->content = NULL;
		free(*elem);
		*elem = NULL;
	}
}

void			ft_lstfreematch(t_list_head *head, void *match, \
		int (*cmp)(void*, void*), void (*del)(void*))
{
	t_list	*cursor;
	t_list	*save;
	t_list	*to_remove;

	to_remove = NULL;
	if (!head)
		return ;
	cursor = head->first;
	while (cursor)
	{
		save = cursor;
		cursor = cursor->next;
		if (cmp(save->content, match))
		{
			to_remove = lstremove(head, save);
			lstdelelem(&to_remove, del);
		}
	}
}
