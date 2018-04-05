/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:18:25 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 17:19:02 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			open_file(char **av, t_champ *champs, int *c_i)
{
	if (*c_i >= 4)
		usage("TOO MANY CHAMPIONS\n");
	if (((champs + *c_i)->fd = open(*av, O_RDONLY)) == -1)
		usage("FAILED OPEN\n");
}

static int		check_num(int *tab_num, int *c_i)
{
	int		i;
	int		j;

	i = -1;
	while (++i < *c_i - 1)
	{
		j = -1;
		while (++j < *c_i)
			if (tab_num[i] == tab_num[j] && i != j && tab_num[i] && tab_num[j])
				return (1);
	}
	return (0);
}

static void		check_and_set(t_champ *champs, int *tab_num, int *c_i)
{
	int		i;
	int		a;

	i = -1;
	a = 0;
	if (check_num(tab_num, c_i))
		usage("same number champ\n");
	while (++i < *c_i)
	{
		if (!tab_num[i])
		{
			tab_num[i] = --a;
			while (check_num(tab_num, c_i))
				tab_num[i] = --a;
		}
		(champs + i)->number = tab_num[i];
	}
}

static int		check_option(char **av, t_champ *champs,
							t_vminfo *vminfo, int *c_i)
{
	int		i;
	int		(*fun[NB_OPTIONS])(char **, t_champ *, t_vminfo*, int *);

	fun[0] = number;
	fun[1] = dump;
	fun[2] = graph;
	fun[3] = color;
	fun[4] = verbose;
	fun[5] = aff_arg;
	i = -1;
	while (++i < NB_OPTIONS)
		if (!ft_strcmp(*av, g_options[i].name)
				|| !ft_strcmp(*av, g_options[i].ltl_name))
			return (fun[i](++av, champs, vminfo, c_i));
	usage("Wrong Option\n");
	return (0);
}

int				args(int ac, char **av, t_champ *champs, t_vminfo *vminfo)
{
	int		i;
	int		c_i;
	int		tab_num[4];

	ft_bzero(tab_num, sizeof(int) * 4);
	i = 0;
	c_i = 0;
	vminfo->dump = -1;
	while (++i < ac)
	{
		if (av[i][0] == '-')
			i += check_option(av + i, champs, vminfo, &c_i);
		else if (!ft_strcmp(av[i] + (ft_strlen(av[i]) - 4), ".cor"))
			open_file(av + i, champs, &c_i);
		else
			usage("BAD ARGS\n");
		if ((champs + c_i)->number)
			tab_num[c_i] = (champs + c_i)->number;
		c_i++;
	}
	check_and_set(champs, tab_num, &c_i);
	return (0);
}
