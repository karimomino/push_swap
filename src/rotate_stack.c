/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 06:10:27 by kamin             #+#    #+#             */
/*   Updated: 2022/03/10 20:19:39 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief This funciton will shift all elements of a stack up by one where
 * the top element becomes the bottom element.
 * 
 * @param stack - The Stack To Be Rolled Up.
 */
void	rotate_stack(t_bp *stack)
{
	struct s_node	*tmp;
	int	key;

	stack_last(stack);
	tmp = (*stack).head;
	key = (*stack).head->data;
	reset_stack(stack);
	deleteNode(&(*stack).head, key);
	reset_stack(stack);
	add_dll_front(&(*stack).head, key);
}

/**
 * @brief This funciton will shift all elements of both stacks up by one where
 * the top element becomes the bottom element.
 * 
 * @param stack Stack A To Be Rolled Up
 * @param stack2 Stack B To Be Rolled Up
 */
void	rotate_both(t_bp *stack, t_bp *stack2)
{
	rotate_stack(stack);
	rotate_stack(stack2);
}

/**
 * @brief This funciton will shift all elements of a stack down by one where
 * the bottom element becomes the top element.
 * 
 * @param stack The Stack To Be Rolled Down
 */
void	rev_rotate_stack(t_bp *stack)
{
	int	key;

	reset_stack(stack);
	key = (*stack).head->data;
	deleteNode(&(*stack).head, key);
	add_dll_back(&(*stack).head, key);
}

/**
 * @brief This funciton will shift all elements of both stacks down by one where
 * the bottom element becomes the top element.
 * 
 * @param stack Stack A To Be Rolled Down
 * @param stack2 Stack B To Be Rolled Down
 */
void	rev_rotate_both(t_bp *stack, t_bp *stack2)
{
	rev_rotate_stack(stack);
	rev_rotate_stack(stack2);
}
