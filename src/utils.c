/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 06:28:45 by kamin             #+#    #+#             */
/*   Updated: 2021/12/22 03:50:47 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief This Function Countes The Elements In A Stack
 * 
 * @param stack Stack To Be Counted
 * @return int - The Number Of Elements In The Stack
 */
int	count_elems(char **stack)
{
	int	counter;
	int	i;

	counter = -1;
	if (!(*stack))
		return (0);
	while ((*stack)[i])
		counter++;
	return (counter);
}
