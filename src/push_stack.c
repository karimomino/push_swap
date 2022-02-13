/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 06:10:20 by kamin             #+#    #+#             */
/*   Updated: 2022/02/13 19:25:17 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** This funciton will take the top element of a stack and put it
** at the top of another stack.
** Params:
** 	NAME		TYPE		DESCRIPTION
** 	TBD			TBD			TBD
*/

/**
 * @brief This funciton will take the top element of a stack and put it
 * at the top of another stack.
 * 
 * @param stack Stack To Take The Top Element From To Put On Top Of B
 * @param stack2 Stack That The Top Element Of A Will Go On Top Of
 */
void	push_stack(t_bp *stack, t_bp *stack2)
{
	int	tmp;

	if ((*stack).head != NULL)
	{
		stack_last(stack);
		tmp = (*stack).head->data;
		reset_stack(stack);
		deleteNode(&(*stack).head, tmp);
		add_dll_back(&(*stack2).head, tmp);
	}
}
