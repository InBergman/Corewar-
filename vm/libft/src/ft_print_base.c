/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:50 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:50 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_base(t_lpr *stc, int base)
{
	char		*tmp;

	tmp = ft_itoa_base(stc->of_int, base);
	ft_putstr(tmp);
	stc->printed += ft_strlen(tmp);
	free(tmp);
}

void	ft_print_base_max(t_lpr *stc, int base)
{
	char		*tmp;

	tmp = ft_itoa_base_ulongmax(stc->of_int, base);
	ft_putstr(tmp);
	stc->printed += ft_strlen(tmp);
	free(tmp);
}
