/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:15:26 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:15:48 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_argp_options g_options[NB_OPTIONS] =
{
	{"--number", "-n", "N", "Fix number of next player"},
	{"--dump", "-d", "N", "Dump memory on stdout"},
	{"--graph", "-g", 0, "do the Dump with Color"},
	{"--color", "-c", 0, "do one Dump with Color"},
	{"--verbose", "-v", 0, "do one Dump with Color"},
	{"--aff", "-a", 0, "Display register in ASCII"},
};

void	n_check(char *str)
{
	int		i;
	int		neg;

	i = -1;
	neg = 0;
	while (str[++i])
	{
		if (str[i] == '-' && !neg)
			neg = 1;
		else if (ft_isdigit(str[i]))
			continue ;
		else
			usage("error in N arg\n");
	}
}

int		number(char **av, t_champ *champs, t_vminfo *vminfo, int *c_i)
{
	(void)vminfo;
	if (*av && *(av + 1))
	{
		n_check(*av);
		(champs + *c_i)->number = ft_atoi(*av);
		open_file(++av, champs, c_i);
	}
	else
		usage("Missing N for --number options or \
Missing champiompion after N\n");
	return (2);
}

int		dump(char **av, t_champ *champs, t_vminfo *vminfo, int *c_i)
{
	if (*av)
	{
		n_check(*av);
		vminfo->dump = ft_atoi(*av);
	}
	else
		usage("Missing N for --dump option\n");
	(void)champs;
	(*c_i)--;
	return (1);
}
