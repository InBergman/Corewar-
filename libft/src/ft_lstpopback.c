/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpopback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:48 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:48 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstpopback(t_list_head *head)
{
	t_list	*temp;
	void	*content;

	if (!head->last)
		return (NULL);
	temp = head->last;
	head->last = temp->prev;
	if (head->last)
		head->last->next = NULL;
	if (head->first == temp)
		head->first = NULL;
	content = temp->content;
	free(temp);
	--head->len;
	return (content);
}
