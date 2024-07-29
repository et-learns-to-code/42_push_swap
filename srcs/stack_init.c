/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:01:02 by etien             #+#    #+#             */
/*   Updated: 2024/07/29 11:21:41 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// This function will create the numbers array that will be loaded
// into the linked list, and can handle for both scenarios:
// 1) the numbers are given in a single string
// 2) the numbers are given as multiple arguments
char **create_numbers_arr(char **av)
{
	char **numbers_arr;
	char *concat_all_numbers;
	char *temp;
	int i;

	i = 0;
	while (av[i])
	{



	}

	numbers_arr = ft_split(concat_all_numbers, ' ');
	free(concat_all_numbers);
	return (numbers_arr);
}
