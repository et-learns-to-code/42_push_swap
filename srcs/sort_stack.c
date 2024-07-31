/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:43:49 by etien             #+#    #+#             */
/*   Updated: 2024/07/31 10:56:30 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// These are the main steps in the Turk's algorithm function:
// 1) If stack A has more than three nodes, its two top nodes will be
// pushed to stack B so that there are nodes in stack B to start
// cross-sorting between stacks.
// 2) Nodes in stack A are initialized and pushed to stack B onto their
// target nodes so that stack B is sorted in descending order.
// 3) Allow 3 nodes to remain in stack A and sort them in ascending
// order with a separate sort three algorithm.
// 4) Nodes in stack B are initialized and pushed back to stack A onto
// their target nodes so that stack A is sorted in ascending order.
// 5) Finally, ensure that the smallest number is rotated to the top.
// 6) Voilà, stack A is fully sorted.
// Least moves calculation (moves_to_push and best_candidate variables)
// is only necessary when pushing from stack A to stack B.
// When pushing back from stack B to stack A, the numbers are already
// sorted so this optimization is not necessary.
void sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	size_a;

	size_a = stack_size(*a);
	if ((size_a-- > 3) && (!stack_sorted(*a)))
		pb(b, a, true);
	if ((size_a-- > 3) && (!stack_sorted(*a)))
		pb(b, a, true);
	while ((size_a-- > 3) && (!stack_sorted(*a)))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*b, *a);
		move_b_to_a(b, a);
	}
	set_index_median(*a);
	min_on_top(a);
}

// This function checks that the stack has been sorted in ascending order
// by returning false if a number is larger than the number that comes
// after it. Only stack A will need to be sorted in ascending order.
bool stack_sorted(t_stack_node *a)
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
