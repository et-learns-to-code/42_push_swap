/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:25:10 by etien             #+#    #+#             */
/*   Updated: 2024/07/27 15:48:17 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// prelim check to ensure at least two nodes in stack
// 1st (p), second last (n) and last node (np) affected
// Last element is moved to the top of the stack
// First build links to make list circular
// Then update head and last node pointers to correct posittions
// Then break links
static void	reverse_rotate(t_stack_node **head)
{
	t_stack_node	*last_node;

	if (!*head || !(*head)->next)
		return ;
	last_node = *head;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = *head;
	(*head)->prev = last_node;
	*head = last_node;
	last_node = last_node->prev;
	(*head)->prev = NULL;
	last_node->next = NULL;
}

void	rra(t_stack_node **a, bool print)
{
	reverse_rotate(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print)
{
	reverse_rotate(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		ft_printf("rrr\n");
}
