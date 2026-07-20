#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

/* Adaptive strategy thresholds (fixed by the subject) */
# define THRESH_LOW		0.2
# define THRESH_HIGH	0.5

/* -------------------------------------------------------------------------- */
/*   Types                                                                    */
/* -------------------------------------------------------------------------- */

typedef enum e_strategy
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE
}	t_strategy;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_op;

/*
** Suggested node: doubly linked so rra/rrb are O(1).
** value = original number (validation/debug), index = rank 0..n-1
** (everything after normalization sorts by index, never by value).
*/
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/*
** One struct to carry the whole program state around
** (global variables are forbidden by the subject).
*/
typedef struct s_data
{
	t_stack		a;
	t_stack		b;
	t_strategy	strategy;
	int			bench;
	double		disorder;
	long		op_count[OP_COUNT];
}	t_data;

/* -------------------------------------------------------------------------- */
/*   parsing/  — args, flags, validation                                      */
/* -------------------------------------------------------------------------- */

/* TODO: parse argv into stack a; handle "Error\n" on stderr + exit */
int		parse_input(t_data *data, int argc, char **argv);
int		parse_flag(t_data *data, char *arg);
int		validate_int(const char *str, long *out);
int		has_duplicates(t_stack *a);
void	error_exit(t_data *data);

/* -------------------------------------------------------------------------- */
/*   stack/  — lifecycle, utils, normalization                                */
/* -------------------------------------------------------------------------- */

int		stack_push_bottom(t_stack *s, int value);
void	stack_free(t_stack *s);
int		stack_is_sorted(t_stack *a);
t_node	*stack_at(t_stack *s, int i);
void	assign_ranks(t_stack *a);

/* -------------------------------------------------------------------------- */
/*   ops/  — the 11 push_swap operations                                      */
/*   Each op: mutate the stack(s), print its name, bump op_count.             */
/*   Tip: route everything through do_op() so --bench counting is free.       */
/* -------------------------------------------------------------------------- */

void	do_op(t_data *data, t_op op);
void	op_sa(t_data *data);
void	op_sb(t_data *data);
void	op_ss(t_data *data);
void	op_pa(t_data *data);
void	op_pb(t_data *data);
void	op_ra(t_data *data);
void	op_rb(t_data *data);
void	op_rr(t_data *data);
void	op_rra(t_data *data);
void	op_rrb(t_data *data);
void	op_rrr(t_data *data);

/* -------------------------------------------------------------------------- */
/*   metrics/  — disorder + bench output                                      */
/* -------------------------------------------------------------------------- */

/* Must be measured BEFORE any move (subject VI.3.2) */
double	compute_disorder(t_stack *a);
void	bench_report(t_data *data);

/* -------------------------------------------------------------------------- */
/*   strategies/  — the four required algorithms                              */
/* -------------------------------------------------------------------------- */

void	sort_dispatch(t_data *data);
void	sort_small(t_data *data);
void	sort_simple(t_data *data);
void	sort_medium(t_data *data);
void	sort_complex(t_data *data);
void	sort_adaptive(t_data *data);

#endif