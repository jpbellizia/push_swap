/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-p <jpaulo-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 00:06:57 by vneves-c          #+#    #+#             */
/*   Updated: 2026/07/30 11:45:11 by jpaulo-p         ###   ########.fr       */
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
	int		disorder;
	t_mode	mode;
	int		bench;
}	t_context;

void	sa(t_context *ctx);
void	sb(t_context *ctx);
void	pa(t_context *ctx);
void	ss(t_context *ctx);
void	pb(t_context *ctx);
void	ra(t_context *ctx);
void	rb(t_context *ctx);
void	rr(t_context *ctx);
void	rra(t_context *ctx);
void	rrb(t_context *ctx);
void	rrr(t_context *ctx);
void	emit(t_context *ctx, char *name, t_op op);
void	swap(t_stack *stack);
void	push(t_stack *stack, int value);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
int		pop(t_stack *stack);
int		error(void);
long	ft_atol(const char *str);
int		is_flag(char *arg);
void	define_mode(int argc, char **argv, t_context *ctx);
int		check_number(char *arg);
int		validate_numbers(int argc, char **argv);
int		check_duplicates(int argc, char **argv);
int		compute_disorder(t_stack *stack);
int		count_numbers(int argc, char **argv);
int		stack_alloc(t_stack *stack, int capacity);
int		stack_fill(t_stack *stack, int argc, char **argv);
int		context_init(t_context *ctx, int argc, char **argv);

#endif
