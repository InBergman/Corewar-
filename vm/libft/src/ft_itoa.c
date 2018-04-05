/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:51 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:51 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** return a char string which is the result of the conversion from a int
** to a char*
*/

static char	*ft_isneg(int isneg, char *str)
{
	if (isneg == 1)
		str[0] = '-';
	return (str);
}

static int	ft_ii(int nb)
{
	int		i;

	i = 0;
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int nb)
{
	int		i;
	char	*str;
	int		isneg;

	if (nb == 0 || nb == -2147483648)
		return ((nb == 0) ? ft_strdup("0") : ft_strdup("-2147483648"));
	i = 0;
	isneg = 0;
	if (nb < 0)
	{
		i++;
		isneg = 1;
		nb = nb * (-1);
	}
	i = ft_ii(nb) + i;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	while (nb)
	{
		str[--i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (ft_isneg(isneg, str));
}
