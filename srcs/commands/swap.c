/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:51:09 by etien             #+#    #+#             */
/*   Updated: 2024/07/27 15:56:53 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// prelim check to ensure at least two nodes in stack
// swap_node is the second node in the stack which
// will swap positions with the head node
// next: n; previous: p
// 1st (np), 2nd (np) and 3rd (p) node will be affected
static void	swap(t_stack_node **head)
{
	t_stack_node	*swap_node;

	if (!*head || !(*head)->next)
		return ;
	swap_node = (*head)->next;
	if (swap_node->next)
		swap_node->next->prev = *head;
	(*head)->next = swap_node->next;
	(*head)->prev = swap_node;
	swap_node->next = *head;
	swap_node->prev = NULL;
	*head = swap_node;
}

void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (print)
		ft_printf("sa\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		ft_printf("ss\n");
}
