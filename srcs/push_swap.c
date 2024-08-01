/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:36:08 by etien             #+#    #+#             */
/*   Updated: 2024/08/01 16:51:46 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Main function for the push swap project.
// First, it checks that there is a number string and that the
// number string is not an empty string (!av[1][0]).
// Then, it initializes the stack.
// After that, it checks whether the stack is already sorted.
// Based on whether there are two, three or more than three nodes
// in stack A, the different sorting algorithms are called.
// A simple swap is done if there are only two nodes.
// Finally, the program terminates.
int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	av = create_numbers_arr(av);
	init_stack(&a, av);
	if (!stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a, true);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	// while (a)
	// {
	// 	ft_printf("%i\n", a->value);
	// 	a = a->next;
	// }
	free_stack(&a);
	return (0);
}
