/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:21:59 by etien             #+#    #+#             */
/*   Updated: 2024/07/30 16:23:00 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// This function will run through the stack and set up the index
// and above_median boolean for each node.
void set_index_median(t_stack_node *stack)
{
	int index;
	int median;

	if (!stack)
		return ;
	index = 0;
	median = (stack_size(stack) / 2);
	while (stack)
	{
		stack->index = index;
		if (index < median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		index++;
	}
}

// This function will run through the stack and set up the
// target node in stack B for each node in stack A.
// Target node means the closest smaller number for a given node.
// Stack B will be sorted in descending order so that stack A will be
// in ascending order when all the nodes are pushed back to stack A.
// Since the nodes are being pushed to stack B, each node must be pushed
// onto a number smaller than them but still closest to them based on
// the nodes currently available in stack B.
// Long data type is used for the best_match_index so that it is always
// clear when this value has been updated. If there were INT_MIN or
// INT_MAX nodes in the stack and an int data type was used instead,
// this could send conflicting signals and result in incorrect execution in
// the decision tree.
// current_b pointer created because we need to iterate through the stack
// but also have the original b pointer to use the find_max function.
void set_target_for_a(t_stack_node *a, t_stack_node *b)
{
	long			best_match;
	t_stack_node	*current_b;

	while (a)
	{
		best_match = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if ((current_b->value < a->value) && (current_b->value > best_match))
			{
				best_match = current_b->value;
				a->target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			a->target_node = find_max(b);
		a = a->next;
	}
}

// This function will calculate how many total moves it takes to get a node
// in stack A and its target node in stack B to the top of their
// respective stacks. This will help to optimize the algorithm by
// ensuring the minimum number of moves are taken.
// If the node is above the median, the stack will have to rotated.
// If the node is below the median, the stack will have to be reverse rotated.
// If the node is at the top of the stack, index will be 0, meaning no
// rotation is necessary.
void set_moves_to_push_a(t_stack_node *a, t_stack_node *b)
{
	int size_a;
	int size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (a)
	{
		a->moves_to_push = a->index;
		if (!(a->above_median))
			a->moves_to_push = size_a - (a->index);
		if (a->target_node->above_median)
			a->moves_to_push += a->target_node->index;
		else
			a->moves_to_push += size_b - (a->target_node->index);
		a = a->next;
	}
}

// This function will set the best_candidate boolean for the node
// that can be pushed to the other stack with the least number of
// moves. If two nodes share the same number of moves, the node closer
// to the top of the stack will be given priority.
// Unlike the set_index_median function, only boolean for the best
// candidate is set. Boolean for the other nodes are uninitialized.
void set_best_candidate(t_stack_node *stack)
{
	int				least_moves;
	t_stack_node	*least_moves_node;

	if (!stack)
		return ;
	least_moves = INT_MAX;
	while (stack)
	{
		if (stack->moves_to_push < least_moves)
		{
			least_moves = stack->moves_to_push;
			least_moves_node = stack;
		}
		stack = stack->next;
	}
	least_moves_node->best_candidate = true;
}

// This is the composite function combining all the above functions.
// Node variables will be initialized in the sequence:
// index > above_median > target_node > moves_to_push > best_candidate
// Index and median in stack B nodes have to be initialized because this info
// is needed by the moves_to_push function.
void init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	set_index_median(a);
	set_index_median(b);
	set_target_for_a(a, b);
	set_moves_to_push_a(a, b);
	set_best_candidate(a);
}
