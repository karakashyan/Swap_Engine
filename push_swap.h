/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <ekarakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:53:12 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/21 17:06:08 by ekarakas         ###   ########.fr       */
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
}					t_data;

void				push_front(t_stack **stack, int value);
int					stack_pop(t_stack **stack);
void				print_stack(t_stack *stack);
bool				parsing(char *value);
int					atoi_check(const char *nptr);
bool				dub_check(int n, t_stack *a);
char				*join_args(int argc, char const **argv);
int					count_args(char **s);
int					stack_size(t_stack *stack);
int					find_min(t_stack *stack);
void				bring_to_top(t_data *data, int pos, int size);
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
void				sort_five(t_data *data);
void    			insertion_sort(t_data *data);
void    			normalize(t_stack *stack);

#endif