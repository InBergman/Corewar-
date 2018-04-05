/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_opt2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:16:03 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:16:05 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		graph(char **av, t_champ *champs, t_vminfo *vminfo, int *c_i)
{
	vminfo->graph = 1;
	(*c_i)--;
	(void)champs;
	(void)av;
	return (0);
}

int		color(char **av, t_champ *champs, t_vminfo *vminfo, int *c_i)
{
	vminfo->color = 1;
	(*c_i)--;
	(void)champs;
	(void)av;
	return (0);
}

int		verbose(char **av, t_champ *champs, t_vminfo *vminfo, int *c_i)
{
	vminfo->verbose = 1;
	(*c_i)--;
	(void)champs;
	(void)av;
	return (0);
}

int		aff_arg(char **av, t_champ *champs, t_vminfo *vminfo, int *c_i)
{
	vminfo->aff = 1;
	(*c_i)--;
	(void)champs;
	(void)av;
	return (0);
}
