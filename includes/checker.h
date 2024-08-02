/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etien <etien@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:33:15 by etien             #+#    #+#             */
/*   Updated: 2024/08/02 14:26:16 by etien            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void	execute_command(char *command, t_stack_node **a, t_stack_node **b);
void	invalid_command(t_stack_node **a, t_stack_node **b);

#endif
