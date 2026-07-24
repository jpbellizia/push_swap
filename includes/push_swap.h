/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:06:57 by vneves-c          #+#    #+#             */
/*   Updated: 2026/07/24 14:29:16 by jpaulo-p         ###   ########.fr       */
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
}	t_mode;

typedef struct s_stack
{
	int	*values;
	int	size;
	int	capacity;
}	t_stack;

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
}	t_op;

typedef struct s_context
{
	t_stack	a;
	t_stack	b;
	int		count[op_total];
	double	disorder;
	t_mode	strategy;
}	t_context;

void    sa(t_context *ctx);
void    sb(t_context *ctx);
void    pa(t_context *ctx);
void    ss(t_context *ctx);
void    pb(t_context *ctx);
void    ra(t_context *ctx);
void    rb(t_context *ctx);
void    rr(t_context *ctx);
void    rra(t_context *ctx);
void    rrb(t_context *ctx);
void    rrr(t_context *ctx);
int		error(void);
int		is_flag(char *arg);
void	define_mode(int argc, char **argv, t_mode *mode, int *bench);

#endif
