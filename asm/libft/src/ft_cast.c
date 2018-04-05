/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:53 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:53 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_cast_u(t_lpr *suitcase)
{
	if (suitcase->of_int <= 65535)
		suitcase->of_int = (unsigned int)suitcase->of_int;
	else if (suitcase->of_int <= 4294967295)
		suitcase->of_int = (unsigned long)suitcase->of_int;
	else if (suitcase->of_int > 4294967295)
		suitcase->of_int = (unsigned long long)suitcase->of_int;
}
