/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 06:10:24 by kamin             #+#    #+#             */
/*   Updated: 2022/02/11 01:36:53 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	constructor(char ***stack, int size)
{
	struct s_node	*mp;
	int	*nums;
	int	*snums;
	int	i;

	i = 0;
	nums = split_atoi(*stack, size);
	snums = split_atoi(*stack, size);
	quicksort(&snums, 0, size - 1);
	t_stack.a.head = NULL;
	t_stack.s.head = NULL;
	while (i < size)
		add_dll_back(&t_stack.a.head, nums[i++]);
	i = 0;
	while (i < size)
		add_dll_back(&t_stack.s.head, snums[i++]);
	i = 0;
	while (i++ < size/2)
	{
		mp = t_stack.s.head;
		t_stack.s.head = t_stack.s.head->next;
	}
	t_stack.mp = t_stack.s.head->data;
	t_stack.b.head = NULL;
}

void	push_swap(char ***stack, int size)
{
	constructor(stack, size);
	// check_smaller(size);
}

void	check_smaller(int size)
{
	int	i;
	int	counter;

	i = -1;
	counter = size / 2;
	while (counter && t_stack.a.stack[++i] < t_stack.mp)
	{
		do_op(0);
		counter--;
	}
	if (counter && t_stack.a.stack[--size] < t_stack.mp)
	{
		printf("true");
		i = size;
		while (counter)
		{
			printf("in");
			if (t_stack.a.stack[--i] >= t_stack.mp)
				do_op(5);
			else
			{
				do_op(0);
				counter--;
			}
		}
	}
	else
	{
		while (counter)
		{
			if (t_stack.a.stack[i] >= t_stack.mp)
				do_op(2);
			else
			{
				do_op(0);
				i++;
				counter--;
			}
		}
	}
}
