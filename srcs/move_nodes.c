/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:21:11 by etien             #+#    #+#             */
/*   Updated: 2024/08/01 10:39:15 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// This function is called in the first while loop in the sort_stack function.
// It will determine the movement of nodes from stack A to stack B.
// First, the best candidate in stack A for pushing to stack B is selected.
// Then rotate_both and node_on_top functions are called and applied
// to both the candidate node and its target node to get them on top
// of their respective stacks.
// Finally, the candidate node is pushed to stack B.
void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*best_candidate;

	best_candidate = find_best_candidate(*a);
	if (best_candidate->above_median
		&& best_candidate->target_node->above_median)
		rotate_both_stacks(a, b, best_candidate, FORWARD);
	else if (!(best_candidate->above_median)
		&& !(best_candidate->target_node->above_median))
		rotate_both_stacks(a, b, best_candidate, REVERSE);
	node_on_top(a, best_candidate, 'a');
	node_on_top(b, best_candidate->target_node, 'b');
	pb(a, b, false);
}

// This function is called in the second while loop in the sort_stack function.
// Since stack B has already been sorted in descending order,
// only the target nodes in stack A have to bubble up to the top of the stack
// before we push the nodes from stack B back to stack A.
void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	node_on_top(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

// This function optimizes the algorithm when preparing to push
// the best candidate node from stack A to stack B.
// Depending on whether both the push node and its target node are above
// or below the median (decided in move_a_to_b function), both stacks will
// be rotated at once to save the number of commands used.
// The direction parameter will determine whether a rotation or a
// reverse rotation is applied.
void	rotate_both_stacks(t_stack_node **a, t_stack_node **b,
	t_stack_node *best_candidate, int direction)
{
	if (direction == FORWARD)
	{
		while (*a != best_candidate && *b != best_candidate->target_node)
			rr(a, b, false);
	}
	else if (direction == REVERSE)
	{
		while (*a != best_candidate && *b != best_candidate->target_node)
			rrr(a, b, false);
	}
	set_index_median(*a);
	set_index_median(*b);
}

// This function will move the node passed in as a parameter
// to the top of its stack.
// Stack name must be given as a parameter because this
// is a general function and stack A and B have different
// commands for moving the nodes.
void	node_on_top(t_stack_node **stack, t_stack_node *node, char stack_name)
{
	while (*stack != node)
	{
		if (stack_name == 'a')
		{
			if (node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

// This function is only used by stack A to bring the smallest number
// to the top of the stack right before the sorting terminates.
// The *a pointer is always pointing to the head of the stack,
// so the while condition is rotating until the min node is
// at the head/top of the stack.
void	min_on_top(t_stack_node **a)
{
	t_stack_node	*min_node;

	min_node = find_min(*a);
	while (*a != min_node)
	{
		if (min_node->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
