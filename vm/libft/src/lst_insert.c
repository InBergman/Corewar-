/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:52 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:52 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstinsert(t_list_head *head, t_list *to_insert,
	int (*insert_here)(void *, void *))
{
	t_list		*tmp;

	tmp = NULL;
	if (!to_insert || !head)
		return (1);
	if (!head->first || insert_here(head->first->content, to_insert->content))
		return (ft_lstpushfront(head, to_insert));
	tmp = head->first;
	while (tmp->next && !insert_here(tmp->next->content, to_insert->content))
		tmp = tmp->next;
	if (!tmp->next)
		head->last = to_insert;
	to_insert->next = tmp->next;
	tmp->next = to_insert;
	++head->len;
	return (0);
}
