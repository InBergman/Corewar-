/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msireau <msireau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:35:55 by msireau           #+#    #+#             */
/*   Updated: 2016/11/20 18:36:03 by msireau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "op.h"
# include "libft.h"
# define NB_OPTIONS		6
# define OPC			prc->action.op
# define PC				prc->pc_pos
# define CURSOR			prc->action.nbr_oct
# define IS_REG(x)		(x > 0 && x <= 16) ? 1 : 0
# define ARG(x)			prc->action.args[x]
# define TYPE(x)		prc->action.type[x]

typedef struct		s_arg_options
{
	char			*name;
	char			*ltl_name;
	char			*associated;
	char			*doc;
}					t_argp_options;

typedef struct		s_inst
{
	int				op;
	int				type[3];
	int				args[3];
	int				nbr_oct;
}					t_inst;

typedef struct		s_champ
{
	int				fd;
	int				number;
	int				weight;
	char			*name;
	char			*comment;
	int				nb_live;
	int				size;
}					t_champ;

typedef struct		s_vminfo
{
	int				cycles;
	int				dump;
	int				graph;
	int				color;
	int				verbose;
	int				aff;
	int				cycle_to_die;
	int				check;
	int				nb_live;
	int				nb_champs;
	char			*memory;
	int				last_live;
	t_list_head		process;
	t_champ			*champ;
}					t_vminfo;

typedef struct		s_process
{
	int				nb;
	int				cycle_end;
	int				pc_pos;
	int				carry;
	int				alive;
	int				reg[REG_NUMBER];
	int				ok_arg;
	t_inst			action;
}					t_process;

typedef struct		s_op
{
	char			*op;
	int				nb_param;
	char			type[3];
	int				opcode;
	int				nb_cycles;
	char			*comment;
	int				smthg;
	int				smthg2;
}					t_op;

extern t_op			g_op[17];
extern int			g_nb_prc;
extern				t_argp_options g_options[NB_OPTIONS];

#endif
