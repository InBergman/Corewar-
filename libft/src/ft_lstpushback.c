/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 14:10:34 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:57:33 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstpushback(t_list_head *head, t_list *link)
{
	if (!head || !link)
		return (1);
	if (head->last)
	{
		link->prev = head->last;
		head->last->next = link;
	}
	else
		head->first = link;
	head->last = link;
	++head->len;
	return (0);
}
