/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:01:02 by etien             #+#    #+#             */
/*   Updated: 2024/07/29 14:30:24 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// This function will create the numbers array that will be processed into
// individual nodes in the linked list. It can handle for both scenarios:
// 1) when numbers are given in a single string
// 2) when numbers are given as multiple arguments
// It achieves this by creating a single string by appending spaces after
// the numbers, concatenating the numbers then splitting the string
// based on spaces.
char	**create_numbers_arr(char **av)
{
	char	**numbers_arr;
	char	*concat_all_numbers;
	char	*temp;
	char	*added_space;
	int		i;

	concat_all_numbers = ft_strdup("");
	i = 1;
	while (av[i])
	{
		added_space = ft_strjoin(av[i], " ");
		temp = ft_strjoin(concat_all_numbers, added_space);
		free(concat_all_numbers);
		free(added_space);
		concat_all_numbers = temp;
		i++;
	}
	numbers_arr = ft_split(concat_all_numbers, ' ');
	free(concat_all_numbers);
	return (numbers_arr);
}
