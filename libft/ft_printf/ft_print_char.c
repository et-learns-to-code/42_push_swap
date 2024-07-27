/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:41:29 by etien             #+#    #+#             */
/*   Updated: 2024/06/27 10:40:28 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// Prints a single character.
int	ft_print_char(va_list ap)
{
	char	c;

	c = (char) va_arg(ap, int);
	return (write(1, &c, 1));
}
