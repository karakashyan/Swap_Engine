/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arptadev <arptadev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:53:12 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/29 20:49:47 by arptadev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	t_stack			*a;
	t_stack			*b;
	int				ops[11];
	int				bench;
	int				silent;
}					t_data;

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}					t_op;

void				bring_to_top(t_data *data, int pos, int size, int flag);
void				push_front(t_stack **stack, int value, int index);
int					stack_pop(t_stack **stack);
void				print_stack(t_stack *stack);
bool				parsing(char *value);
int					atoi_check(const char *nptr);
bool				dub_check(int n, t_stack *a);
char				*join_nums(int argc, char const **argv);
int					count_args(char **s);
int					stack_size(t_stack *stack);
int					find_min(t_stack *stack);
void				sa(t_data *data);
void				sb(t_data *data);
void				ss(t_data *data);
void				ra(t_data *data);
void				rb(t_data *data);
void				rr(t_data *data);
void				rra(t_data *data);
void				rrb(t_data *data);
void				rrr(t_data *data);
void				pa(t_data *data);
void				pb(t_data *data);
void				sort_three(t_data *data);
void				insertion_sort(t_data *data);
void				chunk_sort(t_data *data);
void				normalize(t_stack *stack);
int					is_sorted(t_stack *stack);
void				radix_sort(t_data *data);
void				adaptive_sort(t_data *data);
int					total_ops(t_data *data);
void				print_bench(t_data *data, double disorder, int flag);
void				free_stack(t_stack **stack);
void				free_all(t_data *data, char **arg);
double				compute_disorder(t_stack *stack);
int					parse_options(int argc, char **argv, int *bench);
int					fill_stack(t_data *data, char **arg);
int					ft_strcmp(const char *s1, const char *s2);

#endif