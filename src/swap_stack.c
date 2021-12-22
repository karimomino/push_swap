/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 06:10:32 by kamin             #+#    #+#             */
/*   Updated: 2021/12/22 04:28:16 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief This funciton will swap the first two elements in a stack
 * 
 * @param stack The Stack To Swap The Topmost Two Elements
 */
void	swap_stack(char ***stack)
{
	int		elems;
	char	*tmp;

	elems = count_elems(*stack);
	tmp = *stack[elems - 2];
	*stack[elems - 2] = *stack[elems - 1];
	*stack[elems - 1] = tmp;
}

/**
 * @brief This funciton will swap the first two elements in both stack
 * 
 * @param stack First Stack To Swap The Topmost Two Elements
 * @param stack2 Second Stack To Swap The Topmost Two Elements
 */
void	swap_both(char ***stack, char ***stack2)
{
	swap_stack(stack);
	swap_stack(stack2);
}
