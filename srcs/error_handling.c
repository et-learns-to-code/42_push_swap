/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:31:53 by etien             #+#    #+#             */
/*   Updated: 2024/08/01 10:47:30 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// This function checks that the syntax is valid i.e. only +/- signs
// and numbers are allowed.
// 1st check: 1st character == +/-/0-9;
// 2nd check: 1st character == +/-; 2nd character == 0-9;
// 3rd check: Remaining characters are 0-9;
// Return value of 1 indicates an error with the syntax.
// Remember to increment the string before the 3rd check so that
// the while loop runs from the second character onwards,
// otherwise +/- signs will trigger an error.
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
// This function checks for duplicates by ensuring the number being
// checked does not already have a duplicate number on the stack.
// Return value of 1 indicates a duplicate was found.
int	duplicate_error(t_stack_node *stack, int nbr)
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

// This function frees the stack, prints the error message and
// exits the program.
void	free_err_exit(t_stack_node **stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

// This function will free the existing stack if any errors were encountered
// during processing of the number arrays.
// *stack will automatically be set to NULL by the end of the loop.
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current_node;

	if (!stack)
		return ;
	while (*stack)
	{
		current_node = *stack;
		*stack = (*stack)->next;
		free(current_node);
	}
}

// This function is called in init_stack to free the numbers array
// that was malloced once all the numbers have been processed into
// nodes in the linked list.
void	free_double_arr(char **av)
{
	int	i;

	if (!av)
		return ;
	i = -1;
	while (av[++i])
		free(av[i]);
	free(av);
}
