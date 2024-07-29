/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:31:53 by etien             #+#    #+#             */
/*   Updated: 2024/07/29 15:11:02 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// 1st check: 1st character == +/-/0-9;
// 2nd check: 1st character == +/-; 2nd character == 0-9;
// 3rd check: Remaining characters are 0-9;
// Return value of 1 indicates an error with the syntax.
int	syntax_error(char *str)
{
	if (!(*str == '+' || *str == '-' || ft_isdigit(*str)))
		return (1);
	if ((*str == '+' || *str == '-') && !ft_isdigit(*(str + 1)))
		return (1);
	str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}

// Nodes are only put on the stack after error checking is done.
// The function checks for duplicates by ensuring the number being
// checked does not already have a duplicate number on the stack.
// Return value of 1 indicates a duplicate was found.
int	duplicate_error(t_stack_node stack, int nbr)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}
