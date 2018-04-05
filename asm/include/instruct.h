/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdurand <rdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:03:29 by rdurand           #+#    #+#             */
/*   Updated: 2016/11/20 18:03:33 by rdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCT_H
# define INSTRUCT_H

# include "asm.h"

typedef struct		s_value
{
	int				value;
	int				size;
	int				type;
	char			*label;
}					t_value;

typedef struct		s_inst
{
	unsigned int	index;
	int				opcode;
	size_t			nbr_param;
	struct s_value	param[3];
	struct s_inst	*next;
	struct s_inst	*prev;
}					t_inst;

typedef struct		s_label
{
	char			*label;
	struct s_inst	*inst;
	struct s_label	*next;
	struct s_label	*prev;
}					t_label;

#endif
