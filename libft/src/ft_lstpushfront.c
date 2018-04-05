/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 19:35:04 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:57:45 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstpushfront(t_list_head *head, t_list *link)
{
	if (!head || !link)
		return (1);
	if (head->first)
	{
		head->first->prev = link;
		link->next = head->first;
		link->prev = NULL;
	}
	else
		head->last = link;
	head->first = link;
	++head->len;
	return (0);
}
