/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:21:11 by etien             #+#    #+#             */
/*   Updated: 2024/07/31 14:43:12 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*best_candidate;

	best_candidate = find_best_candidate(*a);


	pb(a, b, false);
}




void move_b_to_a(t_stack_node **a, t_stack_node **b)
{

	pa(a, b, false);
}

// This function will move the node passed in to the top
// of its stack.
void	node_on_top(t_stack_node **stack, t_stack_node)
{





}

// This function optimizes the algorithm when preparing to push
// the best candidate node from stack A to stack B.
// Depending on whether both the push node and its target node are above
// or below the median, both stacks will be rotated at once to save the
// number of commands used. The direction parameter will determine whether
// a rotation or a reverse rotation is applied.
void rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *best_candidate, int direction)
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
