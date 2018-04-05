/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpopfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:53 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:53 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstpopfront(t_list_head *head)
{
	t_list	*temp;
	void	*content;

	if (!head->first)
		return (NULL);
	temp = head->first;
	head->first = temp->next;
	if (head->first)
		head->first->prev = NULL;
	if (head->last == temp)
		head->last = NULL;
	content = temp->content;
	free(temp);
	--head->len;
	return (content);
}
