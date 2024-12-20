/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:21:59 by etien             #+#    #+#             */
/*   Updated: 2024/08/06 10:25:36 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// This is the composite function combining all the functions below.
// Stack A node variables will be initialized in the sequence:
// index > above_median > target_node > moves_to_push > best_candidate
// Index and median in stack B nodes have to be initialized because this info
// is needed by the moves_to_push function.
void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	set_index_median(a);
	set_index_median(b);
	set_target_for_a(a, b);
	set_moves_to_push_a(a, b);
	set_best_candidate(a);
}

// This function will run through the stack and set up the index
// and above_median boolean for each node.
void	set_index_median(t_stack_node *stack)
{
	int	index;
	int	median;

	if (!stack)
		return ;
	index = 0;
	median = (stack_size(stack) / 2);
	while (stack)
	{
		stack->index = index;
		if (index <= median)
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
// LONG_MIN serves as a sentinel value, so that in case a node is unable
// to find a target node (e.g. a large negative number), it will be assigned
// the node with the largest value as its target. Since the stack can be
// rotated, the descending order of the stack will be maintained.
// Long data type is used for best_match so that it is always
// clear when this value has been updated. If there were INT_MIN or
// INT_MAX nodes in the stack and an int data type was used instead,
// this could send conflicting signals and result in incorrect execution in
// the decision tree.
// current_b pointer created because we need to iterate through the stack
// but also need the original b pointer to use the find_max function.
void	set_target_for_a(t_stack_node *a, t_stack_node *b)
{
	long			best_match;
	t_stack_node	*current_b;

	while (a)
	{
		best_match = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if ((current_b->value < a->value)
				&& (current_b->value > best_match))
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
// If the node is above the median, the stack will have to rotated,
// so the number of moves will be its index.
// If the node is below the median, the stack will have to be reverse rotated,
// so the number of moves will be (stack size - index).
// If the node is at the top of the stack, index will be 0, meaning no
// rotation is necessary.
void	set_moves_to_push_a(t_stack_node *a, t_stack_node *b)
{
	int	size_a;
	int	size_b;
	int	moves_a_to_top;
	int	moves_b_to_top;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (a)
	{
		moves_a_to_top = a->index;
		if (!a->above_median)
			moves_a_to_top = size_a - a->index;
		moves_b_to_top = a->target_node->index;
		if (!a->target_node->above_median)
			moves_b_to_top = size_b - a->target_node->index;
		a->moves_to_push = moves_a_to_top + moves_b_to_top;
		a = a->next;
	}
}

// This function will set the best_candidate boolean for the node in
// stack A that can be pushed to the other stack with the least number of
// moves. If two nodes share the same number of moves, the node closer
// to the top of the stack will be given priority.
// IMPORTANT: Boolean for the other nodes are initialized to false by
// default in the append_node function.
void	set_best_candidate(t_stack_node *a)
{
	t_stack_node	*least_moves_node;

	if (!a)
		return ;
	least_moves_node = a;
	while (a)
	{
		if (a->moves_to_push < least_moves_node->moves_to_push)
			least_moves_node = a;
		a = a->next;
	}
	least_moves_node->best_candidate = true;
}
