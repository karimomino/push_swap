/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 06:10:20 by kamin             #+#    #+#             */
/*   Updated: 2021/12/22 04:22:47 by kamin            ###   ########.fr       */
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
void	push_stack(char ***stack, char ***stack2)
{
	int	elems;
	int	elems2;

	elems = count_elems(*stack);
	elems2 = count_elems(*stack2);
	(*stack2)[elems2] = (*stack)[elems - 1];
	(*stack)[elems - 1] = 0;
}
