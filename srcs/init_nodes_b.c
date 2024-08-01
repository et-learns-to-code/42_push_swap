/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:45:04 by etien             #+#    #+#             */
/*   Updated: 2024/08/01 10:33:56 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// This function initializes the nodes in stack B for pushing back
// to stack A.
// Index and median in stack A nodes have to be initialized so that the
// most efficient rotation can take place.
// set_index_median is borrowed from the init_nodes_a.c file
// Least moves calculation (moves_to_push and best_candidate variables)
// is only necessary when pushing from stack A to stack B.
// When pushing back from stack B to stack A, the numbers are already
// sorted so this optimization is not necessary.
void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	set_index_median(b);
	set_index_median(a);
	set_target_for_b(a, b);
}

// This function will run through the stack and set up the
// target node in stack A for each node in stack B.
// Target node means the closest bigger number for a given node.
// This will sort the nodes in ascending order as they are pushed
// back to stack A.
// Long data type is used for best_match so that it is always
// clear when this value has been updated. If there were INT_MIN or
// INT_MAX nodes in the stack and an int data type was used instead,
// this could send conflicting signals and result in incorrect execution in
// the decision tree.
// current_a pointer created because we need to iterate through the stack
// but also have the original a pointer to use the find_min function.
void	set_target_for_b(t_stack_node *a, t_stack_node *b)
{
	long			best_match;
	t_stack_node	*current_a;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if ((current_a->value > b->value)
				&& (current_a->value < best_match))
			{
				best_match = current_a->value;
				b->target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = find_min(a);
		b = b->next;
	}
}
