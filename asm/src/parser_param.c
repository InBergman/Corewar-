/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:27:22 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:27:23 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_reg(t_value *value, char *tok)
{
	int	i;

	i = 0;
	value->type = T_REG;
	tok++;
	if (*tok == '\0')
		return (0);
	while (ft_isdigit(tok[i]))
		i++;
	if (i < 3 && tok[i] == '\0')
		value->value = ft_atoi(tok);
	else
		return (0);
	return (1);
}

static int	check_dir(t_value *value, char *tok)
{
	int	i;

	i = 0;
	value->type = T_DIR;
	tok++;
	if (*tok == ':')
		value->label = ft_strdup(++tok);
	else if (*tok != '\0')
	{
		if (tok[i] == '-')
			i++;
		while (ft_isdigit(tok[i]))
			i++;
		if (tok[i] == '\0')
			value->value = ft_atoi(tok);
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

static int	check_ind(t_value *value, char *tok)
{
	int	i;

	i = 0;
	value->type = T_IND;
	if (*tok == ':')
		value->label = ft_strdup(++tok);
	else if (*tok != '\0')
	{
		if (*tok == '-')
			i++;
		while (ft_isdigit(tok[i]))
			i++;
		if (tok[i] == '\0')
			value->value = ft_atoi(tok);
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

static int	check_arg(t_inst *inst, t_value *value, char *tok, size_t i)
{
	int	error;

	error = 1;
	if (*tok == 'r' && (g_op[inst->opcode - 1].type[i] & T_REG))
		error = check_reg(value, tok);
	else if (*tok == '%' && (g_op[inst->opcode - 1].type[i] & T_DIR))
		error = check_dir(value, tok);
	else if (*tok == ':' && (g_op[inst->opcode - 1].type[i] & T_IND))
		error = check_ind(value, tok);
	else if (g_op[inst->opcode - 1].type[i] & T_IND)
		error = check_ind(value, tok);
	else
		return (0);
	value->size = size_param(inst->opcode, *value);
	if (!error)
		return (0);
	return (1);
}

void		parser_param(t_parser *p, t_inst *inst, char *s)
{
	char	*tok;
	size_t	i;

	i = 0;
	while ((tok = ft_strsep(&s, ",")) != NULL)
	{
		if (i >= inst->nbr_param)
			parser_error(p, "Too many args for instruction",
					g_op[inst->opcode - 1].op);
		ft_trim_leading_space(&tok);
		ft_trim_ending_space(&tok);
		if (!check_arg(inst, &inst->param[i], tok, i))
			parser_error(p, "Wrong type", tok);
		i++;
	}
	if (i < inst->nbr_param)
		parser_error(p, "Too few args for instruction",
				g_op[inst->opcode - 1].op);
}
