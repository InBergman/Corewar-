/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:51 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:51 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Create a new node and apply to it the 'content' and 'content_size'
** parameter, and set his next parameter to NULL
*/

t_list	*ft_lstnew(void *content, size_t content_size)
{
	t_list	*temp;

	if ((temp = (t_list*)malloc(sizeof(t_list))))
	{
		if (content != NULL)
		{
			if (content_size)
			{
				if (!(temp->content = malloc(content_size)))
				{
					free(temp);
					return (NULL);
				}
				ft_memcpy(temp->content, content, content_size);
			}
			else
				temp->content = content;
		}
		else
			temp->content = NULL;
		temp->next = NULL;
		temp->prev = NULL;
	}
	return (temp);
}
