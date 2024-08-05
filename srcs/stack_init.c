/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:01:02 by etien             #+#    #+#             */
/*   Updated: 2024/08/05 14:49:39 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// This function is only called when (ac == 2).
// It's sole purpose is to split the integer string given in av[1].
// This function was initially a general purpose function that would concatenate
// all different forms of arguments (whether in the form "1 2 3" or 1 2 3).
// However, to make the input format more standardized, it has reduced its
// scope to just av[0] and av[1].
// OLD ANNOTATION:
// This function can handle for both scenarios:
// 1) when numbers are given in a single string
// 2) when numbers are given as multiple arguments
// It achieves this by:
// - appending a spaces after each arg
// - concatenating the args into a single string
// - splitting the string based on spaces.
char	**modify_av(char **av)
{
	char	**new_av;
	char	*concat_args;
	char	*temp;
	char	*added_space;
	int		i;

	concat_args = ft_strdup("");
	i = 0;
	while (av[i])
	{
		added_space = ft_strjoin(av[i], " ");
		temp = ft_strjoin(concat_args, added_space);
		free(concat_args);
		free(added_space);
		concat_args = temp;
		i++;
	}
	new_av = ft_split(concat_args, ' ');
	free(concat_args);
	return (new_av);
}

// This function will initialize the stack by first checking the arguments
// for syntax, value or duplicate errors, before creating and appending the
// nodes to the stack.
// Long data type is used for error checking because the number might actually
// exceed the integer limit; after checking, duplicate error can just check for
// int because the number has already been vetted.
// ft_split is only used to modify av in modify_av when first argument
// is a string with integers so free is only called when ac == 2.
// i = 0; while (av[++i]); means nodes start being processed from av[1] onwards,
// because av[0] is the program name.
void	init_stack(t_stack_node **stack, int ac, char **av)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[++i])
	{
		if (syntax_error(av[i]))
			free_err_exit(stack);
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_err_exit(stack);
		if (duplicate_error(*stack, (int)nbr))
			free_err_exit(stack);
		append_node(stack, (int)nbr);
	}
	if (ac == 2)
		free_double_arr(av);
}

// This function converts the string to a long number.
// A long number is used because the numbers have not been
// checked to fit within the integer limit yet.
// It is still necessary to check for whitespaces (ASCII 9-13) because
// ft_split will only trim away ' ' (spaces i.e. ASCII 32).
long	ft_atol(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str >= 9 && *str <= 13)
		str++;
	if ((*str) == '+' || (*str) == '-')
	{
		if ((*str) == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	return (sign * result);
}

// This function creates and appends nodes to the end of the stack and
// sets up their value.
// If there is no last node found i.e. the stack is empty, the stack pointer
// is updated to the new node.
// IMPORTANT: Initialize best_candidate boolean to false to avoid
// undefined behaviour.
void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		free_err_exit(stack);
	new_node->next = NULL;
	new_node->value = nbr;
	new_node->best_candidate = false;
	last_node = find_last(*stack);
	if (!last_node)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}
