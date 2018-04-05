/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:53 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:53 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lpr		*ft_reset_lpr(t_lpr *stc)
{
	if (stc)
		free(stc);
	stc = ft_memalloc(sizeof(t_lpr*));
	stc->min = 0;
	stc->plus = 0;
	stc->space = 0;
	stc->zero = 0;
	stc->precision = 0;
	stc->field = 0;
	return (stc);
}
