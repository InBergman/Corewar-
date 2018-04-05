/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:51 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:51 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** apply 'del' fonction to each 'alst' node and free the memory which is
** occupied by the node
*/

void				ft_lstdel(t_list_head *head, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp_next;

	tmp = head->first;
	while (tmp)
	{
		tmp_next = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = tmp_next;
	}
	ft_bzero(head, sizeof(t_list_head));
}
