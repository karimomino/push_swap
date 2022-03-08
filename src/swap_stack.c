/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 06:10:32 by kamin             #+#    #+#             */
/*   Updated: 2022/03/08 20:40:56 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief This funciton will swap the first two elements in a stack
 * 
 * @param stack The Stack To Swap The Topmost Two Elements
 */
void	swap_stack(t_bp *stack)
{
	int	tmp;

	stack_last(stack);
	tmp = (*stack).head->data;
	(*stack).head->data = (*stack).head->prev->data;
	(*stack).head->prev->data = tmp;
	reset_stack(stack);
}

/**
 * @brief This funciton will swap the first two elements in both stack
 * 
 * @param stack First Stack To Swap The Topmost Two Elements
 * @param stack2 Second Stack To Swap The Topmost Two Elements
 */
void	swap_both(t_bp *stack, t_bp *stack2)
{
	swap_stack(stack);
	swap_stack(stack2);
}
