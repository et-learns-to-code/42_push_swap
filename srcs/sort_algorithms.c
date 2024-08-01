/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:43:49 by etien             #+#    #+#             */
/*   Updated: 2024/08/01 10:32:11 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// These are the main steps in the Turk's algorithm function:
// 1) If stack A has at least five nodes, its two top nodes will be
// pushed to stack B so that there are nodes in stack B to start
// cross-sorting between stacks.
// 2) Nodes in stack A are initialized and pushed to stack B onto their
// target nodes so that stack B is sorted in descending order.
// 3) Keep 3 nodes in stack A and sort them in ascending
// order with a separate sort three algorithm.
// 4) Nodes in stack B are initialized and pushed back to stack A onto
// their target nodes so that stack A is sorted in ascending order.
// 5) Finally, ensure that the smallest number is rotated to the top.
// 6) Voilà, stack A is fully sorted.
void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	size_a;

	size_a = stack_size(*a);
	if ((size_a-- > 3) && (!stack_sorted(*a)))
		pb(a, b, true);
	if ((size_a-- > 3) && (!stack_sorted(*a)))
		pb(a, b, true);
	while ((size_a-- > 3) && (!stack_sorted(*a)))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_index_median(*a);
	min_on_top(a);
}

// This mini algorithm function sorts stack A when there are only three
// nodes left in it.
// If the max_node is at the head of the stack, just rotate it to the
// bottom of the stack.
// If the max_node is in the second position, reverse rotate the stack
// so that it becomes the last node.
// If the first node is still bigger than the second node, swap
// the first two nodes.
void	sort_three(t_stack_node **a)
{
	t_stack_node	*max_node;

	max_node = find_max(*a);
	if (!stack_sorted(*a))
	{
		if ((*a) == max_node)
			ra(a, false);
		else if ((*a)->next == max_node)
			rra(a, false);
		if ((*a)->value > (*a)->next->value)
			sa(a, false);
	}
}

// This function checks that the stack has been sorted in ascending order
// by returning false if a number is larger than the number that comes
// after it. Only stack A will need to be sorted in ascending order.
bool	stack_sorted(t_stack_node *a)
{
	if (!a)
		return (true);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}
