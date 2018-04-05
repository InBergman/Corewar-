/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:49 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:49 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_lstdelone_sub(t_list_head *head, t_list *save, t_list *temp,
			void (*del)(void *))
{
	if (save)
	{
		if (save == head->last)
			head->last = temp;
		del(save->content);
		free(save);
		--head->len;
	}
}

void		ft_lstdelone(t_list_head *head, int (*search)(void *, void *),
			void *match, void (*del)(void *))
{
	t_list	*save;
	t_list	*temp;

	save = NULL;
	temp = NULL;
	if (!head->first)
		return ;
	if (search(head->first->content, match))
	{
		save = head->first;
		head->first = save->next;
	}
	else
	{
		temp = head->first;
		while (temp->next && !search(temp->next->content, match))
			temp = temp->next;
		if (temp->next)
		{
			save = temp->next;
			temp->next = save->next;
		}
	}
	ft_lstdelone_sub(head, save, temp, del);
	return ;
}
