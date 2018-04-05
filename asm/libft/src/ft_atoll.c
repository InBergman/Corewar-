/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:21:06 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:56:24 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** return the conversion from a number of type char to a number of type llong
*/

static long long	atoll_next(const char *str, int isneg, int i)
{
	long long		a;

	a = 0;
	while (str[i])
	{
		if ((str[i] < '0') || (str[i] > '9'))
			return (a * isneg);
		a = a * 10 + (str[i++] - '0');
	}
	return (a);
}

long long			ft_atoll(const char *str)
{
	int				i;
	long long		a;
	int				isneg;

	i = -1;
	a = 0;
	isneg = 1;
	while (str[++i])
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
			ft_error("ERROR\n");
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			isneg = -1;
		i++;
	}
	a = atoll_next(str, isneg, i) * isneg;
	if (a > 2147483647 || a < -2147483648)
		ft_error("ERROR\n");
	return (a);
}
