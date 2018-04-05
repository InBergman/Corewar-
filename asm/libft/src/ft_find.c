/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:54 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:54 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_find_lengthmod(t_lpr *stc, char *ptr, int p)
{
	int				i;
	int				a;
	const char		*lengthmod_tab[6] = {"hh", "h", "l", "ll", "j", "z"};
	char			*length;

	ptr = ptr + p;
	i = 0;
	while (ft_needle(ptr[i], "sSpdDioOuUxXcC") == 0)
		i++;
	length = ft_strnew(sizeof(char) * i + 1);
	i = -1;
	while (ft_needle(ptr[++i], "sSpdDioOuUxXcC") == 0)
		length[i] = ptr[i];
	length[i] = '\0';
	a = 0;
	i = -1;
	while (lengthmod_tab[++i] && i < 6)
		if (!ft_strcmp(lengthmod_tab[i], length))
		{
			stc->lmod = ft_strdup(lengthmod_tab[i]);
			a = ft_strlen(stc->lmod);
			break ;
		}
	free(length);
	return (a);
}

static int		how_much_digit(char *ptr)
{
	int		i;
	int		b;

	i = 0;
	b = 0;
	while (ft_isdigit(ptr[++i]))
		b++;
	return (b);
}

static int		ft_fp2(int i, int a, char *ptr)
{
	char	*num;

	num = ft_strnew((sizeof(char) * i) + 1);
	a = -1;
	while (++a < i && ft_isdigit(ptr[a]))
		num[a] = ptr[a];
	num[a] = '\0';
	a = ft_atoi(num);
	free(num);
	return (a);
}

int				ft_find_precision(t_lpr *stc, char *ptr, int p)
{
	int		a;
	int		b;

	ptr = ptr + p;
	b = 0;
	a = 0;
	if (ptr[0] == '.')
	{
		stc->precision_sign = 1;
		b = how_much_digit(ptr);
		ptr++;
		if (b > 0)
		{
			a = ft_fp2(b, a, ptr);
			if (a > 0)
				stc->precision_sign = 0;
			b++;
		}
		b = b == 0 ? 1 : b;
	}
	stc->precision = a;
	return (b);
}

int				ft_find_field(t_lpr *stc, char *ptr, int p)
{
	int		i;
	int		a;
	int		b;

	i = 0;
	b = 0;
	a = 0;
	ptr = ptr + p;
	while (ft_isdigit(ptr[i]) && ptr[i] != '\0')
	{
		i++;
		b++;
	}
	if (i > 0)
		a = ft_fp2(i, a, ptr);
	stc->field = a;
	return (b);
}
