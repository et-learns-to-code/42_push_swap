/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:53:21 by etien             #+#    #+#             */
/*   Updated: 2024/07/27 17:03:44 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int stack_len(t_stack_node *stack)
{
	int len;

	if (!stack)
		return(0);
	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

t_stack_node *find_min(t_stack_node *stack)
{
	t_stack_node *min;

	return (min);
}

t_stack_node *find_max(t_stack_node *stack)
{
	t_stack_node *max;

	return (max);
}

