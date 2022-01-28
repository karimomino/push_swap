/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 06:10:24 by kamin             #+#    #+#             */
/*   Updated: 2022/01/28 23:14:53 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(char ***stack, int size)
{
	t_stack.a = split_atoi(*stack, size);
	t_stack.s = t_stack.a;
	quicksort(&t_stack.s, 0, size - 1);
	t_stack.mp = t_stack.s[size / 2];
	t_stack.b = (int *)malloc(size * sizeof(int));
}

void	check_smaller(int size)
{
	int	i;
	int	counter;

	i = -1;
	counter = size / 2 + 2;
	while (--counter && t_stack.a[++i] < t_stack.mp)
		push_stack(&t_stack.a, &t_stack.b);
	i = size;
	while (--counter && t_stack.a[--i] < t_stack.mp)
	{
		rev_rotate_stack(&t_stack.a);
		push_stack(&t_stack.a, &t_stack.b);
	}
	i = 0;
	while (counter && t_stack.a[i])
	{
		if (t_stack.a[i] >= t_stack.mp)
			rotate_stack(&t_stack.a);
	}
}
