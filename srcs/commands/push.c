/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:18:23 by etien             #+#    #+#             */
/*   Updated: 2024/08/05 10:22:17 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Pushes a node from the top of one stack to the top of the other stack.
// Returns if there is nothing to push from the stack.
// A pointer is created to the node to be pushed because it has to be
// detached from the src stack and moved to the dst stack.
// The src pointer is updated to the next node.
// IMPORTANT: If there is no next node, the src pointer will be set to NULL.
// Without this line, there will be an infinite loop when pushing from
// stack B back to stack A.
// The push node will become the new head of the dst stack.
static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	push_node->prev = NULL;
	if ((*src)->next)
	{
		*src = (*src)->next;
		(*src)->prev = NULL;
	}
	else
		*src = NULL;
	if (!*dst)
	{
		push_node->next = NULL;
		*dst = push_node;
	}
	else
	{
		push_node->next = *dst;
		(*dst)->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b, bool print)
{
	push(b, a);
	if (print)
		ft_printf("pb\n");
}
