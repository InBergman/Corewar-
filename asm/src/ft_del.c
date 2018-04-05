/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:25:47 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:25:51 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	free_l_inst(t_inst **inst)
{
	size_t	i;

	i = 0;
	if ((*inst)->next)
		free_l_inst(&(*inst)->next);
	while (i < (*inst)->nbr_param)
	{
		if ((*inst)->param[i].label)
			ft_strdel(&(*inst)->param[i].label);
		i++;
	}
	free(*inst);
	*inst = NULL;
}

static void	free_l_label(t_label **label)
{
	if ((*label)->next)
		free_l_label(&(*label)->next);
	if ((*label)->label)
		ft_strdel(&(*label)->label);
	free(*label);
	*label = NULL;
}

void		ft_del(t_parser *p)
{
	if (p->file)
		ft_strdel(&p->file);
	if (p->output)
		ft_strdel(&p->output);
	if (p->line)
		ft_strdel(&p->line);
	if (p->l_inst)
		free_l_inst(&p->l_inst);
	if (p->l_lab)
		free_l_label(&p->l_lab);
}
