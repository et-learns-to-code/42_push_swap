/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:40:35 by etien             #+#    #+#             */
/*   Updated: 2024/07/31 17:23:15 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// First node is moved to the bottom of the stack.
// Prelim check to ensure at least two nodes in the stack.
// First, build links to make list circular.
// Then update head and last node pointers to correct positions.
// Finally, break links.
// First (next, prev), second (prev) and last node (next) affected.
static void	rotate(t_stack_node **head)
{
	t_stack_node	*last_node;

	if (!*head || !(*head)->next)
		return ;
	last_node = find_last(*head);
	last_node->next = *head;
	(*head)->prev = last_node;
	last_node = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last_node->next = NULL;
}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_printf("rr\n");
}
