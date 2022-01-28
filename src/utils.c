/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 06:28:45 by kamin             #+#    #+#             */
/*   Updated: 2022/01/03 21:26:53 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief This Function Countes The Elements In A Stack
 * 
 * @param stack Stack To Be Counted
 * @return int - The Number Of Elements In The Stack
 */
int	count_elems(int *stack)
{
	int	counter;
	int	i;

	counter = -1;
	i = 0;
	if (!(*stack))
		return (0);
	while (stack + 1 != NULL)
		counter++;
	return (counter);
}

/**
 * @brief This Function Will Make An Array Of Ints From An Array Of Strings
 * 
 * @param list The List To Be Converted
 * @param elems The Amount Of Elements In The List
 * @return int* - The Converted Array
 */
int	*split_atoi(char **list, int elems)
{
	int	*list_i;
	int	i;

	list_i = (int *)malloc(elems * sizeof(int));
	i = 0;
	while (i < elems)
	{
		list_i[i] = ft_atoi(list[i]);
		i++;
	}
	return (list_i);
}
