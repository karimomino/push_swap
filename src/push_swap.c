/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 06:10:24 by kamin             #+#    #+#             */
/*   Updated: 2022/02/13 19:38:52 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	constructor(char ***stack, int size)
{
	struct s_node	*mp;
	int				*nums;
	int				*snums;
	int				i;

	i = 0;
	nums = split_atoi(*stack, size);
	snums = split_atoi(*stack, size);
	quicksort(&snums, 0, size - 1);
	t_stack.a.head = NULL;
	t_stack.s.head = NULL;
	while (i < size)
		add_dll_front(&t_stack.a.head, nums[i++]);
	i = 0;
	while (i < size)
	{
		add_dll_front(&t_stack.s.head, snums[i++]);
	}
	i = 0;
	while (i++ < size / 2)
	{
		mp = t_stack.s.head;
		t_stack.s.head = t_stack.s.head->next;
	}
	i = 0;
	reset_stack(&t_stack.s);
	printf("Stack A: ");
	printList(t_stack.a.head);
	printf("\n");
	printf("Stack B: ");
	printList(t_stack.b.head);
	printf("\n");
	while (i++ < size/2 - 1)
		t_stack.s.head = t_stack.s.head->next;
	while (t_stack.a.head->next != NULL)
		t_stack.a.head = t_stack.a.head->next;
	t_stack.mp = t_stack.s.head->data;
	t_stack.b.head = NULL;
	printf("Mid Point: %d\n", t_stack.mp);
}

void	push_swap(char ***stack, int size)
{
	constructor(stack, size);
	check_smaller(size);
}

void	check_smaller(int size)
{
	int	counter;

	counter = size / 2;
	stack_last(&t_stack.a);
	while (counter && t_stack.a.head->data < t_stack.mp)
	{
		do_op(0);
		stack_last(&t_stack.a);
		counter--;
	}
	reset_stack(&t_stack.a);
	if (t_stack.a.head && t_stack.a.head->data < t_stack.mp)
	{
		while (counter)
		{
			if (t_stack.a.head->data < t_stack.mp)
			{
				do_op(5);
				do_op(0);
			}
			else
				do_op(0);
			counter--;
			t_stack.a.head = t_stack.a.head->next;
		}
	}
	else
	{
		stack_last(&t_stack.a);
		while (counter)
		{
			if (t_stack.a.head->data < t_stack.mp)
			{
				do_op(0);
				counter--;
			}
			else
				do_op(2);
			stack_last(&t_stack.a);
		}
	}
	reset_stack(&t_stack.a);
	reset_stack(&t_stack.b);
	printf("Stack A: ");
	printList(t_stack.a.head);
	printf("\n");
	printf("Stack B: ");
	printList(t_stack.b.head);
	printf("\n");
}
