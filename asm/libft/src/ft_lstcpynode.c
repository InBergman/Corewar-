/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpynode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 20:19:30 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:56:53 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstcpynode(void *to_lstcontent)
{
	t_list	*cpy;

	cpy = ft_memalloc(sizeof(t_list));
	cpy->content = to_lstcontent;
	return (cpy);
}
