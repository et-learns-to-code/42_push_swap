/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:06:43 by etien             #+#    #+#             */
/*   Updated: 2024/07/30 16:20:33 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

// Node variables
typedef struct s_stack_node
{
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	int					value;
	int					index;
	bool				above_median;
	struct s_stack_node	*target_node;
	int					moves_to_push;
	bool				best_candidate;
}	t_stack_node;

// Commands
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);

// Error handling
void			free_err_exit(t_stack_node **stack);
void			free_stack(t_stack_node **stack);
int				syntax_error(char *str);
int				duplicate_error(t_stack_node stack, int nbr);

// Stack init
char			**create_numbers_arr(char **av);
void			init_stack(t_stack_node **stack, char **av);
long			ft_atol(char *str);
void			append_node(t_stack_node **stack, int nbr);

// Stack utils
int				stack_size(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

// Init nodes
void set_index_median(t_stack_node *stack);
void set_target_for_a(t_stack_node *stack_a, t_stack_node *stack_b);
void set_moves_to_push_a(t_stack_node *a, t_stack_node *b);
void set_best_candidate(t_stack_node *stack);
void init_nodes_a(t_stack_node *a, t_stack_node *b);

#endif
