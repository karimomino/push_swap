/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 06:10:24 by kamin             #+#    #+#             */
/*   Updated: 2022/03/08 21:49:42 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	constructor(char ***stack, int size)
{
	int				*nums;
	int				*snums;
	int				i;
	int				chunks;

	i = 0;
	chunks = size;
	nums = split_atoi(*stack, size);
	snums = split_atoi(*stack, size);
	quicksort(&snums, 0, size - 1);
	t_stack.a.head = NULL;
	t_stack.s.head = NULL;
	while (i < size)
		add_dll_front(&t_stack.a.head, nums[i++]);
	i = 0;
	while (i < size)
		add_dll_front(&t_stack.s.head, snums[i++]);
	i = 0;
	while (i++ < size/2 - 1)
		t_stack.s.head = t_stack.s.head->next;
	stack_last(&t_stack.a);
	t_stack.mp = t_stack.s.head->data;
	reset_stack(&t_stack.s);
	t_stack.b.head = NULL;
	i = 0;
	while (chunks / 2 > 2)
	{
		chunks /= 2;
		i++;
	}
	t_stack.chunks = (int *)malloc(i * sizeof(int));
	/*DEBUGGING*/
	printf("Stack A: ");
	printList(t_stack.a.head);
	printf("\n");
	printf("Stack B: ");
	printList(t_stack.b.head);
	printf("\n");
	printf("Mid Point: %d\n", t_stack.mp);
}

void	push_swap(char ***stack, int size)
{
	int	i;

	constructor(stack, size);
	t_stack.s.elems = size;
	i = 0;
	while (t_stack.s.elems > 2)
	{
		check_smaller(t_stack.s.elems, &t_stack.chunks[i]);
		refactor(&t_stack.s);
		i++;
		printf("after refactor\n");
	}
	if (t_stack.s.elems == 2 && !is_sorted(&t_stack.a))
		do_op(8);
	printf("Stack A: ");
	printList(t_stack.a.head);
	printf("\n");
	printf("Stack B: ");
	printList(t_stack.b.head);
	printf("\n");
}

void	refactor(t_bp *stack)
{
	int	*nums;
	int	count;
	int	i;

	count = ltoi(&t_stack.a, &nums);
	i = 0;
	quicksort(&nums, 0, count - 1);
	free_stack(stack);
	while (i < count)
		add_dll_front(&t_stack.s.head, nums[i++]);
	(*stack).elems = count;
	i = 0;
	while (i++ < count/2 - 1)
		t_stack.s.head = t_stack.s.head->next;
	if (count == 3)
		t_stack.s.head = t_stack.s.head->next;
	t_stack.mp = (*stack).head->data;
	reset_stack(stack);
	reset_stack(&t_stack.a);
}

void	free_stack(t_bp *stack)
{
	struct s_node	*tmp;

	while ((*stack).head)
	{
		tmp = (*stack).head->next;
		if ((*stack).head->next != NULL)
			(*stack).head->next->prev = NULL;
		free((*stack).head);
		(*stack).head = tmp;
	}
	if ((*stack).head != NULL)
		free((*stack).head);
}

int	ltoi(t_bp *stack, int **nums)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while ((*stack).head->next != NULL)
	{
		(*stack).head = (*stack).head->next;
		count++;
	}
	reset_stack(stack);
	*nums = (int *)malloc(count * sizeof(int));
	while ((*stack).head->next != NULL)
	{
		(*nums)[i] = (*stack).head->data;
		(*stack).head = (*stack).head->next;
		i++;
	}
	if (count == 3)
		(*nums)[i] = (*stack).head->data;
	reset_stack(stack);
	return (count);
}

void	check_smaller(int size, int *chunk_size)
{
	int	counter;

	counter = size / 2;
	stack_last(&t_stack.a);
	while (counter && t_stack.a.head->data < t_stack.mp)
	{
		do_op(0);
		(*chunk_size)++;
		printf("Stack A: ");
		printList(t_stack.a.head);
		printf("\n");
		printf("Stack B: ");
		printList(t_stack.b.head);
		printf("\n");
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
				(*chunk_size)++;
				counter--;
			}
			else
				do_op(5);
			reset_stack(&t_stack.a);
		}
	}
	else
	{
		stack_last(&t_stack.a);
		while (counter)
		{
			stack_last(&t_stack.a);
			if (t_stack.a.head->data < t_stack.mp)
			{
				do_op(0);
				(*chunk_size)++;
				counter--;
			}
			else
			{
				do_op(2);
			}
		}
	}
	reset_stack(&t_stack.a);
	printf("Stack A: ");
	printList(t_stack.a.head);
	printf("\n");
	printf("Stack B: ");
	printList(t_stack.b.head);
	printf("\n");
}


/*TO DO
	Logic for Solving A Single Chunk
	Logic For solving Multiple Chunks
	Logic For Integration With Main Logic
*/
void	solve_b(int	chunk_size)
{
	int	counter;
	int	rrb;

	rrb = 0;
	counter = chunk_size / 2;
	stack_last(&t_stack.b);
	while (counter)
	{
		if (t_stack.b.head->data < t_stack.mp)
		{
			do_op(3);
			rrb++;
		}
		else
		{
			do_op(1);
			counter--;
			chunk_size--;
			printf("Stack A: ");
			printList(t_stack.a.head);
			printf("\n");
			printf("Stack B: ");
			printList(t_stack.b.head);
			printf("\n");
		}
		stack_last(&t_stack.a);
	}
}
