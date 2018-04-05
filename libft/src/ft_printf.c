/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:54:52 by msireau           #+#    #+#             */
/*   Updated: 2016/06/08 13:54:52 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*special_case(t_lpr *stc, char *ptr)
{
	if (stc->field > 0 && !ft_needle('-', stc->flag))
	{
		if (ft_needle('0', stc->flag))
			ft_putichar(--stc->field, '0');
		else
			ft_putichar(--stc->field, ' ');
		stc->printed = stc->field;
	}
	else if (stc->field-- > 0 && ft_needle('-', stc->flag))
	{
		ft_putchar(ptr[0]);
		stc->printed++;
		minus(stc);
		return (++ptr);
	}
	return (ptr);
}

static char		*ft_find_form(const char *format, va_list ap, t_lpr *stc)
{
	char		*ptr;
	int			ret;

	ret = 0;
	ptr = (char *)format;
	ret = ft_find_flag(stc, ptr);
	ret += ft_find_field(stc, ptr, ret);
	ret += ft_find_precision(stc, ptr, ret);
	ret += ft_find_lengthmod(stc, ptr, ret);
	ptr += ret;
	if (ft_needle(ptr[0], "dDioOuUxX"))
		ft_conv_digit(ptr, stc, ap);
	else if (ft_needle(ptr[0], "sS"))
		ft_conv_alpha(ptr, stc, ap);
	else if (ft_needle(ptr[0], "pcC"))
		ft_conv_alpha_pcc(ptr, stc, ap);
	else if (ft_needle(ptr[0], "%"))
		ft_no_conv(ptr, stc);
	else
		return (special_case(stc, ptr));
	return (ptr += 1);
}

static int		ft_after(const char *format, int printed)
{
	ft_putchar(format[0]);
	printed++;
	return (printed);
}

static int		print(const char *format, va_list ap)
{
	int			printed;
	t_lpr		*stc;

	printed = 0;
	while (format[0])
	{
		if (format[0] == '%')
		{
			format++;
			if (format[0] == '\0')
				return (printed);
			stc = NULL;
			stc = ft_memalloc(sizeof(t_lpr));
			ft_bzero(stc, sizeof(t_lpr*));
			format = ft_find_form(format, ap, stc);
			printed += stc->printed;
			ft_free_list(stc);
			free(stc);
		}
		if (format[0] && format[0] != '%')
			printed = ft_after(format++, printed);
	}
	return (printed);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = print(format, ap);
	va_end(ap);
	return (ret);
}
