/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 06:10:32 by kamin             #+#    #+#             */
/*   Updated: 2022/01/08 08:06:54 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief This funciton will swap the first two elements in a stack
 * 
 * @param stack The Stack To Swap The Topmost Two Elements
 */
void	swap_stack(int **stack)
{
	int	elems;
	int	tmp;

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
void	swap_both(int **stack, int **stack2)
{
	swap_stack(stack);
	swap_stack(stack2);
}
