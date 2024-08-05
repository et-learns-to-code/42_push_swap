/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:38:06 by etien             #+#    #+#             */
/*   Updated: 2024/08/05 14:46:37 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

// The main function initializes the stack based on the argument input,
// then it keeps prompting the user for command inputs in a while loop.
// Each time a command is given, it is executed on the stack.
// The while loop is terminated when "CTRL-D" (EOF signal) is pressed
// because get_next_line will return a NULL instead of a string.
// Finally, the stack_sorted function is called to check that the stack has
// been sorted successfully. It will print 'OK' if this is the case,
// otherwise it will print 'KO'.
int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*command;

	a = NULL;
	b = NULL;
	if ((ac == 1) || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = modify_av(av);
	init_stack(&a, ac, av);
	command = get_next_line(STDIN_FILENO);
	while (command)
	{
		execute_command(command, &a, &b);
		command = get_next_line(STDIN_FILENO);
	}
	if (stack_sorted(a) && b == NULL)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

// The user's input into STDIN will be matched to one of the
// 11 valid commands and the relevant command will be executed.
// The boolean is set to false, so that the command is not printed
// to STDOUT (this is the behaviour required for the checker).
// If an invalid command was inputted, a function will be called
// to free the stacks.
void	execute_command(char *command, t_stack_node **a, t_stack_node **b)
{
	if (!ft_strncmp(command, "sa\n", 3))
		sa(a, false);
	else if (!ft_strncmp(command, "sb\n", 3))
		sb(b, false);
	else if (!ft_strncmp(command, "ss\n", 3))
		ss(a, b, false);
	else if (!ft_strncmp(command, "pa\n", 3))
		pa(a, b, false);
	else if (!ft_strncmp(command, "pb\n", 3))
		pb(a, b, false);
	else if (!ft_strncmp(command, "ra\n", 3))
		ra(a, false);
	else if (!ft_strncmp(command, "rb\n", 3))
		rb(b, false);
	else if (!ft_strncmp(command, "rr\n", 3))
		rr(a, b, false);
	else if (!ft_strncmp(command, "rra\n", 4))
		rra(a, false);
	else if (!ft_strncmp(command, "rrb\n", 4))
		rrb(b, false);
	else if (!ft_strncmp(command, "rrr\n", 4))
		rrr(a, b, false);
	else
		invalid_command(a, b);
	free(command);
}

// This function frees both stacks, outputs an error in STDERR and exits.
// free_err_exit is not used here because the function was designed to
// only free one stack. In this case, since the stack is still being
// sorted, there could be nodes in both stacks. All the nodes in both
// stacks have to be freed.
void	invalid_command(t_stack_node **a, t_stack_node **b)
{
	free_stack(a);
	free_stack(b);
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}
