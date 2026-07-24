/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneves-c <vneves-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:06:57 by vneves-c          #+#    #+#             */
/*   Updated: 2026/07/24 12:43:14 by vneves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <limits.h> 

typedef enum e_mode
{
	mode_none,
	mode_simple,
	mode_medium,
	mode_complex,
	mode_adaptive
}			t_mode;

typedef struct s_stack
{
	int	*values;
	int	size;
	int	capacity;
}			t_stack;

typedef enum e_op
{
	op_sa,
	op_sb,
	op_ss,
	op_pa,
	op_pb,
	op_ra,
	op_rb,
	op_rr,
	op_rra,
	op_rrb,
	op_rrr,
	op_total
}		t_op;

typedef struct s_stats
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	double	disorder;
	t_mode	strategy;
}			t_stats;

typedef struct s_context
{
	t_stack	a;
	t_stack	b;
	int	count[op_total];
}			t_context;

int		error(void);
int		is_flag(char *arg);
void	define_mode(int argc, char **argv, t_mode *mode, int *bench);

#endif
