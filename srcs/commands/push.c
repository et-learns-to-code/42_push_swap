/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:18:23 by etien             #+#    #+#             */
/*   Updated: 2024/07/27 15:42:52 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// returns if nothing to push from the stack
// first checks that there is a node to push from src
// a pointer is created to the node to be pushed because
// it has to be detached from the src stack and moved to the
// dst stack
// src pointer is moved to the next node
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
		*src->prev = NULL;
	}
	if (!*dst)
	{
		push_node->next = NULL;
		*dst = push_node;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (print)
		ft_printf("pb\n");
}
