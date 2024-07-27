/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:36:08 by etien             #+#    #+#             */
/*   Updated: 2024/07/27 13:06:37 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main()
{
	// Print to verify ft_printf works
    ft_printf("Hello %s\n", "World");

    char *line;
    int fd = open("meow", O_RDONLY);

    // Check if file opened successfully
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    // Check get_next_line output
    while ((line = get_next_line(fd)) != NULL)
    {
        ft_printf("Line: %s", line);
        free(line);
    }

    // Close the file descriptor
    close(fd);

    return 0;
}
