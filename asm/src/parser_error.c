/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:26:11 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:26:18 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parser_error(t_parser *p, char *msg, char *tok)
{
	if (p->count_line)
	{
		ft_putstr_fd("line : ", 2);
		ft_putnbr_fd(p->count_line, 2);
		ft_putstr_fd(" | ", 2);
	}
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(" ", 2);
	if (tok)
		ft_putendl_fd(tok, 2);
	else
		ft_putendl_fd("NULL", 2);
	ft_del(p);
	exit(EXIT_FAILURE);
}
