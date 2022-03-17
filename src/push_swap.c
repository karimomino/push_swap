/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@42abudhabi.ae>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 06:10:24 by kamin             #+#    #+#             */
/*   Updated: 2022/03/17 17:03:18 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*TO_DO
	FIX SEG FAULTS AND TEST WITH DIFFERENT DATA SETS
	*/

void	constructor(char ***stack, int size)
{
	int				*nums;
	int				*snums;
	int				i;
	int				move;

	i = 0;
	move = 0;
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
	// if (size % 2)
		move = size / 2;
	// else
	// 	move = size / 2 - 1;
	while (i++ < move)
		t_stack.s.head = t_stack.s.head->next;
	stack_last(&t_stack.a);
	t_stack.mp = t_stack.s.head->data;
	reset_stack(&t_stack.s);
	t_stack.b.head = NULL;
	/*DEBUGGING*/
	// printf("Stack A: ");
	// printList(t_stack.a.head);
	// printf("\n");
	// printf("Stack B: ");
	// printList(t_stack.b.head);
	// printf("\n");
	// printf("Mid Point: %d\n", t_stack.mp);
}

void	add_chunk(int **chunks, int old_size)
{
	int	*old_chunks;
	int	i;

	old_chunks = (int *)malloc(old_size * sizeof(int));
	i = -1;
	while (++i < old_size)
		old_chunks[i] = (*chunks)[i];
	free((*chunks));
	i = -1;
	(*chunks) = (int *)malloc((old_size + 1) * sizeof(int));
	while (++i < old_size)
		(*chunks)[i] = old_chunks[i];
}

void	push_swap(char ***stack, int size)
{
	int	i;

	constructor(stack, size);
	t_stack.s.elems = size;
	while (!is_sorted(&t_stack.a))
	{
		i = 0;
		t_stack.chunks = (int *)malloc(1 * sizeof(int));
		while (t_stack.s.elems > 2)
		{
			check_smaller(t_stack.s.elems, &t_stack.chunks[i]);
			refactor(&t_stack.s);
			i++;
			add_chunk(&t_stack.chunks, i);
			// printf("after refactor\n");
		}
		if (t_stack.s.elems == 2 && !is_sorted(&t_stack.a))
			do_op(8);
		i--;
		reset_stack(&t_stack.b);
		while (i < t_stack.chunks_s)
		{
			refactor_b(&t_stack.s, &t_stack.chunks[i]);
			if (t_stack.s.elems == 1)
				solve_b(t_stack.chunks[i]);
			while (t_stack.s.elems > 2)
			{
				refactor_b(&t_stack.s, &t_stack.chunks[i]);
				solve_b(t_stack.chunks[i]);
				// printf("IM HERE\n");
			}
			// printf("Im Here 2\n");
			stack_last(&t_stack.b);
			if (t_stack.s.elems == 2 && t_stack.b.head->data < t_stack.b.head->prev->data)
			{
				do_op(9);
				do_op(1);
				stack_last(&t_stack.b);
				// printf("im here 3\n");
				do_op(1);
			}
			else if (t_stack.s.elems == 2)
			{
				do_op(1);
				stack_last(&t_stack.b);
				do_op(1);
			}
			reset_stack(&t_stack.b);
			i--;
		}
			// printf("Stack A: ");
			// printList(t_stack.a.head);
			// printf("\n");
			// printf("Stack B: ");
			// printList(t_stack.b.head);
			// printf("\n");
	}

	// refactor_b(&t_stack.s,& t_stack.chunks[1]);
	// solve_b(t_stack.chunks[1]);

	// printf("Stack B: ");
	// printList(t_stack.b.head);
	// refactor_b(&t_stack.s, &t_stack.chunks[2]);
	// solve_b(t_stack.chunks[2]);
	// refactor_b(&t_stack.s, &t_stack.chunks[2]);
	// solve_b(t_stack.chunks[2]);
	// refactor_b(&t_stack.s, &t_stack.chunks[2]);
	// solve_b(t_stack.chunks[2]);

	// printf("Stack A: ");
	// printList(t_stack.a.head);
	// printf("\n");
	// printf("Stack B: ");
	// printList(t_stack.b.head);
	// printf("\n");
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
	while (i++ < count/2)
		t_stack.s.head = t_stack.s.head->next;
	// if (count == 3)
	// 	t_stack.s.head = t_stack.s.head->next;
	t_stack.mp = (*stack).head->data;
	reset_stack(stack);
	reset_stack(&t_stack.a);
}

void	refactor_b(t_bp *stack, int *chunk_size)
{
	int	*nums;
	int	count;
	int	i;
	int	move;


	count = ltoi(&t_stack.b, &nums);
	if (count > *chunk_size)
		i = count - *chunk_size;
	else
	{
		i = 0;
		*chunk_size = count;
	}
	quicksort(&nums, 0, count - 1);
	free_stack(stack);
	while (i < count)
		add_dll_front(&t_stack.s.head, nums[i++]);
	if (count > *chunk_size)
		(*stack).elems = *chunk_size;
	else
		(*stack).elems = count;
	i = 0;
	if (*chunk_size % 2)
		move = *chunk_size / 2;
	else
		move = *chunk_size / 2 - 1;
	while (i++ < move && *chunk_size > 1)
		t_stack.s.head = t_stack.s.head->next;
	if (count == 3 && *chunk_size > 1)
		t_stack.s.head = t_stack.s.head->next;
	t_stack.mp = (*stack).head->data;
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
	reset_stack(&t_stack.a);
	reset_stack(&t_stack.b);
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
	(*nums)[i] = (*stack).head->data;
	if (count == 3)
		(*nums)[i] = (*stack).head->data;
	reset_stack(stack);
	return (count);
}

void	check_smaller(int size, int *chunk_size)
{
	int	counter;

	if (size % 2)
		counter = size / 2;
	else
		counter = size / 2 - 1;
	stack_last(&t_stack.a);
	while (counter && t_stack.a.head->data < t_stack.mp)
	{
		do_op(0);
		(*chunk_size)++;
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
	// reset_stack(&t_stack.a);
	// printf("Stack A: ");
	// printList(t_stack.a.head);
	// printf("\n");
	// printf("Stack B: ");
	// printList(t_stack.b.head);
	// printf("\n");
}

void	solve_b(int	chunk_size)
{
	int	counter;
	int	rrb;

	// printf("\nCHUNK SIZE: %d\n", chunk_size);
	// printf("\nMid Point: %d\n", t_stack.mp);
	reset_stack(&t_stack.b);

	if (chunk_size == 1)
		do_op(1);
	else
	{

		rrb = 0;
		if (chunk_size % 2)
			counter = chunk_size / 2;
		else
			counter = chunk_size / 2 - 1;
		stack_last(&t_stack.b);
		while (counter)
		{
			// printf("Current Data Point: %d\n", t_stack.b.head->data);
			if (t_stack.b.head->data <= t_stack.mp)
			{
				do_op(3);
				// printf("MIDPOINT: %d\n", t_stack.mp);
				// printf("Stack B AFTER RB: ");
				// printList(t_stack.b.head);
				rrb++;
			}
			else
			{
				do_op(1);
				counter--;
				chunk_size--;
				t_stack.s.elems--;
			}
			stack_last(&t_stack.b);
			stack_last(&t_stack.a);
		}
			while (rrb-- > 0)
				do_op(6);
	}
	reset_stack(&t_stack.a);
}
