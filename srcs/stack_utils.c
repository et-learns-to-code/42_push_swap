/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:53:21 by etien             #+#    #+#             */
/*   Updated: 2024/07/31 17:35:15 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Returns the number of nodes in the stack.
int	stack_size(t_stack_node *stack)
{
	int	size;

	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

// Returns the last node in the stack.
t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

// Returns the node with the smallest value in the stack.
// Min node is the first node by default then updated
// from comparison with subsequent nodes.
t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->value < min_node->value)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

// Returns the node with the largest value in the stack.
// Max node is the first node by default then updated
// from comparison with subsequent nodes.
t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->value > max_node->value)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

// Returns the node in the stack that has its best_candidate
// boolean set to true.
// This function will work across repeated function calls
// because the best_candidate is only assessed for stack A
// when pushing nodes to stack B. Furthermore, each time the
// boolean is set, that node will be moved into the other
// stack, which means at any one time, only one node will
// have the boolean turned on.
t_stack_node	*find_best_candidate(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->best_candidate)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
