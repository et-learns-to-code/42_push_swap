/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:36:08 by etien             #+#    #+#             */
/*   Updated: 2024/08/06 10:47:43 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Main function for the push swap project.
// Prelim check for no arguments and argument with empty string (!av[1][0]).
// If there is only one argument and the argument is a string of integers,
// modify_av will update the av variable to break apart the integer string
// into an array of integer arguments.
// Then, it initializes the stack.
// After that, it checks whether the stack is already sorted.
// Based on whether there are two, three or more than three nodes
// in stack A, the different sorting algorithms are called.
// A simple swap is done if there are only two nodes.
// Once the stack is sorted, it is freed, and the program terminates.
// Only stack A is freed, because it is assumed that if everything is sorted,
// stack B is automatically set to NULL and all existing nodes will
// have been moved to stack A.
int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = modify_av(av);
	init_stack(&a, ac, av);
	if (!stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a, true);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	return (0);
}
