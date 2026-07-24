/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 01:52:51 by jpaulo-p          #+#    #+#             */
/*   Updated: 2026/07/24 11:34:10 by jpaulo-p         ###   ########.fr       */
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
	mode_adaptative
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
	int	count[op_total];
}	t_context;

void	sa(t_context *ctx);
void	sb(t_context *ctx);
void	ss(t_context *ctx);
void	pa(t_context *ctx);
void	pb(t_context *ctx);
void	ra(t_context *ctx);
void	rb(t_context *ctx);
void	rr(t_context *ctx);
void	rra(t_context *ctx);
void	rrb(t_context *ctx);
void	rrr(t_context *ctx);
void	swap(t_stack *stack);
void	push(t_stack *stack, t_context *ctx);


#endif