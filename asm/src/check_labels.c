/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:25:42 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:25:45 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		count_size_op(t_inst *inst)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 1;
	while (i < inst->nbr_param)
	{
		size += inst->param[i].size;
		i++;
	}
	if (inst->opcode != 1 && inst->opcode != 9 &&
			inst->opcode != 12 && inst->opcode != 15)
		size++;
	return (size);
}

size_t	count_size_after(t_inst *inst, unsigned int nbr)
{
	t_inst	*tmp;
	size_t	size;

	tmp = inst;
	size = 0;
	while (tmp && tmp->index < nbr)
	{
		size += count_size_op(tmp);
		tmp = tmp->next;
	}
	return (size);
}

size_t	count_size_before(t_inst *inst, unsigned int nbr)
{
	t_inst	*tmp;
	size_t	size;

	tmp = inst;
	size = 0;
	while (tmp && tmp->index > nbr)
	{
		tmp = tmp->prev;
		size += count_size_op(tmp);
	}
	return (size * (-1));
}

void	position_label(t_parser *p, t_inst *inst, t_value *value)
{
	t_label *label;

	label = p->l_lab;
	while (label)
	{
		if (!ft_strcmp(label->label, value->label))
		{
			if (!label->inst)
				value->value = count_size_after(inst, p->nbr_inst + 1);
			else if (label->inst->index == inst->index)
				value->value = count_size_op(inst);
			else if (label->inst->index < inst->index)
				value->value = count_size_before(inst, label->inst->index);
			else
				value->value = count_size_after(inst, label->inst->index);
			return ;
		}
		label = label->next;
	}
	parser_error(p, "Label not found :", value->label);
}

void	check_label(t_parser *p)
{
	t_inst		*inst;
	size_t		i;

	inst = p->l_inst;
	while (inst)
	{
		i = 0;
		while (i < inst->nbr_param)
		{
			if (inst->param[i].label)
				position_label(p, inst, &inst->param[i]);
			i++;
		}
		inst = inst->next;
	}
}
