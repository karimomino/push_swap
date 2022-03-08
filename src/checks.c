/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:06:48 by kamin             #+#    #+#             */
/*   Updated: 2022/03/08 20:38:34 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_bp *stack)
{
	int	sorted;

	sorted = 1;
	reset_stack(stack);
	while (stack->head->next != NULL && sorted == 1)
	{
		if (stack->head->data < stack->head->next->data)
			sorted = 0;
		stack->head = stack->head->next;
	}
	reset_stack(stack);
	return (sorted);
}
