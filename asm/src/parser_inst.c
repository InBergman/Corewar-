/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_inst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:26:16 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:26:18 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_inst		*add_inst(t_parser *p)
{
	static unsigned int	i = 1;
	t_inst				*tmp;
	t_inst				*prev;

	tmp = p->l_inst;
	if (!tmp)
	{
		p->l_inst = ft_memalloc(sizeof(t_inst));
		tmp = p->l_inst;
	}
	else
	{
		while (tmp)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = ft_memalloc(sizeof(t_inst));
		tmp = prev->next;
		tmp->prev = prev;
	}
	tmp->index = i++;
	return (tmp);
}

static void			search_op(t_parser *p, char *s)
{
	char	*tmp;
	int		i;
	t_inst	*inst;

	i = -1;
	ft_trim_leading_space(&s);
	tmp = strsep(&s, " \t");
	while (++i < 16)
	{
		if (!ft_strcmp(tmp, g_op[i].op))
		{
			inst = add_inst(p);
			inst->opcode = g_op[i].opcode;
			inst->nbr_param = g_op[i].nb_param;
			while (p->l_top && !p->l_top->inst)
			{
				p->l_top->inst = inst;
				p->l_top = p->l_top->prev;
			}
			p->nbr_inst = inst->index;
			parser_param(p, inst, s);
			return ;
		}
	}
	parser_error(p, "This instruction doesn't exist :", tmp);
}

static void			add_label(t_parser *p, char *label)
{
	t_label	*tmp;
	t_label	*prev;

	tmp = p->l_lab;
	prev = tmp;
	while (tmp)
	{
		prev = tmp;
		if (!ft_strcmp(tmp->label, label))
			return ;
		tmp = tmp->next;
	}
	prev->next = ft_memalloc(sizeof(t_label));
	tmp = prev->next;
	tmp->prev = prev;
	tmp->label = ft_strdup(label);
	p->l_top = tmp;
}

static int			search_label(t_parser *p, char *s)
{
	char *label;

	if ((label = ft_strsep(&s, ":")) == NULL || !s)
		return (0);
	else if (ft_search_each_char(label, LABEL_CHARS))
	{
		if (!p->l_lab)
		{
			p->l_lab = ft_memalloc(sizeof(t_label));
			p->l_lab->label = ft_strdup(label);
			p->l_top = p->l_lab;
		}
		else
			add_label(p, label);
		if (*s != '\0')
			search_op(p, s);
		return (1);
	}
	label[ft_strlen(label)] = ':';
	return (0);
}

void				parser_inst(t_parser *p)
{
	char	*s;

	s = p->line;
	remove_comment(&s);
	ft_trim_leading_space(&s);
	ft_trim_ending_space(&s);
	if (*s == '\0')
		return ;
	if (!search_label(p, s))
		search_op(p, s);
}
