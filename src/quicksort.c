/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 22:35:59 by kamin             #+#    #+#             */
/*   Updated: 2021/12/22 03:23:05 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief This Function Swaps Two Ints In An Array
 * 
 * @param a The Element To Swap With B
 * @param b The Element To Swap With A
 */
void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

/**
 * @brief This function partitions an int pointer using the last element (high)
 * as a pivot point, and places the pivot point in its correct position, then
 * it moves all the elements before or after the pivot point depending if its 
 * bigger or smaller.
 * 
 * @param arr The Pointer To Integers To Partition
 * @param low The Smalles Index
 * @param high The Highest Index
 * @return int - Index Of The Pivot Point
 */
int	partition(int **arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = (*arr)[high];
	i = low - 1;
	j = i;
	while (++j < high)
	{
		if ((*arr)[j] < pivot)
		{
			i++;
			swap(&(*arr)[i], &(*arr)[j]);
		}
	}
	swap(&(*arr)[i + 1], &(*arr)[high]);
	return (i + 1);
}

/**
 * @brief This function Performs The Quicksort Algorithm
 * On A Pointer To Ints
 * 
 * @param arr The Array To Be Sorted
 * @param low The Smallest Index
 * @param high The Highest Index
 */
void	quicksort(int **arr, int low, int high)
{
	int	index;

	if (low < high)
	{
		index = partition(arr, low, high);
		quicksort(arr, low, index - 1);
		quicksort(arr, index + 1, high);
	}
}
