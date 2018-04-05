/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:51 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:51 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define ABS(v) ((v) < 0 ? -(v) : (v))

static void		aux_dix_int(long n, char *ans, int *p)
{
	if (n < -9 || 9 < n)
		aux_dix_int(n / 10, ans, p);
	ans[(*p)++] = '0' + ABS(n % 10);
}

static void		aux_dix(long long n, char *ans, int *p)
{
	if (n < -9 || 9 < n)
		aux_dix(n / 10, ans, p);
	ans[(*p)++] = '0' + ABS(n % 10);
}

static void		aux(unsigned long long n, unsigned int b, char *ans, int *p)
{
	const char	*base = "0123456789abcdef";

	if (n >= b)
		aux(n / b, b, ans, p);
	ans[(*p)++] = base[n % b];
}

static void		aux_int(unsigned int n, unsigned int b, char *ans, int *p)
{
	const char	*base = "0123456789abcdef";

	if (n >= b)
		aux_int(n / b, b, ans, p);
	ans[(*p)++] = base[n % b];
}

char			*ft_itoa_base(long long value, int base)
{
	char	*ans;
	int		p;

	if (value < 4294967296 && value > -4294967296)
		value = (long)value;
	if (base < 2 || 16 < base || !(ans = (char *)malloc(sizeof(char) * 35)))
		return (NULL);
	p = 0;
	if (base == 10 && value < 0)
		ans[p++] = '-';
	if (base == 10 && value < 4294967296)
		aux_dix_int(value, ans, &p);
	else if (base == 10 && value > 4294967296)
		aux_dix((long long)value, ans, &p);
	else if (value < 4294967296 && value > -4294967296)
		aux_int((unsigned int)value, (unsigned int)base, ans, &p);
	else
		aux((unsigned long long)value, (unsigned int)base, ans, &p);
	ans[p] = '\0';
	return (ans);
}
