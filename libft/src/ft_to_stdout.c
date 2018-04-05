/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_stdout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:54 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:54 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_to_stdout(char *ptr, char *to_stdout)
{
	int		i;

	i = -1;
	if (ptr[0] < 'a')
		to_stdout = ft_strtoupper(to_stdout);
	while (to_stdout[++i])
		ft_putchar(to_stdout[i]);
	return (i);
}
