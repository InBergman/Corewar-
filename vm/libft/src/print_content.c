/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 11:54:33 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:55:16 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** print the content of a list through a pointer of function
** that is not general
*/

void		print_content(t_list_head *head, void (*ptr)(void *))
{
	t_list		*tmp;

	tmp = head->first;
	while (tmp)
	{
		(*ptr)(tmp->content);
		tmp = tmp->next;
	}
}
